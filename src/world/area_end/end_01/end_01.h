/// @file end_01.h
/// @brief Ending - Parade (Night)

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../end.h"
#include "mapfs/end_01_shape.h"
#include "mapfs/end_01_hit.h"

#include "sprite/npc/BattleEldstar.h"
#include "sprite/npc/BattleMamar.h"
#include "sprite/npc/BattleSkolar.h"
#include "sprite/npc/BattleMuskular.h"
#include "sprite/npc/BattleMisstar.h"
#include "sprite/npc/BattleKlevar.h"
#include "sprite/npc/BattleKalmar.h"

#include "sprite/npc/ParadeIceShow.h"
#include "sprite/npc/Musician.h"

#include "sprite/npc/Sun.h"
#include "sprite/npc/Dayzee.h"
#include "sprite/npc/ParadeWizard.h"
#include "sprite/npc/Bubulb.h"

#include "sprite/npc/ShyGuy.h"
#include "sprite/npc/PyroGuy.h"
#include "sprite/npc/ParadeShyGuy.h"

#include "sprite/npc/ParadeHorn.h"
#include "sprite/npc/ParadeDrummer.h"
#include "sprite/npc/ParadeTwirler.h"
#include "sprite/npc/ParadeBanner.h"

#include "sprite/npc/ParadeMario.h"
#include "sprite/npc/ParadePeach.h"
#include "sprite/npc/ParadeTwink.h"

enum {
    NPC_Eldstar                 = 0,
    NPC_Mamar                   = 1,
    NPC_Skolar                  = 2,
    NPC_Muskular                = 3,
    NPC_Misstar                 = 4,
    NPC_Klevar                  = 5,
    NPC_Kalmar                  = 6,
    NPC_PenguinSkater1          = 7,
    NPC_PenguinSkater2          = 8,
    NPC_PenguinMayor            = 9,
    NPC_PenguinMayorWife        = 10,
    NPC_ViolinPlayer1           = 11,
    NPC_ViolinPlayer2           = 12,
    NPC_ViolinPlayer3           = 13,
    NPC_Conductor               = 14,
    NPC_Singer                  = 15,
    NPC_AmayzeDayzee1           = 16,
    NPC_AmayzeDayzee2           = 17,
    NPC_Merle                   = 18,
    NPC_Merlee                  = 19,
    NPC_Merlon                  = 20,
    NPC_Merluvlee               = 21,
    NPC_Merlow                  = 22,
    NPC_Merlar                  = 23,
    NPC_SunSad                  = 24,
    NPC_SunHappy                = 25,
    NPC_Bubulb1                = 26,
    NPC_Bubulb2                = 27,
    NPC_ShyGuyMarshall          = 28,
    NPC_GeneralGuy              = 29,
    NPC_BackupDancer1           = 30,
    NPC_BackupDancer2           = 31,
    NPC_GrooveGuy1              = 32,
    NPC_GrooveGuy2              = 33,
    NPC_GrooveGuy3              = 34,
    NPC_GrooveGuy4              = 35,
    NPC_PyroGuy1                = 36,
    NPC_PyroGuy2                = 37,
    NPC_ShyGuyFormation11       = 38,
    NPC_ShyGuyFormation12       = 39,
    NPC_ShyGuyFormation13       = 40,
    NPC_ShyGuyFormation21       = 41,
    NPC_ShyGuyFormation22       = 42,
    NPC_ShyGuyFormation23       = 43,
    NPC_ShyGuyFormation31       = 44,
    NPC_ShyGuyFormation32       = 45,
    NPC_ShyGuyFormation33       = 46,
    NPC_ShyGuyFormation41       = 47,
    NPC_ShyGuyFormation42       = 48,
    NPC_ShyGuyFormation43       = 49,
    NPC_Pratfaller              = 50,
    NPC_HornPlayer1             = 51,
    NPC_HornPlayer2             = 52,
    NPC_Drummer1                = 53,
    NPC_Drummer2                = 54,
    NPC_StandardBearer1         = 55,
    NPC_StandardBearer2         = 56,
    NPC_Mario                   = 57,
    NPC_Peach                   = 58,
    NPC_Twink                   = 59,
    NPC_Twirler1                = 60,
    NPC_Twirler2                = 61,
    NPC_Twirler3                = 62,
    NPC_Baton1                  = 63,
    NPC_Baton2                  = 64,
    NPC_Baton3                  = 65,
    NPC_StandardBearer3         = 66,
    NPC_StandardBearer4         = 67,
};

#define PARADE_SCROLL_RATE (2.0f/3.0f)

enum {
    PARADE_START                = -3135,
    PARADE_PHASE_SKATERS        = -3000,
    PARADE_PHASE_MAYOR          = -2950,
    PARADE_PHASE_OPERA          = -2945,
    PARADE_PHASE_WIZARDS        = -2450,
    PARADE_PHASE_SHYGUY_DANCE   = -1778,
    PARADE_PHASE_SHYGUY_MARCH   = -1248,
    PARADE_PHASE_TOADS          = -889,
    PARADE_PHASE_PEACH          = -689,
    PARADE_PHASE_EXIT           = -330,
};

#define NAMESPACE end_01

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_ManageParade);
extern EvtScript N(EVS_OffsetNpcScroll);

API_CALLABLE(N(AddScrollToNpcPos));
