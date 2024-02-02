#include "arn_03.h"

EvtScript N(EVS_ExitWalk_arn_07_1) = EVT_EXIT_WALK(60, arn_03_ENTRY_0, "arn_07", arn_07_ENTRY_1);
EvtScript N(EVS_ExitWalk_arn_05_0) = EVT_EXIT_WALK(60, arn_03_ENTRY_1, "arn_05", arn_05_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_arn_07_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_arn_05_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    Return
    End
};

EvtScript N(EVS_EnterMap) = {
    Call(GetLoadType, LVar1)
    IfEq(LVar1, LOAD_FROM_FILE_SELECT)
        Exec(EnterSavePoint)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    IfLt(GB_StoryProgress, STORY_CH3_ARRIVED_AT_GHOST_TOWN)
        Call(SetPlayerPos, -175, 165, 160)
        Call(InterpPlayerYaw, 90, 0)
        Call(SetNpcPos, NPC_PARTNER, -175, 165, 160)
        Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
#if VERSION_PAL
        Call(SetPlayerSpeed, Float(4 / DT))
#else
        Call(SetPlayerSpeed, 4)
#endif
        Call(PlayerMoveTo, -55, 160, 0)
        Exec(N(EVS_BindExitTriggers))
        Return
    EndIf
    Set(LVar0, Ref(N(EVS_BindExitTriggers)))
    Exec(EnterWalk)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_GUSTY_GULCH)
    Call(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_DEFAULT()
    Set(AF_ARN_03, FALSE)
    Set(AF_ARN_04, FALSE)
    Set(AF_ARN_05, FALSE)
    IfLt(GB_StoryProgress, STORY_CH3_DEFEATED_TUBBA_BLUBBA)
        Call(MakeNpcs, FALSE, Ref(N(BeforeNPCs)))
    Else
        Call(MakeNpcs, FALSE, Ref(N(AfterNPCs)))
    EndIf
    IfEq(GF_ARN03_WaitingForPackage, TRUE)
        Set(MV_Unk_00, 450)
        Set(MV_Unk_01, 450)
    EndIf
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_EnterMap))
    Wait(1)
    Return
    End
};
