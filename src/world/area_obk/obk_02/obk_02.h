/// @file obk_02.h
/// @brief Boo's Mansion - Basement Stairs

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../obk.h"
#include "mapfs/obk_02_shape.h"
#include "mapfs/obk_02_hit.h"

#include "sprite/npc/Boo.h"

enum {
    NPC_Boo_01      = 0,
    NPC_Boo_02      = 1,
};

enum {
    MV_CurrentMapRegion = MapVar(0),
    MV_Unk_01       = MapVar(1),
};

#define NAMESPACE obk_02

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_UpdateClock);
extern EvtScript N(EVS_ClockDoNothing);
extern EvtScript N(EVS_SetupBombableWall);
extern NpcGroupList N(DefaultNPCs);
extern EvtScript N(EVS_MakeEntities);
