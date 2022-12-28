/// @file arn_11.h
/// @brief Gusty Gulch - Tubba's Heart Chamber

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../arn.h"
#include "mapfs/arn_11_shape.h"
#include "mapfs/arn_11_hit.h"

#include "sprite/npc/TubbasHeart.h"

enum {
    NPC_TubbasHeart             = 0,
};

#define NAMESPACE arn_11

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
