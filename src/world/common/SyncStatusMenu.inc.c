#include "common.h"

static ApiStatus SyncStatusMenu(ScriptInstance* script, s32 isInitialCall) {
    sync_status_menu();
    return ApiStatus_DONE2;
}
