/// @file sbk_20.h
/// @brief Dry Dry Desert - N1W3 Special Block

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../sbk.h"
#include "mapfs/sbk_20_shape.h"
#include "mapfs/sbk_20_hit.h"

#include "sprite/npc/Bandit.h"

enum {
    NPC_Bandit_01       = 0,
    NPC_Bandit_02       = 1,
};

enum {
    MV_BlockHitCounter  = MapVar(0),
};

#define NAMESPACE sbk_20
