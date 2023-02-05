/// @file kmr_03.h
/// @brief Goomba Region - Bottom of the Cliff

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kmr.h"
#include "mapfs/kmr_03_shape.h"
#include "mapfs/kmr_03_hit.h"

#include "sprite/npc/Goompa.h"

enum {
    NPC_Goompa                  = 0,
};

enum {
    MV_Unk_00               = MapVar(0),
};

enum {
    AF_JAN01_TreeDrop_StarPiece               = MapFlag(10),
};

#define NAMESPACE kmr_03

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_Scene_FallingDown);
extern NpcGroupList N(DefaultNPCs);
