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
    Call(BasicAI_Main, Ref(N(AISettings_Short)))
    Return
    End
};

NpcSettings N(NpcSettings_Short) = {
    .height = 22,
    .radius = 24,
    .level = ACTOR_LEVEL_GOOMBA,
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
    Call(BasicAI_Main, Ref(N(AISettings_Koopa)))
    Return
    End
};

NpcSettings N(NpcSettings_KoopaTroopa) = {
    .height = 35,
    .radius = 24,
    .level = ACTOR_LEVEL_DARK_KOOPA,
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
    Call(BasicAI_Main, Ref(N(AISettings_ShyGuy)))
    Return
    End
};

NpcSettings N(NpcSettings_ShyGuy) = {
    .height = 23,
    .radius = 22,
    .level = ACTOR_LEVEL_SHY_GUY,
    .ai = &N(EVS_NpcAI_ShyGuy),
};

#include "world/common/complete/KeyItemChoice.inc.c"
MAP_STATIC_PAD(1,choice);
#include "world/common/complete/NormalItemChoice.inc.c"

EvtScript N(EVS_SetCam_MeetingDoor) = {
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(SetCamPitch, CAM_DEFAULT, Float(11.0), Float(-10.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(450.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(88.0), Float(256.6))
    Call(SetCamPosB, CAM_DEFAULT, Float(195.0), Float(142.0))
    Call(SetCamPosC, CAM_DEFAULT, Float(0.0), Float(0.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_SetCam_AfterBattle) = {
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamSpeed, CAM_DEFAULT, Float(3.0 / DT))
    Call(SetCamPitch, CAM_DEFAULT, Float(5.0), Float(-14.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(375.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(88.0), Float(256.6))
    Call(SetCamPosB, CAM_DEFAULT, Float(195.0), Float(142.0))
    Call(SetCamPosC, CAM_DEFAULT, Float(0.0), Float(0.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_SetCam_AfterResult) = {
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(11.0), Float(-14.0))
    Call(SetCamDistance, CAM_DEFAULT, Float(450.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(88.0), Float(256.6))
    Call(SetCamPosB, CAM_DEFAULT, Float(195.0), Float(142.0))
    Call(SetCamPosC, CAM_DEFAULT, Float(0.0), Float(0.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_SetCam_AskQuestion) = {
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(11.0), Float(-10.5))
    Call(SetCamPosA, CAM_DEFAULT, Float(88.0), Float(256.6))
    Call(SetCamPosB, CAM_DEFAULT, Float(195.0), Float(142.0))
    Call(SetCamPosC, CAM_DEFAULT, Float(0.0), Float(0.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_SetCam_ViewRoom) = {
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamSpeed, CAM_DEFAULT, LVar6)
    Call(SetCamDistance, CAM_DEFAULT, Float(470.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(16.0), Float(-9.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(-2.5), Float(300.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(-2.5), Float(200.0))
    Call(SetCamPosC, CAM_DEFAULT, Float(0.0), Float(0.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_SetCam_BeforeBattle) = {
    Call(SetCamType, CAM_DEFAULT, 4, FALSE)
    Call(SetCamSpeed, CAM_DEFAULT, LVar6)
    Call(SetCamDistance, CAM_DEFAULT, Float(470.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(16.0), Float(-9.0))
    Call(SetCamPosA, CAM_DEFAULT, Float(50.0), Float(300.0))
    Call(SetCamPosB, CAM_DEFAULT, Float(50.0), Float(200.0))
    Call(SetCamPosC, CAM_DEFAULT, Float(0.0), Float(0.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Return
    End
};

EvtScript N(EVS_SetDoorRots) = {
    Call(MakeLerp, 0, 60, 30 * DT, EASING_LINEAR)
    Call(PlaySound, SOUND_KPA_QUIZ_DOORS_OPEN)
    Label(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o100, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o101, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o145, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o146, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o102, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o103, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(StopSound, SOUND_NONE)
    Return
    End
};

EvtScript N(EVS_CloseDoors) = {
    Call(MakeLerp, 60, 0, 30 * DT, EASING_LINEAR)
    Call(PlaySound, SOUND_KPA_QUIZ_DOORS_CLOSE)
    Label(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_o100, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o101, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o145, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o146, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o102, 0, LVar0, 0)
        Call(TranslateModel, MODEL_o103, 0, LVar0, 0)
        Wait(1)
        IfEq(LVar1, 1)
            Goto(0)
        EndIf
    Call(StopSound, SOUND_NONE)
    Return
    End
};

EvtScript N(EVS_ReleaseFrom_Door_0) = {
    Call(SetNpcAnimation, NPC_SELF, LVar3)
    Call(SetNpcPos, NPC_SELF, -100, 0, 0)
    Call(RandInt, 40, LVar1)
    Add(LVar1, -120)
    Call(NpcMoveTo, NPC_SELF, LVar1, 150, 30 * DT)
    Call(SetNpcAnimation, NPC_SELF, LVar4)
    Call(BindNpcAI, NPC_SELF, LVar5)
    Return
    End
};

EvtScript N(EVS_ReleaseFrom_Door_1) = {
    Call(SetNpcAnimation, NPC_SELF, LVar3)
    Call(SetNpcPos, NPC_SELF, 0, 0, 0)
    Call(RandInt, 40, LVar1)
    Add(LVar1, -20)
    Call(NpcMoveTo, NPC_SELF, LVar1, 150, 30 * DT)
    Call(SetNpcAnimation, NPC_SELF, LVar4)
    Call(BindNpcAI, NPC_SELF, LVar5)
    Return
    End
};

EvtScript N(EVS_ReleaseFrom_Door_2) = {
    Call(SetNpcAnimation, NPC_SELF, LVar3)
    Call(SetNpcPos, NPC_SELF, 100, 0, 0)
    Call(RandInt, 40, LVar1)
    Add(LVar1, 80)
    Call(NpcMoveTo, NPC_SELF, LVar1, 150, 30 * DT)
    Call(SetNpcAnimation, NPC_SELF, LVar4)
    Call(BindNpcAI, NPC_SELF, LVar5)
    Return
    End
};

EvtScript N(EVS_WithdrawTo_Door_0) = {
    Call(SetNpcAnimation, NPC_SELF, LVar3)
    Call(RandInt, 20 * DT, LVar1)
    Add(LVar1, 20 * DT)
    Call(NpcMoveTo, NPC_SELF, -100, 0, LVar1)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Return
    End
};

EvtScript N(EVS_WithdrawTo_Door_1) = {
    Call(SetNpcAnimation, NPC_SELF, LVar3)
    Call(RandInt, 20 * DT, LVar1)
    Add(LVar1, 20 * DT)
    Call(NpcMoveTo, NPC_SELF, 0, 0, LVar1)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Return
    End
};

EvtScript N(EVS_WithdrawTo_Door_2) = {
    Call(SetNpcAnimation, NPC_SELF, LVar3)
    Call(RandInt, 20 * DT, LVar1)
    Add(LVar1, 20 * DT)
    Call(NpcMoveTo, NPC_SELF, 100, 0, LVar1)
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Return
    End
};

EvtScript N(EVS_ReleaseFrom_RandomDoor) = {
    Call(RandInt, 2, LVar0)
    Switch(LVar0)
        CaseEq(0)
            ExecWait(N(EVS_ReleaseFrom_Door_0))
        CaseEq(1)
            ExecWait(N(EVS_ReleaseFrom_Door_1))
        CaseEq(2)
            ExecWait(N(EVS_ReleaseFrom_Door_2))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_WithdrawTo_RandomDoor) = {
    Call(RandInt, 2, LVar0)
    Switch(LVar0)
        CaseEq(0)
            ExecWait(N(EVS_WithdrawTo_Door_0))
        CaseEq(1)
            ExecWait(N(EVS_WithdrawTo_Door_1))
        CaseEq(2)
            ExecWait(N(EVS_WithdrawTo_Door_2))
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcIdle_Goomba) = {
    Return
    End
};

EvtScript N(EVS_Release_Goomba) = {
    Set(LVar3, ANIM_Goomba_Run)
    Set(LVar4, ANIM_Goomba_Idle)
    Set(LVar5, Ref(N(EVS_NpcAI_Short)))
    ExecWait(N(EVS_ReleaseFrom_RandomDoor))
    Return
    End
};

EvtScript N(EVS_Withdraw_Goomba) = {
    Set(LVar3, ANIM_Goomba_Run)
    ExecWait(N(EVS_WithdrawTo_RandomDoor))
    Return
    End
};

EvtScript N(EVS_NpcIdle_ShyGuy) = {
    Return
    End
};

EvtScript N(EVS_Release_RedShyGuy) = {
    Set(LVar3, ANIM_ShyGuy_Red_Anim04)
    Set(LVar4, ANIM_ShyGuy_Red_Anim01)
    Set(LVar5, Ref(N(EVS_NpcAI_ShyGuy)))
    ExecWait(N(EVS_ReleaseFrom_RandomDoor))
    Return
    End
};

EvtScript N(EVS_Withdraw_RedShyGuy) = {
    Set(LVar3, ANIM_ShyGuy_Red_Anim04)
    ExecWait(N(EVS_WithdrawTo_RandomDoor))
    Return
    End
};

EvtScript N(EVS_Release_RedShyGuy_Door_1) = {
    Set(LVar3, ANIM_ShyGuy_Red_Anim04)
    Set(LVar4, ANIM_ShyGuy_Red_Anim01)
    Set(LVar5, Ref(N(EVS_NpcAI_ShyGuy)))
    ExecWait(N(EVS_ReleaseFrom_Door_1))
    Return
    End
};

EvtScript N(EVS_Withdraw_RedShyGuy_Door_1) = {
    Set(LVar3, ANIM_ShyGuy_Red_Anim04)
    ExecWait(N(EVS_WithdrawTo_Door_1))
    Return
    End
};

EvtScript N(EVS_Release_BlueShyGuy) = {
    Set(LVar3, ANIM_ShyGuy_Blue_Anim04)
    Set(LVar4, ANIM_ShyGuy_Blue_Anim01)
    Set(LVar5, Ref(N(EVS_NpcAI_ShyGuy)))
    ExecWait(N(EVS_ReleaseFrom_RandomDoor))
    Return
    End
};

EvtScript N(EVS_Withdraw_BlueShyGuy) = {
    Set(LVar3, ANIM_ShyGuy_Blue_Anim04)
    ExecWait(N(EVS_WithdrawTo_RandomDoor))
    Return
    End
};

EvtScript N(EVS_Release_BlueShyGuy_Door_2) = {
    Set(LVar3, ANIM_ShyGuy_Blue_Anim04)
    Set(LVar4, ANIM_ShyGuy_Blue_Anim01)
    Set(LVar5, Ref(N(EVS_NpcAI_ShyGuy)))
    ExecWait(N(EVS_ReleaseFrom_Door_2))
    Return
    End
};

EvtScript N(EVS_Withdraw_BlueShyGuy_Door_2) = {
    Set(LVar3, ANIM_ShyGuy_Blue_Anim04)
    ExecWait(N(EVS_WithdrawTo_Door_2))
    Return
    End
};

EvtScript N(EVS_Release_GreenShyGuy) = {
    Set(LVar3, ANIM_ShyGuy_Green_Anim04)
    Set(LVar4, ANIM_ShyGuy_Green_Anim01)
    Set(LVar5, Ref(N(EVS_NpcAI_ShyGuy)))
    ExecWait(N(EVS_ReleaseFrom_RandomDoor))
    Return
    End
};

EvtScript N(EVS_Withdraw_GreenShyGuy) = {
    Set(LVar3, ANIM_ShyGuy_Green_Anim04)
    ExecWait(N(EVS_WithdrawTo_RandomDoor))
    Return
    End
};

EvtScript N(EVS_NpcIdle_KoopaTroopa) = {
    Return
    End
};

EvtScript N(EVS_Release_DarkTroopa) = {
    Set(LVar3, ANIM_KoopaTroopa_Dark_Run)
    Set(LVar4, ANIM_KoopaTroopa_Dark_Idle)
    Set(LVar5, Ref(N(EVS_NpcAI_KoopaTroopa)))
    ExecWait(N(EVS_ReleaseFrom_RandomDoor))
    Return
    End
};

EvtScript N(EVS_Withdraw_DarkTroopa) = {
    Set(LVar3, ANIM_KoopaTroopa_Dark_Run)
    ExecWait(N(EVS_WithdrawTo_RandomDoor))
    Return
    End
};

EvtScript N(EVS_Release_KoopaTroopa) = {
    Set(LVar3, ANIM_KoopaTroopa_Run)
    Set(LVar4, ANIM_KoopaTroopa_Idle)
    Set(LVar5, Ref(N(EVS_NpcAI_KoopaTroopa)))
    ExecWait(N(EVS_ReleaseFrom_RandomDoor))
    Return
    End
};

EvtScript N(EVS_Withdraw_KoopaTroopa) = {
    Set(LVar3, ANIM_KoopaTroopa_Run)
    ExecWait(N(EVS_WithdrawTo_RandomDoor))
    Return
    End
};

EvtScript N(EVS_NpcIdle_Bobomb) = {
    Return
    End
};

EvtScript N(EVS_Release_Bobomb) = {
    Set(LVar3, ANIM_WorldBobomb_Green_Run)
    Set(LVar4, ANIM_WorldBobomb_Green_Idle)
    Set(LVar5, Ref(N(EVS_NpcAI_Short)))
    ExecWait(N(EVS_ReleaseFrom_RandomDoor))
    Return
    End
};

EvtScript N(EVS_Withdraw_Bobomb) = {
    Set(LVar3, ANIM_WorldBobomb_Green_Run)
    ExecWait(N(EVS_WithdrawTo_RandomDoor))
    Return
    End
};

EvtScript N(EVS_Release_Bobomb_Door_0) = {
    Set(LVar3, ANIM_WorldBobomb_Green_Run)
    Set(LVar4, ANIM_WorldBobomb_Green_Idle)
    Set(LVar5, Ref(N(EVS_NpcAI_Short)))
    ExecWait(N(EVS_ReleaseFrom_Door_0))
    Return
    End
};

EvtScript N(EVS_Withdraw_Bobomb_Door_0) = {
    Set(LVar3, ANIM_WorldBobomb_Green_Run)
    ExecWait(N(EVS_WithdrawTo_Door_0))
    Return
    End
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
    Switch(AB_KPA82_QuizRound)
        CaseEq(0)
            UseBuf(Ref(N(QS_Release_Wave_0)))
        CaseEq(1)
            UseBuf(Ref(N(QS_Release_Wave_1)))
        CaseEq(2)
            UseBuf(Ref(N(QS_Release_Wave_2)))
        CaseEq(3)
            UseBuf(Ref(N(QS_Release_Wave_3)))
        CaseEq(4)
            UseBuf(Ref(N(QS_Release_Wave_4)))
        CaseEq(5)
            UseBuf(Ref(N(QS_Release_Wave_5)))
        CaseEq(6)
            UseBuf(Ref(N(QS_Release_Wave_6)))
    EndSwitch
    Loop(0)
        BufRead2(LVarA, LVarB)
        IfEq(LVarA, -1)
            BreakLoop
        EndIf
        IfEq(LVarA, -2)
            Wait(LVarB)
        Else
            Call(BindNpcAI, LVarA, LVarB)
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_Withdraw_Wave) = {
    Switch(AB_KPA82_QuizRound)
        CaseEq(0)
            UseBuf(Ref(N(QS_Withdraw_Wave_0)))
        CaseEq(1)
            UseBuf(Ref(N(QS_Withdraw_Wave_1)))
        CaseEq(2)
            UseBuf(Ref(N(QS_Withdraw_Wave_2)))
        CaseEq(3)
            UseBuf(Ref(N(QS_Withdraw_Wave_3)))
        CaseEq(4)
            UseBuf(Ref(N(QS_Withdraw_Wave_4)))
        CaseEq(5)
            UseBuf(Ref(N(QS_Withdraw_Wave_5)))
        CaseEq(6)
            UseBuf(Ref(N(QS_Withdraw_Wave_6)))
    EndSwitch
    Loop(0)
        BufRead2(LVarA, LVarB)
        IfEq(LVarA, -1)
            BreakLoop
        EndIf
        IfEq(LVarA, -2)
            Wait(LVarB)
        Else
            Call(BindNpcAI, LVarA, LVarB)
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_AskQuestion) = {
    ExecWait(N(EVS_SetCam_AskQuestion))
    Switch(AB_KPA82_QuizRound)
        CaseEq(0)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0035)
            Call(ShowChoice, MSG_Choice_0046)
            IfEq(LVar0, 0)
                Set(LVar0, ANSWER_CORRECT)
            Else
                Set(LVar0, ANSWER_WRONG)
            EndIf
        CaseEq(1)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0036)
            Call(ShowChoice, MSG_Choice_0047)
            IfEq(LVar0, 0)
                Set(LVar0, ANSWER_CORRECT)
            Else
                Set(LVar0, ANSWER_WRONG)
            EndIf
        CaseEq(2)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0037)
            Call(ShowChoice, MSG_Choice_0048)
            IfEq(LVar0, 1)
                Set(LVar0, ANSWER_CORRECT)
            Else
                Set(LVar0, ANSWER_WRONG)
            EndIf
        CaseEq(3)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0038)
            Call(ShowChoice, MSG_Choice_0049)
            IfEq(LVar0, 0)
                Set(LVar0, ANSWER_CORRECT)
            Else
                Set(LVar0, ANSWER_WRONG)
            EndIf
        CaseEq(4)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0039)
            Call(ShowChoice, MSG_Choice_004A)
            IfEq(LVar0, 0)
                Set(LVar0, ANSWER_CORRECT)
            Else
                Set(LVar0, ANSWER_WRONG)
            EndIf
        CaseEq(5)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_003A)
            Call(ShowChoice, MSG_Choice_004B)
            IfEq(LVar0, 2)
                Set(LVar0, ANSWER_CORRECT)
            Else
                Set(LVar0, ANSWER_WRONG)
            EndIf
        CaseEq(6)
            Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_003B)
            Call(ShowChoice, MSG_Choice_004C)
            IfEq(LVar0, 1)
                Set(LVar0, ANSWER_CORRECT)
            Else
                Set(LVar0, ANSWER_WRONG)
            EndIf
    EndSwitch
    Set(MV_LastAnswerResult, LVar0)
    Call(CloseMessage)
    Return
    End
};

EvtScript N(EVS_ShowUnknownCard) = {
    Call(EnableModel, MODEL_m_, TRUE)
    Call(MakeLerp, 180, LVar0, 60 * DT, EASING_QUADRATIC_IN)
    Loop(0)
        Call(UpdateLerp)
        IfGe(LVar0, 360)
            Call(RotateGroup, MODEL_g47, LVar0, 0, 1, 0)
            Call(EnableGroup, MODEL_g47, TRUE)
            Call(EnableModel, MODEL_m_, FALSE)
        Else
            Call(RotateModel, MODEL_m_, LVar0, 0, 1, 0)
        EndIf
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_TetherResultCardToDummyPos) = {
    Loop(0)
        Call(GetNpcPos, NPC_Dummy, LVar0, LVar1, LVar2)
        Sub(LVar0, 0)
        Sub(LVar1, 130)
        Sub(LVar2, 50)
        Call(TranslateModel, LVarA, LVar0, LVar1, LVar2)
        IfEq(LVarA, 85)
            Call(RotateModel, MODEL_b_kai, 180, 0, 1, 0)
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_ScaleResultCard) = {
    Call(EnableModel, LVarA, TRUE)
    Call(MakeLerp, 100, 50, 30 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        SetF(LVar6, LVar0)
        MulF(LVar6, Float(0.01))
        Call(ScaleModel, LVarA, LVar6, LVar6, 1)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_MoveCardToScoreboard) = {
    Call(EnableModel, LVarA, TRUE)
    Call(SetNpcPos, NPC_Dummy, 0, 130, 50)
    ExecGetTID(N(EVS_TetherResultCardToDummyPos), LVarB)
    Exec(N(EVS_ScaleResultCard))
    Wait(1)
    Switch(AB_KPA82_QuizRound)
        CaseEq(0)
            Set(LVar0, 118)
            Set(LVar1, 148)
            Set(LVar2, 3)
        CaseEq(1)
            Set(LVar0, 78)
            Set(LVar1, 148)
            Set(LVar2, 3)
        CaseEq(2)
            Set(LVar0, 38)
            Set(LVar1, 148)
            Set(LVar2, 3)
        CaseEq(3)
            Set(LVar0, -1)
            Set(LVar1, 148)
            Set(LVar2, 3)
        CaseEq(4)
            Set(LVar0, -41)
            Set(LVar1, 148)
            Set(LVar2, 3)
        CaseEq(5)
            Set(LVar0, -81)
            Set(LVar1, 148)
            Set(LVar2, 3)
        CaseEq(6)
            Set(LVar0, -121)
            Set(LVar1, 148)
            Set(LVar2, 3)
    EndSwitch
    Call(SetNpcJumpscale, NPC_Dummy, Float(0.0))
    Call(NpcJump1, NPC_Dummy, LVar0, LVar1, LVar2, 30 * DT)
    Call(SetNpcPos, NPC_Dummy, 184, 20, 150)
    KillThread(LVarB)
    Return
    End
};

EvtScript N(EVS_GetCorrectScoreboardModel) = {
    Switch(AB_KPA82_QuizRound)
        CaseEq(0)
            Set(LVar0, MODEL_m1)
        CaseEq(1)
            Set(LVar0, MODEL_m2)
        CaseEq(2)
            Set(LVar0, MODEL_m3)
        CaseEq(3)
            Set(LVar0, MODEL_m4)
        CaseEq(4)
            Set(LVar0, MODEL_m5)
        CaseEq(5)
            Set(LVar0, MODEL_m6)
        CaseEq(6)
            Set(LVar0, MODEL_m7)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_GetWrongScoreboardModel) = {
    Switch(AB_KPA82_QuizRound)
        CaseEq(0)
            Set(LVar0, MODEL_b1)
        CaseEq(1)
            Set(LVar0, MODEL_b2)
        CaseEq(2)
            Set(LVar0, MODEL_b3)
        CaseEq(3)
            Set(LVar0, MODEL_b4)
        CaseEq(4)
            Set(LVar0, MODEL_b5)
        CaseEq(5)
            Set(LVar0, MODEL_b6)
        CaseEq(6)
            Set(LVar0, MODEL_b7)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_ShowResultCard) = {
    Set(LVar6, Float(2.0 / DT))
    ExecWait(N(EVS_SetCam_ViewRoom))
    Wait(5)
    IfEq(MV_LastAnswerResult, ANSWER_CORRECT)
        Set(LVar0, 2160)
        ExecWait(N(EVS_ShowUnknownCard))
        Call(PlaySound, SOUND_APPROVE)
        Wait(10 * DT)
        Call(EnableGroup, MODEL_g47, FALSE)
        Set(LVarA, MODEL_m_kai)
        ExecWait(N(EVS_MoveCardToScoreboard))
        ExecWait(N(EVS_GetCorrectScoreboardModel))
        Call(EnableModel, MODEL_m_kai, FALSE)
        Call(EnableModel, LVar0, TRUE)
        Wait(30 * DT)
    Else
        Set(LVar0, 2340)
        ExecWait(N(EVS_ShowUnknownCard))
        Call(PlaySound, SOUND_MENU_ERROR)
        Wait(10 * DT)
        Call(EnableGroup, MODEL_g47, FALSE)
        Set(LVarA, MODEL_b_kai)
        ExecWait(N(EVS_MoveCardToScoreboard))
        ExecWait(N(EVS_GetWrongScoreboardModel))
        Call(EnableModel, MODEL_b_kai, FALSE)
        Call(EnableModel, LVar0, TRUE)
        Wait(30 * DT)
    EndIf
    ExecWait(N(EVS_SetCam_AfterResult))
    Return
    End
};

EvtScript N(EVS_NpcIdle_Door) = {
    Label(1)
        Wait(1)
        IfEq(GF_KPA82_PassedThroughDoor, FALSE)
            Goto(1)
        EndIf
    Set(GF_KPA82_PassedThroughDoor, FALSE)
    Call(DisablePlayerInput, TRUE)
    ExecWait(N(EVS_SetCam_MeetingDoor))
    Set(MF_Sync_MusicChange, FALSE)
    Thread
        Call(SetMusicTrack, 0, SONG_FINAL_BOWSER_BATTLE, 1, 8)
        Wait(150 * DT)
        IfNe(MF_Sync_MusicChange, FALSE)
            Goto(5)
        EndIf
        Call(FadeOutMusic, 0, 250)
        Wait(15 * DT)
        IfNe(MF_Sync_MusicChange, FALSE)
            Goto(5)
        EndIf
        Exec(N(EVS_SetupMusic))
        Label(5)
    EndThread
    IfEq(GF_KPA82_SpokeToDoor, FALSE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_002E)
        Set(GF_KPA82_SpokeToDoor, TRUE)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_002F)
    EndIf
    Call(ShowChoice, MSG_Choice_0013)
    IfEq(LVar0, 0)
        Call(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0031)
    Else
        Call(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0030)
        Call(ResetCam, CAM_DEFAULT, Float(4.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
        Set(GF_KPA82_PassedThroughDoor, FALSE)
        Call(DisablePlayerInput, FALSE)
        Goto(1)
    EndIf
    Call(ShowChoice, MSG_Choice_0013)
    IfEq(LVar0, 0)
        Call(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0032)
    Else
        Call(ContinueSpeech, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0033)
    EndIf
    Call(DisablePartnerAI, 0)
    Thread
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o166, COLLIDER_FLAGS_UPPER_MASK)
        Call(DisablePlayerPhysics, TRUE)
        Call(SetPlayerSpeed, Float(2.0))
        Call(PlayerMoveTo, 175, 236, 20)
        Call(InterpPlayerYaw, 270, 0)
        Call(DisablePlayerPhysics, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o166, COLLIDER_FLAGS_UPPER_MASK)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        Call(SetNpcSpeed, NPC_PARTNER, Float(2.5))
        Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
        Call(NpcMoveTo, NPC_PARTNER, 205, 236, 20)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        Call(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 0)
    EndThread
    Set(AB_KPA82_QuizRound, 0)
    Set(AB_KPA82_RightAnswers, 0)
    Set(AB_KPA82_WrongAnswers, 0)
    Label(10)
        Set(LVar6, Float(2.0 / DT))
        ExecWait(N(EVS_SetCam_ViewRoom))
        Set(MF_Sync_MusicChange, TRUE)
        Wait(2)
        Call(SetMusicTrack, 0, SONG_NORMAL_BATTLE, 0, 8)
        ExecWait(N(EVS_SetDoorRots))
        ExecWait(N(EVS_Release_Wave))
        Wait(200 * DT)
        Thread
            Call(ShowMessageAtScreenPos, MSG_CH8_0034, 300, 200)
            Set(MV_Sync_TimesUp, TRUE)
        EndThread
        Wait(60 * DT)
        ExecWait(N(EVS_Withdraw_Wave))
        Wait(35 * DT)
        ExecWait(N(EVS_CloseDoors))
        Exec(N(EVS_SetupMusic))
        Wait(30 * DT)
        Label(12)
            Wait(1)
            IfEq(MV_Sync_TimesUp, FALSE)
                Goto(12)
            EndIf
        Set(MV_Sync_TimesUp, FALSE)
        ExecWait(N(EVS_AskQuestion))
        ExecWait(N(EVS_ShowResultCard))
        IfEq(MV_LastAnswerResult, ANSWER_CORRECT)
            Add(AB_KPA82_RightAnswers, 1)
            IfEq(AB_KPA82_RightAnswers, 5)
                Goto(30)
            EndIf
            IfEq(AB_KPA82_RightAnswers, 4)
                Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_003D)
            Else
                Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_003C)
            EndIf
        Else
            Add(AB_KPA82_WrongAnswers, 1)
            IfEq(AB_KPA82_WrongAnswers, 3)
                Goto(20)
            EndIf
            IfEq(AB_KPA82_WrongAnswers, 1)
                Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_003E)
            EndIf
            IfEq(AB_KPA82_WrongAnswers, 2)
                Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0040)
            EndIf
        EndIf
        Add(AB_KPA82_QuizRound, 1)
        Goto(10)
    Label(20)
    Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0041)
    Set(LVar6, Float(2.0 / DT))
    ExecWait(N(EVS_SetCam_ViewRoom))
    Call(SetNpcPos, NPC_AntiGuy_01, -100, 0, 0)
    Call(SetNpcPos, NPC_AntiGuy_02, 0, 0, 0)
    Call(SetNpcPos, NPC_AntiGuy_03, 100, 0, 0)
    Call(InterpPlayerYaw, 315, 0)
    Call(InterpNpcYaw, NPC_PARTNER, 315, 0)
    ExecWait(N(EVS_SetDoorRots))
    Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0042)
    Call(PlayerFaceNpc, NPC_AntiGuy_02, 5)
    Call(GetPlayerPos, LVar3, LVar4, LVar5)
    Set(LVar6, Float(3.0 / DT))
    ExecWait(N(EVS_SetCam_BeforeBattle))
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Thread
        Call(SetNpcAnimation, NPC_AntiGuy_01, ANIM_ShyGuy_Black_Anim04)
        Call(NpcMoveTo, NPC_AntiGuy_01, LVar0, LVar2, 30 * DT)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_AntiGuy_02, ANIM_ShyGuy_Black_Anim04)
        Call(NpcMoveTo, NPC_AntiGuy_02, LVar0, LVar2, 30 * DT)
    EndThread
    Thread
        Call(SetNpcAnimation, NPC_AntiGuy_03, ANIM_ShyGuy_Black_Anim04)
        Call(NpcMoveTo, NPC_AntiGuy_03, LVar0, LVar2, 30 * DT)
    EndThread
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    ExecWait(N(EVS_SetCam_AfterBattle))
    Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_0043)
    Goto(40)
    Label(30)
    Thread
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o166, COLLIDER_FLAGS_UPPER_MASK)
        Call(DisablePlayerPhysics, TRUE)
        Call(SetPlayerSpeed, Float(3.0 / DT))
        Call(PlayerMoveTo, 120, 145, 0)
        Call(InterpPlayerYaw, 90, 0)
        Call(DisablePlayerPhysics, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_o166, COLLIDER_FLAGS_UPPER_MASK)
    EndThread
    Thread
        Call(DisablePartnerAI, 0)
        Call(SetNpcSpeed, NPC_PARTNER, Float(3.5 * DT))
        Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
        Call(NpcMoveTo, NPC_PARTNER, 80, 145, 0)
        Call(EnablePartnerAI)
    EndThread
    Call(SpeakToPlayer, NPC_SELF, ANIM_ShyGuy_Black_Anim01, ANIM_ShyGuy_Black_Anim01, 0, MSG_CH8_003F)
    Label(40)
    Call(EnablePartnerAI)
    Call(PanToTarget, CAM_DEFAULT, 0, 0)
    Set(GB_KPA82_BowserDoorState, 1)
    Call(DisablePlayerInput, FALSE)
    BindTrigger(Ref(N(EVS_ExitDoors_kpa_61_0)), TRIGGER_WALL_PRESS_A, COLLIDER_o166, 1, 0)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Door) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(SetNpcPos, NPC_AntiGuy_01, NPC_DISPOSE_LOCATION)
            Call(SetNpcPos, NPC_AntiGuy_02, NPC_DISPOSE_LOCATION)
            Call(SetNpcPos, NPC_AntiGuy_03, NPC_DISPOSE_LOCATION)
            Call(SetPlayerPos, 120, 0, 145)
            Call(SetNpcPos, NPC_PARTNER, 80, 0, 145)
            Call(InterpPlayerYaw, 90, 0)
            Call(InterpNpcYaw, NPC_PARTNER, 90, 0)
            Call(TranslateModel, MODEL_o100, 0, 0, 0)
            Call(TranslateModel, MODEL_o101, 0, 0, 0)
            Call(TranslateModel, MODEL_o145, 0, 0, 0)
            Call(TranslateModel, MODEL_o146, 0, 0, 0)
            Call(TranslateModel, MODEL_o102, 0, 0, 0)
            Call(TranslateModel, MODEL_o103, 0, 0, 0)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_Door) = {
    IfEq(GB_KPA82_BowserDoorState, 0)
        Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Door)))
    EndIf
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_Door)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_10000000, TRUE)
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcPos, NPC_SELF, 184, 20, 150)
    Return
    End
};

EvtScript N(EVS_NpcInit_Goomba) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Goomba)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_ShyGuy) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_ShyGuy)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopaTroopa) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_KoopaTroopa)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Bobomb) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Bobomb)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    Return
    End
};

EvtScript N(EVS_NpcInit_AntiGuy) = {
    Return
    End
};

NpcData N(NpcData_AntiGuys)[] = {
    {
        .id = NPC_Dummy,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_Door),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_HAS_NO_SPRITE | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = ANTI_GUY_ANIMS,
    },
    {
        .id = NPC_AntiGuy_01,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_AntiGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = ANTI_GUY_ANIMS,
    },
    {
        .id = NPC_AntiGuy_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_AntiGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
        .drops = NO_DROPS,
        .animations = ANTI_GUY_ANIMS,
    },
    {
        .id = NPC_AntiGuy_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_AntiGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
        .flags = ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_100000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS | ENEMY_FLAG_IGNORE_TOUCH | ENEMY_FLAG_IGNORE_JUMP,
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
