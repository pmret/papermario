#include "common.h"

ApiStatus func_802A1000_74D570(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    BattleStatus* secondBattleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    f32 posX = playerActor->currentPos.x;
    f32 posY = playerActor->currentPos.y;
    f32 posZ = playerActor->currentPos.z;
    f32 goalX = playerActor->movePos.goal.x;
    f32 goalY = playerActor->movePos.goal.y;
    f32 goalZ = playerActor->movePos.goal.z;

    script->varTable[0] = (dist3D(posX, posY, posZ, goalX, goalY, goalZ) * 15.0f) / 100.0f;

    if (script->varTable[0] >= 21) {
        script->varTable[0] = 20;
    }

    if (secondBattleStatus->unk_83 != 0) {
        if (script->varTable[0] < 6) {
            script->varTable[0] = 6;
        }
    } else if (script->varTable[0] < 12) {
        script->varTable[0] = 12;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802A10E4_74D654(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    script->varTable[0] = 0;

    if (battleStatus->jumpCharge >= 99) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802A1108_74D678(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);

    func_800718D0(0, var1, var2, var3, 1.0f, 60);
    battleStatus->jumpCharge += 1;

    if (battleStatus->jumpCharge >= 100) {
        (*&battleStatus)->jumpCharge = 99; // TODO: macro?
    }

    battleStatus->hammerCharge = 0;
    battleStatus->flags1 = ((battleStatus->flags1 | 0x20000000) & 0xEFFFFFFF);

    return ApiStatus_DONE2;
}

ApiStatus func_802A120C_74D77C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    f32 var3 = get_float_variable(script, *args++);

    func_800720B0(6, (var0 + 10), (var1 + 18), var2, var3, 45);

    return ApiStatus_DONE2;
}
