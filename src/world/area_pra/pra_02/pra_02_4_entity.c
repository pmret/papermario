#include "pra_02.h"
#include "entity.h"
#include "effects.h"

#define NAME_SUFFIX _Unused
#include "world/common/todo/SetEntityPositionF.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"
#define NAME_SUFFIX

s32 N(RedKeyList)[] = {
    ITEM_RED_KEY,
    ITEM_NONE
};

s32 N(BlueKeyList)[] = {
    ITEM_BLUE_KEY,
    ITEM_NONE
};

EvtScript N(EVS_RaisePoundableSwitch) = {
    EVT_CALL(MakeLerp, -10, 0, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_g307, 0, LVar0, 0)
        EVT_CALL(TranslateGroup, MODEL_g308, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o1342)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o1344)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LowerPoundableSwitch) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o1344, SOUND_208B, SOUND_SPACE_MODE_0)
    EVT_CALL(MakeLerp, 0, -10, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_g307, 0, LVar0, 0)
        EVT_CALL(TranslateGroup, MODEL_g308, 0, LVar0, 0)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o1342)
        EVT_CALL(UpdateColliderTransform, COLLIDER_o1344)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/IsPlayerPounding.inc.c"

API_CALLABLE(N(UpdatePadlockPosition)) {
    Bytecode* args = script->ptrReadPos;
    s32 entityIdx = evt_get_variable(script, *args++);
    f32 x = evt_get_float_variable(script, *args++);
    f32 y = evt_get_float_variable(script, *args++);
    f32 z = evt_get_float_variable(script, *args++);
    f32 offset = evt_get_float_variable(script, MV_WallPosOffset);
    Entity* entity;

    if (entityIdx == -1) {
        return ApiStatus_DONE2;
    }

    entity = get_entity_by_index(entityIdx);
    entity->pos.x = x;
    entity->pos.y = y + offset;
    entity->pos.z = z;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ManagePoundableSwitch) = {
    EVT_CALL(N(IsPlayerPounding))
    EVT_IF_EQ(LVar0, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(GF_PRA02_DoorColorToggle, FALSE)
        EVT_CALL(MakeLerp, 0, -250, 250 * DT, EASING_LINEAR)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittse, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilittse2, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilittne2, COLLIDER_FLAGS_UPPER_MASK)
        EVT_SET(GF_PRA02_DoorColorToggle, TRUE)
        EVT_EXEC(N(EVS_LowerPoundableSwitch))
    EVT_ELSE
        EVT_CALL(MakeLerp, -250, 0, 250 * DT, EASING_LINEAR)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittse2, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne2, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilittse, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
        EVT_SET(GF_PRA02_DoorColorToggle, FALSE)
        EVT_EXEC(N(EVS_LowerPoundableSwitch))
    EVT_END_IF
    EVT_WAIT(30)
    EVT_THREAD
        EVT_PLAY_EFFECT(EFFECT_DUST, 0, 1000, 250, 60, 50)
        EVT_PLAY_EFFECT(EFFECT_DUST, 0, 1000, 250, 120, 50)
        EVT_PLAY_EFFECT(EFFECT_DUST, 0, 1000, 250, 180, 50)
        EVT_PLAY_EFFECT(EFFECT_DUST, 0, 1000, 250, -60, 50)
        EVT_PLAY_EFFECT(EFFECT_DUST, 0, 1000, 250, -120, 50)
        EVT_PLAY_EFFECT(EFFECT_DUST, 0, 1000, 250, -180, 50)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(PlaySound, SOUND_3F)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 250 * DT, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10 * DT, EVT_FLOAT(1.5))
        EVT_CALL(PlaySound, SOUND_40)
    EVT_END_THREAD
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_SET(MV_WallPosOffset, LVar0)
        EVT_EXEC_WAIT(N(EVS_UpdateShiftingWallPos))
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_WAIT(10 * DT)
    EVT_IF_EQ(GF_PRA02_DoorColorToggle, TRUE)
        EVT_CALL(SetGroupVisibility, MODEL_g307, MODEL_GROUP_HIDDEN)
        EVT_CALL(SetGroupVisibility, MODEL_g308, MODEL_GROUP_VISIBLE)
        EVT_EXEC_WAIT(N(EVS_RaisePoundableSwitch))
    EVT_ELSE
        EVT_CALL(SetGroupVisibility, MODEL_g307, MODEL_GROUP_VISIBLE)
        EVT_CALL(SetGroupVisibility, MODEL_g308, MODEL_GROUP_HIDDEN)
        EVT_EXEC_WAIT(N(EVS_RaisePoundableSwitch))
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DoNothing) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UsePadlock_Dummy) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_DoNothing)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_DoNothing)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UpdatePadlockPositions) = {
    EVT_LOOP(0)
        EVT_CALL(N(UpdatePadlockPosition), MV_NearRedPadlock, 987, 8, 84)
        EVT_CALL(N(UpdatePadlockPosition), MV_FarRedPadlock, 987, 8, -84)
        EVT_CALL(N(UpdatePadlockPosition), MV_NearBluePadlock, 987, 258, 84)
        EVT_CALL(N(UpdatePadlockPosition), MV_FarBluePadlock, 987, 258, -84)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

EvtScript N(EVS_ItemPrompt_RedPadlock) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        EVT_CALL(CloseChoicePopup)
        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(CloseChoicePopup)
        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_RED_KEY, LVar0)
    EVT_CALL(RemoveKeyItemAt, LVar0)
    EVT_CALL(CloseChoicePopup)
    EVT_SET(GF_PRA02_UnlockedRedDoor, TRUE)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_16_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_16_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    EVT_CALL(N(GetEntityPosition), MV_NearRedPadlock, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_269, SOUND_SPACE_MODE_0, LVar0, LVar1, LVar2)
    EVT_CALL(N(GetEntityPosition), MV_FarRedPadlock, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_269, SOUND_SPACE_MODE_0, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, MV_NearRedPadlock)
    EVT_SET(MV_NearRedPadlock, -1)
    EVT_CALL(N(RemovePadlock))
    EVT_SET(LVar0, MV_FarRedPadlock)
    EVT_SET(MV_FarRedPadlock, -1)
    EVT_CALL(N(RemovePadlock))
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ItemPrompt_BluePadlock) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        EVT_CALL(CloseChoicePopup)
        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(LVar0, -1)
        EVT_CALL(CloseChoicePopup)
        EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(FindKeyItem, ITEM_BLUE_KEY, LVar0)
    EVT_CALL(RemoveKeyItemAt, LVar0)
    EVT_CALL(CloseChoicePopup)
    EVT_SET(GF_PRA02_UnlockedBlueDoor, TRUE)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_13_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse2, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_pra_13_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne2, 1, 0)
    EVT_CALL(N(GetEntityPosition), MV_NearBluePadlock, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_269, SOUND_SPACE_MODE_0, LVar0, LVar1, LVar2)
    EVT_CALL(N(GetEntityPosition), MV_FarBluePadlock, LVar0, LVar1, LVar2)
    EVT_CALL(PlaySoundAt, SOUND_269, SOUND_SPACE_MODE_0, LVar0, LVar1, LVar2)
    EVT_SET(LVar0, MV_NearBluePadlock)
    EVT_SET(MV_NearBluePadlock, -1)
    EVT_CALL(N(RemovePadlock))
    EVT_SET(LVar0, MV_FarBluePadlock)
    EVT_SET(MV_FarBluePadlock, -1)
    EVT_CALL(N(RemovePadlock))
    EVT_CALL(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MakeEntities) = {
    EVT_SET(MV_NearRedPadlock, -1)
    EVT_SET(MV_FarRedPadlock, -1)
    EVT_SET(MV_NearBluePadlock, -1)
    EVT_SET(MV_FarBluePadlock, -1)
    EVT_SET(LVar2, COLLISION_WITH_ENTITY_BIT)
    EVT_IF_EQ(GF_PRA02_UnlockedRedDoor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 987, 8, 84, -80, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_UsePadlock_Dummy)))
        EVT_SET(MV_NearRedPadlock, LVar0)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ItemPrompt_RedPadlock)), TRIGGER_WALL_PRESS_A, LVar2, EVT_PTR(N(RedKeyList)), 0, 1)
        EVT_ADD(LVar2, 1)
        EVT_CALL(UseDynamicShadow, TRUE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 987, 8, -84, -80, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_UsePadlock_Dummy)))
        EVT_SET(MV_FarRedPadlock, LVar0)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ItemPrompt_RedPadlock)), TRIGGER_WALL_PRESS_A, LVar2, EVT_PTR(N(RedKeyList)), 0, 1)
        EVT_ADD(LVar2, 1)
        EVT_CALL(UseDynamicShadow, TRUE)
    EVT_END_IF
    EVT_IF_EQ(GF_PRA02_UnlockedBlueDoor, FALSE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 987, 258, 84, -80, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_UsePadlock_Dummy)))
        EVT_SET(MV_NearBluePadlock, LVar0)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ItemPrompt_BluePadlock)), TRIGGER_WALL_PRESS_A, LVar2, EVT_PTR(N(BlueKeyList)), 0, 1)
        EVT_ADD(LVar2, 1)
        EVT_CALL(UseDynamicShadow, TRUE)
        EVT_CALL(MakeEntity, EVT_PTR(Entity_Padlock), 987, 258, -84, -80, MAKE_ENTITY_END)
        EVT_CALL(AssignScript, EVT_PTR(N(EVS_UsePadlock_Dummy)))
        EVT_SET(MV_FarBluePadlock, LVar0)
        EVT_BIND_PADLOCK(EVT_PTR(N(EVS_ItemPrompt_BluePadlock)), TRIGGER_WALL_PRESS_A, LVar2, EVT_PTR(N(BlueKeyList)), 0, 1)
        EVT_ADD(LVar2, 1)
        EVT_CALL(UseDynamicShadow, TRUE)
    EVT_END_IF
    EVT_EXEC(N(EVS_UpdatePadlockPositions))
    EVT_CALL(ParentColliderToModel, COLLIDER_o1344, MODEL_o1222)
    EVT_CALL(ParentColliderToModel, COLLIDER_o1342, MODEL_o1228)
    EVT_RETURN
    EVT_END
};
