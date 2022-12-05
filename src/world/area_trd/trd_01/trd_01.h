/// @file trd_01.h
/// @brief Koopa Bros Fortress - Left Tower

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../trd.h"
#include "mapfs/trd_01_shape.h"
#include "mapfs/trd_01_hit.h"

#include "sprite/npc/KoopaTroopa.h"
#include "sprite/npc/Bobomb.h"

enum {
    NPC_KoopaTroopa_01              = 0,
    NPC_KoopaTroopa_02              = 1,
    NPC_KoopaTroopa_03              = 2,
    NPC_Bobomb                      = 3,
};

enum {
    MV_Padlock_EntityIndex          = MapVar(0),
};

enum {
    NPC_KoopaTroopa_02_DonePanic    = MapFlag(10),
    NPC_KoopaTroopa_03_DonePanic    = MapFlag(11),
};

#define NAMESPACE trd_01
