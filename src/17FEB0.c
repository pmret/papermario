#include "common.h"
#include "battle/battle.h"
#include "script_api/battle.h"

s32 calc_item_check_hit(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    ActorMovement* walk = &battleStatus->playerActor->state;
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
            if (actor->transStatus == 0xE) {
                return HIT_RESULT_MISS;
            }
            if (actor->stoneStatus == 0xC) {
                sfx_play_sound_at_position(0x10C, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
                return HIT_RESULT_IMMUNE;
            }
            if ((battleStatus->currentAttackElement & 0x80) && (actorPart->eventFlags & ACTOR_EVENT_FLAG_SPIKY_TOP)) {
                sfx_play_sound_at_position(0xE9, 0, walk->goalPos.x, walk->goalPos.y, walk->goalPos.z);
                return HIT_RESULT_LANDED_ON_SPIKE;
            }
        } else {
            return HIT_RESULT_MISS;
        }
    }
    return HIT_RESULT_HIT;
}

//INCLUDE_ASM(s32, "17FEB0", calc_item_damage_enemy);
s32 calc_item_damage_enemy(void) {
    s32 sp18;
    s32 sp1C;
    s32 sp20;
    s32 sp24;
    s32 sp28;
    s32 sp2C;
    Actor* temp_ret;
    Actor* temp_s2;
    Actor* temp_s6;
    Actor* temp_v0;
    ActorPart* temp_s7;
    Evt* temp_v0_10;
    Evt* temp_v0_11;
    Evt* temp_v0_5;
    Evt* temp_v0_6;
    Evt* temp_v0_7;
    Evt* temp_v0_8;
    Evt* temp_v0_9;
    s16 temp_a0_3;
    s16 temp_a2;
    s16 temp_a3;
    s16 temp_s1;
    s16 temp_v0_4;
    s32 temp_a0;
    s32 temp_a0_2;
    s32 temp_a0_4;
    s32 temp_a1;
    s32 temp_s0_2;
    s32 temp_v0_2;
    s32 temp_v1;
    s32 temp_v1_2;
    s32 temp_v1_3;
    s8 temp_s0;
    s8 temp_v0_3;
    ActorState* phi_s1;
    s32 phi_a0;
    s32 phi_s0;
    s32 phi_s2;
    s32 phi_s2_2;
    s32 phi_s2_3;
    s32 phi_s2_4;
    s32 phi_s2_5;
    s32 phi_s2_6;
    s32 phi_s2_7;
    s32 phi_s2_8;
    s32 phi_s2_9;
    s32 phi_s2_10;
    s32 phi_s2_11;
    s32 phi_s2_12;
    s32 phi_s2_13;
    s32 phi_s2_14;
    s32 phi_s2_15;
    s8 phi_s5;
    s32 phi_s2_16;
    s8 phi_s5_2;
    s32 phi_a0_2;
    s32 phi_s2_17;
    s32 phi_a0_3;
    s32 phi_fp;
    s32 phi_fp_2;
    s32 phi_v0;
    s32 phi_s2_18;
    s32 phi_fp_3;
    s32 phi_s2_19;
    s32 phi_s2_20;
    s8 phi_s5_3;
    s8 phi_s5_4;
    s8 phi_s5_5;
    s32 phi_fp_4;
    s32 phi_fp_5;

    sp1C = 0;
    sp24 = 0;
    sp28 = 0;
    sp2C = 0;
    temp_s6 = gBattleStatus.playerActor;
    temp_s1 = gBattleStatus.currentTargetID;
    temp_s2 = gBattleStatus.partnerActor;
    temp_s0 = gBattleStatus.currentTargetPart;
    gBattleStatus.wasStatusInflicted = 0;
    gBattleStatus.lastAttackDamage = 0;
    gBattleStatus.currentTargetID2 = (s16) (u16) gBattleStatus.currentTargetID;
    gBattleStatus.currentTargetPart2 = (s8) (u8) gBattleStatus.currentTargetPart;
    gBattleStatus.attackerActorID = (s16) (u16) temp_s6->actorID;
    temp_ret = get_actor((s32) temp_s1);
    temp_v0 = temp_ret;
    phi_s5_3 = (s8) 0;
    phi_s5_4 = (s8) 0;
    phi_s5_3 = (s8) 0;
    if (temp_v0 == 0) {
        return 0;
    }
    temp_s7 = get_actor_part(temp_v0, (s32) temp_s0);
    if (temp_s7 != 0) {
        temp_v0->lastDamageTaken = 0;
        sp20 = temp_s1 & 0x700;
        if ((gBattleStatus.flags1 & 0x80000) == 0) {
            phi_s1 = &temp_s6->state;
        } else {
            phi_s1 = &temp_s2->state;
        }
        phi_a0_2 = 0;
        if ((gBattleStatus.currentAttackElement & 2) != 0) {
            sp24 = 1;
            playFX_24(0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z + 5.0f, 1.0f, 0x18);
        }
        if ((gBattleStatus.currentAttackElement & 0x20) != 0) {
            func_80251474(temp_v0);
            sp28 = 1;
        }
        if ((gBattleStatus.currentAttackElement & 4) != 0) {
            playFX_5F(0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z + 5.0f, 1.0f, 0x18);
        }
        if ((gBattleStatus.currentAttackElement & 8) != 0) {
            sp2C = 1;
            playFX_30(0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z + 5.0f);
        }
        temp_a1 = gBattleStatus.currentAttackElement;
        if ((temp_a1 & 0x400000) == 0) {
            temp_a0 = temp_s7->eventFlags;
            phi_v0 = 6;
            if ((temp_a0 & 0x20) == 0) {
                if ((temp_v0->transStatus == 0xE) || (((temp_a0 & 0x800) != 0) && ((temp_a1 & 0x800) == 0))) {
                    return 6;
                }
                goto block_23;
            }
            /* Duplicate return node #237. Try simplifying control flow for better match */
            return phi_v0;
        }
block_23:
        if (temp_v0->stoneStatus == 0xC) {
            sfx_play_sound_at_position(0x10C, 0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z);
            func_8024EFE0(phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z, 0, 1, 1);
            show_damage_popup(phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z, 0, 0);
            return (gBattleStatus.flags1 & 0x240) != 0;
        }
        temp_a0_2 = gBattleStatus.currentAttackElement;
        sp18 = (temp_s7->partFlags3 & temp_a0_2) != 0;
        if ((temp_s7->eventFlags & 0xC0000) != 0) {
            gBattleStatus.currentAttackElement = temp_a0_2 & 0xF7FFFFFF;
        }
        temp_v0_2 = get_defense(temp_v0, temp_s7->defenseTable, gBattleStatus.currentAttackElement);
        phi_s0 = temp_v0_2;
        if ((gBattleStatus.currentAttackElement & 0x8000000) == 0) {
            phi_s0 = temp_v0_2 + temp_v0->defenseBoost;
        }
        temp_a0_3 = gBattleStatus.currentAttackDamage;
        phi_a0 = (s32) temp_a0_3;
        if ((s32) temp_a0_3 >= 0x64) {
            phi_a0 = 0x63;
        }
        if (phi_a0 <= 0) {
            phi_s0 = 0;
        }
        temp_a0_4 = phi_a0 - phi_s0;
        temp_v0->hpChangeCounter = 0;
        if (temp_a0_4 <= 0) {
            temp_v0->hpChangeCounter = 0;
            phi_fp_5 = 2;
            if ((gBattleStatus.currentAttackElement & 0x40000000) == 0) {
                sfx_play_sound_at_position(0x10C, 0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z);
                gBattleStatus.lastAttackDamage = 0;
                phi_s2 = 0x17;
            } else {
                gBattleStatus.lastAttackDamage = 0;
                phi_s2 = 0x17;
            }
        } else {
            temp_v0->damageCounter = (u16) temp_v0->damageCounter + temp_a0_4;
            temp_v0->hpChangeCounter -= temp_a0_4;
            gBattleStatus.lastAttackDamage = 0;
            phi_s2 = 9;
            phi_fp_5 = 0;
            if (((temp_s7->flags & 0x2000) == 0) && (sp18 == 0) && ((temp_s7->targetFlags & 4) == 0)) {
                temp_v0_3 = (u8) temp_v0->currentHP - temp_a0_4;
                temp_v0->currentHP = temp_v0_3;
                if ((temp_v0_3 << 0x18) <= 0) {
                    temp_v0->currentHP = 0;
                    phi_s2 = 0x20;
                }
            }
            temp_v0_4 = (u16) gBattleStatus.lastAttackDamage + temp_a0_4;
            gBattleStatus.lastAttackDamage = temp_v0_4;
            temp_v0->lastDamageTaken = temp_v0_4;
            temp_v0->hpChangeCounter = 0;
        }
        phi_s2_2 = phi_s2;
        if ((temp_s7->flags & 0x2000) != 0) {
            dispatch_event_actor(temp_v0, phi_s2);
            func_8024EFE0(phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z, 0, 1, 3);
            sfx_play_sound_at_position(0x10C, 0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z);
            return 2;
        }
        if ((gBattleStatus.currentAttackElement & 0x2000) != 0) {
            gBattleStatus.lastAttackDamage = 0;
            phi_s2_2 = 0x20;
            phi_fp_5 = 0;
        }
        phi_s2_3 = phi_s2_2;
        phi_s2_19 = phi_s2_2;
        phi_fp_4 = phi_fp_5;
        phi_fp = phi_fp_5;
        if ((gBattleStatus.flags1 & 0x20) != 0) {
            if (phi_s2_2 == 9) {
                phi_s2_3 = 0xA;
            }
            phi_s2_4 = phi_s2_3;
            if (phi_s2_3 == 0x17) {
                phi_s2_4 = 0x19;
            }
            phi_s2_19 = phi_s2_4;
            if ((s32) temp_v0->currentHP <= 0) {
                if (phi_s2_4 == 0x19) {
                    phi_s2_19 = 0x20;
                }
            }
        } else if (phi_s2_2 == 0x20) {
            phi_s2_19 = 9;
        }
        phi_s2_18 = phi_s2_19;
        phi_s2_20 = phi_s2_19;
        if ((gBattleStatus.flags1 & 0x20) != 0) {
            if ((gBattleStatus.currentAttackElement & 0x400000) != 0) {
                temp_v1 = temp_s7->eventFlags;
                phi_s2_20 = 0x19;
                if ((temp_v1 & 0x40000) != 0) {
                    phi_s5_3 = 1;
                    phi_s2_20 = 0x13;
                }
                if ((temp_v1 & 0x400000) != 0) {
                    phi_s5_3 = 1;
                    phi_s2_20 = 0x13;
                }
                if ((temp_v1 & 0x80000) != 0) {
                    phi_s2_20 = 0x1D;
                }
                phi_fp_4 = 0;
                goto block_68;
            }
            goto block_80;
        }
block_68:
        phi_s2_18 = phi_s2_20;
        phi_s5_2 = phi_s5_3;
        phi_s2_17 = phi_s2_20;
        phi_fp = phi_fp_4;
        phi_s5_4 = phi_s5_3;
        phi_fp = phi_fp_4;
        if ((gBattleStatus.currentAttackElement & 0x400000) != 0) {
            if ((gBattleStatus.flags1 & 0x20) != 0) {
                if (((s32) temp_v0->attackBoost <= 0) && ((s32) temp_v0->defenseBoost <= 0)) {
                    if (temp_v0->staticStatus == 0) {
                        if (temp_v0->transStatus != 0) {
                            goto block_74;
                        }
                    } else {
                        goto block_75;
                    }
                } else {
block_74:
block_75:
                    temp_v0->attackBoost = 0;
                    temp_v0->defenseBoost = 0;
                    temp_v0->isGlowing = 0;
                    phi_s2_18 = 0xA;
                    if (temp_v0->staticStatus != 0) {
                        temp_v0->staticStatus = 0;
                        temp_v0->staticDuration = 0;
                        remove_status_static(temp_v0->hudElementDataIndex);
                    }
                    if (temp_v0->transStatus != 0) {
                        temp_v0->transStatus = 0;
                        temp_v0->transDuration = 0;
                        remove_status_transparent(temp_v0->hudElementDataIndex);
                    }
                    phi_s5_4 = 1;
                    phi_fp = 0;
                }
                goto block_80;
            }
        } else {
block_80:
            phi_s2_5 = phi_s2_18;
            phi_s5_2 = phi_s5_4;
            phi_s2_17 = phi_s2_18;
            phi_s5_5 = phi_s5_4;
            phi_s5_5 = phi_s5_4;
            if ((gBattleStatus.flags1 & 0x20) != 0) {
                if ((gBattleStatus.currentAttackElement & 0x800000) != 0) {
                    temp_v1_2 = temp_s7->eventFlags;
                    phi_s2_5 = 0x19;
                    if ((temp_v1_2 & 0x40000) != 0) {
                        phi_s2_5 = 0x14;
                        phi_s5_5 = 1;
                    }
                    if ((temp_v1_2 & 0x80000) != 0) {
                        phi_s2_5 = 0x14;
                        phi_s5_5 = 1;
                    }
                }
                phi_s2_6 = phi_s2_5;
                phi_s2_7 = phi_s2_5;
                phi_s5_2 = phi_s5_5;
                phi_s2_17 = phi_s2_5;
                phi_s5 = phi_s5_5;
                if ((gBattleStatus.flags1 & 0x20) != 0) {
                    if ((gBattleStatus.currentAttackElement & 0x4000000) != 0) {
                        if (phi_s2_5 == 0xA) {
                            phi_s2_6 = 0xB;
                        }
                        phi_s2_7 = phi_s2_6;
                        if (phi_s2_6 == 0x20) {
                            phi_s2_7 = 0x21;
                        }
                    }
                    phi_s2_8 = phi_s2_7;
                    phi_s2_9 = phi_s2_7;
                    phi_s2_17 = phi_s2_7;
                    if ((gBattleStatus.flags1 & 0x20) != 0) {
                        if (((gBattleStatus.currentAttackElement & 0x480) != 0) && ((temp_s7->eventFlags & 0x4000) != 0)) {
                            if (phi_s2_7 == 0xA) {
                                phi_s2_8 = 0xC;
                            }
                            phi_s2_9 = phi_s2_8;
                            if (phi_s2_8 == 0x19) {
                                phi_s2_9 = 0xC;
                            }
                        }
                        phi_s2_10 = phi_s2_9;
                        phi_s2_11 = phi_s2_9;
                        phi_s2_17 = phi_s2_9;
                        if ((gBattleStatus.flags1 & 0x20) != 0) {
                            if (((gBattleStatus.currentAttackElement & 0x400) != 0) && ((temp_s7->eventFlags & 0x800000) != 0)) {
                                if (phi_s2_9 == 0xA) {
                                    phi_s2_10 = 0xC;
                                }
                                phi_s2_11 = phi_s2_10;
                                if (phi_s2_10 == 0x19) {
                                    phi_s2_11 = 0xC;
                                }
                            }
                            phi_s2_12 = phi_s2_11;
                            phi_s2_13 = phi_s2_11;
                            phi_s2_17 = phi_s2_11;
                            if ((gBattleStatus.flags1 & 0x20) != 0) {
                                if (((gBattleStatus.currentAttackElement & 0xC80) != 0) && ((temp_s7->eventFlags & 0x1000) != 0)) {
                                    if (phi_s2_11 == 0xA) {
                                        phi_s2_12 = 0xD;
                                    }
                                    phi_s2_13 = phi_s2_12;
                                    if (phi_s2_12 == 0x19) {
                                        phi_s2_13 = 0xD;
                                    }
                                }
                                phi_s2_14 = phi_s2_13;
                                phi_s2_15 = phi_s2_13;
                                phi_s2_17 = phi_s2_13;
                                if ((gBattleStatus.flags1 & 0x20) != 0) {
                                    if ((gBattleStatus.currentAttackElement & 2) != 0) {
                                        if (phi_s2_13 == 0xA) {
                                            phi_s2_14 = 0xE;
                                        }
                                        phi_s2_15 = phi_s2_14;
                                        if (phi_s2_14 == 0x20) {
                                            phi_s2_15 = 0x24;
                                        }
                                        sp24 = 1;
                                    }
                                    phi_s2_16 = phi_s2_15;
                                    phi_s2_17 = phi_s2_15;
                                    if (((gBattleStatus.flags1 & 0x20) != 0) && ((s32) gBattleStatus.lastAttackDamage >= 0) && (phi_s2_15 != 0x20) && (phi_s2_15 != 0x21) && (phi_s2_15 != 0x22)) {
                                        if (((gBattleStatus.currentAttackStatus & 0x80000) != 0) && (try_inflict_status(temp_v0, 0xA, 0x27) != 0)) {
                                            phi_s5 = 1;
                                        }
                                        if (((gBattleStatus.currentAttackStatus & 0x20000) != 0) && (try_inflict_status(temp_v0, 9, 0x25) != 0)) {
                                            phi_s5 = 1;
                                        }
                                        if (((gBattleStatus.currentAttackStatus & 0x100000) != 0) && (try_inflict_status(temp_v0, 0xC, 0x28) != 0)) {
                                            phi_s5 = 1;
                                        }
                                        if (((gBattleStatus.currentAttackStatus & 0x1000) != 0) && (try_inflict_status(temp_v0, 6, 0x20) != 0)) {
                                            phi_s5 = 1;
                                        }
                                        if (((gBattleStatus.currentAttackStatus & 0x200000) != 0) && (try_inflict_status(temp_v0, 8, 0x29) != 0)) {
                                            phi_s5 = 1;
                                        }
                                        if (((gBattleStatus.currentAttackStatus & 0x2000) != 0) && (try_inflict_status(temp_v0, 0xB, 0x21) != 0)) {
                                            phi_s5 = 1;
                                        }
                                        if (((gBattleStatus.currentAttackStatus & 0x8000) != 0) && (try_inflict_status(temp_v0, 3, 0x23) != 0)) {
                                            phi_s5 = 1;
                                        }
                                        if (((gBattleStatus.currentAttackStatus & 0x10000) != 0) && (try_inflict_status(temp_v0, 5, 0x26) != 0)) {
                                            phi_s5 = 1;
                                        }
                                        if (((gBattleStatus.currentAttackStatus & 0x40000) != 0) && (try_inflict_status(temp_v0, 4, 0x24) != 0)) {
                                            phi_s5 = 1;
                                        }
                                        phi_s5_2 = phi_s5;
                                        if (phi_s5 != 0) {
                                            if (phi_s2_15 == 0x17) {
                                                phi_s2_16 = 9;
                                            }
                                            phi_s2_17 = phi_s2_16;
                                            if (phi_s2_16 == 0x19) {
                                                phi_s2_17 = 0xA;
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
        temp_s0_2 = (gBattleStatus.statusChance * temp_v0->staticActorData->baseStatusChance) / 100;
        if (((gBattleStatus.flags1 & 0x20) != 0) && ((gBattleStatus.currentAttackElement & 0x1000) != 0)) {
            phi_s2_17 = 0x19;
            if (rand_int(0x63) < temp_s0_2) {
                phi_fp = 2;
                if ((u32) ((u8) temp_v0->debuff - 3) >= 6U) {
                    phi_fp = 2;
                    if ((temp_v0->flags & 0x400) == 0) {
                        sp1C = 1;
                        gBattleStatus.flags1 |= 0x39;
                        sfx_play_sound_at_position(0x231, 0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z);
                        gBattleStatus.flags1 |= 0x40;
                        phi_s5_2 = 1;
                        phi_s2_17 = 0x39;
                        phi_fp = 0;
                    }
                }
            } else {
                phi_fp = 2;
            }
        }
        gBattleStatus.wasStatusInflicted = phi_s5_2;
        phi_fp_2 = phi_fp;
        if ((((sp1C != 0) && ((gBattleStatus.flags1 & 0x240) != 0)) || ((temp_v1_3 = gBattleStatus.flags1, ((temp_v1_3 & 0x240) != 0)) && ((temp_v1_3 & 0x80) == 0))) && ((((s32) gBattleStatus.lastAttackDamage > 0) && (sfx_play_sound_at_position(0x231, 0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z), ((s32) gBattleStatus.lastAttackDamage > 0))) || (((gBattleStatus.currentAttackElement & 0x40000000) != 0) && (sp1C != 0)))) {
            if ((gBattleStatus.flags1 & 0x40) != 0) {

            } else {
                phi_a0_2 = 3;
            }
            func_802667F0(phi_a0_2, temp_v0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z);
        }
        if ((gBattleStatus.flags1 & 0x20) != 0) {
            func_80266970(temp_v0);
        }
        dispatch_event_actor(temp_ret, phi_s2_17);
        if (sp20 == 0x100) {
            temp_a2 = gBattleStatus.lastAttackDamage;
            if (((s32) temp_a2 > 0) && ((gBattleStatus.flags1 & 0x20) != 0)) {
                inflict_status(temp_v0, 0xD, (s32) temp_a2);
            }
        }
        if ((temp_v0->flags & 0x2000000) == 0) {
            temp_a3 = gBattleStatus.lastAttackDamage;
            if (temp_a3 == 0) {
                if ((sp1C == 0) && (phi_s5_2 == 0)) {
                    func_8024EFE0(phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z, 0, 1, 3);
                }
            } else if (sp18 == 0) {
                if ((gBattleStatus.currentAttackElement & 0x20000040) != 0) {
                    show_damage_popup(phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z, (s32) temp_a3, 0);
                } else {
                    func_802664DC(phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z, temp_a3);
                }
                if ((temp_s7->targetFlags & 4) == 0) {
                    func_802666E4(temp_v0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z, (s16) (s32) gBattleStatus.lastAttackDamage);
                }
            }
        }
        if ((s32) gBattleStatus.lastAttackDamage > 0) {
            if (sp18 == 0) {
                func_80267018(temp_v0, 1);
                phi_a0_3 = 0xEA;
                if (sp24 != 0) {

                } else {
                    phi_a0_3 = 0x37B;
                    if (sp28 != 0) {

                    } else {
                        phi_a0_3 = 0xEB;
                        if (sp2C != 0) {

                        } else {
                            phi_a0_3 = 0xE9;
                        }
                    }
                }
                sfx_play_sound_at_position(phi_a0_3, 0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z);
            }
            if ((s32) gBattleStatus.lastAttackDamage <= 0) {
                goto block_204;
            }
            goto block_205;
        }
block_204:
        if (phi_s5_2 != 0) {
block_205:
            if ((temp_s7->flags & 0x2000) != 0) {
                goto block_206;
            }
        } else {
block_206:
            sfx_play_sound_at_position(0x10C, 0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z);
        }
        if (((gBattleStatus.currentAttackStatus & 0x1000) != 0) && (phi_s5_2 != 0)) {
            temp_v0_5 = start_script((s32 (*)[0]) DoSleepHit, 0xA, 0);
            temp_v0_5->varTable[0] = (s32) phi_s1->goalPos.x;
            temp_v0_5->varTable[1] = (s32) phi_s1->goalPos.y;
            temp_v0_5->varTable[2] = (s32) phi_s1->goalPos.z;
            sfx_play_sound_at_position(0x2031, 0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z);
        }
        if (((gBattleStatus.currentAttackStatus & 0x40000) != 0) && (phi_s5_2 != 0)) {
            temp_v0_6 = start_script((s32 (*)[0]) DoDizzyHit, 0xA, 0);
            temp_v0_6->varTable[0] = (s32) phi_s1->goalPos.x;
            temp_v0_6->varTable[1] = (s32) phi_s1->goalPos.y;
            temp_v0_6->varTable[2] = (s32) phi_s1->goalPos.z;
            sfx_play_sound_at_position(0x2032, 0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z);
        }
        if (((gBattleStatus.currentAttackStatus & 0x10000) != 0) && (phi_s5_2 != 0)) {
            temp_v0_7 = start_script((s32 (*)[0]) DoParalyzeHit, 0xA, 0);
            temp_v0_7->varTable[0] = (s32) phi_s1->goalPos.x;
            temp_v0_7->varTable[1] = (s32) phi_s1->goalPos.y;
            temp_v0_7->varTable[2] = (s32) phi_s1->goalPos.z;
            sfx_play_sound_at_position(0x2032, 0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z);
        }
        if (((gBattleStatus.currentAttackStatus & 0x20000) != 0) && (phi_s5_2 != 0)) {
            temp_v0_8 = start_script((s32 (*)[0]) DoPoisonHit, 0xA, 0);
            temp_v0_8->varTable[0] = (s32) phi_s1->goalPos.x;
            temp_v0_8->varTable[1] = (s32) phi_s1->goalPos.y;
            temp_v0_8->varTable[2] = (s32) phi_s1->goalPos.z;
            sfx_play_sound_at_position(0x2032, 0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z);
        }
        if (((gBattleStatus.currentAttackStatus & 0x200000) != 0) && (phi_s5_2 != 0)) {
            temp_v0_9 = start_script((s32 (*)[0]) DoStopHit, 0xA, 0);
            temp_v0_9->varTable[0] = (s32) phi_s1->goalPos.x;
            temp_v0_9->varTable[1] = (s32) phi_s1->goalPos.y;
            temp_v0_9->varTable[2] = (s32) phi_s1->goalPos.z;
            sfx_play_sound_at_position(0x2032, 0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z);
        }
        if (((gBattleStatus.currentAttackStatus & 0x4000) != 0) && (phi_s5_2 != 0)) {
            temp_v0_10 = start_script((s32 (*)[0]) DoFreezeHit, 0xA, 0);
            temp_v0_10->varTable[0] = (s32) phi_s1->goalPos.x;
            temp_v0_10->varTable[1] = (s32) phi_s1->goalPos.y;
            temp_v0_10->varTable[3] = (s32) temp_v0;
            temp_v0_10->varTable[2] = (s32) phi_s1->goalPos.z;
            sfx_play_sound_at_position(0x2032, 0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z);
        }
        if (((gBattleStatus.currentAttackStatus & 0x80000) != 0) && (phi_s5_2 != 0)) {
            temp_v0_11 = start_script((s32 (*)[0]) DoShrinkHit, 0xA, 0);
            temp_v0_11->varTable[0] = (s32) phi_s1->goalPos.x;
            temp_v0_11->varTable[1] = (s32) phi_s1->goalPos.y;
            temp_v0_11->varTable[3] = (s32) temp_v0;
            temp_v0_11->varTable[2] = (s32) phi_s1->goalPos.z;
            sfx_play_sound_at_position(0x2032, 0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z);
        }
        if (((gBattleStatus.currentAttackElement & 0x40) != 0) && (temp_v0->actorType == 0x93)) {
            sfx_play_sound_at_position(0x165, 0, phi_s1->goalPos.x, phi_s1->goalPos.y, phi_s1->goalPos.z);
        }
        func_80266ADC(temp_v0);
        phi_v0 = phi_fp;
        if ((gBattleStatus.flags1 & 0x240) != 0) {
            if (phi_fp == 0) {
                phi_fp_2 = 1;
            }
            phi_fp_3 = phi_fp_2;
            if (phi_fp_2 == 2) {
                phi_fp_3 = 3;
            }
            phi_v0 = phi_fp_3;
        }
        return phi_v0;
    }
loop_5:
    goto loop_5;
}

ApiStatus ItemDamageEnemy(Evt* script, s32 isInitialCall) {
    BattleStatus* battleStatus = &gBattleStatus;
    Bytecode* args = script->ptrReadPos;
    s32 itemDamageOut = *args++;
    s32 a5;
    Actor* actor;
    s32 itemDamage;
    s32 flag = 0x10;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = 0;
    battleStatus->currentAttackStatus = *args++;
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
    a5 = *args++;

    if ((a5 & 0x30) == 0x30) {
        battleStatus->flags1 |= 0x30;
    } else if (a5 & flag) {
        battleStatus->flags1 = (battleStatus->flags1 | flag) & ~0x20;
    } else if (a5 & 0x20) {
        battleStatus->flags1 = (battleStatus->flags1 & ~flag) | 0x20;
    } else {
        battleStatus->flags1 = (battleStatus->flags1 & ~flag) & ~0x20;
    }

    if (a5 & 0x40) {
        gBattleStatus.flags1 |= 0x40;
    } else {
        gBattleStatus.flags1 &= ~0x40;
    }

    if (a5 & 0x200) {
        gBattleStatus.flags1 |= 0x200;
    } else {
        gBattleStatus.flags1 &= ~0x200;
    }

    if (a5 & 0x80) {
        gBattleStatus.flags1 |= 0x80;
    } else {
        gBattleStatus.flags1 &= ~0x80;
    }

    actor = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;

    if ((battleStatus->statusChance & 0xFF) == 0xFF) {
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
    s32 a5;
    Actor* actor;
    s32 itemDamage;
    s32 flag = 0x10;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = 0;
    battleStatus->currentAttackStatus = *args++;
    battleStatus->currentAttackStatus |= evt_get_variable(script, *args++);
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
    a5 = *args++;

    if ((a5 & 0x30) == 0x30) {
        battleStatus->flags1 |= 0x30;
    } else if (a5 & flag) {
        battleStatus->flags1 = (battleStatus->flags1 | flag) & ~0x20;
    } else if (a5 & 0x20) {
        battleStatus->flags1 = (battleStatus->flags1 & ~flag) | 0x20;
    } else {
        battleStatus->flags1 = (battleStatus->flags1 & ~flag) & ~0x20;
    }

    if (a5 & 0x40) {
        gBattleStatus.flags1 |= 0x40;
    } else {
        gBattleStatus.flags1 &= ~0x40;
    }

    if (a5 & 0x200) {
        gBattleStatus.flags1 |= 0x200;
    } else {
        gBattleStatus.flags1 &= ~0x200;
    }

    if (a5 & 0x80) {
        gBattleStatus.flags1 |= 0x80;
    } else {
        gBattleStatus.flags1 &= ~0x80;
    }

    actor = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;

    if ((battleStatus->statusChance & 0xFF) == 0xFF) {
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
    s32 a5;
    Actor* actor;
    s32 itemDamage;
    s32 flag = 0x10;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = 0;
    battleStatus->currentAttackStatus = evt_get_variable(script, *args++);
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
    a5 = *args++;

    if ((a5 & 0x30) == 0x30) {
        battleStatus->flags1 |= 0x30;
    } else if (a5 & flag) {
        battleStatus->flags1 = (battleStatus->flags1 | flag) & ~0x20;
    } else if (a5 & 0x20) {
        battleStatus->flags1 = (battleStatus->flags1 & ~flag) | 0x20;
    } else {
        battleStatus->flags1 = (battleStatus->flags1 & ~flag) & ~0x20;
    }

    if (a5 & 0x40) {
        gBattleStatus.flags1 |= 0x40;
    } else {
        gBattleStatus.flags1 &= ~0x40;
    }

    if (a5 & 0x200) {
        gBattleStatus.flags1 |= 0x200;
    } else {
        gBattleStatus.flags1 &= ~0x200;
    }

    if (a5 & 0x80) {
        gBattleStatus.flags1 |= 0x80;
    } else {
        gBattleStatus.flags1 &= ~0x80;
    }

    actor = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;

    if ((battleStatus->statusChance & 0xFF) == 0xFF) {
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
    s32 a5;
    Actor* actor;
    s32 itemDamage;
    s32 flag = 0x10;

    battleStatus->currentAttackElement = *args++;
    battleStatus->currentAttackEventSuppression = 0;
    battleStatus->currentAttackStatus = *args++;
    battleStatus->currentAttackDamage = evt_get_variable(script, *args++);
    a5 = *args++;

    if ((a5 & 0x30) == 0x30) {
        battleStatus->flags1 |= 0x30;
    } else if (a5 & flag) {
        battleStatus->flags1 = (battleStatus->flags1 | flag) & ~0x20;
    } else if (a5 & 0x20) {
        battleStatus->flags1 = (battleStatus->flags1 & ~flag) | 0x20;
    } else {
        battleStatus->flags1 = (battleStatus->flags1 & ~flag) & ~0x20;
    }

    if (a5 & 0x40) {
        gBattleStatus.flags1 |= 0x40;
    } else {
        gBattleStatus.flags1 &= ~0x40;
    }

    if (a5 & 0x200) {
        gBattleStatus.flags1 |= 0x200;
    } else {
        gBattleStatus.flags1 &= ~0x200;
    }

    if (a5 & 0x80) {
        gBattleStatus.flags1 |= 0x80;
    } else {
        gBattleStatus.flags1 &= ~0x80;
    }

    actor = get_actor(script->owner1.actorID);
    battleStatus->currentTargetID = actor->targetActorID;
    battleStatus->currentTargetPart = actor->targetPartIndex;
    battleStatus->statusChance = battleStatus->currentAttackStatus;

    if ((battleStatus->statusChance & 0xFF) == 0xFF) {
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
