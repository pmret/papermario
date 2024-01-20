#include "hos_10.h"
#include "effects.h"
#include "sprite/player.h"

#define NAME_SUFFIX _PreTitle
#include "world/common/atomic/TexturePan.inc.c"
#define NAME_SUFFIX

EvtScript N(EVS_Scene_PreTitle) = {
    Call(DisablePlayerInput, TRUE)
    Call(DisablePlayerPhysics, TRUE)
    Call(SetPlayerAnimation, ANIM_Mario1_Hurt)
    Call(SetPlayerPos, NPC_DISPOSE_LOCATION)
    Call(EnableModel, MODEL_o2, FALSE)
    Call(EnableModel, MODEL_nagare, FALSE)
    Call(SetCamLeadPlayer, CAM_DEFAULT, FALSE)
    Call(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    Call(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    Call(SetCamSpeed, CAM_DEFAULT, Float(90.0))
    Call(PanToTarget, CAM_DEFAULT, 0, 1)
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_2)
        TEX_PAN_PARAMS_STEP(  400,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan_PreTitle))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP(  600,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan_PreTitle))
    EndThread
    Thread
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP( 1000,    0,    0,    0)
        TEX_PAN_PARAMS_FREQ(    1,    1,    1,    1)
        TEX_PAN_PARAMS_INIT(    0,    0,    0,    0)
        Exec(N(EVS_UpdateTexturePan_PreTitle))
    EndThread
    Call(EnableTexPanning, MODEL_k2, TRUE)
    Call(EnableTexPanning, MODEL_k7, TRUE)
    Call(EnableTexPanning, MODEL_k1, TRUE)
    Call(EnableTexPanning, MODEL_k5, TRUE)
    Call(EnableTexPanning, MODEL_k9, TRUE)
    Call(EnableTexPanning, MODEL_k12, TRUE)
    Thread
        SetF(LVar0, -1800)
        Loop(450 * DT)
            Call(TranslateModel, MODEL_o3, 0, LVar0, 0)
            AddF(LVar0, Float(1.5 / DT))
            Wait(1)
        EndLoop
    EndThread
    Thread
        SetF(LVar0, -1725)
        Loop(450 * DT)
            Call(TranslateGroup, MODEL_kumo, 0, LVar0, 0)
            AddF(LVar0, Float(2.5 / DT))
            Wait(1)
        EndLoop
    EndThread
    Thread
        Loop(0)
            Wait(1)
            Call(GetModelCenter, MODEL_mario_o)
            IfLt(LVar1, -130)
                BreakLoop
            EndIf
        EndLoop
        PlayEffect(EFFECT_LANDING_DUST, 4, 0, -130, 480, 0)
    EndThread
    Call(MakeLerp, 350, -200, 400 * DT, EASING_LINEAR)
    Set(LVar2, 0)
    Loop(0)
        Call(UpdateLerp)
        Call(TranslateModel, MODEL_mario_o, 0, LVar0, 480)
        Call(ScaleModel, MODEL_mario_o, Float(1.25), Float(1.25), Float(1.25))
        Call(RotateModel, MODEL_mario_o, LVar2, 1, 0, 0)
        Add(LVar2, Float(22.5))
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Call(GotoMapSpecial, Ref("kmr_21"), kmr_21_ENTRY_0, TRANSITION_SLOW_FADE_TO_WHITE)
    Wait(100 * DT)
    Return
    End
};
