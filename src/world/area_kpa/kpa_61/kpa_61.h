/// @file kpa_61.h
/// @brief Bowser's Castle - Battlement

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_61_shape.h"
#include "mapfs/kpa_61_hit.h"

enum {
    NPC_Koopatrol_01                = 0,
    NPC_Koopatrol_02                = 1,
    NPC_FlyingMagikoopa_01          = 2,
    NPC_FlyingMagikoopa_01_Spell    = 3,
    NPC_FlyingMagikoopa_02          = 4,
    NPC_FlyingMagikoopa_02_Spell    = 5,
};

#define NAMESPACE kpa_61

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
