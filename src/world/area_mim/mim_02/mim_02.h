/// @file mim_02.h
/// @brief Forever Forest - Stump Eyes

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mim.h"
#include "mapfs/mim_02_shape.h"
#include "mapfs/mim_02_hit.h"

#include "sprite/npc/Oaklie.h"
#include "sprite/npc/Fuzzy.h"

enum {
    NPC_Oaklie                  = 0,
    NPC_Fuzzy_01                = 1,
    NPC_Fuzzy_02                = 2,
};

#define NAMESPACE mim_02

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupGates);
extern EvtScript N(EVS_SetupExitHint);
extern EvtScript N(EVS_EnableWestGate);
extern NpcGroupList N(DefaultNPCs);
