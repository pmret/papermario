#include "snowman_doll.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = (const) ITEM_SNOWMAN_DOLL;
    await N(UseItemWithEffect);
    N(FadeBackgroundToBlack)();
    PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_363);
    spawn {
        loop 45 {
            RandInt(300, SI_VAR(0));
            SI_VAR(0) -= 150;
            SI_VAR(1) = 170;
            RandInt(50, SI_VAR(2));
            SI_VAR(2) -= 25;
            PlayEffect(0xE, SI_VAR(0), SI_VAR(1), SI_VAR(2), 60, 0, 0, 0, 0, 0, 0, 0, 0, 0);
            sleep 2;
        }
    }
    sleep 10;
    UseBattleCamPreset(3);
    MoveBattleCamOver(50);
    sleep 50;
    PlayEffect(0x60, 0, 0, 0, 20, 1.0, 160, 0, 0, 0, 0, 0, 0, 0);
    spawn {
        sleep 17;
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_202E);
        StartRumble(9);
        ShakeCam(1, 0, 5, 1.0);
        sleep 46;
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_202E);
        StartRumble(9);
        ShakeCam(1, 0, 5, 1.0);
        sleep 25;
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_202E);
        StartRumble(9);
        ShakeCam(1, 0, 5, 1.0);
        sleep 25;
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_202E);
        StartRumble(9);
        ShakeCam(1, 0, 5, 1.0);
    }
    sleep 15;
    StartRumble(10);
    ShakeCam(1, 0, 5, 1.0);
    ShakeCam(1, 0, 10, 2.0);
    ShakeCam(1, 0, 5, 1.0);
    sleep 110;
    InitTargetIterator();
0:
    SetGoalToTarget(ACTOR_SELF);
    ItemCheckHit(SI_VAR(0), 0x10000000, 0, SI_VAR(0), 0);
    if (SI_VAR(0) == 6) {
        goto 1;
    }
    GetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    N(func_802A123C_71C06C)(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    GetItemPower(ITEM_SNOWMAN_DOLL, SI_VAR(0), SI_VAR(1));
    ItemDamageEnemy(SI_VAR(0), 0x38000008, 0, SI_VAR(0), 32);
    sleep 5;
1:
    ChooseNextTarget(0, SI_VAR(0));
    if (SI_VAR(0) != -1) {
        goto 0;
    }
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    sleep 30;
    N(func_802A13B8_71C1E8)();
    await N(PlayerGoHome);
});
