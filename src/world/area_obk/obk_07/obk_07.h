/// @file obk_07.h
/// @brief Boo's Mansion - Record Player Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../obk.h"
#include "mapfs/obk_07_shape.h"
#include "mapfs/obk_07_hit.h"

#include "sprite/npc/Boo.h"

enum {
    NPC_TrafficBoo1     = 0,
    NPC_TrafficBoo2     = 1,
    NPC_GuardBoo        = 2,
};

enum {
    MV_InspectingFireplace  = MapVar(0),
    MV_GuardDancing         = MapVar(1),
    MV_GuardDeparted        = MapVar(2),
    MV_ReadyToPlay          = MapVar(3),
    MV_WindingDown          = MapVar(4),
    MV_GuardReturnScript    = MapVar(5),
    MV_PhonographDataPtr    = MapVar(6),
    MV_MashInputsAmount     = MapVar(7),
    MV_UpdateScaleScript    = MapVar(8),
    MV_UpdateCrankScript    = MapVar(9),
    MV_UpdateRecordScript   = MapVar(10),
    MV_SetScaleScript       = MapVar(11),
    MV_SetCrankScript       = MapVar(12),
    MV_SetRecordScript      = MapVar(13),
    MV_WindDownScript       = MapVar(14),
    MV_UpdateGuardScript    = MapVar(15),
};

enum {
    MF_CancelScaleScript    = MapFlag(10),
    MF_CancelCrankScript    = MapFlag(11),
    MF_CancelRecordScript   = MapFlag(12),
    MF_GuardBusy            = MapFlag(13),
};

#define NAMESPACE obk_07

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupFireplace);
extern EvtScript N(EVS_SetupGuardBoo);
extern EvtScript N(EVS_SetupPhonograph);
extern EvtScript N(EVS_Scene_PlayerGotChestItem);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
