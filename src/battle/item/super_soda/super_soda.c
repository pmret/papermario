#include "super_soda.h"

Script N(script6) = SCRIPT({
    SetActorYaw(ActorID_PLAYER, 30);
    sleep 1;
    SetActorYaw(ActorID_PLAYER, 60);
    sleep 1;
    SetActorYaw(ActorID_PLAYER, 90);
    sleep 1;
    SetActorYaw(ActorID_PLAYER, 120);
    sleep 1;
    SetActorYaw(ActorID_PLAYER, 150);
    sleep 1;
    SetActorYaw(ActorID_PLAYER, 180);
    sleep 10;
    SI_VAR(1) = SI_VAR(15);
    await 0x802A1834;
    SI_VAR(14) = SI_VAR(10);
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_THROW);
    spawn {
        sleep 20;
        SetAnimation(ActorID_PLAYER, 0, PlayerAnim_2);
    }
    func_802D3474(SI_VAR(10), 0x80283EE8);
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 0;
    SI_VAR(1) += 30;
    SI_VAR(2) += 5;
    func_802D36E0(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2));
    func_802D3F74(SI_VAR(10), 32);
    spawn {
        GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 45;
        MakeItemEntity(SI_VAR(14), SI_VAR(0), SI_VAR(1), SI_VAR(2), 1, 0);
        SI_VAR(14) = SI_VAR(0);
        loop 25 {
            func_802D378C(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2));
            N(func_802A123C_724F1C)(SI_VAR(0), SI_VAR(1), SI_VAR(2));
            sleep 1;
        }
        RemoveItemEntity(SI_VAR(14));
    }
    InitTargetIterator();
    SetGoalToTarget(ActorID_SELF);
    GetGoalPos(ActorID_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetBattleCamTarget(0xFFFFFF83, 1, 0);
    SetBattleCamOffsetZ(41);
    SetBattleCamZoom(248);
    MoveBattleCamOver(25);
    func_802D39FC(SI_VAR(10), 0.400390625);
    SI_VAR(2) += 5;
    func_802D3C58(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 25);
    AddBattleCamZoom(100);
    MoveBattleCamOver(30);
    GetActorPos(ActorID_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 25;
    func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(11));
    if (SI_VAR(11) > 0) {
        N(func_802A12EC_724FCC)(SI_VAR(11));
    }
    sleep 30;
    GetActorPos(ActorID_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    func_802D75D8(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(11));
    sleep 20;
    SetActorYaw(ActorID_PLAYER, 150);
    sleep 1;
    SetActorYaw(ActorID_PLAYER, 120);
    sleep 1;
    SetActorYaw(ActorID_PLAYER, 90);
    sleep 1;
    SetActorYaw(ActorID_PLAYER, 60);
    sleep 1;
    SetActorYaw(ActorID_PLAYER, 30);
    sleep 1;
    SetActorYaw(ActorID_PLAYER, 0);
    sleep 10;
});

Script N(main) = SCRIPT({
    SI_VAR(10) =c 0x9B;
    await N(UseItemWithEffect);
    InitTargetIterator();
    GetOwnerTarget(SI_VAR(0), SI_VAR(1));
    if (SI_VAR(0) == 0) {
        PlaySoundAtActor(ActorID_PLAYER, 8341);
        SetAnimation(ActorID_PLAYER, 0, PlayerAnim_DRINK);
        sleep 45;
        GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) += 0;
        SI_VAR(1) += 35;
        N(func_802A1418_7250F8)(SI_VAR(0), SI_VAR(1), SI_VAR(2), 5);
        N(AddFP)(5);
        GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 25;
        func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), 5);
        GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 20;
        SetAnimation(ActorID_PLAYER, 0, PlayerAnim_THUMBS_UP);
        sleep 30;
        SetAnimation(ActorID_PLAYER, 0, PlayerAnim_2);
        GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        func_802D75D8(SI_VAR(0), SI_VAR(1), SI_VAR(2), 5);
        InitTargetIterator();
        GetOwnerTarget(SI_VAR(0), SI_VAR(1));
        N(func_802A1378_725058)(0);
        sleep 20;
    } else {
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        SI_VAR(15) = 0;
        await 0x802A1AEC;
    }
    await N(PlayerGoHome);
});
