/// @file kzn_17.h
/// @brief Mt Lavalava - Spike Roller Trap

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kzn.h"
#include "mapfs/kzn_17_shape.h"
#include "mapfs/kzn_17_hit.h"

enum {
    NPC_Kolorado                = 0,
    NPC_Piranha                 = 1,
    NPC_Piranha_Hitbox          = 2,
    NPC_SpikeTop                = 3,
};

enum {
    MV_TrompPosX                = MapVar(0),
    MV_ScreenShakeTID           = MapVar(10),
};

#define NAMESPACE kzn_17

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupSpinyTromp);
extern EvtScript N(EVS_Kolorado_TrompPanic);
extern EvtScript N(EVS_Kolorado_TrompImpact);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
