/// @file pra_13.h
/// @brief Crystal Palace - Blue Mirror Hall 1

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../pra.h"
#include "mapfs/pra_13_shape.h"
#include "mapfs/pra_13_hit.h"

#include "sprite/npc/WorldBombette.h"
#include "sprite/npc/Duplighost.h"

enum {
    NPC_FakeMario           = 0,
    NPC_FakeBombette        = 1,
    NPC_Duplighost_01       = 2,
    NPC_Duplighost_02       = 3,
};

#define NAMESPACE pra_13

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
