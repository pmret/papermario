/// @file kpa_62.h
/// @brief Bowser's Castle - Front Door Exterior

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_62_shape.h"
#include "mapfs/kpa_62_hit.h"

enum {
    MV_PadLockEntityID  = MapVar(0),
};

#define NAMESPACE kpa_62

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_ExitDoors_kpa_70_0);
extern EvtScript N(EVS_MakeEntities);
