#include "common.h"
#include "nu/nusys.h"
#include "ld_addrs.h"

void intro_logos_set_fade_alpha(s16 alpha);
void intro_logos_set_fade_color(s16 color);
s16 intro_logos_fade_in(s16 subtractAlpha);
s16 intro_logos_fade_out(s16 addAlpha);
void intro_logos_update_fade(void);

extern s32 D_800A0904;
extern s32 D_800A0908;
extern s16** D_800778A0;

void intro_logos_set_fade_alpha(s16 alpha) {
    gGameStatusPtr->bootAlpha = alpha;
}

void intro_logos_set_fade_color(s16 color) {
    gGameStatusPtr->bootRed = color;
    gGameStatusPtr->bootGreen = color;
    gGameStatusPtr->bootBlue = color;
}

s16 intro_logos_fade_in(s16 subtractAlpha) {
    if (gGameStatusPtr->bootAlpha != 0) {
        gGameStatusPtr->bootAlpha -= subtractAlpha;
        if (gGameStatusPtr->bootAlpha << 16 < 0) {
            gGameStatusPtr->bootAlpha = 0;
        }
    } else {
        return 1;
    }
    return 0;
}

s16 intro_logos_fade_out(s16 addAlpha) {
    if (gGameStatusPtr->bootAlpha != 255) {
        gGameStatusPtr->bootAlpha += addAlpha;
        if (gGameStatusPtr->bootAlpha > 255) {
            gGameStatusPtr->bootAlpha = 255;
        }
    } else {
        return 1;
    }
    return 0;
}

void intro_logos_update_fade(void) {
    set_transition_stencil_zoom_0(0, gGameStatusPtr->bootAlpha);
    set_transition_stencil_color(0, gGameStatusPtr->bootBlue, gGameStatusPtr->bootGreen, gGameStatusPtr->bootRed);
}

void begin_state_battle(void) {
    D_800A0900 = 5;
}

#ifdef NON_MATCHING
void step_battle(void) {
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
            func_80149670(0);

            currentBattleSection = gBattleStatus.currentBattleSection;
            unk_47B = gBattleStatus.unk_47B;

            // This part sucks
            if (gGameStatusPtr->peachFlags & 1) {
                gGameStatusPtr->peachFlags |= 1;
                phi_a0 = 6;
            } else if (currentBattleSection == 0x26) {
                if (unk_47B == 0) {
                    gGameStatusPtr->peachFlags |= 1;
                    phi_a0 = 6;
                } else {
                    phi_a0 = 5;
                }
            } else {
                phi_a0 = 5;
            }
            spr_init_sprites(phi_a0);

            clear_model_data();
            func_80148040();
            use_default_background_settings();
            clear_entity_models();
            func_8011E224();
            clear_dynamic_entity_list();
            func_801452E8(0, 0);
            func_80141100();
            reset_status_menu();
            clear_item_entity_data();
            clear_script_list();
            npc_list_clear();
            clear_entity_data(1);
            clear_trigger_data();
            dma_copy(&_16C8E0_ROM_START, &_16C8E0_ROM_END, &_16C8E0_VRAM);
            initialize_battle();
            func_802409F4();
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

    update_counters();
    update_battle_state();
    npc_list_update();
    update_item_entities();
    update_effects();
    func_80116674();
    update_cameras();
}
#else
INCLUDE_ASM(s32, "ebd0_len_6a0", step_battle);
#endif

void func_80033B54(void) {
    draw_encounter_ui();
    if (D_800A0900 < 0) {
        draw_main_battle_ui();
    }
}

void func_80033B88(void) {
    gOverrideFlags |= 0x8;
    nuContRmbForceStop();
    D_800A0900 = 5;
}

INCLUDE_ASM(s32, "ebd0_len_6a0", func_80033BC0);

void func_80033E64(void) {
}
