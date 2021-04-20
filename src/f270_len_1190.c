#include "common.h"
#include "ld_addrs.h"
#include "map.h"
#include "nu/nusys.h"

Gfx D_80077908[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetCombineMode(G_CC_DECALRGB, G_CC_DECALRGB),
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetTextureFilter(G_TF_POINT),
    gsSPEndDisplayList(),
};

// probably a file split
static s32 padding[] = {0, 0};

s32 D_80077950[] = { 0x8038F800, 0x803B5000, &D_803DA800 };

// TODO the gPauseMenuIconScripts should be DATA_START
// TODO the gPauseMenuHeldButtons should be BSS_START
// TODO 80278640 is BSS_END
NUPiOverlaySegment D_8007795C = {
    .romStart = pause_ROM_START,
    .romEnd = pause_ROM_END,
    .ramStart = pause_VRAM,
    .textStart = pause_VRAM,
    .textEnd = gPauseMenuIconScripts,
    .dataStart = gPauseMenuIconScripts,
    .dataEnd = &gPauseMenuHeldButtons,
    .bssStart = &gPauseMenuHeldButtons,
    .bssEnd = 0x80278640
};

void appendGfx_intro_logos();

// bss?
extern s8 D_800A0910[];

void state_init_logos(void) {
    Camera* cameras = &gCameras;
    GameStatus** gameStatus = &gGameStatusPtr;
    s8* romStart;
    s8* romEnd;
    s32* logoRam;
    s32* temp_800A0910;

    general_heap_create();
    (*gameStatus)->loadMenuState = 0;
    (*gameStatus)->menuCounter = 0;
    (*gameStatus)->bSkipIntro = FALSE;
    intro_logos_set_fade_alpha(255);
    intro_logos_set_fade_color(0);

    romEnd = logos_ROM_END;
    romStart = logos_ROM_START;
    logoRam = heap_malloc(romEnd - romStart);

    temp_800A0910 = &D_800A0910;
    *temp_800A0910 = logoRam;

    dma_copy(romStart, romEnd, logoRam);

    // TODO probably this is not ideal
    D_800A0918 = (*temp_800A0910) + 0x0;
    D_800A0914 = (*temp_800A0910) + 0x7000;
    D_800A091C = (*temp_800A0910) + 0x15000;

    nuContRmbForceStop();
    create_cameras_a();
    cameras[0].mode = 6;
    cameras[0].unk_06 = 1;
    cameras[0].nearClip = 0x10;
    cameras[0].farClip = 0x1000;
    gCurrentCameraID = 0;
    cameras[0].vfov = 25.0f;
    cameras[0].flags |= 0x2;
    cameras[1].flags |= 0x2;
    cameras[2].flags |= 0x2;
    cameras[3].flags |= 0x2;
    set_cam_viewport(0, 12, 28, 296, 184);
    cameras[0].unk_1E = 0x28;
    cameras[0].backgroundColor[0] = 0;
    cameras[0].backgroundColor[1] = 0;
    cameras[0].backgroundColor[2] = 0;
    cameras[0].unk_54 = 25.0f;
    cameras[0].unk_58 = 25.0f;
    cameras[0].unk_1C = 0;
    cameras[0].unk_20 = 100;
    cameras[0].unk_22 = 0;
    cameras[0].lookAt_eye[0] = 500.0f;
    cameras[0].lookAt_eye[1] = 1000.0f;
    cameras[0].lookAt_eye[2] = 1500.0f;
    cameras[0].unk_5C = 150.0f;
    clear_script_list();
    clear_dynamic_entity_list();
    func_8011D890();
    spr_init_sprites(0);
    func_8011E224();
    clear_entity_models();
    npc_list_clear();
    func_80141100();
    use_default_background_settings();
    clear_entity_data(1);
    clear_effect_data();
    OVERRIDE_FLAG_SET(0x2);
    intro_logos_update_fade();
    (*gameStatus)->enableBackground = FALSE;
}

//INCLUDE_ASM(s32, "f270_len_1190", state_step_logos);
void state_step_logos(void) {
    s32 gameModeTemp;
    s32* temp800A0910;

    if (gGameStatusPtr->bSkipIntro) {
        if (intro_logos_fade_out(0xA) != 0) {
            set_curtain_scale(1.0f);
            set_curtain_fade(0.0f);
            set_game_mode(2);
        }
    } else {
        switch (gGameStatusPtr->loadMenuState) {
            GameStatus** gameStatus;

            case 1:
                gameStatus = &gGameStatusPtr;

                if ((*gameStatus)->menuCounter == 0) {
                    intro_logos_set_fade_color(208);
                    (*gameStatus)->loadMenuState++;
                }
                (*gameStatus)->menuCounter--;
                break;
            case 2:
                if (intro_logos_fade_out(0xA) != 0) {
                    gGameStatusPtr->loadMenuState++;
                }
                break;
            case 3:
                if (intro_logos_fade_in(0xA) != 0) {
                    GameStatus** gameStatus = &gGameStatusPtr;

                    (*gameStatus)->loadMenuState++;
                    (*gameStatus)->menuCounter = 40;
                }
                break;
            case 4:
                gameStatus = &gGameStatusPtr;

                if ((*gameStatus)->menuCounter == 0) {
                    (*gameStatus)->loadMenuState++;
                    intro_logos_set_fade_color(208);
                }
                (*gameStatus)->menuCounter--;
                break;
            case 5:
                if (intro_logos_fade_out(0xA) != 0) {
                    gGameStatusPtr->loadMenuState++;
                }
                break;
            case 0:
            case 6:
                if (intro_logos_fade_in(0xA) != 0) {
                    GameStatus** gameStatus = &gGameStatusPtr;

                    (*gameStatus)->loadMenuState++;
                    (*gameStatus)->menuCounter = 30;
                }
                break;
            case 7:
                gameStatus = &gGameStatusPtr;
                if ((*gameStatus)->menuCounter == 0) {
                    (*gameStatus)->loadMenuState++;
                    intro_logos_set_fade_color(208);
                    (*gameStatus)->menuCounter = 30;
                }
                (*gameStatus)->menuCounter--;
                break;
            case 8:
                if (gGameStatusPtr->menuCounter == 0) {
                    gGameStatusPtr->loadMenuState++;
                    set_curtain_scale_goal(1.0f);
                    set_curtain_draw_callback(NULL);
                    set_curtain_fade_goal(0.3f);
                } else {
                    gGameStatusPtr->menuCounter--;
                }
                break;
            case 9:
                if (intro_logos_fade_out(0xA) != 0) {
                    GameStatus** gameStatus = &gGameStatusPtr;

                    (*gameStatus)->menuCounter = 15;
                    (*gameStatus)->loadMenuState++;
                }
                break;
            case 10:
                if (gGameStatusPtr->menuCounter == 0) {
                    gGameStatusPtr->loadMenuState++;
                } else {
                    gGameStatusPtr->menuCounter--;
                }
                break;
            case 11:
                temp800A0910 = &D_800A0910;
                heap_free(*temp800A0910);
                *temp800A0910 = 0;

                intro_logos_set_fade_alpha(255);
                gGameStatusPtr->unk_A8 = 0;
                set_game_mode(16);
                break;
        }
    }
    npc_list_update();
    update_cameras();
    intro_logos_update_fade();
}

void state_drawUI_logos(void) {
    appendGfx_intro_logos();
}

// all sorts of issues, but I think it's mostly with D_800A0918, 1C, and 14. Those need better types so they can have
// proper array accesses. the display list macros should mostly be good
#ifdef NON_MATCHING
void appendGfx_intro_logos(void) {
    s32 i;

    gDPPipeSync(gMasterGfxPos++);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetCombineMode(gMasterGfxPos++, G_CC_DECALRGB, G_CC_DECALRGB);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_FILL);
    gDPSetFillColor(gMasterGfxPos++, 0xE739E739);
    gDPFillRectangle(gMasterGfxPos++, 0, 0, 319, 239);
    gDPPipeSync(gMasterGfxPos++);

    switch (gGameStatusPtr->loadMenuState) {
        case 0:
        case 1:
        case 2:
            gSPDisplayList(gMasterGfxPos++, D_80077908);

            for (i = 0; i < 7; i++) {
                gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 128, D_800A0918 + (i << 0xC));
                gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadSync(gMasterGfxPos++);
                gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, 0, 508, 60);
                gDPPipeSync(gMasterGfxPos++);
                gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 0x0000, G_TX_RENDERTILE, 0,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                           G_TX_NOLOD);
                gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, 0, 508, 60);
                gSPTextureRectangle(gMasterGfxPos++, 384, 256 + i * 64, 896, 320 + i * 64, G_TX_RENDERTILE, 0, 0, 1024, 1024);
                gDPPipeSync(gMasterGfxPos++);
            }
            break;
        case 3:
        case 4:
        case 5:
            gSPDisplayList(gMasterGfxPos++, D_80077908);

            for (i = 0; i < 6; i++) {
                gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, D_800A091C + (i << 0xC));
                gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadSync(gMasterGfxPos++);
                gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, 0, 1020, 28);
                gDPPipeSync(gMasterGfxPos++);
                gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 0x0000, G_TX_RENDERTILE, 0,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                           G_TX_NOLOD);
                gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, 0, 1020, 28);
                gSPTextureRectangle(gMasterGfxPos++, 128, 356 + i * 32, 1152, 388 + i * 32, G_TX_RENDERTILE, 0, 0, 1024, 1024);
                gDPPipeSync(gMasterGfxPos++);
            }
            break;
        case 6:
        case 7:
        case 8:
        case 9:
            gSPDisplayList(gMasterGfxPos++, D_80077908);

            for (i = 0; i < 14; i++) {
                gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 256, D_800A0914[i] + (i << 0xC));
                gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 32, 0x0000, G_TX_LOADTILE, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD);
                gDPLoadSync(gMasterGfxPos++);
                gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, 0, 1020, 28);
                gDPPipeSync(gMasterGfxPos++);
                gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 64, 0x0000, G_TX_RENDERTILE, 0,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                           G_TX_NOLOD);
                gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, 0, 1020, 28);
                gSPTextureRectangle(gMasterGfxPos++, 128, 236 + i * 32, 1152, 268 + i * 32, G_TX_RENDERTILE, 0, 0, 1024, 1024);
                gDPPipeSync(gMasterGfxPos++);
            }
            break;
    }
}
#else
INCLUDE_ASM(void, "f270_len_1190", appendGfx_intro_logos);
#endif

void state_init_pause(void) {
    D_800A0921 = 0;
    D_800A0922 = 0;
    disable_player_input();
    set_time_freeze_mode(3);
    set_windows_visible(2);
}

void state_step_pause(void) {
    s8* temp800A0921 = &D_800A0921;
    s32 temp800A0921_2 = *temp800A0921;
    s8* temp800A0920;
    s8* temp800A0920_2;

    switch (temp800A0921_2) {
        case 0:
            update_counters();
            npc_list_update();
            update_player();
            update_effects();
            if (D_8009A658[1] == D_8009A64C) {
                D_800A0920 = 4;
                *temp800A0921 = 2;
                OVERRIDE_FLAG_SET(0x8);
                gGameStatusPtr->enableBackground &= ~0xF0;
                gGameStatusPtr->enableBackground |= 0x10;

            }
            break;
        case 2:
            temp800A0920 = &D_800A0920;
            if (*temp800A0920 >= 0) {
                GameStatus** gameStatus;

                if (*temp800A0920 != 0) {
                    (*temp800A0920)--;
                }

                if (*temp800A0920 == 0) {
                    *temp800A0920 = -1;
                    nuGfxSetCfb(&D_80077950, 2);
                    gameStatus = &gGameStatusPtr;
                    (*gameStatus)->unk_15E = (*gameStatus)->unk_15C;
                    sfx_stop_env_sounds();
                    func_8003B1A8();
                    (*gameStatus)->isBattle = temp800A0921_2;
                    allocate_hit_tables();
                    battle_heap_create();
                    nuContRmbForceStop();
                    func_80149670(0);
                    spr_init_sprites(0);
                    clear_model_data();
                    func_80148040();
                    use_default_background_settings();
                    clear_entity_models();
                    func_8011E224();
                    clear_dynamic_entity_list();
                    func_801452E8(_3169F0_VRAM, 0x38000);
                    func_80141100();
                    reset_status_menu();
                    clear_item_entity_data();
                    clear_script_list();
                    npc_list_clear();
                    clear_entity_data(0);
                    clear_trigger_data();
                    D_800A0924 = func_80149828();
                    func_801497FC(0);
                    bgm_quiet_max_volume();
                    nuPiReadRomOverlay(&D_8007795C);
                    pause_init();
                    OVERRIDE_FLAG_UNSET(0x8);
                }

                if (D_800A0920 >= 0) {
                    break;
                }
            }

            temp800A0920_2 = &D_800A0920;
            if (*temp800A0920_2 >= -10) {
                pause_handle_input(0, 0);
                (*temp800A0920_2)--;
            } else {
                pause_handle_input(gGameStatusPtr->pressedButtons, gGameStatusPtr->heldButtons);
            }
            D_800A0922 = 0;
            break;
    }
}

void state_drawUI_pause(void) {
}

void state_init_unpause(void) {
    if (D_800A0922 > 0) {
        D_800A0921 = 0;
    } else {
        D_800A0921 = 1;
    }
    D_800A0920 = 4;
}

void state_step_unpause(void) {
    s8* temp800A0921 = &D_800A0921;

    switch (*temp800A0921) {
        s8* temp800A0920;
        s16* temp800A0922;
        s16* temp800A0922_2;

        case 0:
        case 1:
            temp800A0920 = &D_800A0920;

            if (*temp800A0920 == 4) {
                OVERRIDE_FLAG_SET(0x8);
            }

            if (*temp800A0920 >= 0) {
                if (*temp800A0920 != 0) {
                    (*temp800A0920)--;
                }

                if (*temp800A0920 == 0) {
                    if (*temp800A0920 == 0) {
                        GameStatus** gameStatus = &gGameStatusPtr;
                        PlayerStatus* playerStatus;
                        MapConfig* mapConfig;
                        Map* map;
                        s32 assetData;
                        s32 assetSize;

                        *temp800A0920 = -1;
                        nuGfxSetCfb(&D_80077950, ARRAY_COUNT(D_80077950));
                        pause_cleanup();
                        OVERRIDE_FLAG_UNSET(0x8);
                        mapConfig = get_current_map_header();
                        map = &gAreas[(*gameStatus)->areaID].maps[(*gameStatus)->mapID];
                        (*gameStatus)->isBattle = FALSE;
                        (*gameStatus)->enableBackground &= ~0xF0;
                        func_8005AF84();
                        func_8002ACDC();
                        nuContRmbForceStopEnd();
                        func_80149670(1);
                        spr_init_sprites((*gameStatus)->unk_84);
                        init_model_data();
                        func_801480F0();
                        init_entity_models();
                        func_8011E310();
                        init_dynamic_entity_list();
                        func_801452E8(0, 0);
                        init_menu_icon_list();
                        init_item_entity_list();
                        init_script_list();
                        npc_list_update_current();
                        func_80110E58();
                        init_trigger_list();
                        func_801497FC(D_800A0924);
                        bgm_reset_max_volume();
                        load_world_script_api();
                        assetData = load_asset_by_name(&D_800D9230, &assetSize);
                        decode_yay0(assetData, &D_80210000);
                        general_heap_free(assetData);
                        initialize_collision();
                        load_collision();

                        if (map->dmaStart != NULL) {
                            dma_copy(map->dmaStart, map->dmaEnd, map->dmaDest);
                        }

                        load_map_bg(map->bgName);
                        if (mapConfig->background != NULL) {
                            read_background_size(mapConfig->background);
                        } else {
                            set_background_size(296, 200, 12, 20);
                        }

                        gGameStatusPtr->unk_15C = gGameStatusPtr->unk_15E;
                        calculate_model_sizes();
                        func_8003B1B0();
                        set_windows_visible(0);
                        func_800E98C4();
                        set_time_freeze_mode(1);
                        D_800A0921 = 3;
                        playerStatus = &gPlayerStatus;
                        playerStatus->unk_0F = playerStatus->unk_0E - 1;
                        D_802D9D71 = D_802D9D70 + 1;

                        update_counters();
                        npc_list_update();
                        update_player();
                        update_effects();

                        temp800A0922_2 = &D_800A0922;
                        *temp800A0922_2 -= 20;
                        if (*temp800A0922_2 < 0) {
                            *temp800A0922_2 = 0;
                        }
                    }
                }
            }
            break;
        case 3:
            update_counters();
            npc_list_update();
            update_player();
            update_effects();

            temp800A0922 = &D_800A0922;
            if (*temp800A0922 == 0) {
                *temp800A0921 = 4;
            } else {
                *temp800A0922 -= 20;
                if (*temp800A0922 < 0) {
                    *temp800A0922 = 0;
                }
            }
            break;
        case 4:
            set_time_freeze_mode(0);
            update_counters();
            npc_list_update();
            update_player();
            update_effects();
            enable_player_input();
            set_game_mode(4);
            break;
    }
}

void state_drawUI_unpause(void) {
}
