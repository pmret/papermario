#include "end_00.h"
#include "effects.h"

extern EvtScript N(EVS_OffsetNpcScroll);

Vec3f N(D_8024CC00_E03600)[] = {
    { 2050.0,   100.0,    0.0 },
    { 1900.0,    80.0,    0.0 },
    { 1820.0,    70.0,    0.0 },
    { 1800.0,    60.0,    0.0 },
    { 1840.0,    50.0,    0.0 },
};

Vec3f N(D_8024CC3C_E0363C)[] = {
    { 1840.0,    50.0,    0.0 },
    { 1880.0,    60.0,    0.0 },
    { 1860.0,    70.0,    0.0 },
    { 1760.0,   100.0,    0.0 },
    { 1660.0,   170.0,    0.0 },
};

EvtScript N(EVS_ParadePhase_CrystalKing) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_CRYSTAL_KING + 300)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_4D, ANIM_CrystalKing_Anim09)
    EVT_SET(LVar0, 77)
    EVT_EXEC_GET_TID(N(EVS_OffsetNpcScroll), LVarA)
    EVT_WAIT(10)
    EVT_CALL(InterpNpcYaw, NPC_4D, 90, 7)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_4D, ANIM_CrystalKing_Anim10)
    EVT_CALL(SetNpcAnimation, NPC_4E, ANIM_CrystalKing_Anim10)
    EVT_SET(LVar0, 78)
    EVT_EXEC_GET_TID(N(EVS_OffsetNpcScroll), LVarB)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_4E, ANIM_CrystalKing_Anim1C)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_4D, ANIM_CrystalKing_Anim19)
    EVT_WAIT(10)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(GetNpcPos, NPC_4D, LVar0, LVar1, LVar2)
    EVT_CALL(PlayEffect, EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetNpcPos, NPC_4D, 1800, 0, 0)
    EVT_CALL(SetNpcYaw, NPC_4D, 270)
    EVT_CALL(SetNpcAnimation, NPC_4D, ANIM_CrystalKing_Anim0E)
    EVT_CALL(SetNpcPos, NPC_4B, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcJumpscale, NPC_4B, EVT_FLOAT(0.5))
    EVT_ADD(LVar0, -40)
    EVT_CALL(NpcJump1, NPC_4B, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetNpcAnimation, NPC_4B, ANIM_Duplighost_Anim02)
    EVT_SET(LVar0, 75)
    EVT_EXEC_GET_TID(N(EVS_OffsetNpcScroll), LVarA)
    EVT_KILL_THREAD(LVarB)
    EVT_CALL(SetNpcAnimation, NPC_4E, ANIM_CrystalKing_Anim0F)
    EVT_CALL(GetNpcPos, NPC_4E, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -80)
    EVT_CALL(NpcMoveTo, NPC_4E, LVar0, LVar2, 40)
    EVT_SET(LVar0, 78)
    EVT_EXEC_GET_TID(N(EVS_OffsetNpcScroll), LVarB)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_4E, ANIM_CrystalKing_Anim10)
        EVT_WAIT(60)
        EVT_CALL(SetNpcAnimation, NPC_4E, ANIM_CrystalKing_Anim09)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_LOOP(4)
            EVT_CALL(SetNpcAnimation, NPC_4B, ANIM_Duplighost_Anim00)
            EVT_WAIT(10)
            EVT_CALL(SetNpcAnimation, NPC_4B, ANIM_Duplighost_Anim07)
            EVT_WAIT(10)
        EVT_END_LOOP
        EVT_CALL(SetNpcAnimation, NPC_4B, ANIM_Duplighost_Anim02)
    EVT_END_THREAD
    EVT_WAIT(100)
    EVT_CALL(InterpNpcYaw, NPC_4E, 90, 7)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_4E, ANIM_CrystalKing_Anim10)
    EVT_CALL(SetNpcAnimation, NPC_4D, ANIM_CrystalKing_Anim10)
    EVT_SET(LVar0, 77)
    EVT_EXEC_GET_TID(N(EVS_OffsetNpcScroll), LVarC)
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_4D, ANIM_CrystalKing_Anim1C)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_4E, ANIM_CrystalKing_Anim19)
    EVT_WAIT(10)
    EVT_KILL_THREAD(LVarB)
    EVT_CALL(GetNpcPos, NPC_4E, LVar0, LVar1, LVar2)
    EVT_CALL(PlayEffect, EFFECT_BIG_SMOKE_PUFF, LVar0, LVar1, LVar2, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0)
    EVT_CALL(SetNpcPos, NPC_4E, 0, -500, 0)
    EVT_CALL(SetNpcPos, NPC_4C, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcJumpscale, NPC_4C, EVT_FLOAT(0.5))
    EVT_ADD(LVar0, -40)
    EVT_CALL(NpcJump1, NPC_4C, LVar0, LVar1, LVar2, 20)
    EVT_CALL(SetNpcAnimation, NPC_4C, ANIM_Duplighost_Anim02)
    EVT_SET(LVar0, 76)
    EVT_EXEC_GET_TID(N(EVS_OffsetNpcScroll), LVarB)
    EVT_KILL_THREAD(LVarC)
    EVT_CALL(SetNpcAnimation, NPC_4D, ANIM_CrystalKing_Anim0F)
    EVT_CALL(GetNpcPos, NPC_4D, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -80)
    EVT_CALL(NpcMoveTo, NPC_4D, LVar0, LVar2, 40)
    EVT_SET(LVar0, 77)
    EVT_EXEC_GET_TID(N(EVS_OffsetNpcScroll), LVarC)
    EVT_THREAD
        EVT_LOOP(6)
            EVT_CALL(SetNpcAnimation, NPC_4D, ANIM_CrystalKing_Anim10)
            EVT_WAIT(10)
            EVT_CALL(SetNpcAnimation, NPC_4D, ANIM_CrystalKing_Anim11)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_LOOP(4)
            EVT_CALL(SetNpcAnimation, NPC_4B, ANIM_Duplighost_Anim00)
            EVT_CALL(SetNpcAnimation, NPC_4C, ANIM_Duplighost_Anim00)
            EVT_WAIT(10)
            EVT_CALL(SetNpcAnimation, NPC_4B, ANIM_Duplighost_Anim07)
            EVT_CALL(SetNpcAnimation, NPC_4C, ANIM_Duplighost_Anim07)
            EVT_WAIT(10)
        EVT_END_LOOP
        EVT_CALL(SetNpcAnimation, NPC_4B, ANIM_Duplighost_Anim02)
        EVT_CALL(SetNpcAnimation, NPC_4C, ANIM_Duplighost_Anim02)
    EVT_END_THREAD
    EVT_WAIT(60)
    EVT_THREAD
        EVT_CALL(LoadPath, 50, EVT_PTR(N(D_8024CC00_E03600)), 5, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_SET(LVar4, LVar1)
            EVT_ADD(LVar4, -30)
            EVT_SET(LVar5, LVar1)
            EVT_ADD(LVar5, 30)
            EVT_SET(LVar6, LVar2)
            EVT_ADD(LVar6, -25)
            EVT_CALL(SetNpcPos, NPC_4F, LVar5, LVar6, LVar3)
            EVT_CALL(SetNpcPos, NPC_50, LVar1, LVar2, LVar3)
            EVT_CALL(SetNpcPos, NPC_51, LVar4, LVar6, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(50)
    EVT_KILL_THREAD(LVarC)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_4D, ANIM_CrystalKing_Anim19)
        EVT_CALL(LoadPath, 50, EVT_PTR(N(D_8024CC3C_E0363C)), 5, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(GetNextPathPos)
            EVT_SET(LVar4, LVar1)
            EVT_ADD(LVar4, -30)
            EVT_SET(LVar5, LVar1)
            EVT_ADD(LVar5, 30)
            EVT_SET(LVar6, LVar2)
            EVT_ADD(LVar6, -25)
            EVT_CALL(SetNpcPos, NPC_4F, LVar5, LVar6, LVar3)
            EVT_CALL(SetNpcPos, NPC_50, LVar1, LVar2, LVar3)
            EVT_CALL(SetNpcPos, NPC_51, LVar4, LVar6, LVar3)
            EVT_ADD(LVar2, -50)
            EVT_CALL(SetNpcPos, NPC_4D, LVar1, LVar2, LVar3)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar0, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_4B, ANIM_Duplighost_Anim02)
    EVT_CALL(SetNpcAnimation, NPC_4C, ANIM_Duplighost_Anim02)
    EVT_LOOP(50)
        EVT_CALL(NpcFaceNpc, NPC_4B, NPC_4D, 0)
        EVT_CALL(NpcFaceNpc, NPC_4C, NPC_4D, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_4B, ANIM_Duplighost_Anim03)
    EVT_CALL(SetNpcAnimation, NPC_4C, ANIM_Duplighost_Anim03)
    EVT_KILL_THREAD(LVarA)
    EVT_KILL_THREAD(LVarB)
    EVT_RETURN
    EVT_END
};
