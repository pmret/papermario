/// @file kpa_50.h
/// @brief Bowser's Castle - Hall to Guard Door 1

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_50_shape.h"
#include "mapfs/kpa_50_hit.h"

#include "sprite/npc/HammerBros.h"
#include "sprite/npc/WorldKoopatrol.h"

enum {
    NPC_Koopatrol_01            = 0,
    NPC_Koopatrol_02            = 1,
    NPC_HammerBros              = 10,
    NPC_HammerBros_Hammer1      = 11,
    NPC_HammerBros_Hammer2      = 12,
    NPC_HammerBros_Hammer3      = 13,
    NPC_HammerBros_Hammer4      = 14,
    NPC_HammerBros_Hammer5      = 15,
    NPC_HammerBros_Hammer6      = 16,
};

#define NAMESPACE kpa_50

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
