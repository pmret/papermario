/// @file dgb_04.h
/// @brief Tubba's Castle - Stairs to Basement

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../dgb.h"
#include "mapfs/dgb_04_shape.h"
#include "mapfs/dgb_04_hit.h"

enum {
    NPC_Sentinel    = 0,
};

enum {
    MV_SuperBlock   = MapVar(0),
};

#define NAMESPACE dgb_04

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
