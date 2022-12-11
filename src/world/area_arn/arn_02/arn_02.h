/// @file arn_02.h
/// @brief Gusty Gulch - Wasteland Ascent 1

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../arn.h"
#include "mapfs/arn_02_shape.h"
#include "mapfs/arn_02_hit.h"

#include "sprite/npc/Cleft.h"
#include "sprite/npc/Goomba.h"

enum {
    NPC_HyperCleft_01       = 0,
    NPC_HyperCleft_02       = 1,
    NPC_HyperGoomba         = 2,
};

#define NAMESPACE arn_02

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
