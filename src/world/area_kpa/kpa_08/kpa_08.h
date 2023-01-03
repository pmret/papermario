/// @file kpa_08.h
/// @brief Bowser's Castle - Castle Key Timing Puzzle

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_08_shape.h"
#include "mapfs/kpa_08_hit.h"

#include "sprite/npc/Magikoopa.h"

enum {
    NPC_Magikoopa           = 0,
    NPC_Magikoopa_Spell     = 1,
};

#define NAMESPACE kpa_08

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
