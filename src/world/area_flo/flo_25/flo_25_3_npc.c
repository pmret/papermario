#include "flo_25.h"
#include "sprite/player.h"

#include "world/common/npc/GateFlower.inc.c"
#include "world/common/enemy/RuffPuff.inc.c"
#include "world/common/enemy/Bzzap.inc.c"

#include "world/common/complete/NormalItemChoice.inc.c"

BSS s32 N(FlowerGuard_ItemChoiceList)[ITEM_NUM_CONSUMABLES + 1];
#include "../common/ItemChoice_FlowerGuard.inc.c"

EvtScript N(EVS_NpcInteract_GateFlower) = {
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_IF_EQ(GF_FLO25_GaveRedBerry, FALSE)
        EVT_CALL(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        EVT_CALL(SetCamDistance, CAM_DEFAULT, 350)
        EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(18.5), EVT_FLOAT(-7.5))
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(4.0 / DT))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
        EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Red_Talk, ANIM_GateFlower_Red_Idle, 0, MSG_CH6_003B)
        EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Thinking)
        EVT_CALL(N(FlowerGuard_MakeItemList))
        EVT_CHOOSE_CONSUMABLE_FROM(N(FlowerGuard_ItemChoiceList), 0)
        EVT_SWITCH(LVar0)
            EVT_CASE_LE(0)
                EVT_CALL(SetPlayerAnimation, ANIM_Mario1_Still)
                EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Red_Talk, ANIM_GateFlower_Red_Idle, 0, MSG_CH6_003C)
            EVT_CASE_DEFAULT
                EVT_SET(LVar8, LVar0)
                EVT_CALL(N(FlowerGuard_JudgeItemTastiness), LVar0)
                EVT_CALL(MakeItemEntity, LVar8, 505, 20, -24, ITEM_SPAWN_MODE_DECORATION, 0)
                EVT_SET(LVar7, LVar0)
                EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_EAT_OR_DRINK, SOUND_SPACE_DEFAULT)
                EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Red_Eat)
                EVT_WAIT(20 * DT)
                EVT_CALL(RemoveItemEntity, LVar7)
                EVT_SWITCH(LVar8)
                    EVT_CASE_EQ(159)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Red_Chew, ANIM_GateFlower_Red_Idle, 0, MSG_CH6_003F)
                        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_APPROVE, SOUND_SPACE_DEFAULT)
                        EVT_CALL(EndSpeech, NPC_SELF, ANIM_GateFlower_Red_HappyTalk, ANIM_GateFlower_Red_HappyIdle, 0)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Red_OpenGate)
                        EVT_CALL(PlaySoundAtCollider, COLLIDER_o94, SOUND_METAL_GATE_OPEN, SOUND_SPACE_DEFAULT)
                        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o94, COLLIDER_FLAGS_UPPER_MASK)
                        EVT_CALL(MakeLerp, 0, 100, 30, EASING_QUADRATIC_IN)
                        EVT_LOOP(0)
                            EVT_CALL(UpdateLerp)
                            EVT_SETF(LVar8, LVar0)
                            EVT_SETF(LVar9, LVar0)
                            EVT_MULF(LVar8, EVT_FLOAT(0.5))
                            EVT_MULF(LVar9, EVT_FLOAT(1.2))
                            EVT_CALL(RotateModel, MODEL_o137, LVar8, 0, -1, 0)
                            EVT_CALL(RotateModel, MODEL_o138, LVar8, 0, -1, 0)
                            EVT_CALL(RotateModel, MODEL_o139, LVar8, 0, -1, 0)
                            EVT_CALL(RotateModel, MODEL_o134, LVar9, 0, 1, 0)
                            EVT_CALL(RotateModel, MODEL_o135, LVar9, 0, 1, 0)
                            EVT_CALL(RotateModel, MODEL_o136, LVar9, 0, 1, 0)
                            EVT_WAIT(1)
                            EVT_IF_NE(LVar1, 1)
                                EVT_BREAK_LOOP
                            EVT_END_IF
                        EVT_END_LOOP
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Red_HappyDance)
                        EVT_SET(GF_FLO25_GaveRedBerry, TRUE)
                    EVT_CASE_EQ(160)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Red_Chew, ANIM_GateFlower_Red_Idle, 0, MSG_CH6_003E)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Red_Idle)
                    EVT_CASE_EQ(158)
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Red_Chew, ANIM_GateFlower_Red_Idle, 0, MSG_CH6_003E)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Red_Idle)
                    EVT_CASE_DEFAULT
                        EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Red_Chew, ANIM_GateFlower_Red_Idle, 0, MSG_CH6_003D)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Red_Disgust)
                        EVT_CALL(PlaySoundAtNpc, NPC_SELF, SOUND_SPIT_OUT, SOUND_SPACE_DEFAULT)
                        EVT_CALL(MakeItemEntity, LVar8, -125, 20, 0, ITEM_SPAWN_MODE_DECORATION, 0)
                        EVT_SET(LVar7, LVar0)
                        EVT_WAIT(5 * DT)
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
                                EVT_ADDF(LVar2, EVT_FLOAT(500.0))
                                EVT_ADDF(LVar3, EVT_FLOAT(15.0))
                                EVT_ADDF(LVar4, EVT_FLOAT(-20.0))
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
                                EVT_SETF(LVar4, EVT_FLOAT(0.9))
                                EVT_MULF(LVar2, LVar0)
                                EVT_MULF(LVar3, LVar0)
                                EVT_MULF(LVar4, LVar0)
                                EVT_ADDF(LVar2, EVT_FLOAT(510.0))
                                EVT_ADDF(LVar3, EVT_FLOAT(15.0))
                                EVT_ADDF(LVar4, EVT_FLOAT(-20.0))
                                EVT_CALL(N(FlowerGuard_SetItemEntityPosition), LVar7, LVar2, LVar3, LVar4)
                                EVT_WAIT(1)
                                EVT_IF_NE(LVar1, 1)
                                    EVT_BREAK_LOOP
                                EVT_END_IF
                            EVT_END_LOOP
                        EVT_END_IF
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Red_Idle)
                        EVT_CALL(RemoveItemEntity, LVar7)
                        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Red_Idle)
                        EVT_CALL(EndSpeech, NPC_SELF, ANIM_GateFlower_Red_Talk, ANIM_GateFlower_Red_Idle, 0)
                EVT_END_SWITCH
        EVT_END_SWITCH
        EVT_THREAD
            EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(6.0 / DT))
        EVT_END_THREAD
        EVT_WAIT(10 * DT)
    EVT_ELSE
        EVT_IF_LT(GB_StoryProgress, STORY_CH6_STAR_SPIRIT_RESCUED)
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Red_HappyTalk, ANIM_GateFlower_Red_HappyIdle, 0, MSG_CH6_0040)
        EVT_ELSE
            EVT_CALL(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Red_HappyTalk, ANIM_GateFlower_Red_HappyIdle, 0, MSG_CH6_0041)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_UNBIND
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_NpcInit_GateFlower) = {
    EVT_CALL(BindNpcInteract, NPC_SELF, EVT_PTR(N(EVS_NpcInteract_GateFlower)))
    EVT_IF_EQ(GF_FLO25_GaveRedBerry, TRUE)
        EVT_CALL(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Red_HappyDance)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o94, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(RotateModel, MODEL_o137, 50, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_o138, 50, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_o139, 50, 0, -1, 0)
        EVT_CALL(RotateModel, MODEL_o134, 120, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o135, 120, 0, 1, 0)
        EVT_CALL(RotateModel, MODEL_o136, 120, 0, 1, 0)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

NpcData N(NpcData_GateFlower) = {
    .id = NPC_GateFlower,
    .pos = { 505.0f, 0.0f, -25.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_GateFlower),
    .settings = &N(NpcSettings_GateFlower),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = GATE_FLOWER_RED_ANIMS,
    .tattle = MSG_NpcTattle_RedGateFlower,
};

NpcData N(NpcData_RuffPuff) = {
    .id = NPC_RuffPuff,
    .pos = { -200.0f, 45.0f, 0.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = FALSE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -200, 45, 0 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -200, 45, 0 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_RuffPuff),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = RUFF_PUFF_DROPS,
    .animations = RUFF_PUFF_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Bzzap) = {
    .id = NPC_Bzzap,
    .pos = { 150.0f, 55.0f, 0.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = TRUE,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 150, 50, 0 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 150, 50, 0 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_Bzzap),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION,
    .drops = BZZAP_DROPS,
    .animations = BZZAP_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_RuffPuff), BTL_FLO_FORMATION_22, BTL_FLO_STAGE_05),
    NPC_GROUP(N(NpcData_Bzzap), BTL_FLO_FORMATION_1A, BTL_FLO_STAGE_01),
    NPC_GROUP(N(NpcData_GateFlower)),
    {}
};
