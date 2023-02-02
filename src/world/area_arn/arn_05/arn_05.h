/// @file arn_05.h
/// @brief Gusty Gulch - Ghost Town 2

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../arn.h"
#include "mapfs/arn_05_shape.h"
#include "mapfs/arn_05_hit.h"

enum {
    NPC_Boo_01          = 0,
    NPC_Boo_02          = 1,
    NPC_Boo_03          = 2,
    NPC_Boo_04          = 3,
    NPC_Boo_05          = 4,
    NPC_Tubba           = 5,
    NPC_Boo_06          = 6,
    NPC_Boo_07          = 7,
    NPC_Boo_08          = 8,
    NPC_Boo_09          = 9,
};

enum {
    MV_Unk_00           = MapVar(0),
    MV_Unk_01           = MapVar(1),
};

#define NAMESPACE arn_05

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupTubbaRaid);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(BeforeNPCs);
extern NpcGroupList N(AfterNPCs);
