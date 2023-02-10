/// @file jan_22.h
/// @brief Jade Jungle - Path to the Volcano

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../jan.h"
#include "mapfs/jan_22_shape.h"
#include "mapfs/jan_22_hit.h"

#include "sprite/npc/Raven.h"
#include "sprite/npc/RaphaelRaven.h"
#include "sprite/npc/Kolorado.h"
#include "sprite/npc/SpearGuy.h"
#include "sprite/npc/WorldMisstar.h"

enum {
	NPC_Kolorado_01             = 0,
	NPC_Kolorado_02             = 1,
	NPC_Kolorado_03             = 2,
	NPC_Kolorado_04             = 3,
	NPC_SpearGuy                = 4,
	NPC_RaphaelRaven            = 5,
	NPC_Raven_01                = 6,
	NPC_Raven_02                = 7,
	NPC_Raven_03                = 8,
	NPC_Raven_04                = 9,
	NPC_Raven_05                = 10,
	NPC_Misstar                 = 11,
};

enum {
    MV_BushOffsetL      = MapVar(0),
    MV_BushOffsetR      = MapVar(1),
};

enum {
	MF_Unk_0A		= MapFlag(10),
	MF_Unk_0B		= MapFlag(11),
};

#define NAMESPACE jan_22

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_80246780);
extern EvtScript N(EVS_802467DC);
extern EvtScript N(EVS_SeparateBushesImmediately);
extern EvtScript N(D_80244BD0_B88D50);
extern EvtScript N(EVS_80249EC4);
extern EvtScript N(D_80242CE4_B86E64);
extern EvtScript N(EVS_SetupTrees);
extern EvtScript N(EVS_SetupBushes);
extern EvtScript N(EVS_MoveBushes);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList(N(DefaultNPCs));
extern NpcGroupList(N(RavenNPCs));
