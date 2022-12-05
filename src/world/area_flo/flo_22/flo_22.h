/// @file flo_22.h
/// @brief Flower Fields - (East) Old Well

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_22_shape.h"
#include "mapfs/flo_22_hit.h"

#include "sprite/npc/Bzzap.h"
#include "sprite/npc/Dayzee.h"

enum {
    NPC_Dummy   = 0, // reused as a dummy for tossing badge out of the well
    NPC_Bzzap   = 0,
    NPC_Dayzee  = 1,
};

enum {
    MV_Bzzap_State      = MapVar(10),
    MV_Dayzee_State     = MapVar(11),
};

#define NAMESPACE flo_22

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_SetupWell);
extern EvtScript N(EVS_SniffleHint);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
