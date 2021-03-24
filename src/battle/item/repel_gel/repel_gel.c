#include "repel_gel.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = c ItemId_REPEL_GEL;
    await N(UseItemWithEffect);
    PlaySoundAtActor(ActorID_PLAYER, SoundId_375);
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_30008);
    sleep 45;
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_2);
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 20;
    PlayEffect(0x33, 3, SI_VAR(0), SI_VAR(1), SI_VAR(2), 1.0, 30, 0, 0, 0, 0, 0, 0, 0);
    PlaySoundAtActor(ActorID_PLAYER, SoundId_376);
    GetItemPower(ItemId_REPEL_GEL, SI_VAR(0), SI_VAR(1));
    N(func_802A123C_72DDAC)();
    sleep 20;
    ShowMessageBox(17, 60);
    WaitForMessageBoxDone();
    await N(PlayerGoHome);
});

