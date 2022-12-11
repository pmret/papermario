/// @file flo_03.h
/// @brief Flower Fields - (East) Petunia's Field

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_03_shape.h"
#include "mapfs/flo_03_hit.h"

#include "sprite/npc/Petunia.h"
#include "sprite/npc/MontyMole.h"
#include "sprite/npc/Dayzee.h"

enum {
    NPC_Petunia                 = 0,
    NPC_Dayzee                  = 1,
    NPC_MontyMole_01            = 2,
    NPC_MontyMole_02            = 3,
    NPC_MontyMole_03            = 4,
    NPC_MontyMole_04            = 5,
};

enum {
    MV_NextBurrowTime_Mole_01   = MapVar(10),
    MV_NextBurrowTime_Mole_02   = MapVar(11),
    MV_NextBurrowTime_Mole_03   = MapVar(12),
    MV_NextBurrowTime_Mole_04   = MapVar(13),
    MV_PauseBurrowing           = MapVar(14),
    MV_NextBurrowTriggerRadius  = MapVar(15),
};

#define NAMESPACE flo_03

extern EvtScript N(EVS_Main);
extern NpcGroupList N(DefaultNPCs);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PushFlowerSong);
extern EvtScript N(EVS_PopSong);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_MakeEntities);

extern EvtScript N(EVS_Scene_SunReturns);
extern EvtScript N(EVS_SetupMoles);
extern EvtScript N(EVS_EmptyEntityHandler);
