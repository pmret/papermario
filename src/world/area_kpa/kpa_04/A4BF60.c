#include "kpa_04.h"

static char* N(exit_str_0) = "kpa_03";
static char* N(exit_str_1) = "kpa_81";

#include "world/common/UnkFunc11.inc.c"

ApiStatus func_802400BC_A4C01C(Evt *script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    f32 dist;
    f32 x;
    f32 y;
    f32 z;

    if (script->varTable[5] == 0) {
        playerStatus->position.x = script->varTable[0];
    } else {
        playerStatus->position.z = script->varTable[0];
    }

    x = playerStatus->position.x;
    y = playerStatus->position.y + 10.0f;
    z = playerStatus->position.z;

    dist = 40.0f;

    npc_raycast_down_sides(0, &x, &y, &z, &dist);

    playerStatus->position.x = x;
    playerStatus->position.y = y;
    playerStatus->position.z = z;

    return ApiStatus_DONE2;
}
