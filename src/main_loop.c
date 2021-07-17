#include "common.h"
#include "nu/nusys.h"
#include "ld_addrs.h"

s8 D_80074020 = 1;
s8 D_80074021 = 5;

GameStatus gGameStatus = {0};
GameStatus* gGameStatusPtr = &gGameStatus;
s16 D_800741A0 = 0;
s16 D_800741A2 = 0;
s32 D_800741A4 = 0;
s32 D_800741A8[] = { 0x00010000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00010000, 0x00000000, 0x00000001,
                     0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000,
                     0x00000000, 0x00000000,
                   };
u16 gMatrixListPos = 0;
u16 D_800741F2 = 0;
s32 gCurrentDisplayContextIndex = 0;
s32 D_800741F8 = 0;
s32 D_800741FC = 0;
s32 D_80074200[] = { 0x028001E0, 0x01FF0000, 0x028001E0, 0x01FF0000 };

Gfx D_80074210[] = {
    gsDPSetRenderMode(G_RM_OPA_SURF, G_RM_OPA_SURF2),
    gsDPSetCombineMode(G_CC_SHADE, G_CC_SHADE),
    gsDPSetColorDither(G_CD_BAYER),
    gsSPEndDisplayList(),
};

Gfx D_80074230[] = {
    gsSPViewport(&D_80074200),
    gsSPClearGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BOTH | G_FOG | G_LIGHTING | G_TEXTURE_GEN |
                          G_TEXTURE_GEN_LINEAR | G_LOD | G_SHADING_SMOOTH | G_CLIPPING | 0x0040F9FA),
    gsSPSetGeometryMode(G_ZBUFFER | G_SHADE | G_CULL_BACK | G_SHADING_SMOOTH),
    gsSPTexture(0, 0, 0, G_TX_RENDERTILE, G_OFF),
    gsSPEndDisplayList(),
};

// BSS
extern s32 timeFreezeMode BSS;

extern s16 D_8009A690;

void gfx_init_state(void);
void gfx_draw_background(void);

void step_game_loop(void) {
    PlayerData* playerData = &gPlayerData;

    update_input();

    gGameStatusPtr->frameCounter++;

    playerData->frameCounter += 2;
    if (playerData->frameCounter > 215999999) {
        playerData->frameCounter = 215999999;
    }

    update_max_rumble_duration();

    if (D_80074021 != 0) {
        D_80074021-- ;
        if (D_80074021 == 0) {
            D_80074021 = D_80074020;
        } else {
            return;
        }
    }

    func_8011BAE8();
    npc_iter_no_op();
    update_generic_entities();
    update_triggers();
    update_scripts();
    update_messages();
    update_hud_elements();
    step_current_game_mode();
    update_entities();
    func_80138198();
    bgm_update_music_settings();
    update_ambient_sounds();
    sfx_update_looping_sound_params();
    update_windows();
    update_curtains();

    if (gOverrideFlags & 0x20) {
        switch (D_800741A2) {
            case 0:
                gOverrideFlags |= 0x200;
                disable_player_input();

                if (D_800741A0 == 255) {
                    D_800741A2 = 1;
                    D_8009A690 = 3;
                } else {
                    D_800741A0 += 10;
                    if (D_800741A0 > 255) {
                        D_800741A0 = 255;
                    }
                }
                break;
            case 1:
                gOverrideFlags |= 0x8;
                D_8009A690--;
                if (D_8009A690 == 0) {
                    sfx_stop_env_sounds();
                    set_game_mode(0);
                    gOverrideFlags &= ~0x20;
                }
                break;
        }
    } else {
        D_800741A0 = 0;
        D_800741A2 = 0;
    }

    if (gOverrideFlags & 0x100) {
        gOverrideFlags |= 0x1000;
    } else {
        gOverrideFlags &= ~0x1000;
    }

    if (gOverrideFlags & 0x200) {
        gOverrideFlags |= 0x2000;
    } else {
        gOverrideFlags &= ~0x2000;
    }

    if (gOverrideFlags & 0x400) {
        gOverrideFlags |= 0x4000;
    } else {
        gOverrideFlags &= ~0x4000;
    }

    if (gOverrideFlags & 0x800) {
        gOverrideFlags |= 0x8000;
    } else {
        gOverrideFlags &= ~0x8000;
    }

    rand_int(1);
}

void gfx_task_background(void) {
    gDisplayContext = &D_80164000[gCurrentDisplayContextIndex];
    gMasterGfxPos = &gDisplayContext->backgroundGfx[0];

    gfx_init_state();
    gfx_draw_background();

    gDPFullSync(gMasterGfxPos++);
    gSPEndDisplayList(gMasterGfxPos++);

    // TODO these << 3 >> 3 shouldn't be necessary. There's almost definitely something we're missing here...
    ASSERT((s32)((u32)((gMasterGfxPos - gDisplayContext->backgroundGfx) << 3) >> 3) < ARRAY_COUNT(
               gDisplayContext->backgroundGfx))

    nuGfxTaskStart(&gDisplayContext->backgroundGfx[0], (u32)(gMasterGfxPos - gDisplayContext->backgroundGfx) * 8,
                   NU_GFX_UCODE_F3DEX2, NU_SC_NOSWAPBUFFER);
}

void gfx_draw_frame(void) {
    gMatrixListPos = 0;
    gMasterGfxPos = &gDisplayContext->mainGfx[0];

    if (gOverrideFlags & 8) {
        gCurrentDisplayContextIndex = gCurrentDisplayContextIndex ^ 1;
        return;
    }

    gSPMatrix(gMasterGfxPos++, D_800741A8, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    spr_render_init(gDisplayContext, &gMasterGfxPos);

    if (!(gOverrideFlags & 2)) {
        render_frame(0);
    }

    player_render_interact_prompts();
    func_802C3EE4();
    render_screen_overlay_backUI();
    render_generic_entities_backUI();
    render_hud_elements_backUI();
    render_effects_UI();
    state_render_backUI();

    if (!(gOverrideFlags & 0x10000)) {
        render_window_root();
    }
    if (!(gOverrideFlags & 2) && gGameStatusPtr->disableScripts == 0) {
        render_frame(1);
    }

    if (!(gOverrideFlags & 0x100010)) {
        render_messages();
    }

    render_generic_entities_frontUI();
    render_hud_elements_frontUI();
    render_screen_overlay_frontUI();

    if ((gOverrideFlags & 0x100010) == 0x10) {
        render_messages();
    }

    render_curtains();

    if (gOverrideFlags & 0x100000) {
        render_messages();
    }
    if (gOverrideFlags & 0x10000) {
        render_window_root();
    }

    state_render_frontUI();

    if (gOverrideFlags & 0x20) {
        switch (D_800741A2) {
            case 0:
            case 1:
                _render_transition_stencil(7, D_800741A0, 0);
                break;
        }
    }

    ASSERT((s32)(((u32)(gMasterGfxPos - gDisplayContext->mainGfx) << 3) >> 3) < ARRAY_COUNT(gDisplayContext->mainGfx));

    gDPFullSync(gMasterGfxPos++);
    gSPEndDisplayList(gMasterGfxPos++);

    nuGfxTaskStart(gDisplayContext->mainGfx, (u32)(gMasterGfxPos - gDisplayContext->mainGfx) * 8, NU_GFX_UCODE_F3DEX2,
                   NU_SC_TASK_LODABLE | NU_SC_SWAPBUFFER);
    gCurrentDisplayContextIndex = gCurrentDisplayContextIndex ^ 1;
    func_8002C890(D_8009A64C, 0x140, 0xF0);
}

void load_engine_data(void) {
    s32 i;

    dma_copy(FEE30_ROM_START, FEE30_ROM_END, FEE30_VRAM);
    dma_copy(_759B0_ROM_START, _759B0_ROM_END, _759B0_VRAM);
    dma_copy(evt_ROM_START, evt_ROM_END, evt_VRAM);
    dma_copy(_102610_ROM_START, _102610_ROM_END, _102610_VRAM);
    dma_copy(A5DD0_ROM_START, A5DD0_ROM_END, A5DD0_VRAM);
    dma_copy(_10CC10_ROM_START, _10CC10_ROM_END, _10CC10_VRAM);

    gOverrideFlags = 0;
    gGameStatusPtr->unk_79 = 0;
    gGameStatusPtr->enableBackground = 0;
    gGameStatusPtr->musicEnabled = 1;
    gGameStatusPtr->unk_7C = 1;
    gGameStatusPtr->creditsViewportMode = -1;
    gGameStatusPtr->demoFlags = 0;
    gGameStatusPtr->unk_81 = 0;
    gGameStatusPtr->unk_82 = -8;
    gGameStatusPtr->unk_83 = 4;
    timeFreezeMode = 0;
    gGameStatusPtr->debugQuizmo = gGameStatusPtr->unk_13C = 0;
    D_80074021 = 5;
    gGameStatusPtr->saveCount = 0;
    fio_init_flash();
    func_80028838();
    general_heap_create();
    clear_render_tasks();
    clear_generic_entity_list();
    clear_script_list();
    create_cameras_a();
    clear_player_status();
    spr_init_sprites(0);
    clear_entity_models();
    clear_animator_list();
    clear_model_data();
    clear_sprite_shading_data();
    reset_background_settings();
    clear_character_set();
    clear_printers();
    clear_game_modes();
    clear_npcs();
    clear_hud_element_cache();
    clear_trigger_data();
    clear_entity_data(0);
    clear_player_data();
    init_encounter_status();
    clear_screen_overlays();
    clear_effect_data();
    clear_saved_variables();
    clear_item_entity_data();
    bgm_reset_sequence_players();
    reset_ambient_sounds();
    sfx_clear_sounds();
    clear_windows();
    initialize_curtains();
    poll_rumble();

    for (i = 0; i < 4; i++) {
        gGameStatusPtr->unk_50[i] = 3;
        gGameStatusPtr->unk_48[i] = 12;
    }

    gOverrideFlags |= 0x8;
    set_game_mode(0);
}

/// Time freeze modes:
///  0: normal
///  1: NPCs move, can't be interacted with
///  2: NPCs don't move, no partner ability, can't interact, can't use exits
///  3: NPCs don't more or animate (partner switch menu)
///  4: NPCs can move, animations don't update, can use exits
void set_time_freeze_mode(s32 mode) {
    switch (mode) {
        case 0:
            timeFreezeMode = mode;
            gOverrideFlags &= ~0xF00;
            resume_all_group(3);
            break;
        case 1:
            timeFreezeMode = mode;
            gOverrideFlags &= ~0xE00;
            gOverrideFlags |= 0x100;
            suspend_all_group(1);
            break;
        case 2:
            timeFreezeMode = mode;
            gOverrideFlags &= ~0xC00;
            gOverrideFlags |= 0x300;
            suspend_all_group(2);
            break;
        case 3:
            timeFreezeMode = mode;
            gOverrideFlags &= ~0x800;
            gOverrideFlags |= 0x700;
            suspend_all_group(2);
            break;
        case 4:
            timeFreezeMode = mode;
            gOverrideFlags |= 0xF00;
            break;
    }
}

s32 get_time_freeze_mode(void) {
    return timeFreezeMode;
}

void gfx_init_state(void) {
    gSPSegment(gMasterGfxPos++, 0x00, 0x0);
    gSPDisplayList(gMasterGfxPos++, OS_K0_TO_PHYSICAL(D_80074230));
    gSPDisplayList(gMasterGfxPos++, OS_K0_TO_PHYSICAL(D_80074210));
}

void func_800271FC(s16*, u32*, s32, s32, void*);

INCLUDE_ASM(void, "main_loop", func_800271FC, s16*, u32*, s32, s32, void*);

INCLUDE_ASM(s32, "main_loop", func_8002725C);

INCLUDE_ASM(s32, "main_loop", func_80027600);

INCLUDE_ASM(s32, "main_loop", func_80027774);

// alex: mystery t0=0x140 temp and a few missing loads, but mostly there
#ifdef NON_MATCHING
// arg0 and arg1 probably framebuffer voidptrs
void func_800279B4(u16* arg0, u16* arg1, u16* arg2) {
    s32 temp_s4;
    s32 j;
    s32 i;
    s32 subroutine_argE;
    s32 subroutine_arg7;
    s32 subroutine_arg8;
    s32 subroutine_arg9;
    s32 subroutine_argA;
    s32 subroutine_argB;
    s32 subroutine_argC;
    s32 subroutine_argF;

    for (i = 1; i < 0xEF; i++) {
        for (j = 2; j < 0x13E; j++) {
            temp_s4 = (subroutine_argF + j) * 2;
            // Wii U VC changes this condition to FALSE to fix pause menu lag
            if (((*(temp_s4 + arg1) >> 2) & 0xF) < 8) {
                func_800271FC(arg0, arg1, i - 1, j - 1, &subroutine_argE);
                func_800271FC(arg0, arg1, i - 1, j + 1, &subroutine_arg7);
                func_800271FC(arg0, arg1, i, j - 2, &subroutine_arg8);
                func_800271FC(arg0, arg1, i, j + 2, &subroutine_arg9);
                func_800271FC(arg0, arg1, i + 1, j - 1, &subroutine_argA);
                func_800271FC(arg0, arg1, i + 1, j + 1, &subroutine_argB);
                func_800271FC(arg0, arg1, i, j, &subroutine_argC);
                func_8002725C(&subroutine_argE, (subroutine_argC << 24) | (subroutine_argC << 16) | (subroutine_argC << 8) | subroutine_argC, arg2 + temp_s4);
            } else {
                *(temp_s4 + arg2) = *(temp_s4 + arg0) | 1;
            }
        }
    }
}
#else
INCLUDE_ASM(s32, "main_loop", func_800279B4);
#endif

void func_80027BAC(s32 arg0, s32 arg1) {
    s32 i;
    s32 temp = 24; // todo figure out why this is needed and can't be used elsewhere

    gDPPipeSync(gMasterGfxPos++);
    gSPTexture(gMasterGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
    gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, arg1);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_COPY);
    gDPSetTexturePersp(gMasterGfxPos++, G_TP_NONE);
    gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetTextureFilter(gMasterGfxPos++, G_TF_POINT);

    for (i = 0; i < 40; i++) {
        gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, arg0 + (0xF00 * i));
        gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 80, 0x0000, G_TX_LOADTILE, 0,
                   G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                   G_TX_NOLOD);
        gDPLoadSync(gMasterGfxPos++);
        gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, 0, 0x04FC, 0x0014);
        gDPPipeSync(gMasterGfxPos++);
        gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 80, 0x0000, G_TX_RENDERTILE, 0,
                   G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                   G_TX_NOLOD);
        gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, 0, 0x04FC, 0x0014);
        gSPTextureRectangle(gMasterGfxPos++, 0, i * temp, 0x04FC, (i * 24) + 20, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
        gDPPipeSync(gMasterGfxPos++);
    }
}

void gfx_draw_background(void) {
    Camera* camera;
    s32 bgFlags;
    s32 backgroundMinW;
    s32 backgroundSumW;
    s32 backgroundMinH;
    s32 backgroundSumH;
    s32 viewportStartX;
    s32 i;
    s32 a = 0x18;

    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 0, 0, 320, 240);

    camera = &gCameras[gCurrentCameraID];
    bgFlags = gGameStatusPtr->enableBackground & 0xF0;

    switch (bgFlags) {
        case 0x10:
            gDPPipeSync(gMasterGfxPos++);
            gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, D_8009A658[1]);
            gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
            gDPSetBlendColor(gMasterGfxPos++, 0x80, 0x80, 0x80, 0xFF);
            gDPSetPrimDepth(gMasterGfxPos++, -1, -1);
            gDPSetDepthSource(gMasterGfxPos++, G_ZS_PRIM);
            gDPSetRenderMode(gMasterGfxPos++, G_RM_VISCVG, G_RM_VISCVG2);
            gDPFillRectangle(gMasterGfxPos++, 0, 0, 320, 240);
            gDPPipeSync(gMasterGfxPos++);
            gDPSetDepthSource(gMasterGfxPos++, G_ZS_PIXEL);
            gGameStatusPtr->enableBackground &= ~0xF0;
            gGameStatusPtr->enableBackground |= 0x20;
            break;
        case 0x20:
            func_800279B4(D_8009A658[0], D_8009A658[1], nuGfxZBuffer);
            D_800741F8 = 0;
            gGameStatusPtr->enableBackground &= ~0xF0;
            gGameStatusPtr->enableBackground |= 0x30;
        case 0x30:
            D_800741F8 += 0x10;
            if (D_800741F8 > 0x80) {
                D_800741F8 = 0x80;
            }

            gDPPipeSync(gMasterGfxPos++);
            gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 0, 0, 320, 240);
            gDPSetCycleType(gMasterGfxPos++, G_CYC_FILL);
            gDPSetRenderMode(gMasterGfxPos++, G_RM_NOOP, G_RM_NOOP2);
            gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, D_8009A64C);
            gDPSetFillColor(gMasterGfxPos++, 0x00010001);
            gDPFillRectangle(gMasterGfxPos++, 0, 0, 319, 239);
            gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
            gDPSetTexturePersp(gMasterGfxPos++, G_TP_NONE);
            gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
            gDPSetRenderMode(gMasterGfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
            gDPSetCombineLERP(gMasterGfxPos++, PRIMITIVE, TEXEL0, PRIMITIVE_ALPHA, TEXEL0, 0, 0, 0, 1, PRIMITIVE,
                              TEXEL1, PRIMITIVE_ALPHA, TEXEL1, 0, 0, 0, 1);
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 0x28, 0x28, 0x28, D_800741F8);
            gDPSetTextureFilter(gMasterGfxPos++, G_TF_POINT);

            for (i = 0; i < 40; i++) {
                gDPSetTextureImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, nuGfxZBuffer + (i * 0x780));
                gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 80, 0x0000, G_TX_LOADTILE, 0,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                           G_TX_NOLOD);
                gDPLoadSync(gMasterGfxPos++);
                gDPLoadTile(gMasterGfxPos++, G_TX_LOADTILE, 0, 0, 0x04FC, 0x0014);
                gDPPipeSync(gMasterGfxPos++);
                gDPSetTile(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 80, 0x0000, G_TX_RENDERTILE, 0,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK,
                           G_TX_NOLOD);
                gDPSetTileSize(gMasterGfxPos++, G_TX_RENDERTILE, 0, 0, 0x04FC, 0x0014);
                gSPTextureRectangle(gMasterGfxPos++, 0, i * a, 0x0500, a + (i * 0x18), G_TX_RENDERTILE,
                                    -0x0020, 0, 0x0400, 0x0400);
                gDPPipeSync(gMasterGfxPos++);
            }
            break;
        default:
            if (gOverrideFlags & 8) {
                gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_8009A64C));
                return;
            }

            gDPSetDepthImage(gMasterGfxPos++, OS_PHYSICAL_TO_K0(nuGfxZBuffer)); // TODO: or OS_K0_TO_PHYSICAL
            gDPSetCycleType(gMasterGfxPos++, G_CYC_FILL);
            gDPSetRenderMode(gMasterGfxPos++, G_RM_NOOP, G_RM_NOOP2);
            gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, OS_PHYSICAL_TO_K0(nuGfxZBuffer));
            gDPSetFillColor(gMasterGfxPos++, 0xFFFCFFFC);
            gDPFillRectangle(gMasterGfxPos++, 0, 0, 319, 239);
            gDPPipeSync(gMasterGfxPos++);
            gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, 320, osVirtualToPhysical(D_8009A64C));
            gDPSetFillColor(gMasterGfxPos++, PACK_FILL_COLOR(camera->bgColor[0], camera->bgColor[1], camera->bgColor[2], 1));

            backgroundMinW = gGameStatusPtr->backgroundMinW;
            backgroundSumW = backgroundMinW + gGameStatusPtr->backgroundMaxW;
            backgroundMinH = gGameStatusPtr->backgroundMinH;
            backgroundSumH = backgroundMinH + gGameStatusPtr->backgroundMaxH;
            viewportStartX = camera->viewportStartX;

            if (backgroundMinW < viewportStartX) {
                backgroundMinW = viewportStartX;
            }

            if (backgroundMinH < camera->viewportStartY) {
                backgroundMinH = camera->viewportStartY;
            }

            if (backgroundSumW > viewportStartX + camera->viewportW) {
                backgroundSumW = viewportStartX + camera->viewportW;
            }

            if (backgroundSumH > camera->viewportStartY + camera->viewportH) {
                backgroundSumH = camera->viewportStartY + camera->viewportH;
            }

            if (backgroundMinW < 0) {
                backgroundMinW = 0;
            }

            if (backgroundMinH < 0) {
                backgroundMinH = 0;
            }

            if (backgroundSumW < 1) {
                backgroundSumW = 1;
            }

            if (backgroundSumH < 1) {
                backgroundSumH = 1;
            }

            if (backgroundMinW > 319) {
                backgroundMinW = 319;
            }

            if (backgroundMinH > 239) {
                backgroundMinH = 239;
            }

            if (backgroundSumW > 320) {
                backgroundSumW = 320;
            }

            if (backgroundSumH > 240) {
                backgroundSumH = 240;
            }

            if (!(gGameStatusPtr->enableBackground & 1)) {
                gDPFillRectangle(gMasterGfxPos++, backgroundMinW, backgroundMinH, backgroundSumW - 1, backgroundSumH - 1);
            } else {
                appendGfx_background_texture();
            }

            gDPPipeSync(gMasterGfxPos++);
            gDPSetCycleType(gMasterGfxPos++, G_CYC_FILL);
            gDPSetRenderMode(gMasterGfxPos++, G_RM_NOOP, G_RM_NOOP2);
            gDPSetFillColor(gMasterGfxPos++, 0x00010001);
            gDPPipeSync(gMasterGfxPos++);

            if (backgroundMinH > 0) {
                gDPFillRectangle(gMasterGfxPos++, 0, 0, 319, backgroundMinH - 1);
                gDPNoOp(gMasterGfxPos++);
            }

            if (backgroundMinW > 0) {
                gDPFillRectangle(gMasterGfxPos++, 0, backgroundMinH, backgroundMinW - 1, backgroundSumH - 1);
                gDPNoOp(gMasterGfxPos++);
            }

            if (backgroundSumW < 0x140) {
                gDPFillRectangle(gMasterGfxPos++, backgroundSumW, backgroundMinH, 319, backgroundSumH - 1);
                gDPNoOp(gMasterGfxPos++);
            }

            if (backgroundSumH < 0xF0) {
                gDPFillRectangle(gMasterGfxPos++, 0, backgroundSumH, 319, 239);
                gDPNoOp(gMasterGfxPos++);
            }
            break;
    }
    gDPPipeSync(gMasterGfxPos++);
}
