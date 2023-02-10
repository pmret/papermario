/// @file jan_07.h
/// @brief Jade Jungle - Small Jungle Ledge

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../jan.h"
#include "mapfs/jan_07_shape.h"
#include "mapfs/jan_07_hit.h"

enum {
    NPC_YoshiKid                = 0,
    NPC_PutridPiranha_01        = 1,
    NPC_PutridPiranha_02        = 2,
    NPC_SpearGuy                = 10,
    NPC_SpearGuy_Hitbox         = 11,
};

#define NAMESPACE jan_07

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupTrees);
extern EvtScript N(EVS_SetupBushes);
extern NpcGroupList N(DefaultNPCs);
