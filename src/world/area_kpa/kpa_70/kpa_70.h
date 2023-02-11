/// @file kpa_70.h
/// @brief Bowser's Castle - Entry Lava Hall

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_70_shape.h"
#include "mapfs/kpa_70_hit.h"

#include "animation_script.h"

enum {
    NPC_Koopatrol_01            = 0,
    NPC_Koopatrol_02            = 1,
};

#define NAMESPACE kpa_70

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);

extern StaticAnimatorNode* N(ChainDriveSkeleton)[];
extern AnimScript N(AS_ChainDriveAnim);

API_CALLABLE(InitAnimatedModels);
API_CALLABLE(SetAnimatedModelRenderMode);
API_CALLABLE(DeleteAnimatedModel);
