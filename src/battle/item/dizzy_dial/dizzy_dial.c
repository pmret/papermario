#include "dizzy_dial.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = c 0x9A;
    await N(UseItemWithEffect);
    UseCamPreset(2);
    MoveBattleCamOver(20);
    sleep 10;
    spawn {
        sleep 5;
        AddBattleCamZoom(0xFFFFFF06);
        MoveBattleCamOver(80);
        func_8024ECF8(0, 0, 1);
        sleep 80;
        AddBattleCamZoom(250);
        MoveBattleCamOver(3);
        func_8024ECF8(0, 0, 1);
    }
    N(func_802A1270_727B80)();
    spawn {
        StartRumble(8);
        ShakeCam(1, 0, 2, 1.0);
        ShakeCam(1, 0, 2, 4.0);
        ShakeCam(1, 0, 2, 3.0);
        ShakeCam(1, 0, 2, 2.0);
        ShakeCam(1, 0, 2, 1.0);
        ShakeCam(1, 0, 2, 0.5);
        sleep 10;
        UseCamPreset(3);
        MoveBattleCamOver(10);
        func_8024ECF8(0, 0, 0);
    }
    InitTargetIterator();
0:
    SetGoalToTarget(ActorID_SELF);
    ItemCheckHit(SI_VAR(0), 0x10000000, 0, SI_VAR(0), 0);
    if (SI_VAR(0) == 6) {
        goto 1;
    }
    GetItemPower(ItemId_DIZZY_DIAL, SI_VAR(0), SI_VAR(1));
    MakeStatusField(SI_VAR(0), 0x40000, 100, SI_VAR(0));
    func_80252B3C(SI_VAR(0), 0x50000000, SI_VAR(0), 0, 32);
1:
    sleep 5;
    ChooseNextTarget(0, SI_VAR(0));
    if (SI_VAR(0) != -1) {
        goto 0;
    }
    sleep 30;
    await N(PlayerGoHome);
});
