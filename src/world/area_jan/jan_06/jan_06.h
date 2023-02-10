/// @file jan_06.h
/// @brief Jade Jungle - NE Jungle (Raven Statue)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../jan.h"
#include "mapfs/jan_06_shape.h"
#include "mapfs/jan_06_hit.h"

#include "sprite/npc/HeartPlant.h"
#include "sprite/npc/HurtPlant.h"
#include "sprite/npc/JungleGuy.h"
#include "sprite/npc/Fuzzy.h"

enum {
    NPC_Fuzzy               = 0,
    NPC_SpearGuy            = 1,
    NPC_SpearGuy_Hitbox     = 2,
    NPC_HeartPlant          = 3,
    NPC_HurtPlant_01        = 4,
    NPC_HurtPlant_02        = 5,
};

enum {
    MV_JadeRavenItemIdx = MapVar(11),
};

enum {
    MF_TreeDrop_Coin    = MapFlag(10),
    MF_KillLogShadow    = MapFlag(11),
};

#define NAMESPACE jan_06

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupStatue);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_80246A14);
extern EvtScript N(EVS_SetupLogs);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList N(DefaultNPCs);
