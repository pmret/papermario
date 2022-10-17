/// @file kzn_01.h
/// @brief Mt Lavalava - Volcano Entrance

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kzn.h"
#include "mapfs/kzn_01_shape.h"
#include "mapfs/kzn_01_hit.h"

enum {
    NPC_PutridPiranha   = 0,
};

#define NAMESPACE kzn_01

extern EvtScript N(EVS_Main);
extern NpcGroupList N(DefaultNPCs);
