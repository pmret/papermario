#include "jan_05.h"
#include "sprite/player.h"

#include "world/common/enemy/MBush.inc.c"
#include "world/common/npc/YoshiKid.inc.c"
#include "world/common/enemy/HeartPlant.inc.c"
#include "world/common/enemy/HurtPlant.inc.c"
#include "world/common/enemy/JungleFuzzy_Wander.inc.c"
#include "world/common/enemy/SpearGuy_Wander.inc.c"

EvtScript N(EVS_NpcIdle_JungleFuzzy) = {
    EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_LABEL(0)
    EVT_CALL(GetSelfVar, 7, LVar0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar0, 0)
        EVT_GOTO(0)
    EVT_END_IF
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Jungle_Anim09)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, FALSE)
    EVT_CALL(SetNpcPos, NPC_SELF, 125, 100, -392)
    EVT_CALL(PlaySoundWithVolume, SOUND_FUZZY_HOP_A, 110)
    EVT_WAIT(20)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, TRUE)
    EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_JungleFuzzy_Wander)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_JungleFuzzy) = {
    EVT_CALL(SetSelfVar, 7, 0)
    EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN, 1)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, TRUE)
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_JungleFuzzy)))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_YoshiKid_WatchPlayerProximinity) = {
    EVT_LABEL(1)
    EVT_CALL(GetSelfVar, 0, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(0)
            EVT_CALL(AwaitPlayerLeave, -308, -270, 70)
            EVT_CALL(SetSelfVar, 0, 1)
        EVT_CASE_EQ(1)
            EVT_CALL(AwaitPlayerApproach, -308, -270, 50)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(ShowMessageAtScreenPos, MSG_CH5_00B8, 160, 40)
            EVT_CALL(DisablePlayerInput, FALSE)
            EVT_CALL(SetSelfVar, 0, 0)
    EVT_END_SWITCH
    EVT_WAIT(1)
    EVT_GOTO(1)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_OnShakeTree_Yoshi) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcVar, NPC_YoshiKid, 0, 9)
    EVT_THREAD
        EVT_CALL(PlaySoundAtNpc, NPC_YoshiKid, SOUND_FALL_QUICK, SOUND_SPACE_DEFAULT)
        EVT_CALL(SetNpcJumpscale, NPC_YoshiKid, EVT_FLOAT(1.0))
        EVT_CALL(NpcJump0, NPC_YoshiKid, -308, 0, -248, 30)
    EVT_END_THREAD
    EVT_CALL(EnableNpcShadow, NPC_YoshiKid, TRUE)
    EVT_WAIT(40)
    EVT_CALL(SetNpcVar, NPC_YoshiKid, 0, 10)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_YoshiKid_Sleeping) = {
    EVT_LOOP(0)
        EVT_CALL(PlaySoundAtNpc, NPC_YoshiKid, SOUND_SNORE_INHALE_A, SOUND_SPACE_DEFAULT)
        EVT_WAIT(24)
        EVT_CALL(PlaySoundAtNpc, NPC_YoshiKid, SOUND_SNORE_EXHALE_A, SOUND_SPACE_DEFAULT)
        EVT_WAIT(21)
        EVT_CALL(GetNpcVar, NPC_YoshiKid, 0, LVar0)
        EVT_IF_GE(LVar0, 9)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_YoshiKid_PlaySounds) = {
    EVT_EXEC_GET_TID(N(EVS_YoshiKid_Sleeping), LVar9)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetNpcVar, NPC_YoshiKid, 0, LVar0)
        EVT_IF_GE(LVar0, 9)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVar9)
    EVT_CALL(SetNpcAnimation, NPC_YoshiKid, ANIM_YoshiKid_Purple_Cry)
    EVT_LOOP(3)
        EVT_CALL(PlaySoundAtNpc, NPC_YoshiKid, SOUND_YOSHI_KID_CRY, SOUND_SPACE_DEFAULT)
        EVT_WAIT(13)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_YoshiKid) = {
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, jan_05_ENTRY_3)
        EVT_CALL(DisablePlayerInput, TRUE)
        EVT_CALL(ShowMessageAtScreenPos, MSG_CH5_00B8, 160, 40)
        EVT_CALL(DisablePlayerInput, FALSE)
    EVT_END_IF
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_OnShakeTree_Yoshi)), TRIGGER_WALL_HAMMER, COLLIDER_o87, 1, 0)
    EVT_EXEC_GET_TID(N(EVS_YoshiKid_WatchPlayerProximinity), LVar9)
    EVT_LOOP(0)
        EVT_WAIT(1)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 10)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_KILL_THREAD(LVar9)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar0, -270)
        EVT_SET(LVar0, -324)
        EVT_SET(LVar1, -355)
        EVT_SET(LVar2, 27)
    EVT_ELSE
        EVT_SET(LVar0, -216)
        EVT_SET(LVar1, -185)
        EVT_SET(LVar2, -27)
    EVT_END_IF
    EVT_THREAD
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Purple_Walk)
        EVT_CALL(NpcMoveTo, NPC_SELF, -270, -248, 30)
        EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(DisablePartnerAI, 0)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
        EVT_CALL(NpcMoveTo, NPC_PARTNER, LVar1, -250, 30)
        EVT_CALL(NpcFaceNpc, NPC_PARTNER, NPC_YoshiKid, 0)
        EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, FALSE)
        EVT_CALL(EnablePartnerAI)
    EVT_END_THREAD
    EVT_THREAD
        EVT_CALL(PlayerMoveTo, LVar0, -248, 30)
        EVT_CALL(PlayerFaceNpc, NPC_SELF, FALSE)
    EVT_END_THREAD
    EVT_ADD(LVar0, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, 0, -248)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, 0, -248)
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(350.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(17.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(15)
    EVT_CALL(GetCurrentPartnerID, LVar0)
    EVT_IF_EQ(LVar0, PARTNER_SUSHIE)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Purple_SadTalk, ANIM_YoshiKid_Purple_SadIdle, 0, MSG_CH5_00B9)
    EVT_ELSE
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Purple_SadTalk, ANIM_YoshiKid_Purple_SadIdle, 0, MSG_CH5_00BA)
    EVT_END_IF
    EVT_CALL(EndSpeech, NPC_SELF, ANIM_YoshiKid_Purple_Talk, ANIM_YoshiKid_Purple_Idle, 0)
    EVT_THREAD
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Purple_Run)
        EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0))
        EVT_CALL(NpcMoveTo, NPC_SELF, -315, -135, 0)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.5))
        EVT_CALL(NpcJump0, NPC_SELF, -325, 0, 215, 25)
        EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EVT_END_THREAD
    EVT_SET(GF_JAN05_SavedYoshi, TRUE)
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
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_YoshiKid) = {
    EVT_IF_EQ(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
        EVT_IF_EQ(GF_JAN05_SavedYoshi, FALSE)
            EVT_CALL(SetNpcPos, NPC_SELF, -308, 110, -300)
            EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
            EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Purple_Sleep)
            EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_YoshiKid)))
            EVT_EXEC(N(EVS_YoshiKid_PlaySounds))
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_YoshiKid) = {
    .id = NPC_YoshiKid,
    .pos = { -320.0f, 0.0f, 80.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_YoshiKid),
    .settings = &N(NpcSettings_YoshiKid),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = YOSHI_KID_PURPLE_ANIMS,
    .tattle = MSG_NpcTattle_PurpleYoshiKid,
};

AnimID N(ExtraAnims_JungleFuzzy)[] = {
    ANIM_Fuzzy_Jungle_Idle,
    ANIM_Fuzzy_Jungle_Walk,
    ANIM_Fuzzy_Jungle_Run,
    ANIM_Fuzzy_Jungle_Hurt,
    ANIM_LIST_END
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
            .centerPos  = { 63, 0, -366 },
            .wanderSize = { 50 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 63, 0, -366 },
            .detectSize = { 200 },
        }
    },
    .init = &N(EVS_NpcInit_JungleFuzzy),
    .settings = &N(NpcSettings_JungleFuzzy_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_400000,
    .drops = JUNGLE_FUZZY_DROPS,
    .animations = JUNGLE_FUZZY_ANIMS,
    .extraAnimations = N(ExtraAnims_JungleFuzzy),
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_SpearGuy)[] = {
    {
        .id = NPC_SpearGuy,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 90,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 20 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 100 },
            }
        },
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        SPEAR_GUY_WANDER_NPC_DATA
    },
    SPEAR_GUY_HITBOX(NPC_SpearGuy_Hitbox)
};

NpcData N(NpcData_HeartPlant) = {
    .id = NPC_HeartPlant,
    .pos = { 430.0f, 0.0f, 205.0f },
    .yaw = 270,
    .settings = &N(NpcSettings_HeartPlant),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_8000 | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = HEART_PLANT_ANIMS,
    .tattle = MSG_NpcTattle_HeartPlant,
};

NpcData N(NpcData_HurtPlant) = {
    .id = NPC_HurtPlant,
    .pos = { 375.0f, 0.0f, 260.0f },
    .yaw = 270,
    HURT_PLANT_NPC_DATA
};

NpcData N(NpcData_MBush) = {
    .id = NPC_MBush,
    .pos = { 400.0f, 0.0f, -75.0f },
    .yaw = 90,
    .settings = &N(NpcSettings_MBush),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_8000 | ENEMY_FLAG_400000,
    .drops = MBUSH_DROPS,
    .animations = MBUSH_ANIMS,
    .tattle = MSG_NpcTattle_MBush,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_JungleFuzzy), BTL_JAN_FORMATION_0A, BTL_JAN_STAGE_01),
    NPC_GROUP(N(NpcData_SpearGuy), BTL_JAN_FORMATION_00, BTL_JAN_STAGE_01),
    NPC_GROUP(N(NpcData_HeartPlant)),
    NPC_GROUP(N(NpcData_HurtPlant), BTL_JAN_FORMATION_08, BTL_JAN_STAGE_01),
    NPC_GROUP(N(NpcData_MBush), BTL_JAN_FORMATION_0E, BTL_JAN_STAGE_01),
    NPC_GROUP(N(NpcData_YoshiKid)),
    {}
};
