/// @file jan_10.h
/// @brief Jade Jungle - Western Dead End

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../jan.h"
#include "mapfs/jan_10_shape.h"
#include "mapfs/jan_10_hit.h"

enum {
    NPC_YoshiKid        = 0,
    NPC_JungleFuzzy     = 1,
};

enum {
    MF_KillLogShadow    = MapFlag(10),
};

#define NAMESPACE jan_10

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupLogs);
extern EvtScript N(EVS_SetupTrees);
extern EvtScript N(EVS_SetupBushes);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
