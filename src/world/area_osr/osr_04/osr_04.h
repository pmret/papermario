/// @file osr_04.h
/// @brief Peach's Castle Grounds - Castle Hijacking Scene

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../osr.h"
#include "mapfs/osr_03_shape.h"
#include "mapfs/osr_03_hit.h"

enum {
    MV_SmokeVelY        = MapVar(1),
    MV_CastleLiftDist   = MapVar(14),
};

#define NAMESPACE osr_04

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_Scene_BowsersAssault);
