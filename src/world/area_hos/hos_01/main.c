#include "hos_01.h"

#include "../common/FallingStars.inc.c"

#include "world/common/todo/GetFloorCollider.inc.c"

//@bug malformed script is missing Return and End, only works because another EvtScript follows
EvtScript N(EVS_GotoMap_kmr_24_0) = {
    Call(FadeOutMusic, 0, 1500)
    Call(GotoMapSpecial, Ref("kmr_24"), kmr_24_ENTRY_0, TRANSITION_AFTER_SAVE_PROMPT)
    Wait(100)
};

EvtScript N(EVS_ExitWalk_hos_00_1) = EVT_EXIT_WALK(60, hos_01_ENTRY_0, "hos_00", hos_00_ENTRY_1);

EvtScript N(EVS_ExitStarBeam) = {
    SetGroup(EVT_GROUP_EXIT_MAP)
    IfLt(GB_StoryProgress, STORY_CH8_OPENED_PATH_TO_STAR_WAY)
        Return
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Call(InterruptUsePartner)
        Wait(20)
        Loop(0)
            Wait(1)
            Call(IsPlayerOnValidFloor, LVar0)
            IfEq(LVar0, TRUE)
                BreakLoop
            EndIf
        EndLoop
    EndIf
    Call(DisablePlayerPhysics, TRUE)
    Call(DisablePartnerAI, 0)
    ExecWait(N(EVS_AscendStarBeam))
    Call(GotoMap, Ref("hos_02"), hos_02_ENTRY_0)
    Wait(100)
    Return
    End
};

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_hos_00_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilisw, 1, 0)
    Call(GetEntryID, LVar0)
    IfNe(LVar0, hos_01_ENTRY_1)
        BindTrigger(Ref(N(EVS_ExitStarBeam)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilin, 1, 0)
    EndIf
    Return
    End
};

EvtScript N(EVS_EnterStarBeam) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(UseSettingsFrom, CAM_DEFAULT, -30, 250, -160)
    Call(SetPanTarget, CAM_DEFAULT, -30, 250, -160)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Set(LVar2, 360)
    Call(MakeLerp, 500, 250, 60, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(SetPlayerPos, -30, LVar0, -160)
        Call(SetNpcPos, NPC_PARTNER, -30, LVar0, -170)
        Add(LVar2, 40)
        Call(InterpPlayerYaw, LVar2, 0)
        Call(SetNpcRotation, NPC_PARTNER, 0, LVar2, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Set(LVar0, LVar2)
    Sub(LVar0, 360)
    Sub(LVar2, LVar0)
    Set(LVar0, 40)
    Label(10)
        IfLt(LVar2, 540)
            Call(InterpPlayerYaw, LVar2, 0)
            Call(SetNpcRotation, NPC_PARTNER, 0, LVar2, 0)
            Add(LVar2, LVar0)
            Wait(1)
            Goto(10)
        EndIf
        Set(LVar2, 180)
        Sub(LVar0, 5)
        IfGt(LVar0, 20)
            Goto(10)
        EndIf
    Call(SetNpcRotation, NPC_PARTNER, 0, 0, 0)
    Call(N(func_80240AAC_A1132C), MV_StarBeamFXPtr)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
    Call(EnablePartnerAI)
    Call(DisablePlayerPhysics, FALSE)
    Call(PanToTarget, CAM_DEFAULT, 0, FALSE)
    Call(SetMusic, 0, SONG_SHOOTING_STAR_SUMMIT, 0, VOL_LEVEL_FULL)
    Call(DisablePlayerInput, FALSE)
    Label(20)
        Call(N(GetFloorCollider), LVar0)
        IfNe(LVar0, COLLIDER_o234)
            Wait(1)
            Goto(20)
        EndIf
    BindTrigger(Ref(N(EVS_ExitStarBeam)), TRIGGER_FLOOR_TOUCH, COLLIDER_deilin, 1, 0)
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_SHOOTING_STAR_SUMMIT)
    Call(SetSpriteShading, SHADING_HOS_01)
    SetUP_CAMERA_NO_LEAD()
    Thread
        Label(1)
        IfNe(GB_StoryProgress, STORY_CH0_MET_STAR_SPIRITS)
            Wait(1)
            Goto(1)
        EndIf
        Call(DisablePlayerInput, TRUE)
        ExecWait(N(EVS_GotoMap_kmr_24_0))
    EndThread
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(EVS_SetupModelFX))
    Exec(N(EVS_Starfall_Random))
    Exec(N(EVS_SetupMusic))
    Call(GetEntryID, LVar0)
    Switch(LVar0)
        CaseEq(hos_01_ENTRY_0)
            Set(LVar0, Ref(N(EVS_BindExitTriggers)))
            Exec(EnterWalk)
            Wait(1)
        CaseEq(hos_01_ENTRY_1)
            Thread
                ExecWait(N(EVS_EnterStarBeam))
                Exec(N(EVS_BindExitTriggers))
            EndThread
    EndSwitch
    IfEq(GB_StoryProgress, STORY_CH7_STAR_SPRIT_DEPARTED)
        Exec(N(EVS_Scene_StarWayOpened))
    EndIf
    Return
    End
};
