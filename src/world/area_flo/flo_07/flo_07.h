/// @file flo_07.h
/// @brief Flower Fields - (SW) Posie and Crystal Tree

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_07_shape.h"
#include "mapfs/flo_07_hit.h"

enum {
    NPC_Posie   = 0,
};

enum {
    MV_GroundShakingScript  = MapVar(0),
};

#define NAMESPACE flo_07

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PushFlowerSong);
extern EvtScript N(EVS_PopSong);
extern EvtScript N(EVS_Scene_SunReturns);
extern EvtScript N(EVS_TryKickingPlayerOut);
extern EvtScript N(EVS_SetupFoliage);

extern NpcGroupList N(DefaultNPCs);
