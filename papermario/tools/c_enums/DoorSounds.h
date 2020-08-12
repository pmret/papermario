#ifndef _DOOR_SOUNDS_
#define _DOOR_SOUNDS_

#include "ultra64.h"
#include "types.h"

typedef enum DoorSounds {
	BASIC = 0x00000000,
	METAL = 0x00000001,
	LARGE = 0x00000002,
	CREAKY = 0x00000003,
	GATE = 0x00000004
} DoorSounds;

#endif