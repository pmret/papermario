/// @file kkj_03.h
/// @brief Peach's Castle - Intro Window Hallway (4F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kkj.h"
#include "mapfs/kkj_03_shape.h"
#include "mapfs/kkj_03_hit.h"

enum {
    NPC_Peach   = 0,
};

#define NAMESPACE kkj_03

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_Scene_MeetingPeach);
extern EvtScript N(EVS_Scene_Ascending);

extern NpcGroupList N(DefaultNPCs);
