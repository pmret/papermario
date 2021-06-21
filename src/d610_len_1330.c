#include "common.h"

extern s16 D_800A08F0;
extern s32 gameModeMap[];

s32 func_800328A4(Camera* camera, f32 arg1, f32 arg2);
void create_camera_lead_player_mtx(Camera* camera);

INCLUDE_ASM(s32, "d610_len_1330", func_80032210);

INCLUDE_ASM(s32, "d610_len_1330", func_800322DC);

INCLUDE_ASM(s32, "d610_len_1330", func_800325E4);

INCLUDE_ASM(s32, "d610_len_1330", func_800328A4, Camera* camera, f32 arg1, f32 arg2);

INCLUDE_ASM(s32, "d610_len_1330", func_80032970, Camera* camera, f32 arg1);

INCLUDE_ASM(s32, "d610_len_1330", func_80032C64);

void create_camera_lead_player_mtx(Camera *camera) {
    f32 xTemp = camera->lookAt_eye.x - camera->lookAt_obj.x;
    f32 yTemp = camera->lookAt_eye.y - camera->lookAt_obj.y;
    f32 zTemp = camera->lookAt_eye.z - camera->lookAt_obj.z;
    f32 dist = sqrtf(SQ(xTemp) + SQ(yTemp) + SQ(zTemp));
    f32 theta = ((camera->vfov * 0.5f) / 180.0f) * PI;
    f32 distSinTheta = dist * sin_rad(theta);

    func_80032970(camera, (((distSinTheta / cos_rad(theta)) * camera->viewportW) / camera->viewportH) * camera->unk_520);
    func_80032C64(camera);
    guTranslateF(camera->viewMtxLeading, -camera->leadAmount, 0.0f, 0.0f);
}

void func_800334E8(void) {
}

void set_game_mode(s16 idx) {
    D_800A08F0 = idx;
    set_game_mode_slot(0, gameModeMap[idx]);
}

s16 get_game_mode(void) {
    return D_800A08F0;
}
