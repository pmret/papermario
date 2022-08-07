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
extern u8 D_8029F244;
extern s32 D_8029F248;
extern s32 D_8029F24C;
extern s32 D_8029F250;
extern s32 D_8029F254;
extern s32 D_8029F258;
extern s32 D_8029F25C;
extern s32 D_8029F260;
extern s32 D_8029F264;

void btl_merlee_on_start_turn(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    PlayerData* playerData = &gPlayerData;

    do {
        if (!(gBattleStatus.flags2 & BS_FLAGS2_40) &&
            battleStatus->nextMerleeSpellType != 3 &&
            battleStatus->nextMerleeSpellType != 4 &&
            playerData->merleeCastsLeft > 0)
        {
            if (playerData->merleeTurnCount <= 0) {
                s32 temp = rand_int(100);

                if (currentEncounter->currentEnemy != NULL) {
                    if (currentEncounter->currentEnemy->flags & ENEMY_FLAGS_40000) {
                        if (temp <= 45) {
                            playerData->merleeSpellType = 1;
                        } else if (temp <= 90) {
                            playerData->merleeSpellType = 2;
                        } else {
                            playerData->merleeSpellType = 3;
                        }
                    } else if (temp <= 30) {
                        playerData->merleeSpellType = 1;
                    } else if (temp <= 60) {
                        playerData->merleeSpellType = 2;
                    } else if (temp <= 80) {
                        playerData->merleeSpellType = 3;
                    } else {
                        playerData->merleeSpellType = 4;
                    }
                } else if (temp <= 30) {
                    playerData->merleeSpellType = 1;
                } else if (temp <= 60) {
                    playerData->merleeSpellType = 2;
                } else if (temp <= 80) {
                    playerData->merleeSpellType = 3;
                } else {
                    playerData->merleeSpellType = 4;
                }

                temp = rand_int(10) + 6;
                playerData->merleeTurnCount = temp;
            }

            if (playerData->merleeTurnCount >= 2) {
                playerData->merleeTurnCount--;
            } else {
                playerData->merleeTurnCount = 0;
                battleStatus->nextMerleeSpellType = playerData->merleeSpellType;
                playerData->merleeCastsLeft--;
            }
        }
    } while (0); // TODO: required to match
}

void btl_merlee_on_first_strike(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    PlayerData* playerData = &gPlayerData;

    do {
        if (!(gBattleStatus.flags2 & BS_FLAGS2_40) &&
            battleStatus->nextMerleeSpellType != 3 &&
            battleStatus->nextMerleeSpellType != 4 &&
            playerData->merleeCastsLeft > 0)
        {
            if (playerData->merleeTurnCount <= 0) {
                s32 temp = rand_int(100);

                if (currentEncounter->currentEnemy != NULL) {
                    if (currentEncounter->currentEnemy->flags & ENEMY_FLAGS_40000) {
                        if (temp <= 45) {
                            playerData->merleeSpellType = 1;
                        } else if (temp <= 90) {
                            playerData->merleeSpellType = 2;
                        } else {
                            playerData->merleeSpellType = 3;
                        }
                    } else if (temp <= 30) {
                        playerData->merleeSpellType = 1;
                    } else if (temp <= 60) {
                        playerData->merleeSpellType = 2;
                    } else if (temp <= 80) {
                        playerData->merleeSpellType = 3;
                    } else {
                        playerData->merleeSpellType = 4;
                    }
                } else if (temp <= 30) {
                    playerData->merleeSpellType = 1;
                } else if (temp <= 60) {
                    playerData->merleeSpellType = 2;
                } else if (temp <= 80) {
                    playerData->merleeSpellType = 3;
                } else {
                    playerData->merleeSpellType = 4;
                }

                if (playerData->merleeSpellType != 4) {
                    // same outcome either way. has to be written like this, and the check does exist in the code. bug?
                    if (playerData->merleeTurnCount == -1) {
                        temp = rand_int(5) + 5;
                    } else {
                        temp = rand_int(5) + 5;

                    }
                } else {
                    temp = rand_int(8) + 5;
                }
                playerData->merleeTurnCount = temp;
            }

            if (playerData->merleeSpellType == 3 || playerData->merleeSpellType == 4) {
                if (playerData->merleeTurnCount >= 2) {
                    playerData->merleeTurnCount--;
                } else {
                    battleStatus->nextMerleeSpellType = playerData->merleeSpellType;
                    playerData->merleeTurnCount = 0;
                    playerData->merleeCastsLeft--;
                }
            }
        }
    } while (0); // TODO: required to match
}

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
        btl_cam_use_preset(BTL_CAM_PRESET_C);
        btl_cam_move(5);
        gBattleState2 = BATTLE_STATE2_UNK_64;
    }

    if (gBattleState2 != BATTLE_STATE2_UNK_14) {
        if (gBattleState2 == BATTLE_STATE2_UNK_64 && btl_cam_is_moving_done()) {
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
                script = start_script(partner->onTurnChanceScriptSource, EVT_PRIORITY_A, 0);
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
                    sfx_play_sound(SOUND_299);
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
                            sfx_play_sound(SOUND_FROZEN_SHATTER);
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
                    player->debuffEffect->data.disableX->unk_3C = player->koDuration;
                } else if (koDuration != (s8) debuffDuration) {
                    player->koStatus = 0;
                    player->koDuration = 0;
                    player->debuffEffect->data.disableX->unk_3C = 0;
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
                    script = start_script(RegainAbility, EVT_PRIORITY_A, 0);
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
                    script = start_script(RegainAbility, EVT_PRIORITY_A, 0);
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
                    script = start_script(RegainAbility, EVT_PRIORITY_A, 0);
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
                btl_set_state(BATTLE_STATE_SWITCH_TO_PLAYER);
            } else{
                btl_set_state(BATTLE_STATE_BEGIN_PARTNER_TURN);
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

void btl_state_update_begin_partner_turn(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* partner = battleStatus->partnerActor;
    Actor* enemy;
    s32 i;

    if (gBattleState2 == BATTLE_STATE2_UNK_0) {
        if (partner == NULL) {
            D_8029F254 = 1;
            gBattleState2 = BATTLE_STATE2_PLAYER_DEFEATED;
        } else if ((battleStatus->flags2 & (BS_FLAGS2_4 | BS_FLAGS2_2)) != (BS_FLAGS2_4 | BS_FLAGS2_2)) {
            if (!(partner->flags & ACTOR_FLAG_NO_ATTACK)) {
                btl_cam_use_preset(2);
                btl_cam_move(5);
                gBattleState2 = BATTLE_STATE2_UNK_64;
            } else {
                btl_set_state(BATTLE_STATE_9);
                return;
            }
        } else {
            btl_set_state(BATTLE_STATE_9);
            return;
        }
    }

    if (gBattleState2 == BATTLE_STATE2_UNK_64) {
        if (btl_cam_is_moving_done()) {
            D_8029F258 = 0;
            reset_actor_turn_info();
            partner = battleStatus->partnerActor;
            battleStatus->unk_86 = 0x7F;
            battleStatus->blockResult = 0x7F;
            D_8029F254 = 0;
            gBattleStatus.flags1 |= BS_FLAGS1_80000;
            gBattleStatus.flags2 |= BS_FLAGS1_100000;
            partner->flags |= ACTOR_FLAG_8000000;

            if (partner->koStatus != 0) {
                partner->koDuration--;
                D_8029F254 = 1;
                D_8029F258 = 20;
                if (partner->koDuration > 0) {
                    partner->debuffEffect->data.disableX->unk_3C = partner->koDuration;
                } else {
                    partner->koStatus = 0;
                    dispatch_event_partner(EVENT_RECOVER_PARTNER);
                    partner->debuffEffect->data.disableX->unk_3C = 0;
                    gBattleStatus.flags2 |= BS_FLAGS2_8;
                }
            }

            for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                enemy = battleStatus->enemyActors[i];
                if (enemy != NULL) {
                    enemy->flags |= ACTOR_FLAG_8000000 | ACTOR_FLAG_4000000;
                }
            }
            gBattleState2 = BATTLE_STATE2_UNK_1;
        }
    }

    if (gBattleState2 == BATTLE_STATE2_UNK_1) {
        if (partner != NULL) {
            if (partner->onHitScript == NULL || !does_script_exist(partner->onHitID)) {
                partner->onHitScript = NULL;
            } else {
                goto block_27; // TODO find a way to remove
            }
        }

        gBattleStatus.flags2 &= ~BS_FLAGS2_8;
        if (btl_check_player_defeated() || btl_check_enemies_defeated()) {
            return;
        }
        gBattleState2 = BATTLE_STATE2_UNK_8;
    }

block_27:
    if (gBattleState2 == BATTLE_STATE2_UNK_8) {
        if (partner->onTurnChanceScriptSource != NULL) {
            Evt* script;

            battleStatus->battlePhase = 0xC;
            script = start_script(partner->onTurnChanceScriptSource, EVT_PRIORITY_A, 0);
            partner->onTurnChangeScript = script;
            partner->onTurnChangeID = script->id;
            script->owner1.actorID = ACTOR_PARTNER;
        }
        gBattleState2 = BATTLE_STATE2_UNK_9;
    }

    if (gBattleState2 == BATTLE_STATE2_UNK_9 &&
        (partner->onTurnChanceScriptSource == NULL || !does_script_exist(partner->onTurnChangeID)))
    {
        gBattleState2 = BATTLE_STATE2_PLAYER_DEFEATED;
    }

    if (gBattleState2 == BATTLE_STATE2_PLAYER_DEFEATED) {
        if (D_8029F258 != 0) {
            D_8029F258--;
            return;
        }
        gBattleStatus.flags2 &= ~BS_FLAGS2_100000;
        if (D_8029F254 == 0) {
            btl_set_state(BATTLE_STATE_SWITCH_TO_PARTNER);
        } else {
            gBattleStatus.flags2 |= BS_FLAGS2_4;
            btl_set_state(BATTLE_STATE_9);
        }
    }
}

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
    btl_cam_use_preset(BTL_CAM_PRESET_C);
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
                dispatch_event_player(EVENT_RECOVER_PARTNER);
                gBattleState2 = BATTLE_STATE2_PLAYER_DEFEATED;
            }
            player->debuff = 0;
            player->staticStatus = 0;
            player->stoneStatus = 0;
            player->transStatus = 0;
            player->koStatus = 0;
            player->koDuration = 0;
            player->debuffEffect->data.disableX->unk_3C = 0;

            if (partner != NULL) {
                if (partner->koStatus == STATUS_DAZE) {
                    dispatch_event_partner(EVENT_RECOVER_PARTNER);
                    gBattleState2 = BATTLE_STATE2_PLAYER_DEFEATED;
                }
                partner->debuff = 0;
                partner->staticStatus = 0;
                partner->stoneStatus = 0;
                partner->transStatus = 0;
                partner->koStatus = 0;
                partner->koDuration = 0;
                partner->debuffEffect->data.disableX->unk_3C = 0;
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
        btl_cam_use_preset(BTL_CAM_PRESET_C);
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
                dispatch_event_player(EVENT_RECOVER_PARTNER);
                gBattleState2 = BATTLE_STATE2_PLAYER_DEFEATED;
            }
            player->debuff = 0;
            player->staticStatus = 0;
            player->stoneStatus = 0;
            player->transStatus = 0;
            player->koStatus = 0;
            player->koDuration = 0;
            player->debuffEffect->data.disableX->unk_3C = 0;
            if (partner != NULL) {
                if (partner->koStatus == STATUS_DAZE) {
                    dispatch_event_partner(EVENT_RECOVER_PARTNER);
                    gBattleState2 = BATTLE_STATE2_PLAYER_DEFEATED;
                }
                partner->debuff = 0;
                partner->staticStatus = 0;
                partner->stoneStatus = 0;
                partner->transStatus = 0;
                partner->koStatus = 0;
                partner->koDuration = 0;
                partner->debuffEffect->data.disableX->unk_3C = 0;
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
                script = start_script(partner->onTurnChanceScriptSource, EVT_PRIORITY_A, 0);
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
            btl_cam_use_preset(BTL_CAM_PRESET_C);
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

void btl_state_update_end_battle(void) {
    Battle* blah = (*D_800DC4FC);
    EncounterStatus* encounterStatus = &gCurrentEncounter;
    BattleStatus* battleStatus = &gBattleStatus;
    Stage* stage;
    Evt* script;
    s32 i;

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_0:
            D_80280A30 = 0;
            if (gGameStatusPtr->debugEnemyContact == 2) {
                D_80280A30 = 255;
            }
            if (encounterStatus->battleOutcome == 1 && !(gBattleStatus.flags1 & BS_FLAGS1_800000)) {
                btl_cam_unfreeze();
                btl_cam_use_preset(BTL_CAM_PRESET_B);
                set_screen_overlay_color(0, 0, 0, 0);
                set_screen_overlay_center(0, 0, 160, 120);
            }
            gBattleState2 = BATTLE_STATE2_UNK_1;
            break;
        case BATTLE_STATE2_UNK_1:
            if (D_80280A30 == 255) {
                gBattleState2 = BATTLE_STATE2_UNK_2;
                break;
            }
            D_80280A30 += battleStatus->unk_8D;
            if (D_80280A30 > 255) {
                D_80280A30 = 255;
            }
            break;
        case BATTLE_STATE2_UNK_2:
            D_80280A30 = 255;
            gBattleStatus.flags1 &= ~BS_FLAGS1_1;
            if (D_800DC064 == NULL) {
                stage = blah->stage;
            } else {
                stage = D_800DC064[1];
            }
            if (stage->postBattle == NULL) {
                gBattleState2 = BATTLE_STATE2_UNK_4;
                return;
            }
            script = start_script(stage->postBattle, EVT_PRIORITY_A, 0);
            battleStatus->controlScript = script;
            gBattleState2 = BATTLE_STATE2_UNK_3;
            battleStatus->controlScriptID = script->id;
            break;
        case BATTLE_STATE2_UNK_3:
            if (!does_script_exist(battleStatus->controlScriptID)) {
                gBattleState2 = BATTLE_STATE2_UNK_4;
                // fallthrough
            } else {
                break;
            }
        case BATTLE_STATE2_UNK_4:
            kill_all_scripts();
            for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                if (battleStatus->enemyActors[i] != NULL) {
                    btl_delete_actor(battleStatus->enemyActors[i]);
                }
            }
            if (battleStatus->partnerActor != NULL) {
                btl_delete_actor(battleStatus->partnerActor);
            }

            btl_delete_player_actor(battleStatus->playerActor);

            if (battleStatus->nextMerleeSpellType == 4) {
                encounterStatus->merleeCoinBonus = 1;
                battleStatus->nextMerleeSpellType = 0;
            }

            encounterStatus->damageTaken = battleStatus->damageTaken;

            if (gBattleStatus.flags2 & BS_FLAGS2_10000000) {
                encounterStatus->dropWhackaBump = 1;
            }

            remove_all_effects();
            set_windows_visible(0);

            if (gBattleStatus.flags2 & BS_FLAGS2_40) {
                decrement_status_menu_disabled();
            }

            if (encounterStatus->battleOutcome == OUTCOME_PLAYER_LOST &&
                !(gBattleStatus.flags1 & BS_FLAGS1_800000))
            {
                s16 areaID;
                s16 mapID;

                btl_set_state(BATTLE_STATE_0);
                D_800DC4D0 = gBattleState;
                get_map_IDs_by_name("gv_01", &areaID, &mapID);
                gGameStatusPtr->areaID = areaID;
                gGameStatusPtr->mapID = mapID;
                gGameStatusPtr->entryID = 0;
                set_game_mode(GAME_MODE_ENTER_WORLD);
            } else {
                btl_set_state(BATTLE_STATE_0);
                D_800DC4D0 = gBattleState;
                func_8003E514(1);
                set_game_mode(GAME_MODE_END_BATTLE);
            }
            break;
    }
}

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

void btl_state_update_run_away(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    EncounterStatus* currentEncounter = &gCurrentEncounter;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    Actor* enemy;
    s32 var_s0;
    f32 var_f2;
    Evt* script;
    s32 i;

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_0:
            battleStatus->unk_8C = 0;
            gBattleStatus.flags1 &= ~BS_FLAGS1_40000;
            gBattleStatus.flags2 |= BS_FLAGS2_10 | BS_FLAGS2_8 | BS_FLAGS2_4 | BS_FLAGS2_2;
            playerData->unk_2A6++;
            btl_cam_use_preset(BTL_CAM_PRESET_25);
            var_s0 = 0;
            btl_cam_target_actor(ACTOR_PLAYER);
            var_f2 = 0.0f;

            for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                enemy = battleStatus->enemyActors[i];
                if (enemy != NULL) {
                    if (!(enemy->flags & ACTOR_FLAG_TARGET_ONLY)) {
                        if (!(enemy->flags & ACTOR_FLAG_NO_DMG_APPLY)) {
                            f32 escapeChance = enemy->actorBlueprint->escapeChance;

                            var_s0 += 1;
                            if (enemy->debuff == 3 ||
                                enemy->debuff == 4 ||
                                enemy->debuff == 5 ||
                                enemy->debuff == 6 ||
                                enemy->debuff == 7 ||
                                enemy->debuff == 8)
                            {
                                escapeChance = 100.0f;
                            }
                            var_f2 += escapeChance;
                        }
                    }
                }
            }

            player->state.varTable[0] = var_f2 / var_s0;
            if (gGameStatusPtr->debugEnemyContact == 4) {
                player->state.varTable[0] = 100;
            }
            battleStatus->battlePhase = 3;
            script = start_script(&PlayerScriptDispatcher, EVT_PRIORITY_A, 0);
            player->takeTurnScript = script;
            player->takeTurnID = script->id;
            script->owner1.actorID = ACTOR_PLAYER;
            if (partner != NULL && partner->koStatus == 0) {
                script = start_script(partner->takeTurnScriptSource, EVT_PRIORITY_A, 0);
                partner->takeTurnScript = script;
                partner->takeTurnID = script->id;
                script->owner1.actorID = ACTOR_PARTNER;
            }
            gBattleState2 = BATTLE_STATE2_UNK_2;
            break;
        case 2:
            if (!does_script_exist(player->takeTurnID) && battleStatus->unk_8C == 0) {
                if (!(gBattleStatus.flags1 & BS_FLAGS1_40000)) {
                    gBattleState2 = BATTLE_STATE2_UNK_3;
                } else {
                    currentEncounter->battleOutcome = 2;
                    if (is_ability_active(ABILITY_RUNAWAY_PAY) == 0) {
                        gBattleState2 = BATTLE_STATE2_UNK_B;
                    } else {
                        status_menu_start_blinking_starpoints();
                        func_8023E104();
                        D_8029F264 = 0;
                        D_8029F24C = 0;
                        D_80280A30 = 0;
                        D_8029F25C = battleStatus->totalStarPoints * 100;
                        D_8029F250 = 20;
                        D_8029F260 = D_8029F25C / D_8029F250;
                        gBattleState2 = BATTLE_STATE2_PLAYER_DEFEATED;
                    }
                }
            }
            break;
    }

    if (gBattleState2 == BATTLE_STATE2_PLAYER_DEFEATED) {
        if (battleStatus->totalStarPoints != 0) {
            s8 temp_v1_4;

            D_8029F25C -= D_8029F260;
            temp_v1_4 = D_8029F25C / 100;
            var_s0 = battleStatus->totalStarPoints - temp_v1_4;
            battleStatus->totalStarPoints = temp_v1_4;

            if (var_s0 > 0) {
                sfx_play_sound(SOUND_211);
            }
            playerData->starPoints += var_s0;
            D_80280A30 += 1;
            if (D_8029F250 == 0 && battleStatus->totalStarPoints != 0) {
                playerData->starPoints++;
            }
        }
        if (playerData->starPoints >= 99) {
            playerData->starPoints = 99;
        }
        if (battleStatus->totalStarPoints == 0) {
            if (D_8029F250 != 0) {
                D_8029F250--;
            } else {
                status_menu_stop_blinking_starpoints();
                func_8023E11C();
                gBattleState2 = BATTLE_STATE2_UNK_B;
            }
        }
    }

    if (gBattleState2 == BATTLE_STATE2_UNK_B) {
        playerData->battlesFled++;
        if (!(gBattleStatus.flags2 & 0x02000000)) {
            bgm_set_song(0, -1, 0, 1500, 8);
        }
        btl_set_state(BATTLE_STATE_END_BATTLE);
    }

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_3:
            battleStatus->battlePhase = 7;
            script = start_script(&PlayerScriptDispatcher, EVT_PRIORITY_A, 0);
            player->takeTurnScript = script;
            player->takeTurnID = script->id;
            script->owner1.actorID = ACTOR_PLAYER;
            if (partner != NULL && partner->koStatus == 0) {
                script = start_script(partner->takeTurnScriptSource, EVT_PRIORITY_A, 0);
                partner->takeTurnScript = script;
                partner->takeTurnID = script->id;
                script->owner1.actorID = ACTOR_PARTNER;
            }
            gBattleState2 = BATTLE_STATE2_UNK_4;
            break;
        case BATTLE_STATE2_UNK_4:
            if (D_8029F248 != 0) {
                D_8029F248--;
                return;
            }
            if (!does_script_exist(player->takeTurnID) &&
                (partner == NULL || !does_script_exist(partner->takeTurnID)) &&
                battleStatus->unk_8C == 0)
            {
                btl_set_state(BATTLE_STATE_9);
            }
            break;
    }
}

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
                player->debuffEffect->data.disableX->unk_3C = 0;
            }

            btl_cam_use_preset(BTL_CAM_PRESET_25);
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
            btl_cam_use_preset(BTL_CAM_PRESET_19);
            btl_cam_set_target_pos(-89.0, 40.0, -99.0);
            btl_cam_set_zoom(372);
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
                btl_cam_use_preset(BTL_CAM_PRESET_C);
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
                btl_cam_use_preset(BTL_CAM_PRESET_C);
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
                                    btl_cam_use_preset(BTL_CAM_PRESET_54);
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
                btl_cam_use_preset(BTL_CAM_PRESET_C);
                btl_cam_move(15);
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
                btl_cam_use_preset(BTL_CAM_PRESET_D);
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
                btl_cam_use_preset(BTL_CAM_PRESET_C);
                btl_cam_move(15);
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
                onTurnChanceScript = start_script(enemy->onTurnChanceScriptSource, EVT_PRIORITY_A, 0);
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

void btl_state_update_partner_striking_first(void) {
    PlayerData* playerData = &gPlayerData;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    Actor* actor;
    s32 found;
    SelectableTarget* target;
    Evt* script;
    s32 level;
    s32 i;

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_0:
            D_8029F254 = 0;
            level = partner->actorBlueprint->level;
            switch (playerData->currentPartner) {
                case PARTNER_KOOPER:
                    battleStatus->moveCategory = 5;
                    battleStatus->selectedItemID = ITEM_NONE;
                    battleStatus->selectedMoveID = level + MOVE_SHELL_TOSS1;
                    battleStatus->currentTargetListFlags = gMoveTable[battleStatus->selectedMoveID].flags;
                    break;
                case PARTNER_BOMBETTE:
                    battleStatus->moveCategory = 5;
                    battleStatus->selectedItemID = ITEM_NONE;
                    battleStatus->selectedMoveID = level + MOVE_BODY_SLAM1;
                    battleStatus->currentTargetListFlags = gMoveTable[battleStatus->selectedMoveID].flags;
                    break;
            }
            actor = get_actor(ACTOR_ENEMY0);
            if (actor->onHitScriptSource != NULL) {
                actor->lastEventType = EVENT_BEGIN_FIRST_STRIKE;
                script = start_script(actor->onHitScriptSource, EVT_PRIORITY_A, EVT_FLAG_20);
                actor->onHitScript = script;
                actor->onHitID = script->id;
                script->owner1.actorID = actor->actorID;
            }
            gBattleState2 = BATTLE_STATE2_UNK_1;
            break;
        case BATTLE_STATE2_UNK_1:
            player_create_target_list(partner);
            target = &partner->targetData[partner->targetIndexList[0]];
            partner->targetActorID = target->actorID;
            partner->targetPartIndex = target->partID;
            battleStatus->unk_8C = 0;
            battleStatus->lastAttackDamage = 0;
            battleStatus->unk_19A = 0;
            gBattleStatus.flags1 &= ~BS_FLAGS1_2;
            gBattleStatus.flags2 |= BS_FLAGS2_1000000;
            gBattleStatus.flags1 |= BS_FLAGS1_80000;
            increment_status_menu_disabled();
            btl_cam_use_preset(BTL_CAM_PRESET_10);
            btl_cam_target_actor(ACTOR_PARTNER);
            reset_actor_turn_info();
            battleStatus->battlePhase = PHASE_FIRST_STRIKE;
            script = start_script(partner->takeTurnScriptSource, EVT_PRIORITY_A, 0);
            partner->takeTurnScript = script;
            D_8029F248 = 3;
            gBattleState2 = BATTLE_STATE2_UNK_2;
            partner->takeTurnID = script->id;
            script->owner1.actorID = ACTOR_PARTNER;
            break;
        case BATTLE_STATE2_UNK_2:
            if (D_8029F248 != 0) {
                D_8029F248--;
            } else {
                D_8029F254 = 1;
            }

            if (partner->takeTurnScript == NULL || !does_script_exist(partner->takeTurnID)) {
                partner->takeTurnScript = NULL;
                if (partner->onHitScript == NULL || !does_script_exist(partner->onHitID)) {
                    partner->onHitScript = NULL;
                    if (player->onHitScript == NULL || !does_script_exist(player->onHitID)) {
                        player->onHitScript = NULL;
                        found = FALSE;

                        for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                            actor = battleStatus->enemyActors[i];
                            if (actor != NULL && actor->takeTurnScript != NULL) {
                                if (does_script_exist(actor->takeTurnID)) {
                                    found = TRUE;
                                } else {
                                    actor->takeTurnScript = NULL;
                                }
                            }
                        }

                        if (!found) {
                            for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                                actor = battleStatus->enemyActors[i];
                                if (actor != NULL && actor->onHitScript != NULL) {
                                    if (does_script_exist(actor->onHitID)) {
                                        found = TRUE;
                                    } else {
                                        actor->onHitScript = NULL;
                                    }
                                }
                            }

                            if (!found) {
                                for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                                    actor = battleStatus->enemyActors[i];
                                    if (actor != NULL) {
                                        actor->flags &= ~ACTOR_FLAG_80000;
                                    }
                                }

                                if (battleStatus->unk_8C == 0) {
                                    decrement_status_menu_disabled();
                                    if (!btl_check_player_defeated() && !btl_check_enemies_defeated()) {
                                        actor = get_actor(partner->targetActorID);
                                        if (actor != NULL) {
                                            if (actor->onHitScriptSource != NULL) {
                                                actor->lastEventType = EVENT_END_FIRST_STRIKE;
                                                script = start_script(actor->onHitScriptSource, EVT_PRIORITY_A, EVT_FLAG_20);
                                                actor->onHitScript = script;
                                                actor->onHitID = script->id;
                                                script->owner1.actorID = actor->actorID;
                                            }
                                        }
                                        gBattleState2 = BATTLE_STATE2_UNK_3;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            break;
        case BATTLE_STATE2_UNK_3:
            found = FALSE;

            for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                actor = battleStatus->enemyActors[i];
                if (actor != NULL && actor->onHitScript != NULL) {
                    if (does_script_exist(actor->onHitID)) {
                        found = TRUE;
                    } else {
                        actor->onHitScript = NULL;
                    }
                }
            }
            if (!found) {
                btl_set_state(BATTLE_STATE_BEGIN_TURN);
            }
            break;
    }
}

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

// ugly loops and such
#ifdef NON_EQUIVALENT
void btl_state_update_enemy_striking_first(void) {
    PlayerData* playerData = &gPlayerData;
    BattleStatus* battleStatus = &gBattleStatus;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    Evt* script;
    Actor* enemy;
    s32 cond;
    s32 i;
    s32 j;

    Actor* temp_s0;
    s32 temp_t0;
    s32 temp_a1;
    s16* temp_t4;
    s16* var_a2;
    s16* var_t3;
    s32 temp_v0;
    s32 var_a3;
    s32 var_t2;

    s32 nextEnemyIdx;
    s32 count;

    switch (gBattleState2) {
        case 0:
            battleStatus->unk_8C = 0;
            battleStatus->lastAttackDamage = 0;
            battleStatus->unk_19A = 0;
            playerData->enemyFirstStrikes++;
            battleStatus->flags1 &= ~2;
            D_8029F254 = 0;
            player->flags &= ~ACTOR_FLAG_8000000;
            if (partner != NULL) {
                partner->flags &= ~ACTOR_FLAG_8000000;
            }
            battleStatus->flags2 |= 0x01000000 | 0x4000;
            count = 0;
            for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                if (battleStatus->enemyActors[i] != NULL) {
                    battleStatus->enemyIDs[i] = i | 0x200;
                    count++;
                }
            }

            battleStatus->numEnemyActors = count;
            // for (i = 0; i < count - 1; i++) {
            //     for (j = i + 1; j < count; j++) {
            //         s32 temp_t0;
            //         s32 temp_a1;

            //         temp_t0 = battleStatus->enemyActors[battleStatus->enemyIDs[i]]->turnPriority;
            //         temp_a1 = battleStatus->enemyActors[battleStatus->enemyIDs[j]]->turnPriority;
            //         if (temp_t0 < temp_a1) {
            //             battleStatus->enemyActors[battleStatus->enemyIDs[i]]->turnPriority = temp_a1;
            //             battleStatus->enemyActors[battleStatus->enemyIDs[j]]->turnPriority = temp_t0;
            //         }
            //     }
            // }

            i = 0;
            temp_v0 = var_t2 - 1;
            temp_t4 = battleStatus->enemyIDs;
            if (temp_v0 > 0) {
                var_t3 = temp_t4;
                do {
                    var_a3 = i + 1;
                    if (var_a3 < var_t2) {
                        var_a2 = &temp_t4[var_a3];
                        do {
                            temp_t0 = (u16) *var_t3;
                            temp_a1 = (u16) *var_a2;
                            var_a3 += 1;
                            if (battleStatus->enemyActors[temp_t0 & 0xFF]->turnPriority < battleStatus->enemyActors[temp_a1 & 0xFF]->turnPriority) {
                                *var_t3 = temp_a1;
                                *var_a2 = temp_t0;
                            }
                            var_a2 += 2;
                        } while (var_a3 < var_t2);
                    }
                    i++;
                    var_t3 += 2;
                } while (i < temp_v0);
            }

            battleStatus->nextEnemyIndex = 0;
            i = 0;
    loop_18:
    loop_19:
            temp_s0 = battleStatus->enemyActors[battleStatus->enemyIDs[i]];
            if (temp_s0 == NULL) {
    block_21:
                i++;
                if (i >= battleStatus->numEnemyActors) {
                    i = 0;
                    goto loop_18;
                }
                goto loop_19;
            }
            if (temp_s0->flags & 0x204000) {
                goto block_21;
            }

            nextEnemyIdx = i + 1;
            battleStatus->currentTurnEnemy = enemy;
            battleStatus->activeEnemyActorID = battleStatus->enemyIDs[i];
            if (nextEnemyIdx >= battleStatus->numEnemyActors) {
                nextEnemyIdx = 0;
            }
            battleStatus->nextEnemyIndex = nextEnemyIdx;
            btl_cam_target_actor(battleStatus->activeEnemyActorID);
            enemy = battleStatus->currentTurnEnemy;
            reset_actor_turn_info();
            battleStatus->battlePhase = 1;
            script = start_script(enemy->takeTurnScriptSource, EVT_PRIORITY_A, 0);
            enemy->takeTurnScript = script;
            D_8029F248 = 3;
            enemy->takeTurnID = script->id;
            gBattleState2 = 2;
            script->owner1.enemyID = battleStatus->activeEnemyActorID;
            break;
        case 2:
            if (D_8029F248 != 0) {
                D_8029F248--;
            } else {
                D_8029F254 = 1;
            }

            enemy = battleStatus->currentTurnEnemy;
            if ((enemy->takeTurnScript == NULL || !does_script_exist(enemy->takeTurnID)) &&
                ((enemy->takeTurnScript = NULL, (player->onHitScript == NULL)) || !does_script_exist(player->onHitID))) {
                player->onHitScript = NULL;
                if (partner != NULL) {
                    if (partner->onHitScript == NULL || !does_script_exist(partner->onHitID)) {
                        partner->onHitScript = NULL;
                        goto block_39;
                    }
                } else {
    block_39:
                    for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                        enemy = battleStatus->enemyActors[i];
                        if (enemy != NULL && enemy->takeTurnScript != NULL) {
                            if (does_script_exist(enemy->takeTurnID)) {
                                cond = TRUE;
                            } else {
                                enemy->takeTurnScript = NULL;
                            }
                        }
                    }

                    if (!cond) {
                        for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                            enemy = battleStatus->enemyActors[i];
                            if (enemy != NULL && enemy->onHitScript != NULL) {
                                if (does_script_exist(enemy->onHitID)) {
                                    cond = TRUE;
                                } else {
                                    enemy->onHitScript = NULL;
                                }
                            }
                        }

                        if (!cond) {
                            gBattleStatus.flags2 &= ~0x4000;
                            for (i = 0; i < ARRAY_COUNT(battleStatus->enemyActors); i++) {
                                enemy = battleStatus->enemyActors[i];
                                if (enemy != NULL) {
                                    enemy->flags &= 0xFFF7FFFF;
                                }
                            }

                            if (battleStatus->unk_8C == 0 &&
                                !btl_check_player_defeated() &&
                                !btl_check_enemies_defeated())
                            {
                                btl_set_state(5);
                            }
                        }
                    }
                }
            }
            break;
    }
}
#else
INCLUDE_ASM(s32, "16F740", btl_state_update_enemy_striking_first);
#endif

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
                battleStatus->controlScript = start_script(stage->postBattle, EVT_PRIORITY_A, 0);
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
