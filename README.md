<!--
Copyright 2015 The Crashpad Authors. All rights reserved.

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

# Backtrace modifications

This repository contains modifications provided by
[Backtrace I/O](https://backtrace.io).

## Windows file attachment support

Provided by [Ihor Dutchak](https://github.com/Youw/crashpad).

There also exists a Backtrace-specific function:

```
bool StartHandlerForBacktrace(const base::FilePath& handler,
                              const base::FilePath& database,
                              const base::FilePath& metrics_dir,
                              const std::string& url,
                              const std::map<std::string, std::string>& annotations,
                              const std::vector<std::string>& arguments,
                              const std::map<std::string, std::string>& fileAttachments,
                              bool restartable,
                              bool asynchronous_start);
```

It's very similar to `StartHandler`, with the exception of the
`fileAttachments` parameter, which is a map of upload file names to
local file paths.

For example, the following code will upload the log file from the specified
path as `2018-02-30.log`:

```
std::map<std::string, std::string> files = {
    { "2018-02-30.log", "C:/my_app/2018-02-30.log" }
};

rc = client.StartHandlerForBacktrace(handler,
    db,
    db,
    url,
    annotations,
    arguments,
    files,
    true,
    true);
```

If one does not want to use a Backtrace-specific function, the same result of
uploading a file attachment to Backtrace I/O can be achieved by adding elements
to the `arguments` vector in the following format:
```
--attachment=attachment_$ATTACHMENT_NAME=$ATTACHMENT_FILE_PATH
```

For the above example of `2018-02-30.log`, the code would look as follows:

```
arguments.push_back(
    "--attachment=attachment_2018-02-30.log=C:/my_app/2018-02-30.log"
);
```

## Send reports using `EXCEPTION_POINTERS` in Windows
A new function has been added to `CrashpadClient`, useful, example, when
dealing with vectored exceptions. Additionally, it does not require that
the process must end (the exception may be handled).

```
static void DumpWithoutCrashWithException(EXCEPTION_POINTERS* pointer);
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
