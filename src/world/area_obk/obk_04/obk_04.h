/// @file obk_04.h
/// @brief Boo's Mansion - Super Boots Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../obk.h"
#include "mapfs/obk_04_shape.h"
#include "mapfs/obk_04_hit.h"

#include "sprite/npc/Boo.h"

enum {
	NPC_Boo_01                  = 0,
	NPC_Boo_02                  = 1,
	NPC_Boo_03                  = 2,
	NPC_Boo_04                  = 3,
	NPC_Boo_05                  = 4,
	NPC_Boo_06                  = 5,
	NPC_Boo_07                  = 6,
	NPC_Boo_08                  = 7,
	NPC_Boo_09                  = 8,
	NPC_Boo_10                  = 9,
	NPC_Boo_11                  = 10,
	NPC_Boo_12                  = 11,
};

enum {
    MV_Unk_00       = MapVar(0),
    MV_Unk_01       = MapVar(1),
    MV_Unk_02       = MapVar(2),
    MV_Unk_03       = MapVar(3),
    MV_Unk_04       = MapVar(4),
    MV_Unk_05       = MapVar(5),
    MV_Unk_06       = MapVar(6),
    MV_Unk_07       = MapVar(7),
    MV_Unk_08       = MapVar(8),
    MV_Unk_09       = MapVar(9),
};

enum {
    MF_Unk_0A       = MapFlag(10),
};

#define NAMESPACE obk_04

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PlayUpgradeSong);
extern EvtScript N(EVS_Scene_BoosUnleashed);
extern EvtScript N(EVS_ManageHole);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
