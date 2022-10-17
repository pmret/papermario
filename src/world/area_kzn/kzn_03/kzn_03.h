/// @file kzn_03.h
/// @brief Mt Lavalava - Central Cavern

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kzn.h"
#include "mapfs/kzn_03_shape.h"
#include "mapfs/kzn_03_hit.h"

enum {
    NPC_Kolorado                = 0,
    NPC_ZiplineDummy1           = 1,
    NPC_ZiplineDummy2           = 2,
    NPC_SpikeTop_01             = 3,
    NPC_SpikeTop_02             = 4,
    NPC_SpikeTop_03             = 5,
    NPC_Piranha                 = 6,
    NPC_Piranha_Hitbox          = 7,
};

enum {
    MV_PlayerCliffState         = MapVar(9)
};

enum {
    MF_RidingZipline1           = MapFlag(10),
    MF_RidingZipline2           = MapFlag(11),
};

#define NAMESPACE kzn_03

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupZiplines);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SyncZiplineDummyNPC1);
extern EvtScript N(EVS_SyncZiplineDummyNPC2);
extern NpcGroupList N(DefaultNPCs);
