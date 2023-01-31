/// @file hos_04.h
/// @brief Shooting Star Summit - Outside the Sanctuary

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../hos.h"
#include "mapfs/hos_04_shape.h"
#include "mapfs/hos_04_hit.h"

#include "sprite/npc/Twink.h"

enum {
    NPC_Twink   = 0,
};

enum {
    MV_Starship_PosX    = MapVar(10),
    MV_Starship_PosY    = MapVar(11),
    MV_Starship_PosZ    = MapVar(12),
    MV_Starship_Yaw     = MapVar(13),
};

#define NAMESPACE hos_04

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_Starship_FlyingAway);
extern EvtScript N(EVS_SetupNarrator);
extern EvtScript N(EVS_Intro_PreHeist_Unused);
extern EvtScript N(EVS_Intro_PostHeist);
extern EvtScript N(EVS_SetupFountains);
extern EvtScript N(EVS_BetaStarship_Flight1);
extern EvtScript N(EVS_BetaStarship_Flight2);
extern EvtScript N(EVS_BetaStarship_Return);
extern NpcGroupList N(DefaultNPCs);
