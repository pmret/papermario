#include "common.h"

extern s32 D_802A2C20;

ApiStatus func_802A1000_761920(ScriptInstance* script, s32 isInitialCall) {
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

ApiStatus func_802A10E4_761A04(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    script->varTable[0] = 0;

    if (battleStatus->jumpCharge >= 99) {
        script->varTable[0] = 1;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802A1108_761A28(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    BattleStatus* battleStatus2 = battleStatus; // TODO: macro?
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    s32* var4;

    func_800718D0(2, var1, var2, var3, 1.0f, 60);
    var4 = &D_802A2C20;
    *var4 = 0;
    if (battleStatus2->jumpCharge > 0) {
        *var4 = 1;
    }

    battleStatus2->jumpCharge += 3;

    if (battleStatus2->jumpCharge >= 100) {
        (*&battleStatus)->jumpCharge = 99; // TODO: macro?
    }

    battleStatus2->hammerCharge = 0;
    battleStatus->flags1 = (battleStatus->flags1 | 0x20000000) & 0xEFFFFFFF;

    return ApiStatus_DONE2;
}

ApiStatus func_802A1228_761B48(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s32 var3 = get_variable(script, *args++);
    f32 var4 = get_float_variable(script, *args++);
    s32 var5 = 45;
    s32 var6 = 30;

    func_800720B0(6, (var1 + 10), (var2 + 18), var3, var4, var5);
    func_80070BB0(13, (var1 + 10), (var2 + 18), var3, var4, var6);

    return ApiStatus_DONE2;
}

ApiStatus func_802A133C_761C5C(ScriptInstance* script, s32 isInitialCall) {
    if (D_802A2C20 == 0) {
        script->varTable[0] = 6;
    } else {
        script->varTable[0] = 7;
    }

    return ApiStatus_DONE2;
}
