#include "fire_flower.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = c ItemId_FIRE_FLOWER;
    await N(UseItemWithEffect);
    N(FadeBackgroundToBlack)();
    PlaySound(SoundId_377);
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_PLANT);
    spawn {
        sleep 50;
        SetAnimation(ActorID_PLAYER, 0, PlayerAnim_2);
    }
    sleep 35;
    UseCamPreset(2);
    MoveBattleCamOver(20);
    sleep 10;
    GetActorPos(ActorID_PLAYER, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    SI_VAR(0) = 40;
    MultiplyByActorScale(SI_VAR(0));
    SI_VAR(3) += SI_VAR(0);
    spawn {
        GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) -= 10;
        SetActorSpeed(ActorID_PLAYER, 2.0);
        SetAnimation(ActorID_PLAYER, 0, PlayerAnim_RUNNING);
        SetGoalPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        PlayerRunToGoal(0);
        SetAnimation(ActorID_PLAYER, 0, PlayerAnim_2);
    }
    spawn {
        N(func_802A123C_716E9C)(SI_VAR(3), SI_VAR(4), SI_VAR(5));
        sleep 25;
        loop 12 {
            sleep 1;
            PlaySound(SoundId_202C);
            sleep 2;
            PlaySound(SoundId_202D);
            sleep 1;
        }
    }
    sleep 80;
    UseCamPreset(3);
    MoveBattleCamOver(20);
    InitTargetIterator();
0:
    SetGoalToTarget(ActorID_SELF);
    ItemCheckHit(SI_VAR(0), 0x10000000, 0, SI_VAR(0), 0);
    if (SI_VAR(0) == 6) {
        goto 1;
    }
    GetGoalPos(ActorID_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    GetItemPower(ItemId_FIRE_FLOWER, SI_VAR(0), SI_VAR(1));
    ItemDamageEnemy(SI_VAR(0), 0x38000002, 0, SI_VAR(0), 32);
1:
    sleep 5;
    ChooseNextTarget(0, SI_VAR(0));
    if (SI_VAR(0) != -1) {
        goto 0;
    }
    N(func_802A1378_716FD8)();
    sleep 30;
    await N(PlayerGoHome);
});
