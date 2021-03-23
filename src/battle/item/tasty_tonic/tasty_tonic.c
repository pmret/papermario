#include "tasty_tonic.h"

Script N(main) = SCRIPT({
    SI_VAR(10) =c 0x89;
    await N(UseItemWithEffect);
    InitTargetIterator();
    GetOwnerTarget(SI_VAR(0), SI_VAR(1));
    if (SI_VAR(0) == 0) {
        await N(DrinkItem);
        GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 25;
        SI_VAR(2) += 5;
        func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
        GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 20;
        SetAnimation(ActorID_PLAYER, 0, PlayerAnim_THUMBS_UP);
        sleep 30;
        SetAnimation(ActorID_PLAYER, 0, PlayerAnim_2);
        GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(2) += 5;
        func_802D75D8(SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
        N(func_802A123C_72223C)(0);
        sleep 20;
    } else {
        GetActorPos(ActorID_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 25;
        SI_VAR(2) += 5;
        func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), 5);
        GetActorPos(ActorID_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 20;
        sleep 30;
        GetActorPos(ActorID_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(2) += 5;
        func_802D75D8(SI_VAR(0), SI_VAR(1), SI_VAR(2), 5);
        N(func_802A123C_72223C)(256);
        sleep 20;
    }
    await N(PlayerGoHome);
});
