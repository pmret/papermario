/// @file mac_06.h
/// @brief Toad Town - Riding the Whale

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mac.h"
#include "mapfs/mac_06_shape.h"
#include "mapfs/mac_06_hit.h"

#include "sprite/npc/Kolorado.h"
#include "sprite/npc/JrTroopa.h"

enum {
    NPC_Whale           = 0,
    NPC_01              = 1,
    NPC_Kolorado        = 2,
    NPC_JrTroopa        = 3,
};

enum {
    MV_Unk_00           = MapVar(0),
    MV_Unk_01           = MapVar(1),
    MV_Unk_02           = MapVar(2),
};

#define NAMESPACE mac_06

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_FlyingGull);
extern EvtScript N(EVS_WhaleMain);

extern NpcGroupList N(DefaultNPCs);
