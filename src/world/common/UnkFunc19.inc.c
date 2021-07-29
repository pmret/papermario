#include "common.h"
#include "map.h"

extern s32 D_8008EF20[11][4];

ApiStatus N(UnkFunc19)(ScriptInstance* script, s32 isInitialCall) {
    set_message_string(D_8008EF20[gPlayerData.currentPartner][0], 0);

    return ApiStatus_DONE2;
}
