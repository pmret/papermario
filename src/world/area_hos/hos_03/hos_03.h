/// @file hos_03.h
/// @brief Shooting Star Summit - Star Haven

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../hos.h"
#include "mapfs/hos_03_shape.h"
#include "mapfs/hos_03_hit.h"

#include "sprite/npc/StarKid.h"
#include "sprite/npc/ChuckQuizmo.h"

enum {
	NPC_StarKid_01              = 0,
	NPC_StarKid_02              = 1,
	NPC_StarKid_03              = 2,
	NPC_StarKid_04              = 3,
	NPC_StarKid_05              = 4,
	NPC_StarKid_ToadHouse       = 5,
	NPC_StarKid_ShopOwner       = 6,
	NPC_ChuckQuizmo             = 7,
};

#define NAMESPACE hos_03

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PlayRestingSong);
extern EvtScript N(EVS_SetupAurora);
extern EvtScript N(EVS_SetupRooms);
extern EvtScript N(EVS_SetupShop);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
