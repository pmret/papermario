#include "stop_watch.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = (const) ITEM_STOP_WATCH;
    await N(UseItemWithEffect);
    spawn {
        sleep 5;
        UseBattleCamPreset(2);
        MoveBattleCamOver(20);
    }
    N(FadeBackgroundToBlack)();
    PlayEffect(0x62, 0, 0, 0, 0, 1.0, 200, 0, 0, 0, 0, 0, 0, 0);
    PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_246);
    sleep 200;
    UseBattleCamPreset(3);
    MoveBattleCamOver(20);
    InitTargetIterator();
0:
    SetGoalToTarget(ACTOR_SELF);
    ItemCheckHit(SI_VAR(0), 0x10000000, 0, SI_VAR(0), 0);
    if (SI_VAR(0) == 6) {
        goto 1;
    }
    GetItemPower(ITEM_STOP_WATCH, SI_VAR(0), SI_VAR(1));
    MakeStatusField(SI_VAR(0), 0x200000, 100, SI_VAR(0));
    func_80252B3C(SI_VAR(0), 0x50000000, SI_VAR(0), 0, 32);
1:
    sleep 5;
    ChooseNextTarget(0, SI_VAR(0));
    if (SI_VAR(0) != -1) {
        goto 0;
    }
    N(func_802A12D4_7270A4)();
    await N(PlayerGoHome);
});
