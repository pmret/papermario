#include "dried_shroom.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = c ITEM_DRIED_SHROOM;
    await N(UseItemWithEffect);
    await N(EatItem);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_STICK_OUT_TONGUE);
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 0;
    SI_VAR(1) += 35;
    N(func_802A123C_71CF1C)(SI_VAR(0), SI_VAR(1), SI_VAR(2), 1);
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 25;
    SI_VAR(2) += 5;
    func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), 1);
    N(func_802A12FC_71CFDC)();
    sleep 30;
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(2) += 5;
    func_802D75D8(SI_VAR(0), SI_VAR(1), SI_VAR(2), 1);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    sleep 20;
    await N(PlayerGoHome);
});
