#include "hos_02.h"

EvtScript N(EVS_DescendStarBeam) = {
    Call(SetMusic, 0, SONG_STAR_WAY_OPENS, BGM_VARIATION_2, VOL_LEVEL_FULL)
    Call(N(func_80240F68_A17188), MV_StarBeamEffect)
    Call(SetPlayerSpeed, Float(3.0))
    Call(PlayerMoveTo, -1105, 230, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, false)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION, true)
    Call(SetNpcJumpscale, NPC_PARTNER, Float(0.5))
    Call(NpcJump0, NPC_PARTNER, -1105, -171, 220, 5)
    Thread
        Set(LVar0, 0)
        Set(LVar1, 90)
        Loop(0)
            Add(LVar0, 2)
            Add(LVar1, LVar0)
            Call(InterpPlayerYaw, LVar1, 0)
            Call(SetNpcRotation, NPC_PARTNER, 0, LVar1, 0)
            Wait(1)
        EndLoop
    EndThread
    Wait(60)
    Call(GetPlayerPos, LVar2, LVar3, LVar4)
    Set(LVar5, LVar4)
    Add(LVar5, -10)
    Call(MakeLerp, LVar3, -600, 40, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        Call(SetPlayerPos, LVar2, LVar0, LVar4)
        Call(SetNpcPos, NPC_PARTNER, LVar2, LVar0, LVar5)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};
