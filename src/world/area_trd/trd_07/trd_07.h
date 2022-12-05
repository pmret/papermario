/// @file trd_07.h
/// @brief Koopa Bros Fortress - Dungeon Trap

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../trd.h"
#include "mapfs/trd_07_shape.h"
#include "mapfs/trd_07_hit.h"

#include "sprite/npc/KoopaTroopa.h"
#include "sprite/npc/ParaTroopa.h"

enum {
    NPC_KoopaTroopa             = 0,
    NPC_ParaTroopa_01           = 1,
    NPC_ParaTroopa_02           = 2,
};

enum {
    MV_EnterWalkScriptID        = MapVar(0),
    MV_DoorScaleZ               = MapVar(0), // reusing
    MV_DoorScaleY               = MapVar(1),
};

#define NAMESPACE trd_07
