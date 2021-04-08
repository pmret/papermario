#include "common.h"

void state_init_language_select(void) {
    D_800A0931 = 0;
    D_800A0932[0] = 0;
    disable_player_input();
    func_80027088(2);
    set_transition_stencil_zoom_0(0, D_800A0932[0]);
}

void state_init_file_select(void) {
    Camera* cameras = gCameras;

    D_800A0931 = 0;
    D_800A0932[0] = 0;
    disable_player_input();
    func_80027088(2);
    general_heap_create();
    func_801452E8(0, 0);
    func_80141100();
    load_model_textures(0, 0, 0);
    cameras[0].mode = 6;
    cameras[0].unk_06 = 1;
    cameras[0].nearClip = 16;
    cameras[0].farClip = 4096;
    cameras[0].flags |= 2;
    gCurrentCameraID = 0;
    cameras[1].flags |= 2;
    cameras[2].flags |= 2;
    cameras[3].flags |= 2;
    cameras[0].vfov = 25.0f;
    set_cam_viewport(0, 12, 28, 296, 184);
    cameras[0].unk_1E = 40;
    cameras[0].lookAt_eye[0] = 500.0f;
    cameras[0].lookAt_eye[1] = 1000.0f;
    cameras[0].lookAt_eye[2] = 1500.0f;
    cameras[0].unk_5C = 150.0f;
    cameras[0].backgroundColor[0] = 0;
    cameras[0].backgroundColor[1] = 0;
    cameras[0].backgroundColor[2] = 0;
    cameras[0].unk_54 = 25.0f;
    cameras[0].unk_58 = 25.0f;
    cameras[0].unk_1C = 0;
    cameras[0].unk_20 = 100;
    cameras[0].unk_22 = 0;
    OVERRIDE_FLAG_SET(0x10000);
}

INCLUDE_ASM(s32, "10400_len_d30", state_step_language_select);

INCLUDE_ASM(s32, "10400_len_d30", func_800354EC);

void state_drawUI_language_select(void) {
}

void state_drawUI_file_select(void) {
}

void func_800355D4(void) {
    if (D_800A0932[0] > 0) {
        D_800A0931 = 0;
        set_transition_stencil_zoom_0(0, D_800A0932[0]);
    } else {
        D_800A0931 = 1;
        set_transition_stencil_zoom_0(0, D_800A0932[0]);
    }
    D_800A0930 = 1;
    OVERRIDE_FLAG_UNSET(0x40);
}

void func_80035660(void) {
    D_800A0931 = 0;
    D_800A0932[0] = 0;
    D_800A0930 = 0;

    if (func_80244BC4() == 0) {
        set_map_transition_effect(7);
    } else {
        set_map_transition_effect(8);
        OVERRIDE_FLAG_UNSET(0x0010000);
        bgm_set_song(0, -1, 0, 1000, 8);
    }
    OVERRIDE_FLAG_UNSET(0x40);
}

INCLUDE_ASM(s32, "10400_len_d30", func_80035704);

INCLUDE_ASM(s32, "10400_len_d30", func_80035B40);

void func_80035D18(void) {
}

void func_80035D20(void) {
}
