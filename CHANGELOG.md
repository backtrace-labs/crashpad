# Backtrace Crashpad Release Notes

## Version 0.3.1

Bugfixes
- Android, and any build that selects the socket HTTP transport (`CRASHPAD_HTTPS_TRANSPORT=OPENSSL` or `NONE`): minidump uploads now send a `Host` header (the URL's authority, default port omitted), hostname-routed edges, load balancers and proxies no longer reject them.
- Socket HTTP transport: upload failures are logged (`HTTP status N`, `malformed HTTP status line`) instead of failing silently, a status-line length check that could index past the end of a 12-byte line is fixed.

## Version 0.3.0

Improvements
- Windows: Added `crashpad_handler.pdb` and `crashpad_handler.sym` to the zip.
- Windows: `client.lib` now embeds debug information.
- All platforms: Binaries are now optimized Release builds.
- Linux, Android: Attachments can be added after initialization.

Bugfixes
- Android: Pending reports are no longer dropped when an upload asks for a retry.

Note
- Windows: The handler executable is now `crashpad_handler.exe` (was `handler.exe`).
