#include "end_00.h"
#include "effects.h"

EvtScript N(EVS_JrTroopa_SpinningDodge) = {
    EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_RaiseStaff)
    EVT_WAIT(5 * DT)
    EVT_CALL(MakeLerp, 0, 360, 10 * DT, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_JrTroopa, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_Bowser) = {
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcJumpscale, NPC_JrTroopa, EVT_FLOAT(0.5))
    EVT_CALL(NpcJump1, NPC_JrTroopa, 2010, 0, 0, 20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Run)
    EVT_CALL(NpcMoveTo, NPC_JrTroopa, 1930, 0, 20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Idle)
    EVT_CALL(InterpNpcYaw, NPC_JrTroopa, 90, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_RaiseStaff)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_SwingStaff)
    EVT_PLAY_EFFECT(EFFECT_SHAPE_SPELL, 0, 1930, 0, 0, 2160, 100, 0, 10)
    EVT_WAIT(30 * DT)
    EVT_PLAY_EFFECT(EFFECT_SHAPE_SPELL, 0, 2160, 100, 0, 1930, 0, 0, 10)
    EVT_EXEC(N(EVS_JrTroopa_SpinningDodge))
    EVT_CALL(NpcJump1, NPC_JrTroopa, 1890, 0, 0, 20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Idle)
    EVT_CALL(NpcFlyTo, NPC_Kammy, 2060, 60, 0, 10 * DT, -10, EASING_LINEAR)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0E)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0F)
    EVT_PLAY_EFFECT(EFFECT_SHAPE_SPELL, 0, 2060, 60, 0, 1890, 0, 0, 10)
    EVT_EXEC(N(EVS_JrTroopa_SpinningDodge))
    EVT_CALL(NpcJump1, NPC_JrTroopa, 2040, 0, 0, 20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Idle)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim14)
    EVT_CALL(NpcFlyTo, NPC_Kammy, 1940, 60, 0, 20 * DT, -10, EASING_LINEAR)
    EVT_CALL(InterpNpcYaw, NPC_Kammy, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_JrTroopa, 270, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0E)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0F)
    EVT_PLAY_EFFECT(EFFECT_SHAPE_SPELL, 0, 1940, 60, 0, 2040, 0, 0, 10)
    EVT_EXEC(N(EVS_JrTroopa_SpinningDodge))
    EVT_CALL(NpcJump1, NPC_JrTroopa, 2160, 0, 0, 20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_RaiseStaff)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_SwingStaff)
    EVT_PLAY_EFFECT(EFFECT_SHAPE_SPELL, 0, 2160, 0, 0, 1940, 60, 0, 20)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim14)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, 1940, 60, 0, EVT_FLOAT(0.5), 10)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcPos, NPC_Kammy, 0, -500, 0)
    EVT_PLAY_EFFECT(EFFECT_GATHER_ENERGY_PINK, 0, 2100, 60, 0, EVT_FLOAT(0.5), 10)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcPos, NPC_Kammy, 2100, 60, 0)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0E)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0F)
    EVT_PLAY_EFFECT(EFFECT_SHAPE_SPELL, 0, 2100, 60, 0, 2160, 0, 0, 10)
    EVT_EXEC(N(EVS_JrTroopa_SpinningDodge))
    EVT_CALL(NpcJump1, NPC_JrTroopa, 2100, 0, 0, 20 * DT)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Run)
        EVT_CALL(NpcMoveTo, NPC_JrTroopa, 1900, 0, 50 * DT)
    EVT_END_THREAD
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim14)
    EVT_CALL(InterpNpcYaw, NPC_Kammy, 270, 0)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim12)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim14)
    EVT_CALL(InterpNpcYaw, NPC_Kammy, 90, 0)
    EVT_WAIT(20 * DT)
    EVT_CALL(NpcFlyTo, NPC_Kammy, 1900, 40, 0, 25 * DT, -10, EASING_LINEAR)
    EVT_WAIT(150 * DT)
    EVT_THREAD
        EVT_WAIT(35 * DT)
        EVT_PLAY_EFFECT(EFFECT_SHAPE_SPELL, 0, 2040, 60, -20, 2180, 0, 20, 10)
        EVT_WAIT(35 * DT)
        EVT_CALL(SetNpcPos, NPC_Kammy, 2390, 120, -20)
        EVT_CALL(NpcFlyTo, NPC_Kammy, 2440, 60, -20, 10 * DT, -10, EASING_LINEAR)
        EVT_CALL(InterpNpcYaw, NPC_Kammy, 270, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcPos, NPC_JrTroopa, 2040, 0, 20 * DT)
    EVT_CALL(SetNpcYaw, NPC_JrTroopa, 90)
    EVT_CALL(NpcMoveTo, NPC_JrTroopa, 2400, 20, 90 * DT)
    EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Idle)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_RaiseStaff)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_SwingStaff)
    EVT_PLAY_EFFECT(EFFECT_SHAPE_SPELL, 0, 2400, 0, 20, 2440, 60, -20, 10)
    EVT_THREAD
        EVT_CALL(NpcFlyTo, NPC_Kammy, 2300, 60, -20, 20 * DT, -10, EASING_LINEAR)
        EVT_CALL(InterpNpcYaw, NPC_Kammy, 90, 0)
        EVT_WAIT(20 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0E)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0F)
        EVT_PLAY_EFFECT(EFFECT_SHAPE_SPELL, 0, 2300, 60, -20, 2390, 40, 0, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Run)
        EVT_CALL(NpcMoveTo, NPC_JrTroopa, 2480, 20, 20 * DT)
        EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Idle)
        EVT_CALL(InterpNpcYaw, NPC_JrTroopa, 270, 0)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_RaiseStaff)
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_SwingStaff)
        EVT_PLAY_EFFECT(EFFECT_SHAPE_SPELL, 0, 2480, 0, 20, 2390, 40, 0, 10)
    EVT_END_THREAD
    EVT_WAIT(60 * DT)
    EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, 2390, 40, 5, EVT_FLOAT(5.0), 30)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_HammerBros1, ANIM_ParadeKoopas_Bowser_HammerBrosPanic)
        EVT_CALL(NpcMoveTo, NPC_HammerBros1, 2180, 0, 30 * DT)
        EVT_CALL(SetNpcPos, NPC_HammerBros1, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_HammerBros2, ANIM_ParadeKoopas_Bowser_HammerBrosPanic)
        EVT_CALL(NpcMoveTo, NPC_HammerBros2, 2140, 0, 30 * DT)
        EVT_CALL(SetNpcPos, NPC_HammerBros2, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol1, ANIM_ParadeKoopas_Bowser_KoopatrolPanic)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol1, 2680, 0, 50 * DT)
        EVT_CALL(SetNpcPos, NPC_Koopatrol1, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Koopatrol2, ANIM_ParadeKoopas_Bowser_KoopatrolPanic)
        EVT_CALL(NpcMoveTo, NPC_Koopatrol2, 2720, 0, 50 * DT)
        EVT_CALL(SetNpcPos, NPC_Koopatrol2, 0, -500, 0)
    EVT_END_THREAD
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcPos, NPC_Bowser, 0, -500, 0)
    EVT_CALL(SetNpcPos, NPC_BowserPropeller, 0, -500, 0)
    EVT_CALL(SetNpcPos, NPC_BurntBowser, 2390, 10, 0)
    EVT_CALL(SetNpcPos, NPC_BurntBowserPropeller, 2390, 10, 0)
    EVT_WAIT(60 * DT)
    EVT_CALL(SetNpcAnimation, NPC_BurntBowser, ANIM_ParadeBurntBowser_BurntDrawBack)
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim0C)
        EVT_CALL(NpcFlyTo, NPC_Kammy, 2180, 60, -20, 30 * DT, -10, EASING_LINEAR)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_Run)
        EVT_CALL(NpcMoveTo, NPC_JrTroopa, 2160, 20, 40 * DT)
    EVT_END_THREAD
    EVT_WAIT(40 * DT)
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_BurntBowserPropeller, 2270, 0, 60 * DT)
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_BurntBowser, 2270, 0, 60 * DT)
    EVT_PLAY_EFFECT(EFFECT_FIRE_BREATH, 0, 2270, 40, -5, 2280, 40, -5, 5, 2, 30, 0, 0, 0)
    EVT_WAIT(20 * DT)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_Kammy, ANIM_WorldKammy_Anim07)
        EVT_CALL(SetNpcYaw, NPC_Kammy, 90)
        EVT_CALL(SetNpcPos, NPC_Kammy, 2280, 0, 0)
        EVT_CALL(SetNpcJumpscale, NPC_Kammy, EVT_FLOAT(0.5))
        EVT_CALL(NpcJump1, NPC_Kammy, 2380, 0, 0, 20 * DT)
        EVT_CALL(NpcJump1, NPC_Kammy, 2430, 0, 0, 10 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_JrTroopa, ANIM_MageJrTroopa_BurnStill)
        EVT_CALL(SetNpcYaw, NPC_JrTroopa, 90)
        EVT_CALL(SetNpcPos, NPC_JrTroopa, 2320, 0, 0)
        EVT_CALL(SetNpcJumpscale, NPC_JrTroopa, EVT_FLOAT(0.5))
        EVT_CALL(NpcJump1, NPC_JrTroopa, 2420, 0, 0, 20 * DT)
        EVT_CALL(NpcJump1, NPC_JrTroopa, 2470, 0, 0, 10 * DT)
    EVT_END_THREAD
    EVT_WAIT(30 * DT)
    EVT_SETF(LVar0, 2430)
    EVT_SETF(LVar1, 2470)
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_ADDF(LVar0, EVT_FLOAT(0.8702 / DT))
            EVT_CALL(SetNpcPos, NPC_Kammy, LVar0, 0, 0)
            EVT_ADDF(LVar1, EVT_FLOAT(0.8702 / DT))
            EVT_CALL(SetNpcPos, NPC_JrTroopa, LVar1, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_DONE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(100 * DT)
    EVT_RETURN
    EVT_END
};
