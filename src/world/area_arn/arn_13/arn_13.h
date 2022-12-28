/// @file arn_13.h
/// @brief Gusty Gulch - Tunnel 3

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../arn.h"
#include "mapfs/arn_13_shape.h"
#include "mapfs/arn_13_hit.h"

enum {
    NPC_TubbasHeart     = 0,
    NPC_HyperGoomba     = 1,
};

#define NAMESPACE arn_13

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
