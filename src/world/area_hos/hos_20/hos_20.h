/// @file hos_20.h
/// @brief Shooting Star Summit - Riding Star Ship Scene

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../hos.h"
#include "mapfs/hos_20_shape.h"
#include "mapfs/hos_20_hit.h"

enum {
    MV_Starship_PosX    = MapVar(10),
    MV_Starship_Yaw     = MapVar(11),
};

#define NAMESPACE hos_20

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_Starship_Flight1);
extern EvtScript N(EVS_Starship_Flight2);
extern EvtScript N(EVS_Starship_Return);
