/// @file dgb_00.h
/// @brief Tubba's Castle - Escape Scene

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../dgb.h"
#include "mapfs/arn_20_shape.h"
#include "mapfs/arn_20_hit.h"

#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/WorldKooper.h"
#include "sprite/npc/WorldBombette.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/WorldBow.h"

enum {
    NPC_Boo_01      = 0,
    NPC_Boo_02      = 1,
    NPC_Boo_03      = 2,
    NPC_Boo_04      = 3,
    NPC_Boo_05      = 4,
    NPC_Boo_06      = 5,
    NPC_Sentinel    = 6,
};

enum {
    MV_PreventTaunting  = MapVar(0),
};

#define NAMESPACE dgb_00

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_Scene_ThrownOutBySentinel);
extern EvtScript N(EVS_Scene_BoosApproachManor);
extern EvtScript N(EVS_Scene_EscapeFromTubba);
extern EvtScript N(EVS_SetBoosBracingDoor);
extern EvtScript N(EVS_TubbaTaunting);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
extern NpcGroupList N(BooNPCs);
