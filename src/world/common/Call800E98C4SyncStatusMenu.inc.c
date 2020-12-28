#include "common.h"
#include "map.h"

ApiStatus M(Call800E98C4SyncStatusMenu)(ScriptInstance* script, s32 isInitialCall) {
    func_800E98C4();
    sync_status_menu();
    return ApiStatus_DONE2;
}
