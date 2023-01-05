/// @file dgb_05.h
/// @brief Tubba's Castle - Stairs Above Basement

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../dgb.h"
#include "mapfs/dgb_05_shape.h"
#include "mapfs/dgb_05_hit.h"

enum {
    NPC_Clubba_01           = 0,
    NPC_Clubba_01_Hitbox    = 1,
    NPC_Clubba_02           = 3,
    NPC_Clubba_02_Hitbox    = 4,
};

#define NAMESPACE dgb_05

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupHole);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
