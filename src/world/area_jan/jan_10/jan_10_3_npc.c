#include "jan_10.h"
#include "sprite/player.h"

#include "world/common/enemy/JungleFuzzy_Wander.inc.c"
#include "world/common/npc/YoshiKid.inc.c"

EvtScript N(EVS_NpcIdle_JungleFuzzy) = {
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_LABEL(0)
        EVT_CALL(GetSelfVar, 7, LVar0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar0, FALSE)
            EVT_GOTO(0)
        EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Jungle_Anim09)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, FALSE)
    EVT_CALL(SetNpcPos, NPC_SELF, -566, 100, 65)
    EVT_CALL(PlaySoundWithVolume, SOUND_FUZZY_HOP_A, 110)
    EVT_WAIT(20)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, TRUE)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_JungleFuzzy_Wander)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_JungleFuzzy) = {
    EVT_CALL(SetSelfVar, 7, FALSE)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN, 1)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, TRUE)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_JungleFuzzy)))
    EVT_RETURN
    EVT_END
};

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

EvtScript N(EVS_NpcInteract_YoshiKid) = {
    EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(4.0), 0, 350, EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_SET(AF_JAN_02, TRUE)
    EVT_WAIT(15)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_EQ(LVar0, PARTNER_SUSHIE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Blue_SadTalk, ANIM_YoshiKid_Blue_SadIdle, 0, MSG_CH5_00B2)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Blue_SadTalk, ANIM_YoshiKid_Blue_SadIdle, 0, MSG_CH5_00B3)
    EVT_END_IF
    EVT_CALL(EndSpeech, NPC_SELF, ANIM_YoshiKid_Blue_Talk, ANIM_YoshiKid_Blue_Idle, 0)
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Blue_Run)
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_SELF, -240, 10, 0)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_SET(GF_JAN10_SavedYoshi, TRUE)
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
        EVT_WAIT(30)
    EVT_END_IF
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_YoshiKid) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
        EVT_EXEC(N(EVS_YoshiKid_CryForHelp))
        EVT_IF_EQ(GF_JAN10_SavedYoshi, FALSE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Blue_Cry)
            EVT_CALL(SetNpcYaw, NPC_SELF, 90)
            EVT_CALL(SetNpcPos, NPC_SELF, -450, 0, 70)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_YoshiKid)))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_YoshiKid) = {
    .id = NPC_YoshiKid,
    .pos = { -260.0f, 0.0f, -220.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_YoshiKid),
    .settings = &N(NpcSettings_YoshiKid),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_4 | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = YOSHI_KID_BLUE_ANIMS,
    .tattle = MSG_NpcTattle_BlueYoshiKid,
};

NpcData N(NpcData_JungleFuzzy) = {
    .id = NPC_JungleFuzzy,
    .pos = { 0.0f, 0.0f, 0.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -460, 0, 70 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -460, 0, 70 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_JungleFuzzy),
    .settings = &N(NpcSettings_JungleFuzzy_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_400000,
    .drops = JUNGLE_FUZZY_DROPS,
    .animations = JUNGLE_FUZZY_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_YoshiKid)),
    NPC_GROUP(N(NpcData_JungleFuzzy), BTL_JAN_FORMATION_0A, BTL_JAN_STAGE_03),
    {}
};
