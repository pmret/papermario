#ifndef _NPC_
#define _NPC_

#include "ultra64.h"
#include "types.h"

typedef enum Npc {
	SELF = 0xFFFFFFFF,
	PLAYER = 0xFFFFFFFE,
	PARTNER = 0xFFFFFFFC
} Npc;

#endif