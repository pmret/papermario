#ifndef _ACTOR_SOUND_
#define _ACTOR_SOUND_

#include "ultra64.h"
#include "types.h"

typedef enum ActorSound {
	WALK = 0x00000000,
	FLY = 0x00000001,
	JUMP = 0x00000002,
	HURT = 0x00000003,
	WALK_INCREMENT = 0x00000004,
	FLY_INCREMENT = 0x00000005
} ActorSound;

#endif