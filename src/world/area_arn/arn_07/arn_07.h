/// @file arn_07.h
/// @brief Gusty Gulch - Windmill Exterior

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../arn.h"
#include "mapfs/arn_07_shape.h"
#include "mapfs/arn_07_hit.h"

#include "sprite/npc/TubbasHeart.h"
#include "sprite/npc/WorldTubba.h"
#include "sprite/npc/WorldBow.h"
#include "sprite/npc/Boo.h"
#include "sprite/npc/Bootler.h"
#include "sprite/npc/WorldSkolar.h"
#include "sprite/npc/Paragoomba.h"

enum {
	NPC_TubbasHeart         = 0,
	NPC_Tubba               = 1,
	NPC_Boo_01              = 2,
	NPC_Boo_02              = 3,
	NPC_Boo_03              = 4,
	NPC_Boo_04              = 5,
	NPC_Boo_05              = 6,
	NPC_Boo_06              = 7,
	NPC_Bow                 = 8,
	NPC_Bootler             = 9,
	NPC_Paragoomba_01       = 10,
	NPC_Paragoomba_02       = 11,
	NPC_Paragoomba_03       = 12,
	NPC_Skolar              = 13,
};

enum {
    MV_Unk_00               = MapVar(0),
};

#define NAMESPACE arn_07
