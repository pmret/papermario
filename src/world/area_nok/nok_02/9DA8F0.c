#include "nok_02.h"

extern s32 D_802523B4_9E93D4;
extern Npc* wPartnerNpc;

// SetupDemoScene
ApiStatus func_802438D0_9DA8F0(Evt* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;

    switch (D_802523B4_9E93D4) {
        case 0:
            D_802523B4_9E93D4 = 1;
            break;
        case 1:
        case 2:
            D_802523B4_9E93D4++;
            break;
        case 3:
            partner_clear_player_tracking(wPartnerNpc);
            partner_set_goal_pos(playerStatus->position.x, playerStatus->position.z);
            func_800EF3D4(0);
            set_npc_yaw(wPartnerNpc, 90.0f);
            playerStatus->targetYaw = 90.0f;
            playerStatus->currentYaw = 90.0f;
            playerStatus->spriteFacingAngle = 0.0f;
            return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

#define NAMESPACE dup2_nok_02
#include "world/common/todo/GetNpcCollisionHeight.inc.c"

#include "world/common/todo/AddPlayerHandsOffset.inc.c"

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80243BEC_9DAC0C);

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}
#define NAMESPACE nok_02

extern s32 nok_02_D_80254BA0[];

ApiStatus func_80243C78_9DAC98(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            nok_02_D_80254BA0[i] = ptr[i];
        }
        nok_02_D_80254BA0[i] = 0;
    } else {
        for (i = 0; i < 112; i++) {
            nok_02_D_80254BA0[i] = i + 16;
            nok_02_D_80254BA0[112] = 0;
        }
    }
    return ApiStatus_DONE2;
}

extern s32 nok_02_D_80254D68[];

ApiStatus func_80243D14_9DAD34(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* ptr = (s32*) evt_get_variable(script, *args++);
    s32 i;

    if (ptr != NULL) {
        for (i = 0; ptr[i] != 0; i++) {
            nok_02_D_80254D68[i] = ptr[i];
        }
        nok_02_D_80254D68[i] = 0;
    } else {
        for (i = 0; i < 91; i++) {
            nok_02_D_80254D68[i] = i + 128;
            nok_02_D_80254D68[91] = 0;
        }
    }
    return ApiStatus_DONE2;
}

#define NAMESPACE dup2_nok_02
#include "world/common/todo/StashVars.inc.c"
#define NAMESPACE nok_02

#define NAMESPACE dup2_nok_02
#include "world/common/todo/GetItemName.inc.c"
#define NAMESPACE nok_02

ApiStatus func_80243EC8_9DAEE8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if ((evt_get_variable(script, *args++) % 4) != 0) {
        script->varTable[0] = 0;
    } else {
        script->varTable[0] = 1;
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80243F10_9DAF30);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80244078_9DB098);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80244224_9DB244);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_80244288_9DB2A8);

INCLUDE_ASM(s32, "world/area_nok/nok_02/9DA8F0", func_802442E0_9DB300);
