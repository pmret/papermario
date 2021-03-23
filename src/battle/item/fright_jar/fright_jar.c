#include "fright_jar.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = c 0x98;
    await N(UseItemWithEffect);
    N(FadeBackgroundToBlack)();
    spawn {
        sleep 5;
        UseCamPreset(2);
        MoveBattleCamOver(50);
    }
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_CROUCH);
    PlaySoundAtActor(ActorID_PLAYER, 871);
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 0xFFFFFFD8;
    SI_VAR(1) += 5;
    SI_VAR(3) = 0.7001953125;
    loop 5 {
        PlayEffect(97, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(3), 25, 0, 0, 0, 0, 0, 0, 0);
        SI_VAR(0) += 5;
        SI_VAR(3) += 0.150390625;
        sleep 7;
    }
    PlayEffect(97, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 1.5, 60, 0, 0, 0, 0, 0, 0, 0);
    sleep 20;
    loop 4 {
        AddBattleCamZoom(0xFFFFFF9C);
        MoveBattleCamOver(2);
        sleep 2;
        AddBattleCamZoom(100);
        MoveBattleCamOver(2);
        sleep 2;
    }
    UseCamPreset(3);
    MoveBattleCamOver(20);
    InitTargetIterator();
0:
    SetGoalToTarget(ActorID_SELF);
    ItemCheckHit(SI_VAR(0), 0x10000000, 0, SI_VAR(0), 0);
    if (SI_VAR(0) == 6) {
        goto 1;
    }
    func_80269EAC(21);
    ItemAfflictEnemy(SI_VAR(0), 0x70001000, 0, 100, 0, 32);
1:
    ChooseNextTarget(0, SI_VAR(0));
    if (SI_VAR(0) != -1) {
        goto 0;
    }
    sleep 10;
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_WALKING);
    N(func_802A12D4_72BBE4)();
    sleep 20;
    await N(PlayerGoHome);
});
