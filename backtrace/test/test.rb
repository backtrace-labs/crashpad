#!/usr/bin/ruby

require 'minitest/autorun'
require 'os'
require 'rbconfig'

require_relative 'test_linux' if OS.linux?
require_relative 'test_macos' if OS.mac? && RbConfig::CONFIG['host_cpu'] == 'arm64'
require_relative 'test_windows' if OS.windows?
