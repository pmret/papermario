#include "common.h"

extern s32 D_802382F8_714FE8;

ApiStatus func_80238000_714CF0(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (battleStatus->flags2 & 0x40) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80238028_714D18(Evt* script, s32 isInitialCall) {
    Actor* actor = get_actor(script->owner1.actorID);

    D_802382F8_714FE8 += 18;
    D_802382F8_714FE8 = clamp_angle(D_802382F8_714FE8);
    actor->unk_19A = 2.0f * sin_rad(D_802382F8_714FE8 * TAU / 360.0f);
    return ApiStatus_DONE2;
}
