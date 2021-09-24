#include "common.h"
#include "effects.h"

ApiStatus GetDamageIntensity(Evt* script, s32 isInitialCall) {
    if (gBattleStatus.lastAttackDamage < 4) {
        script->varTable[0] = 0;
    } else if (gBattleStatus.lastAttackDamage < 7) {
        script->varTable[0] = 1;
    } else if (gBattleStatus.lastAttackDamage < 10) {
        script->varTable[0] = 2;
    } else {
        script->varTable[0] = 3;
    }
    return ApiStatus_DONE2;
}

ApiStatus AddEffectOffset(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = evt_get_variable(script, *args++);

    effect->data->pos.x += evt_get_variable(script, *args++);
    effect->data->pos.y += evt_get_variable(script, *args++);
    effect->data->pos.z += evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}
