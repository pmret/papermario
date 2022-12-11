/// @file mim_03.h
/// @brief Forever Forest - Flowers (Oaklie)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mim.h"
#include "mapfs/mim_03_shape.h"
#include "mapfs/mim_03_hit.h"

enum {
    NPC_Oaklie                  = 0,
};

#define NAMESPACE mim_03

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupExitHint);
extern EvtScript N(EVS_SetupGates);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
