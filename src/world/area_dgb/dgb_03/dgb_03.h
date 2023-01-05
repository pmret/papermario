/// @file dgb_03.h
/// @brief Tubba's Castle - Table/Clock Room (1/2F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../dgb.h"
#include "mapfs/dgb_03_shape.h"
#include "mapfs/dgb_03_hit.h"

enum {
    NPC_Clubba_Wander           = 0,
    NPC_Clubba_Wander_Hitbox    = 1,
    NPC_Clubba_Patrol           = 2,
    NPC_Clubba_Patrol_Hitbox    = 3,
    NPC_Clubba_Napping          = 4,
    NPC_Clubba_Napping_Hitbox   = 5,
};

enum {
    MV_PadlockEntityID      = MapVar(0),
};

#define NAMESPACE dgb_03

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_ExitDoors_dgb_14_0);
extern EvtScript N(EVS_UnlockPrompt_UpperDoor);
extern EvtScript N(EVS_SetupClock);
extern NpcGroupList N(DefaultNPCs);
