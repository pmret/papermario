#include "common.h"

INCLUDE_ASM("code_1a1f0_len_5390", get_defeated);

INCLUDE_ASM("code_1a1f0_len_5390", set_defeated);

ApiStatus GetCamLookAtObjVector(ScriptInstance* script, s32 isInitialCall) {
    // Almost certainly a CURRENT_CAM macro
    script->varTable[0] = (&gCameras[gCurrentCameraID])->lookAt_obj[0];
    script->varTable[1] = (&gCameras[gCurrentCameraID])->lookAt_obj[1];
    script->varTable[2] = (&gCameras[gCurrentCameraID])->lookAt_obj[2];

    return ApiStatus_DONE2;
}

INCLUDE_API_ASM("code_1a1f0_len_5390", HasMerleeCasts);

INCLUDE_API_ASM("code_1a1f0_len_5390", OnDefeatEnemy);

ApiStatus OnFleeBattleDrops(ScriptInstance* script, s32 isInitialCall) {
    PlayerStatus* playerStatus = &gPlayerStatus;
    PlayerData* playerData = &gPlayerData;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
        script->functionTemp[1] = 40;
        script->functionTemp[2] = 0;
    }

    script->functionTemp[2]++;
    if (script->functionTemp[2] >= 5) {
        if (rand_int(100) < 50) {
            if (playerData->coins != 0) {
                playerData->coins--;
                make_item_entity_delayed(ItemId_COIN, playerStatus->position.x, playerStatus->position.y + playerStatus->colliderHeight,
                                         playerStatus->position.z, 3, 0, 0);
            }
        }
        script->functionTemp[2] = 0;
    }

    return --script->functionTemp[1] == 0;
}

INCLUDE_ASM("code_1a1f0_len_5390", func_8003F7CC);

void func_8004135C() {
}

INCLUDE_ASM("code_1a1f0_len_5390", func_80041364);

INCLUDE_ASM("code_1a1f0_len_5390", func_80041964);

INCLUDE_ASM("code_1a1f0_len_5390", show_first_strike_message);

INCLUDE_ASM("code_1a1f0_len_5390", func_80041F10);

s32 func_8004304C(void) {
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    s32 ret = currentEncounter->unk_98;

    if (ret != 0) {
        func_80137D88(0, currentEncounter->unk_90);
        ret = func_80137E10(0, 0, 0, 0);
    }

    return ret;
}

INCLUDE_ASM("code_1a1f0_len_5390", func_8004309C);

void func_800431D4() {
}

INCLUDE_ASM("code_1a1f0_len_5390", func_800431DC);

INCLUDE_ASM("code_1a1f0_len_5390", create_npcs);

void func_80044140() {
}

s32 func_80044148(void) {
    s32 ret = gGameState == 3;

    if (gCurrentEncounter.hitType == 5) {
        ret = 1;
    }
    return ret;
}
