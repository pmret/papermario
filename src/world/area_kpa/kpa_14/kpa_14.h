/// @file kpa_14.h
/// @brief Bowser's Castle - Lava Channel 3

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_14_shape.h"
#include "mapfs/kpa_14_hit.h"

enum {
    MV_PadlockEntityID          = MapVar(0),
    MV_LastFloorBeforeLavaFall  = MapVar(10),
    MV_TakingLavaFallDamage     = MapVar(11),
};

#define NAMESPACE kpa_14

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupPlatforms);
extern EvtScript N(EVS_ExitDoor_kpa_01_0);
extern EvtScript N(EVS_MakeEntities);
