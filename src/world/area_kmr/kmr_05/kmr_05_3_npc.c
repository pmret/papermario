#include "kmr_05.h"

#include "world/common/enemy/complete/Goomba_Wander.inc.c"

#include "world/common/enemy/complete/Paragoomba_Wander.inc.c"

#include "world/common/enemy/complete/SpikedGoomba_Wander.inc.c"

EvtScript N(EVS_GoompaRemark) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_WAIT(10)
    EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
    EVT_CALL(PlayerMoveTo, -60, -19, 0)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SpeakToPlayer, NPC_PARTNER, ANIM_Goompa_Talk, ANIM_Goompa_Idle, 0, MSG_CH0_00B7)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcAux_SpikedGoomba) = {
    EVT_LABEL(0)
    EVT_CALL(TranslateModel, MODEL_usokinoko, -1, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(TranslateModel, MODEL_usokinoko, 1, 0, 0)
    EVT_WAIT(20)
    EVT_CALL(TranslateModel, MODEL_usokinoko, 1, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(TranslateModel, MODEL_usokinoko, -1, 0, 0)
    EVT_WAIT(8)
    EVT_CALL(TranslateModel, MODEL_usokinoko, -1, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(TranslateModel, MODEL_usokinoko, 1, 0, 0)
    EVT_WAIT(30)
    EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcIdle_SpikedGoomba) = {
    EVT_CALL(func_800445D4, LVar0)
    EVT_SWITCH(LVar0)
        EVT_CASE_EQ(100)
            EVT_LABEL(10)
            EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
            EVT_WAIT(1)
            EVT_IF_LT(LVar1, 100)
                EVT_GOTO(10)
            EVT_END_IF
            EVT_IF_LT(LVar0, 560)
                EVT_GOTO(10)
            EVT_END_IF
            EVT_IF_GT(LVar0, 700)
                EVT_GOTO(10)
            EVT_END_IF
            EVT_CALL(SetNpcAux, NPC_SELF, 0)
            EVT_CALL(ShowEmote, NPC_SELF, EMOTE_EXCLAMATION, -30, 12, TRUE, 0, 0, 0, 0)
            EVT_CALL(SetNpcJumpscale, NPC_SELF, EVT_FLOAT(1.0))
            EVT_CALL(SetNpcSpeed, NPC_SELF, EVT_FLOAT(5.0))
            EVT_CALL(NpcJump0, NPC_SELF, 685, 100, -35, 0)
            EVT_CALL(SetSelfEnemyFlagBits, ENEMY_FLAGS_40000000, 1)
            EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_SpikedGoomba_Wander)))
        EVT_CASE_OR_EQ(102)
        EVT_CASE_OR_EQ(3)
        EVT_CASE_OR_EQ(103)
            EVT_CALL(BindNpcAI, NPC_SELF, EVT_PTR(N(EVS_NpcAI_SpikedGoomba_Wander)))
        EVT_END_CASE_GROUP
    EVT_END_SWITCH
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_Goomba_01) = {
    .id = NPC_Goomba_01,
    .settings = &N(NpcSettings_Goomba_Wander),
    .pos = { 305.0f, 50.0f, -13.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS,
    .drops = GOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 305, 50, -13 },
            .wanderSize = { 30, 20 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 330, 50, 20 },
            .detectSize = { 120, 130 },
        }
    },
    .animations = GOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Goomba_02) = {
    .id = NPC_Goomba_02,
    .settings = &N(NpcSettings_Goomba_Wander),
    .pos = { 700.0f, 210.0f, -165.0f },
    .yaw = 90,
    .flags = NPC_FLAG_LOCK_ANIMS,
    .drops = GOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 700, 210, -165 },
            .wanderSize = { 30, 20 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 700, 210, -165 },
            .detectSize = { 120, 130 },
        }
    },
    .animations = GOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

EvtScript N(EVS_NpcInit_SpikedGoomba) = {
    EVT_CALL(BindNpcIdle, NPC_SELF, EVT_PTR(N(EVS_NpcIdle_SpikedGoomba)))
    EVT_CALL(BindNpcAux, NPC_SELF, EVT_PTR(N(EVS_NpcAux_SpikedGoomba)))
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_SpikedGoomba) = {
    .id = NPC_SpikedGoomba,
    .settings = &N(NpcSettings_SpikedGoomba_Wander),
    .pos = { 712.0f, 100.0f, -95.0f },
    .yaw = 270,
    .flags = NPC_FLAG_LOCK_ANIMS,
    .init = &N(EVS_NpcInit_SpikedGoomba),
    .drops = SPIKED_GOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 630, 100, 25 },
            .wanderSize = { 40, 20 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 660, 100, 30 },
            .detectSize = { 165, 150 },
        }
    },
    .animations = SPIKED_GOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

StaticNpc N(NpcData_Paragoomba) = {
    .id = NPC_Paragoomba,
    .settings = &N(NpcSettings_Paragoomba_Wander),
    .pos = { 960.0f, 210.0f, -20.0f },
    .yaw = 270,
    .flags = NPC_FLAG_LOCK_ANIMS,
    .drops = PARAGOOMBA_DROPS,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_RECT,
            .centerPos  = { 960, 210, -20 },
            .wanderSize = { 50, 25 },
            .detectShape = SHAPE_RECT,
            .detectPos  = { 995, 210, -57 },
            .detectSize = { 210, 100 },
        }
    },
    .animations = PARAGOOMBA_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT,
};

NpcGroupList N(NpcsBefore) = {
    NPC_GROUP(N(NpcData_Goomba_01), BTL_KMR_PART_1_FORMATION_00, BTL_KMR_PART_1_STAGE_03),
    NPC_GROUP(N(NpcData_Goomba_02), BTL_KMR_PART_1_FORMATION_00, BTL_KMR_PART_1_STAGE_03),
    NPC_GROUP(N(NpcData_SpikedGoomba), BTL_KMR_PART_3_FORMATION_00, BTL_KMR_PART_3_STAGE_03),
    NPC_GROUP(N(NpcData_Paragoomba), BTL_KMR_PART_3_FORMATION_01, BTL_KMR_PART_3_STAGE_03),
    {}
};

NpcGroupList N(NpcsAfter) = {
    NPC_GROUP(N(NpcData_Goomba_01), BTL_KMR_PART_1_FORMATION_00, BTL_KMR_PART_1_STAGE_03),
    NPC_GROUP(N(NpcData_Goomba_02), BTL_KMR_PART_1_FORMATION_00, BTL_KMR_PART_1_STAGE_03),
    NPC_GROUP(N(NpcData_SpikedGoomba), BTL_KMR_PART_1_FORMATION_0A, BTL_KMR_PART_1_STAGE_03),
    NPC_GROUP(N(NpcData_Paragoomba), BTL_KMR_PART_1_FORMATION_08, BTL_KMR_PART_1_STAGE_03),
    {}
};
