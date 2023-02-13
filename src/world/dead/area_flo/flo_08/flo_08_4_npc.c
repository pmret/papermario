#include "flo_08.h"

#include "world/common/enemy/AmazyDayzee.inc.c"
#include "world/common/npc/GateFlower.inc.c"
#include "world/common/enemy/CrazyDayzee.inc.c"

#include "world/common/complete/NormalItemChoice.inc.c"

static s32 N(FlowerGuard_ItemChoiceList)[ITEM_NUM_CONSUMABLES + 1];
#include "world/area_flo/common/ItemChoice_FlowerGuard.inc.c"

EvtScript N(EVS_NpcInteract_GateFlower) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(GF_FLO08_GaveYellowBerry, FALSE)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.5), EVT_FLOAT(-7.5))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Yellow_Talk, ANIM_GateFlower_Yellow_Idle, 0, MSG_CH6_0042)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_Thinking)
        EVT_CALL(N(FlowerGuard_MakeItemList))
        EVT_CHOOSE_CONSUMABLE_FROM(N(FlowerGuard_ItemChoiceList), 0)
        EVT_SWITCH(LVar0)
            EVT_CASE_LE(0)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario_StandStill)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Yellow_Talk, ANIM_GateFlower_Yellow_Idle, 0, MSG_CH6_0043)
            EVT_CASE_DEFAULT
                EVT_SET(LVar8, LVar0)
                EVT_CALL(N(FlowerGuard_JudgeItemTastiness), LVar0)
                EVT_CALL(MakeItemEntity, LVar8, -695, 20, -29, ITEM_SPAWN_MODE_DECORATION, 0)
                EVT_SET(LVar7, LVar0)
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2095, SOUND_SPACE_MODE_0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Yellow_Eat)
                EVT_WAIT(20)
                EVT_CALL(RemoveItemEntity, LVar7)
                EVT_SWITCH(LVar8)
                    EVT_CASE_EQ(160)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Yellow_Chew, ANIM_GateFlower_Yellow_Idle, 0, MSG_CH6_0046)
                        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_21C, SOUND_SPACE_MODE_0)
                        EVT_CALL(EndSpeech, NPC_SELF, ANIM_GateFlower_Yellow_HappyTalk, ANIM_GateFlower_Yellow_HappyIdle, 0)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Yellow_OpenGate)
                        EVT_CALL(PlaySoundAtCollider, COLLIDER_o96, SOUND_METAL_GATE_OPEN, SOUND_SPACE_MODE_0)
                        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o96, COLLIDER_FLAGS_UPPER_MASK)
                        EVT_CALL(MakeLerp, 0, 100, 30, EASING_QUADRATIC_IN)
                        EVT_LOOP(0)
                            EVT_CALL(UpdateLerp)
                            EVT_SETF(LVar8, LVar0)
                            EVT_SETF(LVar9, LVar0)
                            EVT_MULF(LVar8, EVT_FLOAT(0.5))
                            EVT_MULF(LVar9, EVT_FLOAT(1.2))
                            EVT_CALL(RotateModel, MODEL_o69, LVar8, 0, 1, 0)
                            EVT_CALL(RotateModel, MODEL_o70, LVar8, 0, 1, 0)
                            EVT_CALL(RotateModel, MODEL_o71, LVar8, 0, 1, 0)
                            EVT_CALL(RotateModel, MODEL_o148, LVar9, 0, -1, 0)
                            EVT_CALL(RotateModel, MODEL_o149, LVar9, 0, -1, 0)
                            EVT_CALL(RotateModel, MODEL_o150, LVar9, 0, -1, 0)
                            EVT_WAIT(1)
                            EVT_IF_NE(LVar1, 1)
                                EVT_BREAK_LOOP
                            EVT_END_IF
                        EVT_END_LOOP
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Yellow_HappyDance)
                        EVT_SET(GF_FLO08_GaveYellowBerry, TRUE)
                    EVT_CASE_EQ(159)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Yellow_Chew, ANIM_GateFlower_Yellow_Idle, 0, MSG_CH6_0045)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Yellow_Idle)
                    EVT_CASE_EQ(158)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Yellow_Chew, ANIM_GateFlower_Yellow_Idle, 0, MSG_CH6_0045)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Yellow_Idle)
                    EVT_CASE_DEFAULT
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Yellow_Chew, ANIM_GateFlower_Yellow_Idle, 0, MSG_CH6_0044)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Yellow_Disgust)
                        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2096, SOUND_SPACE_MODE_0)
                        EVT_CALL(MakeItemEntity, LVar8, 125, 20, 0, ITEM_SPAWN_MODE_DECORATION, 0)
                        EVT_SET(LVar7, LVar0)
                        EVT_WAIT(5)
                        EVT_CALL(GetAngleToPlayer, NPC_SELF, LVar0)
                        EVT_IF_LT(LVar0, 180)
                            EVT_CALL(MakeLerp, 0, 100, 7, EASING_LINEAR)
                            EVT_LOOP(0)
                                EVT_CALL(UpdateLerp)
                                EVT_SETF(LVar2, EVT_FLOAT(-0.5))
                                EVT_SETF(LVar3, EVT_FLOAT(-0.2))
                                EVT_SETF(LVar4, EVT_FLOAT(0.9))
                                EVT_MULF(LVar2, LVar0)
                                EVT_MULF(LVar3, LVar0)
                                EVT_MULF(LVar4, LVar0)
                                EVT_ADDF(LVar2, EVT_FLOAT(-700.0))
                                EVT_ADDF(LVar3, EVT_FLOAT(15.0))
                                EVT_ADDF(LVar4, EVT_FLOAT(-25.0))
                                EVT_CALL(N(FlowerGuard_SetItemEntityPosition), LVar7, LVar2, LVar3, LVar4)
                                EVT_WAIT(1)
                                EVT_IF_EQ(LVar1, 0)
                                    EVT_BREAK_LOOP
                                EVT_END_IF
                            EVT_END_LOOP
                        EVT_ELSE
                            EVT_CALL(MakeLerp, 0, 100, 7, EASING_LINEAR)
                            EVT_LOOP(0)
                                EVT_CALL(UpdateLerp)
                                EVT_SETF(LVar2, EVT_FLOAT(0.5))
                                EVT_SETF(LVar3, EVT_FLOAT(-0.2))
                                EVT_SETF(LVar4, EVT_FLOAT(0.9))
                                EVT_MULF(LVar2, LVar0)
                                EVT_MULF(LVar3, LVar0)
                                EVT_MULF(LVar4, LVar0)
                                EVT_ADDF(LVar2, EVT_FLOAT(-690.0))
                                EVT_ADDF(LVar3, EVT_FLOAT(15.0))
                                EVT_ADDF(LVar4, EVT_FLOAT(-25.0))
                                EVT_CALL(N(FlowerGuard_SetItemEntityPosition), LVar7, LVar2, LVar3, LVar4)
                                EVT_WAIT(1)
                                EVT_IF_EQ(LVar1, 0)
                                    EVT_BREAK_LOOP
                                EVT_END_IF
                            EVT_END_LOOP
                        EVT_END_IF
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Yellow_Idle)
                        EVT_CALL(RemoveItemEntity, LVar7)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Yellow_Idle)
                        EVT_CALL(EndSpeech, NPC_SELF, ANIM_GateFlower_Yellow_Talk, ANIM_GateFlower_Yellow_Idle, 0)
                EVT_END_SWITCH
        EVT_END_SWITCH
        EVT_THREAD
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(6.0))
        EVT_END_THREAD
        EVT_WAIT(10)
    EVT_ELSE
        EVT_IF_LT(GB_StoryProgress, STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Yellow_HappyTalk, ANIM_GateFlower_Yellow_HappyIdle, 0, MSG_CH6_0047)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Yellow_HappyTalk, ANIM_GateFlower_Yellow_HappyIdle, 0, MSG_CH6_0048)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_GateFlower) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_GateFlower)))
    EVT_IF_EQ(GF_FLO08_GaveYellowBerry, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Yellow_HappyDance)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o96, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(RotateModel, MODEL_o69, 50, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o70, 50, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o71, 50, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o148, 120, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_o149, 120, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_o150, 120, 0, -1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_GateFlower) = {
    .id = NPC_GateFlower,
    .settings = &N(NpcSettings_GateFlower),
    .pos = { -695.0f, 0.0f, -30.0f },
    .yaw = 270,
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_2000 | ENEMY_FLAG_400000,
    .init = &N(EVS_NpcInit_GateFlower),
    .drops = GATE_FLOWER_DROPS,
    .animations = GATE_FLOWER_YELLOW_ANIMS,
    .tattle = MSG_NpcTattle_YellowGateFlower,
};

StaticNpc N(NpcData_Dayzee_01) = {
    .id = NPC_Dayzee_01,
    .settings = &N(NpcSettings_CrazyDayzee),
    .pos = { 205.0f, 0.0f, -80.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = CRAZY_DAYZEE_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 205, 0, -80 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 205, 0, -80 },
            .detectSize = { 200 },
        }
    },
    .animations = CRAZY_DAYZEE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_Dayzee_02) = {
    .id = NPC_Dayzee_02,
    .settings = &N(NpcSettings_CrazyDayzee),
    .pos = { 275.0f, 0.0f, -115.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800,
    .drops = CRAZY_DAYZEE_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 275, 0, -115 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 275, 0, -115 },
            .detectSize = { 200 },
        }
    },
    .animations = CRAZY_DAYZEE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_Dayzee_03) = {
    .id = NPC_Dayzee_03,
    .settings = &N(NpcSettings_CrazyDayzee),
    .pos = { -230.0f, 60.0f, -110.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
    .drops = CRAZY_DAYZEE_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -230, 60, -110 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -230, 60, -110 },
            .detectSize = { 200 },
        }
    },
    .animations = CRAZY_DAYZEE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_Dayzee_04) = {
    .id = NPC_Dayzee_04,
    .settings = &N(NpcSettings_CrazyDayzee),
    .pos = { -330.0f, 60.0f, -110.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
    .drops = CRAZY_DAYZEE_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -330, 60, -110 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -330, 60, -110 },
            .detectSize = { 200 },
        }
    },
    .animations = CRAZY_DAYZEE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_Dayzee_05) = {
    .id = NPC_Dayzee_05,
    .settings = &N(NpcSettings_CrazyDayzee),
    .pos = { -430.0f, 60.0f, -110.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
    .drops = CRAZY_DAYZEE_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -430, 60, -110 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -430, 60, -110 },
            .detectSize = { 200 },
        }
    },
    .animations = CRAZY_DAYZEE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_Dayzee_06) = {
    .id = NPC_Dayzee_06,
    .settings = &N(NpcSettings_CrazyDayzee),
    .pos = { -530.0f, 60.0f, -110.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
    .drops = CRAZY_DAYZEE_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -530, 60, -110 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -530, 60, -110 },
            .detectSize = { 200 },
        }
    },
    .animations = CRAZY_DAYZEE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

StaticNpc N(NpcData_Dayzee_07) = {
    .id = NPC_Dayzee_07,
    .settings = &N(NpcSettings_CrazyDayzee),
    .pos = { -630.0f, 60.0f, -110.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
    .drops = CRAZY_DAYZEE_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -630, 60, -110 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -630, 60, -110 },
            .detectSize = { 150 },
        }
    },
    .animations = CRAZY_DAYZEE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

EvtScript N(EVS_NpcInit_AmazyDayzee) = {
    EVT_THREAD
        EVT_WAIT(2)
        EVT_CALL(GetNpcPointer, NPC_Dayzee_02, LVar0)
        EVT_IF_EQ(LVar0, 0)
            EVT_CALL(RemoveNpc, NPC_SELF)
            EVT_RETURN
        EVT_END_IF
        EVT_CALL(RandInt, 100, LVar0)
        EVT_IF_LT(LVar0, 30)
            EVT_CALL(SetNpcFlagBits, NPC_Dayzee_02, NPC_FLAG_2 | NPC_FLAG_4, TRUE)
            EVT_CALL(SetNpcPos, NPC_Dayzee_02, NPC_DISPOSE_LOCATION)
        EVT_ELSE
            EVT_CALL(SetNpcFlagBits, NPC_SELF, NPC_FLAG_2 | NPC_FLAG_4, TRUE)
            EVT_CALL(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EVT_END_IF
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_AmazyDayzee) = {
    .id = NPC_AmazyDayzee,
    .settings = &N(NpcSettings_AmazyDayzee),
    .pos = { 240.0f, 0.0f, -90.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000,
    .init = &N(EVS_NpcInit_AmazyDayzee),
    .drops = AMAZY_DAYZEE_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 240, 0, -90 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 240, 0, -90 },
            .detectSize = { 200 },
        }
    },
    .animations = AMAZY_DAYZEE_ANIMS,
    .aiDetectFlags = AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_GateFlower)),
    NPC_GROUP(N(NpcData_Dayzee_01), 0x1A14, BTL_FLO_STAGE_00),
    NPC_GROUP(N(NpcData_Dayzee_02), 0x1A0F, BTL_FLO_STAGE_00),
    NPC_GROUP(N(NpcData_Dayzee_03), 0x1A0F, BTL_FLO_STAGE_01),
    NPC_GROUP(N(NpcData_Dayzee_04), 0x1A0F, BTL_FLO_STAGE_01),
    NPC_GROUP(N(NpcData_Dayzee_05), 0x1A0F, BTL_FLO_STAGE_01),
    NPC_GROUP(N(NpcData_Dayzee_06), 0x1A0F, BTL_FLO_STAGE_01),
    NPC_GROUP(N(NpcData_Dayzee_07), 0x1A12, BTL_FLO_STAGE_01),
    NPC_GROUP(N(NpcData_AmazyDayzee), 0x1A1C, BTL_FLO_STAGE_00),
    {}
};
