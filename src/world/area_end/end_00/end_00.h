/// @file end_00.h
/// @brief Ending - Parade (Day)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../end.h"
#include "mapfs/end_00_shape.h"
#include "mapfs/end_00_hit.h"

#include "sprite/npc/ParadeLuigi.h"
#include "sprite/npc/ParadePartner.h"
#include "sprite/npc/ParadeToad.h"
#include "sprite/npc/ChuckQuizmo.h"
#include "sprite/npc/VannaT.h"
#include "sprite/npc/KoopaBros.h"
#include "sprite/npc/Bobomb.h"
#include "sprite/npc/ParadeKolorado.h"
#include "sprite/npc/Rowf.h"
#include "sprite/npc/Moustafa.h"
#include "sprite/npc/Mouser.h"
#include "sprite/npc/Tutankoopa.h"
#include "sprite/npc/ChainChomp.h"
#include "sprite/npc/Buzzar.h"
#include "sprite/npc/ParadeChick.h"
#include "sprite/npc/TubbasHeart.h"
#include "sprite/npc/Bootler.h"
#include "sprite/npc/Boo.h"
#include "sprite/npc/ParadeTubba.h"
#include "sprite/npc/GoombaBros.h"
#include "sprite/npc/GoombaKing.h"
#include "sprite/npc/HuffNPuff.h"
#include "sprite/npc/RuffPuff.h"
#include "sprite/npc/GourmetGuy.h"

#include "sprite/npc/RaphaelRaven.h"
#include "sprite/npc/LavaPiranha.h"
#include "sprite/npc/ParadeYoshi.h"
#include "sprite/npc/YoshiKid.h"

#include "sprite/npc/CrystalKing.h"
#include "sprite/npc/Duplighost.h"
#include "sprite/npc/MageJrTroopa.h"
#include "sprite/npc/WorldKammy.h"
#include "sprite/npc/ParadeKoopas.h"
#include "sprite/npc/ParadeBurntBowser.h"

enum {
    NPC_Luigi                   = 0,
    NPC_HornPlayer1             = 1,
    NPC_HornPlayer2             = 2,
    NPC_Drummer1                = 3,
    NPC_Drummer2                = 4,
    NPC_StandardBearer1         = 5,
    NPC_StandardBearer2         = 6,
    NPC_Goombario               = 7,
    NPC_Kooper                  = 8,
    NPC_Bombette                = 9,
    NPC_Parakarry               = 10,
    NPC_Bow                     = 11,
    NPC_Watt                    = 12,
    NPC_Sushie                  = 13,
    NPC_Lakilester              = 14,
    NPC_Twirler1                = 15,
    NPC_Twirler2                = 16,
    NPC_Twirler3                = 17,
    NPC_Baton1                  = 18,
    NPC_Baton2                  = 19,
    NPC_Baton3                  = 20,
    NPC_ChuckQuizmo             = 21,
    NPC_VannaT                  = 22,
    NPC_KoopaBrosRed            = 23,
    NPC_KoopaBrosBlack          = 24,
    NPC_KoopaBrosYellow         = 25,
    NPC_KoopaBrosGreen          = 26,
    NPC_Bobomb1                 = 27,
    NPC_Bobomb2                 = 28,
    NPC_Bobomb3                 = 29,
    NPC_Bobomb4                 = 30,
    NPC_Kolorado                = 31,
    NPC_KoloradoWife            = 32,
    NPC_Rowf                    = 33,
    NPC_Rhuff                   = 34,
    NPC_Moustafa                = 35,
    NPC_Mouser1                 = 36,
    NPC_Mouser2                 = 37,
    NPC_Tutankoopa1             = 38,
    NPC_ChainChomp1             = 39,
    NPC_Buzzar                  = 40,
    NPC_VultureChick1           = 41,
    NPC_VultureChick2           = 42,
    NPC_VultureChick3           = 43,
    NPC_Bootler                 = 44,
    NPC_Tutankoopa2             = 45,
    NPC_ChainChomp2             = 46,
    NPC_ChainChomp3             = 47,
    NPC_ChainChomp4             = 48,
    NPC_TubbasBody              = 49,
    NPC_Boo1                    = 50,
    NPC_Boo2                    = 51,
    NPC_Boo3                    = 52,
    NPC_TubbasHeart             = 53,
    NPC_GoombaKing              = 54,
    NPC_RedGoombaBros           = 55,
    NPC_BlueGoombaBros          = 56,
    NPC_Yoshi1                  = 57,
    NPC_Yoshi2                  = 58,
    NPC_Yoshi3                  = 59,
    NPC_Yoshi4                  = 60,
    NPC_YoshiChief              = 61,
    NPC_RaphaelRaven             = 62,
    NPC_LavaPiranha             = 63,
    NPC_YoshiKidGreen           = 64,
    NPC_YoshiKidBlue            = 65,
    NPC_YoshiKidPurple          = 66,
    NPC_YoshiKidYellow          = 67,
    NPC_YoshiKidRed             = 68,
    NPC_HuffNPuffBody           = 69,
    NPC_HuffNPuffFace           = 70,
    NPC_HuffNPuffArms           = 71,
    NPC_RuffPuff1               = 72,
    NPC_RuffPuff2               = 73,
    NPC_GourmetGuy              = 74,
    NPC_Duplighost1             = 75,
    NPC_Duplighost2             = 76,
    NPC_TrueCrystalKing         = 77,
    NPC_FakeCrystalKing         = 78,
    NPC_CrystalBit1             = 79,
    NPC_CrystalBit2             = 80,
    NPC_CrystalBit3             = 81,
    NPC_Kammy                   = 82,
    NPC_JrTroopa                = 83,
    NPC_Bowser                  = 84,
    NPC_BowserPropeller         = 85,
    NPC_HammerBros1             = 86,
    NPC_HammerBros2             = 87,
    NPC_Koopatrol1              = 88,
    NPC_Koopatrol2              = 89,
    NPC_BurntBowser             = 90,
    NPC_BurntBowserPropeller    = 91,
};

#define PARADE_SCROLL_RATE (2.0f/3.0f)

enum {
    PARADE_START                = -3080,
    PARADE_PHASE_PARTNERS       = -2845,
    PARADE_PHASE_TOAD_TOWN      = -2550,
    PARADE_PHASE_KOOPA_BROS     = -2150,
    PARADE_PHASE_KOLORADO       = -2090,
    PARADE_PHASE_CARAVAN        = -1500,
    PARADE_PHASE_BUZZAR         = -1355,
    PARADE_PHASE_TUTANKOOPA     = -760,
    PARADE_PHASE_BOOS           = -960,
    PARADE_PHASE_GOOMBA_KING    = -310,
    PARADE_PHASE_YOSHIS         = -53,
    PARADE_PHASE_HUFF_PUFF      = 750,
    PARADE_PHASE_CRYSTAL_KING   = 1200,
    PARADE_PHASE_BOWSER         = 1860,
    PARADE_PHASE_DONE           = 2580,
};

#define NAMESPACE end_00

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_ManageParade);
extern EvtScript N(EVS_OffsetNpcScroll);

API_CALLABLE(N(AddScrollToNpcPos));

