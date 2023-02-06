#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"

s32 calc_partner_damage_enemy(void);
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

s32 calc_partner_test_enemy(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    s32 currentTargetID = battleStatus->currentTargetID;
    s32 currentTargetPart = battleStatus->currentTargetPart;
    Actor* target;
    ActorState* state;
    ActorPart* part;

    battleStatus->currentTargetID2 = battleStatus->currentTargetID;
    battleStatus->currentTargetPart2 = battleStatus->currentTargetPart;
    target = get_actor(currentTargetID);
    state = &partner->state;
    if (target != NULL) {
        part = get_actor_part(target, currentTargetPart);
        ASSERT(part != NULL);

        if (target->stoneStatus == STATUS_STONE) {
            return 8;
        }

        if ((part->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) || target->transparentStatus == STATUS_TRANSPARENT) {
            return 6;
        }

        // TODO not sure about the flags2
        if ((battleStatus->currentAttackElement & DAMAGE_TYPE_JUMP) &&
            (part->eventFlags & ACTOR_EVENT_FLAG_SPIKY_TOP) &&
            !(target->flags2 & ACTOR_FLAG_HP_OFFSET_BELOW))
        {
            sfx_play_sound_at_position(SOUND_108, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            return 4;
        }

        if (!(battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_JUMP)) &&
            (part->eventFlags & ACTOR_EVENT_FLAG_SPIKY_FRONT) &&
            !(battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_4) &&
            !player_team_is_ability_active(partner, ABILITY_SPIKE_SHIELD))
        {
            sfx_play_sound_at_position(SOUND_108, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_damage_event_partner_1(1, EVENT_SPIKE_CONTACT);
            dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
            return -1;
        }

        if (!(battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_SMASH)) &&
            (part->eventFlags & ACTOR_EVENT_FLAG_FIREY) &&
            !(battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_10))
        {
            sfx_play_sound_at_position(SOUND_HIT_FIRE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_damage_event_partner_1(1, EVENT_BURN_CONTACT);
            dispatch_event_actor(target, EVENT_BURN_TAUNT);
            return -1;
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_AIR_LIFT) {
            if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT)) {
                if ((part->eventFlags & ACTOR_EVENT_FLAG_SPIKY_TOP) &&
                    !(target->flags & ACTOR_FLAG_HP_OFFSET_BELOW) &&
                    !(battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_1))
                {
                    sfx_play_sound_at_position(SOUND_108, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    dispatch_damage_event_partner_1(1, EVENT_SPIKE_CONTACT);
                    dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
                    return -1;
                }

                if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT) &&
                    (part->eventFlags & ACTOR_EVENT_FLAG_200000) &&
                    !(target->flags & ACTOR_FLAG_HP_OFFSET_BELOW) &&
                    !(battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_80))
                {
                    sfx_play_sound_at_position(SOUND_108, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    dispatch_damage_event_partner_1(1, EVENT_SPIKE_CONTACT);
                    dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
                    return -1;
                }
            }

            if (partner->staticStatus != STATUS_STATIC &&
                (target->staticStatus == STATUS_STATIC || (part->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED)) &&
                !(battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT) &&
                !(battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_8))
            {
                sfx_play_sound_at_position(SOUND_HIT_SHOCK, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                func_80251474(partner);
                dispatch_damage_event_partner_1(1, EVENT_SHOCK_HIT);
                return -1;
            }

            if (!(battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_SMASH)) &&
                (part->eventFlags & ACTOR_EVENT_FLAG_FIREY) &&
                !(battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_10))
            {
                sfx_play_sound_at_position(SOUND_HIT_FIRE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                dispatch_damage_event_partner_1(1, EVENT_BURN_CONTACT);
                dispatch_event_actor(target, EVENT_BURN_TAUNT);
                return -1;
            }
            dispatch_event_actor(target, EVENT_BEGIN_AIR_LIFT);
        }
    }
    return 0;
}

s32 calc_partner_damage_enemy(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    s32 currentTargetID = battleStatus->currentTargetID;
    s32 currentTargetPartID = battleStatus->currentTargetPart;
    s32 retVal;
    s32 sp2C = FALSE;
    s32 isFireDamage = FALSE;
    s32 isElectricDamage = FALSE;
    s32 isIceDamage = FALSE;
    s32 tempBinary = FALSE;
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
    battleStatus->currentTargetID2 = battleStatus->currentTargetID;
    battleStatus->currentTargetPart2 = battleStatus->currentTargetPart;
    target = get_actor(currentTargetID);
    state = &partner->state;

    if (target == NULL) {
        return 0;
    }

    targetPart = get_actor_part(target, currentTargetPartID);

    ASSERT(targetPart != NULL);

    target->lastDamageTaken = 0;

    if (gBattleStatus.flags1 & BS_FLAGS1_FORCE_HIT_IMMUNE) {
        retVal = 2;
        dispatchEvent = EVENT_SCRIPTED_IMMUNE;
        sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    } else {
        if (targetPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY || target->transparentStatus == STATUS_TRANSPARENT ||
            targetPart->eventFlags & ACTOR_EVENT_FLAG_800 && !(battleStatus->currentAttackElement & DAMAGE_TYPE_QUAKE)) {
            return 6;
        }

        if (target->stoneStatus == STATUS_STONE) {
            sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            func_8024EFE0(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, 1);
            show_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 0);
            return (gBattleStatus.flags1 & (BS_FLAGS1_40 | BS_FLAGS1_200)) ? 1 : 0;
        }

        if (targetPart->partFlags3 & battleStatus->currentAttackElement) {
            sp2C = 1;
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_JUMP && targetPart->eventFlags & ACTOR_EVENT_FLAG_SPIKY_TOP) {
            sfx_play_sound_at_position(SOUND_108, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_damage_event_partner_1(1, EVENT_SPIKE_CONTACT);
            dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
            return -1;
        } else if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT) && targetPart->eventFlags & ACTOR_EVENT_FLAG_8000) {
            dispatch_event_actor(target, EVENT_EXPLODE_TRIGGER);

            if (!(battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_2)) {
                sfx_play_sound_at_position(SOUND_HIT_FIRE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                dispatch_damage_event_partner_1(1, EVENT_BURN_CONTACT);
                return -1;
            }

            sfx_play_sound_at_position(SOUND_HIT_FIRE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            return (gBattleStatus.flags1 & (BS_FLAGS1_40 | BS_FLAGS1_200)) ? 1 : 0;
        } else if (!(battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_SMASH)) &&
                   targetPart->eventFlags & ACTOR_EVENT_FLAG_FIREY && !(battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_10)) {
            sfx_play_sound_at_position(SOUND_HIT_FIRE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_damage_event_partner_1(1, EVENT_BURN_CONTACT);
            dispatch_event_actor(target, EVENT_BURN_TAUNT);
            return -1;
        } else if (!(battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_JUMP)) &&
                   targetPart->eventFlags & ACTOR_EVENT_FLAG_SPIKY_FRONT && !(battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_4)) {
            sfx_play_sound_at_position(SOUND_108, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_damage_event_partner_1(1, EVENT_SPIKE_CONTACT);
            dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
            return -1;
        } else if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE && battleStatus->currentAttackElement & DAMAGE_TYPE_FIRE &&
                   targetPart->eventFlags & (ACTOR_EVENT_FLAG_400 | ACTOR_EVENT_FLAG_EXPLOSIVE)) {
            sfx_play_sound_at_position(SOUND_HIT_FIRE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_event_actor(target, EVENT_EXPLODE_TRIGGER);
            return (gBattleStatus.flags1 & (BS_FLAGS1_40 | BS_FLAGS1_200)) ? 1 : 0;
        } else if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT) && targetPart->eventFlags & ACTOR_EVENT_FLAG_200000 &&
                   !(target->flags & ACTOR_FLAG_HP_OFFSET_BELOW) && !(battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_80)) {
            sfx_play_sound_at_position(SOUND_108, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_damage_event_partner_1(1, EVENT_SPIKE_CONTACT);
            dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
            return -1;
        } else if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT) && targetPart->eventFlags & ACTOR_EVENT_FLAG_SPIKY_TOP &&
                   !(target->flags & ACTOR_FLAG_HP_OFFSET_BELOW) && !(battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_1)) {
            sfx_play_sound_at_position(SOUND_108, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_damage_event_partner_1(1, EVENT_SPIKE_CONTACT);
            dispatch_event_actor(target, EVENT_SPIKE_TAUNT);
            return -1;
        } else if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE && battleStatus->currentAttackElement & DAMAGE_TYPE_FIRE &&
                   targetPart->eventFlags & (ACTOR_EVENT_FLAG_400 | ACTOR_EVENT_FLAG_EXPLOSIVE)) {
            sfx_play_sound_at_position(SOUND_HIT_FIRE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            dispatch_event_actor(target, EVENT_EXPLODE_TRIGGER);
            return (gBattleStatus.flags1 & (BS_FLAGS1_40 | BS_FLAGS1_200)) ? 1 : 0;
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_AIR_LIFT) {
            if (partner->staticStatus != STATUS_STATIC && (target->staticStatus == STATUS_STATIC ||
                    targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED) && !(battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT) &&
                !(battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_8)) {
                sfx_play_sound_at_position(SOUND_HIT_SHOCK, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                func_80251474(partner);
                dispatch_damage_event_partner_1(1, EVENT_SHOCK_HIT);
                return -1;
            }

            return 0;
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_FIRE) {
            fx_ring_blast(0, state->goalPos.x, state->goalPos.y, state->goalPos.z + 5.0f, 1.0f, 0x18);
            isFireDamage = TRUE;
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_ELECTRIC) {
            func_80251474(target);
            isElectricDamage = TRUE;
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_WATER) {
            fx_water_splash(0, state->goalPos.x, state->goalPos.y, state->goalPos.z + 5.0f, 1.0f, 0x18);
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_ICE) {
            fx_big_snowflakes(0, state->goalPos.x, state->goalPos.y, state->goalPos.z + 5.0f);
            isIceDamage = TRUE;
        }

        if (partner->staticStatus != STATUS_STATIC && (target->staticStatus == STATUS_STATIC ||
                targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED) &&
            !(battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_ELECTRIC)) &&
            !(battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_8)) {
            gBattleStatus.flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;
        }

        if (targetPart->eventFlags & (ACTOR_EVENT_FLAG_80000 | ACTOR_EVENT_FLAG_ENCHANTED)) {
            battleStatus->currentAttackElement &= ~DAMAGE_TYPE_IGNORE_DEFENSE;
        }

        statusChanceOrDefense = get_defense(target, targetPart->defenseTable, battleStatus->currentAttackElement);

        if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_IGNORE_DEFENSE)) {
            statusChanceOrDefense += target->defenseBoost;
        }

        damageDealt = battleStatus->currentAttackDamage + partner->attackBoost;

        if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
            if (battleStatus->currentAttackElement & DAMAGE_TYPE_BLAST) {
                if (targetPart->eventFlags & ACTOR_EVENT_FLAG_EXPLOSIVE) {
                    statusChanceOrDefense = 0;
                    damageDealt = target->currentHP;
                }
            }
        }

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS) {
            statusChanceOrDefense = 0;
            damageDealt = 0;
        }

        if (partner->debuff == STATUS_SHRINK) {
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

        if (battleStatus->currentAttackElement & DAMAGE_TYPE_POWER_BOUNCE && damageDealt > 0) {
            damageDealt += battleStatus->powerBounceCounter;

            if (damageDealt < 1) {
                damageDealt = 1;
            }
        }

        battleStatus->lastAttackDamage = 0;

        if (damageDealt < 1) {
            target->hpChangeCounter = 0;

            if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS)) {
                retVal = 2;
                dispatchEvent = EVENT_SCRIPTED_IMMUNE;
                sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            } else {
                retVal = 2;
                dispatchEvent = (target->currentHP <= 0) ? EVENT_DEATH : EVENT_SCRIPTED_IMMUNE;
            }

            battleStatus->lastAttackDamage = 0;
        } else {
            target->damageCounter += damageDealt;
            target->hpChangeCounter -= damageDealt;
            battleStatus->lastAttackDamage = 0;
            dispatchEvent = EVENT_HIT_COMBO;
            retVal = 0;

            if (!(targetPart->flags & ACTOR_PART_FLAG_2000) && !(gBattleStatus.flags1 & BS_FLAGS1_TUTORIAL_BATTLE) && !sp2C && !(targetPart->targetFlags & ACTOR_PART_FLAG_4)) {
                target->currentHP -= damageDealt;

                if (target->currentHP <= 0) {
                    target->currentHP = 0;
                    dispatchEvent = EVENT_DEATH;
                }
            }

            battleStatus->lastAttackDamage += damageDealt;
            target->lastDamageTaken = battleStatus->lastAttackDamage;
            target->hpChangeCounter = 0;
        }

        if (targetPart->flags & ACTOR_PART_FLAG_2000) {
            if (partner->staticStatus == STATUS_STATIC || (target->staticStatus != STATUS_STATIC &&
                    !(targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED)) || battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT ||
                battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_8) {
                dispatchEvent = (!(gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE)) ? EVENT_SCRIPTED_IMMUNE : EVENT_IMMUNE;
                sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                dispatch_event_actor(target, dispatchEvent);
                func_8024EFE0(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, 3);
                return (gBattleStatus.flags1 & (BS_FLAGS1_40 | BS_FLAGS1_200)) ? 1 : 0;
            }

            sfx_play_sound_at_position(SOUND_HIT_SHOCK, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            func_80251474(partner);
            dispatch_damage_event_partner_1(1, EVENT_SHOCK_HIT);
            return -1;
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (dispatchEvent == EVENT_HIT_COMBO) {
            dispatchEvent = EVENT_HIT;
        }

        if (dispatchEvent == EVENT_SCRIPTED_IMMUNE) {
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
        (func_80266E14(targetPart), gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE)) {  // TODO remove func_80266E14 from conditional
        if (battleStatus->currentAttackElement & DAMAGE_TYPE_SPIN_SMASH) {
            if (dispatchEvent == EVENT_HIT) {
                dispatchEvent = EVENT_SPIN_SMASH_HIT;
            }

            if (dispatchEvent == EVENT_DEATH) {
                dispatchEvent = EVENT_SPIN_SMASH_DEATH;
            }

            tempBinary = TRUE;
        }

        if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
            if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT) && targetPart->eventFlags & ACTOR_EVENT_FLAG_POWER_BOUNCE) {
                if (dispatchEvent == EVENT_HIT_COMBO) {
                    dispatchEvent = EVENT_POWER_BOUNCE_HIT;
                }

                if (dispatchEvent == EVENT_HIT) {
                    dispatchEvent = EVENT_POWER_BOUNCE_HIT;
                }

                if (dispatchEvent == EVENT_SCRIPTED_IMMUNE) {
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
                if (battleStatus->currentAttackElement & DAMAGE_TYPE_JUMP && targetPart->eventFlags & ACTOR_EVENT_FLAG_GROUNDABLE) {
                    if (dispatchEvent == EVENT_HIT) {
                        dispatchEvent = EVENT_FALL_TRIGGER;
                    }

                    if (dispatchEvent == EVENT_IMMUNE) {
                        dispatchEvent = EVENT_FALL_TRIGGER;
                    }

                    tempBinary = TRUE;
                }

                if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
                    if (battleStatus->currentAttackElement & DAMAGE_TYPE_JUMP && targetPart->eventFlags & ACTOR_EVENT_FLAG_FLIPABLE) {
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

    if (!(gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) && battleStatus->currentAttackElement & DAMAGE_TYPE_JUMP &&
        targetPart->eventFlags & ACTOR_EVENT_FLAG_FLIPABLE) {
        if (dispatchEvent == EVENT_HIT_COMBO) {
            dispatchEvent = EVENT_FLIP_TRIGGER;
        }

        if (dispatchEvent == EVENT_SCRIPTED_IMMUNE) {
            dispatchEvent = EVENT_FLIP_TRIGGER;
        }

        if (!(target->flags & ACTOR_FLAG_400)) {
            tempBinary = TRUE;
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (battleStatus->currentAttackElement & DAMAGE_TYPE_BLAST && targetPart->eventFlags & ACTOR_EVENT_FLAG_EXPLOSIVE) {
            if (dispatchEvent == EVENT_DEATH) {
                dispatchEvent = EVENT_EXPLODE_TRIGGER;
            }

            if (dispatchEvent == EVENT_IMMUNE) {
                dispatchEvent = EVENT_EXPLODE_TRIGGER;
            }

            if (dispatchEvent == EVENT_HIT) {
                dispatchEvent = EVENT_EXPLODE_TRIGGER;
            }

            tempBinary = TRUE;
            isFireDamage = TRUE;
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

            do {    // TODO remove this do while
                if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE && battleStatus->lastAttackDamage >= 0 && dispatchEvent != EVENT_DEATH &&
                    dispatchEvent != EVENT_SPIN_SMASH_DEATH &&
                    dispatchEvent != EVENT_EXPLODE_TRIGGER && !(targetPart->targetFlags & ACTOR_PART_FLAG_4)) {
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

                    statusChanceOrDefense = target->actorBlueprint->spookChance;

                    if (statusChanceOrDefense > 0) {
                        statusChanceOrDefense = 100;
                    }

                    statusChanceOrDefense = (battleStatus->statusChance * statusChanceOrDefense) / 100;

                    if (battleStatus->currentAttackStatus & STATUS_FLAG_400000) {
                        if (rand_int(99) < statusChanceOrDefense) {
                            if (!(target->debuff == STATUS_FEAR ||
                                  target->debuff == STATUS_DIZZY ||
                                  target->debuff == STATUS_PARALYZE ||
                                  target->debuff == STATUS_SLEEP ||
                                  target->debuff == STATUS_FROZEN ||
                                  target->debuff == STATUS_STOP) && !(target->flags & ACTOR_FLAG_400)) {
                                dispatchEvent = EVENT_SCARE_AWAY;
                                wasStatusInflicted = TRUE;
                                retVal = 0;
                                tempBinary = TRUE;
                                gBattleStatus.flags1 |= (BS_FLAGS1_40 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10 | BS_FLAGS1_8 | BS_FLAGS1_ACTORS_VISIBLE);
                                sfx_play_sound_at_position(SOUND_231, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                            } else {
                                dispatchEvent = EVENT_IMMUNE;
                                retVal = 2;
                            }
                        } else {
                            dispatchEvent = EVENT_IMMUNE;
                            retVal = 2;
                        }
                    }

                    if (wasStatusInflicted) {
                        if (dispatchEvent == EVENT_SCRIPTED_IMMUNE) {
                            dispatchEvent = EVENT_HIT_COMBO;
                        }

                        if (dispatchEvent == EVENT_IMMUNE) {
                            dispatchEvent = EVENT_HIT;
                        }
                    }
                }
            } while (0);
        }
    }

    statusChanceOrDefense = target->actorBlueprint->spookChance;
    statusChanceOrDefense = (battleStatus->statusChance * statusChanceOrDefense) / 100;

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (battleStatus->currentAttackElement & DAMAGE_TYPE_FEAR) {
            if (rand_int(99) < statusChanceOrDefense) {
                if (!(target->debuff == STATUS_FEAR ||
                      target->debuff == STATUS_DIZZY ||
                      target->debuff == STATUS_PARALYZE ||
                      target->debuff == STATUS_SLEEP ||
                      target->debuff == STATUS_FROZEN ||
                      target->debuff == STATUS_STOP) && !(target->flags & ACTOR_FLAG_400)) {
                    dispatchEvent = EVENT_SCARE_AWAY;
                    wasStatusInflicted = TRUE;
                    retVal = 0;
                    tempBinary = TRUE;
                    gBattleStatus.flags1 |= (BS_FLAGS1_40 | BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10 | BS_FLAGS1_8 | BS_FLAGS1_ACTORS_VISIBLE);
                    sfx_play_sound_at_position(SOUND_231, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                } else {
                    dispatchEvent = EVENT_IMMUNE;
                    retVal = 2;
                }
            } else {
                dispatchEvent = EVENT_IMMUNE;
                retVal = 2;
            }
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
        } else if (!sp2C) {
            if (battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS | DAMAGE_TYPE_SMASH)) {
                show_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 0);
            } else {
                func_802664DC(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 0);
            }

            if (!(targetPart->targetFlags & ACTOR_PART_FLAG_4)) {
                func_802666E4(target, state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage);
            }
        }
    }

    if (tempBinary && gBattleStatus.flags1 & (BS_FLAGS1_200 | BS_FLAGS1_40) || gBattleStatus.flags1 & (BS_FLAGS1_200 | BS_FLAGS1_40) &&
        !(gBattleStatus.flags1 & BS_FLAGS1_80)) {
        if ((battleStatus->lastAttackDamage > 0 &&
             ((sfx_play_sound_at_position(SOUND_231, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y,
                                          state->goalPos.z),                    //TODO remove sfx_play from conditional
               battleStatus->lastAttackDamage > 0))) || (battleStatus->currentAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS && tempBinary)) {
            if (gBattleStatus.flags1 & BS_FLAGS1_40) {
                func_802667F0(0, target, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            } else {
                func_802667F0(3, target, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            }
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        func_80266970(target);
    }

    if (battleStatus->lastAttackDamage > 0) {
        if (sp2C == 0) {
            if (partner->actorTypeData1[5] != 0) {
                sfx_play_sound_at_position(partner->actorTypeData1[5], SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            }

            func_80267018(target, 1);

            if (isFireDamage) {
                sfx_play_sound_at_position(SOUND_HIT_FIRE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            } else if (isElectricDamage) {
                sfx_play_sound_at_position(SOUND_HIT_SHOCK, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            } else if (isIceDamage) {
                sfx_play_sound_at_position(SOUND_HIT_ICE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            } else {
                sfx_play_sound_at_position(SOUND_HIT_NORMAL, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            }
        }
    }

    if (battleStatus->lastAttackDamage <= 0 && !tempBinary && !wasStatusInflicted || targetPart->flags & ACTOR_PART_FLAG_2000) {
        sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_SLEEP && wasStatusInflicted) {
        evt = start_script((EvtScript*) DoSleepHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_SLEEP, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_DIZZY && wasStatusInflicted) {
        evt = start_script((EvtScript*) DoDizzyHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_PARALYZE && wasStatusInflicted) {
        evt = start_script((EvtScript*) DoParalyzeHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_POISON && wasStatusInflicted) {
        evt = start_script((EvtScript*) DoPoisonHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_STOP && wasStatusInflicted) {
        evt = start_script((EvtScript*) DoStopHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_FROZEN && wasStatusInflicted) {
        evt = start_script((EvtScript*) DoFreezeHit, EVT_PRIORITY_A, 0);
        evt->varTable[0] = state->goalPos.x;
        evt->varTable[1] = state->goalPos.y;
        evt->varTable[2] = state->goalPos.z;
        evt->varTablePtr[3] = target;
        sfx_play_sound_at_position(SOUND_HIT_ICE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if (battleStatus->currentAttackStatus & STATUS_FLAG_SHRINK && wasStatusInflicted) {
        evt = start_script((EvtScript*) DoShrinkHit, EVT_PRIORITY_A, 0);
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
        if (retVal == 0) {
            retVal = 1;
        }

        if (retVal == 2) {
            retVal = 3;
        }
    }

    if (partner->staticStatus != STATUS_STATIC && (target->staticStatus == STATUS_STATIC ||
            targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED) && !(battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT) &&
        !(battleStatus->currentAttackEventSuppression & ATTACK_EVENT_FLAG_8)) {
        sfx_play_sound_at_position(SOUND_HIT_SHOCK, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        func_80251474(partner);
        dispatch_damage_event_partner_1(1, EVENT_SHOCK_HIT);
        return -1;
    }

    return retVal;
}

s32 dispatch_damage_event_partner(s32 damageAmount, s32 event, s32 stopMotion) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    ActorState* state = &partner->state;
    s32 hpChange;
    s32 flagCheck;
    s32 oldHP;

    battleStatus->currentAttackDamage = damageAmount;

    hpChange = (s16)damageAmount;
    partner->hpChangeCounter += hpChange;

    hpChange = partner->hpChangeCounter;
    partner->currentHP = 127;
    partner->damageCounter += hpChange;
    partner->hpChangeCounter -= hpChange;
    battleStatus->lastAttackDamage = 0;
    partner->currentHP -= hpChange;
    oldHP = partner->currentHP;


    if (partner->currentHP <= 0) {
        event = EVENT_DEATH;
        battleStatus->lastAttackDamage += oldHP;
        partner->currentHP = 0;
    }

    battleStatus->lastAttackDamage += hpChange;
    partner->lastDamageTaken = battleStatus->lastAttackDamage;
    battleStatus->unk_19A = 0;
    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (event == EVENT_HIT_COMBO) {
            event = EVENT_HIT;
        }
        if (event == EVENT_SCRIPTED_IMMUNE) {
            event = EVENT_IMMUNE;
        }
    }

    if (battleStatus->lastAttackDamage > 0) {
        gBattleStatus.flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;

        inflict_status(partner, STATUS_DAZE, battleStatus->lastAttackDamage);
    }

    if (!stopMotion) {
        set_goal_pos_to_part(state, ACTOR_PARTNER, 0);
    }

    show_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z,
                      battleStatus->lastAttackDamage, 1);
    func_802666E4(partner, state->goalPos.x, state->goalPos.y, state->goalPos.z,
                  battleStatus->lastAttackDamage);

    if (battleStatus->lastAttackDamage > 0) {
        func_80267018(partner, 1);
    }

    partner->flags |= ACTOR_FLAG_80000;

    flagCheck = (gBattleStatus.flags1 & (BS_FLAGS1_200 | BS_FLAGS1_40)) != 0;
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
    battleStatus->flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;

    hitResult = calc_partner_damage_enemy();
    show_damage_popup(actor->state.goalPos.x, actor->state.goalPos.y, actor->state.goalPos.z, battleStatus->lastAttackDamage,
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

    gBattleStatus.currentAttackElement = *args++;
    gBattleStatus.currentAttackEventSuppression = *args++;
    gBattleStatus.currentAttackStatus = *args++;
    gBattleStatus.currentAttackDamage = evt_get_variable(script, *args++);
    gBattleStatus.powerBounceCounter = 0;
    flags = *args++;

    if ((flags & (BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)) == (BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)) {
        battleStatus->flags1 |= BS_FLAGS1_10;
        battleStatus->flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (flags & BS_FLAGS1_10) {
        battleStatus->flags1 |= BS_FLAGS1_10;
        battleStatus->flags1 &= ~BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (flags & BS_FLAGS1_SP_EVT_ACTIVE) {
        battleStatus->flags1 &= ~BS_FLAGS1_10;
        battleStatus->flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;
    } else {
        battleStatus->flags1 &= ~BS_FLAGS1_10;
        battleStatus->flags1 &= ~BS_FLAGS1_SP_EVT_ACTIVE;
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

    if ((flags & (BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)) == (BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)) {
        battleStatus->flags1 |= BS_FLAGS1_10;
        battleStatus->flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (flags & BS_FLAGS1_10) {
        battleStatus->flags1 |= BS_FLAGS1_10;
        battleStatus->flags1 &= ~BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (flags & BS_FLAGS1_SP_EVT_ACTIVE) {
        battleStatus->flags1 &= ~BS_FLAGS1_10;
        battleStatus->flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;
    } else {
        battleStatus->flags1 &= ~BS_FLAGS1_10;
        battleStatus->flags1 &= ~BS_FLAGS1_SP_EVT_ACTIVE;
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

    if ((flags & (BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)) == (BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)) {
        battleStatus->flags1 |= BS_FLAGS1_10;
        battleStatus->flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (flags & BS_FLAGS1_10) {
        battleStatus->flags1 |= BS_FLAGS1_10;
        battleStatus->flags1 &= ~BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (flags & BS_FLAGS1_SP_EVT_ACTIVE) {
        battleStatus->flags1 &= ~BS_FLAGS1_10;
        battleStatus->flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;
    } else {
        battleStatus->flags1 &= ~BS_FLAGS1_10;
        battleStatus->flags1 &= ~BS_FLAGS1_SP_EVT_ACTIVE;
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
    Actor* enemy = get_actor(script->owner1.enemyID);
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

    if ((flags & (BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)) == (BS_FLAGS1_10 | BS_FLAGS1_SP_EVT_ACTIVE)) {
        battleStatus->flags1 |= BS_FLAGS1_10;
        battleStatus->flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (flags & BS_FLAGS1_10) {
        battleStatus->flags1 |= BS_FLAGS1_10;
        battleStatus->flags1 &= ~BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (flags & BS_FLAGS1_SP_EVT_ACTIVE) {
        battleStatus->flags1 &= ~BS_FLAGS1_10;
        battleStatus->flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;
    } else {
        battleStatus->flags1 &= ~BS_FLAGS1_10;
        battleStatus->flags1 &= ~BS_FLAGS1_SP_EVT_ACTIVE;
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
ApiStatus PartnerYieldTurn(Evt* script, s32 isInitialCall) {
    gBattleStatus.flags1 |= BS_FLAGS1_200000;
    return ApiStatus_DONE2;
}
