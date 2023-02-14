/// @file kkj_15.h
/// @brief Peach's Castle - Passage Outlet (2F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kkj.h"
#include "mapfs/kkj_15_shape.h"
#include "mapfs/kkj_15_hit.h"

#include "sprite/npc/Twink.h"
#include "sprite/npc/WorldBowser.h"
#include "sprite/npc/WorldKammy.h"
#include "sprite/npc/KoopaBros.h"
#include "sprite/npc/WorldKoopatrol.h"

enum {
    // shared
    NPC_Bowser                  = 0,
    NPC_Kammy                   = 1,
    // chapter 0 npcs
    NPC_KoopaBros_01            = 2,
    NPC_KoopaBros_02            = 3,
    NPC_KoopaBros_03            = 4,
    NPC_KoopaBros_04            = 5,
    // chapter 1 npcs
    NPC_Koopatrol_01            = 1,
    NPC_Koopatrol_02            = 2,
    // chapter 3 npcs
    NPC_Koopatrol_03            = 2,
    NPC_Koopatrol_04            = 3,
};

#define NAMESPACE kkj_15

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_EnterRotatingWall);
extern EvtScript N(EVS_Scene_Chapter0_BowserAndKammy);
extern EvtScript N(EVS_SetupChapter1);
extern EvtScript N(EVS_SetupChapter2);
extern EvtScript N(EVS_Scene_Chapter3);
extern EvtScript N(EVS_AnimateRotatingWall_AlmostCaught);
extern EvtScript N(EVS_EndPeachChapter0);
extern EvtScript N(EVS_EndPeachChapter1);
extern EvtScript N(EVS_EndPeachChapter3);

extern NpcGroupList N(Chapter0NPCs);
extern NpcGroupList N(Chapter1NPCs);
extern NpcGroupList N(Chapter3NPCs);
