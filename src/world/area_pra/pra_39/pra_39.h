/// @file pra_39.h
/// @brief Crystal Palace - Shooting Star Hall

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../pra.h"
#include "mapfs/pra_10_shape.h"
#include "mapfs/pra_10_hit.h"

#include "sprite/npc/Duplighost.h"

enum {
    NPC_Duplighost      = 0,
};

#define NAMESPACE pra_39

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
