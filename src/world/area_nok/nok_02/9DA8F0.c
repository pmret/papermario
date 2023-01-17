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

extern s32 N(ItemChoice_HasSelectedItem);
extern s32 N(ItemChoice_SelectedItemID);
#include "world/common/todo/ItemChoice_WaitForSelection.inc.c"

ApiStatus N(ItemChoice_SaveSelected)(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    N(ItemChoice_SelectedItemID) = evt_get_variable(script, *args++);
    N(ItemChoice_HasSelectedItem) = TRUE;
    return ApiStatus_DONE2;
}
#define NAMESPACE nok_02

BSS s32 nok_02_D_80254BA0[114];
BSS s32 nok_02_D_80254D68[92];

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

typedef struct UnkNok02 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 unk_18;
} UnkNok02; // size = 0x1C

extern UnkNok02 D_80252784_9E97A4[20];
extern s32 D_802529B4_9E99D4;

ApiStatus func_80243F10_9DAF30(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a0 = *args++;
    u32 count = 0;
    UnkNok02* it = D_80252784_9E97A4;
    u32 i;

    for (i = 0; i < ARRAY_COUNT(D_80252784_9E97A4); i++, it++) {
        if (evt_get_variable(script, it->unk_0C) != 0 && evt_get_variable(script, it->unk_14) == 0) {
            count++;
            if (evt_get_variable(script, it->unk_10) == 0) {
                break;
            }
        }
    }

    if (i == ARRAY_COUNT(D_80252784_9E97A4)) {
        if (count == 0) {
            script->varTable[0] = 0;
            evt_set_variable(script, a0, 0xFF);
            return ApiStatus_DONE2;
        } else {
            s32 temp_s6 = rand_int(count - 1);
            count = 0;

            it = D_80252784_9E97A4;
            for (i = 0; i < ARRAY_COUNT(D_80252784_9E97A4); i++, it++) {
                if (evt_get_variable(script, it->unk_0C) != 0 && evt_get_variable(script, it->unk_14) == 0) {
                    if (count++ == temp_s6) {
                        break;
                    }
                }
            }
        }
        script->varTable[0] = it->unk_00;
        evt_set_variable(script, a0, i + 1);
        return ApiStatus_DONE2;
    } else {
        script->varTable[0] = it->unk_00;
        evt_set_variable(script, a0, i + 1);
        return ApiStatus_DONE2;
    }
}

ApiStatus func_80244078_9DB098(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 a0 = *args++;
    s32 count = 0;
    s32 thing = evt_get_variable(script, a0) - 1;
    UnkNok02* it = D_80252784_9E97A4;
    u32 i;

    evt_set_variable(script, D_80252784_9E97A4[thing].unk_10, 1);

    for (i = 0; i < ARRAY_COUNT(D_80252784_9E97A4); i++, it++) {
        if (evt_get_variable(script, it->unk_0C) != 0 && evt_get_variable(script, it->unk_14) == 0) {
            count++;
            if (evt_get_variable(script, it->unk_10) == 0) {
                break;
            }
        }
    }

    if (i == ARRAY_COUNT(D_80252784_9E97A4)) {
        if (count < 2) {
            script->varTable[0] = 0;
            evt_set_variable(script, a0, 0xFF);
            return ApiStatus_DONE2;
        } else {
            s32 temp_s6 = rand_int(count - 2);

            count = 0;

            it = D_80252784_9E97A4;
            for (i = 0; i < ARRAY_COUNT(D_80252784_9E97A4); i++, it++) {
                if (i != thing &&
                    evt_get_variable(script, it->unk_0C) != 0 &&
                    evt_get_variable(script, it->unk_14) == 0)
                {
                    if (count++ == temp_s6) {
                        break;
                    }
                }
            }
        }
        script->varTable[0] = it->unk_00;
        evt_set_variable(script, a0, i + 1);
        return ApiStatus_DONE2;
    } else {
        script->varTable[0] = it->unk_00;
        evt_set_variable(script, a0, i + 1);
        return ApiStatus_DONE2;
    }
}

ApiStatus func_80244224_9DB244(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *args++) - 1;
    UnkNok02* temp_v1 = &D_80252784_9E97A4[idx];

    script->varTable[0] = temp_v1->unk_00;
    script->varTable[1] = temp_v1->unk_04;
    script->varTable[2] = temp_v1->unk_08;
    return ApiStatus_DONE2;
}

ApiStatus func_80244288_9DB2A8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, D_80252784_9E97A4[evt_get_variable(script, *args++) - 1].unk_14, 1);
    return ApiStatus_DONE2;
}

ApiStatus func_802442E0_9DB300(Evt* script, s32 isInitialCall) {
    Bytecode *args = script->ptrReadPos;
    s32 idx = evt_get_variable(script, *(args++)) - 1;
    s32 val = D_80252784_9E97A4[idx].unk_18;
    s16* typeFlags = &gItemTable[val].typeFlags;

    D_802529B4_9E99D4 = val;
    script->varTable[0] = (*typeFlags & ITEM_TYPE_FLAG_CONSUMABLE) > 0;
    script->varTable[1] = val;
    return ApiStatus_DONE2;
}
