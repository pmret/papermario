#include "common.h"
#include "script_api/battle.h"
#include "ld_addrs.h"
#include "effects.h"
#include "hud_element.h"
#include "battle/battle.h"

extern s16 D_802809F6;
extern s32 D_80280A30;
extern s32 D_8029F254;
extern s32 D_8029F248;

// Almost good but some reorderings at the beginning
#ifdef NON_EQUIVALENT
void btl_merlee_on_start_turn(void) {
    PlayerData* playerData = &gPlayerData;
    BattleStatus* battleStatus = &gBattleStatus;
    EncounterStatus* currentEncounter = &gCurrentEncounter;

    if (!(battleStatus->flags2 & 0x40) && battleStatus->unk_8A != 3 && battleStatus->unk_8A != 4 && playerData->merleeCastsLeft > 0) {
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
    gBattleState2 = BATTLE_STATES2_UNK_0;

    flags &= BS_FLAGS2_40;
    if (flags) {
        switch (battleState) {
            case 14:
                battleState = 16;
                break;
            case 13:
                battleState = 15;
                break;
            case 7:
                battleState = 8;
                break;
            case 8:
                battleState = 7;
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

INCLUDE_ASM(s32, "16F740", btl_state_update_begin_player_turn);

void btl_state_draw_begin_player_turn(void) {
}

void btl_state_update_switch_to_player(void) {
    Actor* player = gBattleStatus.playerActor;
    Actor* partner = gBattleStatus.partnerActor;
    s32 i;

    if (gBattleState2 == BATTLE_STATES2_UNK_0) {
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

        btl_set_state(0xC);
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

    if (gBattleState2 == BATTLE_STATES2_UNK_0) {
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

        btl_set_state(0xC);
    }
}

void btl_state_draw_switch_to_partner(void) {
}

INCLUDE_ASM(s32, "16F740", func_80242FE0);

void func_80243910(void) {
}

void btl_state_update_prepare_menu(void) {
    BattleStatus* battleStatus = &gBattleStatus;

    battleStatus->unk_4D = -1;
    battleStatus->unk_4E = -1;
    battleStatus->unk_4F = -1;
    battleStatus->unk_50 = -1;
    battleStatus->unk_51 = -1;
    battleStatus->unk_52 = -1;
    battleStatus->stratsLastCursorPos = -1;
    battleStatus->unk_5D = -1;
    battleStatus->unk_62 = -1;
    battleStatus->unk_63 = -1;

    dma_copy(_415D90_ROM_START, _415D90_ROM_END, _415D90_VRAM);

    if (battleStatus->flags1 & BS_FLAGS1_80000) {
        btl_set_state(14);
    } else if (gBattleState2 == BATTLE_STATES2_UNK_46) {
        btl_set_state(13);
        gBattleState2 = BATTLE_STATES2_UNK_46;
    } else {
        btl_set_state(13);
    }
}

void btl_state_draw_prepare_menu(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_end_turn);

void btl_state_draw_end_turn(void) {
}

void btl_state_update_1C(void) {
    func_8024E40C(2);
    btl_set_state(12);
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
        case BATTLE_STATES2_UNK_0:
            player->flags &= ~(ACTOR_FLAG_8000000 | ACTOR_FLAG_4000000);
            if (partner != NULL) {
                partner->flags &= ~(ACTOR_FLAG_8000000 | ACTOR_FLAG_4000000);
            }

            battleStatus->unk_8C = 0;
            if (battleStatus->outtaSightActive == 0) {
                gBattleState2 = BATTLE_STATES2_UNK_5;
            } else {
                if (battleStatus->outtaSightActive > 0) {
                    D_8029F254 = 1;
                }
                battleStatus->battlePhase = PHASE_ENEMY_BEGIN;
                script = start_script(partner->onTurnChanceScriptSource, 0xA, 0);
                partner->onTurnChangeScript = script;
                partner->onTurnChangeID = script->id;
                script->owner1.enemyID = 0x100;
                gBattleState2 = BATTLE_STATES2_UNK_1;
            }

            break;
        case BATTLE_STATES2_UNK_1:
            if (!does_script_exist(partner->onTurnChangeID)) {
                battleStatus->outtaSightActive = 0;
                gBattleState2 = BATTLE_STATES2_UNK_5;
            }
            break;
    }

    switch (gBattleState2) {
        case BATTLE_STATES2_UNK_5:
            player->flags &= ~(ACTOR_FLAG_8000000 | ACTOR_FLAG_4000000);
            if (partner != NULL) {
                partner->flags &= ~(ACTOR_FLAG_8000000 | ACTOR_FLAG_4000000);
            }
            gBattleState2 = BATTLE_STATES2_UNK_B;
            gBattleStatus.flags2 &= ~BS_FLAGS2_2;
            gBattleStatus.flags2 &= ~BS_FLAGS2_4;
            gBattleStatus.flags2 &= ~BS_FLAGS2_8;
            gBattleStatus.flags2 &= ~BS_FLAGS2_10;

            gBattleStatus.flags1 &= ~BS_FLAGS1_8;
            if (player->koStatus == 0xD) {
                dispatch_event_player(EVENT_34);
                gBattleState2 = BATTLE_STATES2_PLAYER_DEFEATED;
            }
            player->debuff = 0;
            player->staticStatus = 0;
            player->stoneStatus = 0;
            player->transStatus = 0;
            player->koStatus = 0;
            player->koDuration = 0;
            player->ptrDefuffIcon->ptrPropertyList[15] = 0;

            if (partner != NULL) {
                if (partner->koStatus == 0xD) {
                    dispatch_event_partner(EVENT_34);
                    gBattleState2 = BATTLE_STATES2_PLAYER_DEFEATED;
                }
                partner->debuff = 0;
                partner->staticStatus = 0;
                partner->stoneStatus = 0;
                partner->transStatus = 0;
                partner->koStatus = 0;
                partner->koDuration = 0;
                partner->ptrDefuffIcon->ptrPropertyList[15] = 0;
            }
            break;
        case BATTLE_STATES2_PLAYER_DEFEATED:
            if (player->onHitScript == NULL || !does_script_exist(player->onHitID)) {
                player->onHitScript = NULL;
                if (partner != NULL) {
                    if (partner->onHitScript == NULL || !does_script_exist(partner->onHitID)) {
                        partner->onHitScript = NULL;
                    } else {
                        break;
                    }
                }
                gBattleState2 = BATTLE_STATES2_UNK_B;
            }
            break;
    }

    if (gBattleState2 == BATTLE_STATES2_UNK_B) {
        if (partner == NULL || !(gBattleStatus.flags1 & BS_FLAGS1_100000)) {
            gBattleState2 = BATTLE_STATES2_UNK_2;
        } else {
            partner->state.currentPos.x = partner->currentPos.x;
            partner->state.currentPos.z = partner->currentPos.z;
            partner->state.goalPos.x = player->currentPos.x;
            partner->state.goalPos.z = player->currentPos.z;
            partner->state.moveTime = 4;
            partner->state.angle = 0.0f;
            gBattleState2 = BATTLE_STATES2_UNK_C;
        }
    }

    if (gBattleState2 == BATTLE_STATES2_UNK_C) {
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
            gBattleState2 = BATTLE_STATES2_UNK_2;
            gBattleStatus.flags1 &= ~BS_FLAGS1_100000;
        }
    }

    if (gBattleState2 == BATTLE_STATES2_UNK_2) {
        func_8024E40C(2);
        if (battleStatus->unk_8A == 3) {
            if ((s8) battleStatus->totalStarPoints == 0) {
                battleStatus->unk_8A = 0;
                playerData->merleeTurnCount = 0;
                playerData->merleeCastsLeft++;
            } else {
                battleStatus->battlePhase = PHASE_MERLEE_EXP_BONUS;
                script = start_script(PlayerScriptDispatcher, 0xA, 0);
                player->takeTurnScript = script;
                player->takeTurnID = script->id;
                script->owner1.enemyID = 0;
            }
        }
        gBattleState2 = BATTLE_STATES2_UNK_3;
        D_8029F248 = 0;
        gBattleStatus.flags1 &= ~BS_FLAGS1_2;
    }

    if (gBattleState2 == BATTLE_STATES2_UNK_3) {
        if (D_8029F248 != 0) {
            D_8029F248--;
        } else if (player->takeTurnScript == NULL || !does_script_exist(player->takeTurnID)) {
            player->takeTurnScript = NULL;
            if (battleStatus->unk_8A != 3) {
                gBattleState2 = BATTLE_STATES2_UNK_4;
            } else {
                battleStatus->incrementStarPointDelay = 0x14;
                battleStatus->unk_8A = 0;
                gBattleState2 = BATTLE_STATES2_UNK_4;
                battleStatus->pendingStarPoints = battleStatus->totalStarPoints
                                        + battleStatus->pendingStarPoints + battleStatus->pendingStarPoints;
            }
        }
    }

    if (gBattleState2 == BATTLE_STATES2_UNK_4 && (s8) battleStatus->pendingStarPoints <= 0) {
        if (gBattleStatus.flags1 & BS_FLAGS1_1000000) {
            gBattleStatus.flags1 &= ~BS_FLAGS1_40000;
        }
        if ((u16) playerData->unk_2A4[0] < 0x270F) {
            playerData->unk_2A4[0]++;
        }
        if (gBattleStatus.flags1 & BS_FLAGS1_40000) {
            currentEncounter->battleOutcome = OUTCOME_ENEMY_FLED;
        } else {
            currentEncounter->battleOutcome = OUTCOME_PLAYER_WON;
        }
        if (gBattleStatus.flags1 & BS_FLAGS1_20000) {
            if (!(gBattleStatus.flags2 & BS_FLAGS2_2000000)) {
                bgm_set_song(0, -1, 0, 0x5DC, 8);
            }
            btl_set_state(0x20);
        } else {
            btl_set_state(0x21);
        }
    }
}

void btl_state_draw_victory(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_end_training_battle);

void btl_state_draw_end_training_battle(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_end_battle);

INCLUDE_ASM(s32, "16F740", btl_state_draw_end_battle);

void btl_state_update_defend(void) {
    Actor* player = gBattleStatus.playerActor;
    Evt* script;

    switch (gBattleState2) {
        case BATTLE_STATES2_UNK_0:
            gBattleStatus.unk_8C = 0;
            gBattleStatus.battlePhase = PHASE_USE_DEFEND;
            player->takeTurnScript = script = start_script(PlayerScriptDispatcher, 10, 0);
            player->takeTurnID = script->id;
            gBattleState2 = BATTLE_STATES2_UNK_1;
            script->owner1.enemyID = 0;
            break;
        case BATTLE_STATES2_UNK_1:
            if (!does_script_exist(player->takeTurnID) && gBattleStatus.unk_8C == 0) {
                btl_set_state(0x16);
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
        case BATTLE_STATES2_UNK_0:
            battleStatus->flags1 &= ~BS_FLAGS1_8;
            battleStatus->unk_8C = 0;
            battleStatus->flags2 &= ~BS_FLAGS2_2;
            battleStatus->flags2 &= ~BS_FLAGS2_4;
            battleStatus->flags2 &= ~BS_FLAGS2_8;
            battleStatus->flags2 &= ~BS_FLAGS2_10;

            if (player->debuff != 0) {
                if (player->debuff == 7) {
                    sfx_play_sound(SOUND_E7);
                    player->unk_228->flags |= EFFECT_INSTANCE_FLAGS_10;
                    player->unk_228 = NULL;
                }
                player->debuff = 0;
                player->debuffDuration = 0;
                remove_status_debuff(player->hudElementDataIndex);
                player->koStatus = 0;
                player->koDuration = 0;
                player->ptrDefuffIcon->ptrPropertyList[15] = 0;
            }

            func_8024E40C(0x19);
            btl_cam_target_actor(0);
            battleStatus->battlePhase = PHASE_RUN_AWAY_RESET;
            script = start_script(PlayerScriptDispatcher, 0xA, 0);
            player->takeTurnScript = script;
            player->takeTurnID = script->id;
            script->owner1.enemyID = 0;

            if (partner != NULL) {
                script = start_script(partner->takeTurnScriptSource, 0xA, 0);
                partner->takeTurnScript = script;
                partner->takeTurnID = script->id;
                script->owner1.enemyID = 0x100;
            }
            gBattleState2 = BATTLE_STATES2_UNK_1;
            break;
        case BATTLE_STATES2_UNK_1:
            if (!does_script_exist(player->takeTurnID) && battleStatus->unk_8C == 0) {
                if (find_item(ITEM_LIFE_SHROOM) >= 0) {
                    battleStatus->battlePhase = PHASE_USE_LIFE_SHROOM;
                    script = start_script(PlayerScriptDispatcher, 0xA, 0);
                    player->takeTurnScript = script;
                    player->takeTurnID = script->id;
                    script->owner1.enemyID = 0;
                    gBattleState2 = BATTLE_STATES2_UNK_2;
                } else {
                    gBattleState2 = BATTLE_STATES2_PLAYER_DEFEATED;
                }
            }
            break;
        case BATTLE_STATES2_UNK_2:
            if (!does_script_exist(player->takeTurnID) && battleStatus->unk_8C == 0) {
                gBattleState2 = BATTLE_STATES2_PLAYER_DEFEATED;
            }
            break;
    }

    if (gBattleState2 == BATTLE_STATES2_PLAYER_DEFEATED) {
        currentEncounter->battleOutcome = OUTCOME_PLAYER_LOST;
        if (!(gBattleStatus.flags2 & BS_FLAGS2_2000000)) {
            bgm_set_song(0, -1, 0, 0x5DC, 8);
        }
        btl_set_state(0x20);
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
        case BATTLE_STATES2_UNK_0:
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

            battleStatus->unk_5C = -1;
            D_8029F248 = 0xA;
            gBattleState2 = BATTLE_STATES2_UNK_2;

        case BATTLE_STATES2_UNK_2:
            if (D_8029F248 != 0) {
                D_8029F248--;
                break;
            }
            deduct_current_move_fp();
            script = start_script(BtlPutPartnerAway, 0xA, 0);
            battleStatus->controlScript = script;
            battleStatus->controlScriptID = script->id;
            script->owner1.enemyID = 0x100;
            state->unk_18.x = partner->currentPos.x;
            state->unk_18.y = 0.0f;
            state->unk_18.z = partner->currentPos.z;
            gBattleState2 = BATTLE_STATES2_UNK_3;
            break;
        case BATTLE_STATES2_UNK_3:
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
                gBattleState2 = BATTLE_STATES2_UNK_4;
            }
            break;
        case BATTLE_STATES2_UNK_4:
            partner = battleStatus->partnerActor;
            if (partner != NULL) {
                if (!does_script_exist(partner->takeTurnID)) {
                    partner->takeTurnScript = NULL;
                } else {
                    break;
                }
            }

            script = start_script(BtlBringPartnerOut, 0xA, 0);
            battleStatus->controlScript = script;
            battleStatus->controlScriptID = script->id;
            script->owner1.enemyID = 0x100;
            gBattleState2 = BATTLE_STATES2_UNK_5;
            break;
        case BATTLE_STATES2_UNK_5:
            if (!does_script_exist(battleStatus->controlScriptID)) {
                partner = battleStatus->partnerActor;
                if (partner != NULL) {
                    if (partner->onTurnChanceScriptSource != NULL) {
                        battleStatus->battlePhase = PHASE_PLAYER_BEGIN;
                        script = start_script(partner->onTurnChanceScriptSource, 0xA, 0);
                        partner->onTurnChangeScript = script;
                        partner->onTurnChangeID = script->id;
                        script->owner1.enemyID = 0x100;
                    }
                }
                gBattleState2 = BATTLE_STATES2_UNK_6;
            }
            break;
        case BATTLE_STATES2_UNK_6:
            partner = battleStatus->partnerActor;
            if (partner == NULL || partner->onTurnChanceScriptSource == NULL
                                || !does_script_exist(partner->onTurnChangeID)) {
                func_8024E40C(2);
                gBattleState2 = BATTLE_STATES2_UNK_7;
            }
            break;
        case BATTLE_STATES2_UNK_7:
            if (battleStatus->unk_8C == 0) {
                gBattleStatus.flags2 &= ~BS_FLAGS2_10;
                if (!(gBattleStatus.flags1 & BS_FLAGS1_80000)) {
                    if (player_team_is_ability_active(player, ABILITY_QUICK_CHANGE) != FALSE) {
                        btl_set_state(0xC);
                    } else {
                        btl_set_state(0x16);
                    }
                } else {
                    if (player_team_is_ability_active(player, ABILITY_QUICK_CHANGE) == FALSE) {
                        btl_set_state(0x17);
                    } else {
                        btl_set_state(0xC);
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

void filemenu_main_update_code(void) {
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
        case BATTLE_STATES2_UNK_0:
            if (partner == NULL) {
                btl_set_state(9);
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
                gBattleState2 = BATTLE_STATES2_UNK_2;
            }
            break;
        case BATTLE_STATES2_UNK_2:
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
            script = start_script(partner->takeTurnScriptSource, 0xA, 0);
            partner->takeTurnScript = script;
            partner->takeTurnID = script->id;
            script->owner1.enemyID = 0x100;
            gBattleState2 = BATTLE_STATES2_UNK_3;
            break;
        case BATTLE_STATES2_UNK_3:
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
                                btl_set_state(0x23);
                                break;
                            }
                            decrement_status_menu_disabled();
                            if (playerData->currentPartner == 1 && battleStatus->moveCategory == 5
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
                                    gBattleState2 = BATTLE_STATES2_UNK_B;
                                    partner->flags |= ACTOR_FLAG_8000000;
                                } else {
                                    gBattleState2 = BATTLE_STATES2_UNK_14;
                                }
                            } else {
                                return;
                            }
                        }
                    }
                }
            }
            break;
        case BATTLE_STATES2_UNK_B:
            if (btl_is_popup_displayed() == FALSE) {
                func_8024E40C(2);
                btl_cam_move(0xF);
                D_8029F248 = 0xA;
                gBattleState2 = BATTLE_STATES2_UNK_C;
            }
            break;
        case BATTLE_STATES2_UNK_C:
            if (D_8029F248 != 0) {
                D_8029F248--;
            } else {
                gBattleState2 = BATTLE_STATES2_UNK_14;
            }
            break;
    }

    switch (gBattleState2) {
        case BATTLE_STATES2_UNK_14:
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
                gBattleState2 = BATTLE_STATES2_UNK_1E;
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
                        gBattleState2 = BATTLE_STATES2_UNK_14;
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
                gBattleState2 = BATTLE_STATES2_UNK_15;
            }
            break;
        case BATTLE_STATES2_UNK_15:
            if (btl_is_popup_displayed() == FALSE) {
                func_8024E40C(2);
                btl_cam_move(0xF);
                D_8029F248 = 0xA;
                gBattleState2 = BATTLE_STATES2_UNK_16;
            }
            break;
        case BATTLE_STATES2_UNK_16:
            if (D_8029F248 != 0) {
                D_8029F248--;
            } else {
                gBattleState2 = BATTLE_STATES2_UNK_1E;
            }
            break;
    }

    if (gBattleState2 == BATTLE_STATES2_UNK_1E && (partner->takeTurnScript == NULL ||
                                  !does_script_exist(partner->takeTurnID))) {
        partner->takeTurnScript = NULL;
        btl_set_state(0x17);
    }
}

void btl_state_draw_partner_move(void) {
}

void btl_state_update_end_partner_turn(void) {
    BattleStatus* battleStatus = &gBattleStatus;

    if (gBattleState2 == BATTLE_STATES2_UNK_0) {
        battleStatus->flags2 |= BS_FLAGS2_4;
        if (!btl_check_enemies_defeated()) {
            battleStatus->flags1 &= ~BS_FLAGS1_80000;
            battleStatus->flags2 &= ~BS_FLAGS2_10;

            if (battleStatus->unk_94 < 0) {
                battleStatus->unk_94 = 0;
                btl_set_state(6);
            } else {
                btl_set_state(9);
            }
        }
    }
}

void btl_state_draw_end_partner_turn(void) {
}

INCLUDE_ASM(s32, "16F740", btl_state_update_next_enemy);

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

INCLUDE_ASM(s32, "16F740", btl_state_update_end_demo_battle);

void btl_state_draw_end_demo_battle(void) {
    if (D_802809F6 == -1) {
        set_screen_overlay_color(0, 0, 0, 0);
        set_screen_overlay_params_front(0, D_80280A30);
    }
}
