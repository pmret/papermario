#include "unknown_item.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = (const) ITEM_ULTRA_SHROOM;
    await N(UseItemWithEffect);
    await N(EatItem);
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 0;
    SI_VAR(1) += 35;
    N(func_802A123C_72447C)(SI_VAR(0), SI_VAR(1), SI_VAR(2), 20);
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 25;
    SI_VAR(2) += 5;
    func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), 20);
    N(func_802A12FC_72453C)();
    sleep 10;
    SetAnimation(ACTOR_PLAYER, 0, ANIM_THUMBS_UP);
    sleep 30;
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(2) += 5;
    func_802D75D8(SI_VAR(0), SI_VAR(1), SI_VAR(2), 20);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    sleep 20;
    await N(PlayerGoHome);
});
