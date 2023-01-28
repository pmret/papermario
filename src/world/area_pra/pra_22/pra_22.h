/// @file pra_22.h
/// @brief Crystal Palace - Small Statue Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../pra.h"
#include "mapfs/pra_22_shape.h"
#include "mapfs/pra_22_hit.h"

enum {
    MV_PlayerFloor  = MapVar(0),
};

#define NAMESPACE pra_22

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
