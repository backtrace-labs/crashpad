#!/usr/bin/ruby

require_relative 'crashpad_utils'

class TestLinux < Minitest::Test
    def test_crashpad_uploads
        result = Crashpad::perform_test executable: 'examples/linux/demo/demo_linux'
        assert result
        assert result.has_key? :upload

        payload = result[:upload].params

        assert_equal payload.keys.sort, %w(format guid upload_file_minidump)

        assert_equal payload['format'], 'minidump'
    end

    def test_crash_loop_detection
        exe = 'examples/linux/crash_loop_detection/crash_loop_detection_linux'
        ce = Crashpad::Execution.new executable: exe

        Dir.mktmpdir do |dir|
            10.times do |n|
                out = ce.execute tmp_dir: dir
                assert_match /Last Runs crashed: #{n}/, out[:stdout]
            end
        end
    end
end
