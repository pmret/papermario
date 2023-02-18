// Older version of kzn_18

#include "dead.h"
#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kzn.h"
#include "mapfs/kzn_18_shape.h"
#include "mapfs/kzn_18_hit.h"

enum {
    NPC_Kolorado                = 0,
    NPC_PutridPiranha           = 1,
};

enum {
    MV_KoloradoJumpDone         = MapVar(10),
};

#define NAMESPACE dead_kzn_18
