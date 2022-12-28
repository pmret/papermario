/// @file flo_17.h
/// @brief Flower Fields - (NE) Fallen Logs

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_17_shape.h"
#include "mapfs/flo_17_hit.h"

enum {
    NPC_Lakitu_01               = 0,
    NPC_Lakitu_02               = 1,
    NPC_Spiny_01                = 50,
    NPC_Spiny_02                = 51,
    NPC_Spiny_03                = 52,
    NPC_Spiny_04                = 53,
};

enum {
    MV_RotAngle_Log_01      = MapVar(10),
    MV_RotVelocity_Log_01   = MapVar(11),
    MV_RotAngle_Log_02      = MapVar(12),
    MV_RotVelocity_Log_02   = MapVar(13),
    MV_RotAngle_Log_03      = MapVar(14),
    MV_RotVelocity_Log_03   = MapVar(15),
};

#define NAMESPACE flo_17

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupLogBridges);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
