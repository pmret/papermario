#include "common.h"
#include "npc.h"

API_CALLABLE(N(SyncStatusMenu)) {
    sync_status_menu();
    return ApiStatus_DONE2;
}
