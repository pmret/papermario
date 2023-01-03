/// @file kpa_51.h
/// @brief Bowser's Castle - Hall to Water Puzzle

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_50_shape.h"
#include "mapfs/kpa_50_hit.h"

#include "sprite/npc/Magikoopa.h"
#include "sprite/npc/WorldKoopatrol.h"

enum {
    NPC_Magikoopa_01            = 0,
    NPC_Magikoopa_01_Spell      = 1,
    NPC_Magikoopa_02            = 2,
    NPC_Magikoopa_02_Spell      = 3,
    NPC_Koopatrol               = 4,
};

#define NAMESPACE kpa_51

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
