/// @file pra_33.h
/// @brief Crystal Palace - Turnstyle Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../pra.h"
#include "mapfs/pra_33_shape.h"
#include "mapfs/pra_33_hit.h"

enum {
    MV_WallFlipped  = MapVar(0),
};

#define NAMESPACE pra_33

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
