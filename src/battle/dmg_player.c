#include "common.h"
#include "effects.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "sprite/player.h"

b32 dispatch_damage_event_player(s32 damageAmount, s32 event, b32 noHitSound);
b32 dispatch_hazard_event_player(s32 damageAmount, s32 event);

ApiStatus PlaySleepHitFX(Evt* script, s32 isInitialCall) {
    fx_debuff(0, script->varTable[0], script->varTable[1], script->varTable[2]);
    return ApiStatus_DONE2;
}

ApiStatus PlayDizzyHitFX(Evt* script, s32 isInitialCall) {
    fx_debuff(1, script->varTable[0], script->varTable[1], script->varTable[2]);
    return ApiStatus_DONE2;
}

ApiStatus PlayParalyzeHitFX(Evt* script, s32 isInitialCall) {
    EffectInstance* debuffEffect = fx_debuff(2, script->varTable[0], script->varTable[1], script->varTable[2]);

    debuffEffect->data.debuff->primCol.r = 200;
    debuffEffect->data.debuff->primCol.g = 120;
    debuffEffect->data.debuff->primCol.b = 0;
    debuffEffect->data.debuff->envCol.r = 234;
    debuffEffect->data.debuff->envCol.g = 193;
    debuffEffect->data.debuff->envCol.b = 0;
    return ApiStatus_DONE2;
}

ApiStatus PlayPoisonHitFX(Evt* script, s32 isInitialCall) {
    EffectInstance* debuffEffect = fx_debuff(2, script->varTable[0], script->varTable[1], script->varTable[2]);

    debuffEffect->data.debuff->primCol.r = 60;
    debuffEffect->data.debuff->primCol.g = 160;
    debuffEffect->data.debuff->primCol.b = 0;
    debuffEffect->data.debuff->envCol.r = 90;
    debuffEffect->data.debuff->envCol.g = 240;
    debuffEffect->data.debuff->envCol.b = 0;
    return ApiStatus_DONE2;
}

ApiStatus PlayStopHitFX(Evt* script, s32 isInitialCall) {
    EffectInstance* debuffEffect = fx_debuff(2, script->varTable[0], script->varTable[1], script->varTable[2]);

    debuffEffect->data.debuff->primCol.r = 205;
    debuffEffect->data.debuff->primCol.g = 0;
    debuffEffect->data.debuff->primCol.b = 40;
    debuffEffect->data.debuff->envCol.r = 205;
    debuffEffect->data.debuff->envCol.g = 32;
    debuffEffect->data.debuff->envCol.b = 242;
    return ApiStatus_DONE2;
}

ApiStatus PlayFreezeHitSnowflakeFX(Evt* script, s32 isInitialCall) {
    fx_big_snowflakes(0, script->varTable[0], script->varTable[1], script->varTable[2]);
    return ApiStatus_DONE2;
}

ApiStatus PlayFreezeHitParticleFX(Evt* script, s32 isInitialCall) {
    Actor* actor = (Actor*)script->varTable[3];
    f32 temp1 = actor->size.y;
    f32 temp2 = actor->size.x / 2;

    fx_misc_particles(0, script->varTable[0], script->varTable[1], script->varTable[2], temp1, temp2, 1.0f, 10, 30);
    fx_misc_particles(1, script->varTable[0], script->varTable[1], script->varTable[2], temp1, temp2, 1.0f, 10, 30);
    return ApiStatus_DONE2;
}

ApiStatus PlayShrinkHitFX(Evt* script, s32 isInitialCall) {
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

EvtScript EVS_PlaySleepHitFX = {
    EVT_CALL(PlaySleepHitFX)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_PlayDizzyHitFX = {
    EVT_CALL(PlayDizzyHitFX)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_PlayParalyzeHitFX = {
    EVT_CALL(PlayParalyzeHitFX)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_PlayPoisonHitFX = {
    EVT_CALL(PlayPoisonHitFX)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_PlayStopHitFX = {
    EVT_CALL(PlayStopHitFX)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_PlayFreezeHitFX = {
    EVT_CALL(PlayFreezeHitSnowflakeFX)
    EVT_WAIT(8)
    EVT_CALL(PlayFreezeHitSnowflakeFX)
    EVT_WAIT(15)
    EVT_CALL(PlayFreezeHitParticleFX)
    EVT_RETURN
    EVT_END
};

EvtScript EVS_PlayShrinkHitFX = {
    EVT_CALL(PlayShrinkHitFX)
    EVT_RETURN
    EVT_END
};

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
    s32 targetActorID = battleStatus->curTargetID;
    s32 targetPartIdx = battleStatus->curTargetPart;
    Actor* target;
    ActorPart* targetPart;

    battleStatus->curTargetID2 = battleStatus->curTargetID;
    battleStatus->curTargetPart2 = battleStatus->curTargetPart;

    target = get_actor(targetActorID);
    if (target == NULL) {
        return HIT_RESULT_HIT;
    }

    targetPart = get_actor_part(target, targetPartIdx);
    ASSERT(targetPart != NULL);

    if (targetPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
        return HIT_RESULT_MISS;
    }

    if (target->transparentStatus == STATUS_KEY_TRANSPARENT
        || (targetPart->eventFlags & ACTOR_EVENT_FLAG_BURIED && !(battleStatus->curAttackElement & DAMAGE_TYPE_QUAKE))
    ) {
        return HIT_RESULT_MISS;
    }

    if (target->stoneStatus == STATUS_KEY_STONE) {
        sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        return HIT_RESULT_IMMUNE;
    }

    if ((battleStatus->curAttackElement & DAMAGE_TYPE_JUMP)
        && (targetPart->eventFlags & ACTOR_EVENT_FLAG_SPIKY_TOP)
        && !player_team_is_ability_active(player, ABILITY_SPIKE_SHIELD))
    {
        sfx_play_sound_at_position(SOUND_HIT_SPIKE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        return HIT_RESULT_LANDED_ON_SPIKE;
    }

    if (!(battleStatus->curAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_JUMP))
        && (targetPart->eventFlags & ACTOR_EVENT_FLAG_SPIKY_FRONT)
        && (!(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_SPIKY_FRONT)
        && !player_team_is_ability_active(player, ABILITY_SPIKE_SHIELD)))
    {
        sfx_play_sound_at_position(SOUND_HIT_SPIKE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        dispatch_hazard_event_player(1, EVENT_SPIKE_CONTACT);
        dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
        return HIT_RESULT_BACKFIRE;
    }

    if (player->staticStatus != STATUS_KEY_STATIC && target->staticStatus == STATUS_KEY_STATIC) {
        return HIT_RESULT_HIT_STATIC;
    }

    return HIT_RESULT_HIT;
}

HitResult calc_player_damage_enemy(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 currentTargetID = battleStatus->curTargetID;
    s32 currentTargetPartID = battleStatus->curTargetPart;
    ActorState* state;
    Evt* evt;
    Actor* target;
    ActorPart* targetPart;
    s32 hitResult;
    s32 currentAttackDamage;
    s32 targetDefense;
    s32 dispatchEvent;
    s32 partImmuneToElement;
    s32 canBeShocked;
    s32 missedAllOrNothing;
    s32 isFireDamage;
    s32 isShockDamage;
    s32 isWaterDamage;
    s32 isIceDamage;
    s32 wasSpecialHit;
    s32 wasStatusInflicted;
    s32 attackFxType;

    canBeShocked = FALSE;
    isFireDamage = FALSE;
    isWaterDamage = FALSE;
    isShockDamage = FALSE;
    isIceDamage = FALSE;
    wasSpecialHit = FALSE;
    partImmuneToElement = FALSE;
    wasStatusInflicted = FALSE;
    missedAllOrNothing = FALSE;

    battleStatus->wasStatusInflicted = FALSE;
    battleStatus->lastAttackDamage = 0;
    battleStatus->attackerActorID = player->actorID;
    battleStatus->curTargetID2 = battleStatus->curTargetID;
    battleStatus->curTargetPart2 = battleStatus->curTargetPart;
    target = get_actor(currentTargetID);
    state = &player->state;

    if (target == NULL) {
        return HIT_RESULT_HIT;
    }

    targetPart = get_actor_part(target, currentTargetPartID);

    ASSERT(targetPart != NULL);

    target->lastDamageTaken = 0;

    if (gBattleStatus.flags1 & BS_FLAGS1_FORCE_IMMUNE_HIT) {
        hitResult = HIT_RESULT_NO_DAMAGE;
        dispatchEvent = EVENT_ZERO_DAMAGE;
    } else {
        if (player_team_is_ability_active(player, ABILITY_ICE_POWER)) {
            if (!(battleStatus->curAttackElement & DAMAGE_TYPE_NO_CONTACT)) {
                battleStatus->curAttackElement |= DAMAGE_TYPE_ICE;
            }
        }

        if (targetPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY
            || target->transparentStatus == STATUS_KEY_TRANSPARENT
            || (targetPart->eventFlags & ACTOR_EVENT_FLAG_BURIED && !(battleStatus->curAttackElement & DAMAGE_TYPE_QUAKE))
        ) {
            return HIT_RESULT_MISS;
        }

        if (target->stoneStatus == STATUS_KEY_STONE) {
            sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            show_immune_bonk(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, 1);
            show_next_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 0);
            if (gBattleStatus.flags1 & (BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)) {
                return HIT_RESULT_NICE;
            } else {
                return HIT_RESULT_HIT;
            }
        }

        if (targetPart->elementalImmunities & battleStatus->curAttackElement) {
            partImmuneToElement = TRUE;
        }

        // check jumping on spiky enemy
        if ((battleStatus->curAttackElement & DAMAGE_TYPE_JUMP)
            && (targetPart->eventFlags & ACTOR_EVENT_FLAG_SPIKY_TOP)
            && !player_team_is_ability_active(player, ABILITY_SPIKE_SHIELD))
        {
            sfx_play_sound_at_position(SOUND_HIT_SPIKE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_hazard_event_player(1, EVENT_SPIKE_CONTACT);
            dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
            return HIT_RESULT_BACKFIRE;
        }

        // check touching fiery enemy and explode on contact
        if (!(battleStatus->curAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_SMASH))) {
            if (targetPart->eventFlags & ACTOR_EVENT_FLAG_EXPLODE_ON_CONTACT) {
                sfx_play_sound_at_position(SOUND_HIT_PLAYER_FIRE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                dispatch_hazard_event_player(1, EVENT_BURN_CONTACT);
                dispatch_event_actor(target, EVENT_EXPLODE_TRIGGER);
                return HIT_RESULT_BACKFIRE;
            }

            if (targetPart->eventFlags & ACTOR_EVENT_FLAG_FIREY
                && !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_BURN_CONTACT)
                && !(player_team_is_ability_active(player, ABILITY_FIRE_SHIELD))
                && !(player_team_is_ability_active(player, ABILITY_ICE_POWER))
            ) {
                sfx_play_sound_at_position(SOUND_HIT_PLAYER_FIRE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                dispatch_hazard_event_player(1, EVENT_BURN_CONTACT);
                dispatch_event_actor(target, EVENT_BURN_TAUNT);
                return HIT_RESULT_BACKFIRE;
            }
        }

        // check explode on ignition
        if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS
            && battleStatus->curAttackElement & DAMAGE_TYPE_FIRE
            && targetPart->eventFlags & (ACTOR_EVENT_FLAG_FIRE_EXPLODE | ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION)
        ) {
            sfx_play_sound_at_position(SOUND_HIT_PLAYER_FIRE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_event_actor(target, EVENT_EXPLODE_TRIGGER);
            if (gBattleStatus.flags1 & (BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)) {
                return HIT_RESULT_NICE;
            } else {
                return HIT_RESULT_HIT;
            }
        }

        // unknown alternate spiky #1
        if (!(battleStatus->curAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_SMASH))
            && targetPart->eventFlags & ACTOR_EVENT_FLAG_ALT_SPIKY
            && !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_ALT_SPIKY)
            && !player_team_is_ability_active(player, ABILITY_SPIKE_SHIELD)
        ) {
            sfx_play_sound_at_position(SOUND_HIT_SPIKE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_hazard_event_player(1, EVENT_SPIKE_CONTACT);
            dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
            return HIT_RESULT_BACKFIRE;
        }

        if (battleStatus->curAttackElement & DAMAGE_TYPE_FIRE) {
            fx_ring_blast(0, state->goalPos.x, state->goalPos.y, state->goalPos.z * 5.0f, 1.0f, 24);
            isFireDamage = TRUE;
        }

        if (battleStatus->curAttackElement & DAMAGE_TYPE_SHOCK) {
            apply_shock_effect(target);
            isShockDamage = TRUE;
        }

        if (battleStatus->curAttackElement & DAMAGE_TYPE_WATER) {
            fx_water_splash(0, state->goalPos.x, state->goalPos.y, state->goalPos.z + 5.0f, 1.0f, 24);
            isWaterDamage = TRUE;
        }

        if (battleStatus->curAttackElement & DAMAGE_TYPE_ICE) {
            fx_big_snowflakes(0, state->goalPos.x, state->goalPos.y, state->goalPos.z + 5.0f);
            isIceDamage = TRUE;
        }

        attackFxType = player_team_is_ability_active(player, ABILITY_ATTACK_FX);

        if (attackFxType) {
            fx_breaking_junk(0, state->goalPos.x, state->goalPos.y, state->goalPos.z + 5.0f, 1.0f, 30);

            switch (attackFxType) {
                case 1:
                    sfx_play_sound_at_position(SOUND_LIFE_SHROOM_CHIME, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    break;
                case 2:
                    sfx_play_sound_at_position(SOUND_PLANTS_BELL, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    break;
                case 3:
                    sfx_play_sound_at_position(SOUND_SLIDE_WHISTLE_OUT, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    break;
                case 4:
                    sfx_play_sound_at_position(SOUND_YOSHI, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    break;
                case 5:
                    sfx_play_sound_at_position(SOUND_HIT_WHACKA, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    break;
                case 6:
                    sfx_play_sound_at_position(SOUND_FLOWERS_LAUGH, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    break;
            }
        }

        if (!is_ability_active(ABILITY_ZAP_TAP)
            && player->staticStatus != STATUS_KEY_STATIC
            && (target->staticStatus == STATUS_KEY_STATIC || targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED)
            && !(battleStatus->curAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_SHOCK))
            && !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_SHOCK_CONTACT)
        ) {
            gBattleStatus.flags1 |= BS_FLAGS1_TRIGGER_EVENTS;
            canBeShocked = TRUE;
        }

        if (targetPart->eventFlags & (ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED | ACTOR_EVENT_FLAG_ENCHANTED)) {
            battleStatus->curAttackElement &= ~DAMAGE_TYPE_IGNORE_DEFENSE;
        }

        targetDefense = get_defense(target, targetPart->defenseTable, battleStatus->curAttackElement);

        if (!(battleStatus->curAttackElement & DAMAGE_TYPE_IGNORE_DEFENSE)) {
            targetDefense += target->defenseBoost;
        }

        if (targetPart->eventFlags & ACTOR_EVENT_FLAG_EXTREME_DEFENSE) {
            targetDefense += 127;
        }

        currentAttackDamage = battleStatus->curAttackDamage;
        currentAttackDamage += count_power_plus(battleStatus->curAttackElement);

        if (battleStatus->merleeAttackBoost > 0
            && (gBattleStatus.flags1 & BS_FLAGS1_INCLUDE_POWER_UPS || battleStatus->curAttackElement & DAMAGE_TYPE_JUMP)
        ) {
            currentAttackDamage += battleStatus->merleeAttackBoost;
        }

        if (battleStatus->jumpCharge && battleStatus->curAttackElement & DAMAGE_TYPE_JUMP) {
            currentAttackDamage += battleStatus->jumpCharge;
            gBattleStatus.flags1 &= ~BS_FLAGS1_JUMP_CHARGED;
        }

        if (battleStatus->hammerCharge && battleStatus->curAttackElement & (DAMAGE_TYPE_QUAKE_HAMMER | DAMAGE_TYPE_THROW | DAMAGE_TYPE_SMASH)) {
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

        if (gBattleStatus.flags2 & BS_FLAGS2_HAS_RUSH
            && (gBattleStatus.flags1 & BS_FLAGS1_INCLUDE_POWER_UPS || battleStatus->curAttackElement & DAMAGE_TYPE_JUMP)
        ) {
            if (battleStatus->rushFlags & RUSH_FLAG_POWER) {
                currentAttackDamage += 2;
            }

            if (battleStatus->rushFlags & RUSH_FLAG_MEGA) {
                currentAttackDamage += 4;
            }
            fx_radial_shimmer(9, state->goalPos.x, state->goalPos.y, state->goalPos.z, 0.5f, 20);
        }

        if (!(gBattleStatus.flags2 & BS_FLAGS2_IS_FIRST_STRIKE)
            && player_team_is_ability_active(player, ABILITY_ALL_OR_NOTHING)
        ) {
            currentAttackDamage++;

            if (!(gBattleStatus.flags1 & (BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT))) {
                missedAllOrNothing = TRUE;
                currentAttackDamage = 0;
                targetDefense = 0;
                gBattleStatus.flags1 &= ~BS_FLAGS1_NICE_HIT;
                gBattleStatus.flags1 &= ~BS_FLAGS1_SUPER_HIT;
                gBattleStatus.flags1 &= ~BS_FLAGS1_INCLUDE_POWER_UPS;
                gBattleStatus.flags1 |= BS_FLAGS1_TRIGGER_EVENTS;
            }
        }

        if (player->debuff == STATUS_KEY_SHRINK) {
            if (currentAttackDamage > 0) {
                currentAttackDamage /= 2;

                if (currentAttackDamage == 0) {
                    currentAttackDamage = 1;
                }
            }
        }

        if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS
            && battleStatus->curAttackElement & DAMAGE_TYPE_BLAST
            && targetPart->eventFlags & ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION
        ) {
            targetDefense = 0;
            currentAttackDamage = target->curHP;
        }

        if (battleStatus->curAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS) {
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

        if (battleStatus->curAttackElement & DAMAGE_TYPE_POWER_BOUNCE && currentAttackDamage > 0) {
            currentAttackDamage += battleStatus->powerBounceCounter;

            if (currentAttackDamage < 1) {
                currentAttackDamage = 1;
            }
        }

        battleStatus->lastAttackDamage = 0;

        if (currentAttackDamage < 1) {
            target->hpChangeCounter = 0;
            hitResult = HIT_RESULT_NO_DAMAGE;

            if (!(battleStatus->curAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS)) {
                dispatchEvent = EVENT_ZERO_DAMAGE;
                sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            } else {
                if (target->curHP < 1) {
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

            if (!(targetPart->flags & ACTOR_PART_FLAG_DAMAGE_IMMUNE)
                && !(gBattleStatus.flags1 & BS_FLAGS1_TUTORIAL_BATTLE)
                && !partImmuneToElement
                && !(targetPart->targetFlags & ACTOR_PART_TARGET_NO_DAMAGE)
            ) {
                target->curHP -= currentAttackDamage;

                if (target->curHP < 1) {
                    target->curHP = 0;
                    dispatchEvent = EVENT_DEATH;
                }
            }

            battleStatus->lastAttackDamage += currentAttackDamage;
            target->lastDamageTaken = battleStatus->lastAttackDamage;
            target->hpChangeCounter = 0;
        }

        if (targetPart->flags & ACTOR_PART_FLAG_DAMAGE_IMMUNE) {
            if (!is_ability_active(ABILITY_ZAP_TAP)
                && player->staticStatus != STATUS_KEY_STATIC
                && (target->staticStatus == STATUS_KEY_STATIC || (targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED))
                && !(battleStatus->curAttackElement & DAMAGE_TYPE_NO_CONTACT)
                && !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_SHOCK_CONTACT)
                && !(battleStatus->curAttackElement & DAMAGE_TYPE_SHOCK)
            ) {
                sfx_play_sound_at_position(SOUND_HIT_PLAYER_SHOCK, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                apply_shock_effect(player);
                dispatch_hazard_event_player(1, EVENT_SHOCK_HIT);
                return HIT_RESULT_BACKFIRE;
            } else {
                if (!(gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS)) {
                    dispatchEvent = EVENT_ZERO_DAMAGE;
                } else {
                    dispatchEvent = EVENT_IMMUNE;
                }
                sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                dispatch_event_actor(target, dispatchEvent);
                show_immune_bonk(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, 3);
                if (gBattleStatus.flags1 & (BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)) {
                    return HIT_RESULT_NICE;
                } else {
                    return HIT_RESULT_HIT;
                }
            }
        }

        if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) {
            if (battleStatus->curAttackElement & DAMAGE_TYPE_FEAR
                && rand_int(99) < (target->actorBlueprint->escapeChance * battleStatus->statusChance) / 100
                && (target->debuff != STATUS_KEY_FEAR
                    && target->debuff != STATUS_KEY_DIZZY
                    && target->debuff != STATUS_KEY_PARALYZE
                    && target->debuff != STATUS_KEY_SLEEP
                    && target->debuff != STATUS_KEY_FROZEN
                    && target->debuff != STATUS_KEY_STOP)
                && !(target->flags & ACTOR_FLAG_FLIPPED)
            ) {
                dispatch_event_actor(target, EVENT_SCARE_AWAY);
                if (gBattleStatus.flags1 & (BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)) {
                    return HIT_RESULT_NICE;
                } else {
                    return HIT_RESULT_HIT;
                }
            }
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) {
        if (dispatchEvent == EVENT_HIT_COMBO) {
            dispatchEvent = EVENT_HIT;
        }

        if (dispatchEvent == EVENT_ZERO_DAMAGE) {
            dispatchEvent = EVENT_IMMUNE;
        }

        if (target->curHP < 1) {
            if (dispatchEvent == EVENT_IMMUNE) {
                dispatchEvent = EVENT_DEATH;
            }
        }
    } else if (dispatchEvent == EVENT_DEATH) {
        dispatchEvent = EVENT_HIT_COMBO;
    }

    if (!(gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS)) {
        clear_part_pal_adjustment(targetPart);
    }

    // check for special case damage events
    if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) {
        // if damage is from Spin Smash, convert generic events to Spin Smash specific events
        if (battleStatus->curAttackElement & DAMAGE_TYPE_SPIN_SMASH) {
            PlayerData* playerData = &gPlayerData;

            if (target->actorBlueprint->spinSmashReq != 255
                && playerData->hammerLevel + 1 >= target->actorBlueprint->spinSmashReq
                && battleStatus->lastAttackDamage > 0
                && gBattleStatus.flags1 & BS_FLAGS1_NICE_HIT
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

        // if damage is from Power Bounce, convert generic events to Power Bounce specific events
        if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS
            && !(battleStatus->curAttackElement & DAMAGE_TYPE_NO_CONTACT)
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

        // try generating fall trigger events
        if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS
            && (battleStatus->curAttackElement & (DAMAGE_TYPE_POW | DAMAGE_TYPE_JUMP))
            && targetPart->eventFlags & ACTOR_EVENT_FLAG_GROUNDABLE
        ) {
            if (dispatchEvent == EVENT_HIT) {
                dispatchEvent = EVENT_FALL_TRIGGER;
            }

            if (dispatchEvent == EVENT_IMMUNE) {
                dispatchEvent = EVENT_FALL_TRIGGER;
            }

            wasSpecialHit = TRUE;
        }

        // try generating flip trigger events
        if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS
            && (battleStatus->curAttackElement & (DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_POW | DAMAGE_TYPE_JUMP))
            && targetPart->eventFlags & ACTOR_EVENT_FLAG_FLIPABLE
        ) {
            if (dispatchEvent == EVENT_HIT) {
                dispatchEvent = EVENT_FLIP_TRIGGER;
            }

            if (dispatchEvent == EVENT_IMMUNE) {
                dispatchEvent = EVENT_FLIP_TRIGGER;
            }

            if (!(target->flags & ACTOR_FLAG_FLIPPED)) {
                wasSpecialHit = TRUE;
            }
        }
    }

    // try generating flip trigger events
    if (!(gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS)
        && battleStatus->curAttackElement & (DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_POW | DAMAGE_TYPE_JUMP)
        && targetPart->eventFlags & ACTOR_EVENT_FLAG_FLIPABLE
    ) {
        if (dispatchEvent == EVENT_HIT_COMBO) {
            dispatchEvent = EVENT_FLIP_TRIGGER;
        }

        if (dispatchEvent == EVENT_ZERO_DAMAGE) {
            dispatchEvent = EVENT_FLIP_TRIGGER;
        }

        if (!(target->flags & ACTOR_FLAG_FLIPPED)) {
            wasSpecialHit = TRUE;
        }
    }

    // try generating shell crack events
    if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS
        && battleStatus->curAttackElement & DAMAGE_TYPE_SHELL_CRACK
        && targetPart->eventFlags & ACTOR_EVENT_FLAG_FLIPABLE
    ) {
        if (dispatchEvent == EVENT_HIT) {
            dispatchEvent = EVENT_SHELL_CRACK_HIT;
        }

        if (dispatchEvent == EVENT_IMMUNE) {
            dispatchEvent = EVENT_SHELL_CRACK_HIT;
        }
        wasSpecialHit = TRUE;
    }

    // try generating burn events
    if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS
        && (battleStatus->curAttackElement & (DAMAGE_TYPE_BLAST | DAMAGE_TYPE_FIRE))
    ) {
        if (dispatchEvent == EVENT_HIT) {
            dispatchEvent = EVENT_BURN_HIT;
        }

        if (dispatchEvent == EVENT_DEATH) {
            dispatchEvent = EVENT_BURN_DEATH;
        }

        isFireDamage = TRUE;
    }

    // try inflicting status effects
    do {        // TODO remove this do while
        if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS
            && battleStatus->lastAttackDamage >= 0
            && dispatchEvent != EVENT_DEATH
            && dispatchEvent != EVENT_SPIN_SMASH_DEATH
            && dispatchEvent != EVENT_EXPLODE_TRIGGER
            && !(targetPart->targetFlags & ACTOR_PART_TARGET_NO_DAMAGE)
        ) {
            #define INFLICT_STATUS(STATUS_TYPE) \
                if ((battleStatus->curAttackStatus & STATUS_FLAG_##STATUS_TYPE) && \
                    try_inflict_status(target, STATUS_KEY_##STATUS_TYPE, STATUS_TURN_MOD_##STATUS_TYPE)) { \
                    wasSpecialHit = TRUE; \
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
            if (!wasSpecialHit && !wasStatusInflicted) {
                show_immune_bonk(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, 3);
            }
        } else if (!partImmuneToElement) {
            if (battleStatus->curAttackElement & (DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_SMASH)) {
                show_next_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 0);
            } else {
                show_primary_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 0);
            }

            if (!(targetPart->targetFlags & ACTOR_PART_TARGET_NO_DAMAGE)) {
                show_damage_fx(target, state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage);
            }
        }
    }

    if ((wasSpecialHit && gBattleStatus.flags1 & BS_FLAGS1_NICE_HIT) || gBattleStatus.flags1 & BS_FLAGS1_NICE_HIT) {
        if (!(gBattleStatus.flags1 & BS_FLAGS1_NO_RATING)) {
            if (player->actorTypeData1[5]) {
                sfx_play_sound_at_position(player->actorTypeData1[5], SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            }

            if (battleStatus->lastAttackDamage > 0) {
                sfx_play_sound(SOUND_DAMAGE_STARS);
            }

            if (battleStatus->lastAttackDamage > 0 || ((battleStatus->curAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS) && wasSpecialHit)) {
                if (!(battleStatus->curAttackElement & DAMAGE_TYPE_MULTI_BOUNCE)) {
                    show_action_rating(ACTION_RATING_NICE, target, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                } else {
                    show_action_rating(ACTION_RATING_NICE_SUPER_COMBO, target, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                }
            }
        }
    }

    if (missedAllOrNothing) {
        show_action_rating(ACTION_RATING_MISS, target, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) {
        func_80266970(target);
    }

    if ((battleStatus->lastAttackDamage > 0 || wasSpecialHit) && !partImmuneToElement) {
        set_actor_flash_mode(target, 1);

        if (isFireDamage) {
            sfx_play_sound_at_position(SOUND_HIT_FIRE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        } else if (isShockDamage) {
            sfx_play_sound_at_position(SOUND_HIT_SHOCK, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        } else if (isIceDamage) {
            sfx_play_sound_at_position(SOUND_HIT_ICE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        } else {
            sfx_play_sound_at_position(SOUND_HIT_NORMAL, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        }
    }

    if (battleStatus->lastAttackDamage < 1 && !wasSpecialHit && !canBeShocked || targetPart->flags & ACTOR_PART_FLAG_DAMAGE_IMMUNE) {
        sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->curAttackStatus & STATUS_FLAG_SLEEP && wasStatusInflicted) {
        evt = start_script(&EVS_PlaySleepHitFX, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_SLEEP, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->curAttackStatus & STATUS_FLAG_DIZZY && wasStatusInflicted) {
        evt = start_script(&EVS_PlayDizzyHitFX, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->curAttackStatus & STATUS_FLAG_PARALYZE && wasStatusInflicted) {
        evt = start_script(&EVS_PlayParalyzeHitFX, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->curAttackStatus & STATUS_FLAG_POISON && wasStatusInflicted) {
        evt = start_script(&EVS_PlayPoisonHitFX, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->curAttackStatus & STATUS_FLAG_STOP && wasStatusInflicted) {
        evt = start_script(&EVS_PlayStopHitFX, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->curAttackStatus & STATUS_FLAG_FROZEN && wasStatusInflicted) {
        evt = start_script(&EVS_PlayFreezeHitFX, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        evt->varTablePtr[3] = target;
        sfx_play_sound_at_position(SOUND_HIT_PLAYER_ICE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->curAttackStatus & STATUS_FLAG_SHRINK && wasStatusInflicted) {
        evt = start_script(&EVS_PlayShrinkHitFX, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        evt->varTablePtr[3] = target;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->curAttackElement & DAMAGE_TYPE_SMASH && target->actorType == ACTOR_TYPE_GOOMNUT_TREE) {
        sfx_play_sound_at_position(SOUND_SMACK_TREE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    show_actor_health_bar(target);

    if (gBattleStatus.flags1 & (BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)) {
        if (hitResult == HIT_RESULT_HIT) {
            hitResult = HIT_RESULT_NICE;
        }
        if (hitResult == HIT_RESULT_NO_DAMAGE) {
            hitResult = HIT_RESULT_NICE_NO_DAMAGE;
        }
    }

    if (!is_ability_active(ABILITY_ZAP_TAP)
        && (player->staticStatus != STATUS_KEY_STATIC)
        && (target->staticStatus == STATUS_KEY_STATIC || targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED)
        && !(battleStatus->curAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_SHOCK))
        && !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_SHOCK_CONTACT)
    ) {
        sfx_play_sound_at_position(SOUND_HIT_PLAYER_SHOCK, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        apply_shock_effect(player);
        dispatch_hazard_event_player(1, EVENT_SHOCK_HIT);
        return HIT_RESULT_BACKFIRE;
    }

    return hitResult;
}

b32 dispatch_damage_event_player(s32 damageAmount, s32 event, b32 noHitSound) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* player = battleStatus->playerActor;
    ActorState* state = &player->state;
    s32 oldHPChangeCounter;
    s32 flags;
    s32 dispatchEvent;
    s32 oldPlayerHP;
    s32 temp;

    battleStatus->curAttackDamage = damageAmount;

    temp = (s16)damageAmount; //TODO usage of temp here required to match
    player->hpChangeCounter += temp;

    temp = player->hpChangeCounter;
    player->curHP = playerData->curHP;
    player->damageCounter += temp;
    player->hpChangeCounter -= temp;
    battleStatus->lastAttackDamage = 0;
    player->curHP -= temp;
    battleStatus->damageTaken += temp;

    oldPlayerHP = player->curHP;

    dispatchEvent = event;
    if (player->curHP < 1) {
        battleStatus->lastAttackDamage += oldPlayerHP;
        player->curHP = 0;
        dispatchEvent = EVENT_DEATH;
    }
    battleStatus->lastAttackDamage += temp;
    playerData->curHP = player->curHP;

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

    if (!noHitSound) {
        set_goal_pos_to_part(state, ACTOR_PLAYER, 0);
        sfx_play_sound_at_position(SOUND_HIT_NORMAL, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    show_next_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 1);
    show_damage_fx(player, state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage);

    if (battleStatus->lastAttackDamage > 0) {
        set_actor_flash_mode(player, 1);
    }

    flags = (gBattleStatus.flags1 & (BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)) != 0;
    dispatch_event_player(dispatchEvent);
    return flags;
}

// damage received from "damage over time" effects (only used for poison)
b32 dispatch_damage_tick_event_player(s32 damageAmount, s32 event) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->curAttackElement = ELEMENT_END;
    battleStatus->curDamageSource = DMG_SRC_DEFAULT;
    return dispatch_damage_event_player(damageAmount, event, FALSE);
}

// damage received from contact hazards
b32 dispatch_hazard_event_player(s32 damageAmount, s32 event) {
    return dispatch_damage_event_player(damageAmount, event, TRUE);
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

        player->state.curPos.x = player->curPos.x;
        player->state.curPos.y = player->curPos.y;
        player->state.curPos.z = player->curPos.z;

        x = player->state.curPos.x;
        y = player->state.curPos.y;
        z = player->state.curPos.z;
        goalX = player->state.goalPos.x;
        goalY = player->state.goalPos.y;
        goalZ = player->state.goalPos.z;

        player->state.angle = atan2(x, z, goalX, goalZ);
        player->state.dist = dist2D(x, z, goalX, goalZ);

        y = goalY - y;

        if (player->state.moveTime == 0) {
            player->state.moveTime = player->state.dist / player->state.speed;
            var_f8 = player->state.dist - (player->state.moveTime * player->state.speed);
        } else {
            player->state.speed = player->state.dist / player->state.moveTime;
            var_f8 = player->state.dist - (player->state.moveTime * player->state.speed);
        }

        playerState->speed += var_f8 / playerState->moveTime;
        playerState->vel = (playerState->acceleration * playerState->moveTime * 0.5f) + (y / playerState->moveTime);
        set_actor_anim(0, 0, playerState->animJumpRise);
        playerState->unk_24 = 90.0f;
        playerState->unk_28 = 180 / playerState->moveTime;
        playerState->unk_2C = playerState->goalPos.y;
        if (script->functionTemp[1] != 2) {
            sfx_play_sound_at_position(SOUND_LONG_PLAYER_JUMP, SOUND_SPACE_DEFAULT, player->curPos.x, player->curPos.y, player->curPos.z);
        }
        script->functionTemp[0] = TRUE;
    }

    if (playerState->vel < 0.0f) {
        set_actor_anim(0, 0, playerState->animJumpFall);
    }

    playerVel = playerState->vel;
    switch (playerState->moveArcAmplitude) {
        case 0:
            break;
        case 1:
            if (playerState->curPos.y - playerState->unk_2C > 45.0f) {
                playerVel *= 0.25f;
            }
            break;
        case 2:
            if (playerState->curPos.y - playerState->unk_2C > 54.9) {
                playerVel *= 0.25f;
            }
            break;
    }

    playerState->curPos.y += playerVel;
    playerState->vel -= playerState->acceleration;
    playerSpeed = playerState->speed;
    add_xz_vec3f(&playerState->curPos, playerSpeed + sin_rad(DEG_TO_RAD(playerState->unk_24)), playerState->angle);
    playerState->unk_24 += playerState->unk_28;
    playerState->unk_24 = clamp_angle(playerState->unk_24);
    player->curPos.x = playerState->curPos.x;
    player->curPos.y = playerState->curPos.y;
    player->curPos.z = playerState->curPos.z;
    playerState->moveTime--;

    if (playerState->moveTime >= 0) {
        return ApiStatus_BLOCK;
    }

    player->curPos.y = playerState->goalPos.y;
    if (script->functionTemp[1] != 1) {
        play_movement_dust_effects(2, player->curPos.x, player->curPos.y, player->curPos.z, player->yaw);
    }
    if (script->functionTemp[1] != 2) {
        sfx_play_sound_at_position(SOUND_LAND_SOFTLY, SOUND_SPACE_DEFAULT, player->curPos.x, player->curPos.y, player->curPos.z);
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

        player->state.curPos.x = player->curPos.x;
        player->state.curPos.y = player->curPos.y;
        player->state.curPos.z = player->curPos.z;

        x = player->state.curPos.x;
        y = player->state.curPos.y;
        z = player->state.curPos.z;
        goalX = player->state.goalPos.x;
        goalY = player->state.goalPos.y;
        goalZ = player->state.goalPos.z;

        state->moveTime = moveTime;

        player->state.angle = atan2(x, z, goalX, goalZ);
        player->state.dist = dist2D(x, z, goalX, goalZ);

        y = goalY - y;

        if (state->moveTime == 0) {
            state->moveTime = state->dist / state->speed;
        } else {
            state->speed = state->dist / state->moveTime;
        }

        state->vel = 0.0f;
        state->acceleration = ((y / state->moveTime) - state->vel) / (-state->moveTime * 0.5);
        set_actor_anim(ACTOR_PLAYER, 0, state->animJumpRise);
        script->functionTemp[0] = TRUE;
    }

    if (state->vel < 0.0f) {
        set_actor_anim(ACTOR_PLAYER, 0, state->animJumpFall);
    }

    state->curPos.y += state->vel;
    state->vel -= state->acceleration;
    add_xz_vec3f(&state->curPos, state->speed, state->angle);

    player->curPos.x = state->curPos.x;
    player->curPos.y = state->curPos.y;
    player->curPos.z = state->curPos.z;
    state->moveTime--;

    if (state->moveTime < 0) {
        player->curPos.x = state->goalPos.x;
        player->curPos.y = state->goalPos.y;
        player->curPos.z = state->goalPos.z;
        play_movement_dust_effects(2, player->curPos.x, player->curPos.y, player->curPos.z, player->yaw);
        sfx_play_sound_at_position(SOUND_LAND_SOFTLY, SOUND_SPACE_DEFAULT, player->curPos.x, player->curPos.y, player->curPos.z);
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
        walkMovement->curPos.x = player->curPos.x;
        walkMovement->curPos.y = player->curPos.y;
        walkMovement->curPos.z = player->curPos.z;
        script->functionTemp[0] = 1;
    }

    if (walkMovement->vel > 0.0f) {
        if (walkMovement->animJumpRise != 0) {
            set_actor_anim(0, 0, walkMovement->animJumpRise);
        }
    }

    if (walkMovement->vel < 0.0f) {
        if (walkMovement->animJumpFall != 0) {
            set_actor_anim(0, 0, walkMovement->animJumpFall);
        }
    }

    walkMovement->curPos.y += walkMovement->vel;
    walkMovement->vel -= walkMovement->acceleration;

    add_xz_vec3f(&walkMovement->curPos, walkMovement->speed, walkMovement->angle);

    player->curPos.x = walkMovement->curPos.x;
    player->curPos.y = walkMovement->curPos.y;
    player->curPos.z = walkMovement->curPos.z;

    if (player->curPos.y < 0.0f) {
        player->curPos.y = 0.0f;

        play_movement_dust_effects(2, player->curPos.x, player->curPos.y, player->curPos.z, player->yaw);
        sfx_play_sound_at_position(SOUND_LAND_SOFTLY, SOUND_SPACE_DEFAULT, player->curPos.x, player->curPos.y, player->curPos.z);

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
        player->state.curPos.x = player->curPos.x;
        player->state.curPos.y = player->curPos.y;
        player->state.curPos.z = player->curPos.z;

        goalX = player->state.goalPos.x;
        goalZ = player->state.goalPos.z;
        currentX = player->state.curPos.x;
        currentZ = player->state.curPos.z;

        player->state.angle = atan2(currentX, currentZ, goalX, goalZ);
        player->state.dist = dist2D(currentX, currentZ, goalX, goalZ);
        if (player->state.moveTime == 0) {
            player->state.moveTime = player->state.dist / player->state.speed;
            if (player->state.moveTime == 0) {
                player->state.moveTime = 1;
            }
            player->state.speed += (player->state.dist - (player->state.moveTime * player->state.speed)) / player->state.moveTime;
        } else {
            player->state.speed = player->state.dist / player->state.moveTime;
        }
        playerState->dist = player->actorTypeData1b[0] + 1;
        script->functionTemp[0] = TRUE;
    }

    add_xz_vec3f(&playerState->curPos, playerState->speed, playerState->angle);

    player->curPos.x = playerState->curPos.x;
    player->curPos.y = playerState->curPos.y;
    player->curPos.z = playerState->curPos.z;

    if (playerState->speed < 4.0f) {
        play_movement_dust_effects(0, player->curPos.x, player->curPos.y, player->curPos.z, player->yaw);
    } else {
        play_movement_dust_effects(1, player->curPos.x, player->curPos.y, player->curPos.z, player->yaw);
    }

    playerState->dist += playerState->speed;
    if (playerState->dist > player->actorTypeData1b[0]) {
        player->footStepCounter++;
        playerState->dist = 0.0f;
        if ((player->footStepCounter % 2) != 0) {
            sfx_play_sound_at_position(SOUND_STEP_NORMAL1, SOUND_SPACE_DEFAULT, player->curPos.x, player->curPos.y, player->curPos.z);
        } else {
            sfx_play_sound_at_position(SOUND_STEP_NORMAL2, SOUND_SPACE_DEFAULT, player->curPos.x, player->curPos.y, player->curPos.z);
        }
    }

    playerState->moveTime--;

    if (playerState->moveTime <= 0) {
        player->curPos.x = playerState->goalPos.x;
        player->curPos.z = playerState->goalPos.z;
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
        player->state.curPos.x = player->curPos.x;
        player->state.curPos.y = player->curPos.y;
        player->state.curPos.z = player->curPos.z;

        goalX = player->state.goalPos.x;
        goalZ = player->state.goalPos.z;
        currentX = player->state.curPos.x;
        currentZ = player->state.curPos.z;

        player->state.angle = atan2(currentX, currentZ, goalX, goalZ);
        player->state.dist = dist2D(currentX, currentZ, goalX, goalZ);
        if (player->state.moveTime == 0) {
            player->state.moveTime = player->state.dist / player->state.speed;
            player->state.speed += (player->state.dist - (player->state.moveTime * player->state.speed)) / player->state.moveTime;
        } else {
            player->state.speed = player->state.dist / player->state.moveTime;
        }
        playerState->dist = player->actorTypeData1b[0] + 1;

        if (playerState->moveTime == 0) {
            return ApiStatus_DONE2;
        }

        script->functionTemp[2] = FALSE;
        script->functionTemp[3] = 0;
        script->functionTemp[0] = TRUE;
    }

    add_xz_vec3f(&playerState->curPos, playerState->speed, playerState->angle);

    player->curPos.x = playerState->curPos.x;
    player->curPos.y = playerState->curPos.y;
    player->curPos.z = playerState->curPos.z;

    if (playerState->speed < 4.0f) {
        play_movement_dust_effects(0, player->curPos.x, player->curPos.y, player->curPos.z, player->yaw);
    } else {
        play_movement_dust_effects(1, player->curPos.x, player->curPos.y, player->curPos.z, player->yaw);
    }

    playerState->dist += playerState->speed;
    if (playerState->dist > player->actorTypeData1b[0]) {
        player->footStepCounter++;
        playerState->dist = 0.0f;
        if ((player->footStepCounter % 2) != 0) {
            sfx_play_sound_at_position(SOUND_STEP_NORMAL1, SOUND_SPACE_DEFAULT, player->curPos.x, player->curPos.y, player->curPos.z);
        } else {
            sfx_play_sound_at_position(SOUND_STEP_NORMAL2, SOUND_SPACE_DEFAULT, player->curPos.x, player->curPos.y, player->curPos.z);
        }
    }

    if (script->functionTemp[3] > 12) {
        if (!script->functionTemp[2]) {
            if (!(battleStatus->curButtonsDown & BUTTON_A)) {
                script->functionTemp[2] = TRUE;
            }
        }

        if (script->functionTemp[2]) {
            if (battleStatus->curButtonsPressed & BUTTON_A) {
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

    player->curPos.x = playerState->goalPos.x;
    player->curPos.z = playerState->goalPos.z;
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

    battleStatus->curAttackElement = *args++;
    battleStatus->curAttackEventSuppression = *args++;
    battleStatus->curAttackStatus = *args++;
    battleStatus->curAttackDamage = evt_get_variable(script, *args++);
    battleStatus->powerBounceCounter = 0;
    flags = *args++;

    if ((flags & BS_FLAGS1_INCLUDE_POWER_UPS) && (flags & BS_FLAGS1_TRIGGER_EVENTS)) {
        gBattleStatus.flags1 |= BS_FLAGS1_INCLUDE_POWER_UPS;
        gBattleStatus.flags1 |= BS_FLAGS1_TRIGGER_EVENTS;
    } else if (flags & BS_FLAGS1_INCLUDE_POWER_UPS) {
        gBattleStatus.flags1 |= BS_FLAGS1_INCLUDE_POWER_UPS;
        gBattleStatus.flags1 &= ~BS_FLAGS1_TRIGGER_EVENTS;
    } else if (flags & BS_FLAGS1_TRIGGER_EVENTS) {
        gBattleStatus.flags1 &= ~BS_FLAGS1_INCLUDE_POWER_UPS;
        gBattleStatus.flags1 |= BS_FLAGS1_TRIGGER_EVENTS;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_INCLUDE_POWER_UPS;
        gBattleStatus.flags1 &= ~BS_FLAGS1_TRIGGER_EVENTS;
    }

    if (flags & BS_FLAGS1_NICE_HIT) {
        gBattleStatus.flags1 |= BS_FLAGS1_NICE_HIT;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_NICE_HIT;
    }
    if (flags & BS_FLAGS1_SUPER_HIT) {
        gBattleStatus.flags1 |= BS_FLAGS1_SUPER_HIT;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_SUPER_HIT;
    }
    if (flags & BS_FLAGS1_NO_RATING) {
        gBattleStatus.flags1 |= BS_FLAGS1_NO_RATING;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_NO_RATING;
    }
    if (flags & BS_FLAGS1_FORCE_IMMUNE_HIT) {
        gBattleStatus.flags1 |= BS_FLAGS1_FORCE_IMMUNE_HIT;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_FORCE_IMMUNE_HIT;
    }

    target = get_actor(script->owner1.actorID);
    battleStatus->curTargetID = target->targetActorID;
    battleStatus->curTargetPart = target->targetPartID;
    battleStatus->statusChance = battleStatus->curAttackStatus;
    if (battleStatus->statusChance == STATUS_KEY_NEVER) {
        battleStatus->statusChance = 0;
    }
    battleStatus->statusDuration = (battleStatus->curAttackStatus & 0xF00) >> 8;

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

    battleStatus->curAttackElement = *args++;
    battleStatus->curAttackEventSuppression = *args++;
    battleStatus->curAttackStatus = *args++;
    battleStatus->curAttackDamage = evt_get_variable(script, *args++);
    battleStatus->powerBounceCounter = evt_get_variable(script, *args++);
    flags = *args++;

    if ((flags & BS_FLAGS1_INCLUDE_POWER_UPS) && (flags & BS_FLAGS1_TRIGGER_EVENTS)) {
        gBattleStatus.flags1 |= BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS;
    } else if (flags & BS_FLAGS1_INCLUDE_POWER_UPS) {
        gBattleStatus.flags1 |= BS_FLAGS1_INCLUDE_POWER_UPS;
        gBattleStatus.flags1 &= ~BS_FLAGS1_TRIGGER_EVENTS;
    } else if (flags & BS_FLAGS1_TRIGGER_EVENTS) {
        gBattleStatus.flags1 &= ~BS_FLAGS1_INCLUDE_POWER_UPS;
        gBattleStatus.flags1 |= BS_FLAGS1_TRIGGER_EVENTS;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_INCLUDE_POWER_UPS;
        gBattleStatus.flags1 &= ~BS_FLAGS1_TRIGGER_EVENTS;
    }

    if (flags & BS_FLAGS1_NICE_HIT) {
        gBattleStatus.flags1 |= BS_FLAGS1_NICE_HIT;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_NICE_HIT;
    }
    if (flags & BS_FLAGS1_SUPER_HIT) {
        gBattleStatus.flags1 |= BS_FLAGS1_SUPER_HIT;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_SUPER_HIT;
    }
    if (flags & BS_FLAGS1_NO_RATING) {
        gBattleStatus.flags1 |= BS_FLAGS1_NO_RATING;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_NO_RATING;
    }
    if (flags & BS_FLAGS1_FORCE_IMMUNE_HIT) {
        gBattleStatus.flags1 |= BS_FLAGS1_FORCE_IMMUNE_HIT;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_FORCE_IMMUNE_HIT;
    }

    target = get_actor(script->owner1.actorID);
    battleStatus->curTargetID = target->targetActorID;
    battleStatus->curTargetPart = target->targetPartID;
    battleStatus->statusChance = battleStatus->curAttackStatus;
    if (battleStatus->statusChance == STATUS_KEY_NEVER) {
        battleStatus->statusChance = 0;
    }
    battleStatus->statusDuration = (battleStatus->curAttackStatus & 0xF00) >> 8;

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

    battleStatus->curAttackElement = *args++;
    battleStatus->curAttackEventSuppression = *args++;
    battleStatus->curAttackStatus = *args++;
    battleStatus->curAttackDamage = evt_get_variable(script, *args++);
    battleStatus->powerBounceCounter = 0;
    flags = *args++;

    if ((flags & BS_FLAGS1_INCLUDE_POWER_UPS) && (flags & BS_FLAGS1_TRIGGER_EVENTS)) {
        gBattleStatus.flags1 |= BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_TRIGGER_EVENTS;
    } else if (flags & BS_FLAGS1_INCLUDE_POWER_UPS) {
        gBattleStatus.flags1 |= BS_FLAGS1_INCLUDE_POWER_UPS;
        gBattleStatus.flags1 &= ~BS_FLAGS1_TRIGGER_EVENTS;
    } else if (flags & BS_FLAGS1_TRIGGER_EVENTS) {
        gBattleStatus.flags1 &= ~BS_FLAGS1_INCLUDE_POWER_UPS;
        gBattleStatus.flags1 |= BS_FLAGS1_TRIGGER_EVENTS;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_INCLUDE_POWER_UPS;
        gBattleStatus.flags1 &= ~BS_FLAGS1_TRIGGER_EVENTS;
    }

    if (flags & BS_FLAGS1_NICE_HIT) {
        gBattleStatus.flags1 |= BS_FLAGS1_NICE_HIT;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_NICE_HIT;
    }
    if (flags & BS_FLAGS1_SUPER_HIT) {
        gBattleStatus.flags1 |= BS_FLAGS1_SUPER_HIT;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_SUPER_HIT;
    }
    if (flags & BS_FLAGS1_NO_RATING) {
        gBattleStatus.flags1 |= BS_FLAGS1_NO_RATING;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_NO_RATING;
    }
    if (flags & BS_FLAGS1_FORCE_IMMUNE_HIT) {
        gBattleStatus.flags1 |= BS_FLAGS1_FORCE_IMMUNE_HIT;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_FORCE_IMMUNE_HIT;
    }

    target = get_actor(script->owner1.actorID);
    battleStatus->curTargetID = target->targetActorID;
    battleStatus->curTargetPart = target->targetPartID;
    battleStatus->statusChance = battleStatus->curAttackStatus;
    if (battleStatus->statusChance == STATUS_KEY_NEVER) {
        battleStatus->statusChance = 0;
    }
    battleStatus->statusDuration = (battleStatus->curAttackStatus & 0xF00) >> 8;

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

    if (dispatch_damage_tick_event_player(damageAmount, *args++) < 0) {
        return ApiStatus_BLOCK;
    }

    if (does_script_exist_by_ref(script)) {
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

ApiStatus EnablePlayerBlur(Evt* script, s32 isInitialCall) {
    s32 setting = evt_get_variable(script, *script->ptrReadPos);

    if (setting == ACTOR_BLUR_DISABLE) {
        disable_player_blur();
    } else if (setting == ACTOR_BLUR_ENABLE) {
        enable_player_blur();
    } else {
        reset_player_blur();
    }

    return ApiStatus_DONE2;
}

ApiStatus ForceDisablePlayerBlur(Evt* script, s32 isInitialCall) {
    force_disable_player_blur();
    return ApiStatus_DONE2;
}

ApiStatus ForceDisablePlayerBlurImmediately(Evt* script, s32 isInitialCall) {
    force_disable_player_blur_immediately();
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
        playerState->curPos.x = player->curPos.x;
        playerState->curPos.y = player->curPos.y;
        playerState->curPos.z = player->curPos.z;
        goalX = playerState->goalPos.x;
        goalZ = playerState->goalPos.z;
        posX = playerState->curPos.x;
        posY = playerState->curPos.y;
        posZ = playerState->curPos.z;
        playerState->angle = atan2(posX, posZ, goalX, goalZ);
        playerState->dist = dist2D(posX, posZ, goalX, goalZ);
        if (playerState->moveTime == 0) {
            playerState->moveTime = playerState->dist / playerState->speed;
            temp = playerState->dist - (playerState->moveTime * playerState->speed);
        } else {
            playerState->speed = playerState->dist / playerState->moveTime;
            temp = playerState->dist - (playerState->moveTime * playerState->speed);
        }

        if (playerState->moveTime == 0) {
            return ApiStatus_DONE2;
        }

        playerState->velStep.x = (playerState->goalPos.x - playerState->curPos.x) / playerState->moveTime;
        playerState->velStep.y = (playerState->goalPos.y - playerState->curPos.y) / playerState->moveTime;
        playerState->velStep.z = (playerState->goalPos.z - playerState->curPos.z) / playerState->moveTime;
        playerState->acceleration = PI_S /  playerState->moveTime;
        playerState->vel = 0.0f;
        playerState->speed += temp / playerState->moveTime;
        if (playerState->moveArcAmplitude < 3) {
            temp = playerState->dist;
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
            vel1 = playerState->vel;
            acc1 = playerState->acceleration;
            playerState->vel = vel1 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * acc1) + acc1);
        } else {
            temp = playerState->dist;
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
            vel2 = playerState->vel;
            acc2 = playerState->acceleration;
            playerState->vel = vel2 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.8 * acc2) + acc2);
        }
        set_actor_anim(0, 0, playerState->animJumpRise);
        sfx_play_sound_at_position(SOUND_LONG_PLAYER_JUMP, SOUND_SPACE_DEFAULT, player->curPos.x, player->curPos.y, player->curPos.z);
        script->functionTemp[0] = 1;
    }

    switch (script->functionTemp[0]) {
        case 1:
            if (playerState->vel > PI_S / 2) {
                set_actor_anim(ACTOR_PLAYER, 0, playerState->animJumpFall);
            }
            playerState->curPos.x += playerState->velStep.x;
            playerState->curPos.y += playerState->velStep.y;
            playerState->curPos.z += playerState->velStep.z;
            playerState->unk_18.x = player->curPos.y;
            player->curPos.x = playerState->curPos.x;
            player->curPos.y = playerState->curPos.y + (playerState->bounceDivisor * sin_rad(playerState->vel));
            player->curPos.z = playerState->curPos.z;
            if (playerState->goalPos.y > player->curPos.y && playerState->moveTime < 3) {
                player->curPos.y = playerState->goalPos.y;
            }
            playerState->unk_18.y = player->curPos.y;
            if (playerState->moveArcAmplitude < 3) {
                vel3 = playerState->vel;
                acc3 = playerState->acceleration;
                playerState->vel = vel3 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * acc3) + acc3);
            } else {
                vel4 = playerState->vel;
                acc4 = playerState->acceleration;
                playerState->vel = vel4 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.8 * acc4) + acc4);
            }
            playerState->unk_24 += playerState->unk_28;
            playerState->unk_24 = clamp_angle(playerState->unk_24);
            playerState->moveTime--;
            if (playerState->moveTime == 0) {
                player->curPos.y = playerState->goalPos.y;
                playerState->acceleration = 1.8f;
                playerState->vel = -(playerState->unk_18.x - playerState->unk_18.y);
                set_actor_anim(ACTOR_PLAYER, 0, playerState->animJumpLand);
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
            playerState->vel = -(playerState->unk_18.x - playerState->unk_18.y);
            playerState->bounceDivisor = fabsf(playerState->unk_18.x - playerState->unk_18.y) / 16.5;
            playerState->unk_28 = 360 / playerState->moveTime;
            playerState->curPos.x = player->curPos.x;
            playerState->curPos.y = player->curPos.y;
            playerState->curPos.z = player->curPos.z;
            script->functionTemp[0] = 3;
            // fallthrough
        case 3:
            temp_f20_2 = playerState->curPos.x;
            playerState->curPos.x = temp_f20_2 + ((playerState->bounceDivisor * sin_rad(DEG_TO_RAD(playerState->unk_24))) / 33.0);
            playerState->curPos.y -= (playerState->bounceDivisor * sin_rad(DEG_TO_RAD(playerState->unk_24)));
            playerState->unk_24 += playerState->unk_28;
            playerState->unk_24 = clamp_angle(playerState->unk_24);
            player->curPos.x = playerState->curPos.x;
            player->curPos.y = playerState->curPos.y;
            player->curPos.z = playerState->curPos.z;
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
            playerState->curPos.x = player->curPos.x;
            playerState->curPos.y = player->curPos.y;
            playerState->curPos.z = player->curPos.z;
            goalX = playerState->goalPos.x;
            goalZ = playerState->goalPos.z;
            posX = playerState->curPos.x;
            posY = playerState->curPos.y;
            posZ = playerState->curPos.z;
            playerState->angle = atan2(posX, posZ, goalX, goalZ);
            playerState->dist = dist2D(posX, posZ, goalX, goalZ);

            if (playerState->moveTime == 0) {
                playerState->moveTime = playerState->dist / playerState->speed;
                temp = playerState->dist - (playerState->moveTime * playerState->speed);
            } else {
                playerState->speed = playerState->dist / playerState->moveTime;
                temp = playerState->dist - (playerState->moveTime * playerState->speed);
            }

            if (playerState->moveTime == 0) {
                return ApiStatus_DONE2;
            }

            playerState->velStep.x = (playerState->goalPos.x - playerState->curPos.x) / playerState->moveTime;
            playerState->velStep.y = (playerState->goalPos.y - playerState->curPos.y) / playerState->moveTime;
            playerState->velStep.z = (playerState->goalPos.z - playerState->curPos.z) / playerState->moveTime;
            playerState->acceleration = (PI_S / 2) / playerState->moveTime;
            playerState->vel = 0.0f;
            playerState->speed += temp / playerState->moveTime;
            set_actor_anim(ACTOR_PLAYER, 0, playerState->animJumpRise);
            sfx_play_sound_at_position(SOUND_LONG_PLAYER_JUMP, SOUND_SPACE_DEFAULT, player->curPos.x, player->curPos.y, player->curPos.z);
            playerState->unk_24 = 90.0f;
            playerState->bounceDivisor = 45.0f;
            playerState->unk_28 = 360 / playerState->moveTime;
            if (playerState->moveArcAmplitude == 4) {
                playerState->bounceDivisor = 56.25f;
            }
            playerState->unk_18.x = 0.0f;
            playerState->unk_18.y = 0.0f;
            if (playerState->moveArcAmplitude == 0) {
                vel1 = playerState->vel;
                acc1 = playerState->acceleration;
                playerState->vel = (vel1 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * acc1) + acc1));
            } else {
                vel2 = playerState->vel;
                acc2 = playerState->acceleration;
                playerState->vel = (vel2 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.01 * acc2) + acc2));
            }
            script->functionTemp[0] = 1;
            break;
        case 10:
            playerState->curPos.x = player->curPos.x;
            playerState->curPos.y = player->curPos.y;
            playerState->curPos.z = player->curPos.z;
            goalX = playerState->goalPos.x;
            goalZ = playerState->goalPos.z;
            posX = playerState->curPos.x;
            posY = playerState->curPos.y;
            posZ = playerState->curPos.z;
            playerState->angle = atan2(posX, posZ, goalX, goalZ);
            playerState->dist = dist2D(posX, posZ, goalX, goalZ);
            if (playerState->moveTime == 0) {
                playerState->moveTime = playerState->dist / playerState->speed;
                temp = playerState->dist - (playerState->moveTime * playerState->speed);
            } else {
                playerState->speed = playerState->dist / playerState->moveTime;
                temp = playerState->dist - (playerState->moveTime * playerState->speed);
            }

            if (playerState->moveTime == 0) {
                return ApiStatus_DONE2;
            }
            playerState->velStep.x = (playerState->goalPos.x - playerState->curPos.x) / playerState->moveTime;
            playerState->velStep.y = (playerState->goalPos.y - playerState->curPos.y) / playerState->moveTime;
            playerState->velStep.z = (playerState->goalPos.z - playerState->curPos.z) / playerState->moveTime;
            playerState->vel = (PI_S / 2);
            playerState->acceleration = (PI_S / 4) / (playerState->moveTime + 1);
            playerState->speed += temp / playerState->moveTime;
            set_actor_anim(ACTOR_PLAYER, 0, playerState->animJumpLand);
            playerState->unk_24 = 90.0f;
            playerState->bounceDivisor = 45.0f;
            playerState->unk_28 = (360 / playerState->moveTime);
            if (playerState->moveArcAmplitude == 5) {
                playerState->bounceDivisor = 56.25f;
            }
            playerState->unk_18.x = 0.0f;
            playerState->unk_18.y = 0.0f;
            if (playerState->moveArcAmplitude == 1) {
                vel3 = playerState->vel;
                acc3 = playerState->acceleration;
                playerState->vel = (vel3 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * acc3) + acc3));
            } else {
                vel4 = playerState->vel;
                acc4 = playerState->acceleration;
                playerState->vel = (vel4 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.01 * acc4) + acc4));
            }
            playerState->curPos.y = player->curPos.y - playerState->bounceDivisor;
            script->functionTemp[0] = 11;
            break;
        case 20:
            playerState->moveTime = 1;
            playerState->unk_24 = 90.0f;
            playerState->bounceDivisor = (fabsf(playerState->unk_18.x - playerState->unk_18.y) / 16.5);
            playerState->unk_28 = (360 / playerState->moveTime);
            playerState->curPos.x = player->curPos.x;
            playerState->curPos.y = player->curPos.y;
            playerState->curPos.z = player->curPos.z;
            script->functionTemp[0] = 21;
            break;
    }

    switch (script->functionTemp[0]) {
        case 1:
            if (playerState->moveArcAmplitude == 0) {
                vel5 = playerState->vel;
                acc5 = playerState->acceleration;
                playerState->vel = (vel5 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * acc5) + acc5));
            } else {
                vel6 = playerState->vel;
                acc6 = playerState->acceleration;
                playerState->vel = (vel6 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.01 * acc6) + acc6));
            }
            playerState->curPos.x += playerState->velStep.x;
            playerState->curPos.y += playerState->velStep.y;
            playerState->curPos.z += playerState->velStep.z;
            playerState->unk_18.x = player->curPos.y;
            player->curPos.x = playerState->curPos.x;
            player->curPos.y = playerState->curPos.y + (playerState->bounceDivisor * sin_rad(sin_rad(sin_rad(playerState->vel) * (PI_S / 2)) * (PI_S / 2)));
            player->curPos.z = playerState->curPos.z;
            playerState->unk_18.y = player->curPos.y;
            playerState->unk_24 += playerState->unk_28;
            playerState->unk_24 = clamp_angle(playerState->unk_24);
            playerState->moveTime--;
            if (playerState->moveTime == 0) {
                sfx_play_sound_at_position(SOUND_LONG_PLAYER_JUMP, SOUND_SPACE_DEFAULT, player->curPos.x, player->curPos.y, player->curPos.z);
                set_actor_anim(ACTOR_PLAYER, 0, playerState->animJumpFall);
                player->rotPivotOffset.y = 14;
                player->rot.z -= 66.0f;
                playerState->moveTime = 7;
                script->functionTemp[0] = 2;
            }
            break;
        case 2:
            player->rotPivotOffset.y = 14;
            player->rot.z -= 66.0f;
            playerState->moveTime--;
            if (playerState->moveTime == 0) {
                player->rot.z = 0.0f;
                player->rotPivotOffset.y = 0;
                set_actor_anim(ACTOR_PLAYER, 0, playerState->animJumpLand);
                return ApiStatus_DONE1;
            }
            break;
        case 11:
            playerState->curPos.x += playerState->velStep.x;
            playerState->curPos.y += playerState->velStep.y;
            playerState->curPos.z += playerState->velStep.z;
            playerState->unk_18.x = player->curPos.y;
            player->curPos.x = playerState->curPos.x;
            player->curPos.y = playerState->curPos.y + (playerState->bounceDivisor * sin_rad(playerState->vel));
            player->curPos.z = playerState->curPos.z;
            if (playerState->goalPos.y > player->curPos.y) {
                player->curPos.y = playerState->goalPos.y;
            }
            playerState->unk_18.y = player->curPos.y;

            if (playerState->moveArcAmplitude == 1) {
                vel7 = playerState->vel;
                acc7 = playerState->acceleration;
                playerState->vel = (vel7 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * acc7) + acc7));
            } else {
                vel8 = playerState->vel;
                acc8 = playerState->acceleration;
                playerState->vel = (vel8 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.01 * acc8) + acc8));
            }

            playerState->unk_24 += playerState->unk_28;
            playerState->unk_24 = clamp_angle(playerState->unk_24);
            playerState->moveTime--;
            if (playerState->moveTime == 0) {
                player->curPos.y = playerState->goalPos.y;
                set_actor_anim(ACTOR_PLAYER, 0, ANIM_Mario1_SpinFall);
                return ApiStatus_DONE1;
            }
            break;
        case 21:
            temp_f20 = playerState->curPos.x;
            temp_f20 += (playerState->bounceDivisor * sin_rad(DEG_TO_RAD(playerState->unk_24))) / 33.0;
            playerState->curPos.x = temp_f20;
            playerState->curPos.y -= playerState->bounceDivisor * sin_rad(DEG_TO_RAD(playerState->unk_24));
            playerState->unk_24 += playerState->unk_28;
            playerState->unk_24 = clamp_angle(playerState->unk_24);
            player->curPos.x = playerState->curPos.x;
            player->curPos.y = playerState->curPos.y;
            player->curPos.z = playerState->curPos.z;
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
            playerState->curPos.x = player->curPos.x;
            playerState->curPos.y = player->curPos.y;
            playerState->curPos.z = player->curPos.z;
            goalX = playerState->goalPos.x;
            goalZ = playerState->goalPos.z;
            posX = playerState->curPos.x;
            posY = playerState->curPos.y;
            posZ = playerState->curPos.z;
            playerState->angle = atan2(posX, posZ, goalX, goalZ);
            playerState->dist = dist2D(posX, posZ, goalX, goalZ);
            if (playerState->moveTime == 0) {
                playerState->moveTime = playerState->dist / playerState->speed;
                temp = playerState->dist - (playerState->moveTime * playerState->speed);
            } else {
                playerState->speed = playerState->dist / playerState->moveTime;
                temp = playerState->dist - (playerState->moveTime * playerState->speed);
            }
            playerState->acceleration = PI_S / playerState->moveTime;
            playerState->vel = 0.0f;
            playerState->velStep.x = (playerState->goalPos.x - playerState->curPos.x) / playerState->moveTime;
            playerState->velStep.y = (playerState->goalPos.y - playerState->curPos.y) / playerState->moveTime;
            playerState->velStep.z = (playerState->goalPos.z - playerState->curPos.z) / playerState->moveTime;
            playerState->speed += temp / playerState->moveTime;
            set_actor_anim(ACTOR_PLAYER, 0, playerState->animJumpFall);
            sfx_play_sound_at_position(SOUND_LONG_PLAYER_JUMP, SOUND_SPACE_DEFAULT, player->curPos.x, player->curPos.y, player->curPos.z);
            sfx_play_sound_at_position(SOUND_TORNADO_JUMP, SOUND_SPACE_DEFAULT, player->curPos.x, player->curPos.y, player->curPos.z);
            playerState->unk_18.x = 0.0f;
            playerState->unk_18.y = 0.0f;
            playerState->unk_24 = 90.0f;

            temp = playerState->dist;
            temp -= 20.0;
            temp /= 6.0;
            temp += 47.0;
            playerState->bounceDivisor = temp;

            temp_f20 = playerState->vel;
            temp_f22 = playerState->acceleration;
            playerState->unk_28 = 360 / playerState->moveTime;
            playerState->vel = temp_f20 + (((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53) * temp_f22) + temp_f22);
            script->functionTemp[0] = 1;
            break;
        case 10:
            playerState->curPos.x = player->curPos.x;
            playerState->curPos.y = player->curPos.y;
            playerState->curPos.z = player->curPos.z;
            goalX = playerState->goalPos.x;
            goalZ = playerState->goalPos.z;
            posX = playerState->curPos.x;
            posY = playerState->curPos.y;
            posZ = playerState->curPos.z;
            playerState->angle = atan2(posX, posZ, goalX, goalZ);
            playerState->dist = dist2D(posX, posZ, goalX, goalZ);
            if (playerState->moveTime == 0) {
                playerState->moveTime = playerState->dist / playerState->speed;
                temp = playerState->dist - (playerState->moveTime * playerState->speed);
            } else {
                speed = playerState->dist / playerState->moveTime;
                playerState->speed = speed;
                temp = playerState->dist - (playerState->moveTime * speed);
            }
            playerState->acceleration = PI_S / playerState->moveTime;
            playerState->vel = 0.0f;
            playerState->velStep.x = (playerState->goalPos.x - playerState->curPos.x) / playerState->moveTime;
            playerState->velStep.y = (playerState->goalPos.y - playerState->curPos.y) / playerState->moveTime;
            playerState->velStep.z = (playerState->goalPos.z - playerState->curPos.z) / playerState->moveTime;
            playerState->speed += temp / playerState->moveTime;
            set_actor_anim(ACTOR_PLAYER, 0, playerState->animJumpRise);
            sfx_play_sound_at_position(SOUND_LONG_PLAYER_JUMP, SOUND_SPACE_DEFAULT, player->curPos.x, player->curPos.y, player->curPos.z);
            sfx_play_sound_at_position(SOUND_TORNADO_JUMP, SOUND_SPACE_DEFAULT, player->curPos.x, player->curPos.y, player->curPos.z);
            playerState->unk_18.x = 0.0f;
            playerState->unk_18.y = 0.0f;
            playerState->unk_24 = 90.0f;
            temp_f20_2 = playerState->vel;
            temp_f22_2 = playerState->acceleration;

            temp = playerState->dist;
            temp -= 20.0;
            temp /= 6.0;
            temp += 47.0;
            playerState->bounceDivisor = temp;

            playerState->unk_28 = 360 / playerState->moveTime;
            playerState->vel = temp_f20_2 + (((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53) * temp_f22_2) + temp_f22_2);
            script->functionTemp[0] = 11;
            break;
        case 20:
            playerState->moveTime = 1;
            set_actor_anim(ACTOR_PLAYER, 1, ANIM_Mario1_SpinFall);
            player->rot.y = 0.0f;
            playerState->unk_24 = 90.0f;
            playerState->bounceDivisor = fabsf(playerState->unk_18.x - playerState->unk_18.y) / 16.5;
            playerState->unk_28 = 360 / playerState->moveTime;
            playerState->curPos.x = player->curPos.x;
            playerState->curPos.y = player->curPos.y;
            playerState->curPos.z = player->curPos.z;
            script->functionTemp[0] = 21;
            break;
        case 30:
            playerState->curPos.x = player->curPos.x;
            playerState->curPos.y = player->curPos.y;
            playerState->curPos.z = player->curPos.z;
            goalX = playerState->goalPos.x;
            goalZ = playerState->goalPos.z;
            posX = playerState->curPos.x;
            posY = playerState->curPos.y;
            posZ = playerState->curPos.z;
            playerState->angle = atan2(posX, posZ, goalX, goalZ);
            playerState->dist = dist2D(posX, posZ, goalX, goalZ);
            if (playerState->moveTime == 0) {
                playerState->moveTime = playerState->dist / playerState->speed;
                temp = playerState->dist - (playerState->moveTime * playerState->speed);
            } else {
                playerState->speed = playerState->dist / playerState->moveTime;
                temp = playerState->dist - (playerState->moveTime * playerState->speed);
            }
            playerState->acceleration = PI_S / (playerState->moveTime + 1);
            playerState->vel = 0.0f;
            playerState->velStep.x = (playerState->goalPos.x - playerState->curPos.x) / playerState->moveTime;
            playerState->velStep.y = (playerState->goalPos.y - playerState->curPos.y) / playerState->moveTime;
            playerState->velStep.z = (playerState->goalPos.z - playerState->curPos.z) / playerState->moveTime;
            playerState->speed += temp / playerState->moveTime;
            set_actor_anim(ACTOR_PLAYER, 0, playerState->animJumpRise);
            sfx_play_sound_at_position(SOUND_LONG_PLAYER_JUMP, SOUND_SPACE_DEFAULT, player->curPos.x, player->curPos.y, player->curPos.z);
            playerState->unk_24 = 90.0f;
            playerState->bounceDivisor = 45.0f;
            playerState->unk_28 = 360 / playerState->moveTime;
            if (playerState->moveArcAmplitude == 4) {
                playerState->bounceDivisor = 56.25f;
            }
            playerState->unk_18.x = 0.0f;
            playerState->unk_18.y = 0.0f;
            temp_f22_3 = playerState->acceleration;
            temp_f22_7 = playerState->vel;
            temp_f22_7 = temp_f22_7 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * temp_f22_3) + temp_f22_3);
            playerState->vel = temp_f22_7;
            script->functionTemp[0] = 31;
            break;
    }

    switch (script->functionTemp[0]) {
        case 1:
            temp_f22_4 = playerState->vel;
            temp_f20_4 = playerState->acceleration;
            playerState->vel = temp_f22_4 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * temp_f20_4) + temp_f20_4);
            playerState->curPos.x += playerState->velStep.x;
            playerState->curPos.y += playerState->velStep.y;
            playerState->curPos.z += playerState->velStep.z;
            playerState->unk_18.x = player->curPos.y;
            player->curPos.x = playerState->curPos.x;
            player->curPos.y = playerState->curPos.y + (playerState->bounceDivisor * sin_rad(playerState->vel));
            player->curPos.z = playerState->curPos.z;
            playerState->unk_18.y = player->curPos.y;
            playerState->unk_24 += playerState->unk_28;
            playerState->unk_24 = clamp_angle(playerState->unk_24);
            player->rot.y += 133.0f;
            player->rot.y = clamp_angle(player->rot.y);
            if (gBattleStatus.flags1 & BS_FLAGS1_2000) {
                return ApiStatus_DONE2;
            }
            playerState->moveTime--;
            if (playerState->moveTime == 4) {
                return ApiStatus_DONE1;
            }
            break;
        case 11:
            temp_f22_6 = playerState->vel;
            temp_f20_7 = playerState->acceleration;
            playerState->vel = temp_f22_6 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * temp_f20_7) + temp_f20_7);
            playerState->curPos.x += playerState->velStep.x;
            playerState->curPos.y += playerState->velStep.y;
            playerState->curPos.z += playerState->velStep.z;
            playerState->unk_18.x = player->curPos.y;
            player->curPos.x = playerState->curPos.x;
            player->curPos.y = playerState->curPos.y + (playerState->bounceDivisor * sin_rad(playerState->vel));
            player->curPos.z = playerState->curPos.z;
            if (playerState->goalPos.y > player->curPos.y && playerState->moveTime < 3) {
                player->curPos.y = playerState->goalPos.y;
            }
            playerState->unk_18.y = player->curPos.y;
            playerState->unk_24 += playerState->unk_28;
            playerState->unk_24 = clamp_angle(playerState->unk_24);
            set_actor_anim(ACTOR_PLAYER, 0, playerState->animJumpFall);
            player->rot.y += 133.0f;
            player->rot.y = clamp_angle(player->rot.y);
            playerState->moveTime--;
            if (playerState->moveTime == 0) {
                playerState->acceleration = 1.8f;
                playerState->vel = -(playerState->unk_18.x - playerState->unk_18.y);
                player->curPos.y = playerState->goalPos.y;
                player->rot.y = 0.0f;
                set_actor_anim(ACTOR_PLAYER, 0, playerState->animJumpLand);
                play_movement_dust_effects(2, player->curPos.x, player->curPos.y, player->curPos.z, player->yaw);
                return ApiStatus_DONE1;
            }
            break;
        case 21:
            temp_f20_5 = playerState->curPos.x;
            temp_f20_5 += (playerState->bounceDivisor * sin_rad(DEG_TO_RAD(playerState->unk_24))) / 33.0;
            playerState->curPos.x = temp_f20_5;
            playerState->curPos.y -= playerState->bounceDivisor * sin_rad(DEG_TO_RAD(playerState->unk_24));
            playerState->unk_24 += playerState->unk_28;
            playerState->unk_24 = clamp_angle(playerState->unk_24);
            player->curPos.x = playerState->curPos.x;
            player->curPos.y = playerState->curPos.y;
            player->curPos.z = playerState->curPos.z;
            if (gBattleStatus.flags1 & BS_FLAGS1_2000) {
               return ApiStatus_DONE2;
            }
            playerState->moveTime--;
            if (playerState->moveTime == 0) {
                return ApiStatus_DONE1;
            }
            break;
        case 31:
            temp_f22_5 = playerState->vel;
            temp_f20_6 = playerState->acceleration;
            playerState->vel = temp_f22_5 + ((sin_rad(DEG_TO_RAD(playerState->unk_24)) * 0.53 * temp_f20_6) + temp_f20_6);
            playerState->curPos.x += playerState->velStep.x;
            playerState->curPos.y += playerState->velStep.y;
            playerState->curPos.z += playerState->velStep.z;
            playerState->unk_18.x = player->curPos.y;
            player->curPos.x = playerState->curPos.x;
            player->curPos.y = playerState->curPos.y + (playerState->bounceDivisor * sin_rad(playerState->vel));
            player->curPos.z = playerState->curPos.z;
            if (playerState->goalPos.y > player->curPos.y && playerState->moveTime < 3) {
                player->curPos.y = playerState->goalPos.y;
            }
            playerState->unk_18.y = player->curPos.y;
            playerState->unk_24 += playerState->unk_28;
            playerState->unk_24 = clamp_angle(playerState->unk_24);
            set_actor_anim(ACTOR_PLAYER, 0, playerState->animJumpFall);
            player->rot.y += 133.0f;
            player->rot.y = clamp_angle(player->rot.y);
            playerState->moveTime--;
            if (playerState->moveTime == 0) {
                player->curPos.y = playerState->goalPos.y;
                player->rot.y = 0.0f;
                set_actor_anim(ACTOR_PLAYER, 0, playerState->animJumpLand);
                playerState->acceleration = 1.8f;
                playerState->vel = -(playerState->unk_18.x - playerState->unk_18.y);
                return ApiStatus_DONE1;
            }
            break;
    }

    return ApiStatus_BLOCK;
}

ApiStatus GetPlayerActionSuccess(Evt* script, s32 isInitialCall) {
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

ApiStatus PlayerYieldTurn(Evt* script, s32 isInitialCall) {
    gBattleStatus.flags1 |= BS_FLAGS1_YIELD_TURN;
    return ApiStatus_DONE2;
}

ApiStatus DispatchEventPlayer(Evt* script, s32 isInitialCall) {
    dispatch_event_player(evt_get_variable(script, *script->ptrReadPos));
    return ApiStatus_DONE2;
}
