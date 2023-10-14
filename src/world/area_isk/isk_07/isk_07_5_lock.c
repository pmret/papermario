#include "isk_07.h"

#include "world/common/todo/RemovePadlock.inc.c"

s32 N(ItemList_RuinsKey)[] = {
    ITEM_RUINS_KEY,
    ITEM_NONE
};

EvtScript N(EVS_UnlockPrompt_RuinsDoor) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
            EVT_CALL(CloseChoicePopup)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            EVT_RETURN
        EVT_CASE_EQ(-1)
            EVT_CALL(CloseChoicePopup)
            EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, -300, -380, 530)
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_SET(GF_ISK07_UnlockedDoor, TRUE)
    EVT_SET(LVar0, MV_LockEntityID)
    EVT_CALL(N(RemovePadlock))
    EVT_SET(LVar1, 0)
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilittw, SOUND_ISK_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 65, 65, EASING_LINEAR)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateGroup, MODEL_g310, 0, LVar0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(CloseChoicePopup)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupLock) = {
    EVT_IF_EQ(GF_ISK07_UnlockedDoor, FALSE)
        EVT_CALL(MakeTransformGroup, MODEL_g310)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_UnlockPrompt_RuinsDoor)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(ItemList_RuinsKey)), 0, 1)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_g310, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_CALL(TranslateModel, MODEL_o2057, 0, 65, 0)
    EVT_CALL(TranslateModel, MODEL_o2058, 0, 65, 0)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitte, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShutEntryDoor) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilitte, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitte, SOUND_ISK_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 65, 0, 15, EASING_QUADRATIC_IN)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o2057, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o2058, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilitte, SOUND_ISK_DOOR_SLAM, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(0.3))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenEntryDoor) = {
    EVT_CALL(MakeLerp, 0, 65, 15, EASING_LINEAR)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o2057, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o2058, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitte, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};
