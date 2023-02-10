/// @file jan_08.h
/// @brief Jade Jungle - SW Jungle (Super Block)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../jan.h"
#include "mapfs/jan_08_shape.h"
#include "mapfs/jan_08_hit.h"

enum {
    NPC_SpearGuy            = 0,
    NPC_SpearGuy_Hitbox     = 1,
    NPC_HurtPlant           = 2,
    NPC_MBush_01            = 3,
    NPC_MBush_02            = 4,
    NPC_HeartPlant_01       = 5,
    NPC_HeartPlant_02       = 6,
    NPC_YoshiKid            = 7,
};

enum {
    MV_Unk_00       = MapVar(0),
    MV_Unk_01       = MapVar(1),
    MV_SuperBlock   = MapVar(2),
};

#define NAMESPACE jan_08

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupBushes);
extern EvtScript N(EVS_SetupTrees);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
