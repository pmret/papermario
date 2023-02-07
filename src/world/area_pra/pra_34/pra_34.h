/// @file pra_34.h
/// @brief Crystal Palace - Mirror Hole Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../pra.h"
#include "mapfs/pra_34_shape.h"
#include "mapfs/pra_34_hit.h"

enum {
    MV_FarPadlockEntityID   = MapVar(0),
    MV_NearPadlockEntityID  = MapVar(1),
};

#define NAMESPACE pra_34

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_ExitDoors_pra_31_0);
extern EvtScript N(EVS_ExitDoors_pra_31_2);
extern EvtScript N(EVS_MakeEntities);
