/// @file flo_08.h
/// @brief Flower Fields - (SE) Briar Platforming

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_08_shape.h"
#include "mapfs/flo_08_hit.h"

enum {
    NPC_GateFlower              = 0,
    NPC_Dayzee_01               = 1,
    NPC_Dayzee_02               = 2,
    NPC_Dayzee_03               = 3,
    NPC_Dayzee_04               = 4,
    NPC_Dayzee_05               = 5,
    NPC_Dayzee_06               = 6,
    NPC_Dayzee_07               = 7,
    NPC_AmazyDayzee             = 8,
};

enum {
    MV_SuperBlock               = MapVar(0),
};

#define NAMESPACE flo_08

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_SetupVines);
extern NpcGroupList N(DefaultNPCs);
