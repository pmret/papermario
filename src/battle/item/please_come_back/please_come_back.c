#include "please_come_back.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = (const) ITEM_DIZZY_DIAL;
    await N(UseItemWithEffect);
    SetGoalToHome(ACTOR_PLAYER);
    SetJumpAnimations(ACTOR_PLAYER, 0, ANIM_MIDAIR_STILL, ANIM_MIDAIR, ANIM_10009);
    SetActorSpeed(ACTOR_PLAYER, 4.0);
    SetActorJumpGravity(ACTOR_PLAYER, 1.80078125);
    func_80273444(4, 0, 0);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_8000B);
    sleep 8;
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
});

