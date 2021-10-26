#include "dead.h"
#include "common.h"

#define NAMESPACE EA0C10

const char ascii_EA6D70[] = "kzn_11";
const char ascii_EA6D78[] = "kzn_18";
extern s32 D_802466D0[];

#include "world/common/UnkNpcAIFunc6.inc.c"

#include "world/common/UnkNpcAIFunc7.inc.c"

#include "world/common/UnkNpcAIFunc8.inc.c"

#include "world/common/UnkNpcAIFunc5.inc.c"

//Basically UnkNpcAIFunc26.inc.c, but gPartnerActionStatus.actionState.b[0] access 0, instead of 3
s32 N(UnkNpcAIFunc26)(Evt* script) {
    Enemy* enemy = script->owner1.enemy;
    Npc* npc = get_npc_unsafe(enemy->npcID);
    Camera* camera = &gCameras[gCurrentCamID];
    Enemy* enemy2 = get_enemy(enemy->npcID + 1);
    f32 phi_f20;
    s32 ret = TRUE;

    if (dist2D(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x, gPlayerStatusPtr->position.z) > enemy2->varTable[2]) {
        ret = FALSE;
    }

    if (clamp_angle(get_clamped_angle_diff(camera->currentYaw, npc->yaw)) < 180.0) {
        phi_f20 = 90.0f;
    } else {
        phi_f20 = 270.0f;
    }

    if (fabsf(get_clamped_angle_diff(phi_f20, atan2(npc->pos.x, npc->pos.z, gPlayerStatusPtr->position.x,
                                     gPlayerStatusPtr->position.z))) > enemy2->varTable[3]) {
        ret = FALSE;
    }

    if ((2.0 * npc->collisionHeight) <= fabsf(npc->pos.y - gPlayerStatusPtr->position.y)) {
        ret = FALSE;
    }

    if (gPartnerActionStatus.actionState.b[0] == 9) {
        ret = FALSE;
    }

    if (gPartnerActionStatus.actionState.b[0] == 7) {
        ret = FALSE;
    }

    return ret;
}

INCLUDE_ASM(s32, "EA0C10", func_802406CC_EA0FCC); // Should be relatively similar UnkFunc7

INCLUDE_ASM(s32, "EA0C10", func_8024097C_EA127C);

#include "world/common/UnkNpcAIFunc31.inc.c"

#include "world/common/UnkNpcAIFunc32.inc.c"

INCLUDE_ASM(s32, "EA0C10", func_80240DC4_EA16C4);

#include "world/common/UnkNpcDurationFlagFunc3.inc.c"

#include "world/common/UnkNpcAIFunc33.inc.c"

#include "world/common/UnkNpcDurationFlagFunc2.inc.c"

#include "world/common/UnkNpcAIFunc30.inc.c"

INCLUDE_ASM(s32, "EA0C10", func_80241AE0_EA23E0);

#include "world/common/set_script_owner_npc_anim.inc.c"

#include "world/common/UnkDistFunc.inc.c"

#include "world/common/UnkNpcAIFunc12.inc.c"

#include "world/common/set_script_owner_npc_col_height.inc.c"

INCLUDE_ASM(s32, "EA0C10", func_802420FC_EA29FC);

INCLUDE_ASM(s32, "EA0C10", func_80242568_EA2E68);

ApiStatus func_802425B0_EA2EB0(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    Npc* npc = get_npc_safe(script->owner2.npcID);

    if (dist2D(npc->pos.x, npc->pos.z, playerStatus->position.x, playerStatus->position.z) < 50.0f) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "EA0C10", func_80242608_EA2F08);

INCLUDE_ASM(s32, "EA0C10", func_8024267C_EA2F7C);

#include "world/common/DeadGetItemName.inc.c"

#include "world/common/GetNpcCollisionHeight.inc.c"

#include "world/common/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "EA0C10", func_802429C0_EA32C0);

INCLUDE_ASM(s32, "EA0C10", func_80242A14_EA3314);

ApiStatus func_80242A4C_EA334C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = evt_get_variable(script, *args);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            D_802466D0[i] = ptr[i];
        }
        D_802466D0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            D_802466D0[i] = i + 16;
            D_802466D0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

#include "world/common/SetManyVars.inc.c"

#include "world/common/UnkYawFunc.inc.c"

INCLUDE_ASM(s32, "EA0C10", func_80242D64_EA3664);

INCLUDE_ASM(s32, "EA0C10", func_80242DA8_EA36A8);
