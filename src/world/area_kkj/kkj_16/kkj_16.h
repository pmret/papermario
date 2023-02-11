/// @file kkj_16.h
/// @brief Peach's Castle - Library (2F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kkj.h"
#include "mapfs/kkj_16_shape.h"
#include "mapfs/kkj_16_hit.h"

#include "sprite/npc/WorldKoopatrol.h"
#include "sprite/npc/HammerBros.h"
#include "sprite/npc/Twink.h"
#include "sprite/npc/BattleBow.h"

enum {
    // early
    NPC_HammerBros      = 0,
    NPC_Koopatrol_01    = 1,
    NPC_Koopatrol_02    = 2,
    NPC_Koopatrol_03    = 3,
    NPC_Koopatrol_04    = 4,
    // later
    NPC_HammerBros_01   = 0,
    NPC_HammerBros_02   = 1,
    NPC_HammerBros_03   = 2,
};

#define NAMESPACE kkj_16

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_ManageSneakingScenes);
extern EvtScript N(EVS_EndPeachChapter2);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList N(EarlyNPCs);
extern NpcGroupList N(LaterNPCs);
