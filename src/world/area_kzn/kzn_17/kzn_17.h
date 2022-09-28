/// @file kzn_17.h
/// @brief Mt Lavalava - Spike Roller Trap

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kzn.h"
#include "mapfs/kzn_17_shape.h"
#include "mapfs/kzn_17_hit.h"

#include "sprite/npc/BuzzyBeetle.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/Kolorado.h"
#include "sprite/npc/LargePiranha.h"
#include "sprite/npc/SpikeTop.h"

enum {
	NPC_Kolorado                = 0,
	NPC_PutridPiranha_01        = 1,
	NPC_PutridPiranha_02        = 2,
	NPC_SpikeTop                = 3,
};

enum {
    MV_Unk_00                   = MapVar(0),
    MV_Unk_0A                   = MapVar(10),
};

#define NAMESPACE kzn_17
