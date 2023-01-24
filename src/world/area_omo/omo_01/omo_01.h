/// @file omo_01.h
/// @brief Shy Guy's Toybox - BLU Large Playroom

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../omo.h"
#include "mapfs/omo_01_shape.h"
#include "mapfs/omo_01_hit.h"

enum {
    NPC_ShyGuy_01   = 0,
    NPC_ShyGuy_02   = 1,
    NPC_ShyGuy_03   = 2,
    NPC_ShyGuy_04   = 3,
    NPC_ShyGuy_05   = 4,
};

#define NAMESPACE omo_01

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupGizmos);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
