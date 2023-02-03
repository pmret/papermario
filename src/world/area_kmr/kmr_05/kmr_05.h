/// @file kmr_05.h
/// @brief Goomba Region - Behind the Village

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kmr.h"
#include "mapfs/kmr_05_shape.h"
#include "mapfs/kmr_05_hit.h"

#include "sprite/npc/Goompa.h"
#include "sprite/npc/Goomba.h"
#include "sprite/npc/SpikedGoomba.h"
#include "sprite/npc/Paragoomba.h"

enum {
    NPC_Goomba_01               = 0,
    NPC_Goomba_02               = 2,
    NPC_SpikedGoomba            = 3,
    NPC_Paragoomba              = 4,
    NPC_06                      = 6,
};

enum {
    AF_JAN01_TreeDrop_StarPiece           = MapFlag(10),
};

#define NAMESPACE kmr_05

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_GoompaRemark);
extern NpcGroupList N(NpcsBefore);
extern NpcGroupList N(NpcsAfter);
