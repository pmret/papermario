/// @file kzn_23.h
/// @brief Mt Lavalava - Volcano Escape

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kzn.h"
#include "mapfs/kzn_23_shape.h"
#include "mapfs/kzn_23_hit.h"

#include "sprite/npc/Kolorado.h"
#include "sprite/npc/WorldMisstar.h"

enum {
	NPC_Kolorado                = 0,
	NPC_Misstar                 = 1,
};

enum {
	MV_LavaLevel				= MapVar(10),
};

#define NAMESPACE kzn_23
