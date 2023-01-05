/// @file dgb_13.h
/// @brief Tubba's Castle - Hidden Bedroom (2F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../dgb.h"
#include "mapfs/dgb_13_shape.h"
#include "mapfs/dgb_13_hit.h"

enum {
    MV_LowerDrawerOpen       = MapVar(0),
};

#define NAMESPACE dgb_13

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupDrawers);
extern EvtScript N(EVS_MakeEntities);
