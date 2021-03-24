#include "please_come_back.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = c ItemId_DIZZY_DIAL;
    await N(UseItemWithEffect);
    SetGoalToHome(0);
    SetJumpAnimations(ActorID_PLAYER, 0, PlayerAnim_MIDAIR_STILL, PlayerAnim_MIDAIR, PlayerAnim_9);
    SetActorSpeed(ActorID_PLAYER, 4.0);
    SetActorJumpGravity(ActorID_PLAYER, 1.80078125);
    func_80273444(4, 0, 0);
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_8000B);
    sleep 8;
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_2);
});

