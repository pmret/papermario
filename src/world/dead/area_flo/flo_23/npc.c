#include "flo_23.h"
#include "sprite/player.h"

#include "world/common/npc/GateFlower.inc.c"

#include "world/common/complete/NormalItemChoice.inc.c"

#include "world/common/enemy/Spiny.inc.c"

BSS s32 N(FlowerGuard_ItemChoiceList)[ITEM_NUM_CONSUMABLES + 1];
#include "world/area_flo/common/ItemChoice_FlowerGuard.inc.c"

EvtScript N(EVS_NpcInteract_GateFlower) = {
    Call(DisablePlayerInput, true)
    IfEq(GF_FLO23_GaveBlueBerry, false)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamDistance, CAM_DEFAULT, 350)
        Call(SetCamPitch, CAM_DEFAULT, Float(18.5), Float(-7.5))
        Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Blue_Talk, ANIM_GateFlower_Blue_Idle, 0, MSG_CH6_0049)
        Call(SetPlayerAnimation, ANIM_Mario1_Thinking)
        Call(N(FlowerGuard_MakeItemList))
        EVT_CHOOSE_CONSUMABLE_FROM(N(FlowerGuard_ItemChoiceList), 2)
        Switch(LVar0)
            CaseLe(0)
                Call(SetPlayerAnimation, ANIM_Mario1_Still)
                Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Blue_Talk, ANIM_GateFlower_Blue_Idle, 0, MSG_CH6_004A)
            CaseDefault
                Set(LVar8, LVar0)
                Call(N(FlowerGuard_JudgeItemTastiness), LVar0)
                Call(MakeItemEntity, LVar8, 385, 20, -34, ITEM_SPAWN_MODE_DECORATION, 0)
                Set(LVar7, LVar0)
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_EAT_OR_DRINK, SOUND_SPACE_DEFAULT)
                Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Blue_Eat)
                Wait(20 * DT)
                Call(RemoveItemEntity, LVar7)
                Switch(LVar8)
                    CaseEq(158)
                        Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Blue_Chew, ANIM_GateFlower_Blue_Idle, 0, MSG_CH6_004D)
                        Call(PlaySoundAtNpc, NPC_SELF, SOUND_APPROVE, SOUND_SPACE_DEFAULT)
                        Call(EndSpeech, NPC_SELF, ANIM_GateFlower_Blue_HappyTalk, ANIM_GateFlower_Blue_HappyIdle, 0)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Blue_OpenGate)
                        Call(PlaySoundAtCollider, COLLIDER_o95, SOUND_METAL_GATE_OPEN, SOUND_SPACE_DEFAULT)
                        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o95, COLLIDER_FLAGS_UPPER_MASK)
                        Call(MakeLerp, 0, 100, 30, EASING_QUADRATIC_IN)
                        Loop(0)
                            Call(UpdateLerp)
                            SetF(LVar8, LVar0)
                            SetF(LVar9, LVar0)
                            MulF(LVar8, Float(0.5))
                            MulF(LVar9, Float(1.2))
                            Call(RotateModel, MODEL_o86, LVar8, 0, -1, 0)
                            Call(RotateModel, MODEL_o87, LVar8, 0, -1, 0)
                            Call(RotateModel, MODEL_o88, LVar8, 0, -1, 0)
                            Call(RotateModel, MODEL_o83, LVar9, 0, 1, 0)
                            Call(RotateModel, MODEL_o84, LVar9, 0, 1, 0)
                            Call(RotateModel, MODEL_o85, LVar9, 0, 1, 0)
                            Wait(1)
                            IfNe(LVar1, 1)
                                BreakLoop
                            EndIf
                        EndLoop
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Blue_HappyDance)
                        Set(GF_FLO23_GaveBlueBerry, true)
                    CaseEq(159)
                        Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Blue_Chew, ANIM_GateFlower_Blue_Idle, 0, MSG_CH6_004C)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Blue_Idle)
                    CaseEq(160)
                        Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Blue_Chew, ANIM_GateFlower_Blue_Idle, 0, MSG_CH6_004C)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Blue_Idle)
                    CaseDefault
                        Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Blue_Chew, ANIM_GateFlower_Blue_Idle, 0, MSG_CH6_004B)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Blue_Disgust)
                        Call(PlaySoundAtNpc, NPC_SELF, SOUND_SPIT_OUT, SOUND_SPACE_DEFAULT)
                        Call(MakeItemEntity, LVar8, 375, 20, 0, ITEM_SPAWN_MODE_DECORATION, 0)
                        Set(LVar7, LVar0)
                        Wait(5 * DT)
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
                                AddF(LVar2, Float(380.0))
                                AddF(LVar3, Float(15.0))
                                AddF(LVar4, Float(-30.0))
                                Call(N(FlowerGuard_SetItemEntityPosition), LVar7, LVar2, LVar3, LVar4)
                                Wait(1)
                                IfNe(LVar1, 1)
                                    BreakLoop
                                EndIf
                            EndLoop
                        Else
                            Call(MakeLerp, 0, 100, 7, EASING_LINEAR)
                            Loop(0)
                                Call(UpdateLerp)
                                SetF(LVar2, Float(0.5))
                                SetF(LVar3, Float(-0.2))
                                SetF(LVar4, Float(1.0))
                                MulF(LVar2, LVar0)
                                MulF(LVar3, LVar0)
                                MulF(LVar4, LVar0)
                                AddF(LVar2, Float(390.0))
                                AddF(LVar3, Float(15.0))
                                AddF(LVar4, Float(-30.0))
                                Call(N(FlowerGuard_SetItemEntityPosition), LVar7, LVar2, LVar3, LVar4)
                                Wait(1)
                                IfNe(LVar1, 1)
                                    BreakLoop
                                EndIf
                            EndLoop
                        EndIf
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Blue_Idle)
                        Call(RemoveItemEntity, LVar7)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Blue_Idle)
                        Call(EndSpeech, NPC_SELF, ANIM_GateFlower_Blue_Talk, ANIM_GateFlower_Blue_Idle, 0)
                EndSwitch
        EndSwitch
        Thread
            Call(ResetCam, CAM_DEFAULT, Float(6.0 / DT))
        EndThread
        Wait(10 * DT)
    Else
        IfLt(GB_StoryProgress, STORY_CH6_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Blue_HappyTalk, ANIM_GateFlower_Blue_HappyIdle, 0, MSG_CH6_004E)
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Blue_HappyTalk, ANIM_GateFlower_Blue_HappyIdle, 0, MSG_CH6_004F)
        EndIf
    EndIf
    Call(DisablePlayerInput, false)
    Unbind
    Return
    End
};

EvtScript N(EVS_NpcInit_GateFlower) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_GateFlower)))
    IfEq(GF_FLO23_GaveBlueBerry, true)
        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Blue_HappyDance)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o95, COLLIDER_FLAGS_UPPER_MASK)
        Call(RotateModel, MODEL_o86, 50, 0, -1, 0)
        Call(RotateModel, MODEL_o87, 50, 0, -1, 0)
        Call(RotateModel, MODEL_o88, 50, 0, -1, 0)
        Call(RotateModel, MODEL_o83, 120, 0, 1, 0)
        Call(RotateModel, MODEL_o84, 120, 0, 1, 0)
        Call(RotateModel, MODEL_o85, 120, 0, 1, 0)
    EndIf
    Return
    End
};

NpcData N(NpcData_GateFlower) = {
    .id = NPC_GateFlower,
    .pos = { 385.0f, 0.0f, -35.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_GateFlower),
    .settings = &N(NpcSettings_GateFlower),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
    .drops = NO_DROPS,
    .animations = GATE_FLOWER_BLUE_ANIMS,
    .tattle = MSG_NpcTattle_BlueGateFlower,
};

NpcData N(NpcData_Spiny_01) = {
    .id = NPC_Spiny_01,
    .pos = { 80.0f, 0.0f, 0.0f },
    .yaw = 90,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { 80, 0, 0 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { 80, 0, 0 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_Spiny),
    .flags = ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
};

NpcData N(NpcData_Spiny_02) = {
    .id = NPC_Spiny_02,
    .pos = { -320.0f, 0.0f, 0.0f },
    .yaw = 270,
    .territory = {
        .wander = {
            .isFlying = true,
            .moveSpeedOverride = NO_OVERRIDE_MOVEMENT_SPEED,
            .wanderShape = SHAPE_CYLINDER,
            .centerPos  = { -320, 0, 0 },
            .wanderSize = { 30 },
            .detectShape = SHAPE_CYLINDER,
            .detectPos  = { -320, 0, 0 },
            .detectSize = { 200 },
        }
    },
    .settings = &N(NpcSettings_Spiny),
    .flags = ENEMY_FLAG_FLYING | ENEMY_FLAG_NO_SHADOW_RAYCAST,
    .drops = SPINY_DROPS,
    .animations = SPINY_ANIMS,
};

// dead formation IDs differ from the current
NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_Spiny_01), 0x1A0C, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_Spiny_02), 0x1A0D, BTL_FLO_STAGE_02),
    NPC_GROUP(N(NpcData_GateFlower)),
    {}
};
