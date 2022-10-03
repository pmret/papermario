#include "end_00.h"
#include "effects.h"

EvtScript N(D_8024D780_E04180) = {
    EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_RaiseStaff)
    EVT_WAIT(5)
    EVT_CALL(MakeLerp, 0, 360, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, NPC_53, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_8024D834) = {
    EVT_WAIT(10)
    EVT_CALL(SetNpcJumpscale, NPC_53, EVT_FLOAT(0.5))
    EVT_CALL(NpcJump1, NPC_53, 2010, 0, 0, 20)
    EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_Run)
    EVT_CALL(NpcMoveTo, NPC_53, 1930, 0, 20)
    EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_Idle)
    EVT_CALL(InterpNpcYaw, NPC_53, 90, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_RaiseStaff)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_SwingStaff)
    EVT_CALL(PlayEffect, EFFECT_SHAPE_SPELL, 0, 1930, 0, 0, 2160, 100, 0, 10, 0, 0, 0, 0, 0)
    EVT_WAIT(30)
    EVT_CALL(PlayEffect, EFFECT_SHAPE_SPELL, 0, 2160, 100, 0, 1930, 0, 0, 10, 0, 0, 0, 0, 0)
    EVT_EXEC(N(D_8024D780_E04180))
    EVT_CALL(NpcJump1, NPC_53, 1890, 0, 0, 20)
    EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_Idle)
    EVT_CALL(NpcFlyTo, NPC_52, 2060, 60, 0, 10, -10, EASING_LINEAR)
    EVT_CALL(SetNpcAnimation, NPC_52, ANIM_WorldKammy_Anim0E)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_52, ANIM_WorldKammy_Anim0F)
    EVT_CALL(PlayEffect, EFFECT_SHAPE_SPELL, 0, 2060, 60, 0, 1890, 0, 0, 10, 0, 0, 0, 0, 0)
    EVT_EXEC(N(D_8024D780_E04180))
    EVT_CALL(NpcJump1, NPC_53, 2040, 0, 0, 20)
    EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_Idle)
    EVT_CALL(SetNpcAnimation, NPC_52, ANIM_WorldKammy_Anim14)
    EVT_CALL(NpcFlyTo, NPC_52, 1940, 60, 0, 20, -10, EASING_LINEAR)
    EVT_CALL(InterpNpcYaw, NPC_52, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_53, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_52, ANIM_WorldKammy_Anim0E)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_52, ANIM_WorldKammy_Anim0F)
    EVT_CALL(PlayEffect, EFFECT_SHAPE_SPELL, 0, 0x00000794, 60, 0, 0x000007F8, 0, 0, 10, 0, 0, 0, 0, 0)
    EVT_EXEC(N(D_8024D780_E04180))
    EVT_CALL(NpcJump1, NPC_53, 2160, 0, 0, 20)
    EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_Idle)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_RaiseStaff)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_SwingStaff)
    EVT_CALL(PlayEffect, EFFECT_SHAPE_SPELL, 0, 0x00000870, 0, 0, 0x00000794, 60, 0, 20, 0, 0, 0, 0, 0)
    EVT_CALL(SetNpcAnimation, NPC_52, ANIM_WorldKammy_Anim14)
    EVT_CALL(PlayEffect, EFFECT_GATHER_ENERGY_PINK, 0, 0x00000794, 60, 0, EVT_FLOAT(0.5), 10, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcPos, NPC_52, 0, -500, 0)
    EVT_CALL(PlayEffect, EFFECT_GATHER_ENERGY_PINK, 0, 0x00000834, 60, 0, EVT_FLOAT(0.5), 10, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcPos, NPC_52, 2100, 60, 0)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_52, ANIM_WorldKammy_Anim0E)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_52, ANIM_WorldKammy_Anim0F)
    EVT_CALL(PlayEffect, EFFECT_SHAPE_SPELL, 0, 0x00000834, 60, 0, 0x00000870, 0, 0, 10, 0, 0, 0, 0, 0)
    EVT_EXEC(N(D_8024D780_E04180))
    EVT_CALL(NpcJump1, NPC_53, 2100, 0, 0, 20)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_Run)
        EVT_CALL(NpcMoveTo, NPC_53, 1900, 0, 50)
    EVT_END_THREAD
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_52, ANIM_WorldKammy_Anim14)
    EVT_CALL(InterpNpcYaw, NPC_52, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_52, ANIM_WorldKammy_Anim12)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_52, ANIM_WorldKammy_Anim14)
    EVT_CALL(InterpNpcYaw, NPC_52, 90, 0)
    EVT_WAIT(20)
    EVT_CALL(NpcFlyTo, NPC_52, 1900, 40, 0, 25, -10, EASING_LINEAR)
    EVT_WAIT(150)
    EVT_THREAD
        EVT_WAIT(35)
        EVT_CALL(PlayEffect, EFFECT_SHAPE_SPELL, 0, 0x000007F8, 60, -20, 0x00000884, 0, 20, 10, 0, 0, 0, 0, 0)
        EVT_WAIT(35)
        EVT_CALL(SetNpcPos, NPC_52, 2390, 120, -20)
        EVT_CALL(NpcFlyTo, NPC_52, 2440, 60, -20, 10, -10, EASING_LINEAR)
        EVT_CALL(InterpNpcYaw, NPC_52, 270, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcPos, NPC_53, 2040, 0, 20)
    EVT_CALL(SetNpcYaw, NPC_53, 90)
    EVT_CALL(NpcMoveTo, NPC_53, 2400, 20, 90)
    EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_Idle)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_RaiseStaff)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_SwingStaff)
    EVT_CALL(PlayEffect, EFFECT_SHAPE_SPELL, 0, 0x00000960, 0, 20, 0x00000988, 60, -20, 10, 0, 0, 0, 0, 0)
    EVT_THREAD
        EVT_CALL(NpcFlyTo, NPC_52, 2300, 60, -20, 20, -10, EASING_LINEAR)
        EVT_CALL(InterpNpcYaw, NPC_52, 90, 0)
        EVT_WAIT(20)
        EVT_CALL(SetNpcAnimation, NPC_52, ANIM_WorldKammy_Anim0E)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_52, ANIM_WorldKammy_Anim0F)
        EVT_CALL(PlayEffect, EFFECT_SHAPE_SPELL, 0, 0x000008FC, 60, -20, 0x00000956, 40, 0, 10, 0, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_Run)
        EVT_CALL(NpcMoveTo, NPC_53, 2480, 20, 20)
        EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_Idle)
        EVT_CALL(InterpNpcYaw, NPC_53, 270, 0)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_RaiseStaff)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_SwingStaff)
        EVT_CALL(PlayEffect, EFFECT_SHAPE_SPELL, 0, 0x000009B0, 0, 20, 0x00000956, 40, 0, 10, 0, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_WAIT(60)
    EVT_CALL(PlayEffect, EFFECT_RING_BLAST, 0, 0x00000956, 40, 5, EVT_FLOAT(5.0), 30, 0, 0, 0, 0, 0, 0, 0)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_56, ANIM_ParadeKoopas_Bowser_HammerBrosPanic)
        EVT_CALL(NpcMoveTo, NPC_56, 2180, 0, 30)
        EVT_CALL(SetNpcPos, NPC_56, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_57, ANIM_ParadeKoopas_Bowser_HammerBrosPanic)
        EVT_CALL(NpcMoveTo, NPC_57, 2140, 0, 30)
        EVT_CALL(SetNpcPos, NPC_57, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_58, ANIM_ParadeKoopas_Bowser_KoopatrolPanic)
        EVT_CALL(NpcMoveTo, NPC_58, 2680, 0, 50)
        EVT_CALL(SetNpcPos, NPC_58, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_59, ANIM_ParadeKoopas_Bowser_KoopatrolPanic)
        EVT_CALL(NpcMoveTo, NPC_59, 2720, 0, 50)
        EVT_CALL(SetNpcPos, NPC_59, 0, -500, 0)
    EVT_END_THREAD
    EVT_WAIT(10)
    EVT_CALL(SetNpcPos, NPC_54, 0, -500, 0)
    EVT_CALL(SetNpcPos, NPC_55, 0, -500, 0)
    EVT_CALL(SetNpcPos, NPC_5A, 2390, 10, 0)
    EVT_CALL(SetNpcPos, NPC_5B, 2390, 10, 0)
    EVT_WAIT(60)
    EVT_CALL(SetNpcAnimation, NPC_5A, ANIM_ParadeBurntBowser_BurntDrawBack)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_52, ANIM_WorldKammy_Anim0C)
        EVT_CALL(NpcFlyTo, NPC_52, 2180, 60, -20, 30, -10, EASING_LINEAR)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_Run)
        EVT_CALL(NpcMoveTo, NPC_53, 2160, 20, 40)
    EVT_END_THREAD
    EVT_WAIT(40)
    EVT_THREAD
        EVT_CALL(NpcMoveTo, NPC_5B, 2270, 0, 60)
    EVT_END_THREAD
    EVT_CALL(NpcMoveTo, NPC_5A, 2270, 0, 60)
    EVT_CALL(PlayEffect, EFFECT_FIRE_BREATH, 0, 0x000008DE, 40, -5, 0x000008E8, 40, -5, 5, 2, 30, 0, 0, 0)
    EVT_WAIT(20)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_52, ANIM_WorldKammy_Anim07)
        EVT_CALL(SetNpcYaw, NPC_52, 90)
        EVT_CALL(SetNpcPos, NPC_52, 2280, 0, 0)
        EVT_CALL(SetNpcJumpscale, NPC_52, EVT_FLOAT(0.5))
        EVT_CALL(NpcJump1, NPC_52, 2380, 0, 0, 20)
        EVT_CALL(NpcJump1, NPC_52, 2430, 0, 0, 10)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_53, ANIM_MageJrTroopa_BurnStill)
        EVT_CALL(SetNpcYaw, NPC_53, 90)
        EVT_CALL(SetNpcPos, NPC_53, 2320, 0, 0)
        EVT_CALL(SetNpcJumpscale, NPC_53, EVT_FLOAT(0.5))
        EVT_CALL(NpcJump1, NPC_53, 2420, 0, 0, 20)
        EVT_CALL(NpcJump1, NPC_53, 2470, 0, 0, 10)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_SETF(LVar0, 0x0000097E)
    EVT_SETF(LVar1, 0x000009A6)
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_ADDF(LVar0, EVT_FLOAT(0.87))
            EVT_CALL(SetNpcPos, NPC_52, LVar0, 0, 0)
            EVT_ADDF(LVar1, EVT_FLOAT(0.87))
            EVT_CALL(SetNpcPos, NPC_53, LVar1, 0, 0)
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0x00000A14)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};
