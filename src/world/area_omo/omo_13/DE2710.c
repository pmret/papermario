#include "omo_13.h"

#include "world/common/enemy/ai/ShyGuyWanderAI.inc.c"

#include "world/common/enemy/ai/GrooveGuyAI.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

// matches, needs data migration
#ifdef NON_MATCHING
ApiStatus func_80240F00_DE3390(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (isInitialCall) {
        D_80241C04_DE4094 = FALSE;
    }

    if (D_80241C04_DE4094) {
        D_80241C04_DE4094 = FALSE;
        evt_set_variable(script, *args++, D_80241C08_DE4098);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "world/area_omo/omo_13/DE2710", func_80240F00_DE3390);
#endif

INCLUDE_ASM(s32, "world/area_omo/omo_13/DE2710", func_80240F54_DE33E4);

extern s32 flo_10_npcSettings_80243220[];

ApiStatus func_80240F8C_DE341C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            flo_10_npcSettings_80243220[i] = ptr[i];
        }
        flo_10_npcSettings_80243220[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            flo_10_npcSettings_80243220[i] = i + 128;
            flo_10_npcSettings_80243220[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

// control flow
#ifdef NON_MATCHING
ApiStatus func_80241028_DE34B8(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_safe(0);
    f32 theta;
    f32 x, y, z;

    dist2D(110.0f, -45.0f, playerStatus->position.x, playerStatus->position.z);
    theta = clamp_angle(atan2(110.0f, -45.0f, playerStatus->position.x, playerStatus->position.z));

    x = (sin_deg(theta) * 30.0f) + 110.0f;
    if (script->varTable[11] != 0) {
        y = playerStatus->position.y * 0.7f;
    } else {
        y = npc->pos.y;
    }
    z = -45.0f - (cos_deg(theta) * 30.0f);

    if (script->varTable[11] != 0 && npc->pos.y == 0.0f) {
        script->varTable[11] = 0;
    }
    if (npc->pos.x == x && npc->pos.y == y) {
        if (npc->pos.z == z) {
            if (npc->currentAnim != 0x3B0501) {
                npc->currentAnim = 0x3B0501;
            }
        } else {
            goto block_10;
        }
    } else {
block_10:
        if (npc->currentAnim != 0x3B0502) {
            if (script->varTable[10]++ >= 6) {
                npc->currentAnim = 0x3B0502;
                script->varTable[10] = 0;
            }
        }
        npc->pos.x = x;
        npc->pos.z = z;
        npc->colliderPos.x = npc->pos.x;
        npc->colliderPos.y = npc->pos.y;
        npc->colliderPos.z = npc->pos.z;
        npc->flags |= 0x10000;
    }
    npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "world/area_omo/omo_13/DE2710", func_80241028_DE34B8);
#endif
