#include "strange_cake.h"
#include "battle/item/strange_cake/strange_cake1.png.h"
#include "battle/item/strange_cake/strange_cake2.png.h"
#include "battle/item/strange_cake/strange_cake3.png.h"

s32 N(data)[] = {
    0x00000008, 0x00000005, 0x00000003, 0x00000004,
    0x00000002, 0x0000003C, 0x802A2170, 0x802A2370,
    0x00000003, 0x00000000, 0x00000008, 0x00000005,
    0x00000003, 0x00000004, 0x00000002, 0x0000003C,
    0x802A2390, 0x802A2590, 0x00000003, 0x00000000,
    0x00000008, 0x00000005, 0x00000003, 0x00000004,
    0x00000002, 0x0000003C, 0x802A25B0, 0x802A27B0,
    0x00000003, 0x00000000
};

s32 N(D_802A2848_732B48)[] = {
    0x802A27F8, 0x802A2820, 0x802A27D0, 0x802A27F8
};

s32 N(D_802A2858_732B58)[] = {
    0x00000000, 0x00000001, 0x00000002, 0x00000000, 0x00000001, 0x000000000
};

Script N(script6) = SCRIPT({
    GetMenuSelection(SI_VAR(0), SI_VAR(1), SI_VAR(2));
    if (SI_VAR(1) == 211) {
        SI_VAR(10) = c ItemId_KOOKY_COOKIE;
        SI_VAR(1) = 0;
        await N(UseItemWithEffect);
        await N(EatItem);
        N(func_802A1A8C_731D8C)();
        GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) += 20;
        SI_VAR(1) += 25;
        N(func_802A18D8_731BD8)(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(3));
        GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 25;
        func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(3));
        N(AddFP)(SI_VAR(3));
        sleep 10;
        SetAnimation(ActorID_PLAYER, 0, PlayerAnim_THUMBS_UP);
        sleep 30;
        GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        func_802D75D8(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(3));
        SetAnimation(ActorID_PLAYER, 0, PlayerAnim_2);
        sleep 20;
        SetAnimation(ActorID_PLAYER, 0, PlayerAnim_GOT_ITEM);
    } else {
        SI_VAR(10) = c ItemId_STRANGE_CAKE;
        SI_VAR(1) = 0;
        await N(UseItemWithEffect);
        await N(EatItem);
        SetAnimation(ActorID_PLAYER, 0, PlayerAnim_GOT_ITEM);
    }
    sleep 10;
    spawn {
        sleep 220;
        PlaySoundAtActor(ActorID_PLAYER, 1011);
    }
    PlaySoundAtActor(ActorID_PLAYER, 872);
    N(func_802A13E4_7316E4)();
    sleep 2;
    match SI_VAR(0) {
        == 0 {
            await N(script7);
        }
        == 1 {
            await N(script8);
        }
        == 2 {
            await N(script9);
        }
    }
    await N(PlayerGoHome);
});

Script N(script7) = SCRIPT({
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_2);
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 20;
    PlayEffect(87, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 1.0, 30, 0, 0, 0, 0, 0, 0, 0);
    N(func_802A1AD8_731DD8)();
    sleep 20;
    ShowMessageBox(16, 60);
    WaitForMessageBoxDone();
});

Script N(script8) = SCRIPT({
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_2);
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 20;
    PlayEffect(51, 6, SI_VAR(0), SI_VAR(1), SI_VAR(2), 1.0, 30, 0, 0, 0, 0, 0, 0, 0);
    N(func_802A1B14_731E14)();
    sleep 20;
    ShowMessageBox(17, 60);
    WaitForMessageBoxDone();
});

Script N(script9) = SCRIPT({
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_30004);
    SetGoalToTarget(ActorID_PLAYER);
    GetGoalPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    spawn DoSleepHit;
    N(func_802A1B68_731E68)();
    sleep 20;
    ShowMessageBox(11, 60);
    WaitForMessageBoxDone();
});

