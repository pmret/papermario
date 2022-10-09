#include "iwa_02.h"

EvtScript N(D_802414B0_917220) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_4, TRUE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 30)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024154C_9172BC) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar1, 30)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Anim12)
    EVT_RETURN
    EVT_END
};

MobileAISettings N(D_802415CC_91733C) = {
    .moveSpeed = 1.8f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 90.0f,
    .alertOffsetDist = 70.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 3.0f,
    .chaseTurnRate = 90,
    .chaseUpdateInterval = 25,
    .chaseRadius = 120.0f,
    .chaseOffsetDist = 70.0f,
    .unk_AI_2C = 1,
};

EvtScript N(D_802415FC_91736C) = {
    EVT_CALL(func_800445D4, LVar0)
    EVT_IF_EQ(LVar0, 100)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_20, 1)
        EVT_LABEL(10)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(IsPlayerWithin, LVar0, LVar2, 80, LVar3)
        EVT_IF_NE(LVar3, 1)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetSelfNpcID, LVar0)
        EVT_ADD(LVar0, 1)
        EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_ADD(LVar2, 30)
        EVT_CALL(SetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_4, FALSE)
        EVT_CALL(EnableNpcShadow, NPC_SELF, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Anim0E)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar4, LVar5, LVar6)
        EVT_ADD(LVar5, 30)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_MOLE_POP, 0)
        EVT_CALL(NpcJump0, NPC_SELF, LVar4, LVar5, LVar6, 20)
        EVT_CALL(SetNpcPos, LVar0, 0, -1000, 0)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_20, 0)
        EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_40000000, 1)
        EVT_CALL(BasicAI_Main, EVT_PTR(N(D_802415CC_91733C)))
        EVT_RETURN
        EVT_END
};

NpcSettings N(80241848) = {
    .height = 24,
    .radius = 22,
    .level = 8,
    .otherAI = &N(D_802414B0_917220),
    .ai = &N(D_802415FC_91736C),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

NpcSettings N(80241874) = {
    .height = 24,
    .radius = 22,
    .level = 8,
    .otherAI = &N(D_8024154C_9172BC),
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

EvtScript N(EVS_NpcAuxAI_MontyMole_01) = {
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_4, TRUE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 50)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAuxAI_MontyMole_02) = {
    EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40000, TRUE)
    EVT_CALL(EnableNpcShadow, NPC_SELF, FALSE)
    EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_SUB(LVar2, 50)
    EVT_CALL(SetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
    EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Anim13)
    EVT_RETURN
    EVT_END
};

MobileAISettings N(D_802419BC_91772C) = {
    .moveSpeed = 1.8f,
    .moveTime = 30,
    .waitTime = 30,
    .alertRadius = 90.0f,
    .alertOffsetDist = 70.0f,
    .playerSearchInterval = 2,
    .chaseSpeed = 3.0f,
    .chaseTurnRate = 90,
    .chaseUpdateInterval = 25,
    .chaseRadius = 120.0f,
    .chaseOffsetDist = 70.0f,
    .unk_AI_2C = 1,
};

EvtScript N(EVS_NpcAI_MontyMole_01) = {
    EVT_CALL(func_800445D4, LVar0)
    EVT_IF_EQ(LVar0, 100)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_20, 1)
        EVT_LABEL(10)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_ADD(LVar2, 130)
        EVT_CALL(IsPlayerWithin, LVar0, LVar2, 80, LVar3)
        EVT_IF_NE(LVar3, 1)
            EVT_WAIT(1)
            EVT_GOTO(10)
        EVT_END_IF
        EVT_CALL(GetSelfNpcID, LVar0)
        EVT_ADD(LVar0, 1)
        EVT_CALL(GetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_ADD(LVar2, 30)
        EVT_ADD(LVar3, 50)
        EVT_CALL(SetNpcPos, LVar0, LVar1, LVar2, LVar3)
        EVT_WAIT(1)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_4, FALSE)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40, TRUE)
        EVT_CALL(EnableNpcShadow, NPC_SELF, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_MontyMole_Anim0E)
        EVT_CALL(SetNpcPos, NPC_SELF, LVar1, LVar2, LVar3)
        EVT_SUB(LVar2, 30)
        EVT_ADD(LVar3, 80)
        EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(0.7))
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_MOLE_POP, 0)
        EVT_CALL(NpcJump0, NPC_SELF, LVar1, LVar2, LVar3, 20)
        EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_40, FALSE)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_20, 0)
        EVT_CALL(NpcFacePlayer, NPC_SELF, 0)
        EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_40000000, 1)
    EVT_END_IF
    EVT_CALL(BasicAI_Main, EVT_PTR(N(D_802419BC_91772C)))
    EVT_RETURN
    EVT_END
};

EvtScript N(missing_80241C84_1C84) = {
    EVT_RETURN
    EVT_END
};

#include "world/common/enemy/complete/MontyMole.inc.c"

NpcSettings N(NpcSettings_MontyMole_01) = {
    .height = 24,
    .radius = 22,
    .level = 8,
    .otherAI = &N(EVS_NpcAuxAI_MontyMole_01),
    .ai = &N(EVS_NpcAI_MontyMole_01),
    .onHit = &EnemyNpcHit,
    .onDefeat = &EnemyNpcDefeat,
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

NpcSettings N(NpcSettings_MontyMole_02) = {
    .height = 24,
    .radius = 22,
    .level = 8,
    .otherAI = &N(EVS_NpcAuxAI_MontyMole_02),
    .actionFlags = AI_ACTION_JUMP_WHEN_SEE_PLAYER,
};

#include "world/common/enemy/complete/Cleft.inc.c"

EvtScript N(EVS_NpcAuxAI_Bubulb) = {
    EVT_RETURN
    EVT_END
};

NpcSettings N(NpcSettings_Bubulb) = {
    .height = 42,
    .radius = 26,
    .level = 99,
    .otherAI = &N(EVS_NpcAuxAI_Bubulb),
};

#include "world/common/complete/GiveReward.inc.c"

StaticNpc N(NpcData_Cleft_01) = {
    .id = NPC_Cleft_01,
    .settings = &N(NpcSettings_Cleft),
    .pos = { 526.0f, 238.0f, 69.0f },
    .yaw = 0,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW,
    .drops = CLEFT_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 526, 238, 69 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 526, 238, 69 },
            .detectSize = { 200 },
        }
    },
    .animations = CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Cleft_02) = {
    .id = NPC_Cleft_02,
    .settings = &N(NpcSettings_Cleft),
    .pos = { 450.0f, 50.0f, 215.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW,
    .drops = CLEFT_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 450, 50, 215 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 450, 50, 215 },
            .detectSize = { 200 },
        }
    },
    .animations = CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Cleft_03) = {
    .id = NPC_Cleft_03,
    .settings = &N(NpcSettings_Cleft),
    .pos = { 90.0f, 0.0f, 160.0f },
    .yaw = 270,
    .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_NO_PROJECT_SHADOW,
    .drops = CLEFT_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 90, 0, 160 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 90, 0, 160 },
            .detectSize = { 200 },
        }
    },
    .animations = CLEFT_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_MontyMole_01)[] = {
    {
        .id = NPC_MontyMole_01,
        .settings = &N(NpcSettings_MontyMole_01),
        .pos = { 867.0f, 0.0f, 101.0f },
        .yaw = 0,
        .flags = NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
        .drops = MONTY_MOLE_DROPS,
        .territory = {
            .wander = {
                .isFlying = FALSE,
                .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
                .wanderShape = SHAPE_CYLINDER,
                .centerPos  = { 867, 0, 101 },
                .wanderSize = { 40 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 867, 0, 101 },
                .detectSize = { 150 },
            }
        },
        .animations = MONTY_MOLE_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
    {
        .id = NPC_MontyMole_02,
        .settings = &N(NpcSettings_MontyMole_02),
        .pos = { 867.0f, 0.0f, 101.0f },
        .yaw = 0,
        .flags = NPC_FLAG_PASSIVE | NPC_FLAG_NO_AI | NPC_FLAG_100 | NPC_FLAG_GRAVITY | NPC_FLAG_LOCK_ANIMS | NPC_FLAG_JUMPING,
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
                .wanderSize = { 0 },
                .detectShape = SHAPE_CYLINDER,
                .detectPos  = { 0, 0, 0 },
                .detectSize = { 0 },
            }
        },
        .animations = MONTY_MOLE_ANIMS,
        .aiDetectFlags = AI_DETECT_SIGHT,
    },
};

EvtScript N(EVS_Bulbulb_Conversation) = {
    EVT_IF_EQ(AF_IWA_01, FALSE)
        EVT_SET(LVar2, LVar0)
        EVT_SET(AF_IWA_01, TRUE)
    EVT_ELSE
        EVT_SET(LVar2, LVar1)
        EVT_SET(AF_IWA_01, FALSE)
    EVT_END_IF
    EVT_CALL(SpeakToPlayer, NPC_Bubulb, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, LVar2)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInteract_Bubulb) = {
    EVT_IF_EQ(GF_IWA02_Gift_MagicalSeed2, FALSE)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_BURROW_SURFACE, 0)
        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_MOLE_POP, 0)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Purple_PopUp)
        EVT_WAIT(45)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Purple_Idle)
        EVT_CALL(SetNpcCollisionSize, NPC_SELF, 45, 26)
        EVT_CALL(AdjustCam, CAM_DEFAULT, EVT_FLOAT(10.0), 0, 350, EVT_FLOAT(15.0), EVT_FLOAT(-6.5))
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, MSG_CH2_001F)
        EVT_GIVE_KEY_REWARD(ITEM_MAGICAL_SEED2)
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_Bubulb_Purple_Talk, ANIM_Bubulb_Purple_Idle, 0, MSG_CH2_0020)
        EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(10.0))
        EVT_SET(GF_IWA02_Gift_MagicalSeed2, TRUE)
        EVT_CALL(SetTattleMessage, NPC_Bubulb, MSG_NpcTattle_IWA_Bubulb_Revealed)
    EVT_ELSE
        EVT_SWITCH(GB_StoryProgress)
            EVT_CASE_LT(STORY_CH3_STAR_SPIRIT_RESCUED)
                EVT_SET(LVar0, MSG_CH2_0021)
                EVT_SET(LVar1, MSG_CH2_0022)
            EVT_CASE_LT(STORY_CH5_HIDDEN_PASSAGE_OPEN)
                EVT_SET(LVar0, MSG_CH2_0023)
                EVT_SET(LVar1, MSG_CH2_0024)
            EVT_CASE_DEFAULT
                EVT_SET(LVar0, MSG_CH2_0025)
                EVT_SET(LVar1, MSG_CH2_0026)
        EVT_END_SWITCH
        EVT_EXEC_WAIT(N(EVS_Bulbulb_Conversation))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_Bubulb) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_Bubulb)))
    EVT_IF_EQ(GF_IWA02_Gift_MagicalSeed2, FALSE)
        EVT_CALL(SetNpcCollisionSize, NPC_SELF, 25, 25)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_Bubulb_Purple_BuriedIdle)
        EVT_CALL(SetTattleMessage, NPC_Bubulb, MSG_NpcTattle_IWA_Bubulb_Hidden)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Bubulb) = {
    .id = NPC_Bubulb,
    .settings = &N(NpcSettings_Bubulb),
    .pos = { 1075.0f, 50.0f, 230.0f },
    .yaw = 270,
    .flags = NPC_FLAG_PASSIVE | NPC_FLAG_JUMPING,
    .init = &N(EVS_NpcInit_Bubulb),
    .drops = {
        .dropFlags = NPC_DROP_FLAGS_80,
        .heartDrops  = NO_DROPS,
        .flowerDrops = NO_DROPS,
    },
    .animations = {
        .idle   = ANIM_Bubulb_Purple_Idle,
        .walk   = ANIM_Bubulb_Purple_Walk,
        .run    = ANIM_Bubulb_Purple_Walk,
        .chase  = ANIM_Bubulb_Purple_Idle,
        .anim_4 = ANIM_Bubulb_Purple_Idle,
        .anim_5 = ANIM_Bubulb_Purple_Idle,
        .death  = ANIM_Bubulb_Purple_Idle,
        .hit    = ANIM_Bubulb_Purple_Idle,
        .anim_8 = ANIM_Bubulb_Purple_Idle,
        .anim_9 = ANIM_Bubulb_Purple_Idle,
        .anim_A = ANIM_Bubulb_Purple_Idle,
        .anim_B = ANIM_Bubulb_Purple_Idle,
        .anim_C = ANIM_Bubulb_Purple_Idle,
        .anim_D = ANIM_Bubulb_Purple_Idle,
        .anim_E = ANIM_Bubulb_Purple_Idle,
        .anim_F = ANIM_Bubulb_Purple_Idle,
    },
    .tattle = MSG_NpcTattle_IWA_Bubulb_Revealed,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Cleft_01), BTL_IWA_FORMATION_03, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_Cleft_02), BTL_IWA_FORMATION_01, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_Cleft_03), BTL_IWA_FORMATION_00, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_MontyMole_01), BTL_IWA_FORMATION_05, BTL_IWA_STAGE_01),
    NPC_GROUP(N(NpcData_Bubulb)),
    {}
};
