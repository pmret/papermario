/// @file kpa_63.h
/// @brief Bowser's Castle - Hanger

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_63_shape.h"
#include "mapfs/kpa_63_hit.h"

enum {
    MV_Starship_PosY    = MapVar(10),
    MV_Starship_Yaw     = MapVar(11),
    MV_PlayerOnBoard    = MapVar(12),
    MV_PartnerOnBoard   = MapVar(13),
};

#define NAMESPACE kpa_63

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_Starship_Arrive);
extern EvtScript N(EVS_Starship_Depart);
extern EvtScript N(EVS_SetupStarship);
extern EvtScript N(EVS_MakeEntities);
