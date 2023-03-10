/// @file kmr_00.h
/// @brief Goomba Region - Forest Clearing

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kmr.h"
#include "mapfs/kmr_00_shape.h"
#include "mapfs/kmr_00_hit.h"

#include "sprite/npc/WorldKalmar.h"
#include "sprite/npc/WorldMamar.h"
#include "sprite/npc/WorldEldstar.h"
#include "sprite/npc/WorldSkolar.h"
#include "sprite/npc/WorldMuskular.h"
#include "sprite/npc/WorldMisstar.h"
#include "sprite/npc/WorldKlevar.h"
#include "sprite/npc/Goombaria.h"

enum {
    NPC_Goombaria               = 0,
    NPC_Eldstar                 = 1,
    NPC_Mamar                   = 2,
    NPC_Skolar                  = 3,
    NPC_Muskular                = 4,
    NPC_Misstar                 = 5,
    NPC_Klevar                  = 6,
    NPC_Kalmar                  = 7,
};

enum {
    MV_Unk_01           = MapVar(1),
    MV_Unk_02           = MapVar(2),
};

#define NAMESPACE kmr_00

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_Scene_MarioRevived);
extern NpcGroupList N(DefaultNPCs);
