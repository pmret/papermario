#ifndef _GENERAL_GUY_COMMON_H_
#define _GENERAL_GUY_COMMON_H_

#include "mapfs/omo_bt07_shape.h"

enum N(BattleCommon) {
    ACTOR_GENERAL       = ACTOR_ENEMY0,
    ACTOR_TANK          = ACTOR_ENEMY1,
    ACTOR_BULB          = ACTOR_ENEMY2,
    ACTOR_WAVE_A        = ACTOR_ENEMY3,
    ACTOR_WAVE_B        = ACTOR_ENEMY4,
    // actor vars for general guy
    AVAR_General_DoingTankPhase     = 0,
    AVAR_General_Flags              = 1,
    AVAR_GeneralFlag_SquadFled          = 0x1,
    AVAR_GeneralFlag_ComplainElectric   = 0x2,
    AVAR_GeneralFlag_ComplainUnfair     = 0x4,
    AVAR_GeneralFlag_ComplainGeneric    = 0x8,
    AVAR_General_WavesDefeated      = 2,
    // actor vars for the toy tank
    AVAR_Tank_ShouldTetherGeneral   = 0,
    AVAR_Tank_SquadPhase            = 1,
    AVAL_SquadPhase_Init                = 0,
    AVAL_SquadPhase_Defeated            = 1,
    AVAL_SquadPhase_Done                = 2,
    AVAL_SquadPhase_Next                = 3, // next wave (stilt guys) have arrived
    AVAR_Tank_StiltPhase            = 2,
    AVAL_StiltPhase_Init                = 0,
    AVAL_StiltPhase_1                   = 1,
    AVAL_StiltPhase_Defeated            = 2,
    AVAL_StiltPhase_Done                = 3,
    AVAL_StiltPhase_Next                = 4, // next wave (shy stacks) have arrived
    AVAR_Tank_StackPhase            = 3,
    AVAL_StackPhase_Init                = 0,
    AVAL_StackPhase_1                   = 1,
    AVAL_StackPhase_Defeated            = 2,
    AVAL_StackPhase_Done                = 3,
    AVAR_Tank_UnusedPhase           = 4,
    AVAL_UnusedPhase_Init               = 0,
    AVAL_UnusedPhase_Defeated           = 1,
    AVAL_UnusedPhase_Done               = 2,
    AVAR_Tank_BulbGlowEffect        = 5,
    AVAR_Tank_UsingBulbAttack       = 6, // indicates bulb is glowing (not really used)
    AVAR_Tank_ModulateDarkness      = 7, // have darkness controlled by Watt and the bulb (unused)
    AVAR_Tank_DarknessAmt           = 8,
    AVAR_Tank_HandlingEvent         = 9,
};

#endif // _GENERAL_GUY_COMMON_H_
