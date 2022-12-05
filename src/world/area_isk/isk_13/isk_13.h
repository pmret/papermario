/// @file isk_13.h
/// @brief Dry Dry Ruins - Lunar Stone Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../isk.h"
#include "mapfs/isk_13_shape.h"
#include "mapfs/isk_13_hit.h"

#include "sprite/npc/StoneChomp.h"

enum {
    NPC_StoneChomp              = 1,
};

enum {
    MV_AmbushPtr        = MapVar(10),
};

#define NAMESPACE isk_13

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
