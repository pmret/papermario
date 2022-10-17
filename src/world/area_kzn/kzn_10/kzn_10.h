/// @file kzn_10.h
/// @brief Mt Lavalava - Descent Toward Boss

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kzn.h"
#include "mapfs/kzn_10_shape.h"
#include "mapfs/kzn_10_hit.h"

enum {
    MV_TrompPosX        = MapVar(0),
    MV_ScreenShakeTID   = MapVar(10),
};

#define NAMESPACE kzn_10

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupSpinyTromp);
