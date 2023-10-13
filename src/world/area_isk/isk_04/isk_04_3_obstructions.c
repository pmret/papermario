#include "isk_04.h"
#include "effects.h"

#include "world/common/todo/RemovePadlock.inc.c"

s32 N(ItemList_RuinsKey)[] = {
    ITEM_RUINS_KEY,
    ITEM_NONE
};

BombTrigger N(BombPos_Wall) = {
    .pos = { 510.0f, 25.0f, -184.0f },
    .radius = 0.0f
};

EvtScript N(EVS_OnBlast_Wall) = {
    EVT_PLAY_EFFECT(EFFECT_BOMBETTE_BREAKING, 0, 63, 22, 1, 10, 30)
    EVT_LOOP(10)
        EVT_CALL(EnableModel, MODEL_g262, TRUE)
        EVT_WAIT(1)
        EVT_CALL(EnableModel, MODEL_g262, FALSE)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SET(GF_ISK04_BombedWall, TRUE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UnlockDoorPrompt) = {
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
    EVT_CALL(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, 600, -330, 100)
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_SET(GF_ISK04_UnlockedDoor, TRUE)
    EVT_SET(LVar0, MV_RuinsLockEntityID)
    EVT_CALL(N(RemovePadlock))
    EVT_SET(LVar1, 0)
    EVT_WAIT(5)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_deilittsw, SOUND_ISK_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 65, 65, EASING_LINEAR)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateGroup, MODEL_g304, 0, LVar0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittsw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(CloseChoicePopup)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupObstructions) = {
    EVT_IF_EQ(GF_ISK04_BombedWall, FALSE)
        EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnBlast_Wall)), TRIGGER_POINT_BOMB, EVT_PTR(N(BombPos_Wall)), 1, 0)
    EVT_ELSE
        EVT_CALL(EnableModel, MODEL_g262, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_IF
    EVT_IF_EQ(GF_ISK04_UnlockedDoor, FALSE)
        EVT_CALL(MakeTransformGroup, MODEL_g304)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_UnlockDoorPrompt)), TRIGGER_WALL_PRESS_A, EVT_ENTITY_INDEX(0), EVT_PTR(N(ItemList_RuinsKey)), 0, 1)
    EVT_ELSE
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittsw, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, MODEL_g304, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};
