#include "kkj_25.h"
#include "effects.h"

#define KNOCK_DOWN_MAP_VAR MapVar(10)
#include "world/common/complete/KnockDownPlayer.inc.c"

ApiStatus func_80240B18_B07518(Evt* script, s32 isInitialCall) {
    EffectInstance* effect;

    fx_stars_orbiting(0, script->varTable[0], script->varTable[1], script->varTable[2], script->varTable[3], script->varTable[4], &effect);
    script->varTablePtr[0] = effect;

    return ApiStatus_DONE2;
}

ApiStatus func_80240B8C_B0758C(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*) script->varTablePtr[0];

    effect->data.starsOrbiting->unk_28 = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_80240BA0_B075A0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = (EffectInstance*) evt_get_variable(script, *args++);
    s32 var1 = evt_get_variable(script, *args++);
    s32 var2 = evt_get_variable(script, *args++);
    s32 var3 = evt_get_variable(script, *args++);

    effect->data.starsOrbiting->pos.x = var1;
    effect->data.starsOrbiting->pos.y = var2;
    effect->data.starsOrbiting->pos.z = var3;

    return ApiStatus_DONE2;
}

ApiStatus func_80240C60_B07660(Evt* script, s32 isInitialCall) {
    EffectInstance* effect;

    fx_stars_orbiting(0, script->varTable[0], script->varTable[1], script->varTable[2], script->varTable[3], script->varTable[4], &effect);
    script->varTablePtr[0] = effect;

    return ApiStatus_DONE2;
}

ApiStatus func_80240CD4_B076D4(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*) script->varTablePtr[0];

    effect->data.starsOrbiting->unk_28 = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_80240CE8_B076E8(Evt* script, s32 isInitialCall) {
    gPlayerData.starBeamLevel = 2;
    gPlayerData.curHP = gPlayerData.curMaxHP;
    gPlayerData.curFP = gPlayerData.curMaxFP;
    gPlayerData.specialBarsFilled = gPlayerData.maxStarPower * 256;

    sync_status_menu();
    return ApiStatus_DONE2;
}

ApiStatus func_80240D30_B07730(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
        script->functionTemp[2] = 0;
    }

    switch (script->functionTemp[2]) {
        case 0:
            set_screen_overlay_color(0, 208, 0, 0);
            set_screen_overlay_params_front(1, script->functionTemp[1]);
            if (script->functionTemp[1] == 255) {
                script->functionTemp[1] = 0;
                script->functionTemp[2] = 1;
            } else {
                script->functionTemp[1] += 7;
                if (script->functionTemp[1] > 255) {
                    script->functionTemp[1] = 255;
                }
            }
            break;
        case 1:
            set_screen_overlay_color(
                0,
                208,
                (script->functionTemp[1] * 208) / 255,
                (script->functionTemp[1] * 208) / 255
            );
            set_screen_overlay_params_front(1, 255.0f);
            if (script->functionTemp[1] == 255) {
                script->functionTemp[2] = 2;
            }
            script->functionTemp[1] += 14;
            if (script->functionTemp[1] > 255) {
                script->functionTemp[1] = 255;
            }
    }
    return (script->functionTemp[2] == 2) * 2;
}

ApiStatus func_80240E54_B07854(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[1] = 255;
    }

    set_screen_overlay_params_front(1, script->functionTemp[1]);

    if (script->functionTemp[1] == 0) {
        return ApiStatus_DONE2;
    }

    script->functionTemp[1] -= 16;
    if (script->functionTemp[1] <= 0) {
        script->functionTemp[1] = 0;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_80240EB8_B078B8(Evt* script, s32 isInitialCall) {
    EffectInstance* effect;

    fx_stars_orbiting(0, script->varTable[0], script->varTable[1], script->varTable[2], script->varTable[3], script->varTable[4], &effect);
    script->varTablePtr[0] = effect;

    return ApiStatus_DONE2;
}

ApiStatus func_80240F2C_B0792C(Evt* script, s32 isInitialCall) {
    EffectInstance* effect = (EffectInstance*) script->varTablePtr[0];

    effect->data.starsOrbiting->unk_28 = 0;
    return ApiStatus_DONE2;
}
