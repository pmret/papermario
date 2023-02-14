/// @file kkj_29.h
/// @brief Peach's Castle - Quiz-Off Room (1F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kkj.h"
#include "mapfs/kkj_29_shape.h"
#include "mapfs/kkj_29_hit.h"

#include "sprite/npc/WorldKoopatrol.h"
#include "sprite/npc/WorldBowser.h"
#include "sprite/npc/HammerBros.h"
#include "sprite/npc/Twink.h"

enum {
    NPC_Bowser          = 0,
    NPC_Koopatrol_01    = 1,
    NPC_Koopatrol_02    = 2,
    NPC_HammerBros      = 3,
};

#define NAMESPACE kkj_29

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_ManageStageEffects);
extern EvtScript N(EVS_ManageQuizGame);
extern EvtScript N(EVS_EndPeachChapter5);

extern NpcGroupList N(DefaultNPCs);
