/// @file kkj_14.h
/// @brief Peach's Castle - Peach's Room (2F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kkj.h"
#include "mapfs/kkj_14_shape.h"
#include "mapfs/kkj_14_hit.h"

#include "sprite/npc/Twink.h"
#include "sprite/npc/WorldKoopatrol.h"
#include "sprite/npc/WorldBowser.h"
#include "sprite/npc/WorldKammy.h"

enum {
    // chapter 2/4
    NPC_Bowser                  = 0,
    NPC_Kammy                   = 1,
    // npc_guards
    NPC_Koopatrol_Guard_01      = 0,
    NPC_Koopatrol_Guard_02      = 1,
    // chapter 7
    NPC_Ch7_Bowser              = 0,
    NPC_Ch7_Koopatrol_01        = 1,
    NPC_Ch7_Koopatrol_02        = 2,
    NPC_Ch7_Kammy               = 3,
};

#define NAMESPACE kkj_14

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupInteractables);
extern EvtScript N(EVS_Scene_Chapter0);
extern EvtScript N(EVS_Scene_Chapter1);
extern EvtScript N(EVS_Scene_Chapter2);
extern EvtScript N(EVS_Scene_Chapter3);
extern EvtScript N(EVS_Scene_Chapter4);
extern EvtScript N(EVS_Scene_Chapter5);
extern EvtScript N(EVS_Scene_Chapter6);
extern EvtScript N(EVS_Scene_Chapter7);
extern EvtScript N(EVS_Scene_TossedBackInRoom);
extern EvtScript N(EVS_EndPeachChapter7);

extern NpcGroupList N(Chapter0NPCs);
extern NpcGroupList N(Chapter2NPCs);
extern NpcGroupList N(Chapter7NPCs);
extern NpcGroupList N(TossBackNPCs);
