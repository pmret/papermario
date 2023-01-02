/// @file kpa_115.h
/// @brief Bowser's Castle - Room with Hidden Door 3

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_115_shape.h"
#include "mapfs/kpa_115_hit.h"

enum {
	NPC_HammerBros	= 20, // uses 21-26 for hammers
};

#define NAMESPACE kpa_115

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupStatues);
extern NpcGroupList N(DefaultNPCs);
