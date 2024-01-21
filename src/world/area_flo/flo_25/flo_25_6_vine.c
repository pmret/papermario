#include "flo_25.h"

// unused extra import for flower-spawning regions
#define NAMESPACE flo_25_vines
#include "../common/FlowerSpawnRegion.inc.c"
#define NAMESPACE flo_25

#include "../common/DroppingVine.inc.c"

EvtScript N(EVS_SetupVines) = {
    EVT_DROPPING_VINE(ITEM_NONE, MODEL_o111, MODEL_o112, MODEL_o113, MODEL_o114)
    EVT_DROPPING_VINE(ITEM_NONE, MODEL_o101, MODEL_o102, MODEL_o103, MODEL_o104)
    EVT_DROPPING_VINE(ITEM_STINKY_HERB, MODEL_o105, MODEL_o106, MODEL_o107, MODEL_o108)
    EVT_DROPPING_VINE(ITEM_NONE, MODEL_o130, MODEL_o131, MODEL_o132, MODEL_o133)
    Return
    End
};
