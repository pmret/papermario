#ifndef _CAMERA_H_
#define _CAMERA_H_

extern f32 D_8009A5EC;

enum {
    CAM_FLAG_1 = 0x1,
    CAM_FLAG_ENABLED = 0x2,
    CAM_FLAG_LEAD_PLAYER = 0x4,
    CAM_FLAG_SHAKING = 0x8,
    CAM_FLAG_ORTHO = 0x10,
    CAM_FLAG_80 = 0x80,
    CAM_FLAG_200 = 0x200,
    CAM_FLAG_400 = 0x400,
    CAM_FLAG_1000 = 0x1000,
};

void update_camera_mode_0(Camera*);
void update_camera_mode_1(Camera*);
void update_camera_mode_2(Camera*);
void update_camera_mode_4(Camera*);
void update_camera_mode_5(Camera*);
void update_camera_mode_6(Camera*);
void create_camera_leadplayer_matrix(Camera*);

#endif
