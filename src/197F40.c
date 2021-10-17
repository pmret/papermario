#include "common.h"
#include "effects.h"
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

INCLUDE_ASM(void, "197F40", set_goal_pos_to_part, f32* goalPos, s32 target, s32 partIndex);

INCLUDE_ASM(s32, "197F40", set_part_goal_to_actor_part);

void set_actor_current_position(s32 actorID, f32 x, f32 y, f32 z) {
    Actor* actor = get_actor(actorID);

    actor->currentPos.x = x;
    actor->currentPos.y = y;
    actor->currentPos.z = z;
}

void set_part_absolute_position(s32 actorID, s32 partIndex, f32 x, f32 y, f32 z) {
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

void set_actor_home_position(s32 actorID, f32 x, f32 y, f32 z) {
    Actor* actor = get_actor(actorID);

    actor->homePos.x = x;
    actor->homePos.y = y;
    actor->homePos.z = z;
}

Actor* get_actor(s32 actorID) {
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

ApiStatus LoadBattleSection(Evt* script, s32 isInitialCall) {
    BattleArea* battleArea = &gBattleAreas[evt_get_variable(script, *script->ptrReadPos)];

    dma_copy(battleArea->dmaStart, battleArea->dmaEnd, battleArea->dmaDest);
    return ApiStatus_DONE1;
}


ApiStatus GetBattlePhase(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.battlePhase);
    return ApiStatus_DONE2;
}

ApiStatus GetLastElement(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.currentAttackElement);
    return ApiStatus_DONE2;
}

ApiStatus func_80269E80(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.unk_19A);
    return ApiStatus_DONE2;
}

ApiStatus func_80269EAC(Evt* script, s32 isInitialCall) {
    s32 a0 = *script->ptrReadPos;

    gBattleStatus.unk_19A = a0;
    return ApiStatus_DONE2;
}

ApiStatus SetGoalToHome(Evt* script, s32 isInitialCall) {
    s32 actorID = evt_get_variable(script, *script->ptrReadPos);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    actor->state.goalPos.x = actor->homePos.x;
    actor->state.goalPos.y = actor->homePos.y;
    actor->state.goalPos.z = actor->homePos.z;

    return ApiStatus_DONE2;
}

ApiStatus SetIdleGoalToHome(Evt* script, s32 isInitialCall) {
    s32 actorID = evt_get_variable(script, *script->ptrReadPos);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    actor->fly.goalPos.x = actor->homePos.x;
    actor->fly.goalPos.y = actor->homePos.y;
    actor->fly.goalPos.z = actor->homePos.z;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "197F40", SetGoalToIndex);

ApiStatus GetIndexFromPos(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 a1 = *args++;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    evt_set_variable(script, a1, get_nearest_home_index(actor->currentPos.x, actor->currentPos.y, actor->currentPos.z));

    return ApiStatus_DONE2;
}

ApiStatus GetIndexFromHome(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 a1 = *args++;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    evt_set_variable(script, a1, get_nearest_home_index(actor->homePos.x, actor->homePos.y, actor->homePos.z));

    return ApiStatus_DONE2;
}

ApiStatus CountPlayerTargets(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 targetSelectionFlags = *args++;
    s32 outVar = *args++;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    evt_set_variable(script, outVar, count_targets(actor, get_nearest_home_index(actor->currentPos.x, actor->currentPos.y,
                 actor->currentPos.z), targetSelectionFlags));

    return ApiStatus_DONE2;
}

ApiStatus ForceHomePos(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    f32 x, y, z;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);
    z = evt_get_variable(script, *args++);

    actor = get_actor(actorID);
    actor->homePos.x = x;
    actor->currentPos.x = x;
    actor->homePos.y = y;
    actor->currentPos.y = y;
    actor->homePos.z = z;
    actor->currentPos.z = z;

    return ApiStatus_DONE2;
}

ApiStatus SetHomePos(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    f32 x, y, z;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);
    z = evt_get_variable(script, *args++);

    actor = get_actor(actorID);
    actor->homePos.x = x;
    actor->homePos.y = y;
    actor->homePos.z = z;

    return ApiStatus_DONE2;
}

ApiStatus SetGoalToTarget(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);

    set_goal_pos_to_part(&actor->state, actor->targetActorID, actor->targetPartIndex);

    return ApiStatus_DONE2;
}

ApiStatus SetPartGoalToTarget(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex = evt_get_variable(script, *args++);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);

    set_part_goal_to_actor_part(get_actor_part(actor, partIndex)->movement, actor->targetActorID, actor->targetPartIndex);

    return ApiStatus_DONE2;
}

ApiStatus SetGoalToFirstTarget(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    SelectableTarget* target;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);

    target = &actor->targetData[actor->targetIndexList[0]];
    set_goal_pos_to_part(&actor->state, target->actorID, target->partID);

    return ApiStatus_DONE2;
}

ApiStatus SetGoalPos(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    ActorMovement* walk;
    f32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);
    walk = &actor->state;

    if (*args == -12345678) {
        x = actor->state.goalPos.x;
    } else {
        x = evt_get_variable(script, *args);
    }

    *args++;
    if (*args == -12345678) {
        y = walk->goalPos.y;
    } else {
        y = evt_get_variable(script, *args);
    }

    *args++;
    if (*args == -12345678) {
        z = walk->goalPos.z;
    } else {
        z = evt_get_variable(script, *args);
    }

    walk->goalPos.x = x;
    walk->goalPos.y = y;
    walk->goalPos.z = z;

    return ApiStatus_DONE2;
}

ApiStatus SetIdleGoal(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    ActorMovement* fly;
    f32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);
    fly = &actor->fly;

    if (*args == -12345678) {
        x = actor->fly.goalPos.x;
    } else {
        x = evt_get_variable(script, *args);
    }

    *args++;
    if (*args == -12345678) {
        y = fly->goalPos.y;
    } else {
        y = evt_get_variable(script, *args);
    }

    *args++;
    if (*args == -12345678) {
        z = fly->goalPos.z;
    } else {
        z = evt_get_variable(script, *args);
    }

    fly->goalPos.x = x;
    fly->goalPos.y = y;
    fly->goalPos.z = z;
    return ApiStatus_DONE2;
}

ApiStatus AddGoalPos(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    f32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);

    actor = get_actor(actorID);
    actor->state.goalPos.x += x;
    actor->state.goalPos.y += y;
    actor->state.goalPos.z += z;

    return ApiStatus_DONE2;
}

ApiStatus GetGoalPos(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 outX, outY, outZ;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);

    outX = *args++;
    outY = *args++;
    outZ = *args++;

    x = actor->state.goalPos.x;
    y = actor->state.goalPos.y;
    z = actor->state.goalPos.z;

    evt_set_variable(script, outX, x);
    evt_set_variable(script, outY, y);
    evt_set_variable(script, outZ, z);

    return ApiStatus_DONE2;
}

// should this be renamed to GetFlyGoal ?
ApiStatus GetIdleGoal(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 outX, outY, outZ;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);

    outX = *args++;
    outY = *args++;
    outZ = *args++;

    x = actor->fly.goalPos.x;
    y = actor->fly.goalPos.y;
    z = actor->fly.goalPos.z;

    evt_set_variable(script, outX, x);
    evt_set_variable(script, outY, y);
    evt_set_variable(script, outZ, z);

    return ApiStatus_DONE2;
}

ApiStatus GetPartTarget(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex = evt_get_variable(script, *args++);
    Actor* actor;
    ActorPart* actorPart;
    s32 outX, outY, outZ;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
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

    evt_set_variable(script, outX, x);
    evt_set_variable(script, outY, y);
    evt_set_variable(script, outZ, z);

    return ApiStatus_DONE2;
}

ApiStatus GetActorPos(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 outX, outY, outZ;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);

    outX = *args++;
    outY = *args++;
    outZ = *args++;

    x = actor->currentPos.x;
    y = actor->currentPos.y;
    z = actor->currentPos.z;

    evt_set_variable(script, outX, x);
    evt_set_variable(script, outY, y);
    evt_set_variable(script, outZ, z);

    return ApiStatus_DONE2;
}

ApiStatus GetPartOffset(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex;
    ActorPart* actorPart;
    s32 outX, outY, outZ;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
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

    evt_set_variable(script, outX, x);
    evt_set_variable(script, outY, y);
    evt_set_variable(script, outZ, z);

    return ApiStatus_DONE2;
}

ApiStatus GetPartPos(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex;
    ActorPart* actorPart;
    s32 outX, outY, outZ;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    actorPart = get_actor_part(get_actor(actorID), partIndex);

    outX = *args++;
    outY = *args++;
    outZ = *args++;

    x = actorPart->currentPos.x;
    y = actorPart->currentPos.y;
    z = actorPart->currentPos.z;

    evt_set_variable(script, outX, x);
    evt_set_variable(script, outY, y);
    evt_set_variable(script, outZ, z);

    return ApiStatus_DONE2;
}

ApiStatus GetHomePos(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 outX, outY, outZ;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);

    outX = *args++;
    outY = *args++;
    outZ = *args++;

    x = actor->homePos.x;
    y = actor->homePos.y;
    z = actor->homePos.z;

    evt_set_variable(script, outX, x);
    evt_set_variable(script, outY, y);
    evt_set_variable(script, outZ, z);

    return ApiStatus_DONE2;
}

ApiStatus SetActorPos(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    f32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);
    z = evt_get_variable(script, *args++);

    actor = get_actor(actorID);
    actor->currentPos.x = x;
    actor->currentPos.y = y;
    actor->currentPos.z = z;

    return ApiStatus_DONE2;
}

ApiStatus SetPartPos(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 partIndex;
    f32 x, y, z;
    ActorPart* actorPart;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);
    z = evt_get_variable(script, *args++);

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

ApiStatus SetEnemyTargetOffset(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 partIndex;
    f32 x, y;
    ActorPart* actorPart;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);

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

ApiStatus SetAnimation(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    set_animation(actorID, evt_get_variable(script, *args++), evt_get_variable(script, *args++));

    return ApiStatus_DONE2;
}

ApiStatus GetAnimation(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 var1;
    ActorPart* actorPart;
    s32 a1;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    var1 = evt_get_variable(script, *args++);
    a1 = *args++;

    actorPart = get_actor_part(get_actor(actorID), var1);

    if (actorPart != NULL) {
        evt_set_variable(script, a1, actorPart->currentAnimation);
    }
    return ApiStatus_DONE2;
}

ApiStatus SetAnimationRate(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    set_animation_rate(actorID, evt_get_variable(script, *args++), evt_get_float_variable(script, *args++));

    return ApiStatus_DONE2;
}

ApiStatus SetActorYaw(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    set_actor_yaw(actorID, evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus GetActorYaw(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 a1;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    a1 = *args++;

    evt_set_variable(script, a1, get_actor(actorID)->yaw);
    return ApiStatus_DONE2;
}

ApiStatus SetPartYaw(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    set_part_yaw(actorID, evt_get_variable(script, *args++), evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus GetPartYaw(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex;
    s32 a1;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    a1 = *args++;

    evt_set_variable(script, a1, get_actor_part(get_actor(actorID), partIndex)->yaw);
    return ApiStatus_DONE2;
}

ApiStatus SetActorJumpGravity(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    f32 jumpAccel;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    jumpAccel = evt_get_float_variable(script, *args++);
    get_actor(actorID)->state.acceleration = jumpAccel;
    return ApiStatus_DONE2;
}

ApiStatus SetActorIdleJumpGravity(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    f32 flyJumpAccel;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    flyJumpAccel = evt_get_float_variable(script, *args++);
    get_actor(actorID)->fly.acceleration = flyJumpAccel;
    return ApiStatus_DONE2;
}

ApiStatus SetActorSpeed(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    f32 moveSpeed;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    moveSpeed = evt_get_float_variable(script, *args++);
    get_actor(actorID)->state.speed = moveSpeed;
    return ApiStatus_DONE2;
}

// SetActorFlySpeed?
ApiStatus SetActorIdleSpeed(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    f32 flySpeed;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    flySpeed = evt_get_float_variable(script, *args++);
    get_actor(actorID)->fly.speed = flySpeed;
    return ApiStatus_DONE2;
}

ApiStatus SetPartJumpGravity(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex;
    f32 jumpScale;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    jumpScale = evt_get_float_variable(script, *args++);

    get_actor_part(get_actor(actorID), partIndex)->movement->jumpScale = jumpScale;
    return ApiStatus_DONE2;
}

ApiStatus SetPartMoveSpeed(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex;
    f32 moveSpeed;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    moveSpeed = evt_get_float_variable(script, *args++);

    get_actor_part(get_actor(actorID), partIndex)->movement->moveSpeed = moveSpeed;
    return ApiStatus_DONE2;
}

ApiStatus SetJumpAnimations(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 jumpPartIndex;
    s32 animJumpRise;
    s32 animJumpFall;
    s32 animJumpLand;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    jumpPartIndex = evt_get_variable(script, *args++);
    animJumpRise = *args++;
    animJumpFall = *args++;
    animJumpLand = *args++;

    actor = get_actor(actorID);
    actor->state.jumpPartIndex = jumpPartIndex;
    actor->state.animJumpRise = animJumpRise;
    actor->state.animJumpFall = animJumpFall;
    actor->state.animJumpLand = animJumpLand;

    return ApiStatus_DONE2;
}

ApiStatus AddActorPos(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    f32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);

    actor = get_actor(actorID);
    actor->currentPos.x += x;
    actor->currentPos.y += y;
    actor->currentPos.z += z;

    return ApiStatus_DONE2;
}

ApiStatus SetActorDispOffset(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    f32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);

    actor = get_actor(actorID);
    actor->headOffset.x = x;
    actor->headOffset.y = y;
    actor->headOffset.z = z;

    return ApiStatus_DONE2;
}

ApiStatus GetPartDispOffset(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 partIndex;
    s32 outX, outY, outZ;
    f32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
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

    evt_set_variable(script, outX, x);
    evt_set_variable(script, outY, y);
    evt_set_variable(script, outZ, z);

    return ApiStatus_DONE2;
}

ApiStatus SetPartDispOffset(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 partIndex;
    f32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);

    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);
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

ApiStatus AddPartDispOffset(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 partIndex;
    f32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);

    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);
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

ApiStatus func_8026BF48(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    BattleStatus* battleStatus2 = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;

    if (evt_get_variable(script, *args++) != 0) {
        battleStatus->unk_8C++;
    } else if (battleStatus->unk_8C > 0) {
        battleStatus2->unk_8C--;
    }

    return ApiStatus_DONE2;
}

ApiStatus GetActorVar(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 var1;
    s32 a2;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    var1 = evt_get_variable(script, *args++);
    a2 = *args++;

    evt_set_variable(script, a2, get_actor(actorID)->state.varTable[var1]);

    return ApiStatus_DONE2;
}

ApiStatus SetActorVar(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 index;
    s32 val;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    index = evt_get_variable(script, *args++);
    val = evt_get_variable(script, *args++);

    get_actor(actorID)->state.varTable[index] = val;

    return ApiStatus_DONE2;
}

ApiStatus AddActorVar(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 index;
    s32 val;
    ActorState* state;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    index = evt_get_variable(script, *args++);
    val = evt_get_variable(script, *args++);

    state = &get_actor(actorID)->state;
    state->varTable[index] += val;

    return ApiStatus_DONE2;
}

ApiStatus GetPartMovementVar(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex;
    s32 tableIndex;
    s32 outVar;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    tableIndex = evt_get_variable(script, *args++);
    outVar = *args++;

    evt_set_variable(script, outVar, get_actor_part(get_actor(actorID), partIndex)->movement->varTable[tableIndex]);

    return ApiStatus_DONE2;
}

ApiStatus SetPartMovementVar(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex;
    s32 tableIndex;
    s32 val;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    tableIndex = evt_get_variable(script, *args++);
    val = evt_get_variable(script, *args++);

    get_actor_part(get_actor(actorID), partIndex)->movement->varTable[tableIndex] = val;

    return ApiStatus_DONE2;
}

ApiStatus AddPartMovementVar(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex;
    s32 tableIndex;
    s32 val;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    tableIndex = evt_get_variable(script, *args++);
    val = evt_get_variable(script, *args++);

    get_actor_part(get_actor(actorID), partIndex)->movement->varTable[tableIndex] += val;

    return ApiStatus_DONE2;
}

ApiStatus SetActorRotation(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);

    actor = get_actor(actorID);

    if (x != EVT_LIMIT) {
        actor->rotation.x = x;
    }

    if (y != EVT_LIMIT) {
        actor->rotation.y = y;
    }

    if (z != EVT_LIMIT) {
        actor->rotation.z = z;
    }

    return ApiStatus_DONE2;
}

ApiStatus SetActorRotationOffset(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);

    actor = get_actor(actorID);

    actor->rotationPivotOffset.x = x;
    actor->rotationPivotOffset.y = y;
    actor->rotationPivotOffset.z = z;

    return ApiStatus_DONE2;
}

ApiStatus GetActorRotation(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = *args++;
    y = *args++;
    z = *args++;

    actor = get_actor(actorID);

    evt_set_variable(script, x, actor->rotation.x);
    evt_set_variable(script, y, actor->rotation.y);
    evt_set_variable(script, z, actor->rotation.z);

    return ApiStatus_DONE2;
}

ApiStatus SetPartRotation(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);

    actorPart = get_actor_part(get_actor(actorID), partIndex);

    actorPart->rotation.x = x;
    actorPart->rotation.y = y;
    actorPart->rotation.z = z;

    return ApiStatus_DONE2;
}

ApiStatus SetPartRotationOffset(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);

    actorPart = get_actor_part(get_actor(actorID), partIndex);

    actorPart->rotationPivotOffset.x = x;
    actorPart->rotationPivotOffset.y = y;
    actorPart->rotationPivotOffset.z = z;

    return ApiStatus_DONE2;
}

ApiStatus GetPartRotation(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = *args++;
    y = *args++;
    z = *args++;

    actorPart = get_actor_part(get_actor(actorID), partIndex);

    evt_set_float_variable(script, x, actorPart->rotation.x);
    evt_set_float_variable(script, y, actorPart->rotation.y);
    evt_set_float_variable(script, z, actorPart->rotation.z);

    return ApiStatus_DONE2;
}

ApiStatus SetActorScale(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    f32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);

    actor = get_actor(actorID);

    actor->scale.x = x;
    actor->scale.y = y;
    actor->scale.z = z;

    return ApiStatus_DONE2;
}

ApiStatus SetActorScaleModifier(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    f32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);

    actor = get_actor(actorID);

    actor->scaleModifier.x = x;
    actor->scaleModifier.y = y;
    actor->scaleModifier.z = z;

    return ApiStatus_DONE2;
}

ApiStatus GetActorScale(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    f32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = *args++;
    y = *args++;
    z = *args++;

    actor = get_actor(actorID);

    evt_set_float_variable(script, x, actor->scale.x);
    evt_set_float_variable(script, y, actor->scale.y);
    evt_set_float_variable(script, z, actor->scale.z);

    return ApiStatus_DONE2;
}

ApiStatus SetPartScale(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    f32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);

    actorPart = get_actor_part(get_actor(actorID), partIndex);

    actorPart->scale.x = x;
    actorPart->scale.y = y;
    actorPart->scale.z = z;

    return ApiStatus_DONE2;
}

ApiStatus GetPartScale(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = *args++;
    y = *args++;
    z = *args++;

    actorPart = get_actor_part(get_actor(actorID), partIndex);

    evt_set_float_variable(script, x, actorPart->scale.x);
    evt_set_float_variable(script, y, actorPart->scale.y);
    evt_set_float_variable(script, z, actorPart->scale.z);

    return ApiStatus_DONE2;
}

ApiStatus GetBattleFlags(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.flags1);
    return ApiStatus_DONE2;
}

ApiStatus SetBattleFlagBits(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode a0 = *args++;

    if (evt_get_variable(script, *args)) {
        gBattleStatus.flags1 |= a0;
    } else {
        gBattleStatus.flags1 &= ~a0;
    }

    return ApiStatus_DONE2;
}

ApiStatus GetBattleFlags2(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.flags2);
    return ApiStatus_DONE2;
}

ApiStatus SetBattleFlagBits2(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode a0 = *args++;

    if (evt_get_variable(script, *args)) {
        BattleStatus* battleStatus = &gBattleStatus;
        battleStatus->flags2 |= a0;
    } else {
        BattleStatus* battleStatus = &gBattleStatus;
        battleStatus->flags2 &= ~a0;
    }

    return ApiStatus_DONE2;
}

ApiStatus SetActorFlags(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 a1;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    a1 = *args++;
    get_actor(actorID)->flags = a1;

    return ApiStatus_DONE2;
}

ApiStatus SetActorFlagBits(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 a1;
    s32 var1;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    a1 = *args++;
    var1 = evt_get_variable(script, *args++);
    actor = get_actor(actorID);

    if (var1 != 0) {
        actor->flags |= a1;
    } else {
        actor->flags &= ~a1;
    }

    return ApiStatus_DONE2;
}

ApiStatus GetActorFlags(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 a1;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    a1 = *args++;

    evt_set_variable(script, a1, get_actor(actorID)->flags);

    return ApiStatus_DONE2;
}

ApiStatus SetPartFlags(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 a1;
    s32 partIndex;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    a1 = *args++;

    get_actor_part(get_actor(actorID), partIndex)->flags = a1;

    return ApiStatus_DONE2;
}

ApiStatus SetPartFlagBits(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 bits;
    s32 partIndex;
    s32 cond;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    bits = *args++;
    cond = evt_get_variable(script, *args++);

    actorPart = get_actor_part(get_actor(actorID), partIndex);

    if (cond != 0) {
        actorPart->flags |= bits;
    } else {
        actorPart->flags &= ~bits;
    }

    return ApiStatus_DONE2;
}

ApiStatus SetPartTargetFlags(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 flags;
    s32 partIndex;
    s32 cond;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    flags = *args++;

    get_actor_part(get_actor(actorID), partIndex)->targetFlags = flags;

    return ApiStatus_DONE2;
}

ApiStatus SetPartTargetFlagBits(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 partIndex;
    s32 bits;
    s32 cond;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    bits = *args++;
    cond = evt_get_variable(script, *args++);

    actorPart = get_actor_part(get_actor(actorID), partIndex);

    if (cond != 0) {
        actorPart->targetFlags |= bits;
    } else {
        actorPart->targetFlags &= ~bits;
    }

    return ApiStatus_DONE2;
}

ApiStatus GetPartFlags(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex;
    ActorPart* actorPart;
    s32 a2;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    a2 = *args++;

    evt_set_variable(script, a2, get_actor_part(get_actor(actorID), partIndex)->flags);

    return ApiStatus_DONE2;
}

ApiStatus GetPartTargetFlags(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex;
    ActorPart* actorPart;
    s32 a2;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    a2 = *args++;

    evt_set_variable(script, a2, get_actor_part(get_actor(actorID), partIndex)->targetFlags);

    return ApiStatus_DONE2;
}

ApiStatus SetPartEventFlags(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 flags;
    s32 partIndex;
    s32 cond;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    flags = *args++;

    get_actor_part(get_actor(actorID), partIndex)->eventFlags = flags;

    return ApiStatus_DONE2;
}

ApiStatus SetPartEventBits(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 partIndex;
    s32 bits;
    s32 cond;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    bits = *args++;
    cond = evt_get_variable(script, *args++);

    actorPart = get_actor_part(get_actor(actorID), partIndex);

    if (cond != 0) {
        actorPart->eventFlags |= bits;
    } else {
        actorPart->eventFlags &= ~bits;
    }

    return ApiStatus_DONE2;
}

ApiStatus GetPartEventFlags(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex;
    ActorPart* actorPart;
    s32 a2;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    a2 = *args++;

    evt_set_variable(script, a2, get_actor_part(get_actor(actorID), partIndex)->eventFlags);

    return ApiStatus_DONE2;
}

ApiStatus func_8026D51C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 flags;
    s32 partIndex;
    s32 cond;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    flags = *args++;

    get_actor_part(get_actor(actorID), partIndex)->partFlags3 = flags;

    return ApiStatus_DONE2;
}

ApiStatus func_8026D5A4(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 partIndex;
    s32 bits;
    s32 cond;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    bits = *args++;
    cond = evt_get_variable(script, *args++);

    actorPart = get_actor_part(get_actor(actorID), partIndex);

    if (cond != 0) {
        actorPart->partFlags3 |= bits;
    } else {
        actorPart->partFlags3 &= ~bits;
    }

    return ApiStatus_DONE2;
}

ApiStatus HPBarToHome(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
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

ApiStatus HPBarToCurrent(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
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

ApiStatus func_8026D8EC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    func_80266AF8(get_actor(actorID));

    return ApiStatus_DONE2;
}

ApiStatus func_8026D940(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 x, y;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);

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

ApiStatus func_8026DA94(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 a, b, c, d;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    a = evt_get_variable(script, *args++);
    b = evt_get_variable(script, *args++);
    c = evt_get_variable(script, *args++);
    d = evt_get_variable(script, *args++);

    actor = get_actor(actorID);
    actor->unk_194 = a;
    actor->unk_195 = b;
    actor->unk_196 = c;
    actor->unk_197 = d;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "197F40", SummonEnemy);

ApiStatus GetOwnerID(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, script->owner1.actorID);
    return ApiStatus_DONE2;
}

ApiStatus SetOwnerID(Evt* script, s32 isInitialCall) {
    script->owner1.actorID = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus ActorExists(Evt* script, s32 isInitialCall) {
    Bytecode isExist;
    Actor* partner = gBattleStatus.partnerActor;
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    isExist = get_actor(actorID) != NULL;
    if ((actorID == ACTOR_PARTNER) && (partner == NULL)) {
        isExist = FALSE;
    }

    evt_set_variable(script, *args++, isExist);
    return ApiStatus_DONE2;
}

ApiStatus func_8026DEF0(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex = evt_get_variable(script, *args++);
    s32 a2 = *args++;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    evt_set_variable(script, a2, get_actor_part(get_actor(actorID), partIndex)->unk_84);

    return ApiStatus_DONE2;
}

ApiStatus func_8026DF88(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex = evt_get_variable(script, *args++);
    s32 a2 = *args++;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    evt_set_variable(script, a2, get_actor_part(get_actor(actorID), partIndex)->unk_8C);

    return ApiStatus_DONE2;
}

ApiStatus func_8026E020(Evt* script, s32 isInitialCall) {
    s32 a0 = *script->ptrReadPos;

    gBattleStatus.unk_70 = a0;
    return ApiStatus_DONE2;
}

ApiStatus func_8026E038(Evt* script, s32 isInitialCall) {
    gBattleStatus.unk_74 = *script->ptrReadPos;
    return ApiStatus_DONE2;
}

ApiStatus SetBattleInputMask(Evt* script, s32 isInitialCall) {
    gBattleStatus.inputBitmask = *script->ptrReadPos;
    return ApiStatus_DONE2;
}

ApiStatus SetBattleInputButtons(Evt* script, s32 isInitialCall) {
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

ApiStatus CheckButtonPress(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode buttons = *args++;
    Bytecode out = *args;
    s32 buttonsPressed = gBattleStatus.currentButtonsPressed;

    evt_set_variable(script, out, (buttonsPressed & buttons) != 0);
    return ApiStatus_DONE2;
}

ApiStatus CheckButtonHeld(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode buttons = *args++;
    Bytecode out = *args;
    s32 buttonsHeld = gBattleStatus.currentButtonsHeld;

    evt_set_variable(script, out, (buttonsHeld & buttons) != 0);
    return ApiStatus_DONE2;
}

ApiStatus CheckButtonDown(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Bytecode buttons = *args++;
    Bytecode out = *args;
    s32 buttonsDown = gBattleStatus.currentButtonsDown;

    evt_set_variable(script, out, (buttonsDown & buttons) != 0);
    return ApiStatus_DONE2;
}

ApiStatus GetBattleState(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gBattleState);
    return ApiStatus_DONE2;
}

ApiStatus SetBattleState(Evt* script, s32 isInitialCall) {
    btl_set_state(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}

ApiStatus WaitForState(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32* ptrReadPos = script->ptrReadPos;
    s32 temp_v0;

    if (isInitialCall) {
        temp_v0 = evt_get_variable(script, *ptrReadPos);
        if (!temp_v0) {
            battleStatus->unk_95 = 0;
            return ApiStatus_DONE2;
        }
        battleStatus->unk_95 = temp_v0;
    }

    temp_v0 = battleStatus->unk_95;
    if (temp_v0) {
        return (gBattleState == temp_v0) * 2;
    }

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "197F40", CancelEnemyTurn);

ApiStatus func_8026E260(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);

    evt_get_variable(script, *args++);
    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    get_actor(actorID);

    return ApiStatus_DONE2;
}

ApiStatus PlayerCreateTargetList(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);

    gBattleStatus.currentTargetListFlags = *args;
    player_create_target_list(actor);

    return ApiStatus_DONE2;
}

ApiStatus EnemyCreateTargetList(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);

    gBattleStatus.currentTargetListFlags = *args;
    enemy_create_target_list(actor);

    return ApiStatus_DONE2;
}

ApiStatus InitTargetIterator(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    SelectableTarget* selectableTarget = &actor->targetData[actor->targetIndexList[actor->selectedTargetIndex]];

    actor->targetActorID = selectableTarget->actorID;
    actor->targetPartIndex = selectableTarget->partID;

    return ApiStatus_DONE2;
}

ApiStatus SetOwnerTarget(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.enemyID);
    s16 actorID = evt_get_variable(script, *args++);

    actor->targetPartIndex = evt_get_variable(script, *args++);
    actor->targetActorID = actorID;

    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "197F40", ChooseNextTarget);

INCLUDE_ASM(s32, "197F40", func_8026E558);

ApiStatus GetTargetListLength(Evt* script) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args, get_actor(script->owner1.actorID)->targetListLength);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "197F40", GetOwnerTarget);

INCLUDE_ASM(s32, "197F40", func_8026E914);

ApiStatus GetPlayerActorID(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.attackerActorID);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "197F40", func_8026E9A0);

INCLUDE_ASM(s32, "197F40", GetDistanceToGoal);

INCLUDE_ASM(s32, "197F40", func_8026EA7C);

INCLUDE_ASM(s32, "197F40", func_8026EB20);

INCLUDE_ASM(s32, "197F40", func_8026EBF8);

INCLUDE_ASM(s32, "197F40", func_8026ED20);

INCLUDE_ASM(s32, "197F40", func_8026EDE4);

INCLUDE_ASM(s32, "197F40", AddActorDecoration);

INCLUDE_ASM(s32, "197F40", RemoveActorDecoration);

INCLUDE_ASM(s32, "197F40", ModifyActorDecoration);

INCLUDE_ASM(s32, "197F40", UseIdleAnimation);

INCLUDE_ASM(s32, "197F40", func_8026F1A0);

INCLUDE_ASM(s32, "197F40", GetStatusFlags);

ApiStatus RemovePlayerBuffs(Evt* script, s32 isInitialCall) {
    remove_player_buffs(*script->ptrReadPos);
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "197F40", SetPartAlpha);

INCLUDE_ASM(s32, "197F40", CreatePartShadow);

INCLUDE_ASM(s32, "197F40", RemovePartShadow);

ApiStatus func_8026F60C(Evt* script, s32 isInitialCall) {
    gBattleStatus.unk_8D = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

ApiStatus SetBattleVar(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 varIdx = evt_get_variable(script, *args++);

    gBattleStatus.varTable[varIdx] = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

ApiStatus GetBattleVar(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 varIdx = evt_get_variable(script, *args++);

    evt_set_variable(script, *args++, gBattleStatus.varTable[varIdx]);
    return ApiStatus_DONE2;
}


ApiStatus ResetAllActorSounds(Evt* script, s32 isInitialCall) {
    s32 actorID = evt_get_variable(script, *script->ptrReadPos);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    reset_all_actor_sounds(get_actor(actorID));
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "197F40", SetActorSounds);

INCLUDE_ASM(s32, "197F40", ResetActorSounds);

INCLUDE_ASM(s32, "197F40", SetPartSounds);

ApiStatus SetActorType(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32* actorID = evt_get_variable(script, *args++);
    Actor* enemy;
    s32 actorType;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.enemyID;
    }

    actorType = evt_get_variable(script, *args++);
    enemy = get_actor(actorID);

    if (is_actor_hp_bar_visible(enemy)) {
        load_tattle_flags(actorType);
    }

    enemy->actorType = actorType;
    return ApiStatus_DONE2;
}


ApiStatus ShowShockEffect(Evt* script, s32 isInitialCall) {
    s32 actorID = evt_get_variable(script, *script->ptrReadPos);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    func_80251474(get_actor(actorID));
    return ApiStatus_DONE2;
}

ApiStatus GetActorAttackBoost(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 enemyID = evt_get_variable(script, *args++);
    Bytecode attackBoost;

    if (enemyID == ACTOR_SELF) {
        enemyID = script->owner1.enemyID;
    }

    attackBoost = *args++;
    evt_set_variable(script, attackBoost, get_actor(enemyID)->attackBoost);
    return ApiStatus_DONE2;
}

ApiStatus GetActorDefenseBoost(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 enemyID = evt_get_variable(script, *args++);
    Bytecode defenseBoost;

    if (enemyID == ACTOR_SELF) {
        enemyID = script->owner1.enemyID;
    }

    defenseBoost = *args++;
    evt_set_variable(script, defenseBoost, get_actor(enemyID)->defenseBoost);
    return ApiStatus_DONE2;
}

ApiStatus BoostAttack(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID;
    Actor* actor;
    s32 flags;
    s32 flags2;
    f32 x1, y1, z1;
    f32 x2, y2, z2;
    s32 attackBoost;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        actorID = evt_get_variable(script, *args++);
        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }
        attackBoost = evt_get_variable(script, *args++);
        actor = get_actor(actorID);
        script->functionTemp[1] = (s32) actor;
        script->functionTemp[2] = attackBoost;

        func_8024E40C(8);
        btl_cam_set_zoffset(0xC);
        btl_cam_target_actor(actor->actorID);
        btl_cam_set_zoom(0xFA);
        btl_cam_move(0xA);
        func_8024E60C();
        if (actor->flags & ACTOR_FLAG_HP_OFFSET_BELOW) {
            btl_cam_set_zoffset(0);
        }
        D_8029FBD4 = 1;
        script->functionTemp[3] = 5;
        script->functionTemp[0] = 1;
    }
    get_actor(script->owner1.actorID);
    actor = (Actor*) script->functionTemp[1];
    attackBoost = script->functionTemp[2];

    flags = actor->flags;
    x1 = actor->currentPos.x + actor->headOffset.x;
    if (flags & ACTOR_FLAG_HP_OFFSET_BELOW) {
        y1 = actor->currentPos.y + actor->headOffset.y - actor->size.y / 2;
    } else if (!(flags & ACTOR_FLAG_8000)) {
        y1 = actor->currentPos.y + actor->headOffset.y + actor->size.y / 2;
    } else {
        y1 = actor->currentPos.y + actor->headOffset.y + actor->size.y;
    }
    z1 = actor->currentPos.z + actor->headOffset.z + 10.0f;

    flags2 = actor->flags;
    x2 = actor->currentPos.x + actor->headOffset.x + actor->size.x / 2;
    if (flags2 & ACTOR_FLAG_HP_OFFSET_BELOW) {
        y2 = actor->currentPos.y + actor->headOffset.y - actor->size.y;
    } else if (!(flags2 & ACTOR_FLAG_8000)) {
        y2 = actor->currentPos.y + actor->headOffset.y + actor->size.y;
    } else {
        y2 = actor->currentPos.y + actor->headOffset.y + actor->size.y * 2;
    }
    z2 = actor->currentPos.z + actor->headOffset.z + 10.0f;

    switch (script->functionTemp[0]) {
        case 1:
            if (script->functionTemp[3] == 0) {
                playFX_33(2, x1, y1, z1, 1.0f, 30);
                func_8024E3D8(0x13);
                script->functionTemp[3] = 30;
                script->functionTemp[0] = 2;
            } else {
                script->functionTemp[3]--;
                break;
            }
            break;
        case 2:
            if (script->functionTemp[3] == 0) {
                dispatch_event_actor(actor, EVENT_SWAP_PARTNER);
                func_8024E40C(2);
                btl_cam_move(0xF);
                actor->isGlowing = 1;
                actor->attackBoost += attackBoost;
                if (actor->attackBoost > 20) {
                    actor->attackBoost = 20;
                }
                playFX_56(attackBoost - 1, x2, y2, z2, 1.0f, 60);
                script->functionTemp[3] = 15;
                script->functionTemp[0] = 3;
            } else {
                script->functionTemp[3]--;
                break;
            }
            break;
        case 3:
            if (script->functionTemp[3] == 0) {
                btl_show_variable_battle_message(0x1D, 60, attackBoost);
                script->functionTemp[0] = 4;
            } else {
                script->functionTemp[3]--;
                break;
            }
            break;
        case 4:
            if (btl_is_popup_displayed() == 0) {
                func_8024E40C(2);
                script->functionTemp[3] = 10;
                script->functionTemp[0] = 5;
            }
            break;
        case 5:
            if (script->functionTemp[3] != 0) {
                script->functionTemp[3]--;
                break;
            }
            if ((actor->onHitScript == NULL) || (does_script_exist(actor->onHitID) == 0)) {
                D_8029FBD4 = 0;
                return ApiStatus_DONE2;
            }
    }
            return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "197F40", BoostDefense);

INCLUDE_ASM(s32, "197F40", VanishActor);

INCLUDE_ASM(s32, "197F40", ElectrifyActor);

INCLUDE_ASM(s32, "197F40", HealActor);

ApiStatus WaitForBuffDone(Evt* script, s32 isInitialCall) {
    return (D_8029FBD4 == 0) * ApiStatus_DONE2;
}

ApiStatus CopyBuffs(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actorFrom;
    Actor* actorTo;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.enemyID;
    }
    actorFrom = get_actor(actorID);

    actorID = evt_get_variable(script, *args++);
    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.enemyID;
    }
    actorTo = get_actor(actorID);

    actorTo->isGlowing = actorFrom->isGlowing;
    actorTo->attackBoost = actorFrom->attackBoost;
    actorTo->defenseBoost = actorFrom->defenseBoost;
    actorTo->chillOutAmount = actorFrom->chillOutAmount;
    actorTo->chillOutTurns = actorFrom->chillOutTurns;

    return ApiStatus_DONE2;
}
