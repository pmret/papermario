/// @file jan_11.h
/// @brief Jade Jungle - Root Cavern

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../jan.h"
#include "mapfs/jan_11_shape.h"
#include "mapfs/jan_11_hit.h"

#include "sprite/npc/YoshiKid.h"

enum {
    NPC_YoshiKid    = 0,
};

#define NAMESPACE jan_11

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
