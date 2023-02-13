/// @file sam_02.h
/// @brief Mt Shiver - Shiver City Center

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../sam.h"
#include "mapfs/sam_02_shape.h"
#include "mapfs/sam_02_hit.h"

#include "sprite/npc/Penguin.h"

enum {
    NPC_Penguin_ShopOwner       = 0,
    NPC_ShiverToad              = 1,
    NPC_Penguin_02              = 2,
    NPC_Penguin_03              = 3,
    NPC_Penguin_04              = 4,
    NPC_Penguin_05              = 5,
    NPC_Penguin_06              = 6,
    NPC_Penguin_07              = 7,
    NPC_ChuckQuizmo             = 8,
};

enum {
    MV_DialogueState_Penguin2   = MapVar(0),
    MV_DialogueState_Penguin3   = MapVar(1),
    MV_DialogueState_Penguin4   = MapVar(2),
    MV_DialogueState_Penguin5   = MapVar(3),
    MV_DialogueState_Penguin6   = MapVar(4),
};

enum {
    MF_SkipIcedPotato   = MapFlag(10),
};

#define NAMESPACE sam_02

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PlayRestingSong);
extern EvtScript N(EVS_SetupRooms);
extern EvtScript N(EVS_SetupShop);
extern EvtScript N(EVS_MakeToadHouseGifts);
extern EvtScript N(D_8024B550_D10C80);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(MysteryNPCs);
extern NpcGroupList N(DefaultNPCs);
