#include "tasty_tonic.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = (const) ITEM_TASTY_TONIC;
    await N(UseItemWithEffect);
    InitTargetIterator();
    GetOwnerTarget(SI_VAR(0), SI_VAR(1));
    if (SI_VAR(0) == 0) {
        await N(DrinkItem);
        GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 25;
        SI_VAR(2) += 5;
        func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
        GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 20;
        SetAnimation(ACTOR_PLAYER, 0, ANIM_THUMBS_UP);
        sleep 30;
        SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
        GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(2) += 5;
        func_802D75D8(SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
        N(func_802A123C_72223C)(ACTOR_PLAYER);
        sleep 20;
    } else {
        GetActorPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 25;
        SI_VAR(2) += 5;
        func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), 5);
        GetActorPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(1) += 20;
        sleep 30;
        GetActorPos(ACTOR_PARTNER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
        SI_VAR(2) += 5;
        func_802D75D8(SI_VAR(0), SI_VAR(1), SI_VAR(2), 5);
        N(func_802A123C_72223C)(ACTOR_PARTNER);
        sleep 20;
    }
    await N(PlayerGoHome);
});
