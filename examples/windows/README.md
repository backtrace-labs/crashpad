# Windows demo app for Crashpad with CMAKE

This demo app immediately crashes and sends report to the Backtrace universe
selected by the user.

# Build instructions

Assumptions:
- crashpad is checked out to `C:\demo-crashpad-cmake\crashpad`
- the demo app has been copied to `C:\demo-crashpad-cmake`

1. Update your handler path:
```cpp
std::wstring handler_path(L"c:/demo-crashpad-cmake/build/crashpad/handler/Debug/handler.exe");
```
2. Update your upload URL
```cpp
std::string url("http://submit.backtrace.io/myuniverse/mysubmittoken/minidump");
```
