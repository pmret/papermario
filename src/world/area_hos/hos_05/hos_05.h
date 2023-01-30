/// @file hos_05.h
/// @brief Shooting Star Summit - Star Sanctuary

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../hos.h"
#include "mapfs/hos_05_shape.h"
#include "mapfs/hos_05_hit.h"

#include "sprite/npc/WorldEldstar.h"
#include "sprite/npc/WorldMamar.h"
#include "sprite/npc/WorldSkolar.h"
#include "sprite/npc/WorldMuskular.h"
#include "sprite/npc/WorldMisstar.h"
#include "sprite/npc/WorldKlevar.h"
#include "sprite/npc/WorldKalmar.h"
#include "sprite/npc/WorldBowser.h"
#include "sprite/npc/WorldKammy.h"
#include "sprite/npc/StarRod.h"

enum {
	NPC_Eldstar                 = 0,
	NPC_Mamar                   = 1,
	NPC_Skolar                  = 2,
	NPC_Muskular                = 3,
	NPC_Misstar                 = 4,
	NPC_Klevar                  = 5,
	NPC_Kalmar                  = 6,
	NPC_Bowser_01               = 7,
	NPC_Bowser_02               = 8,
	NPC_Kammy                   = 9,
	NPC_StarRod                 = 10,
};

enum {
	MV_Unk_0A		= MapVar(10),
	MV_Unk_0B		= MapVar(11),
	MV_Unk_0C		= MapVar(12),
	MV_Unk_0D		= MapVar(13),
};

#define NAMESPACE hos_05

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_8024DF28);
extern EvtScript N(EVS_8024E148);
extern EvtScript N(EVS_8024E828);
extern EvtScript N(D_80245E0C_A3004C);
extern EvtScript N(EVS_8024ED24);
extern EvtScript N(EVS_8024ACC0);
extern EvtScript N(D_8024DBDC_A37E1C);
extern EvtScript N(EVS_8024E00C);
extern NpcGroupList N(DefaultNPCs);
extern NpcGroupList N(NpcGroup1);



void N(func_80243100_A2D340)(void);
void N(func_80244C8C_A2EECC)(void);
API_CALLABLE(N(func_80244C60_A2EEA0));
