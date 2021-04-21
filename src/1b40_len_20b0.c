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

extern DisplayContext D_80164000[];
extern s16 D_8009A690;

void gfx_init_state(void);
void gfx_draw_background(void);

void step_game_loop(void) {
    PlayerData* playerData = &gPlayerData;
    s8* temp80074021;
    s16* temp80074182;
    s16* temp800741A0;
    s16* temp8009A690;

    update_input();

    gGameStatusPtr->frameCounter++;

    playerData->frameCounter += 2;
    if (playerData->frameCounter > 215999999) {
        playerData->frameCounter = 215999999;
    }

    update_max_rumble_duration();

    temp80074021 = &D_80074021;
    if (*temp80074021 != 0) {
        (*temp80074021)-- ;
        if (*temp80074021 == 0) {
            *temp80074021 = D_80074020;
        } else {
            return;
        }
    }

    func_8011BAE8();
    npc_iter_no_op();
    update_dynamic_entities();
    update_triggers();
    update_scripts();
    update_messages();
    update_menu_icons();
    step_current_game_mode();
    update_entities();
    func_80138198();
    bgm_update_music_settings();
    update_ambient_sounds();
    sfx_update_looping_sound_params();
    update_windows();
    update_curtains();

    if (OVERRIDE_FLAG_CHECK(0x20)) {
        temp80074182 = &D_800741A2;

        switch (*temp80074182) {
            case 0:
                OVERRIDE_FLAG_SET(0x200);
                disable_player_input();
                temp800741A0 = &D_800741A0;
                if (*temp800741A0 == 255) {
                    *temp80074182 = 1;
                    D_8009A690 = 3;
                } else {
                    *temp800741A0 += 10;
                    if (*temp800741A0 > 255) {
                        *temp800741A0 = 255;
                    }
                }
                break;
            case 1:
                OVERRIDE_FLAG_SET(0x8);
                temp8009A690 = &D_8009A690;
                (*temp8009A690)--;
                if (*temp8009A690 == 0) {
                    sfx_stop_env_sounds();
                    set_game_mode(0);
                    OVERRIDE_FLAG_UNSET(0x20);
                }
                break;
        }
    } else {
        D_800741A0 = 0;
        D_800741A2 = 0;
    }

    if (OVERRIDE_FLAG_CHECK(0x100)) {
        OVERRIDE_FLAG_SET(0x1000);
    } else {
        OVERRIDE_FLAG_UNSET(0x1000);
    }

    if (OVERRIDE_FLAG_CHECK(0x200)) {
        OVERRIDE_FLAG_SET(0x2000);
    } else {
        OVERRIDE_FLAG_UNSET(0x2000);
    }

    if (OVERRIDE_FLAG_CHECK(0x400)) {
        OVERRIDE_FLAG_SET(0x4000);
    } else {
        OVERRIDE_FLAG_UNSET(0x4000);
    }

    if (OVERRIDE_FLAG_CHECK(0x800)) {
        OVERRIDE_FLAG_SET(0x8000);
    } else {
        OVERRIDE_FLAG_UNSET(0x8000);
    }

    rand_int(1);
}

void gfx_task_background(void) {
    DisplayContext** gDisplayContextPtr = &gDisplayContext;
    Gfx** gfx = &gMasterGfxPos;
    DisplayContext* dispContexts = D_80164000;

    *gDisplayContextPtr = &dispContexts[gCurrentDisplayContextIndex];
    *gfx = &(*gDisplayContextPtr)->backgroundGfx[0];

    gfx_init_state();
    gfx_draw_background();

    gDPFullSync((*gfx)++);
    gSPEndDisplayList((*gfx)++);

    // TODO these << 3 >> 3 shouldn't be necessary. There's almost definitely something we're missing here...
    ASSERT((s32)((u32)((*gfx) - (*gDisplayContextPtr)->backgroundGfx) << 3 >> 3) < ARRAY_COUNT((
                *gDisplayContextPtr)->backgroundGfx));

    nuGfxTaskStart(&gDisplayContext->backgroundGfx[0], (gMasterGfxPos - gDisplayContext->backgroundGfx) << 3,
                   NU_GFX_UCODE_F3DEX2, NU_SC_NOSWAPBUFFER);
}

INCLUDE_ASM(s32, "1b40_len_20b0", gfx_draw_frame);

void load_engine_data(void) {
    GameStatus** gameStatus = &gGameStatusPtr;
    s32 i;

    dma_copy(FEE30_ROM_START, FEE30_ROM_END, FEE30_VRAM);
    dma_copy(_759B0_ROM_START, _759B0_ROM_END, _759B0_VRAM);
    dma_copy(E79B0_ROM_START, E79B0_ROM_END, E79B0_VRAM);
    dma_copy(_102610_ROM_START, _102610_ROM_END, _102610_VRAM);
    dma_copy(A5DD0_ROM_START, A5DD0_ROM_END, A5DD0_VRAM);
    dma_copy(_10CC10_ROM_START, _10CC10_ROM_END, _10CC10_VRAM);

    gOverrideFlags = 0;
    (*gameStatus)->unk_79 = 0;
    (*gameStatus)->enableBackground = 0;
    (*gameStatus)->musicEnabled = 1;
    (*gameStatus)->unk_7C = 1;
    (*gameStatus)->unk_A8 = -1;
    (*gameStatus)->unk_AA = 0;
    (*gameStatus)->unk_81 = 0;
    (*gameStatus)->unk_82 = -8;
    (*gameStatus)->unk_83 = 4;
    D_8009A5D8 = 0;
    (*gameStatus)->unk_75 = (*gameStatus)->unk_13C = 0;
    D_80074021 = 5;
    (*gameStatus)->saveCount = 0;
    fio_init_flash();
    func_80028838();
    general_heap_create();
    func_8011D890();
    clear_dynamic_entity_list();
    clear_script_list();
    create_cameras_a();
    clear_player_status();
    func_802DD8F8(0);
    clear_entity_models();
    func_8011E224();
    clear_model_data();
    func_80148040();
    use_default_background_settings();
    clear_character_set();
    clear_printers();
    func_80112B98();
    npc_list_clear();
    func_80141100();
    clear_trigger_data();
    clear_entity_data(0);
    clear_player_data();
    func_8003E338();
    clear_transition_stencil();
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
        (*gameStatus)->unk_50[i] = 3;
        (*gameStatus)->unk_48[i] = 12;
    }

    OVERRIDE_FLAG_SET(0x8);
    set_game_mode(0);
}

void func_80027088(s32 arg0) {
    switch (arg0) {
        case 0:
            D_8009A5D8 = arg0;
            OVERRIDE_FLAG_UNSET(0xF00);
            resume_all_group(3);
            break;
        case 1:
            D_8009A5D8 = arg0;
            OVERRIDE_FLAG_UNSET(0xE00);
            OVERRIDE_FLAG_SET(0x100);
            suspend_all_group(1);
            break;
        case 2:
            D_8009A5D8 = arg0;
            OVERRIDE_FLAG_UNSET(0xC00);
            OVERRIDE_FLAG_SET(0x300);
            suspend_all_group(2);
            break;
        case 3:
            D_8009A5D8 = arg0;
            OVERRIDE_FLAG_UNSET(0x800);
            OVERRIDE_FLAG_SET(0x700);
            suspend_all_group(2);
            break;
        case 4:
            D_8009A5D8 = arg0;
            OVERRIDE_FLAG_SET(0xF00);
            break;
    }
}

s32 func_80027190(void) {
    return D_8009A5D8;
}

#ifdef NON_MATCHING
// void gfx_init_state(void) {
//     gSPSegment(gMasterGfxPos++, 0x00, 0x0);
//     gSPDisplayList(gMasterGfxPos++, OS_K0_TO_PHYSICAL(D_80074230));
//     gSPDisplayList(gMasterGfxPos++, OS_K0_TO_PHYSICAL(D_80074210));
// }
// matching but bullshit
void gfx_init_state(void) {
    Gfx* gfx;
    Gfx* gfx2;

    gfx = gMasterGfxPos++;
    gSPSegment(gfx, 0x00, 0x0);

    gfx = gMasterGfxPos++;
    gSPDisplayList(gfx, OS_K0_TO_PHYSICAL(D_80074230));

    gfx2 = gMasterGfxPos++;

    gfx[1].words.w0 = (_SHIFTL((G_DL), 24, 8) | _SHIFTL((0), 16, 8) | _SHIFTL((G_DL_PUSH), 0, 16));
    gfx[1].words.w1 = OS_K0_TO_PHYSICAL(D_80074210);
}
#else
INCLUDE_ASM(void, "1b40_len_20b0", gfx_init_state);
#endif

INCLUDE_ASM(s32, "1b40_len_20b0", func_800271FC);

INCLUDE_ASM(s32, "1b40_len_20b0", func_8002725C);

INCLUDE_ASM(s32, "1b40_len_20b0", func_80027600);

INCLUDE_ASM(s32, "1b40_len_20b0", func_80027774);

INCLUDE_ASM(s32, "1b40_len_20b0", func_800279B4);

// ordering issues, graphics sadness
#ifdef NON_MATCHING
void func_80027BAC(s32 arg0, s32 arg1) {
    s32 i;

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
        gSPTextureRectangle(gMasterGfxPos++, 0, i * 24, 0x04FC, 20 + i * 24, G_TX_RENDERTILE, 0, 0, 0x1000, 0x0400);
        gDPPipeSync(gMasterGfxPos++);
    }
}
#else
INCLUDE_ASM(s32, "1b40_len_20b0", func_80027BAC);
#endif

INCLUDE_ASM(void, "1b40_len_20b0", gfx_draw_background);
