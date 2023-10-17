#!/usr/bin/ruby

require 'httpclient'
require 'json'
require 'os'
require 'webrick'
require 'zlib'

PORT = 6097
DEFAULT_URL = "http://127.0.0.1:#{PORT}/crashpad_upload"

module Crashpad

class Listener
    def listen_one
        webrick_params = {
            :Port => PORT,
        }
        unless defined?(DEBUG)
            webrick_params = webrick_params.merge({
                Logger: WEBrick::Log.new(OS.windows? ? "NUL:" : "/dev/null"),
                AccessLog: []
            })
        end
        server = WEBrick::HTTPServer.new webrick_params
        ret = nil

        server.mount_proc '/alive' do |req, res|
            res.body = ''
            res.status = 200
        end

        server.mount_proc '/crashpad_upload' do |req, res|
            req.body
            res.body = 'Finished?'
            res.status = 200
            ret = [req, res]
            server.shutdown
        end

        server.start

        ret
    end

    def await_availability timeout = 1
        client = HTTPClient.new
        b = Time.now
        while (Time.now - b < timeout) do
            begin
                r = client.get('http://localhost:6097/alive')
                return true if r.code == 200
            rescue Errno::ECONNREFUSED => e
            end
        end
        false
    end
end

class Upload
    attr_reader :req, :res, :params

    def initialize req, res
        @req = req
        @res = res
        parse_form_data
    end

    def parse_form_data
        body = case @req.header.fetch('content-encoding', nil)
            when ['gzip']
                Zlib::gunzip @req.body
            else
                @req.body
        end
        boundary = @req.content_type.scan(/boundary=(.*)/)[0][0]
        @params = WEBrick::HTTPUtils::parse_form_data body, boundary
    end
end

class Execution
    # expect to be called from [git_root]/backtrace/test by default
    def initialize build_dir: '../../cbuild/', url: DEFAULT_URL, executable:
        @build_dir = build_dir
        @executable = executable
        @url = url
    end

    def execute tmp_dir: nil
        Dir.chdir @build_dir do
            execute = lambda do |tmp|
                argv = [ @executable, @url, handler, tmp ]

                out_r, out_w = IO.pipe
                err_r, err_w = IO.pipe

                pid = spawn *argv, out: out_w, err: err_w

                out_w.close
                err_w.close

                Process.wait pid

                {
                    stdout: out_r.read,
                    stderr: err_r.read
                }
            end

            if tmp_dir
                execute.call tmp_dir
            else
                Dir.mktmpdir { |dir| execute.call dir }
            end
        end
    end

    def handler
        if OS.windows?
            [
                'handler/Debug/handler.exe',
                'handler/Release/handler.exe',
                'handler/handler.exe',
            ].find { |f| File.exist? f }
        else
            'handler/handler'
        end
    end
end

def Crashpad.perform_test opts = {}
    cl = Listener.new
    ce = Execution.new **opts
    execution_result = nil
    thread = Thread.new do
        return nil unless cl.await_availability
        execution_result = ce.execute
    end
    upload = Upload.new *cl.listen_one
    thread.join
    {
        upload: upload,
        crashpad: execution_result,
    }
end

end
