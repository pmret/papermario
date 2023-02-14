/// @file kzn_19.h
/// @brief Mt Lavalava - Boss Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kzn.h"
#include "mapfs/kzn_19_shape.h"
#include "mapfs/kzn_19_hit.h"

enum {
    NPC_Kolorado                = 0,
    NPC_Misstar                 = 1,
    NPC_LavaPiranhaHead         = 2,
    NPC_LavaBud_01              = 3,
    NPC_LavaBud_02              = 4,
    NPC_05                      = 5,
};

enum {
    MV_Unk_01                   = MapVar(1),
    MV_VinesData                = MapVar(0),
    MV_BossDefeated             = MapVar(10),
};

#define NAMESPACE kzn_19

extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_UpdateEruption);
extern EvtScript N(EVS_Misstar_Escape);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(BossNPCs);
extern NpcGroupList N(EscapeNPCs);

extern EvtScript N(EVS_TrySpawningStarCard);
extern StaticAnimatorNode* N(AnimModel_MainHeadVine)[];
extern StaticAnimatorNode* N(AnimModel_SideHeadVine)[];
extern StaticAnimatorNode* N(AnimModel_ExtraVine)[];

extern NpcSettings N(NpcSettings_Kolorado);
extern NpcSettings N(NpcSettings_StarSpirit);
extern NpcSettings N(NpcSettings_LavaPiranhaHead);

extern API_CALLABLE(SetAnimatorFlags);
extern API_CALLABLE(GetAnimatedPositionByTreeIndex);
extern API_CALLABLE(GetAnimatedRotationByTreeIndex);
