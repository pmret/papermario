/// @file kpa_82.h
/// @brief Bowser's Castle - Guard Door 2

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../kpa.h"
#include "mapfs/kpa_80_shape.h"
#include "mapfs/kpa_80_hit.h"

#include "sprite/npc/WorldBobomb.h"

enum {
    NPC_Dummy                   = 0,
    NPC_AntiGuy_01              = 1,
    NPC_AntiGuy_02              = 2,
    NPC_AntiGuy_03              = 3,
    NPC_Goomba_01               = 4,
    NPC_Goomba_02               = 5,
    NPC_Goomba_03               = 6,
    NPC_Goomba_04               = 7,
    NPC_Goomba_05               = 8,
    NPC_RedShyGuy_01            = 10,
    NPC_RedShyGuy_02            = 11,
    NPC_RedShyGuy_03            = 12,
    NPC_RedShyGuy_04            = 13,
    NPC_RedShyGuy_05            = 14,
    NPC_BlueShyGuy_01           = 16,
    NPC_BlueShyGuy_02           = 17,
    NPC_BlueShyGuy_03           = 18,
    NPC_BlueShyGuy_04           = 19,
    NPC_BlueShyGuy_05           = 20,
    NPC_GreenShyGuy_01          = 22,
    NPC_GreenShyGuy_02          = 23,
    NPC_GreenShyGuy_03          = 24,
    NPC_GreenShyGuy_04          = 25,
    NPC_GreenShyGuy_05          = 26,
    NPC_DarkTroopa_01           = 28,
    NPC_DarkTroopa_02           = 29,
    NPC_DarkTroopa_03           = 30,
    NPC_DarkTroopa_04           = 31,
    NPC_DarkTroopa_05           = 32,
    NPC_KoopaTroopa_01          = 34,
    NPC_KoopaTroopa_02          = 35,
    NPC_KoopaTroopa_03          = 36,
    NPC_KoopaTroopa_04          = 37,
    NPC_KoopaTroopa_05          = 38,
    NPC_Bobomb_01               = 40,
    NPC_Bobomb_02               = 41,
    NPC_Bobomb_03               = 42,
    NPC_Bobomb_04               = 43,
    NPC_Bobomb_05               = 44,
};

enum {
    MV_LastAnswerResult     = MapVar(0),
    MV_Sync_TimesUp         = MapVar(1),
};

enum {
    MF_Sync_MusicChange     = MapFlag(0),
};

#define NAMESPACE kpa_82

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_ExitDoors_kpa_61_0);
extern NpcGroupList N(DefaultNPCs);
