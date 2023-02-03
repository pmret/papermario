/// @file jan_02.h
/// @brief Jade Jungle - Village Cove

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../jan.h"
#include "mapfs/jan_02_shape.h"
#include "mapfs/jan_02_hit.h"

#include "sprite/npc/WorldSushie.h"

enum {
    NPC_YoshiLeader         = 0,
    NPC_YoshiCouncillor     = 1,
    NPC_Yoshi_01            = 2,
    NPC_Yoshi_02            = 3,
    NPC_Yoshi_03            = 4,
    NPC_ChuckQuizmo         = 5,
};

#define NAMESPACE jan_02

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupFoliage);
extern NpcGroupList N(DefaultNPCs);
