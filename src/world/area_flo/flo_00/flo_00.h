/// @file flo_00.h
/// @brief Flower Fields - Center

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_00_shape.h"
#include "mapfs/flo_00_hit.h"

#include "sprite/npc/Lakilulu.h"
#include "sprite/npc/WorldLakilester.h"
#include "sprite/npc/WorldParakarry.h"

enum {
    NPC_Dummy_Wisterwood        = 0,
    NPC_Bubulb_01               = 1,
    NPC_Bubulb_02               = 2,
    NPC_Bubulb_03               = 3,
    NPC_Bubulb_04               = 4,
    NPC_Tolielup                = 5,
    NPC_Klevar                  = 6,
    NPC_Lakilulu                = 7,
    NPC_Lakilester_Epilogue     = 0,
    NPC_Lakilulu_Epilogue       = 1,
    NPC_Parakarry_Epilogue      = 2,
};

enum {
    MV_BeanstalkSceneSync       = MapVar(10),
    MV_BeanstalkItemEntity      = MapVar(11),
};

#define NAMESPACE flo_00

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_Scene_Epilogue);
extern EvtScript N(EVS_Interact_Wisterwood);
extern EvtScript N(EVS_Wisterwood_Exit);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);

extern EvtScript N(EVS_Scene_SunReturns);
extern EvtScript N(EVS_SetupBeanPatch);
extern EvtScript N(EVS_SetupBeanstalk);
extern EvtScript N(EVS_Enter_Beanstalk);
extern EvtScript N(EVS_Scene_BeanstalkGrewRemark);

extern NpcGroupList N(DefaultNPCs);
extern NpcGroupList N(EpilogueNPCs);
