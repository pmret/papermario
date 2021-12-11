#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"

s32 calc_item_check_hit(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActorMovement* walk = &battleStatus->playerActor->state;
    s32 actorID = battleStatus->currentTargetID;
    s8 currentTargetPartS8;
    u32 currentTargetPart;
    Actor* actor;
    ActorPart* actorPart;

    currentTargetPart = currentTargetPartS8 = battleStatus->currentTargetPart;
    battleStatus->currentTargetID2 = battleStatus->currentTargetID;
    battleStatus->currentTargetPart2 = currentTargetPartS8;

    actor = get_actor(actorID);
    if (actor != NULL) {
        actorPart = get_actor_part(actor, currentTargetPart);
        ASSERT(actorPart != NULL);

        if (!(actorPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY)) {
            if (actor->transStatus == 0xE) {
                return HIT_RESULT_MISS;
            }
            if (actor->stoneStatus == 0xC) {
                sfx_play_sound_at_position(0x10C, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
                return HIT_RESULT_IMMUNE;
            }
            if ((battleStatus->currentAttackElement & DAMAGE_TYPE_JUMP) && (actorPart->eventFlags & ACTOR_EVENT_FLAG_SPIKY_TOP)) {
                sfx_play_sound_at_position(0xE9, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
                return HIT_RESULT_LANDED_ON_SPIKE;
            }
        } else {
            return HIT_RESULT_MISS;
        }
    }
    return HIT_RESULT_HIT;
}

//INCLUDE_ASM(s32, "17FEB0", calc_item_damage_enemy);
s32 calc_item_damage_enemy(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* playerActor = battleStatus->playerActor;
    s32 currentTargetID = battleStatus->currentTargetID;
    Actor* partnerActor = battleStatus->partnerActor;
    s32 currentTargetPartID = battleStatus->currentTargetPart;
    Actor* targetActor;
    ActorPart* targetActorPart;
    ActorState* actorState;
    Evt* attackScript;
    s32 sp1C = 0;
    s32 isFireDamage = 0;
    s32 isElectricDamage = 0;
    s32 isIceDamage = 0;
    s8 wasStatusInflicted = 0;
    s32 currentHP;
    s32 baseStatusChance;
    s32 attackDamage;
    s32 targetActorDefense;
    s32 dispatchEvent;
    s32 sp18;
    s32 phi_a0_2;
    s32 phi_fp;
    
    battleStatus->wasStatusInflicted = 0;
    battleStatus->lastAttackDamage = 0;
    battleStatus->attackerActorID = playerActor->actorID;
    battleStatus->currentTargetID2 = battleStatus->currentTargetID;
    battleStatus->currentTargetPart2 = battleStatus->currentTargetPart;
    
    targetActor = get_actor(currentTargetID);
    if (targetActor == NULL) {
        return 0;
    }

    targetActorPart = get_actor_part(targetActor, currentTargetPartID);
    if (targetActorPart != NULL) {
        targetActor->lastDamageTaken = 0;
        if (gBattleStatus.flags1 & BS_FLAGS1_80000) {
            actorState = &partnerActor->state;
        } else {
            actorState = &playerActor->state;
        }

        phi_a0_2 = 0;
        if (battleStatus->currentAttackElement & DAMAGE_TYPE_FIRE) {
            playFX_24(0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z + 5.0f, 1.0f, 0x18);
            isFireDamage = TRUE;
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_ELECTRIC) {
            func_80251474(targetActor);
            isElectricDamage = TRUE;
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_WATER) {
            playFX_5F(0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z + 5.0f, 1.0f, 0x18);
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_ICE) {
            playFX_30(0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z + 5.0f);
            isIceDamage = TRUE;
        }

        if ((battleStatus->currentAttackElement & DAMAGE_TYPE_REMOVE_BUFFS) == 0) {
            if (targetActorPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
                return 6;
            }
            if (targetActor->transStatus == 14 || targetActorPart->eventFlags & ACTOR_EVENT_FLAG_800 && battleStatus->currentAttackElement & DAMAGE_TYPE_QUAKE) {
                return 6;
            }
        }

        if (targetActor->stoneStatus == 12) {
            sfx_play_sound_at_position(SOUND_10C, 0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z);
            func_8024EFE0(actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z, 0, 1, 1);
            show_damage_popup(actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z, 0, 0);
            
            if (gBattleStatus.flags1 & (BS_FLAGS1_40 | BS_FLAGS1_200)) {
                return 1;
            } else {
                return 0;
            }
        }

        sp18 = (targetActorPart->partFlags3 & battleStatus->currentAttackElement) != 0;
        if (targetActorPart->eventFlags & (ACTOR_EVENT_FLAG_ENCHANTED | ACTOR_EVENT_FLAG_80000)) {
            battleStatus->currentAttackElement &= ~DAMAGE_TYPE_IGNORE_DEFENSE;
        }

        targetActorDefense = get_defense(targetActor, targetActorPart->defenseTable, battleStatus->currentAttackElement);
        if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_IGNORE_DEFENSE)) {
            targetActorDefense += targetActor->defenseBoost;
        }

        attackDamage = battleStatus->currentAttackDamage;
        if (attackDamage >= 100) {
            attackDamage = 99;
        }

        if (attackDamage <= 0) {
            targetActorDefense = 0;
        }

        attackDamage -= targetActorDefense;
        targetActor->hpChangeCounter = 0;
        if (attackDamage <= 0) {
            targetActor->hpChangeCounter = 0;
            phi_fp = 2;
            if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS)) {
                sfx_play_sound_at_position(SOUND_10C, 0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z);
            }

            battleStatus->lastAttackDamage = 0;
            dispatchEvent = 23;
        } else {
            targetActor->damageCounter += attackDamage;
            targetActor->hpChangeCounter -= attackDamage;
            battleStatus->lastAttackDamage = 0;
            dispatchEvent = 9;
            phi_fp = 0;
            if (((targetActorPart->flags & ACTOR_PART_FLAG_2000) == 0) && sp18 == 0 && ((targetActorPart->targetFlags & ACTOR_PART_FLAG_4) == 0)) {
                targetActor->currentHP -= attackDamage;
                if (targetActor->currentHP <= 0) {
                    targetActor->currentHP = 0;
                    dispatchEvent = 32;
                }
            }

            battleStatus->lastAttackDamage += attackDamage;
            targetActor->lastDamageTaken = battleStatus->lastAttackDamage;
            targetActor->hpChangeCounter = 0;
        }

        if (targetActorPart->flags & ACTOR_PART_FLAG_2000) {
            dispatch_event_actor(targetActor, dispatchEvent);
            func_8024EFE0(actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z, 0, 1, 3);
            sfx_play_sound_at_position(SOUND_10C, 0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z);
            return 2;
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_2000) {
            battleStatus->lastAttackDamage = 0;
            dispatchEvent = 32;
            phi_fp = 0;
        }

        if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
            if (dispatchEvent == 9) {
                dispatchEvent = 10;
            }

            if (dispatchEvent == 23) {
                dispatchEvent = 25;
            }
            
            if (targetActor->currentHP <= 0) {
                if (dispatchEvent == 25) {
                    dispatchEvent = 32;
                }
            }
        } else if (dispatchEvent == 32) {
            dispatchEvent = 9;
        }

        if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
            if (battleStatus->currentAttackElement & DAMAGE_TYPE_REMOVE_BUFFS) {
                dispatchEvent = 25;
                if (targetActorPart->eventFlags & ACTOR_EVENT_FLAG_ENCHANTED) {
                    wasStatusInflicted = 1;
                    dispatchEvent = 19;
                }
                if (targetActorPart->eventFlags & ACTOR_EVENT_FLAG_400000) {
                    wasStatusInflicted = 1;
                    dispatchEvent = 19;
                }
                if (targetActorPart->eventFlags & ACTOR_EVENT_FLAG_80000) {
                    dispatchEvent = 29;
                }
                phi_fp = 0;
                goto block_68;
            }
            goto block_80;
        }
block_68:
        if (battleStatus->currentAttackElement & DAMAGE_TYPE_REMOVE_BUFFS) {
            if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
                if (targetActor->attackBoost <= 0 && targetActor->defenseBoost <= 0) {
                    if (targetActor->staticStatus == 0) {
                        if (targetActor->transStatus != 0) {
                            goto block_74;
                        }
                    } else {
                        goto block_75;
                    }
                } else {
block_74:
block_75:
                    targetActor->attackBoost = 0;
                    targetActor->defenseBoost = 0;
                    targetActor->isGlowing = 0;
                    dispatchEvent = 10;
                    if (targetActor->staticStatus != 0) {
                        targetActor->staticStatus = 0;
                        targetActor->staticDuration = 0;
                        remove_status_static(targetActor->hudElementDataIndex);
                    }
                    if (targetActor->transStatus != 0) {
                        targetActor->transStatus = 0;
                        targetActor->transDuration = 0;
                        remove_status_transparent(targetActor->hudElementDataIndex);
                    }
                    wasStatusInflicted = 1;
                    phi_fp = 0;
                }
                goto block_80;
            }
        } else {
block_80:
            if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
                if (battleStatus->currentAttackElement & DAMAGE_TYPE_PEACH_BEAM) {
                    dispatchEvent = 25;
                    if (targetActorPart->eventFlags & ACTOR_EVENT_FLAG_ENCHANTED) {
                        dispatchEvent = 20;
                        wasStatusInflicted = 1;
                    }
                    if (targetActorPart->eventFlags & ACTOR_EVENT_FLAG_80000) {
                        dispatchEvent = 20;
                        wasStatusInflicted = 1;
                    }
                }
                if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
                    if (battleStatus->currentAttackElement & DAMAGE_TYPE_SPIN_SMASH) {
                        if (dispatchEvent == 10) {
                            dispatchEvent = 11;
                        }
                        if (dispatchEvent == 32) {
                            dispatchEvent = 33;
                        }
                    }
                    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
                        if (battleStatus->currentAttackElement & (DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POW) && targetActorPart->eventFlags & ACTOR_EVENT_FLAG_GROUNDABLE) {
                            if (dispatchEvent == 10) {
                                dispatchEvent = 12;
                            }
                            if (dispatchEvent == 25) {
                                dispatchEvent = 12;
                            }
                        }
                        if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
                            if (battleStatus->currentAttackElement & DAMAGE_TYPE_POW && targetActorPart->eventFlags & ACTOR_EVENT_FLAG_800000) {
                                if (dispatchEvent == 10) {
                                    dispatchEvent = 12;
                                }
                                if (dispatchEvent == 25) {
                                    dispatchEvent = 12;
                                }
                            }
                            if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
                                if (battleStatus->currentAttackElement & (DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POW | DAMAGE_TYPE_QUAKE) && targetActorPart->eventFlags & ACTOR_EVENT_FLAG_FLIPABLE) {
                                    if (dispatchEvent == 10) {
                                        dispatchEvent = 13;
                                    }
                                    if (dispatchEvent == 25) {
                                        dispatchEvent = 13;
                                    }
                                }
                                if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
                                    if (battleStatus->currentAttackElement & DAMAGE_TYPE_FIRE) {
                                        if (dispatchEvent == 10) {
                                            dispatchEvent = 14;
                                        }
                                        if (dispatchEvent == 32) {
                                            dispatchEvent = 36;
                                        }
                                        isFireDamage = 1;
                                    }
                                    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE && battleStatus->lastAttackDamage >= 0 && dispatchEvent != 32 && dispatchEvent != 33 && dispatchEvent != 34) {
                                        if (battleStatus->currentAttackStatus & STATUS_FLAG_SHRINK && try_inflict_status(targetActor, STATUS_SHRINK, STATUS_SHRINK_TURN_MOD)) {
                                            wasStatusInflicted = 1;
                                        }
                                        if (battleStatus->currentAttackStatus & STATUS_FLAG_POISON && try_inflict_status(targetActor, STATUS_POISON, STATUS_POISON_TURN_MOD)) {
                                            wasStatusInflicted = 1;
                                        }
                                        if (battleStatus->currentAttackStatus & STATUS_FLAG_STONE && try_inflict_status(targetActor, STATUS_STONE, STATUS_STONE_TURN_MOD)) {
                                            wasStatusInflicted = 1;
                                        }
                                        if (battleStatus->currentAttackStatus & STATUS_FLAG_SLEEP && try_inflict_status(targetActor, STATUS_SLEEP, STATUS_SLEEP_TURN_MOD)) {
                                            wasStatusInflicted = 1;
                                        }
                                        if (battleStatus->currentAttackStatus & STATUS_FLAG_STOP && try_inflict_status(targetActor, STATUS_STOP, STATUS_STOP_TURN_MOD)) {
                                            wasStatusInflicted = 1;
                                        }
                                        if (battleStatus->currentAttackStatus & STATUS_FLAG_STATIC && try_inflict_status(targetActor, STATUS_STATIC, STATUS_STATIC_TURN_MOD)) {
                                            wasStatusInflicted = 1;
                                        }
                                        if (battleStatus->currentAttackStatus & STATUS_FLAG_FEAR && try_inflict_status(targetActor, STATUS_FEAR, STATUS_FEAR_TURN_MOD)) {
                                            wasStatusInflicted = 1;
                                        }
                                        if (battleStatus->currentAttackStatus & STATUS_FLAG_PARALYZE && try_inflict_status(targetActor, STATUS_PARALYZE, STATUS_PARALYZE_TURN_MOD)) {
                                            wasStatusInflicted = 1;
                                        }
                                        if (battleStatus->currentAttackStatus & STATUS_FLAG_DIZZY && try_inflict_status(targetActor, STATUS_DIZZY, STATUS_DIZZY_TURN_MOD)) {
                                            wasStatusInflicted = 1;
                                        }
                                        if (wasStatusInflicted != 0) {
                                            if (dispatchEvent == 23) {
                                                dispatchEvent = 9;
                                            }
                                            if (dispatchEvent == 25) {
                                                dispatchEvent = 10;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        baseStatusChance = (battleStatus->statusChance * targetActor->staticActorData->baseStatusChance) / 100;
        if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE && battleStatus->currentAttackElement & DAMAGE_TYPE_FEAR) {
            dispatchEvent = 25;
            if (rand_int(99) < baseStatusChance) {
                phi_fp = 2;
                if (targetActor->debuff - 3 >= 6) {
                    phi_fp = 2;
                    if (!(targetActor->flags & ACTOR_FLAG_400)) {
                        sp1C = 1;
                        gBattleStatus.flags1 |= (BS_FLAGS1_1 | BS_FLAGS1_8 | BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE);
                        sfx_play_sound_at_position(SOUND_UNKNOWN_231, 0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z);
                        gBattleStatus.flags1 |= BS_FLAGS1_40;
                        wasStatusInflicted = 1;
                        dispatchEvent = 57;
                        phi_fp = 0;
                    }
                }
            } else {
                phi_fp = 2;
            }
        }

        battleStatus->wasStatusInflicted = wasStatusInflicted;
        if (sp1C != 0 && (gBattleStatus.flags1 & (BS_FLAGS1_40 | BS_FLAGS1_200) || gBattleStatus.flags1 & (BS_FLAGS1_40 | BS_FLAGS1_200) && gBattleStatus.flags1 & BS_FLAGS1_80 && battleStatus->lastAttackDamage > 0) && (sfx_play_sound_at_position(0x231, 0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z), battleStatus->lastAttackDamage > 0) || battleStatus->currentAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS && sp1C != 0) {
            if (!(gBattleStatus.flags1 & BS_FLAGS1_40)) {
                phi_a0_2 = 3;
            } 
            func_802667F0(phi_a0_2, targetActor, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z);
        }

        if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
            func_80266970(targetActor);
        }

        dispatch_event_actor(targetActor, dispatchEvent);
        if (currentTargetID & 0x700 == 0x100) {
            if (battleStatus->lastAttackDamage > 0 && gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
                inflict_status(targetActor, 13, battleStatus->lastAttackDamage);
            }
        }

        if (!(targetActor->flags & ACTOR_FLAG_NO_DMG_POPUP)) {
            if (battleStatus->lastAttackDamage == 0) {
                if (sp1C == 0 && !wasStatusInflicted) {
                    func_8024EFE0(actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z, 0, 1, 3);
                }
            } else if (sp18 == 0) {
                if (battleStatus->currentAttackElement & (DAMAGE_TYPE_SMASH | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS)) {
                    show_damage_popup(actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z, battleStatus->lastAttackDamage, 0);
                } else {
                    func_802664DC(actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z, battleStatus->lastAttackDamage, 0);
                }
                if (!(targetActorPart->targetFlags & 4)) {
                    func_802666E4(targetActor, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z, battleStatus->lastAttackDamage);
                }
            }
        }

        if (battleStatus->lastAttackDamage > 0) {
            if (sp18 == 0) {
                func_80267018(targetActor, 1);
                if (isFireDamage) {
                    sfx_play_sound_at_position(SOUND_FIRE, 0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z);
                } else if (isElectricDamage) {
                    sfx_play_sound_at_position(SOUND_ELECTRIC, 0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z);
                } else if (isIceDamage) {
                    sfx_play_sound_at_position(SOUND_FREEZE, 0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z);
                } else {
                    sfx_play_sound_at_position(SOUND_E9, 0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z);
                }
            }

            if (battleStatus->lastAttackDamage <= 0) {
                goto block_204;
            }
            goto block_205;
        }
block_204:
        if (wasStatusInflicted) {
block_205:
            if (targetActorPart->flags & ACTOR_FLAG_2000) {
                goto block_206;
            }
        } else {
block_206:
            sfx_play_sound_at_position(SOUND_10C, 0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z);
        }

        if (battleStatus->currentAttackStatus & STATUS_FLAG_SLEEP && wasStatusInflicted) {
            attackScript = start_script(DoSleepHit, 10, 0);
            attackScript->varTable[0] = actorState->goalPos.x;
            attackScript->varTable[1] = actorState->goalPos.y;
            attackScript->varTable[2] = actorState->goalPos.z;
            sfx_play_sound_at_position(SOUND_INFLICT_SLEEP, 0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z);
        }

        if (battleStatus->currentAttackStatus & STATUS_FLAG_DIZZY && wasStatusInflicted) {
            attackScript = start_script(DoDizzyHit, 10, 0);
            attackScript->varTable[0] = actorState->goalPos.x;
            attackScript->varTable[1] = actorState->goalPos.y;
            attackScript->varTable[2] = actorState->goalPos.z;
            sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z);
        }

        if (battleStatus->currentAttackStatus & STATUS_FLAG_PARALYZE && wasStatusInflicted) {
            attackScript = start_script(DoParalyzeHit, 10, 0);
            attackScript->varTable[0] = actorState->goalPos.x;
            attackScript->varTable[1] = actorState->goalPos.y;
            attackScript->varTable[2] = actorState->goalPos.z;
            sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z);
        }

        if (battleStatus->currentAttackStatus & STATUS_FLAG_POISON && wasStatusInflicted) {
            attackScript = start_script(DoPoisonHit, 10, 0);
            attackScript->varTable[0] = actorState->goalPos.x;
            attackScript->varTable[1] = actorState->goalPos.y;
            attackScript->varTable[2] = actorState->goalPos.z;
            sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z);
        }

        if (battleStatus->currentAttackStatus & STATUS_FLAG_STOP && wasStatusInflicted) {
            attackScript = start_script(DoStopHit, 10, 0);
            attackScript->varTable[0] = actorState->goalPos.x;
            attackScript->varTable[1] = actorState->goalPos.y;
            attackScript->varTable[2] = actorState->goalPos.z;
            sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z);
        }

        if (battleStatus->currentAttackStatus & STATUS_FLAG_FROZEN && wasStatusInflicted) {
            attackScript = start_script(DoFreezeHit, 10, 0);
            attackScript->varTable[0] = actorState->goalPos.x;
            attackScript->varTable[1] = actorState->goalPos.y;
            attackScript->varTable[2] = actorState->goalPos.z;
            attackScript->varTable[3] = targetActor;
            sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z);
        }

        if (battleStatus->currentAttackStatus & STATUS_FLAG_SHRINK && wasStatusInflicted) {
            attackScript = start_script(DoShrinkHit, 10, 0);
            attackScript->varTable[0] = actorState->goalPos.x;
            attackScript->varTable[1] = actorState->goalPos.y;
            attackScript->varTable[2] = actorState->goalPos.z;
            attackScript->varTable[3] = targetActor;
            sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z);
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_SMASH && targetActor->actorType == 0x93) {
            sfx_play_sound_at_position(SOUND_SMASH_GOOMNUT_TREE, 0, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z);
        }
        
        func_80266ADC(targetActor);
        if (gBattleStatus.flags1 & (BS_FLAGS1_40 | BS_FLAGS1_200)) {
            if (phi_fp == 0) {
                phi_fp = 1;
            }
            if (phi_fp == 2) {
                phi_fp = 3;
            }
        }
        return phi_fp;
    }
loop_5:
    goto loop_5;
}

ApiStatus ItemDamageEnemy(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 itemDamageOut = *args++;
    s32 a5;
    Actor* actor;
    s32 itemDamage;
    s32 flag = 0x10;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = 0;
    battleStatus->currentAttackStatus = *args++;
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
    a5 = *args++;

    if ((a5 & 0x30) == 0x30) {
        gBattleStatus.flags1 |= (BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE);
    } else if (a5 & flag) {
        gBattleStatus.flags1 = (gBattleStatus.flags1 | flag) & ~BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (a5 & 0x20) {
        gBattleStatus.flags1 = (gBattleStatus.flags1 & ~flag) | BS_FLAGS1_SP_EVT_ACTIVE;
    } else {
        gBattleStatus.flags1 = (gBattleStatus.flags1 & ~flag) & ~BS_FLAGS1_SP_EVT_ACTIVE;
    }

    if (a5 & 0x40) {
        gBattleStatus.flags1 |= BS_FLAGS1_40;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_40;
    }

    if (a5 & 0x200) {
        gBattleStatus.flags1 |= BS_FLAGS1_200;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_200;
    }

    if (a5 & 0x80) {
        gBattleStatus.flags1 |= BS_FLAGS1_80;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_80;
    }

    actor = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;

    if ((battleStatus->statusChance & 0xFF) == 0xFF) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;

    itemDamage = calc_item_damage_enemy();
    if (itemDamage < 0) {
        return ApiStatus_FINISH;
    }

    evt_set_variable(script, itemDamageOut, itemDamage);
    if (!does_script_exist_by_ref(script)) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus ItemAfflictEnemy(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 itemDamageOut = *args++;
    s32 a5;
    Actor* actor;
    s32 itemDamage;
    s32 flag = 0x10;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = 0;
    battleStatus->currentAttackStatus = *args++;
    battleStatus->currentAttackStatus |= evt_get_variable(script, *args++);
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
    a5 = *args++;

    if ((a5 & 0x30) == 0x30) {
        gBattleStatus.flags1 |= (BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE);
    } else if (a5 & flag) {
        gBattleStatus.flags1 = (gBattleStatus.flags1 | flag) & ~BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (a5 & 0x20) {
        gBattleStatus.flags1 = (gBattleStatus.flags1 & ~flag) | BS_FLAGS1_SP_EVT_ACTIVE;
    } else {
        gBattleStatus.flags1 = (gBattleStatus.flags1 & ~flag) & ~BS_FLAGS1_SP_EVT_ACTIVE;
    }

    if (a5 & 0x40) {
        gBattleStatus.flags1 |= BS_FLAGS1_40;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_40;
    }

    if (a5 & 0x200) {
        gBattleStatus.flags1 |= BS_FLAGS1_200;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_200;
    }

    if (a5 & 0x80) {
        gBattleStatus.flags1 |= BS_FLAGS1_80;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_80;
    }

    actor = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;

    if ((battleStatus->statusChance & 0xFF) == 0xFF) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;

    itemDamage = calc_item_damage_enemy();
    if (itemDamage < 0) {
        return ApiStatus_FINISH;
    }

    evt_set_variable(script, itemDamageOut, itemDamage);
    if (!does_script_exist_by_ref(script)) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus func_80252B3C(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 itemDamageOut = *args++;
    s32 a5;
    Actor* actor;
    s32 itemDamage;
    s32 flag = 0x10;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = 0;
    battleStatus->currentAttackStatus = evt_get_variable(script, *args++);
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
    a5 = *args++;

    if ((a5 & 0x30) == 0x30) {
        gBattleStatus.flags1 |= (BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE);
    } else if (a5 & flag) {
        gBattleStatus.flags1 = (gBattleStatus.flags1 | flag) & ~BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (a5 & 0x20) {
        gBattleStatus.flags1 = (gBattleStatus.flags1 & ~flag) | BS_FLAGS1_SP_EVT_ACTIVE;
    } else {
        gBattleStatus.flags1 = (gBattleStatus.flags1 & ~flag) & ~BS_FLAGS1_SP_EVT_ACTIVE;
    }

    if (a5 & 0x40) {
        gBattleStatus.flags1 |= BS_FLAGS1_40;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_40;
    }

    if (a5 & 0x200) {
        gBattleStatus.flags1 |= BS_FLAGS1_200;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_200;
    }

    if (a5 & 0x80) {
        gBattleStatus.flags1 |= BS_FLAGS1_80;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_80;
    }

    actor = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;

    if ((battleStatus->statusChance & 0xFF) == 0xFF) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;

    itemDamage = calc_item_damage_enemy();
    if (itemDamage < 0) {
        return ApiStatus_FINISH;
    }

    evt_set_variable(script, itemDamageOut, itemDamage);
    if (!does_script_exist_by_ref(script)) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus ItemCheckHit(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 itemDamageOut = *args++;
    s32 a5;
    Actor* actor;
    s32 itemDamage;
    s32 flag = 0x10;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = 0;
    battleStatus->currentAttackStatus = *args++;
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
    a5 = *args++;

    if ((a5 & 0x30) == 0x30) {
        gBattleStatus.flags1 |= (BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE);
    } else if (a5 & flag) {
        gBattleStatus.flags1 = (gBattleStatus.flags1 | flag) & ~BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (a5 & 0x20) {
        gBattleStatus.flags1 = (gBattleStatus.flags1 & ~flag) | BS_FLAGS1_SP_EVT_ACTIVE;
    } else {
        gBattleStatus.flags1 = (gBattleStatus.flags1 & ~flag) & ~BS_FLAGS1_SP_EVT_ACTIVE;
    }

    if (a5 & 0x40) {
        gBattleStatus.flags1 |= BS_FLAGS1_40;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_40;
    }

    if (a5 & 0x200) {
        gBattleStatus.flags1 |= BS_FLAGS1_200;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_200;
    }

    if (a5 & 0x80) {
        gBattleStatus.flags1 |= BS_FLAGS1_80;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_80;
    }

    actor = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;

    if ((battleStatus->statusChance & 0xFF) == 0xFF) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;

    itemDamage = calc_item_check_hit();
    if (itemDamage < 0) {
        return ApiStatus_FINISH;
    }

    evt_set_variable(script, itemDamageOut, itemDamage);

    return ApiStatus_DONE2;
}
