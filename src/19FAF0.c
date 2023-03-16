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

    oldOnHitScript = player->handleEventScript;
    oldOnHitID = player->handleEventScriptID;

    eventScript = start_script(&EVS_Player_HandleEvent, EVT_PRIORITY_A, EVT_FLAG_RUN_IMMEDIATELY);
    player->handleEventScript = eventScript;
    player->handleEventScriptID = eventScript->id;
    eventScript->owner1.actor = NULL;

    if (player->takeTurnScript != NULL) {
        kill_script_by_ID(player->takeTurnScriptID);
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

    oldOnHitScript = player->handleEventScript;
    oldOnHitID = player->handleEventScriptID;

    eventScript = start_script(&EVS_Player_HandleEvent, EVT_PRIORITY_A, EVT_FLAG_RUN_IMMEDIATELY);
    player->handleEventScript = eventScript;
    player->handleEventScriptID = eventScript->id;
    eventScript->owner1.actor = NULL;

    if (oldOnHitScript != NULL) {
        kill_script_by_ID(oldOnHitID);
    }
}

// Determines whether an attack from the player will hit an enemy or
HitResult calc_player_test_enemy(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    ActorState* state = &player->state;
    s32 targetActorID = battleStatus->currentTargetID;
    s32 targetPartIdx = battleStatus->currentTargetPart;
    Actor* target;
    ActorPart* targetPart;

    battleStatus->currentTargetID2 = battleStatus->currentTargetID;
    battleStatus->currentTargetPart2 = battleStatus->currentTargetPart;

    target = get_actor(targetActorID);
    if (target == NULL) {
        return HIT_RESULT_HIT;
    }

    targetPart = get_actor_part(target, targetPartIdx);
    ASSERT(targetPart != NULL);

    if (targetPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
        return HIT_RESULT_MISS;
    }

    if (target->transparentStatus == STATUS_TRANSPARENT
        || (targetPart->eventFlags & ACTOR_EVENT_FLAG_800)
        && !(battleStatus->currentAttackElement & DAMAGE_TYPE_QUAKE))
    {
        return HIT_RESULT_MISS;
    }

    if (target->stoneStatus == STATUS_STONE) {
        sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        return HIT_RESULT_IMMUNE;
    }

    if ((battleStatus->currentAttackElement & DAMAGE_TYPE_JUMP)
        && (targetPart->eventFlags & ACTOR_EVENT_FLAG_SPIKY_TOP)
        && !player_team_is_ability_active(player, ABILITY_SPIKE_SHIELD))
    {
        sfx_play_sound_at_position(SOUND_108, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        return HIT_RESULT_LANDED_ON_SPIKE;
    }

    if (!(battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_JUMP))
        && (targetPart->eventFlags & ACTOR_EVENT_FLAG_SPIKY_FRONT)
        && (!(battleStatus->currentAttackEventSuppression & SUPPRESS_EVENT_SPIKY_FRONT)
        && !player_team_is_ability_active(player, ABILITY_SPIKE_SHIELD)))
    {
        sfx_play_sound_at_position(SOUND_108, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        dispatch_damage_event_player_1(1, EVENT_SPIKE_CONTACT);
        dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
        return HIT_RESULT_BACKFIRE;
    }

    if (player->staticStatus != STATUS_STATIC && target->staticStatus == STATUS_STATIC) {
        return HIT_RESULT_HIT_STATIC;
    }

    return HIT_RESULT_HIT;
}

HitResult calc_player_damage_enemy(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 currentTargetID = battleStatus->currentTargetID;
    s32 currentTargetPartID = battleStatus->currentTargetPart;
    ActorState* state;
    Evt* evt;
    Actor* target;
    ActorPart* targetPart;
    s32 hitResult;
    s32 currentAttackDamage;
    s32 targetDefense;
    s32 dispatchEvent;
    s32 partImmuneToElement;
    s32 sp20;
    s32 sp24;
    s32 isFireDamage;
    s32 isShockDamage;
    s32 isWaterDamage;
    s32 isIceDamage;
    s32 tempBinary;
    s32 wasStatusInflicted;
    s32 attackFxType;

    sp20 = FALSE;
    isFireDamage = FALSE;
    isWaterDamage = FALSE;
    isShockDamage = FALSE;
    isIceDamage = FALSE;
    tempBinary = FALSE;
    partImmuneToElement = FALSE;
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
        return HIT_RESULT_HIT;
    }

    targetPart = get_actor_part(target, currentTargetPartID);

    ASSERT(targetPart != NULL);

    target->lastDamageTaken = 0;

    if (gBattleStatus.flags1 & BS_FLAGS1_FORCE_HIT_IMMUNE) {
        hitResult = HIT_RESULT_NO_DAMAGE;
        dispatchEvent = EVENT_ZERO_DAMAGE;
    } else {
        if (player_team_is_ability_active(player, ABILITY_ICE_POWER)) {
            if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT)) {
                battleStatus->currentAttackElement |= DAMAGE_TYPE_ICE;
            }
        }

        if (targetPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY
            || (target->transparentStatus == STATUS_TRANSPARENT
            || targetPart->eventFlags & ACTOR_EVENT_FLAG_800
            && !(battleStatus->currentAttackElement & DAMAGE_TYPE_QUAKE))
        ) {
            return HIT_RESULT_MISS;
        }

        if (target->stoneStatus == STATUS_STONE) {
            sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            func_8024EFE0(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, 1);
            show_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 0);
            if (gBattleStatus.flags1 & (BS_FLAGS1_40 | BS_FLAGS1_200)) {
                return HIT_RESULT_1;
            }
            return HIT_RESULT_HIT;
        }

        if (targetPart->elementalImmunities & battleStatus->currentAttackElement) {
            partImmuneToElement = TRUE;
        }

        if ((battleStatus->currentAttackElement & DAMAGE_TYPE_JUMP)
            && (targetPart->eventFlags & ACTOR_EVENT_FLAG_SPIKY_TOP)
            && !player_team_is_ability_active(player, ABILITY_SPIKE_SHIELD))
        {
            sfx_play_sound_at_position(SOUND_108, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_damage_event_player_1(1, EVENT_SPIKE_CONTACT);
            dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
            return HIT_RESULT_BACKFIRE;
        }

        if (!(battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_SMASH))) {
            if (targetPart->eventFlags & ACTOR_EVENT_FLAG_EXPLODE_ON_CONTACT) {
                sfx_play_sound_at_position(SOUND_HIT_PLAYER_FIRE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                dispatch_damage_event_player_1(1, EVENT_BURN_CONTACT);
                dispatch_event_actor(target, EVENT_EXPLODE_TRIGGER);
                return HIT_RESULT_BACKFIRE;
            }

            if (targetPart->eventFlags & ACTOR_EVENT_FLAG_FIREY
                && !(battleStatus->currentAttackEventSuppression & SUPPRESS_EVENT_BURN_CONTACT)
                && !(player_team_is_ability_active(player, ABILITY_FIRE_SHIELD))
                && !(player_team_is_ability_active(player, ABILITY_ICE_POWER))
            ) {
                sfx_play_sound_at_position(SOUND_HIT_PLAYER_FIRE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                dispatch_damage_event_player_1(1, EVENT_BURN_CONTACT);
                dispatch_event_actor(target, EVENT_BURN_TAUNT);
                return HIT_RESULT_BACKFIRE;
            }
        }

        if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE
            && battleStatus->currentAttackElement & DAMAGE_TYPE_FIRE
            && targetPart->eventFlags & (ACTOR_EVENT_FLAG_FIRE_EXPLODE | ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION)
        ) {
            sfx_play_sound_at_position(SOUND_HIT_PLAYER_FIRE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_event_actor(target, EVENT_EXPLODE_TRIGGER);
            if (gBattleStatus.flags1 & (BS_FLAGS1_40 | BS_FLAGS1_200)) {
                return HIT_RESULT_1;
            }
            return HIT_RESULT_HIT;
        }

        if (!(battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_SMASH))
            && targetPart->eventFlags & ACTOR_EVENT_FLAG_200000
            && !(battleStatus->currentAttackEventSuppression & SUPPRESS_EVENT_FLAG_80)
            && !player_team_is_ability_active(player, ABILITY_SPIKE_SHIELD)
        ) {
            sfx_play_sound_at_position(SOUND_108, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_damage_event_player_1(1, EVENT_SPIKE_CONTACT);
            dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
            return HIT_RESULT_BACKFIRE;
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_FIRE) {
            fx_ring_blast(0, state->goalPos.x, state->goalPos.y, state->goalPos.z * 5.0f, 1.0f, 24);
            isFireDamage = TRUE;
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_SHOCK) {
            apply_shock_effect(target);
            isShockDamage = TRUE;
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
                    sfx_play_sound_at_position(SOUND_372, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    break;
                case 2:
                    sfx_play_sound_at_position(SOUND_F1, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    break;
                case 3:
                    sfx_play_sound_at_position(SOUND_DC, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    break;
                case 4:
                    sfx_play_sound_at_position(SOUND_2072, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    break;
                case 5:
                    sfx_play_sound_at_position(SOUND_2073, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    break;
                case 6:
                    sfx_play_sound_at_position(SOUND_205B, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    break;
            }
        }

        if (!is_ability_active(ABILITY_ZAP_TAP)
            && player->staticStatus != STATUS_STATIC
            && (target->staticStatus == STATUS_STATIC || targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED)
            && !(battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_SHOCK))
            && !(battleStatus->currentAttackEventSuppression & SUPPRESS_EVENT_SHOCK_CONTACT)
        ) {
            gBattleStatus.flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;
            sp20 = TRUE;
        }

        if (targetPart->eventFlags & (ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED | ACTOR_EVENT_FLAG_ENCHANTED)) {
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
            gBattleStatus.flags1 &= ~BS_FLAGS1_JUMP_CHARGED;
        }

        if (battleStatus->hammerCharge && battleStatus->currentAttackElement & (DAMAGE_TYPE_QUAKE_HAMMER | DAMAGE_TYPE_THROW | DAMAGE_TYPE_SMASH)) {
            currentAttackDamage += battleStatus->hammerCharge;
            gBattleStatus.flags1 &= ~BS_FLAGS1_HAMMER_CHARGED;
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

            gBattleStatus.flags2 |= BS_FLAGS2_HAS_DRAINED_HP;

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

            gBattleStatus.flags2 |= BS_FLAGS2_HAS_DRAINED_HP;

            if (battleStatus->hpDrainCount > 5) {
                battleStatus->hpDrainCount = 5;
            }
        }

        if (gBattleStatus.flags2 & BS_FLAGS2_HAS_RUSH && (gBattleStatus.flags1 & BS_FLAGS1_10 ||
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

        if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE
            && battleStatus->currentAttackElement & DAMAGE_TYPE_BLAST
            && targetPart->eventFlags & ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION
        ) {
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
            hitResult = HIT_RESULT_NO_DAMAGE;

            if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS)) {
                dispatchEvent = EVENT_ZERO_DAMAGE;
                sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            } else {
                if (target->currentHP < 1) {
                    dispatchEvent = EVENT_DEATH;
                 } else {
                    dispatchEvent = EVENT_ZERO_DAMAGE;
                }
            }

            battleStatus->lastAttackDamage = 0;
        } else {
            target->damageCounter += currentAttackDamage;
            dispatchEvent = EVENT_HIT_COMBO;
            hitResult = HIT_RESULT_HIT;
            target->hpChangeCounter -= currentAttackDamage;

            if (!(targetPart->flags & ACTOR_PART_FLAG_2000)
                && !(gBattleStatus.flags1 & BS_FLAGS1_TUTORIAL_BATTLE)
                && !partImmuneToElement
                && !(targetPart->targetFlags & ACTOR_PART_TARGET_FLAG_4)
            ) {
                target->currentHP -= currentAttackDamage;

                if (target->currentHP < 1) {
                    target->currentHP = 0;
                    dispatchEvent = EVENT_DEATH;
                }
            }

            battleStatus->lastAttackDamage += currentAttackDamage;
            target->lastDamageTaken = battleStatus->lastAttackDamage;
            target->hpChangeCounter = 0;
        }

        if (targetPart->flags & ACTOR_PART_FLAG_2000) {
            if (!is_ability_active(ABILITY_ZAP_TAP)
                && player->staticStatus != STATUS_STATIC
                && (target->staticStatus == STATUS_STATIC || (targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED))
                && !(battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT)
                && !(battleStatus->currentAttackEventSuppression & SUPPRESS_EVENT_SHOCK_CONTACT)
                && !(battleStatus->currentAttackElement & DAMAGE_TYPE_SHOCK)
            ) {
                sfx_play_sound_at_position(SOUND_HIT_PLAYER_SHOCK, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                apply_shock_effect(player);
                dispatch_damage_event_player_1(1, EVENT_SHOCK_HIT);
                return HIT_RESULT_BACKFIRE;
            } else {
                dispatchEvent = (!(gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE)) ? EVENT_ZERO_DAMAGE : EVENT_IMMUNE;
                sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                dispatch_event_actor(target, dispatchEvent);
                func_8024EFE0(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, 3);
                if (gBattleStatus.flags1 & (BS_FLAGS1_40 | BS_FLAGS1_200)) {
                    return HIT_RESULT_1;
                }
                return HIT_RESULT_HIT;
            }
        }

        if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
            if (battleStatus->currentAttackElement & DAMAGE_TYPE_FEAR
                && rand_int(99) < (target->actorBlueprint->escapeChance * battleStatus->statusChance) / 100
                && (target->debuff != STATUS_FEAR
                    && target->debuff != STATUS_DIZZY
                    && target->debuff != STATUS_PARALYZE
                    && target->debuff != STATUS_SLEEP
                    && target->debuff != STATUS_FROZEN
                    && target->debuff != STATUS_STOP)
                && !(target->flags & ACTOR_FLAG_FLIPPED)
            ) {
                dispatch_event_actor(target, EVENT_SCARE_AWAY);
                if (gBattleStatus.flags1 & (BS_FLAGS1_40 | BS_FLAGS1_200)) {
                    return HIT_RESULT_1;
                }
                return HIT_RESULT_HIT;
            }
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (dispatchEvent == EVENT_HIT_COMBO) {
            dispatchEvent = EVENT_HIT;
        }

        if (dispatchEvent == EVENT_ZERO_DAMAGE) {
            dispatchEvent = EVENT_IMMUNE;
        }

        if (target->currentHP < 1) {
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

            if (target->actorBlueprint->spinSmashReq != 255
                && playerData->hammerLevel + 1 >= target->actorBlueprint->spinSmashReq
                && battleStatus->lastAttackDamage > 0
                && gBattleStatus.flags1 & BS_FLAGS1_40
            ) {
                if (dispatchEvent == EVENT_HIT_COMBO) {
                    dispatchEvent = EVENT_SPIN_SMASH_HIT;
                }

                if (dispatchEvent == EVENT_HIT) {
                    dispatchEvent = EVENT_SPIN_SMASH_HIT;
                }

                if (dispatchEvent == EVENT_ZERO_DAMAGE) {
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

        if ((gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE)
            && !(battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT)
            && targetPart->eventFlags & ACTOR_EVENT_FLAG_POWER_BOUNCE
        ) {
            if (dispatchEvent == EVENT_HIT_COMBO) {
                dispatchEvent = EVENT_POWER_BOUNCE_HIT;
            }

            if (dispatchEvent == EVENT_HIT) {
                dispatchEvent = EVENT_POWER_BOUNCE_HIT;
            }

            if (dispatchEvent == EVENT_ZERO_DAMAGE) {
                dispatchEvent = EVENT_POWER_BOUNCE_HIT;
            }

            if (dispatchEvent == EVENT_IMMUNE) {
                dispatchEvent = EVENT_POWER_BOUNCE_HIT;
            }

            if (dispatchEvent == EVENT_DEATH) {
                dispatchEvent = EVENT_POWER_BOUNCE_DEATH;
            }
        }

        if ((gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE)
            && (battleStatus->currentAttackElement & (DAMAGE_TYPE_POW | DAMAGE_TYPE_JUMP))
            && targetPart->eventFlags & ACTOR_EVENT_FLAG_GROUNDABLE
        ) {
            if (dispatchEvent == EVENT_HIT) {
                dispatchEvent = EVENT_FALL_TRIGGER;
            }

            if (dispatchEvent == EVENT_IMMUNE) {
                dispatchEvent = EVENT_FALL_TRIGGER;
            }

            tempBinary = TRUE;
        }

        if ((gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE)
            && (battleStatus->currentAttackElement & (DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_POW | DAMAGE_TYPE_JUMP))
            && targetPart->eventFlags & ACTOR_EVENT_FLAG_FLIPABLE
        ) {
            if (dispatchEvent == EVENT_HIT) {
                dispatchEvent = EVENT_FLIP_TRIGGER;
            }

            if (dispatchEvent == EVENT_IMMUNE) {
                dispatchEvent = EVENT_FLIP_TRIGGER;
            }

            if (!(target->flags & ACTOR_FLAG_FLIPPED)) {
                tempBinary = TRUE;
            }
        }
    }

    if (!(gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE)
        && battleStatus->currentAttackElement & (DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_POW | DAMAGE_TYPE_JUMP)
        && targetPart->eventFlags & ACTOR_EVENT_FLAG_FLIPABLE
    ) {
        if (dispatchEvent == EVENT_HIT_COMBO) {
            dispatchEvent = EVENT_FLIP_TRIGGER;
        }

        if (dispatchEvent == EVENT_ZERO_DAMAGE) {
            dispatchEvent = EVENT_FLIP_TRIGGER;
        }

        if (!(target->flags & ACTOR_FLAG_FLIPPED)) {
            tempBinary = TRUE;
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE
        && battleStatus->currentAttackElement & DAMAGE_TYPE_SHELL_CRACK
        && targetPart->eventFlags & ACTOR_EVENT_FLAG_FLIPABLE
    ) {
        if (dispatchEvent == EVENT_HIT) {
            dispatchEvent = EVENT_SHELL_CRACK_HIT;
        }

        if (dispatchEvent == EVENT_IMMUNE) {
            dispatchEvent = EVENT_SHELL_CRACK_HIT;
        }
        tempBinary = TRUE;
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE
        && (battleStatus->currentAttackElement & (DAMAGE_TYPE_BLAST | DAMAGE_TYPE_FIRE))
    ) {
        if (dispatchEvent == EVENT_HIT) {
            dispatchEvent = EVENT_BURN_HIT;
        }

        if (dispatchEvent == EVENT_DEATH) {
            dispatchEvent = EVENT_BURN_DEATH;
        }

        isFireDamage = TRUE;
    }

    do {        // TODO remove this do while
        if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE
            && battleStatus->lastAttackDamage >= 0
            && dispatchEvent != EVENT_DEATH
            && dispatchEvent != EVENT_SPIN_SMASH_DEATH
            && dispatchEvent != EVENT_EXPLODE_TRIGGER
            && !(targetPart->targetFlags & ACTOR_PART_TARGET_FLAG_4)
        ) {
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
                if (dispatchEvent == EVENT_ZERO_DAMAGE) {
                    dispatchEvent = EVENT_HIT_COMBO;
                }

                if (dispatchEvent == EVENT_IMMUNE) {
                    dispatchEvent = EVENT_HIT;
                }
            }
        }
    } while (0);

    battleStatus->wasStatusInflicted = wasStatusInflicted;
    dispatch_event_actor(target, dispatchEvent);

    if (!(target->flags & ACTOR_FLAG_NO_DMG_POPUP)) {
        if (battleStatus->lastAttackDamage == 0) {
            if (!tempBinary) {
                if (!wasStatusInflicted) {
                    func_8024EFE0(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, 3);
                }
            }
        } else if (!partImmuneToElement) {
            if (battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS | DAMAGE_TYPE_SMASH)) {
                show_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 0);
            } else {
                func_802664DC(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 0);
            }

            if (!(targetPart->targetFlags & ACTOR_PART_TARGET_FLAG_4)) {
                func_802666E4(target, state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage);
            }
        }
    }

    if (tempBinary && gBattleStatus.flags1 & BS_FLAGS1_40 || gBattleStatus.flags1 & BS_FLAGS1_40) {
        if (!(gBattleStatus.flags1 & BS_FLAGS1_80)) {
            if (player->actorTypeData1[5]) {
                sfx_play_sound_at_position(player->actorTypeData1[5], SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
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

    if ((battleStatus->lastAttackDamage > 0 || tempBinary) && !partImmuneToElement) {
        func_80267018(target, 1);

        if (isFireDamage) {
            sfx_play_sound_at_position(SOUND_HIT_FIRE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        } else if (isShockDamage) {
            sfx_play_sound_at_position(SOUND_HIT_SHOCK, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        } else if (isIceDamage) {
            sfx_play_sound_at_position(SOUND_HIT_ICE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        } else {
            sfx_play_sound_at_position(SOUND_HIT_NORMAL, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        }
    }

    if (battleStatus->lastAttackDamage < 1 && !tempBinary && !sp20 || targetPart->flags & ACTOR_PART_FLAG_2000) {
        sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_SLEEP && wasStatusInflicted) {
        evt = start_script(&DoSleepHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_SLEEP, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_DIZZY && wasStatusInflicted) {
        evt = start_script(&DoDizzyHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_PARALYZE && wasStatusInflicted) {
        evt = start_script(&DoParalyzeHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_POISON && wasStatusInflicted) {
        evt = start_script(&DoPoisonHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_STOP && wasStatusInflicted) {
        evt = start_script(&DoStopHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_FROZEN && wasStatusInflicted) {
        evt = start_script(&DoFreezeHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        evt->varTablePtr[3] = target;
        sfx_play_sound_at_position(SOUND_HIT_PLAYER_ICE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_SHRINK && wasStatusInflicted) {
        evt = start_script(&DoShrinkHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        evt->varTablePtr[3] = target;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackElement & DAMAGE_TYPE_SMASH && target->actorType == ACTOR_TYPE_GOOMNUT_TREE) {
        sfx_play_sound_at_position(SOUND_SMASH_GOOMNUT_TREE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    func_80266ADC(target);

    if (gBattleStatus.flags1 & (BS_FLAGS1_200 | BS_FLAGS1_40)) {
        if (hitResult == HIT_RESULT_HIT) {
            hitResult = HIT_RESULT_1;
        }
        if (hitResult == HIT_RESULT_NO_DAMAGE) {
            hitResult = HIT_RESULT_3;
        }
    }

    if (!is_ability_active(ABILITY_ZAP_TAP)
        && (player->staticStatus != STATUS_STATIC)
        && (target->staticStatus == STATUS_STATIC || targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED)
        && !(battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_SHOCK))
        && !(battleStatus->currentAttackEventSuppression & SUPPRESS_EVENT_SHOCK_CONTACT)
    ) {
        sfx_play_sound_at_position(SOUND_HIT_PLAYER_SHOCK, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        apply_shock_effect(player);
        dispatch_damage_event_player_1(1, EVENT_SHOCK_HIT);
        return HIT_RESULT_BACKFIRE;
    }

    return hitResult;
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

    temp = (s16)damageAmount; //TODO usage of temp here required to match
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
    if (player->currentHP < 1) {
        battleStatus->lastAttackDamage += oldPlayerHP;
        player->currentHP = 0;
        dispatchEvent = EVENT_DEATH;
    }
    battleStatus->lastAttackDamage += temp;
    playerData->curHP = player->currentHP;

    if (dispatchEvent == EVENT_HIT_COMBO) {
        dispatchEvent = EVENT_HIT;
    }
    if (dispatchEvent == EVENT_ZERO_DAMAGE) {
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
        sfx_play_sound_at_position(SOUND_HIT_NORMAL, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
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
    evt_set_variable(script, outVar2, battleStatus->moveArgument);
    evt_set_variable(script, outVar3, battleStatus->selectedMoveID);

    return ApiStatus_DONE2;
}

ApiStatus func_80273444(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* player = battleStatus->playerActor;
    ActorState* playerState = &player->state;
    f32 playerVel;
    f32 x, y, z;
    f32 goalX, goalY, goalZ;
    f32 var_f8;
    f64 playerSpeed;

    if (isInitialCall) {
        script->functionTemp[0] = FALSE;
    }

    if (script->functionTemp[0] == 0) {
        player->state.moveTime = evt_get_variable(script, *args++);
        player->state.moveArcAmplitude = evt_get_variable(script, *args++);
        script->functionTemp[1] = evt_get_variable(script, *args++);

        player->state.currentPos.x = player->currentPos.x;
        player->state.currentPos.y = player->currentPos.y;
        player->state.currentPos.z = player->currentPos.z;

        x = player->state.currentPos.x;
        y = player->state.currentPos.y;
        z = player->state.currentPos.z;
        goalX = player->state.goalPos.x;
        goalY = player->state.goalPos.y;
        goalZ = player->state.goalPos.z;

        player->state.angle = atan2(x, z, goalX, goalZ);
        player->state.distance = dist2D(x, z, goalX, goalZ);

        y = goalY - y;

        if (player->state.moveTime == 0) {
            player->state.moveTime = player->state.distance / player->state.speed;
            var_f8 = player->state.distance - (player->state.moveTime * player->state.speed);
        } else {
            player->state.speed = player->state.distance / player->state.moveTime;
            var_f8 = player->state.distance - (player->state.moveTime * player->state.speed);
        }

        playerState->speed += var_f8 / playerState->moveTime;
        playerState->velocity = (playerState->acceleration * playerState->moveTime * 0.5f) + (y / playerState->moveTime);
        set_animation(0, 0, playerState->animJumpRise);
        playerState->unk_24 = 90.0f;
        playerState->unk_28 = 180 / playerState->moveTime;
        playerState->unk_2C = playerState->goalPos.y;
        if (script->functionTemp[1] != 2) {
            sfx_play_sound_at_position(SOUND_160, SOUND_SPACE_MODE_0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
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
    playerSpeed = playerState->speed;
    add_xz_vec3f(&playerState->currentPos, playerSpeed + sin_rad(DEG_TO_RAD(playerState->unk_24)), playerState->angle);
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
        sfx_play_sound_at_position(SOUND_SOFT_LAND, SOUND_SPACE_MODE_0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
    }

    return ApiStatus_DONE1;
}

ApiStatus PlayerFallToGoal(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* player = gBattleStatus.playerActor;
    ActorState* state = &player->state;
    f32 x, y, z;
    f32 goalX, goalY, goalZ;

    if (isInitialCall) {
        script->functionTemp[0] = FALSE;
    }

    if (!script->functionTemp[0]) {
        s32 moveTime = evt_get_variable(script, *args++);

        player->state.currentPos.x = player->currentPos.x;
        player->state.currentPos.y = player->currentPos.y;
        player->state.currentPos.z = player->currentPos.z;

        x = player->state.currentPos.x;
        y = player->state.currentPos.y;
        z = player->state.currentPos.z;
        goalX = player->state.goalPos.x;
        goalY = player->state.goalPos.y;
        goalZ = player->state.goalPos.z;

        state->moveTime = moveTime;

        player->state.angle = atan2(x, z, goalX, goalZ);
        player->state.distance = dist2D(x, z, goalX, goalZ);

        y = goalY - y;

        if (state->moveTime == 0) {
            state->moveTime = state->distance / state->speed;
        } else {
            state->speed = state->distance / state->moveTime;
        }

        state->velocity = 0.0f;
        state->acceleration = ((y / state->moveTime) - state->velocity) / (-state->moveTime * 0.5);
        set_animation(ACTOR_PLAYER, 0, state->animJumpRise);
        script->functionTemp[0] = TRUE;
    }

    if (state->velocity < 0.0f) {
        set_animation(ACTOR_PLAYER, 0, state->animJumpFall);
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
        sfx_play_sound_at_position(SOUND_SOFT_LAND, SOUND_SPACE_MODE_0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
        return ApiStatus_DONE1;
    }
    return ApiStatus_BLOCK;
}

ApiStatus PlayerLandJump(Evt* script, s32 isInitialCall) {
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
        sfx_play_sound_at_position(SOUND_SOFT_LAND, SOUND_SPACE_MODE_0, player->currentPos.x, player->currentPos.y, player->currentPos.z);

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
            sfx_play_sound_at_position(SOUND_STEP_NORMAL1, SOUND_SPACE_MODE_0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
        } else {
            sfx_play_sound_at_position(SOUND_STEP_NORMAL2, SOUND_SPACE_MODE_0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
        }
    }

    playerState->moveTime--;

    if (playerState->moveTime <= 0) {
        player->currentPos.x = playerState->goalPos.x;
        player->currentPos.z = playerState->goalPos.z;
        return ApiStatus_DONE2;
    }
    return ApiStatus_BLOCK;
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
            sfx_play_sound_at_position(SOUND_STEP_NORMAL1, SOUND_SPACE_MODE_0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
        } else {
            sfx_play_sound_at_position(SOUND_STEP_NORMAL2, SOUND_SPACE_MODE_0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
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
    s32 hitResultOutVar = *args++;
    s32 flags;
    Actor* target;
    HitResult hitResult;

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
    if (flags & BS_FLAGS1_FORCE_HIT_IMMUNE) {
        gBattleStatus.flags1 |= BS_FLAGS1_FORCE_HIT_IMMUNE;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_FORCE_HIT_IMMUNE;
    }

    target = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = target->targetActorID;
    battleStatus->currentTargetPart = target->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;
    if (battleStatus->statusChance == STATUS_CHANCE_NEVER) {
        battleStatus->statusChance = 0;
    }
    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;

    hitResult = calc_player_damage_enemy();
    if (hitResult < 0) {
        return ApiStatus_FINISH;
    }
    evt_set_variable(script, hitResultOutVar, hitResult);

    if (!does_script_exist_by_ref(script)) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus PlayerPowerBounceEnemy(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 hitResultOutVar = *args++;
    s32 flags;
    Actor* target;
    HitResult hitResult;

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
    if (flags & BS_FLAGS1_FORCE_HIT_IMMUNE) {
        gBattleStatus.flags1 |= BS_FLAGS1_FORCE_HIT_IMMUNE;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_FORCE_HIT_IMMUNE;
    }

    target = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = target->targetActorID;
    battleStatus->currentTargetPart = target->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;
    if (battleStatus->statusChance == STATUS_CHANCE_NEVER) {
        battleStatus->statusChance = 0;
    }
    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;

    hitResult = calc_player_damage_enemy();
    if (hitResult < 0) {
        return ApiStatus_FINISH;
    }
    evt_set_variable(script, hitResultOutVar, hitResult);

    if (!does_script_exist_by_ref(script)) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus PlayerTestEnemy(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 hitResultOutVar = *args++;
    s32 flags;
    Actor* target;
    HitResult hitResult;

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
    if (flags & BS_FLAGS1_FORCE_HIT_IMMUNE) {
        gBattleStatus.flags1 |= BS_FLAGS1_FORCE_HIT_IMMUNE;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_FORCE_HIT_IMMUNE;
    }

    target = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = target->targetActorID;
    battleStatus->currentTargetPart = target->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;
    if (battleStatus->statusChance == STATUS_CHANCE_NEVER) {
        battleStatus->statusChance = 0;
    }
    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;

    hitResult = calc_player_test_enemy();
    if (hitResult < 0) {
        return ApiStatus_FINISH;
    }
    evt_set_variable(script, hitResultOutVar, hitResult);
    return ApiStatus_DONE2;
}

ApiStatus DispatchDamagePlayerEvent(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 damageAmount = evt_get_variable(script, *args++);

    if (dispatch_damage_event_player_0(damageAmount, *args++) < 0) {
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

ApiStatus func_80274A18(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* player = battleStatus->playerActor;
    ActorState* playerState = &player->state;
    f32 posX, posY, posZ;
    f32 goalX, goalZ;
    f32 temp;
    f64 temp_f20_2;
    f64 vel1, vel2;
    f64 vel3, vel4;
    f64 acc1, acc2;
    f64 acc3, acc4;

    if (isInitialCall) {
        player->state.moveTime = evt_get_variable(script, *args++);
        player->state.moveArcAmplitude = evt_get_variable(script, *args++);
        script->functionTemp[1] = 0;
        script->functionTemp[0] = 0;
        if (player->state.moveArcAmplitude == 1) {
            script->functionTemp[0] = 2;
        }
    }

    if (script->functionTemp[0] == 0) {
        playerState->currentPos.x = player->currentPos.x;
        playerState->currentPos.y = player->currentPos.y;
        playerState->currentPos.z = player->currentPos.z;
        goalX = playerState->goalPos.x;
        goalZ = playerState->goalPos.z;
        posX = playerState->currentPos.x;
        posY = playerState->currentPos.y;
        posZ = playerState->currentPos.z;
        playerState->angle = atan2(posX, posZ, goalX, goalZ);
        playerState->distance = dist2D(posX, posZ, goalX, goalZ);
        if (playerState->moveTime == 0) {
            playerState->moveTime = playerState->distance / playerState->speed;
            temp = playerState->distance - (playerState->moveTime * playerState->speed);
        } else {
            playerState->speed = playerState->distance / playerState->moveTime;
            temp = playerState->distance - (playerState->moveTime * playerState->speed);
        }

        if (playerState->moveTime == 0) {
            return ApiStatus_DONE2;
        }

        playerState->unk_30.x = (playerState->goalPos.x - playerState->currentPos.x) / playerState->moveTime;
        playerState->unk_30.y = (playerState->goalPos.y - playerState->currentPos.y) / playerState->moveTime;
        playerState->unk_30.z = (playerState->goalPos.z - playerState->currentPos.z) / playerState->moveTime;
        playerState->acceleration = PI_S /  playerState->moveTime;
        playerState->velocity = 0.0f;
        playerState->speed += temp / playerState->moveTime;
        if (playerState->moveArcAmplitude < 3) {
            temp = playerState->distance;
            temp -= 20.0;
            temp /= 6.0;
            temp += 47.0;
            playerState->bounceDivisor = temp;
            playerState->unk_24 = 90.0f;
            playerState->unk_28 = 360 / playerState->moveTime;
            if (playerState->moveArcAmplitude == 2) {
                playerState->bounceDivisor = temp * 1.12;
            }
            playerState->unk_18.x = 0.0f;
            playerState->unk_18.y = 0.0f;
            vel1 = playerState->velocity;
            acc1 = playerState->acceleration;
            playerState->velocity = vel1 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * acc1) + acc1);
        } else {
            temp = playerState->distance;
            temp -= 20.0;
            temp /= 6.0;
            temp += 47.0;
            playerState->bounceDivisor = temp;
            playerState->unk_24 = 90.0f;
            playerState->unk_28 = 360 / playerState->moveTime;
            if (playerState->moveArcAmplitude == 4) {
                playerState->bounceDivisor = temp * 1.25;
            }
            playerState->unk_18.x = 0.0f;
            playerState->unk_18.y = 0.0f;
            vel2 = playerState->velocity;
            acc2 = playerState->acceleration;
            playerState->velocity = vel2 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.8 * acc2) + acc2);
        }
        set_animation(0, 0, playerState->animJumpRise);
        sfx_play_sound_at_position(SOUND_160, SOUND_SPACE_MODE_0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
        script->functionTemp[0] = 1;
    }

    switch (script->functionTemp[0]) {
        case 1:
            if (playerState->velocity > PI_S / 2) {
                set_animation(ACTOR_PLAYER, 0, playerState->animJumpFall);
            }
            playerState->currentPos.x += playerState->unk_30.x;
            playerState->currentPos.y += playerState->unk_30.y;
            playerState->currentPos.z += playerState->unk_30.z;
            playerState->unk_18.x = player->currentPos.y;
            player->currentPos.x = playerState->currentPos.x;
            player->currentPos.y = playerState->currentPos.y + (playerState->bounceDivisor * sin_rad(playerState->velocity));
            player->currentPos.z = playerState->currentPos.z;
            if (playerState->goalPos.y > player->currentPos.y && playerState->moveTime < 3) {
                player->currentPos.y = playerState->goalPos.y;
            }
            playerState->unk_18.y = player->currentPos.y;
            if (playerState->moveArcAmplitude < 3) {
                vel3 = playerState->velocity;
                acc3 = playerState->acceleration;
                playerState->velocity = vel3 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * acc3) + acc3);
            } else {
                vel4 = playerState->velocity;
                acc4 = playerState->acceleration;
                playerState->velocity = vel4 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.8 * acc4) + acc4);
            }
            playerState->unk_24 += playerState->unk_28;
            playerState->unk_24 = clamp_angle(playerState->unk_24);
            playerState->moveTime--;
            if (playerState->moveTime == 0) {
                player->currentPos.y = playerState->goalPos.y;
                playerState->acceleration = 1.8f;
                playerState->velocity = -(playerState->unk_18.x - playerState->unk_18.y);
                set_animation(ACTOR_PLAYER, 0, playerState->animJumpLand);
                return ApiStatus_DONE1;
            }
            break;
        case 2:
            if (battleStatus->actionCommandMode == ACTION_COMMAND_MODE_NOT_LEARNED) {
                return ApiStatus_DONE2;
            }
            playerState->moveTime = 1;
            playerState->acceleration = 1.8f;
            playerState->unk_24 = 90.0f;
            playerState->velocity = -(playerState->unk_18.x - playerState->unk_18.y);
            playerState->bounceDivisor = fabsf(playerState->unk_18.x - playerState->unk_18.y) / 16.5;
            playerState->unk_28 = 360 / playerState->moveTime;
            playerState->currentPos.x = player->currentPos.x;
            playerState->currentPos.y = player->currentPos.y;
            playerState->currentPos.z = player->currentPos.z;
            script->functionTemp[0] = 3;
            // fallthrough
        case 3:
            temp_f20_2 = playerState->currentPos.x;
            playerState->currentPos.x = temp_f20_2 + ((playerState->bounceDivisor * sin_rad(DEG_TO_RAD(playerState->unk_24))) / 33.0);
            playerState->currentPos.y -= (playerState->bounceDivisor * sin_rad(DEG_TO_RAD(playerState->unk_24)));
            playerState->unk_24 += playerState->unk_28;
            playerState->unk_24 = clamp_angle(playerState->unk_24);
            player->currentPos.x = playerState->currentPos.x;
            player->currentPos.y = playerState->currentPos.y;
            player->currentPos.z = playerState->currentPos.z;
            if (gBattleStatus.flags1 & BS_FLAGS1_2000) {
                return ApiStatus_DONE2;
            }
            playerState->moveTime--;
            if (playerState->moveTime == 0) {
                return ApiStatus_DONE1;
            }
            break;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_802752AC(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* player = gBattleStatus.playerActor;
    ActorState* playerState = &player->state;
    f32 posX, posY, posZ;
    f32 goalX, goalZ;
    f32 temp;
    f64 temp_f20;
    f64 vel1, vel2;
    f64 vel3, vel4;
    f64 vel5, vel6;
    f64 vel7, vel8;
    f64 acc1, acc2;
    f64 acc3, acc4;
    f64 acc5, acc6;
    f64 acc7, acc8;

    if (isInitialCall) {
        player->state.moveTime = evt_get_variable(script, *args++);
        player->state.moveArcAmplitude = evt_get_variable(script, *args++);
        script->functionTemp[0] = 0;
        if (player->state.moveArcAmplitude == 1 ||
            player->state.moveArcAmplitude == 5 ||
            player->state.moveArcAmplitude == 6)
        {
            script->functionTemp[0] = 10;
        }
        if (playerState->moveArcAmplitude == 2) {
            script->functionTemp[0] = 20;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            playerState->currentPos.x = player->currentPos.x;
            playerState->currentPos.y = player->currentPos.y;
            playerState->currentPos.z = player->currentPos.z;
            goalX = playerState->goalPos.x;
            goalZ = playerState->goalPos.z;
            posX = playerState->currentPos.x;
            posY = playerState->currentPos.y;
            posZ = playerState->currentPos.z;
            playerState->angle = atan2(posX, posZ, goalX, goalZ);
            playerState->distance = dist2D(posX, posZ, goalX, goalZ);

            if (playerState->moveTime == 0) {
                playerState->moveTime = playerState->distance / playerState->speed;
                temp = playerState->distance - (playerState->moveTime * playerState->speed);
            } else {
                playerState->speed = playerState->distance / playerState->moveTime;
                temp = playerState->distance - (playerState->moveTime * playerState->speed);
            }

            if (playerState->moveTime == 0) {
                return ApiStatus_DONE2;
            }

            playerState->unk_30.x = (playerState->goalPos.x - playerState->currentPos.x) / playerState->moveTime;
            playerState->unk_30.y = (playerState->goalPos.y - playerState->currentPos.y) / playerState->moveTime;
            playerState->unk_30.z = (playerState->goalPos.z - playerState->currentPos.z) / playerState->moveTime;
            playerState->acceleration = (PI_S / 2) / playerState->moveTime;
            playerState->velocity = 0.0f;
            playerState->speed += temp / playerState->moveTime;
            set_animation(ACTOR_PLAYER, 0, playerState->animJumpRise);
            sfx_play_sound_at_position(SOUND_160, SOUND_SPACE_MODE_0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
            playerState->unk_24 = 90.0f;
            playerState->bounceDivisor = 45.0f;
            playerState->unk_28 = 360 / playerState->moveTime;
            if (playerState->moveArcAmplitude == 4) {
                playerState->bounceDivisor = 56.25f;
            }
            playerState->unk_18.x = 0.0f;
            playerState->unk_18.y = 0.0f;
            if (playerState->moveArcAmplitude == 0) {
                vel1 = playerState->velocity;
                acc1 = playerState->acceleration;
                playerState->velocity = (vel1 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * acc1) + acc1));
            } else {
                vel2 = playerState->velocity;
                acc2 = playerState->acceleration;
                playerState->velocity = (vel2 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.01 * acc2) + acc2));
            }
            script->functionTemp[0] = 1;
            break;
        case 10:
            playerState->currentPos.x = player->currentPos.x;
            playerState->currentPos.y = player->currentPos.y;
            playerState->currentPos.z = player->currentPos.z;
            goalX = playerState->goalPos.x;
            goalZ = playerState->goalPos.z;
            posX = playerState->currentPos.x;
            posY = playerState->currentPos.y;
            posZ = playerState->currentPos.z;
            playerState->angle = atan2(posX, posZ, goalX, goalZ);
            playerState->distance = dist2D(posX, posZ, goalX, goalZ);
            if (playerState->moveTime == 0) {
                playerState->moveTime = playerState->distance / playerState->speed;
                temp = playerState->distance - (playerState->moveTime * playerState->speed);
            } else {
                playerState->speed = playerState->distance / playerState->moveTime;
                temp = playerState->distance - (playerState->moveTime * playerState->speed);
            }

            if (playerState->moveTime == 0) {
                return ApiStatus_DONE2;
            }
            playerState->unk_30.x = (playerState->goalPos.x - playerState->currentPos.x) / playerState->moveTime;
            playerState->unk_30.y = (playerState->goalPos.y - playerState->currentPos.y) / playerState->moveTime;
            playerState->unk_30.z = (playerState->goalPos.z - playerState->currentPos.z) / playerState->moveTime;
            playerState->velocity = (PI_S / 2);
            playerState->acceleration = (PI_S / 4) / (playerState->moveTime + 1);
            playerState->speed += temp / playerState->moveTime;
            set_animation(ACTOR_PLAYER, 0, playerState->animJumpLand);
            playerState->unk_24 = 90.0f;
            playerState->bounceDivisor = 45.0f;
            playerState->unk_28 = (360 / playerState->moveTime);
            if (playerState->moveArcAmplitude == 5) {
                playerState->bounceDivisor = 56.25f;
            }
            playerState->unk_18.x = 0.0f;
            playerState->unk_18.y = 0.0f;
            if (playerState->moveArcAmplitude == 1) {
                vel3 = playerState->velocity;
                acc3 = playerState->acceleration;
                playerState->velocity = (vel3 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * acc3) + acc3));
            } else {
                vel4 = playerState->velocity;
                acc4 = playerState->acceleration;
                playerState->velocity = (vel4 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.01 * acc4) + acc4));
            }
            playerState->currentPos.y = player->currentPos.y - playerState->bounceDivisor;
            script->functionTemp[0] = 11;
            break;
        case 20:
            playerState->moveTime = 1;
            playerState->unk_24 = 90.0f;
            playerState->bounceDivisor = (fabsf(playerState->unk_18.x - playerState->unk_18.y) / 16.5);
            playerState->unk_28 = (360 / playerState->moveTime);
            playerState->currentPos.x = player->currentPos.x;
            playerState->currentPos.y = player->currentPos.y;
            playerState->currentPos.z = player->currentPos.z;
            script->functionTemp[0] = 21;
            break;
    }

    switch (script->functionTemp[0]) {
        case 1:
            if (playerState->moveArcAmplitude == 0) {
                vel5 = playerState->velocity;
                acc5 = playerState->acceleration;
                playerState->velocity = (vel5 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * acc5) + acc5));
            } else {
                vel6 = playerState->velocity;
                acc6 = playerState->acceleration;
                playerState->velocity = (vel6 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.01 * acc6) + acc6));
            }
            playerState->currentPos.x += playerState->unk_30.x;
            playerState->currentPos.y += playerState->unk_30.y;
            playerState->currentPos.z += playerState->unk_30.z;
            playerState->unk_18.x = player->currentPos.y;
            player->currentPos.x = playerState->currentPos.x;
            player->currentPos.y = playerState->currentPos.y + (playerState->bounceDivisor * sin_rad(sin_rad(sin_rad(playerState->velocity) * (PI_S / 2)) * (PI_S / 2)));
            player->currentPos.z = playerState->currentPos.z;
            playerState->unk_18.y = player->currentPos.y;
            playerState->unk_24 += playerState->unk_28;
            playerState->unk_24 = clamp_angle(playerState->unk_24);
            playerState->moveTime--;
            if (playerState->moveTime == 0) {
                sfx_play_sound_at_position(SOUND_160, SOUND_SPACE_MODE_0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
                set_animation(ACTOR_PLAYER, 0, playerState->animJumpFall);
                player->rotationPivotOffset.y = 14;
                player->rotation.z -= 66.0f;
                playerState->moveTime = 7;
                script->functionTemp[0] = 2;
            }
            break;
        case 2:
            player->rotationPivotOffset.y = 14;
            player->rotation.z -= 66.0f;
            playerState->moveTime--;
            if (playerState->moveTime == 0) {
                player->rotation.z = 0.0f;
                player->rotationPivotOffset.y = 0;
                set_animation(ACTOR_PLAYER, 0, playerState->animJumpLand);
                return ApiStatus_DONE1;
            }
            break;
        case 11:
            playerState->currentPos.x += playerState->unk_30.x;
            playerState->currentPos.y += playerState->unk_30.y;
            playerState->currentPos.z += playerState->unk_30.z;
            playerState->unk_18.x = player->currentPos.y;
            player->currentPos.x = playerState->currentPos.x;
            player->currentPos.y = playerState->currentPos.y + (playerState->bounceDivisor * sin_rad(playerState->velocity));
            player->currentPos.z = playerState->currentPos.z;
            if (playerState->goalPos.y > player->currentPos.y) {
                player->currentPos.y = playerState->goalPos.y;
            }
            playerState->unk_18.y = player->currentPos.y;

            if (playerState->moveArcAmplitude == 1) {
                vel7 = playerState->velocity;
                acc7 = playerState->acceleration;
                playerState->velocity = (vel7 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * acc7) + acc7));
            } else {
                vel8 = playerState->velocity;
                acc8 = playerState->acceleration;
                playerState->velocity = (vel8 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.01 * acc8) + acc8));
            }

            playerState->unk_24 += playerState->unk_28;
            playerState->unk_24 = clamp_angle(playerState->unk_24);
            playerState->moveTime--;
            if (playerState->moveTime == 0) {
                player->currentPos.y = playerState->goalPos.y;
                set_animation(ACTOR_PLAYER, 0, 0x1000C);
                return ApiStatus_DONE1;
            }
            break;
        case 21:
            temp_f20 = playerState->currentPos.x;
            temp_f20 += (playerState->bounceDivisor * sin_rad(DEG_TO_RAD(playerState->unk_24))) / 33.0;
            playerState->currentPos.x = temp_f20;
            playerState->currentPos.y -= playerState->bounceDivisor * sin_rad(DEG_TO_RAD(playerState->unk_24));
            playerState->unk_24 += playerState->unk_28;
            playerState->unk_24 = clamp_angle(playerState->unk_24);
            player->currentPos.x = playerState->currentPos.x;
            player->currentPos.y = playerState->currentPos.y;
            player->currentPos.z = playerState->currentPos.z;
            if (gBattleStatus.flags1 & BS_FLAGS1_2000) {
                return ApiStatus_DONE2;
            }
            playerState->moveTime--;
            if (playerState->moveTime == 0) {
                return ApiStatus_DONE1;
            }
            break;
    }

    return ApiStatus_BLOCK;
}

ApiStatus func_80275F00(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* player = gBattleStatus.playerActor;
    ActorState* playerState = &player->state;
    f32 posX, posY, posZ;
    f32 goalX, goalZ;
    f32 speed;
    f32 temp;

    f64 temp_f20;
    f64 temp_f20_2;
    f64 temp_f20_4;
    f64 temp_f20_5;
    f64 temp_f20_6;
    f64 temp_f20_7;

    f64 temp_f22;
    f64 temp_f22_2;
    f64 temp_f22_3;
    f64 temp_f22_4;
    f64 temp_f22_5;
    f64 temp_f22_6;
    f64 temp_f22_7;

    if (isInitialCall) {
        player->state.moveTime = evt_get_variable(script, *args++);
        player->state.moveArcAmplitude = evt_get_variable(script, *args++);
        script->functionTemp[1] = 0;
        script->functionTemp[0] = 0;
        if (player->state.moveArcAmplitude == 1) {
            script->functionTemp[0] = 11;
        }
        if (player->state.moveArcAmplitude == 3) {
            script->functionTemp[0] = 20;
        }
        if (player->state.moveArcAmplitude == 2 || player->state.moveArcAmplitude == 4) {
            script->functionTemp[0] = 30;
        }
    }

    switch (script->functionTemp[0]) {
        case 0:
            playerState->currentPos.x = player->currentPos.x;
            playerState->currentPos.y = player->currentPos.y;
            playerState->currentPos.z = player->currentPos.z;
            goalX = playerState->goalPos.x;
            goalZ = playerState->goalPos.z;
            posX = playerState->currentPos.x;
            posY = playerState->currentPos.y;
            posZ = playerState->currentPos.z;
            playerState->angle = atan2(posX, posZ, goalX, goalZ);
            playerState->distance = dist2D(posX, posZ, goalX, goalZ);
            if (playerState->moveTime == 0) {
                playerState->moveTime = playerState->distance / playerState->speed;
                temp = playerState->distance - (playerState->moveTime * playerState->speed);
            } else {
                playerState->speed = playerState->distance / playerState->moveTime;
                temp = playerState->distance - (playerState->moveTime * playerState->speed);
            }
            playerState->acceleration = PI_S / playerState->moveTime;
            playerState->velocity = 0.0f;
            playerState->unk_30.x = (playerState->goalPos.x - playerState->currentPos.x) / playerState->moveTime;
            playerState->unk_30.y = (playerState->goalPos.y - playerState->currentPos.y) / playerState->moveTime;
            playerState->unk_30.z = (playerState->goalPos.z - playerState->currentPos.z) / playerState->moveTime;
            playerState->speed += temp / playerState->moveTime;
            set_animation(ACTOR_PLAYER, 0, playerState->animJumpFall);
            sfx_play_sound_at_position(SOUND_160, SOUND_SPACE_MODE_0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
            sfx_play_sound_at_position(SOUND_TORNADO_JUMP, SOUND_SPACE_MODE_0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
            playerState->unk_18.x = 0.0f;
            playerState->unk_18.y = 0.0f;
            playerState->unk_24 = 90.0f;

            temp = playerState->distance;
            temp -= 20.0;
            temp /= 6.0;
            temp += 47.0;
            playerState->bounceDivisor = temp;

            temp_f20 = playerState->velocity;
            temp_f22 = playerState->acceleration;
            playerState->unk_28 = 360 / playerState->moveTime;
            playerState->velocity = temp_f20 + (((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53) * temp_f22) + temp_f22);
            script->functionTemp[0] = 1;
            break;
        case 10:
            playerState->currentPos.x = player->currentPos.x;
            playerState->currentPos.y = player->currentPos.y;
            playerState->currentPos.z = player->currentPos.z;
            goalX = playerState->goalPos.x;
            goalZ = playerState->goalPos.z;
            posX = playerState->currentPos.x;
            posY = playerState->currentPos.y;
            posZ = playerState->currentPos.z;
            playerState->angle = atan2(posX, posZ, goalX, goalZ);
            playerState->distance = dist2D(posX, posZ, goalX, goalZ);
            if (playerState->moveTime == 0) {
                playerState->moveTime = playerState->distance / playerState->speed;
                temp = playerState->distance - (playerState->moveTime * playerState->speed);
            } else {
                speed = playerState->distance / playerState->moveTime;
                playerState->speed = speed;
                temp = playerState->distance - (playerState->moveTime * speed);
            }
            playerState->acceleration = PI_S / playerState->moveTime;
            playerState->velocity = 0.0f;
            playerState->unk_30.x = (playerState->goalPos.x - playerState->currentPos.x) / playerState->moveTime;
            playerState->unk_30.y = (playerState->goalPos.y - playerState->currentPos.y) / playerState->moveTime;
            playerState->unk_30.z = (playerState->goalPos.z - playerState->currentPos.z) / playerState->moveTime;
            playerState->speed += temp / playerState->moveTime;
            set_animation(ACTOR_PLAYER, 0, playerState->animJumpRise);
            sfx_play_sound_at_position(SOUND_160, SOUND_SPACE_MODE_0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
            sfx_play_sound_at_position(SOUND_TORNADO_JUMP, SOUND_SPACE_MODE_0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
            playerState->unk_18.x = 0.0f;
            playerState->unk_18.y = 0.0f;
            playerState->unk_24 = 90.0f;
            temp_f20_2 = playerState->velocity;
            temp_f22_2 = playerState->acceleration;

            temp = playerState->distance;
            temp -= 20.0;
            temp /= 6.0;
            temp += 47.0;
            playerState->bounceDivisor = temp;

            playerState->unk_28 = 360 / playerState->moveTime;
            playerState->velocity = temp_f20_2 + (((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53) * temp_f22_2) + temp_f22_2);
            script->functionTemp[0] = 11;
            break;
        case 20:
            playerState->moveTime = 1;
            set_animation(ACTOR_PLAYER, 1, 0x1000C);
            player->rotation.y = 0.0f;
            playerState->unk_24 = 90.0f;
            playerState->bounceDivisor = fabsf(playerState->unk_18.x - playerState->unk_18.y) / 16.5;
            playerState->unk_28 = 360 / playerState->moveTime;
            playerState->currentPos.x = player->currentPos.x;
            playerState->currentPos.y = player->currentPos.y;
            playerState->currentPos.z = player->currentPos.z;
            script->functionTemp[0] = 21;
            break;
        case 30:
            playerState->currentPos.x = player->currentPos.x;
            playerState->currentPos.y = player->currentPos.y;
            playerState->currentPos.z = player->currentPos.z;
            goalX = playerState->goalPos.x;
            goalZ = playerState->goalPos.z;
            posX = playerState->currentPos.x;
            posY = playerState->currentPos.y;
            posZ = playerState->currentPos.z;
            playerState->angle = atan2(posX, posZ, goalX, goalZ);
            playerState->distance = dist2D(posX, posZ, goalX, goalZ);
            if (playerState->moveTime == 0) {
                playerState->moveTime = playerState->distance / playerState->speed;
                temp = playerState->distance - (playerState->moveTime * playerState->speed);
            } else {
                playerState->speed = playerState->distance / playerState->moveTime;
                temp = playerState->distance - (playerState->moveTime * playerState->speed);
            }
            playerState->acceleration = PI_S / (playerState->moveTime + 1);
            playerState->velocity = 0.0f;
            playerState->unk_30.x = (playerState->goalPos.x - playerState->currentPos.x) / playerState->moveTime;
            playerState->unk_30.y = (playerState->goalPos.y - playerState->currentPos.y) / playerState->moveTime;
            playerState->unk_30.z = (playerState->goalPos.z - playerState->currentPos.z) / playerState->moveTime;
            playerState->speed += temp / playerState->moveTime;
            set_animation(ACTOR_PLAYER, 0, playerState->animJumpRise);
            sfx_play_sound_at_position(SOUND_160, SOUND_SPACE_MODE_0, player->currentPos.x, player->currentPos.y, player->currentPos.z);
            playerState->unk_24 = 90.0f;
            playerState->bounceDivisor = 45.0f;
            playerState->unk_28 = 360 / playerState->moveTime;
            if (playerState->moveArcAmplitude == 4) {
                playerState->bounceDivisor = 56.25f;
            }
            playerState->unk_18.x = 0.0f;
            playerState->unk_18.y = 0.0f;
            temp_f22_3 = playerState->acceleration;
            temp_f22_7 = playerState->velocity;
            temp_f22_7 = temp_f22_7 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * temp_f22_3) + temp_f22_3);
            playerState->velocity = temp_f22_7;
            script->functionTemp[0] = 31;
            break;
    }

    switch (script->functionTemp[0]) {
        case 1:
            temp_f22_4 = playerState->velocity;
            temp_f20_4 = playerState->acceleration;
            playerState->velocity = temp_f22_4 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * temp_f20_4) + temp_f20_4);
            playerState->currentPos.x += playerState->unk_30.x;
            playerState->currentPos.y += playerState->unk_30.y;
            playerState->currentPos.z += playerState->unk_30.z;
            playerState->unk_18.x = player->currentPos.y;
            player->currentPos.x = playerState->currentPos.x;
            player->currentPos.y = playerState->currentPos.y + (playerState->bounceDivisor * sin_rad(playerState->velocity));
            player->currentPos.z = playerState->currentPos.z;
            playerState->unk_18.y = player->currentPos.y;
            playerState->unk_24 += playerState->unk_28;
            playerState->unk_24 = clamp_angle(playerState->unk_24);
            player->rotation.y += 133.0f;
            player->rotation.y = clamp_angle(player->rotation.y);
            if (gBattleStatus.flags1 & BS_FLAGS1_2000) {
                return ApiStatus_DONE2;
            }
            playerState->moveTime--;
            if (playerState->moveTime == 4) {
                return ApiStatus_DONE1;
            }
            break;
        case 11:
            temp_f22_6 = playerState->velocity;
            temp_f20_7 = playerState->acceleration;
            playerState->velocity = temp_f22_6 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * temp_f20_7) + temp_f20_7);
            playerState->currentPos.x += playerState->unk_30.x;
            playerState->currentPos.y += playerState->unk_30.y;
            playerState->currentPos.z += playerState->unk_30.z;
            playerState->unk_18.x = player->currentPos.y;
            player->currentPos.x = playerState->currentPos.x;
            player->currentPos.y = playerState->currentPos.y + (playerState->bounceDivisor * sin_rad(playerState->velocity));
            player->currentPos.z = playerState->currentPos.z;
            if (playerState->goalPos.y > player->currentPos.y && playerState->moveTime < 3) {
                player->currentPos.y = playerState->goalPos.y;
            }
            playerState->unk_18.y = player->currentPos.y;
            playerState->unk_24 += playerState->unk_28;
            playerState->unk_24 = clamp_angle(playerState->unk_24);
            set_animation(ACTOR_PLAYER, 0, playerState->animJumpFall);
            player->rotation.y += 133.0f;
            player->rotation.y = clamp_angle(player->rotation.y);
            playerState->moveTime--;
            if (playerState->moveTime == 0) {
                playerState->acceleration = 1.8f;
                playerState->velocity = -(playerState->unk_18.x - playerState->unk_18.y);
                player->currentPos.y = playerState->goalPos.y;
                player->rotation.y = 0.0f;
                set_animation(ACTOR_PLAYER, 0, playerState->animJumpLand);
                play_movement_dust_effects(2, player->currentPos.x, player->currentPos.y, player->currentPos.z, player->yaw);
                return ApiStatus_DONE1;
            }
            break;
        case 21:
            temp_f20_5 = playerState->currentPos.x;
            temp_f20_5 += (playerState->bounceDivisor * sin_rad(DEG_TO_RAD(playerState->unk_24))) / 33.0;
            playerState->currentPos.x = temp_f20_5;
            playerState->currentPos.y -= playerState->bounceDivisor * sin_rad(DEG_TO_RAD(playerState->unk_24));
            playerState->unk_24 += playerState->unk_28;
            playerState->unk_24 = clamp_angle(playerState->unk_24);
            player->currentPos.x = playerState->currentPos.x;
            player->currentPos.y = playerState->currentPos.y;
            player->currentPos.z = playerState->currentPos.z;
            if (gBattleStatus.flags1 & BS_FLAGS1_2000) {
               return ApiStatus_DONE2;
            }
            playerState->moveTime--;
            if (playerState->moveTime == 0) {
                return ApiStatus_DONE1;
            }
            break;
        case 31:
            temp_f22_5 = playerState->velocity;
            temp_f20_6 = playerState->acceleration;
            playerState->velocity = temp_f22_5 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * temp_f20_6) + temp_f20_6);
            playerState->currentPos.x += playerState->unk_30.x;
            playerState->currentPos.y += playerState->unk_30.y;
            playerState->currentPos.z += playerState->unk_30.z;
            playerState->unk_18.x = player->currentPos.y;
            player->currentPos.x = playerState->currentPos.x;
            player->currentPos.y = playerState->currentPos.y + (playerState->bounceDivisor * sin_rad(playerState->velocity));
            player->currentPos.z = playerState->currentPos.z;
            if (playerState->goalPos.y > player->currentPos.y && playerState->moveTime < 3) {
                player->currentPos.y = playerState->goalPos.y;
            }
            playerState->unk_18.y = player->currentPos.y;
            playerState->unk_24 += playerState->unk_28;
            playerState->unk_24 = clamp_angle(playerState->unk_24);
            set_animation(ACTOR_PLAYER, 0, playerState->animJumpFall);
            player->rotation.y += 133.0f;
            player->rotation.y = clamp_angle(player->rotation.y);
            playerState->moveTime--;
            if (playerState->moveTime == 0) {
                player->currentPos.y = playerState->goalPos.y;
                player->rotation.y = 0.0f;
                set_animation(ACTOR_PLAYER, 0, playerState->animJumpLand);
                playerState->acceleration = 1.8f;
                playerState->velocity = -(playerState->unk_18.x - playerState->unk_18.y);
                return ApiStatus_DONE1;
            }
            break;
    }

    return ApiStatus_BLOCK;
}

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
