/// @file arn_08.h
/// @brief Gusty Gulch - Windmill Interior

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../arn.h"
#include "mapfs/arn_08_shape.h"
#include "mapfs/arn_08_hit.h"

#include "sprite/npc/TubbasHeart.h"
#include "sprite/npc/Yakkey.h"

enum {
    NPC_TubbasHeart             = 0,
    NPC_Yakkey                  = 1,
};

#define NAMESPACE arn_08

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_AnimateGears);
extern EvtScript N(EVS_SetupHole);
extern EvtScript N(EVS_PlayDemoScene);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
