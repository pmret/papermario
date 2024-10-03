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
    Set(AF_JAN_02, FALSE)
    Loop(0)
        Call(PlaySoundAtNpc, NPC_YoshiKid, SOUND_YOSHI_KID_CRY, SOUND_SPACE_DEFAULT)
        Wait(20)
        IfEq(AF_JAN_02, TRUE)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_YoshiKid) = {
    IfEq(GF_JAN07_YoshiCriedForHelp, FALSE)
        Call(DisablePlayerInput, TRUE)
        Call(ShowMessageAtScreenPos, MSG_CH5_00B4, 320, 60)
        Call(PlaySoundAtPlayer, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        Call(ShowEmote, 0, EMOTE_EXCLAMATION, 0, 30, EMOTER_PLAYER, 0, 0, 0, 0)
        Call(PlaySoundAtNpc, NPC_PARTNER, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        Call(ShowEmote, NPC_PARTNER, EMOTE_EXCLAMATION, 0, 30, EMOTER_NPC, 0, 0, 0, 0)
        Wait(30)
        Call(UseSettingsFrom, CAM_DEFAULT, -183, 50, -11)
        Call(SetPanTarget, CAM_DEFAULT, 50, 0, 0)
        Call(SetCamDistance, CAM_DEFAULT, 500)
        Call(SetCamPitch, CAM_DEFAULT, 16, Float(-6.0))
        Call(SetCamSpeed, CAM_DEFAULT, 3)
        Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Yellow_Cry, ANIM_YoshiKid_Yellow_Cry, 5, MSG_CH5_00B5)
        Wait(10)
        Exec(N(EVS_YoshiKid_CryForHelp))
        Call(ResetCam, CAM_DEFAULT, Float(90.0))
        Set(GF_JAN07_YoshiCriedForHelp, TRUE)
        Call(DisablePlayerInput, FALSE)
    EndIf
    Label(0)
        Call(GetSelfVar, 0, LVar0)
        IfNe(LVar0, 1)
            Wait(1)
            Goto(0)
        EndIf
    Call(DisablePlayerInput, TRUE)
    Call(UseSettingsFrom, CAM_DEFAULT, -20, 0, 20)
    Call(SetPanTarget, CAM_DEFAULT, -20, 0, 20)
    Call(SetCamDistance, CAM_DEFAULT, Float(300.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(2.5))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Thread
        Call(DisablePartnerAI, 0)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_WALK)
        Call(NpcMoveTo, NPC_PARTNER, -55, 5, 30)
        Call(SetNpcAnimation, NPC_PARTNER, PARTNER_ANIM_IDLE)
        Call(NpcFaceNpc, NPC_PARTNER, NPC_SELF, 0)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, FALSE)
        Call(EnablePartnerAI)
    EndThread
    Call(PlayerMoveTo, -20, 10, 25)
    Wait(15)
    Set(AF_JAN_02, TRUE)
    Thread
        Call(PlaySoundAtNpc, NPC_SELF, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
        Call(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, 0, 30, EMOTER_NPC, 0, 0, 0, 0)
    EndThread
    Wait(30)
    Call(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Yellow_SadIdle)
    Wait(10)
    Call(InterpNpcYaw, NPC_SELF, 270, 0)
    Wait(30)
    Call(InterpNpcYaw, NPC_SELF, 90, 0)
    Wait(15)
    Call(InterpNpcYaw, NPC_SELF, 270, 0)
    Wait(10)
    Call(GetCurrentPartnerID, LVar0)
    IfEq(LVar0, PARTNER_SUSHIE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Yellow_SadTalk, ANIM_YoshiKid_Yellow_SadIdle, 0, MSG_CH5_00B6)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Yellow_SadTalk, ANIM_YoshiKid_Yellow_SadIdle, 0, MSG_CH5_00B7)
    EndIf
    Call(EndSpeech, NPC_SELF, ANIM_YoshiKid_Yellow_Talk, ANIM_YoshiKid_Yellow_Idle, 0)
    Thread
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Yellow_Run)
        Call(SetNpcSpeed, NPC_SELF, Float(5.0))
        Call(NpcMoveTo, NPC_SELF, -150, 15, 0)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndThread
    Set(GF_JAN07_SavedYoshi, TRUE)
    Set(LVar0, 0)
    Add(LVar0, GF_JAN05_SavedYoshi)
    Add(LVar0, GF_JAN07_SavedYoshi)
    Add(LVar0, GF_JAN08_SavedYoshi)
    Add(LVar0, GF_JAN10_SavedYoshi)
    Add(LVar0, GF_JAN11_SavedYoshi)
    IfEq(LVar0, 5)
        Call(SetMusicTrack, 0, SONG_YOSHI_KIDS_FOUND, 0, 8)
        Set(GB_StoryProgress, STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
        Call(SetPlayerAnimation, ANIM_Mario1_ThumbsUp)
        Wait(120)
        Exec(N(EVS_SetupMusic))
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Else
        Thread
            Wait(12)
            Call(InterpPlayerYaw, 270, 0)
            Call(InterpNpcYaw, NPC_PARTNER, 270, 0)
        EndThread
        Wait(30)
    EndIf
    Call(ResetCam, CAM_DEFAULT, Float(4.5))
    Call(DisablePlayerInput, FALSE)
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcInit_YoshiKid) = {
    IfEq(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
        IfEq(GF_JAN07_SavedYoshi, FALSE)
            Call(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Yellow_Cry)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_YoshiKid)))
            Return
        EndIf
    EndIf
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcIdle_PutridPiranha) = {
#if VERSION_PAL
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH, TRUE)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_PARTNER, TRUE)
#elif VERSION_US || VERSION_IQUE
    ChildThread
        Loop(0)
            Call(GetPlayerPos, LVar0, LVar1, LVar2)
            IfLt(LVar0, -190)
                Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH, TRUE)
                Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_PARTNER, TRUE)
            Else
                Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_TOUCH, FALSE)
                Call(SetSelfEnemyFlagBits, ENEMY_FLAG_IGNORE_PARTNER, FALSE)
            EndIf
            Wait(1)
        EndLoop
    EndChildThread
#endif
    Call(SetNpcCollisionSize, NPC_PutridPiranha_01, 48, 40)
    Call(SetNpcCollisionSize, NPC_PutridPiranha_02, 48, 40)
    Call(AwaitPlayerApproach, 60, 20, 140)
    Call(DisablePlayerInput, TRUE)
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, 0)
        Call(InterruptUsePartner)
    EndIf
    Wait(5)
    Thread
        Call(UseSettingsFrom, CAM_DEFAULT, -60, 0, 20)
        Call(SetPanTarget, CAM_DEFAULT, -50, 0, 20)
        Call(SetCamSpeed, CAM_DEFAULT, Float(1.0))
        Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    EndThread
    Thread
        Call(InterpNpcYaw, NPC_PutridPiranha_01, 270, 0)
    EndThread
    Call(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim04)
    Call(PlaySoundAtNpc, NPC_PutridPiranha_02, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_PutridPiranha_02, EMOTE_EXCLAMATION, 0, 38, EMOTER_NPC, 0, 0, 0, 0)
    Wait(3)
    Call(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim04)
    Call(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_EMOTE_IDEA, SOUND_SPACE_DEFAULT)
    Call(ShowEmote, NPC_PutridPiranha_01, EMOTE_EXCLAMATION, 0, 35, EMOTER_NPC, 0, 0, 0, 0)
    Wait(35)
    Call(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim01)
    Call(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim01)
    Wait(5)
    Call(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim04)
    Set(LVar0, 0)
    Loop(15)
        Add(LVar0, 24)
        Call(SetNpcRotation, NPC_PutridPiranha_01, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Call(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_PIRANHA_SPIN_1, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim01)
    Wait(5)
    Call(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim04)
    Set(LVar0, 0)
    Loop(15)
        Add(LVar0, 24)
        Call(SetNpcRotation, NPC_PutridPiranha_02, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Call(PlaySoundAtNpc, NPC_PutridPiranha_02, SOUND_PIRANHA_SPIN_1, SOUND_SPACE_DEFAULT)
    Call(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim01)
    Wait(5)
    Call(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim04)
    Call(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim04)
    Set(LVar0, 0)
    Loop(12)
        Add(LVar0, 30)
        Call(SetNpcRotation, NPC_PutridPiranha_01, 0, LVar0, 0)
        Call(SetNpcRotation, NPC_PutridPiranha_02, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Call(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_PIRANHA_SPIN_2, SOUND_SPACE_DEFAULT)
    Set(LVar0, 0)
    Loop(12)
        Add(LVar0, 30)
        Call(SetNpcRotation, NPC_PutridPiranha_01, 0, LVar0, 0)
        Call(SetNpcRotation, NPC_PutridPiranha_02, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Call(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_PIRANHA_SPIN_2, SOUND_SPACE_DEFAULT)
    Set(LVar0, 0)
    Loop(12)
        Add(LVar0, 30)
        Call(SetNpcRotation, NPC_PutridPiranha_01, 0, LVar0, 0)
        Call(SetNpcRotation, NPC_PutridPiranha_02, 0, LVar0, 0)
        Wait(1)
    EndLoop
    Call(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_PIRANHA_SPIN_2, SOUND_SPACE_DEFAULT)
    Loop(3)
        Wait(5)
        Call(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_PIRANHA_TENSE, SOUND_SPACE_DEFAULT)
    EndLoop
    Call(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim05)
    Call(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim05)
    Wait(20)
    Call(SetNpcAnimation, NPC_PutridPiranha_01, ANIM_LargePiranha_Putrid_Anim06)
    Call(SetNpcAnimation, NPC_PutridPiranha_02, ANIM_LargePiranha_Putrid_Anim06)
    Call(PlaySoundAtNpc, NPC_PutridPiranha_01, SOUND_PIRANHA_CHOMP, SOUND_SPACE_DEFAULT)
    Call(DisablePlayerInput, FALSE)
    Call(StartBossBattle, SONG_SPECIAL_BATTLE)
    Return
    End
};

EvtScript N(EVS_NpcDefeat_PutridPiranha) = {
    Call(UseSettingsFrom, CAM_DEFAULT, -20, 0, 20)
    Call(SetPanTarget, CAM_DEFAULT, -20, 0, 20)
    Call(SetCamDistance, CAM_DEFAULT, Float(500.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, TRUE)
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(SetNpcVar, NPC_YoshiKid, 0, 1)
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_LOST)
        CaseEq(OUTCOME_PLAYER_FLED)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_PutridPiranha) = {
    IfEq(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
        IfEq(GF_JAN07_SavedYoshi, FALSE)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_PutridPiranha)))
            Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_PutridPiranha)))
            Return
        EndIf
    EndIf
    Call(RemoveEncounter, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcInit_SpearGuy_Hitbox) = {
    IfEq(GF_JAN07_SavedYoshi, FALSE)
        Call(RemoveNpc, NPC_SpearGuy)
        Call(RemoveNpc, NPC_SpearGuy_Hitbox)
    EndIf
    Return
    End
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
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | ENEMY_FLAG_NO_DROPS,
        .drops = NO_DROPS,
        .animations = PUTRID_PIRANHA_ANIMS,
    },
    {
        .id = NPC_PutridPiranha_02,
        .pos = { 80.0f, 0.0f, 20.0f },
        .yaw = 270,
        .settings = &N(NpcSettings_PutridPiranha),
        .flags = ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_DELAY_AFTER_FLEE | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER | ENEMY_FLAG_NO_DROPS,
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
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
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
