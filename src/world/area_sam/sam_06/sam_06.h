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
#include "sprite/npc/StarKid.h"
#include "sprite/npc/Twink.h"

enum {
    NPC_Merle                   = 0,
    NPC_ShiverToad_01           = 1,
    NPC_ShiverToad_02           = 2,
    NPC_ShiverToad_03           = 3,
    NPC_Ninji_01                = 4,
    NPC_Ninji_02                = 5,
    NPC_Ninji_03                = 6,
    NPC_Ninji_04                = 7,
    NPC_Twink_01                = 8,
    NPC_Twink_02                = 9,
    NPC_Twink_03                = 10,
    NPC_Twink_04                = 11,
    NPC_Twink_05                = 12,
    NPC_Twink_06                = 13,
    NPC_ShiverToad_04           = 14,
};

enum {
    MV_Unk_00       = MapVar(0),
};

enum {
    MF_Unk_00       = MapFlag(0),
};

#define NAMESPACE sam_06

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PlayRestingSong);
extern EvtScript N(EVS_SetupRooms);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(D_802443D4_D24264);
extern EvtScript N(EVS_80248CE4);
extern NpcGroupList N(DefaultNPCs);
