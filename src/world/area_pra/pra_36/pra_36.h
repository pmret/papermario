/// @file pra_36.h
/// @brief Crystal Palace - Palace Key Hall

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../pra.h"
#include "mapfs/pra_10_shape.h"
#include "mapfs/pra_10_hit.h"

#include "sprite/npc/Duplighost.h"

enum {
    NPC_Duplighost  = 0,
};

#define NAMESPACE pra_36

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
