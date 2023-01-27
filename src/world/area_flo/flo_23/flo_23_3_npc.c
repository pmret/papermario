#include "flo_23.h"

#include "world/common/npc/GateFlower.inc.c"

#include "world/common/complete/NormalItemChoice.inc.c"

#include "world/common/enemy/complete/Spiny.inc.c"

BSS s32 N(FlowerGuard_ItemChoiceList)[ITEM_NUM_CONSUMABLES + 1];
#include "../common/ItemChoice_FlowerGuard.inc.c"

EvtScript N(EVS_NpcInteract_GateFlower) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(GF_FLO23_GaveBlueBerry, FALSE)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.5), EVT_FLOAT(-7.5))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Blue_Talk, ANIM_GateFlower_Blue_Idle, 0, MSG_CH6_0049)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario_Thinking)
        EVT_CALL(N(FlowerGuard_MakeItemList))
        EVT_CHOOSE_CONSUMABLE_FROM(N(FlowerGuard_ItemChoiceList), 2)
        EVT_SWITCH(LVar0)
            EVT_CASE_LE(0)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario_StandStill)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Blue_Talk, ANIM_GateFlower_Blue_Idle, 0, MSG_CH6_004A)
            EVT_CASE_DEFAULT
                EVT_SET(LVar8, LVar0)
                EVT_CALL(N(FlowerGuard_JudgeItemTastiness), LVar0)
                EVT_CALL(MakeItemEntity, LVar8, 385, 20, -34, ITEM_SPAWN_MODE_DECORATION, 0)
                EVT_SET(LVar7, LVar0)
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2095, 0)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Blue_Eat)
                EVT_WAIT(20)
                EVT_CALL(RemoveItemEntity, LVar7)
                EVT_SWITCH(LVar8)
                    EVT_CASE_EQ(158)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Blue_Chew, ANIM_GateFlower_Blue_Idle, 0, MSG_CH6_004D)
                        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_21C, 0)
                        EVT_CALL(EndSpeech, NPC_SELF, ANIM_GateFlower_Blue_HappyTalk, ANIM_GateFlower_Blue_HappyIdle, 0)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Blue_OpenGate)
                        EVT_CALL(PlaySoundAtCollider, COLLIDER_o95, SOUND_METAL_GATE_OPEN, 0)
                        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o95, COLLIDER_FLAGS_UPPER_MASK)
                        EVT_CALL(MakeLerp, 0, 100, 30, EASING_QUADRATIC_IN)
                        EVT_LOOP(0)
                            EVT_CALL(UpdateLerp)
                            EVT_SETF(LVar8, LVar0)
                            EVT_SETF(LVar9, LVar0)
                            EVT_MULF(LVar8, EVT_FLOAT(0.5))
                            EVT_MULF(LVar9, EVT_FLOAT(1.2))
                            EVT_CALL(RotateModel, MODEL_o86, LVar8, 0, -1, 0)
                            EVT_CALL(RotateModel, MODEL_o87, LVar8, 0, -1, 0)
                            EVT_CALL(RotateModel, MODEL_o88, LVar8, 0, -1, 0)
                            EVT_CALL(RotateModel, MODEL_o83, LVar9, 0, 1, 0)
                            EVT_CALL(RotateModel, MODEL_o84, LVar9, 0, 1, 0)
                            EVT_CALL(RotateModel, MODEL_o85, LVar9, 0, 1, 0)
                            EVT_WAIT(1)
                            EVT_IF_NE(LVar1, 1)
                                EVT_BREAK_LOOP
                            EVT_END_IF
                        EVT_END_LOOP
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Blue_HappyDance)
                        EVT_SET(GF_FLO23_GaveBlueBerry, TRUE)
                    EVT_CASE_EQ(159)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Blue_Chew, ANIM_GateFlower_Blue_Idle, 0, MSG_CH6_004C)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Blue_Idle)
                    EVT_CASE_EQ(160)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Blue_Chew, ANIM_GateFlower_Blue_Idle, 0, MSG_CH6_004C)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Blue_Idle)
                    EVT_CASE_DEFAULT
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Blue_Chew, ANIM_GateFlower_Blue_Idle, 0, MSG_CH6_004B)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Blue_Disgust)
                        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_2096, 0)
                        EVT_CALL(MakeItemEntity, LVar8, 375, 20, 0, ITEM_SPAWN_MODE_DECORATION, 0)
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
                                EVT_ADDF(LVar2, EVT_FLOAT(380.0))
                                EVT_ADDF(LVar3, EVT_FLOAT(15.0))
                                EVT_ADDF(LVar4, EVT_FLOAT(-30.0))
                                EVT_CALL(N(FlowerGuard_SetItemEntityPosition), LVar7, LVar2, LVar3, LVar4)
                                EVT_WAIT(1)
                                EVT_IF_NE(LVar1, 1)
                                    EVT_BREAK_LOOP
                                EVT_END_IF
                            EVT_END_LOOP
                        EVT_ELSE
                            EVT_CALL(MakeLerp, 0, 100, 7, EASING_LINEAR)
                            EVT_LOOP(0)
                                EVT_CALL(UpdateLerp)
                                EVT_SETF(LVar2, EVT_FLOAT(0.5))
                                EVT_SETF(LVar3, EVT_FLOAT(-0.2))
                                EVT_SETF(LVar4, EVT_FLOAT(1.0))
                                EVT_MULF(LVar2, LVar0)
                                EVT_MULF(LVar3, LVar0)
                                EVT_MULF(LVar4, LVar0)
                                EVT_ADDF(LVar2, EVT_FLOAT(390.0))
                                EVT_ADDF(LVar3, EVT_FLOAT(15.0))
                                EVT_ADDF(LVar4, EVT_FLOAT(-30.0))
                                EVT_CALL(N(FlowerGuard_SetItemEntityPosition), LVar7, LVar2, LVar3, LVar4)
                                EVT_WAIT(1)
                                EVT_IF_NE(LVar1, 1)
                                    EVT_BREAK_LOOP
                                EVT_END_IF
                            EVT_END_LOOP
                        EVT_END_IF
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Blue_Idle)
                        EVT_CALL(RemoveItemEntity, LVar7)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Blue_Idle)
                        EVT_CALL(EndSpeech, NPC_SELF, ANIM_GateFlower_Blue_Talk, ANIM_GateFlower_Blue_Idle, 0)
                EVT_END_SWITCH
        EVT_END_SWITCH
        EVT_THREAD
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(6.0))
        EVT_END_THREAD
        EVT_WAIT(10)
    EVT_ELSE
        EVT_IF_LT(GB_StoryProgress, STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Blue_HappyTalk, ANIM_GateFlower_Blue_HappyIdle, 0, MSG_CH6_004E)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Blue_HappyTalk, ANIM_GateFlower_Blue_HappyIdle, 0, MSG_CH6_004F)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_GateFlower) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_GateFlower)))
    EVT_IF_EQ(GF_FLO23_GaveBlueBerry, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Blue_HappyDance)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o95, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(RotateModel, MODEL_o86, 50, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_o87, 50, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_o88, 50, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_o83, 120, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o84, 120, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o85, 120, 0, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

StaticNpc N(NpcData_GateFlower) = {
    .id = NPC_GateFlower,
    .settings = &N(NpcSettings_GateFlower),
    .pos = { 385.0f, 0.0f, -35.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_1 | ENEMY_FLAG_8 | ENEMY_FLAG_100 | ENEMY_FLAG_400 | ENEMY_FLAG_800 | ENEMY_FLAG_2000 | ENEMY_FLAG_400000,
    .init = &N(EVS_NpcInit_GateFlower),
    .drops = GATE_FLOWER_DROPS,
    .animations = GATE_FLOWER_BLUE_ANIMS,
    .tattle = MSG_NpcTattle_BlueGateFlower,
};

StaticNpc N(NpcData_Spiny_01) = {
    .id = NPC_Spiny_01,
    .settings = &N(NpcSettings_Spiny),
    .pos = { 80.0f, 0.0f, 0.0f },
    .yaw = 90,
    .flags = ENEMY_FLAG_800 | ENEMY_FLAG_2000,
    .drops = SPINY_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 80, 0, 0 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 80, 0, 0 },
            .detectSize = { 200 },
        }
    },
    .animations = SPINY_ANIMS,
};

StaticNpc N(NpcData_Spiny_02) = {
    .id = NPC_Spiny_02,
    .settings = &N(NpcSettings_Spiny),
    .pos = { -320.0f, 0.0f, 0.0f },
    .yaw = 270,
    .flags = ENEMY_FLAG_800 | ENEMY_FLAG_2000,
    .drops = SPINY_DROPS,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -320, 0, 0 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -320, 0, 0 },
            .detectSize = { 200 },
        }
    },
    .animations = SPINY_ANIMS,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Spiny_01), BTL_FLO_FORMATION_0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_02), BTL_FLO_FORMATION_0D, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_GateFlower)),
    {}
};
