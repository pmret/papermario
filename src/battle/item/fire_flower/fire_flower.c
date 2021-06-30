#include "fire_flower.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = (const) ITEM_FIRE_FLOWER;
    await N(UseItemWithEffect);
    N(FadeBackgroundToBlack)();
    PlaySound(SOUND_UNKNOWN_377);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_PLANT);
    spawn {
        sleep 50;
        SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    }
    sleep 35;
    UseBattleCamPreset(2);
    MoveBattleCamOver(20);
    sleep 10;
    GetActorPos(ACTOR_PLAYER, SI_VAR(3), SI_VAR(4), SI_VAR(5));
    SI_VAR(0) = 40;
    MultiplyByActorScale(SI_VAR(0));
    SI_VAR(3) += SI_VAR(0);
    spawn {
        GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) -= 10;
        SetActorSpeed(ACTOR_PLAYER, 2.0);
        SetAnimation(ACTOR_PLAYER, 0, ANIM_RUNNING);
        SetGoalPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        PlayerRunToGoal(ACTOR_PLAYER);
        SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    }
    spawn {
        N(func_802A123C_716E9C)(SI_VAR(3), SI_VAR(4), SI_VAR(5));
        sleep 25;
        loop 12 {
            sleep 1;
            PlaySound(SOUND_UNKNOWN_202C);
            sleep 2;
            PlaySound(SOUND_UNKNOWN_202D);
            sleep 1;
        }
    }
    sleep 80;
    UseBattleCamPreset(3);
    MoveBattleCamOver(20);
    InitTargetIterator();
0:
    SetGoalToTarget(ACTOR_SELF);
    ItemCheckHit(SI_VAR(0), 0x10000000, 0, SI_VAR(0), 0);
    if (SI_VAR(0) == 6) {
        goto 1;
    }
    GetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    GetItemPower(ITEM_FIRE_FLOWER, SI_VAR(0), SI_VAR(1));
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
