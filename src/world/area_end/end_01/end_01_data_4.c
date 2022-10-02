#include "end_01.h"

API_CALLABLE(N(UnkFunc26));
API_CALLABLE(N(UnkFunc27));
API_CALLABLE(N(func_80242840_E07BA0));

extern EvtScript N(EVS_80244180);

EvtScript N(D_80246D60_E0C0C0) = {
    EVT_CALL(EnableTexPanning, MODEL_omo1, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_omo4, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_omo6, TRUE)
    EVT_SET(LVar1, LVar0)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x1000)
        EVT_CALL(SetTexPanOffset, 9, 1, LVar0, LVar0)
        EVT_WAIT(LVar1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80246E18_E0C178) = {
    EVT_CALL(EnableTexPanning, MODEL_omo8, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_omo13, TRUE)
    EVT_SET(LVar0, 0)
    EVT_LOOP(0)
        EVT_ADD(LVar0, 0x4000)
        EVT_CALL(SetTexPanOffset, 8, 0, LVar0, LVar0)
        EVT_WAIT(6)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

s32 N(D_80246EAC_E0C20C) = {
    56, 58, 59, 60, 61, 62, 63, 0x0000FFFF 
};

EvtScript N(D_80246ECC_E0C22C) = {
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, -90, 30, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_h2, LVar0, 1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 30, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(RotateGroup, MODEL_h3, LVar0, 1, 0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(N(UnkFunc27), 0, EVT_PTR(N(D_80246EAC_E0C20C)), 3)
    EVT_CALL(N(UnkFunc26), 3, 255, 255, 255, 120, 120, 80, 0, 0, 0)
    EVT_WAIT(30)
    EVT_CALL(N(UnkFunc26), 3, 255, 255, 255, 0, 0, 0, 0, 0, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80247098_E0C3F8) = {
    EVT_SET(LVar0, 270)
    EVT_LOOP(0)
        EVT_IF_EQ(LVar0, 270)
            EVT_SET(LVar0, 90)
        EVT_ELSE
            EVT_SET(LVar0, 270)
        EVT_END_IF
        EVT_CALL(SetNpcAnimation, NPC_1D, ANIM_ParadeShyGuy_GeneralStill)
        EVT_CALL(InterpNpcYaw, NPC_1D, LVar0, 0)
        EVT_WAIT(10)
        EVT_CALL(SetNpcAnimation, NPC_1D, ANIM_ParadeShyGuy_GeneralPoint)
        EVT_WAIT(20)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80247164_E0C4C4) = {
    EVT_SET(LVar2, LVar0)
    EVT_LOOP(0)
        EVT_LOOP(3)
            EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_StackLand)
            EVT_WAIT(10)
            EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_StackHold)
            EVT_WAIT(10)
        EVT_END_LOOP
        EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_StackPointUp)
        EVT_WAIT(10)
        EVT_CALL(MakeLerp, 0, 360, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, LVar2, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024729C_E0C5FC) = {
    EVT_WAIT(30)
    EVT_SET(LVar2, LVar0)
    EVT_SET(LVar3, LVar1)
    EVT_CALL(SetNpcJumpscale, LVar2, EVT_FLOAT(0.5))
    EVT_CALL(NpcJump0, LVar2, LVar3, 10, 20, 20)
    EVT_WAIT(10)
    EVT_LOOP(0)
        EVT_LOOP(2)
            EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_GrooveLeanLeft)
            EVT_WAIT(5)
            EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_GroovePivot)
            EVT_WAIT(5)
            EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_GrooveLeanRight)
            EVT_WAIT(5)
            EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_GroovePivot)
            EVT_WAIT(5)
        EVT_END_LOOP
        EVT_CALL(MakeLerp, 0, 360, 10, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, LVar2, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80247450_E0C7B0) = {
    EVT_EXEC_GET_TID(N(D_80247098_E0C3F8), LVar7)
    EVT_SET(LVar0, 30)
    EVT_EXEC_GET_TID(N(D_80247164_E0C4C4), LVar8)
    EVT_SET(LVar0, 31)
    EVT_EXEC_GET_TID(N(D_80247164_E0C4C4), LVar9)
    EVT_SET(LVar0, 32)
    EVT_SET(LVar1, 0xFFFFFA1C)
    EVT_EXEC_GET_TID(N(D_8024729C_E0C5FC), LVarA)
    EVT_SET(LVar0, 33)
    EVT_SET(LVar1, 0xFFFFFA44)
    EVT_EXEC_GET_TID(N(D_8024729C_E0C5FC), LVarB)
    EVT_SET(LVar0, 34)
    EVT_SET(LVar1, 0xFFFFFA6C)
    EVT_EXEC_GET_TID(N(D_8024729C_E0C5FC), LVarC)
    EVT_SET(LVar0, 35)
    EVT_SET(LVar1, 0xFFFFFA94)
    EVT_EXEC_GET_TID(N(D_8024729C_E0C5FC), LVarD)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFFB66)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVar7)
    EVT_KILL_THREAD(LVar8)
    EVT_KILL_THREAD(LVar9)
    EVT_KILL_THREAD(LVarA)
    EVT_KILL_THREAD(LVarB)
    EVT_KILL_THREAD(LVarC)
    EVT_KILL_THREAD(LVarD)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80247620) = {
    EVT_SET(LVar0, 4)
    EVT_EXEC_GET_TID(N(D_80246D60_E0C0C0), LVarA)
    EVT_EXEC_GET_TID(N(D_80246E18_E0C178), LVarB)
    EVT_WAIT(10)
    EVT_CALL(NpcMoveTo, NPC_1C, -1648, 0, 50)
    EVT_CALL(SetNpcAnimation, NPC_1C, ANIM_ParadeShyGuy_MarshallStill)
    EVT_CALL(InterpNpcYaw, NPC_1C, 90, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_1C, ANIM_ParadeShyGuy_MarshallBeckon)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFFA12)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_1C, ANIM_ParadeShyGuy_MarshallWalk)
        EVT_CALL(NpcMoveTo, NPC_1C, -1748, 0, 50)
    EVT_END_THREAD
    EVT_EXEC(N(D_80247450_E0C7B0))
    EVT_KILL_THREAD(LVarA)
    EVT_SET(LVar0, 2)
    EVT_EXEC_GET_TID(N(D_80246D60_E0C0C0), LVarA)
    EVT_EXEC_WAIT(N(D_80246ECC_E0C22C))
    EVT_KILL_THREAD(LVarA)
    EVT_SET(LVar0, 4)
    EVT_EXEC_GET_TID(N(D_80246D60_E0C0C0), LVarA)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0xFFFFFB66)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_KILL_THREAD(LVarB)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80247854_E0CBB4) = {
    EVT_CALL(GetNpcPos, NPC_26, LVar0, LVar1, LVar2)
    EVT_SETF(LVar0, LVar0)
    EVT_SETF(LVar1, LVar0)
    EVT_ADDF(LVar1, 30)
    EVT_SETF(LVar2, LVar0)
    EVT_ADDF(LVar2, 60)
    EVT_SETF(LVar3, LVar0)
    EVT_ADDF(LVar3, 90)
    EVT_CALL(SetNpcPos, NPC_26, LVar0, 0, -30)
    EVT_CALL(SetNpcPos, NPC_27, LVar0, 0, 0)
    EVT_CALL(SetNpcPos, NPC_28, LVar0, 0, 30)
    EVT_CALL(SetNpcPos, NPC_29, LVar1, 0, -30)
    EVT_CALL(SetNpcPos, NPC_2A, LVar1, 0, 0)
    EVT_CALL(SetNpcPos, NPC_2B, LVar1, 0, 30)
    EVT_CALL(SetNpcPos, NPC_2C, LVar2, 0, -30)
    EVT_CALL(SetNpcPos, NPC_2D, LVar2, 0, 0)
    EVT_CALL(SetNpcPos, NPC_2E, LVar2, 0, 30)
    EVT_CALL(SetNpcPos, NPC_2F, LVar3, 0, -30)
    EVT_CALL(SetNpcPos, NPC_30, LVar3, 0, 0)
    EVT_CALL(SetNpcPos, NPC_31, LVar3, 0, 30)
    EVT_CHILD_THREAD
        EVT_CALL(N(func_80242840_E07BA0), 39)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(func_80242840_E07BA0), 40)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(func_80242840_E07BA0), 41)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(func_80242840_E07BA0), 42)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(func_80242840_E07BA0), 43)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(func_80242840_E07BA0), 44)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(func_80242840_E07BA0), 45)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(func_80242840_E07BA0), 46)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(func_80242840_E07BA0), 47)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(func_80242840_E07BA0), 48)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(func_80242840_E07BA0), 49)
    EVT_END_CHILD_THREAD
    EVT_CALL(N(func_80242840_E07BA0), 38)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80247BB0_E0CF10) = {
    EVT_CALL(GetNpcPos, LVar0, LVar2, LVar3, LVar4)
    EVT_ADD(LVar2, -180)
    EVT_CALL(NpcMoveTo, LVar0, LVar2, LVar4, 90)
    EVT_SET(LVar2, LVar0)
    EVT_SET(LVar3, 28)
    EVT_SUB(LVar3, LVar1)
    EVT_ADD(LVar1, 10)
    EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_ShadeStill)
    EVT_WAIT(LVar1)
    EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_ShadePointUp)
    EVT_CALL(MakeLerp, 0, 360, 10, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcRotation, LVar2, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_WAIT(LVar3)
    EVT_CALL(SetNpcAnimation, LVar2, ANIM_ParadeShyGuy_ShadeWalk)
    EVT_CALL(GetNpcPos, LVar2, LVar3, LVar4, LVar5)
    EVT_ADD(LVar3, -180)
    EVT_CALL(NpcMoveTo, LVar2, LVar3, LVar5, 90)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80247D68) = {
    EVT_SET(LVar1, 0)
    EVT_SET(LVar0, 38)
    EVT_EXEC(N(D_80247BB0_E0CF10))
    EVT_SET(LVar0, 39)
    EVT_EXEC(N(D_80247BB0_E0CF10))
    EVT_SET(LVar0, 40)
    EVT_EXEC(N(D_80247BB0_E0CF10))
    EVT_SET(LVar1, 8)
    EVT_SET(LVar0, 41)
    EVT_EXEC(N(D_80247BB0_E0CF10))
    EVT_SET(LVar0, 42)
    EVT_EXEC(N(D_80247BB0_E0CF10))
    EVT_SET(LVar0, 43)
    EVT_EXEC(N(D_80247BB0_E0CF10))
    EVT_SET(LVar1, 10)
    EVT_SET(LVar0, 44)
    EVT_EXEC(N(D_80247BB0_E0CF10))
    EVT_SET(LVar0, 45)
    EVT_EXEC(N(D_80247BB0_E0CF10))
    EVT_SET(LVar0, 46)
    EVT_EXEC(N(D_80247BB0_E0CF10))
    EVT_SET(LVar1, 18)
    EVT_SET(LVar0, 47)
    EVT_EXEC(N(D_80247BB0_E0CF10))
    EVT_SET(LVar0, 48)
    EVT_EXEC(N(D_80247BB0_E0CF10))
    EVT_SET(LVar0, 49)
    EVT_EXEC(N(D_80247BB0_E0CF10))
    EVT_WAIT(90)
    EVT_EXEC_GET_TID(N(D_80247854_E0CBB4), LVarA)
    EVT_WAIT(48)
    EVT_KILL_THREAD(LVarA)
    EVT_WAIT(130)
    EVT_CALL(GetNpcPos, NPC_32, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -180)
    EVT_CALL(NpcMoveTo, NPC_32, LVar0, LVar2, 45)
    EVT_CALL(func_802CDE68, 50, 10)
    EVT_THREAD
        EVT_SET(LVar0, 0)
        EVT_LOOP(10)
            EVT_ADD(LVar0, 9)
            EVT_CALL(SetNpcRotation, NPC_32, 0, 0, LVar0)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(SetNpcRotation, NPC_32, 0, 0, 0)
        EVT_CALL(SetNpcAnimation, NPC_32, ANIM_ShyGuy_Red_Anim10)
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_32, EVT_FLOAT(1.0))
    EVT_CALL(GetNpcPos, NPC_32, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -45)
    EVT_CALL(NpcJump0, NPC_32, LVar0, LVar1, LVar2, 10)
    EVT_SET(LVar0, 50)
    EVT_EXEC_GET_TID(N(EVS_80244180), LVarA)
    EVT_WAIT(80)
    EVT_CALL(func_802CDE68, 50, 0)
    EVT_KILL_THREAD(LVarA)
    EVT_CALL(SetNpcAnimation, NPC_32, ANIM_ShyGuy_Red_Anim01)
    EVT_CALL(GetNpcPos, NPC_32, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -5)
    EVT_CALL(NpcJump0, NPC_32, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SetNpcAnimation, NPC_32, ANIM_ShyGuy_Red_Anim04)
    EVT_CALL(GetNpcPos, NPC_32, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -180)
    EVT_CALL(NpcMoveTo, NPC_32, LVar0, LVar2, 90)
    EVT_RETURN
    EVT_END
};
