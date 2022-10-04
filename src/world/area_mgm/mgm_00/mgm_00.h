/// @file mgm_00.h
/// @brief Minigame - Playroom Lobby

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mgm.h"
#include "mapfs/mgm_00_shape.h"
#include "mapfs/mgm_00_hit.h"

#include "sprite/npc/Toad.h"

enum {
	NPC_RedToad			= 0,
	NPC_GreenToad		= 1,
	NPC_BlueToad		= 2,
};

enum {
    MV_RecordDisplayData        = MapVar(10),
};

#define NAMESPACE mgm_00
