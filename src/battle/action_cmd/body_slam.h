#ifndef _BODY_SLAM_H_
#define _BODY_SLAM_H_

#include "common_structs.h"

ApiStatus action_command_body_slam_init(Evt* script, s32 isInitialCall);
ApiStatus action_command_body_slam_start(Evt* script, s32 isInitialCall);
void action_command_body_slam_update(void);
void action_command_body_slam_draw(void);
void action_command_body_slam_free(void);

#endif
