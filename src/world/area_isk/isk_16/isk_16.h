/// @file isk_16.h
/// @brief Dry Dry Ruins - Tutankoopa Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../isk.h"
#include "mapfs/isk_16_shape.h"
#include "mapfs/isk_16_hit.h"

#include "sprite/npc/Tutankoopa.h"
#include "sprite/npc/ChainChomp.h"

enum {
    NPC_Tutankoopa_01           = 0,
    NPC_Tutankoopa_02           = 1,
    NPC_ChainChomp              = 2,
};

enum {
    MV_Unk_01               = MapVar(1),
};

#define NAMESPACE isk_16

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupFlames);
extern EvtScript N(EVS_SpawnStarCard);
extern EvtScript N(EVS_Scene_TutankoopaDefeated);
extern EvtScript N(EVS_Scene_TutankoopaAppears);
extern EvtScript N(EVS_BindExitTriggers);
extern NpcGroupList N(DefaultNPCs);
