/// @file kkj_18.h
/// @brief Peach's Castle - Dining Room (2F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kkj.h"
#include "mapfs/kkj_18_shape.h"
#include "mapfs/kkj_18_hit.h"

#include "sprite/npc/GourmetGuy.h"
#include "sprite/npc/WorldKammy.h"
#include "sprite/npc/WorldKoopatrol.h"
#include "sprite/npc/Twink.h"

enum {
    NPC_Kammy               = 0,
    NPC_Koopatrol_01        = 1,
    NPC_Koopatrol_02        = 2,
    NPC_GourmetGuy          = 3,
    NPC_GourmetGuy_Knife    = 4,
    NPC_GourmetGuy_Fork     = 5,
};

enum {
    MV_CakeItemIdx      = MapVar(0),
};

#define NAMESPACE kkj_18

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_EndPeachChapter4);
extern EvtScript N(EVS_ManageGourmetGuyScenes);

extern NpcGroupList N(DefaultNPCs);
