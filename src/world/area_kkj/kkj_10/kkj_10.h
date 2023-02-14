/// @file kkj_10.h
/// @brief Peach's Castle - Entry Hall (1F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kkj.h"
#include "mapfs/kkj_10_shape.h"
#include "mapfs/kkj_10_hit.h"

enum {
    NPC_Koopatrol_01    = 0,
    NPC_Koopatrol_02    = 1,
};

enum {
    MV_PadlockEntityIdx = MapVar(0),
};

#define NAMESPACE kkj_10

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_ExitDoors_osr_02_1);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList N(EarlyNPCs);
extern NpcGroupList N(LaterNPCs);
