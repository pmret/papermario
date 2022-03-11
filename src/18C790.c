#include "common.h"
#include "effects.h"
#include "hud_element.h"
#include "ld_addrs.h"

extern s32 D_80284150;
extern s32 D_80284154[];
extern s32* D_80284188[];
extern s32 D_802841B0;
extern HudScript* D_802841B4;
extern HudScript* D_802841B8;
extern HudScript* D_802841BC;
extern HudScript* D_802841C0[];
extern HudScript* D_802841E8[];
extern HudScript* D_80284210[];
extern HudScript* D_80284238[];
extern HudScript* D_80284260[];
extern HudScript* D_80284288[];
extern EvtScript D_802842B0;
extern EvtScript D_80284880;

extern s32 D_8029FA88;
extern s32 D_8029FAA8;
extern s32 D_8029FAC4;
extern s32 D_8029FB4C;
extern s32 D_8029FB50;
extern s32 D_8029FB54;
extern s32 D_8029FB6C;
extern s32 D_8029FB70;
extern s32 D_8029FB74;
extern Evt* D_8029FB7C;
extern s32 D_8029FB80;
extern s32 D_8029FB84;
extern HudScript D_802A9F0C;
extern HudScript D_802AA320;
extern HudScript D_802AA694;
extern HudScript D_802AAA08;
extern HudScript D_802AAA30;
extern HudScript HudScript_ProjectorBeam;
extern EvtScript PlayerScriptDispatcher;

extern s32 D_8029FA80[4];
extern s32 D_8029FA90[3][7];
extern s32 D_8029FAE8;
extern s32 D_8029FB48;
extern s32 D_8029FB60[];
extern s32 D_8029FB78;
extern s32 D_8029FB88;
extern s32 D_8029FB8C;
extern HudScript D_802A9F34;
extern HudScript D_802A9F5C;
extern HudScript D_802A9F84;
extern HudScript D_802A9FAC;

s32* virtual_entity_get_by_index(s32);

void func_80260948(s32 arg0, s32 posX, s32 posY);
void func_80260A20(s64 posX, s32 posY);

ApiStatus func_8025DEB0(Evt* script, s32 isInitialCall) {
    script->varTable[0] = (s8)gBattleStatus.totalStarPoints;
    return ApiStatus_DONE2;
}

s32 func_8025DEC4(Evt* script, s32 isInitialCall) {
    s32 levelUp = FALSE;

    script->varTable[10] = gBattleStatus.totalStarPoints / 100; // star points in hundreds (levels to gain)
    script->varTable[11] = (gBattleStatus.totalStarPoints % 100) / 10; // star points in tens
    script->varTable[12] = gBattleStatus.totalStarPoints % 10; // star points in ones

    if (script->varTable[10] > 0) {
        script->varTable[10] = (s32) D_80284188[script->varTable[10]];
        levelUp = TRUE;
    } else {
        script->varTable[10] = D_802841B0;
    }

    if ((script->varTable[11] > 0) || levelUp) {
        script->varTable[11] = (s32) D_80284188[script->varTable[11]];
    } else {
        script->varTable[11] = D_802841B0;
    }

    script->varTable[12] = (s32) D_80284188[script->varTable[12]];
    return ApiStatus_DONE2;
}

ApiStatus func_8025E030(Evt* script, s32 isInitialCall) {
    return D_8029FB78 != 0 ? ApiStatus_DONE2 : ApiStatus_BLOCK;
}

ApiStatus func_8025E044(Evt* script, s32 isInitialCall) {
    EntityModel* model;

    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[6]));
    model->flags &= ~MODEL_FLAGS_MASK_FFF0 ;
    model->flags |= MODEL_FLAGS_TRANSFORM_GROUP_MEMBER;
    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[7]));
    model->flags &= ~MODEL_FLAGS_MASK_FFF0 ;
    model->flags |= MODEL_FLAGS_TRANSFORM_GROUP_MEMBER;
    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[8]));
    model->flags &= ~MODEL_FLAGS_MASK_FFF0 ;
    model->flags |= MODEL_FLAGS_TRANSFORM_GROUP_MEMBER;
    model = get_entity_model(*virtual_entity_get_by_index(script->varTable[9]));
    model->flags &= ~MODEL_FLAGS_MASK_FFF0 ;
    model->flags |= MODEL_FLAGS_TRANSFORM_GROUP_MEMBER;

    return ApiStatus_DONE2;
}

ApiStatus func_8025E108(Evt* script, s32 isInitialCall) {
    EntityModel* model = get_entity_model(*virtual_entity_get_by_index(script->varTable[9]));
    model->flags &= ~(MODEL_FLAGS_USES_CUSTOM_GFX | MODEL_FLAGS_FLAG_20 | MODEL_FLAGS_FLAG_40
        | MODEL_FLAGS_HAS_LOCAL_VERTEX_COPY | MODEL_FLAGS_USE_CAMERA_UNK_MATRIX | MODEL_FLAGS_FLAG_200
        | MODEL_FLAGS_HAS_TRANSFORM_APPLIED | MODEL_FLAGS_HAS_TEX_PANNER | MODEL_FLAGS_USES_TRANSFORM_MATRIX
        | MODEL_FLAGS_FLAG_2000 | MODEL_FLAGS_FLAG_4000 | MODEL_FLAGS_FLAG_8000);
    model->flags |= MODEL_FLAGS_TRANSFORM_GROUP_MEMBER;

    return ApiStatus_DONE2;
}

ApiStatus func_8025E14C(Evt* script, s32 isInitialCall) {
    fx_confetti(3, 0.0f, 100.0f, 0.0f, 1.0f, 120);
    return ApiStatus_DONE2;
}

// Some issues with symbols
#ifdef NON_MATCHING
void btl_state_update_celebration(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    PlayerData* playerData = &gPlayerData;
    Actor* player = battleStatus->playerActor;
    Actor* partner = battleStatus->partnerActor;
    s8 currentSubmenu;
    s32 newSubmenu;
    s32 id;
    s32 x;
    s32 y;
    s32 width;

    Evt* takeTurnScript;
    Evt* script;

    s32 temp_v1_4;
    s32 temp_v1_5;

    s32 fpTens;
    s32 fpOnes;

    s32 leftoverSP;
    s32 oldSP;

    s32 i;
    s32 j;

    HudScript* new_var;

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_0:
            if (battleStatus->pendingStarPoints <= 0) {
                player->flags &= ~0x8000000;
                D_8029FB6C = battleStatus->totalStarPoints * 100;
                D_8029FB74 = 0;
                D_8029FB50 = 0;
                D_80284150 = 0;
                D_8029FB88 = 0;
                D_8029FB8C = 0;
                sfx_play_sound(SOUND_D4);

                oldSP = playerData->starPoints;
                if (oldSP + battleStatus->totalStarPoints >= 100) {
                    bgm_set_song(0, SONG_LEVEL_UP, 0, 250, 8);
                } else {
                    bgm_set_song(0, SONG_BATTLE_END, 0, 250, 8);
                }

                D_8029FB84 = 0;
                func_8024E40C(0x17);
                D_8029FB54 = 0;
                D_8029FB4C = 1;
                gBattleState2 = BATTLE_STATE2_UNK_1;
                gBattleStatus.flags2 |= BS_FLAGS2_1;
            }
            break;
        case BATTLE_STATE2_UNK_1:
            if (D_8029FB4C != 0) {
                D_8029FB4C--;
            } else if (func_8024E584() != 0) {
                dma_copy(_7A89A0_ROM_START, _7A89A0_ROM_END, _7A89A0_VRAM);
                script = start_script(D_802842B0, 0xA, 0);
                D_8029FB78 = 0;
                D_8029FB54 = 20;
                D_8029FB70 = D_8029FB6C / D_8029FB54;
                player->takeTurnScript = script;
                D_8029FB4C = 1;
                player->takeTurnID = script->id;
                script->owner1.enemyID = 0;
                gBattleState2 = BATTLE_STATE2_UNK_2;
            }
            break;
        case BATTLE_STATE2_UNK_2:
            if (D_8029FB4C == 0) {
                if (battleStatus->totalStarPoints != 0) {
                    D_8029FB6C -= D_8029FB70;
                    oldSP = battleStatus->totalStarPoints;
                    battleStatus->totalStarPoints = D_8029FB6C / 100;
                    leftoverSP = oldSP - battleStatus->totalStarPoints;
                    if (leftoverSP > 0) {
                        sfx_play_sound(SOUND_215);
                    }

                    playerData->starPoints += leftoverSP;
                    D_80284150 += 1;
                    if (D_8029FB54 == 0 && battleStatus->totalStarPoints != 0) {
                        playerData->starPoints++;
                    }
                }
                if (playerData->level >= 27) {
                    playerData->starPoints = 0;
                }
                if (playerData->starPoints >= 100) {
                    D_8029FB74 = 1;
                    playerData->starPoints -= 100;
                }
                if (playerData->level + D_8029FB74 == 27) {
                    playerData->starPoints = 0;
                }
                if (battleStatus->totalStarPoints == 0) {
                    if (D_8029FB54 == 0) {
                        D_8029FB78 = 1;
                        player->flags &= ~(ACTOR_FLAG_4000000 | ACTOR_FLAG_8000000);
                        if (partner != NULL) {
                            partner->flags &= ~(ACTOR_FLAG_4000000 | ACTOR_FLAG_8000000);
                        }
                        battleStatus->battlePhase = 5;
                        takeTurnScript = start_script(PlayerScriptDispatcher, 0xA, 0);
                        player->takeTurnScript = takeTurnScript;
                        player->takeTurnID = takeTurnScript->id;
                        takeTurnScript->owner1.actorID = ACTOR_PLAYER;
                        if (partner != NULL) {
                            takeTurnScript = start_script(partner->takeTurnScriptSource, 0xA, 0);
                            partner->takeTurnScript = takeTurnScript;
                            partner->takeTurnID = takeTurnScript->id;
                            takeTurnScript->owner1.actorID = ACTOR_PARTNER;
                        }
                        D_8029FB4C = 40;
                        gBattleState2 = BATTLE_STATE2_UNK_3;
                    } else {
                        D_8029FB54--;
                    }
                }
            } else {
                D_8029FB4C--;
            }
            break;
        case BATTLE_STATE2_UNK_3:
            if (D_8029FB4C == 0) {
                if (D_8029FB74 == 0) {
                    gBattleState2 = BATTLE_STATE2_UNK_14;
                } else {
                    gBattleState2 = BATTLE_STATE2_UNK_4;
                }
                break;
            }
            D_8029FB4C--;
            break;
        case BATTLE_STATE2_UNK_4:
            if (D_8029FB84 >= 99) {
                playerData->level++;
                func_8024E40C(2);
                btl_cam_move(5);
                dma_copy(_79EF40_ROM_START, _79EF40_ROM_END, _79EF40_VRAM);
                sfx_play_sound(0x80000008);
                D_8029FB84 = 0;
                gBattleState2 = BATTLE_STATE2_UNK_5;
            }
            break;
        case BATTLE_STATE2_UNK_5:
            D_8029FB7C = start_script(D_80284880, 0xA, 0);
            D_8029FB4C = 25;
            gBattleState2 = BATTLE_STATE2_UNK_6;
            D_8029FB80 = D_8029FB7C->id;
            mdl_set_all_fog_mode(1);
            *D_801512F0 = 1;
            set_background_color_blend(0, 0, 0, 0);
            break;
        case BATTLE_STATE2_UNK_6:
            if (D_8029FB4C == 18) {
                playerData->curHP = playerData->curMaxHP;
                playerData->curFP = playerData->curMaxFP;
                x = player->currentPos.x + 0.0f;
                y = player->currentPos.y + 35.0f;
                fx_recover(0, x, y, (s32) player->currentPos.z, playerData->curHP);
                x = player->currentPos.x + 20.0f;
                y = player->currentPos.y + 25.0f;
                fx_recover(1, x, y, (s32) player->currentPos.z, playerData->curFP);
                playerData->specialBarsFilled = playerData->maxStarPower * 256;
            }

            if (D_8029FB4C != 0) {
                D_8029FB4C--;
                if (D_8029FB4C < 10) {
                    set_background_color_blend(0, 0, 0, ((10 - D_8029FB4C) * 0x10) & 0xF0);
                }
            } else {
                id = create_hud_element(D_802A9F0C);
                D_8029FA80[0] = id;
                set_hud_element_render_pos(id, 310, 140);
                set_hud_element_flags(id, HUD_ELEMENT_FLAGS_80);

                id = create_hud_element(D_802A9F5C);
                D_8029FA80[1] = id;
                set_hud_element_render_pos(id, 158, 340);
                set_hud_element_flags(id, HUD_ELEMENT_FLAGS_80);

                id = create_hud_element(D_802A9F84);
                D_8029FA80[3] = id;
                set_hud_element_render_pos(id, 158, 340);
                set_hud_element_flags(id, HUD_ELEMENT_FLAGS_80);

                id = create_hud_element(D_802A9FAC);
                D_8029FA80[2] = id;
                set_hud_element_render_pos(id, 6, 140);
                set_hud_element_flags(id, HUD_ELEMENT_FLAGS_80);

                id = create_hud_element(D_802841B4);
                D_8029FA90[0][0] = id;
                set_hud_element_render_pos(id, 160, 317);
                set_hud_element_flags(id, HUD_ELEMENT_FLAGS_80);

                for (i = 1; i < ARRAY_COUNT(D_8029FA90[0]); i++) {
                    id = create_hud_element(D_802841C0[0]);
                    D_8029FA90[0][i] = id;
                    set_hud_element_render_pos(id, 160, 317);
                    set_hud_element_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
                }

                id = create_hud_element(D_802841B8);
                D_8029FA90[0][7] = id;
                set_hud_element_render_pos(id, 312, 117);
                set_hud_element_flags(id, HUD_ELEMENT_FLAGS_80);

                for (i = 1; i < ARRAY_COUNT(D_8029FA90[0]); i++) {
                    id = create_hud_element(D_802841C0[10]);
                    D_8029FA90[1][i] = id;
                    set_hud_element_render_pos(id, 312, 117);
                    set_hud_element_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
                }

                id = create_hud_element(D_802841BC);
                D_8029FA90[2][0] = id;
                set_hud_element_render_pos(id, 8, 117);
                set_hud_element_flags(id, HUD_ELEMENT_FLAGS_80);

                for (i = 1; i < ARRAY_COUNT(D_8029FA90[20]); i++) {
                    id = create_hud_element(D_802841C0[20]);
                    D_8029FA90[2][i] = id;
                    set_hud_element_render_pos(id, 8, 117);
                    set_hud_element_flags(id, HUD_ELEMENT_FLAGS_80 | HUD_ELEMENT_FLAGS_DISABLED);
                }

                D_8029FB60[0] = 0;
                D_8029FB60[1] = 0;
                D_8029FB60[2] = 0;

                if (playerData->hardMaxFP != 50) {
                    id = D_8029FA90[0][1];
                    fpTens = playerData->curMaxFP / 10;
                    fpOnes = playerData->curMaxFP % 10;
                    set_hud_element_anim(id, D_80284238[fpTens]);
                    if (fpTens != 0) {
                        clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    }
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x - 14, y + 46);

                    id = D_8029FA90[0][2];
                    set_hud_element_anim(id, D_80284238[fpOnes]);
                    clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x - 8, y + 46);

                    id = D_8029FA90[0][3];
                    set_hud_element_anim(id, D_802AA320);
                    clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x - 3, y + 46);

                    temp_v1_4 = playerData->curMaxFP + 5;
                    id = D_8029FA90[0][4];
                    fpTens = temp_v1_4 / 10;
                    fpOnes = temp_v1_4 % 10;
                    set_hud_element_anim(id, D_802841C0[fpTens]);
                    if (fpTens != 0) {
                        clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    }
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x + 3, y + 46);

                    id = D_8029FA90[0][5];
                    set_hud_element_anim(id, D_802841C0[fpOnes]);
                    clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x + 10, y + 46);
                } else {
                    id = D_8029FA90[0][4];
                    fpTens = playerData->curMaxFP / 10;
                    fpOnes = playerData->curMaxFP % 10;
                    set_hud_element_anim(id, D_802841C0[fpTens]);
                    if (fpTens != 0) {
                        clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    }
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x - 6, y + 46);

                    id = D_8029FA90[0][5];
                    set_hud_element_anim(id, D_802841C0[fpOnes]);
                    clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x + 2, y + 46);
                    D_8029FB60[1] = 1;
                }

                if (is_ability_active(0xC)) {
                    id = D_8029FAA8;
                    set_hud_element_anim(id, gItemHudScripts[gItemTable[248].iconID][0]);
                    clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    set_hud_element_scale(id, 0.5f);
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x + 17, y + 46);
                }

                if (playerData->hardMaxHP != 50) {
                    HudScript** scriptsTemp;

                    scriptsTemp = D_80284238;
                    id = D_8029FA90[1][1];
                    fpTens = playerData->curMaxHP / 10;
                    fpOnes = playerData->curMaxHP % 10;
                    set_hud_element_anim(id, D_80284260[fpTens]);
                    if (fpTens != 0) {
                        clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    }
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x - 14, y + 46);

                    id = D_8029FA90[1][2];
                    set_hud_element_anim(id, scriptsTemp[fpOnes + 10]);
                    clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x - 8, y + 46);

                    id = D_8029FA90[1][3];
                    set_hud_element_anim(id, D_802AA694);
                    clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x - 3, y + 46);

                    temp_v1_5 = playerData->curMaxHP + 5;
                    id = D_8029FA90[1][4];

                    fpTens = temp_v1_5 / 10;
                    fpOnes = temp_v1_5 % 10;
                    scriptsTemp = D_802841C0;
                    new_var = scriptsTemp[fpOnes + 10];
                    set_hud_element_anim(id, D_802841E8[fpTens]);
                    if (fpTens != 0) {
                        clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    }
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x + 3, y + 46);

                    id = D_8029FA90[1][5];
                    set_hud_element_anim(id, new_var);
                    clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x + 10, y + 46);
                } else {
                    HudScript** scriptsTemp;
                    scriptsTemp = D_802841C0;

                    id = D_8029FA90[1][4];
                    fpTens = playerData->curMaxHP / 10;
                    fpOnes = playerData->curMaxHP % 10;
                    set_hud_element_anim(id, scriptsTemp[fpTens]);
                    if (fpTens != 0) {
                        clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    }
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x - 6, y + 46);

                    id = D_8029FA90[1][5];
                    set_hud_element_anim(id, scriptsTemp[fpOnes + 10]);
                    clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x + 2, y + 46);
                    D_8029FB60[0] = 1;
                }

                if (is_ability_active(4)) {
                    id = D_8029FAC4;
                    set_hud_element_anim(id, gItemHudScripts[gItemTable[231].iconID][0]);
                    clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    set_hud_element_scale(id, 0.5f);
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x + 17, y + 46);
                }

                if (playerData->maxBP != 30) {
                    HudScript** scriptsTemp;
                    HudScript* new_var2;

                    new_var2 = D_802AAA08;
                    scriptsTemp = D_80284238;
                    id = D_8029FA90[2][1];
                    fpTens = playerData->maxBP / 10;
                    fpOnes = playerData->maxBP % 10;
                    set_hud_element_anim(id, D_80284288[fpTens]);
                    if (fpTens != 0) {
                        clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    }
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x - 14, y + 46);

                    id = D_8029FA90[2][2];
                    set_hud_element_anim(id, scriptsTemp[fpOnes + 20]);
                    clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x - 8, y + 46);

                    id = D_8029FA90[2][3];
                    set_hud_element_anim(id, new_var2);
                    clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x - 3, y + 46);
                    temp_v1_5 = playerData->maxBP + 3;

                    scriptsTemp = D_802841C0;
                    id = D_8029FA90[2][4];
                    fpTens = temp_v1_5 / 10;
                    fpOnes = temp_v1_5 % 10;
                    set_hud_element_anim(id, D_80284210[fpTens]);
                    if (fpTens != 0) {
                        clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    }
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x + 3, y + 46);

                    id = D_8029FA90[2][5];
                    set_hud_element_anim(id, scriptsTemp[fpOnes + 20]);
                    clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x + 10, y + 46);
                } else {
                    id = D_8029FA90[2][4];
                    set_hud_element_anim(id, D_802841C0[23]);
                    clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x - 6, y + 46);

                    id = D_8029FA90[2][5];
                    set_hud_element_anim(id, D_802841C0[20]);
                    clear_hud_element_flags(id, HUD_ELEMENT_FLAGS_DISABLED);
                    get_hud_element_render_pos(id, &x, &y);
                    set_hud_element_render_pos(id, x + 2, y + 46);
                    D_8029FB60[2] = 1;
                }

                D_8029FAE8 = id = create_hud_element(HudScript_ProjectorBeam);
                create_hud_element_transform_B(id);
                set_hud_element_render_pos(id, 156, 13);
                set_hud_element_tint(id, 255, 255, 255);
                set_hud_element_transform_rotation_pivot(id, 0, -35);
                set_hud_element_transform_rotation(id, 0.0f, 0.0f, 180.0f);
                set_hud_element_transform_scale(id, 1.0f, 1.5f, 1.0f);
                set_hud_element_alpha(id, 200);
                set_hud_element_flags(id, HUD_ELEMENT_FLAGS_8000 | HUD_ELEMENT_FLAGS_80);

                D_8029FB48 = id = create_hud_element(D_802AAA30);
                set_hud_element_render_pos(id, 0, 0);
                set_hud_element_flags(id, HUD_ELEMENT_FLAGS_80);
                battleStatus->currentSubmenu = 1;
                D_8029FB4C = 10;
                gBattleState2 = BATTLE_STATE2_UNK_7;
            }
            break;
        case BATTLE_STATE2_UNK_7:
            id = D_8029FA80[0];
            get_hud_element_render_pos(id, &x, &y);
            x -= 20;
            set_hud_element_render_pos(id, x, y);

            for (i = 0; i < ARRAY_COUNT(D_8029FA90[1]); i++) {
                id = D_8029FA90[1][i];
                get_hud_element_render_pos(id, &x, &y);
                x -= 20;
                set_hud_element_render_pos(id, x, y);
            }

            id = D_8029FA80[1];
            get_hud_element_render_pos(id, &x, &y);
            y -= 20;
            set_hud_element_render_pos(id, x, y);

            id = D_8029FA80[3];
            get_hud_element_render_pos(id, &x, &y);
            y -= 20;
            set_hud_element_render_pos(id, x, y);

            for (i = 0; i < ARRAY_COUNT(D_8029FA90[0]); i++) {
                id = D_8029FA90[0][i];
                get_hud_element_render_pos(id, &x, &y);
                y -= 20;
                set_hud_element_render_pos(id, x, y);
            }

            id = D_8029FA88;
            get_hud_element_render_pos(id, &x, &y);
            x += 20;
            set_hud_element_render_pos(id, x, y);

            for (i = 0; i < ARRAY_COUNT(D_8029FA90[2]); i++) {
                id = D_8029FA90[2][i];
                get_hud_element_render_pos(id, &x, &y);
                x += 20;
                set_hud_element_render_pos(id, x, y);
            }

            D_8029FB4C--;
            if (D_8029FB4C == 0) {
                set_hud_element_tint(id, 128, 128, 128);
                x = 20;
                y = 186;
                set_window_properties(8, 20, 186, 280, 32, 20, func_80260948, NULL, -1);
                set_window_update(8, WINDOW_UPDATE_SHOW);
                gBattleState2 = BATTLE_STATE2_UNK_8;
            }
            break;
        case BATTLE_STATE2_UNK_8:
            if (battleStatus->currentButtonsPressed & 0x8000) {
                if (D_8029FB60[battleStatus->currentSubmenu] == 0) {
                    sfx_play_sound(SOUND_MENU_NEXT);
                    sfx_play_sound(SOUND_749);
                    gBattleState2 = BATTLE_STATE2_UNK_9;
                } else {
                    sfx_play_sound(0x21D);
                    gBattleState2 = BATTLE_STATE2_UNK_F;
                }
                break;
            }

            newSubmenu = currentSubmenu = battleStatus->currentSubmenu;
            if (battleStatus->currentButtonsHeld & BUTTON_STICK_LEFT) {
                newSubmenu--;
            }
            if (battleStatus->currentButtonsHeld & BUTTON_STICK_RIGHT) {
                newSubmenu++;
            }
            if (newSubmenu < 0) {
                newSubmenu = 0;
            }
            if (newSubmenu > 2) {
                newSubmenu = 2;
            }
            if (newSubmenu != currentSubmenu) {
                sfx_play_sound(SOUND_MENU_CHANGE_SELECTION);
                battleStatus->currentSubmenu = newSubmenu;
            }

            D_8029FB84++;
            if (D_8029FB84 > 100) {
                fx_confetti(3, 0.0f, 100.0f, 0.0f, 1.0f, 0x78);
                D_8029FB84 = 0;
            }
            break;
        case BATTLE_STATE2_UNK_9:
            free_hud_element(D_8029FAE8);
            set_window_update(8, WINDOW_UPDATE_HIDE);

            switch (battleStatus->currentSubmenu) {
                case 0:
                    playerData->hardMaxHP += 5;
                    playerData->curMaxHP += 5;
                    playerData->curHP += 5;
                    if (playerData->curMaxHP > 75) {
                        playerData->curMaxHP = 75;
                    }
                    if (playerData->curHP > playerData->curMaxHP) {
                        playerData->curHP = playerData->curMaxHP;
                    }
                    player->maxHP = playerData->curMaxHP;
                    player->currentHP = playerData->curHP;
                    break;
                case 1:
                    playerData->hardMaxFP += 5;
                    playerData->curMaxFP += 5;
                    playerData->curFP += 5;
                    if (playerData->curMaxFP > 75) {
                        playerData->curMaxFP = 75;
                    }
                    if (playerData->curFP > playerData->curMaxFP) {
                        playerData->curFP = playerData->curMaxFP;
                    }
                    break;
                case 2:
                    playerData->maxBP += 3;
                    if (playerData->maxBP > 30) {
                        playerData->maxBP = 30;
                    }
                    break;
            }

            set_animation(0, 0, 0x30009);

            if (partner != NULL) {
                script = start_script(partner->takeTurnScriptSource, 0xA, 0);
                partner->takeTurnScript = script;
                partner->takeTurnID = script->id;
                script->owner1.actorID = ACTOR_PARTNER;
            }
            if (!(gBattleStatus.flags2 & BS_FLAGS2_2000000)) {
                bgm_set_song(0, -1, 0, 2000, 8);
            }
            D_80284150 = 0;
            gBattleState2 = BATTLE_STATE2_PLAYER_DEFEATED;
            break;
        case BATTLE_STATE2_PLAYER_DEFEATED:
            if ((gGameStatusPtr->frameCounter % 2) != 0) {
                switch (battleStatus->currentSubmenu) {
                    case 0:
                        set_hud_element_flags(D_8029FA80[0], HUD_ELEMENT_FLAGS_DISABLED);
                        break;
                    case 1:
                        set_hud_element_flags(D_8029FA80[1], HUD_ELEMENT_FLAGS_DISABLED);
                        set_hud_element_flags(D_8029FA80[3], HUD_ELEMENT_FLAGS_DISABLED);
                        break;
                    case 2:
                        set_hud_element_flags(D_8029FA88, HUD_ELEMENT_FLAGS_DISABLED);
                        break;
                }
            } else {
                switch (battleStatus->currentSubmenu) {
                    case 0:
                        clear_hud_element_flags(D_8029FA80[0], HUD_ELEMENT_FLAGS_DISABLED);
                        break;
                    case 1:
                        clear_hud_element_flags(D_8029FA80[1], HUD_ELEMENT_FLAGS_DISABLED);
                        clear_hud_element_flags(D_8029FA80[3], HUD_ELEMENT_FLAGS_DISABLED);
                        break;
                    case 2:
                        clear_hud_element_flags(D_8029FA88, HUD_ELEMENT_FLAGS_DISABLED);
                        break;
                }
            }
            if (D_80284150 == 0xFF) {
                gBattleState2 = BATTLE_STATE2_UNK_B;
                break;
            }
            D_80284150 += 10;
            if (D_80284150 > 255) {
                D_80284150 = 255;
            }
            break;
        case BATTLE_STATE2_UNK_B:
            free_hud_element(D_8029FA80[0]);
            free_hud_element(D_8029FA80[1]);
            free_hud_element(D_8029FA80[3]);
            free_hud_element(D_8029FA80[2]);

            for (i = 0; i < ARRAY_COUNT(D_8029FA90); i++) {
                for (j = 0; j < ARRAY_COUNT(D_8029FA90[0]); j++) {
                    free_hud_element(D_8029FA90[i][j]);
                }
            }

            free_hud_element(D_8029FB48);
            set_background_color_blend(0, 0, 0, 0);
            btl_set_state(0x20);
            gBattleState2 = BATTLE_STATE2_UNK_2;
            break;
        case BATTLE_STATE2_UNK_F:
            width = get_msg_width(0x1D00AB, 0) + 31;
            x = 160 - (width / 2);
            y = 80;
            set_window_properties(9, x, y, width, 28, 10, func_80260A20, NULL, -1);
            set_window_update(9, WINDOW_UPDATE_SHOW);
            D_8029FB4C = 60;
            gBattleState2 = BATTLE_STATE2_UNK_10;
            break;
        case BATTLE_STATE2_UNK_10:
            if (gGameStatusPtr->pressedButtons & (BUTTON_A | BUTTON_B)) {
                D_8029FB4C = 0;
            }
            if (D_8029FB4C != 0) {
                D_8029FB4C--;
                break;
            }
            set_window_update(9, WINDOW_UPDATE_HIDE);
            gBattleState2 = BATTLE_STATE2_UNK_8;
            break;
        case BATTLE_STATE2_UNK_14:
            if (battleStatus->currentButtonsPressed & (BUTTON_A | BUTTON_B)) {
                D_8029FB84 = 99;
            }
            if (D_8029FB84 >= 99) {
                if (!(gBattleStatus.flags2 & 0x02000000)) {
                    bgm_set_song(0, -1, 0, 1500, 8);
                }
                D_80284150 = 0;
                func_8024E484(1, 270, 100, 8, 0, 0x2400, 0, 100);
                set_animation(0, 0, 0x30009);
                if (partner != NULL) {
                    set_animation(ACTOR_PARTNER, 0, D_80284154[playerData->currentPartner]);
                }
                D_8029FB4C = 6;
                gBattleState2 = BATTLE_STATE2_UNK_15;
                break;
            }
            break;
        case BATTLE_STATE2_UNK_15:
            if (D_8029FB4C != 0) {
                D_8029FB4C--;
                if (D_8029FB4C == 0) {
                    set_animation(0, 0, 0x10004);
                }
            } else {
                player->yaw = 0.0f;
                if (partner != NULL) {
                    partner->yaw = 0.0f;
                }

                player->currentPos.x += 4.0f;
                if (partner != NULL) {
                    partner->currentPos.x += 4.0f;
                }
            }
            if (D_80284150 == 0xFF) {
                gBattleState2 = BATTLE_STATE2_UNK_16;
                break;
            }
            D_80284150 += 20;
            if (D_80284150 > 255) {
                D_80284150 = 255;
            }
            break;
        case BATTLE_STATE2_UNK_16:
            if (does_script_exist(player->takeTurnID)) {
                kill_script_by_ID(player->takeTurnID);
            }
            if (partner != NULL && does_script_exist(partner->takeTurnID)) {
                kill_script_by_ID(partner->takeTurnID);
            }
            btl_set_state(0x20);
            gBattleState2 = BATTLE_STATE2_UNK_2;
            break;
    }
    D_8029FB84 += 1;
}
#else
INCLUDE_ASM(s32, "18C790", btl_state_update_celebration);
#endif

// d1, d2, d3 hell
#ifdef NON_MATCHING
void btl_draw_upgrade_windows(s32 arg0) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 x;
    s32 y;
    s32 d1;
    s32 d2;
    s32 d3;

    switch (arg0) {
        case 1:
            if (battleStatus->currentSubmenu != 0) {
                if (battleStatus->currentSubmenu == arg0) {
                    d1 = 0;
                    d2 = 0;
                    d3 = 100;
                } else {
                    d1 = 0;
                    d2 = 100;
                    d3 = 0;
                }
            } else {
                d1 = 0;
                d2 = 100;
                d3 = 100;
            }
            break;
        default:
        case 0:
            d1 = 100;
            d2 = 100;
            d3 = 100;
            break;
    }

    get_hud_element_render_pos(D_8029FA80[0], &x, &y);
    draw_box(0, 0xF, x - 22, y - 22, 0, 44, 44, 255, d1, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL,
             SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
    get_hud_element_render_pos(D_8029FA80[3], &x, &y);
    draw_box(0, 0xF, x - 22, y - 22, 0, 44, 44, 255, d2, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL,
             SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
    get_hud_element_render_pos(D_8029FA80[2], &x, &y);
    draw_box(0, 0xF, x - 22, y - 22, 0, 44, 44, 255, d3, 1.0f, 1.0f, 0.0f, 0.0f, 0.0f, NULL, NULL, NULL,
             SCREEN_WIDTH, SCREEN_HEIGHT, NULL);
}
#else
INCLUDE_ASM(s32, "18C790", btl_draw_upgrade_windows);
#endif

void btl_state_draw_celebration(void) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 rotZ;
    s32 id;
    s32 i;
    s32 j;

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_7:
            btl_draw_upgrade_windows(0);
            id = D_8029FA80[0];
            set_hud_element_tint(id, 128, 128, 128);
            draw_hud_element_clipped(id);
            id = D_8029FA80[3];
            set_hud_element_tint(id, 128, 128, 128);
            draw_hud_element_clipped(id);
            id = D_8029FA80[1];
            set_hud_element_tint(id, 128, 128, 128);
            draw_hud_element_clipped(id);
            id = D_8029FA80[2];
            set_hud_element_tint(id, 128, 128, 128);
            draw_hud_element_clipped(id);

            for (j = 0; j < ARRAY_COUNT(D_8029FA90); j++) {
                for (i = 0; i < ARRAY_COUNT(D_8029FA90[0]); i++) {
                    id = D_8029FA90[j][i];

                    set_hud_element_tint(id, 128, 128, 128);
                    draw_hud_element_clipped(id);
                }
            }
            break;
        case BATTLE_STATE2_UNK_8:
        case BATTLE_STATE2_UNK_F:
        case BATTLE_STATE2_UNK_10:
            switch (battleStatus->currentSubmenu) {
                case 0:
                    rotZ = 152;
                    set_hud_element_tint(D_8029FA80[0], 255, 255, 255);
                    set_hud_element_tint(D_8029FA80[3], 128, 128, 128);
                    set_hud_element_tint(D_8029FA80[1], 128, 128, 128);
                    set_hud_element_tint(D_8029FA80[2], 128, 128, 128);

                    for (i = 0; i < ARRAY_COUNT(D_8029FA90[0]); i++) {
                        id = D_8029FA90[0][i];

                        set_hud_element_tint(id, 128, 128, 128);
                    }

                    for (i = 0; i < ARRAY_COUNT(D_8029FA90[1]); i++) {
                        id = D_8029FA90[1][i];

                        set_hud_element_tint(id, 255, 255, 255);
                    }

                    for (i = 0; i < ARRAY_COUNT(D_8029FA90[2]); i++) {
                        id = D_8029FA90[2][i];

                        set_hud_element_tint(id, 128, 128, 128);
                    }

                    id = D_8029FA80[0];
                    if (get_hud_element_anim(id) != &D_802A9F34) {
                        set_hud_element_anim(id, &D_802A9F34);
                    }
                    id = D_8029FA80[3];
                    if (get_hud_element_anim(id) != &D_802A9F84) {
                        set_hud_element_anim(id, &D_802A9F84);
                    }
                    id = D_8029FA80[1];
                    if (get_hud_element_anim(id) != &D_802A9F5C) {
                        set_hud_element_anim(id, &D_802A9F5C);
                    }
                    id = D_8029FA80[2];
                    if (get_hud_element_anim(id) != &D_802A9FAC) {
                        set_hud_element_anim(id, &D_802A9FAC);
                    }
                    break;
                case 1:
                    rotZ = 180;
                    set_hud_element_tint(D_8029FA80[0], 128, 128, 128);
                    set_hud_element_tint(D_8029FA80[3], 255, 255, 255);
                    set_hud_element_tint(D_8029FA80[1], 255, 255, 255);
                    set_hud_element_tint(D_8029FA80[2], 128, 128, 128);

                    for (i = 0; i < ARRAY_COUNT(D_8029FA90[0]); i++) {
                        id = D_8029FA90[0][i];

                        set_hud_element_tint(id, 255, 255, 255);
                    }

                    for (i = 0; i < ARRAY_COUNT(D_8029FA90[1]); i++) {
                        id = D_8029FA90[1][i];

                        set_hud_element_tint(id, 128, 128, 128);
                    }

                    for (i = 0; i < ARRAY_COUNT(D_8029FA90[2]); i++) {
                        id = D_8029FA90[2][i];

                        set_hud_element_tint(id, 128, 128, 128);
                    }
                    break;
                case 2:
                default:
                    rotZ = 208;
                    set_hud_element_tint(D_8029FA80[0], 128, 128, 128);
                    set_hud_element_tint(D_8029FA80[3], 128, 128, 128);
                    set_hud_element_tint(D_8029FA80[1], 128, 128, 128);
                    set_hud_element_tint(D_8029FA80[2], 255, 255, 255);

                    for (i = 0; i < ARRAY_COUNT(D_8029FA90[0]); i++) {
                        id = D_8029FA90[0][i];

                        set_hud_element_tint(id, 128, 128, 128);
                    }

                    for (i = 0; i < ARRAY_COUNT(D_8029FA90[1]); i++) {
                        id = D_8029FA90[1][i];

                        set_hud_element_tint(id, 128, 128, 128);
                    }

                    for (i = 0; i < ARRAY_COUNT(D_8029FA90[2]); i++) {
                        id = D_8029FA90[2][i];

                        set_hud_element_tint(id, 255, 255, 255);
                    }
                    break;
            }

            btl_draw_upgrade_windows(1);
            draw_hud_element_clipped(D_8029FA80[0]);
            draw_hud_element_clipped(D_8029FA80[3]);
            draw_hud_element_clipped(D_8029FA80[1]);
            draw_hud_element_clipped(D_8029FA80[2]);

            for (j = 0; j < ARRAY_COUNT(D_8029FA90); j++) {
                for (i = 0; i < ARRAY_COUNT(D_8029FA90[0]); i++) {
                    draw_hud_element_clipped(D_8029FA90[j][i]);
                }
            }

            func_80144218(-1);
            id = D_8029FAE8;
            set_hud_element_transform_rotation(id, 0.0f, 0.0f, rotZ);
            func_80144238(id);
            break;
        case BATTLE_STATE2_UNK_9:
        case BATTLE_STATE2_PLAYER_DEFEATED:
            btl_draw_upgrade_windows(1);
            draw_hud_element_clipped(D_8029FA80[0]);
            draw_hud_element_clipped(D_8029FA80[3]);
            draw_hud_element_clipped(D_8029FA80[1]);
            draw_hud_element_clipped(D_8029FA80[2]);

            for (j = 0; j < ARRAY_COUNT(D_8029FA90); j++) {
                for (i = 0; i < ARRAY_COUNT(D_8029FA90[0]); i++) {
                    draw_hud_element_clipped(D_8029FA90[j][i]);
                }
            }

            set_screen_overlay_params_front(0, D_80284150);
            break;
        case BATTLE_STATE2_UNK_B:
            set_screen_overlay_params_front(0, D_80284150);
            break;
        case BATTLE_STATE2_UNK_15:
            if (D_80284150 != 0) {
                set_screen_overlay_params_front(0, D_80284150);
            }
            break;
    }

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_7:
        case BATTLE_STATE2_UNK_8:
        case BATTLE_STATE2_UNK_9:
            D_8029FB8C += 2;
            D_8029FB88 += D_8029FB8C;
            if (D_8029FB88 > 200) {
                D_8029FB88 = 200;
                D_8029FB8C = -D_8029FB8C / 3;
            }
            id = D_8029FB48;
            set_hud_element_render_pos(id, D_8029FB88 - 43, 176);
            draw_hud_element_clipped(id);
            break;
        case BATTLE_STATE2_PLAYER_DEFEATED:
            D_8029FB8C += 4;
            D_8029FB88 += D_8029FB8C;
            if (D_8029FB88 > 500) {
                D_8029FB88 = 500;
            }
            id = D_8029FB48;
            set_hud_element_render_pos(id, D_8029FB88 - 43, 176);
            draw_hud_element_clipped(id);
            break;
    }
}

void func_80260948(s32 arg0, s32 posX, s32 posY) {
    BattleStatus* battleStatus = &gBattleStatus;
    s32 xOffset;
    s32 msgID;

    switch (gBattleState2) {
        case BATTLE_STATE2_UNK_8:
        case BATTLE_STATE2_UNK_F:
        case BATTLE_STATE2_UNK_10:
            switch (battleStatus->currentSubmenu) {
                case 0:
                    if (D_8029FB60[0] == 0) {
                        msgID = 0x1D00A5;
                    } else {
                        msgID = 0x1D00A8;
                    }
                    xOffset = 9;
                    break;
                case 1:
                    if (D_8029FB60[1] == 0) {
                        msgID = 0x1D00A6;
                    } else {
                        msgID = 0x1D00A9;
                    }
                    xOffset = 9;
                    break;
                default:
                    if (D_8029FB60[2] == 0) {
                        msgID = 0x1D00A7;
                    } else {
                        msgID = 0x1D00AA;
                    }
                    xOffset = 9;
                    break;
            }
            draw_msg(msgID, posX + xOffset + 0x11, posY, 255, 0xA, 0);
            break;
    }
}

// TODO type is almost definitely incorrect
void func_80260A20(s64 posX, s32 posY) {
    draw_msg(0x1D00AB, posX + 11, posY + 6, 255, 0xF, 0);
}
