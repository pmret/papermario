#include "common.h"
#include "ld_addrs.h"
#include "nu/nusys.h"

// todo remove here and from undefined_syms
extern Addr _163400_BSS_START;
extern Addr _163400_BSS_END;

s32 D_80077980[] = { &D_8038F800, &D_803B5000, &D_803DA800, };

NUPiOverlaySegment D_8007798C = {
    .romStart = _163400_ROM_START,
    .romEnd = _163400_ROM_END,
    .ramStart = _163400_VRAM,
    .textStart = _163400_TEXT_START,
    .textEnd = _163400_TEXT_END,
    .dataStart = _163400_DATA_START,
    .dataEnd = _163400_DATA_END,
    .bssStart = _163400_BSS_START,
    .bssEnd = _163400_BSS_END,
};

u8 D_800779B0 = 0;

void state_init_language_select(void) {
    D_800A0931 = 0;
    D_800A0932[0] = 0;
    disable_player_input();
    set_time_freeze_mode(2);
    set_screen_overlay_params_front(0, D_800A0932[0]);
}

void state_init_file_select(void) {
    D_800A0931 = 0;
    D_800A0932[0] = 0;
    disable_player_input();
    set_time_freeze_mode(2);
    general_heap_create();
    set_hud_element_nonworld_cache(0, 0);
    clear_hud_element_cache();
    load_model_textures(0, 0, 0);
    gCameras[0].mode = 6;
    gCameras[0].unk_06 = 1;
    gCameras[0].nearClip = 16;
    gCameras[0].farClip = 4096;
    gCameras[0].flags |= 2;
    gCurrentCameraID = 0;
    gCameras[1].flags |= 2;
    gCameras[2].flags |= 2;
    gCameras[3].flags |= 2;
    gCameras[0].vfov = 25.0f;
    set_cam_viewport(0, 12, 28, 296, 184);
    gCameras[0].unk_1E = 40;
    gCameras[0].lookAt_eye.x = 500.0f;
    gCameras[0].lookAt_eye.y = 1000.0f;
    gCameras[0].lookAt_eye.z = 1500.0f;
    gCameras[0].unk_5C = 150.0f;
    gCameras[0].bgColor[0] = 0;
    gCameras[0].bgColor[1] = 0;
    gCameras[0].bgColor[2] = 0;
    gCameras[0].unk_54 = 25.0f;
    gCameras[0].unk_58 = 25.0f;
    gCameras[0].unk_1C = 0;
    gCameras[0].unk_20 = 100;
    gCameras[0].unk_22 = 0;
    gOverrideFlags |= 0x10000;
}

INCLUDE_ASM(void, "state_file_select", state_step_language_select, void);

void state_step_file_select(void) {
    s32 temp = D_800A0931; // needed to match

    switch (D_800A0931) {
        case 1:
            set_windows_visible(3);
            D_800A0930 = temp;
            D_800A0931 = 2;
            break;
        case 0:
            D_800A0931 = 1;
            break;
        case 2:
            if (D_800A0930 >= 0) {
                D_800A0930--;
                temp = D_800A0930;
                if (temp == 0) {
                    D_800A0930 = -1;
                    battle_heap_create();
                    nuPiReadRomOverlay(&D_8007798C);
                    filemenu_init(0);
                }
            }

            if (D_800A0930 < 0) {
                filemenu_update();
            }
            break;
    }
}

void state_drawUI_language_select(void) {
}

void state_drawUI_file_select(void) {
}

void state_init_exit_language_select(void) {
    if (D_800A0932[0] > 0) {
        D_800A0931 = 0;
        set_screen_overlay_params_front(0, D_800A0932[0]);
    } else {
        D_800A0931 = 1;
        set_screen_overlay_params_front(0, D_800A0932[0]);
    }
    D_800A0930 = 1;
    gOverrideFlags &= ~0x40;
}

void state_init_exit_file_select(void) {
    D_800A0931 = 0;
    D_800A0932[0] = 0;
    D_800A0930 = 0;

    if (func_80244BC4() == 0) {
        set_map_transition_effect(7);
    } else {
        set_map_transition_effect(8);
        gOverrideFlags &= ~0x0010000;
        bgm_set_song(0, -1, 0, 1000, 8);
    }
    gOverrideFlags &= ~0x40;
}

INCLUDE_ASM(void, "state_file_select", state_step_exit_language_select, void);

INCLUDE_ASM(void, "state_file_select", state_step_exit_file_select, void);

void state_drawUI_exit_language_select(void) {
}

void state_drawUI_exit_file_select(void) {
}
