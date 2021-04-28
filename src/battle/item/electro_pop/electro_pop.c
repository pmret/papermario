#include "electro_pop.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = (const) ITEM_ELECTRO_POP;
    await N(UseItemWithEffect);
    await N(EatItem);
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 20;
    PlayEffect(0x57, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 1.0, 30, 0, 0, 0, 0, 0, 0, 0);
    PlaySound(SOUND_UNKNOWN_379);
    GetItemPower(ITEM_VOLT_SHROOM, SI_VAR(0), SI_VAR(1));
    N(func_802A123C_7307DC)();
    sleep 40;
    N(func_802A14F0_730A90)();
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 20;
    SI_VAR(1) += 25;
    N(func_802A133C_7308DC)(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(3));
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 25;
    func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(3));
    N(AddFP)(SI_VAR(3));
    sleep 10;
    SetAnimation(ACTOR_PLAYER, 0, ANIM_THUMBS_UP);
    sleep 30;
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    func_802D75D8(SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(3));
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    sleep 20;
    ShowMessageBox(16, 60);
    WaitForMessageBoxDone();
    await N(PlayerGoHome);
});
