/// @file osr_03.h
/// @brief Peach's Castle Grounds - Outside Hijacked Castle

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../osr.h"
#include "mapfs/osr_03_shape.h"
#include "mapfs/osr_03_hit.h"

#include "sprite/npc/WorldKammy.h"

enum {
    NPC_Kammy       = 0,
};

enum {
    MV_Starship_PosX    = MapVar(10),
    MV_Starship_PosY    = MapVar(11),
    MV_Starship_PosZ    = MapVar(12),
    MV_Starship_Yaw     = MapVar(13),
    MV_CastleLiftDist   = MapVar(14),
};

#define NAMESPACE osr_03

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_AnimateSwingingChains);
extern EvtScript N(EVS_AnimateSpinningRing);
extern EvtScript N(MV_Scene_CastleAscending);
extern EvtScript N(MV_Scene_PlayerTossedOut);
extern EvtScript N(EVS_Scene_UnusedTossOut);
extern EvtScript N(EVS_Scene_BeginInterlude);
extern EvtScript N(EVS_Scene_Starship);
extern EvtScript N(EVS_Scene_CastleDestruction);
extern NpcGroupList N(DefaultNPCs);
