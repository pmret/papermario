#include "common.h"
#include "nu/nusys.h"
#include "hud_element.h"
#include "sprite.h"

void title_screen_draw_copyright(f32);

s16 D_800779C0[2] = {0, 0};
s32 D_800779C4 = 0;
s8 D_800779C8[2] = {0, 0};
s8 D_800779CA = 0;
s8 D_800779CB = 0x45;
s32 D_800779CC = 0x52524F52;
s32 D_800779D0 = 0xF7F7F700;
s32 D_800779D4 = 0;
s32 D_800779D8[] = { 0x00000000, 0x00000000, 0x00000045, 0x52524F52, 0xF7F7F700, 0x00000000, 0x00000000, 0x00000000,
                     0x00000045, 0x52524F52, 0xF7F7F700, 0x00000000, 0x00000000, 0x00000000, 0x00000045, 0x52524F52,
                     0xF7F7F700, 0x00000000, 0x00000000,
                   };
s32 D_80077A24 = 0x01010101;
s32 D_80077A28 = 0;
s32 D_80077A2C = 0;
s32 D_80077A30 = 0;
s32 D_80077A34[1] = {0};

Lights1 D_80077A38 = {
    .a = {
        .l = {
            .col = {255, 255, 255},
            .colc = {255, 255, 255},
        },
    },
    .l = {
        {
            .l = {
                .col = {0, 0, 0},
                .colc = {0, 0, 0},
                .dir = {0, 0, 0},
            }
        }
    }
};

Gfx D_80077A50[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_1CYCLE),
    gsDPSetRenderMode(G_RM_CLD_SURF, G_RM_CLD_SURF2),
    gsDPSetCombineMode(G_CC_DECALRGBA, G_CC_DECALRGBA),
    gsDPSetTextureFilter(G_TF_POINT),
    gsSPTexture(-1, -1, 0, G_TX_RENDERTILE, G_ON),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetColorDither(G_CD_DISABLE),
    gsDPSetAlphaDither(G_AD_DISABLE),
    gsDPSetTextureLOD(G_TL_TILE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetTextureDetail(G_TD_CLAMP),
    gsDPSetTextureConvert(G_TC_FILT),
    gsDPSetCombineKey(G_CK_NONE),
    gsDPSetAlphaCompare(G_AC_NONE),
    gsDPNoOp(),
    gsDPSetScissor(G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT),
    gsSPEndDisplayList(),
};

typedef struct TitleDataStruct {
    /* 0x0 */ s32 unk_00;
    /* 0x4 */ s32 unk_04;
    /* 0x8 */ s32 unk_08;
} TitleDataStruct; // size = 0xC

extern s16 D_800A0970;
extern TitleDataStruct* D_800A0974;
extern s32* D_800A0978;
extern s32* D_800A097C;
extern s32* D_800A0980;
extern s16 D_800A0988;

void appendGfx_title_screen(void*);
void draw_title_screen_NOP(void);
void title_screen_draw_images(f32, f32);
void title_screen_draw_logo(f32);
void title_screen_draw_press_start(void);

// Commented section
#ifdef NON_MATCHING
void state_init_title_screen(void) {
    s32 titleDataSize;
    TitleDataStruct* temp_a0;
    void* titleDataDst;
    void* titleData;

    gOverrideFlags = 0;
    timeFreezeMode = 0;
    D_8014C248[0] = 1;
    general_heap_create();
    clear_printers();
    func_801497FC(0);
    gGameStatusPtr->introState = 0;
    gGameStatusPtr->introCounter = 0;
    gGameStatusPtr->isBattle = 0;
    gGameStatusPtr->creditsViewportMode = -1;
    intro_logos_update_fade();
    titleData = load_asset_by_name("title_data", &titleDataSize);
    titleDataDst = D_800A0974 = heap_malloc(titleDataSize);
    decode_yay0(titleData, titleDataDst);
    general_heap_free(titleData);

    // this is the non-matching part
    D_800A0978 = D_800A0974->unk_00 + (u8*)D_800A0974;
    D_800A0980 = D_800A0974->unk_08 + (u8*)D_800A0974;
    D_800A097C = D_800A0974->unk_04 + (u8*)D_800A0974;

    create_cameras_a();
    gCameras[0].updateMode = 6;
    gCameras[0].unk_06 = 1;
    gCameras[0].nearClip = 0x10;
    gCameras[0].farClip = 0x1000;
    gCurrentCameraID = 0;
    gCameras[0].vfov = 25.0f;
    gCameras[0].flags |= CAMERA_FLAGS_2;
    gCameras[1].flags |= CAMERA_FLAGS_2;
    gCameras[2].flags |= CAMERA_FLAGS_2;
    gCameras[3].flags |= CAMERA_FLAGS_2;
    set_cam_viewport(0, 12, 28, 296, 184);
    gCameras[0].unk_1E = 40;
    gCameras[0].bgColor[0] = 0;
    gCameras[0].bgColor[1] = 0;
    gCameras[0].bgColor[2] = 0;
    gCameras[0].unk_54 = 25.0f;
    gCameras[0].unk_58 = 25.0f;
    gCameras[0].unk_1C = 0;
    gCameras[0].unk_20 = 100;
    gCameras[0].unk_22 = 0;
    gCameras[0].lookAt_eye.x = 500.0f;
    gCameras[0].lookAt_eye.y = 1000.0f;
    gCameras[0].lookAt_eye.z = 1500.0f;
    gCameras[0].unk_5C = 150.0f;
    clear_script_list();
    clear_generic_entity_list();
    clear_render_tasks();
    spr_init_sprites(0);
    clear_animator_list();
    clear_entity_models();
    clear_npcs();
    clear_hud_element_cache();
    reset_background_settings();
    clear_entity_data(1);
    clear_effect_data();
    gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_RENDER_WORLD;
    clear_player_data();
    gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
    game_mode_set_fpDrawAuxUI(0, appendGfx_title_screen);
    load_map_bg("title_bg");
    read_background_size(&gBackgroundImage);
    bgm_set_song(0, SONG_MAIN_THEME, 0, 500, 8);
    D_800A0988 = 0x1E0;
}
#else
INCLUDE_ASM(void, "state_title_screen", state_init_title_screen, void);
#endif

//INCLUDE_ASM(void, "state_title_screen", state_step_title_screen, void);
void state_step_title_screen(void) {
    s16* temp;
    u32 pressedButtons = gGameStatusPtr->pressedButtons;

    set_curtain_scale(1.0f);
    set_curtain_fade(0.0f);

    if (D_800A0988 > 0) {
        D_800A0988--;
    }

    switch (gGameStatusPtr->introState) {
        case 0:
            D_800A0970 = 3;
            gOverrideFlags |= GLOBAL_OVERRIDES_8;
            gGameStatusPtr->unk_B0 = 20;
            gGameStatusPtr->unk_AF = gGameStatusPtr->unk_B0;
            gGameStatusPtr->introState++;
            break;
        case 1:
            if (D_800A0970 != 0) {
                D_800A0970--;
            } else {
                if (gGameStatusPtr->unk_AF != 0) {
                    gGameStatusPtr->unk_AF--;
                }
                gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
                if (intro_logos_fade_in(6) != 0) {
                    if (gGameStatusPtr->unk_AF == 0) {
                        gGameStatusPtr->introState = 2;
                    }
                }
                intro_logos_update_fade();
            }
            break;
        case 2:
            if (D_80077A34[0] != NULL && D_800A0988 == 120) {
                bgm_set_song(0, -1, 0, 3900, 8);
            }
            if (D_800A0988 == 0) {
                gGameStatusPtr->introState = 4;
                if (D_80077A34[0] == NULL) {
                    *D_800779C0 = 10;
                } else {
                    *D_800779C0 = 9;
                }
                D_80077A34[0] ^= 1;
                return;
            }
            if (pressedButtons & (BUTTON_A | BUTTON_START)) {
                gGameStatusPtr->introState = 4;
                *D_800779C0 = 5;
                sfx_play_sound(SOUND_D5);
                bgm_set_song(0, SONG_FILE_SELECT, 0, 500, 8);
                return;
            }
            break;
        case 4:
            gGameStatusPtr->introState = 5;
            intro_logos_set_fade_color(0xD0);
            if (*D_800779C0 == 9 || *D_800779C0 == 10) {
                gGameStatusPtr->unk_B0 = 20;
            } else {
                gGameStatusPtr->unk_B0 = 10;
            }
            gGameStatusPtr->unk_AF = gGameStatusPtr->unk_B0;
            break;
        case 5:
            if (*D_800779C0 == 9 || *D_800779C0 == 10) {
                if (gGameStatusPtr->unk_AF != 0) {
                    gGameStatusPtr->unk_AF--;
                }
                if (intro_logos_fade_out(0xA) != 0) {
                    if (gGameStatusPtr->unk_AF == 0) {
                        gGameStatusPtr->unk_AF = 3;
                        gOverrideFlags |= GLOBAL_OVERRIDES_8;
                        gGameStatusPtr->introState = 6;
                    }
                }
                intro_logos_update_fade();
            } else if (*D_800779C0 == 5) {
                if (gGameStatusPtr->unk_AF == 0) {
                    gGameStatusPtr->unk_AF = 3;
                    gOverrideFlags |= GLOBAL_OVERRIDES_8;
                    gGameStatusPtr->introState = 6;
                } else {
                    gGameStatusPtr->unk_AF--;
                }
            } else {
                gGameStatusPtr->unk_AF = 3;
                gOverrideFlags |= GLOBAL_OVERRIDES_8;
                gGameStatusPtr->introState = 6;
            }
            break;
        case 6:
            if (gGameStatusPtr->unk_AF != 0) {
                gGameStatusPtr->unk_AF--;
                break;
            }
            general_heap_create();
            clear_render_tasks();
            create_cameras_a();
            clear_entity_models();
            clear_animator_list();
            clear_npcs();
            clear_hud_element_cache();
            spr_init_sprites(0);
            clear_entity_data(1);
            clear_windows();
            gOverrideFlags &= ~GLOBAL_OVERRIDES_8;
            gOverrideFlags &= ~GLOBAL_OVERRIDES_DISABLE_RENDER_WORLD;
            temp = D_800779C0;
            gGameStatusPtr->entryID = 0;

            switch (temp[0]) {
                case 9:
                    gGameStatusPtr->creditsViewportMode = 0;
                    set_game_mode(0x10);
                    break;
                case 10:
                    set_game_mode(0x11);
                    break;
                case 5:
                    gGameStatusPtr->areaID = 0;
                    gGameStatusPtr->mapID = 0xB;
                    gGameStatusPtr->entryID = 0;
                    set_game_mode(0xE);
                    break;
            }
            return;
    }

    if (!(gOverrideFlags & GLOBAL_OVERRIDES_8)) {
        update_npcs();
        update_cameras();
    }
}

void state_drawUI_title_screen(void) {
    switch (gGameStatusPtr->introState) {
        case 0:
            D_80077A28 = 0;
            D_80077A2C = 0;
            D_80077A30 = 0;
            draw_title_screen_NOP();
            break;
        case 2:
            draw_title_screen_NOP();
            if (gGameStatusPtr->contBitPattern & 1) {
                title_screen_draw_press_start();
            }
        case 3:
            break;
        case 1:
        case 4:
        case 5:
            draw_title_screen_NOP();
            break;
    }
}

void appendGfx_title_screen(void* data) {
    f32 phi_f12;
    s32 temp;

    switch (gGameStatusPtr->introState) {
        case 0:
        case 3:
            break;
        case 1:
            phi_f12 = gGameStatusPtr->unk_AF;
            phi_f12 /= gGameStatusPtr->unk_B0;
            phi_f12 = SQ(phi_f12);
            title_screen_draw_images(phi_f12, phi_f12);
            break;
        case 2:
            title_screen_draw_images(0.0f, 0.0f);
            break;
        case 4:
            title_screen_draw_images(0.0f, 0.0f);
            break;
        case 5:
            temp = gGameStatusPtr->unk_AF - 1;
            phi_f12 = gGameStatusPtr->unk_B0 - temp;
            phi_f12 /= gGameStatusPtr->unk_B0;
            phi_f12 = SQ(phi_f12);
            title_screen_draw_images(phi_f12, phi_f12);
            break;
    }

    gDPPipeSync(gMasterGfxPos++);
    gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxCfb_ptr));
    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
    gDPPipeSync(gMasterGfxPos++);
    gSPClearGeometryMode(gMasterGfxPos++, G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING |
                            G_TEXTURE_GEN | G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH);
    gSPSetGeometryMode(gMasterGfxPos++, G_ZBUFFER | G_SHADE | G_LIGHTING | G_SHADING_SMOOTH);
    gSPSetLights1(gMasterGfxPos++, D_80077A38);

    gSPTexture(gMasterGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
    gDPSetTextureLOD(gMasterGfxPos++, G_TL_TILE);
    gDPSetTexturePersp(gMasterGfxPos++, G_TP_PERSP);
    gDPSetTextureFilter(gMasterGfxPos++, G_TF_BILERP);
    gDPSetColorDither(gMasterGfxPos++, G_CD_DISABLE);
    gDPSetTextureDetail(gMasterGfxPos++, G_TD_CLAMP);
    gDPSetTextureConvert(gMasterGfxPos++, G_TC_FILT);
    gDPSetCombineKey(gMasterGfxPos++, G_CK_NONE);
    gDPSetAlphaCompare(gMasterGfxPos++, G_AC_NONE);
    render_frame(0);
    render_frame(1);
}

void draw_title_screen_NOP(void) {
}

void title_screen_draw_images(f32 arg0, f32 arg1) {
    title_screen_draw_logo(arg0);
    title_screen_draw_copyright(arg1);
}

INCLUDE_ASM(void, "state_title_screen", title_screen_draw_logo);

void title_screen_draw_press_start(void) {
    switch (D_80077A2C) {
        case 0:
            D_80077A28 -= 128;
            if (D_80077A28 < 0) {
                D_80077A28 = 0;
            }

            D_80077A30++;
            if (D_80077A30 >= 16) {
                D_80077A30 = 0;
                D_80077A2C = 1;
            }
            break;
        case 1:
            D_80077A28 += 128;
            if (D_80077A28 > 255) {
                D_80077A28 = 255;
            }

            D_80077A30++;
            if (D_80077A30 >= 16) {
                D_80077A30 = 0;
                D_80077A2C = 0;
            }
    }

    gSPDisplayList(gMasterGfxPos++, D_80077A50);
    gDPSetCombineMode(gMasterGfxPos++, G_CC_MODULATEIA_PRIM, G_CC_MODULATEIA_PRIM);
    gDPSetPrimColor(gMasterGfxPos++, 0, 0, 248, 240, 152, D_80077A28);
    gDPPipeSync(gMasterGfxPos++);
    gDPLoadTextureBlock(gMasterGfxPos++, D_800A0980, G_IM_FMT_IA, G_IM_SIZ_8b, 128, 32, 0, G_TX_NOMIRROR | G_TX_WRAP,
              G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
    gSPTextureRectangle(gMasterGfxPos++, 384, 548, 896, 676, G_TX_RENDERTILE, 0, 0, 0x0400, 0x0400);
    gDPPipeSync(gMasterGfxPos++);
}

void title_screen_draw_copyright(f32 arg0) {
    s32 alpha;
    s32 i;

    gSPDisplayList(gMasterGfxPos++, &D_80077A50);
    gDPPipeSync(gMasterGfxPos++);

    alpha = 255.0f - (arg0 * 255.0f);
    if (alpha < 255) {
        if (alpha < 0) {
            alpha = 0;
        }
        gDPSetCombineLERP(gMasterGfxPos++, 0, 0, 0, TEXEL0, TEXEL0, 0, PRIMITIVE, 0, 0, 0, 0, TEXEL0, TEXEL0, 0,
                          PRIMITIVE, 0);
        gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0, 0, 0, alpha);
    }

    for (i = 0; i < 2; i++) {
        alpha = 0; // TODO figure out why this is needed
        gDPLoadTextureTile(gMasterGfxPos++, &D_800A097C[0x240 * i], G_IM_FMT_IA, G_IM_SIZ_8b, 144, 32, 0, 0, 143, 15, 0,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD,
                           G_TX_NOLOD);
        gSPTextureRectangle(gMasterGfxPos++, 356, 764 + (0x40 * i), 932, 828 + (0x40 * i), G_TX_RENDERTILE,
                            0, 0, 0x0400, 0x0400);
    }
    gDPPipeSync(gMasterGfxPos++);
}
