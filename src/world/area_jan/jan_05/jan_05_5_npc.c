#include "jan_05.h"
#include "sprite/player.h"

#include "world/common/enemy/MBush.inc.c"
#include "world/common/npc/YoshiKid.inc.c"
#include "world/common/enemy/HeartPlant.inc.c"
#include "world/common/enemy/HurtPlant.inc.c"
#include "world/common/enemy/JungleFuzzy_Wander.inc.c"
#include "world/common/enemy/SpearGuy_Wander.inc.c"

EvtScript N(EVS_NpcIdle_JungleFuzzy) = {
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Label(0)
    Call(GetSelfVar, 7, LVar0)
    Wait(1)
    IfEq(LVar0, 0)
        Goto(0)
    EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Jungle_Anim09)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, FALSE)
    Call(SetNpcPos, NPC_SELF, 125, 100, -392)
    Call(PlaySoundWithVolume, SOUND_FUZZY_HOP_A, 110)
    Wait(20)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, TRUE)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_JungleFuzzy_Wander)))
    Return
    End
};

EvtScript N(EVS_NpcInit_JungleFuzzy) = {
    Call(SetSelfVar, 7, 0)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN, 1)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, FALSE)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, TRUE)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_JungleFuzzy)))
    Return
    End
};

EvtScript N(EVS_YoshiKid_WatchPlayerProximinity) = {
    Label(1)
    Call(GetSelfVar, 0, LVar0)
    Switch(LVar0)
        CaseEq(0)
            Call(AwaitPlayerLeave, -308, -270, 70)
            Call(SetSelfVar, 0, 1)
        CaseEq(1)
            Call(AwaitPlayerApproach, -308, -270, 50)
            Call(DisablePlayerInput, TRUE)
            Call(ShowMessageAtScreenPos, MSG_CH5_00B8, 160, 40)
            Call(DisablePlayerInput, FALSE)
            Call(SetSelfVar, 0, 0)
    EndSwitch
    Wait(1)
    Goto(1)
    Return
    End
};

EvtScript N(EVS_OnShakeTree_Yoshi) = {
    Call(DisablePlayerInput, TRUE)
    Call(SetNpcVar, NPC_YoshiKid, 0, 9)
    Thread
        Call(PlaySoundAtNpc, NPC_YoshiKid, SOUND_FALL_QUICK, SOUND_SPACE_DEFAULT)
        Call(SetNpcJumpscale, NPC_YoshiKid, Float(1.0))
        Call(NpcJump0, NPC_YoshiKid, -308, 0, -248, 30)
    EndThread
    Call(EnableNpcShadow, NPC_YoshiKid, TRUE)
    Wait(40)
    Call(SetNpcVar, NPC_YoshiKid, 0, 10)
    Call(DisablePlayerInput, FALSE)
    Unbind
    Return
    End
};

EvtScript N(EVS_YoshiKid_Sleeping) = {
    Loop(0)
        Call(PlaySoundAtNpc, NPC_YoshiKid, SOUND_SNORE_INHALE_A, SOUND_SPACE_DEFAULT)
        Wait(24)
        Call(PlaySoundAtNpc, NPC_YoshiKid, SOUND_SNORE_EXHALE_A, SOUND_SPACE_DEFAULT)
        Wait(21)
        Call(GetNpcVar, NPC_YoshiKid, 0, LVar0)
        IfGe(LVar0, 9)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_YoshiKid_PlaySounds) = {
    ExecGetTID(N(EVS_YoshiKid_Sleeping), LVar9)
    Loop(0)
        Wait(1)
        Call(GetNpcVar, NPC_YoshiKid, 0, LVar0)
        IfGe(LVar0, 9)
            BreakLoop
        EndIf
    EndLoop
    KillThread(LVar9)
    Call(SetNpcAnimation, NPC_YoshiKid, ANIM_YoshiKid_Purple_Cry)
    Loop(3)
        Call(PlaySoundAtNpc, NPC_YoshiKid, SOUND_YOSHI_KID_CRY, SOUND_SPACE_DEFAULT)
        Wait(13)
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcIdle_YoshiKid) = {
    Call(GetEntryID, LVar0)
    IfEq(LVar0, jan_05_ENTRY_3)
        Call(DisablePlayerInput, TRUE)
        Call(ShowMessageAtScreenPos, MSG_CH5_00B8, 160, 40)
        Call(DisablePlayerInput, FALSE)
    EndIf
    BindTrigger(Ref(N(EVS_OnShakeTree_Yoshi)), TRIGGER_WALL_HAMMER, COLLIDER_o87, 1, 0)
    ExecGetTID(N(EVS_YoshiKid_WatchPlayerProximinity), LVar9)
    Loop(0)
        Wait(1)
        Call(GetSelfVar, 0, LVar0)
        IfEq(LVar0, 10)
            BreakLoop
        EndIf
    EndLoop
    KillThread(LVar9)
    Call(DisablePlayerInput, TRUE)
    Call(GetPlayerPos, LVar0, LVar1, LVar2)
    IfLt(LVar0, -270)
        Set(LVar0, -324)
        Set(LVar1, -355)
        Set(LVar2, 27)
    Else
        Set(LVar0, -216)
        Set(LVar1, -185)
        Set(LVar2, -27)
    EndIf
    Thread
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Purple_Walk)
        Call(NpcMoveTo, NPC_SELF, -270, -248, 30)
        Call(NpcFacePlayer, NPC_SELF, 0)
    EndThread
    Thread
        Call(DisablePartnerAI, 0)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, TRUE)
        Call(NpcMoveTo, NPC_PARTNER, LVar1, -250, 30)
        Call(NpcFaceNpc, NPC_PARTNER, NPC_YoshiKid, 0)
        Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_IGNORE_WORLD_COLLISION | NPC_FLAG_IGNORE_PLAYER_COLLISION | NPC_FLAG_IGNORE_ENTITY_COLLISION, FALSE)
        Call(EnablePartnerAI)
    EndThread
    Thread
        Call(PlayerMoveTo, LVar0, -248, 30)
        Call(PlayerFaceNpc, NPC_SELF, FALSE)
    EndThread
    Add(LVar0, LVar2)
    Call(UseSettingsFrom, CAM_DEFAULT, LVar0, 0, -248)
    Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, -248)
    Call(SetCamDistance, CAM_DEFAULT, Float(350.0))
    Call(SetCamPitch, CAM_DEFAULT, Float(17.0), Float(-7.0))
    Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Wait(15)
    Call(GetCurrentPartnerID, LVar0)
    IfEq(LVar0, PARTNER_SUSHIE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Purple_SadTalk, ANIM_YoshiKid_Purple_SadIdle, 0, MSG_CH5_00B9)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Purple_SadTalk, ANIM_YoshiKid_Purple_SadIdle, 0, MSG_CH5_00BA)
    EndIf
    Call(EndSpeech, NPC_SELF, ANIM_YoshiKid_Purple_Talk, ANIM_YoshiKid_Purple_Idle, 0)
    Thread
        Call(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Purple_Run)
        Call(SetNpcSpeed, NPC_SELF, Float(5.0))
        Call(NpcMoveTo, NPC_SELF, -315, -135, 0)
        Call(SetNpcJumpscale, NPC_SELF, Float(0.5))
        Call(NpcJump0, NPC_SELF, -325, 0, 215, 25)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndThread
    Set(GF_JAN05_SavedYoshi, TRUE)
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
        Wait(30)
    EndIf
    Call(ResetCam, CAM_DEFAULT, Float(4.0))
    Call(DisablePlayerInput, FALSE)
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcInit_YoshiKid) = {
    IfEq(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
        IfEq(GF_JAN05_SavedYoshi, FALSE)
            Call(SetNpcPos, NPC_SELF, -308, 110, -300)
            Call(EnableNpcShadow, NPC_SELF, FALSE)
            Call(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Purple_Sleep)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_YoshiKid)))
            Exec(N(EVS_YoshiKid_PlaySounds))
            Return
        EndIf
    EndIf
    Call(RemoveNpc, NPC_SELF)
    Return
    End
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
        .settings = &N(NpcSettings_SpearGuy_Wander),
        .drops = SPEAR_GUY_DROPS,
        .animations = SPEAR_GUY_ANIMS,
        .extraAnimations = N(ExtraAnims_SpearGuy),
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
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
    .settings = &N(NpcSettings_HurtPlant),
    .flags = HURT_PLANT_FLAGS,
    .drops = HURT_PLANT_DROPS,
    .animations = HURT_PLANT_ANIMS,
    .extraAnimations = N(ExtraAnims_HurtPlant),
    .tattle = MSG_NpcTattle_HeartPlant,
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
