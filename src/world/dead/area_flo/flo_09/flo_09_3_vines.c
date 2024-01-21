#include "flo_09.h"

// unused extra import for flower-spawning regions
#define NAMESPACE dead_flo_09_vines
#include "world/area_flo/common/FlowerSpawnRegion.inc.c"
#define NAMESPACE dead_flo_09

#include "world/area_flo/common/DroppingVine.inc.c"

EvtScript N(EVS_SetupVines) = {
    EVT_DROPPING_VINE(ITEM_NONE, MODEL_o76, MODEL_o77, MODEL_o78, MODEL_o79)
    EVT_DROPPING_VINE(ITEM_STINKY_HERB, MODEL_o72, MODEL_o73, MODEL_o74, MODEL_o75)
    EVT_DROPPING_VINE(ITEM_NONE, MODEL_o80, MODEL_o81, MODEL_o82, MODEL_o83)
    EVT_DROPPING_VINE(ITEM_NONE, MODEL_o84, MODEL_o85, MODEL_o86, MODEL_o87)
    EVT_DROPPING_VINE(ITEM_NONE, MODEL_o96, MODEL_o97, MODEL_o98, MODEL_o99)
    EVT_DROPPING_VINE(ITEM_NONE, MODEL_o92, MODEL_o93, MODEL_o94, MODEL_o95)
    Return
    End
};
