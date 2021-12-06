#include "common.h"
#include "battle/battle.h"
s32 calc_partner_damage_enemy(void);

void dispatch_event_partner(s32 lastEventType) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Evt* onHitScript = partnerActor->onHitScript;
    s32 onHitID = partnerActor->onHitID;
    Evt* script;

    partnerActor->lastEventType = lastEventType;
    script = start_script(partnerActor->onHitScriptSource, 10, 0x20);
    partnerActor->onHitScript = script;
    partnerActor->onHitID = script->id;
    script->owner1.actorID = ACTOR_PARTNER;

    if (partnerActor->takeTurnScript != NULL) {
        kill_script_by_ID(partnerActor->takeTurnID);
        partnerActor->takeTurnScript = NULL;
    }

    if (onHitScript != NULL) {
        kill_script_by_ID(onHitID);
    }
}

void dispatch_event_partner_continue_turn(s8 lastEventType) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Evt* onHitScript = partnerActor->onHitScript;
    s32 onHitID = partnerActor->onHitID;
    Evt* script;

    partnerActor->lastEventType = lastEventType;
    script = start_script(partnerActor->onHitScriptSource, 10, 0x20);
    partnerActor->onHitScript = script;
    partnerActor->onHitID = script->id;
    script->owner1.actorID = ACTOR_PARTNER;

    if (onHitScript != NULL) {
        kill_script_by_ID(onHitID);
    }
}

#ifdef NON_EQUIVALENT
s32 calc_partner_test_enemy(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* actor;
    Actor* partner;
    ActorPart* actorPart;
    ActorMovement* state;
    s32 temp_s2;
    s32 new_var;

    partner = battleStatus->partnerActor;
    state = &partner->state;
    temp_s2 = battleStatus->currentTargetPart;
    new_var = battleStatus->currentTargetID;
    battleStatus->currentTargetID2 = new_var;

    battleStatus->currentTargetPart2 = battleStatus->currentTargetPart;
    actor = get_actor(battleStatus->currentTargetID);

    if (actor != NULL) {
        actorPart = get_actor_part(actor, temp_s2);
        ASSERT(actorPart != NULL);
        if (actor->stoneStatus != 0xC) {
            if (!(actorPart->eventFlags & 0x20) && actor->transStatus != 0xE) {
                if ((battleStatus->currentAttackElement & 0x80) != 0) {
                    if (actorPart->eventFlags & 0x10 && !(actor->flags2 & 0x800)) {
                        sfx_play_sound_at_position(0x108, 0, partner->state.currentPos.x,
                                                   partner->state.currentPos.y, partner->state.currentPos.z);
                        return 4;
                    }
                }

                if (!(battleStatus->currentAttackElement & (0x10000000 | 0x80)) &&
                    (actorPart->eventFlags & 0x10000) && !(battleStatus->currentAttackEventSuppression & 4) &&
                    !(player_team_is_ability_active(state, 2))) {
                    sfx_play_sound_at_position(0x108, 0, partner->state.currentPos.x,
                                               partner->state.currentPos.y, partner->state.currentPos.z);
                    dispatch_damage_event_partner_1(1, 0x2A);
                    dispatch_event_actor(actor, 0x1B);
                    return -1;
                }
                
                if ((battleStatus->currentAttackElement & (0x10000000 | 0x40)) ||
                    !(actorPart->eventFlags & 2) || battleStatus->currentAttackEventSuppression & 0x10) {
                    if (battleStatus->currentAttackElement & 0x8000) {
                        if (!(battleStatus->currentAttackElement & 0x10000000)) {
                            if ((actorPart->eventFlags & 0x10) && (!(actor->flags & 0x800))&&
                                !(battleStatus->currentAttackEventSuppression & 1)) {
                                sfx_play_sound_at_position(0x108, 0, partner->state.currentPos.x,
                                                           partner->state.currentPos.y, partner->state.currentPos.z);
                                dispatch_damage_event_partner_1(1, 0x2A);
                                dispatch_event_actor(actor, 0x1B);
                                return -1;
                            }

                            if ((!(battleStatus->currentAttackElement & 0x10000000)) &&
                                (actorPart->eventFlags & 0x200000) && !(actor->flags & 0x800) &&
                                !(battleStatus->currentAttackEventSuppression & 0x80)) {
                                sfx_play_sound_at_position(0x108, 0, partner->state.currentPos.x,
                                                           partner->state.currentPos.y, partner->state.currentPos.z);
                                dispatch_damage_event_partner_1(1, 0x2A);
                                dispatch_event_actor(actor, 0x1B);
                                return -1;
                            }
                        }

                        if (actor->staticStatus == 0xB) {
                            //missing code here (?)
                        }
                        
                        if ((actor->staticStatus == 0xB || actorPart->eventFlags & 0x80) &&
                            !(battleStatus->currentAttackElement & 0x10000000) &&
                            !(battleStatus->currentAttackEventSuppression & 8)) {
                            sfx_play_sound_at_position(0x37B, 0, partner->state.currentPos.x,
                                                       partner->state.currentPos.y, partner->state.currentPos.z);
                            func_80251474(partner);
                            dispatch_damage_event_partner_1(1, 0x2F);
                            return -1;
                        } 
                    }
                }
                //missing code here (?)
                sfx_play_sound_at_position(0xEA, 0, partner->state.currentPos.x,
                                           partner->state.currentPos.y, partner->state.currentPos.z);
                dispatch_damage_event_partner_1(1, 0x2C);
                dispatch_event_actor(actor, 0x1C);
                return -1;
            }
            return 6;
        }
        return 8;
    }
    return 0;
}
#else
INCLUDE_ASM(s32, "1AC760", calc_partner_test_enemy);
#endif


INCLUDE_ASM(s32, "1AC760", calc_partner_damage_enemy);

//Some slight stack / ordering issues at the beginning
#ifdef NON_EQUIVALENT
s32 dispatch_damage_event_partner(s32 damageAmount, s32 event, s32 stopMotion) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    ActorMovement* state = &partner->state;
    s32 flagCheck;
    s32 temp_a1;

    damageAmount = (s16)damageAmount;
    battleStatus->currentAttackDamage = damageAmount;
    partner->currentHP = 127;
    temp_a1 = (s16)(partner->hpChangeCounter + damageAmount);
    partner->hpChangeCounter += damageAmount;
    partner->hpChangeCounter -= temp_a1;
    partner->damageCounter += temp_a1;
    battleStatus->lastAttackDamage = 0;
    partner->currentHP -= temp_a1;

    if (partner->currentHP <= 0) {
        battleStatus->lastAttackDamage += partner->currentHP;
        partner->currentHP = 0;
        event = 0x20;
    }

    battleStatus->lastAttackDamage += temp_a1;
    partner->lastDamageTaken = battleStatus->lastAttackDamage;
    battleStatus->unk_19A = 0;

    if (battleStatus->flags1 & 0x20) {
        if (event == 0x9) {
            event = 0xA;
        }
        if (event == 0x17) {
            event = 0x19;
        }
    }

    if (battleStatus->lastAttackDamage > 0) {
        BattleStatus* battleStatus2 = &gBattleStatus; // TODO macro for setting flags of battleStatus
        battleStatus2->flags1 |= 0x20;

        inflict_status(partner, 0xD, battleStatus->lastAttackDamage);
    }

    if (stopMotion == 0) {
        set_goal_pos_to_part(state, 0x100, 0);
    }

    show_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z,
                      battleStatus->lastAttackDamage, 1);
    func_802666E4(partner, state->goalPos.x, state->goalPos.y, state->goalPos.z,
                  battleStatus->lastAttackDamage);

    if (battleStatus->lastAttackDamage > 0) {
        func_80267018(partner, 1);
    }

    partner->flags |= 0x80000;

    flagCheck = (gBattleStatus.flags1 & 0x240) != 0;
    dispatch_event_partner(event);
    return flagCheck;
}
#else
INCLUDE_ASM(s32, "1AC760", dispatch_damage_event_partner);
#endif

s32 dispatch_damage_event_partner_0(s32 damageAmount, s32 event, s32 stopMotion) {
    return dispatch_damage_event_partner(damageAmount, event, FALSE);
}

s32 dispatch_damage_event_partner_1(s32 damageAmount, s32 event) {
    return dispatch_damage_event_partner(damageAmount, event, TRUE);
}

ApiStatus MakeOwnerTargetIndex(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    s32 numTargets = actor->targetListLength;
    s8* targetList = &actor->targetIndexList;
    s32 arg1 = evt_get_variable(script, *args++);
    s32 arg2 = evt_get_variable(script, *args++);
    s32 otherArg = *args++;
    SelectableTarget* selectableTarget;

    if (numTargets == 0) {
        arg2 = -1;
    } else {
        if (arg2 != 0) {
            if (arg2 >= numTargets) {
                arg2 = numTargets - 1;
            } else {
                arg2--;
            }
        }

        selectableTarget = &actor->targetData[targetList[arg2]];
        actor->targetActorID = selectableTarget->actorID;
        actor->targetPartIndex = selectableTarget->partID;
    }

    evt_set_variable(script, otherArg, arg2);
    return ApiStatus_DONE2;
}

ApiStatus func_8027FC90(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 hitResult;
    Actor* actor;
    s32 actorID = evt_get_variable(script, *args++);
    s32 outVar;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.enemyID;
    }

    outVar = *args++;
    actor = get_actor(actorID);
    battleStatus->flags1 |= 0x20;

    hitResult = calc_partner_damage_enemy();
    show_damage_popup(actor->state.goalPos.x, actor->state.goalPos.y, actor->state.goalPos.z, battleStatus->lastAttackDamage,
                      0);
    evt_set_variable(script, outVar, hitResult);

    return ApiStatus_DONE2;
}

ApiStatus GetActorLevel(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Bytecode* outVar;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.enemyID;
    }

    outVar = *args++;
    evt_set_variable(script, outVar, get_actor(actorID)->staticActorData->level);

    return ApiStatus_DONE2;
}

ApiStatus PartnerDamageEnemy(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* enemy = get_actor(script->owner1.enemy);
    s32 temp_s4 = *args++;
    s32 flags;
    s32 damageResult;
    u8 statusChance;

    gBattleStatus.currentAttackElement = *args++;
    gBattleStatus.currentAttackEventSuppression = *args++;
    gBattleStatus.currentAttackStatus = *args++;
    gBattleStatus.currentAttackDamage = evt_get_variable(script, *args++);
    gBattleStatus.powerBounceCounter = 0;
    flags = *args++;

    if ((flags & 0x30) == 0x30) {
        battleStatus->flags1 |= 0x10;
        battleStatus->flags1 |= 0x20;
    } else if (flags & 0x10) {
        battleStatus->flags1 |= 0x10;
        battleStatus->flags1 &= ~0x20;
    } else if (flags & 0x20) {
        battleStatus->flags1 &= ~0x10;
        battleStatus->flags1 |= 0x20;
    } else {
        battleStatus->flags1 &= ~0x10;
        battleStatus->flags1 &= ~0x20;
    }

    if (flags & 0x40) {
        gBattleStatus.flags1 |= 0x40;
    } else {
        gBattleStatus.flags1 &= -0x41;
    }

    if (flags & 0x200) {
        gBattleStatus.flags1 |= 0x200;
    } else {
        gBattleStatus.flags1 &= -0x201;
    }

    if (flags & 0x80) {
        gBattleStatus.flags1 |= 0x80;
    } else {
        gBattleStatus.flags1 &= -0x81;
    }

    if (flags & 0x800) {
        gBattleStatus.flags1 |= 0x800;
    } else {
        gBattleStatus.flags1 &= -0x801;
    }

    statusChance = battleStatus->currentAttackStatus;
    battleStatus->currentTargetID = enemy->targetActorID;
    battleStatus->currentTargetPart = enemy->targetPartIndex;
    battleStatus->statusChance = statusChance;
    
    if (statusChance == 0xFF) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;
    damageResult = calc_partner_damage_enemy();

    if (damageResult < 0) {
        return ApiStatus_FINISH;
    }

    evt_set_variable(script, temp_s4, damageResult);

    if (!does_script_exist_by_ref(script)) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus PartnerAfflictEnemy(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.enemyID);
    s32 returnValue = *args++;
    s32 flags;
    u8 statusChance;
    s32 damageResult;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = *args++;
    battleStatus->currentAttackStatus = *args++;
    battleStatus->currentAttackStatus |= evt_get_variable(script, *args++);
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
    battleStatus->powerBounceCounter = 0;
    flags = *args++;

    if ((flags & 0x30) == 0x30) {
        battleStatus->flags1 |= 0x10;
        battleStatus->flags1 |= 0x20;
    } else if (flags & 0x10) {
        battleStatus->flags1 |= 0x10;
        battleStatus->flags1 &= ~0x20;
    } else if (flags & 0x20) {
        battleStatus->flags1 &= ~0x10;
        battleStatus->flags1 |= 0x20;
    } else {
        battleStatus->flags1 &= ~0x10;
        battleStatus->flags1 &= ~0x20;
    }

    if (flags & 0x40) {
        gBattleStatus.flags1 |= 0x40;
    } else {
        gBattleStatus.flags1 &= ~0x40;
    }
    if (flags & 0x200) {
        gBattleStatus.flags1 |= 0x200;
    } else {
        gBattleStatus.flags1 &= ~0x200;
    }
    if (flags & 0x80) {
        gBattleStatus.flags1 |= 0x80;
    } else {
        gBattleStatus.flags1 &= ~0x80;
    }
    if (flags & 0x800) {
        gBattleStatus.flags1 |= 0x800;
    } else {
        gBattleStatus.flags1 &= ~0x800;
    }

    statusChance = battleStatus->currentAttackStatus;
    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = statusChance;

    if (statusChance == 0xFF) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;
    damageResult = calc_partner_damage_enemy();

    if (damageResult < 0) {
        return ApiStatus_FINISH;
    }

    evt_set_variable(script, returnValue, damageResult);

    if (!does_script_exist_by_ref(script)) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus PartnerPowerBounceEnemy(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.enemyID);
    s32 returnValue = *args++;
    s32 flags;
    u8 statusChance;
    s32 damageResult;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = *args++;
    battleStatus->currentAttackStatus = *args++;
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
    battleStatus->powerBounceCounter = evt_get_variable(script, *args++);
    flags = *args++;
    
    if ((flags & 0x30) == 0x30) {
        battleStatus->flags1 |= 0x10;
        battleStatus->flags1 |= 0x20;
    } else if (flags & 0x10) {
        battleStatus->flags1 |= 0x10;
        battleStatus->flags1 &= ~0x20;
    } else if (flags & 0x20) {
        battleStatus->flags1 &= ~0x10;
        battleStatus->flags1 |= 0x20;
    } else {
        battleStatus->flags1 &= ~0x10;
        battleStatus->flags1 &= ~0x20;
    }

    if (flags & 0x40) {
        gBattleStatus.flags1 |= 0x40;
    } else {
        gBattleStatus.flags1 &= ~0x40;
    }
    if (flags & 0x200) {
        gBattleStatus.flags1 |= 0x200;
    } else {
        gBattleStatus.flags1 &= ~0x200;
    }
    if (flags & 0x80) {
        gBattleStatus.flags1 |= 0x80;
    } else {
        gBattleStatus.flags1 &= ~0x80;
    }
    if (flags & 0x800) {
        gBattleStatus.flags1 |= 0x800;
    } else {
        gBattleStatus.flags1 &= ~0x800;
    }

    statusChance = battleStatus->currentAttackStatus;
    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = statusChance;

    if (statusChance == 0xFF) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;
    damageResult = calc_partner_damage_enemy();

    if (damageResult < 0) {
        return ApiStatus_FINISH;
    }

    evt_set_variable(script, returnValue, damageResult);

    if (!does_script_exist_by_ref(script)) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus PartnerTestEnemy(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* enemy = get_actor(script->owner1.enemy);
    s32 temp_s4;
    s32 flags;
    s32 damageResult;
    u8 statusChance;

    temp_s4 = *args++;
    gBattleStatus.currentAttackElement = *args++;
    gBattleStatus.currentAttackEventSuppression = *args++;
    gBattleStatus.currentAttackStatus = *args++;
    gBattleStatus.currentAttackDamage = evt_get_variable(script, *args++);
    gBattleStatus.powerBounceCounter = 0;
    flags = *args++;

    if ((flags & 0x30) == 0x30) {
        battleStatus->flags1 |= 0x10;
        battleStatus->flags1 |= 0x20;
    } else if (flags & 0x10) {
        battleStatus->flags1 |= 0x10;
        battleStatus->flags1 &= ~0x20;
    } else if (flags & 0x20) {
        battleStatus->flags1 &= ~0x10;
        battleStatus->flags1 |= 0x20;
    } else {
        battleStatus->flags1 &= ~0x10;
        battleStatus->flags1 &= ~0x20;
    }

    if (flags & 0x40) {
        gBattleStatus.flags1 |= 0x40;
    } else {
        gBattleStatus.flags1 &= -0x41;
    }

    if (flags & 0x200) {
        gBattleStatus.flags1 |= 0x200;
    } else {
        gBattleStatus.flags1 &= -0x201;
    }

    if (flags & 0x80) {
        gBattleStatus.flags1 |= 0x80;
    } else {
        gBattleStatus.flags1 &= -0x81;
    }

    if (flags & 0x800) {
        gBattleStatus.flags1 |= 0x800;
    } else {
        gBattleStatus.flags1 &= -0x801;
    }

    statusChance = battleStatus->currentAttackStatus;
    battleStatus->currentTargetID = enemy->targetActorID;
    battleStatus->currentTargetPart = enemy->targetPartIndex;
    battleStatus->statusChance = statusChance;
    
    if (statusChance == 0xFF) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;
    damageResult = calc_partner_test_enemy();

    if (damageResult < 0) {
        return ApiStatus_FINISH;
    }

    evt_set_variable(script, temp_s4, damageResult);

    return ApiStatus_DONE2;
}

ApiStatus func_8028070C(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    s32 damageAmount = evt_get_variable(script, *args++);
    s32 event = evt_get_variable(script, *args++);

    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;

    if (dispatch_damage_event_partner_0(damageAmount, event, battleStatus) >= 0) {
        return does_script_exist_by_ref(script) ? ApiStatus_DONE2 : ApiStatus_BLOCK;
    }

    return ApiStatus_BLOCK;
}

ApiStatus DeletePartner(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    btl_delete_actor(battleStatus->partnerActor);
    return ApiStatus_DONE2;
}

ApiStatus GetActionCommandResult(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 var = *script->ptrReadPos;
    s32 actionSuccess = battleStatus->actionSuccess;
    s32 outVal = 0;

    if (actionSuccess < outVal) {
        actionSuccess = outVal;
    }

    if (actionSuccess > outVal) {
        outVal = actionSuccess;
    }

    evt_set_variable(script, var, outVal);
    return ApiStatus_DONE2;
}

/// Seems to be the same functionality as YieldTurn in 1A5830.c
ApiStatus func_80280818(Evt* script, s32 isInitialCall) {
    gBattleStatus.flags1 |= 0x200000;
    return ApiStatus_DONE2;
}
