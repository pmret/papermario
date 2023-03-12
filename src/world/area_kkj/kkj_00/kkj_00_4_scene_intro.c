#include "kkj_00.h"

EvtScript N(EVS_OpenAndCloseFrontDoor_Intro) = {
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
    EVT_WAIT(30 * DT)
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

EvtScript N(EVS_Scene_Intro) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC(N(EVS_OpenAndCloseFrontDoor_Intro))
    EVT_THREAD
        EVT_CALL(SetNpcSpeed, NPC_Luigi, EVT_FLOAT(4.0))
        EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_RunBack)
        EVT_CALL(NpcMoveTo, NPC_Luigi, 20, 320, 0)
        EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_Luigi_Idle)
    EVT_END_THREAD
    EVT_CALL(func_802D1270, 80, 300, EVT_FLOAT(4.0 / DT))
    EVT_CALL(InterpPlayerYaw, 270, 5)
    EVT_WAIT(30 * DT)
    EVT_CALL(SpeakToPlayer, NPC_Luigi, ANIM_Luigi_Talk, ANIM_Luigi_Idle, 0, MSG_Intro_0024)
    EVT_WAIT(20 * DT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
