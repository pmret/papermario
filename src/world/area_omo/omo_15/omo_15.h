/// @file omo_15.h
/// @brief Shy Guy's Toybox - RED General Guy Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../omo.h"
#include "mapfs/omo_15_shape.h"
#include "mapfs/omo_15_hit.h"

#include "sprite/npc/GeneralGuy.h"

enum {
    NPC_GeneralGuy      = 0,
    NPC_ShyGuy_01       = 1,
    NPC_ShyGuy_02       = 2,
    NPC_ShyGuy_03       = 3,
    NPC_ShyGuy_04       = 4,
    NPC_ShyGuy_05       = 5,
    NPC_ShyGuy_06       = 6,
    NPC_ShyGuy_07       = 7,
    NPC_ShyGuy_08       = 8,
    NPC_ShyGuy_09       = 9,
};

enum {
    MV_Unk_01           = MapVar(1),
};

#define NAMESPACE omo_15

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_TrySpawningStarCard);
extern NpcGroupList N(DefaultNPCs);
