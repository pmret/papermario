#include "mac_00.h"
#include "sprite/player.h"

EvtScript N(EVS_PlayerExitPipe_Epilogue) = {
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(HidePlayerShadow, TRUE)
    EVT_CALL(SetPlayerPos, -100, -10, -370)
    EVT_CALL(InterpPlayerYaw, 135, 0)
    EVT_WAIT(2)
    EVT_CALL(PlaySoundAtPlayer, SOUND_ENTER_PIPE, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetPlayerImgFXFlags, IMGFX_FLAG_REVERSE_ANIM)
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_SET_ANIM, IMGFX_ANIM_VERTICAL_PIPE_CURL, 1, 1, 0)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_LOOP(40)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetPlayerPos, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(UpdatePlayerImgFX, ANIM_Mario1_Idle, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(HidePlayerShadow, FALSE)
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_LuigiExitPipe_Epilogue) = {
    EVT_CALL(EnableNpcShadow, NPC_Luigi_Epilogue, FALSE)
    EVT_CALL(SetNpcPos, NPC_Luigi_Epilogue, -100, -35, -370)
    EVT_CALL(SetNpcYaw, NPC_Luigi_Epilogue, 135)
    EVT_WAIT(2)
    EVT_CALL(PlaySoundAtNpc, NPC_Luigi_Epilogue, SOUND_ENTER_PIPE, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcImgFXFlags, NPC_Luigi_Epilogue, IMGFX_FLAG_REVERSE_ANIM)
    EVT_CALL(SetNpcImgFXParams, NPC_Luigi_Epilogue, IMGFX_SET_ANIM, IMGFX_ANIM_VERTICAL_PIPE_CURL, 1, 1, 0)
    EVT_CALL(SetNpcPos, NPC_Luigi_Epilogue, -100, -10, -370)
    EVT_CALL(GetNpcPos, NPC_Luigi_Epilogue, LVar0, LVar1, LVar2)
    EVT_LOOP(45)
        EVT_ADD(LVar1, 1)
        EVT_CALL(SetNpcPos, NPC_Luigi_Epilogue, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetNpcImgFXParams, NPC_Luigi_Epilogue, IMGFX_CLEAR, 0, 0, 0, 0)
    EVT_CALL(SetNpcPos, NPC_Luigi_Epilogue, -100, 30, -370)
    EVT_WAIT(3)
    EVT_CALL(EnableNpcShadow, NPC_Luigi_Epilogue, TRUE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Scene_BeginEpilogue) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -100, 30, -370)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -100, 30, -370)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_EXEC_WAIT(N(EVS_PlayerExitPipe_Epilogue))
        EVT_WAIT(10)
        EVT_CALL(func_802D1270, -60, -320, EVT_FLOAT(4.0))
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(70)
        EVT_EXEC_WAIT(N(EVS_LuigiExitPipe_Epilogue))
        EVT_WAIT(10)
        EVT_CALL(SetNpcFlagBits, NPC_Luigi_Epilogue, NPC_FLAG_GRAVITY, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_Luigi_Epilogue, ANIM_Luigi_Run)
        EVT_CALL(SetNpcSpeed, NPC_Luigi_Epilogue, EVT_FLOAT(4.0))
        EVT_CALL(NpcMoveTo, NPC_Luigi_Epilogue, -100, -300, 0)
        EVT_CALL(SetNpcAnimation, NPC_Luigi_Epilogue, ANIM_Luigi_Idle)
    EVT_END_THREAD
    EVT_WAIT(70)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -60, 0, -320)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -60, 0, -320)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(80)
    EVT_CALL(SpeakToPlayer, NPC_Luigi_Epilogue, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_Outro_0023)
    EVT_WAIT(10)
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(PlayerFaceNpc, NPC_Luigi_Epilogue, FALSE)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Luigi_Epilogue, ANIM_Luigi_Run)
    EVT_CALL(NpcMoveTo, NPC_Luigi_Epilogue, 60, -100, 0)
    EVT_CALL(SetNpcFlagBits, NPC_Luigi_Epilogue, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcPos, NPC_Luigi_Epilogue, NPC_DISPOSE_LOCATION)
    EVT_EXEC(N(EVS_BlockExitToGoomaRoad))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
