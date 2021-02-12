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
ApiStatus ActorAddMovePos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    EffectInstance* effect = get_variable(script, *args++);

    // TODO: Figure out the actual type of unk_0C
    effect->unk_0C->y += get_variable(script, *args++);
    effect->unk_0C->z += get_variable(script, *args++);
    effect->unk_0C->yaw += get_variable(script, *args++);

    return ApiStatus_DONE2;
}
