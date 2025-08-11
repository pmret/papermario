#include "isk_11.h"

#include "world/common/todo/RemovePadlock.inc.c"

s32 N(ItemList_RuinsKey)[] = {
    ITEM_RUINS_KEY,
    ITEM_NONE
};

EvtScript N(EVS_UnlockPrompt_RuinsKey) = {
    Call(ShowKeyChoicePopup)
    IfEq(LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        Call(CloseChoicePopup)
        Return
    EndIf
    IfEq(LVar0, -1)
        Call(CloseChoicePopup)
        Return
    EndIf
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, 355, -460, 430)
    Call(RemoveKeyItemAt, LVar1)
    Set(GF_ISK11_UnlockedDoor, true)
    Set(LVar0, MV_LockEntityID)
    Call(N(RemovePadlock))
    Set(LVar1, 0)
    Wait(5)
    Call(PlaySoundAtCollider, COLLIDER_deilittne, SOUND_ISK_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 65, 65, EASING_LINEAR)
    Label(10)
    Call(UpdateLerp)
    Call(TranslateGroup, MODEL_g374, 0, LVar0, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(10)
    EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    Call(CloseChoicePopup)
    Unbind
    Return
    End
};

EvtScript N(EVS_SetupLock) = {
    IfEq(GF_ISK11_UnlockedDoor, false)
        Call(MakeTransformGroup, MODEL_g374)
        BindPadlock(Ref(N(EVS_UnlockPrompt_RuinsKey)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), Ref(N(ItemList_RuinsKey)), 0, 1)
    Else
        Call(EnableGroup, MODEL_g374, false)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_SURFACE_TYPE_MASK | COLLIDER_FLAG_SAFE_FLOOR | COLLIDER_FLAG_IGNORE_SHELL | COLLIDER_FLAG_IGNORE_PLAYER | COLLIDER_FLAG_DOCK_WALL | 0x7FF47E00)
    EndIf
    Return
    End
};
