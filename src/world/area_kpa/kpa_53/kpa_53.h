/// @file kpa_53.h
/// @brief Bowser's Castle - Fake Peach Hallway

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_50_shape.h"
#include "mapfs/kpa_50_hit.h"

#include "sprite/npc/Duplighost.h"

enum {
    NPC_Follower        = 0,
    NPC_Guardian        = 1,
    NPC_Duplighost      = 2,
};

#define NAMESPACE kpa_53

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_ExitDoors_kpa_83_0);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
