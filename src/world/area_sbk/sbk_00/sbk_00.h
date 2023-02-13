/// @file sbk_00.h
/// @brief Dry Dry Desert - N3W3

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../sbk.h"
#include "mapfs/sbk_00_shape.h"
#include "mapfs/sbk_00_hit.h"

#include "sprite/npc/Pokey.h"

enum {
    NPC_Pokey_01                = 0,
    NPC_Pokey_02                = 1,
};

#define NAMESPACE sbk_00

extern EvtScript N(EVS_Main);
extern NpcGroupList N(DefaultNPCs);
extern EvtScript N(EVS_MakeEntities);
