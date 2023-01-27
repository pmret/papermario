/// @file pra_21.h
/// @brief Crystal Palace - Huge Statue Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../pra.h"
#include "mapfs/pra_21_shape.h"
#include "mapfs/pra_21_hit.h"

enum {
    MV_PlayerFloor  = MapVar(0),
};

#define NAMESPACE pra_21

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
