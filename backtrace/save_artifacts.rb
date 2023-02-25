#!/usr/bin/ruby

require 'bundler/inline'

gemfile do
    source 'https://rubygems.org'
    gem 'zip-zip'
end

require 'date'
require 'optparse'
require 'zip'

KNOWN_ANDROID_ARCH = %w(armeabi-v7a arm64-v8a x86_64)

OPTIONS = lambda do
    opts = {
        output: 'crashpad-%{date}.zip',
        crashpad_root: './',
        include_root: '%{crashpad_root}/',
        binary_root: '%{crashpad_root}/cbuild/',
        android_arch: nil,
    }

    OptionParser.new do |o|
        o.on('-o', '--output FILE'){ opts[:output] = _1 }
        o.on('--crashpad-root DIR'){ opts[:crashpad_root] = _1 }
        o.on('--include-root DIR'){ opts[:include_root] = _1 }
        o.on('--binary-root DIR'){ opts[:binary_root] = _1 }
        o.on('--android-arch ARCH'){ opts[:android_arch] = _1 }
    end.parse!

    opts
end.call

if OPTIONS[:android_arch] and not KNOWN_ANDROID_ARCH.include? OPTIONS[:android_arch]
    puts "Incorrect Android architecture: #{OPTIONS[:android_arch]}."
    puts "Known architectures: #{KNOWN_ANDROID_ARCH.join(?,)}."
    exit 1
end

def include_dir
    OPTIONS[:include_root] % OPTIONS
end

REJECT_DIRS = %w(test third_party build backtrace doc examples infra)
def gather_include_files dir = include_dir
    Dir.chdir dir do
        all_headers = Dir['**/*.h']

        selected_headers = all_headers
            .reject{ _1 =~ /^#{Regexp.union REJECT_DIRS}/ }
            .map{ [ "include/#{_1}", File.absolute_path(_1) ] }


        selected_headers += Dir.chdir 'third_party/mini_chromium/mini_chromium' do
            Dir['**/*.h']
                .map{ [ "include/#{_1}", File.absolute_path(_1) ] }
        end

        if OPTIONS[:android_arch]
            dirs = %w(curl openssl)
                .map{ "#{_1}-#{OPTIONS[:android_arch]}" }
                .map{ "third_party/openssl-android-binary/#{_1}" }
            dirs.each do |d|
                selected_headers += Dir.chdir d do
                    Dir['include/**/*.h'].map{ [ _1, File.absolute_path(_1) ] }
                end
            end
        end
        selected_headers.to_h
    end
end

def binary_dir
    OPTIONS[:binary_root] % OPTIONS
end

def gather_binaries dir = binary_dir
    bins = []
    files = [
        [ 'client/libclient.a', 'bin/libclient.a' ],
        [ 'handler/handler', 'bin/handler' ],
        [ './client/Debug/client.lib', 'bin/client.lib' ],
        [ 'handler/Debug/handler.exe', 'bin/handler.exe' ],
        [ './client/Release/client.lib', 'bin/client.lib' ],
        [ 'handler/Release/handler.exe', 'bin/handler.exe' ],
        [ './client/client.lib', 'bin/client.lib' ],
        [ 'handler/handler.exe', 'bin/handler.exe' ],
    ]
    Dir.chdir dir do
        files.each do |file, name|
            if File.exist? file
                bins.push [ name, File.absolute_path(file) ]
            end
        end
    end
    bins.to_h
end

def env_vars
    {
        date: Date.today.to_s,
    }
end

def create_zip
    files = gather_include_files.merge(gather_binaries)
    zip_file = OPTIONS[:output] % OPTIONS.merge(env_vars)

    Zip::File.open(zip_file, Zip::File::CREATE) do |zip|
        files.each do
            zip.add _1, _2
        end
    end
end

create_zip
