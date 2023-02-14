/// @file trd_10.h
/// @brief Koopa Bros Fortress - Boss Battle Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../trd.h"
#include "mapfs/trd_10_shape.h"
#include "mapfs/trd_10_hit.h"

#include "sprite/npc/KoopaBros.h"

enum {
    NPC_KoopaBros_01            = 0,
    NPC_KoopaBros_02            = 1,
    NPC_KoopaBros_03            = 2,
    NPC_KoopaBros_04            = 3,
};

enum {
    MV_Unk_01               = MapVar(1),
};

#define NAMESPACE trd_10
