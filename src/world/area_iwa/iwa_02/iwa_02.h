/// @file iwa_02.h
/// @brief Mt Rugged - Mt Rugged 3

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../iwa.h"
#include "mapfs/iwa_02_shape.h"
#include "mapfs/iwa_02_hit.h"

#include "sprite/npc/MontyMole.h"
#include "sprite/npc/Cleft.h"
#include "sprite/npc/Bubulb.h"

enum {
	NPC_Cleft_01                = 0,
	NPC_Cleft_02                = 1,
	NPC_Cleft_03                = 2,
	NPC_MontyMole_01            = 3,
	NPC_MontyMole_02            = 4,
	NPC_Bubulb                  = 5,
};

#define NAMESPACE iwa_02
