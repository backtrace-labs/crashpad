<!--
Copyright 2015 The Crashpad Authors

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at

    http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
-->

# Backtrace fork of Crashpad

This is a fork of the Crashpad project with changes provided by
[Backtrace I/O](https://backtrace.io), a [Sauce Labs](https://saucelabs.com)
Company.

The major differences:
- addition of CMake build files, making it possible to use Crashpad as a simple
 CMake dependency.
- support for native Mac OS on M1 ARM builds.

## Build instructions
Please see examples for usage examples.

### Windows

Initial checkout
```sh
# Clone the repository
git clone git@github.com:backtrace-labs/crashpad.git
cd crashpad
# use the `backtrace` branch:
git checkout backtrace
# initialize submodules
git submodule update --init --recursive
```

Ensure that Visual Studio 2019 and CMake are in the path. You can do that by
running terminal from the shortcut provided by the Visual Studio Installer.

Build:
```sh
# make a build directory (note: build is already used by Crashpad)
mkdir -p cbuild && cd cbuild
# run CMake (additional options like -DCMAKE_EXPORT_COMPILE_COMMANDS=TRUE are possible)
# it is recommended to specify the compiler version used for the build
cmake -G "Visual Studio 16 2019" ..
cmake --build .
```

### Linux

Initial checkout
```sh
# Clone the repository
git clone git@github.com:backtrace-labs/crashpad.git
cd crashpad
# use the `backtrace` branch:
git checkout backtrace
# initialize submodules
git submodule update --init --recursive
```
Build:
```sh
# make a build directory (note: build is already used by Crashpad)
mkdir -p cbuild && cd cbuild
# run CMake (additional options like -DCMAKE_EXPORT_COMPILE_COMMANDS=TRUE are possible)
cmake ..
# alternatively: cmake --build .
make -j
```

### Mac OS

Initial checkout
```sh
# Clone the repository
git clone git@github.com:backtrace-labs/crashpad.git
cd crashpad
# use the `backtrace` branch:
git checkout backtrace
# initialize submodules
git submodule update --init --recursive
```

Choose the architecture. Available options: `arm64`, `x86_64`.

Build:
```sh
# make a build directory (note: build is already used by Crashpad)
mkdir -p cbuild && cd cbuild
# run CMake (additional options like -DCMAKE_EXPORT_COMPILE_COMMANDS=TRUE are possible)
cmake -DCMAKE_OSX_ARCHITECTURES=arm64 ..
# alternatively: cmake --build .
make -j
```

### Android

Initial checkout
```sh
# Clone the repository
git clone git@github.com:backtrace-labs/crashpad.git
cd crashpad
# use the `backtrace` branch:
git checkout backtrace
# initialize submodules
git submodule update --init --recursive
```

Ensure that paths are set up for the Android SDK and NDK:

```sh
# note that you will have to adjust those paths to your installation
export SDK_HOME=/home/backtrace/code/android/sdk
export PATH=${SDK_HOME}/cmake/3.18.1/bin/:$PATH
export CMAKE=${SDK_HOME}/cmake/3.18.1/bin/cmake
export ANDROID_HOME=${SDK_HOME}
export NDK_VERSION=21.4.7075529
export NDK=${ANDROID_HOME}/ndk/${NDK_VERSION}
export TOOLCHAIN=${SDK_HOME}/ndk/${NDK_VERSION}/build/cmake/android.toolchain.cmake
export GTEST=${NDK}/sources/third_party/googletest
export API_VERSION=21
# other supported are: armeabi-v7a, x86_64. x86 (32-bit) is NOT supported
export ABI=arm64-v8a
# use OPENSSL or NONE
export HTTPS_TRANSPORT=OPENSSL
```

Build:
```sh
# make a build directory (note: build is already used by Crashpad)
mkdir -p cbuild && cd cbuild
# run CMake (additional options like -DCMAKE_EXPORT_COMPILE_COMMANDS=TRUE are possible)
${CMAKE} \
        -DANDROID_ABI=${ABI} \
        -DANDROID_PLATFORM=${API_VERSION} \
        -DCMAKE_TOOLCHAIN_FILE=${TOOLCHAIN} \
        -DANDROID_NATIVE_API_LEVEL=${API_VERSION} \
        -DANDROID_TOOLCHAIN=clang \
        ..
# build
make -j
```

# Crashpad

[Crashpad](https://crashpad.chromium.org/) is a crash-reporting system.

## Documentation

 * [Project status](doc/status.md)
 * [Developing Crashpad](doc/developing.md): instructions for getting the source
   code, building, testing, and contributing to the project.
 * [Crashpad interface documentation](https://crashpad.chromium.org/doxygen/)
 * [Crashpad tool man pages](doc/man.md)
 * [Crashpad overview design](doc/overview_design.md)

## Source Code

Crashpad’s source code is hosted in a Git repository at
https://chromium.googlesource.com/crashpad/crashpad.

## Other Links

 * Bugs can be reported at the [Crashpad issue
   tracker](https://crashpad.chromium.org/bug/).
 * The [Crashpad bots](https://ci.chromium.org/p/crashpad/g/main/console)
   perform automated builds and tests.
 * [crashpad-dev](https://groups.google.com/a/chromium.org/group/crashpad-dev)
   is the Crashpad developers’ mailing list.
