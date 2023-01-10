#!/usr/bin/ruby

require_relative 'crashpad_utils'

class TestLinux < Minitest::Test
    def test_crashpad_uploads
        result = Crashpad::perform_test executable: 'examples/windows/demo/Debug/demo_windows.exe'
        assert result
        assert result.has_key? :upload

        payload = result[:upload].params

        assert_equal payload.keys.sort, %w(format guid upload_file_minidump)

        assert_equal payload['format'], 'minidump'
    end
end
