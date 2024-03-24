#include "obk_08.h"
#include "entity.h"

API_CALLABLE(N(ShutterCrashRumble)) {
    Bytecode* args = script->ptrReadPos;

    start_rumble(100, evt_get_variable(script, *args++) & 0xFFFF);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(EnableItemTransparency)) {
    set_item_entity_flags(script->varTable[0], ITEM_ENTITY_FLAG_TRANSPARENT);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_AnimateShutterLeft) = {
    Call(PlaySoundWithVolume, SOUND_SEQ_WINDOW_OPEN, 0)
    Call(PlaySoundAtModel, LVar2, SOUND_SEQ_WINDOW_OPEN, SOUND_SPACE_DEFAULT)
    Call(N(ShutterCrashRumble), 5)
    Set(LVar3, 90)
    Call(MakeLerp, 0, LVar3, 15, EASING_COS_FAST_OVERSHOOT)
    Label(10)
        Call(UpdateLerp)
        Call(RotateModel, LVar2, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Call(N(ShutterCrashRumble), 5)
    Set(LVar4, 0)
    Label(15)
        Call(MakeLerp, LVar3, 20, 20, EASING_COS_FAST_OVERSHOOT)
        Label(20)
            Call(UpdateLerp)
            Call(RotateModel, LVar2, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(20)
            EndIf
        Call(N(ShutterCrashRumble), 5)
        Call(MakeLerp, 20, LVar3, 5, EASING_COS_FAST_OVERSHOOT)
        Label(30)
            Call(UpdateLerp)
            Call(RotateModel, LVar2, LVar0, 0, 1, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(30)
            EndIf
        Call(N(ShutterCrashRumble), 5)
        IfNe(MV_WindowsIdle, 0)
            Goto(35)
        EndIf
        Add(LVar4, 1)
        IfNe(LVar4, 2)
            Goto(15)
        EndIf
    Label(35)
    Call(MakeLerp, LVar3, 0, 15, EASING_QUADRATIC_IN)
    Label(40)
        Call(UpdateLerp)
        Call(RotateModel, LVar2, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(40)
        EndIf
    Call(PlaySoundWithVolume, SOUND_SEQ_WINDOW_CLOSE, 0)
    Call(PlaySoundAtModel, LVar2, SOUND_SEQ_WINDOW_CLOSE, SOUND_SPACE_DEFAULT)
    Return
    End
};

EvtScript N(EVS_AnimateShutterRight) = {
    Call(N(ShutterCrashRumble), 5)
    Set(LVar3, 90)
    Call(MakeLerp, 0, LVar3, 15, EASING_COS_FAST_OVERSHOOT)
    Label(10)
        Call(UpdateLerp)
        Call(RotateModel, LVar2, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(10)
        EndIf
    Call(N(ShutterCrashRumble), 5)
    Set(LVar4, 0)
    Label(15)
        Call(MakeLerp, LVar3, 20, 17, EASING_COS_FAST_OVERSHOOT)
        Label(20)
            Call(UpdateLerp)
            Call(RotateModel, LVar2, LVar0, 0, -1, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(20)
            EndIf
        Call(N(ShutterCrashRumble), 5)
        Call(MakeLerp, 20, LVar3, 8, EASING_COS_FAST_OVERSHOOT)
        Label(30)
            Call(UpdateLerp)
            Call(RotateModel, LVar2, LVar0, 0, -1, 0)
            Wait(1)
            IfEq(LVar1, 1)
                Goto(30)
            EndIf
        Call(N(ShutterCrashRumble), 5)
        IfNe(MV_WindowsIdle, 0)
            Goto(35)
        EndIf
        Add(LVar4, 1)
        IfNe(LVar4, 2)
            Goto(15)
        EndIf
    Label(35)
    Call(MakeLerp, LVar3, 0, 15, EASING_QUADRATIC_IN)
    Label(40)
        Call(UpdateLerp)
        Call(RotateModel, LVar2, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(40)
        EndIf
    Return
    End
};

EvtScript N(EVS_ManageWindows) = {
    Label(10)
        Call(AwaitPlayerApproach, 0, -390, 150)
        Set(MV_WindowsIdle, FALSE)
        Set(LVar5, 0)
        Set(LVar2, MODEL_m21)
        Exec(N(EVS_AnimateShutterLeft))
        Wait(3)
        Set(LVar2, MODEL_m22)
        Exec(N(EVS_AnimateShutterRight))
        Wait(2)
        Set(LVar5, 1)
        Set(LVar2, MODEL_m41)
        Exec(N(EVS_AnimateShutterLeft))
        Wait(3)
        Set(LVar2, MODEL_m42)
        Exec(N(EVS_AnimateShutterRight))
        Wait(2)
        Set(LVar5, 0)
        Set(LVar2, MODEL_m31)
        Exec(N(EVS_AnimateShutterLeft))
        Wait(2)
        Set(LVar2, MODEL_m32)
        Exec(N(EVS_AnimateShutterRight))
        Wait(2)
        Set(LVar5, 1)
        Set(LVar2, MODEL_m11)
        Exec(N(EVS_AnimateShutterLeft))
        Wait(3)
        Set(LVar2, MODEL_m12)
        Exec(N(EVS_AnimateShutterRight))
        Wait(2)
        Call(AwaitPlayerLeave, 0, -390, 170)
        Set(MV_WindowsIdle, TRUE)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_MakeEntities) = {
    IfGe(GB_StoryProgress, STORY_CH3_GOT_RECORD)
        Call(MakeItemEntity, ITEM_BOO_RECORD, 0, 0, -20, ITEM_SPAWN_MODE_FIXED_NEVER_VANISH, GF_OBK08_Item_Record)
    Else
        Call(MakeItemEntity, ITEM_BOO_RECORD, NPC_DISPOSE_LOCATION, ITEM_SPAWN_MODE_DECORATION, 0)
        Call(N(EnableItemTransparency))
        Set(MV_KeepAwayItem, LVar0)
    EndIf
    Call(MakeEntity, Ref(Entity_HiddenPanel), 0, 0, 0, 0, MODEL_yuka_jyu, MAKE_ENTITY_END)
    Call(AssignPanelFlag, GF_OBK08_HiddenPanel)
    Return
    End
};
