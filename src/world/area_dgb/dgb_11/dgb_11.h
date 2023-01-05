/// @file dgb_11.h
/// @brief Tubba's Castle - Covered Tables Room (1F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../dgb.h"
#include "mapfs/dgb_11_shape.h"
#include "mapfs/dgb_11_hit.h"

enum {
    MV_SpringEntityID   = MapVar(0),
};

#define NAMESPACE dgb_11

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
