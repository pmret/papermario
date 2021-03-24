#include "volt_shroom.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = c ItemId_VOLT_SHROOM;
    await N(UseItemWithEffect);
    await N(EatItem);
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_2);
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(3) = 20;
    MultiplyByActorScale(SI_VAR(3));
    SI_VAR(1) += SI_VAR(3);
    SI_VAR(3) = 1.0;
    MultiplyByActorScale(SI_VAR(3));
    PlayEffect(0x57, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(3), 30, 0, 0, 0, 0, 0, 0, 0);
    PlaySound(SoundId_379);
    GetItemPower(ItemId_VOLT_SHROOM, SI_VAR(0), SI_VAR(1));
    N(func_802A123C_71AA2C)();
    sleep 20;
    ShowMessageBox(16, 60);
    WaitForMessageBoxDone();
    await N(PlayerGoHome);
});
