#!/usr/bin/ruby

require 'minitest/autorun'
require 'os'

require_relative 'test_linux' if OS.linux?
require_relative 'test_macos' if OS.mac?
require_relative 'test_windows' if OS.windows?
