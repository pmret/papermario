#include "jan_07.h"
#include "sprite/player.h"

#include "world/common/npc/YoshiKid.inc.c"

#include "world/common/enemy/PutridPiranha.h"

NpcSettings N(NpcSettings_PutridPiranha) = {
    .height = 24,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
};

#include "world/common/enemy/SpearGuy_Wander.inc.c"

EvtScript N(EVS_YoshiKid_CryForHelp) = {
    EVT_SET(AF_JAN_02, FALSE)
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, NPC_YoshiKid, SOUND_YOSHI_KID_CRY, SOUND_SPACE_DEFAULT)
        EVT_WAIT(20)
        EVT_IF_EQ(AF_JAN_02, TRUE)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_YoshiKid) = {
    EVT_IF_EQ(GF_JAN07_YoshiCriedForHelp, FALSE)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(ShowMessageAtScreenPos, MSG_CH5_00B4, 320, 60)
        EVT_CALL(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
        EVT_CALL(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShowEmote, NPC_PARTNER, EMOTE_EXCLAMATION, 0, 30, EMOTER_NPC, 0, 0, 0, 0)
        EVT_WAIT(30)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -183, 50, -11)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 50, 0, 0)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 500)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, 16, EVT_FLOAT(-6.0))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, 3)
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Yellow_Cry, ANIM_YoshiKid_Yellow_Cry, 5, MSG_CH5_00B5)
        EVT_WAIT(10)
        EVT_EXEC(N(EVS_YoshiKid_CryForHelp))
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(90.0))
        EVT_SET(GF_JAN07_YoshiCriedForHelp, TRUE)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_IF
    EVT_LABEL(0)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_NE(LVar0, 1)
            EVT_WAIT(1)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -20, 0, 20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -20, 0, 20)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(300.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(2.5))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, -55, 5, 30)
        EVT_CALL(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 0)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, FALSE)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_CALL(PlayerMoveTo, -20, 10, 25)
    EVT_WAIT(15)
    EVT_SET(AF_JAN_02, TRUE)
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        EVT_CALL(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 30, EMOTER_NPC, 0, 0, 0, 0)
    EVT_END_THREAD
    EVT_WAIT(30)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Yellow_SadIdle)
    EVT_WAIT(10)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_WAIT(30)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 90, 0)
    EVT_WAIT(15)
    EVT_CALL(InterpNpcYaw, NPC_SELF, 270, 0)
    EVT_WAIT(10)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_EQ(LVar0, PARTNER_SUSHIE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Yellow_SadTalk, ANIM_YoshiKid_Yellow_SadIdle, 0, MSG_CH5_00B6)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Yellow_SadTalk, ANIM_YoshiKid_Yellow_SadIdle, 0, MSG_CH5_00B7)
    EVT_END_IF
    EVT_CALL(EndSpeech, NPC_SELF, ANIM_YoshiKid_Yellow_Talk, ANIM_YoshiKid_Yellow_Idle, 0)
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Yellow_Run)
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_SELF, -150, 15, 0)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_SET(GF_JAN07_SavedYoshi, TRUE)
    EVT_SET(LVar0, 0)
    EVT_ADD(LVar0, GF_JAN05_SavedYoshi)
    EVT_ADD(LVar0, GF_JAN07_SavedYoshi)
    EVT_ADD(LVar0, GF_JAN08_SavedYoshi)
    EVT_ADD(LVar0, GF_JAN10_SavedYoshi)
    EVT_ADD(LVar0, GF_JAN11_SavedYoshi)
    EVT_IF_EQ(LVar0, 5)
        EVT_CALL(SetMusicTrack, 0, SONG_YOSHI_KIDS_FOUND, 0, 8)
        EVT_SET(GB_StoryProgress, STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_ThumbsUp)
        EVT_WAIT(120)
        EVT_EXEC(N(EVS_SetupMusic))
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Idle)
    EVT_ELSE
        EVT_THREAD
            EVT_WAIT(12)
            EVT_CALL(InterpPlayerYaw, 270, 0)
            EVT_CALL(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EVT_END_THREAD
        EVT_WAIT(30)
    EVT_END_IF
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.5))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_YoshiKid) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
        EVT_IF_EQ(GF_JAN07_SavedYoshi, FALSE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Yellow_Cry)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_YoshiKid)))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_PutridPiranha) = {
#if VERSION_PAL
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH, 1)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_PARTNER, 1)
#else
    EVT_CHILD_THREAD
        EVT_LOOP(0)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_IF_LT(LVar0, -190)
                EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH, 1)
                EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_PARTNER, 1)
            EVT_ELSE
                EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH, 0)
                EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_PARTNER, 0)
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
#endif
    EVT_CALL(SetNpcCollisionSize, NPC_PutridPiranha_01, 48, 40)
    EVT_CALL(SetNpcCollisionSize, NPC_PutridPiranha_02, 48, 40)
    EVT_CALL(AwaitPlayerApproach, 60, 20, 140)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, 0)
        EVT_CALL(InterruptUsePartner)
    EVT_END_IF
    EVT_WAIT(5)
    EVT_THREAD
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -60, 0, 20)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, -50, 0, 20)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(InterpNpcYaw, NPC_PutridPiranha_01, 270, 0)
    EVT_END_THREAD
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim04)
    EVT_CALL(PlaySoundAtNpc, NPC_PutridPiranha_02, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_PutridPiranha_02, EMOTE_EXCLAMATION, 0, 38, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(3)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim04)
    EVT_CALL(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    EVT_CALL(ShowEmote, NPC_PutridPiranha_01, EMOTE_EXCLAMATION, 0, 35, EMOTER_NPC, 0, 0, 0, 0)
    EVT_WAIT(35)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim01)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim01)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim04)
    EVT_SET(LVar0, 0)
    EVT_LOOP(15)
        EVT_ADD(LVar0, 24)
        EVT_CALL(SetNpcRotation, NPC_PutridPiranha_01, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_PIRANHA_SPIN_1, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim01)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim04)
    EVT_SET(LVar0, 0)
    EVT_LOOP(15)
        EVT_ADD(LVar0, 24)
        EVT_CALL(SetNpcRotation, NPC_PutridPiranha_02, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtNpc, NPC_PutridPiranha_02, SOUND_PIRANHA_SPIN_1, SOUND_SPACE_DEFAULT)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim01)
    EVT_WAIT(5)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim04)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim04)
    EVT_SET(LVar0, 0)
    EVT_LOOP(12)
        EVT_ADD(LVar0, 30)
        EVT_CALL(SetNpcRotation, NPC_PutridPiranha_01, 0, LVar0, 0)
        EVT_CALL(SetNpcRotation, NPC_PutridPiranha_02, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_PIRANHA_SPIN_2, SOUND_SPACE_DEFAULT)
    EVT_SET(LVar0, 0)
    EVT_LOOP(12)
        EVT_ADD(LVar0, 30)
        EVT_CALL(SetNpcRotation, NPC_PutridPiranha_01, 0, LVar0, 0)
        EVT_CALL(SetNpcRotation, NPC_PutridPiranha_02, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_PIRANHA_SPIN_2, SOUND_SPACE_DEFAULT)
    EVT_SET(LVar0, 0)
    EVT_LOOP(12)
        EVT_ADD(LVar0, 30)
        EVT_CALL(SetNpcRotation, NPC_PutridPiranha_01, 0, LVar0, 0)
        EVT_CALL(SetNpcRotation, NPC_PutridPiranha_02, 0, LVar0, 0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_PIRANHA_SPIN_2, SOUND_SPACE_DEFAULT)
    EVT_LOOP(3)
        EVT_WAIT(5)
        EVT_CALL(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_PIRANHA_TENSE, SOUND_SPACE_DEFAULT)
    EVT_END_LOOP
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim05)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim05)
    EVT_WAIT(20)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim06)
    EVT_CALL(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim06)
    EVT_CALL(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_PIRANHA_CHOMP, SOUND_SPACE_DEFAULT)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(StartBossBattle, SONG_SPECIAL_BATTLE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcDefeat_PutridPiranha) = {
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, -20, 0, 20)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -20, 0, 20)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(500.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(SetNpcVar, NPC_YoshiKid, 0, 1)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_LOST)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_PutridPiranha) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
        EVT_IF_EQ(GF_JAN07_SavedYoshi, FALSE)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_PutridPiranha)))
            EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_PutridPiranha)))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(RemoveEncounter, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_SpearGuy_Hitbox) = {
    EVT_IF_EQ(GF_JAN07_SavedYoshi, FALSE)
        EVT_CALL(RemoveNpc, NPC_SpearGuy)
        EVT_CALL(RemoveNpc, NPC_SpearGuy_Hitbox)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_SpearGuy)[] = {
    {
        .id = NPC_SpearGuy,
        .pos = { -28.0f, 0.0f, 13.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -28, 0, 13 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -28, 0, 13 },
                .detectSize = { 150 },
            }
        },
        .settings = &N(NpcSettings_SpearGuy_Wander),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = SPEAR_GUY_DROPS,
        .animations = SPEAR_GUY_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    {
        .id = NPC_SpearGuy_Hitbox,
        .pos = { NPC_DISPOSE_LOCATION },
        .yaw = 0,
        .init = &N(EVS_NpcInit_SpearGuy_Hitbox),
        .settings = &N(NpcSettings_SpearGuy_Hitbox),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = SPEAR_GUY_ANIMS,
    },
};

NpcData N(NpcData_PutridPiranhas)[] = {
    {
        .id = NPC_PutridPiranha_01,
        .pos = { -20.0f, 0.0f, 20.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_PutridPiranha),
        .settings = &N(NpcSettings_PutridPiranha),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = PUTRID_PIRANHA_ANIMS,
    },
    {
        .id = NPC_PutridPiranha_02,
        .pos = { 80.0f, 0.0f, 20.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_PutridPiranha),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_40000 | ENEMY_FLAG_400000 | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = PUTRID_PIRANHA_ANIMS,
    },
};

NpcData N(NpcData_YoshiKid) = {
    .id = NPC_YoshiKid,
    .pos = { 30.0f, 0.0f, 20.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_YoshiKid),
    .settings = &N(NpcSettings_YoshiKid),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = YOSHI_KID_YELLOW_ANIMS,
    .tattle = MSG_NpcTattle_YellowYoshiKid,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_SpearGuy), BTL_JAN_FORMATION_01, BTL_JAN_STAGE_03),
    NPC_GROUP(N(NpcData_PutridPiranhas), BTL_JAN2_FORMATION_01, BTL_JAN2_STAGE_03),
    NPC_GROUP(N(NpcData_YoshiKid)),
    {}
};
