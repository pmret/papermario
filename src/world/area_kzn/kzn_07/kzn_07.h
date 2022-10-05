/// @file kzn_07.h
/// @brief Mt Lavalava - Ultra Hammer Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kzn.h"
#include "mapfs/kzn_07_shape.h"
#include "mapfs/kzn_07_hit.h"

#include "sprite/npc/LavaBubble.h"

enum {
    NPC_Bubble_01               = 0,
    NPC_Bubble_02               = 1,
};

// map variables
enum {
    MV_GlowIntensity        = MapVar(0),
};

#define NAMESPACE kzn_07
