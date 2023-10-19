#include "isk_11.h"

#include "world/common/todo/RemovePadlock.inc.c"

s32 N(ItemList_RuinsKey)[] = {
    ITEM_RUINS_KEY,
    ITEM_NONE
};

EvtScript N(EVS_UnlockPrompt_RuinsKey) = {
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        EVT_CALL(CloseChoicePopup)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(CloseChoicePopup)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, 355, -460, 430)
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_SET(GF_ISK11_UnlockedDoor, TRUE)
    EVT_SET(LVar0, MV_LockEntityID)
    EVT_CALL(N(RemovePadlock))
    EVT_SET(LVar1, 0)
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilittne, SOUND_ISK_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 65, 65, EASING_LINEAR)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateGroup, MODEL_g374, 0, LVar0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupLock) = {
    EVT_IF_EQ(GF_ISK11_UnlockedDoor, FALSE)
        EVT_CALL(MakeTransformGroup, MODEL_g374)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_UnlockPrompt_RuinsKey)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(ItemList_RuinsKey)), 0, 1)
    EVT_ELSE
        EVT_CALL(EnableGroup, MODEL_g374, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_SURFACE_TYPE_MASK | COLLIDER_FLAG_SAFE_FLOOR | COLLIDER_FLAG_IGNORE_SHELL | COLLIDER_FLAG_IGNORE_PLAYER | COLLIDER_FLAG_DOCK_WALL | 0x7FF47E00)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
