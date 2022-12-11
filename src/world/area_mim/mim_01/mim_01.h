/// @file mim_01.h
/// @brief Forever Forest - Flower Sounds

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mim.h"
#include "mapfs/mim_01_shape.h"
#include "mapfs/mim_01_hit.h"

#include "sprite/npc/SmallPiranha.h"

enum {
    NPC_PiranhaPlant            = 1,
    NPC_PiranhaPlant_Hitbox     = 2,
};

#define NAMESPACE mim_01

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupExitHint);
extern EvtScript N(EVS_SetupGates);
extern EvtScript N(EVS_BindExitTriggers);
extern NpcGroupList N(DefaultNPCs);
