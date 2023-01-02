/// @file kpa_113.h
/// @brief Bowser's Castle - Room with Hidden Door 2

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_113_shape.h"
#include "mapfs/kpa_113_hit.h"

enum {
    NPC_BonyBeetle      = 0,
};

enum {
    MV_PadlockEntityID  = MapVar(1),
};

#define NAMESPACE kpa_113

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupStatues);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
