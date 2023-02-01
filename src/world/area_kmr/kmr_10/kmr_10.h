/// @file kmr_10.h
/// @brief Goomba Region - Toad Town Entrance

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kmr.h"
#include "mapfs/kmr_10_shape.h"
#include "mapfs/kmr_10_hit.h"

#include "sprite/npc/Toad.h"

enum {
    NPC_Dummy   = 0, // for controlling the spring as it falls from the tree
};

enum {
    MV_SpringEntityIndex    = MapVar(0),
};

#define NAMESPACE kmr_10

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_OnShakeTree1);
extern NpcGroupList N(DefaultNPCs);
