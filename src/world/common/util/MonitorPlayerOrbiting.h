#ifndef _PLAYER_ORBITING_H_
#define _PLAYER_ORBITING_H_

#include "common.h"

typedef struct PlayerOrbitState {
    Vec3i pos;
    s32 startRadius;
    s32 orbitRadius;
    void (*eventListener)(struct PlayerOrbitState*, s32);
    s32 totalOrbitAngle;
    s32 numRotations;
    s32 state;
    f32 firstPlayerX;
    f32 firstPlayerZ;
    f32 lastPlayerX;
    f32 lastPlayerZ;
    f32 direction;
    s32 lastNumRotations;
} PlayerOrbitState;

// these should be defined in map data and supplied to MonitorPlayerOrbiting when it is called
typedef struct {
    Vec3i pos;
    s32 startRadius; // orbiting begins when the player enters this radius
    s32 orbitRadius; // orbiting continues while the player is within this radius
    void (*eventListener)(PlayerOrbitState*, s32);
} PlayerOrbitTarget;

// events which are dispatched to the event handler
enum {
    PLAYER_ORBIT_BEGIN              = 0,
    PLAYER_ORBIT_COMPLETE_ROTATION  = 1,
    PLAYER_ORBIT_CONTINUE_ORBIT     = 2,
    PLAYER_ORBIT_CHANGE_DIRECTION   = 3,
    PLAYER_ORBIT_LEFT_REGION        = 4,
};

// states of this function
enum {
    ORBIT_STATE_FIRST_FRAME       = 0,
    ORBIT_STATE_SECOND_FRAME      = 1,
    ORBIT_STATE_STARTING_ORBIT    = 2,
    ORBIT_STATE_MAINTAIN_ORBIT    = 3,
    ORBIT_STATE_BREAK_ORBIT       = 4,
};

#endif
