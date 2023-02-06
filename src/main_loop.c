#include "common.h"
#include "nu/nusys.h"
#include "ld_addrs.h"
#include "hud_element.h"
#include "sprite.h"
#include "overlay.h"

s8 gGameStepDelayAmount = 1;
s8 gGameStepDelayCount = 5;

GameStatus gGameStatus = {
    .currentButtons = {0},
    .pressedButtons = {0},
    .heldButtons = {0},
    .prevButtons = {0},
    .stickX = {0},
    .stickY = {0},
    .unk_48 = {0},
    .unk_50 = {0},
};

GameStatus* gGameStatusPtr = &gGameStatus;
s16 D_800741A0 = 0;
s16 D_800741A2 = 0;
s32 D_800741A4 = 0;

Matrix4s MasterIdentityMtx = {
    .whole = {
        {1, 0, 0, 0},
        {0, 1, 0, 0},
        {0, 0, 1, 0},
        {0, 0, 0, 1}
    },
    .frac = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    }
};

s32 D_800741E8[2] = {0, 0}; // padding?
u16 gMatrixListPos = 0;
u16 D_800741F2 = 0;
s32 gCurrentDisplayContextIndex = 0;
s32 gPauseBackgroundFade = 0;
s32 D_800741FC = 0;
Vp D_80074200 = {
    .vp = {
        .vscale = {640, 480, 511, 0},
        .vtrans = {640, 480, 511, 0},
    }
};

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

s32 timeFreezeMode;

extern s16 D_8009A690;

void gfx_init_state(void);
void gfx_draw_background(void);

void step_game_loop(void) {
    PlayerData* playerData = &gPlayerData;
    const int MAX_GAME_TIME = 1000*60*60*60 - 1; // 1000 hours minus one frame at 60 fps

    update_input();

    gGameStatusPtr->frameCounter++;

    playerData->frameCounter += 2;
    if (playerData->frameCounter > MAX_GAME_TIME) {
        playerData->frameCounter = MAX_GAME_TIME;
    }

    update_max_rumble_duration();

    if (gGameStepDelayCount != 0) {
        gGameStepDelayCount-- ;
        if (gGameStepDelayCount == 0) {
            gGameStepDelayCount = gGameStepDelayAmount;
        } else {
            return;
        }
    }

    func_8011BAE8();
    npc_iter_no_op();
    update_workers();
    update_triggers();
    update_scripts();
    update_messages();
    update_hud_elements();
    step_current_game_mode();
    update_entities();
    func_80138198();
    bgm_update_music_settings();
    update_ambient_sounds();
    sfx_update_env_sound_params();
    update_windows();
    update_curtains();

    if (gOverrideFlags & GLOBAL_OVERRIDES_ENABLE_TRANSITION_STENCIL) {
        switch (D_800741A2) {
            case 0:
                gOverrideFlags |= GLOBAL_OVERRIDES_200;
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
                gOverrideFlags |= GLOBAL_OVERRIDES_8;
                D_8009A690--;
                if (D_8009A690 == 0) {
                    sfx_stop_env_sounds();
                    set_game_mode(GAME_MODE_STARTUP);
                    gOverrideFlags &= ~GLOBAL_OVERRIDES_ENABLE_TRANSITION_STENCIL;
                }
                break;
        }
    } else {
        D_800741A0 = 0;
        D_800741A2 = 0;
    }

    if (gOverrideFlags & GLOBAL_OVERRIDES_DISABLE_BATTLES) {
        gOverrideFlags |= GLOBAL_OVERRIDES_1000;
    } else {
        gOverrideFlags &= ~GLOBAL_OVERRIDES_1000;
    }

    if (gOverrideFlags & GLOBAL_OVERRIDES_200) {
        gOverrideFlags |= GLOBAL_OVERRIDES_2000;
    } else {
        gOverrideFlags &= ~GLOBAL_OVERRIDES_2000;
    }

    if (gOverrideFlags & GLOBAL_OVERRIDES_400) {
        gOverrideFlags |= GLOBAL_OVERRIDES_4000;
    } else {
        gOverrideFlags &= ~GLOBAL_OVERRIDES_4000;
    }

    if (gOverrideFlags & GLOBAL_OVERRIDES_800) {
        gOverrideFlags |= GLOBAL_OVERRIDES_8000;
    } else {
        gOverrideFlags &= ~GLOBAL_OVERRIDES_8000;
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

    if (gOverrideFlags & GLOBAL_OVERRIDES_8) {
        gCurrentDisplayContextIndex = gCurrentDisplayContextIndex ^ 1;
        return;
    }

    gSPMatrix(gMasterGfxPos++, &MasterIdentityMtx, G_MTX_NOPUSH | G_MTX_LOAD | G_MTX_MODELVIEW);

    spr_render_init();

    if (!(gOverrideFlags & GLOBAL_OVERRIDES_DISABLE_RENDER_WORLD)) {
        render_frame(0);
    }

    player_render_interact_prompts();
    func_802C3EE4();
    render_screen_overlay_backUI();
    render_workers_backUI();
    render_hud_elements_backUI();
    render_effects_UI();
    state_render_backUI();

    if (!(gOverrideFlags & GLOBAL_OVERRIDES_WINDOWS_IN_FRONT_OF_CURTAINS)) {
        render_window_root();
    }

    if (!(gOverrideFlags & GLOBAL_OVERRIDES_DISABLE_RENDER_WORLD) && !gGameStatusPtr->disableScripts) {
        render_frame(1);
    }

    if (!(gOverrideFlags & (GLOBAL_OVERRIDES_MESSAGES_IN_FRONT_OF_CURTAINS | GLOBAL_OVERRIDES_10))) {
        render_messages();
    }

    render_workers_frontUI();
    render_hud_elements_frontUI();
    render_screen_overlay_frontUI();

    if ((gOverrideFlags & (GLOBAL_OVERRIDES_MESSAGES_IN_FRONT_OF_CURTAINS | GLOBAL_OVERRIDES_10)) == GLOBAL_OVERRIDES_10) {
        render_messages();
    }

    render_curtains();

    if (gOverrideFlags & GLOBAL_OVERRIDES_MESSAGES_IN_FRONT_OF_CURTAINS) {
        render_messages();
    }
    if (gOverrideFlags & GLOBAL_OVERRIDES_WINDOWS_IN_FRONT_OF_CURTAINS) {
        render_window_root();
    }

    state_render_frontUI();

    if (gOverrideFlags & GLOBAL_OVERRIDES_ENABLE_TRANSITION_STENCIL) {
        switch (D_800741A2) {
            case 0:
            case 1:
                _render_transition_stencil(7, D_800741A0, NULL);
                break;
        }
    }

    ASSERT((s32)(((u32)(gMasterGfxPos - gDisplayContext->mainGfx) << 3) >> 3) < ARRAY_COUNT(gDisplayContext->mainGfx));

    gDPFullSync(gMasterGfxPos++);
    gSPEndDisplayList(gMasterGfxPos++);

    nuGfxTaskStart(gDisplayContext->mainGfx, (u32)(gMasterGfxPos - gDisplayContext->mainGfx) * 8, NU_GFX_UCODE_F3DEX2,
                   NU_SC_TASK_LODABLE | NU_SC_SWAPBUFFER);
    gCurrentDisplayContextIndex = gCurrentDisplayContextIndex ^ 1;
    crash_screen_set_draw_info(nuGfxCfb_ptr, SCREEN_WIDTH, SCREEN_HEIGHT);
}

void load_engine_data(void) {
    s32 i;

    dma_copy(engine4_ROM_START, engine4_ROM_END, engine4_VRAM);
    dma_copy(engine1_ROM_START, engine1_ROM_END, engine1_VRAM);
    dma_copy(evt_ROM_START, evt_ROM_END, evt_VRAM);
    dma_copy(entity_ROM_START, entity_ROM_END, entity_VRAM);
    dma_copy(engine2_ROM_START, engine2_ROM_END, engine2_VRAM);
    dma_copy(font_width_ROM_START, font_width_ROM_END, font_width_VRAM);

    gOverrideFlags = 0;
    gGameStatusPtr->unk_79 = 0;
    gGameStatusPtr->backgroundFlags = 0;
    gGameStatusPtr->musicEnabled = 1;
    gGameStatusPtr->unk_7C = 1;
    gGameStatusPtr->creditsViewportMode = -1;
    gGameStatusPtr->demoFlags = 0;
    gGameStatusPtr->multiplayerEnabled = 0;
    gGameStatusPtr->unk_82 = -8;
    gGameStatusPtr->unk_83 = 4;
    timeFreezeMode = 0;
    gGameStatusPtr->debugQuizmo = gGameStatusPtr->unk_13C = 0;
    gGameStepDelayCount = 5;
    gGameStatusPtr->saveCount = 0;
    fio_init_flash();
    func_80028838();
    general_heap_create();
    clear_render_tasks();
    clear_worker_list();
    clear_script_list();
    create_cameras_a();
    clear_player_status();
    spr_init_sprites(PLAYER_SPRITES_MARIO_WORLD);
    clear_entity_models();
    clear_animator_list();
    clear_model_data();
    clear_sprite_shading_data();
    reset_background_settings();
    clear_character_set();
    clear_printers();
    clear_game_modes();
    clear_npcs();
    hud_element_clear_cache();
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

    for (i = 0; i < ARRAY_COUNT(gGameStatusPtr->unk_50); i++) {
        gGameStatusPtr->unk_50[i] = 3;
        gGameStatusPtr->unk_48[i] = 12;
    }

    gOverrideFlags |= GLOBAL_OVERRIDES_8;
    set_game_mode(GAME_MODE_STARTUP);
}

/// Time freeze modes:
///  0: normal
///  1: NPCs move, can't be interacted with
///  2: NPCs don't move, no partner ability, can't interact, can't use exits
///  3: NPCs don't more or animate
///  4: NPCs can move, animations don't update, can use exits
void set_time_freeze_mode(s32 mode) {
    switch (mode) {
        case TIME_FREEZE_NORMAL:
            timeFreezeMode = mode;
            gOverrideFlags &= ~(GLOBAL_OVERRIDES_800 | GLOBAL_OVERRIDES_400 | GLOBAL_OVERRIDES_200 | GLOBAL_OVERRIDES_DISABLE_BATTLES);
            resume_all_group(EVT_GROUP_01 | EVT_GROUP_02);
            break;
        case TIME_FREEZE_PARTIAL:
            timeFreezeMode = mode;
            gOverrideFlags &= ~(GLOBAL_OVERRIDES_800 | GLOBAL_OVERRIDES_400 | GLOBAL_OVERRIDES_200);
            gOverrideFlags |= GLOBAL_OVERRIDES_DISABLE_BATTLES;
            suspend_all_group(EVT_GROUP_01);
            break;
        case TIME_FREEZE_FULL:
            timeFreezeMode = mode;
            gOverrideFlags &= ~(GLOBAL_OVERRIDES_400 | GLOBAL_OVERRIDES_800);
            gOverrideFlags |= GLOBAL_OVERRIDES_200 | GLOBAL_OVERRIDES_DISABLE_BATTLES;
            suspend_all_group(EVT_GROUP_02);
            break;
        case TIME_FREEZE_POPUP_MENU:
            timeFreezeMode = mode;
            gOverrideFlags &= ~GLOBAL_OVERRIDES_800;
            gOverrideFlags |= GLOBAL_OVERRIDES_400 | GLOBAL_OVERRIDES_200 | GLOBAL_OVERRIDES_DISABLE_BATTLES;
            suspend_all_group(EVT_GROUP_02);
            break;
        case TIME_FREEZE_EXIT:
            timeFreezeMode = mode;
            gOverrideFlags |= GLOBAL_OVERRIDES_800 | GLOBAL_OVERRIDES_400 | GLOBAL_OVERRIDES_200 | GLOBAL_OVERRIDES_DISABLE_BATTLES;
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

s32 gfx_frame_filter_pass_0(const u16* frameBuffer0, const u16* frameBuffer1, s32 y, s32 x, Color_RGBA8* out) {
    s32 pixel = SCREEN_WIDTH * y + x;

    out->a = (frameBuffer1[pixel] >> 2) & 0xF;
    out->r = (frameBuffer0[pixel] >> 11);
    out->g = (frameBuffer0[pixel] >> 6) & 0x1F;
    out->b = (frameBuffer0[pixel] >> 1) & 0x1F;
}

void gfx_frame_filter_pass_1(Color_RGBA8* filterBuf0, Color_RGBA8 filterBuf1, u16* out) {
    Color_RGBA8 sp0;
    Color_RGBA8 sp8;
    Color_RGBA8 final;
    u8 rs[0x20];
    u8 gs[0x20];
    u8 bs[0x20];
    s32 i;

    sp8 = filterBuf1;
    sp0 = filterBuf1;

    for (i = 0; i < ARRAY_COUNT(rs); i++) {
        rs[i] = 0;
        gs[i] = 0;
        bs[i] = 0;
    }

    for (i = 0; i < 6; i++) {
        if (filterBuf0[i].a == 8) {
            rs[filterBuf0[i].r]++;
            gs[filterBuf0[i].g]++;
            bs[filterBuf0[i].b]++;
        }
    }

    for (i = 0; i < ARRAY_COUNT(rs); i++) {
        if (rs[i] != 0) {
            rs[i]--;
            break;
        }
    }
    for (; i < ARRAY_COUNT(rs); i++) {
        if (rs[i] != 0) {
            break;
        }
    }
    if (sp0.r > i) {
        sp0.r = i;
    }

    for (i = 0; i < ARRAY_COUNT(gs); i++) {
        if (gs[i] != 0) {
            gs[i]--;
            break;
        }
    }
    for (; i < ARRAY_COUNT(gs); i++) {
        if (gs[i] != 0) {
            break;
        }
    }
    if (sp0.g > i) {
        sp0.g = i;
    }

    for (i = 0; i < ARRAY_COUNT(bs); i++) {
        if (bs[i] != 0) {
            bs[i]--;
            break;
        }
    }
    for (; i < ARRAY_COUNT(bs); i++) {
        if (bs[i] != 0) {
            break;
        }
    }
    if (sp0.b > i) {
        sp0.b = i;
    }

    for (i = ARRAY_COUNT(rs) - 1; i >= 0; i--) {
        if (rs[i] != 0) {
            break;
        }
    }
    if (sp8.r < i) {
        sp8.r = i;
    }

    for (i = ARRAY_COUNT(gs) - 1; i >= 0; i--) {
        if (gs[i] != 0) {
            break;
        }
    }
    if (sp8.g < i) {
        sp8.g = i;
    }

    for (i = ARRAY_COUNT(bs) - 1; i >= 0; i--) {
        if (bs[i] != 0) {
            break;
        }
    }
    if (sp8.b < i) {
        sp8.b = i;
    }

    final.r = (sp8.r + sp0.r) - filterBuf1.r;
    final.g = (sp8.g + sp0.g) - filterBuf1.g;
    final.b = (sp8.b + sp0.b) - filterBuf1.b;

    final.r = ((filterBuf1.r * filterBuf1.a) + (final.r * (8 - filterBuf1.a))) >> 3;
    final.g = ((filterBuf1.g * filterBuf1.a) + (final.g * (8 - filterBuf1.a))) >> 3;
    final.b = ((filterBuf1.b * filterBuf1.a) + (final.b * (8 - filterBuf1.a))) >> 3;

    *out = (final.r << 11) + (final.g << 6) + (final.b << 1) + 1;
}

void func_80027600(Color_RGBA8* arg0, s16* out) {
    Color_RGBA8 final;
    u8 rs[0x20];
    u8 gs[0x20];
    u8 bs[0x20];
    s32 i;
    s32 sum;

    for (i = 0; i < ARRAY_COUNT(rs); i++) {
        rs[i] = 0;
        gs[i] = 0;
        bs[i] = 0;
    }

    for (i = 0; i < 9; i++) {
        rs[arg0[i].r]++;
        gs[arg0[i].g]++;
        bs[arg0[i].b]++;
    }

    sum = 0;
    for (i = 0; i < ARRAY_COUNT(rs); i++) {
        sum += rs[i];
        if (sum >= 5) {
            break;
        }
    }
    final.r = i;

    sum = 0;
    for (i = 0; i < ARRAY_COUNT(gs); i++) {
        sum += gs[i];
        if (sum >= 5) {
            break;
        }
    }
    final.g = i;

    sum = 0;
    for (i = 0; i < ARRAY_COUNT(bs); i++) {
        sum += bs[i];
        if (sum >= 5) {
            break;
        }
    }
    final.b = i;

    *out = (final.r << 11) + (final.g << 6) + (final.b << 1) + 1;
}

void func_80027774(u16* frameBuffer0, u16* frameBuffer1, u16* zBuffer) {
    Color_RGBA8 filterBuf0[9];
    s32 x, y;

    for (y = 1; y < SCREEN_HEIGHT - 1; y++) {
        for (x = 1; x < SCREEN_WIDTH - 1; x++) {

            /*
            The application of gfx_frame_filter_pass_0 is done to the following pixels, where x is the current pixel.
               ...
               .x.
               ...
            */
            if (
                (((frameBuffer1[(SCREEN_WIDTH * y) + x - 1] >> 2) & 0xF) < 8) ||
                (((frameBuffer1[(SCREEN_WIDTH * y) + x + 0] >> 2) & 0xF) < 8) ||
                (((frameBuffer1[(SCREEN_WIDTH * y) + x + 1] >> 2) & 0xF) < 8))
            {
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y - 1, x - 1, &filterBuf0[0]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y - 1, x,     &filterBuf0[1]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y - 1, x + 1, &filterBuf0[2]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y    , x - 1, &filterBuf0[3]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y    , x,     &filterBuf0[4]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y    , x + 1, &filterBuf0[5]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y + 1, x - 1, &filterBuf0[6]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y + 1, x,     &filterBuf0[7]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y + 1, x + 1, &filterBuf0[8]);
                func_80027600(filterBuf0, &zBuffer[(SCREEN_WIDTH * y) + x]);
            } else {
                zBuffer[(SCREEN_WIDTH * y) + x] = frameBuffer0[(SCREEN_WIDTH * y) + x] | 1;
            }
        }
    }
}

// transfers the framebuffer into the depth buffer and applies filters
void gfx_transfer_frame_to_depth(u16* frameBuffer0, u16* frameBuffer1, u16* zBuffer) {
    Color_RGBA8 filterBuf0[6];
    Color_RGBA8 filterBuf1;
    s32 y;
    s32 x;

    for (y = 1; y < SCREEN_HEIGHT - 1; y++) {
        for (x = 2; x < SCREEN_WIDTH - 2; x++) {
            s32 pixel = SCREEN_WIDTH * y + x;

            /*
            The application of gfx_frame_filter_pass_0 is done to the following pixels, where x is the current pixel.
               . .
              . x .
               . .
            */
            if (((frameBuffer1[pixel] >> 2) & 0xF) < 8) {
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y - 1, x - 1, &filterBuf0[0]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y - 1, x + 1, &filterBuf0[1]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y,     x - 2, &filterBuf0[2]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y,     x + 2, &filterBuf0[3]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y + 1, x - 1, &filterBuf0[4]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y + 1, x + 1, &filterBuf0[5]);
                gfx_frame_filter_pass_0(frameBuffer0, frameBuffer1, y,     x,     &filterBuf1);
                gfx_frame_filter_pass_1(filterBuf0, filterBuf1, &zBuffer[pixel]);
            } else {
                // Don't apply any filters to the edges of the screen
                zBuffer[pixel] = frameBuffer0[pixel] | 1;
            }
        }
    }
}

void func_80027BAC(s32 arg0, s32 arg1) {
    s32 i;
    s32 temp = 24; // todo figure out why this is needed and can't be used elsewhere

    gDPPipeSync(gMasterGfxPos++);
    gSPTexture(gMasterGfxPos++, -1, -1, 0, G_TX_RENDERTILE, G_ON);
    gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, arg1);
    gDPSetCycleType(gMasterGfxPos++, G_CYC_COPY);
    gDPSetTexturePersp(gMasterGfxPos++, G_TP_NONE);
    gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
    gDPSetRenderMode(gMasterGfxPos++, G_RM_NOOP, G_RM_NOOP2);
    gDPSetTextureFilter(gMasterGfxPos++, G_TF_POINT);

    for (i = 0; i < 40; i++) {
        gDPLoadTextureTile(gMasterGfxPos++, arg0 + (0xF00 * i), G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                           SCREEN_HEIGHT, 0, 0, SCREEN_WIDTH - 1, 5, 0, G_TX_NOMIRROR | G_TX_WRAP,
                           G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
        gSPTextureRectangle(gMasterGfxPos++, 0, i * temp, 0x04FC, (i * 24) + 20, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
        gDPPipeSync(gMasterGfxPos++);
    }
}

// Logic for the drawing the scene background. In normal operation, it draws the regular background.
// While opening pause menu, it does the following:
//  * Extracts coverage from the current framebuffer and saves it to nuGfxCfb[1] on the first frame.
//  * Copies the current framebuffer to the depth buffer to save it and applies a filter on the
//    saved framebuffer based on the saved coverage values one frame later.
//  * Draws the saved framebuffer to the current framebuffer while the pause screen is opened, fading it in over time.
void gfx_draw_background(void) {
    Camera* camera;
    s32 bgFlags;
    s32 backgroundMinX;
    s32 backgroundMaxX;
    s32 backgroundMinY;
    s32 backgroundMaxY;
    s32 viewportStartX;
    s32 i;
    s32 a = SCREEN_COPY_TILE_HEIGHT << 2;

    gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);

    camera = &gCameras[gCurrentCameraID];
    bgFlags = gGameStatusPtr->backgroundFlags & BACKGROUND_RENDER_STATE_MASK;

    switch (bgFlags) {
        case BACKGROUND_RENDER_STATE_1:
            // Save coverage to nunGfxCfb[1] using the VISCVG render mode
            gDPPipeSync(gMasterGfxPos++);
            gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, nuGfxCfb[1]);
            gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
            gDPSetBlendColor(gMasterGfxPos++, 0x80, 0x80, 0x80, 0xFF);
            gDPSetPrimDepth(gMasterGfxPos++, 0xFFFF, 0xFFFF);
            gDPSetDepthSource(gMasterGfxPos++, G_ZS_PRIM);
            gDPSetRenderMode(gMasterGfxPos++, G_RM_VISCVG, G_RM_VISCVG2);
            gDPFillRectangle(gMasterGfxPos++, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            gDPPipeSync(gMasterGfxPos++);
            gDPSetDepthSource(gMasterGfxPos++, G_ZS_PIXEL);
            gGameStatusPtr->backgroundFlags &= ~BACKGROUND_RENDER_STATE_MASK;
            gGameStatusPtr->backgroundFlags |= BACKGROUND_RENDER_STATE_2;
            break;
        case BACKGROUND_RENDER_STATE_2:
            // Save the framebuffer into the depth buffer and run a filter on it based on the saved coverage values
            gfx_transfer_frame_to_depth(nuGfxCfb[0], nuGfxCfb[1], nuGfxZBuffer); // applies filters to the framebuffer
            gPauseBackgroundFade = 0;
            gGameStatusPtr->backgroundFlags &= ~BACKGROUND_RENDER_STATE_MASK;
            gGameStatusPtr->backgroundFlags |= BACKGROUND_RENDER_STATE_3;
            // fallthrough
        case BACKGROUND_RENDER_STATE_3:
            // Draw the saved framebuffer to the background, fading in at a rate of 16 opacity per frame until reaching 128 opacity
            gPauseBackgroundFade += 16;
            if (gPauseBackgroundFade > 128) {
                gPauseBackgroundFade = 128;
            }

            gDPPipeSync(gMasterGfxPos++);
            gDPSetScissor(gMasterGfxPos++, G_SC_NON_INTERLACE, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
            gDPSetCycleType(gMasterGfxPos++, G_CYC_FILL);
            gDPSetRenderMode(gMasterGfxPos++, G_RM_NOOP, G_RM_NOOP2);
            gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, nuGfxCfb_ptr);
            gDPSetFillColor(gMasterGfxPos++, PACK_FILL_COLOR(0, 0, 0, 1));
            gDPFillRectangle(gMasterGfxPos++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
            gDPSetCycleType(gMasterGfxPos++, G_CYC_1CYCLE);
            gDPSetTexturePersp(gMasterGfxPos++, G_TP_NONE);
            gDPSetTextureLUT(gMasterGfxPos++, G_TT_NONE);
            gDPSetRenderMode(gMasterGfxPos++, G_RM_OPA_SURF, G_RM_OPA_SURF2);
            // @bug In 1-cycle mode, the two combiner cycles should be identical. Using Texel1 here in the second cycle,
            // which is the actual cycle of the combiner used on hardware in 1-cycle mode, actually samples the next
            // pixel's texel value instead of the current pixel's. This results in a one-pixel offset.
            gDPSetCombineLERP(gMasterGfxPos++, PRIMITIVE, TEXEL0, PRIMITIVE_ALPHA, TEXEL0, 0, 0, 0, 1, PRIMITIVE,
                              TEXEL1, PRIMITIVE_ALPHA, TEXEL1, 0, 0, 0, 1);
            gDPSetPrimColor(gMasterGfxPos++, 0, 0, 40, 40, 40, gPauseBackgroundFade);
            gDPSetTextureFilter(gMasterGfxPos++, G_TF_POINT);

            for (i = 0; i < 40; i++) {
                gDPLoadTextureTile(gMasterGfxPos++, nuGfxZBuffer + (i * SCREEN_WIDTH * SCREEN_COPY_TILE_HEIGHT), G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH,
                                   SCREEN_HEIGHT, 0, 0, SCREEN_WIDTH - 1, SCREEN_COPY_TILE_HEIGHT - 1, 0, G_TX_NOMIRROR | G_TX_WRAP,
                                   G_TX_NOMIRROR | G_TX_WRAP, G_TX_NOMASK, G_TX_NOMASK, G_TX_NOLOD, G_TX_NOLOD);
                // @bug Due to the previous issue with the incorrect second cycle combiner, the devs added a 1-pixel offset to texture coordinates
                // in this texrect to compensate for the combiner error.
                gSPTextureRectangle(gMasterGfxPos++,
                                    // ulx, uly, lrx, lry
                                    0 << 2, i * a, SCREEN_WIDTH << 2, a + (i * (SCREEN_COPY_TILE_HEIGHT << 2)),
                                    // tile
                                    G_TX_RENDERTILE,
                                    // s, t, dsdx, dtdy
                                    -1 << 5, 0 << 5, 1 << 10, 1 << 10);
                gDPPipeSync(gMasterGfxPos++);
            }
            break;
        default:
            // Draw the scene's background as normal
            if (gOverrideFlags & GLOBAL_OVERRIDES_8) {
                gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxCfb_ptr));
                return;
            }

            gDPSetDepthImage(gMasterGfxPos++, OS_K0_TO_PHYSICAL(nuGfxZBuffer));
            gDPSetCycleType(gMasterGfxPos++, G_CYC_FILL);
            gDPSetRenderMode(gMasterGfxPos++, G_RM_NOOP, G_RM_NOOP2);
            gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, OS_K0_TO_PHYSICAL(nuGfxZBuffer));
            gDPSetFillColor(gMasterGfxPos++, PACK_FILL_DEPTH(G_MAXFBZ, 0));
            gDPFillRectangle(gMasterGfxPos++, 0, 0, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
            gDPPipeSync(gMasterGfxPos++);
            gDPSetColorImage(gMasterGfxPos++, G_IM_FMT_RGBA, G_IM_SIZ_16b, SCREEN_WIDTH, osVirtualToPhysical(nuGfxCfb_ptr));
            gDPSetFillColor(gMasterGfxPos++, PACK_FILL_COLOR(camera->bgColor[0], camera->bgColor[1], camera->bgColor[2], 1));

            backgroundMinX = gGameStatusPtr->backgroundMinX;
            backgroundMaxX = backgroundMinX + gGameStatusPtr->backgroundMaxX;
            backgroundMinY = gGameStatusPtr->backgroundMinY;
            backgroundMaxY = backgroundMinY + gGameStatusPtr->backgroundMaxY;
            viewportStartX = camera->viewportStartX;

            if (backgroundMinX < viewportStartX) {
                backgroundMinX = viewportStartX;
            }

            if (backgroundMinY < camera->viewportStartY) {
                backgroundMinY = camera->viewportStartY;
            }

            if (backgroundMaxX > viewportStartX + camera->viewportW) {
                backgroundMaxX = viewportStartX + camera->viewportW;
            }

            if (backgroundMaxY > camera->viewportStartY + camera->viewportH) {
                backgroundMaxY = camera->viewportStartY + camera->viewportH;
            }

            if (backgroundMinX < 0) {
                backgroundMinX = 0;
            }

            if (backgroundMinY < 0) {
                backgroundMinY = 0;
            }

            if (backgroundMaxX < 1) {
                backgroundMaxX = 1;
            }

            if (backgroundMaxY < 1) {
                backgroundMaxY = 1;
            }

            if (backgroundMinX > SCREEN_WIDTH - 1) {
                backgroundMinX = SCREEN_WIDTH - 1;
            }

            if (backgroundMinY > SCREEN_HEIGHT - 1) {
                backgroundMinY = SCREEN_HEIGHT - 1;
            }

            if (backgroundMaxX > SCREEN_WIDTH) {
                backgroundMaxX = SCREEN_WIDTH;
            }

            if (backgroundMaxY > SCREEN_HEIGHT) {
                backgroundMaxY = SCREEN_HEIGHT;
            }

            if (!(gGameStatusPtr->backgroundFlags & BACKGROUND_FLAG_TEXTURE)) {
                gDPFillRectangle(gMasterGfxPos++, backgroundMinX, backgroundMinY, backgroundMaxX - 1, backgroundMaxY - 1);
            } else {
                appendGfx_background_texture();
            }

            gDPPipeSync(gMasterGfxPos++);
            gDPSetCycleType(gMasterGfxPos++, G_CYC_FILL);
            gDPSetRenderMode(gMasterGfxPos++, G_RM_NOOP, G_RM_NOOP2);
            gDPSetFillColor(gMasterGfxPos++, PACK_FILL_COLOR(0, 0, 0, 1));
            gDPPipeSync(gMasterGfxPos++);

            if (backgroundMinY > 0) {
                gDPFillRectangle(gMasterGfxPos++, 0, 0, SCREEN_WIDTH - 1, backgroundMinY - 1);
                gDPNoOp(gMasterGfxPos++);
            }

            if (backgroundMinX > 0) {
                gDPFillRectangle(gMasterGfxPos++, 0, backgroundMinY, backgroundMinX - 1, backgroundMaxY - 1);
                gDPNoOp(gMasterGfxPos++);
            }

            if (backgroundMaxX < SCREEN_WIDTH) {
                gDPFillRectangle(gMasterGfxPos++, backgroundMaxX, backgroundMinY, SCREEN_WIDTH - 1, backgroundMaxY - 1);
                gDPNoOp(gMasterGfxPos++);
            }

            if (backgroundMaxY < SCREEN_HEIGHT) {
                gDPFillRectangle(gMasterGfxPos++, 0, backgroundMaxY, SCREEN_WIDTH - 1, SCREEN_HEIGHT - 1);
                gDPNoOp(gMasterGfxPos++);
            }
            break;
    }
    gDPPipeSync(gMasterGfxPos++);
}
