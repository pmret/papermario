#include "kzn_20.h"
#include "effects.h"

#include "world/common/atomic/TexturePan.inc.c"

EvtScript N(EVS_ExitWalk_kzn_19_2) = EVT_EXIT_WALK(60, kzn_20_ENTRY_0, "kzn_19", kzn_19_ENTRY_2);
EvtScript N(EVS_ExitWalk_kzn_22_0) = EVT_EXIT_WALK(60, kzn_20_ENTRY_1, "kzn_22", kzn_22_ENTRY_0);

EvtScript N(EVS_BindExitTriggers) = {
    BindTrigger(N(EVS_ExitWalk_kzn_19_2), TRIGGER_FLOOR_ABOVE, COLLIDER_deili1, 1, 0)
    BindTrigger(N(EVS_ExitWalk_kzn_22_0), TRIGGER_FLOOR_ABOVE, COLLIDER_deili2, 1, 0)
    Return
    End
};

EvtScript N(EVS_UpdateTexPan_Lava) = {
    SetGroup(EVT_GROUP_00)
    Call(EnableTexPanning, MODEL_yu, TRUE)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_1)
        TEX_PAN_PARAMS_STEP( -700,  700,  200, -300)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan))
    EndThread
    Return
    End
};

LavaReset N(SafeFloorColliders)[] = {
    { .colliderID = COLLIDER_o919, .pos = { -30.0, 125.0, -15.0 }},
    { .colliderID = COLLIDER_o870, .pos = {  30.0, 150.0,   0.0 }},
    { .colliderID = NO_COLLIDER }
};

EvtScript N(EVS_DetermineLavaLevel) = {
    Loop(0)
        IfGe(GB_StoryProgress, STORY_CH5_OPENED_ESCAPE_ROUTE)
            Label(1)
                IfLt(MV_LavaPosOffset, 110)
                    SubF(MV_WaveScaleOffset, Float(0.01))
                    AddF(MV_PosScaleCoeff, Float(0.01))
                    Loop(5)
                        AddF(MV_LavaPosOffset, Float(0.75))
                        Wait(9)
                    EndLoop
                Else
                    BreakLoop
                EndIf
                Goto(1)
        EndIf
        Wait(1)
    EndLoop
    Return
    End
};

EvtScript N(EVS_InterruptPartnersInLava) = {
    Loop(0)
        Loop(0)
            Wait(1)
            Call(GetModelCenter, MODEL_yu)
            Call(GetPlayerPos, LVar0, LVar3, LVar2)
            IfLt(LVar3, LVar1)
                BreakLoop
            EndIf
        EndLoop
        Call(GetCurrentPartnerID, LVar1)
        IfNe(LVar1, PARTNER_LAKILESTER)
            Call(InterruptUsePartner)
            Call(SetPlayerActionState, ACTION_STATE_HIT_LAVA)
            Wait(30)
        EndIf
    EndLoop
    Return
    End
};

EvtScript N(EVS_UpdateLavaWaves) = {
    SetGroup(EVT_GROUP_EF)
    Call(EnableModel, MODEL_yu, FALSE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_yu, COLLIDER_FLAGS_UPPER_MASK)
    Call(ParentColliderToModel, COLLIDER_yu, MODEL_yu)
    Label(0)
        IfEq(AF_KZN_RumblingIntensified, FALSE)
            Wait(1)
            Goto(0)
        EndIf
    Call(EnableModel, MODEL_yu, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS,  COLLIDER_yu, COLLIDER_FLAGS_UPPER_MASK)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_SURFACE, COLLIDER_yu, SURFACE_TYPE_LAVA)
    Thread
        Call(ResetFromLava, Ref(N(SafeFloorColliders)))
    EndThread
    IfLt(GB_StoryProgress, STORY_CH5_OPENED_ESCAPE_ROUTE)
        SetF(MV_LavaPosOffset, 35)
        SetF(MV_WaveScaleOffset, Float(1.2))
        SetF(MV_PosScaleCoeff, Float(-1.2))
    Else
        SetF(MV_LavaPosOffset, 110)
        SetF(MV_WaveScaleOffset, Float(1.0))
        SetF(MV_PosScaleCoeff, Float(-1.0))
    EndIf
    Exec(N(EVS_DetermineLavaLevel))
    Exec(N(EVS_InterruptPartnersInLava))
    Loop(0)
        Call(MakeLerp, 0, 260, 30, EASING_COS_IN)
        Loop(0)
            Call(UpdateLerp)
            DivF(LVar0, Float(100.0))
            SubF(LVar0, MV_WaveScaleOffset)
            SetF(LVar3, MV_LavaPosOffset)
            SetF(LVar4, MV_LavaPosOffset)
            DivF(LVar3, MV_PosScaleCoeff)
            MulF(LVar3, LVar0)
            AddF(LVar4, LVar3) // = PosOffset + Scale * (PosOffset / PosScaleCoeff)
            Call(TranslateModel, MODEL_yu, 0, LVar4, 0)
            Call(ScaleModel, MODEL_yu, 1, LVar0, 1)
            Call(TranslateModel, MODEL_yu, 0, MV_LavaPosOffset, 0)
            Call(UpdateColliderTransform, COLLIDER_yu)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
        Call(MakeLerp, 260, 0, 60, EASING_SIN_OUT)
        Loop(0)
            Call(UpdateLerp)
            DivF(LVar0, Float(100.0))
            SubF(LVar0, MV_WaveScaleOffset)
            SetF(LVar3, MV_LavaPosOffset)
            SetF(LVar4, MV_LavaPosOffset)
            DivF(LVar3, MV_PosScaleCoeff)
            MulF(LVar3, LVar0)
            AddF(LVar4, LVar3)
            Call(TranslateModel, MODEL_yu, 0, LVar4, 0)
            Call(ScaleModel, MODEL_yu, 1, LVar0, 1)
            Call(TranslateModel, MODEL_yu, 0, MV_LavaPosOffset, 0)
            Call(UpdateColliderTransform, COLLIDER_yu)
            Wait(1)
            IfEq(LVar1, 0)
                BreakLoop
            EndIf
        EndLoop
    EndLoop
    Return
    End
};

BombTrigger N(WeakWallBombTrigger) = {
    .pos = { 175.0, 150.0, 15.0 },
    .diameter = 0.0
};

EvtScript N(EVS_OnBreakWall) = {
    PlayEffect(EFFECT_BOMBETTE_BREAKING, 0, 2, 2, 1, 10, 30)
    Call(EnableGroup, MODEL_bom_mae, FALSE)
    Call(EnableGroup, MODEL_bom_ato, TRUE)
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    Set(GB_StoryProgress, STORY_CH5_OPENED_ESCAPE_ROUTE)
    Unbind
    Return
    End
};

EvtScript N(EVS_Main) = {
    Set(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    Call(SetSpriteShading, SHADING_KZN_20)
    SetUP_CAMERA_NO_LEAD()
    Call(MakeNpcs, TRUE, Ref(N(DefaultNPCs)))
    Set(LVar0, N(EVS_BindExitTriggers))
    Exec(EnterWalk)
    Wait(1)
    Exec(N(EVS_ShakingWorld))
    IfLt(GB_StoryProgress, STORY_CH5_OPENED_ESCAPE_ROUTE)
        Call(EnableGroup, MODEL_bom_ato, FALSE)
        BindTrigger(N(EVS_OnBreakWall), TRIGGER_POINT_BOMB, Ref(N(WeakWallBombTrigger)), 1, 0)
    Else
        Call(EnableGroup, MODEL_bom_mae, FALSE)
        Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_tt1, COLLIDER_FLAGS_UPPER_MASK)
    EndIf
    Exec(N(EVS_SetupMusic))
    Exec(N(EVS_UpdateLavaWaves))
    Exec(N(EVS_UpdateTexPan_Lava))
    Return
    End
};
