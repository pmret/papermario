// Older version of kzn_22

#include "dead.h"
#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kzn.h"
#include "mapfs/kzn_22_shape.h"
#include "mapfs/kzn_22_hit.h"

enum {
    NPC_Kolorado    = 0,
    NPC_Misstar     = 1,
};

#define NAMESPACE dead_kzn_22

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
