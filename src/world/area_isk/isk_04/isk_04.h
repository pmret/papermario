/// @file isk_04.h
/// @brief Dry Dry Ruins - Descending Stairs 1

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../isk.h"
#include "mapfs/isk_04_shape.h"
#include "mapfs/isk_04_hit.h"

#include "sprite/npc/BuzzyBeetle.h"

enum {
    NPC_BuzzyBeetle_01          = 0,
    NPC_BuzzyBeetle_02          = 1,
};

enum {
    MV_RuinsLockEntityID        = MapVar(0),
};

#define NAMESPACE isk_04

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupObstructions);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupDemo);
extern NpcGroupList N(DefaultNPCs);
