#include "iwa_04.h"
#include "sprite/player.h"

#include "world/common/enemy/Cleft.inc.c"

API_CALLABLE(N(func_80241060_91C940)) {
    gCameras[CAM_DEFAULT].yinterpAlpha = 1.0f;
    return ApiStatus_BLOCK;
}

API_CALLABLE(N(func_8024107C_91C95C)) {
    Bytecode* args = script->ptrReadPos;
    Npc* npc = resolve_npc(script, NPC_SELF);
    npc->renderYaw = (f32) evt_get_variable(script, *args++);
    return ApiStatus_DONE2;
}

EvtScript N(EVS_FlapWingSounds) = {
    Loop(0)
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_BUZZAR_FLAP, SOUND_SPACE_DEFAULT)
        Wait(16)
    EndLoop
    Return
    End
};

EvtScript N(EVS_MonitorFlyingAnimation) = {
    Loop(0)
        Loop(0)
            Call(GetNpcAnimation, NPC_SELF, LVar0)
            IfEq(LVar0, ANIM_Buzzar_Anim02)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        ExecGetTID(N(EVS_FlapWingSounds), LVarA)
        Loop(0)
            Call(GetNpcAnimation, NPC_SELF, LVar0)
            IfNe(LVar0, ANIM_Buzzar_Anim02)
                BreakLoop
            EndIf
            Wait(1)
        EndLoop
        KillThread(LVarA)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcAuxAI_Buzzar) = {
    IfEq(GF_IWA04_Defeated_Buzzar, TRUE)
        Call(RemoveNpc, NPC_SELF)
    Else
        Exec(N(EVS_MonitorFlyingAnimation))
        Call(SetNpcPos, NPC_SELF, 10, 96, -347)
        Call(EnableNpcShadow, NPC_SELF, FALSE)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcAI_Buzzar) = {
    Loop(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(GetNpcPos, NPC_Buzzar, LVar3, LVar4, LVar5)
        IfLt(LVar0, LVar3)
            Call(InterpNpcYaw, NPC_Buzzar, 270, 0)
        Else
            Call(InterpNpcYaw, NPC_Buzzar, 90, 0)
        EndIf
        IfGe(LVar0, 400)
            IfLt(LVar0, 450)
                IfLt(LVar2, 100)
                    BreakLoop
                EndIf
            EndIf
        EndIf
        Wait(1)
    EndLoop
    Call(SetMusicTrack, 0, SONG_MINIBOSS_BATTLE, 0, 8)
    Call(DisablePlayerInput, TRUE)
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, 0)
        Call(InterruptUsePartner)
        Wait(5 * DT)
    EndIf
    Call(NpcFacePlayer, NPC_SELF, 0)
    Call(ShowMessageAtScreenPos, MSG_CH2_0030, 160, 40)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Add(LVar1, 15)
    Call(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(GetAngleToPlayer, NPC_SELF, LVarA)
    Wait(4 * DT)
    Call(UseSettingsFrom, CAM_DEFAULT, 430, 0, -25)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(1)
    Call(SetPanTarget, CAM_DEFAULT, 30, 180, -600)
    Call(SetCamDistance, CAM_DEFAULT, Float(100.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(SpeakToPlayer, NPC_SELF, ANIM_Buzzar_Anim05, ANIM_Buzzar_Anim05, 5, MSG_CH2_0031)
    Call(SetNpcAnimation, NPC_SELF, ANIM_Buzzar_Anim02)
    Call(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
    Set(LVar5, LVar3)
    Add(LVar5, 150)
    Call(MakeLerp, LVar3, LVar5, 15 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcPos, NPC_SELF, LVar2, LVar0, LVar4)
        Wait(5)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetPlayerPos, 430, 0, -25)
    Call(func_802CF56C, 2)
    Call(SetNpcPos, NPC_SELF, 538, 200, -25)
    Call(EnableNpcShadow, NPC_SELF, TRUE)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamPosA, CAM_DEFAULT, 0, 0)
    Call(SetCamPosB, CAM_DEFAULT, 100, -100)
    Call(SetCamDistance, CAM_DEFAULT, 600)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Thread
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Add(LVar0, 40)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamDistance, CAM_DEFAULT, 500)
        Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
        Call(PanToTarget, CAM_DEFAULT, Float(0.5), 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(func_802CF56C, 2)
    EndThread
    Call(PlayerFaceNpc, NPC_SELF, FALSE)
    Call(SetPlayerAnimation, ANIM_Mario1_LookUp)
    Call(NpcFacePlayer, NPC_SELF, 0)
    Call(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
    Set(LVar5, LVar3)
    Sub(LVar5, 150)
    Call(MakeLerp, LVar3, LVar5, 15 * DT, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetNpcPos, NPC_SELF, LVar2, LVar0, LVar4)
        Wait(5)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(SetNpcAnimation, NPC_Buzzar, ANIM_Buzzar_Anim01)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_Buzzar, ANIM_Buzzar_Anim07)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_Buzzar, ANIM_Buzzar_Anim08)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_Buzzar, ANIM_Buzzar_Anim09)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_Buzzar, ANIM_Buzzar_Anim0A)
    Wait(30 * DT)
    Call(SetNpcAnimation, NPC_Buzzar, ANIM_Buzzar_Anim01)
    Wait(30 * DT)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, 0, LVar2)
    Add(LVar1, 20)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 275)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_SELF, ANIM_Buzzar_Anim03, ANIM_Buzzar_Anim01, 0, MSG_CH2_0032)
    Call(AdjustCam, CAM_DEFAULT, Float(90.0), 50, 350, Float(15.0), Float(-12.0))
    Call(ShowChoice, MSG_Choice_0017)
    Call(EndSpeech, NPC_SELF, ANIM_Buzzar_Anim03, ANIM_Buzzar_Anim01, 0)
    Set(LVarA, LVar0)
    Switch(LVarA)
        CaseEq(0)
            Set(LVarB, MSG_CH2_0033)
            Set(LVarC, ANIM_Buzzar_Anim04)
        CaseEq(1)
            Set(LVarB, MSG_CH2_0034)
            Set(LVarC, ANIM_Buzzar_Anim03)
        CaseEq(2)
            Set(LVarB, MSG_CH2_0035)
            Set(LVarC, ANIM_Buzzar_Anim04)
    EndSwitch
    Wait(10 * DT)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, 0, LVar2)
    Add(LVar1, 20)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    Call(SetCamDistance, CAM_DEFAULT, 275)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(10 * DT)
    Call(SpeakToPlayer, NPC_SELF, LVarC, ANIM_Buzzar_Anim01, 0, LVarB)
    IfEq(LVarA, 1)
        Exec(N(EVS_SetupMusic))
        Call(SetNpcAnimation, NPC_SELF, ANIM_Buzzar_Anim06)
        Wait(30 * DT)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Buzzar_Anim02)
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
        Call(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
        Set(LVar5, LVar3)
        Add(LVar5, 150)
        Call(MakeLerp, LVar3, LVar5, 15 * DT, EASING_LINEAR)
        Loop(0)
            Call(UpdateLerp)
            Call(SetNpcPos, NPC_SELF, LVar2, LVar0, LVar4)
            Wait(5)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(SetNpcPos, NPC_SELF, 10, 96, -347)
        Call(EnableNpcShadow, NPC_SELF, FALSE)
        Call(SetNpcAnimation, NPC_SELF, ANIM_Buzzar_Anim05)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(SetCamSpeed, CAM_DEFAULT, Float(1.0 / DT))
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
        Call(DisablePlayerInput, FALSE)
    Else
        Call(PanToTarget, CAM_DEFAULT, 0, 0)
        Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
        Wait(5 * DT)
        Call(DisablePlayerInput, FALSE)
        Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    EndIf
    Return
    End
};

EvtScript N(EVS_NpcDefeat_Buzzar) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Set(GF_IWA04_Defeated_Buzzar, TRUE)
            Exec(N(EVS_SetupMusic))
            Call(SetNpcPos, NPC_SELF, 530, 15, -20)
            Call(SetNpcAnimation, NPC_SELF, ANIM_Buzzar_Anim0B)
            Call(AdjustCam, CAM_DEFAULT, Float(90.0), 50, 350, Float(15.0), Float(-12.0))
            Wait(10 * DT)
            Call(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH2_0036)
            Thread
                Call(GetNpcYaw, NPC_SELF, LVar0)
                Loop(55)
                    Add(LVar0, 30)
                    Call(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
                    Wait(1)
                EndLoop
            EndThread
            Call(SetNpcJumpscale, NPC_SELF, Float(0.75))
            Call(NpcJump1, NPC_SELF, 400, -200, -300, 60 * DT)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            Call(ResetCam, CAM_DEFAULT, Float(2.5 / DT))
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

NpcSettings N(NpcSettings_Buzzar) = {
    .defaultAnim = ANIM_Buzzar_Anim05,
    .height = 32,
    .radius = 32,
    .otherAI = &N(EVS_NpcAuxAI_Buzzar),
    .ai = &N(EVS_NpcAI_Buzzar),
    .onDefeat = &N(EVS_NpcDefeat_Buzzar),
};

NpcData N(NpcData_Cleft) = {
    .id = NPC_Cleft,
    .pos = { -412.0f, -250.0f, 143.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -412, -250, 143 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { -355, -250, 105 },
            .detectSize = { 175, 195 },
        }
    },
    .settings = &N(NpcSettings_Cleft),
    .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING,
    .drops = CLEFT_DROPS,
    .animations = CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Buzzar) = {
    .id = NPC_Buzzar,
    .pos = { NPC_DISPOSE_LOCATION },
    .yaw = 270,
    .settings = &N(NpcSettings_Buzzar),
    .flags = ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN | ENEMY_FLAG_NO_DROPS,
    .drops = {
        .dropFlags = NPC_DROP_FLAG_80,
        .heartDrops  = STANDARD_HEART_DROPS(3),
        .flowerDrops = STANDARD_FLOWER_DROPS(2),
        .minCoinBonus = 1,
        .maxCoinBonus = 3,
    },
    .animations = {
        .idle   = ANIM_Buzzar_Anim01,
        .walk   = ANIM_Buzzar_Anim01,
        .run    = ANIM_Buzzar_Anim01,
        .chase  = ANIM_Buzzar_Anim01,
        .anim_4 = ANIM_Buzzar_Anim01,
        .anim_5 = ANIM_Buzzar_Anim01,
        .death  = ANIM_Buzzar_Anim0B,
        .hit    = ANIM_Buzzar_Anim0B,
        .anim_8 = ANIM_Buzzar_Anim01,
        .anim_9 = ANIM_Buzzar_Anim01,
        .anim_A = ANIM_Buzzar_Anim01,
        .anim_B = ANIM_Buzzar_Anim01,
        .anim_C = ANIM_Buzzar_Anim01,
        .anim_D = ANIM_Buzzar_Anim01,
        .anim_E = ANIM_Buzzar_Anim01,
        .anim_F = ANIM_Buzzar_Anim01,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Cleft), BTL_IWA_FORMATION_01, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_Buzzar), BTL_IWA_FORMATION_0C, BTL_IWA_STAGE_02),
    {}
};
