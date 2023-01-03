/// @file kpa_102.h
/// @brief Bowser's Castle - Blue Fire Bridge

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_102_shape.h"
#include "mapfs/kpa_102_hit.h"

#include "sprite/npc/HammerBros.h"
#include "sprite/npc/FlyingMagikoopa.h"
#include "sprite/npc/WorldKoopatrol.h"

enum {
    NPC_Koopatrol               = 0,
    NPC_FlyingMagikoopa         = 1,
    NPC_FlyingMagikoopa_Spell   = 2,
    NPC_HammerBros              = 50,
    NPC_HammerBros_Hammer1      = 51,
    NPC_HammerBros_Hammer2      = 52,
    NPC_HammerBros_Hammer3      = 53,
    NPC_HammerBros_Hammer4      = 54,
    NPC_HammerBros_Hammer5      = 55,
    NPC_HammerBros_Hammer6      = 56,
};

#define NAMESPACE kpa_102

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
