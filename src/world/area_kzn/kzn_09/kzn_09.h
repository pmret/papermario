/// @file kzn_09.h
/// @brief Mt Lavalava - Zipline Cavern

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kzn.h"
#include "mapfs/kzn_09_shape.h"
#include "mapfs/kzn_09_hit.h"

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

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupZipline);
extern EvtScript N(EVS_SyncZiplineDummyNPC);
extern NpcGroupList N(DefaultNPCs);
