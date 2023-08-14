#include "jan_08.h"
#include "sprite/player.h"

#include "world/common/npc/YoshiKid.inc.c"
#include "world/common/enemy/MBush.inc.c"
#include "world/common/enemy/HeartPlant.inc.c"

#include "world/common/enemy/HurtPlant.inc.c"
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
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_LABEL(0)
    EVT_CALL(GetPlayerPos, LVar1, LVar2, LVar3)
    EVT_IF_LE(LVar1, -90)
        EVT_IF_GT(LVar3, 280)
            EVT_CALL(GetEntryID, LVar0)
            EVT_IF_EQ(LVar0, jan_08_ENTRY_0)
                EVT_WAIT(18)
            EVT_END_IF
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(ShowMessageAtScreenPos, MSG_CH5_00AF, 160, 40)
            EVT_EXEC(N(EVS_YoshiKid_CryForHelp))
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_SET(LVar0, 1)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_NE(LVar0, 1)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_LABEL(10)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_IF_EQ(LVar0, 0)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4.0), -23, 350, EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_SET(AF_JAN_02, TRUE)
    EVT_WAIT(15)
    EVT_IF_EQ(LVar0, PARTNER_SUSHIE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Red_SadTalk, ANIM_YoshiKid_Red_SadIdle, 0, MSG_CH5_00B0)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Red_SadTalk, ANIM_YoshiKid_Red_SadIdle, 0, MSG_CH5_00B1)
    EVT_END_IF
    EVT_CALL(EndSpeech, NPC_SELF, ANIM_YoshiKid_Red_Talk, ANIM_YoshiKid_Red_Idle, 0)
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Red_Run)
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_SELF, -418, -60, 0)
        EVT_CALL(NpcMoveTo, NPC_SELF, -300, 80, 0)
        EVT_CALL(NpcMoveTo, NPC_SELF, -320, 115, 0)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_SET(GF_JAN08_SavedYoshi, TRUE)
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
        EVT_WAIT(40)
    EVT_END_IF
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_YoshiKid) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
        EVT_IF_EQ(GF_JAN08_SavedYoshi, FALSE)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Red_Cry)
            EVT_CALL(SetNpcYaw, NPC_SELF, 90)
            EVT_CALL(SetNpcPos, NPC_SELF, -391, 0, -164)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_YoshiKid)))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

// unchanged from MBush.inc.c
EvtScript N(EVS_NpcDefeat_MBush_Copy) = {
    EVT_CALL(GetBattleOutcome, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(OUTCOME_PLAYER_WON)
            EVT_CALL(DoNpcDefeat)
        EVT_CASE_EQ(OUTCOME_PLAYER_FLED)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MBush_Anim05)
            EVT_CALL(GetSelfVar, 10, LVar0)
            EVT_CALL(GetSelfVar, 11, LVar1)
            EVT_CALL(GetSelfVar, 12, LVar2)
            EVT_CALL(NpcJump1, NPC_SELF, LVar0, LVar1, LVar2, 8)
            EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MBush_Anim00)
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_MBush)))
        EVT_CASE_EQ(OUTCOME_ENEMY_FLED)
            EVT_CALL(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, 1)
            EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_MBush_01) = {
    EVT_CALL(SetNpcCollisionSize, NPC_SELF, 60, 30)
    EVT_CALL(BindNpcDefeat, NPC_SELF, EVT_PTR(N(EVS_NpcDefeat_MBush_Copy)))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_SpearGuy)[] = {
    {
        .id = NPC_SpearGuy,
        .pos = { 255.0f, 15.0f, -65.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 255, 0, -65 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 255, 0, -65 },
                .detectSize = { 150 },
            }
        },
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        SPEAR_GUY_WANDER_NPC_DATA
    },
    SPEAR_GUY_HITBOX(NPC_SpearGuy_Hitbox)
};

NpcData N(NpcData_HurtPlant) = {
    .id = NPC_HurtPlant,
    .pos = { 400.0f, 0.0f, 235.0f },
    .yaw = 270,
    HURT_PLANT_NPC_DATA
};

NpcData N(NpcData_MBush_01) = {
    .id = NPC_MBush_01,
    .pos = { -407.0f, 0.0f, -42.0f },
    .yaw = 90,
    MBUSH_NPC_DATA
    .init = &N(EVS_NpcInit_MBush_01),
};

NpcData N(NpcData_MBush_02) = {
    .id = NPC_MBush_02,
    .pos = { -120.0f, 0.0f, -395.0f },
    .yaw = 90,
    MBUSH_NPC_DATA
};

NpcData N(NpcData_HeartPlant_01) = {
    .id = NPC_HeartPlant_01,
    .pos = { -219.0f, 0.0f, 420.0f },
    .yaw = 270,
    HEART_PLANT_NPC_DATA
};

NpcData N(NpcData_HeartPlant_02) = {
    .id = NPC_HeartPlant_02,
    .pos = { -157.0f, 0.0f, 452.0f },
    .yaw = 270,
    HEART_PLANT_NPC_DATA
};

NpcData N(NpcData_YoshiKid) = {
    .id = NPC_YoshiKid,
    .pos = { -450.0f, 0.0f, -290.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_YoshiKid),
    .settings = &N(NpcSettings_YoshiKid),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = YOSHI_KID_RED_ANIMS,
    .tattle = MSG_NpcTattle_RedYoshiKid,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_SpearGuy), BTL_JAN_FORMATION_01, BTL_JAN_STAGE_01),
    NPC_GROUP(N(NpcData_HurtPlant), BTL_JAN_FORMATION_08, BTL_JAN_STAGE_01),
    NPC_GROUP(N(NpcData_MBush_01), BTL_JAN_FORMATION_10, BTL_JAN_STAGE_01),
    NPC_GROUP(N(NpcData_MBush_02), BTL_JAN_FORMATION_0E, BTL_JAN_STAGE_01),
    NPC_GROUP(N(NpcData_HeartPlant_01)),
    NPC_GROUP(N(NpcData_HeartPlant_02)),
    NPC_GROUP(N(NpcData_YoshiKid)),
    {}
};
