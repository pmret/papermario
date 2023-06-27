#include "kmr_20.h"
#include "sprite/player.h"

#include "world/common/complete/ToadHouseBlanketAnim.inc.c"
#include "world/common/atomic/ToadHouse.inc.c"
#include "world/common/atomic/ToadHouse.data.inc.c"

API_CALLABLE(N(MuteAmbienceVolume_Bed)) {
    snd_ambient_set_volume(0, 1000, 1);
    return ApiStatus_DONE2;
}

API_CALLABLE(N(SetAmbienceVolumeHalf_Bed)) {
    snd_ambient_set_volume(0, 1000, 63);
    return ApiStatus_DONE2;
}

#include "world/common/todo/WaitForPlayerToLand.inc.c"

EvtScript N(EVS_ToadHouse_SetDialogue) = {
    EVT_SET(LVar0, MSG_CH0_0106)
    EVT_SET(LVar8, MSG_CH0_0107)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_SET(LVar3, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_GetInBed) = {
    EVT_EXEC(N(EVS_PlayRestingSong))
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -28, -100, 0)
    EVT_CALL(InterpPlayerYaw, 300, 0)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_THREAD
        EVT_WAIT(6)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 40)
        EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 35, -10)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 135)
        EVT_CALL(SetCamPosA, CAM_DEFAULT, -170, 0)
        EVT_CALL(SetCamPosB, CAM_DEFAULT, -109, -76)
        EVT_CALL(SetCamPosC, CAM_DEFAULT, 0, 120)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(EnableGroup, MODEL_o170, FALSE)
        EVT_CALL(EnableGroup, MODEL_o172, FALSE)
        EVT_CALL(EnableGroup, MODEL_o175, FALSE)
        EVT_CALL(EnableGroup, MODEL_o177, FALSE)
        EVT_CALL(EnableGroup, MODEL_o178, FALSE)
        EVT_CALL(EnableGroup, MODEL_o183, FALSE)
        EVT_CALL(EnableGroup, MODEL_o188, FALSE)
        EVT_CALL(EnableGroup, MODEL_o189, FALSE)
        EVT_CALL(EnableGroup, MODEL_o186, FALSE)
        EVT_CALL(EnableGroup, MODEL_o190, FALSE)
        EVT_CALL(EnableGroup, MODEL_o191, FALSE)
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar4, LVar5, LVar6)
    EVT_CALL(MakeLerp, 30, 85, 6, EASING_LINEAR)
    EVT_LOOP(6)
        EVT_WAIT(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetPlayerPos, LVar4, LVar0, LVar6)
    EVT_END_LOOP
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(SetPlayerImgFXFlags, IMGFX_FLAG_800)
    EVT_CALL(UpdatePlayerImgFX, 0x00010002, IMGFX_SET_ANIM, IMGFX_ANIM_GET_IN_BED, 1, 1, 0)
    EVT_THREAD
        EVT_WAIT(60)
        EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_SleepStanding)
    EVT_END_THREAD
    EVT_CALL(N(MuteAmbienceVolume_Bed))
    EVT_WAIT(75)
    EVT_THREAD
        EVT_WAIT(65)
        EVT_CALL(N(ToadHouse_CamSetFOV), 0, 25)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(EnableGroup, MODEL_o170, TRUE)
        EVT_CALL(EnableGroup, MODEL_o172, TRUE)
        EVT_CALL(EnableGroup, MODEL_o175, TRUE)
        EVT_CALL(EnableGroup, MODEL_o177, TRUE)
        EVT_CALL(EnableGroup, MODEL_o178, TRUE)
        EVT_CALL(EnableGroup, MODEL_o183, TRUE)
        EVT_CALL(EnableGroup, MODEL_o188, TRUE)
        EVT_CALL(EnableGroup, MODEL_o189, TRUE)
        EVT_CALL(EnableGroup, MODEL_o186, TRUE)
        EVT_CALL(EnableGroup, MODEL_o190, TRUE)
        EVT_CALL(EnableGroup, MODEL_o191, TRUE)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ToadHouse_ReturnFromRest) = {
    EVT_CALL(N(SetAmbienceVolumeHalf_Bed))
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetPlayerPos, -45, 30, -70)
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetNpcPos, NPC_PARTNER, -75, 30, -70)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
    EVT_WAIT(5)
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_UseBed) = {
    EVT_CALL(N(WaitForPlayerToLand))
    EVT_IF_EQ(LVar0, 1)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(N(ToadHouse_InitScreenOverlay), 0, 0, 0)
    EVT_EXEC_WAIT(N(EVS_ToadHouse_SetDialogue))
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar9, LVar1)
    EVT_SET(LVarA, LVar2)
    EVT_SET(LVarB, LVar3)
    EVT_CALL(N(ToadHouse_DoesPlayerNeedSleep))
    EVT_IF_EQ(LVar1, 0)
        EVT_SET(LVar8, LVar0)
    EVT_END_IF
    EVT_CALL(ShowMessageAtScreenPos, LVar8, 160, 40)
    EVT_CALL(ShowChoice, MSG_Choice_0007)
    EVT_WAIT(10)
    EVT_IF_EQ(LVar0, 1)
        EVT_CALL(CloseMessage)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(CloseMessage)
    EVT_CALL(SetPlayerJumpscale, 1)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(N(ToadHouse_DisableStatusBar))
    EVT_IF_NE(LVar4, 0)
        EVT_EXEC(N(EVS_ToadHouse_Unk2))
    EVT_END_IF
    EVT_CALL(N(ToadHouse_PutPartnerAway), LVarA)
    EVT_WAIT(20)
    EVT_EXEC_GET_TID(N(EVS_ToadHouse_GetInBed), LVar9)
    EVT_CALL(N(ToadHouse_AwaitScriptComplete), LVar9)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 255, 60, EASING_LINEAR)
        EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(ToadHouse_UpdateScreenOverlay), 3, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(FullyRestoreHPandFP)
        EVT_CALL(FullyRestoreSP)
        EVT_IF_NE(LVar4, 0)
            EVT_EXEC(N(EVS_ToadHouse_Unk1))
        EVT_END_IF
        EVT_CALL(N(ToadHouse_GetPartnerBackOut), LVarA)
        EVT_WAIT(30)
        EVT_CALL(MakeLerp, 255, 0, 30, EASING_LINEAR)
        EVT_LABEL(1)
        EVT_CALL(UpdateLerp)
        EVT_CALL(N(ToadHouse_UpdateScreenOverlay), 0, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(90)
    EVT_EXEC_GET_TID(N(EVS_ToadHouse_ReturnFromRest), LVar9)
    EVT_CALL(N(ToadHouse_AwaitScriptComplete), LVar9)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(N(ToadHouse_ShowWorldStatusBar))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetupBed) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_UseBed)), TRIGGER_WALL_PRESS_A, COLLIDER_o352, 1, 0)
    EVT_RETURN
    EVT_END
};
