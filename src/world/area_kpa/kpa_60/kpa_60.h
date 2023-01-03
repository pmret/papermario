/// @file kpa_60.h
/// @brief Bowser's Castle - Ship Enter/Exit Scenes

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_60_shape.h"
#include "mapfs/kpa_60_hit.h"

enum {
    MV_PadLockEntityID  = MapVar(0),
    MV_Starship_PosX    = MapVar(10),
    MV_Starship_PosY    = MapVar(11),
    MV_Starship_PosZ    = MapVar(12),
    MV_Starship_Yaw     = MapVar(13),
};

#define NAMESPACE kpa_60

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_ExitDoor_kpa_70_0);
extern EvtScript N(EVS_Scene_Arrival);
extern EvtScript N(EVS_Scene_Departure);
extern EvtScript N(EVS_MakeEntities);
