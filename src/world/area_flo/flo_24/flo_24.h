/// @file flo_24.h
/// @brief Flower Fields - (SE) Water Level Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_24_shape.h"
#include "mapfs/flo_24_hit.h"

#define NAMESPACE flo_24

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);

extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_SetupWater);
extern EvtScript N(EVS_Scene_FillWithWater);
