#include "thunder_bolt.h"
#include "effects.h"

#include "ItemRefund.inc.c"

ApiStatus N(func_802A123C_722D7C)(Evt* script, s32 isInitialCall) {
    Actor* enemyTarget = get_actor(script->owner1.enemyID);
    Actor* actor = get_actor(enemyTarget->targetActorID);
    f32 posY, posX, posZ;
    s32 scaleX, scaleY;

    if (actor != NULL) {
        sfx_play_sound(0x366);

        posX = actor->currentPos.x;
        posY = actor->currentPos.y + (actor->size.y / 10);
        posZ = actor->currentPos.z;

        scaleX = (actor->size.x + (actor->size.x >> 2)) * actor->scalingFactor;
        scaleY = (actor->size.y - 2) * actor->scalingFactor;

        if (actor->flags & 0x8000) {
            posY -= actor->size.y / 2;
        }

        playFX_36(rand_int(2) + 3, posX, posY, posZ, scaleX, scaleY);

        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

#include "common/FadeBackgroundToBlack.inc.c"

ApiStatus N(func_802A1420_722F60)(Evt* script, s32 isInitialCall) {
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
    SI_VAR(10) = (const) ITEM_THUNDER_BOLT;
    await N(UseItemWithEffect);
    spawn {
        sleep 5;
        UseBattleCamPreset(2);
        MoveBattleCamOver(20);
    }
    N(FadeBackgroundToBlack)();
    PlaySound(SOUND_UNKNOWN_365);
    sleep 10;
    InitTargetIterator();
    SetGoalToTarget(ACTOR_SELF);
    ItemCheckHit(SI_VAR(0), 0x10000000, 0, SI_VAR(0), 0);
    if (SI_VAR(0) == 6) {
        goto 1;
    }
    N(func_802A123C_722D7C)();
    sleep 5;
    StartRumble(10);
    ShakeCam(1, 0, 5, 1.0);
    GetItemPower(ITEM_THUNDER_RAGE, SI_VAR(0), SI_VAR(1));
    ItemDamageEnemy(SI_VAR(0), 0x38000020, 0, SI_VAR(0), 32);
1:
    sleep 5;
    UseBattleCamPreset(3);
    MoveBattleCamOver(20);
    SetAnimation(ACTOR_PLAYER, 0, ANIM_10002);
    sleep 30;
    N(func_802A1420_722F60)();
    await N(PlayerGoHome);
});
