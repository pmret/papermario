/// @file pra_29.h
/// @brief Crystal Palace - Hidden Bridge Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../pra.h"
#include "mapfs/pra_29_shape.h"
#include "mapfs/pra_29_hit.h"

enum {
    MV_BridgeExtendAmt      = MapVar(0),
    MV_UnusedBridgeAlpha    = MapVar(1),
};

#define NAMESPACE pra_29

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupBridge);
extern EvtScript N(EVS_MakeEntities);
