#include "ultra_shroom.h"

Script N(main) = SCRIPT({
    SI_VAR(10) =c 0x8C;
    await N(UseItemWithEffect);
    AddBattleCamZoom(50);
    MoveBattleCamOver(20);
    await N(EatItem);
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 0;
    SI_VAR(1) += 35;
    N(func_802A123C_7239BC)(SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 25;
    SI_VAR(2) += 5;
    func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
    N(func_802A12FC_723A7C)();
    sleep 10;
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_THUMBS_UP);
    sleep 30;
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(2) += 5;
    func_802D75D8(SI_VAR(0), SI_VAR(1), SI_VAR(2), 10);
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_2);
    sleep 20;
    await N(PlayerGoHome);
});
