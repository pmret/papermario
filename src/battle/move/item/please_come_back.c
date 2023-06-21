#include "common.h"
#include "script_api/battle.h"
#include "sprite/player.h"

#define NAMESPACE battle_item_please_come_back

#include "battle/common/move/ItemRefund.inc.c"
#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    EVT_SET_CONST(LVarA, ITEM_DIZZY_DIAL) //@bug should be ITEM_PLEASE_COME_BACK
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario1_Jump, ANIM_Mario1_Fall, ANIM_Mario1_Land)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.8))
    EVT_CALL(func_80273444, 4, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_MarioW2_PleaseComeBack)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    EVT_RETURN
    EVT_END
};
