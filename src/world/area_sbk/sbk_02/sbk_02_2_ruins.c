#include "sbk_02.h"
#include "effects.h"

#include "world/common/atomic/UnkFunc27.inc.c"

API_CALLABLE(N(func_80240338_92A5E8)) {
    EffectInstance* effect = (EffectInstance*)evt_get_variable(script, MapVar(0));
    
    effect->data.sun->targetAlpha = 0;
    return ApiStatus_DONE2;
}

API_CALLABLE(N(func_80240364_92A614)) {
    static u8 savedPrimR, savedPrimG, savedPrimB;
    static u8 savedEnvR, savedEnvG, savedEnvB;
    static s32 targetPrimR, targetPrimG, targetPrimB;
    static s32 targetEnvR, targetEnvG, targetEnvB;
    static s32 duration, elapsed;

    Bytecode* args = script->ptrReadPos;
    s32 blendPrimR, blendPrimG, blendPrimB;
    s32 blendEnvR, blendEnvG, blendEnvB;

    if (isInitialCall) {
        get_model_env_color_parameters(&savedPrimR, &savedPrimG, &savedPrimB, &savedEnvR, &savedEnvG, &savedEnvB);
        targetPrimR = evt_get_variable(script, *args++);
        targetPrimG = evt_get_variable(script, *args++);
        targetPrimB = evt_get_variable(script, *args++);
        targetEnvR = evt_get_variable(script, *args++);
        targetEnvG = evt_get_variable(script, *args++);
        targetEnvB = evt_get_variable(script, *args++);
        duration = evt_get_variable(script, *args++);
        elapsed = 0;
    }

    if (duration > 0) {
        elapsed++;
        blendPrimR = savedPrimR + ((targetPrimR - savedPrimR) * elapsed) / duration;
        blendPrimG = savedPrimG + ((targetPrimG - savedPrimG) * elapsed) / duration;
        blendPrimB = savedPrimB + ((targetPrimB - savedPrimB) * elapsed) / duration;
        blendEnvR = savedEnvR + ((targetEnvR - savedEnvR) * elapsed) / duration;
        blendEnvG = savedEnvG + ((targetEnvG - savedEnvG) * elapsed) / duration;
        blendEnvB = savedEnvB + ((targetEnvB - savedEnvB) * elapsed) / duration;

        set_model_env_color_parameters(blendPrimR, blendPrimG, blendPrimB, blendEnvR, blendEnvG, blendEnvB);
        if (elapsed >= duration) {
            return ApiStatus_DONE2;
        }
    } else {
        set_model_env_color_parameters(targetPrimR, targetPrimG, targetPrimB, targetEnvR, targetEnvG, targetEnvB);
        return ApiStatus_DONE2;
    }

    return ApiStatus_BLOCK;
}

s32 N(D_80241250_92B500)[] = {
    ITEM_PULSE_STONE,
    ITEM_NONE
};

EvtScript N(D_80241258_92B508) = {
    EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 0, 0, 0, 0, 20, 10, 0, 60, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, EFFECT_DUST, 2, 0, 0, 0, 60, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(PlaySoundAtCollider, COLLIDER_iwa, SOUND_5F, 0)
    EVT_SET(LVar2, 0)
    EVT_CALL(MakeLerp, 0, -50, 50, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_point_iwa, LVar2, 0, 1, 0)
        EVT_CALL(TranslateModel, MODEL_point_iwa, 0, LVar0, 0)
        EVT_SUB(LVar2, 10)
        EVT_ADDF(LVar3, EVT_FLOAT(0.2))
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(ModifyColliderFlags, 0, COLLIDER_iwa, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(EnableModel, MODEL_point_iwa, FALSE)
    EVT_CALL(PlaySound, SOUND_8000005F)
    EVT_RETURN
    EVT_END
};

s32 N(D_80241418_92B6C8)[] = {
    MODEL_ruins, MODEL_step, 0x0000FFFF
};

s32 N(D_80241424_92B6D4)[] = {
    MODEL_upper_light, MODEL_o225, 0x0000FFFF
};

EvtScript N(D_80241430_92B6E0) = {
    EVT_CALL(N(UnkFunc27), 2, 0, 3)
    EVT_CALL(N(UnkFunc27), 1, -1, 3)
    EVT_CALL(N(UnkFunc27), 1, EVT_PTR(N(D_80241418_92B6C8)), 0)
    EVT_CALL(N(UnkFunc27), 0, EVT_PTR(N(D_80241424_92B6D4)), 0)
    EVT_CALL(N(func_80240364_92A614), 255, 255, 255, 0, 0, 0, 0)
    EVT_WAIT(1)
    EVT_CALL(N(func_80240364_92A614), 44, 32, 177, 0, 0, 0, 60)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802414FC_92B7AC) = {
    EVT_CALL(SetRenderMode, MODEL_o225, RENDER_MODE_SURFACE_XLU_LAYER2)
    EVT_CALL(EnableTexPanning, MODEL_o225, TRUE)
    EVT_CALL(EnableTexPanning, 0x00002710, TRUE)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_LOOP(0)
        EVT_CALL(SetTexPanOffset, 3, 0, LVar0, 0)
        EVT_CALL(SetTexPanOffset, 3, 1, LVar1, LVar2)
        EVT_ADD(LVar0, 0x00001770)
        EVT_ADD(LVar1, 0x00001388)
        EVT_ADD(LVar2, 0x00000FA0)
        EVT_IF_GT(LVar0, 0x00020000)
            EVT_SUB(LVar0, 0x00020000)
        EVT_END_IF
        EVT_IF_GT(LVar1, 0x00020000)
            EVT_SUB(LVar1, 0x00020000)
        EVT_END_IF
        EVT_IF_GT(LVar2, 0x00020000)
            EVT_SUB(LVar2, 0x00020000)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80241678_92B928) = {
    EVT_CALL(EnableModel, MODEL_o225, TRUE)
    EVT_SET(LVar2, 0)
    EVT_SET(LVar0, -100)
    EVT_LOOP(100)
        EVT_SET(LVar3, LVar2)
        EVT_DIVF(LVar3, 80)
        EVT_CALL(ScaleModel, MODEL_o225, LVar3, EVT_FLOAT(1.0), LVar3)
        EVT_CALL(TranslateModel, MODEL_o225, 0, LVar0, 0)
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(ScaleModel, MODEL_o225, LVar3, EVT_FLOAT(1.0), LVar3)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80241790_92BA40) = {
    EVT_WAIT(10)
    EVT_CALL(EnableModel, 0x00002710, TRUE)
    EVT_SET(LVar2, 0)
    EVT_SET(LVar0, -100)
    EVT_LOOP(100)
        EVT_SET(LVar3, LVar2)
        EVT_DIVF(LVar3, 110)
        EVT_CALL(ScaleModel, 0x00002710, LVar3, EVT_FLOAT(1.0), LVar3)
        EVT_CALL(TranslateModel, 0x00002710, 0, LVar0, 0)
        EVT_ADD(LVar0, 1)
        EVT_ADD(LVar2, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_CALL(ScaleModel, 0x00002710, LVar3, EVT_FLOAT(1.0), LVar3)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802418B4_92BB64) = {
    EVT_CALL(EnableModel, MODEL_o225, TRUE)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar2, 100)
    EVT_SETF(LVar3, EVT_FLOAT(1.25))
    EVT_LOOP(20)
        EVT_CALL(ScaleModel, MODEL_o225, LVar3, EVT_FLOAT(1.0), LVar3)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(70)
        EVT_SET(LVar3, LVar2)
        EVT_DIVF(LVar3, 80)
        EVT_CALL(ScaleModel, MODEL_o225, LVar3, LVar3, LVar3)
        EVT_CALL(TranslateModel, MODEL_o225, 0, LVar0, 0)
        EVT_SUB(LVar0, 2)
        EVT_ADD(LVar2, 5)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EnableModel, MODEL_o225, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802419F0_92BCA0) = {
    EVT_WAIT(10)
    EVT_CALL(EnableModel, 0x00002710, TRUE)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar2, 100)
    EVT_SETF(LVar3, EVT_FLOAT(0.91))
    EVT_LOOP(20)
        EVT_CALL(ScaleModel, 0x00002710, LVar3, EVT_FLOAT(1.0), LVar3)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(70)
        EVT_SET(LVar3, LVar2)
        EVT_DIVF(LVar3, 110)
        EVT_CALL(ScaleModel, 0x00002710, LVar3, LVar3, LVar3)
        EVT_CALL(TranslateModel, 0x00002710, 0, LVar0, 0)
        EVT_SUB(LVar0, 2)
        EVT_ADD(LVar2, 5)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EnableModel, 0x00002710, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80241B38_92BDE8) = {
    EVT_CHILD_THREAD
        EVT_CALL(EnableTexPanning, MODEL_upper_light, TRUE)
        EVT_SET(LVar0, 0)
        EVT_LOOP(0)
            EVT_CALL(SetTexPanOffset, 1, 0, LVar0, 0)
            EVT_ADD(LVar0, 0x000009C4)
            EVT_IF_GT(LVar0, 0x00008000)
                EVT_SUB(LVar0, 0x00008000)
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(EnableModel, MODEL_upper_light, TRUE)
    EVT_SET(LVar0, -200)
    EVT_SET(LVar1, 0)
    EVT_LOOP(200)
        EVT_CALL(TranslateModel, MODEL_upper_light, 0, LVar0, 0)
        EVT_ADD(LVar0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LOOP(0)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80241C90_92BF40) = {
    EVT_CHILD_THREAD
        EVT_CALL(EnableTexPanning, MODEL_upper_light, TRUE)
        EVT_SET(LVar0, 0)
        EVT_LOOP(0)
            EVT_CALL(SetTexPanOffset, 1, 0, LVar0, 0)
            EVT_ADD(LVar0, 0x000009C4)
            EVT_IF_GT(LVar0, 0x00008000)
                EVT_SUB(LVar0, 0x00008000)
            EVT_END_IF
            EVT_WAIT(1)
        EVT_END_LOOP
    EVT_END_CHILD_THREAD
    EVT_CALL(EnableModel, MODEL_upper_light, TRUE)
    EVT_SET(LVar0, 0)
    EVT_CALL(TranslateModel, MODEL_upper_light, 0, LVar0, 0)
    EVT_WAIT(10)
    EVT_LOOP(100)
        EVT_CALL(TranslateModel, MODEL_upper_light, 0, LVar0, 0)
        EVT_SUB(LVar0, 2)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80241DE0_92C090) = {
    EVT_CALL(MakeTransformGroup, MODEL_ruins)
    EVT_CALL(EnableGroup, MODEL_ruins, TRUE)
    EVT_THREAD
        EVT_CALL(EnableTexPanning, MODEL_o232, TRUE)
        EVT_SET(LVar0, 0)
        EVT_SET(LVar1, 0)
        EVT_SET(LVar2, 0)
        EVT_LOOP(600)
            EVT_CALL(SetTexPanOffset, 2, 0, 0, LVar0)
            EVT_CALL(SetTexPanOffset, 2, 1, LVar1, LVar2)
            EVT_ADD(LVar0, 200)
            EVT_ADD(LVar1, -200)
            EVT_ADD(LVar2, 700)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(EnableModel, MODEL_o232, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20)
        EVT_LOOP(30)
            EVT_CALL(RandInt, 290, LVar0)
            EVT_ADD(LVar0, -110)
            EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 0, LVar0, 0, -35, 20, 10, 0, 60, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, EFFECT_DUST, 2, LVar0, 0, -35, 60, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(20)
        EVT_LOOP(15)
            EVT_CALL(RandInt, 180, LVar0)
            EVT_ADD(LVar0, 170)
            EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 0, LVar0, 0, -300, 20, 10, 0, 60, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, EFFECT_DUST, 2, LVar0, 0, -300, 60, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(20)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(100)
        EVT_LOOP(5)
            EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 0, -180, 0, 260, 20, 10, 0, 60, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, EFFECT_DUST, 2, -180, 0, 260, 60, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(40)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(110)
        EVT_LOOP(4)
            EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 0, 180, 0, 260, 20, 10, 0, 60, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, EFFECT_DUST, 2, 180, 0, 260, 60, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(50)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(PlaySound, SOUND_8000005E)
    EVT_CALL(MakeLerp, -310, 0, 310, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_ruins, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802422F0_92C5A0) = {
    EVT_CALL(MakeTransformGroup, MODEL_ruins)
    EVT_CALL(EnableGroup, MODEL_ruins, TRUE)
    EVT_THREAD
        EVT_CALL(EnableTexPanning, MODEL_o232, TRUE)
        EVT_SET(LVar0, 0x0000EA60)
        EVT_SET(LVar1, 0xFFFF15A0)
        EVT_SET(LVar2, 0x00033450)
        EVT_LOOP(300)
            EVT_CALL(SetTexPanOffset, 2, 0, 0, LVar0)
            EVT_CALL(SetTexPanOffset, 2, 1, LVar1, LVar2)
            EVT_ADD(LVar0, 200)
            EVT_ADD(LVar1, -200)
            EVT_ADD(LVar2, 700)
            EVT_WAIT(1)
        EVT_END_LOOP
        EVT_CALL(EnableModel, MODEL_o232, FALSE)
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(10)
            EVT_CALL(RandInt, 290, LVar0)
            EVT_ADD(LVar0, -110)
            EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 0, LVar0, 0, -35, 20, 10, 0, 60, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, EFFECT_DUST, 2, LVar0, 0, -35, 60, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(10)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_LOOP(5)
            EVT_CALL(RandInt, 180, LVar0)
            EVT_ADD(LVar0, 170)
            EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 0, LVar0, 0, -300, 20, 10, 0, 60, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, EFFECT_DUST, 2, LVar0, 0, -300, 60, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(20)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_LOOP(3)
            EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 0, -180, 0, 260, 20, 10, 0, 60, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, EFFECT_DUST, 2, -180, 0, 260, 60, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(40)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_THREAD
        EVT_WAIT(10)
        EVT_LOOP(2)
            EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 0, 180, 0, 260, 20, 10, 0, 60, 0, 0, 0, 0, 0)
            EVT_CALL(PlayEffect, EFFECT_DUST, 2, 180, 0, 260, 60, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_WAIT(50)
        EVT_END_LOOP
    EVT_END_THREAD
    EVT_CALL(MakeLerp, -20, 0, 20, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_ruins, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 10, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802427F4_92CAA4) = {
    EVT_CALL(RotateGroup, MODEL_c_wang, LVar0, 0, 1, 0)
    EVT_CALL(RotateGroup, MODEL_d_wang, LVar0, 0, 1, 0)
    EVT_SET(LVar2, 0)
    EVT_SUB(LVar2, LVar0)
    EVT_CALL(RotateGroup, MODEL_a_wang, LVar2, 0, 1, 0)
    EVT_CALL(RotateGroup, MODEL_b_wang, LVar2, 0, 1, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802428A4_92CB54) = {
    EVT_CALL(MakeLerp, 180, 0, 60, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_EXEC_WAIT(N(D_802427F4_92CAA4))
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80242928_92CBD8) = {
    EVT_CALL(MakeLerp, 0, 60, 180, EASING_QUADRATIC_IN)
    EVT_LABEL(10)
    EVT_CALL(UpdateLerp)
    EVT_CALL(RotateModel, MODEL_o168, LVar0, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o177, LVar0, 0, 1, 0)
    EVT_CALL(TranslateModel, MODEL_o169, -20, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o178, -20, 0, 0)
    EVT_CALL(RotateModel, MODEL_o169, LVar0, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o178, LVar0, 0, 1, 0)
    EVT_CALL(TranslateModel, MODEL_o169, 20, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o178, 20, 0, 0)
    EVT_CALL(RotateModel, MODEL_o130, LVar0, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o176, LVar0, 0, 1, 0)
    EVT_CALL(TranslateModel, MODEL_o175, -20, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o129, -20, 0, 0)
    EVT_CALL(RotateModel, MODEL_o175, LVar0, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o129, LVar0, 0, 1, 0)
    EVT_CALL(TranslateModel, MODEL_o175, 20, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o129, 20, 0, 0)
    EVT_SET(LVar2, 0)
    EVT_SUB(LVar2, LVar0)
    EVT_CALL(RotateModel, MODEL_o141, LVar2, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o174, LVar2, 0, 1, 0)
    EVT_CALL(TranslateModel, MODEL_o140, 20, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o173, 20, 0, 0)
    EVT_CALL(RotateModel, MODEL_o140, LVar2, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o173, LVar2, 0, 1, 0)
    EVT_CALL(TranslateModel, MODEL_o140, -20, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o173, -20, 0, 0)
    EVT_CALL(RotateModel, MODEL_o157, LVar2, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o171, LVar2, 0, 1, 0)
    EVT_CALL(TranslateModel, MODEL_o158, 20, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o172, 20, 0, 0)
    EVT_CALL(RotateModel, MODEL_o158, LVar2, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o172, LVar2, 0, 1, 0)
    EVT_CALL(TranslateModel, MODEL_o158, -20, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o172, -20, 0, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(10)
    EVT_END_IF
    EVT_CALL(MakeLerp, 0, 60, 180, EASING_QUADRATIC_OUT)
    EVT_LABEL(20)
    EVT_CALL(UpdateLerp)
    EVT_CALL(TranslateModel, MODEL_o169, -20, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o178, -20, 0, 0)
    EVT_CALL(RotateModel, MODEL_o169, 60, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o178, 60, 0, 1, 0)
    EVT_CALL(TranslateModel, MODEL_o169, 20, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o178, 20, 0, 0)
    EVT_CALL(RotateModel, MODEL_o169, LVar0, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o178, LVar0, 0, 1, 0)
    EVT_CALL(TranslateModel, MODEL_o175, -20, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o129, -20, 0, 0)
    EVT_CALL(RotateModel, MODEL_o175, 60, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o129, 60, 0, 1, 0)
    EVT_CALL(TranslateModel, MODEL_o175, 20, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o129, 20, 0, 0)
    EVT_CALL(RotateModel, MODEL_o175, LVar0, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o129, LVar0, 0, 1, 0)
    EVT_SET(LVar2, 0)
    EVT_SUB(LVar2, LVar0)
    EVT_CALL(TranslateModel, MODEL_o140, 20, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o173, 20, 0, 0)
    EVT_CALL(RotateModel, MODEL_o140, -60, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o173, -60, 0, 1, 0)
    EVT_CALL(TranslateModel, MODEL_o140, -20, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o173, -20, 0, 0)
    EVT_CALL(RotateModel, MODEL_o140, LVar2, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o173, LVar2, 0, 1, 0)
    EVT_CALL(TranslateModel, MODEL_o158, 20, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o172, 20, 0, 0)
    EVT_CALL(RotateModel, MODEL_o158, -60, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o172, -60, 0, 1, 0)
    EVT_CALL(TranslateModel, MODEL_o158, -20, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o172, -20, 0, 0)
    EVT_CALL(RotateModel, MODEL_o158, LVar2, 0, 1, 0)
    EVT_CALL(RotateModel, MODEL_o172, LVar2, 0, 1, 0)
    EVT_WAIT(1)
    EVT_IF_EQ(LVar1, 1)
        EVT_GOTO(20)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(D_802431C0_92D470) = {
    EVT_CALL(EnableGroup, MODEL_step, TRUE)
    EVT_CALL(MakeLerp, -310, 0, 310, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_step, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243268_92D518) = {
    EVT_CALL(EnableGroup, MODEL_step, TRUE)
    EVT_CALL(MakeLerp, -20, 0, 20, EASING_LINEAR)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(TranslateGroup, MODEL_step, 0, LVar0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(D_80243310_92D5C0) = {
    EVT_CALL(PlaySoundAt, SOUND_5E, 0, 0, 39, -80)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_CALL(MakeLerp, 0, -180, 180, EASING_QUADRATIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_CALL(RotateModel, MODEL_o106, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o107, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o100, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o105, LVar0, 1, 0, 0)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 0, 61, 2, -83, 20, 10, 0, 60, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, EFFECT_DUST, 2, 61, 2, -83, 60, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_WAIT(3)
    EVT_CALL(PlayEffect, EFFECT_SMOKE_IMPACT, 0, -61, 2, -83, 20, 10, 0, 60, 0, 0, 0, 0, 0)
    EVT_CALL(PlayEffect, EFFECT_DUST, 2, -61, 2, -83, 60, 0, 0, 0, 0, 0, 0, 0, 0)
    EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 5, EVT_FLOAT(1.0))
    EVT_RETURN
    EVT_END
};

EvtScript N(D_8024358C_92D83C) = {
    EVT_CALL(DisablePulseStone, TRUE)
    EVT_CALL(ShowKeyChoicePopup)
    EVT_IF_LE(LVar0, 0)
        EVT_CALL(CloseChoicePopup)
        EVT_CALL(DisablePulseStone, FALSE)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(func_802CF56C, 1)
    EVT_CALL(RemoveKeyItemAt, LVar1)
    EVT_CALL(CloseChoicePopup)
    EVT_SET(GB_StoryProgress, STORY_CH2_UNCOVERED_DRY_DRY_RUINS)
    EVT_CALL(N(func_80240338_92A5E8))
    EVT_CALL(SetMusicTrack, 0, SONG_DRY_DRY_RUINS_APPEAR, 1, 8)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 210, 0, 137)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(150.0), EVT_FLOAT(500.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(-450.0), EVT_FLOAT(-500.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(15.0), EVT_FLOAT(-7.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(500.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.2))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(10)
    EVT_SET(LVar0, 180)
    EVT_EXEC_WAIT(N(D_802427F4_92CAA4))
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 120, EVT_FLOAT(0.2))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 300, EVT_FLOAT(0.5))
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 300, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_EXEC(N(D_80241258_92B508))
    EVT_WAIT(30)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar0, 0)
        EVT_SET(LVar0, -80)
        EVT_SET(LocalFlag(0), FALSE)
    EVT_ELSE
        EVT_SET(LVar0, 80)
        EVT_SET(LocalFlag(0), TRUE)
    EVT_END_IF
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(SetPlayerSpeed, EVT_FLOAT(3.0))
        EVT_CALL(PlayerMoveTo, LVar0, 80, 0)
        EVT_CALL(func_802D2884, 0, 0, 0)
    EVT_END_THREAD
    EVT_EXEC(N(D_80241430_92B6E0))
    EVT_WAIT(30)
    EVT_CALL(CloneModel, MODEL_o225, 0x00002710)
    EVT_EXEC(N(D_802414FC_92B7AC))
    EVT_EXEC(N(D_80241678_92B928))
    EVT_EXEC(N(D_80241790_92BA40))
    EVT_WAIT(100)
    EVT_EXEC(N(D_80241B38_92BDE8))
    EVT_WAIT(150)
    EVT_EXEC(N(D_80241DE0_92C090))
    EVT_EXEC(N(D_802431C0_92D470))
    EVT_WAIT(100)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(8.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.2))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(80)
    EVT_EXEC(N(D_802428A4_92CB54))
    EVT_WAIT(60)
    EVT_WAIT(50)
    EVT_IF_EQ(LocalFlag(0), FALSE)
        EVT_CALL(GotoMap, EVT_PTR("sbk_30"), sbk_30_ENTRY_4)
    EVT_ELSE
        EVT_CALL(GotoMap, EVT_PTR("sbk_30"), sbk_30_ENTRY_5)
    EVT_END_IF
    EVT_WAIT(100)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80243A00) = {
    EVT_SWITCH(GB_StoryProgress)
        EVT_CASE_LT(STORY_CH2_GOT_PULSE_STONE)
            EVT_CALL(EnableGroup, MODEL_day_version, FALSE)
            EVT_CALL(ModifyColliderFlags, 0, COLLIDER_ruin, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CASE_LT(STORY_CH2_UNCOVERED_DRY_DRY_RUINS)
            EVT_CALL(EnableGroup, MODEL_day_version, FALSE)
            EVT_CALL(ModifyColliderFlags, 0, COLLIDER_ruin, COLLIDER_FLAGS_UPPER_MASK)
            EVT_BIND_PADLOCK(EVT_PTR(N(D_8024358C_92D83C)), TRIGGER_WALL_PRESS_A, COLLIDER_iwa, EVT_PTR(N(D_80241250_92B500)), 0, 1)
        EVT_CASE_DEFAULT
            EVT_CALL(EnableModel, MODEL_point_iwa, FALSE)
            EVT_CALL(ModifyColliderFlags, 0, COLLIDER_pikapika, COLLIDER_FLAGS_UPPER_MASK)
    EVT_END_SWITCH
    EVT_CALL(EnableGroup, MODEL_ruins, FALSE)
    EVT_CALL(EnableGroup, MODEL_step, FALSE)
    EVT_CALL(EnableModel, MODEL_upper_light, FALSE)
    EVT_CALL(EnableModel, MODEL_o225, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_80243B38) = {
    EVT_CALL(PlaySound, SOUND_5C)
    EVT_CALL(DisablePlayerInput, TRUE)
    EVT_CALL(func_802CF56C, 1)
    EVT_CALL(func_802D2884, 0, 0, 0)
    EVT_CALL(ModifyColliderFlags, 0, COLLIDER_iwa, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(EnableModel, MODEL_point_iwa, FALSE)
    EVT_CALL(EnableGroup, MODEL_day_version, FALSE)
    EVT_THREAD
        EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 400, EVT_FLOAT(0.2))
    EVT_END_THREAD
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 210, 0, 137)
    EVT_CALL(SetCamPosA, CAM_DEFAULT, EVT_FLOAT(150.0), EVT_FLOAT(500.0))
    EVT_CALL(SetCamPosB, CAM_DEFAULT, EVT_FLOAT(-450.0), EVT_FLOAT(-500.0))
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(8.0), EVT_FLOAT(-9.0))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(500.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_CALL(N(UnkFunc27), 2, 0, 3)
    EVT_CALL(N(UnkFunc27), 1, -1, 3)
    EVT_CALL(N(UnkFunc27), 1, EVT_PTR(N(D_80241418_92B6C8)), 0)
    EVT_CALL(N(UnkFunc27), 0, EVT_PTR(N(D_80241424_92B6D4)), 0)
    EVT_CALL(N(func_80240364_92A614), 44, 32, 177, 0, 0, 0, 0)
    EVT_EXEC(N(D_802422F0_92C5A0))
    EVT_EXEC(N(D_80243268_92D518))
    EVT_CALL(CloneModel, MODEL_o225, 0x00002710)
    EVT_EXEC(N(D_802414FC_92B7AC))
    EVT_EXEC(N(D_802418B4_92BB64))
    EVT_EXEC(N(D_802419F0_92BCA0))
    EVT_WAIT(20)
    EVT_EXEC(N(D_80241C90_92BF40))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamPitch, CAM_DEFAULT, EVT_FLOAT(4.0), EVT_FLOAT(-6.5))
    EVT_CALL(SetCamDistance, CAM_DEFAULT, EVT_FLOAT(790.0))
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(0.2))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
    EVT_WAIT(100)
    EVT_EXEC(N(D_80242928_92CBD8))
    EVT_WAIT(100)
    EVT_EXEC_WAIT(N(D_80243310_92D5C0))
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_CLEAR_BITS, COLLIDER_ruin, COLLIDER_FLAGS_UPPER_MASK)
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_WAIT(60)
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_CALL(UseSettingsFrom, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetPanTarget, CAM_DEFAULT, LVar0, LVar1, LVar2)
    EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(90.0))
    EVT_CALL(WaitForCam, CAM_DEFAULT, EVT_FLOAT(1.0))
    EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 0)
    EVT_CALL(func_802CF56C, 0)
    EVT_CALL(DisablePlayerInput, FALSE)
    EVT_RETURN
    EVT_END
};
