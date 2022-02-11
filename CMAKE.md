
# Buliding with CMAKE

It is possible to build Backtrace's fork of Crashpad using CMAKE, either 
independently, or as a sub-project. Currently supported systems are as follows:
- Linux (x86/x86_64)
- Windows (x86/x86_64)
- MacOS (incl. M1 ARM)
- Android (arm, arm64, x86_64)

## Linux

Assuming crashpad is installed to `~/crashpad`
```sh
$ cd ~/crashpad
$ mkdir cbuild && cd cbuild
$ cmake ..
$ make -j
```

This should build crashpad client library and the handler for it.

## Windows

## MacOS

## Android
