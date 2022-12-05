/// @file kmr_09.h
/// @brief Goomba Region - Goomba Road 1

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kmr.h"
#include "mapfs/kmr_09_shape.h"
#include "mapfs/kmr_09_hit.h"

enum {
    NPC_Goomba_01               = 0,
    NPC_Goomba_02               = 1,
    NPC_Goomba_Ambush           = 2,
    NPC_Paragoomba              = 3,
};

#define NAMESPACE kmr_09

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_OnReadBillboard);
extern NpcGroupList N(DefaultNPCs);
