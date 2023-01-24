#include "omo_15.h"

NpcSettings N(NpcSettings_GeneralGuy) = {
    .height = 23,
    .radius = 22,
    .level = 14,
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

s32 N(D_80240F2C_DE969C)[] = {
    8, -35, -240, 7, -5, -180, 6, 10, 
    -120, 6, 25, -60, 6, 25, 60, 6, 
    10, 120, 7, -5, 180, 8, -35, 240, 
    6, 30, 0, 
};

EvtScript N(D_80240F98_DE9708) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(30)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(GetPartnerInUse, LVar0)
        EVT_IF_NE(LVar0, PARTNER_NONE)
            EVT_CALL(InterruptUsePartner)
            EVT_WAIT(30)
            EVT_CALL(func_802D2C14, 1)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_100, TRUE)
            EVT_WAIT(45)
            EVT_CALL(func_802D2C14, 0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_GeneralGuy, ANIM_GeneralGuy_Anim0A, ANIM_GeneralGuy_Anim02, 0, MSG_CH4_005F)
    EVT_WAIT(10)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 250, -50, 10)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 250, -50, 10)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(205.0), EVT_FLOAT(11.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_GeneralGuy, ANIM_GeneralGuy_Anim0A, ANIM_GeneralGuy_Anim02, 0, MSG_CH4_0060)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_GeneralGuy, ANIM_GeneralGuy_Anim0A, ANIM_GeneralGuy_Anim02, 0, MSG_CH4_0061)
    EVT_WAIT(20)
    EVT_CALL(SpeakToPlayer, NPC_GeneralGuy, ANIM_GeneralGuy_Anim0A, ANIM_GeneralGuy_Anim02, 0, MSG_CH4_0062)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -200, 0, 0)
    EVT_SET(LVar0, 1)
    EVT_LOOP(9)
        EVT_CALL(SetNpcAnimation, LVar0, ANIM_ShyGuy_Red_Anim02)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_GeneralGuy, ANIM_GeneralGuy_Anim0C)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH4_0063, 160, 40)
    EVT_CALL(SetNpcAnimation, NPC_GeneralGuy, ANIM_GeneralGuy_Anim02)
    EVT_WAIT(20)
    EVT_SET(LVar0, 1)
    EVT_LOOP(9)
        EVT_CALL(SetNpcAnimation, LVar0, ANIM_ShyGuy_Red_Anim01)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(SpeakToPlayer, NPC_GeneralGuy, ANIM_GeneralGuy_Anim02, ANIM_GeneralGuy_Anim0A, 0, MSG_CH4_0064)
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySound, SOUND_8000004D)
        EVT_SET(LVar0, 1)
        EVT_LOOP(9)
            EVT_CALL(SetNpcVar, LVar0, 0, 10)
            EVT_ADD(LVar0, 1)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_LOOP(30)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(330.0))
        EVT_WAIT(1)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(320.0))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(LVar0, 1)
    EVT_USE_BUF(EVT_PTR(N(D_80240F2C_DE969C)))
    EVT_LOOP(9)
        EVT_BUF_READ3(LVar1, LVar2, LVar3)
        EVT_CALL(SetNpcSpeed, LVar0, LVar1)
        EVT_CALL(SetNpcPos, LVar0, LVar2, 0, LVar3)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_WAIT(20)
    EVT_LABEL(5)
    EVT_CALL(GetNpcVar, NPC_ShyGuy_09, 0, LVar0)
    EVT_IF_NE(LVar0, 40)
        EVT_WAIT(1)
        EVT_GOTO(5)
    EVT_END_IF
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_EQ(LVar0, PARTNER_WATT)
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SpeakToPlayer, NPC_PARTNER, PARTNER_ANIM_TALK, PARTNER_ANIM_IDLE, 0, MSG_CH4_0075)
        EVT_CALL(EnablePartnerAI)
    EVT_END_IF
    EVT_CALL(InterpPlayerYaw, 90, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 150, 0, 0)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(FadeOutMusic, 0, 3000)
    EVT_EXEC(N(EVS_TrySpawningStarCard))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

s32 N(D_8024157C_DE9CEC)[] = {
1, 65, 0, 87, 0, 17, 46, 1,
-24, 0, -11, 0, -63, -16, 0, -120,
43, 1, -172, 0, 25, 0, -234, 23,
0, -320, 30, 0, -400, 0, -1,
};

s32 N(D_802415F8_DE9D68)[] = {
0, 29, -72, 0, -19, -104, 0, -60,
-67, 0, -106, -50, 0, -168, -100, 0,
-279, -20, 0, -400, 0, -1,
};

s32 N(D_80241650_DE9DC0)[] = {
1, -30, 0, 27, 0, -123, -13, 0,
-168, 73, 0, -120, 103, 0, -155, 21,
0, -208, 43, 0, -256, 84, 0, -326,
42, 0, -400, 0, -1,
};

s32 N(D_802416C4_DE9E34)[] = {
0, 133, -3, 0, 84, 27, 0, 25,
0, 0, -31, -23, 0, -97, 0, -50,
0, -150, -75, 0, -230, -90, 0, -309,
-55, 0, -400, 0, -1,
};

s32 N(D_80241738_DE9EA8)[] = {
0, -40, 200, 0, -100, 256, 0, -180,
270, 0, -210, 200, 0, -179, 102, 1,
-167, 0, 52, 0, -261, 118, 0, -400,
0, -1,
};

s32 N(D_802417A0_DE9F10)[] = {
0, -97, -24, 0, -25, 300, 0, 100,
0, 0, -50, 50, 0, -100, 30, 0,
-160, 63, 2, 0, -400, 0, -1,
};

s32 N(D_802417FC_DE9F6C)[] = {
0, -153, 0, 0, -170, 70, 0, -208,
80, 0, -246, 70, 0, -263, 0, 0,
-246, -70, 0, -208, -80, 0, -170, -70,
0, -153, 0, 0, -170, 70, 0, -208,
80, 0, -400, 0, -1,
};

s32* N(D_80241890_DEA000)[] = {
    N(D_8024157C_DE9CEC), N(D_802415F8_DE9D68), N(D_80241650_DE9DC0), N(D_802416C4_DE9E34), N(D_80241738_DE9EA8), N(D_802415F8_DE9D68), N(D_8024157C_DE9CEC), N(D_802416C4_DE9E34), 
    N(D_802417A0_DE9F10), 
};

s32* N(D_802418B4_DEA024)[] = {
    N(D_802417FC_DE9F6C), 
};

s32 N(D_802418B8_DEA028)[] = {
    -238, -55, 0, -218, -60, 0, -198, -60, 
    0, -178, -50, 0, -178, 35, 0, -192, 
    50, 0, -210, 60, 0, -228, 55, 0, 
    -165, -10, 0, 
};

s32 N(D_80241924_DEA094)[] = {
    -182, 0, 0, 
};

EvtScript N(EVS_NpcIdle_ShyGuy_01) = {
    EVT_LABEL(0)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(10)
            EVT_THREAD
                EVT_CALL(GetSelfNpcID, LVar0)
                EVT_SUB(LVar0, 0)
                EVT_USE_BUF(EVT_PTR(N(D_802418B8_DEA028)))
                EVT_LOOP(LVar0)
                    EVT_BUF_READ3(LVar1, LVar2, LVar3)
                EVT_END_LOOP
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
                EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0))
                EVT_CALL(NpcMoveTo, NPC_SELF, LVar1, LVar2, LVar3)
            EVT_END_THREAD
            EVT_WAIT(60)
            EVT_CALL(GetSelfNpcID, LVar0)
            EVT_CALL(SetSelfVar, 0, 0)
            EVT_IF_EQ(LVar0, 9)
                EVT_THREAD
                    EVT_WAIT(20)
                    EVT_CALL(StopSound, SOUND_8000004D)
                EVT_END_THREAD
                EVT_CALL(StartBossBattle, SONG_GENERAL_GUY_BATTLE)
            EVT_END_IF
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80241AC4_DEA234) = {
    EVT_CALL(GetSelfNpcID, LVar9)
    EVT_IF_EQ(LVar9, 0)
        EVT_CALL(PlaySound, SOUND_8000004D)
        EVT_USE_BUF(EVT_PTR(N(D_802418B4_DEA024)))
        EVT_BUF_READ1(LVar1)
        EVT_USE_BUF(LVar1)
        EVT_CALL(SetNpcAnimation, LVar9, ANIM_GeneralGuy_Anim0E)
        EVT_LOOP(0)
            EVT_BUF_READ1(LVar2)
            EVT_SWITCH(LVar2)
                EVT_CASE_EQ(0)
                    EVT_BUF_READ2(LVar3, LVar4)
                    EVT_CALL(SetNpcSpeed, NPC_GeneralGuy, EVT_FLOAT(8.0))
                    EVT_CALL(NpcMoveTo, NPC_GeneralGuy, LVar3, LVar4, 0)
                EVT_CASE_EQ(1)
                    EVT_BUF_READ3(LVar3, LVar4, LVar5)
                    EVT_CALL(SetNpcJumpscale, NPC_GeneralGuy, EVT_FLOAT(1.0))
                    EVT_CALL(NpcJump0, NPC_GeneralGuy, LVar3, LVar4, LVar5, 10)
            EVT_END_SWITCH
            EVT_IF_EQ(LVar2, -1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySound, SOUND_76D)
        EVT_CALL(func_802D62E4, SOUND_36D)
    EVT_ELSE
        EVT_SET(LVar0, LVar9)
        EVT_SUB(LVar0, 0)
        EVT_USE_BUF(EVT_PTR(N(D_80241890_DEA000)))
        EVT_LOOP(LVar0)
            EVT_BUF_READ1(LVar1)
        EVT_END_LOOP
        EVT_USE_BUF(LVar1)
        EVT_LOOP(0)
            EVT_BUF_READ1(LVar2)
            EVT_SWITCH(LVar2)
                EVT_CASE_EQ(0)
                    EVT_BUF_READ2(LVar3, LVar4)
                    EVT_CALL(SetNpcAnimation, LVar9, ANIM_ShyGuy_Red_Anim04)
                    EVT_CALL(SetNpcSpeed, LVar9, EVT_FLOAT(8.0))
                    EVT_CALL(NpcMoveTo, LVar9, LVar3, LVar4, 0)
                EVT_CASE_EQ(1)
                    EVT_BUF_READ3(LVar3, LVar4, LVar5)
                    EVT_CALL(SetNpcJumpscale, LVar9, EVT_FLOAT(1.0))
                    EVT_CALL(NpcJump0, LVar9, LVar3, LVar4, LVar5, 10)
                EVT_CASE_EQ(2)
                    EVT_CALL(func_802CDE68, LVar9, 10)
                    EVT_THREAD
                        EVT_SET(LVar3, 0)
                        EVT_LOOP(10)
                            EVT_ADD(LVar3, 9)
                            EVT_CALL(SetNpcRotation, LVar9, 0, 0, LVar3)
                            EVT_WAIT(1)
                        EVT_END_LOOP
                    EVT_END_THREAD
                    EVT_CALL(NpcJump0, LVar9, -180, 0, 63, 4)
                    EVT_THREAD
                        EVT_WAIT(10)
                        EVT_CALL(SetNpcRotation, LVar9, 0, 0, 0)
                        EVT_CALL(SetNpcAnimation, LVar9, ANIM_ShyGuy_Red_Anim10)
                        EVT_CALL(PlayerFaceNpc, LVar9, 3)
                        EVT_CALL(NpcFaceNpc, NPC_PARTNER, LVar9, 3)
                    EVT_END_THREAD
                    EVT_CALL(NpcJump0, LVar9, -220, 0, 63, 10)
                    EVT_CALL(PlaySoundAtNpc, LVar9, SOUND_MISS_JUMP, 0)
                    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
                    EVT_WAIT(50)
                    EVT_LOOP(2)
                        EVT_CALL(PlaySoundAtNpc, LVar9, SOUND_3E4, 0)
                        EVT_WAIT(7)
                    EVT_END_LOOP
                    EVT_WAIT(6)
                    EVT_CALL(func_802CDE68, LVar9, 0)
                    EVT_CALL(SetNpcAnimation, LVar9, ANIM_ShyGuy_Red_Anim01)
                    EVT_CALL(NpcJump0, LVar9, -230, 0, 63, 10)
                    EVT_CALL(InterpNpcYaw, LVar9, 90, 0)
                    EVT_WAIT(20)
                    EVT_THREAD
                        EVT_CALL(PlaySoundAtNpc, LVar9, SOUND_3A2, 0)
                        EVT_WAIT(45)
                        EVT_CALL(StopSound, SOUND_3A2)
                        EVT_CALL(SetNpcVar, NPC_ShyGuy_09, 0, 40)
                    EVT_END_THREAD
            EVT_END_SWITCH
            EVT_IF_EQ(LVar2, -1)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(SetNpcFlagBits, LVar9, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcPos, LVar9, 0, -1000, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_GeneralGuy) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
            EVT_CALL(GetSelfNpcID, LVar0)
            EVT_IF_EQ(LVar0, 0)
                EVT_CALL(SetEncounterStatusFlags, 2, TRUE)
                EVT_USE_BUF(EVT_PTR(N(D_802418B8_DEA028)))
                EVT_SET(LVar0, 1)
                EVT_LOOP(9)
                    EVT_BUF_READ3(LVar1, LVar2, LVar3)
                    EVT_CALL(SetNpcPos, LVar0, LVar1, 0, LVar2)
                    EVT_CALL(NpcFacePlayer, LVar0, 0)
                    EVT_ADD(LVar0, 1)
                EVT_END_LOOP
                EVT_USE_BUF(EVT_PTR(N(D_80241924_DEA094)))
                EVT_BUF_READ3(LVar1, LVar2, LVar3)
                EVT_CALL(SetNpcPos, NPC_GeneralGuy, LVar1, LVar2, LVar3)
            EVT_END_IF
            EVT_EXEC(N(D_80241AC4_DEA234))
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

s32 N(D_80242200_DEA970)[] = {
    140, 19, 5, 147, 19, 32, 154, 19, 
    59, 161, 19, 86, 100, 0, 30, 106, 
    0, 55, 112, 0, 80, 118, 0, 105, 
    124, 0, 130, 
};

EvtScript N(EVS_NpcInit_ShyGuy_01) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_DEFEATED_GENERAL_GUY)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_ShyGuy_01)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_GeneralGuy)))
        EVT_CALL(GetSelfNpcID, LVar0)
        EVT_SUB(LVar0, 0)
        EVT_USE_BUF(EVT_PTR(N(D_80242200_DEA970)))
        EVT_LOOP(LVar0)
            EVT_BUF_READ3(LVar1, LVar2, LVar3)
        EVT_END_LOOP
        EVT_CALL(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
        EVT_RETURN
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_GeneralGuy) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_DEFEATED_GENERAL_GUY)
        EVT_EXEC(N(D_80240F98_DE9708))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_GeneralGuy)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_GeneralGuy)[] = {
    {
        .id = NPC_GeneralGuy,
        .settings = &N(NpcSettings_GeneralGuy),
        .pos = { 187.0f, 38.0f, 20.0f },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .init = &N(EVS_NpcInit_GeneralGuy),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_GeneralGuy_Anim02,
            .walk   = ANIM_GeneralGuy_Anim02,
            .run    = ANIM_GeneralGuy_Anim02,
            .chase  = ANIM_GeneralGuy_Anim02,
            .anim_4 = ANIM_GeneralGuy_Anim02,
            .anim_5 = ANIM_GeneralGuy_Anim02,
            .death  = ANIM_GeneralGuy_Anim02,
            .hit    = ANIM_GeneralGuy_Anim02,
            .anim_8 = ANIM_GeneralGuy_Anim02,
            .anim_9 = ANIM_GeneralGuy_Anim02,
            .anim_A = ANIM_GeneralGuy_Anim02,
            .anim_B = ANIM_GeneralGuy_Anim02,
            .anim_C = ANIM_GeneralGuy_Anim02,
            .anim_D = ANIM_GeneralGuy_Anim02,
            .anim_E = ANIM_GeneralGuy_Anim02,
            .anim_F = ANIM_GeneralGuy_Anim02,
        },
    },
    {
        .id = NPC_ShyGuy_01,
        .settings = &N(NpcSettings_GeneralGuy),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .init = &N(EVS_NpcInit_ShyGuy_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_ShyGuy_Red_Anim01,
            .walk   = ANIM_ShyGuy_Red_Anim02,
            .run    = ANIM_ShyGuy_Red_Anim03,
            .chase  = ANIM_ShyGuy_Red_Anim03,
            .anim_4 = ANIM_ShyGuy_Red_Anim01,
            .anim_5 = ANIM_ShyGuy_Red_Anim01,
            .death  = ANIM_ShyGuy_Red_Anim0C,
            .hit    = ANIM_ShyGuy_Red_Anim0C,
            .anim_8 = ANIM_ShyGuy_Red_Anim15,
            .anim_9 = ANIM_ShyGuy_Red_Anim12,
            .anim_A = ANIM_ShyGuy_Red_Anim11,
            .anim_B = ANIM_ShyGuy_Red_Anim10,
            .anim_C = ANIM_ShyGuy_Red_Anim05,
            .anim_D = ANIM_ShyGuy_Red_Anim01,
            .anim_E = ANIM_ShyGuy_Red_Anim01,
            .anim_F = ANIM_ShyGuy_Red_Anim01,
        },
    },
    {
        .id = NPC_ShyGuy_02,
        .settings = &N(NpcSettings_GeneralGuy),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .init = &N(EVS_NpcInit_ShyGuy_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_ShyGuy_Red_Anim01,
            .walk   = ANIM_ShyGuy_Red_Anim02,
            .run    = ANIM_ShyGuy_Red_Anim03,
            .chase  = ANIM_ShyGuy_Red_Anim03,
            .anim_4 = ANIM_ShyGuy_Red_Anim01,
            .anim_5 = ANIM_ShyGuy_Red_Anim01,
            .death  = ANIM_ShyGuy_Red_Anim0C,
            .hit    = ANIM_ShyGuy_Red_Anim0C,
            .anim_8 = ANIM_ShyGuy_Red_Anim15,
            .anim_9 = ANIM_ShyGuy_Red_Anim12,
            .anim_A = ANIM_ShyGuy_Red_Anim11,
            .anim_B = ANIM_ShyGuy_Red_Anim10,
            .anim_C = ANIM_ShyGuy_Red_Anim05,
            .anim_D = ANIM_ShyGuy_Red_Anim01,
            .anim_E = ANIM_ShyGuy_Red_Anim01,
            .anim_F = ANIM_ShyGuy_Red_Anim01,
        },
    },
    {
        .id = NPC_ShyGuy_03,
        .settings = &N(NpcSettings_GeneralGuy),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .init = &N(EVS_NpcInit_ShyGuy_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_ShyGuy_Red_Anim01,
            .walk   = ANIM_ShyGuy_Red_Anim02,
            .run    = ANIM_ShyGuy_Red_Anim03,
            .chase  = ANIM_ShyGuy_Red_Anim03,
            .anim_4 = ANIM_ShyGuy_Red_Anim01,
            .anim_5 = ANIM_ShyGuy_Red_Anim01,
            .death  = ANIM_ShyGuy_Red_Anim0C,
            .hit    = ANIM_ShyGuy_Red_Anim0C,
            .anim_8 = ANIM_ShyGuy_Red_Anim15,
            .anim_9 = ANIM_ShyGuy_Red_Anim12,
            .anim_A = ANIM_ShyGuy_Red_Anim11,
            .anim_B = ANIM_ShyGuy_Red_Anim10,
            .anim_C = ANIM_ShyGuy_Red_Anim05,
            .anim_D = ANIM_ShyGuy_Red_Anim01,
            .anim_E = ANIM_ShyGuy_Red_Anim01,
            .anim_F = ANIM_ShyGuy_Red_Anim01,
        },
    },
    {
        .id = NPC_ShyGuy_04,
        .settings = &N(NpcSettings_GeneralGuy),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .init = &N(EVS_NpcInit_ShyGuy_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_ShyGuy_Red_Anim01,
            .walk   = ANIM_ShyGuy_Red_Anim02,
            .run    = ANIM_ShyGuy_Red_Anim03,
            .chase  = ANIM_ShyGuy_Red_Anim03,
            .anim_4 = ANIM_ShyGuy_Red_Anim01,
            .anim_5 = ANIM_ShyGuy_Red_Anim01,
            .death  = ANIM_ShyGuy_Red_Anim0C,
            .hit    = ANIM_ShyGuy_Red_Anim0C,
            .anim_8 = ANIM_ShyGuy_Red_Anim15,
            .anim_9 = ANIM_ShyGuy_Red_Anim12,
            .anim_A = ANIM_ShyGuy_Red_Anim11,
            .anim_B = ANIM_ShyGuy_Red_Anim10,
            .anim_C = ANIM_ShyGuy_Red_Anim05,
            .anim_D = ANIM_ShyGuy_Red_Anim01,
            .anim_E = ANIM_ShyGuy_Red_Anim01,
            .anim_F = ANIM_ShyGuy_Red_Anim01,
        },
    },
    {
        .id = NPC_ShyGuy_05,
        .settings = &N(NpcSettings_GeneralGuy),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .init = &N(EVS_NpcInit_ShyGuy_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_ShyGuy_Red_Anim01,
            .walk   = ANIM_ShyGuy_Red_Anim02,
            .run    = ANIM_ShyGuy_Red_Anim03,
            .chase  = ANIM_ShyGuy_Red_Anim03,
            .anim_4 = ANIM_ShyGuy_Red_Anim01,
            .anim_5 = ANIM_ShyGuy_Red_Anim01,
            .death  = ANIM_ShyGuy_Red_Anim0C,
            .hit    = ANIM_ShyGuy_Red_Anim0C,
            .anim_8 = ANIM_ShyGuy_Red_Anim15,
            .anim_9 = ANIM_ShyGuy_Red_Anim12,
            .anim_A = ANIM_ShyGuy_Red_Anim11,
            .anim_B = ANIM_ShyGuy_Red_Anim10,
            .anim_C = ANIM_ShyGuy_Red_Anim05,
            .anim_D = ANIM_ShyGuy_Red_Anim01,
            .anim_E = ANIM_ShyGuy_Red_Anim01,
            .anim_F = ANIM_ShyGuy_Red_Anim01,
        },
    },
    {
        .id = NPC_ShyGuy_06,
        .settings = &N(NpcSettings_GeneralGuy),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .init = &N(EVS_NpcInit_ShyGuy_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_ShyGuy_Red_Anim01,
            .walk   = ANIM_ShyGuy_Red_Anim02,
            .run    = ANIM_ShyGuy_Red_Anim03,
            .chase  = ANIM_ShyGuy_Red_Anim03,
            .anim_4 = ANIM_ShyGuy_Red_Anim01,
            .anim_5 = ANIM_ShyGuy_Red_Anim01,
            .death  = ANIM_ShyGuy_Red_Anim0C,
            .hit    = ANIM_ShyGuy_Red_Anim0C,
            .anim_8 = ANIM_ShyGuy_Red_Anim15,
            .anim_9 = ANIM_ShyGuy_Red_Anim12,
            .anim_A = ANIM_ShyGuy_Red_Anim11,
            .anim_B = ANIM_ShyGuy_Red_Anim10,
            .anim_C = ANIM_ShyGuy_Red_Anim05,
            .anim_D = ANIM_ShyGuy_Red_Anim01,
            .anim_E = ANIM_ShyGuy_Red_Anim01,
            .anim_F = ANIM_ShyGuy_Red_Anim01,
        },
    },
    {
        .id = NPC_ShyGuy_07,
        .settings = &N(NpcSettings_GeneralGuy),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .init = &N(EVS_NpcInit_ShyGuy_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_ShyGuy_Red_Anim01,
            .walk   = ANIM_ShyGuy_Red_Anim02,
            .run    = ANIM_ShyGuy_Red_Anim03,
            .chase  = ANIM_ShyGuy_Red_Anim03,
            .anim_4 = ANIM_ShyGuy_Red_Anim01,
            .anim_5 = ANIM_ShyGuy_Red_Anim01,
            .death  = ANIM_ShyGuy_Red_Anim0C,
            .hit    = ANIM_ShyGuy_Red_Anim0C,
            .anim_8 = ANIM_ShyGuy_Red_Anim15,
            .anim_9 = ANIM_ShyGuy_Red_Anim12,
            .anim_A = ANIM_ShyGuy_Red_Anim11,
            .anim_B = ANIM_ShyGuy_Red_Anim10,
            .anim_C = ANIM_ShyGuy_Red_Anim05,
            .anim_D = ANIM_ShyGuy_Red_Anim01,
            .anim_E = ANIM_ShyGuy_Red_Anim01,
            .anim_F = ANIM_ShyGuy_Red_Anim01,
        },
    },
    {
        .id = NPC_ShyGuy_08,
        .settings = &N(NpcSettings_GeneralGuy),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .init = &N(EVS_NpcInit_ShyGuy_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_ShyGuy_Red_Anim01,
            .walk   = ANIM_ShyGuy_Red_Anim02,
            .run    = ANIM_ShyGuy_Red_Anim03,
            .chase  = ANIM_ShyGuy_Red_Anim03,
            .anim_4 = ANIM_ShyGuy_Red_Anim01,
            .anim_5 = ANIM_ShyGuy_Red_Anim01,
            .death  = ANIM_ShyGuy_Red_Anim0C,
            .hit    = ANIM_ShyGuy_Red_Anim0C,
            .anim_8 = ANIM_ShyGuy_Red_Anim15,
            .anim_9 = ANIM_ShyGuy_Red_Anim12,
            .anim_A = ANIM_ShyGuy_Red_Anim11,
            .anim_B = ANIM_ShyGuy_Red_Anim10,
            .anim_C = ANIM_ShyGuy_Red_Anim05,
            .anim_D = ANIM_ShyGuy_Red_Anim01,
            .anim_E = ANIM_ShyGuy_Red_Anim01,
            .anim_F = ANIM_ShyGuy_Red_Anim01,
        },
    },
    {
        .id = NPC_ShyGuy_09,
        .settings = &N(NpcSettings_GeneralGuy),
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .flags = ENEMY_FLAG_1 | ENEMY_FLAG_4 | ENEMY_FLAG_100 | ENEMY_FLAG_200 | ENEMY_FLAG_400 | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .init = &N(EVS_NpcInit_ShyGuy_01),
        .drops = {
            .dropFlags = NPC_DROP_FLAG_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
        .animations = {
            .idle   = ANIM_ShyGuy_Red_Anim01,
            .walk   = ANIM_ShyGuy_Red_Anim02,
            .run    = ANIM_ShyGuy_Red_Anim03,
            .chase  = ANIM_ShyGuy_Red_Anim03,
            .anim_4 = ANIM_ShyGuy_Red_Anim01,
            .anim_5 = ANIM_ShyGuy_Red_Anim01,
            .death  = ANIM_ShyGuy_Red_Anim0C,
            .hit    = ANIM_ShyGuy_Red_Anim0C,
            .anim_8 = ANIM_ShyGuy_Red_Anim15,
            .anim_9 = ANIM_ShyGuy_Red_Anim12,
            .anim_A = ANIM_ShyGuy_Red_Anim11,
            .anim_B = ANIM_ShyGuy_Red_Anim10,
            .anim_C = ANIM_ShyGuy_Red_Anim05,
            .anim_D = ANIM_ShyGuy_Red_Anim01,
            .anim_E = ANIM_ShyGuy_Red_Anim01,
            .anim_F = ANIM_ShyGuy_Red_Anim01,
        },
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_GeneralGuy), BTL_OMO2_FORMATION_00),
    {}
};
