#include "isk_02.h"

#include "world/common/todo/RemovePadlock.inc.c"

s32 N(KeyList)[] = {
    ITEM_RUINS_KEY,
    ITEM_NONE,
};

EvtScript N(EVS_UnlockDoor) = {
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
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, 272, 60, 486)
    Call(RemoveKeyItemAt, LVar1)
    Set(GF_ISK02_UnlockedDoor, TRUE)
    Set(LVar0, MV_EntityID_Padlock)
    Call(N(RemovePadlock))
    Set(LVar1, 0)
    Wait(5)
    Call(PlaySoundAtCollider, COLLIDER_deilittne, SOUND_ISK_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 65, 65, EASING_LINEAR)
    Label(10)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g304, 0, LVar0, 0)
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
    IfEq(GF_ISK02_UnlockedDoor, FALSE)
        Call(MakeTransformGroup, MODEL_g304)
        BindPadlock(Ref(N(EVS_UnlockDoor)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), Ref(N(KeyList)), 0, 1)
    Else
        Call(EnableGroup, MODEL_g304, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_SURFACE_TYPE_MASK | COLLIDER_FLAG_SAFE_FLOOR | COLLIDER_FLAG_IGNORE_SHELL | COLLIDER_FLAG_IGNORE_PLAYER | COLLIDER_FLAG_DOCK_WALL | 0x7FF47E00)
    EndIf
    Return
    End
};
