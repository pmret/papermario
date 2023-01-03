/// @file kpa_111.h
/// @brief Bowser's Castle - Room with Hidden Door 1

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_111_shape.h"
#include "mapfs/kpa_111_hit.h"

#include "sprite/npc/DryBones.h"
#include "sprite/npc/ThrownBone.h"

enum {
    NPC_DryBones_01             = 0,
    NPC_DryBones_01_Hitbox1     = 1,
    NPC_DryBones_01_Hitbox2     = 2,
    NPC_DryBones_01_Hitbox3     = 3,
    NPC_DryBones_02             = 4,
    NPC_DryBones_02_Hitbox1     = 5,
    NPC_DryBones_02_Hitbox2     = 6,
    NPC_DryBones_02_Hitbox3     = 7,
};

#define NAMESPACE kpa_111

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupStatues);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
