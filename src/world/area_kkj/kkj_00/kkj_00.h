/// @file kkj_00.h
/// @brief Peach's Castle - Intro Entry Hall (1F)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kkj.h"
#include "mapfs/kkj_00_shape.h"
#include "mapfs/kkj_00_hit.h"

#include "sprite/npc/Luigi.h"
#include "sprite/npc/Toad.h"
#include "sprite/npc/RussT.h"
#include "sprite/npc/ShiverToad.h"
#include "sprite/npc/Toadette.h"
#include "sprite/npc/Penguin.h"
#include "sprite/npc/ToadGuard.h"
#include "sprite/npc/ToadMinister.h"
#include "sprite/npc/TayceT.h"
#include "sprite/npc/WorldGoombario.h"
#include "sprite/npc/WorldKooper.h"
#include "sprite/npc/WorldBombette.h"
#include "sprite/npc/WorldParakarry.h"
#include "sprite/npc/WorldBow.h"
#include "sprite/npc/WorldWatt.h"
#include "sprite/npc/WorldSushie.h"
#include "sprite/npc/WorldLakilester.h"
#include "sprite/npc/Merlon.h"
#include "sprite/npc/Merluvlee.h"
#include "sprite/npc/Merlow.h"
#include "sprite/npc/WorldMerlee.h"
#include "sprite/npc/Merle.h"
#include "sprite/npc/Lakilulu.h"
#include "sprite/npc/Bootler.h"
#include "sprite/npc/Goompa.h"
#include "sprite/npc/Goombaria.h"
#include "sprite/npc/Yoshi.h"
#include "sprite/npc/Dryite.h"
#include "sprite/npc/Ninji.h"

enum {
    // intro
    NPC_Luigi               = 0,
    NPC_Toad_01             = 1,
    NPC_Toad_02             = 2,
    NPC_Toad_03             = 3,
    NPC_Toadette_01         = 4,
    NPC_Toadette_02         = 5,
    NPC_RussT_01            = 6,
    NPC_ShiverToad_01       = 7,
    NPC_Penguin_01          = 8,
    NPC_ToadGuard_01        = 9,
    NPC_ToadGuard_02        = 10,
    // ending
    NPC_Peach               = 0,
    NPC_ToadMinister        = 1,
    NPC_TayceT              = 2,
    NPC_RussT_02            = 3,
    NPC_ShiverToad_02       = 4,
    NPC_Goombario           = 5,
    NPC_Kooper              = 6,
    NPC_Bombette            = 7,
    NPC_Parakarry           = 8,
    NPC_Bow                 = 9,
    NPC_Watt                = 10,
    NPC_Sushie              = 11,
    NPC_Lakilester          = 12,
    NPC_Merlon              = 13,
    NPC_Merluvlee           = 14,
    NPC_Merlow              = 15,
    NPC_Merlee              = 16,
    NPC_Merle               = 17,
    NPC_Lakilulu            = 18,
    NPC_Bootler             = 19,
    NPC_Goompa              = 20,
    NPC_Goombaria           = 21,
    NPC_Yoshi               = 22,
    NPC_Penguin_02          = 24,
    NPC_Penguin_03          = 25,
    NPC_Dryite              = 26,
    NPC_Ninji               = 28,
    NPC_Toad_04             = 31,
    NPC_Toad_05             = 32,
    NPC_Toad_06             = 33,
    NPC_Toad_07             = 34,
    NPC_Toadette_03         = 36,
    NPC_Toadette_04         = 37,
    NPC_Toadette_05         = 38,
    NPC_Toadette_06         = 39,
    NPC_ToadGuard_03        = 40,
    NPC_ToadGuard_04        = 41,
    NPC_ToadGuard_05        = 42,
    NPC_ToadGuard_06        = 44,
    NPC_ToadGuard_07        = 46,
};

#define NAMESPACE kkj_00

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_Scene_Intro);
extern EvtScript N(EVS_Scene_Ending);

extern NpcGroupList N(IntroNPCs);
extern NpcGroupList N(EndingNPCs);
