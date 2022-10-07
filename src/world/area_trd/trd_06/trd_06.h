/// @file trd_06.h
/// @brief Koopa Bros Fortress - Jail

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../trd.h"
#include "mapfs/trd_06_shape.h"
#include "mapfs/trd_06_hit.h"

#include "sprite/npc/WorldBombette.h"
#include "sprite/npc/KoopaTroopa.h"
#include "sprite/npc/Bobomb.h"
#include "sprite/npc/WorldBobomb.h"
#include "sprite/npc/KoopaBros.h"

enum {
	NPC_Bombette                = 1,
	NPC_Bombomb_01              = 2,
	NPC_Bombomb_02              = 3,
	NPC_Bombomb_03              = 4,
	NPC_Bombomb_04              = 5,
	NPC_Jailer_KoopaTroopa      = 10,
	NPC_Jailer_Bombomb_01       = 11,
	NPC_Jailer_Bombomb_02       = 12,
	NPC_KoopaBros_Black         = 15,
	NPC_KoopaBros_Red           = 16,
	NPC_KoopaBros_Yellow        = 17,
	NPC_KoopaBros_Green         = 18,
};

#define NAMESPACE trd_06
