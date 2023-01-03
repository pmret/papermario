/// @file kpa_17.h
/// @brief Bowser's Castle - Lower Jail

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_17_shape.h"
#include "mapfs/kpa_17_hit.h"

#include "sprite/npc/WorldBombette.h"
#include "sprite/npc/Toad.h"
#include "sprite/npc/ToadMinister.h"
#include "sprite/npc/ToadGuard.h"

enum {
    NPC_Toad_01                 = 0,
    NPC_Toad_02                 = 1,
    NPC_ToadGuard               = 2,
    NPC_ToadMinister            = 3,
};

#define NAMESPACE kpa_17

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_BlastWall);
extern EvtScript N(EVS_Scene_FallIntoCell);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
