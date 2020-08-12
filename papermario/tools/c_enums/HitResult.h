#ifndef _HIT_RESULT_
#define _HIT_RESULT_

#include "ultra64.h"
#include "types.h"

typedef enum HitResult {
	HIT = 0x00000000,
	LANDED_ON_SPIKE = 0x00000004,
	LUCKY = 0x00000005,
	MISS = 0x00000006,
	HIT_STATIC = 0x00000007,
	IMMUNE = 0x00000008,
	TRIGGERED_EXPLODE = -0x00000001
} HitResult;

#endif