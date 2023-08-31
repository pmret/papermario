#include "common.h"

/**
 * Koopa Bros Boss Fight
 * 
 * The fake_bowser actor controls both parts of the boss battle.
 * During the first part, it uses ANIM commands defined in fake_bowser to animate models from trd_00 forming the parts
 * of its body. In this phase, each group of models (head, shell, feet, etc.) are tethered to a corresponding ActorPart
 * which the animation scripts operate on.
 * 
 * During the second part, four 'dummy' Koopa Bros actors are enabled, which all have identical behavior. Their actions
 * are completely governed by fake_bowser; they are only responsible for executing animations in response to commands
 * issued by fake_bowser. These commands are listed in the enum below as BOSS_CMD_*. They mostly pertain to the state of
 * the 'tower'.
 * 
 * During each turn, fake_bowser will attempt to form a Koopa Bros tower. If none exists, all standing Koopa Bros are
 * used to create one. If one already exists and an idle Koopa Bros is found, they are joined with the tower (This can
 * occur if the Koopa in question wass incapacitated when the tower was built). If a valid tower exists, a spin attack
 * is executed.
 * 
 * The tower topples when hit twice in one turn by the player or when hit with an explosive or electic attack. A single
 * hit puts the tower into an 'unstable' or 'tipping' state. If not knocked over by the start of fake_bowser's turn,
 * the tower will regain stability.
 * 
 * The current state of the tower is stored in fake_bowser's actor var AVAR_Boss_TowerState
 * The state of each Koopa is stored in their actor var AVAR_Koopa_State
*/

enum N(ActorIDs) {
    GREEN_ACTOR         = ACTOR_ENEMY0,
    YELLOW_ACTOR        = ACTOR_ENEMY1,
    BLACK_ACTOR         = ACTOR_ENEMY2,
    RED_ACTOR           = ACTOR_ENEMY3,
    BOSS_ACTOR          = ACTOR_ENEMY4,
    FIRST_KOOPA_ACTOR   = ACTOR_ENEMY0,
};

enum {
    // boss actor vars
    AVAR_Boss_Flags             = 0,
    AVAR_Boss_TowerState        = 1,
    AVAR_Boss_BowserTaunts      = 2,
    AVAR_Boss_TowerHeight       = 3,
    AVAR_Boss_TopKoopaID        = 4, // top of the tower upon tower formation
    AVAR_Boss_LeadKoopaID       = 5, // top of the tower during spin attack (invalid at other times)
    // flag values for boss var 0
    AFLAG_Boss_KoopaBrosRevealed        = 0x001,
    AFLAG_Boss_Dialogue_HaveATaste      = 0x002,
    AFLAG_Boss_Dialogue_SpinAttack      = 0x004,
    AFLAG_Boss_Dialogue_BowserReveal    = 0x008,
    AFLAG_Boss_TowerUnstable            = 0x010,
    AFLAG_Boss_Dialogue_WereGoingOver   = 0x020,
    AFLAG_Boss_PlayerHitTower           = 0x040,
    AFLAG_Boss_PartnerHitTower          = 0x080,
    AFLAG_Boss_DoneTowerUpdate          = 0x100,
    AFLAG_Boss_DoingSoloAttack          = 0x200,
    // state values for tower (AVAR_Boss_TowerState)
    AVAL_Boss_TowerState_None           = 0,
    AVAL_Boss_TowerState_Stable         = 1,
    AVAL_Boss_TowerState_Unstable       = 2,
    AVAL_Boss_TowerState_Toppled        = 3, // also init value to prevent first-turn tower attack

    // actor vars for each koopa
    AVAR_Koopa_State            = 1,
    AVAR_Koopa_ToppleTurns      = 2, // number of toppled turns remaining
    // state values for koopas (AVAR_Koopa_State)
    AVAL_Koopa_State_Ready      = 0,
    AVAL_Koopa_State_Toppled    = 1,
    AVAL_Koopa_State_GotUp      = 2,
    AVAL_Koopa_State_PosA       = 3, // top position
    AVAL_Koopa_State_PosD       = 4, // above posC
    AVAL_Koopa_State_PosC       = 5, // above posB
    AVAL_Koopa_State_PosB       = 6, // bottom position
    
    // position in the koopa bros tower
    TOWER_TOP       = 0,
    TOWER_DOWN_1    = 1,
    TOWER_DOWN_2    = 2,
    TOWER_DOWN_3    = 3,

    // commands sent to koopa bros from boss
    BOSS_CMD_STABLE             = 0,
    BOSS_CMD_UNSTABLE           = 1,
    BOSS_CMD_HIT                = 2,
    BOSS_CMD_BURN_HIT           = 3,
    BOSS_CMD_NO_DAMAGE_HIT      = 4, 
    BOSS_CMD_TOPPLE_HIT         = 5,
    BOSS_CMD_TOPPLE_BURN_HIT    = 6,
    BOSS_CMD_SPIN_ATTACK        = 7,
    BOSS_CMD_SOLO_ATTACK        = 8,
    BOSS_CMD_TRY_GET_UP         = 9,
    BOSS_CMD_GET_READY          = 10,
};
