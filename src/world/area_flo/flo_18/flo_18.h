/// @file flo_18.h
/// @brief Flower Fields - (NE) Puff Puff Machine

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_18_shape.h"
#include "mapfs/flo_18_hit.h"

#include "sprite/npc/WorldLakilester.h"

enum {
    NPC_Lakitu_01           = 0,
    NPC_Lakitu_02           = 1,
    NPC_Lakitu_03           = 2,
    NPC_Magikoopa           = 3,
    NPC_FlyingMagikoopa     = 4,
};

enum {
    MF_HitGuardedMachine    = MapFlag(1),
    MF_MachineShaking       = MapFlag(2),
    MF_MachineBeingDamaged  = MapFlag(3),
};

enum {
    MV_ReactingNpc          = MapVar(10),
};

#define NAMESPACE flo_18

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_SetupMachine);
extern EvtScript N(EVS_SetupMachineDamageReactions);
extern EvtScript N(EVS_Scene_LakilesterLikesBeingGood);
extern NpcGroupList N(DefaultNPCs);
