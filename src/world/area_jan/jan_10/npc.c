#include "jan_10.h"
#include "sprite/player.h"

#include "world/common/enemy/JungleFuzzy_Wander.inc.c"
#include "world/common/npc/YoshiKid.inc.c"

EvtScript N(EVS_NpcIdle_JungleFuzzy) = {
    Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    Label(0)
        Call(GetSelfVar, 7, LVar0)
        Wait(1)
        IfEq(LVar0, false)
            Goto(0)
        EndIf
    Call(SetNpcAnimation, NPC_SELF, ANIM_Fuzzy_Jungle_Anim09)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, true)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, false)
    Call(SetNpcPos, NPC_SELF, -566, 100, 65)
    Call(PlaySoundWithVolume, SOUND_FUZZY_HOP_A, 110)
    Wait(20)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, false)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, true)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_JungleFuzzy_Wander)))
    Return
    End
};

EvtScript N(EVS_NpcInit_JungleFuzzy) = {
    Call(SetSelfVar, 7, false)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN, true)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, false)
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_FLYING, true)
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_JungleFuzzy)))
    Return
    End
};

EvtScript N(EVS_YoshiKid_CryForHelp) = {
    Set(AF_JAN_02, false)
    Loop(0)
        Call(PlaySoundAtNpc, NPC_YoshiKid, SOUND_YOSHI_KID_CRY, SOUND_SPACE_DEFAULT)
        Wait(20)
        IfEq(AF_JAN_02, true)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_NpcInteract_YoshiKid) = {
    Call(AdjustCam, CAM_DEFAULT, Float(4.0), 0, 350, Float(17.0), Float(-7.0))
    Set(AF_JAN_02, true)
    Wait(15)
    Call(GetCurrentPartnerID, LVar0)
    IfEq(LVar0, PARTNER_SUSHIE)
        Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Blue_SadTalk, ANIM_YoshiKid_Blue_SadIdle, 0, MSG_CH5_00B2)
    Else
        Call(SpeakToPlayer, NPC_SELF, ANIM_YoshiKid_Blue_SadTalk, ANIM_YoshiKid_Blue_SadIdle, 0, MSG_CH5_00B3)
    EndIf
    Call(EndSpeech, NPC_SELF, ANIM_YoshiKid_Blue_Talk, ANIM_YoshiKid_Blue_Idle, 0)
    Thread
        Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, true)
        Call(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Blue_Run)
        Call(SetNpcSpeed, NPC_SELF, Float(5.0))
        Call(NpcMoveTo, NPC_SELF, -240, 10, 0)
        Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
    EndThread
    Set(GF_JAN10_SavedYoshi, true)
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
        Wait(30)
    EndIf
    Call(ResetCam, CAM_DEFAULT, Float(4.0))
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

EvtScript N(EVS_NpcInit_YoshiKid) = {
    IfEq(GB_StoryProgress, STORY_CH5_SUSHIE_JOINED_PARTY)
        Exec(N(EVS_YoshiKid_CryForHelp))
        IfEq(GF_JAN10_SavedYoshi, false)
            Call(SetNpcAnimation, NPC_SELF, ANIM_YoshiKid_Blue_Cry)
            Call(SetNpcYaw, NPC_SELF, 90)
            Call(SetNpcPos, NPC_SELF, -450, 0, 70)
            Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_YoshiKid)))
            Return
        EndIf
    EndIf
    Call(RemoveNpc, NPC_SELF)
    Return
    End
};

NpcData N(NpcData_YoshiKid) = {
    .id = NPC_YoshiKid,
    .pos = { -260.0f, 0.0f, -220.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_YoshiKid),
    .settings = &N(NpcSettings_YoshiKid),
    .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_DO_NOT_KILL | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
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
            .isFlying = true,
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
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .drops = JUNGLE_FUZZY_DROPS,
    .animations = JUNGLE_FUZZY_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_YoshiKid)),
    NPC_GROUP(N(NpcData_JungleFuzzy), BTL_JAN_FORMATION_0A, BTL_JAN_STAGE_03),
    {}
};
