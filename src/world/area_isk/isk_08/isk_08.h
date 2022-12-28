/// @file isk_08.h
/// @brief Dry Dry Ruins - Descending Stairs 2

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../isk.h"
#include "mapfs/isk_08_shape.h"
#include "mapfs/isk_08_hit.h"

#include "sprite/npc/BuzzyBeetle.h"

enum {
    NPC_BuzzyBeetle     = 1,
};

#define NAMESPACE isk_08

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupFlames);
extern EvtScript N(EVS_SetupBombableWall);
extern NpcGroupList N(DefaultNPCs);
