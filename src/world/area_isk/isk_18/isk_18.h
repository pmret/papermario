/// @file isk_18.h
/// @brief Dry Dry Ruins - Deep Tunnel

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../isk.h"
#include "mapfs/isk_18_shape.h"
#include "mapfs/isk_18_hit.h"

#include "sprite/npc/BuzzyBeetle.h"

enum {
    NPC_BuzzyBeetle_01          = 0,
    NPC_BuzzyBeetle_02          = 1,
    NPC_BuzzyBeetle_03          = 2,
};

#define NAMESPACE isk_18

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupFlames);
extern NpcGroupList N(DefaultNPCs);
