/// @file obk_05.h
/// @brief Boo's Mansion - Pot Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../obk.h"
#include "mapfs/obk_05_shape.h"
#include "mapfs/obk_05_hit.h"

#include "sprite/npc/Boo.h"

enum {
    NPC_Boo_01      = 0,
    NPC_Boo_02      = 1,
};

enum {
    MF_IsRetroMario     = MapFlag(10),
};

#define NAMESPACE obk_05

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupRockingChairs);
extern EvtScript N(EVS_ManageHole);
extern NpcGroupList N(DefaultNPCs);
extern EvtScript N(EVS_MakeEntities);
