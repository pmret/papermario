#include "obk_01.h"
#include "effects.h"

EvtScript N(EVS_Scene_JumpScareBoo) = {
    Call(DisablePlayerInput, TRUE)
    Call(GetPlayerPos, LVar3, LVar4, LVar5)
    Add(LVar4, 80)
    Call(SetNpcPos, NPC_JumpScareBoo, LVar3, LVar4, LVar5)
    Thread
        Wait(5 * DT)
        Sub(LVar3, 10)
        PlayEffect(EFFECT_RADIAL_SHIMMER, 0, LVar3, LVar4, LVar5, Float(2.8), 50)
    EndThread
    Call(PlaySoundAtNpc, NPC_JumpScareBoo, SOUND_JUMP_SCARE, SOUND_SPACE_DEFAULT)
    Sub(LVar4, 12)
    Call(MakeLerp, 10, 450, 8 * DT, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        SetF(LVar2, LVar0)
        DivF(LVar2, Float(100.0))
        Call(SetNpcScale, NPC_JumpScareBoo, LVar2, LVar2, LVar2)
        MulF(LVar2, 12)
        SetF(LVar6, LVar4)
        SubF(LVar6, LVar2)
        Call(SetNpcPos, NPC_JumpScareBoo, LVar3, LVar6, LVar5)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Wait(15)
    SetF(LVar0, Float(240.0))
    Loop(20 * DT)
        SubF(LVar0, Float(240.0 / (s32)(20 * DT)))
        Call(SetNpcImgFXParams, NPC_JumpScareBoo, IMGFX_SET_ALPHA, LVar0, 0, 0, 0)
        Wait(1)
    EndLoop
    Call(RemoveNpc, NPC_JumpScareBoo)
    Set(GB_StoryProgress, STORY_CH3_TRIGGERED_DOOR_JUMP_SCARE)
    Call(DisablePlayerInput, FALSE)
    Return
    End
};
