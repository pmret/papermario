/// @file kpa_134.h
/// @brief Bowser's Castle - Right Water Puzzle

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_134_shape.h"
#include "mapfs/kpa_134_hit.h"

#include "sprite/npc/Toad.h"

enum {
    NPC_Dummy   = 0,
};

enum {
    MV_SwitchEntityID   = MapVar(0),
    MV_PadlockEntityID  = MapVar(1),
};

#define NAMESPACE kpa_134

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_ExitDoors_kpa_130_0);
extern EvtScript N(EVS_SetupChains);
extern EvtScript N(EVS_FlipWallPanels);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
