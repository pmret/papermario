#include "common.h"

INCLUDE_ASM(s32, "code_1A5830", func_80276F50);

INCLUDE_ASM(s32, "code_1A5830", dispatch_event_general);

INCLUDE_ASM(s32, "code_1A5830", play_hit_sound);

INCLUDE_ASM(s32, "code_1A5830", dispatch_event_actor);

INCLUDE_ASM(s32, "code_1A5830", calc_enemy_test_target);

INCLUDE_ASM(s32, "code_1A5830", calc_enemy_damage_target);

INCLUDE_ASM(s32, "code_1A5830", dispatch_damage_event_actor);

INCLUDE_ASM(s32, "code_1A5830", dispatch_damage_event_actor_0);

INCLUDE_ASM(s32, "code_1A5830", dispatch_damage_event_actor_1);

ApiStatus BindTakeTurn(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);
    s32 var1;

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    var1 = get_variable(script, *args++);
    get_actor(actorID)->takeTurnCode = var1;
    return ApiStatus_DONE2;
}

ApiStatus PauseTakeTurn(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    get_variable(script, *args++);
    suspend_all_script(get_actor(actorID)->takeTurnID);
    return ApiStatus_DONE2;
}

ApiStatus ResumeTakeTurn(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    get_variable(script, *args++);
    resume_all_script(get_actor(actorID)->takeTurnID);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1A5830", BindIdle);

INCLUDE_ASM(s32, "code_1A5830", EnableIdleScript);

ApiStatus BindHandleEvent(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);
    s32 var1;

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    var1 = get_variable(script, *args++);
    get_actor(actorID)->onHitCode = var1;
    return ApiStatus_DONE2;
}

ApiStatus BindNextTurn(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);
    s32 var1;

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    var1 = get_variable(script, *args++);
    get_actor(actorID)->onTurnChangeCode = var1;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1A5830", JumpToGoal);

INCLUDE_ASM(s32, "code_1A5830", IdleJumpToGoal);

INCLUDE_ASM(s32, "code_1A5830", JumpToGoalSimple2);

INCLUDE_ASM(s32, "code_1A5830", JumpWithBounce);

INCLUDE_ASM(s32, "code_1A5830", LandJump);

INCLUDE_ASM(s32, "code_1A5830", FallToGoal);

INCLUDE_ASM(s32, "code_1A5830", RunToGoal);

INCLUDE_ASM(s32, "code_1A5830", IdleRunToGoal);

INCLUDE_ASM(s32, "code_1A5830", JumpPartTo);

INCLUDE_ASM(s32, "code_1A5830", FallPartTo);

INCLUDE_ASM(s32, "code_1A5830", LandJumpPart);

INCLUDE_ASM(s32, "code_1A5830", RunPartTo);

INCLUDE_ASM(s32, "code_1A5830", update_lerp_battle);

INCLUDE_ASM(s32, "code_1A5830", FlyToGoal);

INCLUDE_ASM(s32, "code_1A5830", IdleFlyToGoal);

INCLUDE_ASM(s32, "code_1A5830", FlyPartTo);

ApiStatus GetLastEvent(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);
    s32 outVar;

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    outVar = *args++;
    set_variable(script, outVar, get_actor(actorID)->lastEventType);
    return ApiStatus_DONE2;
}

ApiStatus SetTargetActor(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);
    s32 targetActorID;
    Actor* actor;

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    targetActorID = get_variable(script, *args++);
    actor = get_actor(actorID);
    actor->targetActorID = targetActorID;
    actor->targetPartIndex = 1;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1A5830", SetEnemyHP);

INCLUDE_ASM(s32, "code_1A5830", GetActorHP);

ApiStatus GetEnemyMaxHP(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);
    s32 outVar;

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    outVar = *args++;
    set_variable(script, outVar, get_actor(actorID)->maxHP);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1A5830", RemoveActor);

INCLUDE_ASM(s32, "code_1A5830", DropStarPoints);

ApiStatus SetDefenseTable(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);
    s32 var1;
    s32 var2;

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    var1 = get_variable(script, *args++);
    var2 = get_variable(script, *args++);
    get_actor_part(get_actor(actorID), var1)->defenseTable = var2;
    return ApiStatus_DONE2;
}

ApiStatus SetStatusTable(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);
    s32 var1;

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    var1 = get_variable(script, *args++);
    get_actor(actorID)->statusTable = var1;
    return ApiStatus_DONE2;
}

ApiStatus SetIdleAnimations(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);
    s32 var1;
    s32 var2;

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    var1 = get_variable(script, *args++);
    var2 = get_variable(script, *args++);
    get_actor_part(get_actor(actorID), var1)->idleAnimations = var2;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1A5830", func_8027CC10);

INCLUDE_ASM(s32, "code_1A5830", EnemyDamageTarget);

INCLUDE_ASM(s32, "code_1A5830", EnemyFollowupAfflictTarget);

INCLUDE_ASM(s32, "code_1A5830", EnemyTestTarget);

INCLUDE_ASM(s32, "code_1A5830", DispatchDamageEvent);

ApiStatus DispatchEvent(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    dispatch_event_actor(get_actor(actorID), get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus func_8027D2D8(ScriptInstance* script, s32 isInitialCall) {
    ActorId actorID = get_variable(script, *script->ptrReadPos);

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    func_80266ADC(get_actor(actorID));
    return ApiStatus_DONE2;
}

ApiStatus func_8027D32C(ScriptInstance* script, s32 isInitialCall) {
    ActorId actorID = get_variable(script, *script->ptrReadPos);

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    func_80266AF8(get_actor(actorID));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1A5830", SetTargetOffset);

INCLUDE_ASM(s32, "code_1A5830", func_8027D434);

INCLUDE_ASM(s32, "code_1A5830", func_8027D4C8);

ApiStatus EnableActorBlur(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);
    s32 enable = get_variable(script, *args++);
    Actor* actor;

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);

    if (enable == 0) {
        disable_actor_blur(actor);
    } else if (enable == 1) {
        enable_actor_blur(actor);
    } else {
        reset_actor_blur(actor);
    }
    return ApiStatus_DONE2;
}

ApiStatus func_8027D628(ScriptInstance* script, s32 isInitialCall) {
    ActorId actorID = get_variable(script, *script->ptrReadPos);

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    func_80254610(get_actor(actorID));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1A5830", AfflictActor);

ApiStatus func_8027D75C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);
    s32 outVar = *args++;

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    set_variable(script, outVar, get_actor(actorID)->unk_208);
    return ApiStatus_DONE2;
}

ApiStatus GetEncounterState(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gCurrentEncounter.hitType);
    return ApiStatus_DONE2;
}

ApiStatus YieldTurn(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.flags1 |= 0x200000;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1A5830", SetActorSize);

ApiStatus GetActorSize(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);
    s32 outY = *args++;
    s32 outX = *args++;
    Actor* actor;

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    set_variable(script, outY, actor->size.y);
    set_variable(script, outX, actor->size.x);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1A5830", SetPartSize);

ApiStatus GetOriginalActorType(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);
    s32 outVar = *args++;

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    set_variable(script, outVar, get_actor(actorID)->staticActorData->type);
    return ApiStatus_DONE2;
}

ApiStatus GetCurrentActorType(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);
    s32 outVar = *args++;

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }

    set_variable(script, outVar, get_actor(actorID)->actorType);
    return ApiStatus_DONE2;
}

ApiStatus GetLastDamage(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorId actorID = get_variable(script, *args++);
    s32 outVar;

    if (actorID == ActorId_SELF) {
        actorID = script->owner1.actorID;
    }
    outVar = *args++;

    set_variable(script, outVar, get_actor(actorID)->lastDamageTaken);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_1A5830", EnableActorGlow);

INCLUDE_ASM(s32, "code_1A5830", WasStatusInflicted);

INCLUDE_ASM(s32, "code_1A5830", CopyStatusEffects);

INCLUDE_ASM(s32, "code_1A5830", ClearStatusEffects);
