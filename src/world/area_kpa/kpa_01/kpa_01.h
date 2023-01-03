/// @file kpa_01.h
/// @brief Bowser's Castle - Dark Cave 1

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_01_shape.h"
#include "mapfs/kpa_01_hit.h"

enum {
    NPC_BonyBeetle_01           = 0,
    NPC_BonyBeetle_02           = 1,
};

#define NAMESPACE kpa_01

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
