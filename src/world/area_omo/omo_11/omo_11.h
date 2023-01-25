/// @file omo_11.h
/// @brief Shy Guy's Toybox - RED Moving Platforms

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../omo.h"
#include "mapfs/omo_11_shape.h"
#include "mapfs/omo_11_hit.h"

#include "sprite/npc/PyroGuy.h"

enum {
    NPC_PyroGuy_01      = 0,
    NPC_PyroGuy_02      = 1,
};

enum {
    MV_SuperBlock       = MapVar(0),
};

#define NAMESPACE omo_11

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupGizmos);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
