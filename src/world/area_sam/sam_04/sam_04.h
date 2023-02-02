/// @file sam_04.h
/// @brief Mt Shiver - Shiver Snowfield

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../sam.h"
#include "mapfs/sam_04_shape.h"
#include "mapfs/sam_04_hit.h"

#include "sprite/npc/Toad.h"
#include "sprite/npc/Penguin.h"

enum {
    NPC_Snowman_01      = 0,
    NPC_Snowman_02      = 1,
    NPC_Snowman_03      = 2,
    NPC_Snowman_04      = 3,
    NPC_Snowman_05      = 4,
    NPC_Snowman_06      = 5,
    NPC_LetterDummy     = 6,
};

enum {
    MV_LetterItemID     = MapVar(0),
    MV_DroppedLetter    = MapVar(1),
    MV_TreeHitCount     = MapVar(2),
};

#define NAMESPACE sam_04

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupSnowmen);
extern EvtScript N(EVS_Scene_SnowmenSpeak);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
