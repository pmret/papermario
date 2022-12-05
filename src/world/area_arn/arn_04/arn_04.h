/// @file arn_04.h
/// @brief Gusty Gulch - Wasteland Ascent 2

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../arn.h"
#include "mapfs/arn_04_shape.h"
#include "mapfs/arn_04_hit.h"

#include "sprite/npc/Paragoomba.h"
#include "sprite/npc/Goomba.h"
#include "sprite/npc/Cleft.h"

enum {
    NPC_HyperParagoomba     = 0,
    NPC_HyperGoomba         = 1,
    NPC_HyperCleft_01       = 2,
    NPC_HyperCleft_02       = 3,
};

#define NAMESPACE arn_04

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
