/// @file mac_01.h
/// @brief Toad Town - Plaza District

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../mac.h"
#include "mapfs/mac_01_shape.h"
#include "mapfs/mac_01_hit.h"

#include "sprite/npc/Merlon.h"
#include "sprite/npc/ChuckQuizmo.h"
#include "sprite/npc/Toad.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/Kolorado.h"
#include "sprite/npc/DarkToad.h"
#include "sprite/npc/KoopaBros.h"
#include "sprite/npc/Ninji.h"
#include "sprite/npc/Rowf.h"
#include "sprite/npc/Postmaster.h"
#include "sprite/npc/ShyGuy.h"
#include "sprite/npc/MinhT.h"
#include "sprite/npc/Bubulb.h"
#include "sprite/npc/Twink.h"
#include "sprite/npc/Luigi.h"
#include "sprite/npc/KoloradoWife.h"
#include "sprite/npc/KoopaKoot.h"
#include "sprite/npc/WorldBobomb.h"
#include "sprite/npc/Koopa.h"
#include "sprite/npc/Dryite.h"
#include "sprite/npc/Chanterelle.h"
#include "sprite/npc/Musician.h"

enum {
    NPC_Luigi                   = 0,
	NPC_Merlon                  = 0,
    NPC_Toad_01                 = 1,
    NPC_Toad_02                 = 2,
    NPC_Toad_03                 = 3,
    NPC_Parakarry               = 4,
    NPC_ChuckQuizmo             = 5,
    NPC_ShyGuy_01               = 6,
    NPC_ShyGuy_02               = 7,
    NPC_ShyGuy_03               = 8,
    NPC_ShyGuy_04               = 9,
    NPC_Toad_04                 = 10,
    NPC_Toad_05                 = 11,
    NPC_Toad_06                 = 12,
    NPC_Toad_07                 = 13,
    NPC_Toad_08                 = 14,
    NPC_Toad_09                 = 15,
    NPC_Toad_10                 = 16,
    NPC_Bubulb                  = 17,
    NPC_MinhT                   = 18,
    NPC_Kolorado                = 19,
    NPC_DarkToad_01             = 20,
    NPC_DarkToad_02             = 21,
    NPC_DarkToad_03             = 22,
    NPC_DarkToad_04             = 23,
    NPC_KoopaBros_01            = 24,
    NPC_KoopaBros_02            = 25,
    NPC_KoopaBros_03            = 26,
    NPC_KoopaBros_04            = 27,
    NPC_Twink                   = 28,
    NPC_Ninji                   = 29,
    NPC_KoloradoWife            = 30,
    NPC_KoopaKoot               = 31,
    NPC_Koopa                   = 32,
    NPC_Bombomb                 = 33,
    NPC_Dryite_01               = 34,
    NPC_Dryite_02               = 35,
    NPC_Chanterelle             = 36,
    NPC_ArtistToad_01           = 37,
    NPC_ArtistToad_02           = 38,
};

enum {
    MV_Unk_00       = MapVar(0),
    MV_Unk_01       = MapVar(1),
    MV_Unk_02       = MapVar(2),
    MV_Unk_0A       = MapVar(10),
    MV_Unk_0C       = MapVar(12),
    MV_Unk_0D       = MapVar(13),
    MV_Unk_0E       = MapVar(14),
};

enum {
    MF_MusicMixTrigger1       = MapFlag(10),
    MF_MusicMixTrigger2       = MapFlag(11),
    MF_MusicMixTrigger3       = MapFlag(12),
	MF_Unk_0B		= MapFlag(11),
    MF_Unk_0D       = MapFlag(13),
    MF_Unk_0E       = MapFlag(14),
    MF_Unk_0F       = MapFlag(15),
	MF_Unk_14		= MapFlag(20),
};

#define NAMESPACE mac_01

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_80259AD0);
extern EvtScript N(EVS_802488A8);
extern EvtScript N(EVS_80257844);
extern EvtScript N(EVS_802502AC);
extern EvtScript N(EVS_80252EB0);
extern EvtScript N(EVS_8024F27C);
extern EvtScript N(EVS_8025023C);
extern EvtScript N(D_80261880_822100);
extern EvtScript N(EVS_8025A004);
extern EvtScript N(EVS_80248070);
extern EvtScript N(EVS_8025A2F0);
extern EvtScript N(EVS_80247D18);
extern EvtScript N(EVS_SetupBulletinBoard);
extern EvtScript N(EVS_802468F8);
extern EvtScript N(EVS_80248428);
extern EvtScript N(EVS_80246924);
extern EvtScript N(EVS_80246824);
extern EvtScript N(EVS_80246850);
extern EvtScript N(D_80246770_806FF0);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList N(IntroNPCs);
extern NpcGroupList N(EpilogueNPCs);
extern NpcGroupList N(NpcGroup2);
extern NpcGroupList N(NpcGroup3);
extern NpcGroupList N(NpcGroup4);
extern NpcGroupList N(NpcGroup5);
extern NpcGroupList N(NpcGroup6);
extern NpcGroupList N(NpcGroup7);
