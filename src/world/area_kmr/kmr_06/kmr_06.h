/// @file kmr_06.h
/// @brief Goomba Region - Goomba Road 2

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kmr.h"
#include "mapfs/kmr_06_shape.h"
#include "mapfs/kmr_06_hit.h"

#include "sprite/npc/SpikedGoomba.h"
#include "sprite/npc/Paragoomba.h"

enum {
	NPC_SpikedGoomba            = 0,
	NPC_Paragoomba              = 1,
};

enum {
    MF_Unk_0A           = MapFlag(10),
};

#define NAMESPACE kmr_06

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupStickerSign);
extern NpcGroupList N(DefaultNPCs);
