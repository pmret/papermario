#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"

s32 dispatch_damage_event_partner_1(s32, s32);

void dispatch_event_partner(s32 lastEventType) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Evt* handleEventScript = partnerActor->handleEventScript;
    s32 onHitID = partnerActor->handleEventScriptID;
    Evt* script;

    partnerActor->lastEventType = lastEventType;
    script = start_script(partnerActor->handleEventSource, EVT_PRIORITY_A, EVT_FLAG_RUN_IMMEDIATELY);
    partnerActor->handleEventScript = script;
    partnerActor->handleEventScriptID = script->id;
    script->owner1.actorID = ACTOR_PARTNER;

    if (partnerActor->takeTurnScript != NULL) {
        kill_script_by_ID(partnerActor->takeTurnScriptID);
        partnerActor->takeTurnScript = NULL;
    }

    if (handleEventScript != NULL) {
        kill_script_by_ID(onHitID);
    }
}

void dispatch_event_partner_continue_turn(s8 lastEventType) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partnerActor = battleStatus->partnerActor;
    Evt* handleEventScript = partnerActor->handleEventScript;
    s32 onHitID = partnerActor->handleEventScriptID;
    Evt* script;

    partnerActor->lastEventType = lastEventType;
    script = start_script(partnerActor->handleEventSource, EVT_PRIORITY_A, EVT_FLAG_RUN_IMMEDIATELY);
    partnerActor->handleEventScript = script;
    partnerActor->handleEventScriptID = script->id;
    script->owner1.actorID = ACTOR_PARTNER;

    if (handleEventScript != NULL) {
        kill_script_by_ID(onHitID);
    }
}

HitResult calc_partner_test_enemy(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    s32 currentTargetID = battleStatus->curTargetID;
    s32 currentTargetPart = battleStatus->curTargetPart;
    Actor* target;
    ActorState* state;
    ActorPart* part;

    battleStatus->curTargetID2 = battleStatus->curTargetID;
    battleStatus->curTargetPart2 = battleStatus->curTargetPart;
    target = get_actor(currentTargetID);
    state = &partner->state;

    if (target == NULL) {
        return HIT_RESULT_HIT;
    }

    part = get_actor_part(target, currentTargetPart);
    ASSERT(part != NULL);

    if (target->stoneStatus == STATUS_KEY_STONE) {
        return HIT_RESULT_IMMUNE;
    }

    if ((part->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) || target->transparentStatus == STATUS_KEY_TRANSPARENT) {
        return HIT_RESULT_MISS;
    }

    // check partner jumping on top-spiky enemy (cannot be suppressed)
    if ((battleStatus->curAttackElement & DAMAGE_TYPE_JUMP)
        && (part->eventFlags & ACTOR_EVENT_FLAG_SPIKY_TOP)
        && !(target->flags2 & ACTOR_FLAG_UPSIDE_DOWN)
    ) {
        sfx_play_sound_at_position(SOUND_HIT_SPIKE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        return HIT_RESULT_LANDED_ON_SPIKE;
    }

    // check partner contacting front-spiky enemy
    if (!(battleStatus->curAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_JUMP))
        && (part->eventFlags & ACTOR_EVENT_FLAG_SPIKY_FRONT)
        && !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_SPIKY_FRONT)
        && !player_team_is_ability_active(partner, ABILITY_SPIKE_SHIELD)
    ) {
        sfx_play_sound_at_position(SOUND_HIT_SPIKE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        dispatch_damage_event_partner_1(1, EVENT_SPIKE_CONTACT);
        dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
        return HIT_RESULT_BACKFIRE;
    }

    // check partner contacting fiery enemy
    if (!(battleStatus->curAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_SMASH))
        && (part->eventFlags & ACTOR_EVENT_FLAG_FIREY)
        && !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_BURN_CONTACT)
    ) {
        sfx_play_sound_at_position(SOUND_HIT_FIRE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        dispatch_damage_event_partner_1(1, EVENT_BURN_CONTACT);
        dispatch_event_actor(target, EVENT_BURN_TAUNT);
        return HIT_RESULT_BACKFIRE;
    }

    // special handling for air lift
    if (battleStatus->curAttackElement & DAMAGE_TYPE_AIR_LIFT) {
        // check partner airlifting top-spiky enemy
        if (!(battleStatus->curAttackElement & DAMAGE_TYPE_NO_CONTACT)) {
            if ((part->eventFlags & ACTOR_EVENT_FLAG_SPIKY_TOP)
                && !(target->flags & ACTOR_FLAG_UPSIDE_DOWN)
                && !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_SPIKY_TOP)
            ) {
                sfx_play_sound_at_position(SOUND_HIT_SPIKE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                dispatch_damage_event_partner_1(1, EVENT_SPIKE_CONTACT);
                dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
                return HIT_RESULT_BACKFIRE;
            }

            if (!(battleStatus->curAttackElement & DAMAGE_TYPE_NO_CONTACT)
                && (part->eventFlags & ACTOR_EVENT_FLAG_ALT_SPIKY)
                && !(target->flags & ACTOR_FLAG_UPSIDE_DOWN)
                && !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_ALT_SPIKY)
            ) {
                sfx_play_sound_at_position(SOUND_HIT_SPIKE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                dispatch_damage_event_partner_1(1, EVENT_SPIKE_CONTACT);
                dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
                return HIT_RESULT_BACKFIRE;
            }
        }

        // check partner airlifting electrified enemy
        if (partner->staticStatus != STATUS_KEY_STATIC
            && (target->staticStatus == STATUS_KEY_STATIC || (part->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED))
            && !(battleStatus->curAttackElement & DAMAGE_TYPE_NO_CONTACT)
            && !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_SHOCK_CONTACT))
        {
            sfx_play_sound_at_position(SOUND_HIT_SHOCK, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            apply_shock_effect(partner);
            dispatch_damage_event_partner_1(1, EVENT_SHOCK_HIT);
            return HIT_RESULT_BACKFIRE;
        }

        // check partner airlifting fiery enemy
        if (!(battleStatus->curAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_SMASH))
            && (part->eventFlags & ACTOR_EVENT_FLAG_FIREY)
            && !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_BURN_CONTACT))
        {
            sfx_play_sound_at_position(SOUND_HIT_FIRE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_damage_event_partner_1(1, EVENT_BURN_CONTACT);
            dispatch_event_actor(target, EVENT_BURN_TAUNT);
            return HIT_RESULT_BACKFIRE;
        }
        dispatch_event_actor(target, EVENT_BEGIN_AIR_LIFT);
    }
    return HIT_RESULT_HIT;
}

HitResult calc_partner_damage_enemy(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    s32 currentTargetID = battleStatus->curTargetID;
    s32 currentTargetPartID = battleStatus->curTargetPart;
    s32 hitResult = HIT_RESULT_HIT;
    s32 partImmuneToElement = FALSE;
    s32 isFireDamage = FALSE;
    s32 isWaterDamage = FALSE;
    s32 isShockDamage = FALSE;
    s32 isIceDamage = FALSE;
    s32 wasSpecialHit = FALSE;
    s32 wasStatusInflicted = FALSE;
    Actor* target;
    ActorPart* targetPart;
    ActorState* state;
    Evt* evt;
    s32 statusChanceOrDefense;
    s32 damageDealt;
    s32 dispatchEvent;

    battleStatus->wasStatusInflicted = FALSE;
    battleStatus->lastAttackDamage = 0;
    battleStatus->attackerActorID = partner->actorID;
    battleStatus->curTargetID2 = battleStatus->curTargetID;
    battleStatus->curTargetPart2 = battleStatus->curTargetPart;
    target = get_actor(currentTargetID);
    state = &partner->state;

    if (target == NULL) {
        return HIT_RESULT_HIT;
    }

    targetPart = get_actor_part(target, currentTargetPartID);

    ASSERT(targetPart != NULL);

    target->lastDamageTaken = 0;

    if (gBattleStatus.flags1 & BS_FLAGS1_FORCE_IMMUNE_HIT) {
        hitResult = HIT_RESULT_NO_DAMAGE;
        dispatchEvent = EVENT_ZERO_DAMAGE;
        sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    } else {
        if ((targetPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY)
            || (target->transparentStatus == STATUS_KEY_TRANSPARENT)
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
        if (battleStatus->curAttackElement & DAMAGE_TYPE_JUMP
            && targetPart->eventFlags & ACTOR_EVENT_FLAG_SPIKY_TOP
        ) {
            sfx_play_sound_at_position(SOUND_HIT_SPIKE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_damage_event_partner_1(1, EVENT_SPIKE_CONTACT);
            dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
            return HIT_RESULT_BACKFIRE;
        }

        // check explode on contact
        if (!(battleStatus->curAttackElement & DAMAGE_TYPE_NO_CONTACT)
            && targetPart->eventFlags & ACTOR_EVENT_FLAG_EXPLODE_ON_CONTACT
        ) {
            dispatch_event_actor(target, EVENT_EXPLODE_TRIGGER);

            if (!(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_EXPLODE_CONTACT)) {
                sfx_play_sound_at_position(SOUND_HIT_FIRE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                dispatch_damage_event_partner_1(1, EVENT_BURN_CONTACT);
                return HIT_RESULT_BACKFIRE;
            }

            sfx_play_sound_at_position(SOUND_HIT_FIRE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            
            if (gBattleStatus.flags1 & (BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)) {
                return HIT_RESULT_NICE;
            } else {
                return HIT_RESULT_HIT;
            }
        }

        // check touching fiery enemy
        if (!(battleStatus->curAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_SMASH))
            && targetPart->eventFlags & ACTOR_EVENT_FLAG_FIREY
            && !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_BURN_CONTACT)
        ) {
            sfx_play_sound_at_position(SOUND_HIT_FIRE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_damage_event_partner_1(1, EVENT_BURN_CONTACT);
            dispatch_event_actor(target, EVENT_BURN_TAUNT);
            return HIT_RESULT_BACKFIRE;
        }

        // check touching spiky-front enemy
        if (!(battleStatus->curAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_JUMP))
            && targetPart->eventFlags & ACTOR_EVENT_FLAG_SPIKY_FRONT
            && !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_SPIKY_FRONT)
        ) {
            sfx_play_sound_at_position(SOUND_HIT_SPIKE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_damage_event_partner_1(1, EVENT_SPIKE_CONTACT);
            dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
            return HIT_RESULT_BACKFIRE;
        }

        // check explode on ignition
        if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS
            && battleStatus->curAttackElement & DAMAGE_TYPE_FIRE
            && targetPart->eventFlags & (ACTOR_EVENT_FLAG_FIRE_EXPLODE | ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION)
        ) {
            sfx_play_sound_at_position(SOUND_HIT_FIRE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_event_actor(target, EVENT_EXPLODE_TRIGGER);

            if (gBattleStatus.flags1 & (BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)) {
                return HIT_RESULT_NICE;
            } else {
                return HIT_RESULT_HIT;
            }
        }

        // unknown alternate spiky #1
        if (!(battleStatus->curAttackElement & DAMAGE_TYPE_NO_CONTACT)
            && targetPart->eventFlags & ACTOR_EVENT_FLAG_ALT_SPIKY
            && !(target->flags & ACTOR_FLAG_UPSIDE_DOWN)
            && !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_ALT_SPIKY)
        ) {
            sfx_play_sound_at_position(SOUND_HIT_SPIKE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_damage_event_partner_1(1, EVENT_SPIKE_CONTACT);
            dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
            return HIT_RESULT_BACKFIRE;
        }

        // unknown alternate spiky top
        if (!(battleStatus->curAttackElement & DAMAGE_TYPE_NO_CONTACT)
            && targetPart->eventFlags & ACTOR_EVENT_FLAG_SPIKY_TOP
            && !(target->flags & ACTOR_FLAG_UPSIDE_DOWN)
            && !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_SPIKY_TOP)
        ) {
            sfx_play_sound_at_position(SOUND_HIT_SPIKE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_damage_event_partner_1(1, EVENT_SPIKE_CONTACT);
            dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
            return HIT_RESULT_BACKFIRE;
        }

         // check explode on ignition (duplicate of previous check)
        if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS
            && battleStatus->curAttackElement & DAMAGE_TYPE_FIRE
            && targetPart->eventFlags & (ACTOR_EVENT_FLAG_FIRE_EXPLODE | ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION)
        ) {
            sfx_play_sound_at_position(SOUND_HIT_FIRE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_event_actor(target, EVENT_EXPLODE_TRIGGER);

            if (gBattleStatus.flags1 & (BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)) {
                return HIT_RESULT_NICE;
            } else {
                return HIT_RESULT_HIT;
            }
        }

        // check shock contact for airlift
        if (battleStatus->curAttackElement & DAMAGE_TYPE_AIR_LIFT) {
            if (partner->staticStatus != STATUS_KEY_STATIC
                && (target->staticStatus == STATUS_KEY_STATIC || targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED)
                && !(battleStatus->curAttackElement & DAMAGE_TYPE_NO_CONTACT)
                && !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_SHOCK_CONTACT)
            ) {
                sfx_play_sound_at_position(SOUND_HIT_SHOCK, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                apply_shock_effect(partner);
                dispatch_damage_event_partner_1(1, EVENT_SHOCK_HIT);
                return HIT_RESULT_BACKFIRE;
            } else {
                return HIT_RESULT_HIT;
            }
        }

        if (battleStatus->curAttackElement & DAMAGE_TYPE_FIRE) {
            fx_ring_blast(0, state->goalPos.x, state->goalPos.y, state->goalPos.z + 5.0f, 1.0f, 24);
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

        if (partner->staticStatus != STATUS_KEY_STATIC
            && (target->staticStatus == STATUS_KEY_STATIC || targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED)
            && !(battleStatus->curAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_SHOCK))
            && !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_SHOCK_CONTACT)
        ) {
            gBattleStatus.flags1 |= BS_FLAGS1_TRIGGER_EVENTS;
        }

        if (targetPart->eventFlags & (ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED | ACTOR_EVENT_FLAG_ENCHANTED)) {
            battleStatus->curAttackElement &= ~DAMAGE_TYPE_IGNORE_DEFENSE;
        }

        statusChanceOrDefense = get_defense(target, targetPart->defenseTable, battleStatus->curAttackElement);

        if (!(battleStatus->curAttackElement & DAMAGE_TYPE_IGNORE_DEFENSE)) {
            statusChanceOrDefense += target->defenseBoost;
        }

        damageDealt = battleStatus->curAttackDamage + partner->attackBoost;

        if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) {
            if (battleStatus->curAttackElement & DAMAGE_TYPE_BLAST
                && targetPart->eventFlags & ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION
            ) {
                statusChanceOrDefense = 0;
                damageDealt = target->curHP;
            }
        }

        if (battleStatus->curAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS) {
            statusChanceOrDefense = 0;
            damageDealt = 0;
        }

        if (partner->debuff == STATUS_KEY_SHRINK) {
            if (damageDealt != 0) {
                damageDealt /= 2;

                if (damageDealt == 0) {
                    damageDealt = 1;
                }
            }
        }

        if (damageDealt > 99) {
            damageDealt = 99;
        }

        if (damageDealt < 0) {
            statusChanceOrDefense = 0;
        }

        damageDealt -= statusChanceOrDefense;
        target->hpChangeCounter = 0;

        if (damageDealt < 0) {
            damageDealt = 0;
        }

        if (battleStatus->curAttackElement & DAMAGE_TYPE_POWER_BOUNCE && damageDealt > 0) {
            damageDealt += battleStatus->powerBounceCounter;

            if (damageDealt < 1) {
                damageDealt = 1;
            }
        }

        battleStatus->lastAttackDamage = 0;

        if (damageDealt < 1) {
            target->hpChangeCounter = 0;

            if (!(battleStatus->curAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS)) {
                hitResult = HIT_RESULT_NO_DAMAGE;
                dispatchEvent = EVENT_ZERO_DAMAGE;
                sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            } else {
                hitResult = HIT_RESULT_NO_DAMAGE;
                if (target->curHP < 1) {
                    dispatchEvent = EVENT_DEATH;
                } else {
                    dispatchEvent = EVENT_ZERO_DAMAGE;
                }
            }

            battleStatus->lastAttackDamage = 0;
        } else {
            target->damageCounter += damageDealt;
            target->hpChangeCounter -= damageDealt;
            battleStatus->lastAttackDamage = 0;
            dispatchEvent = EVENT_HIT_COMBO;
            hitResult = HIT_RESULT_HIT;

            if (!(targetPart->flags & ACTOR_PART_FLAG_DAMAGE_IMMUNE)
                && !(gBattleStatus.flags1 & BS_FLAGS1_TUTORIAL_BATTLE)
                && !partImmuneToElement
                && !(targetPart->targetFlags & ACTOR_PART_TARGET_NO_DAMAGE)
            ) {
                target->curHP -= damageDealt;

                if (target->curHP < 1) {
                    target->curHP = 0;
                    dispatchEvent = EVENT_DEATH;
                }
            }

            battleStatus->lastAttackDamage += damageDealt;
            target->lastDamageTaken = battleStatus->lastAttackDamage;
            target->hpChangeCounter = 0;
        }

        if (targetPart->flags & ACTOR_PART_FLAG_DAMAGE_IMMUNE) {
            if (partner->staticStatus == STATUS_KEY_STATIC
                || !(target->staticStatus == STATUS_KEY_STATIC || (targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED))
                || battleStatus->curAttackElement & DAMAGE_TYPE_NO_CONTACT
                || battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_SHOCK_CONTACT
            ) {
                dispatchEvent = (!(gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS)) ? EVENT_ZERO_DAMAGE : EVENT_IMMUNE;
                sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                dispatch_event_actor(target, dispatchEvent);
                show_immune_bonk(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, 3);
                if (gBattleStatus.flags1 & (BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)) {
                    return HIT_RESULT_NICE;
                } else {
                    return HIT_RESULT_HIT;
                }
            }

            sfx_play_sound_at_position(SOUND_HIT_SHOCK, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            apply_shock_effect(partner);
            dispatch_damage_event_partner_1(1, EVENT_SHOCK_HIT);
            return HIT_RESULT_BACKFIRE;
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

    if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) {
        if (battleStatus->curAttackElement & DAMAGE_TYPE_SPIN_SMASH) {
            if (dispatchEvent == EVENT_HIT) {
                dispatchEvent = EVENT_SPIN_SMASH_HIT;
            }

            if (dispatchEvent == EVENT_DEATH) {
                dispatchEvent = EVENT_SPIN_SMASH_DEATH;
            }

            wasSpecialHit = TRUE;
        }

        if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) {
            if (!(battleStatus->curAttackElement & DAMAGE_TYPE_NO_CONTACT) && targetPart->eventFlags & ACTOR_EVENT_FLAG_POWER_BOUNCE) {
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

            if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) {
                if (battleStatus->curAttackElement & DAMAGE_TYPE_JUMP && targetPart->eventFlags & ACTOR_EVENT_FLAG_GROUNDABLE) {
                    if (dispatchEvent == EVENT_HIT) {
                        dispatchEvent = EVENT_FALL_TRIGGER;
                    }

                    if (dispatchEvent == EVENT_IMMUNE) {
                        dispatchEvent = EVENT_FALL_TRIGGER;
                    }

                    wasSpecialHit = TRUE;
                }

                if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) {
                    if (battleStatus->curAttackElement & DAMAGE_TYPE_JUMP && targetPart->eventFlags & ACTOR_EVENT_FLAG_FLIPABLE) {
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
            }
        }
    }

    if (!(gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS)
        && battleStatus->curAttackElement & DAMAGE_TYPE_JUMP
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

    if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS
        && battleStatus->curAttackElement & DAMAGE_TYPE_BLAST
        && targetPart->eventFlags & ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION
    ) {
        if (dispatchEvent == EVENT_DEATH) {
            dispatchEvent = EVENT_EXPLODE_TRIGGER;
        }

        if (dispatchEvent == EVENT_IMMUNE) {
            dispatchEvent = EVENT_EXPLODE_TRIGGER;
        }

        if (dispatchEvent == EVENT_HIT) {
            dispatchEvent = EVENT_EXPLODE_TRIGGER;
        }

        wasSpecialHit = TRUE;
        isFireDamage = TRUE;
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) {
        if (battleStatus->curAttackElement & (DAMAGE_TYPE_BLAST | DAMAGE_TYPE_FIRE)) {
            if (dispatchEvent == EVENT_HIT) {
                dispatchEvent = EVENT_BURN_HIT;
            }

            if (dispatchEvent == EVENT_DEATH) {
                dispatchEvent = EVENT_BURN_DEATH;
            }

            isFireDamage = TRUE;
        }

        do {    // TODO remove this do while
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

                statusChanceOrDefense = target->actorBlueprint->spookChance;

                if (statusChanceOrDefense > 0) {
                    statusChanceOrDefense = 100;
                }

                statusChanceOrDefense = (battleStatus->statusChance * statusChanceOrDefense) / 100;

                if (battleStatus->curAttackStatus & STATUS_FLAG_400000) {
                    if (rand_int(99) < statusChanceOrDefense) {
                        if (!(target->debuff == STATUS_KEY_FEAR
                            || target->debuff == STATUS_KEY_DIZZY
                            || target->debuff == STATUS_KEY_PARALYZE
                            || target->debuff == STATUS_KEY_SLEEP
                            || target->debuff == STATUS_KEY_FROZEN
                            || target->debuff == STATUS_KEY_STOP)
                            && !(target->flags & ACTOR_FLAG_FLIPPED)
                        ) {
                            dispatchEvent = EVENT_SCARE_AWAY;
                            wasStatusInflicted = TRUE;
                            hitResult = HIT_RESULT_HIT;
                            wasSpecialHit = TRUE;
                            gBattleStatus.flags1 |= BS_FLAGS1_NICE_HIT;
                            gBattleStatus.flags1 |= BS_FLAGS1_TRIGGER_EVENTS;
                            gBattleStatus.flags1 |= BS_FLAGS1_INCLUDE_POWER_UPS;
                            gBattleStatus.flags1 |= BS_FLAGS1_SHOW_PLAYER_DECORATIONS;
                            gBattleStatus.flags1 |= BS_FLAGS1_ACTORS_VISIBLE;
                            sfx_play_sound_at_position(SOUND_DAMAGE_STARS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                        } else {
                            dispatchEvent = EVENT_IMMUNE;
                            hitResult = HIT_RESULT_NO_DAMAGE;
                        }
                    } else {
                        dispatchEvent = EVENT_IMMUNE;
                        hitResult = HIT_RESULT_NO_DAMAGE;
                    }
                }

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
    }

    statusChanceOrDefense = target->actorBlueprint->spookChance;
    statusChanceOrDefense = (battleStatus->statusChance * statusChanceOrDefense) / 100;

    if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) {
        if (battleStatus->curAttackElement & DAMAGE_TYPE_FEAR) {
            if (rand_int(99) < statusChanceOrDefense) {
                if (!(target->debuff == STATUS_KEY_FEAR ||
                      target->debuff == STATUS_KEY_DIZZY ||
                      target->debuff == STATUS_KEY_PARALYZE ||
                      target->debuff == STATUS_KEY_SLEEP ||
                      target->debuff == STATUS_KEY_FROZEN ||
                      target->debuff == STATUS_KEY_STOP) && !(target->flags & ACTOR_FLAG_FLIPPED)) {
                    dispatchEvent = EVENT_SCARE_AWAY;
                    wasStatusInflicted = TRUE;
                    hitResult = HIT_RESULT_HIT;
                    wasSpecialHit = TRUE;
                    gBattleStatus.flags1 |= BS_FLAGS1_NICE_HIT;
                    gBattleStatus.flags1 |= BS_FLAGS1_TRIGGER_EVENTS;
                    gBattleStatus.flags1 |= BS_FLAGS1_INCLUDE_POWER_UPS;
                    gBattleStatus.flags1 |= BS_FLAGS1_SHOW_PLAYER_DECORATIONS;
                    gBattleStatus.flags1 |= BS_FLAGS1_ACTORS_VISIBLE;
                    sfx_play_sound_at_position(SOUND_DAMAGE_STARS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                } else {
                    dispatchEvent = EVENT_IMMUNE;
                    hitResult = HIT_RESULT_NO_DAMAGE;
                }
            } else {
                dispatchEvent = EVENT_IMMUNE;
                hitResult = HIT_RESULT_NO_DAMAGE;
            }
        }
    }

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

    if ((wasSpecialHit && gBattleStatus.flags1 & (BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT))
        || (gBattleStatus.flags1 & (BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT) && !(gBattleStatus.flags1 & BS_FLAGS1_NO_RATING))
    ) {
        if (battleStatus->lastAttackDamage > 0) {
            sfx_play_sound_at_position(SOUND_DAMAGE_STARS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        }

        if (battleStatus->lastAttackDamage > 0 || (battleStatus->curAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS && wasSpecialHit)) {
            if (gBattleStatus.flags1 & BS_FLAGS1_NICE_HIT) {
                show_action_rating(ACTION_RATING_NICE, target, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            } else {
                show_action_rating(ACTION_RATING_SUPER, target, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            }
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) {
        func_80266970(target);
    }

    if (battleStatus->lastAttackDamage > 0) {
        if (partImmuneToElement == 0) {
            if (partner->actorTypeData1[5] != 0) {
                sfx_play_sound_at_position(partner->actorTypeData1[5], SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            }

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
    }

    if (battleStatus->lastAttackDamage < 1
        && !(wasSpecialHit || wasStatusInflicted)
        || targetPart->flags & ACTOR_PART_FLAG_DAMAGE_IMMUNE
    ) {
        sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->curAttackStatus & STATUS_FLAG_SLEEP && wasStatusInflicted) {
        evt = start_script((EvtScript*) EVS_PlaySleepHitFX, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_SLEEP, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->curAttackStatus & STATUS_FLAG_DIZZY && wasStatusInflicted) {
        evt = start_script((EvtScript*) EVS_PlayDizzyHitFX, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->curAttackStatus & STATUS_FLAG_PARALYZE && wasStatusInflicted) {
        evt = start_script((EvtScript*) EVS_PlayParalyzeHitFX, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->curAttackStatus & STATUS_FLAG_POISON && wasStatusInflicted) {
        evt = start_script((EvtScript*) EVS_PlayPoisonHitFX, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->curAttackStatus & STATUS_FLAG_STOP && wasStatusInflicted) {
        evt = start_script((EvtScript*) EVS_PlayStopHitFX, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->curAttackStatus & STATUS_FLAG_FROZEN && wasStatusInflicted) {
        evt = start_script((EvtScript*) EVS_PlayFreezeHitFX, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        evt->varTablePtr[3] = target;
        sfx_play_sound_at_position(SOUND_HIT_ICE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->curAttackStatus & STATUS_FLAG_SHRINK && wasStatusInflicted) {
        evt = start_script((EvtScript*) EVS_PlayShrinkHitFX, EVT_PRIORITY_A, 0);
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

    if (partner->staticStatus != STATUS_KEY_STATIC && (target->staticStatus == STATUS_KEY_STATIC ||
            targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED) && !(battleStatus->curAttackElement & DAMAGE_TYPE_NO_CONTACT) &&
        !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_SHOCK_CONTACT)) {
        sfx_play_sound_at_position(SOUND_HIT_SHOCK, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        apply_shock_effect(partner);
        dispatch_damage_event_partner_1(1, EVENT_SHOCK_HIT);
        return HIT_RESULT_BACKFIRE;
    }

    return hitResult;
}

s32 dispatch_damage_event_partner(s32 damageAmount, s32 event, s32 stopMotion) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    ActorState* state = &partner->state;
    s32 hpChange;
    s32 flagCheck;

    battleStatus->curAttackDamage = damageAmount;

    hpChange = (s16)damageAmount;
    partner->hpChangeCounter += hpChange;

    hpChange = partner->hpChangeCounter;
    partner->curHP = 127;
    partner->damageCounter += hpChange;
    partner->hpChangeCounter -= hpChange;
    battleStatus->lastAttackDamage = 0;
    partner->curHP -= hpChange;

    if (partner->curHP <= 0) {
        event = EVENT_DEATH;
        battleStatus->lastAttackDamage += partner->curHP;
        partner->curHP = 0;
    }

    battleStatus->lastAttackDamage += hpChange;
    partner->lastDamageTaken = battleStatus->lastAttackDamage;
    battleStatus->curDamageSource = DMG_SRC_DEFAULT;
    if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) {
        if (event == EVENT_HIT_COMBO) {
            event = EVENT_HIT;
        }
        if (event == EVENT_ZERO_DAMAGE) {
            event = EVENT_IMMUNE;
        }
    }

    if (battleStatus->lastAttackDamage > 0) {
        gBattleStatus.flags1 |= BS_FLAGS1_TRIGGER_EVENTS;

        inflict_status(partner, STATUS_KEY_DAZE, battleStatus->lastAttackDamage);
    }

    if (!stopMotion) {
        set_goal_pos_to_part(state, ACTOR_PARTNER, 0);
    }

    show_next_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z,
                      battleStatus->lastAttackDamage, 1);
    show_damage_fx(partner, state->goalPos.x, state->goalPos.y, state->goalPos.z,
                  battleStatus->lastAttackDamage);

    if (battleStatus->lastAttackDamage > 0) {
        set_actor_flash_mode(partner, 1);
    }

    partner->flags |= ACTOR_FLAG_HEALTH_BAR_HIDDEN;

    flagCheck = (gBattleStatus.flags1 & (BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)) != 0;
    dispatch_event_partner(event);
    return flagCheck;
}

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
    s8* targetList = actor->targetIndexList;
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
        actor->targetPartID = selectableTarget->partID;
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
    battleStatus->flags1 |= BS_FLAGS1_TRIGGER_EVENTS;

    hitResult = calc_partner_damage_enemy();
    show_next_damage_popup(actor->state.goalPos.x, actor->state.goalPos.y, actor->state.goalPos.z, battleStatus->lastAttackDamage,
                      0);
    evt_set_variable(script, outVar, hitResult);

    return ApiStatus_DONE2;
}

ApiStatus GetActorLevel(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Bytecode outVar;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.enemyID;
    }

    outVar = *args++;
    evt_set_variable(script, outVar, get_actor(actorID)->actorBlueprint->level);

    return ApiStatus_DONE2;
}

ApiStatus PartnerDamageEnemy(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerStatus* playerStatus = &gPlayerStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* enemy = get_actor(script->owner1.enemyID);
    s32 temp_s4 = *args++;
    s32 flags;
    s32 damageResult;
    u8 statusChance;

    gBattleStatus.curAttackElement = *args++;
    gBattleStatus.curAttackEventSuppression = *args++;
    gBattleStatus.curAttackStatus = *args++;
    gBattleStatus.curAttackDamage = evt_get_variable(script, *args++);
    gBattleStatus.powerBounceCounter = 0;
    flags = *args++;

    if ((flags & BS_FLAGS1_INCLUDE_POWER_UPS) && (flags & BS_FLAGS1_TRIGGER_EVENTS)) {
        battleStatus->flags1 |= BS_FLAGS1_INCLUDE_POWER_UPS;
        battleStatus->flags1 |= BS_FLAGS1_TRIGGER_EVENTS;
    } else if (flags & BS_FLAGS1_INCLUDE_POWER_UPS) {
        battleStatus->flags1 |= BS_FLAGS1_INCLUDE_POWER_UPS;
        battleStatus->flags1 &= ~BS_FLAGS1_TRIGGER_EVENTS;
    } else if (flags & BS_FLAGS1_TRIGGER_EVENTS) {
        battleStatus->flags1 &= ~BS_FLAGS1_INCLUDE_POWER_UPS;
        battleStatus->flags1 |= BS_FLAGS1_TRIGGER_EVENTS;
    } else {
        battleStatus->flags1 &= ~BS_FLAGS1_INCLUDE_POWER_UPS;
        battleStatus->flags1 &= ~BS_FLAGS1_TRIGGER_EVENTS;
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

    statusChance = battleStatus->curAttackStatus;
    battleStatus->curTargetID = enemy->targetActorID;
    battleStatus->curTargetPart = enemy->targetPartID;
    battleStatus->statusChance = statusChance;

    if (statusChance == STATUS_KEY_NEVER) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->curAttackStatus & 0xF00) >> 8;
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

    battleStatus->curAttackElement = *args++;
    battleStatus->curAttackEventSuppression = *args++;
    battleStatus->curAttackStatus = *args++;
    battleStatus->curAttackStatus |= evt_get_variable(script, *args++);
    battleStatus->curAttackDamage = evt_get_variable(script, *args++);
    battleStatus->powerBounceCounter = 0;
    flags = *args++;

    if ((flags & BS_FLAGS1_INCLUDE_POWER_UPS) && (flags & BS_FLAGS1_TRIGGER_EVENTS)) {
        battleStatus->flags1 |= BS_FLAGS1_INCLUDE_POWER_UPS;
        battleStatus->flags1 |= BS_FLAGS1_TRIGGER_EVENTS;
    } else if (flags & BS_FLAGS1_INCLUDE_POWER_UPS) {
        battleStatus->flags1 |= BS_FLAGS1_INCLUDE_POWER_UPS;
        battleStatus->flags1 &= ~BS_FLAGS1_TRIGGER_EVENTS;
    } else if (flags & BS_FLAGS1_TRIGGER_EVENTS) {
        battleStatus->flags1 &= ~BS_FLAGS1_INCLUDE_POWER_UPS;
        battleStatus->flags1 |= BS_FLAGS1_TRIGGER_EVENTS;
    } else {
        battleStatus->flags1 &= ~BS_FLAGS1_INCLUDE_POWER_UPS;
        battleStatus->flags1 &= ~BS_FLAGS1_TRIGGER_EVENTS;
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

    statusChance = battleStatus->curAttackStatus;
    battleStatus->curTargetID = actor->targetActorID;
    battleStatus->curTargetPart = actor->targetPartID;
    battleStatus->statusChance = statusChance;

    if (statusChance == STATUS_KEY_NEVER) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->curAttackStatus & 0xF00) >> 8;
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

    battleStatus->curAttackElement = *args++;
    battleStatus->curAttackEventSuppression = *args++;
    battleStatus->curAttackStatus = *args++;
    battleStatus->curAttackDamage = evt_get_variable(script, *args++);
    battleStatus->powerBounceCounter = evt_get_variable(script, *args++);
    flags = *args++;

    if ((flags & BS_FLAGS1_INCLUDE_POWER_UPS) && (flags & BS_FLAGS1_TRIGGER_EVENTS)) {
        battleStatus->flags1 |= BS_FLAGS1_INCLUDE_POWER_UPS;
        battleStatus->flags1 |= BS_FLAGS1_TRIGGER_EVENTS;
    } else if (flags & BS_FLAGS1_INCLUDE_POWER_UPS) {
        battleStatus->flags1 |= BS_FLAGS1_INCLUDE_POWER_UPS;
        battleStatus->flags1 &= ~BS_FLAGS1_TRIGGER_EVENTS;
    } else if (flags & BS_FLAGS1_TRIGGER_EVENTS) {
        battleStatus->flags1 &= ~BS_FLAGS1_INCLUDE_POWER_UPS;
        battleStatus->flags1 |= BS_FLAGS1_TRIGGER_EVENTS;
    } else {
        battleStatus->flags1 &= ~BS_FLAGS1_INCLUDE_POWER_UPS;
        battleStatus->flags1 &= ~BS_FLAGS1_TRIGGER_EVENTS;
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

    statusChance = battleStatus->curAttackStatus;
    battleStatus->curTargetID = actor->targetActorID;
    battleStatus->curTargetPart = actor->targetPartID;
    battleStatus->statusChance = statusChance;

    if (statusChance == STATUS_KEY_NEVER) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->curAttackStatus & 0xF00) >> 8;
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
    Actor* enemy = get_actor(script->owner1.enemyID);
    s32 outVar;
    s32 flags;
    s32 damageResult;
    u8 statusChance;

    outVar = *args++;
    gBattleStatus.curAttackElement = *args++;
    gBattleStatus.curAttackEventSuppression = *args++;
    gBattleStatus.curAttackStatus = *args++;
    gBattleStatus.curAttackDamage = evt_get_variable(script, *args++);
    gBattleStatus.powerBounceCounter = 0;
    flags = *args++;

    if ((flags & BS_FLAGS1_INCLUDE_POWER_UPS) && (flags & BS_FLAGS1_TRIGGER_EVENTS)) {
        battleStatus->flags1 |= BS_FLAGS1_INCLUDE_POWER_UPS;
        battleStatus->flags1 |= BS_FLAGS1_TRIGGER_EVENTS;
    } else if (flags & BS_FLAGS1_INCLUDE_POWER_UPS) {
        battleStatus->flags1 |= BS_FLAGS1_INCLUDE_POWER_UPS;
        battleStatus->flags1 &= ~BS_FLAGS1_TRIGGER_EVENTS;
    } else if (flags & BS_FLAGS1_TRIGGER_EVENTS) {
        battleStatus->flags1 &= ~BS_FLAGS1_INCLUDE_POWER_UPS;
        battleStatus->flags1 |= BS_FLAGS1_TRIGGER_EVENTS;
    } else {
        battleStatus->flags1 &= ~BS_FLAGS1_INCLUDE_POWER_UPS;
        battleStatus->flags1 &= ~BS_FLAGS1_TRIGGER_EVENTS;
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

    statusChance = battleStatus->curAttackStatus;
    battleStatus->curTargetID = enemy->targetActorID;
    battleStatus->curTargetPart = enemy->targetPartID;
    battleStatus->statusChance = statusChance;

    if (statusChance == STATUS_KEY_NEVER) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->curAttackStatus & 0xF00) >> 8;
    damageResult = calc_partner_test_enemy();

    if (damageResult < 0) {
        return ApiStatus_FINISH;
    }

    evt_set_variable(script, outVar, damageResult);

    return ApiStatus_DONE2;
}

ApiStatus func_8028070C(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* actor = get_actor(script->owner1.actorID);
    s32 damageAmount = evt_get_variable(script, *args++);
    s32 event = evt_get_variable(script, *args++);

    battleStatus->curTargetID = actor->targetActorID;
    battleStatus->curTargetPart = actor->targetPartID;

    if (dispatch_damage_event_partner_0(damageAmount, event, (s32) battleStatus) >= 0) {
        return does_script_exist_by_ref(script) ? ApiStatus_DONE2 : ApiStatus_BLOCK;
    }

    return ApiStatus_BLOCK;
}

ApiStatus DeletePartner(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;

    btl_delete_actor(battleStatus->partnerActor);
    return ApiStatus_DONE2;
}

ApiStatus GetPartnerActionSuccess(Evt* script, s32 isInitialCall) {
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
ApiStatus PartnerYieldTurn(Evt* script, s32 isInitialCall) {
    gBattleStatus.flags1 |= BS_FLAGS1_YIELD_TURN;
    return ApiStatus_DONE2;
}
