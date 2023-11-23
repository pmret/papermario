#include "jan_16.h"
#include "effects.h"

EvtScript N(EVS_ExitWalk_jan_15_1) = EVT_EXIT_WALK(60, jan_16_ENTRY_0, "jan_15", jan_15_ENTRY_1);
EvtScript N(EVS_ExitWalk_jan_22_1) = EVT_EXIT_WALK(60, jan_16_ENTRY_1, "jan_22", jan_22_ENTRY_1);
EvtScript N(EVS_ExitWalk_jan_17_0) = EVT_EXIT_WALK(60, jan_16_ENTRY_2, "jan_17", jan_17_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_15_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_22_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_ExitWalk_jan_17_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_o83, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SpawnButterflies) = {
    EVT_IF_NE(GB_StoryProgress, STORY_CH5_RAPHAEL_LEFT_NEST)
        EVT_PLAY_EFFECT(EFFECT_BUTTERFLIES, 5, -310, 10, 0)
        EVT_PLAY_EFFECT(EFFECT_BUTTERFLIES, 5, -210, 10, 240)
        EVT_PLAY_EFFECT(EFFECT_BUTTERFLIES, 5, 330, 10, 260)
    EVT_END_IF
    EVT_PLAY_EFFECT(EFFECT_BUTTERFLIES, 5, -300, 10, 270)
    EVT_PLAY_EFFECT(EFFECT_BUTTERFLIES, 5, -80, 10, 390)
    EVT_PLAY_EFFECT(EFFECT_BUTTERFLIES, 5, 430, 10, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_AnimateFallBreakingBranch) = {
    EVT_SET(LVarF, 0)
    EVT_LOOP(0)
        EVT_SETF(LVar0, MV_Unk_0A)
        EVT_SETF(LVar1, MV_Unk_0A)
        EVT_MULF(LVar0, EVT_FLOAT(-0.02))
        EVT_MULF(LVar1, EVT_FLOAT(0.04))
        EVT_ADDF(LVar0, 1)
        EVT_ADDF(LVar1, 1)
        EVT_CALL(ScaleGroup, MODEL_g47, LVar0, LVar1, 1)
        EVT_ADD(LVarF, 1)
        EVT_IF_GE(LVarF, 600)
            EVT_SET(LVarF, 0)
        EVT_END_IF
        EVT_SETF(LVar0, LVarA)
        EVT_MULF(LVar0, EVT_FLOAT(-0.046875))
        EVT_ADDF(MV_Unk_0A, LVar0)
        EVT_MULF(MV_Unk_0A, EVT_FLOAT(0.84375))
        EVT_ADDF(LVarA, MV_Unk_0A)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_EnterFalling) = {
    EVT_EXEC(N(EVS_AnimateFallBreakingBranch))
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(DisablePlayerPhysics, TRUE)
    EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_CALL(DisablePartnerAI, 0)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 35, 100, 330)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 35, 100, 330)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(GetPartnerInUse, LVar0)
    EVT_IF_NE(LVar0, PARTNER_NONE)
        EVT_CALL(InterruptUsePartner)
    EVT_END_IF
    EVT_WAIT(15)
    EVT_THREAD
        EVT_WAIT(30)
        EVT_CALL(SetPanTarget, CAM_DEFAULT, 35, 0, 330)
        EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.8))
        EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_END_THREAD
    EVT_CALL(DisablePlayerPhysics, FALSE)
    EVT_CALL(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
    EVT_CALL(SetPlayerPos, 35, 600, 340)
    EVT_CALL(MakeLerp, 600, 130, 15, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(SetPlayerPos, 35, LVar0, 340)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, 35, 120, 340, 100)
    EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, 55, 120, 330, 100)
    EVT_ADDF(MV_Unk_0A, EVT_FLOAT(-7.5))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 190, 350)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.2))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_THREAD
        EVT_CALL(SetPlayerJumpscale, EVT_FLOAT(2.0))
        EVT_CALL(PlaySoundAtPlayer, SOUND_SHAKE_TREE_LEAVES, SOUND_SPACE_DEFAULT)
        EVT_CALL(PlayerJump, -35, 0, 385, 30)
        EVT_CALL(SetPlayerActionState, ACTION_STATE_LAND)
    EVT_END_THREAD
    EVT_CALL(SetNpcJumpscale, NPC_PARTNER, 0)
    EVT_CALL(NpcJump0, NPC_PARTNER, 35, 130, 330, 15)
    EVT_THREAD
        EVT_LOOP(3)
            EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, 35, 120, 340, 100)
            EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, 55, 120, 340, 100)
            EVT_WAIT(5)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_ADDF(MV_Unk_0A, EVT_FLOAT(-7.5))
    EVT_CALL(SetPanTarget, CAM_DEFAULT, -35, 0, 385)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.8))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(SetNpcJumpscale, NPC_PARTNER, EVT_FLOAT(2.0))
    EVT_CALL(NpcJump0, NPC_PARTNER, -10, 0, 395, 20)
    EVT_CALL(EnablePartnerAI)
    EVT_CALL(ResetCam, CAM_DEFAULT, EVT_FLOAT(4.0))
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};

#include "world/common/atomic/ApplyTint.inc.c"

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_SETUP_CAMERA_ALT_NO_LEAD()
    EVT_CALL(MakeNpcs, FALSE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC_WAIT(N(EVS_MakeEntities))
    EVT_EXEC(N(D_802412D4_B812D4))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(GetEntryID, LVar0)
    EVT_IF_EQ(LVar0, jan_16_ENTRY_4)
        EVT_EXEC(N(EVS_EnterFalling))
        EVT_EXEC(N(EVS_BindExitTriggers))
    EVT_ELSE
        EVT_SET(LVar0, EVT_PTR(N(EVS_BindExitTriggers)))
        EVT_EXEC(EnterWalk)
    EVT_END_IF
    EVT_EXEC_WAIT(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_SetupBushes))
    EVT_EXEC(N(EVS_SpawnButterflies))
    EVT_CALL(N(SetModelTintMode), APPLY_TINT_MODELS, -1, 3)
    EVT_CALL(N(SetModelTintMode), APPLY_TINT_BG, NULL, 3)
    EVT_CALL(N(SetModelTintParams), ENV_TINT_REMAP, 255, 255, 255, 0, 0, 25, 0, 0, 0)
    EVT_RETURN
    EVT_END
};
