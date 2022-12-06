/// @file flo_12.h
/// @brief Flower Fields - (West) Rosie's Trellis

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_12_shape.h"
#include "mapfs/flo_12_hit.h"

enum {
    NPC_Rosie       = 0,
    NPC_Dummy       = 1,
};

#define NAMESPACE flo_12

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PushFlowerSong);
extern EvtScript N(EVS_PopMusic);
extern EvtScript N(EVS_Scene_SunReturns);
extern NpcGroupList N(DefaultNPCs);
