#include "kmr_20.h"

#include "world/common/entity/Pipe.inc.c"

API_CALLABLE(N(func_80240310_8EC130)){
    set_map_transition_effect(TRANSITION_BEGIN_OR_END_GAME);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_GotoMap_mac_00_4) = {
    Exec(N(EVS_FadeOutAmbientSounds))
    Call(GotoMap, Ref("mac_00"), mac_00_ENTRY_4)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_ExitPipe_mac_00_4) = {
    SetGroup(EVT_GROUP_1B)
    Set(LVarA, kmr_20_ENTRY_4)
    Set(LVarB, COLLIDER_o244)
    Set(LVarC, Ref(N(EVS_GotoMap_mac_00_4)))
    ExecWait(N(EVS_Pipe_ExitVertical))
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitPipe_mac_00_4)), TRIGGER_FLOOR_TOUCH, COLLIDER_o244, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_MARIOS_HOUSE)
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kmr_20_ENTRY_2)
        Set(GB_StoryProgress, STORY_EPILOGUE)
    EndIf
    Call(GetEntryID, LVar0)
    IfEq(LVar0, kmr_20_ENTRY_4)
        Set(MF_LuigiWaiting, FALSE)
        IfEq(GF_KMR20_ReunitedWithLuigi, FALSE)
            Set(GF_KMR20_ReunitedWithLuigi, TRUE)
            IfLt(GB_StoryProgress, STORY_CH3_INVITED_TO_BOOS_MANSION)
                Set(MF_LuigiWaiting, TRUE)
            EndIf
        EndIf
    EndIf
    Set(MF_Unk_0C, FALSE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_NO_LEAD()
    Exec(N(EVS_SetupMusic))
    Call(GetEntryID, LVar0)
    IfLt(LVar0, kmr_20_ENTRY_4)
        Call(MakeNpcs, FALSE, Ref(N(SceneNPCs)))
    Else
        Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    EndIf
    ExecWait(N(EVS_MakeEntities))
    Call(EnableGroup, MODEL_g100, FALSE)
    Exec(N(EVS_SetupTrees))
    Exec(N(EVS_SetupBushes))
    Exec(N(EVS_SetupRooms))
    Exec(N(EVS_Setup_Interactables))
    IfLt(GB_StoryProgress, STORY_EPILOGUE)
        Exec(N(EVS_SetupBed))
    EndIf
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(kmr_20_ENTRY_0)
            Call(N(func_80240310_8EC130))
            Exec(N(EVS_Scene_BeginGame))
            Wait(5)
        CaseEq(kmr_20_ENTRY_1)
            Exec(N(EVS_Scene_SettingOff))
        CaseEq(kmr_20_ENTRY_2)
            Wait(60)
            Exec(N(EVS_Scene_BeginEpilogue))
        CaseEq(kmr_20_ENTRY_3)
            Exec(N(EVS_BindExitTriggers))
            Exec(N(EVS_Scene_EpilogueGetLetter))
        CaseEq(kmr_20_ENTRY_4)
            Set(GF_MAP_MariosHouse, TRUE)
            IfEq(MF_LuigiWaiting, TRUE)
                Exec(N(EVS_Scene_LuigiWaitingAround))
                Thread
                    Call(DisablePlayerPhysics, TRUE)
                    Call(SetPlayerPos, NPC_DISPOSE_LOCATION)
                    Label(0)
                        IfEq(MF_ReadyForPlayerEntry, FALSE)
                            Wait(1)
                            Goto(0)
                        EndIf
                    Set(LVarA, Ref(N(EVS_BindExitTriggers)))
                    Exec(N(EVS_Pipe_EnterVertical))
                EndThread
            Else
                Set(LVarA, Ref(N(EVS_BindExitTriggers)))
                Exec(N(EVS_Pipe_EnterVertical))
            EndIf
    EndSwitch
    Return
    End
};
