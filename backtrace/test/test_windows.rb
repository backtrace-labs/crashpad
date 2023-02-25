#!/usr/bin/ruby

require_relative 'crashpad_utils'

class TestLinux < Minitest::Test
    def test_crashpad_uploads
        if (File.file?('examples/windows/demo/Debug/demo_windows.exe'))
            tests_path = 'examples/windows/demo/Debug/demo_windows.exe'
        else
            tests_path = 'examples/windows/demo/demo_windows.exe'
        end
        result = Crashpad::perform_test executable: tests_path
        assert result
        assert result.has_key? :upload

        payload = result[:upload].params

        assert_equal payload.keys.sort, %w(format guid upload_file_minidump)

        assert_equal payload['format'], 'minidump'
    end
end
