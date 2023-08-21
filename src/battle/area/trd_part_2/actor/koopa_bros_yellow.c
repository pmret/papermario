#include "../area.h"
#include "sprite/npc/KoopaBros.h"

#define NAMESPACE A(yellow_ninja_koopa)

// these are the only parameters that vary among koopa bros actors
enum N(ThisBrosParams) {
    THIS_ACTOR_ID               = ACTOR_ENEMY1,
    THIS_ACTOR_TYPE             = ACTOR_TYPE_YELLOW_NINJAKOOPA,
    THIS_LEVEL                  = ACTOR_LEVEL_YELLOW_NINJAKOOPA,
    THIS_SLEEP_CHANCE           = 60,
    THIS_DIZZY_CHANCE           = 75,
    THIS_PARALYZE_CHANCE        = 75,
    THIS_ANIM_IDLE              = ANIM_KoopaBros_Yellow_Idle,
    THIS_ANIM_STILL             = ANIM_KoopaBros_Yellow_Still,
    THIS_ANIM_SLEEP             = ANIM_KoopaBros_Yellow_Sleep,
    THIS_ANIM_DIZZY             = ANIM_KoopaBros_Yellow_Dizzy,
    THIS_ANIM_RUN               = ANIM_KoopaBros_Yellow_Run,
    THIS_ANIM_HURT              = ANIM_KoopaBros_Yellow_Hurt,
    THIS_ANIM_HURT_STILL        = ANIM_KoopaBros_Yellow_HurtStill,
    THIS_ANIM_BURN              = ANIM_KoopaBros_Yellow_BurnHurt,
    THIS_ANIM_BURN_STILL        = ANIM_KoopaBros_Yellow_BurnStill,
    THIS_ANIM_TOWER_IDLE        = ANIM_KoopaBros_Yellow_IdleCrouch,
    THIS_ANIM_TOWER_STILL       = ANIM_KoopaBros_Yellow_StillCrouch,
    THIS_ANIM_TOPPLE_IDLE       = ANIM_KoopaBros_Yellow_IdleToppled,
    THIS_ANIM_TOPPLE_STILL      = ANIM_KoopaBros_Yellow_StillToppled,
    THIS_ANIM_TOPPLE_DIZZY      = ANIM_KoopaBros_Yellow_DizzyToppled,
    THIS_ANIM_TIPPING_IDLE      = ANIM_KoopaBros_Yellow_IdleTipping,
    THIS_ANIM_TOP_ENTER_SHELL   = ANIM_KoopaBros_Yellow_TopEnterShell,
    THIS_ANIM_TOP_EXIT_SHELL    = ANIM_KoopaBros_Yellow_TopExitShell,
    THIS_ANIM_ENTER_SHELL       = ANIM_KoopaBros_Yellow_EnterShell,
    THIS_ANIM_EXIT_SHELL        = ANIM_KoopaBros_Yellow_ExitShell,
    THIS_ANIM_SHELL_SPIN        = ANIM_KoopaBros_Yellow_ShellSpin,
    THIS_ANIM_POINT             = ANIM_KoopaBros_Yellow_PointForward,
};

#include "common_koopa_bros.inc.c"
