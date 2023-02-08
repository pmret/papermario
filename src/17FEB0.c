#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"

s32 calc_item_check_hit(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActorState* state = &battleStatus->playerActor->state;
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
            if (actor->transparentStatus == STATUS_TRANSPARENT) {
                return HIT_RESULT_MISS;
            }
            if (actor->stoneStatus == STATUS_STONE) {
                sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                return HIT_RESULT_IMMUNE;
            }
            if ((battleStatus->currentAttackElement & DAMAGE_TYPE_JUMP) && (actorPart->eventFlags & ACTOR_EVENT_FLAG_SPIKY_TOP)) {
                sfx_play_sound_at_position(SOUND_HIT_NORMAL, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                return HIT_RESULT_LANDED_ON_SPIKE;
            }
        } else {
            return HIT_RESULT_MISS;
        }
    }
    return HIT_RESULT_HIT;
}

s32 calc_item_damage_enemy(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    s32 currentTargetID = battleStatus->currentTargetID;
    Actor* partner = battleStatus->partnerActor;
    s32 currentTargetPartID = battleStatus->currentTargetPart;
    s32 sp18;
    s32 sp1C = FALSE;
    s32 actorClass;
    s32 isFireDamage = FALSE;
    s32 isElectricDamage = FALSE;
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
    s32 ret;

    battleStatus->wasStatusInflicted = FALSE;
    battleStatus->lastAttackDamage = 0;
    battleStatus->attackerActorID = player->actorID;
    battleStatus->currentTargetID2 = battleStatus->currentTargetID;
    battleStatus->currentTargetPart2 = battleStatus->currentTargetPart;
    target = get_actor(currentTargetID);
    wasStatusInflicted = FALSE;

    if (target == NULL) {
        return 0;
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

    if (battleStatus->currentAttackElement & DAMAGE_TYPE_FIRE) {
        fx_ring_blast(0, state->goalPos.x, state->goalPos.y, state->goalPos.z + 5.0f, 1.0f, 24);
        isFireDamage = TRUE;
    }
    if (battleStatus->currentAttackElement & DAMAGE_TYPE_ELECTRIC) {
        func_80251474(target);
        isElectricDamage = TRUE;
    }
    if (battleStatus->currentAttackElement & DAMAGE_TYPE_WATER) {
        fx_water_splash(0, state->goalPos.x, state->goalPos.y, state->goalPos.z + 5.0f, 1.0f, 24);
    }
    if (battleStatus->currentAttackElement & DAMAGE_TYPE_ICE) {
        fx_big_snowflakes(0, state->goalPos.x, state->goalPos.y, state->goalPos.z + 5.0f);
        isIceDamage = TRUE;
    }

    if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_REMOVE_BUFFS)) {
        if ((targetPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) ||
            ((target->transparentStatus == STATUS_TRANSPARENT) || ((targetPart->eventFlags & ACTOR_EVENT_FLAG_800) && !(battleStatus->currentAttackElement & DAMAGE_TYPE_QUAKE))))
        {
            return 6;
        }
    }

    if (target->stoneStatus == STATUS_STONE) {
        sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        func_8024EFE0(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, 1);
        show_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 0);

        if (gBattleStatus.flags1 & (BS_FLAGS1_40 | BS_FLAGS1_200)) {
            return 1;
        } else {
            return 0;
        }
    }

    if (targetPart->partFlags3 & battleStatus->currentAttackElement) {
        sp18 = TRUE;
    } else {
        sp18 = FALSE;
    }

    if (targetPart->eventFlags & (ACTOR_EVENT_FLAG_ENCHANTED | ACTOR_EVENT_FLAG_80000)) {
        battleStatus->currentAttackElement &= ~DAMAGE_TYPE_IGNORE_DEFENSE;
    }

    temp = get_defense(target, targetPart->defenseTable, battleStatus->currentAttackElement);
    if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_IGNORE_DEFENSE)) {
        temp += target->defenseBoost;
    }

    attackDamage = battleStatus->currentAttackDamage;
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
        ret = 2;
        if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS)) {
            dispatchEvent = EVENT_SCRIPTED_IMMUNE;
            sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            battleStatus->lastAttackDamage = 0;
        } else {
            dispatchEvent = EVENT_SCRIPTED_IMMUNE;
            battleStatus->lastAttackDamage = 0;
        }
    } else {
        target->damageCounter += attackDamage;
        target->hpChangeCounter -= attackDamage;
        battleStatus->lastAttackDamage = 0;
        dispatchEvent = EVENT_HIT_COMBO;
        ret = 0;
        if (!(targetPart->flags & ACTOR_PART_FLAG_2000) && !sp18 && !(targetPart->targetFlags & ACTOR_PART_FLAG_4)) {
            target->currentHP -= attackDamage;
            if (target->currentHP <= 0) {
                target->currentHP = 0;
                dispatchEvent = EVENT_DEATH;
            }
        }
        battleStatus->lastAttackDamage += attackDamage;
        target->lastDamageTaken = battleStatus->lastAttackDamage;
        target->hpChangeCounter = 0;
    }

    if (targetPart->flags & ACTOR_PART_FLAG_2000) {
        dispatch_event_actor(target, dispatchEvent);
        func_8024EFE0(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, 3);
        sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        return 2;
    }
    if (battleStatus->currentAttackElement & DAMAGE_TYPE_2000) {
        battleStatus->lastAttackDamage = 0;
        dispatchEvent = EVENT_DEATH;
        ret = 0;
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (dispatchEvent == EVENT_HIT_COMBO) {
            dispatchEvent = EVENT_HIT;
        }
        if (dispatchEvent == EVENT_SCRIPTED_IMMUNE) {
            dispatchEvent = EVENT_IMMUNE;
        }
        if (target->currentHP <= 0 && dispatchEvent == EVENT_IMMUNE) {
            dispatchEvent = EVENT_DEATH;
        }
    } else if (dispatchEvent == EVENT_DEATH) {
        dispatchEvent = EVENT_HIT_COMBO;
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (battleStatus->currentAttackElement & DAMAGE_TYPE_REMOVE_BUFFS) {
            dispatchEvent = EVENT_IMMUNE;
            if (targetPart->eventFlags & ACTOR_EVENT_FLAG_ENCHANTED) {
                dispatchEvent = EVENT_STAR_BEAM;
                wasStatusInflicted = TRUE;
            }
            if (targetPart->eventFlags & ACTOR_EVENT_FLAG_400000) {
                dispatchEvent = EVENT_STAR_BEAM;
                wasStatusInflicted = TRUE;
            }
            if (targetPart->eventFlags & ACTOR_EVENT_FLAG_80000) {
                dispatchEvent = EVENT_1D;
            }
            ret = 0;
        }
    }

    if (battleStatus->currentAttackElement & DAMAGE_TYPE_REMOVE_BUFFS) {
        if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
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
                ret = 0;
            }
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (battleStatus->currentAttackElement & DAMAGE_TYPE_PEACH_BEAM) {
            dispatchEvent = EVENT_IMMUNE;
            if (targetPart->eventFlags & ACTOR_EVENT_FLAG_ENCHANTED) {
                dispatchEvent = EVENT_PEACH_BEAM;
                wasStatusInflicted = TRUE;
            }
            if (targetPart->eventFlags & ACTOR_EVENT_FLAG_80000) {
                dispatchEvent = EVENT_PEACH_BEAM;
                wasStatusInflicted = TRUE;
            }
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (battleStatus->currentAttackElement & DAMAGE_TYPE_SPIN_SMASH) {
            if (dispatchEvent == EVENT_HIT) {
                dispatchEvent = EVENT_SPIN_SMASH_HIT;
            }
            if (dispatchEvent == EVENT_DEATH) {
                dispatchEvent = EVENT_SPIN_SMASH_DEATH;
            }
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if ((battleStatus->currentAttackElement & (DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POW)) &&
            (targetPart->eventFlags & ACTOR_EVENT_FLAG_GROUNDABLE))
        {
            if (dispatchEvent == EVENT_HIT) {
                dispatchEvent = EVENT_FALL_TRIGGER;
            }
            if (dispatchEvent == EVENT_IMMUNE) {
                dispatchEvent = EVENT_FALL_TRIGGER;
            }
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if ((battleStatus->currentAttackElement & DAMAGE_TYPE_POW) &&
            (targetPart->eventFlags & ACTOR_EVENT_FLAG_800000))
        {
            if (dispatchEvent == EVENT_HIT) {
                dispatchEvent = EVENT_FALL_TRIGGER;
            }
            if (dispatchEvent == EVENT_IMMUNE) {
                dispatchEvent = EVENT_FALL_TRIGGER;
            }
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if ((battleStatus->currentAttackElement & (DAMAGE_TYPE_JUMP | DAMAGE_TYPE_POW | DAMAGE_TYPE_QUAKE)) &&
            (targetPart->eventFlags & ACTOR_EVENT_FLAG_FLIPABLE))
        {
            if (dispatchEvent == EVENT_HIT) {
                dispatchEvent = EVENT_FLIP_TRIGGER;
            }
            if (dispatchEvent == EVENT_IMMUNE) {
                dispatchEvent = EVENT_FLIP_TRIGGER;
            }
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (battleStatus->currentAttackElement & DAMAGE_TYPE_FIRE) {
            if (dispatchEvent == EVENT_HIT) {
                dispatchEvent = EVENT_BURN_HIT;
            }
            if (dispatchEvent == EVENT_DEATH) {
                dispatchEvent = EVENT_BURN_DEATH;
            }
            isFireDamage = TRUE;
        }
    }

    if ((gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) &&
            battleStatus->lastAttackDamage >= 0 &&
            dispatchEvent != EVENT_DEATH &&
            dispatchEvent != EVENT_SPIN_SMASH_DEATH &&
            dispatchEvent != EVENT_EXPLODE_TRIGGER)
    {
        // Using this macro because it's nicer to look at, and it also is necessary to wrap the first 5 of these in a
        // do-while-0 OR to wrap each one individually. It's more likely that it's a macro instead, and much cleaner
        #define INFLICT_STATUS(STATUS_TYPE) \
            do { \
                if ((battleStatus->currentAttackStatus & STATUS_FLAG_##STATUS_TYPE) && \
                    try_inflict_status(target, STATUS_##STATUS_TYPE, STATUS_##STATUS_TYPE##_TURN_MOD)) { \
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
            if (dispatchEvent == EVENT_SCRIPTED_IMMUNE) {
                dispatchEvent = EVENT_HIT_COMBO;
            }
            if (dispatchEvent == EVENT_IMMUNE) {
                dispatchEvent = EVENT_HIT;
            }
        }

    }

    temp = target->actorBlueprint->spookChance;
    temp = (battleStatus->statusChance * temp) / 100;

    if ((gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) && (battleStatus->currentAttackElement & DAMAGE_TYPE_FEAR)) {
        if (rand_int(99) < temp &&
            !(target->debuff == STATUS_FEAR ||
              target->debuff == STATUS_DIZZY ||
              target->debuff == STATUS_PARALYZE ||
              target->debuff == STATUS_SLEEP ||
              target->debuff == STATUS_FROZEN ||
              target->debuff == STATUS_STOP) &&
            !(target->flags & ACTOR_FLAG_400))
        {
            dispatchEvent = EVENT_SCARE_AWAY;
            ret = 0;
            sp1C = TRUE;
            gBattleStatus.flags1 |= BS_FLAGS1_SP_EVT_ACTIVE | BS_FLAGS1_10 | BS_FLAGS1_8 | BS_FLAGS1_ACTORS_VISIBLE;
            sfx_play_sound_at_position(SOUND_231, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
            wasStatusInflicted = TRUE;
            gBattleStatus.flags1 |= BS_FLAGS1_40;
        } else {
            dispatchEvent = EVENT_IMMUNE;
            ret = 2;
        }
    }

    battleStatus->wasStatusInflicted = wasStatusInflicted;

    if (
        (sp1C && (gBattleStatus.flags1 & (BS_FLAGS1_40 | BS_FLAGS1_200))) ||
        ((gBattleStatus.flags1 & (BS_FLAGS1_40 | BS_FLAGS1_200)) && !(gBattleStatus.flags1 & BS_FLAGS1_80))
    ) {
        if (battleStatus->lastAttackDamage > 0) {
            sfx_play_sound_at_position(SOUND_231, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        }

        if (battleStatus->lastAttackDamage > 0 || (battleStatus->currentAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS) && sp1C) {
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

    dispatch_event_actor(target, dispatchEvent);

    if (actorClass == ACTOR_PARTNER) {
        if ((battleStatus->lastAttackDamage > 0) && (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE)) {
            inflict_status(target, STATUS_DAZE, battleStatus->lastAttackDamage);
        }
    }

    if (!(target->flags & ACTOR_FLAG_NO_DMG_POPUP)) {
        if (battleStatus->lastAttackDamage == 0) {
            if (!sp1C && !wasStatusInflicted) {
                func_8024EFE0(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, 3);
            }
        } else if (!sp18) {
            if (battleStatus->currentAttackElement & (DAMAGE_TYPE_SMASH | DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS)) {
                show_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 0);
            } else {
                func_802664DC(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 0);
            }
            if (!(targetPart->targetFlags & 4)) {
                func_802666E4(target, state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage);
            }
        }
    }

    if (battleStatus->lastAttackDamage > 0 && !sp18) {
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

    if ((battleStatus->lastAttackDamage <= 0 && !wasStatusInflicted) || (targetPart->flags & ACTOR_FLAG_2000)) {
        sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if ((battleStatus->currentAttackStatus & STATUS_FLAG_SLEEP) && wasStatusInflicted) {
        script = start_script(&DoSleepHit, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_SLEEP, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->currentAttackStatus & STATUS_FLAG_DIZZY) && wasStatusInflicted) {
        script = start_script(&DoDizzyHit, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->currentAttackStatus & STATUS_FLAG_PARALYZE) && wasStatusInflicted) {
        script = start_script(&DoParalyzeHit, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->currentAttackStatus & STATUS_FLAG_POISON) && wasStatusInflicted) {
        script = start_script(&DoPoisonHit, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->currentAttackStatus & STATUS_FLAG_STOP) && wasStatusInflicted) {
        script = start_script(&DoStopHit, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->currentAttackStatus & STATUS_FLAG_FROZEN) && wasStatusInflicted) {
        script = start_script(&DoFreezeHit, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        script->varTablePtr[3] = target;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->currentAttackStatus & STATUS_FLAG_SHRINK) && wasStatusInflicted) {
        script = start_script(&DoShrinkHit, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        script->varTablePtr[3] = target;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->currentAttackElement & DAMAGE_TYPE_SMASH) && (target->actorType == ACTOR_TYPE_GOOMNUT_TREE)) {
        sfx_play_sound_at_position(SOUND_SMASH_GOOMNUT_TREE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    func_80266ADC(target);

    if (gBattleStatus.flags1 & (BS_FLAGS1_40 | BS_FLAGS1_200)) {
        if (ret == 0) {
            ret = 1;
        }
        if (ret == 2) {
            ret = 3;
        }
    }

    return ret;
}

ApiStatus ItemDamageEnemy(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 itemDamageOut = *args++;
    s32 flags;
    Actor* actor;
    s32 itemDamage;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = 0;
    battleStatus->currentAttackStatus = *args++;
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
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

    actor = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;

    if (battleStatus->statusChance == 0xFF) {
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
    Actor* actor;
    s32 itemDamage;
    s32 flags;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = 0;
    battleStatus->currentAttackStatus = *args++;
    battleStatus->currentAttackStatus |= evt_get_variable(script, *args++);
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
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

    actor = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;

    if (battleStatus->statusChance == 0xFF) {
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
    s32 flags;
    Actor* actor;
    s32 itemDamage;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = 0;
    battleStatus->currentAttackStatus = evt_get_variable(script, *args++);
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
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

    actor = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;

    if (battleStatus->statusChance == 0xFF) {
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
    s32 flags;
    Actor* actor;
    s32 itemDamage;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = 0;
    battleStatus->currentAttackStatus = *args++;
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
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

    actor = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;

    if (battleStatus->statusChance == 0xFF) {
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
