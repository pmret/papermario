/// @file obk_01.h
/// @brief Boo's Mansion - Foyer

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../obk.h"
#include "mapfs/obk_01_shape.h"
#include "mapfs/obk_01_hit.h"

#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/Boo.h"

enum {
    NPC_JumpScareBoo    = 0,
    NPC_TrafficBoo1     = 1,
    NPC_TrafficBoo2     = 2,
    NPC_UpstairsBoo     = 3,
    NPC_Franky          = 4,
};

enum {
    MV_UnusedPosOffset      = MapVar(10),
    MV_CabinetPosOffset     = MapVar(11),
};

#define NAMESPACE obk_01

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupChandelier);
extern EvtScript N(EVS_SetupPortrait);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_Scene_JumpScareBoo);
extern NpcGroupList N(DefaultNPCs);
extern EvtScript N(EVS_MakeEntities);
