#include "mim_11.h"

EvtScript N(D_80242560_BB95D0) = {
    EVT_WAIT(30 * DT)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_mon, SOUND_METAL_GATE_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(MakeLerp, 0, 80, 30, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_h_mon1, LVar0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_h_mon2, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mon, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0 / DT))
    EVT_CALL(PlayerMoveTo, -101, 17, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mon, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(MakeLerp, 80, 0, 8, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_h_mon1, LVar0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_h_mon2, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtCollider, COLLIDER_mon, SOUND_METAL_GATE_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 15, EVT_FLOAT(1.5))
    EVT_WAIT(20 * DT)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
    EVT_CALL(SetCamType, CAM_DEFAULT, 0, TRUE)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(19.5), EVT_FLOAT(-14.9))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, -133, 52)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 23, -109)
    EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 23, 0, -109)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SetMusicTrack, 0, SONG_BOOS_MANSION, 0, 8)
    EVT_CALL(PlaySoundAtNpc, NPC_Bootler, SOUND_BOO_VANISH_A, SOUND_SPACE_DEFAULT)
    EVT_SETF(LVar0, EVT_FLOAT(0.0))
    EVT_LOOP(90 * DT)
        EVT_ADDF(LVar0, EVT_FLOAT(2.6667 / DT))
        EVT_CALL(SetNpcImgFXParams, NPC_Bootler, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Talk, ANIM_Bootler_Idle, 0, MSG_CH3_0028)
    EVT_CALL(SetMusicTrack, 0, SONG_BOOS_MANSION, 1, 8)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(0.0), EVT_FLOAT(-25.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 550)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH3_0029, 160, 40)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(19.5), EVT_FLOAT(-14.9))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Bootler, ANIM_Bootler_Talk, ANIM_Bootler_Idle, 0, MSG_CH3_002A)
    EVT_CALL(PlaySoundAtNpc, NPC_Bootler, SOUND_BOO_APPEAR_A, SOUND_SPACE_DEFAULT)
    EVT_SETF(LVar0, EVT_FLOAT(240.0))
    EVT_LOOP(90 * DT)
        EVT_SUBF(LVar0, EVT_FLOAT(2.6667 / DT))
        EVT_CALL(SetNpcImgFXParams, NPC_Bootler, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(RemoveNpc, NPC_Bootler)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0 / DT))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242B90_BB9C00) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_mon, SOUND_METAL_GATE_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mon, COLLIDER_FLAGS_UPPER_MASK)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 80, 30, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_h_mon1, LVar0, 0, 1, 0)
            EVT_CALL(RotateModel, MODEL_h_mon2, LVar0, 0, -1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, 80)
    EVT_SUB(LVar2, 80)
    EVT_CALL(PlayerMoveTo, LVar0, LVar2, 30)
    EVT_WAIT(10)
    EVT_CALL(MakeLerp, 80, 0, 30, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_h_mon1, LVar0, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_h_mon2, LVar0, 0, -1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mon, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_mon, SOUND_METAL_GATE_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242DC8_BB9E38) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_mon, SOUND_METAL_GATE_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_mon, COLLIDER_FLAGS_UPPER_MASK)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 80, 30, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateModel, MODEL_h_mon1, LVar0, 0, -1, 0)
            EVT_CALL(RotateModel, MODEL_h_mon2, LVar0, 0, 1, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -80)
    EVT_SUB(LVar2, -80)
    EVT_CALL(PlayerMoveTo, LVar0, LVar2, 20)
    EVT_CALL(MakeLerp, 80, 0, 30, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_h_mon1, LVar0, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_h_mon2, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_mon, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_mon, SOUND_METAL_GATE_CLOSE, SOUND_SPACE_DEFAULT)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242FF4_BBA064) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(InterruptUsePartner)
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH3_OPENED_BOOS_MANSION_GATE)
            EVT_SET(GB_StoryProgress, STORY_CH3_OPENED_BOOS_MANSION_GATE)
            EVT_SET(AF_MIM_01, TRUE)
            EVT_EXEC_WAIT(N(D_80242560_BB95D0))
        EVT_CASE_GE(STORY_CH3_OPENED_BOOS_MANSION_GATE)
            EVT_IF_EQ(AF_MIM_01, FALSE)
                EVT_EXEC_WAIT(N(D_80242B90_BB9C00))
                EVT_SET(AF_MIM_01, TRUE)
            EVT_ELSE
                EVT_EXEC_WAIT(N(D_80242DC8_BB9E38))
                EVT_SET(AF_MIM_01, FALSE)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802430E0_BBA150) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(D_80242FF4_BBA064)), TRIGGER_WALL_PRESS_A, COLLIDER_mon, 1, 0)
    EVT_RETURN
    EVT_END
};
