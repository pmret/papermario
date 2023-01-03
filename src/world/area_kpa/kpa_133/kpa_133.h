/// @file kpa_133.h
/// @brief Bowser's Castle - Left Water Puzzle

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_133_shape.h"
#include "mapfs/kpa_133_hit.h"

enum {
    NPC_Dummy   = 0,
};

enum {
    MV_SpringEntityID       = MapVar(0),
    MV_RevealHiddenSpring   = MapVar(1),
};

#define NAMESPACE kpa_133

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetWaterLevel);
extern EvtScript N(D_80241A90_AA8F10);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
