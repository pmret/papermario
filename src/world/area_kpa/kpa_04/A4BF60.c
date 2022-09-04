#include "kpa_04.h"

static char* N(exit_str_0) = "kpa_03";
static char* N(exit_str_1) = "kpa_81";

#include "world/common/UnkFunc11.inc.c"

ApiStatus func_802400BC_A4C01C(Evt *script, s32 isInitialCall) {
    PlayerStatus* playerstatus = &gPlayerStatus;
    f32 sp24;
    f32 x;
    f32 y;
    f32 z;

    if (script->varTable[5] == 0) {
        playerstatus->position.x = script->varTable[0];
    } else {
        playerstatus->position.z = script->varTable[0];
    }

    x = playerstatus->position.x;
    y = playerstatus->position.y + 10.0f;
    z = playerstatus->position.z;

    sp24 = 40.0f;

    npc_raycast_down_sides(0, &x, &y, &z, &sp24);

    playerstatus->position.x = x;
    playerstatus->position.y = y;
    playerstatus->position.z = z;

    return ApiStatus_DONE2;
}
