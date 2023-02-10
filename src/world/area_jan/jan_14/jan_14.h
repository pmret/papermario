/// @file jan_14.h
/// @brief Jade Jungle - Deep Jungle 3

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../jan.h"
#include "mapfs/jan_14_shape.h"
#include "mapfs/jan_14_hit.h"

enum {
    NPC_JungleFuzzy_01  = 0,
    NPC_JungleFuzzy_02  = 1,
};

enum {
    MV_BushOffsetL      = MapVar(0),
    MV_BushOffsetR      = MapVar(1),
    MV_PullVineCallback = MapVar(10),
};

#define NAMESPACE jan_14

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupVines);
extern EvtScript N(EVS_SetupTrees);
extern NpcGroupList N(DefaultNPCs);
