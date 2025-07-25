#include "flo_25.h"
#include "sprite/player.h"

#include "world/common/npc/GateFlower.inc.c"
#include "world/common/enemy/RuffPuff.inc.c"
#include "world/common/enemy/Bzzap.inc.c"

#include "world/common/complete/NormalItemChoice.inc.c"

BSS s32 N(FlowerGuard_ItemChoiceList)[ITEM_NUM_CONSUMABLES + 1];
#include "world/area_flo/common/ItemChoice_FlowerGuard.inc.c"

EvtScript N(EVS_NpcInteract_GateFlower) = {
    Call(DisablePlayerInput, true)
    IfEq(GF_FLO25_GaveRedBerry, false)
        Call(GetNpcPos, NPC_SELF, LVar0, LVar1, LVar2)
        Call(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
        Call(SetCamDistance, CAM_DEFAULT, 350)
        Call(SetCamPitch, CAM_DEFAULT, Float(18.5), Float(-7.5))
        Call(SetCamSpeed, CAM_DEFAULT, Float(4.0 / DT))
        Call(PanToTarget, CAM_DEFAULT, 0, true)
        Call(WaitForCam, CAM_DEFAULT, Float(1.0))
        Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Red_Talk, ANIM_GateFlower_Red_Idle, 0, MSG_CH6_003B)
        Call(SetPlayerAnimation, ANIM_Mario1_Thinking)
        Call(N(FlowerGuard_MakeItemList))
        EVT_CHOOSE_CONSUMABLE_FROM(N(FlowerGuard_ItemChoiceList), 0)
        Switch(LVar0)
            CaseLe(0)
                Call(SetPlayerAnimation, ANIM_Mario1_Still)
                Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Red_Talk, ANIM_GateFlower_Red_Idle, 0, MSG_CH6_003C)
            CaseDefault
                Set(LVar8, LVar0)
                Call(N(FlowerGuard_JudgeItemTastiness), LVar0)
                Call(MakeItemEntity, LVar8, 505, 20, -24, ITEM_SPAWN_MODE_DECORATION, 0)
                Set(LVar7, LVar0)
                Call(PlaySoundAtNpc, NPC_SELF, SOUND_EAT_OR_DRINK, SOUND_SPACE_DEFAULT)
                Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Red_Eat)
                Wait(20 * DT)
                Call(RemoveItemEntity, LVar7)
                Switch(LVar8)
                    CaseEq(159)
                        Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Red_Chew, ANIM_GateFlower_Red_Idle, 0, MSG_CH6_003F)
                        Call(PlaySoundAtNpc, NPC_SELF, SOUND_APPROVE, SOUND_SPACE_DEFAULT)
                        Call(EndSpeech, NPC_SELF, ANIM_GateFlower_Red_HappyTalk, ANIM_GateFlower_Red_HappyIdle, 0)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Red_OpenGate)
                        Call(PlaySoundAtCollider, COLLIDER_o94, SOUND_METAL_GATE_OPEN, SOUND_SPACE_DEFAULT)
                        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o94, COLLIDER_FLAGS_UPPER_MASK)
                        Call(MakeLerp, 0, 100, 30, EASING_QUADRATIC_IN)
                        Loop(0)
                            Call(UpdateLerp)
                            SetF(LVar8, LVar0)
                            SetF(LVar9, LVar0)
                            MulF(LVar8, Float(0.5))
                            MulF(LVar9, Float(1.2))
                            Call(RotateModel, MODEL_o137, LVar8, 0, -1, 0)
                            Call(RotateModel, MODEL_o138, LVar8, 0, -1, 0)
                            Call(RotateModel, MODEL_o139, LVar8, 0, -1, 0)
                            Call(RotateModel, MODEL_o134, LVar9, 0, 1, 0)
                            Call(RotateModel, MODEL_o135, LVar9, 0, 1, 0)
                            Call(RotateModel, MODEL_o136, LVar9, 0, 1, 0)
                            Wait(1)
                            IfNe(LVar1, 1)
                                BreakLoop
                            EndIf
                        EndLoop
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Red_HappyDance)
                        Set(GF_FLO25_GaveRedBerry, true)
                    CaseEq(160)
                        Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Red_Chew, ANIM_GateFlower_Red_Idle, 0, MSG_CH6_003E)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Red_Idle)
                    CaseEq(158)
                        Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Red_Chew, ANIM_GateFlower_Red_Idle, 0, MSG_CH6_003E)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Red_Idle)
                    CaseDefault
                        Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Red_Chew, ANIM_GateFlower_Red_Idle, 0, MSG_CH6_003D)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Red_Disgust)
                        Call(PlaySoundAtNpc, NPC_SELF, SOUND_SPIT_OUT, SOUND_SPACE_DEFAULT)
                        Call(MakeItemEntity, LVar8, -125, 20, 0, ITEM_SPAWN_MODE_DECORATION, 0)
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
                                AddF(LVar2, Float(500.0))
                                AddF(LVar3, Float(15.0))
                                AddF(LVar4, Float(-20.0))
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
                                SetF(LVar4, Float(0.9))
                                MulF(LVar2, LVar0)
                                MulF(LVar3, LVar0)
                                MulF(LVar4, LVar0)
                                AddF(LVar2, Float(510.0))
                                AddF(LVar3, Float(15.0))
                                AddF(LVar4, Float(-20.0))
                                Call(N(FlowerGuard_SetItemEntityPosition), LVar7, LVar2, LVar3, LVar4)
                                Wait(1)
                                IfNe(LVar1, 1)
                                    BreakLoop
                                EndIf
                            EndLoop
                        EndIf
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Red_Idle)
                        Call(RemoveItemEntity, LVar7)
                        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Red_Idle)
                        Call(EndSpeech, NPC_SELF, ANIM_GateFlower_Red_Talk, ANIM_GateFlower_Red_Idle, 0)
                EndSwitch
        EndSwitch
        Thread
            Call(ResetCam, CAM_DEFAULT, Float(6.0 / DT))
        EndThread
        Wait(10 * DT)
    Else
        IfLt(GB_StoryProgress, STORY_CH6_STAR_SPIRIT_RESCUED)
            Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Red_HappyTalk, ANIM_GateFlower_Red_HappyIdle, 0, MSG_CH6_0040)
        Else
            Call(SpeakToPlayer, NPC_SELF, ANIM_GateFlower_Red_HappyTalk, ANIM_GateFlower_Red_HappyIdle, 0, MSG_CH6_0041)
        EndIf
    EndIf
    Call(DisablePlayerInput, false)
    Unbind
    Return
    End
};

EvtScript N(EVS_NpcInit_GateFlower) = {
    Call(BindNpcInteract, NPC_SELF, Ref(N(EVS_NpcInteract_GateFlower)))
    IfEq(GF_FLO25_GaveRedBerry, true)
        Call(SetNpcAnimation, NPC_SELF, ANIM_GateFlower_Red_HappyDance)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o94, COLLIDER_FLAGS_UPPER_MASK)
        Call(RotateModel, MODEL_o137, 50, 0, -1, 0)
        Call(RotateModel, MODEL_o138, 50, 0, -1, 0)
        Call(RotateModel, MODEL_o139, 50, 0, -1, 0)
        Call(RotateModel, MODEL_o134, 120, 0, 1, 0)
        Call(RotateModel, MODEL_o135, 120, 0, 1, 0)
        Call(RotateModel, MODEL_o136, 120, 0, 1, 0)
    EndIf
    Return
    End
};

NpcData N(NpcData_GateFlower) = {
    .id = NPC_GateFlower,
    .pos = { 505.0f, 0.0f, -25.0f },
    .yaw = 90,
    .init = &N(EVS_NpcInit_GateFlower),
    .settings = &N(NpcSettings_GateFlower),
    .flags = COMMON_PASSIVE_FLAGS | ENEMY_FLAG_NO_SHADOW_RAYCAST | ENEMY_FLAG_DO_NOT_AUTO_FACE_PLAYER,
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
            .isFlying = false,
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
            .isFlying = true,
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

// dead formation IDs differ from the current
NpcGroupList N(DefaultNPCs) = {
    NPC_GROUP(N(NpcData_RuffPuff), 0x1A22, BTL_FLO_STAGE_05),
    NPC_GROUP(N(NpcData_Bzzap), 0x1A1A, BTL_FLO_STAGE_01),
    NPC_GROUP(N(NpcData_GateFlower)),
    {}
};
