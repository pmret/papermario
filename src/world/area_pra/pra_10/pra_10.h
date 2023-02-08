/// @file pra_10.h
/// @brief Crystal Palace - P-Down, D-Up Hall

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../pra.h"
#include "mapfs/pra_10_shape.h"
#include "mapfs/pra_10_hit.h"

enum {
    NPC_Swoopula_01     = 0,
    NPC_Swoopula_02     = 1,
};

#define NAMESPACE pra_10

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
