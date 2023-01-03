/// @file kpa_03.h
/// @brief Bowser's Castle - Dark Cave 2

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_03_shape.h"
#include "mapfs/kpa_03_hit.h"

#include "sprite/npc/BuzzyBeetle.h"
#include "sprite/npc/Magikoopa.h"
#include "sprite/npc/WorldKoopatrol.h"
#include "sprite/npc/BonyBeetle.h"

enum {
    NPC_Koopatrol_01            = 0,
    NPC_Koopatrol_02            = 1,
    NPC_BonyBeetle_01           = 2,
    NPC_BonyBeetle_02           = 3,
    NPC_Magikoopa_01            = 4,
    NPC_Magikoopa_01_Spell      = 5,
};

enum {
    MV_PlayerHeightLevel    = MapVar(0),
};

#define NAMESPACE kpa_03

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
