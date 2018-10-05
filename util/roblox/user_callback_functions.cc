#include "util/roblox/user_callback_functions.h"

namespace crashpad
{
  static UserCallbackOnDumpEvent onDumpEvent = nullptr;

  void SetUserCallbackOnDumpEvent(UserCallbackOnDumpEvent func)
  {
    onDumpEvent = func;
  }

  void RunUserCallbackOnDumpEvent(void* data)
  {
    if (onDumpEvent)
        onDumpEvent(data);
  }
}
