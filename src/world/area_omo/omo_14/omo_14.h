/// @file omo_14.h
/// @brief Shy Guy's Toybox - RED Boss Antechamber

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../omo.h"
#include "mapfs/omo_14_shape.h"
#include "mapfs/omo_14_hit.h"

#include "sprite/npc/ShyGuy.h"

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
};

enum {
    MV_ActingPartner    = MapVar(10),
};

#define NAMESPACE omo_14

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
