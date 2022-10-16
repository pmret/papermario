#ifndef _CAMERA_H_
#define _CAMERA_H_

extern f32 D_8009A5EC;

void update_camera_mode_0(Camera*);
void update_camera_mode_1(Camera*);
void update_camera_mode_2(Camera*);
void update_camera_mode_4(Camera*);
void update_camera_mode_5(Camera*);
void update_camera_mode_6(Camera*);
void create_camera_leadplayer_matrix(Camera*);

void update_camera_zone_interp(Camera* camera);
Camera* initialize_next_camera(CameraInitData* data);

#endif
