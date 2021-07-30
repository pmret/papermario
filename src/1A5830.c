#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

void dispatch_event_actor(Actor* actor, Event event);
void func_8024EFE0(f32 x, f32 y, f32 z, s32 a, s32 b);
void func_802664DC(f32 x, f32 y, f32 z, s32 damage);
s32 dispatch_damage_event_actor_1(Actor* actor, s32 damageAmount, s32 event);

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

void dispatch_event_general(Actor* actor, Event event) {
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
    s32 actorType = actor->actorID & 0x700;

    switch (hitSound) {
        case 0:
            sfx_play_sound_at_position(SOUND_10C, 0, x, y, z);
            break;
        case 1:
            sfx_play_sound_at_position(SOUND_10D, 0, x, y, z);
            break;
        case 2:
            switch (actorType) {
                case 0:
                    sfx_play_sound_at_position(SOUND_E1, 0, x, y, z);
                    break;
                case 0x100:
                    sfx_play_sound_at_position(SOUND_E9, 0, x, y, z);
                    break;
                case 0x200:
                    sfx_play_sound_at_position(SOUND_E9, 0, x, y, z);
                    break;
            }
            break;
        case 3:
            switch (actorType) {
                case 0:
                    sfx_play_sound_at_position(SOUND_E2, 0, x, y, z);
                    break;
                case 0x100:
                    sfx_play_sound_at_position(SOUND_EA, 0, x, y, z);
                    break;
                case 0x200:
                    sfx_play_sound_at_position(SOUND_EA, 0, x, y, z);
                    break;
            }
            break;
        case 4:
            switch (actorType) {
                case 0:
                    sfx_play_sound_at_position(SOUND_E3, 0, x, y, z);
                    break;
                case 0x100:
                    sfx_play_sound_at_position(SOUND_FREEZE, 0, x, y, z);
                    break;
                case 0x200:
                    sfx_play_sound_at_position(SOUND_FREEZE, 0, x, y, z);
                    break;
            }
            break;
        case 5:
            switch (actorType) {
                case 0:
                    sfx_play_sound_at_position(SOUND_37A, 0, x, y, z);
                    break;
                case 0x100:
                    sfx_play_sound_at_position(SOUND_37B, 0, x, y, z);
                    break;
                case 0x200:
                    sfx_play_sound_at_position(SOUND_37B, 0, x, y, z);
                    break;
            }
            break;
    }
}

void dispatch_event_actor(Actor* actor, Event event) {
    ScriptInstance* onHitScript = actor->onHitScript;
    ScriptID onHitID = actor->onHitID;

    if (actor->onHitScriptSource != NULL) {
        ScriptInstance* newScript;

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

//INCLUDE_ASM(s32, "1A5830", calc_enemy_damage_target);
s32 calc_enemy_damage_target(Actor* attacker) {
    Actor *temp_ret;
    Actor *target;
    ScriptInstance *temp_v0_10;
    ScriptInstance *temp_v0_11;
    ScriptInstance *temp_v0_5;
    ScriptInstance *temp_v0_6;
    ScriptInstance *temp_v0_7;
    ScriptInstance *temp_v0_8;
    ScriptInstance *temp_v0_9;
    s16 temp_a2;
    s16 temp_a3;
    s16 temp_a3_2;
    s16 attack;
    s16 temp_v0_4;
    s32 eventFlags;
    s32 temp_a0_2;
    s32 temp_s0_3;
    s32 temp_s0_4;
    s32 temp_s0_5;
    s32 temp_s0_6;
    s32 targetID;
    s32 defense;
    s32 temp_v1;
    s32 attackElement;
    s32 temp_v1_3;
    s8 targetPartIdx;
    s8 temp_v0_3;
    u32 temp_s0_7;
    ActorMovementWalk* walk;
    s32 phi_a0;
    s32 phi_s0;
    s32 phi_v0;
    s32 phi_s0_2;
    s32 phi_s0_3;
    s32 phi_v0_2;
    s32 phi_s0_4;
    s32 phi_s2;
    s8 phi_s5;
    s8 phi_s5_2;
    s8 phi_s7;
    s32 isFire = FALSE;
    s32 isElectric = FALSE;
    s32 isEnchanted = FALSE;
    s32 phi_return;
    s16 phi_s0_5;
    s32 phi_s0_6;
    s32 phi_a0_2;
    s32 damage;
    s32 phi_a0_3;
    ActorPart* targetPart;
    s32 hitResult = HIT_RESULT_HIT; // ?

    targetID = gBattleStatus.currentTargetID;
    targetPartIdx = (s8) gBattleStatus.currentTargetPart;
    gBattleStatus.wasStatusInflicted = 0;
    gBattleStatus.lastAttackDamage = 0;
    walk = &attacker->walk;
    gBattleStatus.currentTargetID2 = targetID;
    gBattleStatus.currentTargetPart2 = (u8) targetPartIdx;
    gBattleStatus.attackerActorID = attacker->actorID;

    target = get_actor(targetID);
    if (target == NULL) {
        return HIT_RESULT_HIT;
    }

    targetPart = get_actor_part(target, targetPartIdx);
    ASSERT(targetPart != NULL);

    targetID &= 0x700;
    target->lastDamageTaken = 0;

    /*
    if (targetID != ACTOR_PARTNER) {
        if (targetID < 0x101 && targetID == 0) {
            target->currentHP = (s8) (u8) gPlayerData.curHP;
        }
    } else {
        target->currentHP = 127;
    }
    */
    switch (targetID) {
        case ACTOR_PARTNER:
            target->currentHP = 127;
            break;
        default:
            break;
        case ACTOR_PLAYER:
            target->currentHP = gPlayerData.curHP;
            break;
    }

    eventFlags = targetPart->eventFlags;
    phi_return = 6;
    if ((eventFlags & 0x20) == 0) {
        if (target->transStatus == 0xE) {
            return HIT_RESULT_MISS;
        }
        if (((eventFlags & 0x800) != 0) && ((gBattleStatus.currentAttackElement & 0x800) == 0)) {
            return HIT_RESULT_MISS;
        }
        if (target->stoneStatus == STATUS_STONE) {
            func_8024EFE0(walk->goalPos.x, walk->goalPos.y, /*eventFlags,*/ walk->goalPos.z, /*0,*/ 1, -1);
            show_damage_popup(walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, 0, 0);
            play_hit_sound(attacker, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, 0);
            dispatch_event_general(target, EVENT_IMMUNE);
            return HIT_RESULT_HIT;
        }
        temp_v1 = gBattleStatus.currentAttackElement;
        if (((temp_v1 & DAMAGE_TYPE_BLAST) != 0) && !(temp_v1 & DAMAGE_TYPE_NO_CONTACT) && (targetPart->eventFlags & EVENT_FLAG_EXPLOSIVE)) {
            play_hit_sound(attacker, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, 3);
            dispatch_event_general(target, EVENT_EXPLODE_TRIGGER);
            return HIT_RESULT_TRIGGERED_EXPLODE;
        }
        if ((gBattleStatus.currentAttackElement & DAMAGE_TYPE_QUAKE) && (target->flags & ACTOR_FLAG_FLYING)) {
            play_hit_sound(attacker, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, 1);
            return HIT_RESULT_MISS_QUAKE;
        }
        if (gBattleStatus.currentAttackElement & DAMAGE_TYPE_FIRE) {
            isFire = TRUE;
            playFX_24(0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z + 5.0f, 1.0f, 0x18);
        }
        if (gBattleStatus.currentAttackElement & DAMAGE_TYPE_ELECTRIC) {
            func_80251474(target);
            isElectric = TRUE;
        }
        if (gBattleStatus.currentAttackElement & DAMAGE_TYPE_WATER) {
            playFX_5F(0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z + 5.0f, 1.0f, 0x18);
        }
        if (gBattleStatus.currentAttackElement & DAMAGE_TYPE_ICE) {
            playFX_30(0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z + 5.0f);
        }

        /*
        // TODO: if/else ordering
        if (attacker->staticStatus == STATUS_STATIC) {
            phi_a0 = 0x7FFFFFFF;
        } else if (target->staticStatus != STATUS_STATIC) {
            if (!(targetPart->eventFlags & EVENT_FLAG_ELECTRIFIED)) {
            } else if (!(gBattleStatus.currentAttackElement & 0x10000020)) {
                if (!(gBattleStatus.currentAttackEventSuppression & 8)) {
                    if (!has_enchanted_part(attacker)) {
                        gBattleStatus.flags1 |= 0x20;
                    }
                }
            }
        }
        */
       block_38:
        if ((gBattleStatus.currentAttackElement & 0x10000020) == 0) {
            phi_a0 = 0x7FFFFFFF;
            if ((gBattleStatus.currentAttackEventSuppression & 8) == 0) {
                if (has_enchanted_part(attacker) == 0) {
                    isEnchanted = TRUE;
                    gBattleStatus.flags1 |= 0x20;
                }
                goto block_42;
            }
        } else {
block_42:
            phi_a0 = 0x7FFF0000 | 0xFFFF;
        }

        gBattleStatus.flags1 &= phi_a0;

        defense = get_defense(target, targetPart->defenseTable, gBattleStatus.currentAttackElement);
        attackElement = gBattleStatus.currentAttackElement;

        if (!(attackElement & DAMAGE_TYPE_IGNORE_DEFENSE)) {
            defense += target->defenseBoost;

            if (targetID == ACTOR_PLAYER) {
                if (gBattleStatus.waterBlockTurnsLeft > 0) {
                    if (!(attackElement & (DAMAGE_TYPE_BLAST | DAMAGE_TYPE_FIRE))) {
                        defense += 1;
                    } else {
                        defense += 2;
                    }
                }

                if (gBattleStatus.flags1 & 0x400000) {
                    defense += 1;
                }
            }
        }

        attack = gBattleStatus.currentAttackDamage;

        switch (targetID) {
            case ACTOR_PARTNER:
                break;
            default:
                break;
            case ACTOR_PLAYER:
                attack -= gBattleStatus.unk_AD;
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
            attack = 0;
        }

        target->hpChangeCounter = 0;
        damage = attack - defense;

        if (targetID == ACTOR_PLAYER) {
            if (player_team_is_ability_active(target, ABILITY_FIRE_SHIELD)) {
                if (gBattleStatus.currentAttackElement & DAMAGE_TYPE_FIRE) {
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

        switch (targetID) {
            case ACTOR_PARTNER:
                if ((target->stoneStatus == 0) && (target->koStatus == 0) && ((gBattleStatus.currentAttackElement & 0x2000000) == 0)) {
                    if (check_block_input(BUTTON_A)) {
                        damage = 0;
                        sfx_play_sound_at_position(0x231, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
                        func_802667F0(0, target, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
                        gBattleStatus.flags1 |= 0x80000000;
                    }

                    func_80266970(target);
                }
                break;
            default:
                break;
            case ACTOR_PLAYER:
                if ((target->debuff == 0 || target->debuff >= STATUS_POISON) && (target->stoneStatus == 0) && ((gBattleStatus.currentAttackElement & 0x2000000) == 0)) {
                    s32 blocked;

                    if (player_team_is_ability_active(target, ABILITY_BERSERKER)) {
                        blocked = rand_int(1);
                    } else {
                        blocked = check_block_input(BUTTON_A);
                    }

                    if (blocked) {
                        damage = damage - 1 - player_team_is_ability_active(target, ABILITY_DAMAGE_DODGE);
                        sfx_play_sound_at_position(0x231, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
                        func_802667F0(0, target, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
                        gBattleStatus.flags1 |= 0x80000000;
                    } else {
                        func_80266970(target);
                    }
                }
                break;
        }

        if (gBattleStatus.flags1 & 0x20) {
            func_80266970(target);
        }

        if (damage <= 0) {
            target->hpChangeCounter = 0;
            if ((gBattleStatus.currentAttackElement & 0x40000000) == 0) {
                hitResult = HIT_RESULT_MISS_QUAKE;
                phi_s2 = 0x17;
            } else {
                hitResult = HIT_RESULT_MISS_QUAKE;
                phi_s2 = 0x17;
                if (target->currentHP <= 0) {
                    phi_s2 = EVENT_DEATH;
                }
            }
            gBattleStatus.lastAttackDamage = 0;
        } else {
            target->damageCounter += damage;
            target->hpChangeCounter -= damage;
            gBattleStatus.lastAttackDamage = 0;
            hitResult = HIT_RESULT_HIT; //phi_s2 = 9;
            if (!(targetPart->flags & PART_FLAG_2000)) {
                if (!(gBattleStatus.flags1 & 0x2000000)) {
                    if (!(target->flags & ACTOR_FLAG_NO_DMG_APPLY)) {
                        target->currentHP -= damage;
                    }

                    if (target->currentHP <= 0) {
                        target->currentHP = 0;
                        phi_s2 = EVENT_DEATH;
                    }
                }
            }
            gBattleStatus.lastAttackDamage += damage;
            target->lastDamageTaken = gBattleStatus.lastAttackDamage;
            target->hpChangeCounter = 0;

            if (targetID == ACTOR_PLAYER) {
                gBattleStatus.damageTaken += damage;
                gPlayerData.curHP = target->currentHP;
            }
        }

        if ((gBattleStatus.flags1 & 0x20) != 0) {
            if (phi_s2 == 9) {
                phi_s2 = 0xA;
            }
            if (phi_s2 == 0x17) {
                phi_s2 = 0x19;
            }
            if (target->currentHP <= 0) {
                if (phi_s2 == 0x19) {
                    phi_s2 = 0x20;
                }
            }
        } else {
            if (phi_s2 == 0x20) {
                phi_s2 = 9;
            }
        }
        if ((gBattleStatus.flags1 & 0x20) || (func_80266E14(targetPart), (gBattleStatus.flags1 & 0x20))) { // XXX
            if (gBattleStatus.currentAttackElement & (DAMAGE_TYPE_POW | DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_JUMP)) {
                if (targetPart->eventFlags & EVENT_FLAG_FLIPABLE) {
                    if (phi_s2 == 0xA) {
                        phi_s2 = EVENT_FLIP_TRIGGER;
                    }
                    if (phi_s2 == 0x19) {
                        phi_s2 = EVENT_FLIP_TRIGGER;
                    }
                }
            }
        }

        if (!(gBattleStatus.flags1 & 0x20)) {
            if (gBattleStatus.currentAttackElement & (DAMAGE_TYPE_POW | DAMAGE_TYPE_QUAKE | DAMAGE_TYPE_JUMP)) {
                if (targetPart->eventFlags & EVENT_FLAG_FLIPABLE) {
                    if (phi_s2 == EVENT_HIT_COMBO) {
                        phi_s2 = EVENT_FLIP_TRIGGER;
                    }
                    if (phi_s2 == EVENT_23) {
                        phi_s2 = EVENT_FLIP_TRIGGER;
                    }
                }
            }
        } else if (gBattleStatus.currentAttackElement & (DAMAGE_TYPE_FIRE | DAMAGE_TYPE_BLAST | DAMAGE_TYPE_4000)) {
            if (phi_s2 == 0xA) {
                phi_s2 = EVENT_BURN_HIT;
            }
            if (phi_s2 == EVENT_DEATH) {
                phi_s2 = EVENT_41;
            }
        }

        if (gBattleStatus.flags1 & 0x80000000) { // TODO: what the fuck?
            if (phi_s2 == EVENT_HIT_COMBO) {
                phi_s2 = EVENT_24;
            }
            if (phi_s2 == EVENT_HIT) {
                phi_s2 = EVENT_BLOCK;
            }
            if (phi_s2 == EVENT_23) {
                phi_s2 = EVENT_24;
            }
            if (phi_s2 == EVENT_IMMUNE) {
                phi_s2 = EVENT_BLOCK;
            }
            if (phi_s2 == EVENT_BURN_HIT) {
                phi_s2 = EVENT_BLOCK;
            }
        }

        //temp_v1_3 = gBattleStatus.flags1;
        phi_s5 = FALSE;
        phi_s7 = FALSE; // what is this for
        if (gBattleStatus.flags1 & 0x20) {
            if (gBattleStatus.lastAttackDamage >= 0 && phi_s2 != EVENT_DEATH && phi_s2 != EVENT_SPIN_SMASH_DEATH) {
                if (phi_s2 != EVENT_EXPLODE_TRIGGER) {
                    if (!(gBattleStatus.flags1 & 0x80000000)) {
                        if (!(gBattleStatus.flags2 & 0x1000000)) {
                            if (targetID != ACTOR_PLAYER || !is_ability_active(ABILITY_HEALTHY_HEALTHY) || !(rand_int(100) < 20)) {
                                if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_SHRINK) && try_inflict_status(target, STATUS_SHRINK, STATUS_SHRINK_TURN_MOD)) {
                                    phi_s5 = TRUE;
                                    phi_s7 = TRUE;
                                }
                                if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_POISON) && try_inflict_status(target, STATUS_POISON, STATUS_POISON_TURN_MOD)) {
                                    phi_s5 = TRUE;
                                    phi_s7 = TRUE;
                                }
                                if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_STONE) && try_inflict_status(target, STATUS_STONE, STATUS_STONE_TURN_MOD)) {
                                    phi_s5 = TRUE;
                                    phi_s7 = TRUE;
                                }
                                if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_SLEEP) && try_inflict_status(target, STATUS_SLEEP, STATUS_SLEEP_TURN_MOD)) {
                                    phi_s5 = TRUE;
                                    phi_s7 = TRUE;
                                }
                                if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_SLEEP) && try_inflict_status(target, STATUS_SLEEP, STATUS_SLEEP_TURN_MOD)) {
                                    phi_s5 = TRUE;
                                    phi_s7 = TRUE;
                                }
                                if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_DIZZY) && try_inflict_status(target, STATUS_DIZZY, STATUS_DIZZY_TURN_MOD)) {
                                    phi_s5 = TRUE;
                                    phi_s7 = TRUE;
                                }
                                if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_STOP) && try_inflict_status(target, STATUS_STOP, STATUS_STOP_TURN_MOD)) {
                                    phi_s5 = TRUE;
                                    phi_s7 = TRUE;
                                }
                                if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_STATIC) && try_inflict_status(target, STATUS_STATIC, STATUS_STATIC_TURN_MOD)) {
                                    phi_s5 = TRUE;
                                    phi_s7 = TRUE;
                                }
                                if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_PARALYZE) && try_inflict_status(target, STATUS_PARALYZE, STATUS_PARALYZE_TURN_MOD)) {
                                    phi_s5 = TRUE;
                                    phi_s7 = TRUE;
                                }
                                if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_FEAR) && try_inflict_status(target, STATUS_FEAR, STATUS_FEAR_TURN_MOD)) {
                                    phi_s5 = TRUE;
                                    phi_s7 = TRUE;
                                }

                                // BUG? repeated paralyse and dizzy infliction
                                if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_PARALYZE) && try_inflict_status(target, STATUS_PARALYZE, STATUS_PARALYZE_TURN_MOD)) {
                                    phi_s5 = TRUE;
                                    phi_s7 = TRUE;
                                }
                                if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_DIZZY) && try_inflict_status(target, STATUS_DIZZY, STATUS_DIZZY_TURN_MOD)) {
                                    phi_s5 = TRUE;
                                    phi_s7 = TRUE;
                                }

                                if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_FROZEN) && target->debuff != STATUS_FROZEN && try_inflict_status(target, STATUS_FROZEN, STATUS_FROZEN_TURN_MOD)) {
                                    phi_s5 = TRUE;
                                    phi_s7 = TRUE;
                                }

                                if (phi_s5) {
                                    if (phi_s2 == EVENT_23) {
                                        phi_s2 = EVENT_HIT_COMBO;
                                    }
                                    if (phi_s2 == EVENT_IMMUNE) {
                                        phi_s2 = EVENT_HIT;
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }

        gBattleStatus.wasStatusInflicted = phi_s5;

        switch (targetID) {
            case ACTOR_PARTNER:
                dispatch_event_partner(phi_s2);
                break;
            case ACTOR_PLAYER:
                dispatch_event_player(target, phi_s2);
                break;
            case ACTOR_ENEMY0:
                dispatch_event_actor(target, phi_s2);
                break;
        }

        if (targetID == ACTOR_PARTNER) {
            if (gBattleStatus.lastAttackDamage > 0 && (gBattleStatus.flags1 & 0x20) && !(target->flags & ACTOR_FLAG_NO_DMG_APPLY)) {
                inflict_partner_ko(target, STATUS_KO, gBattleStatus.lastAttackDamage);
            }
        }
        if (!(target->flags & ACTOR_FLAG_NO_DMG_POPUP)) {
            switch (targetID) {
                case ACTOR_PARTNER:
                case ACTOR_PLAYER:
                    if (gBattleStatus.lastAttackDamage == 0) {
                        if (!phi_s7 && !phi_s5) {
                            // immune star fx?
                            func_8024EFE0(walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, 0, -3);
                        }
                    } else {
                        if (gBattleStatus.currentAttackElement & 0x20000040) { // TODO flags
                            show_damage_popup(walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, gBattleStatus.lastAttackDamage, 1);
                        } else {
                            func_802664DC(walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, gBattleStatus.lastAttackDamage);
                        }

                        func_802666E4(target, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, gBattleStatus.lastAttackDamage);
                    }
                    break;
                case ACTOR_ENEMY0:
                    if (gBattleStatus.lastAttackDamage == 0) {
                        if (!phi_s7 && !phi_s5) {
                            func_8024EFE0(walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, 0, 3);
                        }
                    } else {
                        if (gBattleStatus.currentAttackElement & 0x20000040) {
                            // XXX: last arg
                            show_damage_popup(walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, gBattleStatus.lastAttackDamage, 0);
                        } else {
                            func_802664DC(walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, gBattleStatus.lastAttackDamage);
                        }

                        func_802666E4(target, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, gBattleStatus.lastAttackDamage);
                    }
                    break;
            }
        }

        if (gBattleStatus.lastAttackDamage > 0) {
            u32 hitSound;

            func_80267018(target, 1);

            if (attacker->actorTypeData1[5] != 0) {
                sfx_play_sound_at_position(attacker->actorTypeData1[5], 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
            }

            hitSound = HIT_SOUND_FIRE;
            if (!isFire) {
                hitSound = HIT_SOUND_SHOCK;
                if (!isElectric) {
                    hitSound = HIT_SOUND_NORMAL;
                }
            }
            play_hit_sound(target, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z, hitSound);
        } else { // maybe not else
            if (phi_s7 || isEnchanted) {
                if (targetPart->flags & PART_FLAG_2000) {
                    sfx_play_sound_at_position(SOUND_10C, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
                }
            }
        }

        // possibly vars stored as floats
        if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_SLEEP) && phi_s5) {
            ScriptInstance* script = start_script(&DoSleepHit, 10, 0);
            script->varTable[0] = walk->goalPos.x;
            script->varTable[1] = walk->goalPos.y;
            script->varTable[2] = walk->goalPos.z;
            sfx_play_sound_at_position(SOUND_INFLICT_SLEEP, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
        }
        if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_DIZZY) && phi_s5) {
            ScriptInstance* script = start_script(&DoDizzyHit, 10, 0);
            script->varTable[0] = walk->goalPos.x;
            script->varTable[1] = walk->goalPos.y;
            script->varTable[2] = walk->goalPos.z;
            sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
        }
        if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_PARALYZE) && phi_s5) {
            ScriptInstance* script = start_script(&DoParalyzeHit, 10, 0);
            script->varTable[0] = walk->goalPos.x;
            script->varTable[1] = walk->goalPos.y;
            script->varTable[2] = walk->goalPos.z;
            sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
        }
        if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_POISON) && phi_s5) {
            ScriptInstance* script = start_script(&DoPoisonHit, 10, 0);
            script->varTable[0] = walk->goalPos.x;
            script->varTable[1] = walk->goalPos.y;
            script->varTable[2] = walk->goalPos.z;
            sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
        }
        if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_STOP) && phi_s5) {
            ScriptInstance* script = start_script(&DoStopHit, 10, 0);
            script->varTable[0] = walk->goalPos.x;
            script->varTable[1] = walk->goalPos.y;
            script->varTable[2] = walk->goalPos.z;
            sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
        }
        if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_FROZEN) && phi_s5) {
            ScriptInstance* script = start_script(&DoFreezeHit, 10, 0);
            script->varTable[0] = walk->goalPos.x;
            script->varTable[1] = walk->goalPos.y;
            script->varTable[2] = walk->goalPos.z;
            script->varTable[3] = target;
            sfx_play_sound_at_position(SOUND_FREEZE, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
        }
        if ((gBattleStatus.currentAttackStatus & STATUS_FLAG_SHRINK) && phi_s5) {
            ScriptInstance* script = start_script(&DoShrinkHit, 10, 0);
            script->varTable[0] = walk->goalPos.x;
            script->varTable[1] = walk->goalPos.y;
            script->varTable[2] = walk->goalPos.z;
            script->varTable[3] = target;
            sfx_play_sound_at_position(SOUND_INFLICT_STATUS, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
        }

        if ((gBattleStatus.currentAttackElement & DAMAGE_TYPE_SMASH) && target->actorType == ACTOR_TYPE_goomnut_tree) {
            sfx_play_sound_at_position(SOUND_SMASH_GOOMNUT_TREE, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
        }

        func_80266ADC(target);
        if (
            (
                attacker->staticStatus != STATUS_STATIC
                && (target->staticStatus == STATUS_STATIC || (targetPart->eventFlags & EVENT_FLAG_ELECTRIFIED))
            )
            && !(gBattleStatus.currentAttackElement & DAMAGE_TYPE_NO_CONTACT)
            && !(gBattleStatus.currentAttackEventSuppression & 8)
            && (attacker->transStatus != 0xE)
            && !has_enchanted_part(attacker)
        ) {
            // enum mismatch? shock vs explode :raised_eyebrow:
            sfx_play_sound_at_position(SOUND_37B, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
            func_80251474(attacker);
            dispatch_damage_event_actor_1(attacker, 1, EVENT_SHOCK_HIT);
            return HIT_RESULT_TRIGGERED_EXPLODE;
        }
    }

    return hitResult;
}

INCLUDE_ASM(s32, "1A5830", dispatch_damage_event_actor);

s32 dispatch_damage_event_actor_0(Actor* actor, s32 damageAmount, s32 event) {
    return dispatch_damage_event_actor(actor, damageAmount, event, FALSE);
}

s32 dispatch_damage_event_actor_1(Actor* actor, s32 damageAmount, s32 event) {
    return dispatch_damage_event_actor(actor, damageAmount, event, TRUE);
}

ApiStatus BindTakeTurn(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Script* takeTurnScript;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    takeTurnScript = (Script*) get_variable(script, *args++);
    get_actor(actorID)->takeTurnScriptSource = takeTurnScript;
    return ApiStatus_DONE2;
}

ApiStatus PauseTakeTurn(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    get_variable(script, *args++);
    suspend_all_script(get_actor(actorID)->takeTurnID);
    return ApiStatus_DONE2;
}

ApiStatus ResumeTakeTurn(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    get_variable(script, *args++);
    resume_all_script(get_actor(actorID)->takeTurnID);
    return ApiStatus_DONE2;
}

ApiStatus BindIdle(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Script* idleCode;
    Actor* actor;
    ScriptInstance* newScriptContext;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    idleCode = (Script*) get_variable(script, *args++);
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

ApiStatus EnableIdleScript(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 var1;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    var1 = get_variable(script, *args++);
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

ApiStatus BindHandleEvent(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Script* var1;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    var1 = (Script*) get_variable(script, *args++);
    get_actor(actorID)->onHitScriptSource = var1;
    return ApiStatus_DONE2;
}

ApiStatus BindNextTurn(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Script* var1;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    var1 = (Script*) get_variable(script, *args++);
    get_actor(actorID)->onTurnChanceScriptSource = var1;
    return ApiStatus_DONE2;
}

INCLUDE_ASM(s32, "1A5830", JumpToGoal);

INCLUDE_ASM(s32, "1A5830", IdleJumpToGoal);

INCLUDE_ASM(s32, "1A5830", JumpToGoalSimple2);

INCLUDE_ASM(s32, "1A5830", JumpWithBounce);

ApiStatus LandJump(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    Actor* actor;

    if (isInitialCall) {
        script->functionTemp[0] = 0;
    }

    if (script->functionTemp[0] == 0) {
        s32 actorID = get_variable(script, *args++);

        if (actorID == ACTOR_SELF) {
            actorID = script->owner1.actorID;
        }

        actor = get_actor(actorID);
        script->functionTemp[1] = (s32)actor;
        actor->walk.currentPos.x = actor->currentPos.x;
        actor->walk.currentPos.y = actor->currentPos.y;
        actor->walk.currentPos.z = actor->currentPos.z;
        script->functionTemp[0] = 1;
    }

    actor = (Actor*)script->functionTemp[1];
    actor->walk.currentPos.y += actor->walk.velocity;
    actor->walk.velocity -= actor->walk.acceleration;

    add_xz_vec3f(&actor->walk.currentPos, actor->walk.speed, actor->walk.angle);
    actor->currentPos.x = actor->walk.currentPos.x;
    actor->currentPos.y = actor->walk.currentPos.y;
    actor->currentPos.z = actor->walk.currentPos.z;

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

ApiStatus GetLastEvent(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 outVar;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    outVar = *args++;
    set_variable(script, outVar, get_actor(actorID)->lastEventType);
    return ApiStatus_DONE2;
}

ApiStatus SetTargetActor(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 targetActorID;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    targetActorID = get_variable(script, *args++);
    actor = get_actor(actorID);
    actor->targetActorID = targetActorID;
    actor->targetPartIndex = 1;
    return ApiStatus_DONE2;
}

ApiStatus SetEnemyHP(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s8 newHP;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    newHP = get_variable(script, *args++);
    actor = get_actor(actorID);

    actor->currentHP = newHP;
    if (newHP > actor->maxHP) {
        actor->currentHP = actor->maxHP;
    }

    actor->hpFraction = (actor->currentHP * 25) / actor->maxHP;

    return ApiStatus_DONE2;
}

ApiStatus GetActorHP(ScriptInstance* script, s32 isInitialCall) {
    PlayerData* playerData = &gPlayerData;
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
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

    set_variable(script, outVar, outVal);
    return ApiStatus_DONE2;
}

ApiStatus GetEnemyMaxHP(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 outVar;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    outVar = *args++;
    set_variable(script, outVar, get_actor(actorID)->maxHP);
    return ApiStatus_DONE2;
}

// battlestatus shtuff
#ifdef NON_MATCHING
ApiStatus RemoveActor(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
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

INCLUDE_ASM(s32, "1A5830", DropStarPoints);

ApiStatus SetDefenseTable(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex;
    u32* var2;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    var2 = (u32*) get_variable(script, *args++);
    get_actor_part(get_actor(actorID), partIndex)->defenseTable = var2;
    return ApiStatus_DONE2;
}

ApiStatus SetStatusTable(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    u32* var1;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    var1 = (u32*) get_variable(script, *args++);
    get_actor(actorID)->statusTable = var1;
    return ApiStatus_DONE2;
}

ApiStatus SetIdleAnimations(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex;
    u32* var2;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    var2 = (u32*) get_variable(script, *args++);
    get_actor_part(get_actor(actorID), partIndex)->idleAnimations = var2;
    return ApiStatus_DONE2;
}

ApiStatus func_8027CC10(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);

    // weirdly unused
    get_variable(script, *args++);
    get_variable(script, *args++);

    get_actor_part(get_actor(actorID), partIndex);
    return ApiStatus_DONE2;
}

ApiStatus EnemyDamageTarget(ScriptInstance *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    ActorID actorID = get_variable(script, *args++);
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
    battleStatus->currentAttackDamage = get_variable(script, *args++);
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

    set_variable(script, outVar, hitResult);
    if (!(does_script_exist_by_ref(script))) {
        return ApiStatus_FINISH;
    }

    return ApiStatus_DONE2;
}

ApiStatus EnemyFollowupAfflictTarget(ScriptInstance* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    BattleStatus* anotherBattleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    Actor* actor;
    s32 actorID = get_variable(script, *args++);
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

    set_variable(script, outVar, hitResults);
    if (does_script_exist_by_ref(script) == NULL) {
        return ApiStatus_FINISH;
    }
    return ApiStatus_DONE2;
}

ApiStatus EnemyTestTarget(ScriptInstance *script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    ActorID actorID = get_variable(script, *args++);
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
    battleStatus->currentAttackDamage = get_variable(script, *args++);
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

    set_variable(script, outVar, hitResult);

    return ApiStatus_DONE2;
}

ApiStatus DispatchDamageEvent(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    s32 damageAmount;
    s32 scriptExists;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    damageAmount = get_variable(script, *args++);

    if (dispatch_damage_event_actor_0(actor, damageAmount, get_variable(script, *args++)) < 0) {
        return ApiStatus_BLOCK;
    }

    scriptExists = does_script_exist_by_ref(script) != 0;
    return scriptExists * ApiStatus_DONE2;
}

ApiStatus DispatchEvent(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    dispatch_event_actor(get_actor(actorID), get_variable(script, *args++));
    return ApiStatus_DONE2;
}

ApiStatus func_8027D2D8(ScriptInstance* script, s32 isInitialCall) {
    ActorID actorID = get_variable(script, *script->ptrReadPos);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    func_80266ADC(get_actor(actorID));
    return ApiStatus_DONE2;
}

ApiStatus func_8027D32C(ScriptInstance* script, s32 isInitialCall) {
    ActorID actorID = get_variable(script, *script->ptrReadPos);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    func_80266AF8(get_actor(actorID));
    return ApiStatus_DONE2;
}

ApiStatus SetTargetOffset(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex;
    ActorPart* part;
    s32 x;
    s32 y;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    part = get_actor_part(get_actor(actorID), partIndex);

    x = get_variable(script, *args++);
    y = get_variable(script, *args++);

    part->targetOffset.x = x;
    part->targetOffset.y = y;

    return ApiStatus_DONE2;
}

ApiStatus func_8027D434(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex;
    ActorPart* part;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    part = get_actor_part(get_actor(actorID), partIndex);
    part->unk_70 = get_variable(script, *args++);
    return ApiStatus_DONE2;
}

ApiStatus func_8027D4C8(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex;
    ActorPart* part;
    s32 temp;
    s32 temp2;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    partIndex = get_variable(script, *args++);
    part = get_actor_part(get_actor(actorID), partIndex);

    temp = get_variable(script, *args++);
    temp2 = get_variable(script, *args++);

    part->unk_75 = temp;
    part->unk_76 = temp2;

    return ApiStatus_DONE2;
}

ApiStatus EnableActorBlur(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 enable = get_variable(script, *args++);
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

ApiStatus func_8027D628(ScriptInstance* script, s32 isInitialCall) {
    ActorID actorID = get_variable(script, *script->ptrReadPos);

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    func_80254610(get_actor(actorID));
    return ApiStatus_DONE2;
}

ApiStatus AfflictActor(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    Actor* actor;
    s32 statusTypeKey;
    s32 duration;
    s32 statusDurationKey;

    statusTypeKey = get_variable(script, *args++);
    duration = get_variable(script, *args++);

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

ApiStatus func_8027D75C(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 outVar = *args++;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    set_variable(script, outVar, get_actor(actorID)->unk_208);
    return ApiStatus_DONE2;
}

ApiStatus GetEncounterState(ScriptInstance* script, s32 isInitialCall) {
    set_variable(script, *script->ptrReadPos, gCurrentEncounter.hitType);
    return ApiStatus_DONE2;
}

ApiStatus YieldTurn(ScriptInstance* script, s32 isInitialCall) {
    gBattleStatus.flags1 |= 0x200000;
    return ApiStatus_DONE2;
}

ApiStatus SetActorSize(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 y = get_variable(script, *args++);
    s32 x = get_variable(script, *args++);
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);

    if (y != SI_LIMIT) {
        actor->size.y = y;
    }
    if (x != SI_LIMIT) {
        actor->size.x = x;
    }
    actor->shadowScale = actor->size.x / 24.0;

    return ApiStatus_DONE2;
}

ApiStatus GetActorSize(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 outY = *args++;
    s32 outX = *args++;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);
    set_variable(script, outY, actor->size.y);
    set_variable(script, outX, actor->size.x);
    return ApiStatus_DONE2;
}

ApiStatus SetPartSize(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 partIndex = get_variable(script, *args++);
    s32 sizeY = get_variable(script, *args++);
    s32 sizeX = get_variable(script, *args++);
    ActorPart* part;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    part = get_actor_part(get_actor(actorID), partIndex);

    if (sizeY != SI_LIMIT) {
        part->size.y = sizeY;
    }

    if (sizeX != SI_LIMIT) {
        part->size.x = sizeX;
    }

    part->shadowScale = part->size.x / 24.0;

    return ApiStatus_DONE2;
}

ApiStatus GetOriginalActorType(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 outVar = *args++;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    set_variable(script, outVar, get_actor(actorID)->staticActorData->type);
    return ApiStatus_DONE2;
}

ApiStatus GetCurrentActorType(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 outVar = *args++;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    set_variable(script, outVar, get_actor(actorID)->actorType);
    return ApiStatus_DONE2;
}

ApiStatus GetLastDamage(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 outVar;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }
    outVar = *args++;

    set_variable(script, outVar, get_actor(actorID)->lastDamageTaken);
    return ApiStatus_DONE2;
}

ApiStatus EnableActorGlow(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 flag;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    flag = get_variable(script, *args++);
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

ApiStatus WasStatusInflicted(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    BattleStatus* battleStatus = &gBattleStatus;
    s32 outVal;

    get_variable(script, *args++);

    if (script) { // can be args or script but not 1 or do while 0, nor does else work after
        outVal = battleStatus->wasStatusInflicted;
    }
    outVal = battleStatus->wasStatusInflicted;

    set_variable(script, *args++, outVal);

    return ApiStatus_DONE2;
}

ApiStatus CopyStatusEffects(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorIDTo;
    ActorID actorIDFrom;
    Actor* actorTo;
    Actor* actorFrom;

    actorIDFrom = get_variable(script, *args++);
    if (actorIDFrom == ACTOR_SELF) {
        actorIDFrom = script->owner1.actorID;
    }
    actorFrom = get_actor(actorIDFrom);

    actorIDTo = get_variable(script, *args++);
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

ApiStatus ClearStatusEffects(ScriptInstance* script, s32 isInitialCall) {
    Bytecode* args = script->ptrReadPos;
    ActorID actorID = get_variable(script, *args++);
    s32 flag;
    Actor* actor;

    if (actorID == ACTOR_SELF) {
        actorID = script->owner1.actorID;
    }

    actor = get_actor(actorID);

    if (actor->debuff != STATUS_END) {
        actor->debuffDuration = 0;
        actor->debuff = STATUS_END;
        remove_status_1(actor->unk_436);
    }

    if (actor->staticStatus != 0) {
        actor->staticDuration = 0;
        actor->staticStatus = 0;
        remove_status_2(actor->unk_436);
    }

    if (actor->transStatus != 0) {
        actor->transDuration = 0;
        actor->transStatus = 0;
        remove_status_3(actor->unk_436);
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
