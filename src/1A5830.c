#include "common.h"
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
        if (partIt->eventFlags & (ACTOR_EVENT_FLAG_ENCHANTED | ACTOR_EVENT_FLAG_80000)) {
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
            sfx_play_sound_at_position(SOUND_IMMUNE, 0, x, y, z);
            break;
        case HIT_SOUND_BONES:
            sfx_play_sound_at_position(SOUND_HIT_BONES, 0, x, y, z);
            break;
        case HIT_SOUND_NORMAL:
            switch (actorClass) {
                case ACTOR_CLASS_PLAYER:
                    sfx_play_sound_at_position(SOUND_HIT_PLAYER_NORMAL, 0, x, y, z);
                    break;
                case ACTOR_CLASS_PARTNER:
                    sfx_play_sound_at_position(SOUND_HIT_NORMAL, 0, x, y, z);
                    break;
                case ACTOR_CLASS_ENEMY:
                    sfx_play_sound_at_position(SOUND_HIT_NORMAL, 0, x, y, z);
                    break;
            }
            break;
        case HIT_SOUND_FIRE:
            switch (actorClass) {
                case ACTOR_CLASS_PLAYER:
                    sfx_play_sound_at_position(SOUND_HIT_PLAYER_FIRE, 0, x, y, z);
                    break;
                case ACTOR_CLASS_PARTNER:
                    sfx_play_sound_at_position(SOUND_HIT_FIRE, 0, x, y, z);
                    break;
                case ACTOR_CLASS_ENEMY:
                    sfx_play_sound_at_position(SOUND_HIT_FIRE, 0, x, y, z);
                    break;
            }
            break;
        case HIT_SOUND_ICE:
            switch (actorClass) {
                case ACTOR_CLASS_PLAYER:
                    sfx_play_sound_at_position(SOUND_HIT_PLAYER_ICE, 0, x, y, z);
                    break;
                case ACTOR_CLASS_PARTNER:
                    sfx_play_sound_at_position(SOUND_HIT_ICE, 0, x, y, z);
                    break;
                case ACTOR_CLASS_ENEMY:
                    sfx_play_sound_at_position(SOUND_HIT_ICE, 0, x, y, z);
                    break;
            }
            break;
        case HIT_SOUND_SHOCK:
            switch (actorClass) {
                case ACTOR_CLASS_PLAYER:
                    sfx_play_sound_at_position(SOUND_HIT_PLAYER_SHOCK, 0, x, y, z);
                    break;
                case ACTOR_CLASS_PARTNER:
                    sfx_play_sound_at_position(SOUND_HIT_SHOCK, 0, x, y, z);
                    break;
                case ACTOR_CLASS_ENEMY:
                    sfx_play_sound_at_position(SOUND_HIT_SHOCK, 0, x, y, z);
                    break;
            }
            break;
    }
}

void dispatch_event_actor(Actor* actor, s32 event) {
    Evt* onHitScript = actor->onHitScript;
    s32 onHitID = actor->onHitID;

    if (actor->onHitScriptSource != NULL) {
        Evt* newScript;

        actor->lastEventType = event;
        newScript = start_script(actor->onHitScriptSource, EVT_PRIORITY_A, EVT_FLAG_20);
        actor->onHitScript = newScript;
        actor->onHitID = newScript->id;
        newScript->owner1.actorID = actor->actorID;
    }

    if (actor->takeTurnScript != NULL) {
        get_script_by_index(actor->takeTurnID);
        kill_script_by_ID(actor->takeTurnID);
        actor->takeTurnScript = NULL;
    }

    if (onHitScript != NULL) {
        kill_script_by_ID(onHitID);
    }
}

s32 calc_enemy_test_target(Actor* actor) {
    PlayerData* playerData = &gPlayerData;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 targetID = battleStatus->currentTargetID;
    s32 targetPartIdx = battleStatus->currentTargetPart;
    Actor* target;
    Actor* target2;
    ActorPart* targetPart;
    s32 actorClass;
    s32 hitResult;

    battleStatus->currentTargetID2 = battleStatus->currentTargetID;
    battleStatus->currentTargetPart2 = battleStatus->currentTargetPart;

    target = get_actor(targetID);
    if (target == NULL) {
        return HIT_RESULT_HIT;
    }

    targetPart = get_actor_part(target, targetPartIdx);
    ASSERT(targetPart != NULL);

    actorClass = targetID & ACTOR_CLASS_MASK;
    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            target->currentHP = playerData->curHP;
            break;
        case ACTOR_CLASS_PARTNER:
            target->currentHP = 127;
            break;
        case ACTOR_CLASS_ENEMY:
            break;
    }

    if (battleStatus->currentAttackElement & DAMAGE_TYPE_TRIGGER_LUCKY) {
        dispatch_event_general(target, EVENT_LUCKY);
        return HIT_RESULT_HIT;
    }

    hitResult = HIT_RESULT_HIT;
    target2 = target;
    if (targetPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY || battleStatus->outtaSightActive || target2->transparentStatus == STATUS_TRANSPARENT) {
        if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_MAGIC)) {
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
                if (rand_int(100) < (s8) battleStatus->cloudNineDodgeChance) {
                    hitResult = 6;
                    break;
                }
            } else {
                if (player_team_is_ability_active(target2, ABILITY_PRETTY_LUCKY)) {
                    if (rand_int(100) < 10) {
                        hitResult = HIT_RESULT_LUCKY;
                        break;
                    }
                }
                if (player_team_is_ability_active(target2, ABILITY_CLOSE_CALL) && (target2->currentHP < 6)) {
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

    if (target2->stoneStatus == STATUS_STONE) {
        return HIT_RESULT_IMMUNE;
    }

    if (target2->staticStatus == STATUS_STATIC) {
        return HIT_RESULT_HIT_STATIC;
    }

    return HIT_RESULT_HIT;
}

s32 calc_enemy_damage_target(Actor* attacker) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActorState* state = &attacker->state;
    s32 targetID = battleStatus->currentTargetID;
    s32 targetPartIdx = battleStatus->currentTargetPart;
    s32 actorClass;
    Actor* target;
    ActorPart* targetPart;
    s32 hitResult;
    s32 t = TRUE;
    s32 statusInflicted = FALSE;
    s32 statusInflicted2 = FALSE;
    s32 isFire = FALSE;
    s32 isElectric = FALSE;
    s32 isEnchanted = FALSE;
    s32 isPlayer;
    s32 defense;
    s32 event;
    s32 damage;
    Evt* script;

    battleStatus->wasStatusInflicted = FALSE;
    battleStatus->lastAttackDamage = 0;

    battleStatus->attackerActorID = attacker->actorID;
    battleStatus->currentTargetID2 = targetID;
    battleStatus->currentTargetPart2 = targetPartIdx;

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
            target->currentHP = gPlayerData.curHP;
            break;
        case ACTOR_CLASS_PARTNER:
            target->currentHP = 127;
            break;
        case ACTOR_CLASS_ENEMY:
            break;
    }

    if (targetPart->eventFlags & ACTOR_EVENT_FLAG_ILLUSORY) {
        return HIT_RESULT_MISS;
    }

    if (target->transparentStatus == STATUS_TRANSPARENT || targetPart->eventFlags & ACTOR_EVENT_FLAG_800 && !(battleStatus->currentAttackElement & DAMAGE_TYPE_QUAKE)) {
        return HIT_RESULT_MISS;
    }

    if (target->stoneStatus == STATUS_STONE) {
        func_8024EFE0(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, -1);
        show_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 0);
        play_hit_sound(attacker, state->goalPos.x, state->goalPos.y, state->goalPos.z, 0);
        dispatch_event_general(target, EVENT_IMMUNE);
        return HIT_RESULT_HIT;
    }
    if (battleStatus->currentAttackElement & DAMAGE_TYPE_BLAST) {
        if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT) && (targetPart->eventFlags & ACTOR_EVENT_FLAG_EXPLOSIVE)) {
            do {
                play_hit_sound(attacker, state->goalPos.x, state->goalPos.y, state->goalPos.z, 3);
            } while (0); // TODO ?
            dispatch_event_general(target, EVENT_EXPLODE_TRIGGER);
            return HIT_RESULT_TRIGGERED_EXPLODE;
        }
    }
    if ((battleStatus->currentAttackElement & DAMAGE_TYPE_QUAKE) && (target->flags & ACTOR_FLAG_FLYING)) {
        play_hit_sound(attacker, state->goalPos.x, state->goalPos.y, state->goalPos.z, 1);
        return HIT_RESULT_QUAKE_IMMUNE;
    }
    if (battleStatus->currentAttackElement & DAMAGE_TYPE_FIRE) {
        fx_ring_blast(0, state->goalPos.x, state->goalPos.y, state->goalPos.z + 5.0f, 1.0f, 0x18);
        isFire = TRUE;
    }
    if (battleStatus->currentAttackElement & DAMAGE_TYPE_ELECTRIC) {
        func_80251474(target);
        isElectric = TRUE;
    }
    if (battleStatus->currentAttackElement & DAMAGE_TYPE_WATER) {
        fx_water_splash(0, state->goalPos.x, state->goalPos.y, state->goalPos.z + 5.0f, 1.0f, 0x18);
    }
    if (battleStatus->currentAttackElement & DAMAGE_TYPE_ICE) {
        fx_big_snowflakes(0, state->goalPos.x, state->goalPos.y, state->goalPos.z + 5.0f);
    }

    if (!(attacker->staticStatus == STATUS_STATIC)) {
        if ((target->staticStatus == STATUS_STATIC) || (targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED)) {
            if (!(battleStatus->currentAttackElement & (DAMAGE_TYPE_ELECTRIC | DAMAGE_TYPE_NO_CONTACT))) {
                if (!(battleStatus->currentAttackEventSuppression & 8)) {
                    if (!has_enchanted_part(attacker)) {
                        isEnchanted = TRUE;
                        gBattleStatus.flags1 |= BS_FLAGS1_SP_EVT_ACTIVE;
                    }
                }
            }
        }
    }
    gBattleStatus.flags1 &= ~BS_FLAGS1_ATK_BLOCKED;

    defense = get_defense(target, targetPart->defenseTable, battleStatus->currentAttackElement);

    if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_IGNORE_DEFENSE)) {
        defense += target->defenseBoost;

        if (actorClass == ACTOR_CLASS_PLAYER) {
            if (battleStatus->waterBlockTurnsLeft > 0) {
                if ((battleStatus->currentAttackElement & (DAMAGE_TYPE_BLAST | DAMAGE_TYPE_FIRE))) {
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

    damage = battleStatus->currentAttackDamage;

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

    if (attacker->debuff == STATUS_SHRINK) {
        if (damage > 0) {
            damage /= 2;
        }
    }

    if (damage > 99) {
        damage = 99;
    }
    if (damage <= 0) {
        defense = 0;
    }

    target->hpChangeCounter = 0;
    damage -= defense;

    isPlayer = actorClass == ACTOR_CLASS_PLAYER;
    if (isPlayer) {
        if (player_team_is_ability_active(target, ABILITY_FIRE_SHIELD)) {
            if (battleStatus->currentAttackElement & DAMAGE_TYPE_FIRE) {
                damage--;
            }
        }

        damage -= player_team_is_ability_active(target, ABILITY_DEFEND_PLUS);
        damage -= player_team_is_ability_active(target, ABILITY_P_DOWN_D_UP);
        damage += player_team_is_ability_active(target, ABILITY_P_UP_D_DOWN);

        if (target->currentHP <= 5) {
            if (player_team_is_ability_active(target, ABILITY_LAST_STAND)) {
                damage /= 2;
            }
        }
    }

    switch (actorClass) {
        case ACTOR_CLASS_PLAYER:
            // TODO figure out how to better write target->debuff >= STATUS_POISON
            if ((target->debuff == 0 || target->debuff >= STATUS_POISON) && (target->stoneStatus == STATUS_END) && !(battleStatus->currentAttackElement & DAMAGE_TYPE_UNBLOCKABLE)) {
                s32 blocked;

                if (player_team_is_ability_active(target, ABILITY_BERSERKER)) {
                    blocked = rand_int(1);
                } else {
                    blocked = check_block_input(BUTTON_A);
                }

                if (blocked) {
                    damage--;
                    damage -= player_team_is_ability_active(target, ABILITY_DAMAGE_DODGE);
                    sfx_play_sound_at_position(SOUND_231, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    func_802667F0(0, target, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                    gBattleStatus.flags1 |= BS_FLAGS1_ATK_BLOCKED;
                    break;
                }
                func_80266970(target);
            }
            break;
        case ACTOR_CLASS_PARTNER:
            if (target->stoneStatus == STATUS_END) {
                if (target->koStatus == STATUS_END && !(battleStatus->currentAttackElement & DAMAGE_TYPE_UNBLOCKABLE)) {
                    if (check_block_input(BUTTON_A)) {
                        damage = 0;
                        sfx_play_sound_at_position(SOUND_231, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
                        func_802667F0(0, target, state->goalPos.x, state->goalPos.y, state->goalPos.z);
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

    event = EVENT_HIT_COMBO;
    if (damage <= 0) {
        target->hpChangeCounter = 0;
        if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_STATUS_ALWAYS_HITS)) {
            hitResult = HIT_RESULT_QUAKE_IMMUNE;
            event = EVENT_UNKNOWN_TRIGGER;
        } else {
            hitResult = HIT_RESULT_QUAKE_IMMUNE;
            event = EVENT_UNKNOWN_TRIGGER;
            if (target->currentHP <= 0) {
                event = EVENT_DEATH;
            }
        }
        battleStatus->lastAttackDamage = 0;
    } else {
        target->damageCounter += damage;
        target->hpChangeCounter -= damage;
        battleStatus->lastAttackDamage = 0;
        hitResult = HIT_RESULT_HIT;
        if (!(targetPart->flags & ACTOR_PART_FLAG_2000)) {
            if (!(gBattleStatus.flags1 & BS_FLAGS1_2000000)) {
                if (!(target->flags & ACTOR_FLAG_NO_DMG_APPLY)) {
                    target->currentHP -= damage;
                }

                if (target->currentHP <= 0) {
                    target->currentHP = 0;
                    event = EVENT_DEATH;
                }
            }
        }
        battleStatus->lastAttackDamage += damage;
        target->lastDamageTaken = battleStatus->lastAttackDamage;
        target->hpChangeCounter = 0;

        if (actorClass == ACTOR_CLASS_PLAYER) {
            battleStatus->damageTaken += damage;
            gPlayerData.curHP = target->currentHP;
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (event == EVENT_HIT_COMBO) {
            event = EVENT_HIT;
        }
        if (event == EVENT_UNKNOWN_TRIGGER) {
            event = EVENT_IMMUNE;
        }
        if (target->currentHP <= 0 && event == EVENT_IMMUNE) {
            event = EVENT_DEATH;
        }
    } else if (event == EVENT_DEATH) {
        event = EVENT_HIT_COMBO;
    }

    if (!(gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE)) {
        func_80266E14(targetPart);
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (battleStatus->currentAttackElement & (DAMAGE_TYPE_POW | DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_JUMP)) {
            if (targetPart->eventFlags & ACTOR_EVENT_FLAG_FLIPABLE) {
                if (event == EVENT_HIT) {
                    event = EVENT_FLIP_TRIGGER;
                }
                if (event == EVENT_IMMUNE) {
                    event = EVENT_FLIP_TRIGGER;
                }
            }
        }
    }

    if (!(gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE)) {
        if (battleStatus->currentAttackElement & (DAMAGE_TYPE_POW | DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_JUMP)) {
            if (targetPart->eventFlags & ACTOR_EVENT_FLAG_FLIPABLE) {
                if (event == EVENT_HIT_COMBO) {
                    event = EVENT_FLIP_TRIGGER;
                }
                if (event == EVENT_UNKNOWN_TRIGGER) {
                    event = EVENT_FLIP_TRIGGER;
                }
            }
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (battleStatus->currentAttackElement & (DAMAGE_TYPE_FIRE | DAMAGE_TYPE_BLAST | DAMAGE_TYPE_4000)) {
            if (event == EVENT_HIT) {
                event = EVENT_BURN_HIT;
            }
            if (event == EVENT_DEATH) {
                event = EVENT_FIRE_DEATH;
            }
            isFire = TRUE;
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_ATK_BLOCKED) {
        if (event == EVENT_HIT_COMBO) {
            event = EVENT_18;
        }
        if (event == EVENT_HIT) {
            event = EVENT_BLOCK;
        }
        if (event == EVENT_UNKNOWN_TRIGGER) {
            event = EVENT_18;
        }
        if (event == EVENT_IMMUNE) {
            event = EVENT_BLOCK;
        }
        if (event == EVENT_BURN_HIT) {
            event = EVENT_BLOCK;
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (battleStatus->lastAttackDamage >= 0 && event != EVENT_DEATH && event != EVENT_SPIN_SMASH_DEATH) {
            if (event != EVENT_EXPLODE_TRIGGER) {
                if (!(gBattleStatus.flags1 & BS_FLAGS1_ATK_BLOCKED)) {
                    if (!(gBattleStatus.flags2 & BS_FLAGS2_1000000)) {
                        if (actorClass != ACTOR_PLAYER || !is_ability_active(ABILITY_HEALTHY_HEALTHY) || !(rand_int(100) < 50)) {
                            if (battleStatus->currentAttackStatus & STATUS_FLAG_SHRINK && try_inflict_status(target, STATUS_SHRINK, STATUS_SHRINK_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }
                            if (battleStatus->currentAttackStatus & STATUS_FLAG_POISON && try_inflict_status(target, STATUS_POISON, STATUS_POISON_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }
                            if (battleStatus->currentAttackStatus & STATUS_FLAG_STONE && try_inflict_status(target, STATUS_STONE, STATUS_STONE_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }
                            if (battleStatus->currentAttackStatus & STATUS_FLAG_SLEEP && try_inflict_status(target, STATUS_SLEEP, STATUS_SLEEP_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }
                            if (battleStatus->currentAttackStatus & STATUS_FLAG_DIZZY && try_inflict_status(target, STATUS_DIZZY, STATUS_DIZZY_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }
                            if (battleStatus->currentAttackStatus & STATUS_FLAG_STOP && try_inflict_status(target, STATUS_STOP, STATUS_STOP_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }
                            if (battleStatus->currentAttackStatus & STATUS_FLAG_STATIC && try_inflict_status(target, STATUS_STATIC, STATUS_STATIC_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }
                            if (battleStatus->currentAttackStatus & STATUS_FLAG_PARALYZE && try_inflict_status(target, STATUS_PARALYZE, STATUS_PARALYZE_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }
                            if (battleStatus->currentAttackStatus & STATUS_FLAG_FEAR && try_inflict_status(target, STATUS_FEAR, STATUS_FEAR_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }

                            // BUG? repeated paralyze and dizzy infliction
                            if (battleStatus->currentAttackStatus & STATUS_FLAG_PARALYZE && try_inflict_status(target, STATUS_PARALYZE, STATUS_PARALYZE_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }
                            if (battleStatus->currentAttackStatus & STATUS_FLAG_DIZZY && try_inflict_status(target, STATUS_DIZZY, STATUS_DIZZY_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }

                            if (battleStatus->currentAttackStatus & STATUS_FLAG_FROZEN && target->debuff != STATUS_FROZEN && try_inflict_status(target, STATUS_FROZEN, STATUS_FROZEN_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }

                            if (statusInflicted) {
                                if (event == EVENT_UNKNOWN_TRIGGER) {
                                    event = EVENT_HIT_COMBO;
                                }
                                if (event == EVENT_IMMUNE) {
                                    event = EVENT_HIT;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

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

    if (actorClass == ACTOR_CLASS_PARTNER) {
        if (battleStatus->lastAttackDamage > 0 && gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE && !(target->flags & ACTOR_FLAG_NO_DMG_APPLY)) {
            inflict_partner_ko(target, STATUS_DAZE, battleStatus->lastAttackDamage);
        }
    }
    if (!(target->flags & ACTOR_FLAG_NO_DMG_POPUP)) {
        switch (actorClass) {
            case ACTOR_CLASS_PLAYER:
            case ACTOR_CLASS_PARTNER:
                if (battleStatus->lastAttackDamage == 0) {
                    if (!statusInflicted2 && !statusInflicted) {
                        // immune star fx?
                        func_8024EFE0(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, -3);
                    }
                } else if (battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS | DAMAGE_TYPE_SMASH)) {
                    show_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 1);
                    func_802666E4(target, state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage);
                } else {
                    func_802664DC(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 1);
                    func_802666E4(target, state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage);
                    break;
                }
                break;
            case ACTOR_CLASS_ENEMY:
                if (battleStatus->lastAttackDamage == 0) {
                    if (!statusInflicted2 && !statusInflicted) {
                        func_8024EFE0(state->goalPos.x, state->goalPos.y, state->goalPos.z, 0, 1, 3);
                    }
                } else if (battleStatus->currentAttackElement & (DAMAGE_TYPE_NO_OTHER_DAMAGE_POPUPS | DAMAGE_TYPE_SMASH)) {
                    show_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 0);
                    func_802666E4(target, state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage);
                } else {
                    func_802664DC(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 0);
                    func_802666E4(target, state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage);
                }
                break;
        }
    }

    if (battleStatus->lastAttackDamage > 0) {
        u32 hitSound;

        func_80267018(target, 1);

        if (attacker->actorTypeData1[5] != SOUND_0) {
            sfx_play_sound_at_position(attacker->actorTypeData1[5], 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
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

    if ((battleStatus->lastAttackDamage <= 0 && !statusInflicted2 && !isEnchanted) || targetPart->flags & ACTOR_PART_FLAG_2000) {
        sfx_play_sound_at_position(SOUND_IMMUNE, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if ((battleStatus->currentAttackStatus & STATUS_FLAG_SLEEP) && statusInflicted) {
        script = start_script(&DoSleepHit, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_SLEEP, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->currentAttackStatus & STATUS_FLAG_DIZZY) && statusInflicted) {
        script = start_script(&DoDizzyHit, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->currentAttackStatus & STATUS_FLAG_PARALYZE) && statusInflicted) {
        script = start_script(&DoParalyzeHit, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->currentAttackStatus & STATUS_FLAG_POISON) && statusInflicted) {
        script = start_script(&DoPoisonHit, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->currentAttackStatus & STATUS_FLAG_STOP) && statusInflicted) {
        script = start_script(&DoStopHit, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->currentAttackStatus & STATUS_FLAG_FROZEN) && statusInflicted) {
        script = start_script(&DoFreezeHit, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        script->varTablePtr[3] = target;
        sfx_play_sound_at_position(SOUND_HIT_ICE, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }
    if ((battleStatus->currentAttackStatus & STATUS_FLAG_SHRINK) && statusInflicted) {
        script = start_script(&DoShrinkHit, EVT_PRIORITY_A, 0);
        script->varTable[0] = state->goalPos.x;
        script->varTable[1] = state->goalPos.y;
        script->varTable[2] = state->goalPos.z;
        script->varTablePtr[3] = target;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    if ((battleStatus->currentAttackElement & DAMAGE_TYPE_SMASH) && target->actorType == ACTOR_TYPE_GOOMNUT_TREE) {
        sfx_play_sound_at_position(SOUND_SMASH_GOOMNUT_TREE, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
    }

    func_80266ADC(target);
    if ((
            attacker->staticStatus != STATUS_STATIC
            && (target->staticStatus == STATUS_STATIC || (targetPart->eventFlags & ACTOR_EVENT_FLAG_ELECTRIFIED))
        )
        && !(battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT)
        && !(battleStatus->currentAttackEventSuppression & 8)
        && (attacker->transparentStatus != STATUS_TRANSPARENT)
        && !has_enchanted_part(attacker)
    ) {
        // enum mismatch? shock vs explode :raised_eyebrow:
        sfx_play_sound_at_position(SOUND_HIT_SHOCK, 0, state->goalPos.x, state->goalPos.y, state->goalPos.z);
        func_80251474(attacker);
        dispatch_damage_event_actor_1(attacker, 1, EVENT_SHOCK_HIT);
        return HIT_RESULT_TRIGGERED_EXPLODE;
    }

    return hitResult;
}

// missing one move
#ifdef NON_EQUIVALENT
s32 dispatch_damage_event_actor(Actor* actor, s32 damageAmount, s32 originalEvent, s32 stopMotion) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActorState* state;
    s32 dispatchEvent = originalEvent;
    s32 currentAttackDamage;
    s32 hpChangeCounter;

    battleStatus->currentAttackDamage = damageAmount;
    currentAttackDamage = battleStatus->currentAttackDamage;

    actor->hpChangeCounter += currentAttackDamage;
    hpChangeCounter = actor->hpChangeCounter;
    actor->damageCounter += hpChangeCounter;
    actor->hpChangeCounter -= hpChangeCounter;
    battleStatus->lastAttackDamage = 0;
    do { } while (0);
    actor->currentHP -= hpChangeCounter;
    state = &actor->state;
    if (actor->currentHP <= 0) {
        dispatchEvent = EVENT_DEATH;
        battleStatus->lastAttackDamage += actor->currentHP;
        actor->currentHP = 0;
    }
    battleStatus->lastAttackDamage += currentAttackDamage;
    actor->lastDamageTaken = battleStatus->lastAttackDamage;
    battleStatus->unk_19A = 0;

    if (battleStatus->flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (dispatchEvent == EVENT_HIT_COMBO) {
            dispatchEvent = EVENT_HIT;
        }
        if (dispatchEvent == EVENT_UNKNOWN_TRIGGER) {
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

    if (stopMotion == 0) {
        s32 oldTargetActorID = actor->targetActorID;

        if (func_80263230(actor, actor) != 0) {
            show_damage_popup(actor->targetData[0].pos.x, actor->targetData[0].pos.y, actor->targetData[0].pos.z, battleStatus->lastAttackDamage, 0);
            func_802666E4(actor, actor->targetData[0].pos.x, actor->targetData[0].pos.y, actor->targetData[0].pos.z, battleStatus->lastAttackDamage);
            actor->targetActorID = oldTargetActorID;
        } else {
            actor->targetActorID = oldTargetActorID;
        }
    } else {
        show_damage_popup(state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage, 0);
        func_802666E4(actor, state->goalPos.x, state->goalPos.y, state->goalPos.z, battleStatus->lastAttackDamage);
    }

    if (battleStatus->lastAttackDamage > 0) {
        func_80267018(actor, 1);
    }
    actor->flags |= ACTOR_FLAG_80000;
    dispatch_event_actor(actor, dispatchEvent);
    return 0;
}
#else
s32 dispatch_damage_event_actor(Actor* actor, s32 damageAmount, s32 originalEvent, s32 stopMotion);
INCLUDE_ASM(s32, "1A5830", dispatch_damage_event_actor);
#endif

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
    get_actor(actorID)->takeTurnScriptSource = takeTurnScript;
    return ApiStatus_DONE2;
}

ApiStatus PauseTakeTurn(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    evt_get_variable(script, *args++);
    suspend_all_script(get_actor(actorID)->takeTurnID);
    return ApiStatus_DONE2;
}

ApiStatus ResumeTakeTurn(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    evt_get_variable(script, *args++);
    resume_all_script(get_actor(actorID)->takeTurnID);
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

    actor->idleScriptSource = idleCode;
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
    EvtScript* var1;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    var1 = (EvtScript*) evt_get_variable(script, *args++);
    get_actor(actorID)->onHitScriptSource = var1;
    return ApiStatus_DONE2;
}

ApiStatus BindNextTurn(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    EvtScript* var1;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    var1 = (EvtScript*) evt_get_variable(script, *args++);
    get_actor(actorID)->onTurnChanceScriptSource = var1;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "1A5830", JumpToGoal);

ApiStatus IdleJumpToGoal(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorMovement* fly;
    f32 x, y, z;
    f32 goalX, goalY, goalZ;
    f32 var_f8;
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
        fly = &actor->fly;

        actor->fly.flyTime = evt_get_variable(script, *args++);
        script->functionTemp[2] = evt_get_variable(script, *args++);
        script->functionTemp[3] = evt_get_variable(script, *args++);

        fly->currentPos.x = actor->currentPos.x;
        fly->currentPos.y = actor->currentPos.y;
        fly->currentPos.z = actor->currentPos.z;

        x = fly->currentPos.x;
        y = fly->currentPos.y;
        z = fly->currentPos.z;
        goalX = fly->goalPos.x;
        goalY = fly->goalPos.y;
        goalZ = fly->goalPos.z;
        fly->angle = atan2(x, z, goalX, goalZ);
        fly->distance = dist2D(x, z, goalX, goalZ);
        y = goalY - y;

        if (fly->flyTime == 0) {
            fly->flyTime = fly->distance / fly->speed;
            var_f8 = fly->distance - (fly->flyTime * fly->speed);
        } else {
            fly->speed = fly->distance / fly->flyTime;
            var_f8 = fly->distance - (fly->flyTime * fly->speed);
        }

        if (fly->flyTime == 0) {
            return ApiStatus_DONE2;
        }

        fly->velocity = ((fly->acceleration * fly->flyTime) * 0.5f) + (y / fly->flyTime);
        fly->speed += var_f8 / fly->flyTime;
        script->functionTemp[0] = TRUE;
    }

    actor = script->functionTempPtr[1];
    fly = &actor->fly;

    fly->currentPos.y += fly->velocity;
    fly->velocity -= fly->acceleration;
    if (fly->velocity < 0.0f && fly->goalPos.y > fly->currentPos.y) {
        fly->currentPos.y = fly->goalPos.y;
    }
    add_xz_vec3f_copy2(&fly->currentPos, fly->speed, fly->angle);
    actor->currentPos.x = fly->currentPos.x;
    actor->currentPos.y = fly->currentPos.y;
    actor->currentPos.z = fly->currentPos.z;

    fly->flyTime--;
    if (fly->flyTime <= 0) {
        if (script->functionTemp[3] != 0) {
            play_movement_dust_effects(2, fly->goalPos.x, fly->goalPos.y, fly->goalPos.z, fly->angle);
        }
        actor->currentPos.x = fly->goalPos.x;
        actor->currentPos.y = fly->goalPos.y;
        actor->currentPos.z = fly->goalPos.z;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus JumpToGoalSimple2(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorState* state;
    f32 x, y, z;
    f32 goalX, goalY, goalZ;
    f32 var_f8;
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
        state->currentPos.x = actor->currentPos.x;
        state->currentPos.y = actor->currentPos.y;
        state->currentPos.z = actor->currentPos.z;

        x = state->currentPos.x;
        y = state->currentPos.y;
        z = state->currentPos.z;
        goalX = state->goalPos.x;
        goalY = state->goalPos.y;
        goalZ = state->goalPos.z;
        state->angle = atan2(x, z, goalX, goalZ);
        state->distance = dist2D(x, z, goalX, goalZ);
        y -= goalY;

        if (state->moveTime == 0) {
            state->moveTime = state->distance / state->speed;
            var_f8 = state->distance - (state->moveTime * state->speed);
        } else {
            state->speed = state->distance / state->moveTime;
            var_f8 = state->distance - (state->moveTime * state->speed);
        }

        if (state->moveTime == 0) {
            return ApiStatus_DONE2;
        }

        state->velocity = ((state->acceleration * state->moveTime) * 0.5f) + (y / state->moveTime);
        state->speed += var_f8 / state->moveTime;
        if (actor->actorTypeData1[4] != 0) {
            sfx_play_sound_at_position(actor->actorTypeData1[4], 0, actor->currentPos.x, actor->currentPos.y, actor->currentPos.z);
        }
        script->functionTemp[0] = TRUE;
    }

    actor = script->functionTempPtr[1];
    state = &actor->state;

    state->currentPos.y -= state->velocity;
    state->velocity -= state->acceleration;
    if (state->velocity > 0.0f && state->goalPos.y < state->currentPos.y) {
        state->currentPos.y = state->goalPos.y;
    }
    add_xz_vec3f(&state->currentPos, state->speed, state->angle);
    actor->currentPos.x = state->currentPos.x;
    actor->currentPos.y = state->currentPos.y;
    actor->currentPos.z = state->currentPos.z;

    state->moveTime--;
    if (state->moveTime <= 0) {
        play_movement_dust_effects(2, state->goalPos.x, state->goalPos.y, state->goalPos.z, state->angle);
        actor->currentPos.x = state->goalPos.x;
        actor->currentPos.y = state->goalPos.y;
        actor->currentPos.z = state->goalPos.z;
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

INCLUDE_ASM(s32, "1A5830", JumpWithBounce);

ApiStatus LandJump(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        s32 actorID = evt_get_variable(script, *args++);

        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }

        actor = get_actor(actorID);
        script->functionTempPtr[1] = actor;
        actor->state.currentPos.x = actor->currentPos.x;
        actor->state.currentPos.y = actor->currentPos.y;
        actor->state.currentPos.z = actor->currentPos.z;
        script->functionTemp[0] = 1;
    }

    actor = script->functionTempPtr[1];
    actor->state.currentPos.y += actor->state.velocity;
    actor->state.velocity -= actor->state.acceleration;

    add_xz_vec3f(&actor->state.currentPos, actor->state.speed, actor->state.angle);
    actor->currentPos.x = actor->state.currentPos.x;
    actor->currentPos.y = actor->state.currentPos.y;
    actor->currentPos.z = actor->state.currentPos.z;

    if (actor->currentPos.y < 0.0f) {
        actor->currentPos.y = 0.0f;
        play_movement_dust_effects(2, actor->currentPos.x, actor->currentPos.y, actor->currentPos.z, actor->yaw);
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

ApiStatus FallToGoal(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorState* state;
    f32 x, y, z;
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

        actor->state.currentPos.x = actor->currentPos.x;
        actor->state.currentPos.y = actor->currentPos.y;
        actor->state.currentPos.z = actor->currentPos.z;

        x = actor->state.currentPos.x;
        y = actor->state.currentPos.y;
        z = actor->state.currentPos.z;
        goalX = actor->state.goalPos.x;
        goalY = actor->state.goalPos.y;
        goalZ = actor->state.goalPos.z;

        actor->state.angle = atan2(x, z, goalX, goalZ);
        actor->state.distance = dist2D(x, z, goalX, goalZ);
        y = goalY - y;

        if (actor->state.moveTime == 0) {
            actor->state.moveTime = actor->state.distance / actor->state.speed;
        } else {
            actor->state.speed = actor->state.distance / actor->state.moveTime;
        }

        state->velocity = 0.0f;
        state->acceleration = (y / state->moveTime - state->velocity) / (-state->moveTime * 0.5);

        if (actor->actorTypeData1[4] != 0) {
            sfx_play_sound_at_position(actor->actorTypeData1[4], 0, actor->currentPos.x, actor->currentPos.y, actor->currentPos.z);
        }
        script->functionTemp[0] = 1;
    }

    actor = script->functionTempPtr[1];
    actor->state.currentPos.y += actor->state.velocity;
    actor->state.velocity -= actor->state.acceleration;
    add_xz_vec3f(&actor->state.currentPos, actor->state.speed, actor->state.angle);
    actor->currentPos.x = actor->state.currentPos.x;
    actor->currentPos.y = actor->state.currentPos.y;
    actor->currentPos.z = actor->state.currentPos.z;
    actor->state.moveTime--;

    if (actor->state.moveTime <= 0) {
        play_movement_dust_effects(2, actor->state.goalPos.x, actor->state.goalPos.y, actor->state.goalPos.z, actor->state.angle);
        actor->currentPos.x = actor->state.goalPos.x;
        actor->currentPos.y = actor->state.goalPos.y;
        actor->currentPos.z = actor->state.goalPos.z;
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

INCLUDE_ASM(s32, "1A5830", RunToGoal);

#ifdef NON_EQUIVALENT
s32 IdleRunToGoal(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorMovement* fly;
    f32 x1, z1, x2, z2;

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
        fly = &actor->fly;

        actor->flyTime = evt_get_variable(script, *args++);

        actor->fly.currentPos.x = actor->currentPos.x;
        actor->fly.currentPos.y = actor->currentPos.y;
        actor->fly.currentPos.z = actor->currentPos.z;
        actor->fly.unk_18.x = actor->fly.goalPos.x;
        actor->fly.unk_18.y = actor->fly.goalPos.y;
        actor->fly.unk_18.z = actor->fly.goalPos.z;

        x1 = actor->fly.currentPos.x;
        z1 = actor->fly.currentPos.z;
        x2 = actor->fly.goalPos.x;
        z2 = actor->fly.goalPos.z;

        actor->fly.angle = atan2(x1, z1, x2, z2);
        actor->fly.distance = dist2D(x1, z1, x2, z2);

        if (actor->flyTime == 0) {
            actor->flyTime = actor->fly.distance / actor->fly.speed;
            if (actor->flyTime == 0) {
                actor->flyTime = 1;
            }
            actor->fly.speed += (actor->fly.distance - actor->flyTime * actor->fly.speed) / actor->flyTime;
        } else {
            actor->fly.speed = actor->fly.distance / actor->flyTime;
        }

        if (actor->actorTypeData1b[0] >= 0) {
            fly->distance = actor->actorTypeData1b[0] + 1;
        } else {
            fly->distance = ~actor->actorTypeData1b[0];
        }
        script->functionTemp[0] = TRUE;
    }

    actor = script->functionTempPtr[1];
    fly = &actor->fly;

    add_xz_vec3f_copy2(&fly->currentPos, actor->fly.speed, actor->fly.angle);
    if (actor->fly.speed < 4.0f) {
        play_movement_dust_effects(0, actor->fly.currentPos.x, actor->fly.currentPos.y, actor->fly.currentPos.z, actor->fly.angle);
    } else {
        play_movement_dust_effects(1, actor->fly.currentPos.x, actor->fly.currentPos.y, actor->fly.currentPos.z, actor->fly.angle);
    }
    actor->currentPos.x = fly->currentPos.x;
    actor->currentPos.z = fly->currentPos.z;
    actor->flyTime--;

    if (actor->flyTime > 0) {
        return ApiStatus_BLOCK;
    } else {
        actor->currentPos.x = fly->unk_18.x;
        actor->currentPos.z = fly->unk_18.z;
        if (actor->actorTypeData1[0] != 0 && actor->actorTypeData1[1] == 0) {
            snd_stop_sound(actor->actorTypeData1[0]);
        }
        return ApiStatus_DONE1;
    }
}
#else
INCLUDE_ASM(s32, "1A5830", IdleRunToGoal);
#endif

s32 JumpPartTo(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorPart* part;
    ActorPartMovement* movement;
    s32 actorID, partIndex;
    f32 x, y, z;
    f32 x1, y1, z1;
    f32 deltaDist;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        actorID = evt_get_variable(script, *args++);
        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }
        partIndex = evt_get_variable(script, *args++);

        actor = get_actor(actorID);
        part = get_actor_part(actor, partIndex);
        script->functionTempPtr[1] = actor;
        script->functionTempPtr[2] = part;
        movement = part->movement;

        x = evt_get_variable(script, *args++);
        y = evt_get_variable(script, *args++);
        z = evt_get_variable(script, *args++);
        movement->goalPos.x = x;
        movement->goalPos.y = y;
        movement->goalPos.z = z;
        movement->moveTime = evt_get_variable(script, *args++);
        script->functionTemp[3] = evt_get_variable(script, *args++);

        x1 = movement->goalPos.x;
        y1 = movement->goalPos.y;
        z1 = movement->goalPos.z;

        movement->unk_00.x = part->absolutePosition.x;
        movement->unk_00.y = part->absolutePosition.y;
        movement->unk_00.z = part->absolutePosition.z;

        x = movement->unk_00.x;
        y = movement->unk_00.y;
        z = movement->unk_00.z;

        movement->angle = atan2(x, z, x1, z1);
        movement->distance = dist2D(x, z, x1, z1);

        y = y1 - y;

        if (movement->moveTime == 0) {
            movement->moveTime = movement->distance / movement->moveSpeed;
            deltaDist = movement->distance - movement->moveTime * movement->moveSpeed;
        } else {
            movement->moveSpeed = movement->distance / movement->moveTime;
            deltaDist = movement->distance - movement->moveTime * movement->moveSpeed;
        }
        movement->moveSpeed += deltaDist / movement->moveTime;
        movement->unk_2C = movement->jumpScale * movement->moveTime * 0.5f + y / movement->moveTime;
        if (part->partTypeData[4] != 0) {
            sfx_play_sound_at_position(part->partTypeData[4], 0, part->absolutePosition.x, part->absolutePosition.y, part->absolutePosition.z);
        }
        script->functionTemp[0] = 1;
    }

    part = script->functionTempPtr[2];
    movement = part->movement;
    movement->unk_00.y += movement->unk_2C;
    movement->unk_2C -= movement->jumpScale;
    add_xz_vec3f_copy1(&movement->unk_00, movement->moveSpeed, movement->angle);
    part->absolutePosition.x = movement->unk_00.x;
    part->absolutePosition.y = movement->unk_00.y;
    part->absolutePosition.z = movement->unk_00.z;
    movement->moveTime--;

    if (movement->moveTime <= 0) {
        if (script->functionTemp[3] != 0) {
            play_movement_dust_effects(2, movement->goalPos.x, movement->goalPos.y, movement->goalPos.z, movement->angle);
        }
        part->absolutePosition.x = movement->goalPos.x;
        part->absolutePosition.y = movement->goalPos.y;
        part->absolutePosition.z = movement->goalPos.z;
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

s32 FallPartTo(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorPart* part;
    ActorPartMovement* movement;
    s32 actorID, partIndex;
    f32 x, y, z;
    f32 x1, y1, z1;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        actorID = evt_get_variable(script, *args++);
        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }
        partIndex = evt_get_variable(script, *args++);

        actor = get_actor(actorID);
        part = get_actor_part(actor, partIndex);
        script->functionTempPtr[1] = actor;
        script->functionTempPtr[2] = part;
        movement = part->movement;

        x = evt_get_variable(script, *args++);
        y = evt_get_variable(script, *args++);
        z = evt_get_variable(script, *args++);
        movement->goalPos.x = x;
        movement->goalPos.y = y;
        movement->goalPos.z = z;
        movement->moveTime = evt_get_variable(script, *args++);

        x1 = movement->goalPos.x;
        y1 = movement->goalPos.y;
        z1 = movement->goalPos.z;

        movement->unk_00.x = part->absolutePosition.x;
        movement->unk_00.y = part->absolutePosition.y;
        movement->unk_00.z = part->absolutePosition.z;

        x = movement->unk_00.x;
        y = movement->unk_00.y;
        z = movement->unk_00.z;

        movement->angle = atan2(x, z, x1, z1);
        movement->distance = dist2D(x, z, x1, z1);

        y = y1 - y;

        if (movement->moveTime == 0) {
            movement->moveTime = movement->distance / movement->moveSpeed;
        } else {
            movement->moveSpeed = movement->distance / movement->moveTime;
        }

        movement->unk_2C = 0.0f;
        movement->jumpScale = (y / movement->moveTime - movement->unk_2C) / (-movement->moveTime * 0.5);
        if (part->partTypeData[4] != 0) {
            sfx_play_sound_at_position(part->partTypeData[4], 0, part->absolutePosition.x, part->absolutePosition.y, part->absolutePosition.z);
        }
        script->functionTemp[0] = 1;
    }

    part = script->functionTempPtr[2];
    movement = part->movement;
    movement->unk_00.y += movement->unk_2C;
    movement->unk_2C -= movement->jumpScale;
    add_xz_vec3f_copy1(&movement->unk_00, movement->moveSpeed, movement->angle);
    part->absolutePosition.x = movement->unk_00.x;
    part->absolutePosition.y = movement->unk_00.y;
    part->absolutePosition.z = movement->unk_00.z;
    movement->moveTime--;

    if (movement->moveTime <= 0) {
        play_movement_dust_effects(2, movement->goalPos.x, movement->goalPos.y, movement->goalPos.z, movement->angle);
        part->absolutePosition.x = movement->goalPos.x;
        part->absolutePosition.y = movement->goalPos.y;
        part->absolutePosition.z = movement->goalPos.z;
        return ApiStatus_DONE1;
    } else {
        return ApiStatus_BLOCK;
    }
}

s32 LandJumpPart(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorPart* part;
    ActorPartMovement* movement;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        s32 actorID = evt_get_variable(script, *args++);
        s32 partIndex = evt_get_variable(script, *args++);

        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }

        actor = get_actor(actorID);
        part = get_actor_part(actor, partIndex);
        script->functionTempPtr[1] = actor;
        script->functionTempPtr[2] = part;
        movement = part->movement;
        movement->unk_00.x = part->absolutePosition.x;
        movement->unk_00.y = part->absolutePosition.y;
        movement->unk_00.z = part->absolutePosition.z;
        script->functionTemp[0] = 1;
    }

    part = script->functionTempPtr[2];
    movement = part->movement;
    movement->unk_00.y += movement->unk_2C;
    movement->unk_2C -= movement->jumpScale;
    add_xz_vec3f_copy1(&movement->unk_00, movement->moveSpeed, movement->angle);
    part->absolutePosition.x = movement->unk_00.x;
    part->absolutePosition.y = movement->unk_00.y;
    part->absolutePosition.z = movement->unk_00.z;

    if (part->absolutePosition.y < 0.0f) {
        part->absolutePosition.y = 0.0f;
        play_movement_dust_effects(2, part->absolutePosition.x, part->absolutePosition.y, part->absolutePosition.z, part->yaw);
        return ApiStatus_DONE1;
    }

    return ApiStatus_BLOCK;
}

s32 RunPartTo(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorPart* part;
    ActorPartMovement* movement;
    s32 actorID, partIndex;
    f32 x, y, z;
    f32 x1, y1, z1;
    f32 deltaDist;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        actorID = evt_get_variable(script, *args++);
        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }
        partIndex = evt_get_variable(script, *args++);

        actor = get_actor(actorID);
        part = get_actor_part(actor, partIndex);
        script->functionTempPtr[1] = actor;
        script->functionTempPtr[2] = part;
        movement = part->movement;

        x = evt_get_variable(script, *args++);
        y = evt_get_variable(script, *args++);
        z = evt_get_variable(script, *args++);
        movement->goalPos.x = x;
        movement->goalPos.y = y;
        movement->goalPos.z = z;
        movement->moveTime = evt_get_variable(script, *args++);

        x1 = movement->goalPos.x;
        y1 = movement->goalPos.y;
        z1 = movement->goalPos.z;

        movement->unk_00.x = part->absolutePosition.x;
        movement->unk_00.y = part->absolutePosition.y;
        movement->unk_00.z = part->absolutePosition.z;

        x = movement->unk_00.x;
        y = movement->unk_00.y;
        z = movement->unk_00.z;

        movement->angle = atan2(x, z, x1, z1);
        movement->distance = dist2D(x, z, x1, z1);

        if (movement->moveTime == 0) {
            movement->moveTime = movement->distance / movement->moveSpeed;
        } else {
            movement->moveSpeed = movement->distance / movement->moveTime;
        }
        if (part->actorTypeData2b[0] >= 0) {
            movement->distance = part->actorTypeData2b[0] + 1;
        } else {
            movement->distance = ~part->actorTypeData2b[0];
        }
        if (part->partTypeData[0] != 0 && part->partTypeData[1] == 0) {
            sfx_play_sound_at_position(part->partTypeData[0], 0, part->absolutePosition.x, part->absolutePosition.y, part->absolutePosition.z);
        }
        script->functionTemp[0] = 1;
    }

    part = script->functionTempPtr[2];
    movement = part->movement;
    actor = script->functionTempPtr[1];

    add_xz_vec3f_copy1(&movement->unk_00, movement->moveSpeed, movement->angle);
    if (movement->moveSpeed < 4.0f) {
        play_movement_dust_effects(0, movement->unk_00.x, movement->unk_00.y, movement->unk_00.z, movement->angle);
    } else {
        play_movement_dust_effects(1, movement->unk_00.x, movement->unk_00.y, movement->unk_00.z, movement->angle);
    }
    part->absolutePosition.x = movement->unk_00.x;
    part->absolutePosition.y = movement->unk_00.y;
    part->absolutePosition.z = movement->unk_00.z;

    if (part->partTypeData[0] != 0 && part->partTypeData[1] != 0) {
        if (part->actorTypeData2b[0] >= 0) {
            movement->distance += movement->moveSpeed;
            if (part->actorTypeData2b[0] < movement->distance) {
                actor->footStepCounter++;
                movement->distance = 0;
                if (actor->footStepCounter % 2 != 0) {
                    if (part->partTypeData[0] != 0) {
                        sfx_play_sound_at_position(part->partTypeData[0], 0, part->absolutePosition.x, part->absolutePosition.y, part->absolutePosition.z);
                    }
                } else {
                    if (part->partTypeData[1] != 0) {
                        sfx_play_sound_at_position(part->partTypeData[1], 0, part->absolutePosition.x, part->absolutePosition.y, part->absolutePosition.z);
                    }
                }
            }
        } else {
            movement->distance += 1.0f;
            if (-part->actorTypeData2b[0] <= movement->distance) {
                actor->footStepCounter++;
                movement->distance = 0;
                if (actor->footStepCounter % 2 != 0) {
                    if (part->partTypeData[0] != 0) {
                        sfx_play_sound_at_position(part->partTypeData[0], 0, part->absolutePosition.x, part->absolutePosition.y, part->absolutePosition.z);
                    }
                } else {
                    if (part->partTypeData[1] != 0) {
                        sfx_play_sound_at_position(part->partTypeData[1], 0, part->absolutePosition.x, part->absolutePosition.y, part->absolutePosition.z);
                    }
                }
            }
        }
    }

    movement->moveTime--;
    if (movement->moveTime > 0) {
        return ApiStatus_BLOCK;
    } else {
        part->absolutePosition.x = movement->goalPos.x;
        part->absolutePosition.z = movement->goalPos.z;
        if (part->partTypeData[0] != 0 && part->partTypeData[1] == 0) {
            snd_stop_sound(part->partTypeData[0]);
        }
        return ApiStatus_DONE1;
    }
}

f32 update_lerp_battle(s32 easing, f32 start, f32 end, s32 elapsed, s32 duration);
INCLUDE_ASM(s32, "1A5830", update_lerp_battle);

INCLUDE_ASM(s32, "1A5830", FlyToGoal);

INCLUDE_ASM(s32, "1A5830", IdleFlyToGoal);

#ifdef NON_MATCHING
s32 FlyPartTo(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    ActorPart* part;
    ActorPartMovement* partMovement;
    s32 actorID;
    s32 partIndex;
    f32 f2, f4;

    f32 temp_f0;
    f32 xComp;
    f32 temp_f0_2;
    f32 temp_f0_3;
    f32 yComp;
    f32 zComp;
    f32 temp_f2_4;

    if (isInitialCall) {
        actorID = evt_get_variable(script, *args++);
        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }
        partIndex = evt_get_variable(script, *args++);

        actor = get_actor(actorID);
        part = get_actor_part(actor, partIndex);
        script->functionTempPtr[1] = actor;
        script->functionTempPtr[2] = part;
        partMovement = part->movement;

        partMovement->goalPos.x = evt_get_variable(script, *args++);
        partMovement->goalPos.y = evt_get_variable(script, *args++);
        partMovement->goalPos.z = evt_get_variable(script, *args++);
        partMovement->moveTime = evt_get_variable(script, *args++);
        partMovement->unk_3A = evt_get_variable(script, *args++);
        script->functionTemp[3] = evt_get_variable(script, *args++);

        temp_f0 = part->absolutePosition.x;
        partMovement->unk_00.x = temp_f0;
        partMovement->unk_18.x = temp_f0;
        temp_f0_2 = part->absolutePosition.y;
        partMovement->unk_00.y = temp_f0_2;
        partMovement->unk_18.y = temp_f0_2;
        temp_f0_3 = part->absolutePosition.z;
        partMovement->unk_00.z = temp_f0_3;
        partMovement->unk_18.z = temp_f0_3;
        //xComp = temp_f0 - partMovement->goalPos.x;
        f2 = partMovement->goalPos.x;
        xComp = temp_f0 - f2;
        yComp = temp_f0_2 - partMovement->goalPos.y;
        zComp = temp_f0_3 - partMovement->goalPos.z;
        partMovement->distance = sqrtf(SQ(xComp) + SQ(yComp) + SQ(zComp));

        if (partMovement->moveTime == 0) {
            partMovement->moveTime = partMovement->distance / partMovement->moveSpeed;
        } else {
            partMovement->moveSpeed = partMovement->distance / partMovement->moveTime;
        }

        if (partMovement->moveTime == 0) {
            return ApiStatus_DONE2;
        }

        if (part->partTypeData[2] != 0 && part->partTypeData[3] == 0) {
            sfx_play_sound_at_position(part->partTypeData[2], 0, part->absolutePosition.x, part->absolutePosition.y, part->absolutePosition.z);
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
    partMovement->unk_00.x = update_lerp_battle(script->functionTemp[3], partMovement->unk_18.x, partMovement->goalPos.x, partMovement->unk_3C, partMovement->moveTime);
    partMovement->unk_00.y = update_lerp_battle(script->functionTemp[3], partMovement->unk_18.y, partMovement->goalPos.y, partMovement->unk_3C, partMovement->moveTime);
    partMovement->unk_00.z = update_lerp_battle(script->functionTemp[3], partMovement->unk_18.z, partMovement->goalPos.z, partMovement->unk_3C, partMovement->moveTime);
    partMovement->unk_3C++;

    if (partMovement->moveTime < partMovement->unk_3C) {
        part->absolutePosition.x = partMovement->goalPos.x;
        part->absolutePosition.y = partMovement->goalPos.y;
        part->absolutePosition.z = partMovement->goalPos.z;
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
                        sfx_play_sound_at_position(part->partTypeData[2], 0, part->absolutePosition.x, part->absolutePosition.y, part->absolutePosition.z);
                    }
                } else {
                    if (part->partTypeData[3] != 0) {
                        sfx_play_sound_at_position(part->partTypeData[3], 0, part->absolutePosition.x, part->absolutePosition.y, part->absolutePosition.z);
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
                        sfx_play_sound_at_position(part->partTypeData[2], 0, part->absolutePosition.x, part->absolutePosition.y, part->absolutePosition.z);
                    }
                } else {
                    if (part->partTypeData[3] != 0) {
                        sfx_play_sound_at_position(part->partTypeData[3], 0, part->absolutePosition.x, part->absolutePosition.y, part->absolutePosition.z);
                    }
                }
            }
        }
    }

    f2 = sqrtf(
        SQ(partMovement->goalPos.x - partMovement->unk_00.x) +
        SQ(partMovement->goalPos.y - partMovement->unk_00.y) +
        SQ(partMovement->goalPos.z - partMovement->unk_00.z)
    );

    if (f2 == 0.0f) {
        f2 = 1.0f;
    }
    if (partMovement->distance == 0.0f) {
        partMovement->distance = 1.0f;
    }

    f4 = sin_deg((1.0 - f2 / partMovement->distance) * 180.0);
    if (partMovement->unk_3A == 0) {
        f4 = 0.0f;
    }
    if (partMovement->unk_3A < 0) {
        f4 = -f4 * (-partMovement->unk_3A);
    }
    if (partMovement->unk_3A > 0) {
        f4 = f4 * partMovement->unk_3A;
    }

    part->absolutePosition.x = partMovement->unk_00.x;
    part->absolutePosition.y = partMovement->unk_00.y + f4;
    part->absolutePosition.z = partMovement->unk_00.z;
    return ApiStatus_BLOCK;
}
#else
INCLUDE_ASM(s32, "1A5830", FlyPartTo);
#endif

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

    actor->currentHP = newHP;
    if (newHP > actor->maxHP) {
        actor->currentHP = actor->maxHP;
    }

    actor->hpFraction = (actor->currentHP * 25) / actor->maxHP;

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
            outVal = actor->currentHP;
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

        if (dropper->flags & ACTOR_FLAG_HP_OFFSET_BELOW) {
            spawnMode = ITEM_SPAWN_MODE_TOSS_FADE3;
        } else {
            spawnMode = ITEM_SPAWN_MODE_TOSS_FADE1;
        }

        for (i = 0; i < numToDrop; i++) {
            make_item_entity_delayed(ITEM_STAR_POINT, dropper->currentPos.x, dropper->currentPos.y,
                                     dropper->currentPos.z, spawnMode, i, 0);
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
    s32 partIndex;
    u32* var2;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    var2 = (u32*) evt_get_variable(script, *args++);
    get_actor_part(get_actor(actorID), partIndex)->defenseTable = var2;
    return ApiStatus_DONE2;
}

ApiStatus SetStatusTable(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    u32* var1;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    var1 = (u32*) evt_get_variable(script, *args++);
    get_actor(actorID)->statusTable = var1;
    return ApiStatus_DONE2;
}

ApiStatus SetIdleAnimations(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex;
    u32* var2;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    var2 = (u32*) evt_get_variable(script, *args++);
    get_actor_part(get_actor(actorID), partIndex)->idleAnimations = var2;
    return ApiStatus_DONE2;
}

ApiStatus func_8027CC10(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);

    // weirdly unused
    evt_get_variable(script, *args++);
    evt_get_variable(script, *args++);

    get_actor_part(get_actor(actorID), partIndex);
    return ApiStatus_DONE2;
}

ApiStatus EnemyDamageTarget(Evt *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
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
    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = *args++;
    battleStatus->currentAttackStatus = *args++;
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
    battleFlagsModifier = *args++;

    if (battleFlagsModifier & 0x10) {
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

    attackStatus = battleStatus->currentAttackStatus;
    battleStatus->currentTargetID = actor->targetActorID;

    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = attackStatus;

    if ((attackStatus & 0xFF) == 0xFF) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;
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

    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;

    if (battleStatus->statusChance == 0xFF) {
        battleStatus->statusChance = 0;
    }

    anotherBattleStatus->statusDuration = (anotherBattleStatus->currentAttackStatus & 0xF00) >> 8;
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

ApiStatus EnemyTestTarget(Evt *script, s32 isInitialCall) {
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
    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = 0;
    battleStatus->currentAttackStatus = *args++;
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
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

    attackStatus = battleStatus->currentAttackStatus;
    battleStatus->currentTargetID = actor->targetActorID;

    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = attackStatus;

    if ((attackStatus & 0xFF) == 0xFF) {
        battleStatus->statusChance = 0;
    }

    battleStatus->statusDuration = (battleStatus->currentAttackStatus & 0xF00) >> 8;
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

ApiStatus func_8027D2D8(Evt* script, s32 isInitialCall) {
    s32 actorID = evt_get_variable(script, *script->ptrReadPos);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    func_80266ADC(get_actor(actorID));
    return ApiStatus_DONE2;
}

ApiStatus func_8027D32C(Evt* script, s32 isInitialCall) {
    s32 actorID = evt_get_variable(script, *script->ptrReadPos);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    func_80266AF8(get_actor(actorID));
    return ApiStatus_DONE2;
}

ApiStatus SetTargetOffset(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex;
    ActorPart* part;
    s32 x;
    s32 y;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    part = get_actor_part(get_actor(actorID), partIndex);

    x = evt_get_variable(script, *args++);
    y = evt_get_variable(script, *args++);

    part->targetOffset.x = x;
    part->targetOffset.y = y;

    return ApiStatus_DONE2;
}

ApiStatus func_8027D434(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex;
    ActorPart* part;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    part = get_actor_part(get_actor(actorID), partIndex);
    part->unk_70 = evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_8027D4C8(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 partIndex;
    ActorPart* part;
    s32 temp;
    s32 temp2;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = evt_get_variable(script, *args++);
    part = get_actor_part(get_actor(actorID), partIndex);

    temp = evt_get_variable(script, *args++);
    temp2 = evt_get_variable(script, *args++);

    part->unk_75 = temp;
    part->unk_76 = temp2;

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

ApiStatus func_8027D75C(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    s32 outVar = *args++;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    evt_set_variable(script, outVar, get_actor(actorID)->unk_208);
    return ApiStatus_DONE2;
}

ApiStatus GetEncounterState(Evt* script, s32 isInitialCall) {
    evt_set_variable(script, *script->ptrReadPos, gCurrentEncounter.hitType);
    return ApiStatus_DONE2;
}

ApiStatus YieldTurn(Evt* script, s32 isInitialCall) {
    gBattleStatus.flags1 |= BS_FLAGS1_200000;
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
    s32 partIndex = evt_get_variable(script, *args++);
    s32 sizeY = evt_get_variable(script, *args++);
    s32 sizeX = evt_get_variable(script, *args++);
    ActorPart* part;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    part = get_actor_part(get_actor(actorID), partIndex);

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
                func_802DE894(it->unk_84, 0, 0, 0, 0, 0, 0);
            }
            it = it->nextPart;
        }
        func_80266EE8(actor, 0);
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

    actorFrom->status = 0;
    actorTo->status = 0;

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

    if (actor->debuff != STATUS_END) {
        actor->debuffDuration = 0;
        actor->debuff = STATUS_END;
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
    actor->disableEffect->data.disableX->unk_3C = 0;
    actor->attackBoost = 0;
    actor->defenseBoost = 0;
    actor->isGlowing = 0;

    return ApiStatus_DONE2;
}
