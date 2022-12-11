/// @file flo_09.h
/// @brief Flower Fields - (East) Triple Tree Path

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_09_shape.h"
#include "mapfs/flo_09_hit.h"

#include "sprite/npc/Dayzee.h"
#include "sprite/npc/Bzzap.h"

enum {
    NPC_Dayzee_01               = 0,
    NPC_Dayzee_02               = 1,
    NPC_Bzzap_01                = 2,
    NPC_Bzzap_02                = 3,
};

#define NAMESPACE flo_09

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_SetupVines);
extern NpcGroupList N(DefaultNPCs);
