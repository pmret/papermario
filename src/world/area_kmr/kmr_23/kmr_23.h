/// @file kmr_23.h
/// @brief Goomba Region - Chapter End

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kmr.h"
#include "mapfs/kmr_23_shape.h"
#include "mapfs/kmr_23_hit.h"

#include "sprite/npc/WorldEldstar.h"
#include "sprite/npc/WorldMamar.h"
#include "sprite/npc/WorldSkolar.h"
#include "sprite/npc/WorldMuskular.h"
#include "sprite/npc/WorldMisstar.h"
#include "sprite/npc/WorldKlevar.h"
#include "sprite/npc/WorldKalmar.h"

enum {
    NPC_StarSpirit          = 0,
    NPC_AuxSpirit           = 1,
};

enum {
    MV_EndChapterDataPtr    = MapVar(0),
};

enum {
    AF_JAN01_TreeDrop_StarPiece               = MapFlag(10),
    MF_Unk_0B               = MapFlag(11),
};

#define NAMESPACE kmr_23

extern EvtScript N(EVS_Main);
extern NpcGroupList N(NpcGroup_Eldstar);
extern NpcGroupList N(NpcGroup_Mamar);
extern NpcGroupList N(NpcGroup_Skolar);
extern NpcGroupList N(NpcGroup_Muskular);
extern NpcGroupList N(NpcGroup_Misstar);
extern NpcGroupList N(NpcGroup_Klevar);
extern NpcGroupList N(NpcGroup_Kalmar);
