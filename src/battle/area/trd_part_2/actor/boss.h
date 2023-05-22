#include "common.h"

enum N(ActorIDs) {
    GREEN_ACTOR     = ACTOR_ENEMY0,
    YELLOW_ACTOR    = ACTOR_ENEMY1,
    BLACK_ACTOR     = ACTOR_ENEMY2,
    RED_ACTOR       = ACTOR_ENEMY3,
    BOSS_ACTOR      = ACTOR_ENEMY4,
};

enum N(CommonVars) {
    // boss actor vars
    AVAR_Boss_Flags         = 0,
    AFLAG_Boss_KoopaBrosRevealed        = 0x001,
    AFLAG_Boss_Dialogue_HaveATaste      = 0x002,
    AFLAG_Boss_Dialogue_SpinAttack      = 0x004,
    AFLAG_Boss_Dialogue_BowserTaunt     = 0x008,
    AFLAG_Boss_010          = 0x010,
    AFLAG_Boss_Dialogue_WereGoingOver   = 0x020,
    AFLAG_Boss_PlayerHitTower           = 0x040,
    AFLAG_Boss_PartnerHitTower          = 0x080,
    AFLAG_Boss_100          = 0x100,
    AFLAG_Boss_DoingSoloAttack          = 0x200,
    AVAR_Boss_1             = 1,
    AVAL_Boss_1_0           = 0,
    AVAL_Boss_1_1           = 1,
    AVAL_Boss_1_2           = 2,
    AVAL_Boss_1_3           = 3,
    AVAR_Boss_2             = 2,
    AVAR_Boss_TowerDamage   = 3,
    AVAR_Boss_4             = 4,
    AVAR_Boss_5             = 5,

    // actor vars for each koopa
    AVAR_Koopa_State            = 1,
    AVAL_Koopa_State_Ready      = 0,
    AVAL_Koopa_State_Toppled    = 1,
    AVAL_Koopa_State_GotUp      = 2,
    AVAL_Koopa_State_PosA       = 3, // in position TOWER_TOP
    AVAL_Koopa_State_PosD       = 4, // in position TOWER_DOWN_3
    AVAL_Koopa_State_PosC       = 5, // in position TOWER_DOWN_2
    AVAL_Koopa_State_PosB       = 6, // in position TOWER_DOWN_1
    AVAR_Koopa_ToppledTurns = 2, // number of toppled turns remaining

    // position in the koopa bros tower
    TOWER_TOP       = 0,
    TOWER_DOWN_1    = 1,
    TOWER_DOWN_2    = 2,
    TOWER_DOWN_3    = 3,

    // commands sent to koopa bros from boss
    KCMD_0      = 0,
    KCMD_1      = 1,
    KCMD_HIT                = 2,
    KCMD_BURN_HIT           = 3,
    KCMD_NO_DAMAGE_HIT      = 4, 
    KCMD_TOPPLE_HIT         = 5,
    KCMD_TOPPLE_BURN_HIT    = 6,
    KCMD_SPIN_ATTACK        = 7,
    KCMD_SOLO_ATTACK        = 8,
    KCMD_TRY_GET_UP         = 9,
    KCMD_GET_READY          = 10,
};
