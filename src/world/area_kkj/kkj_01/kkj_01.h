/// @file kkj_01.h
/// @brief Peach's Castle - Intro Upper Hall (2F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kkj.h"
#include "mapfs/kkj_01_shape.h"
#include "mapfs/kkj_01_hit.h"

enum {
    NPC_ToadMinister        = 0,
    NPC_Toad_01             = 1,
    NPC_Toad_02             = 2,
    NPC_Toad_03             = 3,
    NPC_Toadette            = 4,
    NPC_ToadGuard_01        = 5,
    NPC_ToadGuard_02        = 6,
    NPC_Dryite              = 7,
    NPC_Mouser              = 8,
    NPC_MayorPenguin        = 9,
    NPC_Koopa               = 10,
};

#define NAMESPACE kkj_01

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_ExitDoors_kkj_14_0);

extern NpcGroupList N(DefaultNPCs);
