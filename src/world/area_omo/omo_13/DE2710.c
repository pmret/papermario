#include "omo_13.h"
#include "sprite/npc/ShyGuy.h"

#include "world/common/enemy/ai/ShyGuyWanderAI.inc.c"

#include "world/common/enemy/ai/GrooveGuyAI.inc.c"

#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);
#include "world/common/todo/ItemChoice_WaitForSelection.inc.c"

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}

BSS s32 omo_13_80243220[92];

ApiStatus func_80240F8C_DE341C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            omo_13_80243220[i] = ptr[i];
        }
        omo_13_80243220[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            omo_13_80243220[i] = i + 128;
            omo_13_80243220[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

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

    if (npc->pos.x != x || npc->pos.y != y || npc->pos.z != z) {
        if (npc->currentAnim != ANIM_ShyGuy_Black_Anim02 && script->varTable[10]++ >= 6) {
            npc->currentAnim = ANIM_ShyGuy_Black_Anim02;
            script->varTable[10] = 0;
        }
        npc->pos.x = x;
        npc->pos.z = z;
        npc->colliderPos.x = npc->pos.x;
        npc->colliderPos.y = npc->pos.y;
        npc->colliderPos.z = npc->pos.z;
        npc->flags |= NPC_FLAG_DIRTY_SHADOW;
    } else if (npc->currentAnim != ANIM_ShyGuy_Black_Anim01) {
        npc->currentAnim = ANIM_ShyGuy_Black_Anim01;
    }
    npc->yaw = atan2(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z);
    return ApiStatus_DONE2;
}
