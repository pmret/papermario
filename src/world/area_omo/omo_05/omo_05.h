/// @file omo_05.h
/// @brief Shy Guy's Toybox - PNK Gourmet Guy Crossing

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../omo.h"
#include "mapfs/omo_05_shape.h"
#include "mapfs/omo_05_hit.h"

#include "sprite/npc/GourmetGuy.h"
#include "sprite/npc/GrooveGuy.h"

enum {
    NPC_GourmetGuy          = 0,
    NPC_GourmetGuy_Knife    = 1,
    NPC_GourmetGuy_Fork     = 2,
    NPC_GrooveGuy           = 3,
};

#define NAMESPACE omo_05

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupGizmos);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
