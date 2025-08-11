#include "isk_07.h"

#include "world/common/todo/RemovePadlock.inc.c"

s32 N(ItemList_RuinsKey)[] = {
    ITEM_RUINS_KEY,
    ITEM_NONE
};

EvtScript N(EVS_UnlockPrompt_RuinsDoor) = {
    SetGroup(EVT_GROUP_NEVER_PAUSE)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(ShowKeyChoicePopup)
    Switch(LVar0)
        CaseEq(0)
            Call(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
            Call(CloseChoicePopup)
            Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
            Return
        CaseEq(-1)
            Call(CloseChoicePopup)
            Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
            Return
    EndSwitch
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, -300, -380, 530)
    Call(RemoveKeyItemAt, LVar1)
    Set(GF_ISK07_UnlockedDoor, true)
    Set(LVar0, MV_LockEntityID)
    Call(N(RemovePadlock))
    Set(LVar1, 0)
    Wait(5)
    Call(PlaySoundAtCollider, COLLIDER_deilittw, SOUND_ISK_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 65, 65, EASING_LINEAR)
    Label(10)
    Call(UpdateLerp)
    Call(TranslateGroup, MODEL_g310, 0, LVar0, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(10)
    EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittw, COLLIDER_FLAGS_UPPER_MASK)
    Call(CloseChoicePopup)
    Call(SetTimeFreezeMode, TIME_FREEZE_NONE)
    Unbind
    Return
    End
};

EvtScript N(EVS_SetupLock) = {
    IfEq(GF_ISK07_UnlockedDoor, false)
        Call(MakeTransformGroup, MODEL_g310)
        BindPadlock(Ref(N(EVS_UnlockPrompt_RuinsDoor)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), Ref(N(ItemList_RuinsKey)), 0, 1)
    Else
        Call(EnableModel, MODEL_g310, false)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittw, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Call(TranslateModel, MODEL_o2057, 0, 65, 0)
    Call(TranslateModel, MODEL_o2058, 0, 65, 0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitte, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_ShutEntryDoor) = {
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilitte, COLLIDER_FLAGS_UPPER_MASK)
    Call(PlaySoundAtCollider, COLLIDER_deilitte, SOUND_ISK_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 65, 0, 15, EASING_QUADRATIC_IN)
    Label(10)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o2057, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o2058, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Call(PlaySoundAtCollider, COLLIDER_deilitte, SOUND_ISK_DOOR_SLAM, SOUND_SPACE_DEFAULT)
    Call(ShakeCam, CAM_DEFAULT, 0, 10, Float(0.3))
    Return
    End
};

EvtScript N(EVS_OpenEntryDoor) = {
    Call(MakeLerp, 0, 65, 15, EASING_LINEAR)
    Label(10)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o2057, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o2058, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitte, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};
