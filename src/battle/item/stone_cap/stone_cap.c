#include "stone_cap.h"

Script N(main) = SCRIPT({
    SI_VAR(10) =c 0x88;
    await N(UseItemWithEffect);
    PlaySound(865);
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_30009);
    sleep 30;
    SetAnimation(ActorID_PLAYER, 0, PlayerAnim_CROUCH);
    GetItemPower(ItemId_STONE_CAP, SI_VAR(0), SI_VAR(1));
    PlaySound(866);
    N(func_802A123C_7217DC)();
    GetActorPos(ActorID_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    sleep 20;
});
