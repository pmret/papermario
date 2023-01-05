/// @file dgb_15.h
/// @brief Tubba's Castle - West Hall (3F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../dgb.h"
#include "mapfs/dgb_15_shape.h"
#include "mapfs/dgb_15_hit.h"

#include "sprite/npc/WorldTubba.h"

enum {
    NPC_Tubba       = 0,
};

enum {
    MV_PadlockEntityID  = MapVar(0),
};

#define NAMESPACE dgb_15

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_UnlockPrompt_Door);
extern EvtScript N(EVS_ExitDoors_dgb_17_0);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
