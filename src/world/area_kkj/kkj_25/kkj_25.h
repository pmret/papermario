/// @file kkj_25.h
/// @brief Peach's Castle - Final Boss Arena (6F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kkj.h"
#include "mapfs/kkj_25_shape.h"
#include "mapfs/kkj_25_hit.h"

#include "sprite/npc/BattleKammy.h"
#include "sprite/npc/Twink.h"
#include "sprite/npc/WorldBowser.h"
#include "sprite/npc/BattleKooper.h"
#include "sprite/npc/BattleParakarry.h"
#include "sprite/npc/BattleBow.h"
#include "sprite/npc/WorldEldstar.h"
#include "sprite/npc/WorldMamar.h"
#include "sprite/npc/WorldSkolar.h"
#include "sprite/npc/WorldMuskular.h"
#include "sprite/npc/WorldMisstar.h"
#include "sprite/npc/WorldKlevar.h"
#include "sprite/npc/WorldKalmar.h"
#include "sprite/npc/StarRod.h"

enum {
	NPC_Bowser_01               = 0,
	NPC_BattleKooper_01         = 1,
	NPC_BattleKammy_01          = 2,
	NPC_BattleKammy_02          = 3,
	NPC_Twink_01                = 4,
	NPC_Bowser_02               = 5,
	NPC_BattleKammy_03          = 6,
	NPC_BattleKammy_04          = 7,
	NPC_Eldstar                 = 8,
	NPC_Mamar                   = 9,
	NPC_Skolar                  = 10,
	NPC_Muskular                = 11,
	NPC_Misstar                 = 12,
	NPC_Klevar                  = 13,
	NPC_Kalmar                  = 14,
	NPC_Bowser_03               = 15,
	NPC_BattleKooper_02         = 16,
	NPC_BattleKammy_05          = 17,
	NPC_Twink_02                = 18,
	NPC_StarRod                 = 19,
};

enum {
    MV_Unk_00       = MapVar(0),
    MV_Unk_01       = MapVar(1),
    MV_Unk_0A       = MapVar(10),
    MV_Unk_0B       = MapVar(11),
    MV_Unk_0C       = MapVar(12),
    MV_Unk_0D       = MapVar(13),
};

#define NAMESPACE kkj_25

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_80247194);
extern EvtScript N(EVS_80245AF0);
extern EvtScript N(EVS_80248998);
extern EvtScript N(EVS_8024B254);
extern EvtScript N(EVS_80247AAC);
extern EvtScript N(EVS_802463F4);
extern EvtScript N(D_802479C4_B0E3C4);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList N(DefaultNPCs);
extern NpcGroupList N(NpcGroup1);
extern NpcGroupList N(NpcGroup2);
