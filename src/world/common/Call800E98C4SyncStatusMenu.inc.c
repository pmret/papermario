#include "common.h"
#include "npc.h"

ApiStatus N(Call800E98C4SyncStatusMenu)(Evt* script, s32 isInitialCall) {
    func_800E98C4();
    sync_status_menu();
    return ApiStatus_DONE2;
}
