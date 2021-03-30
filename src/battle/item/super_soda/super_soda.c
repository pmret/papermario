#include "super_soda.h"

Script N(script6) = SCRIPT({
    SetActorYaw(ACTOR_PLAYER, 30);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 60);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 90);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 120);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 150);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 180);
    sleep 10;
    SI_VAR(1) = SI_VAR(15);
    await N(UseItem);
    SI_VAR(14) = SI_VAR(10);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_THROW);
    spawn {
        sleep 20;
        SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    }
    func_802D3474(SI_VAR(10), 0x80283EE8);
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 0;
    SI_VAR(1) += 30;
    SI_VAR(2) += 5;
    func_802D36E0(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2));
    func_802D3F74(SI_VAR(10), 32);
    spawn {
        GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
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
    SetGoalToTarget(ACTOR_SELF);
    GetGoalPos(ACTOR_SELF, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SetBattleCamTarget(0xFFFFFF83, 1, 0);
    SetBattleCamOffsetZ(41);
    SetBattleCamZoom(248);
    MoveBattleCamOver(25);
    func_802D39FC(SI_VAR(10), 0.400390625);
    SI_VAR(2) += 5;
    func_802D3C58(SI_VAR(10), SI_VAR(0), SI_VAR(1), SI_VAR(2), 25);
    AddBattleCamZoom(100);
    MoveBattleCamOver(30);
    GetActorPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 25;
    func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(11));
    if (SI_VAR(11) > 0) {
        N(func_802A12EC_724FCC)(SI_VAR(11));
    }
    sleep 30;
    GetActorPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    func_802D75D8(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(11));
    sleep 20;
    SetActorYaw(ACTOR_PLAYER, 150);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 120);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 90);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 60);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 30);
    sleep 1;
    SetActorYaw(ACTOR_PLAYER, 0);
    sleep 10;
});

Script N(main) = SCRIPT({
    SI_VAR(10) = c ITEM_SUPER_SODA;
    await N(UseItemWithEffect);
    InitTargetIterator();
    GetOwnerTarget(SI_VAR(0), SI_VAR(1));
    if (SI_VAR(0) == ACTOR_PLAYER) {
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_2095);
        SetAnimation(ACTOR_PLAYER, 0, ANIM_DRINK);
        sleep 45;
        GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(0) += 0;
        SI_VAR(1) += 35;
        N(func_802A1418_7250F8)(SI_VAR(0), SI_VAR(1), SI_VAR(2), 5);
        N(AddFP)(5);
        GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 25;
        func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), 5);
        GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 20;
        SetAnimation(ACTOR_PLAYER, 0, ANIM_THUMBS_UP);
        sleep 30;
        SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
        GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        func_802D75D8(SI_VAR(0), SI_VAR(1), SI_VAR(2), 5);
        InitTargetIterator();
        GetOwnerTarget(SI_VAR(0), SI_VAR(1));
        N(func_802A1378_725058)(ACTOR_PLAYER);
        sleep 20;
    } else {
        SI_VAR(11) = 0;
        SI_VAR(12) = 0;
        SI_VAR(15) = 0;
        await N(script6);
    }
    await N(PlayerGoHome);
});
