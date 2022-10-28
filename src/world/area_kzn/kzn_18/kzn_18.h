/// @file kzn_18.h
/// @brief Mt Lavalava - Boss Antechamber

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

#define NAMESPACE kzn_18
