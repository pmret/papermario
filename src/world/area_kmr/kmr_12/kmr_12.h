/// @file kmr_12.h
/// @brief Goomba Region - Goomba Road 4

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kmr.h"
#include "mapfs/kmr_12_shape.h"
#include "mapfs/kmr_12_hit.h"

#include "sprite/npc/Goomba.h"

enum {
    NPC_Goomba_Ambush   = 0,
};

#define NAMESPACE kmr_12

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_OnReadBillboard);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
