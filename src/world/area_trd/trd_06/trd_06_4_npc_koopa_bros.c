#include "trd_06.h"

MobileAISettings N(AISettings_KoopaBros) = {
    .moveSpeed = 1.5f,
    .moveTime = 60,
    .waitTime = 30,
    .playerSearchInterval = -1,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_KoopaBros) = {
    EVT_CALL(BasicAI_Main, EVT_PTR(N(AISettings_KoopaBros)))
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_KoopaBros) = {
    .height = 35,
    .radius = 24,
    .level = 99,
    .ai = &N(EVS_NpcAI_KoopaBros),
    .actionFlags = AI_ACTION_LOOK_AROUND_DURING_LOITER,
};

NpcSettings N(NpcSettings_Unused) = {
    .height = 42,
    .radius = 24,
    .level = 99,
    .ai = &N(EVS_NpcAI_KoopaBros),
};

EvtScript N(EVS_Scene_ImprisonedKoopaBros) = {
    EVT_WAIT(60)
    EVT_CALL(EnableNpcAI, NPC_KoopaBros_Red, FALSE)
    EVT_CALL(SpeakToPlayer, NPC_KoopaBros_Red, ANIM_KoopaBros_Red_Anim18, ANIM_KoopaBros_Red_Anim18, 0, MSG_CH1_010C)
    EVT_CALL(EnableNpcAI, NPC_KoopaBros_Red, TRUE)
    EVT_WAIT(30)
    EVT_CALL(FadeOutMusic, 0, 2000)
    EVT_WAIT(30)
    EVT_CALL(GetEntryID, LVar0)
    EVT_CALL(GotoMap, EVT_PTR("trd_10"), trd_10_ENTRY_1)
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_KoopaBros)[] = {
    {
        .id = NPC_KoopaBros_Red,
        .settings = &N(NpcSettings_KoopaBros),
        .pos = { 60.0f, 0.0f, -60.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .animations = {
            .idle   = ANIM_KoopaBros_Red_Anim04,
            .walk   = ANIM_KoopaBros_Red_Anim02,
            .run    = ANIM_KoopaBros_Red_Anim03,
            .chase  = ANIM_KoopaBros_Red_Anim03,
            .anim_4 = ANIM_KoopaBros_Red_Anim04,
            .anim_5 = ANIM_KoopaBros_Red_Anim04,
            .death  = ANIM_KoopaBros_Red_Anim0A,
            .hit    = ANIM_KoopaBros_Red_Anim0A,
            .anim_8 = ANIM_KoopaBros_Red_Anim03,
            .anim_9 = ANIM_KoopaBros_Red_Anim03,
            .anim_A = ANIM_KoopaBros_Red_Anim03,
            .anim_B = ANIM_KoopaBros_Red_Anim03,
            .anim_C = ANIM_KoopaBros_Red_Anim03,
            .anim_D = ANIM_KoopaBros_Red_Anim03,
            .anim_E = ANIM_KoopaBros_Red_Anim03,
            .anim_F = ANIM_KoopaBros_Red_Anim03,
        },
    },
    {
        .id = NPC_KoopaBros_Black,
        .settings = &N(NpcSettings_KoopaBros),
        .pos = { 60.0f, 0.0f, 0.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .animations = {
            .idle   = ANIM_KoopaBros_Black_Anim04,
            .walk   = ANIM_KoopaBros_Black_Anim02,
            .run    = ANIM_KoopaBros_Black_Anim03,
            .chase  = ANIM_KoopaBros_Black_Anim03,
            .anim_4 = ANIM_KoopaBros_Black_Anim04,
            .anim_5 = ANIM_KoopaBros_Black_Anim04,
            .death  = ANIM_KoopaBros_Black_Anim0A,
            .hit    = ANIM_KoopaBros_Black_Anim0A,
            .anim_8 = ANIM_KoopaBros_Black_Anim03,
            .anim_9 = ANIM_KoopaBros_Black_Anim03,
            .anim_A = ANIM_KoopaBros_Black_Anim03,
            .anim_B = ANIM_KoopaBros_Black_Anim03,
            .anim_C = ANIM_KoopaBros_Black_Anim03,
            .anim_D = ANIM_KoopaBros_Black_Anim03,
            .anim_E = ANIM_KoopaBros_Black_Anim03,
            .anim_F = ANIM_KoopaBros_Black_Anim03,
        },
    },
    {
        .id = NPC_KoopaBros_Yellow,
        .settings = &N(NpcSettings_KoopaBros),
        .pos = { -10.0f, 0.0f, -60.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .animations = {
            .idle   = ANIM_KoopaBros_Yellow_Anim04,
            .walk   = ANIM_KoopaBros_Yellow_Anim02,
            .run    = ANIM_KoopaBros_Yellow_Anim03,
            .chase  = ANIM_KoopaBros_Yellow_Anim03,
            .anim_4 = ANIM_KoopaBros_Yellow_Anim04,
            .anim_5 = ANIM_KoopaBros_Yellow_Anim04,
            .death  = ANIM_KoopaBros_Yellow_Anim0A,
            .hit    = ANIM_KoopaBros_Yellow_Anim0A,
            .anim_8 = ANIM_KoopaBros_Yellow_Anim03,
            .anim_9 = ANIM_KoopaBros_Yellow_Anim03,
            .anim_A = ANIM_KoopaBros_Yellow_Anim03,
            .anim_B = ANIM_KoopaBros_Yellow_Anim03,
            .anim_C = ANIM_KoopaBros_Yellow_Anim03,
            .anim_D = ANIM_KoopaBros_Yellow_Anim03,
            .anim_E = ANIM_KoopaBros_Yellow_Anim03,
            .anim_F = ANIM_KoopaBros_Yellow_Anim03,
        },
    },
    {
        .id = NPC_KoopaBros_Green,
        .settings = &N(NpcSettings_KoopaBros),
        .pos = { 0.0f, 0.0f, 0.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .drops = {
            .dropFlags = NPC_DROP_FLAGS_80,
            .heartDrops  = NO_DROPS,
            .flowerDrops = NO_DROPS,
        },
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
        .animations = {
            .idle   = ANIM_KoopaBros_Green_Anim04,
            .walk   = ANIM_KoopaBros_Green_Anim02,
            .run    = ANIM_KoopaBros_Green_Anim03,
            .chase  = ANIM_KoopaBros_Green_Anim03,
            .anim_4 = ANIM_KoopaBros_Green_Anim04,
            .anim_5 = ANIM_KoopaBros_Green_Anim04,
            .death  = ANIM_KoopaBros_Green_Anim0A,
            .hit    = ANIM_KoopaBros_Green_Anim0A,
            .anim_8 = ANIM_KoopaBros_Green_Anim03,
            .anim_9 = ANIM_KoopaBros_Green_Anim03,
            .anim_A = ANIM_KoopaBros_Green_Anim03,
            .anim_B = ANIM_KoopaBros_Green_Anim03,
            .anim_C = ANIM_KoopaBros_Green_Anim03,
            .anim_D = ANIM_KoopaBros_Green_Anim03,
            .anim_E = ANIM_KoopaBros_Green_Anim03,
            .anim_F = ANIM_KoopaBros_Green_Anim03,
        },
    },
};

NpcGroupList N(NpcGroup_KoopaBros) = {
    NPC_GROUP(N(NpcData_KoopaBros)),
    {}
};

#define PARTY_IMAGE "party_pinki"
#include "world/common/todo/LoadPartyImage.inc.c"
