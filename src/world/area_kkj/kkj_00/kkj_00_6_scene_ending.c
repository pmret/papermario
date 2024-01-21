#include "kkj_00.h"
#include "sprite/player.h"

API_CALLABLE(N(FadeScreenToWhite)) {
    if (isInitialCall) {
        script->functionTemp[1] = 0;
    }

    set_screen_overlay_color(SCREEN_LAYER_FRONT, 208, 208, 208);
    set_screen_overlay_params_front(OVERLAY_VIEWPORT_COLOR, script->functionTemp[1]);

    if (script->functionTemp[1] == 255) {
        return ApiStatus_DONE2;
    }

    script->functionTemp[1] += 7;
    if (script->functionTemp[1] > 255) {
        script->functionTemp[1] = 255;
    }

    return ApiStatus_BLOCK;
}

EvtScript N(EVS_OpenAndCloseFrontDoor_Ending) = {
    Call(PlaySoundAtCollider, COLLIDER_tts, SOUND_LARGE_DOOR_OPEN, 0)
    Call(MakeLerp, 0, 80, 14, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_door2, LVar0, 0, -1, 0)
        Call(RotateModel, MODEL_door1, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(30)
    Call(MakeLerp, 80, 0, 8, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_door2, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_door1, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_tts, SOUND_LARGE_DOOR_CLOSE, 0)
    Return
    End
};

EvtScript N(EVS_OpenAndClosePeachDoor) = {
    Call(PlaySoundAtCollider, COLLIDER_ttn, SOUND_LARGE_DOOR_OPEN, 0)
    Call(MakeLerp, 0, 80, 14, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_door3, LVar0, 0, -1, 0)
        Call(RotateModel, MODEL_door4, LVar0, 0, 1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(30)
    Call(MakeLerp, 80, 0, 8, EASING_QUADRATIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        Call(RotateModel, MODEL_door4, LVar0, 0, 1, 0)
        Call(RotateModel, MODEL_door3, LVar0, 0, -1, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(PlaySoundAtCollider, COLLIDER_ttn, SOUND_LARGE_DOOR_CLOSE, 0)
    Return
    End
};

EvtScript N(EVS_Scene_Ending) = {
    Call(DisablePlayerInput, TRUE)
    Call(UseSettingsFrom, CAM_DEFAULT, 50, 0, 250)
    Call(SetPanTarget, CAM_DEFAULT, 50, 0, 250)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(10)
    Exec(N(EVS_OpenAndCloseFrontDoor_Ending))
    Call(func_802D1270, 0, 300, Float(4.0))
    Call(SetNpcAnimation, NPC_Toad_01, ANIM_ToadMinister_Walk)
    Call(NpcMoveTo, NPC_Toad_01, 74, 243, 10)
    Call(SetNpcAnimation, NPC_Toad_01, ANIM_ToadMinister_Idle)
    Call(SpeakToPlayer, NPC_Toad_01, ANIM_ToadMinister_Talk, ANIM_ToadMinister_Idle, 0, MSG_Outro_0064)
    Wait(10)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 100, -290)
    Call(SetPanTarget, CAM_DEFAULT, 0, 100, -290)
    Call(SetCamDistance, CAM_DEFAULT, 400)
    Call(SetCamPitch, CAM_DEFAULT, 10, -7)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(20)
    Call(SpeakToPlayer, NPC_ToadGuard_03, ANIM_ToadGuard_Red_Talk, ANIM_ToadGuard_Red_Idle, 5, MSG_Outro_0065)
    Call(InterpPlayerYaw, 0, 0)
    Wait(10)
    Call(SetMusicTrack, 0, SONG_PEACH_APPEARS, 0, 8)
    Exec(N(EVS_OpenAndClosePeachDoor))
    Thread
        Call(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Walk)
        Call(SetNpcSpeed, NPC_Peach, Float(2.0))
        Call(NpcMoveTo, NPC_Peach, 0, -200, 0)
        Call(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Idle)
    EndThread
    Loop(0)
        Call(GetNpcPos, NPC_Peach, LVar0, LVar1, LVar2)
        IfGt(LVar0, -350)
            BreakLoop
        EndIf
        Wait(1)
    EndLoop
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 100, -200)
    Call(SetPanTarget, CAM_DEFAULT, 0, 100, -200)
    Call(SetCamDistance, CAM_DEFAULT, 550)
    Call(SetCamPitch, CAM_DEFAULT, 10, -7)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.6))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 100, -200)
    Call(SetPanTarget, CAM_DEFAULT, 0, 100, -200)
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Call(SetCamPitch, CAM_DEFAULT, 3, -11)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(20)
    Call(SetMusicTrack, 0, SONG_PEACH_APPEARS, 1, 8)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach2_RaiseArms)
    Wait(10)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_Peach, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Outro_0066)
    Call(UseSettingsFrom, CAM_DEFAULT, 50, 0, 250)
    Call(SetPanTarget, CAM_DEFAULT, 50, 0, 250)
    Call(SetCamDistance, CAM_DEFAULT, 500)
    Call(SetCamPitch, CAM_DEFAULT, 3, -10)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(1)
    Call(SpeakToPlayer, NPC_Peach, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Outro_0067)
    Wait(10)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 100, -200)
    Call(SetPanTarget, CAM_DEFAULT, 0, 100, -200)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPitch, CAM_DEFAULT, 25, Float(-9.5))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(InterpPlayerYaw, 90, 0)
    Wait(10)
    Call(SpeakToPlayer, NPC_Peach, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Outro_0068)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach2_LowerArms)
    Wait(10)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Idle)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 300)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 300)
    Call(SetCamDistance, CAM_DEFAULT, Float(252.7))
    Call(SetCamPitch, CAM_DEFAULT, 5, Float(-9.5))
    Call(SetCamPosA, CAM_DEFAULT, 500, 100)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(20)
    Call(ShowMessageAtWorldPos, MSG_Outro_0069, 0, 100, -200)
    Call(UseSettingsFrom, CAM_DEFAULT, 250, 0, 100)
    Call(SetPanTarget, CAM_DEFAULT, 250, 0, 100)
    Call(SetCamDistance, CAM_DEFAULT, 400)
    Call(SetCamPitch, CAM_DEFAULT, 15, -1)
    Call(SetCamPosA, CAM_DEFAULT, -100, 100)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(1)
    Call(ShowMessageAtWorldPos, MSG_Outro_006A, 0, 100, -200)
    Call(UseSettingsFrom, CAM_DEFAULT, -250, 0, 50)
    Call(SetPanTarget, CAM_DEFAULT, -250, 0, 50)
    Call(SetCamDistance, CAM_DEFAULT, 450)
    Call(SetCamPitch, CAM_DEFAULT, 15, -7)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(1)
    Call(ShowMessageAtWorldPos, MSG_Outro_006B, 0, 100, -200)
    Call(UseSettingsFrom, CAM_DEFAULT, -150, 0, 360)
    Call(SetPanTarget, CAM_DEFAULT, -150, 0, 360)
    Call(SetCamDistance, CAM_DEFAULT, 300)
    Call(SetCamPitch, CAM_DEFAULT, 25, -13)
    Call(SetCamPosA, CAM_DEFAULT, 820, -100)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(1)
    Call(ShowMessageAtWorldPos, MSG_Outro_006C, 0, 100, -200)
    Wait(10)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 100, -200)
    Call(SetPanTarget, CAM_DEFAULT, 0, 100, -200)
    Call(SetCamDistance, CAM_DEFAULT, 250)
    Call(SetCamPitch, CAM_DEFAULT, 5, -10)
    Call(SetCamPosA, CAM_DEFAULT, -500, -1400)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(1)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach2_RaiseArms)
    Wait(10)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_Peach, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_Outro_006D)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach2_LowerArms)
    Wait(30)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach3_Pray)
    Wait(60)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach2_TalkIdle)
    Call(SpeakToPlayer, NPC_Peach, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_Outro_006E)
    Call(SetNpcAnimation, NPC_Peach, ANIM_Peach2_SpreadArms)
    Call(EnableGroup, MODEL_chandelier, FALSE)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 120)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 120)
    Call(SetCamDistance, CAM_DEFAULT, 1300)
    Call(SetCamPitch, CAM_DEFAULT, 30, -7)
    Call(SetCamPosA, CAM_DEFAULT, -120, 75)
    Call(SetCamSpeed, CAM_DEFAULT, Float(0.5))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(120)
    Call(N(FadeScreenToWhite))
    Wait(60)
    Call(FadeOutMusic, 0, 2000)
    Call(GotoMapSpecial, Ref("end_00"), end_00_ENTRY_0, TRANSITION_OUTRO_END_SCENE)
    Wait(100)
    Return
    End
};
