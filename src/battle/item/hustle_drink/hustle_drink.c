#include "hustle_drink.h"

Script N(main) = SCRIPT({
    SI_VAR(10) = (const) ITEM_HUSTLE_DRINK;
    await N(UseItemWithEffect);
    await N(DrinkItem);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_SQUISH);
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 25;
    func_802D7520(SI_VAR(0), SI_VAR(1), SI_VAR(2), 5);
    N(func_802A12C4_726224)();
    N(func_802A123C_72619C)();
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(1) += 20;
    UseCamPreset(13);
    BattleCamTargetActor(ACTOR_SELF);
    MoveBattleCamOver(20);
    PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_369);
    spawn {
        loop 2 {
            SetActorScale(ACTOR_SELF, 1.0, 1.0, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.1005859375, 1.0, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.2001953125, 0.9501953125, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.30078125, 0.900390625, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.3505859375, 0.8505859375, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.380859375, 0.80078125, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.400390625, 0.80078125, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.30078125, 0.8505859375, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.2001953125, 0.900390625, 1.0);
            sleep 1;
            SetActorScale(ACTOR_SELF, 1.1005859375, 0.9501953125, 1.0);
            sleep 1;
        }
        SetActorScale(ACTOR_SELF, 1.0, 1.0, 1.0);
        sleep 1;
        SetActorScale(ACTOR_SELF, 1.1005859375, 1.0, 1.0);
        sleep 1;
        SetActorScale(ACTOR_SELF, 1.2001953125, 0.9501953125, 1.0);
        sleep 1;
        SetActorScale(ACTOR_SELF, 1.30078125, 0.900390625, 1.0);
        sleep 1;
        SetActorScale(ACTOR_SELF, 1.3505859375, 0.8505859375, 1.0);
        sleep 1;
        SetActorScale(ACTOR_SELF, 1.380859375, 0.80078125, 1.0);
        sleep 1;
        SetActorScale(ACTOR_SELF, 1.400390625, 0.80078125, 1.0);
        sleep 1;
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_208E);
        SetActorScale(ACTOR_SELF, 0.900390625, 1.30078125, 1.0);
        sleep 1;
        SetActorScale(ACTOR_SELF, 0.900390625, 1.2001953125, 1.0);
        sleep 1;
        SetActorScale(ACTOR_SELF, 0.9501953125, 1.1005859375, 1.0);
        sleep 1;
        SetActorScale(ACTOR_SELF, 1.0, 1.0, 1.0);
        sleep 1;
        SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    }
    loop 10 {
        PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_369);
        PlayEffect(0x6, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
        PlayEffect(0x6, 1, SI_VAR(0), SI_VAR(1), SI_VAR(2), 0, 0, 0, 0, 0, 0, 0, 0, 0);
        sleep 4;
    }
    sleep 10;
    SetAnimation(ACTOR_PLAYER, 0, ANIM_RUNNING);
    UseCamPreset(2);
    MoveBattleCamOver(20);
    sleep 20;
    await N(PlayerGoHome);
});
