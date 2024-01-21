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
    Call(MakeLerp, -10, 0, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g307, 0, LVar0, 0)
        Call(TranslateGroup, MODEL_g308, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o1342)
        Call(UpdateColliderTransform, COLLIDER_o1344)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_LowerPoundableSwitch) = {
    Call(PlaySoundAtCollider, COLLIDER_o1344, SOUND_FLOOR_SWITCH_ACTIVATE, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, -10, 10, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateGroup, MODEL_g307, 0, LVar0, 0)
        Call(TranslateGroup, MODEL_g308, 0, LVar0, 0)
        Call(UpdateColliderTransform, COLLIDER_o1342)
        Call(UpdateColliderTransform, COLLIDER_o1344)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
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
    Call(N(IsPlayerPounding))
    IfEq(LVar0, FALSE)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    IfEq(GF_PRA02_DoorColorToggle, FALSE)
        Call(MakeLerp, 0, -250, 250 * DT, EASING_LINEAR)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittse, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilittse2, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilittne2, COLLIDER_FLAGS_UPPER_MASK)
        Set(GF_PRA02_DoorColorToggle, TRUE)
        Exec(N(EVS_LowerPoundableSwitch))
    Else
        Call(MakeLerp, -250, 0, 250 * DT, EASING_LINEAR)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittse2, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittne2, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilittse, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilittne, COLLIDER_FLAGS_UPPER_MASK)
        Set(GF_PRA02_DoorColorToggle, FALSE)
        Exec(N(EVS_LowerPoundableSwitch))
    EndIf
    Wait(30)
    Thread
        PlayEffect(EFFECT_DUST, 0, 1000, 250, 60, 50)
        PlayEffect(EFFECT_DUST, 0, 1000, 250, 120, 50)
        PlayEffect(EFFECT_DUST, 0, 1000, 250, 180, 50)
        PlayEffect(EFFECT_DUST, 0, 1000, 250, -60, 50)
        PlayEffect(EFFECT_DUST, 0, 1000, 250, -120, 50)
        PlayEffect(EFFECT_DUST, 0, 1000, 250, -180, 50)
    EndThread
    Thread
        Call(PlaySound, SOUND_PRA_SHIFT_FLOORS_RUMBLE)
        Call(ShakeCam, CAM_DEFAULT, 0, 250 * DT, Float(0.5))
        Call(ShakeCam, CAM_DEFAULT, 0, 10 * DT, Float(1.5))
        Call(PlaySound, SOUND_PRA_SHIFT_FLOORS_THUD) // ??? somehow this terminates the looping SOUND_PRA_SHIFT_FLOORS_RUMBLE
    EndThread
    Label(0)
        Call(UpdateLerp)
        Set(MV_WallPosOffset, LVar0)
        ExecWait(N(EVS_UpdateShiftingWallPos))
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Wait(10 * DT)
    IfEq(GF_PRA02_DoorColorToggle, TRUE)
        Call(SetGroupVisibility, MODEL_g307, MODEL_GROUP_HIDDEN)
        Call(SetGroupVisibility, MODEL_g308, MODEL_GROUP_VISIBLE)
        ExecWait(N(EVS_RaisePoundableSwitch))
    Else
        Call(SetGroupVisibility, MODEL_g307, MODEL_GROUP_VISIBLE)
        Call(SetGroupVisibility, MODEL_g308, MODEL_GROUP_HIDDEN)
        ExecWait(N(EVS_RaisePoundableSwitch))
    EndIf
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

EvtScript N(EVS_DoNothing) = {
    Return
    End
};

EvtScript N(EVS_UsePadlock_Dummy) = {
    BindTrigger(Ref(N(EVS_DoNothing)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    BindTrigger(Ref(N(EVS_DoNothing)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    Return
    End
};

EvtScript N(EVS_UpdatePadlockPositions) = {
    Loop(0)
        Call(N(UpdatePadlockPosition), MV_NearRedPadlock, 987, 8, 84)
        Call(N(UpdatePadlockPosition), MV_FarRedPadlock, 987, 8, -84)
        Call(N(UpdatePadlockPosition), MV_NearBluePadlock, 987, 258, 84)
        Call(N(UpdatePadlockPosition), MV_FarBluePadlock, 987, 258, -84)
        Wait(1)
    EndLoop
    Return
    End
};

#include "world/common/todo/RemovePadlock.inc.c"
#include "world/common/todo/GetEntityPosition.inc.c"

EvtScript N(EVS_ItemPrompt_RedPadlock) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(ShowKeyChoicePopup)
    IfEq(LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        Call(CloseChoicePopup)
        Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        Return
    EndIf
    IfEq(LVar0, -1)
        Call(CloseChoicePopup)
        Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        Return
    EndIf
    Call(FindKeyItem, ITEM_RED_KEY, LVar0)
    Call(RemoveKeyItemAt, LVar0)
    Call(CloseChoicePopup)
    Set(GF_PRA02_UnlockedRedDoor, TRUE)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_16_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_16_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne, 1, 0)
    Call(N(GetEntityPosition), MV_NearRedPadlock, LVar0, LVar1, LVar2)
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Call(N(GetEntityPosition), MV_FarRedPadlock, LVar0, LVar1, LVar2)
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Set(LVar0, MV_NearRedPadlock)
    Set(MV_NearRedPadlock, -1)
    Call(N(RemovePadlock))
    Set(LVar0, MV_FarRedPadlock)
    Set(MV_FarRedPadlock, -1)
    Call(N(RemovePadlock))
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Unbind
    Return
    End
};

EvtScript N(EVS_ItemPrompt_BluePadlock) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTimeFreezeMode, TIME_FREEZE_PARTIAL)
    Call(ShowKeyChoicePopup)
    IfEq(LVar0, 0)
        Call(ShowMessageAtScreenPos, MSG_Menus_00D8, 160, 40)
        Call(CloseChoicePopup)
        Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        Return
    EndIf
    IfEq(LVar0, -1)
        Call(CloseChoicePopup)
        Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
        Return
    EndIf
    Call(FindKeyItem, ITEM_BLUE_KEY, LVar0)
    Call(RemoveKeyItemAt, LVar0)
    Call(CloseChoicePopup)
    Set(GF_PRA02_UnlockedBlueDoor, TRUE)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_13_0)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittse2, 1, 0)
    BindTrigger(Ref(N(EVS_ExitDoors_pra_13_3)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittne2, 1, 0)
    Call(N(GetEntityPosition), MV_NearBluePadlock, LVar0, LVar1, LVar2)
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Call(N(GetEntityPosition), MV_FarBluePadlock, LVar0, LVar1, LVar2)
    Call(PlaySoundAt, SOUND_USE_KEY, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
    Set(LVar0, MV_NearBluePadlock)
    Set(MV_NearBluePadlock, -1)
    Call(N(RemovePadlock))
    Set(LVar0, MV_FarBluePadlock)
    Set(MV_FarBluePadlock, -1)
    Call(N(RemovePadlock))
    Call(SetTimeFreezeMode, TIME_FREEZE_NORMAL)
    Unbind
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    Set(MV_NearRedPadlock, -1)
    Set(MV_FarRedPadlock, -1)
    Set(MV_NearBluePadlock, -1)
    Set(MV_FarBluePadlock, -1)
    Set(LVar2, COLLISION_WITH_ENTITY_BIT)
    IfEq(GF_PRA02_UnlockedRedDoor, FALSE)
        Call(MakeEntity, Ref(Entity_Padlock), 987, 8, 84, -80, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_UsePadlock_Dummy)))
        Set(MV_NearRedPadlock, LVar0)
        BindPadlock(Ref(N(EVS_ItemPrompt_RedPadlock)), TRIGGER_WALL_PRESS_A, LVar2, Ref(N(RedKeyList)), 0, 1)
        Add(LVar2, 1)
        Call(UseDynamicShadow, TRUE)
        Call(MakeEntity, Ref(Entity_Padlock), 987, 8, -84, -80, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_UsePadlock_Dummy)))
        Set(MV_FarRedPadlock, LVar0)
        BindPadlock(Ref(N(EVS_ItemPrompt_RedPadlock)), TRIGGER_WALL_PRESS_A, LVar2, Ref(N(RedKeyList)), 0, 1)
        Add(LVar2, 1)
        Call(UseDynamicShadow, TRUE)
    EndIf
    IfEq(GF_PRA02_UnlockedBlueDoor, FALSE)
        Call(MakeEntity, Ref(Entity_Padlock), 987, 258, 84, -80, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_UsePadlock_Dummy)))
        Set(MV_NearBluePadlock, LVar0)
        BindPadlock(Ref(N(EVS_ItemPrompt_BluePadlock)), TRIGGER_WALL_PRESS_A, LVar2, Ref(N(BlueKeyList)), 0, 1)
        Add(LVar2, 1)
        Call(UseDynamicShadow, TRUE)
        Call(MakeEntity, Ref(Entity_Padlock), 987, 258, -84, -80, MAKE_ENTITY_END)
        Call(AssignScript, Ref(N(EVS_UsePadlock_Dummy)))
        Set(MV_FarBluePadlock, LVar0)
        BindPadlock(Ref(N(EVS_ItemPrompt_BluePadlock)), TRIGGER_WALL_PRESS_A, LVar2, Ref(N(BlueKeyList)), 0, 1)
        Add(LVar2, 1)
        Call(UseDynamicShadow, TRUE)
    EndIf
    Exec(N(EVS_UpdatePadlockPositions))
    Call(ParentColliderToModel, COLLIDER_o1344, MODEL_o1222)
    Call(ParentColliderToModel, COLLIDER_o1342, MODEL_o1228)
    Return
    End
};
