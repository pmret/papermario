#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "hud_element.h"
#include "sprite.h"

s32 D_802946E0[] = { 100, 100, 100, 110, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130, 130 };

s32 has_enchanted_part(Actor* actor) {
    ActorPart* partIt = actor->partsTable;
    s32 ret = FALSE;

    while (partIt != NULL) {
        if (partIt->eventFlags & (ACTOR_EVENT_FLAG_ENCHANTED | ACTOR_EVENT_FLAG_STAR_ROD_ENCHANTED)) {
            ret = TRUE;
            break;
        } else {
            partIt = partIt->nextPart;
        }
    }

    return ret;
}

void dispatch_event_general(Actor* actor, s32 event) {
    switch (actor->actorID & ACTOR_CLASS_MASK) {
        case ACTOR_CLASS_PLAYER:
            dispatch_event_player(event);
            break;
        case ACTOR_CLASS_PARTNER:
            dispatch_event_partner(event);
            break;
        case ACTOR_CLASS_ENEMY:
            dispatch_event_actor(actor, event);
            break;
    }
}

void play_hit_sound(Actor* actor, f32 x, f32 y, f32 z, u32 hitSound) {
    s32 actorClass = actor->actorID & ACTOR_CLASS_MASK;

    switch (hitSound) {
        case HIT_SOUND_MISS:
            sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_MODE_0, x, y, z);
            break;
        case HIT_SOUND_BONES:
            sfx_play_sound_at_position(SOUND_HIT_BONES, SOUND_SPACE_MODE_0, x, y, z);
            break;
        case HIT_SOUND_NORMAL:
            switch (actorClass) {
                case ACTOR_CLASS_PLAYER:
                    sfx_play_sound_at_position(SOUND_HIT_PLAYER_NORMAL, SOUND_SPACE_MODE_0, x, y, z);
                    break;
                case ACTOR_CLASS_PARTNER:
                    sfx_play_sound_at_position(SOUND_HIT_NORMAL, SOUND_SPACE_MODE_0, x, y, z);
                    break;
                case ACTOR_CLASS_ENEMY:
                    sfx_play_sound_at_position(SOUND_HIT_NORMAL, SOUND_SPACE_MODE_0, x, y, z);
                    break;
            }
            break;
        case HIT_SOUND_FIRE:
            switch (actorClass) {
                case ACTOR_CLASS_PLAYER:
                    sfx_play_sound_at_position(SOUND_HIT_PLAYER_FIRE, SOUND_SPACE_MODE_0, x, y, z);
                    break;
                case ACTOR_CLASS_PARTNER:
                    sfx_play_sound_at_position(SOUND_HIT_FIRE, SOUND_SPACE_MODE_0, x, y, z);
                    break;
                case ACTOR_CLASS_ENEMY:
                    sfx_play_sound_at_position(SOUND_HIT_FIRE, SOUND_SPACE_MODE_0, x, y, z);
                    break;
            }
            break;
        case HIT_SOUND_ICE:
            switch (actorClass) {
                case ACTOR_CLASS_PLAYER:
                    sfx_play_sound_at_position(SOUND_HIT_PLAYER_ICE, SOUND_SPACE_MODE_0, x, y, z);
                    break;
                case ACTOR_CLASS_PARTNER:
                    sfx_play_sound_at_position(SOUND_HIT_ICE, SOUND_SPACE_MODE_0, x, y, z);
                    break;
                case ACTOR_CLASS_ENEMY:
                    sfx_play_sound_at_position(SOUND_HIT_ICE, SOUND_SPACE_MODE_0, x, y, z);
                    break;
            }
            break;
        case HIT_SOUND_SHOCK:
            switch (actorClass) {
                case ACTOR_CLASS_PLAYER:
                    sfx_play_sound_at_position(SOUND_HIT_PLAYER_SHOCK, SOUND_SPACE_MODE_0, x, y, z);
                    break;
                case ACTOR_CLASS_PARTNER:
                    sfx_play_sound_at_position(SOUND_HIT_SHOCK, SOUND_SPACE_MODE_0, x, y, z);
                    break;
                case ACTOR_CLASS_ENEMY:
                    sfx_play_sound_at_position(SOUND_HIT_SHOCK, SOUND_SPACE_MODE_0, x, y, z);
                    break;
            }
            break;
    }
}

void dispatch_event_actor(Actor* actor, s32 event) {
    Evt* handleEventScript = actor->handleEventScript;
    s32 onHitID = actor->handleEventScriptID;

    if (actor->handleEventSource != NULL) {
        Evt* newScript;

        actor->lastEventType = event;
        newScript = start_script(actor->handleEventSource, EVT_PRIORITY_A, EVT_FLAG_RUN_IMMEDIATELY);
        actor->handleEventScript = newScript;
        actor->handleEventScriptID = newScript->id;
        newScript->owner1.actorID = actor->actorID;
    }

    if (actor->takeTurnScript != NULL) {
        get_script_by_index(actor->takeTurnScriptID);
        kill_script_by_ID(actor->takeTurnScriptID);
        actor->takeTurnScript = NULL;
    }

    if (handleEventScript != NULL) {
        kill_script_by_ID(onHitID);
    }
}

HitResult calc_enemy_test_target(Actor* actor) {
    PlayerData* playerData = &gPlayerData;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 targetID = battleStatus->curTargetID;
    s32 targetPartIdx = battleStatus->curTargetPart;
    Actor* target;
    Actor* target2;
    ActorPart* targetPart;
    s32 actorClass;
    s32 hitResult;

    battleStatus->curTargetID2 = battleStatus->curTargetID;
    battleStatus->curTargetPart2 = battleStatus->curTargetPart;

    target = get_actor(targetID);
    if (target == NULL) {
        return HIT_RESULT_HIT;
    }

    targetPart = get_actor_part(target, targetPartIdx);
    ASSERT(targetPart != NULL);

    actorClass = targetID & ACTOR_CLASS_MASK;
    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            target->curHP = playerData->curHP;
            break;
        case ACTOR_CLASS_PARTNER:
            target->curHP = 127;
            break;
        case ACTOR_CLASS_ENEMY:
            break;
    }

    if (battleStatus->curAttackElement & DAMAGE_TYPE_TRIGGER_LUCKY) {
        dispatch_event_general(target, EVENT_LUCKY);
        return HIT_RESULT_HIT;
    }

    hitResult = HIT_RESULT_HIT;
    target2 = target;
    if (targetPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY || battleStatus->outtaSightActive || target2->transparentStatus == STATUS_KEY_TRANSPARENT) {
        if (!(battleStatus->curAttackElement & DAMAGE_TYPE_MAGIC)) {
            hitResult = HIT_RESULT_MISS;
        }
    }

    if (hitResult == HIT_RESULT_MISS) {
        return HIT_RESULT_MISS;
    }
    hitResult = HIT_RESULT_HIT;
    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            if (battleStatus->cloudNineTurnsLeft) {
                if (rand_int(100) < battleStatus->cloudNineDodgeChance) {
                    hitResult = HIT_RESULT_MISS;
                    break;
                }
            } else {
                if (player_team_is_ability_active(target2, ABILITY_PRETTY_LUCKY)) {
                    if (rand_int(100) < 10) {
                        hitResult = HIT_RESULT_LUCKY;
                        break;
                    }
                }
                if (player_team_is_ability_active(target2, ABILITY_CLOSE_CALL) && (target2->curHP < 6)) {
                    if (rand_int(100) < 30) {
                        hitResult = HIT_RESULT_LUCKY;
                        break;
                    }
                }
                if (player_team_is_ability_active(target2, ABILITY_LUCKY_DAY)) {
                    if (rand_int(100) < 20) {
                        hitResult = HIT_RESULT_LUCKY;
                        break;
                    }
                }
            }
            break;
        case ACTOR_CLASS_PARTNER:
            break;
        case ACTOR_CLASS_ENEMY:
            break;
    }

    if (hitResult == HIT_RESULT_MISS) {
        return HIT_RESULT_MISS;
    }

    if (hitResult == HIT_RESULT_LUCKY) {
        return HIT_RESULT_LUCKY;
    }

    if (target2->stoneStatus == STATUS_KEY_STONE) {
        return HIT_RESULT_IMMUNE;
    }

    if (target2->staticStatus == STATUS_KEY_STATIC) {
        return HIT_RESULT_HIT_STATIC;
    }

    return HIT_RESULT_HIT;
}

HitResult calc_enemy_damage_target(Actor* attacker) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActorState* state = &attacker->state;
    s32 targetID = battleStatus->curTargetID;
    s32 targetPartIdx = battleStatus->curTargetPart;
    s32 actorClass;
    Actor* target;
    ActorPart* targetPart;
    s32 hitResult;
    s32 one = TRUE;
    s32 statusInflicted = FALSE;
    s32 statusInflicted2 = FALSE;
    s32 isFire = FALSE;
    s32 isWater = FALSE;
    s32 isIce = FALSE;
    s32 isElectric = FALSE;
    s32 madeElectricContact = FALSE;
    s32 isPlayer;
    s32 defense;
    s32 event;
    s32 damage;
    Evt* script;

    battleStatus->wasStatusInflicted = FALSE;
    battleStatus->lastAttackDamage = 0;

    battleStatus->attackerActorID = attacker->actorID;
    battleStatus->curTargetID2 = targetID;
    battleStatus->curTargetPart2 = targetPartIdx;

    target = get_actor(targetID);
    if (target == NULL) {
        return HIT_RESULT_HIT;
    }

    targetPart = get_actor_part(target, targetPartIdx);
    ASSERT(targetPart != NULL);

    actorClass = targetID & ACTOR_CLASS_MASK;
    target->lastDamageTaken = 0;

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            target->curHP = gPlayerData.curHP;
            break;
        case ACTOR_CLASS_PARTNER:
            target->curHP = 127;
            break;
        case ACTOR_CLASS_ENEMY:
            break;
    }

    // handle defender status

    if (targetPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
        return HIT_RESULT_MISS;
    }

    if (target->transparentStatus == STATUS_KEY_TRANSPARENT
        || targetPart->eventFlags & ACTOR_EVENT_FLAG_800
        && !(battleStatus->curAttackElement & DAMAGE_TYPE_QUAKE)
    ) {
        return HIT_RESULT_MISS;
    }

    if (target->stoneStatus == STATUS_KEY_STONE) {
        show_immune_bonk(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, -1);
        show_next_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 0);
        play_hit_sound(attacker, state->goalPos.x, state->goalPos.y, state->goalPos.z, 0);
        dispatch_event_general(target, EVENT_IMMUNE);
        return HIT_RESULT_HIT;
    }

    // handle attack element

    if (battleStatus->curAttackElement & DAMAGE_TYPE_BLAST) {
        if (!(battleStatus->curAttackElement & DAMAGE_TYPE_NO_CONTACT)
            && (targetPart->eventFlags & ACTOR_EVENT_FLAG_EXPLODE_ON_IGNITION)
        ) {
            do {
                play_hit_sound(attacker, state->goalPos.x, state->goalPos.y, state->goalPos.z, 3);
            } while (0); // TODO required to match
            dispatch_event_general(target, EVENT_EXPLODE_TRIGGER);
            return HIT_RESULT_BACKFIRE;
        }
    }
    if ((battleStatus->curAttackElement & DAMAGE_TYPE_QUAKE) && (target->flags & ACTOR_FLAG_FLYING)) {
        play_hit_sound(attacker, state->goalPos.x, state->goalPos.y, state->goalPos.z, 1);
        return HIT_RESULT_NO_DAMAGE;
    }
    if (battleStatus->curAttackElement & DAMAGE_TYPE_FIRE) {
        fx_ring_blast(0, state->goalPos.x, state->goalPos.y, state->goalPos.z + 5.0f, 1.0f, 24);
        isFire = TRUE;
    }
    if (battleStatus->curAttackElement & DAMAGE_TYPE_SHOCK) {
        apply_shock_effect(target);
        isElectric = TRUE;
    }
    if (battleStatus->curAttackElement & DAMAGE_TYPE_WATER) {
        fx_water_splash(0, state->goalPos.x, state->goalPos.y, state->goalPos.z + 5.0f, 1.0f, 24);
        isWater = TRUE;
    }
    if (battleStatus->curAttackElement & DAMAGE_TYPE_ICE) {
        fx_big_snowflakes(0, state->goalPos.x, state->goalPos.y, state->goalPos.z + 5.0f);
        isIce = TRUE;
    }

    if (!(attacker->staticStatus == STATUS_KEY_STATIC)
        && ((target->staticStatus == STATUS_KEY_STATIC) || (targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED))
        && !(battleStatus->curAttackElement & (DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_NO_CONTACT))
        && !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_SHOCK_CONTACT)
        && !has_enchanted_part(attacker)) // enchanted attacks ignore electrified defenders
    {
        madeElectricContact = TRUE;
        gBattleStatus.flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;
    }

    // begin calulating damage

    gBattleStatus.flags1 &= ~BS_FLAGS1_ATK_BLOCKED;

    defense = get_defense(target, targetPart->defenseTable, battleStatus->curAttackElement);

    if (!(battleStatus->curAttackElement & DAMAGE_TYPE_IGNORE_DEFENSE)) {
        defense += target->defenseBoost;

        if (actorClass == ACTOR_CLASS_PLAYER) {
            if (battleStatus->waterBlockTurnsLeft > 0) {
                if ((battleStatus->curAttackElement & (DAMAGE_TYPE_BLAST | DAMAGE_TYPE_FIRE))) {
                    defense += 2;
                } else {
                    defense += 1;
                }
            }

            if (gBattleStatus.flags1 & BS_FLAGS1_PLAYER_DEFENDING) {
                defense += 1;
            }
        }
    }

    damage = battleStatus->curAttackDamage;

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            damage -= battleStatus->merleeDefenseBoost;
            break;
        case ACTOR_CLASS_PARTNER:
        case ACTOR_CLASS_ENEMY:
            break;
    }

    damage += attacker->attackBoost;

    if (attacker->chillOutTurns != 0) {
        damage -= attacker->chillOutAmount;
    }

    if (attacker->debuff == STATUS_KEY_SHRINK) {
        if (damage > 0) {
            damage /= 2;
        }
    }

    if (damage > 99) {
        damage = 99;
    }
    if (damage < 1) {
        defense = 0;
    }

    target->hpChangeCounter = 0;
    damage -= defense;

    isPlayer = actorClass == ACTOR_CLASS_PLAYER;
    if (isPlayer) {
        if (player_team_is_ability_active(target, ABILITY_FIRE_SHIELD)) {
            if (battleStatus->curAttackElement & DAMAGE_TYPE_FIRE) {
                damage--;
            }
        }

        damage -= player_team_is_ability_active(target, ABILITY_DEFEND_PLUS);
        damage -= player_team_is_ability_active(target, ABILITY_P_DOWN_D_UP);
        damage += player_team_is_ability_active(target, ABILITY_P_UP_D_DOWN);

        if (target->curHP <= 5) {
            if (player_team_is_ability_active(target, ABILITY_LAST_STAND)) {
                damage /= 2;
            }
        }
    }

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            // TODO figure out how to better write target->debuff >= STATUS_KEY_POISON
            if ((target->debuff == 0 || target->debuff >= STATUS_KEY_POISON) && (target->stoneStatus == 0) && !(battleStatus->curAttackElement & DAMAGE_TYPE_UNBLOCKABLE)) {
                s32 blocked;

                if (player_team_is_ability_active(target, ABILITY_BERSERKER)) {
                    blocked = rand_int(1);
                } else {
                    blocked = check_block_input(BUTTON_A);
                }

                if (blocked) {
                    damage--;
                    damage -= player_team_is_ability_active(target, ABILITY_DAMAGE_DODGE);
                    sfx_play_sound_at_position(SOUND_231, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    show_action_rating(ACTION_RATING_NICE, target, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    gBattleStatus.flags1 |= BS_FLAGS1_ATK_BLOCKED;
                    break;
                }
                func_80266970(target);
            }
            break;
        case ACTOR_CLASS_PARTNER:
            if (target->stoneStatus == 0) {
                if (target->koStatus == 0 && !(battleStatus->curAttackElement & DAMAGE_TYPE_UNBLOCKABLE)) {
                    if (check_block_input(BUTTON_A)) {
                        damage = 0;
                        sfx_play_sound_at_position(SOUND_231, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                        show_action_rating(ACTION_RATING_NICE, target, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                        gBattleStatus.flags1 |= BS_FLAGS1_ATK_BLOCKED;
                        break;
                    }
                    func_80266970(target);
                }
            }
            break;
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        func_80266970(target);
    }

    // deal damage and determine resulting battle event

    event = EVENT_HIT_COMBO;
    if (damage < 1) {
        target->hpChangeCounter = 0;
        if (!(battleStatus->curAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS)) {
            hitResult = HIT_RESULT_NO_DAMAGE;
            event = EVENT_ZERO_DAMAGE;
        } else {
            hitResult = HIT_RESULT_NO_DAMAGE;
            event = EVENT_ZERO_DAMAGE;
            if (target->curHP < 1) {
                event = EVENT_DEATH;
            }
        }
        battleStatus->lastAttackDamage = 0;
    } else {
        target->damageCounter += damage;
        target->hpChangeCounter -= damage;
        battleStatus->lastAttackDamage = 0;
        hitResult = HIT_RESULT_HIT;
        if (!(targetPart->flags & ACTOR_PART_FLAG_2000)
            && !(gBattleStatus.flags1 & BS_FLAGS1_TUTORIAL_BATTLE)
        ) {
            if (!(target->flags & ACTOR_FLAG_NO_DMG_APPLY)) {
                target->curHP -= damage;
            }

            if (target->curHP < 1) {
                target->curHP = 0;
                event = EVENT_DEATH;
            }
        }
        battleStatus->lastAttackDamage += damage;
        target->lastDamageTaken = battleStatus->lastAttackDamage;
        target->hpChangeCounter = 0;

        if (actorClass == ACTOR_CLASS_PLAYER) {
            battleStatus->damageTaken += damage;
            gPlayerData.curHP = target->curHP;
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (event == EVENT_HIT_COMBO) {
            event = EVENT_HIT;
        }
        if (event == EVENT_ZERO_DAMAGE) {
            event = EVENT_IMMUNE;
        }
        if (target->curHP < 1 && event == EVENT_IMMUNE) {
            event = EVENT_DEATH;
        }
    } else if (event == EVENT_DEATH) {
        event = EVENT_HIT_COMBO;
    }

    if (!(gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE)) {
        clear_part_pal_adjustment(targetPart);
    }

    if ((gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE)
        && (battleStatus->curAttackElement & (DAMAGE_TYPE_POW | DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_JUMP))
        && (targetPart->eventFlags & ACTOR_EVENT_FLAG_FLIPABLE)
    ) {
        if (event == EVENT_HIT) {
            event = EVENT_FLIP_TRIGGER;
        }
        if (event == EVENT_IMMUNE) {
            event = EVENT_FLIP_TRIGGER;
        }
    }

    if (!(gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE)
        && (battleStatus->curAttackElement & (DAMAGE_TYPE_POW | DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_JUMP))
        && (targetPart->eventFlags & ACTOR_EVENT_FLAG_FLIPABLE)
    ) {
        if (event == EVENT_HIT_COMBO) {
            event = EVENT_FLIP_TRIGGER;
        }
        if (event == EVENT_ZERO_DAMAGE) {
            event = EVENT_FLIP_TRIGGER;
        }
    }

    if ((gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE)
        && (battleStatus->curAttackElement & (DAMAGE_TYPE_FIRE | DAMAGE_TYPE_BLAST | DAMAGE_TYPE_4000))
    ) {
        if (event == EVENT_HIT) {
            event = EVENT_BURN_HIT;
        }
        if (event == EVENT_DEATH) {
            event = EVENT_FIRE_DEATH;
        }
        isFire = TRUE;
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_ATK_BLOCKED) {
        if (event == EVENT_HIT_COMBO) {
            event = EVENT_18;
        }
        if (event == EVENT_HIT) {
            event = EVENT_BLOCK;
        }
        if (event == EVENT_ZERO_DAMAGE) {
            event = EVENT_18;
        }
        if (event == EVENT_IMMUNE) {
            event = EVENT_BLOCK;
        }
        if (event == EVENT_BURN_HIT) {
            event = EVENT_BLOCK;
        }
    }

    // try inflicting status effect

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE
        && battleStatus->lastAttackDamage >= 0
        && event != EVENT_DEATH
        && event != EVENT_SPIN_SMASH_DEATH
        && event != EVENT_EXPLODE_TRIGGER
        && !(gBattleStatus.flags1 & BS_FLAGS1_ATK_BLOCKED)
        && !(gBattleStatus.flags2 & BS_FLAGS2_1000000)
        && !(actorClass == ACTOR_PLAYER && is_ability_active(ABILITY_HEALTHY_HEALTHY) && (rand_int(100) < 50)))
    {
        if (battleStatus->curAttackStatus & STATUS_FLAG_SHRINK && try_inflict_status(target, STATUS_KEY_SHRINK, STATUS_TURN_MOD_SHRINK)) {
            statusInflicted = one;
            statusInflicted2 = one;
        }
        if (battleStatus->curAttackStatus & STATUS_FLAG_POISON && try_inflict_status(target, STATUS_KEY_POISON, STATUS_TURN_MOD_POISON)) {
            statusInflicted = one;
            statusInflicted2 = one;
        }
        if (battleStatus->curAttackStatus & STATUS_FLAG_STONE && try_inflict_status(target, STATUS_KEY_STONE, STATUS_TURN_MOD_STONE)) {
            statusInflicted = one;
            statusInflicted2 = one;
        }
        if (battleStatus->curAttackStatus & STATUS_FLAG_SLEEP && try_inflict_status(target, STATUS_KEY_SLEEP, STATUS_TURN_MOD_SLEEP)) {
            statusInflicted = one;
            statusInflicted2 = one;
        }
        if (battleStatus->curAttackStatus & STATUS_FLAG_DIZZY && try_inflict_status(target, STATUS_KEY_DIZZY, STATUS_TURN_MOD_DIZZY)) {
            statusInflicted = one;
            statusInflicted2 = one;
        }
        if (battleStatus->curAttackStatus & STATUS_FLAG_STOP && try_inflict_status(target, STATUS_KEY_STOP, STATUS_TURN_MOD_STOP)) {
            statusInflicted = one;
            statusInflicted2 = one;
        }
        if (battleStatus->curAttackStatus & STATUS_FLAG_STATIC && try_inflict_status(target, STATUS_KEY_STATIC, STATUS_TURN_MOD_STATIC)) {
            statusInflicted = one;
            statusInflicted2 = one;
        }
        if (battleStatus->curAttackStatus & STATUS_FLAG_PARALYZE && try_inflict_status(target, STATUS_KEY_PARALYZE, STATUS_TURN_MOD_PARALYZE)) {
            statusInflicted = one;
            statusInflicted2 = one;
        }
        if (battleStatus->curAttackStatus & STATUS_FLAG_FEAR && try_inflict_status(target, STATUS_KEY_FEAR, STATUS_TURN_MOD_FEAR)) {
            statusInflicted = one;
            statusInflicted2 = one;
        }

        // @bug? repeated paralyze and dizzy infliction
        if (battleStatus->curAttackStatus & STATUS_FLAG_PARALYZE && try_inflict_status(target, STATUS_KEY_PARALYZE, STATUS_TURN_MOD_PARALYZE)) {
            statusInflicted = one;
            statusInflicted2 = one;
        }
        if (battleStatus->curAttackStatus & STATUS_FLAG_DIZZY && try_inflict_status(target, STATUS_KEY_DIZZY, STATUS_TURN_MOD_DIZZY)) {
            statusInflicted = one;
            statusInflicted2 = one;
        }

        if (battleStatus->curAttackStatus & STATUS_FLAG_FROZEN && target->debuff != STATUS_KEY_FROZEN && try_inflict_status(target, STATUS_KEY_FROZEN, STATUS_TURN_MOD_FROZEN)) {
            statusInflicted = one;
            statusInflicted2 = one;
        }

        if (statusInflicted) {
            if (event == EVENT_ZERO_DAMAGE) {
                event = EVENT_HIT_COMBO;
            }
            if (event == EVENT_IMMUNE) {
                event = EVENT_HIT;
            }
        }
    }

    // dispatch events and play damage effects

    battleStatus->wasStatusInflicted = statusInflicted;

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            dispatch_event_player(event);
            break;
        case ACTOR_CLASS_PARTNER:
            dispatch_event_partner(event);
            break;
        case ACTOR_CLASS_ENEMY:
            dispatch_event_actor(target, event);
            break;
    }

    if (actorClass == ACTOR_CLASS_PARTNER
        && battleStatus->lastAttackDamage > 0
        && gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE
        && !(target->flags & ACTOR_FLAG_NO_DMG_APPLY))
    {
        inflict_partner_ko(target, STATUS_KEY_DAZE, battleStatus->lastAttackDamage);
    }

    if (!(target->flags & ACTOR_FLAG_NO_DMG_POPUP)) {
        switch (actorClass) {
            case ACTOR_CLASS_PLAYER:
            case ACTOR_CLASS_PARTNER:
                if (battleStatus->lastAttackDamage == 0) {
                    if (!statusInflicted2 && !statusInflicted) {
                        // immune star fx?
                        show_immune_bonk(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, -3);
                    }
                } else if (battleStatus->curAttackElement & (DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_SMASH)) {
                    show_next_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 1);
                    show_damage_fx(target, state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage);
                } else {
                    show_primary_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 1);
                    show_damage_fx(target, state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage);
                    break;
                }
                break;
            case ACTOR_CLASS_ENEMY:
                if (battleStatus->lastAttackDamage == 0) {
                    if (!statusInflicted2 && !statusInflicted) {
                        show_immune_bonk(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, 3);
                    }
                } else if (battleStatus->curAttackElement & (DAMAGE_TYPE_MULTIPLE_POPUPS | DAMAGE_TYPE_SMASH)) {
                    show_next_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 0);
                    show_damage_fx(target, state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage);
                } else {
                    show_primary_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 0);
                    show_damage_fx(target, state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage);
                }
                break;
        }
    }

    if (battleStatus->lastAttackDamage > 0) {
        u32 hitSound;

        func_80267018(target, 1);

        if (attacker->actorTypeData1[5] != SOUND_NONE) {
            sfx_play_sound_at_position(attacker->actorTypeData1[5], SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        }

        if (isFire) {
            hitSound = HIT_SOUND_FIRE;
        } else if (!isElectric) {
            hitSound = HIT_SOUND_NORMAL;
        } else {
            hitSound = HIT_SOUND_SHOCK;
        }

        play_hit_sound(target, state->goalPos.x, state->goalPos.y, state->goalPos.z, hitSound);
    }

    if ((battleStatus->lastAttackDamage < 1 && !statusInflicted2 && !madeElectricContact) || targetPart->flags & ACTOR_PART_FLAG_2000) {
        sfx_play_sound_at_position(SOUND_IMMUNE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if ((battleStatus->curAttackStatus & STATUS_FLAG_SLEEP) && statusInflicted) {
        script = start_script(&EVS_PlaySleepHitFX, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_SLEEP, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->curAttackStatus & STATUS_FLAG_DIZZY) && statusInflicted) {
        script = start_script(&EVS_PlayDizzyHitFX, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->curAttackStatus & STATUS_FLAG_PARALYZE) && statusInflicted) {
        script = start_script(&EVS_PlayParalyzeHitFX, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->curAttackStatus & STATUS_FLAG_POISON) && statusInflicted) {
        script = start_script(&EVS_PlayPoisonHitFX, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->curAttackStatus & STATUS_FLAG_STOP) && statusInflicted) {
        script = start_script(&EVS_PlayStopHitFX, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->curAttackStatus & STATUS_FLAG_FROZEN) && statusInflicted) {
        script = start_script(&EVS_PlayFreezeHitFX, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        script->varTablePtr[3] = target;
        sfx_play_sound_at_position(SOUND_HIT_ICE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->curAttackStatus & STATUS_FLAG_SHRINK) && statusInflicted) {
        script = start_script(&EVS_PlayShrinkHitFX, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        script->varTablePtr[3] = target;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if ((battleStatus->curAttackElement & DAMAGE_TYPE_SMASH) && target->actorType == ACTOR_TYPE_GOOMNUT_TREE) {
        sfx_play_sound_at_position(SOUND_SMASH_GOOMNUT_TREE, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    show_actor_health_bar(target);

    if (attacker->staticStatus != STATUS_KEY_STATIC
        && (target->staticStatus == STATUS_KEY_STATIC || targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED)
        && !(battleStatus->curAttackElement & DAMAGE_TYPE_NO_CONTACT)
        && !(battleStatus->curAttackEventSuppression & SUPPRESS_EVENT_SHOCK_CONTACT)
        && (attacker->transparentStatus != STATUS_KEY_TRANSPARENT)
        && !has_enchanted_part(attacker))
    {
        sfx_play_sound_at_position(SOUND_HIT_SHOCK, SOUND_SPACE_MODE_0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        apply_shock_effect(attacker);
        dispatch_damage_event_actor_1(attacker, 1, EVENT_SHOCK_HIT);
        return HIT_RESULT_BACKFIRE;
    }

    return hitResult;
}

s32 dispatch_damage_event_actor(Actor* actor, s32 damageAmount, s32 originalEvent, s32 stopMotion) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActorState* state = &actor->state;
    s32 dispatchEvent = originalEvent;
    s32 currentAttackDamage;
    s32 hpChangeCounter;
    s32 hpChange;
    s32 flagCheck;
    s32 new_var;

    battleStatus->curAttackDamage = damageAmount;
    hpChange = (s16) damageAmount;
    actor->hpChangeCounter += hpChange;
    new_var = actor->hpChangeCounter;
    hpChange = new_var;
    actor->damageCounter += hpChange;
    actor->hpChangeCounter -= hpChange;
    battleStatus->lastAttackDamage = 0;
    actor->curHP -= hpChange;

    if (actor->curHP <= 0) {
        dispatchEvent = EVENT_DEATH;
        battleStatus->lastAttackDamage += actor->curHP;
        actor->curHP = 0;
    }

    battleStatus->lastAttackDamage += hpChange;
    actor->lastDamageTaken = battleStatus->lastAttackDamage;
    battleStatus->curDamageSource = DMG_SRC_DEFAULT;
    if (battleStatus->flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (dispatchEvent == EVENT_HIT_COMBO) {
            dispatchEvent = EVENT_HIT;
        }
        if (dispatchEvent == EVENT_ZERO_DAMAGE) {
            dispatchEvent = EVENT_IMMUNE;
        }
    }
    if (dispatchEvent == EVENT_DEATH) {
        if (originalEvent == EVENT_SPIN_SMASH_LAUNCH_HIT) {
            dispatchEvent = EVENT_SPIN_SMASH_LAUNCH_DEATH;
        }
        if (originalEvent == EVENT_SHOCK_HIT) {
            dispatchEvent = EVENT_SHOCK_DEATH;
        }
    }

    if (!stopMotion) {
        s32 oldTargetActorID = actor->targetActorID;

        if (func_80263230(actor, actor) != 0) {
            show_next_damage_popup(actor->targetData[0].posA.x, actor->targetData[0].posA.y, actor->targetData[0].posA.z, battleStatus->lastAttackDamage, 0);
            show_damage_fx(actor, actor->targetData[0].posA.x, actor->targetData[0].posA.y, actor->targetData[0].posA.z, battleStatus->lastAttackDamage);
            actor->targetActorID = oldTargetActorID;
        } else {
            actor->targetActorID = oldTargetActorID;
        }
    } else {
        show_next_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 0);
        show_damage_fx(actor, state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage);
    }

    if (battleStatus->lastAttackDamage > 0) {
        func_80267018(actor, 1);
    }
    actor->flags |= ACTOR_FLAG_HEALTH_BAR_HIDDEN;
    dispatch_event_actor(actor, dispatchEvent);
    return 0;
}

s32 dispatch_damage_event_actor_0(Actor* actor, s32 damageAmount, s32 event) {
    return dispatch_damage_event_actor(actor, damageAmount, event, FALSE);
}

s32 dispatch_damage_event_actor_1(Actor* actor, s32 damageAmount, s32 event) {
    return dispatch_damage_event_actor(actor, damageAmount, event, TRUE);
}

ApiStatus BindTakeTurn(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    EvtScript* takeTurnScript;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    takeTurnScript = (EvtScript*) evt_get_variable(script, *args++);
    get_actor(actorID)->takeTurnSource = takeTurnScript;
    return ApiStatus_DONE2;
}

ApiStatus PauseTakeTurn(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    evt_get_variable(script, *args++);
    suspend_all_script(get_actor(actorID)->takeTurnScriptID);
    return ApiStatus_DONE2;
}

ApiStatus ResumeTakeTurn(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    evt_get_variable(script, *args++);
    resume_all_script(get_actor(actorID)->takeTurnScriptID);
    return ApiStatus_DONE2;
}

ApiStatus BindIdle(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    EvtScript* idleCode;
    Actor* actor;
    Evt* newScriptContext;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    idleCode = (EvtScript*) evt_get_variable(script, *args++);
    actor = get_actor(actorID);

    if (actor->idleScript != 0) {
        kill_script_by_ID(actor->idleScriptID);
        actor->idleScript = 0;
    }

    actor->idleSource = idleCode;
    newScriptContext = start_script(idleCode, EVT_PRIORITY_A, 0);
    actor->idleScript = newScriptContext;
    actor->idleScriptID = newScriptContext->id;
    newScriptContext->owner1.actorID = actorID;
    return ApiStatus_DONE2;
}

ApiStatus EnableIdleScript(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 var1;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    var1 = evt_get_variable(script, *args++);
    actor = get_actor(actorID);

    if (actor->idleScript != NULL) {
        switch (var1) {
            case -1:
                restart_script(actor->idleScript);
                resume_all_script(actor->idleScriptID);
                break;
            case 1:
                resume_all_script(actor->idleScriptID);
                break;
            case 0:
                suspend_all_script(actor->idleScriptID);
                break;
        }
    }

    return ApiStatus_DONE2;
}

ApiStatus BindHandleEvent(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    EvtScript* src;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    src = (EvtScript*) evt_get_variable(script, *args++);
    get_actor(actorID)->handleEventSource = src;
    return ApiStatus_DONE2;
}

ApiStatus BindNextTurn(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    EvtScript* src;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    src = (EvtScript*) evt_get_variable(script, *args++);
    get_actor(actorID)->handlePhaseSource = src;
    return ApiStatus_DONE2;
}

ApiStatus JumpToGoal(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorState* actorState;
    s32 actorID;
    f32 posX, posY, posZ;
    f32 goalX, goalY, goalZ;
    f32 moveDist;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        actorID = evt_get_variable(script, *args++);
        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.enemyID;
        }
        script->functionTempPtr[1] = actor = get_actor(actorID);
        actorState = &actor->state;
        actorState->moveTime = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        script->functionTemp[3] = 0;
        if (evt_get_variable(script, *args++) != 0) {
            script->functionTemp[3] |= 1;
        }
        if (evt_get_variable(script, *args++) != 0) {
            script->functionTemp[3] |= 2;
        }

        actorState->curPos.x = actor->curPos.x;
        actorState->curPos.y = actor->curPos.y;
        actorState->curPos.z = actor->curPos.z;

        posX = actorState->curPos.x;
        posY = actorState->curPos.y;
        posZ = actorState->curPos.z;
        goalX = actorState->goalPos.x;
        goalY = actorState->goalPos.y;
        goalZ = actorState->goalPos.z;
        actorState->angle = atan2(posX, posZ, goalX, goalZ);
        actorState->dist = dist2D(posX, posZ, goalX, goalZ);

        // make relative
        posX = (goalX - posX);
        posY = (goalY - posY);
        posZ = (goalZ - posZ);

        if (actorState->moveTime == 0) {
            actorState->moveTime = actorState->dist / actorState->speed;
            moveDist = actorState->dist - (actorState->moveTime * actorState->speed);
        } else {
            actorState->speed = actorState->dist / actorState->moveTime;
            moveDist = actorState->dist - (actorState->moveTime * actorState->speed);
        }

        if (actorState->moveTime == 0) {
            return ApiStatus_DONE2;
        }

        actorState->vel = (actorState->acceleration * actorState->moveTime * 0.5f) + (posY / actorState->moveTime);
        actorState->speed += (moveDist / actorState->moveTime);

        if (script->functionTemp[2] != 0) {
            set_animation(actor->actorID, (s8) actor->state.jumpPartIndex, actor->state.animJumpRise);
        }
        if (!(script->functionTemp[3] & 2) && (actor->actorTypeData1[4] != 0)) {
            sfx_play_sound_at_position(actor->actorTypeData1[4], SOUND_SPACE_MODE_0, actor->curPos.x, actor->curPos.y, actor->curPos.z);
        }
        script->functionTemp[0] = 1;
    }

    actor = script->functionTempPtr[1];
    actorState = &actor->state;

    actorState->curPos.y += actorState->vel;
    actorState->vel -= actorState->acceleration;

    if ((script->functionTemp[2] != 0) && (actorState->vel < 0.0f)) {
        set_animation(actor->actorID, (s8) actorState->jumpPartIndex, actorState->animJumpFall);
    }
    if (actorState->vel < 0.0f) {
        if (actorState->curPos.y < actorState->goalPos.y) {
            actorState->curPos.y = actorState->goalPos.y;
        }
    }

    add_xz_vec3f(&actorState->curPos, actorState->speed, actorState->angle);
    actor->curPos.x = actorState->curPos.x;
    actor->curPos.y = actorState->curPos.y;
    actor->curPos.z = actorState->curPos.z;

    actorState->moveTime--;
    if (actorState->moveTime > 0) {
        return ApiStatus_BLOCK;
    }

    if (script->functionTemp[3] & 1) {
        play_movement_dust_effects(2, actorState->goalPos.x, actorState->goalPos.y, actorState->goalPos.z, actorState->angle);
    }
    actor->curPos.x = actorState->goalPos.x;
    actor->curPos.y = actorState->goalPos.y;
    actor->curPos.z = actorState->goalPos.z;
    if (script->functionTemp[2] != 0) {
        set_animation(actor->actorID, (s8) actorState->jumpPartIndex, actorState->animJumpLand);
    }
    return ApiStatus_DONE1;
}

ApiStatus IdleJumpToGoal(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorMovement* movement;
    f32 posX, posY, posZ;
    f32 goalX, goalY, goalZ;
    f32 moveDist;

    if (isInitialCall) {
        script->functionTemp[0] = FALSE;
    }

    if (!script->functionTemp[0]) {
        s32 actorID = evt_get_variable(script, *args++);

        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }

        script->functionTempPtr[1] = actor = get_actor(actorID);
        movement = &actor->fly;

        actor->fly.flyTime = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        script->functionTemp[3] = evt_get_variable(script, *args++);

        movement->curPos.x = actor->curPos.x;
        movement->curPos.y = actor->curPos.y;
        movement->curPos.z = actor->curPos.z;

        posX = movement->curPos.x;
        posY = movement->curPos.y;
        posZ = movement->curPos.z;
        goalX = movement->goalPos.x;
        goalY = movement->goalPos.y;
        goalZ = movement->goalPos.z;
        movement->angle = atan2(posX, posZ, goalX, goalZ);
        movement->dist = dist2D(posX, posZ, goalX, goalZ);

        // make relative
        posX = (goalX - posX);
        posY = (goalY - posY);
        posZ = (goalZ - posZ);

        if (movement->flyTime == 0) {
            movement->flyTime = movement->dist / movement->speed;
            moveDist = movement->dist - (movement->flyTime * movement->speed);
        } else {
            movement->speed = movement->dist / movement->flyTime;
            moveDist = movement->dist - (movement->flyTime * movement->speed);
        }

        if (movement->flyTime == 0) {
            return ApiStatus_DONE2;
        }

        movement->vel = (movement->acceleration * movement->flyTime * 0.5f) + (posY / movement->flyTime);
        movement->speed += moveDist / movement->flyTime;
        script->functionTemp[0] = TRUE;
    }

    actor = script->functionTempPtr[1];
    movement = &actor->fly;

    movement->curPos.y += movement->vel;
    movement->vel -= movement->acceleration;
    if (movement->vel < 0.0f && movement->goalPos.y > movement->curPos.y) {
        movement->curPos.y = movement->goalPos.y;
    }
    add_xz_vec3f_copy2(&movement->curPos, movement->speed, movement->angle);
    actor->curPos.x = movement->curPos.x;
    actor->curPos.y = movement->curPos.y;
    actor->curPos.z = movement->curPos.z;

    movement->flyTime--;
    if (movement->flyTime <= 0) {
        if (script->functionTemp[3] != 0) {
            play_movement_dust_effects(2, movement->goalPos.x, movement->goalPos.y, movement->goalPos.z, movement->angle);
        }
        actor->curPos.x = movement->goalPos.x;
        actor->curPos.y = movement->goalPos.y;
        actor->curPos.z = movement->goalPos.z;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus JumpToGoalSimple2(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorState* state;
    f32 posX, posY, posZ;
    f32 goalX, goalY, goalZ;
    f32 moveDist;
    Actor* actor;

    if (isInitialCall) {
        script->functionTemp[0] = FALSE;
    }

    if (!script->functionTemp[0]) {
        s32 actorID = evt_get_variable(script, *args++);

        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }

        script->functionTempPtr[1] = actor = get_actor(actorID);
        state = &actor->state;

        state->moveTime = evt_get_variable(script, *args++);
        state->curPos.x = actor->curPos.x;
        state->curPos.y = actor->curPos.y;
        state->curPos.z = actor->curPos.z;

        posX = state->curPos.x;
        posY = state->curPos.y;
        posZ = state->curPos.z;
        goalX = state->goalPos.x;
        goalY = state->goalPos.y;
        goalZ = state->goalPos.z;
        state->angle = atan2(posX, posZ, goalX, goalZ);
        state->dist = dist2D(posX, posZ, goalX, goalZ);

        // make relative (note: negated)
        posX = (posX - goalX);
        posY = (posY - goalY);
        posZ = (posZ - goalZ);

        if (state->moveTime == 0) {
            state->moveTime = state->dist / state->speed;
            moveDist = state->dist - (state->moveTime * state->speed);
        } else {
            state->speed = state->dist / state->moveTime;
            moveDist = state->dist - (state->moveTime * state->speed);
        }

        if (state->moveTime == 0) {
            return ApiStatus_DONE2;
        }

        state->vel = ((state->acceleration * state->moveTime) * 0.5f) + (posY / state->moveTime);
        state->speed += moveDist / state->moveTime;
        if (actor->actorTypeData1[4] != 0) {
            sfx_play_sound_at_position(actor->actorTypeData1[4], SOUND_SPACE_MODE_0, actor->curPos.x, actor->curPos.y, actor->curPos.z);
        }
        script->functionTemp[0] = TRUE;
    }

    actor = script->functionTempPtr[1];
    state = &actor->state;

    state->curPos.y -= state->vel;
    state->vel -= state->acceleration;
    if (state->vel > 0.0f && state->goalPos.y < state->curPos.y) {
        state->curPos.y = state->goalPos.y;
    }
    add_xz_vec3f(&state->curPos, state->speed, state->angle);
    actor->curPos.x = state->curPos.x;
    actor->curPos.y = state->curPos.y;
    actor->curPos.z = state->curPos.z;

    state->moveTime--;
    if (state->moveTime <= 0) {
        play_movement_dust_effects(2, state->goalPos.x, state->goalPos.y, state->goalPos.z, state->angle);
        actor->curPos.x = state->goalPos.x;
        actor->curPos.y = state->goalPos.y;
        actor->curPos.z = state->goalPos.z;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus JumpWithBounce(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorState* actorState;
    s32 actorID;
    f32 posX, posY, posZ;
    f32 goalX, goalY, goalZ;
    f32 moveDist;

    if (isInitialCall) {
        script->functionTemp[0] = FALSE;
    }

    if (!script->functionTemp[0]) {
        actorID = evt_get_variable(script, *args++);
        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.enemyID;
        }
        script->functionTempPtr[1] = actor = get_actor(actorID);
        actorState = &actor->state;

        actorState->moveTime = evt_get_variable(script, *args++);
        actorState->bounceDivisor = evt_get_float_variable(script, *args++);

        actorState->curPos.x = actor->curPos.x;
        actorState->curPos.y = actor->curPos.y;
        actorState->curPos.z = actor->curPos.z;

        posX = actorState->curPos.x;
        posY = actorState->curPos.y;
        posZ = actorState->curPos.z;
        goalX = actorState->goalPos.x;
        goalZ = actorState->goalPos.z;
        goalY = actorState->goalPos.y;
        actorState->angle = atan2(posX, posZ, goalX, goalZ);
        actorState->dist = dist2D(posX, posZ, goalX, goalZ);

        // make relative
        posX = (goalX - posX);
        posY = (goalY - posY);
        posZ = (goalZ - posZ);

        if (actorState->moveTime == 0) {
            actorState->moveTime = (s32) (actorState->dist / actorState->speed);
            moveDist = actorState->dist - (actorState->moveTime * actorState->speed);
        } else {
            actorState->speed = actorState->dist / actorState->moveTime;
            moveDist = actorState->dist - (actorState->moveTime * actorState->speed);
        }

        if (actorState->moveTime == 0) {
            return ApiStatus_DONE2;
        }

        actorState->vel = (actorState->acceleration * actorState->moveTime * 0.5f) + (posY / actorState->moveTime);
        actorState->speed += moveDist / actorState->moveTime;

        if (actor->actorTypeData1[4] != 0) {
            sfx_play_sound_at_position(actor->actorTypeData1[4], SOUND_SPACE_MODE_0, actor->curPos.x, actor->curPos.y, actor->curPos.z);
        }
        script->functionTemp[0] = TRUE;
    }

    actor = script->functionTempPtr[1];
    actorState = &actor->state;

    switch (script->functionTemp[0]) {
        case 1:
            actorState->curPos.y += actorState->vel;
            actorState->vel -= actorState->acceleration;
            if ((actorState->vel < 0.0f) && (actorState->curPos.y < actorState->goalPos.y)) {
                actorState->acceleration = -actorState->acceleration;
                actorState->vel /= actorState->bounceDivisor;
                script->functionTemp[0] = 2;
            }
            add_xz_vec3f(&actorState->curPos, actorState->speed, actorState->angle);
            break;
        case 2:
            actorState->curPos.y += actorState->vel;
            actorState->vel -= actorState->acceleration;
            if (actorState->vel > 0.0f) {
                if (actorState->goalPos.y < actorState->curPos.y) {
                    actorState->curPos.y = actorState->goalPos.y;
                    script->functionTemp[0] = 3;
                }
            }
            add_xz_vec3f(&actorState->curPos, actorState->speed, actorState->angle);
            actor->curPos.x = actorState->curPos.x;
            actor->curPos.y = actorState->curPos.y;
            actor->curPos.z = actorState->curPos.z;
            break;

        case 3:
            return ApiStatus_DONE2;
    }

    actor->curPos.x = actorState->curPos.x;
    actor->curPos.y = actorState->curPos.y;
    actor->curPos.z = actorState->curPos.z;
    return ApiStatus_BLOCK;
}

ApiStatus LandJump(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;

    if (isInitialCall) {
        script->functionTemp[0] = FALSE;
    }

    if (!script->functionTemp[0]) {
        s32 actorID = evt_get_variable(script, *args++);

        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }

        actor = get_actor(actorID);
        script->functionTempPtr[1] = actor;
        actor->state.curPos.x = actor->curPos.x;
        actor->state.curPos.y = actor->curPos.y;
        actor->state.curPos.z = actor->curPos.z;
        script->functionTemp[0] = TRUE;
    }

    actor = script->functionTempPtr[1];
    actor->state.curPos.y += actor->state.vel;
    actor->state.vel -= actor->state.acceleration;

    add_xz_vec3f(&actor->state.curPos, actor->state.speed, actor->state.angle);
    actor->curPos.x = actor->state.curPos.x;
    actor->curPos.y = actor->state.curPos.y;
    actor->curPos.z = actor->state.curPos.z;

    if (actor->curPos.y < 0.0f) {
        actor->curPos.y = 0.0f;
        play_movement_dust_effects(2, actor->curPos.x, actor->curPos.y, actor->curPos.z, actor->yaw);
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus FallToGoal(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorState* state;
    f32 posX, posY, posZ;
    f32 goalX, goalY, goalZ;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        s32 actorID = evt_get_variable(script, *args++);

        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.enemyID;
        }
        actor = get_actor(actorID);
        state = &actor->state;
        script->functionTempPtr[1] = actor;

        actor->state.moveTime = evt_get_variable(script, *args++);

        actor->state.curPos.x = actor->curPos.x;
        actor->state.curPos.y = actor->curPos.y;
        actor->state.curPos.z = actor->curPos.z;

        posX = actor->state.curPos.x;
        posY = actor->state.curPos.y;
        posZ = actor->state.curPos.z;
        goalX = actor->state.goalPos.x;
        goalY = actor->state.goalPos.y;
        goalZ = actor->state.goalPos.z;

        actor->state.angle = atan2(posX, posZ, goalX, goalZ);
        actor->state.dist = dist2D(posX, posZ, goalX, goalZ);

        // make relative
        posX = (goalX - posX);
        posY = (goalY - posY);
        posZ = (goalZ - posZ);

        if (actor->state.moveTime == 0) {
            actor->state.moveTime = actor->state.dist / actor->state.speed;
        } else {
            actor->state.speed = actor->state.dist / actor->state.moveTime;
        }

        state->vel = 0.0f;
        state->acceleration = (posY / state->moveTime - state->vel) / (-state->moveTime * 0.5);

        if (actor->actorTypeData1[4] != 0) {
            sfx_play_sound_at_position(actor->actorTypeData1[4], SOUND_SPACE_MODE_0, actor->curPos.x, actor->curPos.y, actor->curPos.z);
        }
        script->functionTemp[0] = 1;
    }

    actor = script->functionTempPtr[1];
    actor->state.curPos.y += actor->state.vel;
    actor->state.vel -= actor->state.acceleration;
    add_xz_vec3f(&actor->state.curPos, actor->state.speed, actor->state.angle);
    actor->curPos.x = actor->state.curPos.x;
    actor->curPos.y = actor->state.curPos.y;
    actor->curPos.z = actor->state.curPos.z;
    actor->state.moveTime--;

    if (actor->state.moveTime <= 0) {
        play_movement_dust_effects(2, actor->state.goalPos.x, actor->state.goalPos.y, actor->state.goalPos.z, actor->state.angle);
        actor->curPos.x = actor->state.goalPos.x;
        actor->curPos.y = actor->state.goalPos.y;
        actor->curPos.z = actor->state.goalPos.z;
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus RunToGoal(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorState* actorState;
    s32 actorID;
    f32 posX, posY, posZ;
    f32 goalX, goalY, goalZ;

    if (isInitialCall) {
        script->functionTemp[0] = FALSE;
    }

    if (!script->functionTemp[0]) {
        actorID = evt_get_variable(script, *args++);
        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.enemyID;
        }
        script->functionTempPtr[1] = actor = get_actor(actorID);
        actorState = &actor->state;

        actorState->moveTime = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);

        actorState->curPos.x = actor->curPos.x;
        actorState->curPos.y = actor->curPos.y;
        actorState->curPos.z = actor->curPos.z;

        goalX = actorState->goalPos.x;
        goalY = actorState->goalPos.y;
        goalZ = actorState->goalPos.z;
        posX = actorState->curPos.x;
        posY = actorState->curPos.y;
        posZ = actorState->curPos.z;

        actorState->unk_18.x = goalX;
        actorState->unk_18.y = goalY;
        actorState->unk_18.z = goalZ;

        actorState->angle = atan2(posX, posZ, goalX, goalZ);
        actorState->dist = dist2D(posX, posZ, goalX, goalZ);

        if (actorState->moveTime == 0) {
            actorState->moveTime = actorState->dist / actorState->speed;
            if (actorState->moveTime == 0) {
                actorState->moveTime = 1;
            }
            actorState->speed += (actorState->dist - (actorState->moveTime * actorState->speed)) / actorState->moveTime;
        } else {
            actorState->speed = actorState->dist / actorState->moveTime;
        }

        if (actor->actorTypeData1b[0] >= 0) {
            actorState->dist = actor->actorTypeData1b[0] + 1;
        } else {
            actorState->dist = ~actor->actorTypeData1b[0]; //TODO optimization?
        }
        if ((actor->actorTypeData1[0] != 0) && (actor->actorTypeData1[1] == 0)) {
            sfx_play_sound_at_position(actor->actorTypeData1[0], SOUND_SPACE_MODE_0, actor->curPos.x, actor->curPos.y, actor->curPos.z);
        }
        script->functionTemp[0] = TRUE;
    }

    actor = script->functionTempPtr[1];
    actorState = &actor->state;

    add_xz_vec3f(&actorState->curPos, actorState->speed, actorState->angle);
    if (script->functionTemp[2] == 0) {
        if (actorState->speed < 4.0f) {
            play_movement_dust_effects(0, actorState->curPos.x, actorState->curPos.y, actorState->curPos.z, actorState->angle);
        } else {
            play_movement_dust_effects(1, actorState->curPos.x, actorState->curPos.y, actorState->curPos.z, actorState->angle);
        }
    }
    actor->curPos.x = actorState->curPos.x;
    actor->curPos.z = actorState->curPos.z;

    if ((actor->actorTypeData1[0] != 0) && (actor->actorTypeData1[1] != 0)) {
        if (actor->actorTypeData1b[0] >= 0) {
            actorState->dist += actorState->speed;
            if (actor->actorTypeData1b[0] < actorState->dist) {
                actor->footStepCounter++;
                actorState->dist = 0.0f;
                if (actor->footStepCounter & 1) {
                    if (actor->actorTypeData1[0] != 0) {
                        sfx_play_sound_at_position(actor->actorTypeData1[0], SOUND_SPACE_MODE_0, actor->curPos.x, actor->curPos.y, actor->curPos.z);
                    }
                } else {
                    if (actor->actorTypeData1[1] != 0) {
                        sfx_play_sound_at_position(actor->actorTypeData1[1], SOUND_SPACE_MODE_0, actor->curPos.x, actor->curPos.y, actor->curPos.z);
                    }
                }
            }
        } else {
            actorState->dist += 1.0f;
            if (-actor->actorTypeData1b[0] <= actorState->dist) {
                actor->footStepCounter++;
                actorState->dist = 0.0f;
                if (actor->footStepCounter & 1) {
                    if (actor->actorTypeData1[0] != 0) {
                        sfx_play_sound_at_position(actor->actorTypeData1[0], SOUND_SPACE_MODE_0, actor->curPos.x, actor->curPos.y, actor->curPos.z);
                    }
                } else {
                    if (actor->actorTypeData1[1] != 0) {
                        sfx_play_sound_at_position(actor->actorTypeData1[1], SOUND_SPACE_MODE_0, actor->curPos.x, actor->curPos.y, actor->curPos.z);
                    }
                }
            }
        }
    }

    actorState->moveTime--;
    if (actorState->moveTime > 0) {
        return ApiStatus_BLOCK;
    }

    actor->curPos.x = actorState->unk_18.x;
    actor->curPos.z = actorState->unk_18.z;
    if (actor->actorTypeData1[0] != 0) {
        if (actor->actorTypeData1[1] == 0) {
            snd_stop_sound(actor->actorTypeData1[0]);
        }
    }
    return ApiStatus_DONE1;
}

ApiStatus IdleRunToGoal(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorMovement* movement;
    f32 posX, posY, posZ;
    f32 goalX, goalY, goalZ;
    s32 actorID;

    if (isInitialCall) {
        script->functionTemp[0] = FALSE;
    }

    if (!script->functionTemp[0]) {
        actorID = evt_get_variable(script, *args++);
        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }
        script->functionTempPtr[1] = actor = get_actor(actorID);
        movement = &actor->fly;

        movement->flyTime = evt_get_variable(script, *args++);

        movement->curPos.x = actor->curPos.x;
        movement->curPos.y = actor->curPos.y;
        movement->curPos.z = actor->curPos.z;

        goalX = movement->goalPos.x;
        goalY = movement->goalPos.y;
        goalZ = movement->goalPos.z;

        posX = movement->curPos.x;
        posY = movement->curPos.y;
        posZ = movement->curPos.z;

        movement->unk_18.x = goalX;
        movement->unk_18.y = goalY;
        movement->unk_18.z = goalZ;

        movement->angle = atan2(posX, posZ, goalX, goalZ);
        movement->dist = dist2D(posX, posZ, goalX, goalZ);

        if (movement->flyTime == 0) {
            movement->flyTime = movement->dist / movement->speed;
            if (movement->flyTime == 0) {
                movement->flyTime = 1;
            }
            // this simplifies to: flyMotion->speed = flyMotion->distance / flyMotion->flyTime
            movement->speed += (movement->dist - movement->flyTime * movement->speed) / movement->flyTime;
        } else {
            movement->speed = movement->dist / movement->flyTime;
        }

        if (actor->actorTypeData1b[0] >= 0) {
            movement->dist = actor->actorTypeData1b[0] + 1;
        } else {
            movement->dist = ~actor->actorTypeData1b[0];
        }
        script->functionTemp[0] = TRUE;
    }

    actor = script->functionTempPtr[1];
    movement = &actor->fly;

    add_xz_vec3f_copy2(&movement->curPos, movement->speed, movement->angle);
    if (movement->speed < 4.0f) {
        play_movement_dust_effects(0, movement->curPos.x, movement->curPos.y, movement->curPos.z, movement->angle);
    } else {
        play_movement_dust_effects(1, movement->curPos.x, movement->curPos.y, movement->curPos.z, movement->angle);
    }
    actor->curPos.x = movement->curPos.x;
    actor->curPos.z = movement->curPos.z;

    movement->flyTime--;
    if (movement->flyTime > 0) {
        return ApiStatus_BLOCK;
    }

    actor->curPos.x = movement->unk_18.x;
    actor->curPos.z = movement->unk_18.z;
    if (actor->actorTypeData1[0] != 0 && actor->actorTypeData1[1] == 0) {
        snd_stop_sound(actor->actorTypeData1[0]);
    }
    return ApiStatus_DONE1;
}

ApiStatus JumpPartTo(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorPart* part;
    ActorPartMovement* movement;
    s32 actorID, partID;
    f32 posX, posY, posZ;
    f32 goalX, goalY, goalZ;
    f32 deltaDist;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        actorID = evt_get_variable(script, *args++);
        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }
        partID = evt_get_variable(script, *args++);

        actor = get_actor(actorID);
        part = get_actor_part(actor, partID);
        script->functionTempPtr[1] = actor;
        script->functionTempPtr[2] = part;
        movement = part->movement;

        posX = evt_get_variable(script, *args++);
        posY = evt_get_variable(script, *args++);
        posZ = evt_get_variable(script, *args++);
        movement->goalPos.x = posX;
        movement->goalPos.y = posY;
        movement->goalPos.z = posZ;
        movement->moveTime = evt_get_variable(script, *args++);
        script->functionTemp[3] = evt_get_variable(script, *args++);

        goalX = movement->goalPos.x;
        goalY = movement->goalPos.y;
        goalZ = movement->goalPos.z;

        movement->absolutePos.x = part->absolutePos.x;
        movement->absolutePos.y = part->absolutePos.y;
        movement->absolutePos.z = part->absolutePos.z;

        posX = movement->absolutePos.x;
        posY = movement->absolutePos.y;
        posZ = movement->absolutePos.z;

        movement->angle = atan2(posX, posZ, goalX, goalZ);
        movement->dist = dist2D(posX, posZ, goalX, goalZ);

        // make relative
        posX = (goalX - posX);
        posY = (goalY - posY);
        posZ = (goalZ - posZ);

        if (movement->moveTime == 0) {
            movement->moveTime = movement->dist / movement->moveSpeed;
            deltaDist = movement->dist - movement->moveTime * movement->moveSpeed;
        } else {
            movement->moveSpeed = movement->dist / movement->moveTime;
            deltaDist = movement->dist - movement->moveTime * movement->moveSpeed;
        }
        movement->moveSpeed += deltaDist / movement->moveTime;
        movement->unk_2C = movement->jumpScale * movement->moveTime * 0.5f + posY / movement->moveTime;
        if (part->partTypeData[4] != 0) {
            sfx_play_sound_at_position(part->partTypeData[4], SOUND_SPACE_MODE_0, part->absolutePos.x, part->absolutePos.y, part->absolutePos.z);
        }
        script->functionTemp[0] = 1;
    }

    part = script->functionTempPtr[2];
    movement = part->movement;
    movement->absolutePos.y += movement->unk_2C;
    movement->unk_2C -= movement->jumpScale;
    add_xz_vec3f_copy1(&movement->absolutePos, movement->moveSpeed, movement->angle);
    part->absolutePos.x = movement->absolutePos.x;
    part->absolutePos.y = movement->absolutePos.y;
    part->absolutePos.z = movement->absolutePos.z;
    movement->moveTime--;

    if (movement->moveTime <= 0) {
        if (script->functionTemp[3] != 0) {
            play_movement_dust_effects(2, movement->goalPos.x, movement->goalPos.y, movement->goalPos.z, movement->angle);
        }
        part->absolutePos.x = movement->goalPos.x;
        part->absolutePos.y = movement->goalPos.y;
        part->absolutePos.z = movement->goalPos.z;
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus FallPartTo(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorPart* part;
    ActorPartMovement* movement;
    s32 actorID, partID;
    f32 posX, posY, posZ;
    f32 goalX, goalY, goalZ;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        actorID = evt_get_variable(script, *args++);
        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }
        partID = evt_get_variable(script, *args++);

        actor = get_actor(actorID);
        part = get_actor_part(actor, partID);
        script->functionTempPtr[1] = actor;
        script->functionTempPtr[2] = part;
        movement = part->movement;

        posX = evt_get_variable(script, *args++);
        posY = evt_get_variable(script, *args++);
        posZ = evt_get_variable(script, *args++);
        movement->goalPos.x = posX;
        movement->goalPos.y = posY;
        movement->goalPos.z = posZ;
        movement->moveTime = evt_get_variable(script, *args++);

        goalX = movement->goalPos.x;
        goalY = movement->goalPos.y;
        goalZ = movement->goalPos.z;

        movement->absolutePos.x = part->absolutePos.x;
        movement->absolutePos.y = part->absolutePos.y;
        movement->absolutePos.z = part->absolutePos.z;

        posX = movement->absolutePos.x;
        posY = movement->absolutePos.y;
        posZ = movement->absolutePos.z;

        movement->angle = atan2(posX, posZ, goalX, goalZ);
        movement->dist = dist2D(posX, posZ, goalX, goalZ);

        // make relative
        posX = (goalX - posX);
        posY = (goalY - posY);
        posZ = (goalZ - posZ);

        if (movement->moveTime == 0) {
            movement->moveTime = movement->dist / movement->moveSpeed;
        } else {
            movement->moveSpeed = movement->dist / movement->moveTime;
        }

        movement->unk_2C = 0.0f;
        movement->jumpScale = (posY / movement->moveTime - movement->unk_2C) / (-movement->moveTime * 0.5);
        if (part->partTypeData[4] != 0) {
            sfx_play_sound_at_position(part->partTypeData[4], SOUND_SPACE_MODE_0, part->absolutePos.x, part->absolutePos.y, part->absolutePos.z);
        }
        script->functionTemp[0] = 1;
    }

    part = script->functionTempPtr[2];
    movement = part->movement;
    movement->absolutePos.y += movement->unk_2C;
    movement->unk_2C -= movement->jumpScale;
    add_xz_vec3f_copy1(&movement->absolutePos, movement->moveSpeed, movement->angle);
    part->absolutePos.x = movement->absolutePos.x;
    part->absolutePos.y = movement->absolutePos.y;
    part->absolutePos.z = movement->absolutePos.z;
    movement->moveTime--;

    if (movement->moveTime <= 0) {
        play_movement_dust_effects(2, movement->goalPos.x, movement->goalPos.y, movement->goalPos.z, movement->angle);
        part->absolutePos.x = movement->goalPos.x;
        part->absolutePos.y = movement->goalPos.y;
        part->absolutePos.z = movement->goalPos.z;
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

ApiStatus LandJumpPart(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorPart* part;
    ActorPartMovement* movement;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        s32 actorID = evt_get_variable(script, *args++);
        s32 partID = evt_get_variable(script, *args++);

        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }

        actor = get_actor(actorID);
        part = get_actor_part(actor, partID);
        script->functionTempPtr[1] = actor;
        script->functionTempPtr[2] = part;
        movement = part->movement;
        movement->absolutePos.x = part->absolutePos.x;
        movement->absolutePos.y = part->absolutePos.y;
        movement->absolutePos.z = part->absolutePos.z;
        script->functionTemp[0] = 1;
    }

    part = script->functionTempPtr[2];
    movement = part->movement;
    movement->absolutePos.y += movement->unk_2C;
    movement->unk_2C -= movement->jumpScale;
    add_xz_vec3f_copy1(&movement->absolutePos, movement->moveSpeed, movement->angle);
    part->absolutePos.x = movement->absolutePos.x;
    part->absolutePos.y = movement->absolutePos.y;
    part->absolutePos.z = movement->absolutePos.z;

    if (part->absolutePos.y < 0.0f) {
        part->absolutePos.y = 0.0f;
        play_movement_dust_effects(2, part->absolutePos.x, part->absolutePos.y, part->absolutePos.z, part->yaw);
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus RunPartTo(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorPart* part;
    ActorPartMovement* movement;
    s32 actorID, partID;
    f32 posX, posY, posZ;
    f32 goalX, goalY, goalZ;
    f32 deltaDist;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        actorID = evt_get_variable(script, *args++);
        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }
        partID = evt_get_variable(script, *args++);

        actor = get_actor(actorID);
        part = get_actor_part(actor, partID);
        script->functionTempPtr[1] = actor;
        script->functionTempPtr[2] = part;
        movement = part->movement;

        posX = evt_get_variable(script, *args++);
        posY = evt_get_variable(script, *args++);
        posZ = evt_get_variable(script, *args++);
        movement->goalPos.x = posX;
        movement->goalPos.y = posY;
        movement->goalPos.z = posZ;
        movement->moveTime = evt_get_variable(script, *args++);

        goalX = movement->goalPos.x;
        goalY = movement->goalPos.y;
        goalZ = movement->goalPos.z;

        movement->absolutePos.x = part->absolutePos.x;
        movement->absolutePos.y = part->absolutePos.y;
        movement->absolutePos.z = part->absolutePos.z;

        posX = movement->absolutePos.x;
        posY = movement->absolutePos.y;
        posZ = movement->absolutePos.z;

        movement->angle = atan2(posX, posZ, goalX, goalZ);
        movement->dist = dist2D(posX, posZ, goalX, goalZ);

        if (movement->moveTime == 0) {
            movement->moveTime = movement->dist / movement->moveSpeed;
        } else {
            movement->moveSpeed = movement->dist / movement->moveTime;
        }
        if (part->actorTypeData2b[0] >= 0) {
            movement->dist = part->actorTypeData2b[0] + 1;
        } else {
            movement->dist = ~part->actorTypeData2b[0];
        }
        if (part->partTypeData[0] != 0 && part->partTypeData[1] == 0) {
            sfx_play_sound_at_position(part->partTypeData[0], SOUND_SPACE_MODE_0, part->absolutePos.x, part->absolutePos.y, part->absolutePos.z);
        }
        script->functionTemp[0] = 1;
    }

    part = script->functionTempPtr[2];
    movement = part->movement;
    actor = script->functionTempPtr[1];

    add_xz_vec3f_copy1(&movement->absolutePos, movement->moveSpeed, movement->angle);
    if (movement->moveSpeed < 4.0f) {
        play_movement_dust_effects(0, movement->absolutePos.x, movement->absolutePos.y, movement->absolutePos.z, movement->angle);
    } else {
        play_movement_dust_effects(1, movement->absolutePos.x, movement->absolutePos.y, movement->absolutePos.z, movement->angle);
    }
    part->absolutePos.x = movement->absolutePos.x;
    part->absolutePos.y = movement->absolutePos.y;
    part->absolutePos.z = movement->absolutePos.z;

    if (part->partTypeData[0] != 0 && part->partTypeData[1] != 0) {
        if (part->actorTypeData2b[0] >= 0) {
            movement->dist += movement->moveSpeed;
            if (part->actorTypeData2b[0] < movement->dist) {
                actor->footStepCounter++;
                movement->dist = 0;
                if (actor->footStepCounter % 2 != 0) {
                    if (part->partTypeData[0] != 0) {
                        sfx_play_sound_at_position(part->partTypeData[0], SOUND_SPACE_MODE_0, part->absolutePos.x, part->absolutePos.y, part->absolutePos.z);
                    }
                } else {
                    if (part->partTypeData[1] != 0) {
                        sfx_play_sound_at_position(part->partTypeData[1], SOUND_SPACE_MODE_0, part->absolutePos.x, part->absolutePos.y, part->absolutePos.z);
                    }
                }
            }
        } else {
            movement->dist += 1.0f;
            if (-part->actorTypeData2b[0] <= movement->dist) {
                actor->footStepCounter++;
                movement->dist = 0;
                if (actor->footStepCounter % 2 != 0) {
                    if (part->partTypeData[0] != 0) {
                        sfx_play_sound_at_position(part->partTypeData[0], SOUND_SPACE_MODE_0, part->absolutePos.x, part->absolutePos.y, part->absolutePos.z);
                    }
                } else {
                    if (part->partTypeData[1] != 0) {
                        sfx_play_sound_at_position(part->partTypeData[1], SOUND_SPACE_MODE_0, part->absolutePos.x, part->absolutePos.y, part->absolutePos.z);
                    }
                }
            }
        }
    }

    movement->moveTime--;
    if (movement->moveTime > 0) {
        return ApiStatus_BLOCK;
    } else {
        part->absolutePos.x = movement->goalPos.x;
        part->absolutePos.z = movement->goalPos.z;
        if (part->partTypeData[0] != 0 && part->partTypeData[1] == 0) {
            snd_stop_sound(part->partTypeData[0]);
        }
        return ApiStatus_DONE1;
    }
}

f32 update_lerp_battle(s32 easing, f32 start, f32 end, s32 elapsed, s32 duration) {
    s32 timeLeft;
    f32 absMag;
    f64 start1;
    f64 start2;
    f32 len1;
    f32 len2;
    f32 len3;
    f32 len4;
    f64 len5;
    f32 len6;
    f64 len7;

    switch (easing) {
        case EASING_LINEAR:
            return start + (end - start) * elapsed / duration;
        case EASING_QUADRATIC_IN:
            return start + SQ(elapsed) * (end - start) / SQ(duration);
        case EASING_CUBIC_IN:
            return start + CUBE(elapsed) * (end - start) / CUBE(duration);
        case EASING_QUARTIC_IN:
            return start + QUART(elapsed) * (end - start) / QUART(duration);
        case EASING_COS_SLOW_OVERSHOOT:
            len1 = end - start;
            return end - (len1 * cos_rad(((f32)elapsed / duration) * PI_D * 4.0) * (duration - elapsed) *
                    (duration - elapsed)) / SQ((f32)duration);
        case EASING_COS_FAST_OVERSHOOT:
            len2 = end - start;
            return end - (len2 * cos_rad((((f32)SQ(elapsed) / duration) * PI_D * 4.0) / 15.0) * (duration - elapsed) *
                    (duration - elapsed)) / SQ((f32)duration);
        case EASING_QUADRATIC_OUT:
            timeLeft = duration - elapsed;
            return start + (end - start) - ((SQ(timeLeft) * (end - start))) / SQ(duration);
        case EASING_CUBIC_OUT:
            len3 = end - start;
            timeLeft = duration - elapsed;
            return start + len3 - ((CUBE(timeLeft) * len3)) / CUBE(duration);
        case EASING_QUARTIC_OUT:
            len4 = end - start;
            timeLeft = duration - elapsed;
            return start + len4 - ((QUART(timeLeft) * len4)) / QUART(duration);
        case EASING_COS_BOUNCE:
            absMag = cos_rad((((f32)SQ(elapsed) / duration) * PI_D * 4.0) / 40.0) * (duration - elapsed) *
                    (duration - elapsed) / SQ((f32)duration);
            if (absMag < 0.0f) {
                absMag = -absMag;
            }
            return end - (end - start) * absMag;
        case EASING_COS_IN_OUT:
            len5 = end - start;
            start1 = start;
            return start1 + (len5 * (1.0 - cos_rad(((f32)elapsed * PI_D) / (f32)duration)) / 2);
        case EASING_SIN_OUT:
            len6 = end - start;
            return start + (len6 * sin_rad((((f32) elapsed) * (PI_D / 2)) / ((f32) duration)));
        case EASING_COS_IN:
            len7 = end - start;
            start2 = start;
            return start2 + (len7 * (1.0 - cos_rad(((f32)elapsed * (PI_D / 2)) / (f32)duration)));
    }

    return 0.0f;
}

ApiStatus FlyToGoal(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorState* actorState;
    s32 actorID;
    f32 posX, posY, posZ;
    f32 goalX, goalY, goalZ;
    f32 deltaX, deltaY, deltaZ;
    f32 dist3D;
    f32 offsetY;

    if (isInitialCall) {
        actorID = evt_get_variable(script, *args++);
        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.enemyID;
        }
        script->functionTempPtr[1] = actor = get_actor(actorID);
        actorState = &actor->state;

        actorState->moveTime = evt_get_variable(script, *args++);
        actorState->moveArcAmplitude = evt_get_variable(script, *args++);
        script->functionTemp[3] = evt_get_variable(script, *args++);
        actorState->functionTemp[0] = FALSE;

        if (script->functionTemp[3] >= 100) {
            script->functionTemp[3] -= 100;
            actorState->functionTemp[0] = TRUE;
        }

        goalX = actorState->goalPos.x;
        goalY = actorState->goalPos.y;
        goalZ = actorState->goalPos.z;

        posX = actor->curPos.x;
        posY = actor->curPos.y;
        posZ = actor->curPos.z;

        deltaX = posX - goalX;
        deltaY = posY - goalY;
        deltaZ = posZ - goalZ;

        actorState->curPos.x = posX;
        actorState->unk_18.x = posX;
        actorState->curPos.y = posY;
        actorState->unk_18.y = posY;
        actorState->curPos.z = posZ;
        actorState->unk_18.z = posZ;

        actorState->dist = sqrtf(SQ(deltaX) + SQ(deltaY) + SQ(deltaZ));

        if (actorState->moveTime == 0) {
            actorState->moveTime = actorState->dist / actorState->speed;
        } else {
            actorState->speed = actorState->dist / actorState->moveTime;
        }
        if (actorState->moveTime == 0) {
            return ApiStatus_DONE2;
        }

        actorState->bounceDivisor = 0.0f;
        actorState->angle = 0.0f;
        if (actor->actorTypeData1b[1] >= 0) {
            actorState->vel = actor->actorTypeData1b[1] + 1;
        } else {
            actorState->vel = ~actor->actorTypeData1b[1];
        }
        if ((actor->actorTypeData1[2] != 0) && (actor->actorTypeData1[3] == 0)) {
            sfx_play_sound_at_position(actor->actorTypeData1[2], SOUND_SPACE_MODE_0, actor->curPos.x, actor->curPos.y, actor->curPos.z);
        }
    }

    actor = script->functionTempPtr[1];
    actorState = &actor->state;

    actorState->curPos.x = update_lerp_battle(script->functionTemp[3], actorState->unk_18.x, actorState->goalPos.x, actorState->bounceDivisor, actorState->moveTime);
    actorState->curPos.y = update_lerp_battle(script->functionTemp[3], actorState->unk_18.y, actorState->goalPos.y, actorState->bounceDivisor, actorState->moveTime);
    actorState->curPos.z = update_lerp_battle(script->functionTemp[3], actorState->unk_18.z, actorState->goalPos.z, actorState->bounceDivisor, actorState->moveTime);
    if ((actorState->functionTemp[0]) && (actorState->curPos.y < 0.0f)) {
        actorState->bounceDivisor = actorState->moveTime;
        actorState->goalPos.x = actorState->curPos.x;
        actorState->goalPos.y = 0.0f;
        actorState->goalPos.z = actorState->curPos.z;
    }
    actorState->bounceDivisor += 1.0f;
    if (actorState->moveTime < actorState->bounceDivisor) {
        actor->curPos.x = actorState->goalPos.x;
        actor->curPos.y = actorState->goalPos.y;
        actor->curPos.z = actorState->goalPos.z;
        if (actor->actorTypeData1[2] != 0) {
            if (actor->actorTypeData1[3] == 0) {
                snd_stop_sound(actor->actorTypeData1[2]);
            }
        }
        return ApiStatus_DONE2;
    }
    if ((actor->actorTypeData1[2] != 0) && (actor->actorTypeData1[3] != 0)) {
        if (actor->actorTypeData1b[1] >= 0) {
            actorState->vel += actorState->speed;
            if (actor->actorTypeData1b[1] < actorState->vel) {
                actor->footStepCounter++;
                actorState->vel = 0.0f;
                if (actor->footStepCounter & 1) {
                    if (actor->actorTypeData1[2] != 0) {
                        sfx_play_sound_at_position(actor->actorTypeData1[2], SOUND_SPACE_MODE_0, actor->curPos.x, actor->curPos.y, actor->curPos.z);
                    }
                } else {
                    if (actor->actorTypeData1[3] != 0) {
                        sfx_play_sound_at_position(actor->actorTypeData1[3], SOUND_SPACE_MODE_0, actor->curPos.x, actor->curPos.y, actor->curPos.z);
                    }
                }
            }
        } else {
            actorState->vel += 1.0f;
            if (-actor->actorTypeData1b[1] <= actorState->vel) {
                actor->footStepCounter++;
                actorState->vel = 0.0f;
                if (actor->footStepCounter & 1) {
                    if (actor->actorTypeData1[2] != 0) {
                        sfx_play_sound_at_position(actor->actorTypeData1[2], SOUND_SPACE_MODE_0, actor->curPos.x, actor->curPos.y, actor->curPos.z);
                    }
                } else {
                    if (actor->actorTypeData1[3] != 0) {
                        sfx_play_sound_at_position(actor->actorTypeData1[3], SOUND_SPACE_MODE_0, actor->curPos.x, actor->curPos.y, actor->curPos.z);
                    }
                }
            }
        }
    }

    deltaX = actorState->goalPos.x - actorState->curPos.x;
    deltaY = actorState->goalPos.y - actorState->curPos.y;
    deltaZ = actorState->goalPos.z - actorState->curPos.z;
    dist3D = sqrtf(SQ(deltaX) + SQ(deltaY) + SQ(deltaZ));
    if (dist3D == 0.0f) {
        dist3D = 1.0f;
    }
    if (actorState->dist == 0.0f) {
        actorState->dist = 1.0f;
    }
    offsetY = sin_deg((1.0 - (dist3D / actorState->dist)) * 180.0);
    if (actorState->moveArcAmplitude == 0) {
        offsetY = 0.0f;
    }
    if (actorState->moveArcAmplitude < 0) {
        offsetY = -offsetY * -actorState->moveArcAmplitude;
    }
    if (actorState->moveArcAmplitude > 0) {
        offsetY = offsetY * actorState->moveArcAmplitude;
    }
    actor->curPos.x = actorState->curPos.x;
    actor->curPos.y = actorState->curPos.y + offsetY;
    actor->curPos.z = actorState->curPos.z;
    return ApiStatus_BLOCK;
}

ApiStatus IdleFlyToGoal(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorMovement* movement;
    s32 actorID;
    f32 posX, posY, posZ;
    f32 goalX, goalY, goalZ;
    f32 deltaX, deltaY, deltaZ;
    f32 dist3D;
    f32 offsetY;

    if (isInitialCall) {
        actorID = evt_get_variable(script, *args++);
        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.enemyID;
        }
        script->functionTempPtr[1] = actor = get_actor(actorID);
        movement = &actor->fly;

        movement->flyTime = evt_get_variable(script, *args++);
        movement->flyArcAmplitude = evt_get_variable(script, *args++);
        script->functionTemp[3] = evt_get_variable(script, *args++);

        goalX = movement->goalPos.x;
        goalY = movement->goalPos.y;
        goalZ = movement->goalPos.z;

        posX = actor->curPos.x;
        posY = actor->curPos.y;
        posZ = actor->curPos.z;

        deltaX = posX - goalX;
        deltaY = posY - goalY;
        deltaZ = posZ - goalZ;

        movement->curPos.x = posX;
        movement->unk_18.x = posX;
        movement->curPos.y = posY;
        movement->unk_18.y = posY;
        movement->curPos.z = posZ;
        movement->unk_18.z = posZ;

        movement->dist = sqrtf(SQ(deltaX) + SQ(deltaY) + SQ(deltaZ));

        if (movement->flyTime == 0) {
            movement->flyTime = movement->dist / movement->speed;
        } else {
            movement->speed = movement->dist / movement->flyTime;
        }
        if (movement->flyTime == 0) {
            return ApiStatus_DONE2;
        }

        movement->flyElapsed = 0.0f;
        movement->angle = 0.0f;
        movement->vel = 0.0f;
    }

    actor = script->functionTempPtr[1];
    movement = &actor->fly;

    movement->curPos.x = update_lerp_battle(script->functionTemp[3], movement->unk_18.x, movement->goalPos.x, movement->flyElapsed, movement->flyTime);
    movement->curPos.y = update_lerp_battle(script->functionTemp[3], movement->unk_18.y, movement->goalPos.y, movement->flyElapsed, movement->flyTime);
    movement->curPos.z = update_lerp_battle(script->functionTemp[3], movement->unk_18.z, movement->goalPos.z, movement->flyElapsed, movement->flyTime);

    movement->flyElapsed += 1.0f;
    if (movement->flyTime < movement->flyElapsed) {
        actor->curPos.x = movement->goalPos.x;
        actor->curPos.y = movement->goalPos.y;
        actor->curPos.z = movement->goalPos.z;
        return ApiStatus_DONE2;
    }

    deltaX = movement->goalPos.x - movement->curPos.x;
    deltaY = movement->goalPos.y - movement->curPos.y;
    deltaZ = movement->goalPos.z - movement->curPos.z;
    dist3D = sqrtf(SQ(deltaX) + SQ(deltaY) + SQ(deltaZ));
    if (dist3D == 0.0f) {
        dist3D = 1.0f;
    }
    if (movement->dist == 0.0f) {
        movement->dist = 1.0f;
    }

    offsetY = sin_deg((1.0 - (dist3D / movement->dist)) * 180.0);
    if (movement->flyArcAmplitude == 0) {
        offsetY = 0.0f;
    }
    if (movement->flyArcAmplitude < 0) {
        offsetY = -offsetY * -movement->flyArcAmplitude;
    }
    if (movement->flyArcAmplitude > 0) {
        offsetY = offsetY * movement->flyArcAmplitude;
    }

    actor->curPos.x = movement->curPos.x;
    actor->curPos.y = movement->curPos.y + offsetY;
    actor->curPos.z = movement->curPos.z;
    return ApiStatus_BLOCK;
}

ApiStatus FlyPartTo(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorPart* part;
    ActorPartMovement* partMovement;
    s32 actorID;
    s32 partID;

    f32 posX, posY, posZ;
    f32 goalX, goalY, goalZ;
    f32 deltaX, deltaY, deltaZ;
    f32 dist3D;
    f32 offsetY;

    if (isInitialCall) {
        actorID = evt_get_variable(script, *args++);
        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }
        partID = evt_get_variable(script, *args++);

        actor = get_actor(actorID);
        part = get_actor_part(actor, partID);
        script->functionTempPtr[1] = actor;
        script->functionTempPtr[2] = part;
        partMovement = part->movement;

        partMovement->goalPos.x = evt_get_variable(script, *args++);
        partMovement->goalPos.y = evt_get_variable(script, *args++);
        partMovement->goalPos.z = evt_get_variable(script, *args++);
        partMovement->moveTime = evt_get_variable(script, *args++);
        partMovement->unk_3A = evt_get_variable(script, *args++);
        script->functionTemp[3] = evt_get_variable(script, *args++);

        goalX = partMovement->goalPos.x;
        posX = part->absolutePos.x;
        deltaX = posX - goalX;
        partMovement->absolutePos.x = posX;
        partMovement->unk_18.x = posX;

        goalY = partMovement->goalPos.y;
        posY = part->absolutePos.y;
        deltaY = posY - goalY;
        partMovement->absolutePos.y = posY;
        partMovement->unk_18.y = posY;

        goalZ = partMovement->goalPos.z;
        posZ = part->absolutePos.z;
        deltaZ = posZ - goalZ;
        partMovement->absolutePos.z = posZ;
        partMovement->unk_18.z = posZ;

        partMovement->dist = sqrtf(SQ(deltaX) + SQ(deltaY) + SQ(deltaZ));

        if (partMovement->moveTime == 0) {
            partMovement->moveTime = partMovement->dist / partMovement->moveSpeed;
        } else {
            partMovement->moveSpeed = partMovement->dist / partMovement->moveTime;
        }

        if (partMovement->moveTime == 0) {
            return ApiStatus_DONE2;
        }

        if (part->partTypeData[2] != 0 && part->partTypeData[3] == 0) {
            sfx_play_sound_at_position(part->partTypeData[2], SOUND_SPACE_MODE_0, part->absolutePos.x, part->absolutePos.y, part->absolutePos.z);
        }
        partMovement->unk_3C = 0;
        partMovement->angle = 0.0f;

        if (part->actorTypeData2b[1] >= 0) {
            partMovement->unk_2C = actor->actorTypeData1b[1] + 1;
        } else {
            partMovement->unk_2C = ~actor->actorTypeData1b[1];
        }
    }

    part = script->functionTempPtr[2];
    actor = script->functionTempPtr[1];
    partMovement = part->movement;
    partMovement->absolutePos.x = update_lerp_battle(script->functionTemp[3], partMovement->unk_18.x, partMovement->goalPos.x, partMovement->unk_3C, partMovement->moveTime);
    partMovement->absolutePos.y = update_lerp_battle(script->functionTemp[3], partMovement->unk_18.y, partMovement->goalPos.y, partMovement->unk_3C, partMovement->moveTime);
    partMovement->absolutePos.z = update_lerp_battle(script->functionTemp[3], partMovement->unk_18.z, partMovement->goalPos.z, partMovement->unk_3C, partMovement->moveTime);
    partMovement->unk_3C++;

    if (partMovement->moveTime < partMovement->unk_3C) {
        part->absolutePos.x = partMovement->goalPos.x;
        part->absolutePos.y = partMovement->goalPos.y;
        part->absolutePos.z = partMovement->goalPos.z;
        if (part->partTypeData[2] != 0 && part->partTypeData[3] == 0) {
            snd_stop_sound(part->partTypeData[2]);
        }
        return ApiStatus_DONE2;
    }

    if (part->partTypeData[2] != 0 && part->partTypeData[3] != 0) {
        if (part->actorTypeData2b[1] >= 0) {
            partMovement->unk_2C += partMovement->moveSpeed;
            if (part->actorTypeData2b[1] < partMovement->unk_2C) {
                actor->footStepCounter++;
                partMovement->unk_2C = 0;
                if (actor->footStepCounter % 2 != 0) {
                    if (part->partTypeData[2] != 0) {
                        sfx_play_sound_at_position(part->partTypeData[2], SOUND_SPACE_MODE_0, part->absolutePos.x, part->absolutePos.y, part->absolutePos.z);
                    }
                } else {
                    if (part->partTypeData[3] != 0) {
                        sfx_play_sound_at_position(part->partTypeData[3], SOUND_SPACE_MODE_0, part->absolutePos.x, part->absolutePos.y, part->absolutePos.z);
                    }
                }
            }
        } else {
            partMovement->unk_2C += 1.0f;
            if (-part->actorTypeData2b[1] <= partMovement->unk_2C) {
                actor->footStepCounter++;
                partMovement->unk_2C = 0;
                if (actor->footStepCounter % 2 != 0) {
                    if (part->partTypeData[2] != 0) {
                        sfx_play_sound_at_position(part->partTypeData[2], SOUND_SPACE_MODE_0, part->absolutePos.x, part->absolutePos.y, part->absolutePos.z);
                    }
                } else {
                    if (part->partTypeData[3] != 0) {
                        sfx_play_sound_at_position(part->partTypeData[3], SOUND_SPACE_MODE_0, part->absolutePos.x, part->absolutePos.y, part->absolutePos.z);
                    }
                }
            }
        }
    }

    deltaX = partMovement->goalPos.x - partMovement->absolutePos.x;
    deltaY = partMovement->goalPos.y - partMovement->absolutePos.y;
    deltaZ = partMovement->goalPos.z - partMovement->absolutePos.z;
    dist3D = sqrtf(SQ(deltaX) + SQ(deltaY) + SQ(deltaZ));
    if (dist3D == 0.0f) {
        dist3D = 1.0f;
    }
    if (partMovement->dist == 0.0f) {
        partMovement->dist = 1.0f;
    }

    offsetY = sin_deg((1.0 - dist3D / partMovement->dist) * 180.0);
    if (partMovement->unk_3A == 0) {
        offsetY = 0.0f;
    }
    if (partMovement->unk_3A < 0) {
        offsetY = -offsetY * (-partMovement->unk_3A);
    }
    if (partMovement->unk_3A > 0) {
        offsetY = offsetY * partMovement->unk_3A;
    }

    part->absolutePos.x = partMovement->absolutePos.x;
    part->absolutePos.y = partMovement->absolutePos.y + offsetY;
    part->absolutePos.z = partMovement->absolutePos.z;
    return ApiStatus_BLOCK;
}

ApiStatus GetLastEvent(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 outVar;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    outVar = *args++;
    evt_set_variable(script, outVar, get_actor(actorID)->lastEventType);
    return ApiStatus_DONE2;
}

ApiStatus SetTargetActor(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 targetActorID;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    targetActorID = evt_get_variable(script, *args++);
    actor = get_actor(actorID);
    actor->targetActorID = targetActorID;
    actor->targetPartIndex = 1;
    return ApiStatus_DONE2;
}

ApiStatus SetEnemyHP(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s8 newHP;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    newHP = evt_get_variable(script, *args++);
    actor = get_actor(actorID);

    actor->curHP = newHP;
    if (newHP > actor->maxHP) {
        actor->curHP = actor->maxHP;
    }

    actor->healthFraction = (actor->curHP * 25) / actor->maxHP;

    return ApiStatus_DONE2;
}

ApiStatus GetActorHP(Evt* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 outVar;
    s32 outVal;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    outVar = *args++;

    actor = get_actor(actorID);

    switch (actorID & ACTOR_CLASS_MASK) {
        case ACTOR_CLASS_PLAYER:
            outVal = playerData->curHP;
            break;
        case ACTOR_CLASS_PARTNER:
            outVal = 99;
            break;
        default:
            outVal = actor->curHP;
            break;
    }

    evt_set_variable(script, outVar, outVal);
    return ApiStatus_DONE2;
}

ApiStatus GetEnemyMaxHP(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 outVar;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    outVar = *args++;
    evt_set_variable(script, outVar, get_actor(actorID)->maxHP);
    return ApiStatus_DONE2;
}

ApiStatus RemoveActor(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 i;
    s32 numEnemies;
    s16* enemyIDs;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    numEnemies = battleStatus->numEnemyActors;
    enemyIDs = battleStatus->enemyIDs;

    for (i = 0; i < numEnemies; i++) {
        if (actor == battleStatus->enemyActors[enemyIDs[i] & 0xFF]) {
            enemyIDs[i] = -1;
        }
    }

    currentEncounter->coinsEarned += actor->extraCoinBonus;
    currentEncounter->coinsEarned += actor->actorBlueprint->coinReward;
    btl_delete_actor(actor);
    battleStatus->enemyActors[actorID & 0xFF] = NULL;

    return ApiStatus_DONE2;
}

ApiStatus DropStarPoints(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Bytecode* args = script->ptrReadPos;
    Actor* dropper;
    f32 playerLevel;
    f32 enemyLevel;
    s32 actorID;
    f32 ntd;
    s32 numToDrop;

    actorID = evt_get_variable(script, *args++);
    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.enemyID;
    }
    dropper = get_actor(actorID);

    enemyLevel = dropper->actorBlueprint->level;
    if (dropper->actorBlueprint->level == 0.0f) {
        enemyLevel = 1.0f;
    }

    playerLevel = playerData->level;
    if (playerLevel == 0.0f) {
        playerLevel = 1.0f;
    }

    ntd = 0.0f;
    if (!(enemyLevel < playerLevel)) {
        ntd = ((enemyLevel - playerLevel) * 0.5f) * D_802946E0[battleStatus->initialEnemyCount];
        ntd = (ntd + 50.0f) / 100.0f;
    }
    numToDrop = ntd;

    if (playerData->level < 27) {
        s32 spawnMode;
        s32 i;

        if (dropper->flags & ACTOR_FLAG_UPSIDE_DOWN) {
            spawnMode = ITEM_SPAWN_MODE_TOSS_FADE3;
        } else {
            spawnMode = ITEM_SPAWN_MODE_TOSS_FADE1;
        }

        for (i = 0; i < numToDrop; i++) {
            make_item_entity_delayed(ITEM_STAR_POINT,
                dropper->curPos.x, dropper->curPos.y, dropper->curPos.z, spawnMode, i, 0);
        }

        battleStatus->incrementStarPointDelay = 40;
        battleStatus->pendingStarPoints += numToDrop;
    }

    gBattleStatus.flags1 |= BS_FLAGS1_STAR_POINTS_DROPPED;
    return ApiStatus_DONE2;
}

ApiStatus SetDefenseTable(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID;
    u32* table;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    table = (u32*) evt_get_variable(script, *args++);
    get_actor_part(get_actor(actorID), partID)->defenseTable = table;
    return ApiStatus_DONE2;
}

ApiStatus SetStatusTable(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    u32* table;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    table = (u32*) evt_get_variable(script, *args++);
    get_actor(actorID)->statusTable = table;
    return ApiStatus_DONE2;
}

ApiStatus SetIdleAnimations(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID;
    AnimID* idleAnims;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    idleAnims = (u32*) evt_get_variable(script, *args++);
    get_actor_part(get_actor(actorID), partID)->idleAnimations = idleAnims;
    return ApiStatus_DONE2;
}

ApiStatus func_8027CC10(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);

    // weirdly unused
    evt_get_variable(script, *args++);
    evt_get_variable(script, *args++);

    get_actor_part(get_actor(actorID), partID);
    return ApiStatus_DONE2;
}

ApiStatus EnemyDamageTarget(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 outVar;
    s32 hitResult;
    s32 battleStatusFlags1Temp;
    s32 battleFlagsModifier;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.enemyID;
    }

    actor = get_actor(actorID);
    outVar = *args++;
    battleStatus->curAttackElement = *args++;
    battleStatus->curAttackEventSuppression = *args++;
    battleStatus->curAttackStatus = *args++;
    battleStatus->curAttackDamage = evt_get_variable(script, *args++);
    battleFlagsModifier = *args++;

    if (battleFlagsModifier & BS_FLAGS1_10) {
        gBattleStatus.flags1 |= BS_FLAGS1_10;
        gBattleStatus.flags1 &= ~BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (battleFlagsModifier & BS_FLAGS1_SP_EVT_ACTIVE) {
        gBattleStatus.flags1 &= ~BS_FLAGS1_10;
        gBattleStatus.flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_10;
        gBattleStatus.flags1 &= ~BS_FLAGS1_SP_EVT_ACTIVE;
    }

    if (battleFlagsModifier & BS_FLAGS1_40) {
        gBattleStatus.flags1 |= BS_FLAGS1_40;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_40;
    }
    if (battleFlagsModifier & BS_FLAGS1_200) {
        gBattleStatus.flags1 |= BS_FLAGS1_200;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_200;
    }
    if (battleFlagsModifier & BS_FLAGS1_80) {
        gBattleStatus.flags1 |= BS_FLAGS1_80;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_80;
    }

    battleStatus->curTargetID = actor->targetActorID;
    battleStatus->curTargetPart = actor->targetPartIndex;

    battleStatus->statusChance = battleStatus->curAttackStatus & 0xFF;
    if (battleStatus->statusChance == STATUS_KEY_NEVER) {
        battleStatus->statusChance = 0;
    }
    battleStatus->statusDuration = (battleStatus->curAttackStatus & 0xF00) >> 8;

    hitResult = calc_enemy_damage_target(actor);
    if (hitResult < 0) {
        return ApiStatus_FINISH;
    }

    evt_set_variable(script, outVar, hitResult);
    if (!(does_script_exist_by_ref(script))) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus EnemyFollowupAfflictTarget(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    BattleStatus* anotherBattleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    s32 actorID = evt_get_variable(script, *args++);
    s32 hitResults;
    s32 outVar;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    outVar = *args++;

    battleStatus->curTargetID = actor->targetActorID;
    battleStatus->curTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = battleStatus->curAttackStatus;

    if (battleStatus->statusChance == STATUS_KEY_NEVER) {
        battleStatus->statusChance = 0;
    }

    anotherBattleStatus->statusDuration = (anotherBattleStatus->curAttackStatus & 0xF00) >> 8;
    hitResults = calc_enemy_damage_target(actor);

    if (hitResults < 0) {
        return ApiStatus_FINISH;
    }

    evt_set_variable(script, outVar, hitResults);
    if (does_script_exist_by_ref(script) == NULL) {
        return ApiStatus_FINISH;
    }
    return ApiStatus_DONE2;
}

ApiStatus EnemyTestTarget(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 actorID = evt_get_variable(script, *args++);
    Actor *actor;
    s32 outVar;
    s32 hitResult;
    u8 attackStatus;
    s32 battleStatusFlags1Temp;
    s32 battleFlagsModifier;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.enemyID;
    }

    actor = get_actor(actorID);
    outVar = *args++;
    battleStatus->curAttackElement = *args++;
    battleStatus->curAttackEventSuppression = 0;
    battleStatus->curAttackStatus = *args++;
    battleStatus->curAttackDamage = evt_get_variable(script, *args++);
    battleFlagsModifier = *args++;

    if (battleFlagsModifier & BS_FLAGS1_10) {
        gBattleStatus.flags1 |= BS_FLAGS1_10;
        gBattleStatus.flags1 &= ~BS_FLAGS1_SP_EVT_ACTIVE;
    } else if (battleFlagsModifier & BS_FLAGS1_SP_EVT_ACTIVE) {
        gBattleStatus.flags1 &= ~BS_FLAGS1_10;
        gBattleStatus.flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_10;
        gBattleStatus.flags1 &= ~BS_FLAGS1_SP_EVT_ACTIVE;
    }

    if (battleFlagsModifier & BS_FLAGS1_40) {
        gBattleStatus.flags1 |= BS_FLAGS1_40;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_40;
    }
    if (battleFlagsModifier & BS_FLAGS1_200) {
        gBattleStatus.flags1 |= BS_FLAGS1_200;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_200;
    }
    if (battleFlagsModifier & BS_FLAGS1_80) {
        gBattleStatus.flags1 |= BS_FLAGS1_80;
    } else {
        gBattleStatus.flags1 &= ~BS_FLAGS1_80;
    }

    attackStatus = battleStatus->curAttackStatus;
    battleStatus->curTargetID = actor->targetActorID;

    battleStatus->curTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = attackStatus;

    if ((attackStatus & 0xFF) == 0xFF) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->curAttackStatus & 0xF00) >> 8;
    hitResult = calc_enemy_test_target(actor);

    if (hitResult < 0) {
        return ApiStatus_FINISH;
    }

    evt_set_variable(script, outVar, hitResult);

    return ApiStatus_DONE2;
}

ApiStatus DispatchDamageEvent(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 damageAmount;
    s32 scriptExists;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    damageAmount = evt_get_variable(script, *args++);

    if (dispatch_damage_event_actor_0(actor, damageAmount, evt_get_variable(script, *args++)) < 0) {
        return ApiStatus_BLOCK;
    }

    scriptExists = does_script_exist_by_ref(script) != 0;
    return scriptExists * ApiStatus_DONE2;
}

ApiStatus DispatchEvent(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    dispatch_event_actor(get_actor(actorID), evt_get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus ShowHealthBar(Evt* script, s32 isInitialCall) {
    s32 actorID = evt_get_variable(script, *script->ptrReadPos);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    show_actor_health_bar(get_actor(actorID));
    return ApiStatus_DONE2;
}

ApiStatus HideHealthBar(Evt* script, s32 isInitialCall) {
    s32 actorID = evt_get_variable(script, *script->ptrReadPos);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    hide_actor_health_bar(get_actor(actorID));
    return ApiStatus_DONE2;
}

ApiStatus SetTargetOffset(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID;
    ActorPart* part;
    s32 x;
    s32 y;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    part = get_actor_part(get_actor(actorID), partID);

    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);

    part->targetOffset.x = x;
    part->targetOffset.y = y;

    return ApiStatus_DONE2;
}

ApiStatus func_8027D434(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID;
    ActorPart* part;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    part = get_actor_part(get_actor(actorID), partID);
    part->unk_70 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus SetProjectileTargetOffset(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID;
    ActorPart* part;
    s32 dx;
    s32 dy;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partID = evt_get_variable(script, *args++);
    part = get_actor_part(get_actor(actorID), partID);

    dx = evt_get_variable(script, *args++);
    dy = evt_get_variable(script, *args++);

    part->projectileTargetOffset.x = dx;
    part->projectileTargetOffset.y = dy;

    return ApiStatus_DONE2;
}

ApiStatus EnableActorBlur(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 enable = evt_get_variable(script, *args++);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);

    if (enable == 0) {
        disable_actor_blur(actor);
    } else if (enable == 1) {
        enable_actor_blur(actor);
    } else {
        reset_actor_blur(actor);
    }
    return ApiStatus_DONE2;
}

ApiStatus func_8027D628(Evt* script, s32 isInitialCall) {
    s32 actorID = evt_get_variable(script, *script->ptrReadPos);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    func_80254610(get_actor(actorID));
    return ApiStatus_DONE2;
}

ApiStatus AfflictActor(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 statusTypeKey;
    s32 duration;
    s32 statusDurationKey;

    statusTypeKey = evt_get_variable(script, *args++);
    duration = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    actor = get_actor(actorID);

    switch (statusTypeKey) {
        case 7:
            statusDurationKey = 38;
            break;
        case 6:
            statusDurationKey = 32;
            break;
        case 5:
            statusDurationKey = 38;
            break;
        case 4:
            statusDurationKey = 36;
            break;
        default:
            statusDurationKey = 38;
            break;
    }

    inflict_status_set_duration(actor, statusTypeKey, statusDurationKey, duration);

    return ApiStatus_DONE2;
}

ApiStatus GetInstigatorValue(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 outVar = *args++;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    evt_set_variable(script, outVar, get_actor(actorID)->instigatorValue);
    return ApiStatus_DONE2;
}

ApiStatus GetEncounterTrigger(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gCurrentEncounter.hitType);
    return ApiStatus_DONE2;
}

ApiStatus YieldTurn(Evt* script, s32 isInitialCall) {
    gBattleStatus.flags1 |= BS_FLAGS1_YIELD_TURN;
    return ApiStatus_DONE2;
}

ApiStatus SetActorSize(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 y = evt_get_variable(script, *args++);
    s32 x = evt_get_variable(script, *args++);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);

    if (y != EVT_IGNORE_ARG) {
        actor->size.y = y;
    }
    if (x != EVT_IGNORE_ARG) {
        actor->size.x = x;
    }
    actor->shadowScale = actor->size.x / 24.0;

    return ApiStatus_DONE2;
}

ApiStatus GetActorSize(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 outY = *args++;
    s32 outX = *args++;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    evt_set_variable(script, outY, actor->size.y);
    evt_set_variable(script, outX, actor->size.x);
    return ApiStatus_DONE2;
}

ApiStatus SetPartSize(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partID = evt_get_variable(script, *args++);
    s32 sizeY = evt_get_variable(script, *args++);
    s32 sizeX = evt_get_variable(script, *args++);
    ActorPart* part;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    part = get_actor_part(get_actor(actorID), partID);

    if (sizeY != EVT_IGNORE_ARG) {
        part->size.y = sizeY;
    }

    if (sizeX != EVT_IGNORE_ARG) {
        part->size.x = sizeX;
    }

    part->shadowScale = part->size.x / 24.0;

    return ApiStatus_DONE2;
}

ApiStatus GetOriginalActorType(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 outVar = *args++;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    evt_set_variable(script, outVar, get_actor(actorID)->actorBlueprint->type);
    return ApiStatus_DONE2;
}

ApiStatus GetCurrentActorType(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 outVar = *args++;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    evt_set_variable(script, outVar, get_actor(actorID)->actorType);
    return ApiStatus_DONE2;
}

ApiStatus GetLastDamage(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 outVar;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    outVar = *args++;

    evt_set_variable(script, outVar, get_actor(actorID)->lastDamageTaken);
    return ApiStatus_DONE2;
}

ApiStatus EnableActorGlow(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 flag;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    flag = evt_get_variable(script, *args++);
    actor = get_actor(actorID);
    actor->isGlowing = flag;

    if (!flag) {
        ActorPart* it = actor->partsTable;

        while (it != NULL) {
            if (it->idleAnimations != NULL) {
                set_npc_imgfx_all(it->spriteInstanceID, IMGFX_CLEAR, 0, 0, 0, 0, 0);
            }
            it = it->nextPart;
        }
        func_80266EE8(actor, UNK_PAL_EFFECT_0);
    }

    return ApiStatus_DONE2;
}

ApiStatus WasStatusInflicted(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 outVal;

    evt_get_variable(script, *args++);

    if (script) { // can be args or script but not 1 or do while 0, nor does else work after
        outVal = battleStatus->wasStatusInflicted;
    }
    outVal = battleStatus->wasStatusInflicted;

    evt_set_variable(script, *args++, outVal);

    return ApiStatus_DONE2;
}

ApiStatus CopyStatusEffects(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorIDTo;
    s32 actorIDFrom;
    Actor* actorTo;
    Actor* actorFrom;

    actorIDFrom = evt_get_variable(script, *args++);
    if (actorIDFrom == ACTOR_SELF) {
        actorIDFrom = script->owner1.actorID;
    }
    actorFrom = get_actor(actorIDFrom);

    actorIDTo = evt_get_variable(script, *args++);
    if (actorIDTo == ACTOR_SELF) {
        actorIDTo = script->owner1.actorID;
    }
    actorTo = get_actor(actorIDTo);

    inflict_status(actorTo, actorFrom->debuff, actorFrom->debuffDuration);
    inflict_status(actorTo, actorFrom->staticStatus, actorFrom->staticDuration);
    inflict_status(actorTo, actorFrom->stoneStatus, actorFrom->stoneDuration);
    inflict_status(actorTo, actorFrom->koStatus, actorFrom->koDuration);
    inflict_status(actorTo, actorFrom->transparentStatus, actorFrom->transparentDuration);

    actorFrom->statusAfflicted = 0;
    actorTo->statusAfflicted = 0;

    return ApiStatus_DONE2;
}

ApiStatus ClearStatusEffects(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 flag;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);

    if (actor->debuff != 0) {
        actor->debuffDuration = 0;
        actor->debuff = 0;
        remove_status_debuff(actor->hudElementDataIndex);
    }

    if (actor->staticStatus != 0) {
        actor->staticDuration = 0;
        actor->staticStatus = 0;
        remove_status_static(actor->hudElementDataIndex);
    }

    if (actor->transparentStatus != 0) {
        actor->transparentDuration = 0;
        actor->transparentStatus = 0;
        remove_status_transparent(actor->hudElementDataIndex);
    }

    if (actor->stoneStatus != 0) {
        actor->stoneDuration = 0;
        actor->stoneStatus = 0;
    }

    actor->koStatus = 0;
    actor->koDuration = 0;
    actor->disableEffect->data.disableX->koDuration = 0;
    actor->attackBoost = 0;
    actor->defenseBoost = 0;
    actor->isGlowing = 0;

    return ApiStatus_DONE2;
}
