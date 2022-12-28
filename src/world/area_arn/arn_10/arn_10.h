/// @file arn_10.h
/// @brief Gusty Gulch - Tunnel 1

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../arn.h"
#include "mapfs/arn_10_shape.h"
#include "mapfs/arn_10_hit.h"

enum {
    NPC_TubbasHeart     = 0,
    NPC_HyperGoomba     = 1,
};

#define NAMESPACE arn_10

extern EvtScript N(EVS_Main);
extern NpcGroupList N(DefaultNPCs);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
