/// @file flo_25.h
/// @brief Flower Fields - (SW) Path to Crystal Tree

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_25_shape.h"
#include "mapfs/flo_25_hit.h"

enum {
    NPC_GateFlower              = 0,
    NPC_RuffPuff                = 1,
    NPC_Bzzap                   = 2,
};

#define NAMESPACE flo_25

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_SetupVines);

extern NpcGroupList N(DefaultNPCs);
