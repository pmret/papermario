/// @file tik_25.h
/// @brief Toad Town Tunnels - Ultra Boots Room (B3)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../tik.h"
#include "mapfs/tik_25_shape.h"
#include "mapfs/tik_25_hit.h"

enum {
    MV_EntityID_SpringR     = MapVar(0),
    MV_EntityID_SpringL     = MapVar(1),
};

#define NAMESPACE tik_25

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PlayUpgradeSong);
extern EvtScript N(EVS_SetupDrips);
extern EvtScript N(EVS_MakeEntities);
