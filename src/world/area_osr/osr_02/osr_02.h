/// @file osr_02.h
/// @brief Peach's Castle Grounds - Hijacked Castle Entrance

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../osr.h"
#include "mapfs/osr_02_shape.h"
#include "mapfs/osr_02_hit.h"

#include "sprite/npc/Twink.h"
#include "sprite/npc/WorldEldstar.h"
#include "sprite/npc/WorldMamar.h"
#include "sprite/npc/WorldSkolar.h"
#include "sprite/npc/WorldMuskular.h"
#include "sprite/npc/WorldMisstar.h"
#include "sprite/npc/WorldKlevar.h"
#include "sprite/npc/WorldKalmar.h"
#include "sprite/npc/StarRod.h"

enum {
    NPC_Clubba                  = 0,
    NPC_Peach                   = 0,
    NPC_Twink                   = 1,
    NPC_Eldstar                 = 2,
    NPC_Mamar                   = 3,
    NPC_Skolar                  = 4,
    NPC_Muskular                = 5,
    NPC_Misstar                 = 6,
    NPC_Klevar                  = 7,
    NPC_Kalmar                  = 8,
    NPC_StarRod                 = 9,
};

#define NAMESPACE osr_02

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_Scene_ReturnStarRod);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(PeachNPCs);
extern NpcGroupList N(DefaultNPCs);
