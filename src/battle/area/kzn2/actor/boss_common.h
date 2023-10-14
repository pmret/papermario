#ifndef _LAVA_PIRANHA_COMMON_H_
#define _LAVA_PIRANHA_COMMON_H_

enum N(BattleCommon) {
    ACTOR_BOSS          = ACTOR_ENEMY0,
    ACTOR_BUD_1         = ACTOR_ENEMY1,
    ACTOR_BUD_2         = ACTOR_ENEMY2,
    ACTOR_PETIT_1       = ACTOR_ENEMY3,
    ACTOR_PETIT_2       = ACTOR_ENEMY4,
    // actor vars specific to certain actors in the boss battle
    AVAR_Boss_IsSecondPhase     = 0,
    AVAR_Boss_Dying             = 1,
    AVAR_Bud_WhichVine          = 0,
    AVAR_Bud_PetitCount         = 9,
    AVAR_Petit_Parent           = 0,
    // actor vars used by both the boss and buds
    AVAR_Common_PiranhaState    = 5,
    AVAR_Common_FlameEffect     = 6,
    AVAR_Common_UnkAnim1        = 7,
    AVAR_Common_UnkAnim2        = 8,
    AVAR_Common_FlameSize       = 10,
    AVAR_Common_StunTurnsLeft   = 11,
    AVAR_Common_NextTwitchMode  = 12,
    AVAR_Common_NextTwitchTime  = 13,
};

// state for piranha plant and buds during the second phase
enum N(PiranhaState) {
    PIRANHA_STATE_STUNNED   = 0,
    PIRANHA_STATE_FIERY     = 1,
    PIRANHA_STATE_DEAD      = 2, // used by buds when HP = 0
};

enum {
    VINE_0          = 0,
    VINE_1          = 1,
    VINE_2          = 2,
    VINE_3          = 3,
    NUM_VINES       = 4,
    SHATTER_GROUND  = 4, // animator ID for ground crack and shattering animation
};

enum N(VineAnims) {
    // VINE_0
    VINE_ANIM_BOSS_IDLE                 = 0,
    VINE_ANIM_BOSS_TWITCH               = 1, // slight sway while stunned
    VINE_ANIM_BOSS_ATTACK               = 2, // lurch forward for attack
    VINE_ANIM_BOSS_POST_ATTACK          = 3, // withdraw after attack
    VINE_ANIM_BOSS_STUNNED_HEAVY_HIT    = 4,
    VINE_ANIM_BOSS_STUNNED_LIGHT_HIT    = 5,
    VINE_ANIM_BOSS_HEAVY_HIT            = 6,
    VINE_ANIM_BOSS_LIGHT_HIT            = 7,
    VINE_ANIM_BOSS_STUNNED_DEATH_BEGIN  = 8,
    VINE_ANIM_BOSS_DEATH_BEGIN          = 9,
    VINE_ANIM_BOSS_DEATH_MIDDLE         = 10, // swing violently and stop, ending upright
    VINE_ANIM_BOSS_DEATH_COLLAPSE       = 11, // fall down
    VINE_ANIM_BOSS_EMERGE               = 12, // emerge
    VINE_ANIM_BOSS_STUN                 = 13, // stun
    VINE_ANIM_BOSS_RECOVER              = 14, // un-stun
    VINE_ANIM_BOSS_DUP_EMERGE           = 15, // unused?
    VINE_ANIM_BOSS_SINK_AWAY            = 16,
    VINE_ANIM_BOSS_TALK                 = 17,

    // VINE_1 and VINE_2
    VINE_ANIM_BUD_ATTACK                = 18,
    VINE_ANIM_BUD_STUNNED_HEAVY_HIT     = 19,
    VINE_ANIM_BUD_STUNNED_LIGHT_HIT     = 20,
    VINE_ANIM_BUD_HEAVY_HIT             = 21,
    VINE_ANIM_BUD_LIGHT_HIT             = 22,
    VINE_ANIM_BUD_STUNNED_DEATH_BEGIN   = 23,
    VINE_ANIM_BUD_DEATH_BEGIN           = 24,
    VINE_ANIM_BUD_DEATH_MIDDLE          = 25,
    VINE_ANIM_BUD_DEATH_COLLAPSE        = 26,
    VINE_ANIM_BUD_STUN                  = 27, // stun
    VINE_ANIM_BUD_EMERGE                = 28, // emerge
    VINE_ANIM_BUD_RECOVER               = 29, // un-stun
    VINE_ANIM_BUD_TWITCH                = 30,
    VINE_ANIM_BUD_IDLE                  = 31,
    VINE_ANIM_BUD_DUP_EMERGE            = 32, // unused?
    VINE_ANIM_BUD_SINK_AWAY             = 33,

    // VINE_3
    VINE_ANIM_EXTRA_IDLE                = 34,
    VINE_ANIM_EXTRA_DEATH               = 35,
    VINE_ANIM_EXTRA_EMERGE              = 36,
};

#endif // _LAVA_PIRANHA_COMMON_H_
