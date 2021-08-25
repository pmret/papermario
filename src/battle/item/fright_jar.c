#include "fright_jar.h"

#include "ItemRefund.inc.c"

#include "common/FadeBackgroundToBlack.inc.c"

ApiStatus N(func_802A12D4_72BBE4)(Evt* script, s32 isInitialCall) {
    if (isInitialCall) {
        script->functionTemp[0] = 20;
    }

    set_background_color_blend(0, 0, 0, (script->functionTemp[0] * 10) & 254);

    script->functionTemp[0]--;
    if (script->functionTemp[0] == 0) {
        set_background_color_blend(0, 0, 0, 0);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

#include "UseItem.inc.c"

EvtSource N(main) = SCRIPT({
    SI_VAR(10) = (const) ITEM_FRIGHT_JAR;
    await N(UseItemWithEffect);
    N(FadeBackgroundToBlack)();
    spawn {
        sleep 5;
        UseBattleCamPreset(2);
        MoveBattleCamOver(50);
    }
    SetAnimation(ACTOR_PLAYER, 0, ANIM_CROUCH);
    PlaySoundAtActor(ACTOR_PLAYER, SOUND_UNKNOWN_367);
    GetActorPos(ACTOR_PLAYER, SI_VAR(0), SI_VAR(1), SI_VAR(2));
    SI_VAR(0) += 0xFFFFFFD8;
    SI_VAR(1) += 5;
    SI_VAR(3) = 0.7001953125;
    loop 5 {
        PlayEffect(0x61, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2), SI_VAR(3), 25, 0, 0, 0, 0, 0, 0, 0);
        SI_VAR(0) += 5;
        SI_VAR(3) += 0.150390625;
        sleep 7;
    }
    PlayEffect(0x61, 0, SI_VAR(0), SI_VAR(1), SI_VAR(2), 1.5, 60, 0, 0, 0, 0, 0, 0, 0);
    sleep 20;
    loop 4 {
        AddBattleCamZoom(0xFFFFFF9C);
        MoveBattleCamOver(2);
        sleep 2;
        AddBattleCamZoom(100);
        MoveBattleCamOver(2);
        sleep 2;
    }
    UseBattleCamPreset(3);
    MoveBattleCamOver(20);
    InitTargetIterator();
0:
    SetGoalToTarget(ACTOR_SELF);
    ItemCheckHit(SI_VAR(0), 0x10000000, 0, SI_VAR(0), 0);
    if (SI_VAR(0) == 6) {
        goto 1;
    }
    func_80269EAC(21);
    ItemAfflictEnemy(SI_VAR(0), 0x70001000, 0, 100, 0, 32);
1:
    ChooseNextTarget(0, SI_VAR(0));
    if (SI_VAR(0) != -1) {
        goto 0;
    }
    sleep 10;
    SetAnimation(ACTOR_PLAYER, 0, ANIM_WALKING);
    N(func_802A12D4_72BBE4)();
    sleep 20;
    await N(PlayerGoHome);
});
