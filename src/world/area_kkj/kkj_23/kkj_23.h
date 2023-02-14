/// @file kkj_23.h
/// @brief Peach's Castle - Rooftop (5F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kkj.h"
#include "mapfs/kkj_23_shape.h"
#include "mapfs/kkj_23_hit.h"

#include "sprite/npc/WorldBowser.h"
#include "sprite/npc/WorldKoopatrol.h"
#include "sprite/npc/WorldKammy.h"

enum {
    // peach
    NPC_Kammy           = 0,
    NPC_Koopatrol_01    = 1,
    NPC_Koopatrol_02    = 2,
    // finale
    NPC_Bowser_Body     = 0,
    NPC_Bowser_Prop     = 1,
    NPC_Peach           = 2,
};

#define NAMESPACE kkj_23

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_Scene_KammyUnmasksPeach);
extern EvtScript N(EVS_BowserTauntMario);
extern EvtScript N(EVS_EndPeachChapter6);

extern NpcGroupList N(PeachNPCs);
extern NpcGroupList N(FinaleNPCs);
