#ifndef CRASHPAD_UTIL_ROBLOX_USER_CALLBACK_FUNCTIONS_H_
#define CRASHPAD_UTIL_ROBLOX_USER_CALLBACK_FUNCTIONS_H_

namespace crashpad
{
  typedef void(*UserCallbackOnDumpEvent)(void* data);
  void SetUserCallbackOnDumpEvent(UserCallbackOnDumpEvent func);
  void RunUserCallbackOnDumpEvent(void* data);
}

#endif
