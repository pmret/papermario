/// @file dgb_06.h
/// @brief Tubba's Castle - Basement

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../dgb.h"
#include "mapfs/dgb_06_shape.h"
#include "mapfs/dgb_06_hit.h"

enum {
    NPC_Boo     = 0,
};

#define NAMESPACE dgb_06

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
