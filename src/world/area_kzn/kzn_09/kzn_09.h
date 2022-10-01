/// @file kzn_09.h
/// @brief Mt Lavalava - Zipline Cavern

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kzn.h"
#include "mapfs/kzn_09_shape.h"
#include "mapfs/kzn_09_hit.h"

#include "sprite/npc/BuzzyBeetle.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/Kolorado.h"
#include "sprite/npc/SpikeTop.h"
#include "sprite/npc/LargePiranha.h"

enum {
    NPC_Kolorado                = 0,
    NPC_ZiplineDummy            = 1,    // used to give the zipline a shadow
    NPC_SpikeTop                = 2,
    NPC_Piranha                 = 3,
    NPC_Piranha_Hitbox          = 4,
};

enum {
    MV_SuperBlock               = MapVar(0),
};

enum {
    MF_Zipline_GoingDown        = MapFlag(10),
    MF_Zipline_GoingUp          = MapFlag(11),
};

#define NAMESPACE kzn_09
