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
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tts, SOUND_LARGE_DOOR_OPEN, 0)
    EVT_CALL(MakeLerp, 0, 80, 14, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_door2, LVar0, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_door1, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(30)
    EVT_CALL(MakeLerp, 80, 0, 8, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_door2, LVar0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_door1, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_tts, SOUND_LARGE_DOOR_CLOSE, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenAndClosePeachDoor) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_ttn, SOUND_LARGE_DOOR_OPEN, 0)
    EVT_CALL(MakeLerp, 0, 80, 14, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_door3, LVar0, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_door4, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(30)
    EVT_CALL(MakeLerp, 80, 0, 8, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_door4, LVar0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_door3, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_ttn, SOUND_LARGE_DOOR_CLOSE, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_Ending) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 50, 0, 250)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 50, 0, 250)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(10)
    EVT_EXEC(N(EVS_OpenAndCloseFrontDoor_Ending))
    EVT_CALL(func_802D1270, 0, 300, EVT_FLOAT(4.0))
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_ToadMinister_Walk)
    EVT_CALL(NpcMoveTo, NPC_Toad_01, 74, 243, 10)
    EVT_CALL(SetNpcAnimation, NPC_Toad_01, ANIM_ToadMinister_Idle)
    EVT_CALL(SpeakToPlayer, NPC_Toad_01, ANIM_ToadMinister_Talk, ANIM_ToadMinister_Idle, 0, MSG_Outro_0064)
    EVT_WAIT(10)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 100, -290)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 100, -290)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 10, -7)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_ToadGuard_03, ANIM_ToadGuard_Red_Talk, ANIM_ToadGuard_Red_Idle, 5, MSG_Outro_0065)
    EVT_CALL(InterpPlayerYaw, 0, 0)
    EVT_WAIT(10)
    EVT_CALL(SetMusicTrack, 0, SONG_PEACH_APPEARS, 0, 8)
    EVT_EXEC(N(EVS_OpenAndClosePeachDoor))
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Walk)
        EVT_CALL(SetNpcSpeed, NPC_Peach, EVT_FLOAT(2.0))
        EVT_CALL(NpcMoveTo, NPC_Peach, 0, -200, 0)
        EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Idle)
    EVT_END_THREAD
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_Peach, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, -350)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 100, -200)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 100, -200)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 550)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 10, -7)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.6))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 100, -200)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 100, -200)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 3, -11)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(20)
    EVT_CALL(SetMusicTrack, 0, SONG_PEACH_APPEARS, 1, 8)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_Peach, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Outro_0066)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 50, 0, 250)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 50, 0, 250)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 500)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 3, -10)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(SpeakToPlayer, NPC_Peach, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Outro_0067)
    EVT_WAIT(10)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 100, -200)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 100, -200)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 25, EVT_FLOAT(-9.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_WAIT(10)
    EVT_CALL(SpeakToPlayer, NPC_Peach, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 5, MSG_Outro_0068)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_LowerArms)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach1_Idle)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 300)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 300)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(252.7))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 5, EVT_FLOAT(-9.5))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 500, 100)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(20)
    EVT_CALL(ShowMessageAtWorldPos, MSG_Outro_0069, 0, 100, -200)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 250, 0, 100)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 250, 0, 100)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 400)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 15, -1)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -100, 100)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(ShowMessageAtWorldPos, MSG_Outro_006A, 0, 100, -200)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -250, 0, 50)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -250, 0, 50)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 450)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 15, -7)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(ShowMessageAtWorldPos, MSG_Outro_006B, 0, 100, -200)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -150, 0, 360)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -150, 0, 360)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 25, -13)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 820, -100)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(ShowMessageAtWorldPos, MSG_Outro_006C, 0, 100, -200)
    EVT_WAIT(10)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 100, -200)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 100, -200)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 250)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 5, -10)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -500, -1400)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_RaiseArms)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_Peach, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_Outro_006D)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_LowerArms)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach3_Pray)
    EVT_WAIT(60)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_TalkIdle)
    EVT_CALL(SpeakToPlayer, NPC_Peach, ANIM_Peach2_Talk, ANIM_Peach2_TalkIdle, 0, MSG_Outro_006E)
    EVT_CALL(SetNpcAnimation, NPC_Peach, ANIM_Peach2_SpreadArms)
    EVT_CALL(EnableGroup, MODEL_chandelier, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 120)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 120)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 1300)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, 30, -7)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -120, 75)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(120)
    EVT_CALL(N(FadeScreenToWhite))
    EVT_WAIT(60)
    EVT_CALL(FadeOutMusic, 0, 2000)
    EVT_CALL(GotoMapSpecial, EVT_PTR("end_00"), end_00_ENTRY_0, TRANSITION_OUTRO_END_SCENE)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};
