#ifndef _DOOR_SWING_
#define _DOOR_SWING_

#include "ultra64.h"
#include "types.h"

typedef enum DoorSwing {
	IN = 0x00000001,
	OUT = -0x00000001
} DoorSwing;

#endif