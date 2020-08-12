#ifndef _OUTCOME_
#define _OUTCOME_

#include "ultra64.h"
#include "types.h"

typedef enum Outcome {
	PLAYER_WON = 0x00000000,
	PLAYER_LOST = 0x00000001,
	PLAYER_FLED = 0x00000002,
	ENEMY_FLED = 0x00000003
} Outcome;

#endif