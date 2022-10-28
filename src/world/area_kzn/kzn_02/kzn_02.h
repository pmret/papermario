/// @file kzn_02.h
/// @brief Mt Lavalava - First Lava Lake

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kzn.h"
#include "mapfs/kzn_02_shape.h"
#include "mapfs/kzn_02_hit.h"

enum {
    NPC_Kolorado                = 0,
    NPC_LavaBubble              = 1,
};

#define NAMESPACE kzn_02

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_InitializePlatforms);
extern EvtScript N(EVS_PlayDemoScene);
extern EvtScript N(EVS_KoloradoSinkingPlatform);
extern NpcGroupList N(DefaultNPCs);
