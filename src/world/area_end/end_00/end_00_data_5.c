#include "end_00.h"
#include "effects.h"

EvtScript N(D_80247230_DFDC30) = {
    EVT_CALL(PlaySound, SOUND_89)
    EVT_WAIT(80)
    EVT_THREAD
        EVT_LOOP(9)
            EVT_CALL(PlaySoundAtNpc, NPC_00, SOUND_11, 0)
            EVT_WAIT(15)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_00, -3080, 0, 120)
    EVT_CALL(SetNpcAnimation, NPC_00, ANIM_ParadeLuigi_Idle)
    EVT_WAIT(10)
    EVT_CALL(InterpNpcYaw, NPC_00, 90, 0)
    EVT_WAIT(25)
    EVT_CALL(StopSound, SOUND_89)
    EVT_WAIT(15)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_LOOP(4)
            EVT_CALL(PlaySoundAtNpc, NPC_00, SOUND_14, 0)
            EVT_WAIT(15)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_00, ANIM_ParadeLuigi_BlowWhistle)
    EVT_WAIT(30)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_00, ANIM_ParadeLuigi_MarchInPlace)
    EVT_WAIT(7)
    EVT_CALL(SetMusicTrack, 0, SONG_PARADE_DAY, 0, 8)
    EVT_WAIT(120)
    EVT_WAIT(100)
    EVT_CALL(InterpNpcYaw, NPC_00, 270, 0)
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80247418_DFDE18) = {
    EVT_CALL(PlayEffect, EFFECT_CONFETTI, 3, 0xFFFFF60F, 200, 0, 1, 800, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(EnableNpcShadow, NPC_07, FALSE)
    EVT_CALL(EnableNpcShadow, NPC_09, FALSE)
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_WAIT(25)
            EVT_CALL(PlayEffect, EFFECT_CONFETTI, 4, 0xFFFFF61E, 95, 5, 1, 20, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(20)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(SetNpcJumpscale, NPC_0D, EVT_FLOAT(1.0))
        EVT_LOOP(0)
            EVT_CALL(NpcJump0, NPC_0D, -2550, 35, 7, 15)
            EVT_WAIT(10)
            EVT_CALL(NpcJump0, NPC_0D, -2570, 61, 7, 15)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFF704)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80247600_DFE000) = {
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

EvtScript N(D_802477A0_DFE1A0) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFF7AE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_15, ANIM_ChuckQuizmo_OpenHat)
    EVT_WAIT(10)
    EVT_CALL(GetNpcPos, NPC_15, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 80)
    EVT_CALL(PlayEffect, EFFECT_EXPLOSION, 0, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_16, ANIM_VannaT_Clap)
    EVT_WAIT(60)
    EVT_CALL(SetNpcAnimation, NPC_15, ANIM_ChuckQuizmo_CloseHat)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_15, ANIM_ChuckQuizmo_Walk)
    EVT_CALL(SetNpcAnimation, NPC_16, ANIM_VannaT_Walk)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFF862)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(InterpNpcYaw, NPC_16, 90, 5)
    EVT_CALL(SetNpcAnimation, NPC_16, ANIM_VannaT_Wave)
    EVT_WAIT(30)
    EVT_CALL(InterpNpcYaw, NPC_16, 270, 5)
    EVT_CALL(SetNpcAnimation, NPC_16, ANIM_VannaT_Walk)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802479C4_DFE3C4) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFF60A)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(LVar0, 15)
    EVT_SET(LVar1, 18)
    EVT_EXEC_GET_TID(N(D_80247600_DFE000), LVarA)
    EVT_SET(LVar0, 16)
    EVT_SET(LVar1, 19)
    EVT_EXEC_GET_TID(N(D_80247600_DFE000), LVarB)
    EVT_SET(LVar0, 17)
    EVT_SET(LVar1, 20)
    EVT_EXEC_GET_TID(N(D_80247600_DFE000), LVarC)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFF704)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC(N(D_802477A0_DFE1A0))
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFF7EA)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_KILL_THREAD(LVarB)
    EVT_KILL_THREAD(LVarC)
    EVT_RETURN
    EVT_END
};
