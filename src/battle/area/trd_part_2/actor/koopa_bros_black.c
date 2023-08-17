#include "../area.h"
#include "sprite/npc/KoopaBros.h"

#define NAMESPACE A(black_ninja_koopa)

// these are the only parameters that vary among koopa bros actors
enum N(ThisBrosParams) {
    THIS_ACTOR_ID               = ACTOR_ENEMY2,
    THIS_ACTOR_TYPE             = ACTOR_TYPE_BLACK_NINJAKOOPA,
    THIS_LEVEL                  = ACTOR_LEVEL_BLACK_NINJAKOOPA,
    THIS_SLEEP_CHANCE           = 40,
    THIS_DIZZY_CHANCE           = 30,
    THIS_PARALYZE_CHANCE        = 60,
    THIS_ANIM_IDLE              = ANIM_KoopaBros_Black_Idle,
    THIS_ANIM_STILL             = ANIM_KoopaBros_Black_Still,
    THIS_ANIM_SLEEP             = ANIM_KoopaBros_Black_Sleep,
    THIS_ANIM_DIZZY             = ANIM_KoopaBros_Black_Dizzy,
    THIS_ANIM_RUN               = ANIM_KoopaBros_Black_Run,
    THIS_ANIM_HURT              = ANIM_KoopaBros_Black_Hurt,
    THIS_ANIM_HURT_STILL        = ANIM_KoopaBros_Black_HurtStill,
    THIS_ANIM_BURN              = ANIM_KoopaBros_Black_BurnHurt,
    THIS_ANIM_BURN_STILL        = ANIM_KoopaBros_Black_BurnStill,
    THIS_ANIM_TOWER_IDLE        = ANIM_KoopaBros_Black_IdleCrouch,
    THIS_ANIM_TOWER_STILL       = ANIM_KoopaBros_Black_StillCrouch,
    THIS_ANIM_TOPPLE_IDLE       = ANIM_KoopaBros_Black_IdleToppled,
    THIS_ANIM_TOPPLE_STILL      = ANIM_KoopaBros_Black_StillToppled,
    THIS_ANIM_TOPPLE_DIZZY      = ANIM_KoopaBros_Black_DizzyToppled,
    THIS_ANIM_TIPPING_IDLE      = ANIM_KoopaBros_Black_IdleTipping,
    THIS_ANIM_TOP_ENTER_SHELL   = ANIM_KoopaBros_Black_TopEnterShell,
    THIS_ANIM_TOP_EXIT_SHELL    = ANIM_KoopaBros_Black_TopExitShell,
    THIS_ANIM_ENTER_SHELL       = ANIM_KoopaBros_Black_EnterShell,
    THIS_ANIM_EXIT_SHELL        = ANIM_KoopaBros_Black_ExitShell,
    THIS_ANIM_SHELL_SPIN        = ANIM_KoopaBros_Black_ShellSpin,
    THIS_ANIM_POINT             = ANIM_KoopaBros_Black_PointForward,
};

#include "common_koopa_bros.inc.c"
