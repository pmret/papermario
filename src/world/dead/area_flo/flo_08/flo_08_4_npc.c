#include "flo_08.h"
#include "sprite/player.h"

#include "world/common/enemy/AmazyDayzee.inc.c"
#include "world/common/npc/GateFlower.inc.c"
#include "world/common/enemy/CrazyDayzee.inc.c"

#include "world/common/complete/NormalItemChoice.inc.c"

static s32 N(FlowerGuard_ItemChoiceList)[ITEM_NUM_CONSUMABLES + 1];
#include "world/area_flo/common/ItemChoice_FlowerGuard.inc.c"

EvtScript N(EVS_NpcInteract_GateFlower) = {
    Call(DisablePlayerInput, TRUE)
    IfEq(GF_FLO08_GaveYellowBerry, FALSE)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamDistance, CAM_DEFAULT, 350)
        Call(SetCamPitch, CAM_DEFAULT, Float(18.5), Float(-7.5))
        Call(SetCamSpeed, CAM_DEFAULT, Float(4.0))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Yellow_Talk, ANIM_GateFlower_Yellow_Idle, 0, MSG_CH6_0042)
        Call(SetPlayerAnimation, ANIM_Mario1_Thinking)
        Call(N(FlowerGuard_MakeItemList))
        EVT_CHOOSE_CONSUMABLE_FROM(N(FlowerGuard_ItemChoiceList), 0)
        Switch(LVar0)
            CaseLe(0)
                Call(SetPlayerAnimation, ANIM_Mario1_Still)
                Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Yellow_Talk, ANIM_GateFlower_Yellow_Idle, 0, MSG_CH6_0043)
            CaseDefault
                Set(LVar8, LVar0)
                Call(N(FlowerGuard_JudgeItemTastiness), LVar0)
                Call(MakeItemEntity, LVar8, -695, 20, -29, ITEM_SPAWN_MODE_DECORATION, 0)
                Set(LVar7, LVar0)
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_EAT_OR_DRINK, SOUND_SPACE_DEFAULT)
                Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Yellow_Eat)
                Wait(20)
                Call(RemoveItemEntity, LVar7)
                Switch(LVar8)
                    CaseEq(160)
                        Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Yellow_Chew, ANIM_GateFlower_Yellow_Idle, 0, MSG_CH6_0046)
                        Call(PlaySoundAtNpc, NPC_SELF, SOUND_APPROVE, SOUND_SPACE_DEFAULT)
                        Call(EndSpeech, NPC_SELF, ANIM_GateFlower_Yellow_HappyTalk, ANIM_GateFlower_Yellow_HappyIdle, 0)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Yellow_OpenGate)
                        Call(PlaySoundAtCollider, COLLIDER_o96, SOUND_METAL_GATE_OPEN, SOUND_SPACE_DEFAULT)
                        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o96, COLLIDER_FLAGS_UPPER_MASK)
                        Call(MakeLerp, 0, 100, 30, EASING_QUADRATIC_IN)
                        Loop(0)
                            Call(UpdateLerp)
                            SetF(LVar8, LVar0)
                            SetF(LVar9, LVar0)
                            MulF(LVar8, Float(0.5))
                            MulF(LVar9, Float(1.2))
                            Call(RotateModel, MODEL_o69, LVar8, 0, 1, 0)
                            Call(RotateModel, MODEL_o70, LVar8, 0, 1, 0)
                            Call(RotateModel, MODEL_o71, LVar8, 0, 1, 0)
                            Call(RotateModel, MODEL_o148, LVar9, 0, -1, 0)
                            Call(RotateModel, MODEL_o149, LVar9, 0, -1, 0)
                            Call(RotateModel, MODEL_o150, LVar9, 0, -1, 0)
                            Wait(1)
                            IfNe(LVar1, 1)
                                BreakLoop
                            EndIf
                        EndLoop
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Yellow_HappyDance)
                        Set(GF_FLO08_GaveYellowBerry, TRUE)
                    CaseEq(159)
                        Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Yellow_Chew, ANIM_GateFlower_Yellow_Idle, 0, MSG_CH6_0045)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Yellow_Idle)
                    CaseEq(158)
                        Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Yellow_Chew, ANIM_GateFlower_Yellow_Idle, 0, MSG_CH6_0045)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Yellow_Idle)
                    CaseDefault
                        Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Yellow_Chew, ANIM_GateFlower_Yellow_Idle, 0, MSG_CH6_0044)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Yellow_Disgust)
                        Call(PlaySoundAtNpc, NPC_SELF, SOUND_SPIT_OUT, SOUND_SPACE_DEFAULT)
                        Call(MakeItemEntity, LVar8, 125, 20, 0, ITEM_SPAWN_MODE_DECORATION, 0)
                        Set(LVar7, LVar0)
                        Wait(5)
                        Call(GetAngleToPlayer, NPC_SELF, LVar0)
                        IfLt(LVar0, 180)
                            Call(MakeLerp, 0, 100, 7, EASING_LINEAR)
                            Loop(0)
                                Call(UpdateLerp)
                                SetF(LVar2, Float(-0.5))
                                SetF(LVar3, Float(-0.2))
                                SetF(LVar4, Float(0.9))
                                MulF(LVar2, LVar0)
                                MulF(LVar3, LVar0)
                                MulF(LVar4, LVar0)
                                AddF(LVar2, Float(-700.0))
                                AddF(LVar3, Float(15.0))
                                AddF(LVar4, Float(-25.0))
                                Call(N(FlowerGuard_SetItemEntityPosition), LVar7, LVar2, LVar3, LVar4)
                                Wait(1)
                                IfEq(LVar1, 0)
                                    BreakLoop
                                EndIf
                            EndLoop
                        Else
                            Call(MakeLerp, 0, 100, 7, EASING_LINEAR)
                            Loop(0)
                                Call(UpdateLerp)
                                SetF(LVar2, Float(0.5))
                                SetF(LVar3, Float(-0.2))
                                SetF(LVar4, Float(0.9))
                                MulF(LVar2, LVar0)
                                MulF(LVar3, LVar0)
                                MulF(LVar4, LVar0)
                                AddF(LVar2, Float(-690.0))
                                AddF(LVar3, Float(15.0))
                                AddF(LVar4, Float(-25.0))
                                Call(N(FlowerGuard_SetItemEntityPosition), LVar7, LVar2, LVar3, LVar4)
                                Wait(1)
                                IfEq(LVar1, 0)
                                    BreakLoop
                                EndIf
                            EndLoop
                        EndIf
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Yellow_Idle)
                        Call(RemoveItemEntity, LVar7)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Yellow_Idle)
                        Call(EndSpeech, NPC_SELF, ANIM_GateFlower_Yellow_Talk, ANIM_GateFlower_Yellow_Idle, 0)
                EndSwitch
        EndSwitch
        Thread
            Call(ResetCam, CAM_DEFAULT, Float(6.0))
        EndThread
        Wait(10)
    Else
        IfLt(GB_StoryProgress, STORY_CH6_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Yellow_HappyTalk, ANIM_GateFlower_Yellow_HappyIdle, 0, MSG_CH6_0047)
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Yellow_HappyTalk, ANIM_GateFlower_Yellow_HappyIdle, 0, MSG_CH6_0048)
        EndIf
    EndIf
    Call(DisablePlayerInput, FALSE)
    Unbind
    Return
    End
};

EvtScript N(EVS_NpcInit_GateFlower) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_GateFlower)))
    IfEq(GF_FLO08_GaveYellowBerry, TRUE)
        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Yellow_HappyDance)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o96, COLLIDER_FLAGS_UPPER_MASK)
        Call(RotateModel, MODEL_o69, 50, 0, 1, 0)
        Call(RotateModel, MODEL_o70, 50, 0, 1, 0)
        Call(RotateModel, MODEL_o71, 50, 0, 1, 0)
        Call(RotateModel, MODEL_o148, 120, 0, -1, 0)
        Call(RotateModel, MODEL_o149, 120, 0, -1, 0)
        Call(RotateModel, MODEL_o150, 120, 0, -1, 0)
    EndIf
    Return
    End
};

NpcData N(NpcData_GateFlower) = {
    .id = NPC_GateFlower,
    .pos = { -695.0f, 0.0f, -30.0f },
    .yaw = 270,
    .init = &N(EVS_NpcInit_GateFlower),
    .settings = &N(NpcSettings_GateFlower),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_400000,
    .drops = NO_DROPS,
    .animations = GATE_FLOWER_YELLOW_ANIMS,
    .tattle = MSG_NpcTattle_YellowGateFlower,
};

NpcData N(NpcData_Dayzee_01) = {
    .id = NPC_Dayzee_01,
    .pos = { 205.0f, 0.0f, -80.0f },
    .yaw = 90,
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
    .settings = &N(NpcSettings_CrazyDayzee),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = CRAZY_DAYZEE_DROPS,
    .animations = CRAZY_DAYZEE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Dayzee_02) = {
    .id = NPC_Dayzee_02,
    .pos = { 275.0f, 0.0f, -115.0f },
    .yaw = 270,
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
    .settings = &N(NpcSettings_CrazyDayzee),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING,
    .drops = CRAZY_DAYZEE_DROPS,
    .animations = CRAZY_DAYZEE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Dayzee_03) = {
    .id = NPC_Dayzee_03,
    .pos = { -230.0f, 60.0f, -110.0f },
    .yaw = 90,
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
    .settings = &N(NpcSettings_CrazyDayzee),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = CRAZY_DAYZEE_DROPS,
    .animations = CRAZY_DAYZEE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Dayzee_04) = {
    .id = NPC_Dayzee_04,
    .pos = { -330.0f, 60.0f, -110.0f },
    .yaw = 270,
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
    .settings = &N(NpcSettings_CrazyDayzee),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = CRAZY_DAYZEE_DROPS,
    .animations = CRAZY_DAYZEE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Dayzee_05) = {
    .id = NPC_Dayzee_05,
    .pos = { -430.0f, 60.0f, -110.0f },
    .yaw = 90,
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
    .settings = &N(NpcSettings_CrazyDayzee),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = CRAZY_DAYZEE_DROPS,
    .animations = CRAZY_DAYZEE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Dayzee_06) = {
    .id = NPC_Dayzee_06,
    .pos = { -530.0f, 60.0f, -110.0f },
    .yaw = 270,
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
    .settings = &N(NpcSettings_CrazyDayzee),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = CRAZY_DAYZEE_DROPS,
    .animations = CRAZY_DAYZEE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

NpcData N(NpcData_Dayzee_07) = {
    .id = NPC_Dayzee_07,
    .pos = { -630.0f, 60.0f, -110.0f },
    .yaw = 90,
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
    .settings = &N(NpcSettings_CrazyDayzee),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = CRAZY_DAYZEE_DROPS,
    .animations = CRAZY_DAYZEE_ANIMS,
    .aiDetectFlags = AI_DETECT_SIGHT | AI_DETECT_SENSITIVE_MOTION,
};

EvtScript N(EVS_NpcInit_AmazyDayzee) = {
    Thread
        Wait(2)
        Call(GetNpcPointer, NPC_Dayzee_02, LVar0)
        IfEq(LVar0, 0)
            Call(RemoveNpc, NPC_SELF)
            Return
        EndIf
        Call(RandInt, 100, LVar0)
        IfLt(LVar0, 30)
            Call(SetNpcFlagBits, NPC_Dayzee_02, NPC_FLAG_INVISIBLE | NPC_FLAG_INACTIVE, TRUE)
            Call(SetNpcPos, NPC_Dayzee_02, NPC_DISPOSE_LOCATION)
        Else
            Call(SetNpcFlagBits, NPC_SELF, NPC_FLAG_INVISIBLE | NPC_FLAG_INACTIVE, TRUE)
            Call(SetNpcPos, NPC_SELF, NPC_DISPOSE_LOCATION)
        EndIf
    EndThread
    Return
    End
};

NpcData N(NpcData_AmazyDayzee) = {
    .id = NPC_AmazyDayzee,
    .pos = { 240.0f, 0.0f, -90.0f },
    .yaw = 270,
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
    .init = &N(EVS_NpcInit_AmazyDayzee),
    .settings = &N(NpcSettings_AmazyDayzee),
    .flags = ENEMY_FLAG_IGNORE_ENTITY_COLLISION | ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = AMAZY_DAYZEE_DROPS,
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
