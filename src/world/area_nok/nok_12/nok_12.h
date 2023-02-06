/// @file nok_12.h
/// @brief Koopa Region - Pleasant Path Bridge

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../nok.h"
#include "mapfs/nok_12_shape.h"
#include "mapfs/nok_12_hit.h"

#include "sprite/npc/SpikedGoomba.h"
#include "sprite/npc/KoopaTroopa.h"
#include "sprite/npc/Goomba.h"

enum {
    NPC_KoopaTroopa_01          = 0,
    NPC_KoopaTroopa_02          = 1,
    NPC_Goomba                  = 2,
    NPC_SpikedGoomba            = 3,
};

enum {
    MV_SwitchEntityID   = MapVar(0),
};

#define NAMESPACE nok_12

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_OnShakeTree_DropSwitch);
extern EvtScript N(EVS_SetupBridge);
extern EvtScript N(EVS_PlayDemoScene1);
extern EvtScript N(EVS_PlayDemoScene2);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupFoliage);
extern NpcGroupList N(DefaultNPCs);
extern NpcGroupList N(DemoNPCs);
