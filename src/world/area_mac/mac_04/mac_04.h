/// @file mac_04.h
/// @brief Toad Town - Residental District

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mac.h"
#include "mapfs/mac_04_shape.h"
#include "mapfs/mac_04_hit.h"

#include "sprite/npc/ChuckQuizmo.h"
#include "sprite/npc/WorldMuskular.h"
#include "sprite/npc/Twink.h"
#include "sprite/npc/ShyGuy.h"
#include "sprite/npc/HarryT.h"
#include "sprite/npc/ChetRippo.h"
#include "sprite/npc/Toadette.h"
#include "sprite/npc/Toad.h"
#include "sprite/npc/ToadKid.h"
#include "sprite/npc/Goomama.h"
#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/Goombaria.h"

enum {
	NPC_HarryT                  = 0,
	NPC_ThreeSisters_01         = 1,
	NPC_ThreeSisters_02         = 2,
	NPC_Toad_01                 = 3,
	NPC_Toad_02                 = 4,
	NPC_ToadKid_01              = 5,
	NPC_ToadKid_02              = 6,
	NPC_ToadKid_03              = 7,
	NPC_ThreeSisters_03         = 8,
	NPC_Toad_03                 = 9,
	NPC_Toad_04                 = 10,
	NPC_Toad_05                 = 11,
	NPC_Toad_06                 = 12,
	NPC_ChetRippo               = 13,
	NPC_ShyGuy_01               = 14,
	NPC_ShyGuy_02               = 15,
	NPC_Twink                   = 16,
	NPC_Muskular                = 17,
	NPC_Goomama                 = 18,
	NPC_Goombaria               = 19,
	NPC_ChuckQuizmo             = 20,
	NPC_WishingToadKid          = 21,
};

enum {
	MV_Unk_00				= MapVar(0),
	MV_PlayerShrinkScale	= MapVar(10),
	MV_Unk_0B				= MapVar(11),
};

enum {
	MF_Unk_0A		= MapFlag(10),
};

#define NAMESPACE mac_04

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupShop);
extern EvtScript N(EVS_8024F4E8);
extern EvtScript N(D_80242E48_845A18);
extern EvtScript N(EVS_80248B08);
extern EvtScript N(D_80248798_84B368);
extern EvtScript N(EVS_80242E88);
extern EvtScript N(EVS_80246C58);
extern EvtScript N(EVS_Scene_WishingToadKid);
extern EvtScript N(EVS_8024ECDC);
extern EvtScript N(D_8024697C_84954C);
extern EvtScript N(D_80242E08_8459D8);
extern EvtScript N(EVS_8024F24C);
extern EvtScript N(EVS_MakeEntities);
extern EvtScript N(EVS_SetupFoliage);

extern NpcGroupList N(DefaultNPCs);
extern NpcGroupList N(Chapter4NPCs);
extern NpcGroupList N(Chapter5NPCs);
extern NpcGroupList N(Chapter7NPCs);
extern NpcGroupList N(WishSceneNPCs);
