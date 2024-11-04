#ifndef _BODY_SLAM_H_
#define _BODY_SLAM_H_

#include "common_structs.h"

// args: none
API_CALLABLE(action_command_body_slam_init);

// args: prep time, duration, difficulty, variation
API_CALLABLE(action_command_body_slam_start);

void action_command_body_slam_update(void);
void action_command_body_slam_draw(void);
void action_command_body_slam_free(void);

enum {
    ACV_SLAM_BOMBETTE   = 0,
    ACV_SLAM_WATT       = 1,
};

#endif
