#!/usr/bin/ruby

require_relative 'crashpad_utils'

class TestMacOS < Minitest::Test
    def test_crashpad_uploads
        result = Crashpad::perform_test executable: 'examples/macos/demo/demo_macos'
        assert result
        assert result.has_key? :upload

        payload = result[:upload].params

        assert_equal payload.keys.sort, %w(format guid upload_file_minidump)

        assert_equal payload['format'], 'minidump'
    end
end
