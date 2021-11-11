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

        if (actor->flags & ACTOR_FLAG_8000) {
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

EvtSource N(main) = {
    EVT_SET_CONST(EVT_VAR(10), 0x84)
    EVT_EXEC_WAIT(battle_item_thunder_bolt_UseItemWithEffect)
    EVT_THREAD
        EVT_WAIT_FRAMES(5)
        EVT_CALL(UseBattleCamPreset, 2)
        EVT_CALL(MoveBattleCamOver, 20)
    EVT_END_THREAD
    EVT_CALL(battle_item_thunder_bolt_FadeBackgroundToBlack)
    EVT_CALL(PlaySound, 869)
    EVT_WAIT_FRAMES(10)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, -127)
    EVT_CALL(ItemCheckHit, EVT_VAR(0), 268435456, 0, EVT_VAR(0), 0)
    EVT_IF_EQ(EVT_VAR(0), 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(battle_item_thunder_bolt_func_802A123C_722D7C)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(StartRumble, 10)
    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FIXED(1.0))
    EVT_CALL(GetItemPower, 130, EVT_VAR(0), EVT_VAR(1))
    EVT_CALL(ItemDamageEnemy, EVT_VAR(0), 939524128, 0, EVT_VAR(0), 32)
    EVT_LABEL(1)
    EVT_WAIT_FRAMES(5)
    EVT_CALL(UseBattleCamPreset, 3)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetAnimation, 0, 0, 65538)
    EVT_WAIT_FRAMES(30)
    EVT_CALL(battle_item_thunder_bolt_func_802A1420_722F60)
    EVT_EXEC_WAIT(battle_item_thunder_bolt_PlayerGoHome)
    EVT_RETURN
    EVT_END
};
