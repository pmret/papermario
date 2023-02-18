// Older version of flo_15

#include "dead.h"
#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_15_shape.h"
#include "mapfs/flo_15_hit.h"

#include "sprite/npc/Sun.h"

enum {
    NPC_Sun_01                  = 10,
    NPC_Sun_02                  = 11,
};

#define NAMESPACE dead_flo_15

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_MonitorFallingStairs);
extern EvtScript N(EVS_Scene_SunReturns);
extern NpcGroupList N(DefaultNPCs);
