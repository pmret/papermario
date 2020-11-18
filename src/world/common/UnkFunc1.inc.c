#include "common.h"

static ApiStatus UnkFunc1(ScriptInstance* script, s32 isInitialCall) {
    increment_status_menu_disabled();
    func_80137DA4(0, 255.0f);
    return ApiStatus_DONE2;
}
