/// @file kkj_11.h
/// @brief Peach's Castle - Upper Hall (2F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kkj.h"
#include "mapfs/kkj_11_shape.h"
#include "mapfs/kkj_11_hit.h"

#include "sprite/npc/WorldKoopatrol.h"

enum {
    NPC_Koopatrol_01        = 0,
    NPC_Koopatrol_02        = 1,
    NPC_Koopatrol_03        = 2,
    NPC_Koopatrol_04        = 3,
    NPC_Koopatrol_05        = 4,
};

enum {
    MV_PadlockEntityIdx     = MapVar(0),
};

#define NAMESPACE kkj_11

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_PlayDemoScene);
extern EvtScript N(EVS_FirstTimeEnterHall);
extern EvtScript N(EVS_ExitDoors_kkj_10_1);
extern EvtScript N(EVS_ExitDoors_kkj_12_0);
extern EvtScript N(EVS_ExitDoor_kkj_14_0);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList N(EarlyNPCs);
extern NpcGroupList N(LaterNPCs);
