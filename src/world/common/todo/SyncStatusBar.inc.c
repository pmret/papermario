#include "common.h"
#include "npc.h"

API_CALLABLE(N(SyncStatusBar)) {
    sync_status_bar();
    return ApiStatus_DONE2;
}
