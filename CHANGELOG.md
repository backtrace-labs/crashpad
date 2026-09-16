# Backtrace Crashpad Release Notes

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
