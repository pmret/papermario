#include "common.h"
#include "effects.h"
#include "battle/battle.h"

extern s32 IsGroupHeal;
extern s8 ApplyingBuff;

s32 count_targets(Actor* actor, s32 targetHomeIndex, s32 targetSelectionFlags) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->sampleTargetHomeIndex = targetHomeIndex;
    battleStatus->curTargetListFlags = targetSelectionFlags;
    create_current_pos_target_list(actor);
    return actor->targetListLength;
}

s32 get_nearest_home_index(f32 x, f32 y, f32 z) {
    s32 row;
    s32 col;

    if (y < 40.0f) {
        row = 0;
    } else if (y < 85.0f) {
        row = 1;
    } else if (y < 100.0f) {
        row = 2;
    } else {
        row = 3;
    }

    if (x < 25.0f) {
        col = 0;
    } else if (x < 65.0f) {
        col = 1;
    } else if (x < 105.0f) {
        col = 2;
    } else {
        col = 3;
    }

    return col | (row << 2);
}

void set_goal_pos_to_part(ActorState* state, s32 actorID, s32 partID) {
    s32 actorClass = actorID & ACTOR_CLASS_MASK;
    Actor* actor = get_actor(actorID);
    ActorPart* part;

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            part = get_actor_part(actor, 0);
            state->goalPos.x = actor->curPos.x + part->partOffset.x * actor->scalingFactor;
            state->goalPos.y = actor->curPos.y + part->partOffset.y * actor->scalingFactor;
            state->goalPos.z = actor->curPos.z + 10.0f;
            if (actor->stoneStatus == STATUS_KEY_STONE) {
                state->goalPos.y -= actor->scalingFactor * 5.0f;
            }
            break;
        case ACTOR_CLASS_PARTNER:
        case ACTOR_CLASS_ENEMY:
            part = get_actor_part(actor, partID);
            if (!(part->flags & ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)) {
                state->goalPos.x = actor->curPos.x + (part->partOffset.x + part->targetOffset.x) * actor->scalingFactor;
                if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
                    state->goalPos.y = actor->curPos.y + (part->partOffset.y + part->targetOffset.y) * actor->scalingFactor;
                } else {
                    state->goalPos.y = actor->curPos.y + (-part->partOffset.y - part->targetOffset.y) * actor->scalingFactor;
                }
                state->goalPos.z = actor->curPos.z + part->partOffset.z + 10.0f;
            } else {
                state->goalPos.x = part->absolutePos.x + part->targetOffset.x;
                if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
                    state->goalPos.y = part->absolutePos.y + part->targetOffset.y * actor->scalingFactor;
                } else {
                    state->goalPos.y = part->absolutePos.y - part->targetOffset.y * actor->scalingFactor;
                }
                state->goalPos.z = part->absolutePos.z + 10.0f;
            }
            break;
    }
}

void set_part_goal_to_actor_part(ActorPartMovement* movement, s32 actorID, s32 partID) {
    s32 actorClass = actorID & ACTOR_CLASS_MASK;
    Actor* actor = get_actor(actorID);
    ActorPart* part;

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            part = get_actor_part(actor, 0);
            part->movement->goalPos.x = actor->curPos.x + part->partOffset.x * actor->scalingFactor;
            part->movement->goalPos.y = actor->curPos.y + part->partOffset.y * actor->scalingFactor;
            part->movement->goalPos.z = actor->curPos.z;
            break;
        case ACTOR_CLASS_PARTNER:
        case ACTOR_CLASS_ENEMY:
            part = get_actor_part(actor, partID);
            if (!(part->flags & ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)) {
                part->movement->goalPos.x = actor->curPos.x + (part->partOffset.x + part->targetOffset.x) * actor->scalingFactor;
                if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
                    part->movement->goalPos.y = actor->curPos.y + (part->partOffset.y + part->targetOffset.y) * actor->scalingFactor;
                } else {
                    part->movement->goalPos.y = actor->curPos.y + (-part->partOffset.y - part->targetOffset.y) * actor->scalingFactor;
                }
                part->movement->goalPos.z = actor->curPos.z + part->partOffset.z;
            } else {
                part->movement->goalPos.x = part->absolutePos.x + part->targetOffset.x;
                if (!(actor->flags & ACTOR_FLAG_UPSIDE_DOWN)) {
                    part->movement->goalPos.y = part->absolutePos.y + part->targetOffset.y * actor->scalingFactor;
                } else {
                    part->movement->goalPos.y = part->absolutePos.y - part->targetOffset.y * actor->scalingFactor;
                }
                part->movement->goalPos.z = part->absolutePos.z;
            }
            break;
    }
}

void set_actor_current_position(s32 actorID, f32 x, f32 y, f32 z) {
    Actor* actor = get_actor(actorID);

    actor->curPos.x = x;
    actor->curPos.y = y;
    actor->curPos.z = z;
}

void set_part_absolute_position(s32 actorID, s32 partID, f32 x, f32 y, f32 z) {
    Actor* actor = get_actor(actorID);
    ActorPart* actorPart;

    switch (actorID & ACTOR_CLASS_MASK) {
        case ACTOR_CLASS_PLAYER:
            actor->curPos.x = x;
            actor->curPos.y = y;
            actor->curPos.z = z;
            break;
        case ACTOR_CLASS_PARTNER:
        case ACTOR_CLASS_ENEMY:
            actorPart = get_actor_part(actor, partID);
            actorPart->absolutePos.x = x;
            actorPart->absolutePos.y = y;
            actorPart->absolutePos.z = z;
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
    s32 actorClass = actorID & ACTOR_CLASS_MASK;
    u32 idIdx = (u8)actorID;

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            ret = battleStatus->playerActor;
            break;
        case ACTOR_CLASS_PARTNER:
            ret = battleStatus->partnerActor;
            break;
        case ACTOR_CLASS_ENEMY:
            ret = battleStatus->enemyActors[idIdx];
            break;
    }
    return ret;
}

API_CALLABLE(LoadBattleSection) {
    BattleArea* battleArea = &gBattleAreas[evt_get_variable(script, *script->ptrReadPos)];

    dma_copy(battleArea->dmaStart, battleArea->dmaEnd, battleArea->dmaDest);
    return ApiStatus_DONE1;
}


API_CALLABLE(GetBattlePhase) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.battlePhase);
    return ApiStatus_DONE2;
}

API_CALLABLE(GetLastElement) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.curAttackElement);
    return ApiStatus_DONE2;
}

API_CALLABLE(GetDamageSource) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.curDamageSource);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetDamageSource) {
    s32 damageSource = *script->ptrReadPos;

    gBattleStatus.curDamageSource = damageSource;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetGoalToHome) {
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

API_CALLABLE(SetIdleGoalToHome) {
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

API_CALLABLE(SetGoalToIndex) {
    s32* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 index = evt_get_variable(script, *args++);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    actor->state.goalPos.x = StandardActorHomePositions[index].x;
    actor->state.goalPos.y = StandardActorHomePositions[index].y;
    actor->state.goalPos.z = StandardActorHomePositions[index].z;

    return ApiStatus_DONE2;
}

API_CALLABLE(GetIndexFromPos) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 outVar = *args++;
    Actor* actor;
    s32 homeIdx;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    homeIdx = get_nearest_home_index(actor->curPos.x, actor->curPos.y, actor->curPos.z);
    evt_set_variable(script, outVar, homeIdx);

    return ApiStatus_DONE2;
}

API_CALLABLE(GetIndexFromHome) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 outVar = *args++;
    Actor* actor;
    s32 homeIdx;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    homeIdx = get_nearest_home_index(actor->homePos.x, actor->homePos.y, actor->homePos.z);
    evt_set_variable(script, outVar, homeIdx);

    return ApiStatus_DONE2;
}

API_CALLABLE(CountTargets) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 targetSelectionFlags = *args++;
    s32 outVar = *args++;
    Actor* actor;
    s32 homeIdx;
    s32 numTargets;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    homeIdx = get_nearest_home_index(actor->curPos.x, actor->curPos.y, actor->curPos.z);
    numTargets = count_targets(actor, homeIdx, targetSelectionFlags);
    evt_set_variable(script, outVar, numTargets);

    return ApiStatus_DONE2;
}

API_CALLABLE(ForceHomePos) {
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
    actor->curPos.x = actor->homePos.x = x;
    actor->curPos.y = actor->homePos.y = y;
    actor->curPos.z = actor->homePos.z = z;

    return ApiStatus_DONE2;
}

API_CALLABLE(SetHomePos) {
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

API_CALLABLE(SetGoalToTarget) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);

    set_goal_pos_to_part(&actor->state, actor->targetActorID, actor->targetPartID);

    return ApiStatus_DONE2;
}

API_CALLABLE(SetPartGoalToTarget) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);

    set_part_goal_to_actor_part(get_actor_part(actor, partID)->movement, actor->targetActorID, actor->targetPartID);

    return ApiStatus_DONE2;
}

API_CALLABLE(SetGoalToFirstTarget) {
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

API_CALLABLE(SetGoalPos) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    ActorState* walk;
    f32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);
    walk = &actor->state;

    if (*args == ACTOR_API_SKIP_ARG) {
        x = walk->goalPos.x;
    } else {
        x = evt_get_variable(script, *args);
    }

    *args++;
    if (*args == ACTOR_API_SKIP_ARG) {
        y = walk->goalPos.y;
    } else {
        y = evt_get_variable(script, *args);
    }

    *args++;
    if (*args == ACTOR_API_SKIP_ARG) {
        z = walk->goalPos.z;
    } else {
        z = evt_get_variable(script, *args);
    }

    walk->goalPos.x = x;
    walk->goalPos.y = y;
    walk->goalPos.z = z;

    return ApiStatus_DONE2;
}

API_CALLABLE(SetIdleGoal) {
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

    if (*args == ACTOR_API_SKIP_ARG) {
        x = actor->fly.goalPos.x;
    } else {
        x = evt_get_variable(script, *args);
    }

    *args++;
    if (*args == ACTOR_API_SKIP_ARG) {
        y = fly->goalPos.y;
    } else {
        y = evt_get_variable(script, *args);
    }

    *args++;
    if (*args == ACTOR_API_SKIP_ARG) {
        z = fly->goalPos.z;
    } else {
        z = evt_get_variable(script, *args);
    }

    fly->goalPos.x = x;
    fly->goalPos.y = y;
    fly->goalPos.z = z;
    return ApiStatus_DONE2;
}

API_CALLABLE(AddGoalPos) {
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

API_CALLABLE(GetGoalPos) {
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
API_CALLABLE(GetIdleGoal) {
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

API_CALLABLE(GetPartTarget) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    Actor* actor;
    ActorPart* actorPart;
    s32 outX, outY, outZ;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    actorPart = get_actor_part(actor, partID);

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

API_CALLABLE(GetActorPos) {
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

    x = actor->curPos.x;
    y = actor->curPos.y;
    z = actor->curPos.z;

    evt_set_variable(script, outX, x);
    evt_set_variable(script, outY, y);
    evt_set_variable(script, outZ, z);

    return ApiStatus_DONE2;
}

API_CALLABLE(GetPartOffset) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID;
    ActorPart* actorPart;
    s32 outX, outY, outZ;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    actorPart = get_actor_part(get_actor(actorID), partID);

    outX = *args++;
    outY = *args++;
    outZ = *args++;

    if (!(actorPart->flags & ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)) {
        x = actorPart->partOffset.x;
        y = actorPart->partOffset.y;
        z = actorPart->partOffset.z;
    } else {
        x = actorPart->absolutePos.x;
        y = actorPart->absolutePos.y;
        z = actorPart->absolutePos.z;
    }

    evt_set_variable(script, outX, x);
    evt_set_variable(script, outY, y);
    evt_set_variable(script, outZ, z);

    return ApiStatus_DONE2;
}

API_CALLABLE(GetPartPos) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID;
    ActorPart* actorPart;
    s32 outX, outY, outZ;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    actorPart = get_actor_part(get_actor(actorID), partID);

    outX = *args++;
    outY = *args++;
    outZ = *args++;

    x = actorPart->curPos.x;
    y = actorPart->curPos.y;
    z = actorPart->curPos.z;

    evt_set_variable(script, outX, x);
    evt_set_variable(script, outY, y);
    evt_set_variable(script, outZ, z);

    return ApiStatus_DONE2;
}

API_CALLABLE(GetHomePos) {
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

API_CALLABLE(SetActorPos) {
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
    actor->curPos.x = x;
    actor->curPos.y = y;
    actor->curPos.z = z;

    return ApiStatus_DONE2;
}

API_CALLABLE(SetPartPos) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 partID;
    f32 x, y, z;
    ActorPart* actorPart;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);
    z = evt_get_variable(script, *args++);

    actor = get_actor(actorID);

    switch (actorID & ACTOR_CLASS_MASK) {
        case ACTOR_CLASS_PLAYER:
            actor->curPos.x = x;
            actor->curPos.y = y;
            actor->curPos.z = z;
            break;
        case ACTOR_CLASS_PARTNER:
        case ACTOR_CLASS_ENEMY:
            actorPart = get_actor_part(actor, partID);

            if (!(actorPart->flags & ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)) {
                actorPart->partOffset.x = x;
                actorPart->partOffset.y = y;
                actorPart->partOffset.z = z;
            } else {
                actorPart->absolutePos.x = x;
                actorPart->absolutePos.y = y;
                actorPart->absolutePos.z = z;
            }
            break;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(SetEnemyTargetOffset) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 partID;
    f32 x, y;
    ActorPart* actorPart;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);

    actor = get_actor(actorID);

    switch (actorID & ACTOR_CLASS_MASK) {
        case ACTOR_CLASS_PLAYER:
            break;
        case ACTOR_CLASS_PARTNER:
        case ACTOR_CLASS_ENEMY:
            actorPart = get_actor_part(actor, partID);
            actorPart->targetOffset.x = x;
            actorPart->targetOffset.y = y;
            break;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(SetAnimation) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 partID;
    AnimID animID;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    animID = evt_get_variable(script, *args++);

    set_actor_anim(actorID, partID, animID);

    return ApiStatus_DONE2;
}

API_CALLABLE(GetAnimation) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID;
    ActorPart* actorPart;
    s32 outVar;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    partID = evt_get_variable(script, *args++);
    outVar = *args++;

    actorPart = get_actor_part(get_actor(actorID), partID);

    if (actorPart != NULL) {
        evt_set_variable(script, outVar, actorPart->curAnimation);
    }
    return ApiStatus_DONE2;
}

API_CALLABLE(SetAnimationRate) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 partID;
    f32 rate;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    rate = evt_get_float_variable(script, *args++);

    set_actor_anim_rate(actorID, partID, rate);

    return ApiStatus_DONE2;
}

API_CALLABLE(SetActorYaw) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    set_actor_yaw(actorID, evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

API_CALLABLE(GetActorYaw) {
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

API_CALLABLE(SetPartYaw) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID;
    s32 yaw;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    yaw = evt_get_variable(script, *args++);

    set_part_yaw(actorID, partID, yaw);
    return ApiStatus_DONE2;
}

API_CALLABLE(GetPartYaw) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID;
    s32 a1;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    a1 = *args++;

    evt_set_variable(script, a1, get_actor_part(get_actor(actorID), partID)->yaw);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetActorJumpGravity) {
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

API_CALLABLE(SetActorIdleJumpGravity) {
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

API_CALLABLE(SetActorSpeed) {
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
API_CALLABLE(SetActorIdleSpeed) {
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

API_CALLABLE(SetPartJumpGravity) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID;
    f32 jumpScale;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    jumpScale = evt_get_float_variable(script, *args++);

    get_actor_part(get_actor(actorID), partID)->movement->jumpScale = jumpScale;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetPartMoveSpeed) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID;
    f32 moveSpeed;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    moveSpeed = evt_get_float_variable(script, *args++);

    get_actor_part(get_actor(actorID), partID)->movement->moveSpeed = moveSpeed;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetJumpAnimations) {
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

API_CALLABLE(AddActorPos) {
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
    actor->curPos.x += x;
    actor->curPos.y += y;
    actor->curPos.z += z;

    return ApiStatus_DONE2;
}

API_CALLABLE(SetActorDispOffset) {
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

API_CALLABLE(GetPartDispOffset) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 partID;
    s32 outX, outY, outZ;
    f32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    outX = *args++;
    outY = *args++;
    outZ = *args++;

    actorPart = get_actor_part(get_actor(actorID), partID);

    if (!(actorPart->flags & ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)) {
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

API_CALLABLE(SetPartDispOffset) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 partID;
    f32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);

    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);
    actorPart = get_actor_part(get_actor(actorID), partID);

    if (!(actorPart->flags & ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)) {
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

API_CALLABLE(AddPartDispOffset) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 partID;
    f32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);

    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);
    actorPart = get_actor_part(get_actor(actorID), partID);

    if (!(actorPart->flags & ACTOR_PART_FLAG_USE_ABSOLUTE_POSITION)) {
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

API_CALLABLE(FreezeBattleState) {
    BattleStatus* battleStatus = &gBattleStatus;
    BattleStatus* battleStatus2 = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    b32 increaseFreeze = evt_get_variable(script, *args++);

    if (increaseFreeze) {
        battleStatus->stateFreezeCount++;
    } else if (battleStatus->stateFreezeCount > 0) {
        battleStatus2->stateFreezeCount--;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(GetActorVar) {
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

API_CALLABLE(SetActorVar) {
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

API_CALLABLE(AddActorVar) {
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

API_CALLABLE(GetPartMovementVar) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID;
    s32 tableIndex;
    s32 outVar;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    tableIndex = evt_get_variable(script, *args++);
    outVar = *args++;

    evt_set_variable(script, outVar, get_actor_part(get_actor(actorID), partID)->movement->varTable[tableIndex]);

    return ApiStatus_DONE2;
}

API_CALLABLE(SetPartMovementVar) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID;
    s32 tableIndex;
    s32 val;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    tableIndex = evt_get_variable(script, *args++);
    val = evt_get_variable(script, *args++);

    get_actor_part(get_actor(actorID), partID)->movement->varTable[tableIndex] = val;

    return ApiStatus_DONE2;
}

API_CALLABLE(AddPartMovementVar) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID;
    s32 tableIndex;
    s32 val;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    tableIndex = evt_get_variable(script, *args++);
    val = evt_get_variable(script, *args++);

    get_actor_part(get_actor(actorID), partID)->movement->varTable[tableIndex] += val;

    return ApiStatus_DONE2;
}

API_CALLABLE(SetActorRotation) {
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

    if (x != EVT_IGNORE_ARG) {
        actor->rot.x = x;
    }

    if (y != EVT_IGNORE_ARG) {
        actor->rot.y = y;
    }

    if (z != EVT_IGNORE_ARG) {
        actor->rot.z = z;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(SetActorRotationOffset) {
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

    actor->rotPivotOffset.x = x;
    actor->rotPivotOffset.y = y;
    actor->rotPivotOffset.z = z;

    return ApiStatus_DONE2;
}

API_CALLABLE(GetActorRotation) {
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

    evt_set_variable(script, x, actor->rot.x);
    evt_set_variable(script, y, actor->rot.y);
    evt_set_variable(script, z, actor->rot.z);

    return ApiStatus_DONE2;
}

API_CALLABLE(SetPartRotation) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);

    actorPart = get_actor_part(get_actor(actorID), partID);

    actorPart->rot.x = x;
    actorPart->rot.y = y;
    actorPart->rot.z = z;

    return ApiStatus_DONE2;
}

API_CALLABLE(SetPartRotationOffset) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);

    actorPart = get_actor_part(get_actor(actorID), partID);

    actorPart->rotPivotOffset.x = x;
    actorPart->rotPivotOffset.y = y;
    actorPart->rotPivotOffset.z = z;

    return ApiStatus_DONE2;
}

API_CALLABLE(GetPartRotation) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = *args++;
    y = *args++;
    z = *args++;

    actorPart = get_actor_part(get_actor(actorID), partID);

    evt_set_float_variable(script, x, actorPart->rot.x);
    evt_set_float_variable(script, y, actorPart->rot.y);
    evt_set_float_variable(script, z, actorPart->rot.z);

    return ApiStatus_DONE2;
}

API_CALLABLE(SetActorScale) {
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

API_CALLABLE(SetActorScaleModifier) {
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

API_CALLABLE(GetActorScale) {
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

API_CALLABLE(SetPartScale) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    f32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = evt_get_float_variable(script, *args++);
    y = evt_get_float_variable(script, *args++);
    z = evt_get_float_variable(script, *args++);

    actorPart = get_actor_part(get_actor(actorID), partID);

    actorPart->scale.x = x;
    actorPart->scale.y = y;
    actorPart->scale.z = z;

    return ApiStatus_DONE2;
}

API_CALLABLE(GetPartScale) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 x, y, z;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    x = *args++;
    y = *args++;
    z = *args++;

    actorPart = get_actor_part(get_actor(actorID), partID);

    evt_set_float_variable(script, x, actorPart->scale.x);
    evt_set_float_variable(script, y, actorPart->scale.y);
    evt_set_float_variable(script, z, actorPart->scale.z);

    return ApiStatus_DONE2;
}

API_CALLABLE(GetBattleFlags) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.flags1);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetBattleFlagBits) {
    Bytecode* args = script->ptrReadPos;
    s32 bits = *args++;
    s32 mode = evt_get_variable(script, *args++);

    if (mode) {
        gBattleStatus.flags1 |= bits;
    } else {
        gBattleStatus.flags1 &= ~bits;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(GetBattleFlags2) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.flags2);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetBattleFlagBits2) {
    Bytecode* args = script->ptrReadPos;
    s32 bits = *args++;
    s32 mode = evt_get_variable(script, *args++);

    if (mode) {
        gBattleStatus.flags2 |= bits;
    } else {
        gBattleStatus.flags2 &= ~bits;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(SetActorFlags) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 flagBits;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    flagBits = *args++;
    get_actor(actorID)->flags = flagBits;

    return ApiStatus_DONE2;
}

API_CALLABLE(SetActorFlagBits) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 bits;
    s32 mode;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    bits = *args++;
    mode = evt_get_variable(script, *args++);
    actor = get_actor(actorID);

    if (mode) {
        actor->flags |= bits;
    } else {
        actor->flags &= ~bits;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(GetActorFlags) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 outVar;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    outVar = *args++;

    evt_set_variable(script, outVar, get_actor(actorID)->flags);

    return ApiStatus_DONE2;
}

API_CALLABLE(SetPartFlags) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 flagBits;
    s32 partID;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    flagBits = *args++;

    get_actor_part(get_actor(actorID), partID)->flags = flagBits;

    return ApiStatus_DONE2;
}

API_CALLABLE(SetPartFlagBits) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 bits;
    s32 partID;
    s32 mode;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    bits = *args++;
    mode = evt_get_variable(script, *args++);

    actorPart = get_actor_part(get_actor(actorID), partID);

    if (mode) {
        actorPart->flags |= bits;
    } else {
        actorPart->flags &= ~bits;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(SetPartTargetFlags) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 flagBits;
    s32 partID;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    flagBits = *args++;

    get_actor_part(get_actor(actorID), partID)->targetFlags = flagBits;

    return ApiStatus_DONE2;
}

API_CALLABLE(SetPartTargetFlagBits) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 partID;
    s32 bits;
    s32 mode;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    bits = *args++;
    mode = evt_get_variable(script, *args++);

    actorPart = get_actor_part(get_actor(actorID), partID);

    if (mode) {
        actorPart->targetFlags |= bits;
    } else {
        actorPart->targetFlags &= ~bits;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(GetPartFlags) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID;
    ActorPart* actorPart;
    s32 outVar;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    outVar = *args++;

    evt_set_variable(script, outVar, get_actor_part(get_actor(actorID), partID)->flags);

    return ApiStatus_DONE2;
}

API_CALLABLE(GetPartTargetFlags) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID;
    ActorPart* actorPart;
    s32 outVar;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    outVar = *args++;

    evt_set_variable(script, outVar, get_actor_part(get_actor(actorID), partID)->targetFlags);

    return ApiStatus_DONE2;
}

API_CALLABLE(SetPartEventFlags) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 flagBits;
    s32 partID;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    flagBits = *args++;

    get_actor_part(get_actor(actorID), partID)->eventFlags = flagBits;

    return ApiStatus_DONE2;
}

API_CALLABLE(SetPartEventBits) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    ActorPart* part;
    s32 partID;
    s32 bits;
    s32 mode;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    bits = *args++;
    mode = evt_get_variable(script, *args++);

    actor = get_actor(actorID);
    part = get_actor_part(actor, partID);

    if (mode) {
        part->eventFlags |= bits;
    } else {
        part->eventFlags &= ~bits;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(GetPartEventFlags) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID;
    Actor* actor;
    ActorPart* part;
    s32 outVar;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    outVar = *args++;

    actor = get_actor(actorID);
    part = get_actor_part(actor, partID);
    evt_set_variable(script, outVar, part->eventFlags);

    return ApiStatus_DONE2;
}

API_CALLABLE(SetPartImmunityFlags) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 flagBits;
    s32 partID;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    flagBits = *args++;

    get_actor_part(get_actor(actorID), partID)->elementalImmunities = flagBits;

    return ApiStatus_DONE2;
}

API_CALLABLE(SetPartImmunityBits) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    ActorPart* part;
    s32 partID;
    s32 bits;
    s32 mode;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    bits = *args++;
    mode = evt_get_variable(script, *args++);

    actor = get_actor(actorID);
    part = get_actor_part(actor, partID);

    if (mode) {
        part->elementalImmunities |= bits;
    } else {
        part->elementalImmunities &= ~bits;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(HPBarToHome) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    actor->healthBarPos.x = actor->homePos.x + actor->actorBlueprint->healthBarOffset.x;
    actor->healthBarPos.y = actor->homePos.y + actor->actorBlueprint->healthBarOffset.y;
    actor->healthBarPos.z = actor->homePos.z;

    if (actor->flags & ACTOR_FLAG_UPSIDE_DOWN) {
        actor->healthBarPos.y = actor->homePos.y - actor->size.y - actor->actorBlueprint->healthBarOffset.y;
    }

    actor->healthFraction = (actor->curHP * 25) / actor->maxHP;

    return ApiStatus_DONE2;
}

API_CALLABLE(HPBarToCurrent) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    actor->healthBarPos.x = actor->curPos.x + actor->actorBlueprint->healthBarOffset.x;
    actor->healthBarPos.y = actor->curPos.y + actor->actorBlueprint->healthBarOffset.y;
    actor->healthBarPos.z = actor->curPos.z;

    if (actor->flags & ACTOR_FLAG_UPSIDE_DOWN) {
        actor->healthBarPos.y = actor->curPos.y - actor->size.y - actor->actorBlueprint->healthBarOffset.y;
    }

    actor->healthFraction = (actor->curHP * 25) / actor->maxHP;

    return ApiStatus_DONE2;
}

API_CALLABLE(HideHPBar) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    hide_actor_health_bar(get_actor(actorID));

    return ApiStatus_DONE2;
}

API_CALLABLE(SetHPBarOffset) {
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

    actor->healthBarOffset.x = x;
    actor->healthBarOffset.y = y;
    actor->healthBarPos.x = actor->homePos.x + actor->actorBlueprint->healthBarOffset.x + actor->healthBarOffset.x;
    actor->healthBarPos.y = actor->homePos.y + actor->actorBlueprint->healthBarOffset.y + actor->healthBarOffset.y;
    actor->healthBarPos.z = actor->homePos.z;

    if (actor->flags & ACTOR_FLAG_UPSIDE_DOWN) {
        actor->healthBarPos.y = actor->homePos.y - actor->size.y;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(SetActorStatusOffsets) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 iconX, iconY, textX, textY;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    iconX = evt_get_variable(script, *args++);
    iconY = evt_get_variable(script, *args++);
    textX = evt_get_variable(script, *args++);
    textY = evt_get_variable(script, *args++);

    actor = get_actor(actorID);
    actor->statusIconOffset.x = iconX;
    actor->statusIconOffset.y = iconY;
    actor->statusTextOffset.x = textX;
    actor->statusTextOffset.y = textY;

    return ApiStatus_DONE2;
}

API_CALLABLE(SummonEnemy) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32* args = script->ptrReadPos;
    Actor* actor1;
    Actor* actor2;
    s16* enemyIDs;
    s32 numEnemies;
    s32 i, j;
    u16 enemyID1, enemyID2;
    s32 priority1, priority2;
    s32 basePriority;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    switch (script->functionTemp[0]) {
        case 0:
            script->functionTempPtr[1] = create_actor((FormationRow*)evt_get_variable(script, *args++));
            script->functionTemp[2] = evt_get_variable(script, *args++); // isLowPriority
            script->functionTemp[0] = 1;
            break;
        case 1:
            actor2 = script->functionTempPtr[1];
            if (does_script_exist(actor2->takeTurnScriptID)) {
                break;
            }
            
            enemyIDs = battleStatus->enemyIDs;
            if (battleStatus->nextEnemyIndex == 0) {
                numEnemies = 0;
                for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                    if (battleStatus->enemyActors[i]) {
                        battleStatus->enemyIDs[numEnemies++] = i | ACTOR_CLASS_ENEMY;
                    }
                }
                battleStatus->numEnemyActors = numEnemies;
                if (script->functionTemp[2]) {
                    basePriority = -1000;
                } else {
                    basePriority = 1000;
                }
                enemyIDs = battleStatus->enemyIDs;
                for (i = 0; i < numEnemies - 1; i++) {
                    for (j = i + 1; j < numEnemies; j++) {
                        enemyID1 = enemyIDs[i];
                        actor1 = battleStatus->enemyActors[enemyID1 & 0xFF];
                        priority1 = actor1->turnPriority;
                        if (actor1 == actor2) {
                            priority1 += basePriority;
                        }
                        enemyID2 = enemyIDs[j];
                        actor1 = battleStatus->enemyActors[enemyID2 & 0xFF];
                        priority2 = actor1->turnPriority;
                        if (actor1 == actor2) {
                            priority2 += basePriority;
                        }
                        if (priority1 < priority2) {
                            enemyIDs[i] = enemyID2;
                            enemyIDs[j] = enemyID1;
                        }
                    }
                }
            } else {
                numEnemies = battleStatus->numEnemyActors;
                for (i = 0; i < numEnemies; i++){
                    if (battleStatus->enemyActors[enemyIDs[i] & 0xFF] == actor2) {
                        enemyIDs[i] = -1;
                    }
                }
                if (script->functionTemp[2] == 0) {
                    for (i = numEnemies; i >= battleStatus->nextEnemyIndex; i--) {
                        battleStatus->enemyIDs[i] = battleStatus->enemyIDs[i - 1];
                    }
                    battleStatus->enemyIDs[battleStatus->nextEnemyIndex - 1] = actor2->actorID;
                    battleStatus->numEnemyActors++;
                    battleStatus->nextEnemyIndex++;
                } else {
                    battleStatus->enemyIDs[battleStatus->numEnemyActors] = actor2->actorID;
                    battleStatus->numEnemyActors++;
                }
            }
            script->varTable[0] = actor2->actorID;
            return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(GetOwnerID) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, script->owner1.actorID);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetOwnerID) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);

    script->owner1.actorID = actorID;
    return ApiStatus_DONE2;
}

API_CALLABLE(ActorExists) {
    Actor* partner = gBattleStatus.partnerActor;
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    b32 exists;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    exists = get_actor(actorID) != NULL;
    if ((actorID == ACTOR_PARTNER) && (partner == NULL)) {
        exists = FALSE;
    }

    evt_set_variable(script, *args++, exists);
    return ApiStatus_DONE2;
}

API_CALLABLE(GetPartAnimInstanceID) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    s32 outVar = *args++;
    Actor* actor;
    ActorPart* part;
    
    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    part = get_actor_part(actor, partID);
    evt_set_variable(script, outVar, part->spriteInstanceID);

    return ApiStatus_DONE2;
}

API_CALLABLE(GetPartAnimNotify) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    s32 outVar = *args++;
    Actor* actor;
    ActorPart* part;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    part = get_actor_part(actor, partID);
    evt_set_variable(script, outVar, part->animNotifyValue);

    return ApiStatus_DONE2;
}

API_CALLABLE(SetBattleMenuEnabledFlags) {
    Bytecode* args = script->ptrReadPos;
    s32 flagsValue = *args++;

    gBattleStatus.enabledMenusFlags = flagsValue;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetEnabledStarPowers) {
    Bytecode* args = script->ptrReadPos;
    s32 enabled = *args++;

    gBattleStatus.enabledStarPowersFlags = enabled;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetBattleInputMask) {
    Bytecode* args = script->ptrReadPos;
    s32 mask = *args++;

    gBattleStatus.inputBitmask = mask;
    return ApiStatus_DONE2;
}

API_CALLABLE(SetBattleInputButtons) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 currentButtonsDown = *args++;
    s32 currentButtonsPressed = *args++;
    s32 currentButtonsHeld = *args++;

    battleStatus->curButtonsDown = currentButtonsDown;
    battleStatus->curButtonsPressed = currentButtonsPressed;
    battleStatus->curButtonsHeld = currentButtonsHeld;

    return ApiStatus_DONE2;
}

API_CALLABLE(CheckButtonPress) {
    Bytecode* args = script->ptrReadPos;
    Bytecode buttons = *args++;
    Bytecode outVar = *args++;
    s32 buttonsPressed = gBattleStatus.curButtonsPressed;

    evt_set_variable(script, outVar, (buttonsPressed & buttons) != 0);
    return ApiStatus_DONE2;
}

API_CALLABLE(CheckButtonHeld) {
    Bytecode* args = script->ptrReadPos;
    Bytecode buttons = *args++;
    Bytecode outVar = *args++;
    s32 buttonsHeld = gBattleStatus.curButtonsHeld;

    evt_set_variable(script, outVar, (buttonsHeld & buttons) != 0);
    return ApiStatus_DONE2;
}

API_CALLABLE(CheckButtonDown) {
    Bytecode* args = script->ptrReadPos;
    Bytecode buttons = *args++;
    Bytecode outVar = *args++;
    s32 buttonsDown = gBattleStatus.curButtonsDown;

    evt_set_variable(script, outVar, (buttonsDown & buttons) != 0);
    return ApiStatus_DONE2;
}

API_CALLABLE(GetBattleState) {
    Bytecode* args = script->ptrReadPos;
    s32 outVar = *args++;

    evt_set_variable(script, outVar, gBattleState);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetBattleState) {
    Bytecode* args = script->ptrReadPos;
    s32 state = evt_get_variable(script, *args++);

    btl_set_state(state);
    return ApiStatus_DONE2;
}

API_CALLABLE(WaitForState) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 waitForState;

    if (isInitialCall) {
        waitForState = evt_get_variable(script, *args++);
        if (waitForState == BATTLE_STATE_0) {
            battleStatus->waitForState = BATTLE_STATE_0;
            return ApiStatus_DONE2;
        }
        battleStatus->waitForState = waitForState;
    }

    waitForState = battleStatus->waitForState;
    if (waitForState == BATTLE_STATE_0) {
        return ApiStatus_DONE2;
    }

    if (gBattleState == waitForState) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(CancelEnemyTurn) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 cancelMode = evt_get_variable(script, *args++);

    switch (cancelMode) {
        case 0:
            battleStatus->unk_94 = 1;
            break;
        case 1:
            battleStatus->unk_94 = -1;
            break;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(func_8026E260) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);

    evt_get_variable(script, *args++);
    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    get_actor(actorID);

    return ApiStatus_DONE2;
}

API_CALLABLE(CreateCurrentPosTargetList) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);

    gBattleStatus.curTargetListFlags = *args;
    create_current_pos_target_list(actor);

    return ApiStatus_DONE2;
}

API_CALLABLE(CreateHomeTargetList) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);

    gBattleStatus.curTargetListFlags = *args;
    create_home_target_list(actor);

    return ApiStatus_DONE2;
}

API_CALLABLE(InitTargetIterator) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    SelectableTarget* selectableTarget = &actor->targetData[actor->targetIndexList[actor->selectedTargetIndex]];

    actor->targetActorID = selectableTarget->actorID;
    actor->targetPartID = selectableTarget->partID;

    return ApiStatus_DONE2;
}

API_CALLABLE(SetOwnerTarget) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.enemyID);
    s16 actorID = evt_get_variable(script, *args++);

    actor->targetPartID = evt_get_variable(script, *args++);
    actor->targetActorID = actorID;

    return ApiStatus_DONE2;
}

API_CALLABLE(ChooseNextTarget) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    s32 mode = evt_get_variable(script, *args++);
    s32 temp = *args++;
    SelectableTarget* target;
    s32 length;
    s32 curIdx;
    s32 retVal;

    if (mode == ITER_FIRST) {
        actor->selectedTargetIndex = 0;
        target = &actor->targetData[actor->targetIndexList[0]];
        actor->targetActorID = target->actorID;
        actor->targetPartID = target->partID;
        return ApiStatus_DONE2;
    }

    if (mode == ITER_LAST) {
        actor->selectedTargetIndex = actor->targetListLength - 1;
        target = &actor->targetData[actor->targetIndexList[actor->selectedTargetIndex]];
        actor->targetActorID = target->actorID;
        actor->targetPartID = target->partID;
        return ApiStatus_DONE2;
    }

    curIdx = actor->selectedTargetIndex;
    length = actor->targetListLength;
    retVal = ITER_HAS_MORE;

    if (mode == ITER_NEXT) {
        curIdx++;
    } else {
        curIdx--;
    }

    if (curIdx < 0) {
        curIdx = length - 1;
        retVal = ITER_NO_MORE;
    }

    if (curIdx >= length) {
        curIdx = 0;
        retVal = ITER_NO_MORE;
    }

    actor->selectedTargetIndex = curIdx;
    target = &actor->targetData[actor->targetIndexList[actor->selectedTargetIndex]];
    actor->targetActorID = target->actorID;
    actor->targetPartID = target->partID;
    evt_set_variable(script, temp, retVal);

    return ApiStatus_DONE2;
}

s32 func_8026E558(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    SelectableTarget* target;
    s32 mode;
    s32 outVar;
    Actor* actor;
    f32 x, y, z;
    s32 outVal;
    s32 row;
    s32 column;
    s32 layer;
    s32 i;

    i = evt_get_variable(script, *args++);
    mode = evt_get_variable(script, *args++);
    outVar = *args++;

    if (i == ACTOR_SELF) {
        i = script->owner1.actorID;
    }

    actor = get_actor(i);
    x = actor->curPos.x;
    y = actor->curPos.y;
    z = actor->curPos.z;

    outVal = -1;

    if (y < 40.0f) {
        row = 0;
    } else if (y < 85.0f) {
        row = 1;
    } else if (y < 100.0f) {
        row = 2;
    } else {
        row = 3;
    }

    if (x < 25.0f) {
        column = 0;
    } else if (x < 65.0f) {
        column = 1;
    } else if (x < 105.0f) {
        column = 2;
    } else {
        column = 3;
    }

    if (z < -30.0f) {
        layer = 0;
    } else {
        layer = 1;
    }

    switch (mode) {
        case 0:
            for (i = 0; i < actor->targetListLength; i++) {
                target = &actor->targetData[actor->targetIndexList[i]];

                if (target->column == column && target->layer == layer && target->row < row) {
                    actor->targetActorID = target->actorID;
                    actor->targetPartID = target->partID;
                    outVal = 0;
                }
            }
            break;
        case 1:
            for (i = 0; i < actor->targetListLength; i++) {
                target = &actor->targetData[actor->targetIndexList[i]];

                if (target->column == column && target->layer == layer && target->row < row) {
                    actor->targetActorID = target->actorID;
                    actor->targetPartID = target->partID;
                    outVal = 0;
                }
            }
            break;
        case -1:
            for (i = 0; i < actor->targetListLength; i++) {
                target = &actor->targetData[actor->targetIndexList[i]];

                if (target->column == column && target->layer == layer && target->row < row) {
                    actor->targetActorID = target->actorID;
                    actor->targetPartID = target->partID;
                    outVal = 0;
                }
            }
            break;
    }
    evt_set_variable(script, outVar, outVal);
    return ApiStatus_DONE2;
}

API_CALLABLE(GetTargetListLength) {
    Bytecode* args = script->ptrReadPos;

    evt_set_variable(script, *args++, get_actor(script->owner1.actorID)->targetListLength);
    return ApiStatus_DONE2;
}

API_CALLABLE(GetOwnerTarget) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.enemyID);
    s32 actorID = *args++;
    s32 partID = *args++;

    evt_set_variable(script, actorID, actor->targetActorID);
    evt_set_variable(script, partID, actor->targetPartID);

    return ApiStatus_DONE2;
}

API_CALLABLE(func_8026E914) {
    Bytecode* args = script->ptrReadPos;
    s32 temp_v0 = *args++;
    s32 temp_s1 = *args++;

    evt_set_variable(script, temp_v0, gBattleStatus.curTargetID2);
    evt_set_variable(script, temp_s1, gBattleStatus.curTargetPart2);

    return ApiStatus_DONE2;
}

API_CALLABLE(GetPlayerActorID) {
    evt_set_variable(script, *script->ptrReadPos, gBattleStatus.attackerActorID);
    return ApiStatus_DONE2;
}

API_CALLABLE(func_8026E9A0) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID;
    s32 partID;

    actorID = evt_get_variable(script, *args++);
    partID = evt_get_variable(script, *args++);

    gBattleStatus.curTargetPart2 = partID;
    gBattleStatus.curTargetID2 = actorID;

    return ApiStatus_DONE2;
}

API_CALLABLE(GetDistanceToGoal) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 outVar = *args++;
    Actor* actor;
    f32 dist;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);

    dist = dist2D(actor->curPos.x, actor->curPos.z, actor->state.goalPos.x, actor->state.goalPos.z);
    evt_set_variable(script, outVar, dist);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetActorPaletteEffect) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    s32 palAdjustment = evt_get_variable(script, *args++);
    Actor* actor;
    ActorPart* actorPart;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);
    actorPart = get_actor_part(actor, partID);

    set_part_pal_adjustment(actorPart, palAdjustment);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetActorPaletteSwapTimes) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    Actor* actor;
    ActorPart* actorPart;
    DecorationTable* decorations;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);
    actorPart = get_actor_part(actor, partID);
    decorations = actorPart->decorationTable;

    decorations->blendPalA = evt_get_variable(script, *args++);
    decorations->blendPalB = evt_get_variable(script, *args++);
    decorations->palswapTimeHoldA = evt_get_variable(script, *args++);
    decorations->palswapTimeAtoB = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

API_CALLABLE(SetActorPaletteSwapParams) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    Actor* actor;
    ActorPart* actorPart;
    DecorationTable* table;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);
    actorPart = get_actor_part(actor, partID);
    table = actorPart->decorationTable;

    table->blendPalA = evt_get_variable(script, *args++);
    table->blendPalB = evt_get_variable(script, *args++);
    table->palswapTimeHoldA = evt_get_variable(script, *args++);
    table->palswapTimeAtoB = evt_get_variable(script, *args++);
    table->palswapTimeHoldB = evt_get_variable(script, *args++);
    table->palswapTimeBtoA = evt_get_variable(script, *args++);
    table->palswapUnused1 = evt_get_variable(script, *args++);
    table->palswapUnused2 = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

API_CALLABLE(EnableActorPaletteEffects) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    s32 enable = evt_get_variable(script, *args++);
    Actor* actor;
    ActorPart* actorPart;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);
    actorPart = get_actor_part(actor, partID);

    if (enable) {
        actorPart->flags |= ACTOR_PART_FLAG_HAS_PAL_EFFECT;
    } else {
        actorPart->flags &= ~ACTOR_PART_FLAG_HAS_PAL_EFFECT;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(func_8026EDE4) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    s32 temp_s3 = evt_get_variable(script, *args++);
    Actor* actor;
    ActorPart* actorPart;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);
    actorPart = get_actor_part(actor, partID);

    set_part_glow_pal(actorPart, temp_s3);

    return ApiStatus_DONE2;
}

API_CALLABLE(AddActorDecoration) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    s32 decorationIndex = evt_get_variable(script, *args++);
    s32 decorationType = evt_get_variable(script, *args++);
    Actor* actor;
    ActorPart* actorPart;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);
    actorPart = get_actor_part(actor, partID);

    add_part_decoration(actorPart, decorationIndex, decorationType);
    return ApiStatus_DONE2;
}

API_CALLABLE(RemoveActorDecoration) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    s32 decorationIndex = evt_get_variable(script, *args++);
    Actor* actor;
    ActorPart* actorPart;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.enemyID;
    }
    actor = get_actor(actorID);
    actorPart = get_actor_part(actor, partID);

    remove_part_decoration(actorPart, decorationIndex);
    return ApiStatus_DONE2;
}

API_CALLABLE(ModifyActorDecoration) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    s32 idx = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    DecorationTable* decorationtable;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);
    actorPart = get_actor_part(actor, partID);
    decorationtable = actorPart->decorationTable;

    decorationtable->decorData[idx].raw[0] = evt_get_variable(script, *args++);
    decorationtable->decorData[idx].raw[1] = evt_get_variable(script, *args++);
    decorationtable->decorData[idx].raw[2] = evt_get_variable(script, *args++);
    decorationtable->decorData[idx].raw[3] = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

API_CALLABLE(UseIdleAnimation) {
    Actor* actor;
    s32* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 useIdle = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    if (!useIdle) {
        actor->flags &= ~ACTOR_FLAG_USING_IDLE_ANIM;
        actor->flags &= ~ACTOR_FLAG_SHOW_STATUS_ICONS;
        clear_actor_static_pal_adjustments(actor);
    } else {
        actor->flags |= ACTOR_FLAG_USING_IDLE_ANIM;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(func_8026F1A0) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 temp_s0_3 = evt_get_variable(script, *args++);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);

    if (temp_s0_3 == 0) {
        actor->flags &= ~ACTOR_FLAG_SHOW_STATUS_ICONS;
        clear_actor_static_pal_adjustments(actor);
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(GetStatusFlags) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 actorID = evt_get_variable(script, *args++);
    s32 outVar = *args++;
    Actor* actor;
    s32 actorClass;
    s8 debuff;
    s8 staticStatus;
    s8 stoneStatus;
    s8 koStatus;
    s8 transStatus;
    ActorPart* partsTable;
    s32 flags;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);
    debuff = actor->debuff;
    actorClass = actor->actorID & ACTOR_CLASS_MASK;
    flags = 0;

    if (debuff != 0) {
        if (debuff == STATUS_KEY_STOP) {
            flags |= STATUS_FLAG_STOP;
        }
        if (debuff == STATUS_KEY_FROZEN) {
            flags |= STATUS_FLAG_FROZEN;
        }
        if (debuff == STATUS_KEY_SLEEP) {
            flags |= STATUS_FLAG_SLEEP;
        }
        if (debuff == STATUS_KEY_PARALYZE) {
            flags |= STATUS_FLAG_PARALYZE;
        }
        if (debuff == STATUS_KEY_DIZZY) {
            flags |= STATUS_FLAG_DIZZY;
        }
        if (debuff == STATUS_KEY_FEAR) {
            flags |= STATUS_FLAG_FEAR;
        }
        if (debuff == STATUS_KEY_POISON) {
            flags |= STATUS_FLAG_POISON;
        }
        if (debuff == STATUS_KEY_SHRINK) {
            flags |= STATUS_FLAG_SHRINK;
        }
    }

    switch (actor->staticStatus) {
        case 0:
            break;
        case STATUS_KEY_STATIC:
            flags |= STATUS_FLAG_STATIC;
            break;
    }

    switch (actor->stoneStatus) {
        case 0:
            break;
        case STATUS_KEY_STONE:
            flags |= STATUS_FLAG_STONE;
            break;
    }

    switch (actor->koStatus) {
        case 0:
            break;
        case STATUS_KEY_DAZE:
            flags |= STATUS_FLAG_KO;
            break;
    }

    switch (actor->transparentStatus) {
        case 0:
            break;
        case STATUS_KEY_TRANSPARENT:
            flags |= STATUS_FLAG_TRANSPARENT;
            break;
    }

    for (partsTable = actor->partsTable; partsTable != NULL; partsTable = partsTable->nextPart) {
            if (partsTable->flags & ACTOR_PART_FLAG_TRANSPARENT) {
                flags |= STATUS_FLAG_TRANSPARENT;
            }
            if (partsTable->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
                flags |= STATUS_FLAG_TRANSPARENT;
            }
    }

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
        case ACTOR_CLASS_PARTNER:
            if (battleStatus->outtaSightActive) {
                flags |= STATUS_FLAG_TRANSPARENT;
            }
            break;
        case ACTOR_CLASS_ENEMY:
            break;
    }

    if (actor->isGlowing) {
        flags |= STATUS_FLAG_GLOWING;
    }

    if (actor->attackBoost) {
        flags |= STATUS_FLAG_ATTACK_BOOST;
    }

    if (actor->defenseBoost) {
        flags |= STATUS_FLAG_DEFENSE_BOOST;
    }

    if (actor->chillOutAmount) {
        flags |= STATUS_FLAG_CHILL_OUT;
    }

    if (player_team_is_ability_active(actor, ABILITY_RIGHT_ON)) {
        flags |= STATUS_FLAG_RIGHT_ON;
    }

    evt_set_variable(script, outVar, flags);
    return ApiStatus_DONE2;
}

API_CALLABLE(RemovePlayerBuffs) {
    remove_player_buffs(*script->ptrReadPos);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetPartAlpha) {
    Actor* actor;
    s32* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    s32 opacity = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    get_actor_part(actor, partID)->opacity = opacity;

    actor->renderMode = (opacity == 255) ? RENDER_MODE_ALPHATEST : RENDER_MODE_SURFACE_XLU_LAYER3;
    return ApiStatus_DONE2;
}

API_CALLABLE(CreatePartShadow) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    create_part_shadow(actorID, partID);
    return ApiStatus_DONE2;
}

API_CALLABLE(RemovePartShadow) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    remove_part_shadow(actorID, partID);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetEndBattleFadeOutRate) {
    gBattleStatus.endBattleFadeOutRate = evt_get_variable(script, *script->ptrReadPos);
    return ApiStatus_DONE2;
}

API_CALLABLE(SetBattleVar) {
    Bytecode* args = script->ptrReadPos;
    s32 varIdx = evt_get_variable(script, *args++);

    gBattleStatus.varTable[varIdx] = evt_get_variable(script, *args++);

    return ApiStatus_DONE2;
}

API_CALLABLE(GetBattleVar) {
    Bytecode* args = script->ptrReadPos;
    s32 varIdx = evt_get_variable(script, *args++);

    evt_set_variable(script, *args++, gBattleStatus.varTable[varIdx]);
    return ApiStatus_DONE2;
}

API_CALLABLE(ResetAllActorSounds) {
    s32 actorID = evt_get_variable(script, *script->ptrReadPos);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    reset_all_actor_sounds(get_actor(actorID));
    return ApiStatus_DONE2;
}

s32 SetActorSounds(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 soundType;
    s32 sound1;
    s32 sound2;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    soundType = evt_get_variable(script, *args++);
    sound1 = evt_get_variable(script, *args++);
    sound2 = evt_get_variable(script, *args++);
    actor = get_actor(actorID);

    switch (soundType) {
        case ACTOR_SOUND_WALK:
            actor->actorTypeData1[0] = sound1;
            actor->actorTypeData1[1] = sound2;
            break;
        case ACTOR_SOUND_FLY:
            actor->actorTypeData1[2] = sound1;
            actor->actorTypeData1[3] = sound2;
            break;
        case ACTOR_SOUND_JUMP:
            actor->actorTypeData1[4] = sound1;
            break;
        case ACTOR_SOUND_HURT:
            actor->actorTypeData1[5] = sound1;
            break;
        case ACTOR_SOUND_WALK_INCREMENT:
            actor->actorTypeData1b[0] = sound1;
            break;
        case ACTOR_SOUND_FLY_INCREMENT:
            actor->actorTypeData1b[1] = sound1;
            break;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(ResetActorSounds) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 soundType;
    s32 sound1;
    s32 sound2;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    soundType = evt_get_variable(script, *args++);
    sound1 = evt_get_variable(script, *args++);
    sound2 = evt_get_variable(script, *args++);
    actor = get_actor(actorID);

    switch (soundType) {
        case ACTOR_SOUND_WALK:
            actor->actorTypeData1[0] = bActorSoundTable[actor->actorType].walk[0];
            actor->actorTypeData1[1] = bActorSoundTable[actor->actorType].walk[1];
            break;
        case ACTOR_SOUND_FLY:
            actor->actorTypeData1[2] = bActorSoundTable[actor->actorType].fly[0];
            actor->actorTypeData1[3] = bActorSoundTable[actor->actorType].fly[1];
            break;
        case ACTOR_SOUND_JUMP:
            actor->actorTypeData1[4] = bActorSoundTable[actor->actorType].jump;
            break;
        case ACTOR_SOUND_HURT:
            actor->actorTypeData1[5] = bActorSoundTable[actor->actorType].hurt;
            break;
        case ACTOR_SOUND_WALK_INCREMENT:
            actor->actorTypeData1b[0] = bActorSoundTable[actor->actorType].delay[0];
            break;
        case ACTOR_SOUND_FLY_INCREMENT:
            actor->actorTypeData1b[1] = bActorSoundTable[actor->actorType].delay[1];
            break;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(SetPartSounds) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    ActorPart* actorPart;
    s32 partID;
    s32 soundType;
    s32 sound1;
    s32 sound2;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    soundType = evt_get_variable(script, *args++);
    sound1 = evt_get_variable(script, *args++);
    sound2 = evt_get_variable(script, *args++);
    actorPart = get_actor_part(get_actor(actorID), partID);

    switch (soundType) {
        case ACTOR_SOUND_WALK:
            actorPart->partTypeData[0] = sound1;
            actorPart->partTypeData[1] = sound2;
            break;
        case ACTOR_SOUND_FLY:
            actorPart->partTypeData[2] = sound1;
            actorPart->partTypeData[3] = sound2;
            break;
        case ACTOR_SOUND_JUMP:
            actorPart->partTypeData[4] = sound1;
            break;
        case ACTOR_SOUND_HURT:
            actorPart->partTypeData[5] = sound1;
            break;
        case ACTOR_SOUND_WALK_INCREMENT:
            actorPart->actorTypeData2b[0] = sound1;
            break;
        case ACTOR_SOUND_FLY_INCREMENT:
            actorPart->actorTypeData2b[1] = sound1;
            break;
    }

    return ApiStatus_DONE2;
}

API_CALLABLE(SetActorType) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* enemy;
    s32 actorType;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actorType = evt_get_variable(script, *args++);
    enemy = get_actor(actorID);

    if (is_actor_health_bar_visible(enemy)) {
        load_tattle_flags(actorType);
    }

    enemy->actorType = actorType;
    return ApiStatus_DONE2;
}

API_CALLABLE(ShowShockEffect) {
    s32 actorID = evt_get_variable(script, *script->ptrReadPos);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    apply_shock_effect(get_actor(actorID));
    return ApiStatus_DONE2;
}

API_CALLABLE(GetActorAttackBoost) {
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

API_CALLABLE(GetActorDefenseBoost) {
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

API_CALLABLE(BoostAttack) {
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
        script->functionTempPtr[1] = actor;
        script->functionTemp[2] = attackBoost;

        btl_cam_use_preset(BTL_CAM_PRESET_08);
        btl_cam_set_zoffset(12);
        btl_cam_target_actor(actor->actorID);
        btl_cam_set_zoom(250);
        btl_cam_move(10);
        func_8024E60C();
        if (actor->flags & ACTOR_FLAG_UPSIDE_DOWN) {
            btl_cam_set_zoffset(0);
        }
        ApplyingBuff = TRUE;
        script->functionTemp[3] = 5;
        script->functionTemp[0] = 1;
    }
    get_actor(script->owner1.actorID);
    actor = script->functionTempPtr[1];
    attackBoost = script->functionTemp[2];

    flags = actor->flags;
    x1 = actor->curPos.x + actor->headOffset.x;
    if (flags & ACTOR_FLAG_UPSIDE_DOWN) {
        y1 = actor->curPos.y + actor->headOffset.y - actor->size.y / 2;
    } else if (!(flags & ACTOR_FLAG_HALF_HEIGHT)) {
        y1 = actor->curPos.y + actor->headOffset.y + actor->size.y / 2;
    } else {
        y1 = actor->curPos.y + actor->headOffset.y + actor->size.y;
    }
    z1 = actor->curPos.z + actor->headOffset.z + 10.0f;

    flags2 = actor->flags;
    x2 = actor->curPos.x + actor->headOffset.x + actor->size.x / 2;
    if (flags2 & ACTOR_FLAG_UPSIDE_DOWN) {
        y2 = actor->curPos.y + actor->headOffset.y - actor->size.y;
    } else if (!(flags2 & ACTOR_FLAG_HALF_HEIGHT)) {
        y2 = actor->curPos.y + actor->headOffset.y + actor->size.y;
    } else {
        y2 = actor->curPos.y + actor->headOffset.y + actor->size.y * 2;
    }
    z2 = actor->curPos.z + actor->headOffset.z + 10.0f;

    switch (script->functionTemp[0]) {
        case 1:
            if (script->functionTemp[3] == 0) {
                fx_radial_shimmer(2, x1, y1, z1, 1.0f, 30);
                btl_cam_use_preset_immediately(BTL_CAM_PRESET_19);
                script->functionTemp[3] = 30;
                script->functionTemp[0] = 2;
            } else {
                script->functionTemp[3]--;
                break;
            }
            break;
        case 2:
            if (script->functionTemp[3] == 0) {
                dispatch_event_actor(actor, EVENT_RECEIVE_BUFF);
                btl_cam_use_preset(BTL_CAM_DEFAULT);
                btl_cam_move(15);
                actor->isGlowing = TRUE;
                actor->attackBoost += attackBoost;
                if (actor->attackBoost > 20) {
                    actor->attackBoost = 20;
                }
                fx_stat_change(attackBoost - 1, x2, y2, z2, 1.0f, 60);
                script->functionTemp[3] = 15;
                script->functionTemp[0] = 3;
            } else {
                script->functionTemp[3]--;
                break;
            }
            break;
        case 3:
            if (script->functionTemp[3] == 0) {
                btl_show_variable_battle_message(BTL_MSG_ATTACK_UP, 60, attackBoost);
                script->functionTemp[0] = 4;
            } else {
                script->functionTemp[3]--;
                break;
            }
            break;
        case 4:
            if (btl_is_popup_displayed() == 0) {
                btl_cam_use_preset(BTL_CAM_DEFAULT);
                script->functionTemp[3] = 10;
                script->functionTemp[0] = 5;
            }
            break;
        case 5:
            if (script->functionTemp[3] != 0) {
                script->functionTemp[3]--;
                break;
            }
            if ((actor->handleEventScript != NULL) && does_script_exist(actor->handleEventScriptID)) {
                break;
            }
            ApplyingBuff = FALSE;
            return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(BoostDefense) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID;
    Actor* actor;
    f32 x1, y1, z1;
    f32 x2, y2, z2;
    s32 defenseBoost;
    s32 flags;
    s32 flags2;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        actorID = evt_get_variable(script, *args++);
        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }
        defenseBoost = evt_get_variable(script, *args++);
        actor = get_actor(actorID);
        script->functionTempPtr[1] = actor;
        script->functionTemp[2] = defenseBoost;

        btl_cam_use_preset(BTL_CAM_PRESET_08);
        btl_cam_set_zoffset(12);
        btl_cam_target_actor(actor->actorID);
        btl_cam_set_zoom(250);
        btl_cam_move(10);
        func_8024E60C();
        if (actor->flags & ACTOR_FLAG_UPSIDE_DOWN) {
            btl_cam_set_zoffset(0);
        }

        ApplyingBuff = TRUE;
        script->functionTemp[3] = 5;
        script->functionTemp[0] = 1;
    }
    get_actor(script->owner1.actorID);
    actor = script->functionTempPtr[1];
    defenseBoost = script->functionTemp[2];

    flags = actor->flags;
    x1 = actor->curPos.x + actor->headOffset.x;
    if (flags & ACTOR_FLAG_UPSIDE_DOWN) {
        y1 = actor->curPos.y + actor->headOffset.y - actor->size.y / 2;
    } else if (!(flags & ACTOR_FLAG_HALF_HEIGHT)) {
        y1 = actor->curPos.y + actor->headOffset.y + actor->size.y / 2;
    } else {
        y1 = actor->curPos.y + actor->headOffset.y + actor->size.y;
    }
    z1 = actor->curPos.z + actor->headOffset.z + 10.0f;

    flags2 = actor->flags;
    x2 = actor->curPos.x + actor->headOffset.x + actor->size.x / 2;
    if (flags2 & ACTOR_FLAG_UPSIDE_DOWN) {
        y2 = actor->curPos.y + actor->headOffset.y - actor->size.y;
    } else if (!(flags2 & ACTOR_FLAG_HALF_HEIGHT)) {
        y2 = actor->curPos.y + actor->headOffset.y + actor->size.y;
    } else {
        y2 = actor->curPos.y + actor->headOffset.y + actor->size.y * 2;
    }
    z2 = actor->curPos.z + actor->headOffset.z + 10.0f;

    switch (script->functionTemp[0]) {
        case 1:
            if (script->functionTemp[3] == 0) {
                fx_radial_shimmer(2, x1, y1, z1, 1.0f, 30);
                btl_cam_use_preset_immediately(BTL_CAM_PRESET_19);
                script->functionTemp[3] = 30;
                script->functionTemp[0] = 2;
            } else {
                script->functionTemp[3]--;
                break;
            }
            break;
        case 2:
            if (script->functionTemp[3] == 0) {
                dispatch_event_actor(actor, EVENT_RECEIVE_BUFF);
                btl_cam_use_preset(BTL_CAM_DEFAULT);
                btl_cam_move(15);
                actor->isGlowing = TRUE;
                actor->defenseBoost += defenseBoost;
                if (actor->defenseBoost > 20) {
                    actor->defenseBoost = 20;
                }
                fx_stat_change(defenseBoost + 5, x2, y2, z2, 1.0f, 60);
                script->functionTemp[3] = 15;
                script->functionTemp[0] = 3;
            } else {
                script->functionTemp[3]--;
                break;
            }
            break;
        case 3:
            if (script->functionTemp[3] == 0) {
                btl_show_variable_battle_message(BTL_MSG_DEFENCE_UP, 60, defenseBoost);
                script->functionTemp[0] = 4;
            } else {
                script->functionTemp[3]--;
                break;
            }
            break;
        case 4:
            if (btl_is_popup_displayed() == 0) {
                btl_cam_use_preset(BTL_CAM_DEFAULT);
                script->functionTemp[3] = 10;
                script->functionTemp[0] = 5;
            }
            break;
        case 5:
            if (script->functionTemp[3] != 0) {
                script->functionTemp[3]--;
                break;
            }
            if ((actor->handleEventScript != NULL) && does_script_exist(actor->handleEventScriptID)) {
                break;
            }
            ApplyingBuff = FALSE;
            return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(VanishActor) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID;
    Actor* actor;
    f32 x, y, z;
    s32 vanished;
    s32 flags;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        actorID = evt_get_variable(script, *args++);
        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }
        vanished = evt_get_variable(script, *args++);
        actor = get_actor(actorID);
        script->functionTemp[1] = (s32) actor;
        script->functionTemp[2] = vanished;

        btl_cam_use_preset(BTL_CAM_PRESET_08);
        btl_cam_set_zoffset(12);
        btl_cam_target_actor(actor->actorID);
        btl_cam_set_zoom(250);
        btl_cam_move(10);
        func_8024E60C();
        if (actor->flags & ACTOR_FLAG_UPSIDE_DOWN) {
            btl_cam_set_zoffset(0);
        }

        ApplyingBuff = TRUE;
        script->functionTemp[3] = 5;
        script->functionTemp[0] = 1;
    }
    get_actor(script->owner1.actorID);
    actor = script->functionTempPtr[1];
    vanished = script->functionTemp[2];

    flags = actor->flags;
    x = actor->curPos.x + actor->headOffset.x;
    if (flags & ACTOR_FLAG_UPSIDE_DOWN) {
        y = actor->curPos.y + actor->headOffset.y - actor->size.y / 2;
    } else if (!(flags & ACTOR_FLAG_HALF_HEIGHT)) {
        y = actor->curPos.y + actor->headOffset.y + actor->size.y / 2;
    } else {
        y = actor->curPos.y + actor->headOffset.y + actor->size.y;
    }
    z = actor->curPos.z + actor->headOffset.z + 10.0f;

    switch (script->functionTemp[0]) {
        case 1:
            if (script->functionTemp[3] == 0) {
                fx_radial_shimmer(3, x, y, z, 1.0f, 30);
                btl_cam_use_preset_immediately(BTL_CAM_PRESET_19);
                script->functionTemp[3] = 30;
                script->functionTemp[0] = 2;
            } else {
                script->functionTemp[3]--;
                break;
            }
            break;
        case 2:
            if (script->functionTemp[3] == 0) {
                dispatch_event_actor(actor, EVENT_RECEIVE_BUFF);
                btl_cam_use_preset(BTL_CAM_DEFAULT);
                btl_cam_move(15);
                inflict_status(actor, STATUS_KEY_TRANSPARENT, vanished);
                script->functionTemp[3] = 15;
                script->functionTemp[0] = 3;
            } else {
                script->functionTemp[3]--;
                break;
            }
            break;
        case 3:
            if (script->functionTemp[3] == 0) {
                btl_show_variable_battle_message(BTL_MSG_ENEMY_TRANSPARENT, 60, vanished);
                script->functionTemp[0] = 4;
            } else {
                script->functionTemp[3]--;
                break;
            }
            break;
        case 4:
            if (btl_is_popup_displayed() == 0) {
                btl_cam_use_preset(BTL_CAM_DEFAULT);
                script->functionTemp[3] = 10;
                script->functionTemp[0] = 5;
            }
            break;
        case 5:
            if (script->functionTemp[3] != 0) {
                script->functionTemp[3]--;
                break;
            }
            if ((actor->handleEventScript != NULL) && does_script_exist(actor->handleEventScriptID)) {
                break;
            }
            ApplyingBuff = FALSE;
            return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(ElectrifyActor) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID;
    Actor* actor;
    f32 x, y, z;
    s32 electrified;
    s32 flags;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        actorID = evt_get_variable(script, *args++);
        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }
        electrified = evt_get_variable(script, *args++);
        actor = get_actor(actorID);
        script->functionTempPtr[1] = actor;
        script->functionTemp[2] = electrified;

        btl_cam_use_preset(BTL_CAM_PRESET_08);
        btl_cam_set_zoffset(12);
        btl_cam_target_actor(actor->actorID);
        btl_cam_set_zoom(250);
        btl_cam_move(10);
        func_8024E60C();
        if (actor->flags & ACTOR_FLAG_UPSIDE_DOWN) {
            btl_cam_set_zoffset(0);
        }

        ApplyingBuff = TRUE;
        script->functionTemp[3] = 5;
        script->functionTemp[0] = 1;
    }
    get_actor(script->owner1.actorID);
    actor = script->functionTempPtr[1];
    electrified = script->functionTemp[2];

    flags = actor->flags;
    x = actor->curPos.x + actor->headOffset.x;
    if (flags & ACTOR_FLAG_UPSIDE_DOWN) {
        y = actor->curPos.y + actor->headOffset.y - actor->size.y / 2;
    } else if (!(flags & ACTOR_FLAG_HALF_HEIGHT)) {
        y = actor->curPos.y + actor->headOffset.y + actor->size.y / 2;
    } else {
        y = actor->curPos.y + actor->headOffset.y + actor->size.y;
    }
    z = actor->curPos.z + actor->headOffset.z + 10.0f;

    switch (script->functionTemp[0]) {
        case 1:
            if (script->functionTemp[3] == 0) {
                fx_snaking_static(8, x, y, z, 1.0f, 30);
                btl_cam_use_preset_immediately(BTL_CAM_PRESET_19);
                script->functionTemp[3] = 30;
                script->functionTemp[0] = 2;
            } else {
                script->functionTemp[3]--;
                break;
            }
            break;
        case 2:
            if (script->functionTemp[3] == 0) {
                dispatch_event_actor(actor, EVENT_RECEIVE_BUFF);
                btl_cam_use_preset(BTL_CAM_DEFAULT);
                btl_cam_move(15);
                inflict_status(actor, STATUS_KEY_STATIC, electrified);
                script->functionTemp[3] = 15;
                script->functionTemp[0] = 3;
            } else {
                script->functionTemp[3]--;
                break;
            }
            break;
        case 3:
            if (script->functionTemp[3] == 0) {
                btl_show_variable_battle_message(BTL_MSG_ENEMY_CHARGED, 60, electrified);
                script->functionTemp[0] = 4;
            } else {
                script->functionTemp[3]--;
                break;
            }
            break;
        case 4:
            if (btl_is_popup_displayed() == 0) {
                btl_cam_use_preset(BTL_CAM_DEFAULT);
                script->functionTemp[3] = 10;
                script->functionTemp[0] = 5;
            }
            break;
        case 5:
            if (script->functionTemp[3] != 0) {
                script->functionTemp[3]--;
                break;
            }
            if ((actor->handleEventScript != NULL) && does_script_exist(actor->handleEventScriptID)) {
                break;
            }
            ApplyingBuff = FALSE;
            return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(HealActor) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID;
    Actor* actor;
    f32 x1, y1, z1;
    f32 x2, y2, z2;
    s32 hpBoost;
    s32 flags;
    s32 flags2;
    s32 message;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        actorID = evt_get_variable(script, *args++);
        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.enemyID;
        }
        hpBoost = evt_get_variable(script, *args++);
        IsGroupHeal = evt_get_variable(script, *args++);
        actor = get_actor(actorID);
        script->functionTempPtr[1] = actor;
        script->functionTemp[2] = hpBoost;

        btl_cam_use_preset(BTL_CAM_PRESET_08);
        btl_cam_set_zoffset(12);
        btl_cam_target_actor(actor->actorID);
        btl_cam_move(10);
        func_8024E60C();

        ApplyingBuff = TRUE;
        script->functionTemp[3] = 5;
        script->functionTemp[0] = 1;
    }
    get_actor(script->owner1.enemyID);
    actor = script->functionTempPtr[1];
    hpBoost = script->functionTemp[2];

    flags = actor->flags;
    x1 = actor->curPos.x + actor->headOffset.x;
    if (flags & ACTOR_FLAG_UPSIDE_DOWN) {
        y1 = actor->curPos.y + actor->headOffset.y - actor->size.y / 2;
    } else if (!(flags & ACTOR_FLAG_HALF_HEIGHT)) {
        y1 = actor->curPos.y + actor->headOffset.y + actor->size.y / 2;
    } else {
        y1 = actor->curPos.y + actor->headOffset.y + actor->size.y;
    }
    z1 = actor->curPos.z + actor->headOffset.z + 10.0f;

    flags2 = actor->flags;
    x2 = actor->curPos.x + actor->headOffset.x + actor->size.x / 2;
    if (flags2 & ACTOR_FLAG_UPSIDE_DOWN) {
        y2 = actor->curPos.y + actor->headOffset.y - actor->size.y;
    } else if (!(flags2 & ACTOR_FLAG_HALF_HEIGHT)) {
        y2 = actor->curPos.y + actor->headOffset.y + actor->size.y;
    } else {
        y2 = actor->curPos.y + actor->headOffset.y + actor->size.y * 2;
    }
    z2 = actor->curPos.z + actor->headOffset.z + 10.0f;

    switch (script->functionTemp[0]) {
        case 1:
            if (script->functionTemp[3] == 0) {
                dispatch_event_actor(actor, EVENT_RECEIVE_BUFF);
                fx_recover(0, x2, y2, z2, hpBoost);
                show_start_recovery_shimmer(x1, y1, z1, hpBoost);
                script->functionTemp[3] = 30;
                script->functionTemp[0] = 2;
            } else {
                script->functionTemp[3]--;
                break;
            }
            break;
        case 2:
            if (script->functionTemp[3] == 0) {
                btl_cam_use_preset(BTL_CAM_DEFAULT);
                btl_cam_move(15);
                actor->curHP += hpBoost;
                if (actor->maxHP < actor->curHP) {
                    actor->curHP = actor->maxHP;
                }
                show_recovery_shimmer(x1, y1, z1, hpBoost);
                script->functionTemp[3] = 15;
                script->functionTemp[0] = 3;
            } else {
                script->functionTemp[3]--;
                break;
            }
            break;
        case 3:
            if (script->functionTemp[3] == 0) {
                message = BTL_MSG_HEAL_ALL;
                if (!IsGroupHeal) {
                    message = BTL_MSG_HEAL_ONE;
                }
                btl_show_variable_battle_message(message, 60, hpBoost);
                script->functionTemp[0] = 4;
            } else {
                script->functionTemp[3]--;
                break;
            }
            break;
        case 4:
            if (btl_is_popup_displayed() == 0) {
                script->functionTemp[3] = 10;
                script->functionTemp[0] = 5;
            }
            break;
        case 5:
            if (script->functionTemp[3] != 0) {
                script->functionTemp[3]--;
                break;
            }
            if ((actor->handleEventScript != NULL) && does_script_exist(actor->handleEventScriptID)) {
                break;
            }
            ApplyingBuff = FALSE;
            return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
}

API_CALLABLE(WaitForBuffDone) {
    if (!ApplyingBuff) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

API_CALLABLE(CopyBuffs) {
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
