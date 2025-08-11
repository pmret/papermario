#include "hos_05.h"
#include "effects.h"
#include "model.h"

API_CALLABLE(N(SwingCameraPitchUpward)) {
    Camera* camera = &gCameras[CAM_DEFAULT];

    if (isInitialCall) {
        script->functionTemp[0] = 40;
    }
    script->functionTemp[0]--;
    if (camera->curSettings != nullptr) {
        camera->curSettings->viewPitch -= 1.0 - ((f32) (40 - script->functionTemp[0]) * 0.01);
    } else if (camera->prevSettings != nullptr) {
        camera->prevSettings->viewPitch -= 1.0 - ((f32) (40 - script->functionTemp[0]) * 0.01);
    }

    if (script->functionTemp[0] == 0) {
        return ApiStatus_DONE2;
    } else {
        return ApiStatus_BLOCK;
    }
}

EvtScript N(EVS_UpdatePassengers) = {
    Label(0)
        Call(GetModelCenter, MODEL_o637)
        Add(LVar0, -5)
        IfEq(MV_PlayerOnBoard, true)
            Call(SetPlayerPos, LVar0, LVar1, LVar2)
        EndIf
        Add(LVar0, 10)
        IfEq(MV_PartnerOnBoard, true)
            Call(SetNpcPos, NPC_PARTNER, LVar0, LVar1, LVar2)
        EndIf
        Wait(1)
        Goto(0)
    Return
    End
};

EvtScript N(EVS_Starship_Depart) = {
    Call(GetPartnerInUse, LVar9)
    IfNe(LVar9, PARTNER_NONE)
        Return
    EndIf
    Call(DisablePlayerInput, true)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, false)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, true)
    ExecGetTID(N(EVS_UpdatePassengers), LVar9)
    Call(HidePlayerShadow, true)
    Call(GetModelCenter, MODEL_o637)
    Add(LVar0, -5)
    Call(SetPlayerJumpscale, 0)
    Call(PlayerJump2, LVar0, LVar1, LVar2, 2)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Set(MV_PlayerOnBoard, true)
    Call(InterpPlayerYaw, 0, 0)
    Call(DisablePlayerPhysics, true)
    Call(DisablePartnerAI, 0)
    Add(LVar0, 10)
    Call(SetNpcJumpscale, NPC_PARTNER, Float(1.5))
    Call(NpcJump0, NPC_PARTNER, LVar0, LVar1, LVar2, 12)
    Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
    Set(MV_PartnerOnBoard, true)
    Call(EnableNpcShadow, NPC_PARTNER, false)
    Wait(10)
    Call(ShowMessageAtScreenPos, MSG_Menus_0188, 160, 40)
    Call(ShowChoice, MSG_Choice_000C)
    Call(CloseMessage)
    IfEq(LVar0, 1)
        // player chose "not ready to take off"
        KillThread(LVar9)
        Call(DisablePlayerPhysics, false)
        Set(MV_PlayerOnBoard, false)
        Thread
            Set(MV_PartnerOnBoard, false)
            Call(PartnerIsFlying, LVar0)
            IfEq(LVar0, true)
                Wait(10)
                Call(SetNpcJumpscale, NPC_PARTNER, 1)
                Call(NpcJump0, NPC_PARTNER, 45, 162, 25, 10)
            EndIf
            Call(EnableNpcShadow, NPC_PARTNER, true)
            Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, false)
            Call(EnablePartnerAI)
        EndThread
        Call(SetPlayerJumpscale, 1)
        Call(PlayerJump, 25, 162, 45, 10)
        Call(SetPlayerActionState, ACTION_STATE_LAND)
        Call(HidePlayerShadow, false)
        Wait(10)
        Call(DisablePlayerInput, false)
        Return
    EndIf
    Wait(20)
    IfLt(GB_StoryProgress, STORY_UNUSED_0000005D)
        Call(SetMusic, 0, SONG_STARSHIP_THEME, 0, VOL_LEVEL_FULL)
    Else
        Call(SetMusic, 0, SONG_STARSHIP_THEME, BGM_VARIATION_1, VOL_LEVEL_FULL)
    EndIf
    Thread
        Wait(25)
        Call(N(SwingCameraPitchUpward))
    EndThread
    Call(PlaySoundAtPlayer, SOUND_STARSHIP_TAKEOFF_LONG, SOUND_SPACE_DEFAULT)
    Set(LVar2, MV_Starship_PosY)
    Call(MakeLerp, 0, 1000, 100, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Add(LVar0, LVar2)
        Set(MV_Starship_PosY, LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    IfLt(GB_StoryProgress, STORY_UNUSED_0000005D)
        Call(GotoMap, Ref("hos_04"), hos_04_ENTRY_2)
    Else
        Call(GotoMap, Ref("hos_20"), hos_20_ENTRY_0)
    EndIf
    Wait(100)
    Return
    End
};

EvtScript N(EVS_EnterStarship) = {
    Call(DisablePlayerInput, true)
    Call(DisablePlayerPhysics, true)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, false)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, true)
    Call(HidePlayerShadow, true)
    Call(EnableNpcShadow, NPC_PARTNER, false)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 180, -5)
    Call(SetPanTarget, CAM_DEFAULT, 0, 180, -5)
    Call(SetCamDistance, CAM_DEFAULT, Float(550.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-35.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, true)
    Set(MV_PlayerOnBoard, true)
    Set(MV_PartnerOnBoard, true)
    ExecGetTID(N(EVS_UpdatePassengers), LVar9)
    Thread
        Wait(25)
        Call(MakeLerp, -350, -70, 60, EASING_QUADRATIC_OUT)
        Loop(0)
            Call(UpdateLerp)
            SetF(LVar2, LVar0)
            DivF(LVar2, 10)
            Call(SetCamPitch, CAM_DEFAULT, Float(17.0), LVar2)
            Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
            Call(PanToTarget, CAM_DEFAULT, 0, true)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndThread
    Call(PlaySoundAtPlayer, SOUND_STARSHIP_ARRIVE, SOUND_SPACE_DEFAULT)
    Call(MakeLerp, 750, -85, 90, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Set(MV_Starship_PosY, LVar0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    KillThread(LVar9)
    Set(MV_PlayerOnBoard, false)
    Call(SetPlayerJumpscale, 1)
    Call(PlayerJump, 25, 162, 45, 10)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(HidePlayerShadow, false)
    Thread
        Set(MV_PartnerOnBoard, false)
        Call(GetCurrentPartnerID, LVar0)
        Switch(LVar0)
            CaseEq(PARTNER_PARAKARRY)
            CaseEq(PARTNER_BOW)
            CaseEq(PARTNER_WATT)
            CaseEq(PARTNER_LAKILESTER)
            CaseDefault
                Wait(10)
                Call(SetNpcJumpscale, NPC_PARTNER, 1)
                Call(NpcJump0, NPC_PARTNER, 45, 162, 25, 10)
        EndSwitch
        Call(EnableNpcShadow, NPC_PARTNER, true)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, false)
        Call(EnablePartnerAI)
    EndThread
    Call(DisablePlayerPhysics, false)
    Call(SetMusic, 0, SONG_STAR_SANCTUARY, 0, VOL_LEVEL_FULL)
    Call(ResetCam, CAM_DEFAULT, Float(1.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.5))
    Call(DisablePlayerInput, false)
    Return
    End
};
