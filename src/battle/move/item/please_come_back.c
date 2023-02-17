#include "please_come_back.h"

#include "ItemRefund.inc.c"

#include "UseItem.inc.c"

EvtScript N(main) = {
    EVT_SET_CONST(LVarA, ITEM_DIZZY_DIAL) //@bug should be ITEM_PLEASE_COME_BACK
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_Mario_AnimMidairStill, ANIM_Mario_AnimMidair, ANIM_Mario_10009)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FLOAT(4.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FLOAT(1.8))
    EVT_CALL(func_80273444, 4, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_8000B)
    EVT_WAIT(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario_10002)
    EVT_RETURN
    EVT_END
};

