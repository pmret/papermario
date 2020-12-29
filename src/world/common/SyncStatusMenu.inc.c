#include "common.h"
#include "map.h"

ApiStatus M(SyncStatusMenu)(ScriptInstance* script, s32 isInitialCall) {
    sync_status_menu();
    return ApiStatus_DONE2;
}
