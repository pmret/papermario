/// @file mgm_01.h
/// @brief Minigame - Jump Attack Minigame

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mgm.h"
#include "mapfs/mgm_01_shape.h"
#include "mapfs/mgm_01_hit.h"

#include "sprite/npc/Toad.h"

enum {
    NPC_Toad                    = 0,
};

#define NAMESPACE mgm_01

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_802424A4);
extern NpcGroupList N(DefaultNPCs);

API_CALLABLE(N(SetMsgImgs_Panels));

void delete_entity(s32 entityIndex);
