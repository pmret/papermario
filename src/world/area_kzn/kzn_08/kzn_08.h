/// @file kzn_08.h
/// @brief Mt Lavalava - Dizzy Stomp Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kzn.h"
#include "mapfs/kzn_08_shape.h"
#include "mapfs/kzn_08_hit.h"

#include "sprite/npc/LargePiranha.h"

enum {
    NPC_PutridPiranha       = 0,
    NPC_Piranha_Hitbox      = 1
};

enum {
    MV_GlowIntensity        = MapVar(0),
};

#define NAMESPACE kzn_08
