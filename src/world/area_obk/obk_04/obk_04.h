/// @file obk_04.h
/// @brief Boo's Mansion - Super Boots Room

#include "common.h"
#include "message_ids.h"
#include "map.h"

#include "../obk.h"
#include "mapfs/obk_04_shape.h"
#include "mapfs/obk_04_hit.h"

#include "sprite/npc/Boo.h"

enum {
    NPC_Boo_01              = 0,
    NPC_KeepAwayBoo1        = 1,
    NPC_KeepAwayBoo2        = 2,
    NPC_KeepAwayBoo3        = 3,
    NPC_KeepAwayBoo4        = 4,
    NPC_KeepAwayBoo5        = 5,
    NPC_KeepAwayBoo6        = 6,
    NPC_KeepAwayBoo7        = 7,
    NPC_KeepAwayBoo8        = 8,
    NPC_LeaderBoo           = 9,
    NPC_DummyBoo            = 10,
    NPC_TutorialBoo         = 11,
};

enum {
    MV_KeepAwayItem         = MapVar(0), // item entity ID
    MV_KeepAwayStarted      = MapVar(1), //
    MV_Unk_02               = MapVar(2), //
    MV_KeepAwayMovement     = MapVar(3), //
    MV_KeepAwayTarget       = MapVar(4), // npcID to throw item to
    MV_ThrowTargetNpc       = MapVar(5), // npcID the item is thrown to (redundant)
    MV_KeepAwayResult       = MapVar(6), // did the player hit the correct boo?
    MV_ItemCarrierNpc       = MapVar(7), // npcID holding the item (also redundant)
    MV_KeepAwayThrows       = MapVar(8), // number of tosses for this round (not counting the first)
    MV_KeepAwayRound        = MapVar(9), // how many times has the game been played
};

enum {
    MF_WaitForUpgradeDone   = MapFlag(10),
};

enum KeepAwayResult {
    KEEP_AWAY_WAITING   = 0,
    KEEP_AWAY_RIGHT     = 1,
    KEEP_AWAY_WRONG     = 2,
};

enum KeepAwayMoveState {
    KEEP_AWAY_CLOCKWISE         = 0,
    KEEP_AWAY_STOP              = 1,
    KEEP_AWAY_COUNTER_CLOCKWISE = 2,
    KEEP_AWAY_SPIRAL            = 3,
};

#define NAMESPACE obk_04

extern EvtScript N(EVS_Main);
extern EvtScript N(EVS_SetupMusic);
extern EvtScript N(EVS_PlayUpgradeSong);
extern EvtScript N(EVS_Scene_BoosUnleashed);
extern EvtScript N(EVS_ManageHole);
extern EvtScript N(EVS_MakeEntities);
extern NpcGroupList N(DefaultNPCs);
