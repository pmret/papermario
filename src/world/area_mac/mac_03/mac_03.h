/// @file mac_03.h
/// @brief Toad Town - Station District

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mac.h"
#include "mapfs/mac_03_shape.h"
#include "mapfs/mac_03_hit.h"

#include "sprite/npc/TrainToad.h"
#include "sprite/npc/Toad.h"
#include "sprite/npc/ShyGuy.h"

enum {
    NPC_TrainToad_01        = 0,
    NPC_TrainToad_02        = 1,
    NPC_Toad_01             = 2,
    NPC_Toadette_01         = 3,
    NPC_Toad_02             = 4,
    NPC_ToadKid_01          = 5,
    NPC_ToadKid_02          = 6,
    NPC_Toadette_02         = 7,
    NPC_Toadette_03         = 8,
    NPC_Toadette_04         = 9,
    NPC_Toad_03             = 10,
    NPC_ShyGuy              = 11,
    NPC_LilOink_01          = 12,
    NPC_LilOink_02          = 13,
    NPC_LilOink_03          = 14,
    NPC_LilOink_04          = 15,
    NPC_LilOink_05          = 16,
    NPC_LilOink_06          = 17,
    NPC_LilOink_07          = 18,
    NPC_LilOink_08          = 19,
    NPC_LilOink_09          = 20,
    NPC_LilOink_10          = 21,
    NPC_Capsule             = 22,
    NPC_ChuckQuizmo         = 23,
};

enum {
    MF_TrainDepartDoorOpen          = MapFlag(0),
    MF_TrainDepartPlayerBoard       = MapFlag(1),
    MF_TrainArriveDoorOpen          = MapFlag(2),
    MF_TrainArrivePlayerDisembark   = MapFlag(3),
    MF_TrainMoving                  = MapFlag(4),
    MF_TrainReverseDir              = MapFlag(5),
    MF_Unk_06                       = MapFlag(6),
    MF_Unk_07                       = MapFlag(7),
    MF_Unk_08                       = MapFlag(8),
};

enum {
    MV_TrainMoveDist            = MapVar(0),
    MV_TrainMoveSpeed           = MapVar(1),
    MV_LilOinkEffect            = MapVar(2),
};

#define NAMESPACE mac_03

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_InitializeTrainScene);
extern EvtScript N(EVS_ArriveFromMtRugged);
extern EvtScript N(EVS_DepartForMtRugged);
extern EvtScript N(EVS_InitializeLilOinks);
extern EvtScript N(EVS_PlayDemoScene);

extern NpcGroupList N(DefaultNPCs);
