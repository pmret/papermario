/// @file mim_12.h
/// @brief Forever Forest - Exit to Gusty Gulch

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mim.h"
#include "mapfs/mim_12_shape.h"
#include "mapfs/mim_12_hit.h"

#include "sprite/npc/Boo.h"
#include "sprite/npc/WorldBow.h"

enum {
    NPC_GateBoo_01      = 0,
    NPC_GateBoo_02      = 1,
};

#define NAMESPACE mim_12

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_StartForestMusic);
extern EvtScript N(EVS_StartGustyMusic);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupForestGate);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
