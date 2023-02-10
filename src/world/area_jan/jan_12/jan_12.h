/// @file jan_12.h
/// @brief Jade Jungle - Deep Jungle 1

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../jan.h"
#include "mapfs/jan_12_shape.h"
#include "mapfs/jan_12_hit.h"

enum {
    NPC_SpearGuy        = 0,
    NPC_SpearGuy_Hitbox = 1,
};

enum {
    MV_BushOffsetL      = MapVar(0),
    MV_BushOffsetR      = MapVar(1),
    MV_PullVineCallback = MapVar(10),
};

#define NAMESPACE jan_12

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupTrees);
extern EvtScript N(EVS_SetupVines);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
