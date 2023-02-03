/// @file nok_01.h
/// @brief Koopa Region - Koopa Village 1

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../nok.h"
#include "mapfs/nok_01_shape.h"
#include "mapfs/nok_01_hit.h"

#include "sprite/npc/Toad.h"
#include "sprite/npc/ChuckQuizmo.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/Fuzzy.h"
#include "sprite/npc/Koopa.h"
#include "sprite/npc/KoopaWithoutShell.h"
#include "sprite/npc/WorldBobomb.h"
#include "sprite/npc/WorldBombette.h"

enum {
	NPC_Koopa_01                = 0,
	NPC_Fuzzy_01                = 1,
	NPC_Koopa_02                = 2,
	NPC_KoopaWithoutShell_01    = 3,
	NPC_Koopa_03                = 4,
	NPC_KoopaWithoutShell_02    = 5,
	NPC_Koopa_04                = 6,
	NPC_Koopa_05                = 7,
	NPC_Toad                    = 8,
	NPC_Koopa_06                = 9,
	NPC_Fuzzy_02                = 10,
	NPC_Fuzzy_03                = 11,
	NPC_Bombomb_01              = 12,
	NPC_Bombomb_02              = 13,
	NPC_Bombomb_03              = 14,
	NPC_ChuckQuizmo             = 15,
};

enum {
    MF_Unk_0A       = MapFlag(10),
    MF_Unk_0B       = MapFlag(11),
    MF_Unk_0C       = MapFlag(12),
    MF_Unk_0D       = MapFlag(13),
};

#define NAMESPACE nok_01

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PlayRestingSong);
extern EvtScript N(EVS_8024A758);
extern EvtScript N(EVS_SetupShop);
extern EvtScript N(EVS_80250B70);
extern EvtScript N(EVS_802506C0);
extern EvtScript N(EVS_80249E24);
extern EvtScript N(EVS_80242C38);
extern EvtScript N(EVS_80242DE0);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList N(DefaultNPCs);
extern NpcGroupList N(NpcGroup1);

API_CALLABLE(N(func_802427C0_9C7BA0));
API_CALLABLE(N(func_80242804_9C7BE4));
API_CALLABLE(N(func_80242858_9C7C38));
API_CALLABLE(N(func_80242898_9C7C78));
API_CALLABLE(N(func_802428B8_9C7C98));
API_CALLABLE(N(func_802428D8_9C7CB8));
