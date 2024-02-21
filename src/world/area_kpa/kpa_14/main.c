#include "kpa_14.h"
#include "effects.h"
#include "sprite/player.h"

#include "world/common/atomic/TexturePan.inc.c"

API_CALLABLE(N(GetActingPartner)) {
    if (gPartnerStatus.partnerActionState != 0) {
        script->varTable[9] = gPartnerStatus.actingPartner;
    } else {
        script->varTable[9] = -1;
    }
    return ApiStatus_DONE2;
}

EvtScript N(EVS_ExitWalk_kpa_13_1) = EVT_EXIT_WALK(60, kpa_14_ENTRY_0, "kpa_13", kpa_13_ENTRY_1);

EvtScript N(EVS_ExitDoor_kpa_01_0) = {
    SetGroup(EVT_GROUP_1B)
    Call(DisablePlayerInput, TRUE)
    Set(LVar0, kpa_14_ENTRY_1)
    Set(LVar1, COLLIDER_deilitte)
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Set(LVar2, MODEL_o1035)
    Else
        Set(LVar2, MODEL_o1036)
    EndIf
    Set(LVar3, DOOR_SWING_OUT)
    Exec(ExitSingleDoor)
    Wait(17)
    Call(GotoMap, Ref("kpa_01"), kpa_01_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitWalk_kpa_16_0) = EVT_EXIT_WALK(60, kpa_14_ENTRY_2, "kpa_16", kpa_16_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_13_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kpa_16_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kpa_14_ENTRY_0)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
        CaseEq(kpa_14_ENTRY_1)
            Set(LVar0, kpa_14_ENTRY_1)
            Set(LVar1, COLLIDER_deilitte)
            Set(LVar2, MODEL_o1035)
            Set(LVar3, DOOR_SWING_OUT)
            Exec(EnterSingleDoor)
            Exec(N(EVS_BindExitTriggers))
        CaseEq(kpa_14_ENTRY_2)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_TexPan_Lava) = {
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_0)
        TEX_PAN_PARAMS_STEP(-1000,    0,-2000,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( -400,    0, -800,    0)
        TEX_PAN_PARAMS_FREQ(    1,    0,    1,    0)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Call(SetTexPanner, MODEL_o631, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o625, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o776, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o777, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o778, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o779, TEX_PANNER_1)
    Return
    End
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o202, .pos = {  110.0,   30.0, -135.0 }},
    { .colliderID = COLLIDER_o201, .pos = {  345.0,   30.0, -135.0 }},
    { .colliderID = COLLIDER_o196, .pos = {  550.0,   30.0, -135.0 }},
    { .colliderID = COLLIDER_o197, .pos = {  800.0,   30.0, -135.0 }},
    { .colliderID = COLLIDER_o195, .pos = { 1045.0,   30.0, -135.0 }},
    { .colliderID = COLLIDER_o198, .pos = { 1400.0,   30.0, -135.0 }},
    { .colliderID = COLLIDER_o200, .pos = { 1590.0,   30.0,  -90.0 }},
    { .colliderID = COLLIDER_o199, .pos = { 1940.0,   30.0, -135.0 }},
    { .colliderID = -1 }
};

EvtScript N(EVS_Touch_LeftOfLavaFall) = {
    Set(MV_LastFloorBeforeLavaFall, COLLIDER_o195)
    Return
    End
};

EvtScript N(EVS_Touch_RightOfLavaFall) = {
    Set(MV_LastFloorBeforeLavaFall, COLLIDER_o198)
    Return
    End
};

EvtScript N(EVS_MakeSmokeEffects) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        PlayEffect(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, 1, 10)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_SetupLavaFall) = {
    SetGroup(EVT_GROUP_0B)
    Loop(0)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o854, COLLIDER_FLAGS_UPPER_MASK)
        Call(N(GetActingPartner))
        Switch(LVar9)
            CaseEq(8)
                Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o854, COLLIDER_FLAGS_UPPER_MASK)
            CaseEq(9)
            CaseDefault
                Call(GetPlayerPos, LVar0, LVar1, LVar2)
                IfLt(LVar1, 120)
                    Switch(LVar0)
                        CaseRange(1200, 1245)
                            Call(DisablePlayerInput, TRUE)
                            Call(DisablePlayerPhysics, TRUE)
                            Set(MV_TakingLavaFallDamage, TRUE)
                            Call(SetPlayerActionState, ACTION_STATE_LAND)
                            ExecGetTID(N(EVS_MakeSmokeEffects), LVar9)
                            IfEq(MV_LastFloorBeforeLavaFall, COLLIDER_o195)
                                Set(LVar5, 1045)
                            Else
                                Set(LVar5, 1400)
                            EndIf
                            Wait(1)
                            Call(InterruptUsePartner)
                            Call(SetPlayerActionState, ACTION_STATE_HIT_LAVA)
                            Wait(10)
                            Call(UseSettingsFrom, CAM_DEFAULT, LVar5, 30, -135)
                            Call(SetPanTarget, CAM_DEFAULT, LVar5, 30, -135)
                            Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
                            Call(PanToTarget, CAM_DEFAULT, 0, 1)
                            Call(MakeLerp, LVar0, LVar5, 30, EASING_LINEAR)
                            Loop(0)
                                Call(UpdateLerp)
                                Call(SetPlayerPos, LVar0, 250, -135)
                                Wait(1)
                                IfEq(LVar1, 0)
                                    BreakLoop
                                EndIf
                            EndLoop
                            Call(MakeLerp, 250, 30, 20, EASING_QUADRATIC_IN)
                            Loop(0)
                                Call(UpdateLerp)
                                Call(SetPlayerPos, LVar5, LVar0, -135)
                                Wait(1)
                                IfEq(LVar1, 0)
                                    BreakLoop
                                EndIf
                            EndLoop
                            Call(SetPlayerAnimation, ANIM_MarioW2_Thrown)
                            Call(MakeLerp, 30, 60, 5, EASING_QUADRATIC_IN)
                            Loop(0)
                                Call(UpdateLerp)
                                Call(SetPlayerPos, LVar5, LVar0, -135)
                                Wait(1)
                                IfEq(LVar1, 0)
                                    BreakLoop
                                EndIf
                            EndLoop
                            KillThread(LVar9)
                            Call(MakeLerp, 60, 30, 5, EASING_QUADRATIC_IN)
                            Loop(0)
                                Call(UpdateLerp)
                                Call(SetPlayerPos, LVar5, LVar0, -135)
                                Wait(1)
                                IfEq(LVar1, 0)
                                    BreakLoop
                                EndIf
                            EndLoop
                            Wait(5)
                            Call(SetPlayerAnimation, ANIM_Mario1_Idle)
                            Call(DisablePlayerPhysics, FALSE)
                            Call(PanToTarget, CAM_DEFAULT, 0, 0)
                            Call(DisablePlayerInput, FALSE)
                            Wait(1)
                            Set(MV_TakingLavaFallDamage, FALSE)
                    EndSwitch
                EndIf
        EndSwitch
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_BOWSERS_CASTLE)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    ExecWait(N(EVS_MakeEntities))
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Call(EnableGroup, MODEL_after, FALSE)
        Exec(N(EVS_TexPan_Lava))
    Else
        Call(EnableGroup, MODEL_before, FALSE)
    EndIf
    Exec(N(EVS_EnterMap))
    Exec(N(EVS_SetupMusic))
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Exec(N(EVS_SetupPlatforms))
    EndIf
    IfEq(GF_KPA16_ShutOffLava, FALSE)
        Thread
            Wait(2)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o625, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o776, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o818, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o819, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o820, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o821, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o822, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o823, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o824, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o825, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o826, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o827, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o828, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o829, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o830, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o857, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o858, SURFACE_TYPE_LAVA)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_deilin, SURFACE_TYPE_LAVA)
            Thread
                Call(ResetFromLava, Ref(N(SafeFloorColliders)))
            EndThread
            BindTrigger(Ref(N(EVS_Touch_LeftOfLavaFall)), TRIGGER_FLOOR_TOUCH, COLLIDER_o195, 1, 0)
            BindTrigger(Ref(N(EVS_Touch_RightOfLavaFall)), TRIGGER_FLOOR_TOUCH, COLLIDER_o198, 1, 0)
            Exec(N(EVS_SetupLavaFall))
        EndThread
    Else
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o854, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Return
    End
};
