#ifndef _CAMERA_H_
#define _CAMERA_H_

extern f32 CamLengthScale;

void update_camera_minimal(Camera*);
void update_camera_unused_radial(Camera*);
void update_camera_interp_pos(Camera*);
void update_camera_unused_confined(Camera*);
void update_camera_unused_leading(Camera*);
void update_camera_no_interp(Camera*);
void create_camera_leadplayer_matrix(Camera*);

void update_camera_zone_interp(Camera* camera);
Camera* initialize_next_camera(CameraInitData* data);

#endif
