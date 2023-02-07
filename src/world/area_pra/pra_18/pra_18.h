/// @file pra_18.h
/// @brief Crystal Palace - Bridge Mirror Hall

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../pra.h"
#include "mapfs/pra_18_shape.h"
#include "mapfs/pra_18_hit.h"

enum {
    NPC_Clubba_01       = 0,
    NPC_Clubba_02       = 1,
    NPC_Clubba_03       = 2,
    NPC_Clubba_01_Aux   = 3,
    NPC_Clubba_02_Aux   = 4,
    NPC_Clubba_03_Aux   = 5,
};

#define NAMESPACE pra_18

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_ExitDoors_pra_33_1);
extern NpcGroupList N(DefaultNPCs);
