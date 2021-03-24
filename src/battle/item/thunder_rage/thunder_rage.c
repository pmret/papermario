#include "thunder_rage.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = c ItemId_THUNDER_RAGE;
    await N(UseItemWithEffect);
    parallel {
        sleep 5;
        UseCamPreset(2);
        MoveBattleCamOver(20);
    }
    N(FadeBackgroundToBlack)();
    PlaySound(SoundId_365);
    sleep 10;
    InitTargetIterator();
0:
    SetGoalToTarget(ActorID_SELF);
    ItemCheckHit(SI_VAR(0), 0x10000000, 0, SI_VAR(0), 0);
    if (SI_VAR(0) == 6) {
        goto 1;
    }
    N(func_802A1354_71B4F4)();
    sleep 5;
    StartRumble(10);
    ShakeCam(1, 0, 5, 1.0);
    SetGoalToTarget(ActorID_SELF);
    GetItemPower(ItemId_THUNDER_RAGE, SI_VAR(0), SI_VAR(1));
    ItemDamageEnemy(SI_VAR(0), 0x38000020, 0, SI_VAR(0), 32);
1:
    sleep 5;
    ChooseNextTarget(0, SI_VAR(0));
    if (SI_VAR(0) != -1) {
        goto 0;
    }
    UseCamPreset(3);
    MoveBattleCamOver(20);
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_2);
    sleep 30;
    N(func_802A12D4_71B474)();
    await N(PlayerGoHome);
});
