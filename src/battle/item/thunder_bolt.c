#include "thunder_bolt.h"
#include "effects.h"
#include "model.h"

#include "ItemRefund.inc.c"

API_CALLABLE(N(func_802A123C_722D7C)) {
    Actor* enemyTarget = get_actor(script->owner1.enemyID);
    Actor* actor = get_actor(enemyTarget->targetActorID);
    f32 posY, posX, posZ;
    s32 scaleX, scaleY;

    if (actor != NULL) {
        sfx_play_sound(SOUND_366);

        posX = actor->currentPos.x;
        posY = actor->currentPos.y + (actor->size.y / 10);
        posZ = actor->currentPos.z;

        scaleX = (actor->size.x + (actor->size.x >> 2)) * actor->scalingFactor;
        scaleY = (actor->size.y - 2) * actor->scalingFactor;

        if (actor->flags & ACTOR_FLAG_8000) {
            posY -= actor->size.y / 2;
        }

        fx_lightning(rand_int(2) + 3, posX, posY, posZ, scaleX, scaleY);

        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

#include "common/FadeBackgroundToBlack.inc.c"

API_CALLABLE(N(func_802A1420_722F60)) {
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

EvtScript N(main) = {
    EVT_SET_CONST(LVarA, 0x84)
    EVT_EXEC_WAIT(battle_item_thunder_bolt_UseItemWithEffect)
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_C)
        EVT_CALL(MoveBattleCamOver, 20)
    EVT_END_THREAD
    EVT_CALL(battle_item_thunder_bolt_FadeBackgroundToBlack)
    EVT_CALL(PlaySound, 869)
    EVT_WAIT(10)
    EVT_CALL(InitTargetIterator)
    EVT_CALL(SetGoalToTarget, -127)
    EVT_CALL(ItemCheckHit, LVar0, 268435456, 0, LVar0, 0)
    EVT_IF_EQ(LVar0, 6)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(battle_item_thunder_bolt_func_802A123C_722D7C)
    EVT_WAIT(5)
    EVT_CALL(StartRumble, 10)
    EVT_CALL(ShakeCam, 1, 0, 5, EVT_FLOAT(1.0))
    EVT_CALL(GetItemPower, 130, LVar0, LVar1)
    EVT_CALL(ItemDamageEnemy, LVar0, 939524128, 0, LVar0, BS_FLAGS1_SP_EVT_ACTIVE)
    EVT_LABEL(1)
    EVT_WAIT(5)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_D)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(SetAnimation, 0, 0, 65538)
    EVT_WAIT(30)
    EVT_CALL(battle_item_thunder_bolt_func_802A1420_722F60)
    EVT_EXEC_WAIT(battle_item_thunder_bolt_PlayerGoHome)
    EVT_RETURN
    EVT_END
};
