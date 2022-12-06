/// @file arn_09.h
/// @brief Gusty Gulch - Windmill Tunnel Entry

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../arn.h"
#include "mapfs/arn_09_shape.h"
#include "mapfs/arn_09_hit.h"

#include "sprite/npc/TubbasHeart.h"

enum {
    NPC_TubbasHeart             = 0,
};

#define NAMESPACE arn_09

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_LaunchPlayer);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
