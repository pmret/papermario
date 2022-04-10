#include "common.h"
#include "npc.h"

ApiStatus N(UnkPhysicsFunc)(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_unsafe(script->owner1.enemy->npcID);
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    f32 inDist1 = *args++;
    f32 r = *args++;
    f32 inDist2 = *args++;
    f32 x = npc->pos.x;
    f32 z = npc->pos.z;
    f32 y;
    f32 xDist;
    f32 zDist;
    s32 outVal;

    add_vec2D_polar(&x, &z, r, npc->yaw);
    xDist = dist2D(x, 0.0f, playerStatus->position.x, 0.0f);
    zDist = dist2D(0.0f, z, 0.0f, playerStatus->position.z);

    if (npc->yaw == 90.0 || npc->yaw == 270.0) {
        if (xDist <= inDist1 && zDist <= inDist2) {
            outVal = TRUE;
        } else {
            outVal = FALSE;
        }
    } else {
        if (zDist <= inDist1 && xDist <= inDist2) {
            outVal = TRUE;
        } else {
            outVal = FALSE;
        }
    }

    if (outVal) {
        x = npc->pos.x;
        y = npc->pos.y;
        z = npc->pos.z;
        // required to match, has to be r
        r = dist2D(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);

        if (npc_test_move_taller_with_slipping(0x78000, &x, &y, &z, r,
                                               atan2(npc->pos.x, npc->pos.z, playerStatus->position.x,
                                                     playerStatus->position.z),
                                               npc->collisionRadius,
                                               npc->collisionHeight))
        {
            outVal = FALSE;
        }
    }
    evt_set_variable(script, outVar, outVal);
    return ApiStatus_DONE2;
}
