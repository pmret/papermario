/// @file flo_10.h
/// @brief Flower Fields - (SE) Lily's Fountain

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_10_shape.h"
#include "mapfs/flo_10_hit.h"

enum {
    NPC_Lily                    = 0,
};

#define NAMESPACE flo_10

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PushFlowerSong);
extern EvtScript N(EVS_PopSong);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupFountain);
extern EvtScript N(EVS_SetupWaterStoneSocket);
extern EvtScript N(EVS_SetupWaterEffect);

extern EvtScript N(EVS_Scene_ReleaseFountain);
extern EvtScript N(EVS_Scene_PostReleaseFountain);
extern EvtScript N(EVS_Scene_SunReturns);

extern NpcGroupList N(DefaultNPCs);
