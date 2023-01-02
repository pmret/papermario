/// @file kpa_91.h
/// @brief Bowser's Castle - East Upper Jail

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_91_shape.h"
#include "mapfs/kpa_91_hit.h"

#include "sprite/npc/ToadGuard.h"

enum {
    NPC_Toad_01         = 0,
    NPC_Toad_02         = 1,
    NPC_ToadGuard       = 2,
    NPC_Dryite          = 3,
    NPC_Koopatrol       = 4,
};

enum {
    MV_PadlockEntityID  = MapVar(0),
    MV_LastPlayerPosX   = MapVar(1),
    MV_LastPlayerPosY   = MapVar(2),
    MV_LastPlayerPosZ   = MapVar(3),
};

#define NAMESPACE kpa_91

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_OpenCellDoor);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
