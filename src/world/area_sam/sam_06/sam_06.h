/// @file sam_06.h
/// @brief Mt Shiver - Starborn Valley

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../sam.h"
#include "mapfs/sam_06_shape.h"
#include "mapfs/sam_06_hit.h"

#include "sprite/npc/Toad.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/Merle.h"
#include "sprite/npc/ShiverToad.h"
#include "sprite/npc/Ninji.h"

enum {
    NPC_Merle                   = 0,
    NPC_ShiverToad_01           = 1,
    NPC_ShiverToad_02           = 2,
    NPC_ShiverToad_03           = 3,
    NPC_Ninji_01                = 4,
    NPC_Ninji_02                = 5,
    NPC_Ninji_03                = 6,
    NPC_Ninji_04                = 7,
    NPC_StarKid_01              = 8,
    NPC_StarKid_02              = 9,
    NPC_StarKid_03              = 10,
    NPC_StarKid_04              = 11,
    NPC_StarKid_05              = 12,
    NPC_StarKid_06              = 13,
    NPC_ShiverToad_04           = 14,
};

enum {
    MV_ScarfItemID  = MapVar(0),
};

enum {
    MF_MerleReady   = MapFlag(0),
};

#define NAMESPACE sam_06

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PlayRestingSong);
extern EvtScript N(EVS_SetupRooms);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(D_802443D4_D24264);
extern EvtScript N(EVS_Scene_Merle_OneLastThing);
extern NpcGroupList N(DefaultNPCs);
