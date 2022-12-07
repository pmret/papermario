/// @file mac_00.h
/// @brief Toad Town - Gate District

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mac.h"
#include "mapfs/mac_00_shape.h"
#include "mapfs/mac_00_hit.h"

#include "sprite/npc/ChuckQuizmo.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/ShyGuy.h"
#include "sprite/npc/RussT.h"
#include "sprite/npc/HarryT.h"
#include "sprite/npc/Toad.h"
#include "sprite/npc/Chan.h"
#include "sprite/npc/TheMaster.h"
#include "sprite/npc/Lee.h"
#include "sprite/npc/Toadette.h"
#include "sprite/npc/ToadKid.h"
#include "sprite/npc/Luigi.h"
#include "sprite/npc/Goompapa.h"
#include "sprite/npc/Goomama.h"
#include "sprite/npc/Gooma.h"
#include "sprite/npc/VannaT.h"

enum {
	NPC_Luigi_01                = 0,
	NPC_Toad_01                 = 1,
	NPC_Toad_02                 = 2,
	NPC_Toad_03                 = 3,
	NPC_Chan                    = 4,
	NPC_Lee                     = 5,
	NPC_ChuckQuizmo             = 6,
	NPC_Toad_04                 = 7,
	NPC_Toad_05                 = 8,
	NPC_Toad_06                 = 9,
	NPC_Toad_07                 = 10,
	NPC_ThreeSisters_01         = 11,
	NPC_ThreeSisters_02         = 12,
	NPC_ThreeSisters_03         = 13,
	NPC_ThreeSisters_04         = 14,
	NPC_Toad_08                 = 15,
	NPC_Toad_09                 = 16,
	NPC_Toad_10                 = 17,
	NPC_ThreeSisters_05         = 18,
	NPC_ToadKid_01              = 19,
	NPC_ToadKid_02              = 20,
	NPC_ShyGuy_01               = 21,
	NPC_ShyGuy_02               = 22,
	NPC_ShyGuy_03               = 23,
	NPC_Toad_11                 = 24,
	NPC_Luigi_Epilogue			= 25,
	NPC_Goompapa_Epilogue		= 26,
	NPC_Goomama_Epilogue		= 27,
	NPC_Gooma_Epilogue			= 28,
	NPC_HarryT                  = 29,
	NPC_VannaT_Epilogue			= 30,
};

enum {
    MF_MusicMixTrigger1       = MapFlag(10),
    MF_MusicMixTrigger2       = MapFlag(11),
};

#define NAMESPACE mac_00

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusicTriggers);
extern EvtScript N(EVS_SetupRooms);
extern EvtScript N(EVS_SetupShop);
extern EvtScript N(EVS_SetupWaterCustomGfx);
extern EvtScript N(EVS_SetupDemo);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_8024F64C);
extern EvtScript N(EVS_Scene_Intro);
extern EvtScript N(EVS_Scene_BeginEpilogue);
extern EvtScript N(EVS_8024BF20);
extern EvtScript N(D_8024FC44_7FA954);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList N(IntroNPCs);
extern NpcGroupList N(EpilogueNPCs);
extern NpcGroupList N(DefaultNPCs);

extern EvtScript ItemShopInteract;
