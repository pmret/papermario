#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"

HitResult calc_item_check_hit(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActorState* state = &battleStatus->playerActor->state;
    s32 actorID = battleStatus->curTargetID;
    s8 currentTargetPartS8;
    u32 currentTargetPart;
    Actor* actor;
    ActorPart* actorPart;

    battleStatus->curTargetID2 = battleStatus->curTargetID;
    currentTargetPart = currentTargetPartS8 = battleStatus->curTargetPart;
    battleStatus->curTargetPart2 = currentTargetPartS8;

    actor = get_actor(actorID);
    if (actor == NULL) {
        return HIT_RESULT_HIT;
    }

    actorPart = get_actor_part(actor, currentTargetPart);
    ASSERT(actorPart != NULL);

    if (actorPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
        return HIT_RESULT_MISS;
    }

    if (actor->transparentStatus == STATUS_KEY_TRANSPARENT) {
        return HIT_RESULT_MISS;
    }

    if (actor->stoneStatus == STATUS_KEY_STONE) {
        sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        return HIT_RESULT_IMMUNE;
    }

    if ((battleStatus->curAttackElement & DAMAGE_TYPE_JUMP)
        && (actorPart->eventFlags & ACTOR_EVENT_FLAG_SPIKY_TOP))
    {
        sfx_play_sound_at_position(SOUND_HIT_NORMAL, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        return HIT_RESULT_LANDED_ON_SPIKE;
    }

    return HIT_RESULT_HIT;
}

HitResult calc_item_damage_enemy(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 currentTargetID = battleStatus->curTargetID;
    Actor* partner = battleStatus->partnerActor;
    s32 currentTargetPartID = battleStatus->curTargetPart;
    s32 partImmuneToElement;
    s32 wasSpecialHit = FALSE;
    s32 actorClass;
    s32 isFireDamage = FALSE;
    s32 isWaterDamage = FALSE;
    s32 isShockDamage = FALSE;
    s32 isIceDamage = FALSE;
    Actor* target;
    ActorPart* targetPart;
    Evt* script;
    s32 attackDamage;
    s32 temp;
    s32 targetDefense;
    ActorState* state;
    s32 dispatchEvent;
    s32 wasStatusInflicted;
    s32 hitResult;

    battleStatus->wasStatusInflicted = FALSE;
    battleStatus->lastAttackDamage = 0;
    battleStatus->attackerActorID = player->actorID;
    battleStatus->curTargetID2 = battleStatus->curTargetID;
    battleStatus->curTargetPart2 = battleStatus->curTargetPart;
    target = get_actor(currentTargetID);
    wasStatusInflicted = FALSE;

    if (target == NULL) {
        return HIT_RESULT_HIT;
    }

    targetPart = get_actor_part(target, currentTargetPartID);
    if (targetPart == NULL) {
        PANIC();
    }

    target->lastDamageTaken = 0;
    actorClass = currentTargetID & ACTOR_CLASS_MASK;
    if (!(gBattleStatus.flags1 & BS_FLAGS1_PARTNER_ACTING)) {
        state = &player->state;
    } else {
        state = &partner->state;
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

    if (!(battleStatus->curAttackElement & DAMAGE_TYPE_REMOVE_BUFFS)) {
        if ((targetPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY)
            || (target->transparentStatus == STATUS_KEY_TRANSPARENT)
            || (targetPart->eventFlags & ACTOR_EVENT_FLAG_BURIED && !(battleStatus->curAttackElement & DAMAGE_TYPE_QUAKE))
        ) {
            return HIT_RESULT_MISS;
        }
    }

    if (target->stoneStatus == STATUS_KEY_STONE) {
        sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        show_immune_bonk(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, 1);
        show_next_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 0);
        if (gBattleStatus.flags1 & (BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)) {
            return HIT_RESULT_NICE;
        }
        return HIT_RESULT_HIT;
    }

    if (targetPart->elementalImmunities & battleStatus->curAttackElement) {
        partImmuneToElement = TRUE;
    } else {
        partImmuneToElement = FALSE;
    }

    if (targetPart->eventFlags & (ACTOR_EVENT_FLAG_ENCHANTED | ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED)) {
        battleStatus->curAttackElement &= ~DAMAGE_TYPE_IGNORE_DEFENSE;
    }

    temp = get_defense(target, targetPart->defenseTable, battleStatus->curAttackElement);
    if (!(battleStatus->curAttackElement & DAMAGE_TYPE_IGNORE_DEFENSE)) {
        temp += target->defenseBoost;
    }

    attackDamage = battleStatus->curAttackDamage;
    if (attackDamage > 99) {
        attackDamage = 99;
    }
    if (attackDamage <= 0) {
        temp = 0;
    }

    attackDamage -= temp;
    target->hpChangeCounter = 0;

    if (attackDamage <= 0) {
        target->hpChangeCounter = 0;
        hitResult = HIT_RESULT_NO_DAMAGE;

        if (!(battleStatus->curAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS)) {
            dispatchEvent = EVENT_ZERO_DAMAGE;
            sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            battleStatus->lastAttackDamage = 0;
        } else {
            dispatchEvent = EVENT_ZERO_DAMAGE;
            battleStatus->lastAttackDamage = 0;
        }
    } else {
        target->damageCounter += attackDamage;
        target->hpChangeCounter -= attackDamage;
        battleStatus->lastAttackDamage = 0;
        dispatchEvent = EVENT_HIT_COMBO;
        hitResult = HIT_RESULT_HIT;

        if (!(targetPart->flags & ACTOR_PART_FLAG_DAMAGE_IMMUNE)
            && !partImmuneToElement
            && !(targetPart->targetFlags & ACTOR_PART_TARGET_NO_DAMAGE)
        ) {
            target->curHP -= attackDamage;
            if (target->curHP <= 0) {
                target->curHP = 0;
                dispatchEvent = EVENT_DEATH;
            }
        }
        battleStatus->lastAttackDamage += attackDamage;
        target->lastDamageTaken = battleStatus->lastAttackDamage;
        target->hpChangeCounter = 0;
    }

    if (targetPart->flags & ACTOR_PART_FLAG_DAMAGE_IMMUNE) {
        dispatch_event_actor(target, dispatchEvent);
        show_immune_bonk(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, 3);
        sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        return HIT_RESULT_NO_DAMAGE;
    }

    if (battleStatus->curAttackElement & DAMAGE_TYPE_DEATH) {
        battleStatus->lastAttackDamage = 0;
        dispatchEvent = EVENT_DEATH;
        hitResult = HIT_RESULT_HIT;
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) {
        if (dispatchEvent == EVENT_HIT_COMBO) {
            dispatchEvent = EVENT_HIT;
        }
        if (dispatchEvent == EVENT_ZERO_DAMAGE) {
            dispatchEvent = EVENT_IMMUNE;
        }
        if (target->curHP <= 0 && dispatchEvent == EVENT_IMMUNE) {
            dispatchEvent = EVENT_DEATH;
        }
    } else if (dispatchEvent == EVENT_DEATH) {
        dispatchEvent = EVENT_HIT_COMBO;
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) {
        if (battleStatus->curAttackElement & DAMAGE_TYPE_REMOVE_BUFFS) {
            dispatchEvent = EVENT_IMMUNE;
            if (targetPart->eventFlags & ACTOR_EVENT_FLAG_ENCHANTED) {
                dispatchEvent = EVENT_STAR_BEAM;
                wasStatusInflicted = TRUE;
            }
            if (targetPart->eventFlags & ACTOR_EVENT_FLAG_ATTACK_CHARGED) {
                dispatchEvent = EVENT_STAR_BEAM;
                wasStatusInflicted = TRUE;
            }
            if (targetPart->eventFlags & ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED) {
                dispatchEvent = EVENT_INVUNERABLE_TAUNT;
            }
            hitResult = HIT_RESULT_HIT;
        }
    }

    if (battleStatus->curAttackElement & DAMAGE_TYPE_REMOVE_BUFFS) {
        if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) {
            if ((target->attackBoost > 0 || target->defenseBoost > 0) ||
                ((target->staticStatus == 0 && target->transparentStatus != 0) || target->staticStatus != 0))
            {
                target->attackBoost = 0;
                target->defenseBoost = 0;
                target->isGlowing = FALSE;
                dispatchEvent = EVENT_HIT;
                if (target->staticStatus != 0) {
                    target->staticStatus = 0;
                    target->staticDuration = 0;
                    remove_status_static(target->hudElementDataIndex);
                }
                if (target->transparentStatus != 0) {
                    target->transparentStatus = 0;
                    target->transparentDuration = 0;
                    remove_status_transparent(target->hudElementDataIndex);
                }
                wasStatusInflicted = TRUE;
                hitResult = HIT_RESULT_HIT;
            }
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) {
        if (battleStatus->curAttackElement & DAMAGE_TYPE_PEACH_BEAM) {
            dispatchEvent = EVENT_IMMUNE;
            if (targetPart->eventFlags & ACTOR_EVENT_FLAG_ENCHANTED) {
                dispatchEvent = EVENT_PEACH_BEAM;
                wasStatusInflicted = TRUE;
            }
            if (targetPart->eventFlags & ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED) {
                dispatchEvent = EVENT_PEACH_BEAM;
                wasStatusInflicted = TRUE;
            }
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) {
        if (battleStatus->curAttackElement & DAMAGE_TYPE_SPIN_SMASH) {
            if (dispatchEvent == EVENT_HIT) {
                dispatchEvent = EVENT_SPIN_SMASH_HIT;
            }
            if (dispatchEvent == EVENT_DEATH) {
                dispatchEvent = EVENT_SPIN_SMASH_DEATH;
            }
        }
    }

    if ((gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS)
        && (battleStatus->curAttackElement & (DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POW))
        && (targetPart->eventFlags & ACTOR_EVENT_FLAG_GROUNDABLE)
    ) {
        if (dispatchEvent == EVENT_HIT) {
            dispatchEvent = EVENT_FALL_TRIGGER;
        }
        if (dispatchEvent == EVENT_IMMUNE) {
            dispatchEvent = EVENT_FALL_TRIGGER;
        }
    }

    if ((gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS)
        && (battleStatus->curAttackElement & DAMAGE_TYPE_POW)
        && (targetPart->eventFlags & ACTOR_EVENT_FLAG_RIDING_BROOMSTICK)
    ) {
        if (dispatchEvent == EVENT_HIT) {
            dispatchEvent = EVENT_FALL_TRIGGER;
        }
        if (dispatchEvent == EVENT_IMMUNE) {
            dispatchEvent = EVENT_FALL_TRIGGER;
        }
    }

    if ((gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS)
        && (battleStatus->curAttackElement & (DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POW | DAMAGE_TYPE_QUAKE))
        && (targetPart->eventFlags & ACTOR_EVENT_FLAG_FLIPABLE)
    ) {
        if (dispatchEvent == EVENT_HIT) {
            dispatchEvent = EVENT_FLIP_TRIGGER;
        }
        if (dispatchEvent == EVENT_IMMUNE) {
            dispatchEvent = EVENT_FLIP_TRIGGER;
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) {
        if (battleStatus->curAttackElement & DAMAGE_TYPE_FIRE) {
            if (dispatchEvent == EVENT_HIT) {
                dispatchEvent = EVENT_BURN_HIT;
            }
            if (dispatchEvent == EVENT_DEATH) {
                dispatchEvent = EVENT_BURN_DEATH;
            }
            isFireDamage = TRUE;
        }
    }

    if ((gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS)
        && battleStatus->lastAttackDamage >= 0
        && dispatchEvent != EVENT_DEATH
        && dispatchEvent != EVENT_SPIN_SMASH_DEATH
        && dispatchEvent != EVENT_EXPLODE_TRIGGER
    ) {
        // Using this macro because it's nicer to look at, and it also is necessary to wrap the first 5 of these in a
        // do-while-0 OR to wrap each one individually. It's more likely that it's a macro instead, and much cleaner
        #define INFLICT_STATUS(STATUS_TYPE) \
            do { \
                if ((battleStatus->curAttackStatus & STATUS_FLAG_##STATUS_TYPE) && \
                    try_inflict_status(target, STATUS_KEY_##STATUS_TYPE, STATUS_TURN_MOD_##STATUS_TYPE)) { \
                    wasStatusInflicted = TRUE; \
                } \
            } while (0);

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

    temp = target->actorBlueprint->spookChance;
    temp = (battleStatus->statusChance * temp) / 100;

    if ((gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS) && (battleStatus->curAttackElement & DAMAGE_TYPE_FEAR)) {
        if (rand_int(99) < temp
            && (target->debuff != STATUS_KEY_FEAR
                && target->debuff != STATUS_KEY_DIZZY
                && target->debuff != STATUS_KEY_PARALYZE
                && target->debuff != STATUS_KEY_SLEEP
                && target->debuff != STATUS_KEY_FROZEN
                && target->debuff != STATUS_KEY_STOP)
            && !(target->flags & ACTOR_FLAG_FLIPPED))
        {
            dispatchEvent = EVENT_SCARE_AWAY;
            hitResult = HIT_RESULT_HIT;
            wasSpecialHit = TRUE;
            gBattleStatus.flags1 |= BS_FLAGS1_TRIGGER_EVENTS | BS_FLAGS1_INCLUDE_POWER_UPS | BS_FLAGS1_SHOW_PLAYER_DECORATIONS | BS_FLAGS1_ACTORS_VISIBLE;
            sfx_play_sound_at_position(SOUND_DAMAGE_STARS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            wasStatusInflicted = TRUE;
            gBattleStatus.flags1 |= BS_FLAGS1_NICE_HIT;
        } else {
            dispatchEvent = EVENT_IMMUNE;
            hitResult = HIT_RESULT_NO_DAMAGE;
        }
    }

    battleStatus->wasStatusInflicted = wasStatusInflicted;

    if ((wasSpecialHit && (gBattleStatus.flags1 & (BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)))
        || ((gBattleStatus.flags1 & (BS_FLAGS1_NICE_HIT | BS_FLAGS1_SUPER_HIT)) && !(gBattleStatus.flags1 & BS_FLAGS1_NO_RATING))
    ) {
        if (battleStatus->lastAttackDamage > 0) {
            sfx_play_sound_at_position(SOUND_DAMAGE_STARS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        }

        if (battleStatus->lastAttackDamage > 0 || (battleStatus->curAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS) && wasSpecialHit) {
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

    dispatch_event_actor(target, dispatchEvent);

    if (actorClass == ACTOR_PARTNER) {
        if ((battleStatus->lastAttackDamage > 0) && (gBattleStatus.flags1 & BS_FLAGS1_TRIGGER_EVENTS)) {
            inflict_status(target, STATUS_KEY_DAZE, battleStatus->lastAttackDamage);
        }
    }

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

    if (battleStatus->lastAttackDamage > 0 && !partImmuneToElement) {
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

    if ((battleStatus->lastAttackDamage <= 0 && !wasStatusInflicted) || (targetPart->flags & ACTOR_FLAG_DAMAGE_IMMUNE)) {
        sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if ((battleStatus->curAttackStatus & STATUS_FLAG_SLEEP) && wasStatusInflicted) {
        script = start_script(&EVS_PlaySleepHitFX, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_SLEEP, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->curAttackStatus & STATUS_FLAG_DIZZY) && wasStatusInflicted) {
        script = start_script(&EVS_PlayDizzyHitFX, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->curAttackStatus & STATUS_FLAG_PARALYZE) && wasStatusInflicted) {
        script = start_script(&EVS_PlayParalyzeHitFX, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->curAttackStatus & STATUS_FLAG_POISON) && wasStatusInflicted) {
        script = start_script(&EVS_PlayPoisonHitFX, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->curAttackStatus & STATUS_FLAG_STOP) && wasStatusInflicted) {
        script = start_script(&EVS_PlayStopHitFX, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->curAttackStatus & STATUS_FLAG_FROZEN) && wasStatusInflicted) {
        script = start_script(&EVS_PlayFreezeHitFX, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        script->varTablePtr[3] = target;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->curAttackStatus & STATUS_FLAG_SHRINK) && wasStatusInflicted) {
        script = start_script(&EVS_PlayShrinkHitFX, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        script->varTablePtr[3] = target;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_DEFAULT, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->curAttackElement & DAMAGE_TYPE_SMASH) && (target->actorType == ACTOR_TYPE_GOOMNUT_TREE)) {
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

    return hitResult;
}

ApiStatus ItemDamageEnemy(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 hitResultVarOut = *args++;
    s32 flags;
    Actor* actor;
    HitResult hitResult;

    battleStatus->curAttackElement = *args++;
    battleStatus->curAttackEventSuppression = 0;
    battleStatus->curAttackStatus = *args++;
    battleStatus->curAttackDamage = evt_get_variable(script, *args++);
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

    actor = get_actor(script->owner1.actorID);
    battleStatus->curTargetID = actor->targetActorID;
    battleStatus->curTargetPart = actor->targetPartID;
    battleStatus->statusChance = battleStatus->curAttackStatus;

    if (battleStatus->statusChance == STATUS_KEY_NEVER) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->curAttackStatus & 0xF00) >> 8;

    hitResult = calc_item_damage_enemy();
    if (hitResult < 0) {
        return ApiStatus_FINISH;
    }

    evt_set_variable(script, hitResultVarOut, hitResult);
    if (!does_script_exist_by_ref(script)) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus ItemSpookEnemy(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 hitResultVarOut = *args++;
    Actor* actor;
    HitResult hitResult;
    s32 flags;

    battleStatus->curAttackElement = *args++;
    battleStatus->curAttackEventSuppression = 0;
    battleStatus->curAttackStatus = *args++;
    battleStatus->curAttackStatus |= evt_get_variable(script, *args++);
    battleStatus->curAttackDamage = evt_get_variable(script, *args++);
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

    actor = get_actor(script->owner1.actorID);
    battleStatus->curTargetID = actor->targetActorID;
    battleStatus->curTargetPart = actor->targetPartID;
    battleStatus->statusChance = battleStatus->curAttackStatus;

    if (battleStatus->statusChance == STATUS_KEY_NEVER) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->curAttackStatus & 0xF00) >> 8;

    hitResult = calc_item_damage_enemy();
    if (hitResult < 0) {
        return ApiStatus_FINISH;
    }

    evt_set_variable(script, hitResultVarOut, hitResult);
    if (!does_script_exist_by_ref(script)) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus ItemAfflictEnemy(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 hitResultVarOut = *args++;
    s32 flags;
    Actor* actor;
    HitResult hitResult;

    battleStatus->curAttackElement = *args++;
    battleStatus->curAttackEventSuppression = 0;
    battleStatus->curAttackStatus = evt_get_variable(script, *args++);
    battleStatus->curAttackDamage = evt_get_variable(script, *args++);
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

    actor = get_actor(script->owner1.actorID);
    battleStatus->curTargetID = actor->targetActorID;
    battleStatus->curTargetPart = actor->targetPartID;
    battleStatus->statusChance = battleStatus->curAttackStatus;

    if (battleStatus->statusChance == STATUS_KEY_NEVER) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->curAttackStatus & 0xF00) >> 8;

    hitResult = calc_item_damage_enemy();
    if (hitResult < 0) {
        return ApiStatus_FINISH;
    }

    evt_set_variable(script, hitResultVarOut, hitResult);
    if (!does_script_exist_by_ref(script)) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus ItemCheckHit(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 hitResultVarOut = *args++;
    s32 flags;
    Actor* actor;
    HitResult hitResult;

    battleStatus->curAttackElement = *args++;
    battleStatus->curAttackEventSuppression = 0;
    battleStatus->curAttackStatus = *args++;
    battleStatus->curAttackDamage = evt_get_variable(script, *args++);
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

    actor = get_actor(script->owner1.actorID);
    battleStatus->curTargetID = actor->targetActorID;
    battleStatus->curTargetPart = actor->targetPartID;
    battleStatus->statusChance = battleStatus->curAttackStatus;

    if (battleStatus->statusChance == STATUS_KEY_NEVER) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->curAttackStatus & 0xF00) >> 8;

    hitResult = calc_item_check_hit();
    if (hitResult < 0) {
        return ApiStatus_FINISH;
    }

    evt_set_variable(script, hitResultVarOut, hitResult);

    return ApiStatus_DONE2;
}
