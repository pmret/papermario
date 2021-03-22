#include "shooting_star.h"

Script N(main) = SCRIPT({
    SI_VAR(10) =c 0x83;
    await N(UseItemWithEffect);
    spawn {
        sleep 5;
        UseCamPreset(2);
        MoveBattleCamOver(20);
    }
    N(func_802A1444_71DBB4)();
    spawn {
        SI_VAR(0) = 0;
        loop 10 {
            PlaySoundAtActor(ActorID_PLAYER, 601);
            N(func_802A123C_71D9AC)();
            SI_VAR(0) += 1;
            sleep 5;
            PlaySoundAtActor(ActorID_PLAYER, 602);
            N(func_802A123C_71D9AC)();
            SI_VAR(0) += 1;
            sleep 5;
        }
    }
    spawn {
        SI_VAR(0) = 0;
        sleep 50;
        loop 10 {
            PlaySoundAtActor(ActorID_PLAYER, 604);
            SI_VAR(0) += 1;
            sleep 5;
            PlaySoundAtActor(ActorID_PLAYER, 605);
            SI_VAR(0) += 1;
            sleep 5;
        }
    }
    spawn {
        loop 5 {
            sleep 15;
            StartRumble(8);
            ShakeCam(1, 0, 5, 1.0);
        }
    }
    sleep 90;
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
    N(func_802A1388_71DAF8)(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    GetItemPower(ItemId_SHOOTING_STAR, SI_VAR(0), SI_VAR(1));
    ItemDamageEnemy(SI_VAR(0), 0x38000100, 0, SI_VAR(0), 32);
1:
    sleep 10;
    ChooseNextTarget(0, SI_VAR(0));
    if (SI_VAR(0) != -1) {
        goto 0;
    }
    sleep 20;
    UseCamPreset(2);
    MoveBattleCamOver(20);
    await N(PlayerGoHome);
    spawn {
        N(func_802A14D4_71DC44)();
    }
    sleep 30;
});
