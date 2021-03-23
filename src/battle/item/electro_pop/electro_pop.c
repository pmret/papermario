#include "electro_pop.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = c 0xCC;
    await N(UseItemWithEffect);
    await N(EatItem);
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 20;
    PlayEffect(87, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 1.0, 30, 0, 0, 0, 0, 0, 0, 0);
    PlaySound(889);
    GetItemPower(ItemId_VOLT_SHROOM, SI_VAR(0), SI_VAR(1));
    N(func_802A123C_7307DC)();
    sleep 40;
    N(func_802A14F0_730A90)();
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 20;
    SI_VAR(1) += 25;
    N(func_802A133C_7308DC)(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(3));
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
    ShowMessageBox(16, 60);
    WaitForMessageBoxDone();
    await N(PlayerGoHome);
});
