/// @file kpa_11.h
/// @brief Bowser's Castle - Outisde Lower Jail (Lava)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_11_shape.h"
#include "mapfs/kpa_11_hit.h"

#include "sprite/npc/WorldKoopatrol.h"
#include "sprite/npc/Toad.h"
#include "sprite/npc/ToadGuard.h"

enum {
    NPC_Koopatrol               = 0,
    NPC_Toad_01                 = 1,
    NPC_Toad_02                 = 2,
    NPC_ToadGuard               = 3,
};

#define NAMESPACE kpa_11

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
