/// @file obk_03.h
/// @brief Boo's Mansion - Basement

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../obk.h"
#include "mapfs/obk_03_shape.h"
#include "mapfs/obk_03_hit.h"

#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/Boo.h"

enum {
    NPC_Igor    = 0,
};

#define NAMESPACE obk_03

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupShop);
extern EvtScript N(EVS_SetupStairs);
extern EvtScript N(EVS_SetupRockingChair);
extern EvtScript N(EVS_Scene_DropSteps);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
