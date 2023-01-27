/// @file pra_03.h
/// @brief Crystal Palace - Save Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../pra.h"
#include "mapfs/pra_03_shape.h"
#include "mapfs/pra_03_hit.h"

enum {
    MV_PlayerFloor  = MapVar(0),
};

#define NAMESPACE pra_03

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
