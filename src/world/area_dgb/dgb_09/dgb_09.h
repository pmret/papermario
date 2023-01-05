/// @file dgb_09.h
/// @brief Tubba's Castle - West Hall (2F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../dgb.h"
#include "mapfs/dgb_09_shape.h"
#include "mapfs/dgb_09_hit.h"

enum {
    NPC_Clubba_Wander           = 0,
    NPC_Clubba_Wander_Hitbox    = 1,
    NPC_Clubba_Napping          = 2,
    NPC_Clubba_Napping_Hitbox   = 3,
    NPC_Sentinel                = 4,
};

#define NAMESPACE dgb_09

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupBreakable);
extern NpcGroupList N(DefaultNPCs);
