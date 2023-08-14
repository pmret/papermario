#include "obk_01.h"
#include "effects.h"

EvtScript N(EVS_Scene_JumpScareBoo) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
    EVT_ADD(LVar4, 80)
    EVT_CALL(SetNpcPos, NPC_JumpScareBoo, LVar3, LVar4, LVar5)
    EVT_THREAD
        EVT_WAIT(5 * DT)
        EVT_SUB(LVar3, 10)
        EVT_PLAY_EFFECT(EFFECT_RADIAL_SHIMMER, 0, LVar3, LVar4, LVar5, EVT_FLOAT(2.8), 50)
    EVT_END_THREAD
    EVT_CALL(PlaySoundAtNpc, NPC_JumpScareBoo, SOUND_JUMP_SCARE, SOUND_SPACE_DEFAULT)
    EVT_SUB(LVar4, 12)
    EVT_CALL(MakeLerp, 10, 450, 8 * DT, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar2, LVar0)
        EVT_DIVF(LVar2, EVT_FLOAT(100.0))
        EVT_CALL(SetNpcScale, NPC_JumpScareBoo, LVar2, LVar2, LVar2)
        EVT_MULF(LVar2, 12)
        EVT_SETF(LVar6, LVar4)
        EVT_SUBF(LVar6, LVar2)
        EVT_CALL(SetNpcPos, NPC_JumpScareBoo, LVar3, LVar6, LVar5)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(15)
    EVT_SETF(LVar0, EVT_FLOAT(240.0))
    EVT_LOOP(20 * DT)
        EVT_SUBF(LVar0, EVT_FLOAT(240.0 / (s32)(20 * DT)))
        EVT_CALL(SetNpcImgFXParams, NPC_JumpScareBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(RemoveNpc, NPC_JumpScareBoo)
    EVT_SET(GB_StoryProgress, STORY_CH3_TRIGGERED_DOOR_JUMP_SCARE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
