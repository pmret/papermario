#include "flo_00.h"
#include "effects.h"

#include "world/area_flo/common/FlowerSpawnRegion.inc.c"

API_CALLABLE(N(SpawnSunEffect)) {
    fx_sun_undeclared(FX_SUN_FROM_LEFT, 0, 0, 0, 0, 0);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_Wisterwood_Exit) = {
    Call(DisablePlayerInput, true)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittn, COLLIDER_FLAGS_UPPER_MASK)
    Call(PlayerMoveTo, 30, -170, 10)
    Call(InterpPlayerYaw, 0, 0)
    Call(PlaySoundAtCollider, COLLIDER_deilittn, SOUND_WOODEN_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, -100, 20, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_g27, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(func_802D2C14, 1)
    Call(PlayerMoveTo, 0, -310, 30)
    Call(func_802D2C14, 0)
    IfEq(GB_StoryProgress, STORY_CH6_STAR_SPRIT_DEPARTED)
        Set(GB_StoryProgress, STORY_CH6_RETURNED_TO_TOAD_TOWN)
    EndIf
    Call(MakeLerp, -100, 0, 30, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_g27, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_deilittn, SOUND_WOODEN_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Call(GotoMap, Ref("mac_01"), mac_01_ENTRY_5)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_Wisterwood_Enter) = {
    Call(DisablePlayerInput, true)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilittn, COLLIDER_FLAGS_UPPER_MASK)
    Call(InterpPlayerYaw, 180, 0)
    Call(PlaySoundAtCollider, COLLIDER_deilittn, SOUND_WOODEN_DOOR_OPEN, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 0, -100, 30, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_g27, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(func_802D2C14, 1)
    Call(PlayerMoveTo, 0, -135, 30)
    Call(func_802D2C14, 0)
    Call(MakeLerp, -100, 0, 30, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateGroup, MODEL_g27, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_deilittn, SOUND_WOODEN_DOOR_CLOSE, SOUND_SPACE_DEFAULT)
    Call(DisablePlayerInput, false)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_deilittn, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_ExitWalk_flo_14_0) = EVT_EXIT_WALK(60, flo_00_ENTRY_1, "flo_14", flo_14_ENTRY_0);
EvtScript N(EVS_ExitWalk_flo_23_0) = EVT_EXIT_WALK(60, flo_00_ENTRY_2, "flo_23", flo_23_ENTRY_0);
EvtScript N(EVS_ExitWalk_flo_25_0) = EVT_EXIT_WALK(60, flo_00_ENTRY_3, "flo_25", flo_25_ENTRY_0);
EvtScript N(EVS_ExitWalk_flo_16_0) = EVT_EXIT_WALK(60, flo_00_ENTRY_4, "flo_16", flo_16_ENTRY_0);
EvtScript N(EVS_ExitWalk_flo_09_0) = EVT_EXIT_WALK(60, flo_00_ENTRY_5, "flo_09", flo_09_ENTRY_0);
EvtScript N(EVS_ExitWalk_flo_08_0) = EVT_EXIT_WALK(60, flo_00_ENTRY_6, "flo_08", flo_08_ENTRY_0);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_flo_14_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilinw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_flo_23_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_flo_25_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_flo_16_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiline, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_flo_09_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_flo_08_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilise, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
    Else
        Call(GetEntryID, LVar0)
        IfNe(LVar0, flo_00_ENTRY_8)
            Set(AF_FLO_RidingBeanstalk, false)
        EndIf
        Switch(LVar0)
            CaseEq(flo_00_ENTRY_0)
                Thread
                    ExecWait(N(EVS_Wisterwood_Enter))
                    Exec(N(EVS_BindExitTriggers))
                EndThread
            CaseRange(flo_00_ENTRY_1, flo_00_ENTRY_6)
                Set(LVar0, Ref(N(EVS_BindExitTriggers)))
                Exec(EnterWalk)
            CaseEq(flo_00_ENTRY_7)
                Thread
                    ExecWait(N(EVS_Scene_BeanstalkGrewRemark))
                    Exec(N(EVS_BindExitTriggers))
                EndThread
            CaseEq(flo_00_ENTRY_8)
                Thread
                    ExecWait(N(EVS_Enter_Beanstalk))
                    Exec(N(EVS_BindExitTriggers))
                EndThread
            CaseEq(flo_00_ENTRY_9)
                Exec(N(EVS_Scene_SunReturns))
                Set(LVar0, Ref(N(EVS_BindExitTriggers)))
                Exec(EnterWalk)
            CaseEq(flo_00_ENTRY_A)
                Exec(N(EVS_BindExitTriggers))
            CaseEq(flo_00_ENTRY_B)
                Exec(N(EVS_Scene_Epilogue))
        EndSwitch
    EndIf
    BindTrigger(Ref(N(EVS_Interact_Wisterwood)), TRIGGER_WALL_PRESS_A, COLLIDER_deilittn, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_FLOWER_FIELDS)
    Call(SetSpriteShading, SHADING_NONE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, false)
    EVT_SETUP_CAMERA_DEFAULT()
    Set(GF_MAP_FlowerFields, true)
    IfLt(GB_StoryProgress, STORY_CH6_GREW_MAGIC_BEANSTALK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o351, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Set(GF_MAC01_RowfBadgesChosen, false)
    Call(GetEntryID, LVar0)
    IfEq(LVar0, flo_00_ENTRY_B)
        Call(MakeNpcs, false, Ref(N(EpilogueNPCs)))
    Else
        Call(MakeNpcs, false, Ref(N(DefaultNPCs)))
    EndIf
    ExecWait(N(EVS_MakeEntities))
    Call(ParentColliderToModel, COLLIDER_o240, MODEL_o142)
    Exec(N(EVS_SetupBeanstalk))
    Exec(N(EVS_SetupBeanPatch))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o129, SURFACE_TYPE_FLOWERS)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o363, SURFACE_TYPE_FLOWERS)
    EVT_FLOWER_SPAWN_REGION(  150, -270,  410,  170,  0)
    EVT_FLOWER_SPAWN_REGION(  115, -450,  250, -270,  0)
    EVT_FLOWER_SPAWN_REGION( -330,  220,   45,  410,  0)
    EVT_FLOWER_SPAWN_REGION( -420, -260, -140,  160,  0)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitse, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitne, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitsw, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitnw, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(EVS_EnterMap))
    Call(GetLoadType, LVar1)
    IfNe(LVar1, LOAD_FROM_FILE_SELECT)
        Call(GetEntryID, LVar0)
        IfEq(LVar0, flo_00_ENTRY_A)
            Wait(65)
        EndIf
    EndIf
    ExecWait(N(EVS_SetupMusic))
    IfGe(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        Call(N(SpawnSunEffect))
    EndIf
    // thread to manage wisterwood blinking
    Thread
        Call(EnableTexPanning, MODEL_o47, true)
        Set(LVar0, 0)
        Label(0)
            Call(RandInt, 300, LVar1)
            Add(LVar1, 100)
            Call(RandInt, 1, LVar2)
            Add(LVar2, 1)
            Wait(LVar1)
            Loop(LVar2)
                Call(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, -0x8000, 0)
                Wait(2)
                Call(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, -0x10000, 0)
                Wait(2)
                Call(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, -0x18000, 0)
                Call(RandInt, 5, LVar3)
                Add(LVar3, 2)
                Wait(LVar3)
                Call(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, -0x10000, 0)
                Wait(2)
                Call(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, -0x8000, 0)
                Wait(2)
                Call(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, 0, 0)
                Call(RandInt, 5, LVar3)
                Add(LVar3, 2)
                Wait(LVar3)
            EndLoop
            Goto(0)
    EndThread
    Return
    End
};
