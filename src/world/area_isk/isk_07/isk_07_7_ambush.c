#include "isk_07.h"
#include "sprite/player.h"

extern EvtScript N(EVS_OpenSarcophagus1);
extern EvtScript N(EVS_OpenSarcophagus2);
extern EvtScript N(EVS_OpenSarcophagus3);

EvtScript N(EVS_SetupSarcophagi) = {
    EVT_IF_EQ(GF_ISK07_OpenedSarcophagi, FALSE)
        EVT_SET(AF_ISK07_OpeningSarcophagus1, FALSE)
        EVT_SET(AF_ISK07_OpeningSarcophagus2, FALSE)
        EVT_SET(AF_ISK07_OpeningSarcophagus3, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2039, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2040, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2041, COLLIDER_FLAGS_UPPER_MASK)
        EVT_LABEL(10)
            EVT_IF_EQ(GF_ISK07_OpenedSarcophagi, FALSE)
                EVT_WAIT(1)
                EVT_GOTO(10)
            EVT_END_IF
        EVT_CALL(PlaySound, SOUND_CHIME_BEGIN_AMBUSH)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 30, EVT_FLOAT(1.0))
        EVT_CALL(SetNpcYaw, NPC_Pokey_01, 105)
        EVT_CALL(SetNpcFlagBits, NPC_Pokey_01, NPC_FLAG_INVISIBLE, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_Pokey_02, NPC_FLAG_INVISIBLE, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_Pokey_03, NPC_FLAG_INVISIBLE, FALSE)
        EVT_THREAD
            EVT_WAIT(12)
            EVT_CALL(InterpPlayerYaw, 109, 0)
            EVT_WAIT(3)
            EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_SHOCK, 1, 1, 0)
            EVT_CALL(SetPlayerAnimation, ANIM_MarioW2_Shocked)
            EVT_WAIT(20)
            EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
            EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_END_THREAD
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -151, -390, 576)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -151, -390, 576)
        EVT_WAIT(1)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_EXEC(N(EVS_OpenSarcophagus1))
        EVT_WAIT(15)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 51, -390, 589)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_EXEC(N(EVS_OpenSarcophagus2))
        EVT_WAIT(15)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 239, -390, 515)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_EXEC(N(EVS_OpenSarcophagus3))
        EVT_WAIT(15)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 517, -390, 292)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_EXEC(N(EVS_ShutEntryDoor))
        EVT_WAIT(30)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_SET(AF_ISK07_MummiesReleased, TRUE)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_SET(AF_ISK07_OpeningSarcophagus1, TRUE)
        EVT_SET(AF_ISK07_OpeningSarcophagus2, TRUE)
        EVT_SET(AF_ISK07_OpeningSarcophagus3, TRUE)
        EVT_CALL(TranslateModel, MODEL_g323, 38, 0, 13)
        EVT_CALL(RotateModel, MODEL_g323, 35, 0, 1, 0)
        EVT_CALL(TranslateModel, MODEL_g327, 38, 0, 13)
        EVT_CALL(RotateModel, MODEL_g327, 35, 0, 1, 0)
        EVT_CALL(TranslateModel, MODEL_g331, 38, 0, 13)
        EVT_CALL(RotateModel, MODEL_g331, 35, 0, 1, 0)
        EVT_WAIT(5)
        EVT_SET(AF_ISK07_OpeningSarcophagus1, FALSE)
        EVT_SET(AF_ISK07_OpeningSarcophagus2, FALSE)
        EVT_SET(AF_ISK07_OpeningSarcophagus3, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2036, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2037, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2038, COLLIDER_FLAGS_UPPER_MASK)
        EVT_SET(AF_ISK07_MummiesReleased, TRUE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenSarcophagusAnim) = {
    EVT_CALL(PlaySoundAtModel, LVar3, SOUND_SARCOPHAGUS_OPEN, SOUND_SPACE_DEFAULT)
    EVT_CALL(TranslateModel, LVar3, 0, 0, 13)
    EVT_WAIT(3)
    EVT_CALL(MakeLerp, 0, 35, 9, EASING_COS_IN_OUT)
    EVT_LABEL(10)
        EVT_CALL(UpdateLerp)
        EVT_SET(LVar2, LVar0)
        EVT_MULF(LVar2, EVT_FLOAT(1.1))
        EVT_CALL(TranslateModel, LVar3, LVar2, 0, 13)
        EVT_CALL(RotateModel, LVar3, LVar0, 0, 1, 0)
        EVT_WAIT(1)
        EVT_IF_NE(LVar1, 0)
            EVT_GOTO(10)
        EVT_END_IF
    EVT_WAIT(3)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenSarcophagus1) = {
    EVT_SET(AF_ISK07_OpeningSarcophagus1, TRUE)
    EVT_SET(LVar3, MODEL_g323)
    EVT_EXEC_WAIT(N(EVS_OpenSarcophagusAnim))
    EVT_SET(AF_ISK07_OpeningSarcophagus1, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2036, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2039, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenSarcophagus2) = {
    EVT_SET(AF_ISK07_OpeningSarcophagus2, TRUE)
    EVT_SET(LVar3, MODEL_g327)
    EVT_EXEC_WAIT(N(EVS_OpenSarcophagusAnim))
    EVT_SET(AF_ISK07_OpeningSarcophagus2, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2037, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2040, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OpenSarcophagus3) = {
    EVT_SET(AF_ISK07_OpeningSarcophagus3, TRUE)
    EVT_SET(LVar3, MODEL_g331)
    EVT_EXEC_WAIT(N(EVS_OpenSarcophagusAnim))
    EVT_SET(AF_ISK07_OpeningSarcophagus3, FALSE)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o2038, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o2041, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};
