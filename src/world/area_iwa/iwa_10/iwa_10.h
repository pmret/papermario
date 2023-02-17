/// @file iwa_10.h
/// @brief Mt Rugged - Train Station

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../iwa.h"
#include "mapfs/iwa_10_shape.h"
#include "mapfs/iwa_10_hit.h"

#include "sprite/npc/TrainToad.h"
#include "sprite/npc/WorldParakarry.h"

enum {
    NPC_TrainToad_01        = 0,
    NPC_TrainToad_02        = 1,
    NPC_Dryite              = 2,
    NPC_Toadette_01         = 3,
    NPC_Parakarry           = 4,
    NPC_Toad                = 5,
    NPC_Toadette_02         = 6,
    NPC_Toadette_03         = 7,
    NPC_Toadette_04         = 8,
};

enum {
    MF_TrainArriveDoorOpen          = MapFlag(0),
    MF_TrainArrivePlayerDisembark   = MapFlag(1),
    MF_TrainDepartDoorOpen          = MapFlag(2),
    MF_TrainDepartPlayerBoard       = MapFlag(3),
    MF_TrainMoving                  = MapFlag(4),
    MF_TrainReverseDir              = MapFlag(5),
    MF_DropBush1                    = MapFlag(10),
    MF_DropBush2                    = MapFlag(11),
    MF_DropBush3                    = MapFlag(12),
    MF_DropBush4                    = MapFlag(13),
};

enum {
    MV_TrainMoveDist        = MapVar(0),
    MV_TrainMoveSpeed       = MapVar(1),
    MV_ParakarryPosZ        = MapVar(10),
    MV_SuperBlock           = MapVar(11),
};

#define NAMESPACE iwa_10

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_InitializeTrainScene);
extern EvtScript N(EVS_ArriveFromToadTown);
extern EvtScript N(EVS_DepartForToadTown);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PushSong);
extern EvtScript N(EVS_PopSong);
extern EvtScript N(EVS_Scene_MeetParakarry);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);

extern EvtScript N(EVS_NpcIdle_Parakarry);
extern NpcData N(NpcData_Parakarry);
API_CALLABLE(N(LoadPartyImage));
