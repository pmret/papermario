#include "pow_block.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = c ItemId_P_O_W_BLOCK;
    await N(UseItemWithEffect);
    sleep 10;
    MakeEntity(0x802EA2E0, 0xFFFFFFD8, 60, 0, 0, 0x80000000);
    SI_VAR(10) = SI_VAR(0);
    N(func_802A1318_718B68)();
    PlayEffect(0x7, 2, 0xFFFFFFD8, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PlayEffect(0x7, 2, 0xFFFFFFE2, 65, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PlayEffect(0x7, 2, 0xFFFFFFD8, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PlayEffect(0x7, 2, 0xFFFFFFD8, 55, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_2);
    sleep 20;
    UseCamPreset(2);
    MoveBattleCamOver(20);
    spawn {
        sleep 15;
        PlaySoundAtActor(ActorID_PLAYER, SoundId_HIT_BLOCK);
        N(func_802A123C_718A8C)();
        PlayEffect(0x7, 2, 0xFFFFFFD8, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        PlayEffect(0x7, 2, 0xFFFFFFE2, 65, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        PlayEffect(0x7, 2, 0xFFFFFFD8, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        PlayEffect(0x7, 2, 0xFFFFFFD8, 55, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
        StartRumble(4);
        ShakeCam(1, 0, 2, 1.0);
        ShakeCam(1, 0, 2, 3.0);
        ShakeCam(1, 0, 2, 6.0);
        ShakeCam(1, 0, 2, 5.0);
        ShakeCam(1, 0, 2, 4.0);
        PlaySoundAtActor(ActorID_PLAYER, SoundId_2030);
        ShakeCam(1, 0, 2, 3.0);
        ShakeCam(1, 0, 2, 2.0);
        ShakeCam(1, 0, 2, 1.0);
        ShakeCam(1, 0, 2, 0.5);
        ShakeCam(1, 0, 2, 0.2001953125);
    }
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 30;
    SetActorSpeed(ActorID_PLAYER, 4.0);
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_RUNNING);
    SetGoalPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    PlayerRunToGoal(0);
    sleep 5;
    SetJumpAnimations(ActorID_PLAYER, 0, PlayerAnim_MIDAIR_STILL, PlayerAnim_MIDAIR, PlayerAnim_9);
    SetActorJumpGravity(ActorID_PLAYER, 0.6005859375);
    SetGoalPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    func_80273444(20, 0, 0);
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_2);
    UseCamPreset(3);
    MoveBattleCamOver(20);
    InitTargetIterator();
0:
    SetGoalToTarget(ActorID_SELF);
    ItemCheckHit(SI_VAR(0), 0x10000000, 0, SI_VAR(0), 0);
    if (SI_VAR(0) == 6) {
        goto 1;
    }
    GetItemPower(ItemId_P_O_W_BLOCK, SI_VAR(3), SI_VAR(4));
    ApplyShrinkFromOwner(SI_VAR(3));
    func_80269EAC(22);
    ItemDamageEnemy(SI_VAR(0), 0x38000400, 0, SI_VAR(3), 32);
1:
    ChooseNextTarget(0, SI_VAR(0));
    if (SI_VAR(0) != -1) {
        goto 0;
    }
    PlayEffect(0x7, 2, 0xFFFFFFBA, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PlayEffect(0x7, 2, 0xFFFFFFC4, 65, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PlayEffect(0x7, 2, 0xFFFFFFBA, 60, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    PlayEffect(0x7, 2, 0xFFFFFFBA, 55, 20, 0, 0, 0, 0, 0, 0, 0, 0, 0);
    N(func_802A12E4_718B34)();
    sleep 30;
    await N(PlayerGoHome);
});
