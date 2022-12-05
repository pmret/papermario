/// @file trd_03.h
/// @brief Koopa Bros Fortress - Central Hall

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../trd.h"
#include "mapfs/trd_03_shape.h"
#include "mapfs/trd_03_hit.h"

#include "sprite/npc/KoopaBros.h"
#include "sprite/npc/KoopaTroopa.h"

enum {
    NPC_KoopaBros               = 0,
    NPC_KoopaTroopa_01          = 10,
    NPC_KoopaTroopa_02          = 11,
    NPC_KoopaTroopa_03          = 12,
};

enum {
    MV_PlatformsExtended        = MapVar(0),
};

#define NAMESPACE trd_03
