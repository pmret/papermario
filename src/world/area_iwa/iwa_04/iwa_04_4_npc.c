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
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BUZZAR_FLAP, SOUND_SPACE_DEFAULT)
        EVT_WAIT(16)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MonitorFlyingAnimation) = {
    EVT_LOOP(0)
        EVT_LOOP(0)
            EVT_CALL(GetNpcAnimation, NPC_SELF, LVar0)
            EVT_IF_EQ(LVar0, ANIM_Buzzar_Anim02)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_EXEC_GET_TID(N(EVS_FlapWingSounds), LVarA)
        EVT_LOOP(0)
            EVT_CALL(GetNpcAnimation, NPC_SELF, LVar0)
            EVT_IF_NE(LVar0, ANIM_Buzzar_Anim02)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_KILL_THREAD(LVarA)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAuxAI_Buzzar) = {
    EVT_IF_EQ(GF_IWA04_Defeated_Buzzar, TRUE)
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_ELSE
        EVT_EXEC(N(EVS_MonitorFlyingAnimation))
        EVT_CALL(SetNpcPos, NPC_SELF, 10, 96, -347)
        EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAI_Buzzar) = {
    EVT_LOOP(0)
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_CALL(GetNpcPos, NPC_Buzzar, LVar3, LVar4, LVar5)
        EVT_IF_LT(LVar0, LVar3)
            EVT_CALL(InterpNpcYaw, NPC_Buzzar, 270, 0)
        EVT_ELSE
            EVT_CALL(InterpNpcYaw, NPC_Buzzar, 90, 0)
        EVT_END_IF
        EVT_IF_GE(LVar0, 400)
            EVT_IF_LT(LVar0, 450)
                EVT_IF_LT(LVar2, 100)
                    EVT_BREAK_LOOP
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(SetMusicTrack, 0, SONG_MINIBOSS_BATTLE, 0, 8)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(InterruptUsePartner)
        EVT_WAIT(5 * DT)
    EVT_END_IF
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH2_0030, 160, 40)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_ADD(LVar1, 15)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(GetAngleToPlayer, NPC_SELF, LVarA)
    EVT_WAIT(4 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 430, 0, -25)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(1)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 30, 180, -600)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(100.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Buzzar_Anim05, ANIM_Buzzar_Anim05, 5, MSG_CH2_0031)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Buzzar_Anim02)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
    EVT_SET(LVar5, LVar3)
    EVT_ADD(LVar5, 150)
    EVT_CALL(MakeLerp, LVar3, LVar5, 15 * DT, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcPos, NPC_SELF, LVar2, LVar0, LVar4)
        EVT_WAIT(5)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetPlayerPos, 430, 0, -25)
    EVT_CALL(func_802CF56C, 2)
    EVT_CALL(SetNpcPos, NPC_SELF, 538, 200, -25)
    EVT_CALL(EnableNpcShadow, NPC_SELF, TRUE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, 0, 0)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, 100, -100)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 600)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_THREAD
        EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
        EVT_ADD(LVar0, 40)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 500)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, EVT_FLOAT(0.5), 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(func_802CF56C, 2)
    EVT_END_THREAD
    EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
    EVT_CALL(SetPlayerAnimation, ANIM_Mario1_LookUp)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
    EVT_SET(LVar5, LVar3)
    EVT_SUB(LVar5, 150)
    EVT_CALL(MakeLerp, LVar3, LVar5, 15 * DT, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetNpcPos, NPC_SELF, LVar2, LVar0, LVar4)
        EVT_WAIT(5)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_Buzzar, ANIM_Buzzar_Anim01)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Buzzar, ANIM_Buzzar_Anim07)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Buzzar, ANIM_Buzzar_Anim08)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Buzzar, ANIM_Buzzar_Anim09)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Buzzar, ANIM_Buzzar_Anim0A)
    EVT_WAIT(30 * DT)
    EVT_CALL(SetNpcAnimation, NPC_Buzzar, ANIM_Buzzar_Anim01)
    EVT_WAIT(30 * DT)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, 0, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 275)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Buzzar_Anim03, ANIM_Buzzar_Anim01, 0, MSG_CH2_0032)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(90.0), 50, 350, EVT_FLOAT(15.0), EVT_FLOAT(-12.0))
    EVT_CALL(ShowChoice, MSG_Choice_0017)
    EVT_CALL(EndSpeech, NPC_SELF, ANIM_Buzzar_Anim03, ANIM_Buzzar_Anim01, 0)
    EVT_SET(LVarA, LVar0)
    EVT_SWITCH(LVarA)
        EVT_CASE_EQ(0)
            EVT_SET(LVarB, MSG_CH2_0033)
            EVT_SET(LVarC, ANIM_Buzzar_Anim04)
        EVT_CASE_EQ(1)
            EVT_SET(LVarB, MSG_CH2_0034)
            EVT_SET(LVarC, ANIM_Buzzar_Anim03)
        EVT_CASE_EQ(2)
            EVT_SET(LVarB, MSG_CH2_0035)
            EVT_SET(LVarC, ANIM_Buzzar_Anim04)
    EVT_END_SWITCH
    EVT_WAIT(10 * DT)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, 0, LVar2)
    EVT_ADD(LVar1, 20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, 275)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(10 * DT)
    EVT_CALL(SpeakToPlayer, NPC_SELF, LVarC, ANIM_Buzzar_Anim01, 0, LVarB)
    EVT_IF_EQ(LVarA, 1)
        EVT_EXEC(N(EVS_SetupMusic))
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Buzzar_Anim06)
        EVT_WAIT(30 * DT)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Buzzar_Anim02)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
        EVT_CALL(GetNpcPos, NPC_SELF, LVar2, LVar3, LVar4)
        EVT_SET(LVar5, LVar3)
        EVT_ADD(LVar5, 150)
        EVT_CALL(MakeLerp, LVar3, LVar5, 15 * DT, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar2, LVar0, LVar4)
            EVT_WAIT(5)
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, NPC_SELF, 10, 96, -347)
        EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Buzzar_Anim05)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0 / DT))
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_ELSE
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
        EVT_WAIT(5 * DT)
        EVT_CALL(DisablePlayerInput, FALSE)
        EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_Buzzar) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_SET(GF_IWA04_Defeated_Buzzar, TRUE)
            EVT_EXEC(N(EVS_SetupMusic))
            EVT_CALL(SetNpcPos, NPC_SELF, 530, 15, -20)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Buzzar_Anim0B)
            EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(90.0), 50, 350, EVT_FLOAT(15.0), EVT_FLOAT(-12.0))
            EVT_WAIT(10 * DT)
            EVT_CALL(SpeakToPlayer, NPC_SELF, -1, -1, 0, MSG_CH2_0036)
            EVT_THREAD
                EVT_CALL(GetNpcYaw, NPC_SELF, LVar0)
                EVT_LOOP(55)
                    EVT_ADD(LVar0, 30)
                    EVT_CALL(SetNpcRotation, NPC_SELF, 0, LVar0, 0)
                    EVT_WAIT(1)
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.75))
            EVT_CALL(NpcJump1, NPC_SELF, 400, -200, -300, 60 * DT)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(2.5 / DT))
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
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
