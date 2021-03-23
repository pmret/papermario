#include "dried_shroom.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = c 0x8D;
    await N(UseItemWithEffect);
    await N(EatItem);
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_STICK_OUT_TONGUE);
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 0;
    SI_VAR(1) += 35;
    N(func_802A123C_71CF1C)(SI_VAR(0), SI_VAR(1), SI_VAR(2), 1);
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 25;
    SI_VAR(2) += 5;
    func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), 1);
    N(func_802A12FC_71CFDC)();
    sleep 30;
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(2) += 5;
    func_802D75D8(SI_VAR(0), SI_VAR(1), SI_VAR(2), 1);
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_2);
    sleep 20;
    await N(PlayerGoHome);
});
