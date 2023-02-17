#ifndef _BODY_SLAM_H_
#define _BODY_SLAM_H_

#include "common_structs.h"

API_CALLABLE(action_command_body_slam_init);
API_CALLABLE(action_command_body_slam_start);
void action_command_body_slam_update(void);
void action_command_body_slam_draw(void);
void action_command_body_slam_free(void);

#endif
