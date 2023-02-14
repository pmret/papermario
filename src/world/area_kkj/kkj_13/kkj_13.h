/// @file kkj_13.h
/// @brief Peach's Castle - Window Hallway (4F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kkj.h"
#include "mapfs/kkj_13_shape.h"
#include "mapfs/kkj_13_hit.h"

#include "sprite/npc/WorldBowser.h"
#include "sprite/npc/WorldKammy.h"
#include "sprite/npc/WorldKoopatrol.h"

enum {
    // shared
    NPC_Bowser_Body     = 0,
    NPC_Bowser_Prop     = 1,
    // chapter 8
    NPC_CaptivePeach    = 2,
    // intro
    NPC_Koopatrol_01    = 2,
    NPC_Koopatrol_02    = 3,
    NPC_Kammy           = 4,
    NPC_Peach           = 5,
};

#define NAMESPACE kkj_13

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_Scene_MarioConfrontsBowser);
extern EvtScript N(EVS_Scene_BowserAttacks);
extern EvtScript N(EVS_Scene_PeachCaptured);

extern NpcGroupList N(IntroNPCs);
extern NpcGroupList N(ChapterNPCs);
