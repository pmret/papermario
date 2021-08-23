#include "common.h"
#include "map.h"

ApiStatus N(SyncStatusMenu)(Evt* script, s32 isInitialCall) {
    sync_status_menu();
    return ApiStatus_DONE2;
}
