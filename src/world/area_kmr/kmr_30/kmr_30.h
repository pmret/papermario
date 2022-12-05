/// @file kmr_30.h
/// @brief Goomba Region - Mario's House (Ending)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kmr.h"
#include "mapfs/kmr_30_shape.h"
#include "mapfs/kmr_30_hit.h"

#include "sprite/npc/ParadePeach.h"

enum {
    NPC_ParadePeach             = 0,
};

#define NAMESPACE kmr_30

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_Scene_TheEnd);
extern NpcGroupList N(DefaultNPCs);
