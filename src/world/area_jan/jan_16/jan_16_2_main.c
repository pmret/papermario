#include "jan_16.h"
#include "effects.h"

EvtScript N(EVS_ExitWalk_jan_15_1) = EVT_EXIT_WALK(60, jan_16_ENTRY_0, "jan_15", jan_15_ENTRY_1);
EvtScript N(EVS_ExitWalk_jan_22_1) = EVT_EXIT_WALK(60, jan_16_ENTRY_1, "jan_22", jan_22_ENTRY_1);
EvtScript N(EVS_ExitWalk_jan_17_0) = EVT_EXIT_WALK(60, jan_16_ENTRY_2, "jan_17", jan_17_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(Ref(N(EVS_ExitWalk_jan_15_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deiliw, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_jan_22_1)), TRIGGER_FLOOR_ABOVE, COLLIDER_deilie, 1, 0)
    BindTrigger(Ref(N(EVS_ExitWalk_jan_17_0)), TRIGGER_FLOOR_ABOVE, COLLIDER_o83, 1, 0)
    Return
    End
};

EvtScript N(EVS_SpawnButterflies) = {
    IfNe(GB_StoryProgress, STORY_CH5_RAPHAEL_LEFT_NEST)
        PlayEffect(EFFECT_BUTTERFLIES, 5, -310, 10, 0)
        PlayEffect(EFFECT_BUTTERFLIES, 5, -210, 10, 240)
        PlayEffect(EFFECT_BUTTERFLIES, 5, 330, 10, 260)
    EndIf
    PlayEffect(EFFECT_BUTTERFLIES, 5, -300, 10, 270)
    PlayEffect(EFFECT_BUTTERFLIES, 5, -80, 10, 390)
    PlayEffect(EFFECT_BUTTERFLIES, 5, 430, 10, 0)
    Return
    End
};

EvtScript N(EVS_AnimateFallBreakingBranch) = {
    Set(LVarF, 0)
    Loop(0)
        SetF(LVar0, MV_Unk_0A)
        SetF(LVar1, MV_Unk_0A)
        MulF(LVar0, Float(-0.02))
        MulF(LVar1, Float(0.04))
        AddF(LVar0, 1)
        AddF(LVar1, 1)
        Call(ScaleGroup, MODEL_g47, LVar0, LVar1, 1)
        Add(LVarF, 1)
        IfGe(LVarF, 600)
            Set(LVarF, 0)
        EndIf
        SetF(LVar0, LVarA)
        MulF(LVar0, Float(-0.046875))
        AddF(MV_Unk_0A, LVar0)
        MulF(MV_Unk_0A, Float(0.84375))
        AddF(LVarA, MV_Unk_0A)
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_EnterFalling) = {
    Exec(N(EVS_AnimateFallBreakingBranch))
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerActionState, ACTION_STATE_LAND)
    Call(DisablePartnerAI, 0)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, FALSE)
    Call(UseSettingsFrom, CAM_DEFAULT, 35, 100, 330)
    Call(SetPanTarget, CAM_DEFAULT, 35, 100, 330)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(WaitForCam, CAM_DEFAULT, Float(1.0))
    Call(GetPartnerInUse, LVar0)
    IfNe(LVar0, PARTNER_NONE)
        Call(InterruptUsePartner)
    EndIf
    Wait(15)
    Thread
        Wait(30)
        Call(SetPanTarget, CAM_DEFAULT, 35, 0, 330)
        Call(SetCamSpeed, CAM_DEFAULT, Float(0.8))
        Call(PanToTarget, CAM_DEFAULT, 0, 1)
    EndThread
    Call(DisablePlayerPhysics, FALSE)
    Call(SetNpcFlagBits, NPC_PARTNER, NPC_FLAG_GRAVITY, TRUE)
    Call(SetPlayerPos, 35, 600, 340)
    Call(MakeLerp, 600, 130, 15, EASING_LINEAR)
    Loop(0)
        Call(UpdateLerp)
        Call(SetPlayerPos, 35, LVar0, 340)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    PlayEffect(EFFECT_DROP_LEAVES, 0, 35, 120, 340, 100)
    PlayEffect(EFFECT_DROP_LEAVES, 0, 55, 120, 330, 100)
    AddF(MV_Unk_0A, Float(-7.5))
    Call(SetPanTarget, CAM_DEFAULT, 0, 190, 350)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.2))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Thread
        Call(SetPlayerJumpscale, Float(2.0))
        Call(PlaySoundAtPlayer, SOUND_SHAKE_TREE_LEAVES, SOUND_SPACE_DEFAULT)
        Call(PlayerJump, -35, 0, 385, 30)
        Call(SetPlayerActionState, ACTION_STATE_LAND)
    EndThread
    Call(SetNpcJumpscale, NPC_PARTNER, 0)
    Call(NpcJump0, NPC_PARTNER, 35, 130, 330, 15)
    Thread
        Loop(3)
            PlayEffect(EFFECT_DROP_LEAVES, 0, 35, 120, 340, 100)
            PlayEffect(EFFECT_DROP_LEAVES, 0, 55, 120, 340, 100)
            Wait(5)
        EndLoop
    EndThread
    AddF(MV_Unk_0A, Float(-7.5))
    Call(SetPanTarget, CAM_DEFAULT, -35, 0, 385)
    Call(SetCamSpeed, CAM_DEFAULT, Float(1.8))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Call(SetNpcJumpscale, NPC_PARTNER, Float(2.0))
    Call(NpcJump0, NPC_PARTNER, -10, 0, 395, 20)
    Call(EnablePartnerAI)
    Call(ResetCam, CAM_DEFAULT, Float(4.0))
    Call(DisablePlayerInput, FALSE)
    Return
    End
};

#include "world/common/atomic/ApplyTint.inc.c"

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_JADE_JUNGLE)
    Call(SetSpriteShading, SHADING_NONE)
    SetUP_CAMERA_ALT_NO_LEAD()
    Call(MakeNpcs, FALSE, Ref(N(DefaultNPCs)))
    ExecWait(N(EVS_MakeEntities))
    Exec(N(D_802412D4_B812D4))
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilitw, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_deilite, COLLIDER_FLAGS_UPPER_MASK)
    Call(GetEntryID, LVar0)
    IfEq(LVar0, jan_16_ENTRY_4)
        Exec(N(EVS_EnterFalling))
        Exec(N(EVS_BindExitTriggers))
    Else
        Set(LVar0, Ref(N(EVS_BindExitTriggers)))
        Exec(EnterWalk)
    EndIf
    ExecWait(N(EVS_SetupMusic))
    Exec(N(EVS_SetupBushes))
    Exec(N(EVS_SpawnButterflies))
    Call(N(SetModelTintMode), APPLY_TINT_MODELS, -1, 3)
    Call(N(SetModelTintMode), APPLY_TINT_BG, NULL, 3)
    Call(N(SetModelTintParams), ENV_TINT_REMAP, 255, 255, 255, 0, 0, 25, 0, 0, 0)
    Return
    End
};
