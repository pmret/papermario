/// @file omo_13.h
/// @brief Shy Guy's Toybox - BLU Anti-Guy Hall

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../omo.h"
#include "mapfs/omo_13_shape.h"
#include "mapfs/omo_13_hit.h"

#include "sprite/npc/ShyGuy.h"
#include "sprite/npc/GrooveGuy.h"

enum {
    NPC_AntiGuy     = 0,
    NPC_ShyGuy      = 1,
    NPC_GrooveGuy   = 2,
};

#define NAMESPACE omo_13

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupGizmos);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
