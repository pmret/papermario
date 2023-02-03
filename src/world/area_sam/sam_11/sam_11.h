/// @file sam_11.h
/// @brief Mt Shiver - Shiver City Pond Area

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../sam.h"
#include "mapfs/sam_11_shape.h"
#include "mapfs/sam_11_hit.h"

#include "sprite/npc/Toad.h"
#include "sprite/npc/Penguin.h"
#include "sprite/npc/PenguinPatrol.h"
#include "sprite/npc/Herringway.h"
#include "sprite/npc/WorldKooper.h"
#include "sprite/npc/WorldParakarry.h"

#include "animation_script.h"

enum {
    NPC_PenguinPatrol           = 0,
    NPC_PenguinSentry           = 1,
    NPC_Herringway              = 2,
    NPC_Penguin_02              = 3,
    NPC_Penguin_03              = 4,
    NPC_Penguin_04              = 5,
    NPC_Penguin_05              = 6,
    NPC_Penguin_06              = 7,
    NPC_Toadette_01             = 8,
    NPC_Toadette_02             = 9,
    NPC_Toadette_03             = 10,
    NPC_0B                      = 11,
    NPC_Kolorado                = 12,
    NPC_Archeologist_01         = 13,
    NPC_Archeologist_02         = 14,
    NPC_Kooper                  = 15,
    NPC_Parakarry               = 16,
    NPC_ChuckQuizmo             = 17,
};

enum {
    MV_DialogueState_Penguin2   = MapVar(0),
    MV_DialogueState_Penguin3   = MapVar(1),
    MV_DialogueState_Penguin4   = MapVar(2),
    MV_DialogueState_Penguin5   = MapVar(3),
    MV_DialogueState_Penguin6   = MapVar(4),
    MV_DialogueState_Patrol     = MapVar(5),
    MV_PadlockEntityID          = MapVar(6),
    MV_CantDamagePond           = MapVar(7),
    MV_CurrentFloor             = MapVar(7),
    MV_ThrownOut                = MapVar(9),
};

enum {
    MF_Unk_00       = MapFlag(0),
    MF_Unk_01       = MapFlag(1),
    MF_UsingSpring  = MapFlag(2),
};

#define NAMESPACE sam_11

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupRooms);
extern EvtScript N(EVS_SetupPond);
extern EvtScript N(EVS_SetupStaircase);
extern EvtScript N(EVS_LoadPondAnimation);
extern EvtScript N(EVS_LowerStaircase);
extern EvtScript N(EVS_HideRightHouse);
extern EvtScript N(EVS_RevealRightHouse);
extern EvtScript N(EVS_RevealLeftHouse);
extern EvtScript N(EVS_SetupLockedHouse);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(EpilogueNPCs);
extern NpcGroupList N(BeforeNPCs);
extern NpcGroupList N(MysteryNPCs);
extern NpcGroupList N(AfterNPCs);

extern StaticAnimatorNode* N(ShatterPondSkeleton)[];
extern AnimScript N(AS_ShatterPond);

//TODO sort these into an include somewhere
API_CALLABLE(InitAnimatedModels);
API_CALLABLE(DeleteAnimatedModel);
API_CALLABLE(SetAnimatedModelRenderMode);
