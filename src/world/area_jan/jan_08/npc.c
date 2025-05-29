#include "jan_08.h"
#include "sprite/player.h"

#include "world/common/npc/YoshiKid.inc.c"
#include "world/common/enemy/MBush.inc.c"
#include "world/common/enemy/HeartPlant.inc.c"

#include "world/common/enemy/HurtPlant.inc.c"
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
    Call(SetSelfVar, 0, 0)
    Label(0)
    Call(GetPlayerPos, LVar1, LVar2, LVar3)
    IfLe(LVar1, -90)
        IfGt(LVar3, 280)
            Call(GetEntryID, LVar0)
            IfEq(LVar0, jan_08_ENTRY_0)
                Wait(18)
            EndIf
            Call(DisablePlayerInput, TRUE)
            Call(ShowMessageAtScreenPos, MSG_CH5_00AF, 160, 40)
            Exec(N(EVS_YoshiKid_CryForHelp))
            Call(DisablePlayerInput, FALSE)
            Set(LVar0, 1)
        EndIf
    EndIf
    IfNe(LVar0, 1)
        Wait(1)
        Goto(0)
    EndIf
    Label(10)
    Call(GetSelfVar, 0, LVar0)
    IfEq(LVar0, 0)
        Wait(1)
        Goto(10)
    EndIf
    Call(DisablePlayerInput, TRUE)
    Call(AdjustCam, CAM_DEFAULT, Float(4.0), -23, 350, Float(17.0), Float(-7.0))
    Call(NpcFacePlayer, NPC_SELF, 0)
    Call(GetCurrentPartnerID, LVar0)
    Set(AF_JAN_02, TRUE)
    Wait(15)
    IfEq(LVar0, PARTNER_SUSHIE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Red_SadTalk, ANIM_YoshiKid_Red_SadIdle, 0, MSG_CH5_00B0)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Red_SadTalk, ANIM_YoshiKid_Red_SadIdle, 0, MSG_CH5_00B1)
    EndIf
    Call(EndSpeech, NPC_SELF, ANIM_YoshiKid_Red_Talk, ANIM_YoshiKid_Red_Idle, 0)
    Thread
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
        Call(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Red_Run)
        Call(SetNpcSpeed, NPC_SELF, Float(5.0))
        Call(NpcMoveTo, NPC_SELF, -418, -60, 0)
        Call(NpcMoveTo, NPC_SELF, -300, 80, 0)
        Call(NpcMoveTo, NPC_SELF, -320, 115, 0)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndThread
    Set(GF_JAN08_SavedYoshi, TRUE)
    Set(LVar0, 0)
    Add(LVar0, GF_JAN05_SavedYoshi)
    Add(LVar0, GF_JAN07_SavedYoshi)
    Add(LVar0, GF_JAN08_SavedYoshi)
    Add(LVar0, GF_JAN10_SavedYoshi)
    Add(LVar0, GF_JAN11_SavedYoshi)
    IfEq(LVar0, 5)
        Call(SetMusic, 0, SONG_YOSHI_KIDS_FOUND, 0, VOL_LEVEL_FULL)
        Set(GB_StoryProgress, STORY_CH5_ALL_YOSHI_CHILDREN_RESCUED)
        Call(SetPlayerAnimation, ANIM_Mario1_ThumbsUp)
        Wait(120)
        Exec(N(EVS_SetupMusic))
        Call(SetPlayerAnimation, ANIM_Mario1_Idle)
    Else
        Wait(40)
    EndIf
    Call(ResetCam, CAM_DEFAULT, Float(4.0))
    Call(DisablePlayerInput, FALSE)
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcInit_YoshiKid) = {
    IfEq(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
        IfEq(GF_JAN08_SavedYoshi, FALSE)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
            Call(EnableNpcShadow, NPC_SELF, FALSE)
            Call(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Red_Cry)
            Call(SetNpcYaw, NPC_SELF, 90)
            Call(SetNpcPos, NPC_SELF, -391, 0, -164)
            Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_YoshiKid)))
            Return
        EndIf
    EndIf
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

// unchanged from MBush.inc.c
EvtScript N(EVS_NpcDefeat_MBush_Copy) = {
    Call(GetBattleOutcome, LVar0)
    Switch(LVar0)
        CaseEq(OUTCOME_PLAYER_WON)
            Call(DoNpcDefeat)
        CaseEq(OUTCOME_PLAYER_FLED)
            Call(SetNpcAnimation, NPC_SELF, ANIM_MBush_Anim05)
            Call(GetSelfVar, 10, LVar0)
            Call(GetSelfVar, 11, LVar1)
            Call(GetSelfVar, 12, LVar2)
            Call(NpcJump1, NPC_SELF, LVar0, LVar1, LVar2, 8)
            Call(EnableNpcShadow, NPC_SELF, FALSE)
            Call(SetNpcAnimation, NPC_SELF, ANIM_MBush_Anim00)
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
            Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_MBush)))
        CaseEq(OUTCOME_ENEMY_FLED)
            Call(SetEnemyFlagBits, NPC_SELF, ENEMY_FLAG_FLED, TRUE)
            Call(RemoveNpc, NPC_SELF)
    EndSwitch
    Return
    End
};

EvtScript N(EVS_NpcInit_MBush_01) = {
    Call(SetNpcCollisionSize, NPC_SELF, 60, 30)
    Call(BindNpcDefeat, NPC_SELF, Ref(N(EVS_NpcDefeat_MBush_Copy)))
    Return
    End
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
        .settings = &N(NpcSettings_SpearGuy_Wander),
        .drops = SPEAR_GUY_DROPS,
        .animations = SPEAR_GUY_ANIMS,
        .extraAnimations = N(ExtraAnims_SpearGuy),
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    SPEAR_GUY_HITBOX(NPC_SpearGuy_Hitbox)
};

NpcData N(NpcData_HurtPlant) = {
    .id = NPC_HurtPlant,
    .pos = { 400.0f, 0.0f, 235.0f },
    .yaw = 270,
    .settings = &N(NpcSettings_HurtPlant),
    .flags = HURT_PLANT_FLAGS,
    .drops = HURT_PLANT_DROPS,
    .animations = HURT_PLANT_ANIMS,
    .extraAnimations = N(ExtraAnims_HurtPlant),
    .tattle = MSG_NpcTattle_HeartPlant,
};

NpcData N(NpcData_MBush_01) = {
    .id = NPC_MBush_01,
    .pos = { -407.0f, 0.0f, -42.0f },
    .yaw = 90,
    .settings = &N(NpcSettings_MBush),
    .flags = MBUSH_FLAGS,
    .drops = MBUSH_DROPS,
    .animations = MBUSH_ANIMS,
    .tattle = MSG_NpcTattle_MBush,
    .init = &N(EVS_NpcInit_MBush_01),
};

NpcData N(NpcData_MBush_02) = {
    .id = NPC_MBush_02,
    .pos = { -120.0f, 0.0f, -395.0f },
    .yaw = 90,
    .settings = &N(NpcSettings_MBush),
    .flags = MBUSH_FLAGS,
    .drops = MBUSH_DROPS,
    .animations = MBUSH_ANIMS,
    .tattle = MSG_NpcTattle_MBush,
};

NpcData N(NpcData_HeartPlant_01) = {
    .id = NPC_HeartPlant_01,
    .pos = { -219.0f, 0.0f, 420.0f },
    .yaw = 270,
    .settings = &N(NpcSettings_HeartPlant),
    .flags = HEART_PLANT_FLAGS,
    .drops = NO_DROPS,
    .animations = HEART_PLANT_ANIMS,
    .tattle = MSG_NpcTattle_HeartPlant,
};

NpcData N(NpcData_HeartPlant_02) = {
    .id = NPC_HeartPlant_02,
    .pos = { -157.0f, 0.0f, 452.0f },
    .yaw = 270,
    .settings = &N(NpcSettings_HeartPlant),
    .flags = HEART_PLANT_FLAGS,
    .drops = NO_DROPS,
    .animations = HEART_PLANT_ANIMS,
    .tattle = MSG_NpcTattle_HeartPlant,
};

NpcData N(NpcData_YoshiKid) = {
    .id = NPC_YoshiKid,
    .pos = { -450.0f, 0.0f, -290.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_YoshiKid),
    .settings = &N(NpcSettings_YoshiKid),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
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
