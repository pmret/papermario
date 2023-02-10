/// @file jan_05.h
/// @brief Jade Jungle - SE Jungle (Quake Hammer)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../jan.h"
#include "mapfs/jan_05_shape.h"
#include "mapfs/jan_05_hit.h"

enum {
    NPC_JungleFuzzy         = 0,
    NPC_SpearGuy            = 1,
    NPC_SpearGuy_Hitbox     = 2,
    NPC_YoshiKid            = 3,
    NPC_HeartPlant          = 4,
    NPC_HurtPlant           = 5,
    NPC_MBush               = 6,
};

enum {
    MV_BushOffsetL      = MapVar(0),
    MV_BushOffsetR      = MapVar(1),
};

enum {
    MF_BushDrop_Coin    = MapFlag(10),
    MF_KillLogShadow    = MapFlag(11),
};

#define NAMESPACE jan_05

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupLogs);
extern EvtScript N(EVS_SetupTrees);
extern EvtScript N(EVS_SetupBushes);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList N(DefaultNPCs);
