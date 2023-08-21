#include "omo_15.h"

#include "world/common/enemy/ShyGuy_Stationary.inc.c"

enum {
    MANAGER_IDLE_STATE      = 0,
    MANAGER_ARMY_CHARGE     = 10,
    MANAGER_ARMY_FLEE       = 40,
};

s32 N(BeginSurroundCrowdPositions)[] = {
    8, -35, -240,
    7,  -5, -180,
    6,  10, -120,
    6,  25,  -60,
    6,  25,   60,
    6,  10,  120,
    7,  -5,  180,
    8, -35,  240,
    6,  30,    0,
};

EvtScript N(EVS_Scene_MeetingGeneralGuy) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(30 * DT)
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(GetPartnerInUse, LVar0)
        EVT_IF_NE(LVar0, PARTNER_NONE)
            EVT_CALL(InterruptUsePartner)
            EVT_WAIT(30 * DT)
            EVT_CALL(func_802D2C14, 1)
            EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            EVT_WAIT(45 * DT)
            EVT_CALL(func_802D2C14, 0)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_GeneralGuy, ANIM_GeneralGuy_Anim0A, ANIM_GeneralGuy_Anim02, 0, MSG_CH4_005F)
    EVT_WAIT(10 * DT)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 250, -50, 10)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 250, -50, 10)
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(205.0), EVT_FLOAT(11.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_GeneralGuy, ANIM_GeneralGuy_Anim0A, ANIM_GeneralGuy_Anim02, 0, MSG_CH4_0060)
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_GeneralGuy, ANIM_GeneralGuy_Anim0A, ANIM_GeneralGuy_Anim02, 0, MSG_CH4_0061)
    EVT_WAIT(20 * DT)
    EVT_CALL(SpeakToPlayer, NPC_GeneralGuy, ANIM_GeneralGuy_Anim0A, ANIM_GeneralGuy_Anim02, 0, MSG_CH4_0062)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0 / DT))
    EVT_CALL(PlayerMoveTo, -200, 0, 0)
    EVT_SET(LVar0, NPC_ShyGuy_01)
    EVT_LOOP(9)
        EVT_CALL(SetNpcAnimation, LVar0, ANIM_ShyGuy_Red_Anim02)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_GeneralGuy, ANIM_GeneralGuy_Anim0C)
    EVT_CALL(ShowMessageAtScreenPos, MSG_CH4_0063, 160, 40)
    EVT_CALL(SetNpcAnimation, NPC_GeneralGuy, ANIM_GeneralGuy_Anim02)
    EVT_WAIT(20 * DT)
    EVT_SET(LVar0, NPC_ShyGuy_01)
    EVT_LOOP(9)
        EVT_CALL(SetNpcAnimation, LVar0, ANIM_ShyGuy_Red_Anim01)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(SpeakToPlayer, NPC_GeneralGuy, ANIM_GeneralGuy_Anim02, ANIM_GeneralGuy_Anim0A, 0, MSG_CH4_0064)
    EVT_THREAD
        EVT_WAIT(10 * DT)
        EVT_CALL(PlaySound, SOUND_LOOP_SHY_GUY_CROWD_2)
        EVT_SET(LVar0, NPC_ShyGuy_01)
        EVT_LOOP(9)
            EVT_CALL(SetNpcVar, LVar0, 0, MANAGER_ARMY_CHARGE)
            EVT_ADD(LVar0, 1)
        EVT_END_LOOP
    EVT_END_THREAD
    // screen 'shaking' from charging army
    EVT_LOOP(30)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(330.0))
        EVT_WAIT(1)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(320.0))
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SET(LVar0, NPC_ShyGuy_01)
    EVT_USE_BUF(EVT_PTR(N(BeginSurroundCrowdPositions)))
    EVT_LOOP(9)
        EVT_BUF_READ3(LVar1, LVar2, LVar3)
        EVT_CALL(SetNpcSpeed, LVar0, LVar1)
        EVT_CALL(SetNpcPos, LVar0, LVar2, 0, LVar3)
        EVT_ADD(LVar0, 1)
    EVT_END_LOOP
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_WAIT(20 * DT)
    // wait for battle to be over
    EVT_LABEL(5)
        EVT_CALL(GetNpcVar, NPC_ShyGuy_09, 0, LVar0)
        EVT_IF_NE(LVar0, MANAGER_ARMY_FLEE)
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
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.5 / DT))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(FadeOutMusic, 0, 3000 * DT)
    EVT_EXEC(N(EVS_TrySpawningStarCard))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

s32 N(CrowdFleeScriptA)[] = {
    CS_JUMP(  65,   0,  87)
    CS_MOVE(  17,  46)
    CS_JUMP( -24,   0, -11)
    CS_MOVE( -63, -16)
    CS_MOVE(-120,  43)
    CS_JUMP(-172,   0,  25)
    CS_MOVE(-234,  23)
    CS_MOVE(-320,  30)
    CS_MOVE(-400,   0)
    CS_END
};

s32 N(CrowdFleeScriptB)[] = {
    CS_MOVE(  29,  -72)
    CS_MOVE( -19, -104)
    CS_MOVE( -60,  -67)
    CS_MOVE(-106,  -50)
    CS_MOVE(-168, -100)
    CS_MOVE(-279,  -20)
    CS_MOVE(-400,    0)
    CS_END
};

s32 N(CrowdFleeScriptC)[] = {
    CS_JUMP( -30,   0,  27)
    CS_MOVE(-123, -13)
    CS_MOVE(-168,  73)
    CS_MOVE(-120, 103)
    CS_MOVE(-155,  21)
    CS_MOVE(-208,  43)
    CS_MOVE(-256,  84)
    CS_MOVE(-326,  42)
    CS_MOVE(-400,   0)
    CS_END
};

s32 N(CrowdFleeScriptD)[] = {
    CS_MOVE( 133,  -3)
    CS_MOVE(  84,  27)
    CS_MOVE(  25,   0)
    CS_MOVE( -31, -23)
    CS_MOVE( -97,   0)
    -50, //@bug -- ignored by event running this script; previous op should probably be CS_JUMP with this as third arg
    CS_MOVE(-150, -75)
    CS_MOVE(-230, -90)
    CS_MOVE(-309, -55)
    CS_MOVE(-400,   0)
    CS_END
};

s32 N(CrowdFleeScriptE)[] = {
    CS_MOVE( -40, 200)
    CS_MOVE(-100, 256)
    CS_MOVE(-180, 270)
    CS_MOVE(-210, 200)
    CS_MOVE(-179, 102)
    CS_JUMP(-167,   0,  52)
    CS_MOVE(-261, 118)
    CS_MOVE(-400,   0)
    CS_END
};

s32 N(CrowdPratfallScript)[] = {
    CS_MOVE( -97, -24)
    CS_MOVE( -25, 300)
    CS_MOVE( 100,   0)
    CS_MOVE( -50,  50)
    CS_MOVE(-100,  30)
    CS_MOVE(-160,  63)
    CS_FALL()
    CS_MOVE(-400,   0)
    CS_END
};

s32 N(GeneralGuyFleeScript)[] = {
    CS_MOVE(-153,   0)
    CS_MOVE(-170,  70)
    CS_MOVE(-208,  80)
    CS_MOVE(-246,  70)
    CS_MOVE(-263,   0)
    CS_MOVE(-246, -70)
    CS_MOVE(-208, -80)
    CS_MOVE(-170, -70)
    CS_MOVE(-153,   0)
    CS_MOVE(-170,  70)
    CS_MOVE(-208,  80)
    CS_MOVE(-400,   0)
    CS_END
};

s32* N(CrowdFleeScripts)[] = {
    N(CrowdFleeScriptA),
    N(CrowdFleeScriptB),
    N(CrowdFleeScriptC),
    N(CrowdFleeScriptD),
    N(CrowdFleeScriptE),
    N(CrowdFleeScriptB),
    N(CrowdFleeScriptA),
    N(CrowdFleeScriptD),
    N(CrowdPratfallScript),
};

s32* N(GeneralGuyFleeScripts)[] = {
    N(GeneralGuyFleeScript),
};

Vec3i N(FinalSurroundCrowdPositions)[] = {
    { -238, -55,  0 },
    { -218, -60,  0 },
    { -198, -60,  0 },
    { -178, -50,  0 },
    { -178,  35,  0 },
    { -192,  50,  0 },
    { -210,  60,  0 },
    { -228,  55,  0 },
    { -165, -10,  0 },
};

Vec3i N(PostBattleGeneralPosition) = {
    -182, 0, 0,
};

EvtScript N(EVS_NpcIdle_ShyGuy) = {
    EVT_LABEL(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_SWITCH(LVar0)
            EVT_CASE_EQ(MANAGER_ARMY_CHARGE)
                EVT_THREAD
                    EVT_CALL(GetSelfNpcID, LVar0)
                    EVT_SUB(LVar0, 0)
                    EVT_USE_BUF(EVT_PTR(N(FinalSurroundCrowdPositions)))
                    EVT_LOOP(LVar0)
                        EVT_BUF_READ3(LVar1, LVar2, LVar3)
                    EVT_END_LOOP
                    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_ShyGuy_Red_Anim03)
                    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(3.0))
                    EVT_CALL(NpcMoveTo, NPC_SELF, LVar1, LVar2, LVar3)
                EVT_END_THREAD
                EVT_WAIT(60)
                EVT_CALL(GetSelfNpcID, LVar0)
                EVT_CALL(SetSelfVar, 0, MANAGER_IDLE_STATE)
                EVT_IF_EQ(LVar0, NPC_ShyGuy_09)
                    EVT_THREAD
                        EVT_WAIT(20)
                        EVT_CALL(StopSound, SOUND_LOOP_SHY_GUY_CROWD_2)
                    EVT_END_THREAD
                    EVT_CALL(StartBossBattle, SONG_GENERAL_GUY_BATTLE)
                EVT_END_IF
        EVT_END_SWITCH
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BossDefeated_RunAway) = {
    EVT_CALL(GetSelfNpcID, LVar9)
    EVT_IF_EQ(LVar9, NPC_GeneralGuy)
        EVT_CALL(PlaySound, SOUND_LOOP_SHY_GUY_CROWD_2)
        EVT_USE_BUF(EVT_PTR(N(GeneralGuyFleeScripts)))
        EVT_BUF_READ1(LVar1)
        EVT_USE_BUF(LVar1)
        EVT_CALL(SetNpcAnimation, LVar9, ANIM_GeneralGuy_Anim0E)
        EVT_LOOP(0)
            EVT_BUF_READ1(LVar2)
            EVT_SWITCH(LVar2)
                EVT_CASE_EQ(op_CS_MOVE)
                    EVT_BUF_READ2(LVar3, LVar4)
                    EVT_CALL(SetNpcSpeed, NPC_GeneralGuy, EVT_FLOAT(8.0))
                    EVT_CALL(NpcMoveTo, NPC_GeneralGuy, LVar3, LVar4, 0)
                EVT_CASE_EQ(op_CS_JUMP)
                    EVT_BUF_READ3(LVar3, LVar4, LVar5)
                    EVT_CALL(SetNpcJumpscale, NPC_GeneralGuy, EVT_FLOAT(1.0))
                    EVT_CALL(NpcJump0, NPC_GeneralGuy, LVar3, LVar4, LVar5, 10)
            EVT_END_SWITCH
            EVT_IF_EQ(LVar2, op_CS_END)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_CALL(PlaySound, SOUND_LRAW_SHY_GUY_CROWD_2 | SOUND_ID_TRIGGER_CHANGE_SOUND)
        EVT_CALL(StopTrackingSoundPos, SOUND_LRAW_SHY_GUY_CROWD_2)
    EVT_ELSE
        EVT_SET(LVar0, LVar9)
        EVT_SUB(LVar0, 0)
        EVT_USE_BUF(EVT_PTR(N(CrowdFleeScripts)))
        EVT_LOOP(LVar0)
            EVT_BUF_READ1(LVar1)
        EVT_END_LOOP
        EVT_USE_BUF(LVar1)
        EVT_LOOP(0)
            EVT_BUF_READ1(LVar2)
            EVT_SWITCH(LVar2)
                EVT_CASE_EQ(op_CS_MOVE)
                    EVT_BUF_READ2(LVar3, LVar4)
                    EVT_CALL(SetNpcAnimation, LVar9, ANIM_ShyGuy_Red_Anim04)
                    EVT_CALL(SetNpcSpeed, LVar9, EVT_FLOAT(8.0))
                    EVT_CALL(NpcMoveTo, LVar9, LVar3, LVar4, 0)
                EVT_CASE_EQ(op_CS_JUMP)
                    EVT_BUF_READ3(LVar3, LVar4, LVar5)
                    EVT_CALL(SetNpcJumpscale, LVar9, EVT_FLOAT(1.0))
                    EVT_CALL(NpcJump0, LVar9, LVar3, LVar4, LVar5, 10)
                EVT_CASE_EQ(op_CS_FALL)
                    EVT_CALL(SetNpcRotationPivot, LVar9, 10)
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
                    EVT_CALL(PlaySoundAtNpc, LVar9, SOUND_ACTOR_TRIP, SOUND_SPACE_DEFAULT)
                    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
                    EVT_WAIT(50)
                    EVT_LOOP(2)
                        EVT_CALL(PlaySoundAtNpc, LVar9, SOUND_ACTOR_TWITCH, SOUND_SPACE_DEFAULT)
                        EVT_WAIT(7)
                    EVT_END_LOOP
                    EVT_WAIT(6)
                    EVT_CALL(SetNpcRotationPivot, LVar9, 0)
                    EVT_CALL(SetNpcAnimation, LVar9, ANIM_ShyGuy_Red_Anim01)
                    EVT_CALL(NpcJump0, LVar9, -230, 0, 63, 10)
                    EVT_CALL(InterpNpcYaw, LVar9, 90, 0)
                    EVT_WAIT(20)
                    EVT_THREAD
                        EVT_CALL(PlaySoundAtNpc, LVar9, SOUND_SHY_GUY_FLEE_LOOP, SOUND_SPACE_DEFAULT)
                        EVT_WAIT(45)
                        EVT_CALL(StopSound, SOUND_SHY_GUY_FLEE_LOOP)
                        EVT_CALL(SetNpcVar, NPC_ShyGuy_09, 0, MANAGER_ARMY_FLEE)
                    EVT_END_THREAD
            EVT_END_SWITCH
            EVT_IF_EQ(LVar2, op_CS_END)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
    EVT_END_IF
    EVT_CALL(SetNpcFlagBits, LVar9, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcPos, LVar9, NPC_DISPOSE_LOCATION)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_GeneralGuy) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetMusicTrack, 0, SONG_SHY_GUY_TOYBOX, 0, 8)
            EVT_CALL(GetSelfNpcID, LVar0)
            EVT_IF_EQ(LVar0, NPC_GeneralGuy)
                EVT_CALL(SetEncounterStatusFlags, ENCOUNTER_STATUS_FLAG_2, TRUE)
                EVT_USE_BUF(EVT_PTR(N(FinalSurroundCrowdPositions)))
                EVT_SET(LVar0, NPC_ShyGuy_01)
                EVT_LOOP(9)
                    EVT_BUF_READ3(LVar1, LVar2, LVar3)
                    EVT_CALL(SetNpcPos, LVar0, LVar1, 0, LVar2)
                    EVT_CALL(NpcFacePlayer, LVar0, 0)
                    EVT_ADD(LVar0, 1)
                EVT_END_LOOP
                EVT_USE_BUF(EVT_PTR(N(PostBattleGeneralPosition)))
                EVT_BUF_READ3(LVar1, LVar2, LVar3)
                EVT_CALL(SetNpcPos, NPC_GeneralGuy, LVar1, LVar2, LVar3)
            EVT_END_IF
            EVT_EXEC(N(EVS_BossDefeated_RunAway))
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

Vec3i N(InitialCrowdPositions)[] = {
    { 140, 19,   5 },
    { 147, 19,  32 },
    { 154, 19,  59 },
    { 161, 19,  86 },
    { 100,  0,  30 },
    { 106,  0,  55 },
    { 112,  0,  80 },
    { 118,  0, 105 },
    { 124,  0, 130 },
};

EvtScript N(EVS_NpcInit_ShyGuy) = {
    EVT_IF_LT(GB_StoryProgress, STORY_CH4_DEFEATED_GENERAL_GUY)
        EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_ShyGuy)))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_GeneralGuy)))
        EVT_CALL(GetSelfNpcID, LVar0)
        EVT_SUB(LVar0, 0)
        EVT_USE_BUF(EVT_PTR(N(InitialCrowdPositions)))
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
        EVT_EXEC(N(EVS_Scene_MeetingGeneralGuy))
        EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_GeneralGuy)))
    EVT_ELSE
        EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_GeneralGuy)[] = {
    {
        .id = NPC_GeneralGuy,
        .pos = { 187.0f, 38.0f, 20.0f },
        .yaw = 270,
        .init = &N(EVS_NpcInit_GeneralGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
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
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_02,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_03,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_04,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_05,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_06,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_07,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_08,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
    {
        .id = NPC_ShyGuy_09,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 270,
        .init = &N(EVS_NpcInit_ShyGuy),
        .settings = &N(NpcSettings_ShyGuy_Stationary),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_GRAVITY | ENEMY_FLAG_40000,
        .drops = NO_DROPS,
        .animations = RED_SHY_GUY_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_GeneralGuy), BTL_OMO2_FORMATION_00),
    {}
};
