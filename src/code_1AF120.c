#include "common.h"

ApiStatus GetDamageIntensity(ScriptInstance* script, s32 isInitialCall) {
    if (gBattleStatus.lastAttackDamage < 4) {
        script->varTable[0] = 0;
    } else if (gBattleStatus.lastAttackDamage < 7) {
        script->varTable[0] = 1;
    } else if (gBattleStatus.lastAttackDamage < 10){
        script->varTable[0] = 2;
    } else {
        script->varTable[0] = 3;
    }
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1AF120", ActorAddMovePos);
/*ApiStatus ActorAddMovePos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    Vec3f* actorMoveCurrentPos;

    actor = (Actor*)get_variable(script, *args++);
    actorMoveCurrentPos = &actor->moveCurrentPos;
    actorMoveCurrentPos->x += get_variable(script, *args++);
    actorMoveCurrentPos->y += get_variable(script, *args++);
    actorMoveCurrentPos->z += get_variable(script, *args++);
    return ApiStatus_DONE2;
}*/
