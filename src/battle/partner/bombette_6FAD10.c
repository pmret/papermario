#include "common.h"
#include "battle/battle.h"

ApiStatus func_80238000_6FAD10(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = get_variable(script, *args++);
    s32 var2 = get_variable(script, *args++);
    s16 selectedMoveID;
    s32 soundID;

    func_80070130(0, var0, var1, var2);
    selectedMoveID = battleStatus->selectedMoveID;

    switch (selectedMoveID) {
        case 146:
            if (script->varTable[10] > 0) {
                func_800701F0(1, var0, var1 + 20, var2);
            } else {
                func_800701F0(0, var0, var1 + 20, var2);
            }
            play_sound(8214);
            break;
        case 147:
            if (script->varTable[10] > 0) {
                func_800701F0(1, var0, var1 + 20, var2);
            } else {
                func_800701F0(0, var0, var1 + 20, var2);
            }
            play_sound(8215);
            break;
        case 148:
            if (script->varTable[10] > 0) {
                func_800701F0(2, var0, var1 + 20, var2);
            } else {
                func_800701F0(1, var0, var1 + 20, var2);
            }
            play_sound(8215);
            break;
        default:
            func_800701F0(0, var0, var1 + 20, var2);
            play_sound(8214);
            break;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80238244_6FAF54(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    ActorMovement* partnerActorMovement = &partnerActor->walk;

    if (isInitialCall) {
        partnerActor->walk.currentPos.x = partnerActor->currentPos.x;
        partnerActor->walk.currentPos.y = partnerActor->currentPos.y;
        partnerActor->walk.currentPos.z = partnerActor->currentPos.z;
    }

    add_xz_vec3f(&partnerActorMovement->currentPos, partnerActor->walk.speed, partnerActor->walk.angle);

    if (partnerActor->walk.speed < 4.0f) {
        play_movement_dust_effects(0, partnerActor->walk.currentPos.x, partnerActor->walk.currentPos.y, partnerActor->walk.currentPos.z, partnerActor->walk.angle);
    } else {
        play_movement_dust_effects(1, partnerActor->walk.currentPos.x, partnerActor->walk.currentPos.y, partnerActor->walk.currentPos.z, partnerActor->walk.angle);
    }

    partnerActorMovement->speed = partnerActorMovement->speed / 1.5;

    partnerActor->currentPos.x = partnerActorMovement->currentPos.x;
    partnerActor->currentPos.y = partnerActorMovement->currentPos.y;
    partnerActor->currentPos.z = partnerActorMovement->currentPos.z;

    if (partnerActorMovement->speed < 1.0) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_80238358_6FB068(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = 0;

    switch (partnerActor->staticActorData->level) {
        case 0:
            if (var0 < 36) {
                var1 = 1;
            }
            else if (var0 < 61) {
                var1 = 2;
            }
            else if (var0 < 81) {
                var1 = 3;
            }
            else if (var0 < 100) {
                var1 = 4;
            }
            else {
                var1 = 5;
            }
            break;
        case 1:
            if (var0 < 36) {
                var1 = 1;
            }
            else if (var0 < 61) {
                var1 = 3;
            }
            else if (var0 < 81) {
                var1 = 4;
            }
            else if (var0 < 100) {
                var1 = 5;
            }
            else {
                var1 = 6;
            }
            break;
        case 2:
            if (var0 < 36) {
                var1 = 1;
            }
            else if (var0 < 61) {
                var1 = 3;
            }
            else if (var0 < 81) {
                var1 = 5;
            }
            else if (var0 < 100) {
                var1 = 6;
            }
            else {
                var1 = 7;
            }
            break;
        default:
            break;
    }


    if (!(var0 < 100)) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }

    script->varTable[15] = var1;

    return 2;
}

ApiStatus func_8023849C_6FB1AC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = 0;

    switch (partnerActor->staticActorData->level) {
        case 1:
            if (var0 < 36) {
                var1 = 1;
            }
            else if (var0 < 61) {
                var1 = 3;
            }
            else if (var0 < 81) {
                var1 = 4;
            }
            else if (var0 < 100) {
                var1 = 5;
            }
            else {
                var1 = 6;
            }
            break;
        case 2:
            if (var0 < 36) {
                var1 = 1;
            }
            else if (var0 < 61) {
                var1 = 3;
            }
            else if (var0 < 81) {
                var1 = 5;
            }
            else if (var0 < 100) {
                var1 = 6;
            }
            else {
                var1 = 7;
            }
            break;
        default:
            break;
    }


    if (!(var0 < 100)) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }

    script->varTable[15] = var1;

    return 2;
}

ApiStatus func_80238590_6FB2A0(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    s32 var0 = get_variable(script, *args++);
    s32 var1 = 0;

    switch (partnerActor->staticActorData->level) {
        case 2:
            if (var0 < 36) {
                var1 = 1;
            }
            else if (var0 < 61) {
                var1 = 3;
            }
            else if (var0 < 81) {
                var1 = 5;
            }
            else if (var0 < 100) {
                var1 = 6;
            }
            else {
                var1 = 7;
            }
            break;
        default:
            break;
    }


    if (!(var0 < 100)) {
        script->varTable[0] = 1;
    } else {
        script->varTable[0] = 0;
    }

    script->varTable[15] = var1;

    return 2;
}
