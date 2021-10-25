#include "please_come_back.h"

#include "ItemRefund.inc.c"

#include "UseItem.inc.c"

EvtSource N(main) = {
    EVT_SET_CONST(EVT_VAR(10), 0x0000009A)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_CALL(SetGoalToHome, ACTOR_PLAYER)
    EVT_CALL(SetJumpAnimations, ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_10009)
    EVT_CALL(SetActorSpeed, ACTOR_PLAYER, EVT_FIXED(4.0))
    EVT_CALL(SetActorJumpGravity, ACTOR_PLAYER, EVT_FIXED(1.8))
    EVT_CALL(func_80273444, 4, 0, 0)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_8000B)
    EVT_WAIT_FRAMES(8)
    EVT_CALL(SetAnimation, ACTOR_PLAYER, 0, ANIM_10002)
    EVT_RETURN
    EVT_END
};

