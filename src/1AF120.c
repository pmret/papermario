#include "common.h"

ApiStatus GetDamageIntensity(ScriptInstance* script, s32 isInitialCall) {
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

// TODO: Rename to AddEffectOffset
ApiStatus AddEffectOffset(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = get_variable(script, *args++);

    effect->data->pos.x += get_variable(script, *args++);
    effect->data->pos.y += get_variable(script, *args++);
    effect->data->pos.z += get_variable(script, *args++);

    return ApiStatus_DONE2;
}
