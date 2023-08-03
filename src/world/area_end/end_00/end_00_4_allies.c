#include "end_00.h"
#include "effects.h"

EvtScript N(EVS_ParadePhase_Luigi) = {
    EVT_CALL(PlaySound, SOUND_89)
    EVT_WAIT(80 * DT)
    EVT_THREAD
        EVT_LOOP(9 * DT)
            EVT_CALL(PlaySoundAtNpc, NPC_Luigi, SOUND_NORMAL_VOICE_A, SOUND_SPACE_MODE_0)
            EVT_WAIT(15)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_Luigi, PARADE_START, 0, 120 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_ParadeLuigi_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Luigi, 90, 0)
    EVT_WAIT(25 * DT)
    EVT_CALL(StopSound, SOUND_89)
    EVT_WAIT(15 * DT)
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_LOOP(4 * DT)
            EVT_CALL(PlaySoundAtNpc, NPC_Luigi, SOUND_14, SOUND_SPACE_MODE_0)
            EVT_WAIT(15)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_ParadeLuigi_BlowWhistle)
    EVT_WAIT(30 * DT)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Luigi, ANIM_ParadeLuigi_MarchInPlace)
    EVT_WAIT(7 * DT)
    EVT_CALL(SetMusicTrack, 0, SONG_PARADE_DAY, 0, 8)
    EVT_WAIT(120 * DT)
    EVT_WAIT(100 * DT)
    EVT_CALL(InterpNpcYaw, NPC_Luigi, 270, 0)
    EVT_WAIT(30 * DT)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_Partners) = {
    EVT_PLAY_EFFECT(EFFECT_CONFETTI, 3, -2545, 200, 0, 1, 800)
    EVT_CALL(EnableNpcShadow, NPC_Goombario, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_Bombette, FALSE)
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_WAIT(25)
            EVT_PLAY_EFFECT(EFFECT_CONFETTI, 4, -2530, 95, 5, 1, 20)
            EVT_WAIT(20)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_Sushie, EVT_FLOAT(1.0))
        EVT_LOOP(0)
            EVT_CALL(NpcJump0, NPC_Sushie, -2550, 35, 7, 15)
            EVT_WAIT(10)
            EVT_CALL(NpcJump0, NPC_Sushie, -2570, 61, 7, 15)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_PARTNERS + 545)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Twirler) = {
    EVT_CALL(EnableNpcShadow, LVar1, FALSE)
    EVT_CALL(SetNpcJumpscale, LVar1, EVT_FLOAT(0.5))
    EVT_LOOP(0)
        EVT_CALL(SetNpcAnimation, LVar0, ANIM_ParadeToad_Red_TwirlerWalk)
        EVT_WAIT(30)
        EVT_CHILD_THREAD
            EVT_CALL(GetNpcPos, LVar0, LVar2, LVar3, LVar4)
            EVT_ADD(LVar2, -7)
            EVT_CALL(SetNpcPos, LVar1, LVar2, LVar3, LVar4)
            EVT_CALL(NpcJump0, LVar1, LVar2, LVar3, LVar4, 40)
            EVT_CALL(SetNpcPos, LVar1, 0, -500, 0)
        EVT_END_CHILD_THREAD
        EVT_CALL(SetNpcAnimation, LVar0, ANIM_ParadeToad_Red_TwirlerToss)
        EVT_WAIT(5)
        EVT_CALL(SetNpcAnimation, LVar0, ANIM_ParadeToad_Red_TwirlerCatch)
        EVT_WAIT(5)
        EVT_CALL(SetNpcAnimation, LVar0, ANIM_ParadeToad_Red_TwirlerSpin)
        EVT_WAIT(20)
        EVT_CALL(SetNpcAnimation, LVar0, ANIM_ParadeToad_Red_TwirlerToss)
        EVT_WAIT(5)
        EVT_CALL(SetNpcAnimation, LVar0, ANIM_ParadeToad_Red_TwirlerCatch)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_QuizCrew) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_TOAD_TOWN + 420)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_ChuckQuizmo, ANIM_ChuckQuizmo_OpenHat)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, NPC_ChuckQuizmo, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 80)
    EVT_PLAY_EFFECT(EFFECT_EXPLOSION, 0, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_VannaT, ANIM_VannaT_Clap)
    EVT_WAIT(60)
    EVT_CALL(SetNpcAnimation, NPC_ChuckQuizmo, ANIM_ChuckQuizmo_CloseHat)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_ChuckQuizmo, ANIM_ChuckQuizmo_Walk)
    EVT_CALL(SetNpcAnimation, NPC_VannaT, ANIM_VannaT_Walk)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_TOAD_TOWN + 600)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(InterpNpcYaw, NPC_VannaT, 90, 5)
    EVT_CALL(SetNpcAnimation, NPC_VannaT, ANIM_VannaT_Wave)
    EVT_WAIT(30)
    EVT_CALL(InterpNpcYaw, NPC_VannaT, 270, 5)
    EVT_CALL(SetNpcAnimation, NPC_VannaT, ANIM_VannaT_Walk)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_Toads) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_TOAD_TOWN)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(LVar0, NPC_Twirler1)
    EVT_SET(LVar1, NPC_Baton1)
    EVT_EXEC_GET_TID(N(EVS_Twirler), LVarA)
    EVT_SET(LVar0, NPC_Twirler2)
    EVT_SET(LVar1, NPC_Baton2)
    EVT_EXEC_GET_TID(N(EVS_Twirler), LVarB)
    EVT_SET(LVar0, NPC_Twirler3)
    EVT_SET(LVar1, NPC_Baton3)
    EVT_EXEC_GET_TID(N(EVS_Twirler), LVarC)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_TOAD_TOWN + 250)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(EVS_QuizCrew))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_TOAD_TOWN + 480)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_KILL_THREAD(LVarB)
    EVT_KILL_THREAD(LVarC)
    EVT_RETURN
    EVT_END
};
