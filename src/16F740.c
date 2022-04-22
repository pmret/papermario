#include "common.h"
#include "script_api/battle.h"
#include "ld_addrs.h"
#include "effects.h"
#include "hud_element.h"
#include "battle/battle.h"

extern s32* D_800DC064;

extern s16 D_802809F6;
extern s16 D_802809F8;
extern s32 D_80280A30;
extern s32 D_8029F254;
extern u8 D_8029F244;
extern s32 D_8029F248;
extern s32 D_8029F258;

// Almost good but some reorderings at the beginning
#ifdef NON_EQUIVALENT
void btl_merlee_on_start_turn(void) {
    PlayerData* playerData = &gPlayerData;
    BattleStatus* battleStatus = &gBattleStatus;
    EncounterStatus* currentEncounter = &gCurrentEncounter;

    if (!(gBattleStatus.flags2 & 0x40) && battleStatus->unk_8A != 3 && battleStatus->unk_8A != 4 && playerData->merleeCastsLeft > 0) {
        if (playerData->merleeTurnCount <= 0) {
            s32 d100 = rand_int(100);

            if (currentEncounter->currentEnemy != NULL) {
                if (currentEncounter->currentEnemy->flags & 0x40000) {
                    if (d100 <= 45) {
                        playerData->merleeSpellType = 1;
                    } else if (d100 <= 90) {
                        playerData->merleeSpellType = 2;
                    } else {
                        playerData->merleeSpellType = 3;
                    }
                } else if (d100 <= 30) {
                    playerData->merleeSpellType = 1;
                } else if (d100 <= 60) {
                    playerData->merleeSpellType = 2;
                } else if (d100 <= 80) {
                    playerData->merleeSpellType = 3;
                } else {
                    playerData->merleeSpellType = 4;
                }
            } else if (d100 <= 30) {
                playerData->merleeSpellType = 1;
            } else if (d100 <= 60) {
                playerData->merleeSpellType = 2;
            } else if (d100 <= 80) {
                playerData->merleeSpellType = 3;
            } else {
                playerData->merleeSpellType = 4;
            }
            playerData->merleeTurnCount = rand_int(10) + 6;
        }

        if (playerData->merleeTurnCount >= 2) {
            playerData->merleeTurnCount--;
        } else {
            playerData->merleeTurnCount = 0;
            battleStatus->unk_8A = playerData->merleeSpellType;
            playerData->merleeCastsLeft--;
        }
    }
}
#else
INCLUDE_ASM(s32, "16F740", btl_merlee_on_start_turn);
#endif

INCLUDE_ASM(s32, "16F740", btl_merlee_on_first_strike);

void btl_set_state(s32 battleState) {
    s32 flags = gBattleStatus.flags2;
    gBattleState = battleState;
    D_800DC4E0 = 1;
    gBattleState2 = BATTLE_STATE2_UNK_0;

    flags &= BS_FLAGS2_40;
    if (flags) {
        switch (battleState) {
            case BATTLE_STATE_PARTNER_MENU:
                battleState = BATTLE_STATE_TWINK_MENU;
                break;
            case BATTLE_STATE_PLAYER_MENU:
                battleState = BATTLE_STATE_PEACH_MENU;
                break;
            case BATTLE_STATE_BEGIN_PLAYER_TURN:
                battleState = BATTLE_STATE_BEGIN_PARTNER_TURN;
                break;
            case BATTLE_STATE_BEGIN_PARTNER_TURN:
                battleState = BATTLE_STATE_BEGIN_PLAYER_TURN;
                break;
        }
        gBattleState = battleState;
    }
}

INCLUDE_ASM(s32, "16F740", btl_state_update_normal_start);

void btl_state_draw_normal_start(void) {
    set_screen_overlay_color(0, 0, 0, 0);

    if (D_80280A30 > 255) {
        set_screen_overlay_params_front(0, 255.0f);
    } else {
        set_screen_overlay_params_front(0, D_80280A30);
    }
}

INCLUDE_ASM(s32, "16F740", btl_state_update_begin_turn);

void btl_state_draw_begin_turn(void) {
}

// tail merging
#ifdef NON_MATCHING
void btl_state_update_begin_player_turn(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    ActorPart* part = &player->partsTable[0];
    Evt* script;
    s32 i;

    s32 phi_v0;
    s32 phi_v1;
    s32 phi_a0;
    s32 phi_v0_2;

    if (gBattleState2 == BATTLE_STATE2_UNK_0) {
        func_8024E40C(2);
        btl_cam_move(5);
        gBattleState2 = BATTLE_STATE2_UNK_64;
    }

    if (gBattleState2 != BATTLE_STATE2_UNK_14) {
        if (gBattleState2 == BATTLE_STATE2_UNK_64 && (func_8024E584() != 0)) {
            gBattleStatus.flags1 &= ~0x80000;
            reset_actor_turn_info();
            battleStatus->unk_86 = 0x7F;
            battleStatus->blockResult = 0x7F;
            battleStatus->selectedMoveID = 0;
            gBattleStatus.flags1 |= 8;
            gBattleStatus.flags2 &= ~0x1000000;
            player->unk_21D = 0;
            player->flags |= 0x0C000000;

            if (partner != NULL) {
                player->flags |= 0x0C000000;
                partner->unk_21D = 0;
            }

            battleStatus->unk_8C = 0;
            D_8029F254 = 0;
            D_8029F258 = 0;

            if (battleStatus->outtaSightActive == 0) {
                gBattleState2 = BATTLE_STATE2_PLAYER_DEFEATED;
            } else {
                battleStatus->battlePhase = 0xC;
                script = start_script(partner->onTurnChanceScriptSource, 0xA, 0);
                partner->onTurnChangeScript = script;
                gBattleState2 = BATTLE_STATE2_UNK_14;
                partner->onTurnChangeID = script->id;
                script->owner1.actorID = ACTOR_PARTNER;
            }
        }
    } else if (!does_script_exist(partner->onTurnChangeID)) {
        battleStatus->outtaSightActive = 0;
        gBattleState2 = BATTLE_STATE2_PLAYER_DEFEATED;
        gBattleStatus.flags2 |= 4;
    }

    if (gBattleState2 != BATTLE_STATE2_UNK_2) {
        if (gBattleState2 == BATTLE_STATE2_PLAYER_DEFEATED && (battleStatus->unk_8C == 0)) {
            if (battleStatus->waterBlockTurnsLeft != 0) {
                battleStatus->waterBlockTurnsLeft--;
                battleStatus->unk_43C->unk_0C->unk_10 = battleStatus->waterBlockTurnsLeft;
                if (battleStatus->waterBlockTurnsLeft <= 0) {
                    battleStatus->waterBlockEffect->flags |= 0x10;
                    fx_water_block(1, player->currentPos.x, player->currentPos.y + 18.0f, player->currentPos.z + 5.0f, 1.5f, 10);
                    fx_water_splash(0, player->currentPos.x - 10.0f, player->currentPos.y + 5.0f, player->currentPos.z + 5.0f, 1.0f, 0x18);
                    fx_water_splash(0, player->currentPos.x - 15.0f, player->currentPos.y + 32.0f, player->currentPos.z + 5.0f, 1.0f, 0x18);
                    fx_water_splash(1, player->currentPos.x + 15.0f, player->currentPos.y + 22.0f, player->currentPos.z + 5.0f, 1.0f, 0x18);
                    battleStatus->waterBlockEffect = NULL;
                    sfx_play_sound(0x299);
                    btl_show_battle_message(0x27, 0x3C);
                    gBattleState2 = BATTLE_STATE2_UNK_2;
                } else {
                    gBattleState2 = BATTLE_STATE2_UNK_B;
                }
            } else {
                gBattleState2 = BATTLE_STATE2_UNK_B;
            }
        }
    } else if (!btl_is_popup_displayed()) {
        gBattleState2 = BATTLE_STATE2_UNK_B;
    }

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_B:
            if (battleStatus->cloudNineTurnsLeft != 0) {
                battleStatus->cloudNineTurnsLeft--;
                battleStatus->unk_43C->unk_0C->unk_1A = battleStatus->cloudNineTurnsLeft;

                if (battleStatus->cloudNineTurnsLeft <= 0) {
                    remove_effect(battleStatus->cloudNineEffect);
                    battleStatus->cloudNineEffect = NULL;
                    btl_show_battle_message(0x29, 0x3C);
                    gBattleState2 = BATTLE_STATE2_UNK_C;
                } else {
                    gBattleState2 = BATTLE_STATE2_UNK_F;
                }
            } else {
                gBattleState2 = BATTLE_STATE2_UNK_F;
            }
            break;
        case BATTLE_STATE2_UNK_C:
            if (!btl_is_popup_displayed()) {
                gBattleState2 = BATTLE_STATE2_UNK_F;
            }
            break;
    }

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_F:
            if (battleStatus->turboChargeTurnsLeft != 0) {
                if (gBattleStatus.flags2 & 0x100) {
                    gBattleStatus.flags2 &= ~0x100;
                    gBattleState2 = BATTLE_STATE2_UNK_15;
                } else {
                    battleStatus->turboChargeTurnsLeft--;
                    battleStatus->unk_43C->unk_0C->unk_24 = battleStatus->turboChargeTurnsLeft;
                    if (battleStatus->turboChargeTurnsLeft <= 0) {
                        btl_show_battle_message(0x2B, 0x3C);
                        gBattleState2 = BATTLE_STATE2_UNK_10;
                    } else {
                        gBattleState2 = BATTLE_STATE2_UNK_15;
                    }
                }
            } else {
                gBattleState2 = BATTLE_STATE2_UNK_15;
            }
            break;
        case BATTLE_STATE2_UNK_10:
            if (!btl_is_popup_displayed()) {
                gBattleState2 = BATTLE_STATE2_UNK_15;
            }
            break;
    }

    if (gBattleState2 == BATTLE_STATE2_UNK_15) {
        if ((player->debuff == 9) && (player->stoneStatus == 0)) {
            gBattleStatus.flags1 |= 0x20;
            dispatch_damage_event_player_0(1, 0xA);
        }

        battleStatus->rushFlags = 0;
        gBattleStatus.flags2 &= ~0x8000000;
        if (!(gBattleStatus.flags2 & 0x40)) {
            if (playerData->curHP <= 1 && is_ability_active(0x14)) {
                gBattleStatus.flags2 |= 0x08000000;
                battleStatus->rushFlags |= 1;
            }
            if (playerData->curHP < 6 && is_ability_active(0x1E) && !(battleStatus->rushFlags & 1)) {
                gBattleStatus.flags2 |= 0x08000000;
                battleStatus->rushFlags |= 2;
            }
        }
        gBattleState2 = BATTLE_STATE2_UNK_16;
    }

    if ((gBattleState2 == BATTLE_STATE2_UNK_16) && (player->onHitScript == NULL || !does_script_exist(player->onHitID))) {
        player->onHitScript = NULL;
        if (!btl_check_player_defeated()) {
            D_8029F254 = 0;
            player->unk_21D = 0;
            player->flags |= 0x0C000000;
            if (is_ability_active(0xE)) {
                if (player->debuff != 0) {
                    player->debuffDuration = 1;
                }
                if (player->staticStatus != 0) {
                    player->staticDuration = 1;
                }
                if (player->stoneStatus != 0) {
                    player->stoneDuration = 1;
                }
                if (player->koStatus != 0) {
                    player->koDuration = 1;
                }
                if (player->transStatus != 0) {
                    player->transDuration = 1;
                }
            }
            if (player->stoneStatus != 0) {
                player->stoneDuration--;
                if (player->stoneDuration <= 0) {
                    player->stoneStatus = 0;
                    dispatch_event_player(0x31);
                }
            } else {
                s32 debuffDuration;
                s32 koDuration;

                if (!is_ability_active(0x13) && (player->staticStatus != 0)) {
                    player->staticDuration--;
                    if (player->staticDuration <= 0) {
                        player->staticStatus = 0;
                        remove_status_static(player->hudElementDataIndex);
                    }
                }
                if (player->transStatus != 0) {
                    player->transDuration--;
                    part->flags |= 0x100;
                    if (player->transDuration <= 0) {
                        player->transStatus = 0;
                        part->flags &= ~0x100;
                        remove_status_transparent(player->hudElementDataIndex);
                    }
                }

                if (player->debuff != 0) {
                    if (player->debuff < 9) {
                        D_8029F254 = 1;
                    }
                    D_8029F258 = 20;
                    player->debuffDuration--;
                    if (player->debuffDuration <= 0) {
                        if (player->debuff == STATUS_FROZEN) {
                            sfx_play_sound(0xE7);
                            player->icePillarEffect->flags |= 0x10;
                            player->icePillarEffect = NULL;
                            dispatch_event_player(0x32);
                        } else {
                            dispatch_event_player(0x31);
                        }
                        player->debuff = 0;
                        player->debuffDuration = 0;
                        remove_status_debuff(player->hudElementDataIndex);
                    }
                }

                debuffDuration = (u8) player->debuffDuration;
                koDuration = player->koDuration;
                player->koDuration = debuffDuration;
                if ((s8) debuffDuration > 0) {
                    player->koStatus = 0xD;
                    ((DisableXFXData*)player->debuffEffect->data)->unk_3C = player->koDuration;
                } else if (koDuration != (s8) debuffDuration) {
                    player->koStatus = 0;
                    player->koDuration = 0;
                    ((DisableXFXData*)player->debuffEffect->data)->unk_3C = 0;
                }
            }

            for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                Actor* enemy = battleStatus->enemyActors[i];

                if (enemy != NULL) {
                    enemy->flags |= 0x0C000000;
                    if (enemy->chillOutTurns != 0) {
                        enemy->chillOutTurns--;
                        if (enemy->chillOutTurns == 0) {
                            enemy->chillOutAmount = 0;
                            remove_status_chill_out(enemy->hudElementDataIndex);
                            D_8029F258 = 20;
                        }
                    }
                }
            }
            gBattleState2 = BATTLE_STATE2_UNK_1;
        } else {
            return;
        }
    }

    if (gBattleState2 == BATTLE_STATE2_UNK_1) {
        s32 phi_s0_2 = 1;
        s32 phi_s0_3;

        if (!btl_check_enemies_defeated()) {
            battleStatus->unk_8C = 0;
            if (battleStatus->hammerLossTurns >= 0) {
                battleStatus->hammerLossTurns--;
                if (battleStatus->hammerLossTurns == -1) {
                    script = start_script(RegainAbility, 0xA, 0);
                    player->takeTurnScript = script;
                    player->takeTurnID = script->id;
                    script->varTable[0] = 1;
                    phi_s0_2 = 9;
                    script->owner1.actorID = ACTOR_PLAYER;
                    script->varTable[10] = 1;
                    battleStatus->unk_8C = 1;
                }
            }

            phi_s0_3 = phi_s0_2;
            if (battleStatus->jumpLossTurns >= 0) {
                battleStatus->jumpLossTurns--;
                if (battleStatus->jumpLossTurns == -1) {
                    script = start_script(RegainAbility, 0xA, 0);
                    player->takeTurnScript = script;
                    player->takeTurnID = script->id;
                    script->varTable[0] = phi_s0_3;
                    script->owner1.actorID = ACTOR_PLAYER;
                    script->varTable[10] = 0;
                    battleStatus->unk_8C = 1;
                    phi_s0_3 += 8;
                }
            }

            if (battleStatus->itemLossTurns >= 0) {
                battleStatus->itemLossTurns--;
                if (battleStatus->itemLossTurns == -1) {
                    script = start_script(RegainAbility, 0xA, 0);
                    player->takeTurnScript = script;
                    player->takeTurnID = script->id;
                    script->varTable[10] = 2;
                    script->owner1.actorID = ACTOR_PLAYER;
                    script->varTable[0] = phi_s0_3;
                    battleStatus->unk_8C = 1;
                }
            }
            gBattleState2 = BATTLE_STATE2_UNK_1E;
        }
    } else {
        return;
    }

    if (gBattleState2 == BATTLE_STATE2_UNK_1E && (player->onHitScript == NULL || !does_script_exist(player->onHitID))) {
        player->onHitScript = NULL;

        if (!btl_check_player_defeated() && !btl_check_enemies_defeated()) {
            if (D_8029F258 != 0) {
                D_8029F258--;
                return;
            }

            if (D_8029F254 == 0) {
                btl_set_state(BATTLE_STATE2_PLAYER_DEFEATED);
            } else{
                btl_set_state(BATTLE_STATE2_UNK_8);
                gBattleStatus.flags2 |= 2;
            }
        }
    }
}
#else
INCLUDE_ASM(s32, "16F740", btl_state_update_begin_player_turn);
#endif

void btl_state_draw_begin_player_turn(void) {
}

void btl_state_update_switch_to_player(void) {
    Actor* player = gBattleStatus.playerActor;
    Actor* partner = gBattleStatus.partnerActor;
    s32 i;

    if (gBattleState2 == BATTLE_STATE2_UNK_0) {
        gBattleStatus.flags1 &= ~BS_FLAGS1_80000;
        reset_actor_turn_info();
        gBattleStatus.selectedMoveID = MOVE_NONE;
        gBattleStatus.unk_86 = 0x7F;
        gBattleStatus.blockResult = 0x7F;
        gBattleStatus.flags1 |= BS_FLAGS1_8;
        player->flags |= ACTOR_FLAG_8000000;
        if (partner != NULL) {
            partner->flags |= (ACTOR_FLAG_8000000 | ACTOR_FLAG_4000000);
        }

        for (i = 0; i < ARRAY_COUNT(gBattleStatus.enemyActors); i++) {
            Actor* enemy = gBattleStatus.enemyActors[i];
            if (enemy != NULL) {
                enemy->flags |= ENEMY_FLAGS_80000;
                enemy->flags |= ENEMY_FLAGS_8000000;
            }
        }

        btl_set_state(BATTLE_STATE_PREPARE_MENU);
    }
}

void btl_state_draw_switch_to_player(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_begin_partner_turn);

void btl_state_draw_begin_partner_turn(void) {
}

void btl_state_update_switch_to_partner(void) {
    Actor* player = gBattleStatus.playerActor;
    Actor* partner = gBattleStatus.partnerActor;
    s32 i;

    if (gBattleState2 == BATTLE_STATE2_UNK_0) {
        reset_actor_turn_info();
        gBattleStatus.flags1 |= BS_FLAGS1_80000;
        gBattleStatus.selectedMoveID = MOVE_NONE;
        gBattleStatus.unk_86 = 0x7F;
        gBattleStatus.blockResult = 0x7F;
        gBattleStatus.flags1 |= BS_FLAGS1_8;
        player->flags |= (ACTOR_FLAG_8000000 | ACTOR_FLAG_4000000);
        partner->flags |= ACTOR_FLAG_8000000;

        for (i = 0; i < ARRAY_COUNT(gBattleStatus.enemyActors); i++) {
            Actor* enemy = gBattleStatus.enemyActors[i];
            if (enemy != NULL) {
                enemy->flags |= ENEMY_FLAGS_80000;
                enemy->flags |= ENEMY_FLAGS_8000000;
            }
        }

        btl_set_state(BATTLE_STATE_PREPARE_MENU);
    }
}

void btl_state_draw_switch_to_partner(void) {
}

INCLUDE_ASM(s32, "16F740", func_80242FE0);

void func_80243910(void) {
}

void btl_state_update_prepare_menu(void) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->unk_4C[1] = -1;
    battleStatus->unk_4C[2] = -1;
    battleStatus->unk_4C[3] = -1;
    battleStatus->unk_4C[4] = -1;
    battleStatus->unk_4C[5] = -1;
    battleStatus->unk_4C[5] = -1;
    battleStatus->unk_4C[6] = -1;
    battleStatus->unk_4C[7] = -1;
    battleStatus->unk_5C[1] = -1;
    battleStatus->unk_5C[6] = -1;
    battleStatus->unk_5C[7] = -1;

    dma_copy(_415D90_ROM_START, _415D90_ROM_END, _415D90_VRAM);

    if (battleStatus->flags1 & BS_FLAGS1_80000) {
        btl_set_state(BATTLE_STATE_PARTNER_MENU);
    } else if (gBattleState2 == BATTLE_STATE2_UNK_46) {
        btl_set_state(BATTLE_STATE_PLAYER_MENU);
        gBattleState2 = BATTLE_STATE2_UNK_46;
    } else {
        btl_set_state(BATTLE_STATE_PLAYER_MENU);
    }
}

void btl_state_draw_prepare_menu(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_end_turn);

void btl_state_draw_end_turn(void) {
}

void btl_state_update_1C(void) {
    func_8024E40C(2);
    btl_set_state(BATTLE_STATE_PREPARE_MENU);
}

void btl_state_draw_1C(void) {
}

void btl_state_update_victory(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    PlayerData* playerData = &gPlayerData;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    Evt* script;

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_0:
            player->flags &= ~(ACTOR_FLAG_8000000 | ACTOR_FLAG_4000000);
            if (partner != NULL) {
                partner->flags &= ~(ACTOR_FLAG_8000000 | ACTOR_FLAG_4000000);
            }

            battleStatus->unk_8C = 0;
            if (battleStatus->outtaSightActive == 0) {
                gBattleState2 = BATTLE_STATE2_UNK_5;
            } else {
                if (battleStatus->outtaSightActive > 0) {
                    D_8029F254 = 1;
                }
                battleStatus->battlePhase = PHASE_ENEMY_BEGIN;
                script = start_script(partner->onTurnChanceScriptSource, EVT_PRIORITY_A, 0);
                partner->onTurnChangeScript = script;
                partner->onTurnChangeID = script->id;
                script->owner1.actorID = ACTOR_PARTNER;
                gBattleState2 = BATTLE_STATE2_UNK_1;
            }

            break;
        case BATTLE_STATE2_UNK_1:
            if (!does_script_exist(partner->onTurnChangeID)) {
                battleStatus->outtaSightActive = 0;
                gBattleState2 = BATTLE_STATE2_UNK_5;
            }
            break;
    }

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_5:
            player->flags &= ~(ACTOR_FLAG_8000000 | ACTOR_FLAG_4000000);
            if (partner != NULL) {
                partner->flags &= ~(ACTOR_FLAG_8000000 | ACTOR_FLAG_4000000);
            }
            gBattleState2 = BATTLE_STATE2_UNK_B;
            gBattleStatus.flags2 &= ~BS_FLAGS2_2;
            gBattleStatus.flags2 &= ~BS_FLAGS2_4;
            gBattleStatus.flags2 &= ~BS_FLAGS2_8;
            gBattleStatus.flags2 &= ~BS_FLAGS2_10;

            gBattleStatus.flags1 &= ~BS_FLAGS1_8;
            if (player->koStatus == STATUS_DAZE) {
                dispatch_event_player(EVENT_34);
                gBattleState2 = BATTLE_STATE2_PLAYER_DEFEATED;
            }
            player->debuff = 0;
            player->staticStatus = 0;
            player->stoneStatus = 0;
            player->transStatus = 0;
            player->koStatus = 0;
            player->koDuration = 0;
            ((DisableXFXData*)player->debuffEffect->data)->unk_3C = 0;

            if (partner != NULL) {
                if (partner->koStatus == STATUS_DAZE) {
                    dispatch_event_partner(EVENT_34);
                    gBattleState2 = BATTLE_STATE2_PLAYER_DEFEATED;
                }
                partner->debuff = 0;
                partner->staticStatus = 0;
                partner->stoneStatus = 0;
                partner->transStatus = 0;
                partner->koStatus = 0;
                partner->koDuration = 0;
                ((DisableXFXData*)partner->debuffEffect->data)->unk_3C = 0;
            }
            break;
        case BATTLE_STATE2_PLAYER_DEFEATED:
            if (player->onHitScript == NULL || !does_script_exist(player->onHitID)) {
                player->onHitScript = NULL;
                if (partner != NULL) {
                    if (partner->onHitScript == NULL || !does_script_exist(partner->onHitID)) {
                        partner->onHitScript = NULL;
                    } else {
                        break;
                    }
                }
                gBattleState2 = BATTLE_STATE2_UNK_B;
            }
            break;
    }

    if (gBattleState2 == BATTLE_STATE2_UNK_B) {
        if (partner == NULL || !(gBattleStatus.flags1 & BS_FLAGS1_100000)) {
            gBattleState2 = BATTLE_STATE2_UNK_2;
        } else {
            partner->state.currentPos.x = partner->currentPos.x;
            partner->state.currentPos.z = partner->currentPos.z;
            partner->state.goalPos.x = player->currentPos.x;
            partner->state.goalPos.z = player->currentPos.z;
            partner->state.moveTime = 4;
            partner->state.angle = 0.0f;
            gBattleState2 = BATTLE_STATE2_UNK_C;
        }
    }

    if (gBattleState2 == BATTLE_STATE2_UNK_C) {
        if (partner->state.moveTime != 0) {
            partner->currentPos.x += (partner->state.goalPos.x - partner->currentPos.x)
                                                            / partner->state.moveTime;
            partner->currentPos.z += (partner->state.goalPos.z - partner->currentPos.z)
                                                            / partner->state.moveTime;
            player->currentPos.x += (partner->state.currentPos.x - player->currentPos.x)
                                                            / partner->state.moveTime;
            player->currentPos.z += (partner->state.currentPos.z - player->currentPos.z)
                                                            / partner->state.moveTime;
        }
        partner->currentPos.z += sin_rad((partner->state.angle * TAU) / 360.0f) * 16.0f;
        partner->yaw = clamp_angle(-partner->state.angle);
        player->currentPos.z -= sin_rad((partner->state.angle * TAU) / 360.0f) * 16.0f;
        player->yaw = clamp_angle(-partner->state.angle);
        partner->state.angle += 90.0f;

        if (partner->state.moveTime != 0) {
            partner->state.moveTime--;
        } else {
            partner->currentPos.x = partner->state.goalPos.x;
            partner->currentPos.z = partner->state.goalPos.z;
            player->currentPos.x = partner->state.currentPos.x;
            player->currentPos.z = partner->state.currentPos.z;
            partner->homePos.x = partner->currentPos.x;
            partner->homePos.z = partner->currentPos.z;
            player->homePos.x = player->currentPos.x;
            player->homePos.z = player->currentPos.z;
            gBattleState2 = BATTLE_STATE2_UNK_2;
            gBattleStatus.flags1 &= ~BS_FLAGS1_100000;
        }
    }

    if (gBattleState2 == BATTLE_STATE2_UNK_2) {
        func_8024E40C(2);
        if (battleStatus->nextMerleeSpellType == 3) {
            if (battleStatus->totalStarPoints == 0) {
                battleStatus->nextMerleeSpellType = 0;
                playerData->merleeTurnCount = 0;
                playerData->merleeCastsLeft++;
            } else {
                battleStatus->battlePhase = PHASE_MERLEE_EXP_BONUS;
                script = start_script(&PlayerScriptDispatcher, EVT_PRIORITY_A, 0);
                player->takeTurnScript = script;
                player->takeTurnID = script->id;
                script->owner1.actorID = ACTOR_PLAYER;
            }
        }
        gBattleState2 = BATTLE_STATE2_UNK_3;
        D_8029F248 = 0;
        gBattleStatus.flags1 &= ~BS_FLAGS1_2;
    }

    if (gBattleState2 == BATTLE_STATE2_UNK_3) {
        if (D_8029F248 != 0) {
            D_8029F248--;
        } else if (player->takeTurnScript == NULL || !does_script_exist(player->takeTurnID)) {
            player->takeTurnScript = NULL;
            if (battleStatus->nextMerleeSpellType != 3) {
                gBattleState2 = BATTLE_STATE2_UNK_4;
            } else {
                battleStatus->incrementStarPointDelay = 0x14;
                battleStatus->nextMerleeSpellType = 0;
                gBattleState2 = BATTLE_STATE2_UNK_4;
                battleStatus->pendingStarPoints = battleStatus->totalStarPoints
                                        + battleStatus->pendingStarPoints + battleStatus->pendingStarPoints;
            }
        }
    }

    if (gBattleState2 == BATTLE_STATE2_UNK_4 && (s8) battleStatus->pendingStarPoints <= 0) {
        if (gBattleStatus.flags1 & BS_FLAGS1_1000000) {
            gBattleStatus.flags1 &= ~BS_FLAGS1_40000;
        }
        if (playerData->battlesWon < 9999) {
            playerData->battlesWon++;
        }
        if (gBattleStatus.flags1 & BS_FLAGS1_40000) {
            currentEncounter->battleOutcome = OUTCOME_ENEMY_FLED;
        } else {
            currentEncounter->battleOutcome = OUTCOME_PLAYER_WON;
        }
        if (gBattleStatus.flags1 & BS_FLAGS1_20000) {
            if (!(gBattleStatus.flags2 & BS_FLAGS2_2000000)) {
                bgm_set_song(0, -1, 0, 1500, 8);
            }
            btl_set_state(BATTLE_STATE_END_BATTLE);
        } else {
            btl_set_state(BATTLE_STATE_CELEBRATION);
        }
    }
}

void btl_state_draw_victory(void) {
}

void btl_state_update_end_training_battle(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    EncounterStatus* encounterStatus = &gCurrentEncounter;
    Actor* player = gBattleStatus.playerActor;
    Actor* partner = gBattleStatus.partnerActor;

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_0:
            player->flags &= ~(ACTOR_FLAG_8000000 | ACTOR_FLAG_4000000);
            if (partner != NULL) {
                partner->flags &= ~(ACTOR_FLAG_8000000 | ACTOR_FLAG_4000000);
            }
            gBattleState2 = 0xB;
            gBattleStatus.flags2 &= ~BS_FLAGS2_2;
            gBattleStatus.flags2 &= ~BS_FLAGS2_4;
            gBattleStatus.flags2 &= ~BS_FLAGS2_8;
            gBattleStatus.flags2 &= ~BS_FLAGS2_10;

            if (player->koStatus == STATUS_DAZE) {
                dispatch_event_player(EVENT_34);
                gBattleState2 = BATTLE_STATE2_PLAYER_DEFEATED;
            }
            player->debuff = 0;
            player->staticStatus = 0;
            player->stoneStatus = 0;
            player->transStatus = 0;
            player->koStatus = 0;
            player->koDuration = 0;
            ((DisableXFXData*)player->debuffEffect->data)->unk_3C = 0;
            if (partner != NULL) {
                if (partner->koStatus == STATUS_DAZE) {
                    dispatch_event_partner(EVENT_34);
                    gBattleState2 = BATTLE_STATE2_PLAYER_DEFEATED;
                }
                partner->debuff = 0;
                partner->staticStatus = 0;
                partner->stoneStatus = 0;
                partner->transStatus = 0;
                partner->koStatus = 0;
                partner->koDuration = 0;
                ((DisableXFXData*)partner->debuffEffect->data)->unk_3C = 0;
            }
            break;
        case BATTLE_STATE2_PLAYER_DEFEATED:
            if (player->onHitScript == NULL || !does_script_exist(player->onHitID)) {
                player->onHitScript = NULL;
                if (partner != NULL) {
                    if (partner->onHitScript == NULL || !does_script_exist(partner->onHitID)) {
                        partner->onHitScript = NULL;
                    } else {
                        break;
                    }
                }
                gBattleState2 = BATTLE_STATE2_UNK_B;
            }
            break;
    }

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_B:
            battleStatus->unk_8C = 0;
            gBattleStatus.flags2 &= ~BS_FLAGS2_2;
            gBattleStatus.flags2 &= ~BS_FLAGS2_4;
            gBattleStatus.flags2 &= ~BS_FLAGS2_8;
            gBattleStatus.flags2 &= ~BS_FLAGS2_10;

            if (!battleStatus->outtaSightActive) {
                gBattleState2 = BATTLE_STATE2_UNK_D;
            } else {
                Evt* script;

                battleStatus->battlePhase = PHASE_ENEMY_BEGIN;
                script = start_script(partner->onTurnChanceScriptSource, 0xA, 0);
                partner->onTurnChangeScript = script;
                gBattleState2 = BATTLE_STATE2_UNK_C;
                partner->onTurnChangeID = script->id;
                script->owner1.actorID = ACTOR_PARTNER;
            }
            break;
        case BATTLE_STATE2_UNK_D:
            if (!does_script_exist(partner->onTurnChangeID)) {
                battleStatus->outtaSightActive = FALSE;
                gBattleState2 = BATTLE_STATE2_UNK_D;
            }
            break;
    }

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_D:
            func_8024E40C(2);
            D_8029F248 = 30;
            gBattleState2 = BATTLE_STATE2_UNK_E;
            break;
        case BATTLE_STATE2_UNK_E:
            if (D_8029F248 != 0) {
                D_8029F248--;
                return;
            }
            if (playerData->trainingsDone < 9999) {
                playerData->trainingsDone++;
            }
            encounterStatus->battleOutcome = 3;
            if (!(gBattleStatus.flags2 & BS_FLAGS2_2000000)) {
                bgm_set_song(0, -1, 0, 1500, 8);
            }
            btl_set_state(BATTLE_STATE_END_BATTLE);
            break;
    }
}

void btl_state_draw_end_training_battle(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_end_battle);

void btl_state_draw_end_battle(void) {
    Camera* camera = &gCameras[gCurrentCameraID];

    if (gCurrentEncounter.battleOutcome == 1 && !(gBattleStatus.flags1 & BS_FLAGS1_800000)) {
        camera->auxBoomZOffset += 0x100;
        set_screen_overlay_params_front(7, D_80280A30);
    } else {
        set_screen_overlay_params_front(0, D_80280A30);
    }
}

void btl_state_update_defend(void) {
    Actor* player = gBattleStatus.playerActor;
    Evt* script;

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_0:
            gBattleStatus.unk_8C = 0;
            gBattleStatus.battlePhase = PHASE_USE_DEFEND;
            player->takeTurnScript = script = start_script(&PlayerScriptDispatcher, EVT_PRIORITY_A, 0);
            player->takeTurnID = script->id;
            gBattleState2 = BATTLE_STATE2_UNK_1;
            script->owner1.actorID = ACTOR_PLAYER;
            break;
        case BATTLE_STATE2_UNK_1:
            if (!does_script_exist(player->takeTurnID) && gBattleStatus.unk_8C == 0) {
                btl_set_state(BATTLE_STATE_END_PLAYER_TURN);
            }
            break;
    }
}

void btl_state_draw_defend(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_run_away);

void btl_state_draw_run_away(void) {
}

void btl_state_update_defeat(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    Evt* script;

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_0:
            battleStatus->flags1 &= ~BS_FLAGS1_8;
            battleStatus->unk_8C = 0;
            gBattleStatus.flags2 &= ~BS_FLAGS2_2;
            gBattleStatus.flags2 &= ~BS_FLAGS2_4;
            gBattleStatus.flags2 &= ~BS_FLAGS2_8;
            gBattleStatus.flags2 &= ~BS_FLAGS2_10;

            if (player->debuff != 0) {
                if (player->debuff == 7) {
                    sfx_play_sound(SOUND_FROZEN_SHATTER);
                    player->icePillarEffect->flags |= EFFECT_INSTANCE_FLAGS_10;
                    player->icePillarEffect = NULL;
                }
                player->debuff = 0;
                player->debuffDuration = 0;
                remove_status_debuff(player->hudElementDataIndex);
                player->koStatus = 0;
                player->koDuration = 0;
                ((DisableXFXData*)player->debuffEffect->data)->unk_3C = 0;
            }

            func_8024E40C(0x19);
            btl_cam_target_actor(0);
            battleStatus->battlePhase = PHASE_RUN_AWAY_RESET;
            script = start_script(&PlayerScriptDispatcher, EVT_PRIORITY_A, 0);
            player->takeTurnScript = script;
            player->takeTurnID = script->id;
            script->owner1.actorID = ACTOR_PLAYER;

            if (partner != NULL) {
                script = start_script(partner->takeTurnScriptSource, EVT_PRIORITY_A, 0);
                partner->takeTurnScript = script;
                partner->takeTurnID = script->id;
                script->owner1.actorID = ACTOR_PARTNER;
            }
            gBattleState2 = BATTLE_STATE2_UNK_1;
            break;
        case BATTLE_STATE2_UNK_1:
            if (!does_script_exist(player->takeTurnID) && battleStatus->unk_8C == 0) {
                if (find_item(ITEM_LIFE_SHROOM) >= 0) {
                    battleStatus->battlePhase = PHASE_USE_LIFE_SHROOM;
                    script = start_script(&PlayerScriptDispatcher, EVT_PRIORITY_A, 0);
                    player->takeTurnScript = script;
                    player->takeTurnID = script->id;
                    script->owner1.actorID = ACTOR_PLAYER;
                    gBattleState2 = BATTLE_STATE2_UNK_2;
                } else {
                    gBattleState2 = BATTLE_STATE2_PLAYER_DEFEATED;
                }
            }
            break;
        case BATTLE_STATE2_UNK_2:
            if (!does_script_exist(player->takeTurnID) && battleStatus->unk_8C == 0) {
                gBattleState2 = BATTLE_STATE2_PLAYER_DEFEATED;
            }
            break;
    }

    if (gBattleState2 == BATTLE_STATE2_PLAYER_DEFEATED) {
        currentEncounter->battleOutcome = OUTCOME_PLAYER_LOST;
        if (!(gBattleStatus.flags2 & BS_FLAGS2_2000000)) {
            bgm_set_song(0, -1, 0, 0x5DC, 8);
        }
        btl_set_state(BATTLE_STATE_END_BATTLE);
    }
}

void btl_state_draw_defeat(void) {
}

ApiStatus EnablePartnerBlur(Evt* script, s32 isInitialCall) {
    enable_partner_blur();
    return ApiStatus_DONE2;
}

ApiStatus DisablePartnerBlur(Evt* script, s32 isInitialCall) {
    disable_partner_blur();
    return ApiStatus_DONE2;
}

void btl_state_update_change_partner(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    ActorState* state = &player->state;
    PlayerData* playerData = &gPlayerData;
    Actor* enemyActor;
    Evt* script;
    s32 i;

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_0:
            player->flags &= ~ACTOR_FLAG_8000000;
            partner->flags &= ~ACTOR_FLAG_8000000;
            battleStatus->unk_8C = 0;
            gBattleStatus.flags2 |= BS_FLAGS2_10;
            func_8024E40C(0x13);
            btl_cam_set_target_pos(-89.0, 40.0, -99.0);
            btl_cam_set_zoom(0x174);
            btl_cam_set_zoffset(0);
            gBattleStatus.flags1 &= ~BS_FLAGS1_2;

            for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                enemyActor = battleStatus->enemyActors[i];
                if (enemyActor != NULL) {
                    enemyActor->flags &= ~ACTOR_FLAG_80000;
                    enemyActor->flags &= ~ACTOR_FLAG_8000000;
                }
            }

            battleStatus->unk_5C[0] = -1;
            D_8029F248 = 0xA;
            gBattleState2 = BATTLE_STATE2_UNK_2;

        case BATTLE_STATE2_UNK_2:
            if (D_8029F248 != 0) {
                D_8029F248--;
                break;
            }
            deduct_current_move_fp();
            script = start_script(&BtlPutPartnerAway, EVT_PRIORITY_A, 0);
            battleStatus->controlScript = script;
            battleStatus->controlScriptID = script->id;
            script->owner1.actorID = ACTOR_PARTNER;
            state->unk_18.x = partner->currentPos.x;
            state->unk_18.y = 0.0f;
            state->unk_18.z = partner->currentPos.z;
            gBattleState2 = BATTLE_STATE2_UNK_3;
            break;
        case BATTLE_STATE2_UNK_3:
            if (!does_script_exist(battleStatus->controlScriptID)) {
                btl_delete_actor(partner);
                playerData->currentPartner = battleStatus->unk_1AA[2];
                load_partner_actor();
                partner = battleStatus->partnerActor;
                partner->scale.x = 0.1f;
                partner->scale.y = 0.1f;
                partner->scale.z = 0.1f;
                partner->state.goalPos.x = state->unk_18.x;
                partner->state.goalPos.y = partner->currentPos.y;
                partner->state.goalPos.z = state->unk_18.z;
                partner->currentPos.x = player->currentPos.x;
                partner->currentPos.y = player->currentPos.y + 25.0f;
                partner->currentPos.z = player->currentPos.z;
                gBattleState2 = BATTLE_STATE2_UNK_4;
            }
            break;
        case BATTLE_STATE2_UNK_4:
            partner = battleStatus->partnerActor;
            if (partner != NULL) {
                if (!does_script_exist(partner->takeTurnID)) {
                    partner->takeTurnScript = NULL;
                } else {
                    break;
                }
            }

            script = start_script(&BtlBringPartnerOut, EVT_PRIORITY_A, 0);
            battleStatus->controlScript = script;
            battleStatus->controlScriptID = script->id;
            script->owner1.actorID = ACTOR_PARTNER;
            gBattleState2 = BATTLE_STATE2_UNK_5;
            break;
        case BATTLE_STATE2_UNK_5:
            if (!does_script_exist(battleStatus->controlScriptID)) {
                partner = battleStatus->partnerActor;
                if (partner != NULL) {
                    if (partner->onTurnChanceScriptSource != NULL) {
                        battleStatus->battlePhase = PHASE_PLAYER_BEGIN;
                        script = start_script(partner->onTurnChanceScriptSource, EVT_PRIORITY_A, 0);
                        partner->onTurnChangeScript = script;
                        partner->onTurnChangeID = script->id;
                        script->owner1.actorID = ACTOR_PARTNER;
                    }
                }
                gBattleState2 = BATTLE_STATE2_UNK_6;
            }
            break;
        case BATTLE_STATE2_UNK_6:
            partner = battleStatus->partnerActor;
            if (partner == NULL || partner->onTurnChanceScriptSource == NULL
                                || !does_script_exist(partner->onTurnChangeID)) {
                func_8024E40C(2);
                gBattleState2 = BATTLE_STATE2_UNK_7;
            }
            break;
        case BATTLE_STATE2_UNK_7:
            if (battleStatus->unk_8C == 0) {
                gBattleStatus.flags2 &= ~BS_FLAGS2_10;
                if (!(gBattleStatus.flags1 & BS_FLAGS1_80000)) {
                    if (player_team_is_ability_active(player, ABILITY_QUICK_CHANGE) != FALSE) {
                        btl_set_state(BATTLE_STATE_PREPARE_MENU);
                    } else {
                        btl_set_state(BATTLE_STATE_END_PLAYER_TURN);
                    }
                } else {
                    if (player_team_is_ability_active(player, ABILITY_QUICK_CHANGE) == FALSE) {
                        btl_set_state(BATTLE_STATE_END_PARTNER_TURN);
                    } else {
                        btl_set_state(BATTLE_STATE_PREPARE_MENU);
                    }
                }
            }
            break;
    }
}

void btl_state_draw_change_partner(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_player_move);

void btl_state_draw_player_move(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_end_player_turn);

void btl_state_draw_end_player_turn(void) {
}


void btl_state_update_partner_move(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* enemyActor;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    Evt* script;
    s8 switchCondition;
    s32 phi_s3;
    s32 phi_s0;
    s32 i;

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_0:
            if (partner == NULL) {
                btl_set_state(BATTLE_STATE_9);
            } else {
                battleStatus->unk_8C = 0;
                battleStatus->unk_86 = 0x7F;
                battleStatus->blockResult = 0x7F;
                battleStatus->unk_19A = 0;
                gBattleStatus.flags1 &= ~BS_FLAGS1_1000;
                gBattleStatus.flags1 &= ~BS_FLAGS1_2;
                reset_actor_turn_info();
                partner->status = 0;
                partner->flags &= ~ACTOR_FLAG_8000000;
                player->flags &= ~ACTOR_FLAG_8000000;
                deduct_current_move_fp();
                btl_cam_target_actor(0x100);
                gBattleStatus.flags2 |= BS_FLAGS2_10;
                gBattleStatus.flags1 &= ~BS_FLAGS1_200000;

                for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                    enemyActor = battleStatus->enemyActors[i];
                    if (enemyActor != NULL) {
                        enemyActor->status = 0;
                    }
                }
                func_8024E40C(2);
                gBattleState2 = BATTLE_STATE2_UNK_2;
            }
            break;
        case BATTLE_STATE2_UNK_2:
            for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                enemyActor = battleStatus->enemyActors[i];
                if (enemyActor != NULL) {
                    enemyActor->flags &= ~ACTOR_FLAG_80000;
                    enemyActor->flags &= ~ACTOR_FLAG_8000000;
                }
            }

            increment_status_menu_disabled();
            gBattleStatus.flags1 |= BS_FLAGS1_100;
            reset_actor_turn_info();
            reset_all_actor_sounds(partner);
            battleStatus->battlePhase = PHASE_EXECUTE_ACTION;
            script = start_script(partner->takeTurnScriptSource, EVT_PRIORITY_A, 0);
            partner->takeTurnScript = script;
            partner->takeTurnID = script->id;
            script->owner1.actorID = ACTOR_PARTNER;
            gBattleState2 = BATTLE_STATE2_UNK_3;
            break;
        case BATTLE_STATE2_UNK_3:
            if (!(gBattleStatus.flags1 & BS_FLAGS1_200000)) {
                if (partner->takeTurnScript == NULL || !does_script_exist(partner->takeTurnID)) {
                    partner->takeTurnScript = NULL;
                } else {
                    break;
                }
            }
            gBattleStatus.flags1 &= ~BS_FLAGS1_100;

            if ((partner->onHitScript == NULL || !does_script_exist(partner->onHitID))
                && ((partner->onHitScript = NULL, player->onHitScript == NULL)
                    || !does_script_exist(player->onHitID))) {

                player->onHitScript = NULL;
                for (phi_s3 = FALSE, i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                    enemyActor = battleStatus->enemyActors[i];
                    if (enemyActor != NULL && enemyActor->takeTurnScript != NULL) {
                        if (does_script_exist(enemyActor->takeTurnID)) {
                            phi_s3 = TRUE;
                        } else {
                            enemyActor->takeTurnScript = NULL;
                        }
                    }
                }

                if (phi_s3 == FALSE) {
                    for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                        enemyActor = battleStatus->enemyActors[i];
                        if (enemyActor != NULL && enemyActor->onHitScript != NULL) {
                            if (does_script_exist(enemyActor->onHitID)) {
                                phi_s3 = TRUE;
                            } else {
                                enemyActor->onHitScript = NULL;
                            }
                        }
                    }

                    if (phi_s3 == FALSE) {
                        for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                            enemyActor = battleStatus->enemyActors[i];
                            if (enemyActor != NULL) {
                                enemyActor->flags &= ~ACTOR_FLAG_80000;
                            }
                        }
                        if (battleStatus->unk_8C == 0) {
                            if (gGameStatusPtr->demoFlags & 1) {
                                btl_set_state(BATTLE_STATE_END_DEMO_BATTLE);
                                break;
                            }
                            decrement_status_menu_disabled();
                            if (playerData->currentPartner == PARTNER_GOOMBARIO && battleStatus->moveCategory == 5
                                                                && battleStatus->selectedMoveID != MOVE_CHARGE) {
                                partner->isGlowing = 0;
                                gBattleStatus.flags1 &= ~BS_FLAGS1_40000000;
                            }
                            if (btl_check_player_defeated() == FALSE) {
                                for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                                    enemyActor = battleStatus->enemyActors[i];
                                    if (enemyActor != NULL) {
                                        if (!(enemyActor->flags & ACTOR_FLAG_NO_DMG_APPLY)) {
                                            enemyActor->flags |= (ACTOR_FLAG_8000000 | ACTOR_FLAG_4000000);
                                        }
                                    }
                                }

                                btl_update_ko_status();

                                if ((s8) partner->status == 0xD && btl_are_all_enemies_defeated() == FALSE) {
                                    func_8024E40C(0x36);
                                    btl_show_battle_message(0x23, 0x3C);
                                    partner->status = 0;
                                    partner->unk_21D = 0;
                                    gBattleState2 = BATTLE_STATE2_UNK_B;
                                    partner->flags |= ACTOR_FLAG_8000000;
                                } else {
                                    gBattleState2 = BATTLE_STATE2_UNK_14;
                                }
                            } else {
                                return;
                            }
                        }
                    }
                }
            }
            break;
        case BATTLE_STATE2_UNK_B:
            if (btl_is_popup_displayed() == FALSE) {
                func_8024E40C(2);
                btl_cam_move(0xF);
                D_8029F248 = 0xA;
                gBattleState2 = BATTLE_STATE2_UNK_C;
            }
            break;
        case BATTLE_STATE2_UNK_C:
            if (D_8029F248 != 0) {
                D_8029F248--;
            } else {
                gBattleState2 = BATTLE_STATE2_UNK_14;
            }
            break;
    }

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_14:
            for (phi_s3 = FALSE, i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                enemyActor = battleStatus->enemyActors[i];
                if (enemyActor != NULL) {
                    if ((s8)enemyActor->status != 0) {
                        phi_s3 = TRUE;
                        break;
                    }
                }
            }

            if (phi_s3 == FALSE) {
                gBattleState2 = BATTLE_STATE2_UNK_1E;
            } else {
                func_8024E40C(3);
                switchCondition = enemyActor->status - 4;
                switch (switchCondition) {
                    case 0:
                        phi_s0 = 0x12;
                        break;
                    case 2:
                        phi_s0 = 0x13;
                        break;
                    case 3:
                        phi_s0 = 0x14;
                        break;
                    case 5:
                        phi_s0 = 0x15;
                        break;
                    case 6:
                        phi_s0 = 0x16;
                        break;
                    case 1:
                        phi_s0 = 0x17;
                        break;
                    case 7:
                        phi_s0 = 0x18;
                        break;
                    case 4:
                        phi_s0 = 0x19;
                        break;
                    default:
                        phi_s0 = 0;
                        gBattleState2 = BATTLE_STATE2_UNK_14;
                        break;
                }

                sfx_play_sound(SOUND_2107);
                btl_show_battle_message(phi_s0, 0x3C);

                for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                    enemyActor = battleStatus->enemyActors[i];
                    if (enemyActor != NULL) {
                        enemyActor->status = 0;
                    }
                }
                gBattleState2 = BATTLE_STATE2_UNK_15;
            }
            break;
        case BATTLE_STATE2_UNK_15:
            if (btl_is_popup_displayed() == FALSE) {
                func_8024E40C(2);
                btl_cam_move(0xF);
                D_8029F248 = 10;
                gBattleState2 = BATTLE_STATE2_UNK_16;
            }
            break;
        case BATTLE_STATE2_UNK_16:
            if (D_8029F248 != 0) {
                D_8029F248--;
            } else {
                gBattleState2 = BATTLE_STATE2_UNK_1E;
            }
            break;
    }

    if (gBattleState2 == BATTLE_STATE2_UNK_1E && (partner->takeTurnScript == NULL ||
                                  !does_script_exist(partner->takeTurnID))) {
        partner->takeTurnScript = NULL;
        btl_set_state(BATTLE_STATE_END_PARTNER_TURN);
    }
}

void btl_state_draw_partner_move(void) {
}

void btl_state_update_end_partner_turn(void) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (gBattleState2 == BATTLE_STATE2_UNK_0) {
        battleStatus->flags2 |= BS_FLAGS2_4;
        if (!btl_check_enemies_defeated()) {
            battleStatus->flags1 &= ~BS_FLAGS1_80000;
            battleStatus->flags2 &= ~BS_FLAGS2_10;

            if (battleStatus->unk_94 < 0) {
                battleStatus->unk_94 = 0;
                btl_set_state(BATTLE_STATE_END_TURN);
            } else {
                btl_set_state(BATTLE_STATE_9);
            }
        }
    }
}

void btl_state_draw_end_partner_turn(void) {
}

void btl_state_update_next_enemy(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = gBattleStatus.playerActor;
    Actor* partner = gBattleStatus.partnerActor;
    Actor* enemy;
    s32 cond;
    s32 i;

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_0:
        case BATTLE_STATE2_UNK_1:
            i = battleStatus->nextEnemyIndex;
            if (i >= battleStatus->numEnemyActors) {
                battleStatus->nextEnemyIndex = 0;
                btl_set_state(BATTLE_STATE_END_TURN);
                return;
            }

            while (TRUE) {
                if (battleStatus->enemyIDs[i] >= 0) {
                    u16 enemyID = battleStatus->enemyIDs[i];

                    enemy = battleStatus->enemyActors[enemyID & 0xFF];
                    if (enemy != NULL) {
                        if (!(enemy->flags & (ACTOR_FLAG_NO_ATTACK | ACTOR_FLAG_TARGET_ONLY))) {
                            break;
                        }
                    }
                }
                i++;
                if (i >= battleStatus->numEnemyActors) {
                    i = 0;
                }
                if (i == 0) {
                    battleStatus->nextEnemyIndex = 0;
                    btl_set_state(BATTLE_STATE_END_TURN);
                    return;
                }
            }

            battleStatus->activeEnemyActorID = battleStatus->enemyIDs[i++];
            battleStatus->currentTurnEnemy = enemy;
            battleStatus->nextEnemyIndex = i;

            cond = enemy->debuff == STATUS_SLEEP;
            if (enemy->debuff == STATUS_FEAR) {
                cond = TRUE;
            }
            if (enemy->debuff == STATUS_DIZZY) {
                cond = TRUE;
            }
            if (enemy->debuff == STATUS_PARALYZE) {
                cond = TRUE;
            }
            if (enemy->debuff == STATUS_FROZEN) {
                cond = TRUE;
            }
            if (enemy->debuff == STATUS_STOP) {
                cond = TRUE;
            }
            if (enemy->stoneStatus == STATUS_STONE) {
                cond = TRUE;
            }
            if (enemy->flags & ACTOR_FLAG_10000) {
                cond = TRUE;
            }
            if (cond) {
                gBattleState2 = BATTLE_STATE2_UNK_0;
                return;
            }

            battleStatus->unk_8C = 0;
            gBattleStatus.flags1 &= ~BS_FLAGS1_2;
            gBattleStatus.flags1 &= ~BS_FLAGS1_40000;
            gBattleStatus.flags1 &= ~BS_FLAGS1_1000;
            gBattleStatus.flags1 &= ~BS_FLAGS1_80000;

            player->flags &= ~ACTOR_FLAG_8000000;
            player->flags |= ACTOR_FLAG_4000000;

            if (partner != NULL) {
                partner->flags &= ~ACTOR_FLAG_8000000;
                partner->flags |= ACTOR_FLAG_4000000;
            }

            gBattleStatus.flags2 &= ~BS_FLAGS2_2;
            gBattleStatus.flags2 &= ~BS_FLAGS2_4;
            gBattleStatus.flags2 |= BS_FLAGS2_10000;

            D_8029F244 = enemy->unk_134;
            if (enemy->onTurnChanceScriptSource != NULL) {
                Evt* onTurnChanceScript;

                battleStatus->battlePhase = PHASE_ENEMY_BEGIN;
                onTurnChanceScript = start_script(enemy->onTurnChanceScriptSource, 0xA, 0);
                enemy->onTurnChangeScript = onTurnChanceScript;
                enemy->onTurnChangeID = onTurnChanceScript->id;
                onTurnChanceScript->owner1.actorID = battleStatus->activeEnemyActorID;
            }
            gBattleState2 = BATTLE_STATE2_UNK_2;
            break;
        case BATTLE_STATE2_UNK_2:
            if (battleStatus->unk_8C == 0) {
                enemy = get_actor(battleStatus->activeEnemyActorID);

                if (enemy != NULL && enemy->unk_134 == D_8029F244) {
                    if (enemy->onTurnChanceScriptSource == NULL || !does_script_exist(enemy->onTurnChangeID)) {
                        if (battleStatus->unk_94 < 0) {
                            battleStatus->unk_94 = 0;
                            btl_set_state(BATTLE_STATE_END_TURN);
                        } else {
                            btl_set_state(BATTLE_STATE_ENEMY_MOVE);
                        }
                    }
                } else {
                    btl_set_state(BATTLE_STATE_NEXT_ENEMY);
                }
            }
            break;
    }
}

void btl_state_draw_next_enemy(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_enemy_move);

void btl_state_draw_enemy_move(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_first_strike);

void btl_state_draw_first_stike(void) {
    if (D_802809F6 == -1 && D_8029F254 != 0) {
        if (D_80280A30 == 0) {
            set_screen_overlay_params_front(255, -1.0f);
        } else {
            if (!(gGameStatusPtr->demoFlags & 1)) {
                D_80280A30 -= 20;
            } else {
                D_80280A30 -= 50;
            }

            if (D_80280A30 < 0) {
                D_80280A30 = 0;
            }
            set_screen_overlay_params_front(0, D_80280A30);
        }
    }
}

INCLUDE_ASM(s32, "16F740", btl_state_update_partner_striking_first);

void btl_state_draw_partner_striking_first(void) {
    if (D_8029F254 != 0) {
        if (D_80280A30 == 0) {
            set_screen_overlay_params_front(255, -1.0f);
        } else {
            D_80280A30 -= 20;
            if (D_80280A30 < 0) {
                D_80280A30 = 0;
            }

            set_screen_overlay_params_front(0, D_80280A30);
        }
    }
}

INCLUDE_ASM(s32, "16F740", btl_state_update_enemy_striking_first);

void btl_state_draw_enemy_striking_first(void) {
    if (D_8029F254 != 0) {
        if (D_80280A30 == 0) {
            set_screen_overlay_params_front(255, -1.0f);
        } else {
            D_80280A30 -= 20;
            if (D_80280A30 < 0) {
                D_80280A30 = 0;
            }

            set_screen_overlay_params_front(0, D_80280A30);
        }
    }
}

void btl_state_update_end_demo_battle(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Battle* blah = (*D_800DC4FC);
    Stage* stage;
    s32 i;

    switch (gBattleState2) {
        case 0:
            D_80280A30 = 0;
            if (D_802809F6 == -1) {
                if (D_802809F8 != 0) {
                    D_802809F8--;
                    break;
                }
            }
            gBattleState2 = BATTLE_STATE2_UNK_1;
            break;
        case 1:
            switch (D_802809F6) {
                case 255:
                    gBattleState2 = BATTLE_STATE2_UNK_2;
                    return;
                case -1:
                    if (D_80280A30 == 0xFF) {
                        gBattleState2 = BATTLE_STATE2_UNK_2;
                        return;
                    }
                    D_80280A30 += 50;
                    if (D_80280A30 > 0xFF) {
                        D_80280A30 = 0xFF;
                    }
                    return;
            }
            break;
        case 2:
            D_80280A30 = 0xFF;
            gBattleStatus.flags1 &= ~BS_FLAGS1_1;
            if (D_800DC064 == NULL) {
                stage = blah->stage;
            } else {
                stage = D_800DC064[1]; // TODO cleanup
            }

            if (stage->postBattle == NULL) {
                gBattleState2 = BATTLE_STATE2_UNK_4;
            } else {
                battleStatus->controlScript = start_script(stage->postBattle, 0xA, 0);
                gBattleState2 = BATTLE_STATE2_UNK_3;
                battleStatus->controlScriptID = battleStatus->controlScript->id;
            }
            break;
        case 3:
            if (does_script_exist(battleStatus->controlScriptID)) {
                break;
            }
            gBattleState2 = BATTLE_STATE2_UNK_4;
        case 4:
            kill_all_scripts();

            for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                Actor* enemy = battleStatus->enemyActors[i];

                if (enemy != NULL) {
                    btl_delete_actor(enemy);
                }
            }

            if (battleStatus->partnerActor != NULL) {
                btl_delete_actor(battleStatus->partnerActor);
            }

            btl_delete_player_actor(battleStatus->playerActor);
            remove_all_effects();
            set_windows_visible(WINDOW_GROUP_ALL);

            if (gBattleStatus.flags2 & BS_FLAGS2_40) {
                decrement_status_menu_disabled();
            }

            if (D_802809F6 != -1) {
                gGameStatusPtr->nextDemoScene = 0x12;
            }

            btl_set_state(BATTLE_STATE_0);
            D_800DC4D0 = gBattleState;
            set_game_mode(GAME_MODE_END_BATTLE);
            break;
    }
}

const static f32 padding[] = { 0.0f, 0.0f, 0.0f };

void btl_state_draw_end_demo_battle(void) {
    if (D_802809F6 == -1) {
        set_screen_overlay_color(0, 0, 0, 0);
        set_screen_overlay_params_front(0, D_80280A30);
    }
}
