/// @file trd_02.h
/// @brief Koopa Bros Fortress - Left Stairway

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../trd.h"
#include "mapfs/trd_02_shape.h"
#include "mapfs/trd_02_hit.h"

#include "sprite/npc/Bobomb.h"
#include "sprite/npc/KoopaTroopa.h"

enum {
    NPC_Bobomb_01               = 0,
    NPC_Bobomb_02               = 1,
    NPC_KoopaTroopa             = 2,
};

enum {
    MV_Padlock_EntityIndex      = MapVar(0),
};

#define NAMESPACE trd_02
