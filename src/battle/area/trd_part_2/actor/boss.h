#include "common.h"

enum N(ActorIDs) {
    GREEN_ACTOR     = ACTOR_ENEMY0,
    YELLOW_ACTOR    = ACTOR_ENEMY1,
    BLACK_ACTOR     = ACTOR_ENEMY2,
    RED_ACTOR       = ACTOR_ENEMY3,
    BOSS_ACTOR      = ACTOR_ENEMY4,
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
    AFLAG_Boss_100                  = 0x100,
    AFLAG_Boss_DoingSoloAttack          = 0x200,
    // state values for boss var 1
    AVAL_Boss_TowerState_0              = 0,
    AVAL_Boss_TowerState_1              = 1,
    AVAL_Boss_TowerState_Unstable       = 2,
    AVAL_Boss_TowerState_3              = 3, // toppled? also init to prevent first-turn tower attack

    // actor vars for each koopa
    AVAR_Koopa_State            = 1,
    AVAR_Koopa_ToppledTurns     = 2, // number of toppled turns remaining
    // state values for koopa var 1
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
    BOSS_CMD_0             = 0,
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
