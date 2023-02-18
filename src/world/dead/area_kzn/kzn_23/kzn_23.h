// Older version of kzn_23

#include "dead.h"
#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kzn.h"
#include "mapfs/kzn_23_shape.h"
#include "mapfs/kzn_23_hit.h"

enum {
    NPC_Kolorado    = 0,
    NPC_Misstar     = 1,
};

enum {
    MV_LavaLevel    = MapVar(10),
};

#define NAMESPACE dead_kzn_23

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
