#include "common.h"
#include "script_api/battle.h"
#include "effects.h"
#include "model.h"
#include "sprite/player.h"

#define NAMESPACE battle_item_thunder_bolt

#include "battle/common/move/ItemRefund.inc.c"

API_CALLABLE(N(SpawnLightningFX)) {
    Actor* enemyTarget = get_actor(script->owner1.enemyID);
    Actor* actor = get_actor(enemyTarget->targetActorID);
    f32 posY, posX, posZ;
    s32 scaleX, scaleY;

    if (actor != NULL) {
        sfx_play_sound(SOUND_LIGHTNING_STRIKE);

        posX = actor->curPos.x;
        posY = actor->curPos.y + (actor->size.y / 10);
        posZ = actor->curPos.z;

        scaleX = (actor->size.x + (actor->size.x >> 2)) * actor->scalingFactor;
        scaleY = (actor->size.y - 2) * actor->scalingFactor;

        if (actor->flags & ACTOR_FLAG_HALF_HEIGHT) {
            posY -= actor->size.y / 2;
        }

        fx_lightning(rand_int(2) + 3, posX, posY, posZ, scaleX, scaleY);

        return ApiStatus_DONE2;
    }

    return ApiStatus_DONE2;
}

#include "common/FadeBackgroundDarken.inc.c"
#include "common/FadeBackgroundLighten.inc.c"

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    SetConst(LVarA, ITEM_THUNDER_BOLT)
    ExecWait(N(UseItemWithEffect))
    Thread
        Wait(5)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 20)
    EndThread
    Call(N(FadeBackgroundDarken))
    Call(PlaySound, SOUND_THUNDER_BOLT)
    Wait(10)
    Call(InitTargetIterator)
    Call(SetGoalToTarget, ACTOR_SELF)
    Call(ItemCheckHit, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, LVar0, 0)
    IfEq(LVar0, HIT_RESULT_MISS)
        Goto(1)
    EndIf
    Call(N(SpawnLightningFX))
    Wait(5)
    Call(StartRumble, BTL_RUMBLE_PLAYER_EXTREME)
    Call(ShakeCam, CAM_BATTLE, 0, 5, Float(1.0))
    Call(GetItemPower, ITEM_THUNDER_RAGE, LVar0, LVar1)
    Call(ItemDamageEnemy, LVar0, DAMAGE_TYPE_SHOCK | DAMAGE_TYPE_IGNORE_DEFENSE | DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_MULTIPLE_POPUPS, 0, LVar0, BS_FLAGS1_TRIGGER_EVENTS)
    Label(1)
    Wait(5)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
    Call(MoveBattleCamOver, 20)
    Call(SetAnimation, ACTOR_PLAYER, 0, ANIM_Mario1_Idle)
    Wait(30)
    Call(N(FadeBackgroundLighten))
    ExecWait(N(PlayerGoHome))
    Return
    End
};
