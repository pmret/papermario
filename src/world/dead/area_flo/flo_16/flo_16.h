// Older version of flo_16

#include "dead.h"
#include "common.h"
#include "dead_structs.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_16_shape.h"
#include "mapfs/flo_16_hit.h"

#include "sprite/npc/TuffPuff.h"

enum {
    NPC_TuffPuff_01     = 0,
    NPC_TuffPuff_02     = 1,
};

enum {
    MV_SuperBlock       = MapVar(0),
};

#define NAMESPACE dead_flo_16

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupVines);
extern EvtScript N(EVS_SetupPillarPuzzle);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList N(DefaultNPCs);
