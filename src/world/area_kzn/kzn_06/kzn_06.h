/// @file kzn_06.h
/// @brief Mt Lavalava - Flowing Lava Puzzle

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kzn.h"
#include "mapfs/kzn_06_shape.h"
#include "mapfs/kzn_06_hit.h"

enum {
    MV_GlowIntensity        = MapVar(0),
};

#define NAMESPACE kzn_06

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupLavaPuzzle);
