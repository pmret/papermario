#include "isk_04.h"
#include "effects.h"

#include "world/common/todo/RemovePadlock.inc.c"

s32 N(ItemList_RuinsKey)[] = {
    ITEM_RUINS_KEY,
    ITEM_NONE
};

BombTrigger N(BombPos_Wall) = {
    .pos = { 510.0f, 25.0f, -184.0f },
    .diameter = 0.0f
};

EvtScript N(EVS_OnBlast_Wall) = {
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 63, 22, 1, 10, 30)
    Loop(10)
        Call(EnableModel, MODEL_g262, TRUE)
        Wait(1)
        Call(EnableModel, MODEL_g262, FALSE)
        Wait(1)
    EndLoop
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    Set(GF_ISK04_BombedWall, TRUE)
    Unbind
    Return
    End
};

EvtScript N(EVS_UnlockDoorPrompt) = {
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
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, 600, -330, 100)
    Call(RemoveKeyItemAt, LVar1)
    Set(GF_ISK04_UnlockedDoor, TRUE)
    Set(LVar0, MV_RuinsLockEntityID)
    Call(N(RemovePadlock))
    Set(LVar1, 0)
    Wait(5)
    Call(PlaySoundAtCollider, COLLIDER_deilittsw, SOUND_ISK_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, 65, 65, EASING_LINEAR)
    Label(10)
    Call(UpdateLerp)
    Call(TranslateGroup, MODEL_g304, 0, LVar0, 0)
    Wait(1)
    IfEq(LVar1, 1)
        Goto(10)
    EndIf
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittsw, COLLIDER_FLAGS_UPPER_MASK)
    Call(CloseChoicePopup)
    Unbind
    Return
    End
};

EvtScript N(EVS_SetupObstructions) = {
    IfEq(GF_ISK04_BombedWall, FALSE)
        BindTrigger(Ref(N(EVS_OnBlast_Wall)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Wall)), 1, 0)
    Else
        Call(EnableModel, MODEL_g262, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    IfEq(GF_ISK04_UnlockedDoor, FALSE)
        Call(MakeTransformGroup, MODEL_g304)
        BindPadlock(Ref(N(EVS_UnlockDoorPrompt)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), Ref(N(ItemList_RuinsKey)), 0, 1)
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittsw, COLLIDER_FLAGS_UPPER_MASK)
        Call(EnableModel, MODEL_g304, FALSE)
    EndIf
    Return
    End
};
