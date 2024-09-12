// Older version of flo_21

#include "dead.h"
#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../flo.h"
#include "mapfs/flo_21_shape.h"
#include "mapfs/flo_21_hit.h"

enum {
    NPC_HuffNPuff_01            = 0,
    NPC_HuffNPuff_02            = 1,
    NPC_HuffNPuff_03            = 2,
    NPC_RuffPuff_01             = 3,
    NPC_RuffPuff_02             = 4,
    NPC_RuffPuff_03             = 5,
    NPC_RuffPuff_04             = 6,
    NPC_RuffPuff_05             = 7,
    NPC_RuffPuff_06             = 8,
    NPC_RuffPuff_07             = 9,
    NPC_RuffPuff_08             = 10,
    NPC_RuffPuff_09             = 11,
    NPC_RuffPuff_10             = 12,
    NPC_RuffPuff_11             = 13,
    NPC_RuffPuff_12             = 14,
    NPC_RuffPuff_13             = 15,
    NPC_RuffPuff_14             = 16,
    NPC_RuffPuff_15             = 17,
};

enum {
    MV_Unk_00           = MapVar(0),
    MV_Unk_01           = MapVar(1),
    MV_Unk_02           = MapVar(2),
    MV_Unk_03           = MapVar(3),
    MV_Unk_04           = MapVar(4),
    MV_BossDefeated     = MapVar(10),
    MV_HuffScaleX       = MapVar(11),
    MV_HuffScaleY       = MapVar(12),
    MV_BossFightState   = MapVar(13),
};

#define NAMESPACE dead_flo_21

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupCloudPuffs);
extern EvtScript N(EVS_Scene_HuffNPuffAmbush);
extern EvtScript N(EVS_TrySpawningStarCard);

extern NpcGroupList N(DefaultNPCs);
