/// @file kkj_02.h
/// @brief Peach's Castle - Intro Stairs Hallway (3F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kkj.h"
#include "mapfs/kkj_02_shape.h"
#include "mapfs/kkj_02_hit.h"

enum {
    NPC_Toad            = 0,
    NPC_ToadGuard       = 1,
};

#define NAMESPACE kkj_02

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);
