/// @file kpa_09.h
/// @brief Bowser's Castle - Ultra Shroom Timing Puzzle

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_09_shape.h"
#include "mapfs/kpa_09_hit.h"

#include "sprite/npc/DryBones.h"
#include "sprite/npc/ThrownBone.h"

enum {
    NPC_DryBones                = 0,
    NPC_DryBones_Bone1          = 1,
    NPC_DryBones_Bone2          = 2,
    NPC_DryBones_Bone3          = 3,
};

#define NAMESPACE kpa_09

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
