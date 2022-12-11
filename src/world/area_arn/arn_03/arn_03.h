/// @file arn_03.h
/// @brief Gusty Gulch - Ghost Town 1

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../arn.h"
#include "mapfs/arn_03_shape.h"
#include "mapfs/arn_03_hit.h"

#include "sprite/npc/Boo.h"
#include "sprite/npc/WorldBow.h"

enum {
    NPC_Boo_01          = 0,
    NPC_Boo_02          = 1,
    NPC_Boo_03          = 2,
    NPC_Boo_04          = 3,
    NPC_Boo_05          = 4,
    NPC_Boo_06          = 5,
    NPC_Boo_07          = 6,
    NPC_Boo_08          = 7,
    NPC_Boo_09          = 8,
};

enum {
    MV_Unk_00           = MapVar(0),
    MV_Unk_01           = MapVar(1),
    MV_Unk_02           = MapVar(2),
    MV_Unk_03           = MapVar(3),
};

#define NAMESPACE arn_03

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(BeforeNPCs);
extern NpcGroupList N(AfterNPCs);
