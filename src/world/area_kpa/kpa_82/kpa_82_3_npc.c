#include "kpa_82.h"

#include "world/common/enemy/Goomba.h"
#include "world/common/enemy/KoopaTroopa.h"
#include "world/common/enemy/DarkTroopa.h"
#include "world/common/enemy/ShyGuy.h"
#include "world/common/npc/Bobomb.h"

enum {
    ANSWER_CORRECT  = 0,
    ANSWER_WRONG  = 1,
};

#include "world/common/enemy/ShyGuy_Stationary.inc.c"

MobileAISettings N(AISettings_Short) = {
    .moveSpeed = 5.0f,
    .moveTime = 1,
    .alertRadius = 1.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 6.0f,
    .chaseTurnRate = 10,
    .chaseUpdateInterval = 1,
    .chaseRadius = 1.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_Short) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_Short)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Short) = {
    .height = 22,
    .radius = 24,
    .level = 5,
    .ai = &N(EVS_NpcAI_Short),
};

MobileAISettings N(AISettings_Koopa) = {
    .moveSpeed = 5.0f,
    .moveTime = 1,
    .alertRadius = 1.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 6.0f,
    .chaseTurnRate = 10,
    .chaseUpdateInterval = 1,
    .chaseRadius = 1.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_KoopaTroopa) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_Koopa)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_KoopaTroopa) = {
    .height = 35,
    .radius = 24,
    .level = 18,
    .ai = &N(EVS_NpcAI_KoopaTroopa),
};

MobileAISettings N(AISettings_ShyGuy) = {
    .moveSpeed = 5.0f,
    .moveTime = 1,
    .alertRadius = 1.0f,
    .playerSearchInterval = 1,
    .chaseSpeed = 6.0f,
    .chaseTurnRate = 10,
    .chaseUpdateInterval = 1,
    .chaseRadius = 1.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_ShyGuy) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_ShyGuy)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_ShyGuy) = {
    .height = 23,
    .radius = 22,
    .level = 14,
    .ai = &N(EVS_NpcAI_ShyGuy),
};

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,choice);
#include "world/common/complete/NormalItemChoice.inc.c"

EvtScript N(EVS_SetCam_MeetingDoor) = {
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(11.0), EVT_FLOAT(-10.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(450.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(88.0), EVT_FLOAT(256.6))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(195.0), EVT_FLOAT(142.0))
    EVT_CALL(SetCamPosC, CAM_DEFAULT, EVT_FLOAT(0.0), EVT_FLOAT(0.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetCam_AfterBattle) = {
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(3.0 / DT))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(5.0), EVT_FLOAT(-14.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(375.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(88.0), EVT_FLOAT(256.6))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(195.0), EVT_FLOAT(142.0))
    EVT_CALL(SetCamPosC, CAM_DEFAULT, EVT_FLOAT(0.0), EVT_FLOAT(0.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetCam_AfterResult) = {
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(11.0), EVT_FLOAT(-14.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(450.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(88.0), EVT_FLOAT(256.6))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(195.0), EVT_FLOAT(142.0))
    EVT_CALL(SetCamPosC, CAM_DEFAULT, EVT_FLOAT(0.0), EVT_FLOAT(0.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetCam_AskQuestion) = {
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(11.0), EVT_FLOAT(-10.5))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(88.0), EVT_FLOAT(256.6))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(195.0), EVT_FLOAT(142.0))
    EVT_CALL(SetCamPosC, CAM_DEFAULT, EVT_FLOAT(0.0), EVT_FLOAT(0.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetCam_ViewRoom) = {
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, LVar6)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(470.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(-2.5), EVT_FLOAT(300.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(-2.5), EVT_FLOAT(200.0))
    EVT_CALL(SetCamPosC, CAM_DEFAULT, EVT_FLOAT(0.0), EVT_FLOAT(0.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetCam_BeforeBattle) = {
    EVT_CALL(SetCamType, CAM_DEFAULT, 4, FALSE)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, LVar6)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(470.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(16.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(50.0), EVT_FLOAT(300.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(50.0), EVT_FLOAT(200.0))
    EVT_CALL(SetCamPosC, CAM_DEFAULT, EVT_FLOAT(0.0), EVT_FLOAT(0.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SetDoorRots) = {
    EVT_CALL(MakeLerp, 0, 60, 30 * DT, EASING_LINEAR)
    EVT_CALL(PlaySound, SOUND_225)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o100, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o101, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o145, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o146, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o102, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o103, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(StopSound, SOUND_NONE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_CloseDoors) = {
    EVT_CALL(MakeLerp, 60, 0, 30 * DT, EASING_LINEAR)
    EVT_CALL(PlaySound, SOUND_226)
    EVT_LABEL(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateModel, MODEL_o100, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o101, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o145, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o146, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o102, 0, LVar0, 0)
        EVT_CALL(TranslateModel, MODEL_o103, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(StopSound, SOUND_NONE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReleaseFrom_Door_0) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, LVar3)
    EVT_CALL(SetNpcPos, NPC_SELF, -100, 0, 0)
    EVT_CALL(RandInt, 40, LVar1)
    EVT_ADD(LVar1, -120)
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar1, 150, 30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, LVar4)
    EVT_CALL(BindNpcAI, NPC_SELF, LVar5)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReleaseFrom_Door_1) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, LVar3)
    EVT_CALL(SetNpcPos, NPC_SELF, 0, 0, 0)
    EVT_CALL(RandInt, 40, LVar1)
    EVT_ADD(LVar1, -20)
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar1, 150, 30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, LVar4)
    EVT_CALL(BindNpcAI, NPC_SELF, LVar5)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReleaseFrom_Door_2) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, LVar3)
    EVT_CALL(SetNpcPos, NPC_SELF, 100, 0, 0)
    EVT_CALL(RandInt, 40, LVar1)
    EVT_ADD(LVar1, 80)
    EVT_CALL(NpcMoveTo, NPC_SELF, LVar1, 150, 30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_SELF, LVar4)
    EVT_CALL(BindNpcAI, NPC_SELF, LVar5)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_WithdrawTo_Door_0) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, LVar3)
    EVT_CALL(RandInt, 20 * DT, LVar1)
    EVT_ADD(LVar1, 20 * DT)
    EVT_CALL(NpcMoveTo, NPC_SELF, -100, 0, LVar1)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_WithdrawTo_Door_1) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, LVar3)
    EVT_CALL(RandInt, 20 * DT, LVar1)
    EVT_ADD(LVar1, 20 * DT)
    EVT_CALL(NpcMoveTo, NPC_SELF, 0, 0, LVar1)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_WithdrawTo_Door_2) = {
    EVT_CALL(SetNpcAnimation, NPC_SELF, LVar3)
    EVT_CALL(RandInt, 20 * DT, LVar1)
    EVT_ADD(LVar1, 20 * DT)
    EVT_CALL(NpcMoveTo, NPC_SELF, 100, 0, LVar1)
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ReleaseFrom_RandomDoor) = {
    EVT_CALL(RandInt, 2, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_ReleaseFrom_Door_0))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_ReleaseFrom_Door_1))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_ReleaseFrom_Door_2))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_WithdrawTo_RandomDoor) = {
    EVT_CALL(RandInt, 2, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_EXEC_WAIT(N(EVS_WithdrawTo_Door_0))
        EVT_CASE_EQ(1)
            EVT_EXEC_WAIT(N(EVS_WithdrawTo_Door_1))
        EVT_CASE_EQ(2)
            EVT_EXEC_WAIT(N(EVS_WithdrawTo_Door_2))
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Goomba) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Release_Goomba) = {
    EVT_SET(LVar3, ANIM_Goomba_Run)
    EVT_SET(LVar4, ANIM_Goomba_Idle)
    EVT_SET(LVar5, EVT_PTR(N(EVS_NpcAI_Short)))
    EVT_EXEC_WAIT(N(EVS_ReleaseFrom_RandomDoor))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Withdraw_Goomba) = {
    EVT_SET(LVar3, ANIM_Goomba_Run)
    EVT_EXEC_WAIT(N(EVS_WithdrawTo_RandomDoor))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_ShyGuy) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Release_RedShyGuy) = {
    EVT_SET(LVar3, ANIM_ShyGuy_Red_Anim04)
    EVT_SET(LVar4, ANIM_ShyGuy_Red_Anim01)
    EVT_SET(LVar5, EVT_PTR(N(EVS_NpcAI_ShyGuy)))
    EVT_EXEC_WAIT(N(EVS_ReleaseFrom_RandomDoor))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Withdraw_RedShyGuy) = {
    EVT_SET(LVar3, ANIM_ShyGuy_Red_Anim04)
    EVT_EXEC_WAIT(N(EVS_WithdrawTo_RandomDoor))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Release_RedShyGuy_Door_1) = {
    EVT_SET(LVar3, ANIM_ShyGuy_Red_Anim04)
    EVT_SET(LVar4, ANIM_ShyGuy_Red_Anim01)
    EVT_SET(LVar5, EVT_PTR(N(EVS_NpcAI_ShyGuy)))
    EVT_EXEC_WAIT(N(EVS_ReleaseFrom_Door_1))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Withdraw_RedShyGuy_Door_1) = {
    EVT_SET(LVar3, ANIM_ShyGuy_Red_Anim04)
    EVT_EXEC_WAIT(N(EVS_WithdrawTo_Door_1))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Release_BlueShyGuy) = {
    EVT_SET(LVar3, ANIM_ShyGuy_Blue_Anim04)
    EVT_SET(LVar4, ANIM_ShyGuy_Blue_Anim01)
    EVT_SET(LVar5, EVT_PTR(N(EVS_NpcAI_ShyGuy)))
    EVT_EXEC_WAIT(N(EVS_ReleaseFrom_RandomDoor))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Withdraw_BlueShyGuy) = {
    EVT_SET(LVar3, ANIM_ShyGuy_Blue_Anim04)
    EVT_EXEC_WAIT(N(EVS_WithdrawTo_RandomDoor))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Release_BlueShyGuy_Door_2) = {
    EVT_SET(LVar3, ANIM_ShyGuy_Blue_Anim04)
    EVT_SET(LVar4, ANIM_ShyGuy_Blue_Anim01)
    EVT_SET(LVar5, EVT_PTR(N(EVS_NpcAI_ShyGuy)))
    EVT_EXEC_WAIT(N(EVS_ReleaseFrom_Door_2))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Withdraw_BlueShyGuy_Door_2) = {
    EVT_SET(LVar3, ANIM_ShyGuy_Blue_Anim04)
    EVT_EXEC_WAIT(N(EVS_WithdrawTo_Door_2))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Release_GreenShyGuy) = {
    EVT_SET(LVar3, ANIM_ShyGuy_Green_Anim04)
    EVT_SET(LVar4, ANIM_ShyGuy_Green_Anim01)
    EVT_SET(LVar5, EVT_PTR(N(EVS_NpcAI_ShyGuy)))
    EVT_EXEC_WAIT(N(EVS_ReleaseFrom_RandomDoor))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Withdraw_GreenShyGuy) = {
    EVT_SET(LVar3, ANIM_ShyGuy_Green_Anim04)
    EVT_EXEC_WAIT(N(EVS_WithdrawTo_RandomDoor))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_KoopaTroopa) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Release_DarkTroopa) = {
    EVT_SET(LVar3, ANIM_KoopaTroopa_Dark_Run)
    EVT_SET(LVar4, ANIM_KoopaTroopa_Dark_Idle)
    EVT_SET(LVar5, EVT_PTR(N(EVS_NpcAI_KoopaTroopa)))
    EVT_EXEC_WAIT(N(EVS_ReleaseFrom_RandomDoor))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Withdraw_DarkTroopa) = {
    EVT_SET(LVar3, ANIM_KoopaTroopa_Dark_Run)
    EVT_EXEC_WAIT(N(EVS_WithdrawTo_RandomDoor))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Release_KoopaTroopa) = {
    EVT_SET(LVar3, ANIM_KoopaTroopa_Run)
    EVT_SET(LVar4, ANIM_KoopaTroopa_Idle)
    EVT_SET(LVar5, EVT_PTR(N(EVS_NpcAI_KoopaTroopa)))
    EVT_EXEC_WAIT(N(EVS_ReleaseFrom_RandomDoor))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Withdraw_KoopaTroopa) = {
    EVT_SET(LVar3, ANIM_KoopaTroopa_Run)
    EVT_EXEC_WAIT(N(EVS_WithdrawTo_RandomDoor))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Bobomb) = {
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Release_Bobomb) = {
    EVT_SET(LVar3, ANIM_WorldBobomb_Green_Run)
    EVT_SET(LVar4, ANIM_WorldBobomb_Green_Idle)
    EVT_SET(LVar5, EVT_PTR(N(EVS_NpcAI_Short)))
    EVT_EXEC_WAIT(N(EVS_ReleaseFrom_RandomDoor))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Withdraw_Bobomb) = {
    EVT_SET(LVar3, ANIM_WorldBobomb_Green_Run)
    EVT_EXEC_WAIT(N(EVS_WithdrawTo_RandomDoor))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Release_Bobomb_Door_0) = {
    EVT_SET(LVar3, ANIM_WorldBobomb_Green_Run)
    EVT_SET(LVar4, ANIM_WorldBobomb_Green_Idle)
    EVT_SET(LVar5, EVT_PTR(N(EVS_NpcAI_Short)))
    EVT_EXEC_WAIT(N(EVS_ReleaseFrom_Door_0))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Withdraw_Bobomb_Door_0) = {
    EVT_SET(LVar3, ANIM_WorldBobomb_Green_Run)
    EVT_EXEC_WAIT(N(EVS_WithdrawTo_Door_0))
    EVT_RETURN
    EVT_END
};

// special 'script' used only to organize the quiz waves
#define QS_NEXT(npcID, script)  npcID, (s32) script,
#define QS_WAIT(n)  -2, n,
#define QS_END      -1,

s32 N(QS_Release_Wave_0)[] = {
    QS_NEXT(NPC_DarkTroopa_01,  N(EVS_Release_DarkTroopa))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_Goomba_01,      N(EVS_Release_Goomba))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_DarkTroopa_02,  N(EVS_Release_DarkTroopa))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_Goomba_02,      N(EVS_Release_Goomba))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_Goomba_03,      N(EVS_Release_Goomba))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_DarkTroopa_03,  N(EVS_Release_DarkTroopa))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_Goomba_04,      N(EVS_Release_Goomba))
    QS_END
};

s32 N(QS_Release_Wave_1)[] = {
    QS_NEXT(NPC_RedShyGuy_01,   N(EVS_Release_RedShyGuy))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_RedShyGuy_02,   N(EVS_Release_RedShyGuy))
    QS_WAIT(10 * DT)
    QS_NEXT(NPC_RedShyGuy_03,   N(EVS_Release_RedShyGuy))
    QS_WAIT(8 * DT)
    QS_NEXT(NPC_BlueShyGuy_01,  N(EVS_Release_BlueShyGuy))
    QS_WAIT(3 * DT)
    QS_NEXT(NPC_BlueShyGuy_02,  N(EVS_Release_BlueShyGuy))
    QS_WAIT(6 * DT)
    QS_NEXT(NPC_BlueShyGuy_03,  N(EVS_Release_BlueShyGuy))
    QS_WAIT(7 * DT)
    QS_NEXT(NPC_BlueShyGuy_04,  N(EVS_Release_BlueShyGuy))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_GreenShyGuy_01, N(EVS_Release_GreenShyGuy))
    QS_WAIT(4 * DT)
    QS_NEXT(NPC_GreenShyGuy_02, N(EVS_Release_GreenShyGuy))
    QS_WAIT(6 * DT)
    QS_NEXT(NPC_GreenShyGuy_03, N(EVS_Release_GreenShyGuy))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_GreenShyGuy_04, N(EVS_Release_GreenShyGuy))
    QS_END
};

s32 N(QS_Release_Wave_2)[] = {
    QS_NEXT(NPC_RedShyGuy_01,   N(EVS_Release_RedShyGuy_Door_1))
    QS_NEXT(NPC_BlueShyGuy_01,  N(EVS_Release_BlueShyGuy_Door_2))
    QS_NEXT(NPC_Bobomb_01,      N(EVS_Release_Bobomb_Door_0))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_RedShyGuy_02,   N(EVS_Release_RedShyGuy_Door_1))
    QS_NEXT(NPC_BlueShyGuy_02,  N(EVS_Release_BlueShyGuy_Door_2))
    QS_NEXT(NPC_Bobomb_02,      N(EVS_Release_Bobomb_Door_0))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_BlueShyGuy_03,  N(EVS_Release_BlueShyGuy_Door_2))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_BlueShyGuy_04,  N(EVS_Release_BlueShyGuy_Door_2))
    QS_END
};

s32 N(QS_Release_Wave_3)[] = {
    QS_NEXT(NPC_Goomba_01,      N(EVS_Release_Goomba))
    QS_WAIT(8 * DT)
    QS_NEXT(NPC_KoopaTroopa_01, N(EVS_Release_KoopaTroopa))
    QS_NEXT(NPC_KoopaTroopa_02, N(EVS_Release_KoopaTroopa))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_BlueShyGuy_01,  N(EVS_Release_BlueShyGuy))
    QS_NEXT(NPC_GreenShyGuy_01, N(EVS_Release_GreenShyGuy))
    QS_NEXT(NPC_BlueShyGuy_02,  N(EVS_Release_BlueShyGuy))
    QS_WAIT(8 * DT)
    QS_NEXT(NPC_Goomba_02,      N(EVS_Release_Goomba))
    QS_NEXT(NPC_BlueShyGuy_03,  N(EVS_Release_BlueShyGuy))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_KoopaTroopa_03, N(EVS_Release_KoopaTroopa))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_KoopaTroopa_04, N(EVS_Release_KoopaTroopa))
    QS_END
};

s32 N(QS_Release_Wave_4)[] = {
    QS_NEXT(NPC_Goomba_01,      N(EVS_Release_Goomba))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_KoopaTroopa_01, N(EVS_Release_KoopaTroopa))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_DarkTroopa_01,  N(EVS_Release_DarkTroopa))
    QS_END
};

s32 N(QS_Release_Wave_5)[] = {
    QS_NEXT(NPC_RedShyGuy_01,   N(EVS_Release_RedShyGuy))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_RedShyGuy_02,   N(EVS_Release_RedShyGuy))
    QS_WAIT(4 * DT)
    QS_NEXT(NPC_GreenShyGuy_01, N(EVS_Release_GreenShyGuy))
    QS_WAIT(8 * DT)
    QS_NEXT(NPC_Bobomb_01,      N(EVS_Release_Bobomb))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_Bobomb_02,      N(EVS_Release_Bobomb))
    QS_WAIT(8 * DT)
    QS_NEXT(NPC_Bobomb_03,      N(EVS_Release_Bobomb))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_KoopaTroopa_01, N(EVS_Release_KoopaTroopa))
    QS_WAIT(10 * DT)
    QS_NEXT(NPC_KoopaTroopa_02, N(EVS_Release_KoopaTroopa))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_KoopaTroopa_03, N(EVS_Release_KoopaTroopa))
    QS_WAIT(8 * DT)
    QS_NEXT(NPC_KoopaTroopa_04, N(EVS_Release_KoopaTroopa))
    QS_END
};

s32 N(QS_Release_Wave_6)[] = {
    QS_NEXT(NPC_DarkTroopa_01,  N(EVS_Release_DarkTroopa))
    QS_WAIT(10 * DT)
    QS_NEXT(NPC_BlueShyGuy_01,  N(EVS_Release_BlueShyGuy))
    QS_NEXT(NPC_Goomba_01,      N(EVS_Release_Goomba))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_BlueShyGuy_02,  N(EVS_Release_BlueShyGuy))
    QS_NEXT(NPC_Goomba_02,      N(EVS_Release_Goomba))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_Goomba_03,      N(EVS_Release_Goomba))
    QS_NEXT(NPC_DarkTroopa_02,  N(EVS_Release_DarkTroopa))
    QS_WAIT(8 * DT)
    QS_NEXT(NPC_DarkTroopa_03,  N(EVS_Release_DarkTroopa))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_RedShyGuy_01,   N(EVS_Release_RedShyGuy))
    QS_WAIT(5 * DT)
    QS_NEXT(NPC_RedShyGuy_02,   N(EVS_Release_RedShyGuy))
    QS_END
};

s32 N(QS_Withdraw_Wave_0)[] = {
    QS_NEXT(NPC_DarkTroopa_01,  N(EVS_Withdraw_DarkTroopa))
    QS_NEXT(NPC_DarkTroopa_02,  N(EVS_Withdraw_DarkTroopa))
    QS_NEXT(NPC_DarkTroopa_03,  N(EVS_Withdraw_DarkTroopa))
    QS_NEXT(NPC_Goomba_01,      N(EVS_Withdraw_Goomba))
    QS_NEXT(NPC_Goomba_02,      N(EVS_Withdraw_Goomba))
    QS_NEXT(NPC_Goomba_03,      N(EVS_Withdraw_Goomba))
    QS_NEXT(NPC_Goomba_04,      N(EVS_Withdraw_Goomba))
    QS_END
};

s32 N(QS_Withdraw_Wave_1)[] = {
    QS_NEXT(NPC_RedShyGuy_01,   N(EVS_Withdraw_RedShyGuy))
    QS_NEXT(NPC_RedShyGuy_02,   N(EVS_Withdraw_RedShyGuy))
    QS_NEXT(NPC_RedShyGuy_03,   N(EVS_Withdraw_RedShyGuy))
    QS_NEXT(NPC_BlueShyGuy_01,  N(EVS_Withdraw_BlueShyGuy))
    QS_NEXT(NPC_BlueShyGuy_02,  N(EVS_Withdraw_BlueShyGuy))
    QS_NEXT(NPC_BlueShyGuy_03,  N(EVS_Withdraw_BlueShyGuy))
    QS_NEXT(NPC_BlueShyGuy_04,  N(EVS_Withdraw_BlueShyGuy))
    QS_NEXT(NPC_GreenShyGuy_01, N(EVS_Withdraw_GreenShyGuy))
    QS_NEXT(NPC_GreenShyGuy_02, N(EVS_Withdraw_GreenShyGuy))
    QS_NEXT(NPC_GreenShyGuy_03, N(EVS_Withdraw_GreenShyGuy))
    QS_NEXT(NPC_GreenShyGuy_04, N(EVS_Withdraw_GreenShyGuy))
    QS_END
};

s32 N(QS_Withdraw_Wave_2)[] = {
    QS_NEXT(NPC_RedShyGuy_01,   N(EVS_Withdraw_RedShyGuy_Door_1))
    QS_NEXT(NPC_RedShyGuy_02,   N(EVS_Withdraw_RedShyGuy_Door_1))
    QS_NEXT(NPC_BlueShyGuy_01,  N(EVS_Withdraw_BlueShyGuy_Door_2))
    QS_NEXT(NPC_BlueShyGuy_02,  N(EVS_Withdraw_BlueShyGuy_Door_2))
    QS_NEXT(NPC_BlueShyGuy_03,  N(EVS_Withdraw_BlueShyGuy_Door_2))
    QS_NEXT(NPC_BlueShyGuy_04,  N(EVS_Withdraw_BlueShyGuy_Door_2))
    QS_NEXT(NPC_Bobomb_01,      N(EVS_Withdraw_Bobomb_Door_0))
    QS_NEXT(NPC_Bobomb_02,      N(EVS_Withdraw_Bobomb_Door_0))
    QS_END
};

s32 N(QS_Withdraw_Wave_3)[] = {
    QS_NEXT(NPC_Goomba_01,      N(EVS_Withdraw_Goomba))
    QS_NEXT(NPC_Goomba_02,      N(EVS_Withdraw_Goomba))
    QS_NEXT(NPC_KoopaTroopa_01, N(EVS_Withdraw_KoopaTroopa))
    QS_NEXT(NPC_KoopaTroopa_02, N(EVS_Withdraw_KoopaTroopa))
    QS_NEXT(NPC_KoopaTroopa_03, N(EVS_Withdraw_KoopaTroopa))
    QS_NEXT(NPC_KoopaTroopa_04, N(EVS_Withdraw_KoopaTroopa))
    QS_NEXT(NPC_GreenShyGuy_01, N(EVS_Withdraw_GreenShyGuy))
    QS_NEXT(NPC_BlueShyGuy_01,  N(EVS_Withdraw_BlueShyGuy))
    QS_NEXT(NPC_BlueShyGuy_02,  N(EVS_Withdraw_BlueShyGuy))
    QS_NEXT(NPC_BlueShyGuy_03,  N(EVS_Withdraw_BlueShyGuy))
    QS_END
};

s32 N(QS_Withdraw_Wave_4)[] = {
    QS_NEXT(NPC_Goomba_01,      N(EVS_Withdraw_Goomba))
    QS_NEXT(NPC_KoopaTroopa_01, N(EVS_Withdraw_KoopaTroopa))
    QS_NEXT(NPC_DarkTroopa_01,  N(EVS_Withdraw_DarkTroopa))
    QS_END
};

s32 N(QS_Withdraw_Wave_5)[] = {
    QS_NEXT(NPC_RedShyGuy_01,   N(EVS_Withdraw_RedShyGuy))
    QS_NEXT(NPC_RedShyGuy_02,   N(EVS_Withdraw_RedShyGuy))
    QS_NEXT(NPC_GreenShyGuy_01, N(EVS_Withdraw_GreenShyGuy))
    QS_NEXT(NPC_Bobomb_01,      N(EVS_Withdraw_Bobomb))
    QS_NEXT(NPC_Bobomb_02,      N(EVS_Withdraw_Bobomb))
    QS_NEXT(NPC_Bobomb_03,      N(EVS_Withdraw_Bobomb))
    QS_NEXT(NPC_KoopaTroopa_01, N(EVS_Withdraw_KoopaTroopa))
    QS_NEXT(NPC_KoopaTroopa_02, N(EVS_Withdraw_KoopaTroopa))
    QS_NEXT(NPC_KoopaTroopa_03, N(EVS_Withdraw_KoopaTroopa))
    QS_NEXT(NPC_KoopaTroopa_04, N(EVS_Withdraw_KoopaTroopa))
    QS_END
};

s32 N(QS_Withdraw_Wave_6)[] = {
    QS_NEXT(NPC_DarkTroopa_01, N(EVS_Withdraw_DarkTroopa))
    QS_NEXT(NPC_DarkTroopa_02, N(EVS_Withdraw_DarkTroopa))
    QS_NEXT(NPC_DarkTroopa_03, N(EVS_Withdraw_DarkTroopa))
    QS_NEXT(NPC_BlueShyGuy_01, N(EVS_Withdraw_BlueShyGuy))
    QS_NEXT(NPC_BlueShyGuy_02, N(EVS_Withdraw_BlueShyGuy))
    QS_NEXT(NPC_Goomba_01,     N(EVS_Withdraw_Goomba))
    QS_NEXT(NPC_Goomba_02,     N(EVS_Withdraw_Goomba))
    QS_NEXT(NPC_Goomba_03,     N(EVS_Withdraw_Goomba))
    QS_NEXT(NPC_RedShyGuy_01,  N(EVS_Withdraw_RedShyGuy))
    QS_NEXT(NPC_RedShyGuy_02,  N(EVS_Withdraw_RedShyGuy))
    QS_END
};

EvtScript N(EVS_Release_Wave) = {
    EVT_SWITCH(AB_KPA82_QuizRound)
        EVT_CASE_EQ(0)
            EVT_USE_BUF(EVT_PTR(N(QS_Release_Wave_0)))
        EVT_CASE_EQ(1)
            EVT_USE_BUF(EVT_PTR(N(QS_Release_Wave_1)))
        EVT_CASE_EQ(2)
            EVT_USE_BUF(EVT_PTR(N(QS_Release_Wave_2)))
        EVT_CASE_EQ(3)
            EVT_USE_BUF(EVT_PTR(N(QS_Release_Wave_3)))
        EVT_CASE_EQ(4)
            EVT_USE_BUF(EVT_PTR(N(QS_Release_Wave_4)))
        EVT_CASE_EQ(5)
            EVT_USE_BUF(EVT_PTR(N(QS_Release_Wave_5)))
        EVT_CASE_EQ(6)
            EVT_USE_BUF(EVT_PTR(N(QS_Release_Wave_6)))
    EVT_END_SWITCH
    EVT_LOOP(0)
        EVT_BUF_READ2(LVarA, LVarB)
        EVT_IF_EQ(LVarA, -1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_IF_EQ(LVarA, -2)
            EVT_WAIT(LVarB)
        EVT_ELSE
            EVT_CALL(BindNpcAI, LVarA, LVarB)
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Withdraw_Wave) = {
    EVT_SWITCH(AB_KPA82_QuizRound)
        EVT_CASE_EQ(0)
            EVT_USE_BUF(EVT_PTR(N(QS_Withdraw_Wave_0)))
        EVT_CASE_EQ(1)
            EVT_USE_BUF(EVT_PTR(N(QS_Withdraw_Wave_1)))
        EVT_CASE_EQ(2)
            EVT_USE_BUF(EVT_PTR(N(QS_Withdraw_Wave_2)))
        EVT_CASE_EQ(3)
            EVT_USE_BUF(EVT_PTR(N(QS_Withdraw_Wave_3)))
        EVT_CASE_EQ(4)
            EVT_USE_BUF(EVT_PTR(N(QS_Withdraw_Wave_4)))
        EVT_CASE_EQ(5)
            EVT_USE_BUF(EVT_PTR(N(QS_Withdraw_Wave_5)))
        EVT_CASE_EQ(6)
            EVT_USE_BUF(EVT_PTR(N(QS_Withdraw_Wave_6)))
    EVT_END_SWITCH
    EVT_LOOP(0)
        EVT_BUF_READ2(LVarA, LVarB)
        EVT_IF_EQ(LVarA, -1)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_IF_EQ(LVarA, -2)
            EVT_WAIT(LVarB)
        EVT_ELSE
            EVT_CALL(BindNpcAI, LVarA, LVarB)
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AskQuestion) = {
    EVT_EXEC_WAIT(N(EVS_SetCam_AskQuestion))
    EVT_SWITCH(AB_KPA82_QuizRound)
        EVT_CASE_EQ(0)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0035)
            EVT_CALL(ShowChoice, MSG_Choice_0046)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET(LVar0, ANSWER_CORRECT)
            EVT_ELSE
                EVT_SET(LVar0, ANSWER_WRONG)
            EVT_END_IF
        EVT_CASE_EQ(1)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0036)
            EVT_CALL(ShowChoice, MSG_Choice_0047)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET(LVar0, ANSWER_CORRECT)
            EVT_ELSE
                EVT_SET(LVar0, ANSWER_WRONG)
            EVT_END_IF
        EVT_CASE_EQ(2)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0037)
            EVT_CALL(ShowChoice, MSG_Choice_0048)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET(LVar0, ANSWER_CORRECT)
            EVT_ELSE
                EVT_SET(LVar0, ANSWER_WRONG)
            EVT_END_IF
        EVT_CASE_EQ(3)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0038)
            EVT_CALL(ShowChoice, MSG_Choice_0049)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET(LVar0, ANSWER_CORRECT)
            EVT_ELSE
                EVT_SET(LVar0, ANSWER_WRONG)
            EVT_END_IF
        EVT_CASE_EQ(4)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0039)
            EVT_CALL(ShowChoice, MSG_Choice_004A)
            EVT_IF_EQ(LVar0, 0)
                EVT_SET(LVar0, ANSWER_CORRECT)
            EVT_ELSE
                EVT_SET(LVar0, ANSWER_WRONG)
            EVT_END_IF
        EVT_CASE_EQ(5)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_003A)
            EVT_CALL(ShowChoice, MSG_Choice_004B)
            EVT_IF_EQ(LVar0, 2)
                EVT_SET(LVar0, ANSWER_CORRECT)
            EVT_ELSE
                EVT_SET(LVar0, ANSWER_WRONG)
            EVT_END_IF
        EVT_CASE_EQ(6)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_003B)
            EVT_CALL(ShowChoice, MSG_Choice_004C)
            EVT_IF_EQ(LVar0, 1)
                EVT_SET(LVar0, ANSWER_CORRECT)
            EVT_ELSE
                EVT_SET(LVar0, ANSWER_WRONG)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_SET(MV_LastAnswerResult, LVar0)
    EVT_CALL(CloseMessage)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShowUnknownCard) = {
    EVT_CALL(EnableModel, MODEL_m_, TRUE)
    EVT_CALL(MakeLerp, 180, LVar0, 60 * DT, EASING_QUADRATIC_IN)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_IF_GE(LVar0, 360)
            EVT_CALL(RotateGroup, MODEL_g47, LVar0, 0, 1, 0)
            EVT_CALL(EnableGroup, MODEL_g47, TRUE)
            EVT_CALL(EnableModel, MODEL_m_, FALSE)
        EVT_ELSE
            EVT_CALL(RotateModel, MODEL_m_, LVar0, 0, 1, 0)
        EVT_END_IF
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_TetherResultCardToDummyPos) = {
    EVT_LOOP(0)
        EVT_CALL(GetNpcPos, NPC_Dummy, LVar0, LVar1, LVar2)
        EVT_SUB(LVar0, 0)
        EVT_SUB(LVar1, 130)
        EVT_SUB(LVar2, 50)
        EVT_CALL(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        EVT_IF_EQ(LVarA, 85)
            EVT_CALL(RotateModel, MODEL_b_kai, 180, 0, 1, 0)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ScaleResultCard) = {
    EVT_CALL(EnableModel, LVarA, TRUE)
    EVT_CALL(MakeLerp, 100, 50, 30 * DT, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SETF(LVar6, LVar0)
        EVT_MULF(LVar6, EVT_FLOAT(0.01))
        EVT_CALL(ScaleModel, LVarA, LVar6, LVar6, 1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MoveCardToScoreboard) = {
    EVT_CALL(EnableModel, LVarA, TRUE)
    EVT_CALL(SetNpcPos, NPC_Dummy, 0, 130, 50)
    EVT_EXEC_GET_TID(N(EVS_TetherResultCardToDummyPos), LVarB)
    EVT_EXEC(N(EVS_ScaleResultCard))
    EVT_WAIT(1)
    EVT_SWITCH(AB_KPA82_QuizRound)
        EVT_CASE_EQ(0)
            EVT_SET(LVar0, 118)
            EVT_SET(LVar1, 148)
            EVT_SET(LVar2, 3)
        EVT_CASE_EQ(1)
            EVT_SET(LVar0, 78)
            EVT_SET(LVar1, 148)
            EVT_SET(LVar2, 3)
        EVT_CASE_EQ(2)
            EVT_SET(LVar0, 38)
            EVT_SET(LVar1, 148)
            EVT_SET(LVar2, 3)
        EVT_CASE_EQ(3)
            EVT_SET(LVar0, -1)
            EVT_SET(LVar1, 148)
            EVT_SET(LVar2, 3)
        EVT_CASE_EQ(4)
            EVT_SET(LVar0, -41)
            EVT_SET(LVar1, 148)
            EVT_SET(LVar2, 3)
        EVT_CASE_EQ(5)
            EVT_SET(LVar0, -81)
            EVT_SET(LVar1, 148)
            EVT_SET(LVar2, 3)
        EVT_CASE_EQ(6)
            EVT_SET(LVar0, -121)
            EVT_SET(LVar1, 148)
            EVT_SET(LVar2, 3)
    EVT_END_SWITCH
    EVT_CALL(SetNpcJumpscale, NPC_Dummy, EVT_FLOAT(0.0))
    EVT_CALL(NpcJump1, NPC_Dummy, LVar0, LVar1, LVar2, 30 * DT)
    EVT_CALL(SetNpcPos, NPC_Dummy, 184, 20, 150)
    EVT_KILL_THREAD(LVarB)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GetCorrectScoreboardModel) = {
    EVT_SWITCH(AB_KPA82_QuizRound)
        EVT_CASE_EQ(0)
            EVT_SET(LVar0, MODEL_m1)
        EVT_CASE_EQ(1)
            EVT_SET(LVar0, MODEL_m2)
        EVT_CASE_EQ(2)
            EVT_SET(LVar0, MODEL_m3)
        EVT_CASE_EQ(3)
            EVT_SET(LVar0, MODEL_m4)
        EVT_CASE_EQ(4)
            EVT_SET(LVar0, MODEL_m5)
        EVT_CASE_EQ(5)
            EVT_SET(LVar0, MODEL_m6)
        EVT_CASE_EQ(6)
            EVT_SET(LVar0, MODEL_m7)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_GetWrongScoreboardModel) = {
    EVT_SWITCH(AB_KPA82_QuizRound)
        EVT_CASE_EQ(0)
            EVT_SET(LVar0, MODEL_b1)
        EVT_CASE_EQ(1)
            EVT_SET(LVar0, MODEL_b2)
        EVT_CASE_EQ(2)
            EVT_SET(LVar0, MODEL_b3)
        EVT_CASE_EQ(3)
            EVT_SET(LVar0, MODEL_b4)
        EVT_CASE_EQ(4)
            EVT_SET(LVar0, MODEL_b5)
        EVT_CASE_EQ(5)
            EVT_SET(LVar0, MODEL_b6)
        EVT_CASE_EQ(6)
            EVT_SET(LVar0, MODEL_b7)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShowResultCard) = {
    EVT_SET(LVar6, EVT_FLOAT(2.0 / DT))
    EVT_EXEC_WAIT(N(EVS_SetCam_ViewRoom))
    EVT_WAIT(5)
    EVT_IF_EQ(MV_LastAnswerResult, ANSWER_CORRECT)
        EVT_SET(LVar0, 2160)
        EVT_EXEC_WAIT(N(EVS_ShowUnknownCard))
        EVT_CALL(PlaySound, SOUND_21C)
        EVT_WAIT(10 * DT)
        EVT_CALL(EnableGroup, MODEL_g47, FALSE)
        EVT_SET(LVarA, MODEL_m_kai)
        EVT_EXEC_WAIT(N(EVS_MoveCardToScoreboard))
        EVT_EXEC_WAIT(N(EVS_GetCorrectScoreboardModel))
        EVT_CALL(EnableModel, MODEL_m_kai, FALSE)
        EVT_CALL(EnableModel, LVar0, TRUE)
        EVT_WAIT(30 * DT)
    EVT_ELSE
        EVT_SET(LVar0, 2340)
        EVT_EXEC_WAIT(N(EVS_ShowUnknownCard))
        EVT_CALL(PlaySound, SOUND_MENU_ERROR)
        EVT_WAIT(10 * DT)
        EVT_CALL(EnableGroup, MODEL_g47, FALSE)
        EVT_SET(LVarA, MODEL_b_kai)
        EVT_EXEC_WAIT(N(EVS_MoveCardToScoreboard))
        EVT_EXEC_WAIT(N(EVS_GetWrongScoreboardModel))
        EVT_CALL(EnableModel, MODEL_b_kai, FALSE)
        EVT_CALL(EnableModel, LVar0, TRUE)
        EVT_WAIT(30 * DT)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_SetCam_AfterResult))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_Door) = {
    EVT_LABEL(1)
        EVT_WAIT(1)
        EVT_IF_EQ(GF_KPA82_PassedThroughDoor, FALSE)
            EVT_GOTO(1)
        EVT_END_IF
    EVT_SET(GF_KPA82_PassedThroughDoor, FALSE)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_EXEC_WAIT(N(EVS_SetCam_MeetingDoor))
    EVT_SET(MF_Sync_MusicChange, FALSE)
    EVT_THREAD
        EVT_CALL(SetMusicTrack, 0, SONG_FINAL_BOWSER_BATTLE, 1, 8)
        EVT_WAIT(150 * DT)
        EVT_IF_NE(MF_Sync_MusicChange, FALSE)
            EVT_GOTO(5)
        EVT_END_IF
        EVT_CALL(FadeOutMusic, 0, 250)
        EVT_WAIT(15 * DT)
        EVT_IF_NE(MF_Sync_MusicChange, FALSE)
            EVT_GOTO(5)
        EVT_END_IF
        EVT_EXEC(N(EVS_SetupMusic))
        EVT_LABEL(5)
    EVT_END_THREAD
    EVT_IF_EQ(GF_KPA82_SpokeToDoor, FALSE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_002E)
        EVT_SET(GF_KPA82_SpokeToDoor, TRUE)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_002F)
    EVT_END_IF
    EVT_CALL(ShowChoice, MSG_Choice_0013)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0031)
    EVT_ELSE
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0030)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_SET(GF_KPA82_PassedThroughDoor, FALSE)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_GOTO(1)
    EVT_END_IF
    EVT_CALL(ShowChoice, MSG_Choice_0013)
    EVT_IF_EQ(LVar0, 0)
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0032)
    EVT_ELSE
        EVT_CALL(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0033)
    EVT_END_IF
    EVT_CALL(DisablePartnerAI, 0)
    EVT_THREAD
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o166, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(2.0))
        EVT_CALL(PlayerMoveTo, 175, 236, 20)
        EVT_CALL(InterpPlayerYaw, 270, 0)
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o166, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(2.5))
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, 205, 236, 20)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 0)
    EVT_END_THREAD
    EVT_SET(AB_KPA82_QuizRound, 0)
    EVT_SET(AB_KPA82_RightAnswers, 0)
    EVT_SET(AB_KPA82_WrongAnswers, 0)
    EVT_LABEL(10)
        EVT_SET(LVar6, EVT_FLOAT(2.0 / DT))
        EVT_EXEC_WAIT(N(EVS_SetCam_ViewRoom))
        EVT_SET(MF_Sync_MusicChange, TRUE)
        EVT_WAIT(2)
        EVT_CALL(SetMusicTrack, 0, SONG_NORMAL_BATTLE, 0, 8)
        EVT_EXEC_WAIT(N(EVS_SetDoorRots))
        EVT_EXEC_WAIT(N(EVS_Release_Wave))
        EVT_WAIT(200 * DT)
        EVT_THREAD
            EVT_CALL(ShowMessageAtScreenPos, MSG_CH8_0034, 300, 200)
            EVT_SET(MV_Sync_TimesUp, TRUE)
        EVT_END_THREAD
        EVT_WAIT(60 * DT)
        EVT_EXEC_WAIT(N(EVS_Withdraw_Wave))
        EVT_WAIT(35 * DT)
        EVT_EXEC_WAIT(N(EVS_CloseDoors))
        EVT_EXEC(N(EVS_SetupMusic))
        EVT_WAIT(30 * DT)
        EVT_LABEL(12)
            EVT_WAIT(1)
            EVT_IF_EQ(MV_Sync_TimesUp, FALSE)
                EVT_GOTO(12)
            EVT_END_IF
        EVT_SET(MV_Sync_TimesUp, FALSE)
        EVT_EXEC_WAIT(N(EVS_AskQuestion))
        EVT_EXEC_WAIT(N(EVS_ShowResultCard))
        EVT_IF_EQ(MV_LastAnswerResult, ANSWER_CORRECT)
            EVT_ADD(AB_KPA82_RightAnswers, 1)
            EVT_IF_EQ(AB_KPA82_RightAnswers, 5)
                EVT_GOTO(30)
            EVT_END_IF
            EVT_IF_EQ(AB_KPA82_RightAnswers, 4)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_003D)
            EVT_ELSE
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_003C)
            EVT_END_IF
        EVT_ELSE
            EVT_ADD(AB_KPA82_WrongAnswers, 1)
            EVT_IF_EQ(AB_KPA82_WrongAnswers, 3)
                EVT_GOTO(20)
            EVT_END_IF
            EVT_IF_EQ(AB_KPA82_WrongAnswers, 1)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_003E)
            EVT_END_IF
            EVT_IF_EQ(AB_KPA82_WrongAnswers, 2)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0040)
            EVT_END_IF
        EVT_END_IF
        EVT_ADD(AB_KPA82_QuizRound, 1)
        EVT_GOTO(10)
    EVT_LABEL(20)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0041)
    EVT_SET(LVar6, EVT_FLOAT(2.0 / DT))
    EVT_EXEC_WAIT(N(EVS_SetCam_ViewRoom))
    EVT_CALL(SetNpcPos, NPC_AntiGuy_01, -100, 0, 0)
    EVT_CALL(SetNpcPos, NPC_AntiGuy_02, 0, 0, 0)
    EVT_CALL(SetNpcPos, NPC_AntiGuy_03, 100, 0, 0)
    EVT_CALL(InterpPlayerYaw, 315, 0)
    EVT_CALL(InterpNpcYaw, NPC_PARTNER, 315, 0)
    EVT_EXEC_WAIT(N(EVS_SetDoorRots))
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0042)
    EVT_CALL(PlayerFaceNpc, NPC_AntiGuy_02, 5)
    EVT_CALL(GetPlayerPos, LVar3, LVar4, LVar5)
    EVT_SET(LVar6, EVT_FLOAT(3.0 / DT))
    EVT_EXEC_WAIT(N(EVS_SetCam_BeforeBattle))
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_AntiGuy_01, ANIM_ShyGuy_Black_Anim04)
        EVT_CALL(NpcMoveTo, NPC_AntiGuy_01, LVar0, LVar2, 30 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_AntiGuy_02, ANIM_ShyGuy_Black_Anim04)
        EVT_CALL(NpcMoveTo, NPC_AntiGuy_02, LVar0, LVar2, 30 * DT)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_AntiGuy_03, ANIM_ShyGuy_Black_Anim04)
        EVT_CALL(NpcMoveTo, NPC_AntiGuy_03, LVar0, LVar2, 30 * DT)
    EVT_END_THREAD
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_EXEC_WAIT(N(EVS_SetCam_AfterBattle))
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0043)
    EVT_GOTO(40)
    EVT_LABEL(30)
    EVT_THREAD
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o166, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(DisablePlayerPhysics, TRUE)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
        EVT_CALL(PlayerMoveTo, 120, 145, 0)
        EVT_CALL(InterpPlayerYaw, 90, 0)
        EVT_CALL(DisablePlayerPhysics, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o166, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcSpeed, NPC_PARTNER, EVT_FLOAT(3.5 * DT))
        EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, 80, 145, 0)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_003F)
    EVT_LABEL(40)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_SET(GB_KPA82_BowserDoorState, 1)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitDoors_kpa_61_0)), TRIGGER_WALL_PRESS_A, COLLIDER_o166, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Door) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetNpcPos, NPC_AntiGuy_01, NPC_DISPOSE_LOCATION)
            EVT_CALL(SetNpcPos, NPC_AntiGuy_02, NPC_DISPOSE_LOCATION)
            EVT_CALL(SetNpcPos, NPC_AntiGuy_03, NPC_DISPOSE_LOCATION)
            EVT_CALL(SetPlayerPos, 120, 0, 145)
            EVT_CALL(SetNpcPos, NPC_PARTNER, 80, 0, 145)
            EVT_CALL(InterpPlayerYaw, 90, 0)
            EVT_CALL(InterpNpcYaw, NPC_PARTNER, 90, 0)
            EVT_CALL(TranslateModel, MODEL_o100, 0, 0, 0)
            EVT_CALL(TranslateModel, MODEL_o101, 0, 0, 0)
            EVT_CALL(TranslateModel, MODEL_o145, 0, 0, 0)
            EVT_CALL(TranslateModel, MODEL_o146, 0, 0, 0)
            EVT_CALL(TranslateModel, MODEL_o102, 0, 0, 0)
            EVT_CALL(TranslateModel, MODEL_o103, 0, 0, 0)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Door) = {
    EVT_IF_EQ(GB_KPA82_BowserDoorState, 0)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Door)))
    EVT_END_IF
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_Door)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcPos, NPC_SELF, 184, 20, 150)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Goomba) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Goomba)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ShyGuy) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_ShyGuy)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_KoopaTroopa) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_KoopaTroopa)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bobomb) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Bobomb)))
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_AntiGuy) = {
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_AntiGuys)[] = {
    {
        .id = NPC_Dummy,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Door),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = ANTI_GUY_ANIMS,
    },
    {
        .id = NPC_AntiGuy_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_AntiGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = ANTI_GUY_ANIMS,
    },
    {
        .id = NPC_AntiGuy_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_AntiGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = ANTI_GUY_ANIMS,
    },
    {
        .id = NPC_AntiGuy_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_AntiGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = ANTI_GUY_ANIMS,
    },
};

NpcData N(NpcData_Goombas)[] = {
    {
        .id = NPC_Goomba_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_Goomba),
        .settings = &N(NpcSettings_Short),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = GOOMBA_DROPS,
        .animations = GOOMBA_ANIMS,
    },
    {
        .id = NPC_Goomba_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_Goomba),
        .settings = &N(NpcSettings_Short),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = GOOMBA_DROPS,
        .animations = GOOMBA_ANIMS,
    },
    {
        .id = NPC_Goomba_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_Goomba),
        .settings = &N(NpcSettings_Short),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = GOOMBA_DROPS,
        .animations = GOOMBA_ANIMS,
    },
    {
        .id = NPC_Goomba_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_Goomba),
        .settings = &N(NpcSettings_Short),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = GOOMBA_DROPS,
        .animations = GOOMBA_ANIMS,
    },
    {
        .id = NPC_Goomba_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_Goomba),
        .settings = &N(NpcSettings_Short),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = GOOMBA_DROPS,
        .animations = GOOMBA_ANIMS,
    },
};

NpcData N(NpcData_RedShyGuys)[] = {
    {
        .id = NPC_RedShyGuy_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = SHY_GUY_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_RedShyGuy_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = SHY_GUY_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_RedShyGuy_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = SHY_GUY_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_RedShyGuy_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = SHY_GUY_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_RedShyGuy_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = SHY_GUY_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
};

NpcData N(NpcData_BlueShyGuys)[] = {
    {
        .id = NPC_BlueShyGuy_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = SHY_GUY_DROPS,
        .animations = BLUE_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_BlueShyGuy_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = SHY_GUY_DROPS,
        .animations = BLUE_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_BlueShyGuy_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = SHY_GUY_DROPS,
        .animations = BLUE_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_BlueShyGuy_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = SHY_GUY_DROPS,
        .animations = BLUE_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_BlueShyGuy_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = SHY_GUY_DROPS,
        .animations = BLUE_SHY_GUY_ANIMS,
    },
};

NpcData N(NpcData_GreenShyGuys)[] = {
    {
        .id = NPC_GreenShyGuy_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = SHY_GUY_DROPS,
        .animations = GREEN_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_GreenShyGuy_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = SHY_GUY_DROPS,
        .animations = GREEN_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_GreenShyGuy_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = SHY_GUY_DROPS,
        .animations = GREEN_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_GreenShyGuy_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = SHY_GUY_DROPS,
        .animations = GREEN_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_GreenShyGuy_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = SHY_GUY_DROPS,
        .animations = GREEN_SHY_GUY_ANIMS,
    },
};

NpcData N(NpcData_DarkTroopas)[] = {
    {
        .id = NPC_DarkTroopa_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_KoopaTroopa),
        .settings = &N(NpcSettings_KoopaTroopa),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = KOOPA_TROOPA_NOK_DROPS,
        .animations = DARK_TROOPA_ANIMS,
    },
    {
        .id = NPC_DarkTroopa_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_KoopaTroopa),
        .settings = &N(NpcSettings_KoopaTroopa),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = KOOPA_TROOPA_NOK_DROPS,
        .animations = DARK_TROOPA_ANIMS,
    },
    {
        .id = NPC_DarkTroopa_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_KoopaTroopa),
        .settings = &N(NpcSettings_KoopaTroopa),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = KOOPA_TROOPA_NOK_DROPS,
        .animations = DARK_TROOPA_ANIMS,
    },
    {
        .id = NPC_DarkTroopa_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_KoopaTroopa),
        .settings = &N(NpcSettings_KoopaTroopa),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = KOOPA_TROOPA_NOK_DROPS,
        .animations = DARK_TROOPA_ANIMS,
    },
    {
        .id = NPC_DarkTroopa_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_KoopaTroopa),
        .settings = &N(NpcSettings_KoopaTroopa),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = KOOPA_TROOPA_NOK_DROPS,
        .animations = DARK_TROOPA_ANIMS,
    },
};

NpcData N(NpcData_KoopaTroopas)[] = {
    {
        .id = NPC_KoopaTroopa_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_KoopaTroopa),
        .settings = &N(NpcSettings_KoopaTroopa),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = KOOPA_TROOPA_NOK_DROPS,
        .animations = KOOPA_TROOPA_ANIMS,
    },
    {
        .id = NPC_KoopaTroopa_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_KoopaTroopa),
        .settings = &N(NpcSettings_KoopaTroopa),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = KOOPA_TROOPA_NOK_DROPS,
        .animations = KOOPA_TROOPA_ANIMS,
    },
    {
        .id = NPC_KoopaTroopa_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_KoopaTroopa),
        .settings = &N(NpcSettings_KoopaTroopa),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = KOOPA_TROOPA_NOK_DROPS,
        .animations = KOOPA_TROOPA_ANIMS,
    },
    {
        .id = NPC_KoopaTroopa_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_KoopaTroopa),
        .settings = &N(NpcSettings_KoopaTroopa),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = KOOPA_TROOPA_NOK_DROPS,
        .animations = KOOPA_TROOPA_ANIMS,
    },
    {
        .id = NPC_KoopaTroopa_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_KoopaTroopa),
        .settings = &N(NpcSettings_KoopaTroopa),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = KOOPA_TROOPA_NOK_DROPS,
        .animations = KOOPA_TROOPA_ANIMS,
    },
};

NpcData N(NpcData_Bobombs)[] = {
    {
        .id = NPC_Bobomb_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_Bobomb),
        .settings = &N(NpcSettings_Short),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BOBOMB_GREEN_ANIMS,
    },
    {
        .id = NPC_Bobomb_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_Bobomb),
        .settings = &N(NpcSettings_Short),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BOBOMB_GREEN_ANIMS,
    },
    {
        .id = NPC_Bobomb_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_Bobomb),
        .settings = &N(NpcSettings_Short),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BOBOMB_GREEN_ANIMS,
    },
    {
        .id = NPC_Bobomb_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_Bobomb),
        .settings = &N(NpcSettings_Short),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BOBOMB_GREEN_ANIMS,
    },
    {
        .id = NPC_Bobomb_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_RECT,
                .centerPos  = { 0, 0, 150 },
                .wanderSize = { 130, 100 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 0, 0, 150 },
                .detectSize = { 130, 100 },
            }
        },
        .init = &N(EVS_NpcInit_Bobomb),
        .settings = &N(NpcSettings_Short),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_800 | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = BOBOMB_GREEN_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_AntiGuys), BTL_KPA3_FORMATION_00, BTL_KPA3_STAGE_00),
    NPC_GROUP(N(NpcData_Goombas), BTL_KPA3_FORMATION_00, BTL_KPA3_STAGE_00),
    NPC_GROUP(N(NpcData_RedShyGuys), BTL_KPA3_FORMATION_00, BTL_KPA3_STAGE_00),
    NPC_GROUP(N(NpcData_BlueShyGuys), BTL_KPA3_FORMATION_00, BTL_KPA3_STAGE_00),
    NPC_GROUP(N(NpcData_GreenShyGuys), BTL_KPA3_FORMATION_00, BTL_KPA3_STAGE_00),
    NPC_GROUP(N(NpcData_DarkTroopas), BTL_KPA3_FORMATION_00, BTL_KPA3_STAGE_00),
    NPC_GROUP(N(NpcData_KoopaTroopas), BTL_KPA3_FORMATION_00, BTL_KPA3_STAGE_00),
    NPC_GROUP(N(NpcData_Bobombs), BTL_KPA3_FORMATION_00, BTL_KPA3_STAGE_00),
    {}
};
