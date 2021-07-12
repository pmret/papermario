#include "common.h"

s32 D_800778A0[] = {
    &D_8038F800, &D_803B5000, &D_803DA800, 0x00000000, 0xFFFFFF00, 0xFFFFFF00, 0x00000000, 0x00000000, 0x00000000,
    0x00000000,
};

Gfx D_800778C8[] = {
    gsDPPipeSync(),
    gsDPSetCycleType(G_CYC_COPY),
    gsDPSetTexturePersp(G_TP_NONE),
    gsDPSetTextureLUT(G_TT_NONE),
    gsDPSetCombineMode(G_CC_DECALRGB, G_CC_DECALRGB),
    gsDPSetRenderMode(G_RM_NOOP, G_RM_NOOP2),
    gsDPSetTextureFilter(G_TF_POINT),
    gsSPEndDisplayList(),
};

// Should maybe be in state_logos.c but creates an 0x8 data split
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


// BSS
extern s32 D_800A0904;
extern s32 D_800A0908;

void state_init_battle(void) {
    D_800A0900 = 5;
}

#ifdef NON_MATCHING
void state_step_battle(void) {
    s32 phi_a0;
    u32 currentBattleSection;
    u32 unk_47B;

    if (D_800A0900 == 5) {
        if (D_8009A658[1] != D_8009A64C) {
            return;
        }
        D_800A0900--;
        gOverrideFlags |= 0x8;
        nuContRmbForceStop();
    }

    if (D_800A0900 >= 0) {
        if (D_800A0900 > 0) {
            D_800A0900--;
            return;
        } else {
            D_800A0900 = -1;
            nuGfxSetCfb(&D_800778A0, 2);
            nuContRmbForceStopEnd();
            sfx_stop_env_sounds();
            func_8003B1A8();
            gGameStatusPtr->isBattle = TRUE;
            allocate_hit_tables();
            func_8002D160();
            func_802B20B4();
            sfx_clear_env_sounds(0);

            currentBattleSection = gBattleStatus.currentBattleSection;
            unk_47B = gBattleStatus.unk_47B;

            // This part sucks
            if ((gGameStatusPtr->peachFlags & 1) || (currentBattleSection == 0x26 && unk_47B == 0)) {
                gGameStatusPtr->peachFlags |= 1;
                spr_init_sprites(6);
            } else {
                spr_init_sprites(5);
            }

            clear_model_data();
            clear_sprite_shading_data();
            reset_background_settings();
            clear_entity_models();
            clear_animator_list();
            clear_generic_entity_list();
            set_hud_element_nonworld_cache(0, 0);
            clear_hud_element_cache();
            reset_status_menu();
            clear_item_entity_data();
            clear_script_list();
            clear_npcs();
            clear_entity_data(1);
            clear_trigger_data();
            dma_copy(&_16C8E0_ROM_START, &_16C8E0_ROM_END, &_16C8E0_VRAM);
            initialize_battle();
            btl_save_world_cameras();
            load_battle_section();
            D_800A0904 = gPlayerStatusPtr->animFlags;
            gPlayerStatusPtr->animFlags &= ~0x40;
            D_800A0908 = get_time_freeze_mode();
            set_time_freeze_mode(0);
            gOverrideFlags &= ~0x8;

            if (D_800A0900 >= 0) {
                return;
            }
        }
    }

    update_encounters();
    btl_update();
    update_npcs();
    update_item_entities();
    update_effects();
    func_80116674();
    update_cameras();
}
#else
INCLUDE_ASM(void, "state_battle", state_step_battle, void);
#endif

void state_drawUI_battle(void) {
    draw_encounter_ui();
    if (D_800A0900 < 0) {
        btl_draw_ui();
    }
}

void state_init_end_battle(void) {
    gOverrideFlags |= 0x8;
    nuContRmbForceStop();
    D_800A0900 = 5;
}

INCLUDE_ASM(void, "state_battle", state_step_end_battle, void);

void state_drawUI_end_battle(void) {
}
