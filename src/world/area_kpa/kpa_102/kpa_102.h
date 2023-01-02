/// @file kpa_102.h
/// @brief Bowser's Castle - Blue Fire Bridge

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_102_shape.h"
#include "mapfs/kpa_102_hit.h"

#include "sprite/npc/HammerBros.h"
#include "sprite/npc/FlyingMagikoopa.h"
#include "sprite/npc/WorldKoopatrol.h"

enum {
	NPC_Koopatrol               = 0,
	NPC_FlyingMagikoopa      	= 1, // spell uses ID 2
	NPC_HammerBros              = 50, // hammers use IDs 51-56
};

#define NAMESPACE kpa_102

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
