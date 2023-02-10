/// @file jan_09.h
/// @brief Jade Jungle - NW Jungle (Large Ledge)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../jan.h"
#include "mapfs/jan_09_shape.h"
#include "mapfs/jan_09_hit.h"

enum {
    NPC_SpearGuy        = 30,
    NPC_SpearGuy_Hitbox = 31,
    NPC_MBush_01        = 70,
    NPC_MBush_02        = 80,
};

enum {
    MV_RightShoreBushOffsetL    = MapVar(0),
    MV_RightShoreBushOffsetR    = MapVar(1),
    MV_CliffTopBush1OffsetR     = MapVar(2),
    MV_CliffTopBush2OffsetL     = MapVar(3),
    MV_CliffTopBush2OffsetR     = MapVar(4),
    MV_Unk_05       = MapVar(5),
};

#define NAMESPACE jan_09

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupBushes);
extern EvtScript N(EVS_SetupTrees);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
