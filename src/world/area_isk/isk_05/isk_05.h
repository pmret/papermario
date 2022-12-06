/// @file isk_05.h
/// @brief Dry Dry Ruins - Pyramid Stone Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../isk.h"
#include "mapfs/isk_05_shape.h"
#include "mapfs/isk_05_hit.h"

#include "sprite/npc/StoneChomp.h"

enum {
    NPC_StoneChomp              = 1,
};

#define NAMESPACE isk_05

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
