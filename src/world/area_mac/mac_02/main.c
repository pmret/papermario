#include "mac_02.h"

#include "world/common/entity/Pipe.inc.c"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_mac_04_0) = EVT_EXIT_WALK(60, mac_02_ENTRY_0, "mac_04", mac_04_ENTRY_0);
EvtScript N(EVS_ExitWalk_mim_10_0) = EVT_EXIT_WALK(60, mac_02_ENTRY_1, "mim_10", mim_10_ENTRY_0);
EvtScript N(EVS_ExitWalk_mac_01_3) = EVT_EXIT_WALK(60, mac_02_ENTRY_2, "mac_01", mac_01_ENTRY_3);
EvtScript N(EVS_ExitWalk_mac_03_0) = EVT_EXIT_WALK(60, mac_02_ENTRY_3, "mac_03", mac_03_ENTRY_0);

EvtScript N(EVS_GotoMap_tik_06_3) = {
    Call(GotoMap, Ref("tik_06"), tik_06_ENTRY_3)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_GotoMap_tik_15_1) = {
    Call(GotoMap, Ref("tik_15"), tik_15_ENTRY_1)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_SetupPipe) = {
    SetGroup(EVT_GROUP_1B)
    Set(LVarA, LVar0)
    Set(LVarB, LVar1)
    Set(LVarC, LVar2)
    ExecWait(N(EVS_Pipe_ExitVertical))
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_mac_04_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_mim_10_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_mac_01_3)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilin, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_mac_03_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilis, 1, 0)
    Set(LVar0, mac_02_ENTRY_4)
    Set(LVar1, COLLIDER_deilip)
    Set(LVar2, Ref(N(EVS_GotoMap_tik_06_3)))
    BindTrigger(Ref(N(EVS_SetupPipe)), TRIGGER_FLOOR_TOUCH, LVar1, 1, 0)
    Set(LVar0, mac_02_ENTRY_5)
    Set(LVar1, COLLIDER_deilid)
    Set(LVar2, Ref(N(EVS_GotoMap_tik_15_1)))
    BindTrigger(Ref(N(EVS_SetupPipe)), TRIGGER_FLOOR_TOUCH, LVar1, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    IfEq(GB_StoryProgress, STORY_CH5_TRADED_VASE_FOR_SEED)
        Set(GB_StoryProgress, STORY_CH5_RETURNED_TO_TOAD_TOWN)
    EndIf
    Set(GB_WorldLocation, LOCATION_TOAD_TOWN)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Set(AF_MAC_16, FALSE)
    Set(AF_MAC_17, FALSE)
    Set(AF_MAC_18, FALSE)
    Set(AF_MAC_19, FALSE)
    Set(AF_MAC_1A, FALSE)
    Set(AF_MAC_1B, FALSE)
    Set(AF_MAC_1C, FALSE)
    Set(AF_MAC_1D, FALSE)
    Set(AF_MAC_1E, FALSE)
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH2_STAR_SPRIT_DEPARTED)
            Call(MakeNpcs, FALSE, Ref(N(NpcGroup4)))
        CaseLt(STORY_CH3_SAW_BOO_ENTER_FOREST)
            Call(MakeNpcs, FALSE, Ref(N(NpcGroup1)))
        CaseLt(STORY_CH3_STAR_SPRIT_DEPARTED)
            Call(MakeNpcs, FALSE, Ref(N(NpcGroup4)))
        CaseLt(STORY_CH4_RETURNED_TOY_TRAIN)
            Call(MakeNpcs, FALSE, Ref(N(NpcGroup3)))
        CaseDefault
            Call(MakeNpcs, FALSE, Ref(N(NpcGroup4)))
    EndSwitch
    ExecWait(N(EVS_MakeEntities))
    Switch(GB_StoryProgress)
        CaseLt(STORY_CH0_TWINK_GAVE_LUCKY_STAR)
            Call(EnableGroup, MODEL_st2, FALSE)
            Call(EnableGroup, MODEL_st3, FALSE)
        CaseLt(STORY_CH1_BEGAN_PEACH_MISSION)
            Call(EnableGroup, MODEL_st1, FALSE)
            Call(EnableGroup, MODEL_st3, FALSE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_st1, COLLIDER_FLAGS_UPPER_MASK)
        CaseDefault
            Call(EnableGroup, MODEL_st1, FALSE)
            Call(EnableGroup, MODEL_st2, FALSE)
            Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_g47, COLLIDER_FLAGS_UPPER_MASK)
    EndSwitch
    Call(EnableTexPanning, MODEL_hori, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP(  100,   40,  200,  -40)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Exec(N(EVS_SetupRooms))
    Exec(N(EVS_SetupFoliage))
    Exec(N(EVS_SetupMusic))
    Call(GetEntryID, LVar0)
    IfLe(LVar0, mac_02_ENTRY_3)
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
    Else
        EVT_ENTER_PIPE_VERTICAL(N(EVS_BindExitTriggers))
    EndIf
    Return
    End
};
