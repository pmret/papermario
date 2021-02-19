#include "common.h"

extern s32* D_802382F8_714FE8[];

ApiStatus func_80238000_714CF0(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = BATTLE_STATUS;

    if (battleStatus->flags2 & 0x40) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }

    return ApiStatus_DONE2;
}

#ifdef NON_MATCHING
ApiStatus func_80238028_714D18(ScriptInstance* script, s32 isInitialCall) {
    Actor* actor = get_actor(script->owner1.actorID);
    s32* var0 = &D_802382F8_714FE8[0];
    s32 var4 = *D_802382F8_714FE8[1];
    //s32* var4 = (*&var0);
    s32 var1 = *var0 + 18;
    f32 var2;

    var1 = clamp_angle(var4 + 18);
    var2 = var1 * 6.28318f;

    actor->unk_19A = 2.0f * sin_rad(var2 / 360.0f);

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "battle/partner/twink_714CF0", func_80238028_714D18);
#endif
