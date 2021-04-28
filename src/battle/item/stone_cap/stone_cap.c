#include "stone_cap.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = (const) ITEM_STONE_CAP;
    await N(UseItemWithEffect);
    PlaySound(SOUND_UNKNOWN_361);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_30009);
    sleep 30;
    SetAnimation(ACTOR_PLAYER, 0, ANIM_CROUCH);
    GetItemPower(ITEM_STONE_CAP, SI_VAR(0), SI_VAR(1));
    PlaySound(SOUND_UNKNOWN_362);
    N(func_802A123C_7217DC)();
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    sleep 20;
});
