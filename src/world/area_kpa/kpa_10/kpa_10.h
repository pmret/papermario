/// @file kpa_10.h
/// @brief Bowser's Castle - Outside Lower Jail (No Lava)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_10_shape.h"
#include "mapfs/kpa_10_hit.h"

#include "sprite/npc/Toad.h"
#include "sprite/npc/ToadGuard.h"

enum {
    NPC_Toad_01                 = 0,
    NPC_Toad_02                 = 1,
    NPC_ToadGuard               = 2,
};

#define NAMESPACE kpa_10

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
extern EvtScript N(EVS_MakeEntities);
