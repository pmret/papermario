#include "trd_06.h"

#include "world/common/npc/KoopaBros.h"

MobileAISettings N(AISettings_KoopaBros) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_KoopaBros) = {
    Call(BasicAI_Main, Ref(N(AISettings_KoopaBros)))
    Return
    End
};

NpcSettings N(NpcSettings_KoopaBros) = {
    .height = 35,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_KoopaBros),
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

NpcSettings N(NpcSettings_Unused) = {
    .height = 42,
    .radius = 24,
    .level = ACTOR_LEVEL_NONE,
    .ai = &N(EVS_NpcAI_KoopaBros),
};

EvtScript N(EVS_Scene_ImprisonedKoopaBros) = {
    Wait(60)
    Call(EnableNpcAI, NPC_KoopaBros_Red, FALSE)
    Call(SpeakToPlayer, NPC_KoopaBros_Red, ANIM_KoopaBros_Red_Dizzy, ANIM_KoopaBros_Red_Dizzy, 0, MSG_CH1_010C)
    Call(EnableNpcAI, NPC_KoopaBros_Red, TRUE)
    Wait(30)
    Call(FadeOutMusic, 0, 2000)
    Wait(30)
    Call(GetEntryID, LVar0)
    Call(GotoMap, Ref("trd_10"), trd_10_ENTRY_1)
    Wait(100)
    Return
    End
};

NpcData N(NpcData_KoopaBros)[] = {
    {
        .id = NPC_KoopaBros_Red,
        .pos = { 60.0f, 0.0f, -60.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 60, 0, -60 },
                .wanderSize = { 20 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 60, 0, -60 },
                .detectSize = { 0 },
            }
        },
        .settings = &N(NpcSettings_KoopaBros),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = RED_KOOPA_BROS_ANIMS,
    },
    {
        .id = NPC_KoopaBros_Black,
        .pos = { 60.0f, 0.0f, 0.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 60, 0, 0 },
                .wanderSize = { 20 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 60, 0, 60 },
                .detectSize = { 0 },
            }
        },
        .settings = &N(NpcSettings_KoopaBros),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = BLACK_KOOPA_BROS_ANIMS,
    },
    {
        .id = NPC_KoopaBros_Yellow,
        .pos = { -10.0f, 0.0f, -60.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { -10, 0, -60 },
                .wanderSize = { 20 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -10, 0, -60 },
                .detectSize = { 0 },
            }
        },
        .settings = &N(NpcSettings_KoopaBros),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = YELLOW_KOOPA_BROS_ANIMS,
    },
    {
        .id = NPC_KoopaBros_Green,
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 0, 0, 0 },
                .wanderSize = { 20 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { -10, 0, 60 },
                .detectSize = { 0 },
            }
        },
        .settings = &N(NpcSettings_KoopaBros),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
        .drops = NO_DROPS,
        .animations = GREEN_KOOPA_BROS_ANIMS,
    },
};

NpcGroupList N(NpcGroup_KoopaBros) = {
    NPC_GROUP(N(NpcData_KoopaBros)),
    {}
};

#define PARTY_IMAGE "party_pinki"
#include "world/common/todo/LoadPartyImage.inc.c"
