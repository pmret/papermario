#include "end_00.h"
#include "effects.h"

EvtScript N(EVS_JrTroopa_SpinningDodge) = {
    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_RaiseStaff)
    Wait(5 * DT)
    Call(MakeLerp, 0, 360, 10 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcRotation, NPC_JrTroopa, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_ParadePhase_Bowser) = {
    Wait(10 * DT)
    Call(SetNpcJumpscale, NPC_JrTroopa, Float(0.5))
    Call(NpcJump1, NPC_JrTroopa, 2010, 0, 0, 20 * DT)
    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Run)
    Call(NpcMoveTo, NPC_JrTroopa, 1930, 0, 20 * DT)
    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Idle)
    Call(InterpNpcYaw, NPC_JrTroopa, 90, 0)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_RaiseStaff)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_SwingStaff)
    PlayEffect(EFFECT_SHAPE_SPELL, 0, 1930, 0, 0, 2160, 100, 0, 10)
    Wait(30 * DT)
    PlayEffect(EFFECT_SHAPE_SPELL, 0, 2160, 100, 0, 1930, 0, 0, 10)
    Exec(N(EVS_JrTroopa_SpinningDodge))
    Call(NpcJump1, NPC_JrTroopa, 1890, 0, 0, 20 * DT)
    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Idle)
    Call(NpcFlyTo, NPC_Kammy, 2060, 60, 0, 10 * DT, -10, EASING_LINEAR)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0E)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0F)
    PlayEffect(EFFECT_SHAPE_SPELL, 0, 2060, 60, 0, 1890, 0, 0, 10)
    Exec(N(EVS_JrTroopa_SpinningDodge))
    Call(NpcJump1, NPC_JrTroopa, 2040, 0, 0, 20 * DT)
    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Idle)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim14)
    Call(NpcFlyTo, NPC_Kammy, 1940, 60, 0, 20 * DT, -10, EASING_LINEAR)
    Call(InterpNpcYaw, NPC_Kammy, 90, 0)
    Call(InterpNpcYaw, NPC_JrTroopa, 270, 0)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0E)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0F)
    PlayEffect(EFFECT_SHAPE_SPELL, 0, 1940, 60, 0, 2040, 0, 0, 10)
    Exec(N(EVS_JrTroopa_SpinningDodge))
    Call(NpcJump1, NPC_JrTroopa, 2160, 0, 0, 20 * DT)
    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Idle)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_RaiseStaff)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_SwingStaff)
    PlayEffect(EFFECT_SHAPE_SPELL, 0, 2160, 0, 0, 1940, 60, 0, 20)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim14)
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 0, 1940, 60, 0, Float(0.5), 10)
    Wait(10 * DT)
    Call(SetNpcPos, NPC_Kammy, 0, -500, 0)
    PlayEffect(EFFECT_GATHER_ENERGY_PINK, 0, 2100, 60, 0, Float(0.5), 10)
    Wait(10 * DT)
    Call(SetNpcPos, NPC_Kammy, 2100, 60, 0)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0E)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0F)
    PlayEffect(EFFECT_SHAPE_SPELL, 0, 2100, 60, 0, 2160, 0, 0, 10)
    Exec(N(EVS_JrTroopa_SpinningDodge))
    Call(NpcJump1, NPC_JrTroopa, 2100, 0, 0, 20 * DT)
    Thread
        Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Run)
        Call(NpcMoveTo, NPC_JrTroopa, 1900, 0, 50 * DT)
    EndThread
    Wait(20 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim14)
    Call(InterpNpcYaw, NPC_Kammy, 270, 0)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim12)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim14)
    Call(InterpNpcYaw, NPC_Kammy, 90, 0)
    Wait(20 * DT)
    Call(NpcFlyTo, NPC_Kammy, 1900, 40, 0, 25 * DT, -10, EASING_LINEAR)
    Wait(150 * DT)
    Thread
        Wait(35 * DT)
        PlayEffect(EFFECT_SHAPE_SPELL, 0, 2040, 60, -20, 2180, 0, 20, 10)
        Wait(35 * DT)
        Call(SetNpcPos, NPC_Kammy, 2390, 120, -20)
        Call(NpcFlyTo, NPC_Kammy, 2440, 60, -20, 10 * DT, -10, EASING_LINEAR)
        Call(InterpNpcYaw, NPC_Kammy, 270, 0)
    EndThread
    Call(SetNpcPos, NPC_JrTroopa, 2040, 0, 20 * DT)
    Call(SetNpcYaw, NPC_JrTroopa, 90)
    Call(NpcMoveTo, NPC_JrTroopa, 2400, 20, 90 * DT)
    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Idle)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_RaiseStaff)
    Wait(10 * DT)
    Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_SwingStaff)
    PlayEffect(EFFECT_SHAPE_SPELL, 0, 2400, 0, 20, 2440, 60, -20, 10)
    Thread
        Call(NpcFlyTo, NPC_Kammy, 2300, 60, -20, 20 * DT, -10, EASING_LINEAR)
        Call(InterpNpcYaw, NPC_Kammy, 90, 0)
        Wait(20 * DT)
        Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0E)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0F)
        PlayEffect(EFFECT_SHAPE_SPELL, 0, 2300, 60, -20, 2390, 40, 0, 10)
    EndThread
    Thread
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Run)
        Call(NpcMoveTo, NPC_JrTroopa, 2480, 20, 20 * DT)
        Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Idle)
        Call(InterpNpcYaw, NPC_JrTroopa, 270, 0)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_RaiseStaff)
        Wait(10 * DT)
        Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_SwingStaff)
        PlayEffect(EFFECT_SHAPE_SPELL, 0, 2480, 0, 20, 2390, 40, 0, 10)
    EndThread
    Wait(60 * DT)
    PlayEffect(EFFECT_RING_BLAST, 0, 2390, 40, 5, Float(5.0), 30)
    Thread
        Call(SetNpcAnimation, NPC_HammerBros1, ANIM_ParadeKoopas_Bowser_HammerBrosPanic)
        Call(NpcMoveTo, NPC_HammerBros1, 2180, 0, 30 * DT)
        Call(SetNpcPos, NPC_HammerBros1, 0, -500, 0)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_HammerBros2, ANIM_ParadeKoopas_Bowser_HammerBrosPanic)
        Call(NpcMoveTo, NPC_HammerBros2, 2140, 0, 30 * DT)
        Call(SetNpcPos, NPC_HammerBros2, 0, -500, 0)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Koopatrol1, ANIM_ParadeKoopas_Bowser_KoopatrolPanic)
        Call(NpcMoveTo, NPC_Koopatrol1, 2680, 0, 50 * DT)
        Call(SetNpcPos, NPC_Koopatrol1, 0, -500, 0)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_Koopatrol2, ANIM_ParadeKoopas_Bowser_KoopatrolPanic)
        Call(NpcMoveTo, NPC_Koopatrol2, 2720, 0, 50 * DT)
        Call(SetNpcPos, NPC_Koopatrol2, 0, -500, 0)
    EndThread
    Wait(10 * DT)
    Call(SetNpcPos, NPC_Bowser, 0, -500, 0)
    Call(SetNpcPos, NPC_BowserPropeller, 0, -500, 0)
    Call(SetNpcPos, NPC_BurntBowser, 2390, 10, 0)
    Call(SetNpcPos, NPC_BurntBowserPropeller, 2390, 10, 0)
    Wait(60 * DT)
    Call(SetNpcAnimation, NPC_BurntBowser, ANIM_ParadeBurntBowser_BurntDrawBack)
    Wait(10 * DT)
    Thread
        Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0C)
        Call(NpcFlyTo, NPC_Kammy, 2180, 60, -20, 30 * DT, -10, EASING_LINEAR)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Run)
        Call(NpcMoveTo, NPC_JrTroopa, 2160, 20, 40 * DT)
    EndThread
    Wait(40 * DT)
    Thread
        Call(NpcMoveTo, NPC_BurntBowserPropeller, 2270, 0, 60 * DT)
    EndThread
    Call(NpcMoveTo, NPC_BurntBowser, 2270, 0, 60 * DT)
    PlayEffect(EFFECT_FIRE_BREATH, 0, 2270, 40, -5, 2280, 40, -5, 5, 2, 30, 0, 0, 0)
    Wait(20 * DT)
    Thread
        Call(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim07)
        Call(SetNpcYaw, NPC_Kammy, 90)
        Call(SetNpcPos, NPC_Kammy, 2280, 0, 0)
        Call(SetNpcJumpscale, NPC_Kammy, Float(0.5))
        Call(NpcJump1, NPC_Kammy, 2380, 0, 0, 20 * DT)
        Call(NpcJump1, NPC_Kammy, 2430, 0, 0, 10 * DT)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_BurnStill)
        Call(SetNpcYaw, NPC_JrTroopa, 90)
        Call(SetNpcPos, NPC_JrTroopa, 2320, 0, 0)
        Call(SetNpcJumpscale, NPC_JrTroopa, Float(0.5))
        Call(NpcJump1, NPC_JrTroopa, 2420, 0, 0, 20 * DT)
        Call(NpcJump1, NPC_JrTroopa, 2470, 0, 0, 10 * DT)
    EndThread
    Wait(30 * DT)
    SetF(LVar0, 2430)
    SetF(LVar1, 2470)
    ChildThread
        Loop(0)
            AddF(LVar0, Float(0.8702 / DT))
            Call(SetNpcPos, NPC_Kammy, LVar0, 0, 0)
            AddF(LVar1, Float(0.8702 / DT))
            Call(SetNpcPos, NPC_JrTroopa, LVar1, 0, 0)
            Wait(1)
        EndLoop
    EndChildThread
    Loop(0)
        Wait(1)
        Call(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        IfGt(LVar0, PARADE_PHASE_DONE)
            BreakLoop
        EndIf
    EndLoop
    Wait(100 * DT)
    Return
    End
};
