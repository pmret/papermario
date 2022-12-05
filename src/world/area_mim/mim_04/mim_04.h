/// @file mim_04.h
/// @brief Forever Forest - Tree Face (Bub-ulb)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mim.h"
#include "mapfs/mim_04_shape.h"
#include "mapfs/mim_04_hit.h"

#include "sprite/npc/Bubulb.h"
#include "sprite/npc/Fuzzy.h"

enum {
    NPC_Bubulb                  = 0,
    NPC_Fuzzy                   = 1,
};

#define NAMESPACE mim_04

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupGates);
extern EvtScript N(EVS_SetupExitHint);
extern NpcGroupList N(DefaultNPCs);
