#include "mac_03.h"

#include "world/common/entity/Pipe.inc.c"

EvtScript N(EVS_ExitWalk_mac_02_3) = EVT_EXIT_WALK(60, mac_03_ENTRY_0, "mac_02", mac_02_ENTRY_3);

EvtScript N(EVS_GotoMap_mgm_00_0) = {
    Call(GotoMap, Ref("mgm_00"), mgm_00_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitPipe_mgm_00_0) = EVT_EXIT_PIPE_VERTICAL(mac_02_ENTRY_2, COLLIDER_deilim, N(EVS_GotoMap_mgm_00_0));

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_mac_02_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    BindTrigger(Ref(N(EVS_ExitPipe_mgm_00_0)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilim, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(mac_03_ENTRY_0)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
        CaseEq(mac_03_ENTRY_1)
            Exec(N(EVS_ArriveFromMtRugged))
            Exec(N(EVS_BindExitTriggers))
        CaseEq(mac_03_ENTRY_2)
            EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
        CaseEq(mac_03_ENTRY_3)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_HidePlayroomPipe) = {
    IfEq(GF_MAC03_UnlockedPlayroom, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_dokan, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilim, COLLIDER_FLAGS_UPPER_MASK)
        Call(EnableModel, MODEL_o241, FALSE)
    EndIf
    Return
    End
};

API_CALLABLE(N(GetClockHandAngles)) {
    if (script->varTable[15] > 720) {
        script->varTable[15] = 0;
    }
    script->varTable[0] = script->varTable[15] * 6;
    script->varTable[1] = script->varTable[15] / 2;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
#if VERSION_PAL
    Call(GetLanguage, LVar0)
    Call(SetModelTexVariant, MODEL_o110, LVar0)
#endif
    Set(AF_MAC_20, FALSE)
    Set(AF_MAC_21, FALSE)
    Set(AF_MAC_22, FALSE)
    Set(AF_MAC_23, FALSE)
    Set(AF_MAC_24, FALSE)
    Set(AF_MAC_25, FALSE)
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    Exec(N(EVS_MakeEntities))
    Exec(N(EVS_SetupFoliage))
    Call(GetDemoState, LVar0)
    IfEq(LVar0, DEMO_STATE_NONE)
        Exec(N(EVS_InitializeLilOinks))
    EndIf
    ExecWait(N(EVS_InitializeTrainScene))
    Thread
        Set(LVarF, 0)
        Label(10)
            Add(LVarF, 1)
            Call(N(GetClockHandAngles))
            Call(RotateModel, MODEL_o148, LVar0, 0, 0, -1)
            Call(RotateModel, MODEL_o147, LVar1, 0, 0, -1)
            Wait(10)
            Goto(10)
    EndThread
    Call(GetDemoState, LVar0)
    IfNe(LVar0, DEMO_STATE_NONE)
        ExecWait(N(EVS_PlayDemoScene))
        Return
    EndIf
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_HidePlayroomPipe))
    Exec(N(EVS_EnterMap))
    Set(GF_MAC01_RowfBadgesChosen, FALSE)
    Wait(1)
    Return
    End
};
