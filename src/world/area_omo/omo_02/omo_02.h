/// @file omo_02.h
/// @brief Shy Guy's Toybox - RED Boss Barricade

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../omo.h"
#include "mapfs/omo_02_shape.h"
#include "mapfs/omo_02_hit.h"

#include "sprite/npc/ShyGuy.h"
#include "sprite/npc/SpyGuy.h"

enum {
    NPC_ShyGuy_01       = 0,
    NPC_ShyGuy_02       = 1,
    NPC_ShyGuy_03       = 2,
    NPC_ShyGuy_04       = 3,
    NPC_ShyGuy_05       = 4,
    NPC_ShyGuy_06       = 5,
    NPC_ShyGuy_07       = 6,
    NPC_ShyGuy_08       = 7,
    NPC_ShyGuy_09       = 8,
    NPC_ShyGuy_10       = 9,
    NPC_ShyGuy_11       = 10,
    NPC_SpyGuy          = 50,
    NPC_SpyGuy_Rock1    = 51,
    NPC_SpyGuy_Rock2    = 52,
    NPC_SpyGuy_Rock3    = 53,
    NPC_SpyGuy_Rock4    = 54,
};

enum {
    MV_Unk_0A           = MapVar(10),
};

#define NAMESPACE omo_02

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupGizmos);
extern EvtScript N(EVS_8024455C);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
