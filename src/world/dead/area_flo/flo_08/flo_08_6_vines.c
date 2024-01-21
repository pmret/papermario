#include "flo_08.h"

// unused extra import for flower-spawning regions
#define NAMESPACE dead_flo_08_vines
#include "world/area_flo/common/FlowerSpawnRegion.inc.c"
#define NAMESPACE dead_flo_08

#include "world/area_flo/common/DroppingVine.inc.c"

EvtScript N(EVS_SetupVines) = {
    EVT_DROPPING_VINE(ITEM_NONE, MODEL_o78, MODEL_o79, MODEL_o80, MODEL_o81)
    EVT_DROPPING_VINE(ITEM_NONE, MODEL_o82, MODEL_o83, MODEL_o84, MODEL_o85)
    EVT_DROPPING_VINE(ITEM_NONE, MODEL_o88, MODEL_o89, MODEL_o90, MODEL_o91)
    EVT_DROPPING_VINE(ITEM_STINKY_HERB, MODEL_o159, MODEL_o158, MODEL_o160, MODEL_o161)
    Return
    End
};
