/// @file sam_01.h
/// @brief Mt Shiver - Shiver City Mayor Area

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../sam.h"
#include "mapfs/sam_01_shape.h"
#include "mapfs/sam_01_hit.h"

#include "sprite/npc/Herringway.h"
#include "sprite/npc/Penguin.h"
#include "sprite/npc/ChuckQuizmo.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/MayorPenguin.h"
#include "sprite/npc/MayorPenguinWife.h"
#include "sprite/npc/PenguinPatrol.h"
#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/WorldKooper.h"
#include "sprite/npc/WorldBombette.h"
#include "sprite/npc/WorldBow.h"
#include "sprite/npc/WorldWatt.h"
#include "sprite/npc/WorldSushie.h"
#include "sprite/npc/WorldLakilester.h"

enum {
    NPC_MayorPenguin            = 0,
    NPC_MayorDummy              = 1,
    NPC_MayorPenguinWife        = 2,
    NPC_PenguinPatrol           = 3,
    NPC_Herringway              = 4,
    NPC_Penguin_01              = 5,
    NPC_Penguin_02              = 6,
    NPC_Penguin_03              = 7,
    NPC_Penguin_04              = 8,
    NPC_Penguin_05              = 9,
    NPC_Penguin_06              = 10,
    NPC_Penguin_07              = 11,
    NPC_Penguin_08              = 12,
    NPC_Penguin_09              = 13,
    NPC_ChuckQuizmo             = 14,
};

enum {
    MV_DialogueState_Penguin1   = MapVar(0),
    MV_DialogueState_Penguin2   = MapVar(1),
    MV_DialogueState_Penguin3   = MapVar(2),
    MV_DialogueState_Penguin4   = MapVar(3),
    MV_PresentItemID            = MapVar(4),
    MV_BucketItemID             = MapVar(5),
    MV_PlayerLeftOfMayor        = MapVar(6),
};

enum {
    MF_ContinueScene            = MapFlag(0),
};

#define NAMESPACE sam_01

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_NpcInteract_Herringway);
extern EvtScript N(EVS_SetupMayorRooms);
extern EvtScript N(EVS_SetupRooms);
extern EvtScript N(EVS_Scene_MysteryBegins);
extern EvtScript N(EVS_Scene_MysterySolved);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(BeforeNPCs);
extern NpcGroupList N(MysteryNPCs);
extern NpcGroupList N(AfterNPCs);
