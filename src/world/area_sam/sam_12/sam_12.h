/// @file sam_12.h
/// @brief Mt Shiver - Merlar's Sanctuary

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../sam.h"
#include "mapfs/sam_12_shape.h"
#include "mapfs/sam_12_hit.h"

#include "sprite/npc/Merlar.h"

enum {
    NPC_Merlar  = 0,
};

enum {
    MV_StarStoneItemID  = MapVar(0),
};

enum {
    MF_DoneFadingIn     = MapFlag(0),
};

#define NAMESPACE sam_12

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_Scene_MeetMerlar);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
