/// @file nok_02.h
/// @brief Koopa Region - Koopa Village 2

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../nok.h"
#include "mapfs/nok_02_shape.h"
#include "mapfs/nok_02_hit.h"

#include "sprite/npc/ChuckQuizmo.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/KooperWithoutShell.h"
#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/Fuzzy.h"
#include "sprite/npc/KoopaWithoutShell.h"
#include "sprite/npc/Koopa.h"
#include "sprite/npc/WorldKooper.h"
#include "sprite/npc/WorldBobomb.h"
#include "sprite/npc/WorldBombette.h"
#include "sprite/npc/Kolorado.h"
#include "sprite/npc/KoloradoWife.h"
#include "sprite/npc/KoopaKoot.h"

enum {
	NPC_Koopa_00                = 0,
//	NPC_Bombette                = 1,
	NPC_KoloradoWife_01         = 2,
	NPC_KoopaWithoutShell       = 3,
	NPC_Koopa_01                = 4,
	NPC_Koopa_02                = 5,
	NPC_Koopa_03                = 6,
	NPC_Kolorado                = 7,
	NPC_KoloradoWife_02         = 8,
	NPC_KoopaKoot               = 9,
	NPC_Kooper_01               = 10,
	NPC_Kooper_02               = 11,
	NPC_Fuzzy_01                = 12,
	NPC_MiscFuzzy1              = 13,
	NPC_MiscFuzzy2                = 14,
	NPC_Fuzzy_04                = 15,
	NPC_Bobomb_01               = 16,
	NPC_Bobomb_02               = 17,
	NPC_Bobomb_03               = 18,
	NPC_ChuckQuizmo             = 19,
	// epilogue
	NPC_Parakarry               = 0,
	NPC_Bombette                = 1,
};

enum {
    MV_Unk_00       = MapVar(0),
    MV_Unk_01       = MapVar(1),
    MV_Unk_02       = MapVar(2),
    MV_Unk_03       = MapVar(3),
    MV_StarPieceItem	= MapVar(10),
};

enum {
    MF_Unk_00       = MapFlag(0),
    MF_Unk_0A       = MapFlag(10),
};

#define NAMESPACE nok_02

extern EvtScript N(EVS_Main);
extern EvtScript N(D_802446A0_9DB6C0);
extern EvtScript N(EVS_Scene_Epilogue);
extern EvtScript N(EVS_Setup_Bookshelf);
extern EvtScript N(EVS_80246B50);
extern EvtScript N(EVS_SetupDemo);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_BreakBlock_DropShell);
extern EvtScript N(EVS_8024A8EC);
extern EvtScript N(EVS_8024A908);
extern EvtScript N(D_8025254C_9E956C);
extern EvtScript N(D_802526D0_9E96F0);
extern EvtScript N(D_80252754_9E9774);
extern EvtScript N(D_80252724_9E9744);
extern EvtScript N(D_8024988C_9E08AC);
extern EvtScript N(EVS_80253350);
extern EvtScript N(EVS_NpcInteract_KoopaKoot);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupFoliage);
extern NpcGroupList N(EpilogueNPCs);
extern NpcGroupList N(CrisisNPCs);
extern NpcGroupList N(NormalNPCs);
