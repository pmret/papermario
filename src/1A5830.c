#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"
#include "effects.h"
#include "hud_element.h"

extern s32 D_802946E0[];

void dispatch_event_actor(Actor* actor, s32 event);
void func_8024EFE0(f32 x, f32 y, f32 z, s32 a, s32 b);
void func_802664DC(f32 x, f32 y, f32 z, s32 damage);
s32 dispatch_damage_event_actor_1(Actor* actor, s32 damageAmount, s32 event);
s32 func_80263230(Actor*, Actor*);
void func_80267018(Actor* actor, s32 arg1);

s32 has_enchanted_part(Actor* actor) {
    ActorPart* partIt = actor->partsTable;
    s32 ret = FALSE;

    while (partIt != NULL) {
        if (partIt->eventFlags & 0xC0000) {
            ret = TRUE;
            break;
        } else {
            partIt = partIt->nextPart;
        }
    }

    return ret;
}

void dispatch_event_general(Actor* actor, s32 event) {
    switch (actor->actorID & 0x700) {
        case ACTOR_PLAYER:
            dispatch_event_player(event);
            break;
        case ACTOR_PARTNER:
            dispatch_event_partner(event);
            break;
        case ACTOR_ENEMY0:
            dispatch_event_actor(actor, event);
            break;
    }
}

void play_hit_sound(Actor* actor, f32 x, f32 y, f32 z, u32 hitSound) {
    s32 actorKind = actor->actorID & 0x700;

    switch (hitSound) {
        case HIT_SOUND_MISS:
            sfx_play_sound_at_position(SOUND_10C, 0, x, y, z);
            break;
        case HIT_SOUND_BONES:
            sfx_play_sound_at_position(SOUND_10D, 0, x, y, z);
            break;
        case HIT_SOUND_NORMAL:
            switch (actorKind) {
                case ACTOR_PLAYER:
                    sfx_play_sound_at_position(SOUND_E1, 0, x, y, z);
                    break;
                case ACTOR_PARTNER:
                    sfx_play_sound_at_position(SOUND_E9, 0, x, y, z);
                    break;
                case ACTOR_ENEMY0:
                    sfx_play_sound_at_position(SOUND_E9, 0, x, y, z);
                    break;
            }
            break;
        case HIT_SOUND_FIRE:
            switch (actorKind) {
                case ACTOR_PLAYER:
                    sfx_play_sound_at_position(SOUND_E2, 0, x, y, z);
                    break;
                case ACTOR_PARTNER:
                    sfx_play_sound_at_position(SOUND_EA, 0, x, y, z);
                    break;
                case ACTOR_ENEMY0:
                    sfx_play_sound_at_position(SOUND_EA, 0, x, y, z);
                    break;
            }
            break;
        case HIT_SOUND_ICE:
            switch (actorKind) {
                case ACTOR_PLAYER:
                    sfx_play_sound_at_position(SOUND_E3, 0, x, y, z);
                    break;
                case ACTOR_PARTNER:
                    sfx_play_sound_at_position(SOUND_FREEZE, 0, x, y, z);
                    break;
                case ACTOR_ENEMY0:
                    sfx_play_sound_at_position(SOUND_FREEZE, 0, x, y, z);
                    break;
            }
            break;
        case HIT_SOUND_SHOCK:
            switch (actorKind) {
                case ACTOR_PLAYER:
                    sfx_play_sound_at_position(SOUND_37A, 0, x, y, z);
                    break;
                case ACTOR_PARTNER:
                    sfx_play_sound_at_position(SOUND_37B, 0, x, y, z);
                    break;
                case ACTOR_ENEMY0:
                    sfx_play_sound_at_position(SOUND_37B, 0, x, y, z);
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
        newScript = start_script(actor->onHitScriptSource, 0xA, 0x20);
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

INCLUDE_ASM(s32, "1A5830", calc_enemy_test_target);

s32 calc_enemy_damage_target(Actor* attacker) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActorState* walk = &attacker->state;
    s32 attack = 40;
    s32 targetID;
    s32 actorMasked;
    s32 defense;
    s32 targetPartIdx;
    s32 event;
    s32 statusInflicted = FALSE;
    s32 statusInflicted2 = FALSE;
    Actor *target;
    s32 new_var;
    s32 t = TRUE;
    ActorPart* targetPart;
    s32 hitResult;
    s32 isFire = FALSE;
    s32 isElectric = FALSE;
    s32 isEnchanted = FALSE;

    targetID = battleStatus->currentTargetID;
    targetPartIdx = battleStatus->currentTargetPart;

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

    actorMasked = targetID & 0x700;
    target->lastDamageTaken = 0;

    switch (actorMasked) {
        case ACTOR_PLAYER:
            target->currentHP = gPlayerData.curHP;
            break;
        case ACTOR_PARTNER:
            target->currentHP = 127;
            break;
        case ACTOR_ENEMY0:
            break;
    }

    if ((targetPart->eventFlags & EVENT_FLAG_ILLUSORY)) {
            return HIT_RESULT_MISS;
    }

    if ((target->transStatus == STATUS_E) || (targetPart->eventFlags & EVENT_FLAG_800) && !(battleStatus->currentAttackElement & DAMAGE_TYPE_QUAKE)) {
        return HIT_RESULT_MISS;
    }

    if (target->stoneStatus == STATUS_STONE) {
        func_8024EFE0(walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, 0, 1, -1);
        show_damage_popup(walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, 0, 0);
        play_hit_sound(attacker, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, 0);
        dispatch_event_general(target, EVENT_IMMUNE);
        return HIT_RESULT_HIT;
    }
    if (battleStatus->currentAttackElement & DAMAGE_TYPE_BLAST) {
        if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT) && (targetPart->eventFlags & EVENT_FLAG_EXPLOSIVE)) {
            do { play_hit_sound(attacker, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, 3); } while (0);
            dispatch_event_general(target, EVENT_EXPLODE_TRIGGER);
            return HIT_RESULT_TRIGGERED_EXPLODE;
        }
    }
    if ((battleStatus->currentAttackElement & DAMAGE_TYPE_QUAKE) && (target->flags & ACTOR_FLAG_FLYING)) {
        play_hit_sound(attacker, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, 1);
        return HIT_RESULT_MISS_QUAKE;
    }
    if (battleStatus->currentAttackElement & DAMAGE_TYPE_FIRE) {
        playFX_24(0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z + 5.0f, 1.0f, 0x18);
        isFire = TRUE;
    }
    if (battleStatus->currentAttackElement & DAMAGE_TYPE_ELECTRIC) {
        func_80251474(target);
        isElectric = TRUE;
    }
    if (battleStatus->currentAttackElement & DAMAGE_TYPE_WATER) {
        playFX_5F(0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z + 5.0f, 1.0f, 0x18);
    }
    if (battleStatus->currentAttackElement & DAMAGE_TYPE_ICE) {
        playFX_30(0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z + 5.0f);
    }

    if (!(attacker->staticStatus == STATUS_STATIC)) {
        if ((target->staticStatus == STATUS_STATIC) || (targetPart->eventFlags & EVENT_FLAG_ELECTRIFIED)) {
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

        if (actorMasked == ACTOR_PLAYER) {
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

    attack = battleStatus->currentAttackDamage;

    switch (actorMasked) {
        case ACTOR_PLAYER:
            attack -= battleStatus->unk_AD;
            break;
        case ACTOR_PARTNER:
        case ACTOR_ENEMY0:
            break;
    }

    attack += attacker->attackBoost;

    if (attacker->chillOutTurns != 0) {
        attack -= attacker->chillOutAmount;
    }

    if (attacker->debuff == STATUS_SHRINK) {
        if (attack > 0) {
            attack /= 2;
        }
    }

    if (attack > 99) {
        attack = 99;
    }
    if (attack <= 0) {
        defense = 0;
    }

    target->hpChangeCounter = 0;
    attack = attack - defense;

    new_var = actorMasked == ACTOR_PLAYER;
    if (new_var) {
        if (player_team_is_ability_active(target, ABILITY_FIRE_SHIELD)) {
            if (battleStatus->currentAttackElement & DAMAGE_TYPE_FIRE) {
                attack--;
            }
        }

        attack -= player_team_is_ability_active(target, ABILITY_DEFEND_PLUS);
        attack -= player_team_is_ability_active(target, ABILITY_P_DOWN_D_UP);
        attack += player_team_is_ability_active(target, ABILITY_P_UP_D_DOWN);

        if (target->currentHP <= 5) {
            if (player_team_is_ability_active(target, ABILITY_LAST_STAND)) {
                attack /= 2;
            }
        }
    }

    switch (actorMasked) {
        case ACTOR_PLAYER:
            if ((target->debuff == 0 || target->debuff >= STATUS_POISON) && (target->stoneStatus == STATUS_END) && !(battleStatus->currentAttackElement & DAMAGE_TYPE_2000000)) {
                s32 blocked;

                if (player_team_is_ability_active(target, ABILITY_BERSERKER)) {
                    blocked = rand_int(1);
                } else {
                    blocked = check_block_input(BUTTON_A);
                }

                if (blocked) {
                    attack--;
                    attack = attack - player_team_is_ability_active(target, ABILITY_DAMAGE_DODGE);
                    sfx_play_sound_at_position(SOUND_UNKNOWN_231, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
                    func_802667F0(0, target, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
                    gBattleStatus.flags1 |= BS_FLAGS1_ATK_BLOCKED;
                    break;
                }
                func_80266970(target);
            }
            break;
        case ACTOR_PARTNER:
            if ((target->stoneStatus == STATUS_END)) {
                if ((target->koStatus == STATUS_END) && !(battleStatus->currentAttackElement & DAMAGE_TYPE_2000000)) {
                    if (check_block_input(BUTTON_A)) {
                        attack = 0;
                        sfx_play_sound_at_position(SOUND_UNKNOWN_231, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
                        func_802667F0(0, target, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
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
    if (attack <= 0) {
        target->hpChangeCounter = 0;
        if (!(battleStatus->currentAttackElement & DAMAGE_TYPE_40000000)) {
            hitResult = HIT_RESULT_MISS_QUAKE;
            event = EVENT_23;
        } else {
            hitResult = HIT_RESULT_MISS_QUAKE;
            event = EVENT_23;
            if (target->currentHP <= 0) {
                event = EVENT_DEATH;
            }
        }
        battleStatus->lastAttackDamage = 0;
    } else {
        target->damageCounter += attack;
        target->hpChangeCounter -= attack;
        battleStatus->lastAttackDamage = 0;
        hitResult = HIT_RESULT_HIT;
        if (!(targetPart->flags & PART_FLAG_2000)) {
            if (!(gBattleStatus.flags1 & BS_FLAGS1_2000000)) {
                if (!(target->flags & ACTOR_FLAG_NO_DMG_APPLY)) {
                    target->currentHP -= attack;
                }

                if (target->currentHP <= 0) {
                    target->currentHP = 0;
                    event = EVENT_DEATH;
                }
            }
        }
        battleStatus->lastAttackDamage += attack;
        target->lastDamageTaken = battleStatus->lastAttackDamage;
        target->hpChangeCounter = 0;

        if (actorMasked == ACTOR_PLAYER) {
            battleStatus->damageTaken += attack;
            gPlayerData.curHP = target->currentHP;
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (event == EVENT_HIT_COMBO) {
            event = EVENT_HIT;
        }
        if (event == EVENT_23) {
            event = EVENT_IMMUNE;
        }
        if (target->currentHP <= 0) {
            if (event == EVENT_IMMUNE) {
                event = EVENT_DEATH;
            }
        }
    } else {
        if (event == EVENT_DEATH) {
            event = EVENT_HIT_COMBO;
        }
    }

    if (!(gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE)) {
        func_80266E14(targetPart);
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) {
        if (battleStatus->currentAttackElement & (DAMAGE_TYPE_POW | DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_JUMP)) {
            if (targetPart->eventFlags & EVENT_FLAG_FLIPABLE) {
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
            if (targetPart->eventFlags & EVENT_FLAG_FLIPABLE) {
                if (event == EVENT_HIT_COMBO) {
                    event = EVENT_FLIP_TRIGGER;
                }
                if (event == EVENT_23) {
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
                event = EVENT_41;
            }
            isFire = TRUE;
        }
    }

    if (gBattleStatus.flags1 & BS_FLAGS1_ATK_BLOCKED) {
        if (event == EVENT_HIT_COMBO) {
            event = EVENT_24;
        }
        if (event == EVENT_HIT) {
            event = EVENT_BLOCK;
        }
        if (event == EVENT_23) {
            event = EVENT_24;
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
                        if (actorMasked != ACTOR_PLAYER || !is_ability_active(ABILITY_HEALTHY_HEALTHY) || !(rand_int(100) < 50)) {
                            if ((battleStatus->currentAttackStatus & STATUS_FLAG_SHRINK) && try_inflict_status(target, STATUS_SHRINK, STATUS_SHRINK_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }
                            if ((battleStatus->currentAttackStatus & STATUS_FLAG_POISON) && try_inflict_status(target, STATUS_POISON, STATUS_POISON_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }
                            if ((battleStatus->currentAttackStatus & STATUS_FLAG_STONE) && try_inflict_status(target, STATUS_STONE, STATUS_STONE_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }
                            if ((battleStatus->currentAttackStatus & STATUS_FLAG_SLEEP) && try_inflict_status(target, STATUS_SLEEP, STATUS_SLEEP_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }
                            if ((battleStatus->currentAttackStatus & STATUS_FLAG_DIZZY) && try_inflict_status(target, STATUS_DIZZY, STATUS_DIZZY_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }
                            if ((battleStatus->currentAttackStatus & STATUS_FLAG_STOP) && try_inflict_status(target, STATUS_STOP, STATUS_STOP_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }
                            if ((battleStatus->currentAttackStatus & STATUS_FLAG_STATIC) && try_inflict_status(target, STATUS_STATIC, STATUS_STATIC_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }
                            if ((battleStatus->currentAttackStatus & STATUS_FLAG_PARALYZE) && try_inflict_status(target, STATUS_PARALYZE, STATUS_PARALYZE_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }
                            if ((battleStatus->currentAttackStatus & STATUS_FLAG_FEAR) && try_inflict_status(target, STATUS_FEAR, STATUS_FEAR_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }

                            // BUG? repeated paralyse and dizzy infliction
                            if ((battleStatus->currentAttackStatus & STATUS_FLAG_PARALYZE) && try_inflict_status(target, STATUS_PARALYZE, STATUS_PARALYZE_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }
                            if ((battleStatus->currentAttackStatus & STATUS_FLAG_DIZZY) && try_inflict_status(target, STATUS_DIZZY, STATUS_DIZZY_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }

                            if ((battleStatus->currentAttackStatus & STATUS_FLAG_FROZEN) && target->debuff != STATUS_FROZEN && try_inflict_status(target, STATUS_FROZEN, STATUS_FROZEN_TURN_MOD)) {
                                statusInflicted = t;
                                statusInflicted2 = t;
                            }

                            if (statusInflicted) {
                                if (event == EVENT_23) {
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

    switch (actorMasked) {
        case ACTOR_PLAYER:
            dispatch_event_player(event);
            break;
        case ACTOR_PARTNER:
            dispatch_event_partner(event);
            break;
        case ACTOR_ENEMY0:
            dispatch_event_actor(target, event);
            break;
    }

    if (actorMasked == ACTOR_PARTNER) {
        if (battleStatus->lastAttackDamage > 0 && (gBattleStatus.flags1 & BS_FLAGS1_SP_EVT_ACTIVE) && !(target->flags & ACTOR_FLAG_NO_DMG_APPLY)) {
            inflict_partner_ko(target, STATUS_DAZE, battleStatus->lastAttackDamage);
        }
    }
    if (!(target->flags & ACTOR_FLAG_NO_DMG_POPUP)) {
        switch (actorMasked) {
            case ACTOR_PLAYER:
            case ACTOR_PARTNER:
                if (battleStatus->lastAttackDamage == 0) {
                    if (!statusInflicted2 && !statusInflicted) {
                        // immune star fx?
                        func_8024EFE0(walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, 0, 1, -3);
                    }
                } else {
                    if (battleStatus->currentAttackElement & (DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_SMASH)) {
                        show_damage_popup(walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, battleStatus->lastAttackDamage, 1);
                        func_802666E4(target, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, battleStatus->lastAttackDamage);
                    } else {
                        func_802664DC(walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, battleStatus->lastAttackDamage, 1);
                        func_802666E4(target, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, battleStatus->lastAttackDamage);
                    }
                    break;
                }
                break;

            case ACTOR_ENEMY0:
                if (battleStatus->lastAttackDamage == 0) {
                    if (!statusInflicted2 && !statusInflicted) {
                        func_8024EFE0(walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, 0, 1, 3);
                    }
                } else {
                    if (battleStatus->currentAttackElement & (DAMAGE_TYPE_UNBLOCKABLE | DAMAGE_TYPE_SMASH)) {
                        show_damage_popup(walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, battleStatus->lastAttackDamage, 0);
                        func_802666E4(target, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, battleStatus->lastAttackDamage);
                    } else {
                        func_802664DC(walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, battleStatus->lastAttackDamage, 0);
                        func_802666E4(target, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, battleStatus->lastAttackDamage);
                    }
                }
                break;
        }
    }

    if (battleStatus->lastAttackDamage > 0) {
        u32 hitSound;

        func_80267018(target, 1);

        if (attacker->actorTypeData1[5] != SOUND_UNKNOWN_0) {
            sfx_play_sound_at_position(attacker->actorTypeData1[5], 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
        }

        hitSound = HIT_SOUND_FIRE;
        if (isFire == FALSE) {
            hitSound = HIT_SOUND_SHOCK;
            if (isElectric == FALSE) {
                hitSound = HIT_SOUND_NORMAL;
            }
        }
        play_hit_sound(target, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, hitSound);
    }

    if (((battleStatus->lastAttackDamage <= 0) && !statusInflicted2 && !isEnchanted) || (targetPart->flags & PART_FLAG_2000)) {
            sfx_play_sound_at_position(SOUND_10C, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
    }

    if ((battleStatus->currentAttackStatus & STATUS_FLAG_SLEEP) && statusInflicted) {
        Evt* script = start_script(&DoSleepHit, 10, 0);
        script->varTable[0] = walk->goalPos.x;
        script->varTable[1] = walk->goalPos.y;
        script->varTable[2] = walk->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_SLEEP, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
    }
    if ((battleStatus->currentAttackStatus & STATUS_FLAG_DIZZY) && statusInflicted) {
        Evt* script = start_script(&DoDizzyHit, 10, 0);
        script->varTable[0] = walk->goalPos.x;
        script->varTable[1] = walk->goalPos.y;
        script->varTable[2] = walk->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
    }
    if ((battleStatus->currentAttackStatus & STATUS_FLAG_PARALYZE) && statusInflicted) {
        Evt* script = start_script(&DoParalyzeHit, 10, 0);
        script->varTable[0] = walk->goalPos.x;
        script->varTable[1] = walk->goalPos.y;
        script->varTable[2] = walk->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
    }
    if ((battleStatus->currentAttackStatus & STATUS_FLAG_POISON) && statusInflicted) {
        Evt* script = start_script(&DoPoisonHit, 10, 0);
        script->varTable[0] = walk->goalPos.x;
        script->varTable[1] = walk->goalPos.y;
        script->varTable[2] = walk->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
    }
    if ((battleStatus->currentAttackStatus & STATUS_FLAG_STOP) && statusInflicted) {
        Evt* script = start_script(&DoStopHit, 10, 0);
        script->varTable[0] = walk->goalPos.x;
        script->varTable[1] = walk->goalPos.y;
        script->varTable[2] = walk->goalPos.z;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
    }
    if ((battleStatus->currentAttackStatus & STATUS_FLAG_FROZEN) && statusInflicted) {
        Evt* script = start_script(&DoFreezeHit, 10, 0);
        script->varTable[0] = walk->goalPos.x;
        script->varTable[1] = walk->goalPos.y;
        script->varTable[2] = walk->goalPos.z;
        script->varTable[3] = (s32) target;
        sfx_play_sound_at_position(SOUND_FREEZE, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
    }
    if ((battleStatus->currentAttackStatus & STATUS_FLAG_SHRINK) && statusInflicted) {
        Evt* script = start_script(&DoShrinkHit, 10, 0);
        script->varTable[0] = walk->goalPos.x;
        script->varTable[1] = walk->goalPos.y;
        script->varTable[2] = walk->goalPos.z;
        script->varTable[3] = (s32) target;
        sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
    }

    if ((battleStatus->currentAttackElement & DAMAGE_TYPE_SMASH) && target->actorType == ACTOR_TYPE_GOOMNUT_TREE) {
        sfx_play_sound_at_position(SOUND_SMASH_GOOMNUT_TREE, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
    }

    func_80266ADC(target);
    if ((
            attacker->staticStatus != STATUS_STATIC
            && (target->staticStatus == STATUS_STATIC || (targetPart->eventFlags & EVENT_FLAG_ELECTRIFIED))
        )
        && !(battleStatus->currentAttackElement & DAMAGE_TYPE_NO_CONTACT)
        && !(battleStatus->currentAttackEventSuppression & 8)
        && (attacker->transStatus != STATUS_E)
        && !has_enchanted_part(attacker)
    ) {
        // enum mismatch? shock vs explode :raised_eyebrow:
        sfx_play_sound_at_position(SOUND_37B, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
        func_80251474(attacker);
        dispatch_damage_event_actor_1(attacker, 1, EVENT_SHOCK_HIT);
        return HIT_RESULT_TRIGGERED_EXPLODE;
    }

    return hitResult;
}

// part before the first conditional needs work
#ifdef NON_MATCHING
s32 dispatch_damage_event_actor(Actor* actor, s32 damageAmount, s32 originalEvent, s32 stopMotion) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActorMovementWalk* walk;
    s32 dispatchEvent;

    u16 temp_v1;

    battleStatus->currentAttackDamage = damageAmount;
    temp_v1 = actor->hpChangeCounter + battleStatus->currentAttackDamage;
    actor->hpChangeCounter += temp_v1;
    actor->damageCounter += temp_v1;
    battleStatus->lastAttackDamage = 0;
    actor->hpChangeCounter -= temp_v1;
    actor->currentHP -= temp_v1;

    dispatchEvent = originalEvent;

    walk = &actor->walk;
    if (actor->currentHP <= 0) {
        battleStatus->lastAttackDamage += actor->currentHP;
        actor->currentHP = 0;
        dispatchEvent = EVENT_DEATH;
    }

    battleStatus->lastAttackDamage += temp_v1;
    actor->lastDamageTaken = battleStatus->lastAttackDamage;
    battleStatus->unk_19A = 0;

    if (battleStatus->flags1 & 0x20) {
        if (dispatchEvent == EVENT_HIT_COMBO) {
            dispatchEvent = EVENT_HIT;
        }
        if (dispatchEvent == EVENT_23) {
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
        s32 targetActorID = actor->targetActorID; // why?

        if (func_80263230(actor, actor) != 0) {
            show_damage_popup(actor->targetData[0].pos.x, actor->targetData[0].pos.y, actor->targetData[0].pos.z,
                              battleStatus->lastAttackDamage, 0);
            func_802666E4(actor, actor->targetData[0].pos.x, actor->targetData[0].pos.y, actor->targetData[0].pos.z,
                          battleStatus->lastAttackDamage);
            actor->targetActorID = targetActorID;
        } else {
            actor->targetActorID = targetActorID;
        }
    } else {
        show_damage_popup(walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, battleStatus->lastAttackDamage, 0);
        func_802666E4(actor, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, battleStatus->lastAttackDamage);
    }

    if (battleStatus->lastAttackDamage > 0) {
        func_80267018(actor, 1);
    }
    actor->flags |= ACTOR_FLAG_80000;
    dispatch_event_actor(actor, dispatchEvent);
    return 0;
}
#else
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
    EvtSource* takeTurnScript;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    takeTurnScript = (EvtSource*) evt_get_variable(script, *args++);
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
    EvtSource* idleCode;
    Actor* actor;
    Evt* newScriptContext;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    idleCode = (EvtSource*) evt_get_variable(script, *args++);
    actor = get_actor(actorID);

    if (actor->idleScript != 0) {
        kill_script_by_ID(actor->idleScriptID);
        actor->idleScript = 0;
    }

    actor->idleScriptSource = idleCode;
    newScriptContext = start_script(idleCode, 10, 0);
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
    EvtSource* var1;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    var1 = (EvtSource*) evt_get_variable(script, *args++);
    get_actor(actorID)->onHitScriptSource = var1;
    return ApiStatus_DONE2;
}

ApiStatus BindNextTurn(Evt* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    EvtSource* var1;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    var1 = (EvtSource*) evt_get_variable(script, *args++);
    get_actor(actorID)->onTurnChanceScriptSource = var1;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "1A5830", JumpToGoal);

INCLUDE_ASM(s32, "1A5830", IdleJumpToGoal);

INCLUDE_ASM(s32, "1A5830", JumpToGoalSimple2);

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
        script->functionTemp[1] = (s32)actor;
        actor->state.currentPos.x = actor->currentPos.x;
        actor->state.currentPos.y = actor->currentPos.y;
        actor->state.currentPos.z = actor->currentPos.z;
        script->functionTemp[0] = 1;
    }

    actor = (Actor*)script->functionTemp[1];
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

INCLUDE_ASM(s32, "1A5830", FallToGoal);

INCLUDE_ASM(s32, "1A5830", RunToGoal);

INCLUDE_ASM(s32, "1A5830", IdleRunToGoal);

INCLUDE_ASM(s32, "1A5830", JumpPartTo);

INCLUDE_ASM(s32, "1A5830", FallPartTo);

INCLUDE_ASM(s32, "1A5830", LandJumpPart);

INCLUDE_ASM(s32, "1A5830", RunPartTo);

INCLUDE_ASM(s32, "1A5830", update_lerp_battle);

INCLUDE_ASM(s32, "1A5830", FlyToGoal);

INCLUDE_ASM(s32, "1A5830", IdleFlyToGoal);

INCLUDE_ASM(s32, "1A5830", FlyPartTo);

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

    switch (actorID & 0x700) {
        case ACTOR_PLAYER:
            outVal = playerData->curHP;
            break;
        case ACTOR_PARTNER:
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

// battlestatus shtuff
#ifdef NON_MATCHING
ApiStatus RemoveActor(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    Bytecode* args = script->ptrReadPos;
    s32 actorID = evt_get_variable(script, *args++);
    Actor* actor;
    s32 i;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);

    for (i = 0; i < battleStatus->numEnemyActors; i++) {
        if (actor == battleStatus->enemyActors[(u8)battleStatus->enemyIDs[i]]) {
            battleStatus->enemyIDs[i] = -1;
        }
    }

    currentEncounter->coinsEarned += actor->extraCoinBonus;
    currentEncounter->coinsEarned += actor->staticActorData->coinReward;
    btl_delete_actor(actor);
    battleStatus->enemyActors[(u8)actorID] = NULL;

    return ApiStatus_DONE2;
}
#else
INCLUDE_ASM(s32, "1A5830", RemoveActor);
#endif

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

    enemyLevel = dropper->staticActorData->level;
    if (dropper->staticActorData->level == 0.0f) {
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
            spawnMode = ITEM_SPAWN_MODE_UNKNOWN_19;
        } else {
            spawnMode = ITEM_SPAWN_MODE_UNKNOWN_17;
        }

        for (i = 0; i < numToDrop; i++) {
            make_item_entity_delayed(ITEM_STAR_POINT, dropper->currentPos.x, dropper->currentPos.y,
                                     dropper->currentPos.z, spawnMode, i, 0);
        }

        battleStatus->incrementStarPointDelay = 40;
        battleStatus->pendingStarPoints += numToDrop;
    }

    gBattleStatus.flags1 |= 0x1000000;
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
        gBattleStatus.flags1 |= 0x10;
        gBattleStatus.flags1 &= ~0x20;
    } else if (battleFlagsModifier & 0x20) {
        gBattleStatus.flags1 &= ~0x10;
        gBattleStatus.flags1 |= 0x20;
    } else {
        gBattleStatus.flags1 &= ~0x10;
        gBattleStatus.flags1 &= ~0x20;
    }

    if (battleFlagsModifier & 0x40) {
        gBattleStatus.flags1 |= 0x40;
    } else {
        gBattleStatus.flags1 &= ~0x40;
    }
    if (battleFlagsModifier & 0x200) {
        gBattleStatus.flags1 |= 0x200;
    } else {
        gBattleStatus.flags1 &= ~0x200;
    }
    if (battleFlagsModifier & 0x80) {
        gBattleStatus.flags1 |= 0x80;
    } else {
        gBattleStatus.flags1 &= ~0x80;
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

    if (battleFlagsModifier & 0x10) {
        gBattleStatus.flags1 |= 0x10;
        gBattleStatus.flags1 &= ~0x20;
    } else if (battleFlagsModifier & 0x20) {
        gBattleStatus.flags1 &= ~0x10;
        gBattleStatus.flags1 |= 0x20;
    } else {
        gBattleStatus.flags1 &= ~0x10;
        gBattleStatus.flags1 &= ~0x20;
    }

    if (battleFlagsModifier & 0x40) {
        gBattleStatus.flags1 |= 0x40;
    } else {
        gBattleStatus.flags1 &= ~0x40;
    }
    if (battleFlagsModifier & 0x200) {
        gBattleStatus.flags1 |= 0x200;
    } else {
        gBattleStatus.flags1 &= ~0x200;
    }
    if (battleFlagsModifier & 0x80) {
        gBattleStatus.flags1 |= 0x80;
    } else {
        gBattleStatus.flags1 &= ~0x80;
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
    gBattleStatus.flags1 |= 0x200000;
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

    if (y != EVT_LIMIT) {
        actor->size.y = y;
    }
    if (x != EVT_LIMIT) {
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

    if (sizeY != EVT_LIMIT) {
        part->size.y = sizeY;
    }

    if (sizeX != EVT_LIMIT) {
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

    evt_set_variable(script, outVar, get_actor(actorID)->staticActorData->type);
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
    inflict_status(actorTo, actorFrom->transStatus, actorFrom->transDuration);

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

    if (actor->transStatus != 0) {
        actor->transDuration = 0;
        actor->transStatus = 0;
        remove_status_transparent(actor->hudElementDataIndex);
    }

    if (actor->stoneStatus != 0) {
        actor->stoneDuration = 0;
        actor->stoneStatus = 0;
    }

    actor->koStatus = 0;
    actor->koDuration = 0;
    actor->ptrDefuffIcon->ptrPropertyList[15] = 0;
    actor->attackBoost = 0;
    actor->defenseBoost = 0;
    actor->isGlowing = 0;

    return ApiStatus_DONE2;
}
