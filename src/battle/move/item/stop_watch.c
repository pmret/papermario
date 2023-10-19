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
    EVT_SET_CONST(LVarA, ITEM_STOP_WATCH)
    EVT_EXEC_WAIT(N(UseItemWithEffect))
    EVT_THREAD
        EVT_WAIT(5)
        EVT_CALL(UseBattleCamPreset, BTL_CAM_DEFAULT)
        EVT_CALL(MoveBattleCamOver, 20)
    EVT_END_THREAD
    EVT_CALL(N(FadeBackgroundDarken))
    EVT_PLAY_EFFECT(EFFECT_STOP_WATCH, 0, 0, 0, 0, EVT_FLOAT(1.0), 200, 0)
    EVT_CALL(PlaySoundAtActor, ACTOR_PLAYER, SOUND_TIME_OUT)
    EVT_WAIT(200)
    EVT_CALL(UseBattleCamPreset, BTL_CAM_PRESET_03)
    EVT_CALL(MoveBattleCamOver, 20)
    EVT_CALL(InitTargetIterator)
    EVT_LABEL(0)
        EVT_CALL(SetGoalToTarget, ACTOR_SELF)
        EVT_CALL(ItemCheckHit, LVar0, DAMAGE_TYPE_NO_CONTACT, 0, LVar0, 0)
        EVT_IF_EQ(LVar0, HIT_RESULT_MISS)
            EVT_GOTO(1)
        EVT_END_IF
        EVT_CALL(GetItemPower, ITEM_STOP_WATCH, LVar0, LVar1)
        EVT_CALL(MakeStatusField, LVar0, STATUS_FLAG_STOP, 100, LVar0)
        EVT_CALL(ItemAfflictEnemy, LVar0, DAMAGE_TYPE_NO_CONTACT | DAMAGE_TYPE_STATUS_ALWAYS_HITS, LVar0, 0, BS_FLAGS1_TRIGGER_EVENTS)
        EVT_LABEL(1)
        EVT_WAIT(5)
        EVT_CALL(ChooseNextTarget, ITER_NEXT, LVar0)
        EVT_IF_NE(LVar0, ITER_NO_MORE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(N(FadeBackgroundLighten))
    EVT_EXEC_WAIT(N(PlayerGoHome))
    EVT_RETURN
    EVT_END
};
