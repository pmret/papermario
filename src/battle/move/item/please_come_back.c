#include "common.h"
#include "script_api/battle.h"
#include "sprite/player.h"

#define NAMESPACE battle_item_please_come_back

#include "battle/common/move/ItemRefund.inc.c"
#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    SetConst(LVarA, ITEM_DIZZY_DIAL) //@bug should be ITEM_PLEASE_COME_BACK
    ExecWait(N(UseItemWithEffect))
    Call(SetGoalToHome, ACTOR_PLAYER)
    Call(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    Call(SetActorSpeed, ACTOR_PLAYER, Float(4.0))
    Call(SetActorJumpGravity, ACTOR_PLAYER, Float(1.8))
    Call(func_80273444, 4, 0, 0)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioW2_PleaseComeBack)
    Wait(8)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Return
    End
};
