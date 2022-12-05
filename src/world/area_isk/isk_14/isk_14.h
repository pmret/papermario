/// @file isk_14.h
/// @brief Dry Dry Ruins - Diamond Stone Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../isk.h"
#include "mapfs/isk_14_shape.h"
#include "mapfs/isk_14_hit.h"

#include "sprite/npc/StoneChomp.h"

enum {
    NPC_StoneChomp              = 1,
};

#define NAMESPACE isk_14

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
