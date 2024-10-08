#include "nok_03.h"

#include "world/common/enemy/Fuzzy_Wander.inc.c"
#include "world/common/enemy/Fuzzy.inc.c"
#include "world/common/npc/Koopa.inc.c"

EvtScript N(EVS_NpcIdle_FuzzyBoss) = {
    Thread
        Label(0)
            Call(GetNpcPos, NPC_Fuzzy_03, LVar0, LVar1, LVar2)
            Add(LVar2, 2)
            Call(SetNpcPos, NPC_KoopersShell, LVar0, LVar1, LVar2)
            Wait(1)
            Goto(0)
    EndThread
    Label(1)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        Call(GetNpcPos, NPC_Fuzzy_03, LVar3, LVar4, LVar5)
        Set(LVar6, LVar3)
        Sub(LVar6, LVar0)
        IfLt(LVar6, 100)
            Add(LVar3, 100)
            Call(PlaySoundAtNpc, NPC_Fuzzy_03, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
            Call(NpcJump0, NPC_Fuzzy_03, LVar3, LVar4, LVar5, 10 * DT)
            Set(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_RAN_AWAY)
        EndIf
        IfGt(LVar3, 1200)
            Call(SetNpcPos, NPC_Fuzzy_03, NPC_DISPOSE_LOCATION)
            Call(SetNpcPos, NPC_KoopersShell, NPC_DISPOSE_LOCATION)
            Call(EnableNpcShadow, NPC_Fuzzy_03, FALSE)
            Call(EnableNpcShadow, NPC_KoopersShell, FALSE)
            Return
        EndIf
        Wait(1)
        Goto(1)
    Return
    End
};

EvtScript N(EVS_NpcIdle_Fuzzy_01) = {
    Wait(5)
    Label(10)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar0, -400)
            Wait(1)
            Goto(10)
        EndIf
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Call(SetNpcJumpscale, NPC_SELF, Float(3.0))
    Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 6)
    Call(SetNpcJumpscale, NPC_SELF, Float(1.2))
    Add(LVar0, 20)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 8)
    Sub(LVar0, 15)
    Add(LVar2, 20)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 10)
    Add(LVar0, 20)
    Add(LVar2, 20)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
    Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 8)
    Call(PlaySoundAtNpc, NPC_SELF, SOUND_SEQ_FUZZY_HOP, SOUND_SPACE_DEFAULT)
    Call(SetNpcJumpscale, NPC_SELF, Float(1.8))
    Call(NpcJump0, NPC_SELF, -341, 0, 23, 15)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_BEGIN_WITH_CHASING, TRUE)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_Fuzzy_Wander)))
    Return
    End
};

EvtScript N(EVS_NpcIdle_Fuzzy_02) = {
    Wait(5)
    Label(0)
        Call(GetPlayerPos, LVar0, LVar1, LVar2)
        IfLt(LVar0, -140)
            Wait(1)
            Goto(0)
        EndIf
    Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    Set(LVar1, 0)
    Call(SetNpcJumpscale, NPC_SELF, Float(3.0))
    Call(NpcJump0, NPC_SELF, LVar0, LVar1, LVar2, 6)
    Call(SetSelfEnemyFlagBits, ENEMY_FLAG_BEGIN_WITH_CHASING, TRUE)
    Call(BindNpcAI, NPC_SELF, Ref(N(EVS_NpcAI_Fuzzy_Wander)))
    Return
    End
};

EvtScript N(EVS_NpcInit_Fuzzy_01) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Fuzzy_01)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_Fuzzy_02) = {
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_Fuzzy_02)))
    Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_WORLD_COLLISION, TRUE)
    Return
    End
};

EvtScript N(EVS_NpcInit_FuzzyBoss) = {
    IfGe(GB_StoryProgress, STORY_CH1_FUZZY_THIEF_RAN_AWAY)
        Call(SetNpcFlagBits, NPC_Fuzzy_03, NPC_FLAG_GRAVITY, FALSE)
        Call(SetNpcFlagBits, NPC_KoopersShell, NPC_FLAG_GRAVITY, FALSE)
        Call(SetNpcPos, NPC_Fuzzy_03, NPC_DISPOSE_LOCATION)
        Call(SetNpcPos, NPC_KoopersShell, NPC_DISPOSE_LOCATION)
        Call(EnableNpcShadow, NPC_Fuzzy_03, FALSE)
        Call(EnableNpcShadow, NPC_KoopersShell, FALSE)
        Return
    EndIf
    Call(BindNpcIdle, NPC_SELF, Ref(N(EVS_NpcIdle_FuzzyBoss)))
    Return
    End
};

EvtScript N(EVS_NpcInit_KoopersShell) = {
    Call(EnableNpcShadow, NPC_SELF, FALSE)
    Call(SetNpcAnimation, NPC_SELF, ANIM_WorldKooper_StillShellAlt)
    Return
    End
};

NpcData N(NpcData_Fuzzy_01) = {
    .id = NPC_Fuzzy_01,
    .pos = { -388.0f, 100.0f, -107.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -388, 100, -107 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -388, 0, -107 },
            .detectSize = { 300 },
        }
    },
    .init = &N(EVS_NpcInit_Fuzzy_01),
    .settings = &N(NpcSettings_Fuzzy_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .drops = FUZZY_DROPS,
    .animations = FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_Fuzzy_02) = {
    .id = NPC_Fuzzy_02,
    .pos = { -76.0f, 118.0f, -43.0f },
    .yaw = 0,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -76, 118, -43 },
            .wanderSize = { 100 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -76, 118, -43 },
            .detectSize = { 300 },
        }
    },
    .init = &N(EVS_NpcInit_Fuzzy_02),
    .settings = &N(NpcSettings_Fuzzy_Wander),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .drops = FUZZY_DROPS,
    .animations = FUZZY_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcData N(NpcData_FuzzyBoss)[] = {
    {
        .id = NPC_Fuzzy_03,
        .pos = { -540.0f, 0.0f, 0.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .init = &N(EVS_NpcInit_FuzzyBoss),
        .settings = &N(NpcSettings_Fuzzy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = FUZZY_DROPS,
        .animations = FUZZY_ANIMS,
    },
    {
        .id = NPC_KoopersShell,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .init = &N(EVS_NpcInit_KoopersShell),
        .settings = &N(NpcSettings_Koopa),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
        .drops = FUZZY_DROPS,
        .animations = KOOPER_ANIMS,
    },
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Fuzzy_01), BTL_NOK_FORMATION_16, BTL_NOK_STAGE_01),
    NPC_GROUP(N(NpcData_Fuzzy_02), BTL_NOK_FORMATION_16, BTL_NOK_STAGE_01),
    NPC_GROUP(N(NpcData_FuzzyBoss)),
    {}
};
