#include "common.h"
#include "effects.h"

extern f32 D_8023D1E0;
extern s32 D_8023D2C8;
extern s32 D_8023D330;
extern s32 D_8023D334;

ApiStatus func_80238000_70BD10(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        D_8023D2C8 = 0;
    }

    if (D_8023D2C8 == 0) {
        btl_set_popup_duration(99);
        return ApiStatus_BLOCK;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/lakilester", func_8023803C_70BD4C);

ApiStatus func_80238A6C_70C77C(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    f32 xPos = partnerActor->currentPos.x + 5;
    f32 yPos = partnerActor->currentPos.y + partnerActor->size.y + 20;
    f32 zPos = partnerActor->currentPos.z;
    f32 var = rand_int(140) + 10;
    f32 var2 = rand_int(80) + 10;

    fx_throw_spiny(0, xPos, yPos, zPos, var, var2, 20, 1.5f, 30);

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/lakilester", func_80238B50_70C860);

ApiStatus func_80238C14_70C924(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = gBattleStatus.cloudNineEffect;

    if (effect != NULL) {
        remove_effect(effect);
        gBattleStatus.cloudNineEffect = NULL;
        gBattleStatus.cloudNineTurnsLeft = 0;
        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80238C58_70C968(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* actor = battleStatus->playerActor;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            D_8023D1E0 = 0.1f;
            fx_ending_decals(0, actor->currentPos.x, actor->currentPos.y, actor->currentPos.z, 0.1f, &battleStatus->cloudNineEffect);
            script->functionTemp[0] = 1;
            break;
        case 1:
            if (D_8023D1E0 >= 1.0) {
                return ApiStatus_DONE2;
            }
            battleStatus->cloudNineEffect->data.endingDecals->unk_10 += 0.2;
            D_8023D1E0 += 0.2;
            break;
    }
    return ApiStatus_BLOCK;
}

ApiStatus func_80238D48_70CA58(Evt* script, s32 isInitialCall) {
    if (gBattleStatus.cloudNineTurnsLeft < script->varTable[10]) {
        gBattleStatus.cloudNineTurnsLeft = script->varTable[10];
        gBattleStatus.cloudNineDodgeChance = 50;
        gBattleStatus.unk_43C->unk_0C->unk_1A = gBattleStatus.cloudNineTurnsLeft;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "battle/partner/lakilester", func_80238D8C_70CA9C);

INCLUDE_ASM(s32, "battle/partner/lakilester", func_8023906C_70CD7C);

INCLUDE_ASM(s32, "battle/partner/lakilester", func_80239140_70CE50);

INCLUDE_ASM(s32, "battle/partner/lakilester", func_80239F84_70DC94);

ApiStatus func_8023A19C_70DEAC(Evt* script, s32 isInitialCall) {
    return (D_8023D330 == 0) * 2;
}

ApiStatus func_8023A1B0_70DEC0(Evt* script, s32 isInitialCall) {
    script->varTable[0] = D_8023D334;
    return ApiStatus_DONE2;
}
