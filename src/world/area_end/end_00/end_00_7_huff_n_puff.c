#include "end_00.h"
#include "effects.h"

extern EvtScript N(EVS_SetNpcShadowScale);
extern EvtScript N(EVS_OffsetNpcScroll);

API_CALLABLE(N(AddScrollToNpcPos));

EvtScript N(D_8024AFE0_E019E0) = {
    EVT_CALL(GetNpcPos, NPC_40, LVar0, LVar1, LVar2)
    EVT_SETF(LVar0, LVar0)
    EVT_SETF(LVar3, LVar0)
    EVT_SUBF(LVar3, 40)
    EVT_SETF(LVar4, LVar0)
    EVT_SUBF(LVar4, 80)
    EVT_SETF(LVar5, LVar0)
    EVT_SUBF(LVar5, 120)
    EVT_SETF(LVar6, LVar0)
    EVT_SUBF(LVar6, 160)
    EVT_CALL(SetNpcPos, NPC_40, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_41, LVar3, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_42, LVar4, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_43, LVar5, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_44, LVar6, LVar1, LVar2)
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), 65)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), 66)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), 67)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), 68)
    EVT_END_CHILD_THREAD
    EVT_CALL(N(AddScrollToNpcPos), 64)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B1B8_E01BB8) = {
    EVT_CALL(GetNpcPos, NPC_45, LVar0, LVar1, LVar2)
    EVT_SETF(LVar0, LVar0)
    EVT_SETF(LVar3, LVar0)
    EVT_ADDF(LVar3, 80)
    EVT_SETF(LVar4, LVar0)
    EVT_SUBF(LVar4, 80)
    EVT_CALL(SetNpcPos, NPC_45, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_46, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_47, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_48, LVar3, 60, 0)
    EVT_CALL(SetNpcPos, NPC_49, LVar4, 60, 0)
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_46)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_47)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_48)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_49)
    EVT_END_CHILD_THREAD
    EVT_CALL(N(AddScrollToNpcPos), NPC_45)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B350_E01D50) = {
    EVT_CALL(SetNpcAnimation, NPC_45, ANIM_HuffNPuff_Anim26)
    EVT_CALL(SetNpcAnimation, NPC_46, ANIM_HuffNPuff_Anim27)
    EVT_CALL(SetNpcAnimation, NPC_47, ANIM_HuffNPuff_Anim28)
    EVT_CALL(SetNpcAnimation, NPC_48, ANIM_TuffPuff_Blush)
    EVT_CALL(SetNpcAnimation, NPC_49, ANIM_TuffPuff_Blush)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B3C4_E01DC4) = {
    EVT_CALL(SetNpcAnimation, NPC_45, ANIM_HuffNPuff_Anim07)
    EVT_CALL(SetNpcAnimation, NPC_46, ANIM_HuffNPuff_Anim08)
    EVT_CALL(SetNpcAnimation, NPC_47, ANIM_HuffNPuff_Anim09)
    EVT_CALL(SetNpcAnimation, NPC_48, ANIM_TuffPuff_Hurt)
    EVT_CALL(SetNpcAnimation, NPC_49, ANIM_TuffPuff_Hurt)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B438_E01E38) = {
    EVT_CALL(GetNpcPos, NPC_45, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar0)
    EVT_ADD(LVar3, 80)
    EVT_SET(LVar4, LVar0)
    EVT_ADD(LVar4, -80)
    EVT_LOOP(10)
        EVT_ADD(LVar0, -2)
        EVT_CALL(SetNpcPos, NPC_45, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_46, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_47, LVar0, LVar1, LVar2)
        EVT_ADD(LVar3, -2)
        EVT_CALL(SetNpcPos, NPC_48, LVar3, 60, 0)
        EVT_ADD(LVar4, -2)
        EVT_CALL(SetNpcPos, NPC_49, LVar4, 60, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B580_E01F80) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcPos, NPC_40, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0x00000424)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(GetNpcPos, NPC_49, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcSpeed, NPC_4A, EVT_FLOAT(1.0))
    EVT_CALL(NpcMoveTo, NPC_4A, LVar0, -20, 0)
    EVT_CALL(SetNpcAnimation, NPC_4A, ANIM_GourmetGuy_Idle)
    EVT_CALL(N(AddScrollToNpcPos), 74)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024B65C_E0205C) = {
    EVT_CALL(N(AddScrollToNpcPos), NPC_4A)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_YoshiKids) = {
    EVT_WAIT(20)
    EVT_CALL(SetNpcJumpscale, NPC_40, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_40, 680, 0, 0, 20)
    EVT_CALL(NpcJump0, NPC_40, 740, 0, 0, 10)
    EVT_CALL(SetNpcAnimation, NPC_40, ANIM_YoshiKid_Green_Idle)
    EVT_LOOP(2)
        EVT_CALL(InterpNpcYaw, NPC_40, 270, 7)
        EVT_WAIT(10)
        EVT_CALL(InterpNpcYaw, NPC_40, 90, 7)
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_CALL(InterpNpcYaw, NPC_40, 270, 7)
    EVT_WAIT(10)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_40, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_40, LVar0, LVar1, LVar2, 7)
        EVT_CALL(SetNpcAnimation, NPC_40, ANIM_YoshiKid_Green_Run)
        EVT_CALL(NpcMoveTo, NPC_40, 980, 0, 60)
        EVT_CALL(SetNpcAnimation, NPC_40, ANIM_YoshiKid_Green_LookUp)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_41, 660, 0, 0)
        EVT_CALL(NpcMoveTo, NPC_41, 940, 0, 70)
        EVT_CALL(SetNpcAnimation, NPC_41, ANIM_YoshiKid_Blue_LookUp)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetNpcPos, NPC_42, 660, 0, 0)
        EVT_CALL(NpcMoveTo, NPC_42, 900, 0, 60)
        EVT_CALL(SetNpcAnimation, NPC_42, ANIM_YoshiKid_Purple_LookUp)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20)
        EVT_CALL(SetNpcPos, NPC_43, 660, 0, 0)
        EVT_CALL(NpcMoveTo, NPC_43, 860, 0, 50)
        EVT_CALL(SetNpcAnimation, NPC_43, ANIM_YoshiKid_Yellow_LookUp)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(30)
        EVT_CALL(SetNpcPos, NPC_44, 660, 0, 0)
        EVT_CALL(NpcMoveTo, NPC_44, 820, 0, 40)
        EVT_CALL(SetNpcAnimation, NPC_44, ANIM_YoshiKid_Red_LookUp)
    EVT_END_THREAD
    EVT_WAIT(70)
    EVT_EXEC_GET_TID(N(D_8024AFE0_E019E0), LVarA)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcPos, NPC_40, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0x00000424)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_40, ANIM_YoshiKid_Green_Idle)
    EVT_CALL(SetNpcAnimation, NPC_41, ANIM_YoshiKid_Blue_Idle)
    EVT_CALL(SetNpcAnimation, NPC_42, ANIM_YoshiKid_Purple_Idle)
    EVT_CALL(SetNpcAnimation, NPC_43, ANIM_YoshiKid_Yellow_Idle)
    EVT_CALL(SetNpcAnimation, NPC_44, ANIM_YoshiKid_Red_Idle)
    EVT_CALL(InterpNpcYaw, NPC_40, 270, 0)
    EVT_WAIT(5)
    EVT_LOOP(3)
        EVT_CALL(InterpNpcYaw, NPC_42, 270, 0)
        EVT_WAIT(5)
        EVT_CALL(InterpNpcYaw, NPC_41, 270, 0)
        EVT_WAIT(5)
        EVT_CALL(InterpNpcYaw, NPC_43, 270, 0)
        EVT_WAIT(5)
        EVT_CALL(InterpNpcYaw, NPC_42, 90, 0)
        EVT_WAIT(5)
        EVT_CALL(InterpNpcYaw, NPC_41, 90, 0)
        EVT_WAIT(5)
        EVT_CALL(InterpNpcYaw, NPC_43, 90, 0)
        EVT_WAIT(5)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_HUFF_PUFF + 310)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcYaw, NPC_40, 270)
    EVT_CALL(SetNpcAnimation, NPC_40, ANIM_YoshiKid_Green_EatMiss)
    EVT_CALL(SetNpcYaw, NPC_41, 270)
    EVT_CALL(SetNpcAnimation, NPC_41, ANIM_YoshiKid_Blue_EatMiss)
    EVT_CALL(SetNpcYaw, NPC_42, 90)
    EVT_CALL(SetNpcAnimation, NPC_42, ANIM_YoshiKid_Purple_EatMiss)
    EVT_CALL(SetNpcYaw, NPC_43, 90)
    EVT_CALL(SetNpcAnimation, NPC_43, ANIM_YoshiKid_Yellow_EatMiss)
    EVT_CALL(SetNpcYaw, NPC_44, 90)
    EVT_CALL(SetNpcAnimation, NPC_44, ANIM_YoshiKid_Red_EatMiss)
    EVT_WAIT(10)
    EVT_EXEC(N(D_8024B3C4_E01DC4))
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_45, LVar0, LVar1, LVar2)
        EVT_CALL(PlayEffect, EFFECT_SMOKE_RING, 0, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(GetNpcPos, NPC_48, LVar0, LVar1, LVar2)
        EVT_CALL(PlayEffect, EFFECT_SMOKE_RING, 0, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(GetNpcPos, NPC_49, LVar0, LVar1, LVar2)
        EVT_CALL(PlayEffect, EFFECT_SMOKE_RING, 0, LVar0, LVar1, LVar2, 0, 0, 0, 0, 0, 0, 0, 0, 0)
        EVT_CALL(MakeLerp, 750, 375, 5, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVar2, LVar0)
            EVT_DIVF(LVar2, 1000)
            EVT_CALL(SetNpcScale, NPC_45, LVar2, LVar2, 1)
            EVT_CALL(SetNpcScale, NPC_46, LVar2, LVar2, 1)
            EVT_CALL(SetNpcScale, NPC_47, LVar2, LVar2, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 100, 50, 5, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVar2, LVar0)
            EVT_DIVF(LVar2, 100)
            EVT_CALL(SetNpcScale, NPC_48, LVar2, LVar2, 1)
            EVT_CALL(SetNpcScale, NPC_49, LVar2, LVar2, 1)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(MakeLerp, 600, 300, 5, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVar2, LVar0)
            EVT_DIVF(LVar2, 100)
            EVT_SET(LVar0, 69)
            EVT_EXEC(N(EVS_SetNpcShadowScale))
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_WAIT(40)
    EVT_CALL(SetNpcAnimation, NPC_40, ANIM_YoshiKid_Green_Exhale)
    EVT_CALL(SetNpcAnimation, NPC_41, ANIM_YoshiKid_Blue_Exhale)
    EVT_CALL(SetNpcAnimation, NPC_42, ANIM_YoshiKid_Purple_Exhale)
    EVT_CALL(SetNpcAnimation, NPC_43, ANIM_YoshiKid_Yellow_Exhale)
    EVT_CALL(SetNpcAnimation, NPC_44, ANIM_YoshiKid_Red_Exhale)
    EVT_WAIT(50)
    EVT_KILL_THREAD(LVarA)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_40, ANIM_YoshiKid_Green_Run)
        EVT_CALL(GetNpcPos, NPC_40, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 300)
        EVT_CALL(NpcMoveTo, NPC_40, LVar0, LVar2, 75)
        EVT_CALL(SetNpcPos, NPC_40, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_41, ANIM_YoshiKid_Blue_Run)
        EVT_CALL(GetNpcPos, NPC_41, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 300)
        EVT_CALL(NpcMoveTo, NPC_41, LVar0, LVar2, 75)
        EVT_CALL(SetNpcPos, NPC_41, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_42, ANIM_YoshiKid_Purple_Run)
        EVT_CALL(GetNpcPos, NPC_42, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 300)
        EVT_CALL(NpcMoveTo, NPC_42, LVar0, LVar2, 75)
        EVT_CALL(SetNpcPos, NPC_42, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_43, ANIM_YoshiKid_Yellow_Run)
        EVT_CALL(GetNpcPos, NPC_43, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 300)
        EVT_CALL(NpcMoveTo, NPC_43, LVar0, LVar2, 75)
        EVT_CALL(SetNpcPos, NPC_43, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_44, ANIM_YoshiKid_Red_Run)
        EVT_CALL(GetNpcPos, NPC_44, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 300)
        EVT_CALL(NpcMoveTo, NPC_44, LVar0, LVar2, 75)
        EVT_CALL(SetNpcPos, NPC_44, 0, -500, 0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ParadePhase_HuffNPuff) = {
    EVT_THREAD
        EVT_LOOP(0)
            EVT_WAIT(1)
            EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
            EVT_IF_GT(LVar0, PARADE_PHASE_HUFF_PUFF + 50)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_WAIT(10)
        EVT_CALL(SetNpcFlagBits, NPC_45, NPC_FLAG_400000, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_46, NPC_FLAG_400000, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_47, NPC_FLAG_400000, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_48, NPC_FLAG_400000, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_49, NPC_FLAG_400000, FALSE)
        EVT_CALL(SetNpcScale, NPC_45, EVT_FLOAT(0.75), EVT_FLOAT(0.75), 1)
        EVT_CALL(SetNpcScale, NPC_46, EVT_FLOAT(0.75), EVT_FLOAT(0.75), 1)
        EVT_CALL(SetNpcScale, NPC_47, EVT_FLOAT(0.75), EVT_FLOAT(0.75), 1)
        EVT_CALL(EnableNpcShadow, NPC_46, FALSE)
        EVT_CALL(EnableNpcShadow, NPC_47, FALSE)
    EVT_END_THREAD
    EVT_EXEC(N(EVS_YoshiKids))
    EVT_EXEC_GET_TID(N(D_8024B580_E01F80), LVarB)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_HUFF_PUFF + 310)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC_GET_TID(N(D_8024B1B8_E01BB8), LVarA)
    EVT_WAIT(10)
    EVT_KILL_THREAD(LVarB)
    EVT_CALL(SetNpcAnimation, NPC_4A, ANIM_GourmetGuy_Leap)
    EVT_CALL(GetNpcPos, NPC_4A, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_4A, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SetNpcAnimation, NPC_4A, ANIM_GourmetGuy_TalkSurprise)
    EVT_EXEC_GET_TID(N(D_8024B65C_E0205C), LVarB)
    EVT_WAIT(130)
    EVT_EXEC(N(D_8024B350_E01D50))
    EVT_WAIT(30)
    EVT_CALL(InterpNpcYaw, NPC_45, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_46, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_47, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_48, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_49, 90, 0)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 3, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_4A, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcAnimation, NPC_4A, ANIM_GourmetGuy_Still)
        EVT_CALL(MakeLerp, 270, 360, 3, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_4A, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcAnimation, NPC_4A, ANIM_GourmetGuy_Idle)
    EVT_END_THREAD
    EVT_WAIT(6)
    EVT_LOOP(2)
        EVT_EXEC(N(D_8024B3C4_E01DC4))
        EVT_KILL_THREAD(LVarA)
        EVT_EXEC_WAIT(N(D_8024B438_E01E38))
        EVT_EXEC(N(D_8024B350_E01D50))
        EVT_EXEC_GET_TID(N(D_8024B1B8_E01BB8), LVarA)
        EVT_WAIT(10)
        EVT_KILL_THREAD(LVarB)
        EVT_CALL(SetNpcAnimation, NPC_4A, ANIM_GourmetGuy_Walk)
        EVT_CALL(GetNpcPos, NPC_4A, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -20)
        EVT_CALL(NpcMoveTo, NPC_4A, LVar0, LVar2, 10)
        EVT_CALL(SetNpcAnimation, NPC_4A, ANIM_GourmetGuy_Idle)
        EVT_EXEC_GET_TID(N(D_8024B65C_E0205C), LVarB)
        EVT_WAIT(10)
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_45, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_45, LVar0, LVar1, LVar2, 10)
        EVT_ADD(LVar0, -200)
        EVT_CALL(NpcMoveTo, NPC_45, LVar0, LVar2, 50)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_46, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_46, LVar0, LVar1, LVar2, 10)
        EVT_ADD(LVar0, -200)
        EVT_CALL(NpcMoveTo, NPC_46, LVar0, LVar2, 50)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_47, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_47, LVar0, LVar1, LVar2, 10)
        EVT_ADD(LVar0, -200)
        EVT_CALL(NpcMoveTo, NPC_47, LVar0, LVar2, 50)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_48, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_48, LVar0, LVar1, LVar2, 10)
        EVT_ADD(LVar0, -200)
        EVT_CALL(NpcMoveTo, NPC_48, LVar0, LVar2, 50)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_49, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_49, LVar0, LVar1, LVar2, 10)
        EVT_ADD(LVar0, -200)
        EVT_CALL(NpcMoveTo, NPC_49, LVar0, LVar2, 50)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_4A, ANIM_GourmetGuy_Inspect)
    EVT_WAIT(10)
    EVT_CALL(SetNpcAnimation, NPC_4A, ANIM_GourmetGuy_Walk)
    EVT_KILL_THREAD(LVarB)
    EVT_CALL(GetNpcPos, NPC_4A, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -300)
    EVT_CALL(NpcMoveTo, NPC_4A, LVar0, LVar2, 50)
    EVT_RETURN
    EVT_END
};
