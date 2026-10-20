#!/usr/bin/ruby

require_relative 'crashpad_utils'

class TestWindows < Minitest::Test
    def test_crashpad_uploads
        exe = [
            'examples/windows/demo/Release/demo_windows.exe',
            'examples/windows/demo/Debug/demo_windows.exe',
            'examples/windows/demo/demo_windows.exe',
        ].find { |f| File.exist? "#{__dir__}/../../cbuild/#{f}" } || 'examples/windows/demo/demo_windows.exe'

        result = Crashpad::perform_test executable: exe
        assert result
        assert result.has_key? :upload

        payload = result[:upload].params

        assert_equal payload.keys.sort, %w(format guid upload_file_minidump)

        assert_equal payload['format'], 'minidump'
    end
end
