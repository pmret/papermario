#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"

s32 dispatch_damage_event_player(s32 damageAmount, s32 event, s32 arg2);

ApiStatus func_80271210(Evt* script, s32 isInitialCall) {
    fx_debuff(0, script->varTable[0], script->varTable[1], script->varTable[2]);
    return ApiStatus_DONE2;
}

ApiStatus func_80271258(Evt* script, s32 isInitialCall) {
    fx_debuff(1, script->varTable[0], script->varTable[1], script->varTable[2]);
    return ApiStatus_DONE2;
}

ApiStatus func_802712A0(Evt* script, s32 isInitialCall) {
    EffectInstance* debuffEffect = fx_debuff(2, script->varTable[0], script->varTable[1], script->varTable[2]);

    debuffEffect->data.debuff->unk_38 = 200;
    debuffEffect->data.debuff->unk_39 = 120;
    debuffEffect->data.debuff->unk_3A = 0;
    debuffEffect->data.debuff->unk_3B = 234;
    debuffEffect->data.debuff->unk_3C = 193;
    debuffEffect->data.debuff->unk_3D = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_80271328(Evt* script, s32 isInitialCall) {
    EffectInstance* debuffEffect = fx_debuff(2, script->varTable[0], script->varTable[1], script->varTable[2]);

    debuffEffect->data.debuff->unk_38 = 60;
    debuffEffect->data.debuff->unk_39 = 160;
    debuffEffect->data.debuff->unk_3A = 0;
    debuffEffect->data.debuff->unk_3B = 90;
    debuffEffect->data.debuff->unk_3C = 240;
    debuffEffect->data.debuff->unk_3D = 0;
    return ApiStatus_DONE2;
}

ApiStatus func_802713B0(Evt* script, s32 isInitialCall) {
    EffectInstance* debuffEffect = fx_debuff(2, script->varTable[0], script->varTable[1], script->varTable[2]);

    debuffEffect->data.debuff->unk_38 = 205;
    debuffEffect->data.debuff->unk_39 = 0;
    debuffEffect->data.debuff->unk_3A = 40;
    debuffEffect->data.debuff->unk_3B = 205;
    debuffEffect->data.debuff->unk_3C = 32;
    debuffEffect->data.debuff->unk_3D = 242;
    return ApiStatus_DONE2;
}

ApiStatus func_8027143C(Evt* script, s32 isInitialCall) {
    fx_big_snowflakes(0, script->varTable[0], script->varTable[1], script->varTable[2]);
    return ApiStatus_DONE2;
}

ApiStatus func_80271484(Evt* script, s32 isInitialCall) {
    Actor* actor = (Actor*)script->varTable[3];
    f32 temp1 = actor->size.y;
    f32 temp2 = actor->size.x / 2;

    fx_misc_particles(0, script->varTable[0], script->varTable[1], script->varTable[2], temp1, temp2, 1.0f, 10, 30);
    fx_misc_particles(1, script->varTable[0], script->varTable[1], script->varTable[2], temp1, temp2, 1.0f, 10, 30);
    return ApiStatus_DONE2;
}

ApiStatus func_80271588(Evt* script, s32 isInitialCall) {
    s32 i;

    for (i = 0; i < 20; i++) {
        fx_floating_cloud_puff(0,
                               script->varTable[0] + rand_int(30) - 15,
                               script->varTable[1] + rand_int(20) - 15,
                               script->varTable[2] + 5,
                               1.0f,
                               25);
    }
    return ApiStatus_DONE2;
}

EvtScript DoSleepHit = {
    EVT_CALL(func_80271210)
    EVT_RETURN
    EVT_END
};

EvtScript DoDizzyHit = {
    EVT_CALL(func_80271258)
    EVT_RETURN
    EVT_END
};

EvtScript DoParalyzeHit = {
    EVT_CALL(func_802712A0)
    EVT_RETURN
    EVT_END
};

EvtScript DoPoisonHit = {
    EVT_CALL(func_80271328)
    EVT_RETURN
    EVT_END
};

EvtScript DoStopHit = {
    EVT_CALL(func_802713B0)
    EVT_RETURN
    EVT_END
};

EvtScript DoFreezeHit = {
    EVT_CALL(func_8027143C)
    EVT_WAIT(8)
    EVT_CALL(func_8027143C)
    EVT_WAIT(15)
    EVT_CALL(func_80271484)
    EVT_RETURN
    EVT_END
};

EvtScript DoShrinkHit = {
    EVT_CALL(func_80271588)
    EVT_RETURN
    EVT_END
};

void dispatch_damage_event_player_1(s32 damageAmount, s32 event);

void dispatch_event_player(s32 eventType) {
    Actor* player = gBattleStatus.playerActor;
    Evt* oldOnHitScript;
    s32 oldOnHitID;
    Evt* eventScript;

    player->lastEventType = eventType;

    oldOnHitScript = player->onHitScript;
    oldOnHitID = player->onHitID;

    eventScript = start_script(&HandleEvent_Player, EVT_PRIORITY_A, EVT_FLAG_20);
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
    Evt* oldOnHitScript;
    s32 oldOnHitID;
    Evt* eventScript;

    player->lastEventType = eventType;

    oldOnHitScript = player->onHitScript;
    oldOnHitID = player->onHitID;

    eventScript = start_script(&HandleEvent_Player, EVT_PRIORITY_A, EVT_FLAG_20);
    player->onHitScript = eventScript;
    player->onHitID = eventScript->id;
    eventScript->owner1.actor = NULL;

    if (oldOnHitScript != NULL) {
        kill_script_by_ID(oldOnHitID);
    }
}

s32 calc_player_test_enemy(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 currentTargetID = battleStatus->currentTargetID;
    s32 targetPart = battleStatus->currentTargetPart;
    ActorState* state = &player->state;
    Actor* target;
    ActorPart* part;

    battleStatus->currentTargetID2 = battleStatus->currentTargetID;
    battleStatus->currentTargetPart2 = battleStatus->currentTargetPart;

    target = get_actor(currentTargetID);
    if (target == NULL) {
        return HIT_RESULT_HIT;
    }

    part = get_actor_part(target, targetPart);
    ASSERT(part != NULL);

    if (part->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
        return HIT_RESULT_MISS;
    } else if (target->transparentStatus == STATUS_TRANSPARENT || ((part->eventFlags & ACTOR_EVENT_FLAG_800) &&
               !(battleStatus->currentAttackElement & DAMAGE_TYPE_QUAKE)))
    {
        return HIT_RESULT_MISS;
    } else if (target->stoneStatus == STATUS_STONE) {
        sfx_play_sound_at_position(SOUND_IMMUNE, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        return HIT_RESULT_IMMUNE;
    } else if ((battleStatus->currentAttackElement & DAMAGE_TYPE_JUMP) && (part->eventFlags & ACTOR_EVENT_FLAG_SPIKY_TOP) &&
               !player_team_is_ability_active(player, ABILITY_SPIKE_SHIELD))
    {
        sfx_play_sound_at_position(SOUND_108, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        return HIT_RESULT_LANDED_ON_SPIKE;
    } else if (!(battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_JUMP)) &&
               (part->eventFlags & ACTOR_EVENT_FLAG_SPIKY_FRONT) &&
               (!(battleStatus->currentAttackEventSuppression & 4) &&
               !player_team_is_ability_active(player, ABILITY_SPIKE_SHIELD)))
    {
        sfx_play_sound_at_position(SOUND_108, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        dispatch_damage_event_player_1(1, EVENT_SPIKE_CONTACT);
        dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
        return HIT_RESULT_TRIGGERED_EXPLODE;
    } else if (player->staticStatus != STATUS_STATIC && target->staticStatus == STATUS_STATIC) {
        return HIT_RESULT_HIT_STATIC;
    }

    return HIT_RESULT_HIT;
}

s32 calc_player_damage_enemy(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 currentTargetID = battleStatus->currentTargetID;
    s32 currentTargetPartID = battleStatus->currentTargetPart;
    ActorState* state;
    Evt* evt;
    Actor* target;
    ActorPart* targetPart;
    s32 retVal;
    s32 currentAttackDamage;
    s32 targetDefense;
    s32 dispatchEvent;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 isFireDamage;
    s32 isElectricDamage;
    s32 isWaterDamage;
    s32 isIceDamage;
    s32 tempBinary;
    s32 wasStatusInflicted;
    s32 attackFxType;

    sp20 = FALSE;
    isFireDamage = FALSE;
    isElectricDamage = FALSE;
    isIceDamage = FALSE;
    tempBinary = FALSE;
    sp1C = FALSE;
    wasStatusInflicted = FALSE;
    sp24 = FALSE;

    battleStatus->wasStatusInflicted = FALSE;
    battleStatus->lastAttackDamage = 0;
    battleStatus->attackerActorID = player->actorID;
    battleStatus->currentTargetID2 = battleStatus->currentTargetID;
    battleStatus->currentTargetPart2 = battleStatus->currentTargetPart;
    target = get_actor(currentTargetID);
    state = &player->state;

    if (target == NULL) {
        return 0;
    }

    targetPart = get_actor_part(target, currentTargetPartID);

    ASSERT(targetPart != NULL);

    target->lastDamageTaken = 0;

    if (gBattleStatus.flags1 & BS_FLAGS1_800) {
        retVal = 2;
        dispatchEvent = EVENT_UNKNOWN_TRIGGER;
    } else {
        if (player_team_is_ability_active(player, ABILITY_ICE_POWER)) {
            if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT)) {
                battleStatus->currentAttackElement |= DAMAGE_TYPE_ICE;
            }
        }

        if (targetPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY || (target->transparentStatus == STATUS_TRANSPARENT ||
                targetPart->eventFlags & ACTOR_EVENT_FLAG_800 && !(battleStatus->currentAttackElement & DAMAGE_TYPE_QUAKE))) {
            return 6;
        }

        if (target->stoneStatus == STATUS_STONE) {
            sfx_play_sound_at_position(SOUND_IMMUNE, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            func_8024EFE0(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, 1);
            show_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 0);
            return (gBattleStatus.flags1 & (BS_FLAGS1_200 | BS_FLAGS1_40)) ? 1 : 0;
        }

        if (targetPart->partFlags3 & battleStatus->currentAttackElement) {
            sp1C = TRUE;
        }

        if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_JUMP) || !(targetPart->eventFlags & ACTOR_EVENT_FLAG_SPIKY_TOP) ||
            player_team_is_ability_active(player, ABILITY_SPIKE_SHIELD)) {
            if (!(battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_SMASH))) {
                if (targetPart->eventFlags & ACTOR_EVENT_FLAG_8000) {
                    sfx_play_sound_at_position(SOUND_HIT_PLAYER_FIRE, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    dispatch_damage_event_player_1(1, EVENT_BURN_CONTACT);
                    dispatch_event_actor(target, EVENT_EXPLODE_TRIGGER);
                    return -1;
                }

                if (targetPart->eventFlags & ACTOR_EVENT_FLAG_FIREY && !(battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_10) &&
                    !(player_team_is_ability_active(player, ABILITY_FIRE_SHIELD)) && !(player_team_is_ability_active(player, ABILITY_ICE_POWER))) {
                    sfx_play_sound_at_position(SOUND_HIT_PLAYER_FIRE, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    dispatch_damage_event_player_1(1, EVENT_BURN_CONTACT);
                    dispatch_event_actor(target, EVENT_BURN_TAUNT);
                    return -1;
                }
            }

            if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE && battleStatus->currentAttackElement & DAMAGE_TYPE_FIRE &&
                targetPart->eventFlags & (ACTOR_EVENT_FLAG_400 | ACTOR_EVENT_FLAG_EXPLOSIVE)) {
                sfx_play_sound_at_position(SOUND_HIT_PLAYER_FIRE, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                dispatch_event_actor(target, EVENT_EXPLODE_TRIGGER);
                return (gBattleStatus.flags1 & (BS_FLAGS1_200 | BS_FLAGS1_40)) ? 1 : 0;
            }

            if (!(battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_SMASH)) &&
                targetPart->eventFlags & ACTOR_EVENT_FLAG_200000 &&
                !(battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_80) && !(player_team_is_ability_active(player, ABILITY_SPIKE_SHIELD))) {
                sfx_play_sound_at_position(SOUND_108, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                dispatch_damage_event_player_1(1, EVENT_SPIKE_CONTACT);
                dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
                return -1;
            }
        } else {
            sfx_play_sound_at_position(SOUND_108, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_damage_event_player_1(1, EVENT_SPIKE_CONTACT);
            dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
            return -1;
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_FIRE) {
            fx_ring_blast(0, state->goalPos.x, state->goalPos.y, state->goalPos.z * 5.0f, 1.0f, 24);
            isFireDamage = TRUE;
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_ELECTRIC) {
            func_80251474(target);
            isElectricDamage = TRUE;
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_WATER) {
            fx_water_splash(0, state->goalPos.x, state->goalPos.y, state->goalPos.z + 5.0f, 1.0f, 24);
            isWaterDamage = TRUE;
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_ICE) {
            fx_big_snowflakes(0, state->goalPos.x, state->goalPos.y, state->goalPos.z + 5.0f);
            isIceDamage = TRUE;
        }

        attackFxType = player_team_is_ability_active(player, ABILITY_ATTACK_FX);

        if (attackFxType) {
            fx_breaking_junk(0, state->goalPos.x, state->goalPos.y, state->goalPos.z + 5.0f, 1.0f, 30);

            switch (attackFxType) {
                case 1:
                    sfx_play_sound_at_position(SOUND_372, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    break;
                case 2:
                    sfx_play_sound_at_position(SOUND_F1, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    break;
                case 3:
                    sfx_play_sound_at_position(SOUND_DC, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    break;
                case 4:
                    sfx_play_sound_at_position(SOUND_2072, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    break;
                case 5:
                    sfx_play_sound_at_position(SOUND_2073, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    break;
                case 6:
                    sfx_play_sound_at_position(SOUND_205B, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    break;
            }
        }

        if (!is_ability_active(ABILITY_ZAP_TAP)) {
            if (player->staticStatus != STATUS_STATIC && (target->staticStatus == STATUS_STATIC ||
                    targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED) &&
                !(battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_ELECTRIC)) &&
                !(battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_8)) {
                gBattleStatus.flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;
                sp20 = TRUE;
            }
        }

        if (targetPart->eventFlags & (ACTOR_EVENT_FLAG_80000 | ACTOR_EVENT_FLAG_ENCHANTED)) {
            battleStatus->currentAttackElement &= ~DAMAGE_TYPE_IGNORE_DEFENSE;
        }

        targetDefense = get_defense(target, targetPart->defenseTable, battleStatus->currentAttackElement);

        if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_IGNORE_DEFENSE)) {
            targetDefense += target->defenseBoost;
        }

        if (targetPart->eventFlags & ACTOR_EVENT_FLAG_2000) {
            targetDefense += 127;
        }

        currentAttackDamage = battleStatus->currentAttackDamage;
        currentAttackDamage += count_power_plus(battleStatus->currentAttackElement);

        if (battleStatus->merleeAttackBoost > 0 && (gBattleStatus.flags1 & BS_FLAGS1_10 || battleStatus->currentAttackElement & DAMAGE_TYPE_JUMP)) {
            currentAttackDamage += battleStatus->merleeAttackBoost;
        }

        if (battleStatus->jumpCharge && battleStatus->currentAttackElement & DAMAGE_TYPE_JUMP) {
            currentAttackDamage += battleStatus->jumpCharge;
            gBattleStatus.flags1 &= ~BS_FLAGS1_20000000;
        }

        if (battleStatus->hammerCharge && battleStatus->currentAttackElement & (DAMAGE_TYPE_QUAKE_HAMMER | DAMAGE_TYPE_THROW | DAMAGE_TYPE_SMASH)) {
            currentAttackDamage += battleStatus->hammerCharge;
            gBattleStatus.flags1 &= ~BS_FLAGS1_10000000;
        }

        if (battleStatus->unk_98 != 0) {
            currentAttackDamage += 2;
        }

        if (player_team_is_ability_active(player, ABILITY_BERSERKER)) {
            currentAttackDamage += 2;
        }

        if (player_team_is_ability_active(player, ABILITY_P_UP_D_DOWN)) {
            currentAttackDamage++;
        }

        if (player_team_is_ability_active(player, ABILITY_P_DOWN_D_UP)) {
            currentAttackDamage--;
        }

        if (battleStatus->turboChargeTurnsLeft != 0) {
            currentAttackDamage++;
        }

        currentAttackDamage += player->attackBoost;

        if (player_team_is_ability_active(player, ABILITY_HP_DRAIN)) {
            battleStatus->hpDrainCount++;
            currentAttackDamage--;

            if (currentAttackDamage < 0) {
                battleStatus->hpDrainCount += currentAttackDamage;
            }

            gBattleStatus.flags2 |= BS_FLAGS2_4000000;

            if (battleStatus->hpDrainCount > 5) {
                battleStatus->hpDrainCount = 5;
            }
        }

        if (player_team_is_ability_active(player, ABILITY_MEGA_HP_DRAIN)) {
            battleStatus->hpDrainCount += 2;
            currentAttackDamage -= 2;

            if (currentAttackDamage < 0) {
                battleStatus->hpDrainCount += currentAttackDamage;
            }

            gBattleStatus.flags2 |= BS_FLAGS2_4000000;

            if (battleStatus->hpDrainCount > 5) {
                battleStatus->hpDrainCount = 5;
            }
        }

        if (gBattleStatus.flags2 & BS_FLAGS2_8000000 && (gBattleStatus.flags1 & BS_FLAGS1_10 ||
                battleStatus->currentAttackElement & DAMAGE_TYPE_JUMP)) {
            if (battleStatus->rushFlags & RUSH_FLAG_POWER) {
                currentAttackDamage += 2;
            }

            if (battleStatus->rushFlags & RUSH_FLAG_MEGA) {
                currentAttackDamage += 4;
            }
            fx_radial_shimmer(9, state->goalPos.x, state->goalPos.y, state->goalPos.z, 0.5f, 20);
        }

        if (!(gBattleStatus.flags2 & BS_FLAGS2_1000000) && player_team_is_ability_active(player, ABILITY_ALL_OR_NOTHING)) {
            currentAttackDamage++;

            if (!(gBattleStatus.flags1 & (BS_FLAGS1_200 | BS_FLAGS1_40))) {
                sp24 = TRUE;
                currentAttackDamage = 0;
                targetDefense = 0;
                gBattleStatus.flags1 &= ~BS_FLAGS1_40;
                gBattleStatus.flags1 &= ~BS_FLAGS1_200;
                gBattleStatus.flags1 &= ~BS_FLAGS1_10;
                gBattleStatus.flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;
            }
        }

        if (player->debuff == STATUS_SHRINK) {
            if (currentAttackDamage > 0) {
                currentAttackDamage /= 2;

                if (currentAttackDamage == 0) {
                    currentAttackDamage = 1;
                }
            }
        }

        if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE && battleStatus->currentAttackElement & DAMAGE_TYPE_BLAST &&
            targetPart->eventFlags & ACTOR_EVENT_FLAG_EXPLOSIVE) {
            targetDefense = 0;
            currentAttackDamage = target->currentHP;
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS) {
            targetDefense = 0;
            currentAttackDamage = 0;
        }

        if (currentAttackDamage > 99) {
            currentAttackDamage = 99;
        }

        if (currentAttackDamage < 0) {
            targetDefense = 0;
        }

        target->hpChangeCounter = 0;
        currentAttackDamage -= targetDefense;

        if (currentAttackDamage < 0) {
            currentAttackDamage = 0;
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_POWER_BOUNCE && currentAttackDamage > 0) {
            currentAttackDamage += battleStatus->powerBounceCounter;

            if (currentAttackDamage < 1) {
                currentAttackDamage = 1;
            }
        }

        battleStatus->lastAttackDamage = 0;

        if (currentAttackDamage < 1) {
            target->hpChangeCounter = 0;
            retVal = 2;

            if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS)) {
                dispatchEvent = EVENT_UNKNOWN_TRIGGER;
                sfx_play_sound_at_position(SOUND_IMMUNE, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            } else {
                dispatchEvent = (target->currentHP <= 0) ? EVENT_DEATH : EVENT_UNKNOWN_TRIGGER;
            }

            battleStatus->lastAttackDamage = 0;
        } else {
            target->damageCounter += currentAttackDamage;
            dispatchEvent = EVENT_HIT_COMBO;
            retVal = 0;
            target->hpChangeCounter -= currentAttackDamage;

            if (!(targetPart->flags & ACTOR_PART_FLAG_2000) && !(gBattleStatus.flags1 & BS_FLAGS1_2000000) && !sp1C &&
                !(targetPart->targetFlags & ACTOR_PART_FLAG_4)) {
                target->currentHP -= currentAttackDamage;

                if (target->currentHP <= 0) {
                    target->currentHP = 0;
                    dispatchEvent = EVENT_DEATH;
                }
            }

            battleStatus->lastAttackDamage += currentAttackDamage;
            target->lastDamageTaken = battleStatus->lastAttackDamage;
            target->hpChangeCounter = 0;
        }

        if (targetPart->flags & ACTOR_PART_FLAG_2000) {
            if (is_ability_active(ABILITY_ZAP_TAP) || player->staticStatus == STATUS_STATIC || (target->staticStatus != STATUS_STATIC &&
                    !(targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED)) || battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT ||
                battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_8 || battleStatus->currentAttackElement & DAMAGE_TYPE_ELECTRIC) {
                dispatchEvent = (!(gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE)) ? EVENT_UNKNOWN_TRIGGER : EVENT_IMMUNE;
                sfx_play_sound_at_position(SOUND_IMMUNE, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                dispatch_event_actor(target, dispatchEvent);
                func_8024EFE0(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, 3);
                return (gBattleStatus.flags1 & (BS_FLAGS1_200 | BS_FLAGS1_40)) ? 1 : 0;
            } else {
                sfx_play_sound_at_position(SOUND_HIT_PLAYER_SHOCK, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                func_80251474(player);
                dispatch_damage_event_player_1(1, EVENT_SHOCK_HIT);
                return -1;
            }
        }

        if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
            if (battleStatus->currentAttackElement & DAMAGE_TYPE_FEAR &&
                rand_int(99) < (target->actorBlueprint->escapeChance * battleStatus->statusChance) / 100 &&
                !(target->debuff == STATUS_FEAR ||
                  target->debuff == STATUS_DIZZY ||
                  target->debuff == STATUS_PARALYZE ||
                  target->debuff == STATUS_SLEEP ||
                  target->debuff == STATUS_FROZEN ||
                  target->debuff == STATUS_STOP) && !(target->flags & ACTOR_FLAG_400)) {
                dispatch_event_actor(target, EVENT_SCARE_AWAY);
                return (gBattleStatus.flags1 & (BS_FLAGS1_200 | BS_FLAGS1_40)) ? 1 : 0;
            }
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (dispatchEvent == EVENT_HIT_COMBO) {
            dispatchEvent = EVENT_HIT;
        }

        if (dispatchEvent == EVENT_UNKNOWN_TRIGGER) {
            dispatchEvent = EVENT_IMMUNE;
        }

        if (target->currentHP <= 0) {
            if (dispatchEvent == EVENT_IMMUNE) {
                dispatchEvent = EVENT_DEATH;
            }
        }
    } else if (dispatchEvent == EVENT_DEATH) {
        dispatchEvent = EVENT_HIT_COMBO;
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE ||
        (func_80266E14(targetPart), gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE)) {    // TODO remove func_80266E14 from conditional
        if (battleStatus->currentAttackElement & DAMAGE_TYPE_SPIN_SMASH) {
            PlayerData* playerData = &gPlayerData;

            if (target->actorBlueprint->spinSmashReq != 255 && playerData->hammerLevel + 1 >= target->actorBlueprint->spinSmashReq &&
                battleStatus->lastAttackDamage > 0 && gBattleStatus.flags1 & BS_FLAGS1_40) {
                if (dispatchEvent == EVENT_HIT_COMBO) {
                    dispatchEvent = EVENT_SPIN_SMASH_HIT;
                }

                if (dispatchEvent == EVENT_HIT) {
                    dispatchEvent = EVENT_SPIN_SMASH_HIT;
                }

                if (dispatchEvent == EVENT_UNKNOWN_TRIGGER) {
                    dispatchEvent = EVENT_SPIN_SMASH_HIT;
                }

                if (dispatchEvent == EVENT_IMMUNE) {
                    dispatchEvent = EVENT_SPIN_SMASH_HIT;
                }

                if (dispatchEvent == EVENT_DEATH) {
                    dispatchEvent = EVENT_SPIN_SMASH_DEATH;
                }
            }
        }

        if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
            if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT) && targetPart->eventFlags & ACTOR_EVENT_FLAG_POWER_BOUNCE) {
                if (dispatchEvent == EVENT_HIT_COMBO) {
                    dispatchEvent = EVENT_POWER_BOUNCE_HIT;
                }

                if (dispatchEvent == EVENT_HIT) {
                    dispatchEvent = EVENT_POWER_BOUNCE_HIT;
                }

                if (dispatchEvent == EVENT_UNKNOWN_TRIGGER) {
                    dispatchEvent = EVENT_POWER_BOUNCE_HIT;
                }

                if (dispatchEvent == EVENT_IMMUNE) {
                    dispatchEvent = EVENT_POWER_BOUNCE_HIT;
                }

                if (dispatchEvent == EVENT_DEATH) {
                    dispatchEvent = EVENT_POWER_BOUNCE_DEATH;
                }
            }

            if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
                if (battleStatus->currentAttackElement & (DAMAGE_TYPE_POW | DAMAGE_TYPE_JUMP) && targetPart->eventFlags & ACTOR_EVENT_FLAG_GROUNDABLE) {
                    if (dispatchEvent == EVENT_HIT) {
                        dispatchEvent = EVENT_FALL_TRIGGER;
                    }

                    if (dispatchEvent == EVENT_IMMUNE) {
                        dispatchEvent = EVENT_FALL_TRIGGER;
                    }

                    tempBinary = TRUE;
                }

                if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
                    if (battleStatus->currentAttackElement & (DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_POW | DAMAGE_TYPE_JUMP) &&
                        targetPart->eventFlags & ACTOR_EVENT_FLAG_FLIPABLE) {
                        if (dispatchEvent == EVENT_HIT) {
                            dispatchEvent = EVENT_FLIP_TRIGGER;
                        }

                        if (dispatchEvent == EVENT_IMMUNE) {
                            dispatchEvent = EVENT_FLIP_TRIGGER;
                        }

                        if (!(target->flags & ACTOR_FLAG_400)) {
                            tempBinary = TRUE;
                        }
                    }
                }
            }
        }
    }

    if (!(gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) &&
        battleStatus->currentAttackElement & (DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_POW | DAMAGE_TYPE_JUMP) &&
        targetPart->eventFlags & ACTOR_EVENT_FLAG_FLIPABLE) {
        if (dispatchEvent == EVENT_HIT_COMBO) {
            dispatchEvent = EVENT_FLIP_TRIGGER;
        }

        if (dispatchEvent == EVENT_UNKNOWN_TRIGGER) {
            dispatchEvent = EVENT_FLIP_TRIGGER;
        }

        if (!(target->flags & ACTOR_FLAG_400)) {
            tempBinary = TRUE;
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (battleStatus->currentAttackElement & DAMAGE_TYPE_SHELL_CRACK && targetPart->eventFlags & ACTOR_EVENT_FLAG_FLIPABLE) {
            if (dispatchEvent == EVENT_HIT) {
                dispatchEvent = EVENT_SHELL_CRACK_HIT;
            }

            if (dispatchEvent == EVENT_IMMUNE) {
                dispatchEvent = EVENT_SHELL_CRACK_HIT;
            }
            tempBinary = TRUE;
        }

        if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
            if (battleStatus->currentAttackElement & (DAMAGE_TYPE_BLAST | DAMAGE_TYPE_FIRE)) {
                if (dispatchEvent == EVENT_HIT) {
                    dispatchEvent = EVENT_BURN_HIT;
                }

                if (dispatchEvent == EVENT_DEATH) {
                    dispatchEvent = EVENT_BURN_DEATH;
                }

                isFireDamage = TRUE;
            }

            do {        // TODO remove this do while
                if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE && battleStatus->lastAttackDamage >= 0 && dispatchEvent != EVENT_DEATH &&
                    dispatchEvent != EVENT_SPIN_SMASH_DEATH && dispatchEvent != EVENT_EXPLODE_TRIGGER) {
                    if (!(targetPart->targetFlags & ACTOR_PART_FLAG_4)) {

                        #define INFLICT_STATUS(STATUS_TYPE) \
                            if ((battleStatus->currentAttackStatus & STATUS_FLAG_##STATUS_TYPE) && \
                                try_inflict_status(target, STATUS_##STATUS_TYPE, STATUS_##STATUS_TYPE##_TURN_MOD)) { \
                                tempBinary = TRUE; \
                                wasStatusInflicted = TRUE; \
                            } \

                        INFLICT_STATUS(SHRINK);
                        INFLICT_STATUS(POISON);
                        INFLICT_STATUS(STONE);
                        INFLICT_STATUS(SLEEP);
                        INFLICT_STATUS(STOP);
                        INFLICT_STATUS(STATIC);
                        INFLICT_STATUS(FEAR);
                        INFLICT_STATUS(PARALYZE);
                        INFLICT_STATUS(DIZZY);

                        #undef INFLICT_STATUS

                        if (wasStatusInflicted) {
                            if (dispatchEvent == EVENT_UNKNOWN_TRIGGER) {
                                dispatchEvent = EVENT_HIT_COMBO;
                            }

                            if (dispatchEvent == EVENT_IMMUNE) {
                                dispatchEvent = EVENT_HIT;
                            }
                        }
                    }
                }
            } while (0);
        }
    }

    battleStatus->wasStatusInflicted = wasStatusInflicted;
    dispatch_event_actor(target, dispatchEvent);

    if (!(target->flags & ACTOR_FLAG_NO_DMG_POPUP)) {
        if (battleStatus->lastAttackDamage == 0) {
            if (!tempBinary) {
                if (!wasStatusInflicted) {
                    func_8024EFE0(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, 3);
                }
            }
        } else if (!sp1C) {
            if (battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS | DAMAGE_TYPE_SMASH)) {
                show_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 0);
            } else {
                func_802664DC(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 0);
            }

            if (!(targetPart->targetFlags & 4)) {
                func_802666E4(target, state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage);
            }
        }
    }

    if (tempBinary && gBattleStatus.flags1 & BS_FLAGS1_40 || gBattleStatus.flags1 & BS_FLAGS1_40) {
        if (!(gBattleStatus.flags1 & BS_FLAGS1_80)) {
            if (player->actorTypeData1[5]) {
                sfx_play_sound_at_position(player->actorTypeData1[5], 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            }

            if (battleStatus->lastAttackDamage > 0 && (sfx_play_sound(SOUND_231), battleStatus->lastAttackDamage > 0) ||    // TODO remove sfx_play_sound from conditional
                battleStatus->currentAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS && tempBinary) {
                if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_MULTI_BOUNCE)) {
                    func_802667F0(0, target, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                } else {
                    func_802667F0(5, target, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                }
            }
        }
    }


    if (sp24) {
        func_802667F0(1, target, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        func_80266970(target);
    }

    if (battleStatus->lastAttackDamage > 0 || tempBinary) {
        if (!sp1C) {
            func_80267018(target, 1);

            if (isFireDamage) {
                sfx_play_sound_at_position(SOUND_HIT_FIRE, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            } else if (isElectricDamage) {
                sfx_play_sound_at_position(SOUND_HIT_SHOCK, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            } else if (isIceDamage) {
                sfx_play_sound_at_position(SOUND_HIT_ICE, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            } else {
                sfx_play_sound_at_position(SOUND_HIT_NORMAL, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            }
        }
    }

    if (battleStatus->lastAttackDamage <= 0 && !tempBinary && !sp20 || targetPart->flags & ACTOR_PART_FLAG_2000) {
        sfx_play_sound_at_position(SOUND_IMMUNE, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_SLEEP && wasStatusInflicted) {
        evt = start_script((EvtScript*) DoSleepHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_SLEEP, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_DIZZY && wasStatusInflicted) {
        evt = start_script((EvtScript*) DoDizzyHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_PARALYZE && wasStatusInflicted) {
        evt = start_script((EvtScript*) DoParalyzeHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_POISON && wasStatusInflicted) {
        evt = start_script((EvtScript*) DoPoisonHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_STOP && wasStatusInflicted) {
        evt = start_script((EvtScript*) DoStopHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_FROZEN && wasStatusInflicted) {
        evt = start_script((EvtScript*) DoFreezeHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        evt->varTablePtr[3] = target;
        sfx_play_sound_at_position(SOUND_HIT_PLAYER_ICE, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_SHRINK && wasStatusInflicted) {
        evt = start_script((EvtScript*) DoShrinkHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        evt->varTablePtr[3] = target;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackElement & DAMAGE_TYPE_SMASH && target->actorType == ACTOR_TYPE_GOOMNUT_TREE) {
        sfx_play_sound_at_position(SOUND_SMASH_GOOMNUT_TREE, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    func_80266ADC(target);

    if (gBattleStatus.flags1 & (BS_FLAGS1_200 | BS_FLAGS1_40)) {
        if (retVal == 0) {
            retVal = 1;
        }
        if (retVal == 2) {
            retVal = 3;
        }
    }

    if (!is_ability_active(ABILITY_ZAP_TAP)) {
        if (player->staticStatus != STATUS_STATIC && (target->staticStatus == STATUS_STATIC ||
                targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED) &&
            !(battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_ELECTRIC)) &&
            !(battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_8)) {
            sfx_play_sound_at_position(SOUND_HIT_PLAYER_SHOCK, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            func_80251474(player);
            dispatch_damage_event_player_1(1, EVENT_SHOCK_HIT);
            return -1;
        }
    }

    return retVal;
}

s32 dispatch_damage_event_player(s32 damageAmount, s32 event, s32 arg2) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* player = battleStatus->playerActor;
    ActorState* state = &player->state;
    s32 oldHPChangeCounter;
    s32 flags;
    s32 dispatchEvent;
    s32 oldPlayerHP;
    s32 temp;

    battleStatus->currentAttackDamage = damageAmount;

    temp = (s16)damageAmount; // usage of temp here required to match
    player->hpChangeCounter += temp;

    temp = player->hpChangeCounter;
    player->currentHP = playerData->curHP;
    player->damageCounter += temp;
    player->hpChangeCounter -= temp;
    battleStatus->lastAttackDamage = 0;
    player->currentHP -= temp;
    battleStatus->damageTaken += temp;

    oldPlayerHP = player->currentHP;

    dispatchEvent = event;
    if (player->currentHP <= 0) {
        battleStatus->lastAttackDamage += oldPlayerHP;
        player->currentHP = 0;
        dispatchEvent = EVENT_DEATH;
    }
    battleStatus->lastAttackDamage += temp;
    playerData->curHP = player->currentHP;

    if (dispatchEvent == EVENT_HIT_COMBO) {
        dispatchEvent = EVENT_HIT;
    }
    if (dispatchEvent == EVENT_UNKNOWN_TRIGGER) {
        dispatchEvent = EVENT_IMMUNE;
    }

    if (dispatchEvent == EVENT_DEATH) {
        if (event == EVENT_SPIKE_CONTACT) {
            dispatchEvent = EVENT_SPIKE_DEATH;
        }
        if (event == EVENT_BURN_CONTACT) {
            dispatchEvent = EVENT_BURN_DEATH;
        }
        if (event == EVENT_SHOCK_HIT) {
            dispatchEvent = EVENT_SHOCK_DEATH;
        }
    }

    if (!arg2) {
        set_goal_pos_to_part(state, ACTOR_PLAYER, 0);
        sfx_play_sound_at_position(SOUND_HIT_NORMAL, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    show_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 1);
    func_802666E4(player, state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage);

    if (battleStatus->lastAttackDamage > 0) {
        func_80267018(player, 1);
    }

    flags = (gBattleStatus.flags1 & (BS_FLAGS1_200 | BS_FLAGS1_40)) != 0;
    dispatch_event_player(dispatchEvent);
    return flags;
}

s32 dispatch_damage_event_player_0(s32 damageAmount, s32 event) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->currentAttackElement = ELEMENT_END;
    battleStatus->unk_19A = 0;
    return dispatch_damage_event_player(damageAmount, event, FALSE);
}

void dispatch_damage_event_player_1(s32 damageAmount, s32 event) {
    dispatch_damage_event_player(damageAmount, event, TRUE);
}

ApiStatus GetMenuSelection(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 outVar1 = *args++;
    s32 outVar2 = *args++;
    s32 outVar3 = *args++;

    evt_set_variable(script, outVar1, battleStatus->moveCategory);
    evt_set_variable(script, outVar2, battleStatus->selectedItemID);
    evt_set_variable(script, outVar3, battleStatus->selectedMoveID);

    return ApiStatus_DONE2;
}

// float regz
#ifdef NON_MATCHING
ApiStatus func_80273444(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* player = battleStatus->playerActor;
    ActorState* playerState = &player->state;
    f32 playerVel;
    f32 currentX;
    f32 currentY;
    f32 currentZ;
    f32 goalX;
    f32 goalY;
    f32 goalZ;
    f32 var_f8;
    f64 temp_f20_2;
    f32 sub;

    if (isInitialCall) {
        script->functionTemp[0] = FALSE;
    }

    if (!script->functionTemp[0]) {
        player->state.moveTime = evt_get_variable(script, *args++);
        player->state.moveArcAmplitude = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);

        goalX = player->state.goalPos.x;
        goalY = player->state.goalPos.y;
        goalZ = player->state.goalPos.z;
        player->state.currentPos.x = player->currentPos.x;
        player->state.currentPos.y = player->currentPos.y;
        player->state.currentPos.z = player->currentPos.z;
        currentX = player->currentPos.x;
        currentY = player->currentPos.y;
        currentZ = player->currentPos.z;

        player->state.angle = atan2(currentX, currentZ, goalX, goalZ);
        player->state.distance = dist2D(currentX, currentZ, goalX, goalZ);

        sub = goalY - currentY;

        if (player->state.moveTime == 0) {
            player->state.moveTime = player->state.distance / player->state.speed;
            var_f8 = player->state.distance - (player->state.moveTime * player->state.speed);
        } else {
            player->state.speed = player->state.distance / player->state.moveTime;
            var_f8 = player->state.distance - (player->state.moveTime * player->state.speed);
        }

        playerState->speed += var_f8 / playerState->moveTime;
        playerState->velocity = (playerState->acceleration * playerState->moveTime * 0.5f) + (sub / playerState->moveTime);
        set_animation(0, 0, playerState->animJumpRise);
        playerState->unk_24 = 90.0f;
        playerState->unk_28 = 180 / playerState->moveTime;
        playerState->unk_2C = playerState->goalPos.y;
        if (script->functionTemp[1] != 2) {
            sfx_play_sound_at_position(0x160, 0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
        }
        script->functionTemp[0] = TRUE;
    }

    if (playerState->velocity < 0.0f) {
        set_animation(0, 0, playerState->animJumpFall);
    }

    playerVel = playerState->velocity;
    switch (playerState->moveArcAmplitude) {
        case 0:
            break;
        case 1:
            if (playerState->currentPos.y - playerState->unk_2C > 45.0f) {
                playerVel *= 0.25f;
            }
            break;
        case 2:
            if (playerState->currentPos.y - playerState->unk_2C > 54.9) {
                playerVel *= 0.25f;
            }
            break;
    }

    playerState->currentPos.y += playerVel;
    playerState->velocity -= playerState->acceleration;
    temp_f20_2 = playerState->speed;
    add_xz_vec3f(&playerState->currentPos, temp_f20_2 + sin_rad(DEG_TO_RAD(playerState->unk_24), playerState->angle);
    playerState->unk_24 += playerState->unk_28;
    playerState->unk_24 = clamp_angle(playerState->unk_24);
    player->currentPos.x = playerState->currentPos.x;
    player->currentPos.y = playerState->currentPos.y;
    player->currentPos.z = playerState->currentPos.z;
    playerState->moveTime--;

    if (playerState->moveTime >= 0) {
        return ApiStatus_BLOCK;
    }

    player->currentPos.y = playerState->goalPos.y;
    if (script->functionTemp[1] != 1) {
        play_movement_dust_effects(2, player->currentPos.x, player->currentPos.y, player->currentPos.z, player->yaw);
    }
    if (script->functionTemp[1] != 2) {
        sfx_play_sound_at_position(SOUND_SOFT_LAND, 0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
    }

    return ApiStatus_DONE1;
}
#else
INCLUDE_ASM(s32, "19FAF0", func_80273444);
#endif

//float bs
#ifdef NON_MATCHING
s32 PlayerFallToGoal(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* player = gBattleStatus.playerActor;
    ActorState* state = &player->state;
    f32 temp_f0_2;
    f32 temp_f20;
    f32 goalX;
    f32 goalY;
    f32 goalZ;
    f32 currentX, currentY, currentZ;
    f32 new_var2;
    f32 temp;
    f32 xTemp, yTemp, zTemp;
    f32 goalPosX, goalPosZ;

    if (isInitialCall) {
        script->functionTemp[0] = FALSE;
    }

    if (!script->functionTemp[0]) {
        s32 moveTime = evt_get_variable(script, *args++);

        state->currentPos.x = player->currentPos.x;
        state->currentPos.z = player->currentPos.z;
        currentX = state->currentPos.x;
        state->currentPos.y = player->currentPos.y;
        currentY = state->currentPos.y;
        temp = state->currentPos.z;

        goalX = state->goalPos.x;
        goalY = state->goalPos.y;
        goalZ = state->goalPos.z;

        state->moveTime = moveTime;

        state->angle = atan2(currentX, temp, goalX, goalZ);
        state->distance = dist2D(currentX, temp, goalX, goalZ);

        temp = goalY - currentY;

        if (state->moveTime == 0) {
            state->moveTime = state->distance / state->speed;
        } else {
            state->speed = state->distance / state->moveTime;
        }

        state->velocity = 0.0f;
        state->acceleration = (((temp / state->moveTime) - state->velocity) / (-state->moveTime * 0.5));
        set_animation(ACTOR_PLAYER, 0, state->animJumpRise);
        script->functionTemp[0] = TRUE;
    }

    if (state->velocity < 0.0f) {
        set_animation(0, 0, state->animJumpFall);
    }

    state->currentPos.y += state->velocity;
    state->velocity -= state->acceleration;
    add_xz_vec3f(&state->currentPos, state->speed, state->angle);

    player->currentPos.x = state->currentPos.x;
    player->currentPos.y = state->currentPos.y;
    player->currentPos.z = state->currentPos.z;
    state->moveTime--;

    if (state->moveTime < 0) {
        player->currentPos.x = state->goalPos.x;
        player->currentPos.y = state->goalPos.y;
        player->currentPos.z = state->goalPos.z;
        play_movement_dust_effects(2, player->currentPos.x, player->currentPos.y, player->currentPos.z, player->yaw);
        sfx_play_sound_at_position(SOUND_SOFT_LAND, 0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "19FAF0", PlayerFallToGoal, Evt* script, s32 isInitialCall);
#endif

ApiStatus PlayerLandJump(Evt *script, s32 isInitialCall) {
    Actor* player = gBattleStatus.playerActor;
    ActorState* walkMovement = &player->state;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        walkMovement->currentPos.x = player->currentPos.x;
        walkMovement->currentPos.y = player->currentPos.y;
        walkMovement->currentPos.z = player->currentPos.z;
        script->functionTemp[0] = 1;
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

ApiStatus PlayerRunToGoal(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* player = battleStatus->playerActor;
    ActorState* playerState = &player->state;
    f32 currentX, currentZ, goalX, goalZ;

    if (isInitialCall) {
        script->functionTemp[0] = FALSE;
    }

    if (!script->functionTemp[0]) {
        player->state.moveTime = evt_get_variable(script, *args++);
        player->state.currentPos.x = player->currentPos.x;
        player->state.currentPos.y = player->currentPos.y;
        player->state.currentPos.z = player->currentPos.z;

        goalX = player->state.goalPos.x;
        goalZ = player->state.goalPos.z;
        currentX = player->state.currentPos.x;
        currentZ = player->state.currentPos.z;

        player->state.angle = atan2(currentX, currentZ, goalX, goalZ);
        player->state.distance = dist2D(currentX, currentZ, goalX, goalZ);
        if (player->state.moveTime == 0) {
            player->state.moveTime = player->state.distance / player->state.speed;
            if (player->state.moveTime == 0) {
                player->state.moveTime = 1;
            }
            player->state.speed += (player->state.distance - (player->state.moveTime * player->state.speed)) / player->state.moveTime;
        } else {
            player->state.speed = player->state.distance / player->state.moveTime;
        }
        playerState->distance = player->actorTypeData1b[0] + 1;
        script->functionTemp[0] = TRUE;
    }

    add_xz_vec3f(&playerState->currentPos, playerState->speed, playerState->angle);

    player->currentPos.x = playerState->currentPos.x;
    player->currentPos.y = playerState->currentPos.y;
    player->currentPos.z = playerState->currentPos.z;

    if (playerState->speed < 4.0f) {
        play_movement_dust_effects(0, player->currentPos.x, player->currentPos.y, player->currentPos.z, player->yaw);
    } else {
        play_movement_dust_effects(1, player->currentPos.x, player->currentPos.y, player->currentPos.z, player->yaw);
    }

    playerState->distance += playerState->speed;
    if (playerState->distance > player->actorTypeData1b[0]) {
        player->footStepCounter++;
        playerState->distance = 0.0f;
        if ((player->footStepCounter % 2) != 0) {
            sfx_play_sound_at_position(SOUND_STEP_NORMAL1, 0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
        } else {
            sfx_play_sound_at_position(SOUND_STEP_NORMAL2, 0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
        }
    }

    playerState->moveTime--;

    if (playerState->moveTime <= 0) {
        player->currentPos.x = playerState->goalPos.x;
        player->currentPos.z = playerState->goalPos.z;
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;;
}

ApiStatus CancelablePlayerRunToGoal(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* player = battleStatus->playerActor;
    ActorState* playerState = &player->state;
    f32 currentX, currentZ, goalX, goalZ;

    if (isInitialCall) {
        script->functionTemp[0] = FALSE;
    }

    if (!script->functionTemp[0]) {
        player->state.moveTime = evt_get_variable(script, *args++);
        script->functionTemp[1] = *args++;
        player->state.currentPos.x = player->currentPos.x;
        player->state.currentPos.y = player->currentPos.y;
        player->state.currentPos.z = player->currentPos.z;

        goalX = player->state.goalPos.x;
        goalZ = player->state.goalPos.z;
        currentX = player->state.currentPos.x;
        currentZ = player->state.currentPos.z;

        player->state.angle = atan2(currentX, currentZ, goalX, goalZ);
        player->state.distance = dist2D(currentX, currentZ, goalX, goalZ);
        if (player->state.moveTime == 0) {
            player->state.moveTime = player->state.distance / player->state.speed;
            player->state.speed += (player->state.distance - (player->state.moveTime * player->state.speed)) / player->state.moveTime;
        } else {
            player->state.speed = player->state.distance / player->state.moveTime;
        }
        playerState->distance = player->actorTypeData1b[0] + 1;

        if (playerState->moveTime == 0) {
            return ApiStatus_DONE2;
        }

        script->functionTemp[2] = FALSE;
        script->functionTemp[3] = 0;
        script->functionTemp[0] = TRUE;
    }

    add_xz_vec3f(&playerState->currentPos, playerState->speed, playerState->angle);

    player->currentPos.x = playerState->currentPos.x;
    player->currentPos.y = playerState->currentPos.y;
    player->currentPos.z = playerState->currentPos.z;

    if (playerState->speed < 4.0f) {
        play_movement_dust_effects(0, player->currentPos.x, player->currentPos.y, player->currentPos.z, player->yaw);
    } else {
        play_movement_dust_effects(1, player->currentPos.x, player->currentPos.y, player->currentPos.z, player->yaw);
    }

    playerState->distance += playerState->speed;
    if (playerState->distance > player->actorTypeData1b[0]) {
        player->footStepCounter++;
        playerState->distance = 0.0f;
        if ((player->footStepCounter % 2) != 0) {
            sfx_play_sound_at_position(SOUND_STEP_NORMAL1, 0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
        } else {
            sfx_play_sound_at_position(SOUND_STEP_NORMAL2, 0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
        }
    }

    if (script->functionTemp[3] > 12) {
        if (!script->functionTemp[2]) {
            if (!(battleStatus->currentButtonsDown & BUTTON_A)) {
                script->functionTemp[2] = TRUE;
            }
        }

        if (script->functionTemp[2]) {
            if (battleStatus->currentButtonsPressed & BUTTON_A) {
                evt_set_variable(script, script->functionTemp[1], 1);
                return ApiStatus_DONE2;
            }
        }
    }

    script->functionTemp[3]++;

    playerState->moveTime--;
    if (playerState->moveTime > 0) {
        return ApiStatus_BLOCK;
    }

    player->currentPos.x = playerState->goalPos.x;
    player->currentPos.z = playerState->goalPos.z;
    evt_set_variable(script, script->functionTemp[1], 0);
    return ApiStatus_DONE2;
}

ApiStatus GetPlayerHP(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gPlayerData.curHP);
    return ApiStatus_DONE2;
}

ApiStatus PlayerDamageEnemy(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 a0 = *args++;
    s32 flags;
    Actor* target;
    s32 temp_v0_2;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = *args++;
    battleStatus->currentAttackStatus = *args++;
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
    battleStatus->powerBounceCounter = 0;
    flags = *args++;

    if ((flags & (BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)) == (BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)) {
        gBattleStatus.flags1 |= BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (flags & BS_FLAGS1_10) {
        gBattleStatus.flags1 |= BS_FLAGS1_10;
        gBattleStatus.flags1 &= ~BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (flags & BS_FLAGS1_SP_EVT_ACTIVE) {
        gBattleStatus.flags1 &= ~BS_FLAGS1_10;
        gBattleStatus.flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_10;
        gBattleStatus.flags1 &= ~BS_FLAGS1_SP_EVT_ACTIVE;
    }

    if (flags & BS_FLAGS1_40) {
        gBattleStatus.flags1 |= BS_FLAGS1_40;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_40;
    }
    if (flags & BS_FLAGS1_200) {
        gBattleStatus.flags1 |= BS_FLAGS1_200;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_200;
    }
    if (flags & BS_FLAGS1_80) {
        gBattleStatus.flags1 |= BS_FLAGS1_80;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_80;
    }
    if (flags & BS_FLAGS1_800) {
        gBattleStatus.flags1 |= BS_FLAGS1_800;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_800;
    }

    target = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = target->targetActorID;
    battleStatus->currentTargetPart = target->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;
    if (battleStatus->statusChance == 0xFF) {
        battleStatus->statusChance = 0;
    }
    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;

    temp_v0_2 = calc_player_damage_enemy();
    if (temp_v0_2 < 0) {
        return ApiStatus_FINISH;
    }
    evt_set_variable(script, a0, temp_v0_2);

    if (!does_script_exist_by_ref(script)) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus PlayerPowerBounceEnemy(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 a0 = *args++;
    s32 flags;
    Actor* target;
    s32 temp_v0_2;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = *args++;
    battleStatus->currentAttackStatus = *args++;
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
    battleStatus->powerBounceCounter = evt_get_variable(script, *args++);
    flags = *args++;

    if ((flags & (BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)) == (BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)) {
        gBattleStatus.flags1 |= BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (flags & BS_FLAGS1_10) {
        gBattleStatus.flags1 |= BS_FLAGS1_10;
        gBattleStatus.flags1 &= ~BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (flags & BS_FLAGS1_SP_EVT_ACTIVE) {
        gBattleStatus.flags1 &= ~BS_FLAGS1_10;
        gBattleStatus.flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_10;
        gBattleStatus.flags1 &= ~BS_FLAGS1_SP_EVT_ACTIVE;
    }

    if (flags & BS_FLAGS1_40) {
        gBattleStatus.flags1 |= BS_FLAGS1_40;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_40;
    }
    if (flags & BS_FLAGS1_200) {
        gBattleStatus.flags1 |= BS_FLAGS1_200;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_200;
    }
    if (flags & BS_FLAGS1_80) {
        gBattleStatus.flags1 |= BS_FLAGS1_80;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_80;
    }
    if (flags & BS_FLAGS1_800) {
        gBattleStatus.flags1 |= BS_FLAGS1_800;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_800;
    }

    target = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = target->targetActorID;
    battleStatus->currentTargetPart = target->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;
    if (battleStatus->statusChance == 0xFF) {
        battleStatus->statusChance = 0;
    }
    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;

    temp_v0_2 = calc_player_damage_enemy();
    if (temp_v0_2 < 0) {
        return ApiStatus_FINISH;
    }
    evt_set_variable(script, a0, temp_v0_2);

    if (!does_script_exist_by_ref(script)) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus PlayerTestEnemy(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 a0 = *args++;
    s32 flags;
    Actor* target;
    s32 temp_v0_2;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = *args++;
    battleStatus->currentAttackStatus = *args++;
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
    battleStatus->powerBounceCounter = 0;
    flags = *args++;

    if ((flags & (BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)) == (BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)) {
        gBattleStatus.flags1 |= BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (flags & BS_FLAGS1_10) {
        gBattleStatus.flags1 |= BS_FLAGS1_10;
        gBattleStatus.flags1 &= ~BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (flags & BS_FLAGS1_SP_EVT_ACTIVE) {
        gBattleStatus.flags1 &= ~BS_FLAGS1_10;
        gBattleStatus.flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_10;
        gBattleStatus.flags1 &= ~BS_FLAGS1_SP_EVT_ACTIVE;
    }

    if (flags & BS_FLAGS1_40) {
        gBattleStatus.flags1 |= BS_FLAGS1_40;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_40;
    }
    if (flags & BS_FLAGS1_200) {
        gBattleStatus.flags1 |= BS_FLAGS1_200;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_200;
    }
    if (flags & BS_FLAGS1_80) {
        gBattleStatus.flags1 |= BS_FLAGS1_80;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_80;
    }
    if (flags & BS_FLAGS1_800) {
        gBattleStatus.flags1 |= BS_FLAGS1_800;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_800;
    }

    target = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = target->targetActorID;
    battleStatus->currentTargetPart = target->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;
    if (battleStatus->statusChance == 0xFF) {
        battleStatus->statusChance = 0;
    }
    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;

    temp_v0_2 = calc_player_test_enemy();
    if (temp_v0_2 < 0) {
        return ApiStatus_FINISH;
    }
    evt_set_variable(script, a0, temp_v0_2);
    return ApiStatus_DONE2;
}

ApiStatus DispatchDamagePlayerEvent(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;

    if (dispatch_damage_event_player_0(evt_get_variable(script, *args++), *args++) < 0) {
        return ApiStatus_BLOCK;
    }

    if (does_script_exist_by_ref(script)) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus EnablePlayerBlur(Evt* script, s32 isInitialCall) {
    s32 setting = evt_get_variable(script, *script->ptrReadPos);

    if (setting == 0) {
        disable_player_blur();
    } else if (setting == 1) {
        enable_player_blur();
    } else {
        func_80254950();
    }

    return ApiStatus_DONE2;
}

ApiStatus func_802749D8(Evt* script, s32 isInitialCall) {
    func_802549A0();
    return ApiStatus_DONE2;
}

ApiStatus func_802749F8(Evt* script, s32 isInitialCall) {
    func_802549C0();
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "19FAF0", func_80274A18);

INCLUDE_ASM(s32, "19FAF0", func_802752AC);

INCLUDE_ASM(s32, "19FAF0", func_80275F00);

ApiStatus DidActionSucceed(Evt* script, s32 isInitialCall) {
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

    evt_set_variable(script, outVar, actionSucceeded);
    return ApiStatus_DONE2;
}

ApiStatus func_80276EFC(Evt* script, s32 isInitialCall) {
    gBattleStatus.flags1 |= BS_FLAGS1_200000;
    return ApiStatus_DONE2;
}

ApiStatus DispatchEventPlayer(Evt* script, s32 isInitialCall) {
    dispatch_event_player(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
