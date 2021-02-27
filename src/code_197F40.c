#include "common.h"
#include "battle/battle.h"

extern s8 D_8029FBD4;

s32 count_targets(Actor* actor, s32 targetHomeIndex, s32 targetSelectionFlags) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->targetHomeIndex = targetHomeIndex;
    battleStatus->currentTargetListFlags = targetSelectionFlags;
    player_create_target_list(actor);
    return actor->targetListLength;
}

s32 get_nearest_home_index(f32 x, f32 y, f32 z) {
    s32 xVal;
    s32 yVal;

    if (y < 40.0f) {
        xVal = 0;
    } else if (y < 85.0f) {
        xVal = 1;
    } else if (y < 100.0f) {
        xVal = 2;
    } else {
        xVal = 3;
    }

    if (x < 25.0f) {
        yVal = 0;
    } else if (x < 65.0f) {
        yVal = 1;
    } else if (x < 105.0f) {
        yVal = 2;
    } else {
        yVal = 3;
    }

    return yVal | (xVal << 2);
}

INCLUDE_ASM(void, "code_197F40", set_goal_pos_to_part, f32* goalPos, ActorID target, s32 partIndex);

INCLUDE_ASM(s32, "code_197F40", set_part_goal_to_actor_part);

void set_actor_current_position(ActorID actorID, f32 x, f32 y, f32 z) {
    Actor* actor = get_actor(actorID);

    actor->currentPos.x = x;
    actor->currentPos.y = y;
    actor->currentPos.z = z;
}

void set_part_absolute_position(ActorID actorID, s32 partIndex, f32 x, f32 y, f32 z) {
    Actor* actor = get_actor(actorID);
    ActorPart* actorPart;

    switch (actorID & 0x700) {
        case 0:
            actor->currentPos.x = x;
            actor->currentPos.y = y;
            actor->currentPos.z = z;
            break;
        case 0x100:
        case 0x200:
            actorPart = get_actor_part(actor, partIndex);
            actorPart->absolutePosition.x = x;
            actorPart->absolutePosition.y = y;
            actorPart->absolutePosition.z = z;
            break;
    }
}

void set_actor_home_position(ActorID actorID, f32 x, f32 y, f32 z) {
    Actor* actor = get_actor(actorID);

    actor->homePos.x = x;
    actor->homePos.y = y;
    actor->homePos.z = z;
}

Actor* get_actor(ActorID actorID) {
    Actor* ret = NULL;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 idFlag = actorID & 0x700;
    u32 idIdx = (u8)actorID;

    switch (idFlag) {
        case 0:
            ret = battleStatus->playerActor;
            break;
        case 0x100:
            ret = battleStatus->partnerActor;
            break;
        case 0x200:
            ret = battleStatus->enemyActors[idIdx];
            break;
    }
    return ret;
}

INCLUDE_ASM(s32, "code_197F40", LoadBattleSection);

ApiStatus GetBattlePhase(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.battlePhase);
    return ApiStatus_DONE2;
}

ApiStatus GetLastElement(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.currentAttackElement);
    return ApiStatus_DONE2;
}

ApiStatus func_80269E80(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.unk_19A);
    return ApiStatus_DONE2;
}

ApiStatus func_80269EAC(ScriptInstance* script, s32 isInitialCall) {
    s32 a0 = *script->ptrReadPos;

    gBattleStatus.unk_19A = a0;
    return ApiStatus_DONE2;
}

ApiStatus SetGoalToHome(ScriptInstance* script, s32 isInitialCall) {
    ActorID actorID = get_variable(script, *script->ptrReadPos);
    Actor* actor;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    actor->walk.goalPos.x = actor->homePos.x;
    actor->walk.goalPos.y = actor->homePos.y;
    actor->walk.goalPos.z = actor->homePos.z;

    return ApiStatus_DONE2;
}

ApiStatus SetIdleGoalToHome(ScriptInstance* script, s32 isInitialCall) {
    ActorID actorID = get_variable(script, *script->ptrReadPos);
    Actor* actor;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    actor->fly.goalPos.x = actor->homePos.x;
    actor->fly.goalPos.y = actor->homePos.y;
    actor->fly.goalPos.z = actor->homePos.z;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_197F40", SetGoalToIndex);

ApiStatus GetIndexFromPos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 a1 = *args++;
    Actor* actor;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    set_variable(script, a1, get_nearest_home_index(actor->currentPos.x, actor->currentPos.y, actor->currentPos.z));

    return ApiStatus_DONE2;
}

ApiStatus GetIndexFromHome(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 a1 = *args++;
    Actor* actor;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    set_variable(script, a1, get_nearest_home_index(actor->homePos.x, actor->homePos.y, actor->homePos.z));

    return ApiStatus_DONE2;
}

ApiStatus CountPlayerTargets(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 targetSelectionFlags = *args++;
    s32 outVar = *args++;
    Actor* actor;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    set_variable(script, outVar, count_targets(actor, get_nearest_home_index(actor->currentPos.x, actor->currentPos.y,
                 actor->currentPos.z), targetSelectionFlags));

    return ApiStatus_DONE2;
}

ApiStatus ForceHomePos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    f32 x, y, z;
    Actor* actor;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    x = get_variable(script, *args++);
    y = get_variable(script, *args++);
    z = get_variable(script, *args++);

    actor = get_actor(actorID);
    actor->homePos.x = x;
    actor->currentPos.x = x;
    actor->homePos.y = y;
    actor->currentPos.y = y;
    actor->homePos.z = z;
    actor->currentPos.z = z;

    return ApiStatus_DONE2;
}

ApiStatus SetHomePos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    f32 x, y, z;
    Actor* actor;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    x = get_variable(script, *args++);
    y = get_variable(script, *args++);
    z = get_variable(script, *args++);

    actor = get_actor(actorID);
    actor->homePos.x = x;
    actor->homePos.y = y;
    actor->homePos.z = z;

    return ApiStatus_DONE2;
}

ApiStatus SetGoalToTarget(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);

    set_goal_pos_to_part(&actor->walk, actor->targetActorID, actor->targetPartIndex);

    return ApiStatus_DONE2;
}

ApiStatus SetPartGoalToTarget(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex = get_variable(script, *args++);
    Actor* actor;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);

    set_part_goal_to_actor_part(get_actor_part(actor, partIndex)->movement, actor->targetActorID, actor->targetPartIndex);

    return ApiStatus_DONE2;
}

ApiStatus SetGoalToFirstTarget(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    SelectableTarget* target;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);

    target = &actor->targetData[actor->targetIndexList[0]];
    set_goal_pos_to_part(&actor->walk, target->actorID, target->partID);

    return ApiStatus_DONE2;
}

ApiStatus SetGoalPos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    ActorMovement* walk;
    f32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);
    walk = &actor->walk;

    if (*args == -12345678) {
        x = actor->walk.goalPos.x;
    } else {
        x = get_variable(script, *args);
    }

    *args++;
    if (*args == -12345678) {
        y = walk->goalPos.y;
    } else {
        y = get_variable(script, *args);
    }

    *args++;
    if (*args == -12345678) {
        z = walk->goalPos.z;
    } else {
        z = get_variable(script, *args);
    }

    walk->goalPos.x = x;
    walk->goalPos.y = y;
    walk->goalPos.z = z;

    return ApiStatus_DONE2;
}

ApiStatus SetIdleGoal(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    ActorMovement* fly;
    f32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);
    fly = &actor->fly;

    if (*args == -12345678) {
        x = actor->fly.goalPos.x;
    } else {
        x = get_variable(script, *args);
    }

    *args++;
    if (*args == -12345678) {
        y = fly->goalPos.y;
    } else {
        y = get_variable(script, *args);
    }

    *args++;
    if (*args == -12345678) {
        z = fly->goalPos.z;
    } else {
        z = get_variable(script, *args);
    }

    fly->goalPos.x = x;
    fly->goalPos.y = y;
    fly->goalPos.z = z;
    return ApiStatus_DONE2;
}

ApiStatus AddGoalPos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    f32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    x = get_float_variable(script, *args++);
    y = get_float_variable(script, *args++);
    z = get_float_variable(script, *args++);

    actor = get_actor(actorID);
    actor->walk.goalPos.x += x;
    actor->walk.goalPos.y += y;
    actor->walk.goalPos.z += z;

    return ApiStatus_DONE2;
}

ApiStatus GetGoalPos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    s32 outX, outY, outZ;
    s32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);

    outX = *args++;
    outY = *args++;
    outZ = *args++;

    x = actor->walk.goalPos.x;
    y = actor->walk.goalPos.y;
    z = actor->walk.goalPos.z;

    set_variable(script, outX, x);
    set_variable(script, outY, y);
    set_variable(script, outZ, z);

    return ApiStatus_DONE2;
}

// should this be renamed to GetFlyGoal ?
ApiStatus GetIdleGoal(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    s32 outX, outY, outZ;
    s32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);

    outX = *args++;
    outY = *args++;
    outZ = *args++;

    x = actor->fly.goalPos.x;
    y = actor->fly.goalPos.y;
    z = actor->fly.goalPos.z;

    set_variable(script, outX, x);
    set_variable(script, outY, y);
    set_variable(script, outZ, z);

    return ApiStatus_DONE2;
}

ApiStatus GetPartTarget(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex = get_variable(script, *args++);
    Actor* actor;
    ActorPart* actorPart;
    s32 outX, outY, outZ;
    s32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    actorPart = get_actor_part(actor, partIndex);

    outX = *args++;
    outY = *args++;
    outZ = *args++;

    x = actorPart->movement->goalPos.x;
    y = actorPart->movement->goalPos.y;
    z = actorPart->movement->goalPos.z;

    set_variable(script, outX, x);
    set_variable(script, outY, y);
    set_variable(script, outZ, z);

    return ApiStatus_DONE2;
}

ApiStatus GetActorPos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    s32 outX, outY, outZ;
    s32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);

    outX = *args++;
    outY = *args++;
    outZ = *args++;

    x = actor->currentPos.x;
    y = actor->currentPos.y;
    z = actor->currentPos.z;

    set_variable(script, outX, x);
    set_variable(script, outY, y);
    set_variable(script, outZ, z);

    return ApiStatus_DONE2;
}

ApiStatus GetPartOffset(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex;
    ActorPart* actorPart;
    s32 outX, outY, outZ;
    s32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    actorPart = get_actor_part(get_actor(actorID), partIndex);

    outX = *args++;
    outY = *args++;
    outZ = *args++;

    if (!(actorPart->flags & 0x100000)) {
        x = actorPart->partOffset.x;
        y = actorPart->partOffset.y;
        z = actorPart->partOffset.z;
    } else {
        x = actorPart->absolutePosition.x;
        y = actorPart->absolutePosition.y;
        z = actorPart->absolutePosition.z;
    }

    set_variable(script, outX, x);
    set_variable(script, outY, y);
    set_variable(script, outZ, z);

    return ApiStatus_DONE2;
}

ApiStatus GetPartPos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex;
    ActorPart* actorPart;
    s32 outX, outY, outZ;
    s32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    actorPart = get_actor_part(get_actor(actorID), partIndex);

    outX = *args++;
    outY = *args++;
    outZ = *args++;

    x = actorPart->currentPos.x;
    y = actorPart->currentPos.y;
    z = actorPart->currentPos.z;

    set_variable(script, outX, x);
    set_variable(script, outY, y);
    set_variable(script, outZ, z);

    return ApiStatus_DONE2;
}

ApiStatus GetHomePos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    s32 outX, outY, outZ;
    s32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);

    outX = *args++;
    outY = *args++;
    outZ = *args++;

    x = actor->homePos.x;
    y = actor->homePos.y;
    z = actor->homePos.z;

    set_variable(script, outX, x);
    set_variable(script, outY, y);
    set_variable(script, outZ, z);

    return ApiStatus_DONE2;
}

ApiStatus SetActorPos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    f32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    x = get_variable(script, *args++);
    y = get_variable(script, *args++);
    z = get_variable(script, *args++);

    actor = get_actor(actorID);
    actor->currentPos.x = x;
    actor->currentPos.y = y;
    actor->currentPos.z = z;

    return ApiStatus_DONE2;
}

ApiStatus SetPartPos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    s32 partIndex;
    f32 x, y, z;
    ActorPart* actorPart;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    x = get_variable(script, *args++);
    y = get_variable(script, *args++);
    z = get_variable(script, *args++);

    actor = get_actor(actorID);

    switch (actorID & 0x700) {
        case 0:
            actor->currentPos.x = x;
            actor->currentPos.y = y;
            actor->currentPos.z = z;
            break;
        case 0x100:
        case 0x200:
            actorPart = get_actor_part(actor, partIndex);

            if (!(actorPart->flags & 0x100000)) {
                actorPart->partOffset.x = x;
                actorPart->partOffset.y = y;
                actorPart->partOffset.z = z;
            } else {
                actorPart->absolutePosition.x = x;
                actorPart->absolutePosition.y = y;
                actorPart->absolutePosition.z = z;
            }
            break;
    }

    return ApiStatus_DONE2;
}

ApiStatus SetEnemyTargetOffset(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    s32 partIndex;
    f32 x, y;
    ActorPart* actorPart;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    x = get_variable(script, *args++);
    y = get_variable(script, *args++);

    actor = get_actor(actorID);

    switch (actorID & 0x700) {
        case 0:
            break;
        case 0x100:
        case 0x200:
            actorPart = get_actor_part(actor, partIndex);
            actorPart->targetOffset.x = x;
            actorPart->targetOffset.y = y;
            break;
    }

    return ApiStatus_DONE2;
}

ApiStatus SetAnimation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    set_animation(actorID, get_variable(script, *args++), get_variable(script, *args++));

    return ApiStatus_DONE2;
}

ApiStatus GetAnimation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 var1;
    ActorPart* actorPart;
    s32 a1;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }
    var1 = get_variable(script, *args++);
    a1 = *args++;

    actorPart = get_actor_part(get_actor(actorID), var1);

    if (actorPart != NULL) {
        set_variable(script, a1, actorPart->currentAnimation);
    }
    return ApiStatus_DONE2;
}

ApiStatus SetAnimationRate(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    set_animation_rate(actorID, get_variable(script, *args++), get_float_variable(script, *args++));

    return ApiStatus_DONE2;
}

ApiStatus SetActorYaw(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    set_actor_yaw(actorID, get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus GetActorYaw(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 a1;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    a1 = *args++;

    set_variable(script, a1, get_actor(actorID)->yaw);
    return ApiStatus_DONE2;
}

ApiStatus SetPartYaw(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    set_part_yaw(actorID, get_variable(script, *args++), get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus GetPartYaw(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex;
    s32 a1;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    a1 = *args++;

    set_variable(script, a1, get_actor_part(get_actor(actorID), partIndex)->yaw);
    return ApiStatus_DONE2;
}

ApiStatus SetActorJumpGravity(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    f32 jumpAccel;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    jumpAccel = get_float_variable(script, *args++);
    get_actor(actorID)->walk.acceleration = jumpAccel;
    return ApiStatus_DONE2;
}

ApiStatus SetActorIdleJumpGravity(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    f32 flyJumpAccel;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    flyJumpAccel = get_float_variable(script, *args++);
    get_actor(actorID)->fly.acceleration = flyJumpAccel;
    return ApiStatus_DONE2;
}

ApiStatus SetActorSpeed(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    f32 moveSpeed;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    moveSpeed = get_float_variable(script, *args++);
    get_actor(actorID)->walk.speed = moveSpeed;
    return ApiStatus_DONE2;
}

// SetActorFlySpeed?
ApiStatus SetActorIdleSpeed(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    f32 flySpeed;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    flySpeed = get_float_variable(script, *args++);
    get_actor(actorID)->fly.speed = flySpeed;
    return ApiStatus_DONE2;
}

ApiStatus SetPartJumpGravity(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex;
    f32 jumpScale;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    jumpScale = get_float_variable(script, *args++);

    get_actor_part(get_actor(actorID), partIndex)->movement->jumpScale = jumpScale;
    return ApiStatus_DONE2;
}

ApiStatus SetPartMoveSpeed(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex;
    f32 moveSpeed;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    moveSpeed = get_float_variable(script, *args++);

    get_actor_part(get_actor(actorID), partIndex)->movement->moveSpeed = moveSpeed;
    return ApiStatus_DONE2;
}

ApiStatus SetJumpAnimations(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    s32 jumpPartIndex;
    s32 animJumpRise;
    s32 animJumpFall;
    s32 animJumpLand;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    jumpPartIndex = get_variable(script, *args++);
    animJumpRise = *args++;
    animJumpFall = *args++;
    animJumpLand = *args++;

    actor = get_actor(actorID);
    actor->jumpPartIndex = jumpPartIndex;
    actor->animJumpRise = animJumpRise;
    actor->animJumpFall = animJumpFall;
    actor->animJumpLand = animJumpLand;

    return ApiStatus_DONE2;
}

ApiStatus AddActorPos(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    f32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    x = get_float_variable(script, *args++);
    y = get_float_variable(script, *args++);
    z = get_float_variable(script, *args++);

    actor = get_actor(actorID);
    actor->currentPos.x += x;
    actor->currentPos.y += y;
    actor->currentPos.z += z;

    return ApiStatus_DONE2;
}

ApiStatus SetActorDispOffset(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    f32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    x = get_float_variable(script, *args++);
    y = get_float_variable(script, *args++);
    z = get_float_variable(script, *args++);

    actor = get_actor(actorID);
    actor->headOffset.x = x;
    actor->headOffset.y = y;
    actor->headOffset.z = z;

    return ApiStatus_DONE2;
}

ApiStatus GetPartDispOffset(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    ActorPart* actorPart;
    s32 partIndex;
    s32 outX, outY, outZ;
    f32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    outX = *args++;
    outY = *args++;
    outZ = *args++;

    actorPart = get_actor_part(get_actor(actorID), partIndex);

    if (!(actorPart->flags & 0x100000)) {
        x = actorPart->partOffset.x;
        y = actorPart->partOffset.y;
        z = actorPart->partOffset.z;
    } else {
        x = actorPart->visualOffset.x;
        y = actorPart->visualOffset.y;
        z = actorPart->visualOffset.z;
    }

    set_variable(script, outX, x);
    set_variable(script, outY, y);
    set_variable(script, outZ, z);

    return ApiStatus_DONE2;
}

ApiStatus SetPartDispOffset(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    ActorPart* actorPart;
    s32 partIndex;
    f32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);

    x = get_float_variable(script, *args++);
    y = get_float_variable(script, *args++);
    z = get_float_variable(script, *args++);
    actorPart = get_actor_part(get_actor(actorID), partIndex);

    if (!(actorPart->flags & 0x100000)) {
        actorPart->partOffset.x = x;
        actorPart->partOffset.y = y;
        actorPart->partOffset.z = z;
    } else {
        actorPart->visualOffset.x = x;
        actorPart->visualOffset.y = y;
        actorPart->visualOffset.z = z;
    }

    return ApiStatus_DONE2;
}

ApiStatus AddPartDispOffset(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    ActorPart* actorPart;
    s32 partIndex;
    f32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);

    x = get_float_variable(script, *args++);
    y = get_float_variable(script, *args++);
    z = get_float_variable(script, *args++);
    actorPart = get_actor_part(get_actor(actorID), partIndex);

    if (!(actorPart->flags & 0x100000)) {
        actorPart->partOffset.x += x;
        actorPart->partOffset.y += y;
        actorPart->partOffset.z += z;
    } else {
        actorPart->visualOffset.x += x;
        actorPart->visualOffset.y += y;
        actorPart->visualOffset.z += z;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_8026BF48(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    BattleStatus* battleStatus2 = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (get_variable(script, *args++) != 0) {
        battleStatus->unk_8C++;
    } else if (battleStatus->unk_8C > 0) {
        battleStatus2->unk_8C--;
    }

    return ApiStatus_DONE2;
}

ApiStatus GetActorVar(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 var1;
    s32 a2;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    var1 = get_variable(script, *args++);
    a2 = *args++;

    set_variable(script, a2, get_actor(actorID)->varTable[var1]);

    return ApiStatus_DONE2;
}

ApiStatus SetActorVar(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 index;
    s32 val;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    index = get_variable(script, *args++);
    val = get_variable(script, *args++);

    get_actor(actorID)->varTable[index] = val;

    return ApiStatus_DONE2;
}

#ifdef NON_MATCHING
ApiStatus AddActorVar(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 index;
    s32 val;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    index = get_variable(script, *args++);
    val = get_variable(script, *args++);

    get_actor(actorID)->varTable[index] += val;

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "code_197F40", AddActorVar);
#endif

ApiStatus GetPartMovementVar(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex;
    s32 tableIndex;
    s32 outVar;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    tableIndex = get_variable(script, *args++);
    outVar = *args++;

    set_variable(script, outVar, get_actor_part(get_actor(actorID), partIndex)->movement->varTable[tableIndex]);

    return ApiStatus_DONE2;
}

ApiStatus SetPartMovementVar(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex;
    s32 tableIndex;
    s32 val;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    tableIndex = get_variable(script, *args++);
    val = get_variable(script, *args++);

    get_actor_part(get_actor(actorID), partIndex)->movement->varTable[tableIndex] = val;

    return ApiStatus_DONE2;
}

ApiStatus AddPartMovementVar(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex;
    s32 tableIndex;
    s32 val;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    tableIndex = get_variable(script, *args++);
    val = get_variable(script, *args++);

    get_actor_part(get_actor(actorID), partIndex)->movement->varTable[tableIndex] += val;

    return ApiStatus_DONE2;
}

ApiStatus SetActorRotation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    s32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    x = get_float_variable(script, *args++);
    y = get_float_variable(script, *args++);
    z = get_float_variable(script, *args++);

    actor = get_actor(actorID);

    if (x != -250000000) {
        actor->rotation.x = x;
    }

    if (y != -250000000) {
        actor->rotation.y = y;
    }

    if (z != -250000000) {
        actor->rotation.z = z;
    }

    return ApiStatus_DONE2;
}

ApiStatus SetActorRotationOffset(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    s32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    x = get_float_variable(script, *args++);
    y = get_float_variable(script, *args++);
    z = get_float_variable(script, *args++);

    actor = get_actor(actorID);

    actor->rotationPivotOffset.x = x;
    actor->rotationPivotOffset.y = y;
    actor->rotationPivotOffset.z = z;

    return ApiStatus_DONE2;
}

ApiStatus GetActorRotation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    s32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    x = *args++;
    y = *args++;
    z = *args++;

    actor = get_actor(actorID);

    set_variable(script, x, actor->rotation.x);
    set_variable(script, y, actor->rotation.y);
    set_variable(script, z, actor->rotation.z);

    return ApiStatus_DONE2;
}

ApiStatus SetPartRotation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex = get_variable(script, *args++);
    ActorPart* actorPart;
    s32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    x = get_float_variable(script, *args++);
    y = get_float_variable(script, *args++);
    z = get_float_variable(script, *args++);

    actorPart = get_actor_part(get_actor(actorID), partIndex);

    actorPart->rotation.x = x;
    actorPart->rotation.y = y;
    actorPart->rotation.z = z;

    return ApiStatus_DONE2;
}

ApiStatus SetPartRotationOffset(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex = get_variable(script, *args++);
    ActorPart* actorPart;
    s32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    x = get_float_variable(script, *args++);
    y = get_float_variable(script, *args++);
    z = get_float_variable(script, *args++);

    actorPart = get_actor_part(get_actor(actorID), partIndex);

    actorPart->rotationPivotOffset.x = x;
    actorPart->rotationPivotOffset.y = y;
    actorPart->rotationPivotOffset.z = z;

    return ApiStatus_DONE2;
}

ApiStatus GetPartRotation(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex = get_variable(script, *args++);
    ActorPart* actorPart;
    s32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    x = *args++;
    y = *args++;
    z = *args++;

    actorPart = get_actor_part(get_actor(actorID), partIndex);

    set_float_variable(script, x, actorPart->rotation.x);
    set_float_variable(script, y, actorPart->rotation.y);
    set_float_variable(script, z, actorPart->rotation.z);

    return ApiStatus_DONE2;
}

ApiStatus SetActorScale(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    f32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    x = get_float_variable(script, *args++);
    y = get_float_variable(script, *args++);
    z = get_float_variable(script, *args++);

    actor = get_actor(actorID);

    actor->scale.x = x;
    actor->scale.y = y;
    actor->scale.z = z;

    return ApiStatus_DONE2;
}

ApiStatus SetActorScaleModifier(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    f32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    x = get_float_variable(script, *args++);
    y = get_float_variable(script, *args++);
    z = get_float_variable(script, *args++);

    actor = get_actor(actorID);

    actor->scaleModifier.x = x;
    actor->scaleModifier.y = y;
    actor->scaleModifier.z = z;

    return ApiStatus_DONE2;
}

ApiStatus GetActorScale(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    f32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    x = *args++;
    y = *args++;
    z = *args++;

    actor = get_actor(actorID);

    set_float_variable(script, x, actor->scale.x);
    set_float_variable(script, y, actor->scale.y);
    set_float_variable(script, z, actor->scale.z);

    return ApiStatus_DONE2;
}

ApiStatus SetPartScale(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex = get_variable(script, *args++);
    ActorPart* actorPart;
    f32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    x = get_float_variable(script, *args++);
    y = get_float_variable(script, *args++);
    z = get_float_variable(script, *args++);

    actorPart = get_actor_part(get_actor(actorID), partIndex);

    actorPart->scale.x = x;
    actorPart->scale.y = y;
    actorPart->scale.z = z;

    return ApiStatus_DONE2;
}

ApiStatus GetPartScale(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex = get_variable(script, *args++);
    ActorPart* actorPart;
    s32 x, y, z;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    x = *args++;
    y = *args++;
    z = *args++;

    actorPart = get_actor_part(get_actor(actorID), partIndex);

    set_float_variable(script, x, actorPart->scale.x);
    set_float_variable(script, y, actorPart->scale.y);
    set_float_variable(script, z, actorPart->scale.z);

    return ApiStatus_DONE2;
}

ApiStatus GetBattleFlags(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.flags1);
    return ApiStatus_DONE2;
}

ApiStatus SetBattleFlagBits(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode a0 = *args++;

    if (get_variable(script, *args)) {
        gBattleStatus.flags1 |= a0;
    } else {
        gBattleStatus.flags1 &= ~a0;
    }

    return ApiStatus_DONE2;
}

ApiStatus GetBattleFlags2(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.flags2);
    return ApiStatus_DONE2;
}

ApiStatus SetBattleFlagBits2(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode a0 = *args++;

    if (get_variable(script, *args)) {
        BattleStatus* battleStatus = &gBattleStatus;
        battleStatus->flags2 |= a0;
    } else {
        BattleStatus* battleStatus = &gBattleStatus;
        battleStatus->flags2 &= ~a0;
    }

    return ApiStatus_DONE2;
}

ApiStatus SetActorFlags(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 a1;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    a1 = *args++;
    get_actor(actorID)->flags = a1;

    return ApiStatus_DONE2;
}

ApiStatus SetActorFlagBits(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 a1;
    s32 var1;
    Actor* actor;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    a1 = *args++;
    var1 = get_variable(script, *args++);
    actor = get_actor(actorID);

    if (var1 != 0) {
        actor->flags |= a1;
    } else {
        actor->flags &= ~a1;
    }

    return ApiStatus_DONE2;
}

ApiStatus GetActorFlags(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 a1;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    a1 = *args++;

    set_variable(script, a1, get_actor(actorID)->flags);

    return ApiStatus_DONE2;
}

ApiStatus SetPartFlags(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 a1;
    s32 partIndex;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    a1 = *args++;

    get_actor_part(get_actor(actorID), partIndex)->flags = a1;

    return ApiStatus_DONE2;
}

ApiStatus SetPartFlagBits(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    ActorPart* actorPart;
    s32 bits;
    s32 partIndex;
    s32 cond;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    bits = *args++;
    cond = get_variable(script, *args++);

    actorPart = get_actor_part(get_actor(actorID), partIndex);

    if (cond != 0) {
        actorPart->flags |= bits;
    } else {
        actorPart->flags &= ~bits;
    }

    return ApiStatus_DONE2;
}

ApiStatus SetPartTargetFlags(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    ActorPart* actorPart;
    s32 flags;
    s32 partIndex;
    s32 cond;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    flags = *args++;

    get_actor_part(get_actor(actorID), partIndex)->targetFlags = flags;

    return ApiStatus_DONE2;
}

ApiStatus SetPartTargetFlagBits(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    ActorPart* actorPart;
    s32 partIndex;
    s32 bits;
    s32 cond;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    bits = *args++;
    cond = get_variable(script, *args++);

    actorPart = get_actor_part(get_actor(actorID), partIndex);

    if (cond != 0) {
        actorPart->targetFlags |= bits;
    } else {
        actorPart->targetFlags &= ~bits;
    }

    return ApiStatus_DONE2;
}

ApiStatus GetPartFlags(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex;
    ActorPart* actorPart;
    s32 a2;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    a2 = *args++;

    set_variable(script, a2, get_actor_part(get_actor(actorID), partIndex)->flags);

    return ApiStatus_DONE2;
}

ApiStatus GetPartTargetFlags(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex;
    ActorPart* actorPart;
    s32 a2;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    a2 = *args++;

    set_variable(script, a2, get_actor_part(get_actor(actorID), partIndex)->targetFlags);

    return ApiStatus_DONE2;
}

ApiStatus SetPartEventFlags(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    ActorPart* actorPart;
    s32 flags;
    s32 partIndex;
    s32 cond;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    flags = *args++;

    get_actor_part(get_actor(actorID), partIndex)->eventFlags = flags;

    return ApiStatus_DONE2;
}

ApiStatus SetPartEventBits(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    ActorPart* actorPart;
    s32 partIndex;
    s32 bits;
    s32 cond;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    bits = *args++;
    cond = get_variable(script, *args++);

    actorPart = get_actor_part(get_actor(actorID), partIndex);

    if (cond != 0) {
        actorPart->eventFlags |= bits;
    } else {
        actorPart->eventFlags &= ~bits;
    }

    return ApiStatus_DONE2;
}

ApiStatus GetPartEventFlags(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex;
    ActorPart* actorPart;
    s32 a2;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    a2 = *args++;

    set_variable(script, a2, get_actor_part(get_actor(actorID), partIndex)->eventFlags);

    return ApiStatus_DONE2;
}

ApiStatus func_8026D51C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    ActorPart* actorPart;
    s32 flags;
    s32 partIndex;
    s32 cond;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    flags = *args++;

    get_actor_part(get_actor(actorID), partIndex)->partFlags3 = flags;

    return ApiStatus_DONE2;
}

ApiStatus func_8026D5A4(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    ActorPart* actorPart;
    s32 partIndex;
    s32 bits;
    s32 cond;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    bits = *args++;
    cond = get_variable(script, *args++);

    actorPart = get_actor_part(get_actor(actorID), partIndex);

    if (cond != 0) {
        actorPart->partFlags3 |= bits;
    } else {
        actorPart->partFlags3 &= ~bits;
    }

    return ApiStatus_DONE2;
}

ApiStatus HPBarToHome(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    actor->healthBarPosition.x = actor->homePos.x + actor->staticActorData->hpBarOffset.x;
    actor->healthBarPosition.y = actor->homePos.y + actor->staticActorData->hpBarOffset.y;
    actor->healthBarPosition.z = actor->homePos.z;

    if (actor->flags & 0x800) {
        actor->healthBarPosition.y = actor->homePos.y - actor->size.y - actor->staticActorData->hpBarOffset.y;
    }

    actor->hpFraction = (actor->currentHP * 25) / actor->maxHP;

    return ApiStatus_DONE2;
}

ApiStatus HPBarToCurrent(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    actor->healthBarPosition.x = actor->currentPos.x + actor->staticActorData->hpBarOffset.x;
    actor->healthBarPosition.y = actor->currentPos.y + actor->staticActorData->hpBarOffset.y;
    actor->healthBarPosition.z = actor->currentPos.z;

    if (actor->flags & 0x800) {
        actor->healthBarPosition.y = actor->currentPos.y - actor->size.y - actor->staticActorData->hpBarOffset.y;
    }

    actor->hpFraction = (actor->currentHP * 25) / actor->maxHP;

    return ApiStatus_DONE2;
}

ApiStatus func_8026D8EC(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    func_80266AF8(get_actor(actorID));

    return ApiStatus_DONE2;
}

ApiStatus func_8026D940(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    s32 x, y;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    x = get_variable(script, *args++);
    y = get_variable(script, *args++);

    actor = get_actor(actorID);

    actor->unk_198.x = x;
    actor->unk_198.y = y;
    actor->healthBarPosition.x = actor->homePos.x + actor->staticActorData->hpBarOffset.x + actor->unk_198.x;
    actor->healthBarPosition.y = actor->homePos.y + actor->staticActorData->hpBarOffset.y + actor->unk_198.y;
    actor->healthBarPosition.z = actor->homePos.z;

    if (actor->flags & 0x800) {
        actor->healthBarPosition.y = actor->homePos.y - actor->size.y;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_8026DA94(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    s32 a, b, c, d;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    a = get_variable(script, *args++);
    b = get_variable(script, *args++);
    c = get_variable(script, *args++);
    d = get_variable(script, *args++);

    actor = get_actor(actorID);
    actor->unk_194 = a;
    actor->unk_195 = b;
    actor->unk_196 = c;
    actor->unk_197 = d;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_197F40", SummonEnemy);

ApiStatus GetOwnerID(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, script->owner1.actorID);
    return ApiStatus_DONE2;
}

ApiStatus SetOwnerID(ScriptInstance* script, s32 isInitialCall) {
    script->owner1.actorID = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus ActorExists(ScriptInstance* script, s32 isInitialCall) {
    Bytecode isExist;
    Actor* partner = gBattleStatus.partnerActor;
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    isExist = get_actor(actorID) != NULL;
    if ((actorID == ActorID_PARTNER) && (partner == NULL)) {
        isExist = FALSE;
    }

    set_variable(script, *args++, isExist);
    return ApiStatus_DONE2;
}

ApiStatus func_8026DEF0(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex = get_variable(script, *args++);
    s32 a2 = *args++;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    set_variable(script, a2, get_actor_part(get_actor(actorID), partIndex)->unk_84);

    return ApiStatus_DONE2;
}

ApiStatus func_8026DF88(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex = get_variable(script, *args++);
    s32 a2 = *args++;

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    set_variable(script, a2, get_actor_part(get_actor(actorID), partIndex)->unk_8C);

    return ApiStatus_DONE2;
}

ApiStatus func_8026E020(ScriptInstance* script, s32 isInitialCall) {
    s32 a0 = *script->ptrReadPos;

    gBattleStatus.unk_70 = a0;
    return ApiStatus_DONE2;
}

ApiStatus func_8026E038(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.unk_74 = *script->ptrReadPos;
    return ApiStatus_DONE2;
}

ApiStatus SetBattleInputMask(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.inputBitmask = *script->ptrReadPos;
    return ApiStatus_DONE2;
}

ApiStatus SetBattleInputButtons(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 currentButtonsDown = *args++;
    s32 currentButtonsPressed = *args++;
    s32 currentButtonsHeld = *args;

    battleStatus->currentButtonsDown = currentButtonsDown;
    battleStatus->currentButtonsPressed = currentButtonsPressed;
    battleStatus->currentButtonsHeld = currentButtonsHeld;

    return ApiStatus_DONE2;
}

ApiStatus CheckButtonPress(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode buttons = *args++;
    Bytecode out = *args;
    s32 buttonsPressed = gBattleStatus.currentButtonsPressed;

    set_variable(script, out, (buttonsPressed & buttons) != 0);
    return ApiStatus_DONE2;
}

ApiStatus CheckButtonHeld(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode buttons = *args++;
    Bytecode out = *args;
    s32 buttonsHeld = gBattleStatus.currentButtonsHeld;

    set_variable(script, out, (buttonsHeld & buttons) != 0);
    return ApiStatus_DONE2;
}

ApiStatus CheckButtonDown(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode buttons = *args++;
    Bytecode out = *args;
    s32 buttonsDown = gBattleStatus.currentButtonsDown;

    set_variable(script, out, (buttonsDown & buttons) != 0);
    return ApiStatus_DONE2;
}

ApiStatus GetBattleState(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleState);
    return ApiStatus_DONE2;
}

ApiStatus func_8026E16C(ScriptInstance* script, s32 isInitialCall) {
    func_80241190(get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_197F40", func_8026E198);

INCLUDE_ASM(s32, "code_197F40", func_8026E208);

INCLUDE_ASM(s32, "code_197F40", func_8026E260);

ApiStatus PlayerCreateTargetList(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);

    gBattleStatus.currentTargetListFlags = *args;
    player_create_target_list(actor);

    return ApiStatus_DONE2;
}

ApiStatus EnemyCreateTargetList(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);

    gBattleStatus.currentTargetListFlags = *args;
    enemy_create_target_list(actor);

    return ApiStatus_DONE2;
}

ApiStatus InitTargetIterator(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    SelectableTarget* selectableTarget = &actor->targetData[actor->targetIndexList[actor->selectedTargetIndex]];

    actor->targetActorID = selectableTarget->actorID;
    actor->targetPartIndex = selectableTarget->partID;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_197F40", SetOwnerTarget);

INCLUDE_ASM(s32, "code_197F40", ChooseNextTarget);

INCLUDE_ASM(s32, "code_197F40", func_8026E558);

ApiStatus GetTargetListLength(ScriptInstance* script) {
    Bytecode* args = script->ptrReadPos;

    set_variable(script, *args, get_actor(script->owner1.actorID)->targetListLength);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_197F40", GetOwnerTarget);

INCLUDE_ASM(s32, "code_197F40", func_8026E914);

ApiStatus GetAttackerActorID(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gBattleStatus.attackerActorID);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_197F40", func_8026E9A0);

INCLUDE_ASM(s32, "code_197F40", GetDistanceToGoal);

INCLUDE_ASM(s32, "code_197F40", func_8026EA7C);

INCLUDE_ASM(s32, "code_197F40", func_8026EB20);

INCLUDE_ASM(s32, "code_197F40", func_8026EBF8);

INCLUDE_ASM(s32, "code_197F40", func_8026ED20);

INCLUDE_ASM(s32, "code_197F40", func_8026EDE4);

INCLUDE_ASM(s32, "code_197F40", AddActorDecoration);

INCLUDE_ASM(s32, "code_197F40", RemoveActorDecoration);

INCLUDE_ASM(s32, "code_197F40", ModifyActorDecoration);

INCLUDE_ASM(s32, "code_197F40", UseIdleAnimation);

INCLUDE_ASM(s32, "code_197F40", func_8026F1A0);

INCLUDE_ASM(s32, "code_197F40", GetStatusFlags);

ApiStatus RemovePlayerBuffs(ScriptInstance* script, s32 isInitialCall) {
    remove_player_buffs(*script->ptrReadPos);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_197F40", SetPartAlpha);

INCLUDE_ASM(s32, "code_197F40", CreatePartShadow);

INCLUDE_ASM(s32, "code_197F40", RemovePartShadow);

ApiStatus func_8026F60C(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.unk_8D = get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_197F40", SetBattleVar);

INCLUDE_ASM(s32, "code_197F40", GetBattleVar);

ApiStatus ResetAllActorSounds(ScriptInstance* script, s32 isInitialCall) {
    ActorID actorID = get_variable(script, *script->ptrReadPos);

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    reset_all_actor_sounds(get_actor(actorID));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_197F40", SetActorSounds);

INCLUDE_ASM(s32, "code_197F40", ResetActorSounds);

INCLUDE_ASM(s32, "code_197F40", SetPartSounds);

INCLUDE_ASM(s32, "code_197F40", SetActorType);

ApiStatus ShowShockEffect(ScriptInstance* script, s32 isInitialCall) {
    ActorID actorID = get_variable(script, *script->ptrReadPos);

    if (actorID == ActorID_SELF) {
        actorID = script->owner1.actorID;
    }

    func_80251474(get_actor(actorID));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_197F40", GetActorAttackBoost);

INCLUDE_ASM(s32, "code_197F40", GetActorDefenseBoost);

INCLUDE_ASM(s32, "code_197F40", BoostAttack);

INCLUDE_ASM(s32, "code_197F40", BoostDefense);

INCLUDE_ASM(s32, "code_197F40", VanishActor);

INCLUDE_ASM(s32, "code_197F40", ElectrifyActor);

INCLUDE_ASM(s32, "code_197F40", HealActor);

ApiStatus WaitForBuffDone(ScriptInstance* script, s32 isInitialCall) {
    return (D_8029FBD4 == 0) * ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "code_197F40", CopyBuffs);
