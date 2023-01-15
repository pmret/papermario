/// @file omo_04.h
/// @brief Shy Guy's Toybox - BLU Block City

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../omo.h"
#include "mapfs/omo_04_shape.h"
#include "mapfs/omo_04_hit.h"

#include "sprite/npc/WorldKammy.h"

enum {
    NPC_Goomba      = 0,
    NPC_Clubba      = 1,
    NPC_Kammy       = 2,
    NPC_ShyGuy      = 3,
    NPC_SkyGuy      = 4,
};

enum {
    MV_AmbushID                 = MapVar(10), // npcID or itemID depending on GB_OMO_PeachChoice1
    MV_FlightSoundsScriptID     = MapVar(11),
};

enum {
    MF_KammyFlying      = MapFlag(10),
};

#define NAMESPACE omo_04

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_NpcIdle_Kammy);
extern EvtScript N(EVS_NpcAux_Kammy);
extern EvtScript N(EVS_SetupGizmos);
extern EvtScript N(EVS_Scene_KammySetAmbush);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(KammySceneNPCs);
extern NpcGroupList N(GoombaAmbushNPCs);
extern NpcGroupList N(ClubbaAmbushNPCs);
extern NpcGroupList N(DefaultNPCs);
