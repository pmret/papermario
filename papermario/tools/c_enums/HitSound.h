#ifndef _HIT_SOUND_
#define _HIT_SOUND_

#include "ultra64.h"
#include "types.h"

typedef enum HitSound {
	MISS = 0x00000000,
	BONES = 0x00000001,
	NORMAL = 0x00000002,
	FIRE = 0x00000003,
	ICE = 0x00000004,
	SHOCK = 0x00000005
} HitSound;

#endif