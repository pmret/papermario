/// @file hos_05.h
/// @brief Shooting Star Summit - Star Sanctuary

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../hos.h"
#include "mapfs/hos_05_shape.h"
#include "mapfs/hos_05_hit.h"

#include "sprite/npc/WorldEldstar.h"
#include "sprite/npc/WorldMamar.h"
#include "sprite/npc/WorldSkolar.h"
#include "sprite/npc/WorldMuskular.h"
#include "sprite/npc/WorldMisstar.h"
#include "sprite/npc/WorldKlevar.h"
#include "sprite/npc/WorldKalmar.h"
#include "sprite/npc/WorldBowser.h"
#include "sprite/npc/WorldKammy.h"
#include "sprite/npc/StarRod.h"

enum {
    NPC_Eldstar         = 0,
    NPC_Mamar           = 1,
    NPC_Skolar          = 2,
    NPC_Muskular        = 3,
    NPC_Misstar         = 4,
    NPC_Klevar          = 5,
    NPC_Kalmar          = 6,
    NPC_Bowser_Body     = 7,
    NPC_Bowser_Prop     = 8,
    NPC_Kammy           = 9,
    NPC_StarRod         = 10,
};

enum {
    MV_Starship_Yaw     = MapVar(10),
    MV_Starship_PosY    = MapVar(11),
    MV_PlayerOnBoard    = MapVar(12),
    MV_PartnerOnBoard   = MapVar(13),
};

#define NAMESPACE hos_05

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupStarship);
extern EvtScript N(EVS_Starship_Summon);
extern EvtScript N(EVS_Starship_Depart);
extern EvtScript N(EVS_SetupStarshipAndWater);
extern EvtScript N(EVS_EnterStarship);
extern EvtScript N(EVS_Intro_Main);
extern EvtScript N(EVS_SetupNarrator);
extern EvtScript N(EVS_SetupLightBeam);
extern NpcGroupList N(IntroNPCs);
extern NpcGroupList N(DefaultNPCs);

void N(draw_foreground_bowser_silhouette)(void);
