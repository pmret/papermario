/// @file pra_02.h
/// @brief Crystal Palace - Entry Hall

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../pra.h"
#include "mapfs/pra_02_shape.h"
#include "mapfs/pra_02_hit.h"

enum {
    MV_WallPosOffset    = MapVar(0),
    MV_NearRedPadlock   = MapVar(1),
    MV_FarRedPadlock    = MapVar(2),
    MV_NearBluePadlock  = MapVar(3),
    MV_FarBluePadlock   = MapVar(4),
};

#define NAMESPACE pra_02

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_ManagePoundableSwitch);
extern EvtScript N(EVS_UpdateShiftingWallPos);
extern EvtScript N(EVS_ExitDoors_pra_16_0);
extern EvtScript N(EVS_ExitDoors_pra_16_3);
extern EvtScript N(EVS_ExitDoors_pra_13_0);
extern EvtScript N(EVS_ExitDoors_pra_13_3);
extern EvtScript N(EVS_MakeEntities);
