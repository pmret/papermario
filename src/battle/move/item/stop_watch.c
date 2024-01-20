#include "common.h"
#include "script_api/battle.h"
#include "model.h"
#include "effects.h"

#define NAMESPACE battle_item_stop_watch

#include "battle/common/move/ItemRefund.inc.c"

#include "common/FadeBackgroundDarken.inc.c"
#include "common/FadeBackgroundLighten.inc.c"

#include "battle/common/move/UseItem.inc.c"

EvtScript N(EVS_UseItem) = {
    SetConst(LVarA, ITEM_STOP_WATCH)
    ExecWait(N(UseItemWithEffect))
    Thread
        Wait(5)
        Call(UseBattleCamPreset, BTL_CAM_DEFAULT)
        Call(MoveBattleCamOver, 20)
    EndThread
    Call(N(FadeBackgroundDarken))
    PlayEffect(EFFECT_STOP_WATCH, 0, 0, 0, 0, Float(1.0), 200, 0)
    Call(PlaySoundAtActor, ACTOR_PLAYER, SOUND_TIME_OUT)
    Wait(200)
    Call(UseBattleCamPreset, BTL_CAM_PRESET_03)
    Call(MoveBattleCamOver, 20)
    Call(InitTargetIterator)
    Label(0)
        Call(SetGoalToTarget, ACTOR_SELF)
        Call(ItemCheckHit, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, LVar0, 0)
        IfEq(LVar0, HIT_RESULT_MISS)
            Goto(1)
        EndIf
        Call(GetItemPower, ITEM_STOP_WATCH, LVar0, LVar1)
        Call(MakeStatusField, LVar0, STATUS_FLAG_STOP, 100, LVar0)
        Call(ItemAfflictEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_STATUS_ALWAYS_HITS, LVar0, 0, BS_FLAGS1_TRIGGER_EVENTS)
        Label(1)
        Wait(5)
        Call(ChooseNextTarget, ITER_NEXT, LVar0)
        IfNe(LVar0, ITER_NO_MORE)
            Goto(0)
        EndIf
    Call(N(FadeBackgroundLighten))
    ExecWait(N(PlayerGoHome))
    Return
    End
};
