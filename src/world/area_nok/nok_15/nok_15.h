/// @file nok_15.h
/// @brief Koopa Region - Path to Fortress 2

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../nok.h"
#include "mapfs/nok_15_shape.h"
#include "mapfs/nok_15_hit.h"

enum {
    NPC_KoopaTroopa             = 0,
    NPC_ParaTroopa              = 1,
};

enum {
    MF_TreeDrop_StarPiece   = MapFlag(10),
};

#define NAMESPACE nok_15

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
