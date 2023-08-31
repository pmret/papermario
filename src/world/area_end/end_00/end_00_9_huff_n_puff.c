#include "end_00.h"
#include "effects.h"

extern EvtScript N(EVS_SetNpcShadowScale);

EvtScript N(EVS_HoldPosition_Yoshis) = {
    EVT_CALL(GetNpcPos, NPC_YoshiKidGreen, LVar0, LVar1, LVar2)
    EVT_SETF(LVar0, LVar0)
    EVT_SETF(LVar3, LVar0)
    EVT_SUBF(LVar3, 40)
    EVT_SETF(LVar4, LVar0)
    EVT_SUBF(LVar4, 80)
    EVT_SETF(LVar5, LVar0)
    EVT_SUBF(LVar5, 120)
    EVT_SETF(LVar6, LVar0)
    EVT_SUBF(LVar6, 160)
    EVT_CALL(SetNpcPos, NPC_YoshiKidGreen, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_YoshiKidBlue, LVar3, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_YoshiKidPurple, LVar4, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_YoshiKidYellow, LVar5, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_YoshiKidRed, LVar6, LVar1, LVar2)
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_YoshiKidBlue)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_YoshiKidPurple)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_YoshiKidYellow)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_YoshiKidRed)
    EVT_END_CHILD_THREAD
    EVT_CALL(N(AddScrollToNpcPos), NPC_YoshiKidGreen)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HoldPosition_Puffs) = {
    EVT_CALL(GetNpcPos, NPC_HuffNPuffBody, LVar0, LVar1, LVar2)
    EVT_SETF(LVar0, LVar0)
    EVT_SETF(LVar3, LVar0)
    EVT_ADDF(LVar3, 80)
    EVT_SETF(LVar4, LVar0)
    EVT_SUBF(LVar4, 80)
    EVT_CALL(SetNpcPos, NPC_HuffNPuffBody, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_HuffNPuffFace, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_HuffNPuffArms, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_RuffPuff1, LVar3, 60, 0)
    EVT_CALL(SetNpcPos, NPC_RuffPuff2, LVar4, 60, 0)
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_HuffNPuffFace)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_HuffNPuffArms)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_RuffPuff1)
    EVT_END_CHILD_THREAD
    EVT_CHILD_THREAD
        EVT_CALL(N(AddScrollToNpcPos), NPC_RuffPuff2)
    EVT_END_CHILD_THREAD
    EVT_CALL(N(AddScrollToNpcPos), NPC_HuffNPuffBody)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Puffs_Surprise) = {
    EVT_CALL(SetNpcAnimation, NPC_HuffNPuffBody, ANIM_HuffNPuff_Anim26)
    EVT_CALL(SetNpcAnimation, NPC_HuffNPuffFace, ANIM_HuffNPuff_Anim27)
    EVT_CALL(SetNpcAnimation, NPC_HuffNPuffArms, ANIM_HuffNPuff_Anim28)
    EVT_CALL(SetNpcAnimation, NPC_RuffPuff1, ANIM_RuffPuff_Blush)
    EVT_CALL(SetNpcAnimation, NPC_RuffPuff2, ANIM_RuffPuff_Blush)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Puffs_Hurt) = {
    EVT_CALL(SetNpcAnimation, NPC_HuffNPuffBody, ANIM_HuffNPuff_Anim07)
    EVT_CALL(SetNpcAnimation, NPC_HuffNPuffFace, ANIM_HuffNPuff_Anim08)
    EVT_CALL(SetNpcAnimation, NPC_HuffNPuffArms, ANIM_HuffNPuff_Anim09)
    EVT_CALL(SetNpcAnimation, NPC_RuffPuff1, ANIM_RuffPuff_Hurt)
    EVT_CALL(SetNpcAnimation, NPC_RuffPuff2, ANIM_RuffPuff_Hurt)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Puffs_Retreat) = {
    EVT_CALL(GetNpcPos, NPC_HuffNPuffBody, LVar0, LVar1, LVar2)
    EVT_SET(LVar3, LVar0)
    EVT_ADD(LVar3, 80)
    EVT_SET(LVar4, LVar0)
    EVT_ADD(LVar4, -80)
    EVT_LOOP(10)
        EVT_ADD(LVar0, -2)
        EVT_CALL(SetNpcPos, NPC_HuffNPuffBody, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_HuffNPuffFace, LVar0, LVar1, LVar2)
        EVT_CALL(SetNpcPos, NPC_HuffNPuffArms, LVar0, LVar1, LVar2)
        EVT_ADD(LVar3, -2)
        EVT_CALL(SetNpcPos, NPC_RuffPuff1, LVar3, 60, 0)
        EVT_ADD(LVar4, -2)
        EVT_CALL(SetNpcPos, NPC_RuffPuff2, LVar4, 60, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GourmetGuy_Enter) = {
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcPos, NPC_YoshiKidGreen, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 1060)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(GetNpcPos, NPC_RuffPuff2, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcSpeed, NPC_GourmetGuy, EVT_FLOAT(1.0))
    EVT_CALL(NpcMoveTo, NPC_GourmetGuy, LVar0, -20, 0)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
    EVT_CALL(N(AddScrollToNpcPos), NPC_GourmetGuy)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_HoldPosition_GourmetGuy) = {
    EVT_CALL(N(AddScrollToNpcPos), NPC_GourmetGuy)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_YoshiKids) = {
    EVT_WAIT(20 * DT)
    EVT_CALL(SetNpcJumpscale, NPC_YoshiKidGreen, EVT_FLOAT(1.0))
    EVT_CALL(NpcJump0, NPC_YoshiKidGreen, 680, 0, 0, 20 * DT)
    EVT_CALL(NpcJump0, NPC_YoshiKidGreen, 740, 0, 0, 10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKidGreen, ANIM_YoshiKid_Green_Idle)
    EVT_LOOP(2)
        EVT_CALL(InterpNpcYaw, NPC_YoshiKidGreen, 270, 7 * DT)
        EVT_WAIT(10 * DT)
        EVT_CALL(InterpNpcYaw, NPC_YoshiKidGreen, 90, 7 * DT)
        EVT_WAIT(10 * DT)
    EVT_END_LOOP
    EVT_CALL(InterpNpcYaw, NPC_YoshiKidGreen, 270, 7 * DT)
    EVT_WAIT(10 * DT)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_YoshiKidGreen, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_YoshiKidGreen, LVar0, LVar1, LVar2, 7)
        EVT_CALL(SetNpcAnimation, NPC_YoshiKidGreen, ANIM_YoshiKid_Green_Run)
        EVT_CALL(NpcMoveTo, NPC_YoshiKidGreen, 980, 0, 60 * DT)
        EVT_CALL(SetNpcAnimation, NPC_YoshiKidGreen, ANIM_YoshiKid_Green_LookUp)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcPos, NPC_YoshiKidBlue, 660, 0, 0)
        EVT_CALL(NpcMoveTo, NPC_YoshiKidBlue, 940, 0, 70 * DT)
        EVT_CALL(SetNpcAnimation, NPC_YoshiKidBlue, ANIM_YoshiKid_Blue_LookUp)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcPos, NPC_YoshiKidPurple, 660, 0, 0)
        EVT_CALL(NpcMoveTo, NPC_YoshiKidPurple, 900, 0, 60 * DT)
        EVT_CALL(SetNpcAnimation, NPC_YoshiKidPurple, ANIM_YoshiKid_Purple_LookUp)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20 * DT)
        EVT_CALL(SetNpcPos, NPC_YoshiKidYellow, 660, 0, 0)
        EVT_CALL(NpcMoveTo, NPC_YoshiKidYellow, 860, 0, 50 * DT)
        EVT_CALL(SetNpcAnimation, NPC_YoshiKidYellow, ANIM_YoshiKid_Yellow_LookUp)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcPos, NPC_YoshiKidRed, 660, 0, 0)
        EVT_CALL(NpcMoveTo, NPC_YoshiKidRed, 820, 0, 40 * DT)
        EVT_CALL(SetNpcAnimation, NPC_YoshiKidRed, ANIM_YoshiKid_Red_LookUp)
    EVT_END_THREAD
    EVT_WAIT(70 * DT)
    EVT_EXEC_GET_TID(N(EVS_HoldPosition_Yoshis), LVarA)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcPos, NPC_YoshiKidGreen, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, 0x00000424)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_YoshiKidGreen, ANIM_YoshiKid_Green_Idle)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKidBlue, ANIM_YoshiKid_Blue_Idle)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKidPurple, ANIM_YoshiKid_Purple_Idle)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKidYellow, ANIM_YoshiKid_Yellow_Idle)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKidRed, ANIM_YoshiKid_Red_Idle)
    EVT_CALL(InterpNpcYaw, NPC_YoshiKidGreen, 270, 0)
    EVT_WAIT(5 * DT)
    EVT_LOOP(3)
        EVT_CALL(InterpNpcYaw, NPC_YoshiKidPurple, 270, 0)
        EVT_WAIT(5 * DT)
        EVT_CALL(InterpNpcYaw, NPC_YoshiKidBlue, 270, 0)
        EVT_WAIT(5 * DT)
        EVT_CALL(InterpNpcYaw, NPC_YoshiKidYellow, 270, 0)
        EVT_WAIT(5 * DT)
        EVT_CALL(InterpNpcYaw, NPC_YoshiKidPurple, 90, 0)
        EVT_WAIT(5 * DT)
        EVT_CALL(InterpNpcYaw, NPC_YoshiKidBlue, 90, 0)
        EVT_WAIT(5 * DT)
        EVT_CALL(InterpNpcYaw, NPC_YoshiKidYellow, 90, 0)
        EVT_WAIT(5 * DT)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_HUFF_PUFF + 310)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcYaw, NPC_YoshiKidGreen, 270)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKidGreen, ANIM_YoshiKid_Green_EatMiss)
    EVT_CALL(SetNpcYaw, NPC_YoshiKidBlue, 270)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKidBlue, ANIM_YoshiKid_Blue_EatMiss)
    EVT_CALL(SetNpcYaw, NPC_YoshiKidPurple, 90)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKidPurple, ANIM_YoshiKid_Purple_EatMiss)
    EVT_CALL(SetNpcYaw, NPC_YoshiKidYellow, 90)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKidYellow, ANIM_YoshiKid_Yellow_EatMiss)
    EVT_CALL(SetNpcYaw, NPC_YoshiKidRed, 90)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKidRed, ANIM_YoshiKid_Red_EatMiss)
    EVT_WAIT(10 * DT)
    EVT_EXEC(N(EVS_Puffs_Hurt))
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_HuffNPuffBody, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_RING, 0, LVar0, LVar1, LVar2)
        EVT_CALL(GetNpcPos, NPC_RuffPuff1, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_RING, 0, LVar0, LVar1, LVar2)
        EVT_CALL(GetNpcPos, NPC_RuffPuff2, LVar0, LVar1, LVar2)
        EVT_PLAY_EFFECT(EFFECT_SMOKE_RING, 0, LVar0, LVar1, LVar2)
        EVT_CALL(MakeLerp, 750, 375, 5, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_SETF(LVar2, LVar0)
            EVT_DIVF(LVar2, 1000)
            EVT_CALL(SetNpcScale, NPC_HuffNPuffBody, LVar2, LVar2, 1)
            EVT_CALL(SetNpcScale, NPC_HuffNPuffFace, LVar2, LVar2, 1)
            EVT_CALL(SetNpcScale, NPC_HuffNPuffArms, LVar2, LVar2, 1)
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
            EVT_CALL(SetNpcScale, NPC_RuffPuff1, LVar2, LVar2, 1)
            EVT_CALL(SetNpcScale, NPC_RuffPuff2, LVar2, LVar2, 1)
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
    EVT_WAIT(40 * DT)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKidGreen, ANIM_YoshiKid_Green_Exhale)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKidBlue, ANIM_YoshiKid_Blue_Exhale)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKidPurple, ANIM_YoshiKid_Purple_Exhale)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKidYellow, ANIM_YoshiKid_Yellow_Exhale)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKidRed, ANIM_YoshiKid_Red_Exhale)
    EVT_WAIT(50 * DT)
    EVT_KILL_THREAD(LVarA)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_YoshiKidGreen, ANIM_YoshiKid_Green_Run)
        EVT_CALL(GetNpcPos, NPC_YoshiKidGreen, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 300)
        EVT_CALL(NpcMoveTo, NPC_YoshiKidGreen, LVar0, LVar2, 75 * DT)
        EVT_CALL(SetNpcPos, NPC_YoshiKidGreen, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_YoshiKidBlue, ANIM_YoshiKid_Blue_Run)
        EVT_CALL(GetNpcPos, NPC_YoshiKidBlue, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 300)
        EVT_CALL(NpcMoveTo, NPC_YoshiKidBlue, LVar0, LVar2, 75 * DT)
        EVT_CALL(SetNpcPos, NPC_YoshiKidBlue, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_YoshiKidPurple, ANIM_YoshiKid_Purple_Run)
        EVT_CALL(GetNpcPos, NPC_YoshiKidPurple, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 300)
        EVT_CALL(NpcMoveTo, NPC_YoshiKidPurple, LVar0, LVar2, 75 * DT)
        EVT_CALL(SetNpcPos, NPC_YoshiKidPurple, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_YoshiKidYellow, ANIM_YoshiKid_Yellow_Run)
        EVT_CALL(GetNpcPos, NPC_YoshiKidYellow, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 300)
        EVT_CALL(NpcMoveTo, NPC_YoshiKidYellow, LVar0, LVar2, 75 * DT)
        EVT_CALL(SetNpcPos, NPC_YoshiKidYellow, 0, -500, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_YoshiKidRed, ANIM_YoshiKid_Red_Run)
        EVT_CALL(GetNpcPos, NPC_YoshiKidRed, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 300)
        EVT_CALL(NpcMoveTo, NPC_YoshiKidRed, LVar0, LVar2, 75 * DT)
        EVT_CALL(SetNpcPos, NPC_YoshiKidRed, 0, -500, 0)
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
        EVT_WAIT(10 * DT)
        EVT_CALL(SetNpcFlagBits, NPC_HuffNPuffBody, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_HuffNPuffFace, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_HuffNPuffArms, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_RuffPuff1, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_RuffPuff2, NPC_FLAG_TOUCHES_GROUND, FALSE)
        EVT_CALL(SetNpcScale, NPC_HuffNPuffBody, EVT_FLOAT(0.75), EVT_FLOAT(0.75), 1)
        EVT_CALL(SetNpcScale, NPC_HuffNPuffFace, EVT_FLOAT(0.75), EVT_FLOAT(0.75), 1)
        EVT_CALL(SetNpcScale, NPC_HuffNPuffArms, EVT_FLOAT(0.75), EVT_FLOAT(0.75), 1)
        EVT_CALL(EnableNpcShadow, NPC_HuffNPuffFace, FALSE)
        EVT_CALL(EnableNpcShadow, NPC_HuffNPuffArms, FALSE)
    EVT_END_THREAD
    EVT_EXEC(N(EVS_YoshiKids))
    EVT_EXEC_GET_TID(N(EVS_GourmetGuy_Enter), LVarB)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetCamPosition, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_IF_GT(LVar0, PARADE_PHASE_HUFF_PUFF + 310)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_EXEC_GET_TID(N(EVS_HoldPosition_Puffs), LVarA)
    EVT_WAIT(10 * DT)
    EVT_KILL_THREAD(LVarB)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Leap)
    EVT_CALL(GetNpcPos, NPC_GourmetGuy, LVar0, LVar1, LVar2)
    EVT_CALL(NpcJump0, NPC_GourmetGuy, LVar0, LVar1, LVar2, 10)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_TalkSurprise)
    EVT_EXEC_GET_TID(N(EVS_HoldPosition_GourmetGuy), LVarB)
    EVT_WAIT(130 * DT)
    EVT_EXEC(N(EVS_Puffs_Surprise))
    EVT_WAIT(30 * DT)
    EVT_CALL(InterpNpcYaw, NPC_HuffNPuffBody, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_HuffNPuffFace, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_HuffNPuffArms, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_RuffPuff1, 90, 0)
    EVT_CALL(InterpNpcYaw, NPC_RuffPuff2, 90, 0)
    EVT_WAIT(30 * DT)
    EVT_THREAD
        EVT_CALL(MakeLerp, 0, 90, 3, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_GourmetGuy, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Still)
        EVT_CALL(MakeLerp, 270, 360, 3, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcRotation, NPC_GourmetGuy, 0, LVar0, 0)
            EVT_WAIT(1)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
    EVT_END_THREAD
    EVT_WAIT(6)
    EVT_LOOP(2)
        EVT_EXEC(N(EVS_Puffs_Hurt))
        EVT_KILL_THREAD(LVarA)
        EVT_EXEC_WAIT(N(EVS_Puffs_Retreat))
        EVT_EXEC(N(EVS_Puffs_Surprise))
        EVT_EXEC_GET_TID(N(EVS_HoldPosition_Puffs), LVarA)
        EVT_WAIT(10 * DT)
        EVT_KILL_THREAD(LVarB)
        EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Walk)
        EVT_CALL(GetNpcPos, NPC_GourmetGuy, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, -20)
        EVT_CALL(NpcMoveTo, NPC_GourmetGuy, LVar0, LVar2, 10)
        EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Idle)
        EVT_EXEC_GET_TID(N(EVS_HoldPosition_GourmetGuy), LVarB)
        EVT_WAIT(10 * DT)
    EVT_END_LOOP
    EVT_KILL_THREAD(LVarA)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_HuffNPuffBody, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_HuffNPuffBody, LVar0, LVar1, LVar2, 10 * DT)
        EVT_ADD(LVar0, -200)
        EVT_CALL(NpcMoveTo, NPC_HuffNPuffBody, LVar0, LVar2, 50 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_HuffNPuffFace, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_HuffNPuffFace, LVar0, LVar1, LVar2, 10 * DT)
        EVT_ADD(LVar0, -200)
        EVT_CALL(NpcMoveTo, NPC_HuffNPuffFace, LVar0, LVar2, 50 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_HuffNPuffArms, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_HuffNPuffArms, LVar0, LVar1, LVar2, 10 * DT)
        EVT_ADD(LVar0, -200)
        EVT_CALL(NpcMoveTo, NPC_HuffNPuffArms, LVar0, LVar2, 50 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_RuffPuff1, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_RuffPuff1, LVar0, LVar1, LVar2, 10 * DT)
        EVT_ADD(LVar0, -200)
        EVT_CALL(NpcMoveTo, NPC_RuffPuff1, LVar0, LVar2, 50 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_RuffPuff2, LVar0, LVar1, LVar2)
        EVT_CALL(NpcJump0, NPC_RuffPuff2, LVar0, LVar1, LVar2, 10 * DT)
        EVT_ADD(LVar0, -200)
        EVT_CALL(NpcMoveTo, NPC_RuffPuff2, LVar0, LVar2, 50 * DT)
    EVT_END_THREAD
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Inspect)
    EVT_WAIT(10 * DT)
    EVT_CALL(SetNpcAnimation, NPC_GourmetGuy, ANIM_GourmetGuy_Walk)
    EVT_KILL_THREAD(LVarB)
    EVT_CALL(GetNpcPos, NPC_GourmetGuy, LVar0, LVar1, LVar2)
    EVT_ADD(LVar0, -300)
    EVT_CALL(NpcMoveTo, NPC_GourmetGuy, LVar0, LVar2, 50 * DT)
    EVT_RETURN
    EVT_END
};
