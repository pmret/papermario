#include "kzn_03.h"

#include "world/common/enemy/SpikeTop.inc.c"
#include "world/common/enemy/PutridPiranha.inc.c"
#include "world/common/npc/Dummy.inc.c"
#include "world/common/npc/Kolorado.inc.c"

#include "world/common/complete/LetterDelivery.inc.c"

s32 N(LetterList)[] = {
    ITEM_LETTER_TO_KOLORADO,
    ITEM_NONE
};

EVT_LETTER_PROMPT(Kolorado, NPC_Kolorado, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle,
    MSG_CH5_00E4, MSG_CH5_00E5, MSG_CH5_00E6, MSG_CH5_00E7,
    ITEM_LETTER_TO_KOLORADO, N(LetterList));

EVT_LETTER_REWARD(Kolorado);

EvtScript N(EVS_NpcIdle_Kolorado) = {
    EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(2.0))
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Walk)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar4, LVar5, LVar6)
    EVT_SET(LVar3, LVar4)
    EVT_ADD(LVar3, -45)
    EVT_SET(LVar7, 90)
    EVT_LOOP(0)
        EVT_SET(LVar2, LVar3)
        EVT_SET(LVar3, LVar4)
        EVT_SET(LVar4, LVar2)
        EVT_CALL(InterpNpcYaw, NPC_SELF, LVar7, 5)
        EVT_CALL(MakeLerp, LVar2, LVar3, 45, EASING_LINEAR)
        EVT_LOOP(0)
            EVT_CALL(UpdateLerp)
            EVT_CALL(SetNpcYaw, NPC_SELF, LVar7)
            EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar5, LVar6)
            EVT_WAIT(1)
            EVT_IF_GE(GB_StoryProgress, STORY_CH5_SMASHED_ULTRA_BLOCK)
                EVT_BREAK_LOOP
            EVT_END_IF
            EVT_IF_EQ(LVar1, 0)
                EVT_BREAK_LOOP
            EVT_END_IF
        EVT_END_LOOP
        EVT_IF_GE(GB_StoryProgress, STORY_CH5_SMASHED_ULTRA_BLOCK)
            EVT_BREAK_LOOP
        EVT_END_IF
        EVT_ADD(LVar7, 180)
        EVT_IF_GE(LVar7, 360)
            EVT_ADD(LVar7, -360)
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Kolorado_Idle)
    EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
    EVT_WAIT(10)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_CALL(SetSelfVar, 0, 1)
    EVT_THREAD
        EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.5))
        EVT_LABEL(5)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
        EVT_CALL(NpcJump0, NPC_SELF, LVar3, LVar4, LVar5, 9)
        EVT_CALL(GetSelfVar, 0, LVar0)
        EVT_IF_EQ(LVar0, 1)
            EVT_WAIT(6)
            EVT_GOTO(5)
        EVT_END_IF
    EVT_END_THREAD
    EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Panic, 512, MSG_CH5_00F3)
    EVT_CALL(SetSelfVar, 0, 0)
    EVT_WAIT(18)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Kolorado) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, TRUE)
    EVT_IF_LT(GB_StoryProgress, STORY_CH5_SMASHED_ULTRA_BLOCK)
        EVT_IF_EQ(GF_KZN03_SpokeWithKolorado, FALSE)
            EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(3.3), 0, 350, EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00F1)
            EVT_SET(GF_KZN03_SpokeWithKolorado, TRUE)
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(5.0))
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Talk, ANIM_Kolorado_Idle, 0, MSG_CH5_00F2)
        EVT_END_IF
    EVT_ELSE
        EVT_CALL(SetSelfVar, 0, 1)
        EVT_THREAD
            EVT_CALL(GetNpcPos, NPC_SELF, LVar3, LVar4, LVar5)
            EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(2.5))
            EVT_LABEL(5)
            EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_NPC_JUMP, SOUND_SPACE_DEFAULT)
            EVT_CALL(NpcJump0, NPC_SELF, LVar3, LVar4, LVar5, 9)
            EVT_CALL(GetSelfVar, 0, LVar0)
            EVT_IF_EQ(LVar0, 1)
                EVT_WAIT(6)
                EVT_GOTO(5)
            EVT_END_IF
        EVT_END_THREAD
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Kolorado_Shout, ANIM_Kolorado_Panic, 512, MSG_CH5_00F3)
        EVT_CALL(SetSelfVar, 0, 0)
        EVT_WAIT(18)
    EVT_END_IF
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_IGNORE_PLAYER_COLLISION, FALSE)
    EVT_LETTER_CHECK(Kolorado)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Kolorado) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH5_SMASHED_ULTRA_BLOCK)
            EVT_IF_EQ(GF_KZN06_Visited, TRUE)
                EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_Kolorado)))
                EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado)))
                EVT_RETURN
            EVT_END_IF
        EVT_CASE_EQ(STORY_CH5_SMASHED_ULTRA_BLOCK)
            EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Kolorado)))
            EVT_RETURN
    EVT_END_SWITCH
    EVT_CALL(RemoveNpc, NPC_SELF)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SyncZiplineDummyNPC1) = {
    EVT_LOOP(0)
        EVT_CALL(GetModelCenter, MODEL_kassya_koma)
        EVT_CALL(SetNpcPos, NPC_ZiplineDummy1, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SyncZiplineDummyNPC2) = {
    EVT_LOOP(0)
        EVT_CALL(GetModelCenter, MODEL_kssya2_koma)
        EVT_CALL(SetNpcPos, NPC_ZiplineDummy2, LVar0, LVar1, LVar2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_ZiplineDummy) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE, TRUE)
    EVT_CALL(SetNpcScale, NPC_SELF, EVT_FLOAT(0.3), 1, EVT_FLOAT(0.3))
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_PassiveNPCs)[] = {
    {
        .id = NPC_Kolorado,
        .pos = { 392.0f, 470.0f, 218.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_Kolorado),
        .settings = &N(NpcSettings_Kolorado),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_ENABLE_HIT_SCRIPT | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_10000 | ENEMY_FLAG_100000,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Kolorado,
    },
    {
        .id = NPC_ZiplineDummy1,
        .pos = { 392.0f, 470.0f, 218.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_ZiplineDummy),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Kolorado,
    },
    {
        .id = NPC_ZiplineDummy2,
        .pos = { 392.0f, 470.0f, 218.0f },
        .yaw = 90,
        .init = &N(EVS_NpcInit_ZiplineDummy),
        .settings = &N(NpcSettings_Dummy),
        .flags = ENEMY_FLAG_PASSIVE | ENEMY_FLAG_IGNORE_WORLD_COLLISION | ENEMY_FLAG_IGNORE_PLAYER_COLLISION | ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_ACTIVE_WHILE_OFFSCREEN,
        .drops = NO_DROPS,
        .animations = KOLORADO_ANIMS,
        .tattle = MSG_NpcTattle_Kolorado,
    },
};

NpcData N(NpcData_SpikeTop_01) = {
    .id = NPC_SpikeTop_01,
    .pos = { 140.0f, 670.0f, -20.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 140, 670, -20 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { -50, 670, -25 },
            .detectSize = { 240, 115 },
        }
    },
    .settings = &N(NpcSettings_SpikeTop),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = SPIKE_TOP_DROPS,
    .animations = SPIKE_TOP_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_SpikeTop_02) = {
    .id = NPC_SpikeTop_02,
    .pos = { -200.0f, 670.0f, -35.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -200, 670, -35 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { -50, 670, -25 },
            .detectSize = { 240, 115 },
        }
    },
    .settings = &N(NpcSettings_SpikeTop),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = SPIKE_TOP_DROPS,
    .animations = SPIKE_TOP_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_SpikeTop_03) = {
    .id = NPC_SpikeTop_03,
    .pos = { 30.0f, 20.0f, 320.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 30, 20, 320 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 140, 20, 275 },
            .detectSize = { 180, 95 },
        }
    },
    .settings = &N(NpcSettings_SpikeTop),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = SPIKE_TOP_DROPS,
    .animations = SPIKE_TOP_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_PutridPiranha)[] = {
    {
        .id = NPC_Piranha,
        .pos = { 260.0f, 20.0f, 255.0f },
        .yaw = 270,
        .territory = {
            .wander = {
                .isFlying = TRUE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 260, 20, 255 },
                .wanderSize = { 30 },
                .detectShape = SHAPE_RECT,
                .detectPos  = { 260, 20, 255 },
                .detectSize = { 100, 50 },
            }
        },
        .settings = &N(NpcSettings_PutridPiranha),
        .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
        .drops = PUTRID_PIRANHA_DROPS,
        .animations = PUTRID_PIRANHA_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
    },
    PUTRID_PIRANHA_HITBOX(NPC_Piranha_Hitbox),
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_PassiveNPCs)),
    NPC_GROUP(N(NpcData_SpikeTop_01), BTL_KZN_FORMATION_08, BTL_KZN_STAGE_01),
    NPC_GROUP(N(NpcData_SpikeTop_02), BTL_KZN_FORMATION_09, BTL_KZN_STAGE_01),
    NPC_GROUP(N(NpcData_SpikeTop_03), BTL_KZN_FORMATION_0A, BTL_KZN_STAGE_01),
    NPC_GROUP(N(NpcData_PutridPiranha), BTL_KZN_FORMATION_13, BTL_KZN_STAGE_01),
    {}
};
