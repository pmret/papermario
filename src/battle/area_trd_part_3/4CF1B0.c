#include "common.h"

#define NAMESPACE b_area_trd_part_3

extern s32 D_80219040;

ApiStatus func_80218000_4CF1B0(Evt* script, s32 isInitialCall) {
    Actor* actor = get_actor(script->owner1.actorID);
    s32* sym;

    if (isInitialCall) {
        D_80219040 = 0;
    }

    sym = &D_80219040;
    *sym += 15;
    *sym = clamp_angle(*sym);
    actor->unk_19A = sin_rad(*sym * TAU / 360.0f) * 3.0f;

    return ApiStatus_BLOCK;
}

ApiStatus func_802180C8_4CF278(Evt* script, s32 isInitialCall) {
    status_menu_start_blinking_sp();
    return ApiStatus_DONE2;
}

ApiStatus func_802180E8_4CF298(Evt* script, s32 isInitialCall) {
    status_menu_stop_blinking_sp();
    return ApiStatus_DONE2;
}

ApiStatus func_80218108_4CF2B8(Evt* script, s32 isInitialCall) {
    status_menu_start_blinking_hp();
    status_menu_start_blinking_fp();
    return ApiStatus_DONE2;
}

ApiStatus func_80218130_4CF2E0(Evt* script, s32 isInitialCall) {
    status_menu_stop_blinking_hp();
    status_menu_stop_blinking_fp();
    return ApiStatus_DONE2;
}

ApiStatus func_80218158_4CF308(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->unk_4C = 0;
    battleStatus->unk_5C = 0;

    return ApiStatus_DONE2;
}

ApiStatus func_80218170_4CF320(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (isInitialCall) {
        script->functionTemp[0] = 10;
    }

    battleStatus->flags2 &= ~0x2;

    if (script->functionTemp[0] != 0) {
        script->functionTemp[0]--;
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802181B4_4CF364(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (isInitialCall) {
        script->functionTemp[0] = 10;
    }

    battleStatus->flags2 &= ~0x4;

    if (script->functionTemp[0] != 0) {
        script->functionTemp[0]--;
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802181F8_4CF3A8(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;

    playerData->specialBarsFilled += 32;

    return ApiStatus_DONE2;
}
