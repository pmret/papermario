#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

ApiStatus func_80271210(ScriptInstance* script, s32 isInitialCall) {
    func_80070AF0(0, script->varTable[0], script->varTable[1], script->varTable[2]);
    return ApiStatus_DONE2;
}

ApiStatus func_80271258(ScriptInstance* script, s32 isInitialCall) {
    func_80070AF0(1, script->varTable[0], script->varTable[1], script->varTable[2]);
    return ApiStatus_DONE2;
}

ApiStatus func_802712A0(ScriptInstance* script, s32 isInitialCall);
INCLUDE_ASM(ApiStatus, "19FAF0", func_802712A0, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_80271328(ScriptInstance* script, s32 isInitialCall);
INCLUDE_ASM(ApiStatus, "19FAF0", func_80271328, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_802713B0(ScriptInstance* script, s32 isInitialCall);
INCLUDE_ASM(ApiStatus, "19FAF0", func_802713B0, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_8027143C(ScriptInstance* script, s32 isInitialCall) {
    func_80070A90(0, script->varTable[0], script->varTable[1], script->varTable[2]);
    return ApiStatus_DONE2;
}

ApiStatus func_80271484(ScriptInstance* script, s32 isInitialCall);
INCLUDE_ASM(ApiStatus, "19FAF0", func_80271484, ScriptInstance* script, s32 isInitialCall);

ApiStatus func_80271588(ScriptInstance* script, s32 isInitialCall);
INCLUDE_ASM(ApiStatus, "19FAF0", func_80271588, ScriptInstance* script, s32 isInitialCall);

void dispatch_event_player(s32 eventType) {
    Actor* player = gBattleStatus.playerActor;
    ScriptInstance* oldOnHitScript;
    s32 oldOnHitID;
    ScriptInstance* eventScript;

    player->lastEventType = eventType;

    oldOnHitScript = player->onHitScript;
    oldOnHitID = player->onHitID;

    eventScript = start_script(HandleEvent_Player, 10, 0x20);
    player->onHitScript = eventScript;
    player->onHitID = eventScript->id;
    eventScript->owner1.actor = NULL;

    if (player->takeTurnScript != NULL) {
        kill_script_by_ID(player->takeTurnID);
        player->takeTurnScript = NULL;
    }

    if (oldOnHitScript != NULL) {
        kill_script_by_ID(oldOnHitID);
    }
}

void dispatch_event_player_continue_turn(s32 eventType) {
    Actor* player = gBattleStatus.playerActor;
    ScriptInstance* oldOnHitScript;
    s32 oldOnHitID;
    ScriptInstance* eventScript;

    player->lastEventType = eventType;

    oldOnHitScript = player->onHitScript;
    oldOnHitID = player->onHitID;

    eventScript = start_script(HandleEvent_Player, 10, 0x20);
    player->onHitScript = eventScript;
    player->onHitID = eventScript->id;
    eventScript->owner1.actor = NULL;

    if (oldOnHitScript != NULL) {
        kill_script_by_ID(oldOnHitID);
    }
}

INCLUDE_ASM(s32, "19FAF0", calc_player_test_enemy);

INCLUDE_ASM(s32, "19FAF0", calc_player_damage_enemy);

INCLUDE_ASM(s32, "19FAF0", dispatch_damage_event_player);

s32 dispatch_damage_event_player_0(s32 damageAmount, Event event) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->currentAttackElement = ELEMENT_END;
    battleStatus->unk_19A = 0;
    return dispatch_damage_event_player(damageAmount, event, FALSE);
}

void dispatch_damage_event_player_1(s32 damageAmount, Event event) {
    dispatch_damage_event_player(damageAmount, event, TRUE);
}

ApiStatus GetMenuSelection(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 outVar1 = *args++;
    s32 outVar2 = *args++;
    s32 outVar3 = *args++;

    set_variable(script, outVar1, battleStatus->moveCategory);
    set_variable(script, outVar2, battleStatus->selectedItemID);
    set_variable(script, outVar3, battleStatus->selectedMoveID);

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "19FAF0", func_80273444);

INCLUDE_ASM(s32, "19FAF0", PlayerFallToGoal, ScriptInstance* script, s32 isInitialCall);

ApiStatus PlayerLandJump(ScriptInstance *script, s32 isInitialCall) {
    Actor* player = gBattleStatus.playerActor;
    ActorMovementWalk* walkMovement = &player->walk;

    if (isInitialCall) {
        script->functionTemp[0].s = 0;
    }

    if (script->functionTemp[0].s == 0) {
        walkMovement->currentPos.x = player->currentPos.x;
        walkMovement->currentPos.y = player->currentPos.y;
        walkMovement->currentPos.z = player->currentPos.z;
        script->functionTemp[0].s = 1;
    }

    if (walkMovement->velocity > 0.0f) {
        if (walkMovement->animJumpRise != 0) {
            set_animation(0, 0, walkMovement->animJumpRise);
        }
    }

    if (walkMovement->velocity < 0.0f) {
        if (walkMovement->animJumpFall != 0) {
            set_animation(0, 0, walkMovement->animJumpFall);
        }
    }

    walkMovement->currentPos.y += walkMovement->velocity;
    walkMovement->velocity -= walkMovement->acceleration;

    add_xz_vec3f(&walkMovement->currentPos, walkMovement->speed, walkMovement->angle);

    player->currentPos.x = walkMovement->currentPos.x;
    player->currentPos.y = walkMovement->currentPos.y;
    player->currentPos.z = walkMovement->currentPos.z;

    if (player->currentPos.y < 0.0f) {
        player->currentPos.y = 0.0f;

        play_movement_dust_effects(2, player->currentPos.x, player->currentPos.y, player->currentPos.z, player->yaw);
        sfx_play_sound_at_position(SOUND_SOFT_LAND, 0, player->currentPos.x, player->currentPos.y, player->currentPos.z);

        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "19FAF0", PlayerRunToGoal, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "19FAF0", CancelablePlayerRunToGoal, ScriptInstance* script, s32 isInitialCall);

ApiStatus GetPlayerHP(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gPlayerData.curHP);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "19FAF0", PlayerDamageEnemy, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "19FAF0", PlayerPowerBounceEnemy, ScriptInstance* script, s32 isInitialCall);

INCLUDE_ASM(s32, "19FAF0", PlayerTestEnemy, ScriptInstance* script, s32 isInitialCall);

ApiStatus DispatchDamagePlayerEvent(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (dispatch_damage_event_player_0(get_variable(script, *args++), *args++) < 0) {
        return ApiStatus_BLOCK;
    }

    if (does_script_exist_by_ref(script)) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus EnablePlayerBlur(ScriptInstance* script, s32 isInitialCall) {
    s32 setting = get_variable(script, *script->ptrReadPos);

    if (setting == 0) {
        disable_player_blur();
    } else if (setting == 1) {
        enable_player_blur();
    } else {
        func_80254950();
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802749D8(ScriptInstance* script, s32 isInitialCall) {
    func_802549A0();
    return ApiStatus_DONE2;
}

ApiStatus func_802749F8(ScriptInstance* script, s32 isInitialCall) {
    func_802549C0();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "19FAF0", func_80274A18);

INCLUDE_ASM(s32, "19FAF0", func_802752AC);

INCLUDE_ASM(s32, "19FAF0", func_80275F00);

ApiStatus DidActionSucceed(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;
    s32 actionSuccess = gBattleStatus.actionSuccess;
    s32 actionSucceeded = 0;

    if (actionSuccess < 0) {
        actionSuccess = 0;
    }

    if (actionSucceeded < actionSuccess) {
        actionSucceeded = actionSuccess;
    }

    set_variable(script, outVar, actionSucceeded);
    return ApiStatus_DONE2;
}

ApiStatus func_80276EFC(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.flags1 |= 0x200000;
    return ApiStatus_DONE2;
}

ApiStatus func_80276F1C(ScriptInstance* script, s32 isInitialCall) {
    dispatch_event_player(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
