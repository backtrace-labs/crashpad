# Linux demo app for crash loop detection

This demo app immediately crashes and sends report to the Backtrace universe
selected by the user. This demo enables Backtrace's Safe Mode/crash loop
detection feature.

# Build instructions

Assumptions:
- crashpad is checked out to `~/crashpad`
- the demo app has been copied to `~/crash_loop_detection`

1. Update your handler path:
```cpp
std::string handler_path("/home/myusername/crash_loop_detection/build/crashpad/handler/handler");
```
2. Update your upload URL
```cpp
std::string url("http://submit.backtrace.io/myuniverse/mysubmittoken/minidump");
```
3. Ensure that crashpad is a subdirectory of this project (a symbolic link will do), for example:
```sh
ln -s ~/crashpad ~/backtrace/crashpad
```
