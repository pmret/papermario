/// @file iwa_01.h
/// @brief Mt Rugged - Mt Rugged 2

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../iwa.h"
#include "mapfs/iwa_01_shape.h"
#include "mapfs/iwa_01_hit.h"

#include "sprite/npc/MontyMole.h"
#include "sprite/npc/Cleft.h"

enum {
	NPC_MontyMole_01            = 0,
	NPC_MontyMole_01_Hole       = 1,
	NPC_MontyMole_02            = 2,
	NPC_MontyMole_02_Stone      = 3,
	NPC_MontyMole_03            = 4,
	NPC_MontyMole_03_Stone      = 5,
	NPC_MontyMole_04            = 6,
	NPC_MontyMole_04_Stone      = 7,
	NPC_Cleft                   = 8,
};

#define NAMESPACE iwa_01
