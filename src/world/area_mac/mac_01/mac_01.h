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
    // intro NPCs
    NPC_Luigi                   = 0,
    NPC_IntroToad1              = 1,
    NPC_IntroToad2              = 2,
    NPC_IntroToad3              = 3,
    // standard NPCs
    NPC_Merlon                  = 0,
    NPC_Rowf                    = 1,
    NPC_Rhuff                   = 2,
    NPC_Postmaster              = 3,
    NPC_Parakarry               = 4,
    NPC_ChuckQuizmo             = 5,
    NPC_PostOfficeShyGuy        = 6,
    NPC_ToadHouseShyGuy         = 7,
    NPC_GardenShyGuy1           = 8,
    NPC_GardenShyGuy2           = 9,
    NPC_Toad_04                 = 10,
    NPC_Toad_05                 = 11,
    NPC_Toad_06                 = 12,
    NPC_Toad_07                 = 13,
    NPC_Toad_08                 = 14,
    NPC_Toad_09                 = 15,
    NPC_ToadHouseToad           = 16,
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
    NPC_Bobomb                  = 33,
    NPC_Dryite_01               = 34,
    NPC_Dryite_02               = 35,
    NPC_Chanterelle             = 36,
    NPC_Poet                    = 37,
    NPC_Composer                = 38,
};

enum {
    MV_RowfRugRippleAmount  = MapVar(0),
    MV_RowfRugRotateAngle   = MapVar(1),
    MV_RowfShopBuyFlags     = MapVar(2),
    MV_KnockdownWorker      = MapVar(10),
    MV_FortuneFXHandles     = MapVar(12),
    MV_BadgeShopOpenState   = MapVar(13),
    MV_BadgeShopCloseState  = MapVar(14),
};

enum {
    MF_MusicMixTrigger1     = MapFlag(10),
    MF_MusicMixTrigger2     = MapFlag(11),
    MF_MusicMixTrigger3     = MapFlag(12),
    MF_BadgeShopOpen        = MapFlag(11),
    MF_SpawnFlag_Tree1      = MapFlag(13),
    MF_SetupMusicMixes      = MapFlag(14),
    MF_InsideToadHouse      = MapFlag(15),
    MF_KoopaBrosSceneLock   = MapFlag(20),
};

#define NAMESPACE mac_01

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_SetupMusicMix);
extern EvtScript N(EVS_PlayRestingSong);
extern EvtScript N(EVS_PlaySpellcastSong);
extern EvtScript N(EVS_PlayFlowerGateSong);
extern EvtScript N(EVS_ResetMusicAfterFortune);
extern EvtScript N(EVS_SetupRooms);
extern EvtScript N(EVS_SetupBadgeShop);
extern EvtScript N(EVS_SetupBulletinBoard);
extern EvtScript N(EVS_SetupCrystalBallGfx);
extern EvtScript N(EVS_SetupFlowerModels);
extern EvtScript N(EVS_EnterFlowerGate);
extern EvtScript N(EVS_ExitFlowerGate);
extern EvtScript N(EVS_Merlon_GiveHint);
extern EvtScript N(EVS_MerlonShooAway);
extern EvtScript N(EVS_SetupQuickChangeTrigger);
extern EvtScript N(EVS_Scene_IntroWalking);
extern EvtScript N(EVS_Scene_MailbagTheft);
extern EvtScript N(EVS_Scene_MerlonAndNinji);
extern EvtScript N(EVS_SetupFoliage);
extern EvtScript N(EVS_MakeEntities);

extern NpcGroupList N(IntroNPCs);
extern NpcGroupList N(EpilogueNPCs);
extern NpcGroupList N(Chapter0NPCs);
extern NpcGroupList N(Chapter1NPCs);
extern NpcGroupList N(TwinkMeetingNPCs);
extern NpcGroupList N(Chapter4NPCs);
extern NpcGroupList N(NinjiMeetingNPCs);
extern NpcGroupList N(DefaultNPCs);

extern ShopItemData N(RowfBadgeInventory)[16];
