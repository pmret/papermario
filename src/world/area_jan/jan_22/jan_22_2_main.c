#include "jan_22.h"

EvtScript N(EVS_ExitWalk_jan_03_2) = EVT_EXIT_WALK(60, jan_22_ENTRY_0, "jan_03", jan_03_ENTRY_2);
EvtScript N(EVS_ExitWalk_jan_16_1) = EVT_EXIT_WALK(60, jan_22_ENTRY_1, "jan_16", jan_16_ENTRY_1);
EvtScript N(EVS_ExitWalk_kzn_01_0) = EVT_EXIT_WALK(60, jan_22_ENTRY_2, "kzn_01", kzn_01_ENTRY_0);

MAP_RODATA_PAD(1, exits);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_jan_03_2)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_jan_16_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_kzn_01_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_TexPan_LavaFalls) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, MODEL_o262, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o269, TEX_PANNER_1)
    Call(SetTexPanner, MODEL_o261, TEX_PANNER_1)
    Set(LVar0, 0)
    Label(10)
        Call(SetTexPanOffset, TEX_PANNER_1, TEX_PANNER_MAIN, 0, LVar0)
        Sub(LVar0, 300)
        Wait(1)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_TexPan_LavaSpread) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, MODEL_o275, TEX_PANNER_2)
    Call(SetTexPanner, MODEL_o274, TEX_PANNER_2)
    Set(LVar0, 0)
    Label(10)
        Call(SetTexPanOffset, TEX_PANNER_2, TEX_PANNER_MAIN, 0, LVar0)
        Sub(LVar0, 300)
        Wait(1)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_TexPan_LavaFlow) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, MODEL_o263, TEX_PANNER_3)
    Call(SetTexPanner, MODEL_o271, TEX_PANNER_3)
    Set(LVar0, 0)
    Label(10)
        Call(SetTexPanOffset, TEX_PANNER_3, TEX_PANNER_MAIN, 0, LVar0)
        Sub(LVar0, 170)
        Wait(1)
        Goto(10)
    Return
    End
};

EvtScript N(EVS_TexPan_LavaGather) = {
    SetGroup(EVT_GROUP_00)
    Call(SetTexPanner, MODEL_o267, TEX_PANNER_4)
    Call(SetTexPanner, MODEL_o272, TEX_PANNER_4)
    Set(LVar0, 0)
    Label(10)
        Call(SetTexPanOffset, TEX_PANNER_4, TEX_PANNER_MAIN, 0, LVar0)
        Add(LVar0, 300)
        Wait(1)
        Goto(10)
    Return
    End
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o170, .pos = {  750.0,    0.0,   50.0 }},
    { .colliderID = COLLIDER_o70,  .pos = {  750.0,    0.0,   50.0 }},
    { .colliderID = COLLIDER_o119, .pos = {  960.0,    0.0,   50.0 }},
    { .colliderID = COLLIDER_o276, .pos = {  960.0,    0.0,   50.0 }},
    { .colliderID = -1 }
};

EvtScript N(D_8024202C_B861AC) = {
    IfLt(GB_StoryProgress, STORY_CH5_ZIP_LINE_READY)
        Call(SetGroupVisibility, MODEL_g39, MODEL_GROUP_HIDDEN)
        Call(SetGroupVisibility, MODEL_g52, MODEL_GROUP_HIDDEN)
        Call(SetGroupVisibility, MODEL_g58, MODEL_GROUP_HIDDEN)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g29, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g39, COLLIDER_FLAGS_UPPER_MASK)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g86, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    IfGe(GB_StoryProgress, STORY_CH5_RAPHAEL_WAITING_FOR_MARIO)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o149, COLLIDER_FLAGS_UPPER_MASK)
        ExecWait(N(EVS_SeparateBushesImmediately))
    EndIf
    Switch(GB_StoryProgress)
        CaseEq(STORY_CH5_RAPHAEL_MOVED_ROOT)
            Thread
                Exec(N(EVS_Scene_RaphaelComingThrough))
                Wait(200)
                Exec(N(EVS_BindExitTriggers))
            EndThread
        CaseEq(STORY_CH5_BEGAN_PEACH_MISSION)
            Exec(N(EVS_BindExitTriggers))
        CaseDefault
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_DEFAULT()
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o304, COLLIDER_FLAGS_UPPER_MASK)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH5_RAPHAEL_MOVED_ROOT)
            Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
        CaseEq(STORY_CH5_BEGAN_PEACH_MISSION)
            Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
        CaseDefault
            Call(MakeNpcs, FALSE, Ref(N(RavenNPCs)))
    EndSwitch
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupZiplines))
    Exec(N(EVS_SetupBasketElevator))
    Exec(N(EVS_SetupTrees))
    Exec(N(EVS_SetupBushes))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_o294, SURFACE_TYPE_LAVA)
    Thread
        Call(ResetFromLava, Ref(N(SafeFloorColliders)))
    EndThread
    Exec(N(EVS_TexPan_LavaFalls))
    Exec(N(EVS_TexPan_LavaSpread))
    Exec(N(EVS_TexPan_LavaFlow))
    Exec(N(EVS_TexPan_LavaGather))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitn, COLLIDER_FLAGS_UPPER_MASK)
    Exec(N(D_8024202C_B861AC))
    IfEq(GB_StoryProgress, STORY_CH5_BEGAN_PEACH_MISSION)
        Wait(65)
    EndIf
    ExecWait(N(EVS_SetupMusic))
    Return
    End
};
