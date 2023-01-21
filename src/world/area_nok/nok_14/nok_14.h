/// @file nok_14.h
/// @brief Koopa Region - Path to Fortress 1

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../nok.h"
#include "mapfs/nok_14_shape.h"
#include "mapfs/nok_14_hit.h"

enum {
    NPC_KoopaTroopa_01          = 0,
    NPC_SpikedGoomba            = 2,
    NPC_ParaTroopa              = 3,
    NPC_KoopaTroopa_02          = 4,
};

enum {
    MV_Item_ThunderBolt         = MapVar(0),
};

#define NAMESPACE nok_14

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupBridge);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
