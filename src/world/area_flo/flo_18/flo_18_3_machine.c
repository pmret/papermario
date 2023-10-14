#include "flo_18.h"
#include "effects.h"

enum {
    DAMAGE_PART_LEFT_SIDE,
    DAMAGE_PART_RIGHT_SIDE,
    DAMAGE_PART_PROTRUSTIONS,
    DAMAGE_PART_LEVER,
    DAMAGE_PART_SMOKE_STACK,
};

API_CALLABLE(N(SetMachineLightningColor)) {
    EffectInstance* effect = (EffectInstance*) script->varTable[15];

    effect->data.lightningBolt->outerColor.r = 69;
    effect->data.lightningBolt->outerColor.g = 255;
    effect->data.lightningBolt->outerColor.b = 217;
    effect->data.lightningBolt->innerColor.r = 176;
    effect->data.lightningBolt->innerColor.g = 254;
    effect->data.lightningBolt->innerColor.b = 124;
    return ApiStatus_DONE2;
}

EvtScript N(EVS_AnimateMachineLightning) = {
    EVT_SET_GROUP(EVT_GROUP_0B)
    EVT_LOOP(0)
        EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, EVT_FLOAT(-16.0), EVT_FLOAT(102.0), EVT_FLOAT(-4.1), EVT_FLOAT(80.9), EVT_FLOAT(102.0), EVT_FLOAT(-4.1), EVT_FLOAT(0.5), 6)
        EVT_CALL(N(SetMachineLightningColor))
        EVT_WAIT(4)
        EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, EVT_FLOAT(80.9), EVT_FLOAT(102.0), EVT_FLOAT(-4.1), EVT_FLOAT(-16.0), EVT_FLOAT(102.0), EVT_FLOAT(-4.1), EVT_FLOAT(0.5), 6)
        EVT_CALL(N(SetMachineLightningColor))
        EVT_WAIT(4)
        EVT_IF_GE(GB_FLO18_MachineDamage_Right, 3)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_SET(LVar0, 6)
    EVT_LOOP(5)
        EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, EVT_FLOAT(-16.0), EVT_FLOAT(102.0), EVT_FLOAT(-4.1), EVT_FLOAT(80.9), EVT_FLOAT(102.0), EVT_FLOAT(-4.1), EVT_FLOAT(0.5), 6)
        EVT_CALL(N(SetMachineLightningColor))
        EVT_WAIT(LVar0)
        EVT_ADD(LVar0, 2)
        EVT_PLAY_EFFECT(EFFECT_LIGHTNING_BOLT, 0, EVT_FLOAT(80.9), EVT_FLOAT(102.0), EVT_FLOAT(-4.1), EVT_FLOAT(-16.0), EVT_FLOAT(102.0), EVT_FLOAT(-4.1), EVT_FLOAT(0.5), 6)
        EVT_CALL(N(SetMachineLightningColor))
        EVT_WAIT(LVar0)
        EVT_ADD(LVar0, 2)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

#include "common/CosInterpMinMax.inc.c"

EvtScript N(EVS_UpdateSmokeParticle) = {
    EVT_CALL(EnableModel, LVarF, TRUE)
    EVT_SET(LVarE, 159)
    EVT_LOOP(LVarE)
        EVT_ADDF(LVar3, 0)
        EVT_ADDF(LVar4, EVT_FLOAT(0.0))
        EVT_SETF(LVar5, EVT_FLOAT(0.01))
        EVT_ADDF(LVar0, LVar3)
        EVT_ADDF(LVar1, LVar4)
        EVT_ADDF(LVar2, LVar5)
        EVT_MULF(LVar6, EVT_FLOAT(1.01))
        EVT_ADDF(LVar7, EVT_FLOAT(0.01))
        EVT_SETF(LVar8, LVar6)
        EVT_CALL(N(CosInterpMinMax), LVarE, LVarA, EVT_FLOAT(0.0), EVT_FLOAT(0.203), 15, 0, 0)
        EVT_ADDF(LVar8, LVarA)
        EVT_SETF(LVar9, LVar7)
        EVT_CALL(N(CosInterpMinMax), LVarE, LVarA, EVT_FLOAT(0.0), EVT_FLOAT(0.203), 20, 0, 90)
        EVT_ADDF(LVar9, LVarA)
        EVT_SETF(LVarA, LVar0)
        EVT_MULF(LVarA, EVT_FLOAT(10.0))
        EVT_CALL(TranslateModel, LVarF, LVar0, LVar1, LVar2)
        EVT_CALL(ScaleModel, LVarF, LVar8, LVar9, 1)
        EVT_CALL(RotateModel, LVarF, LVarA, 0, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_CALL(EnableModel, LVarF, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ManageSmoke) = {
    EVT_SET(LVarE, 0)
    EVT_LABEL(0)
        EVT_IF_GE(GB_FLO18_MachineDamage_Right, 3)
            EVT_RETURN
        EVT_END_IF
        EVT_SETF(LVar0, EVT_FLOAT(132.0))
        EVT_SETF(LVar1, EVT_FLOAT(90.0))
        EVT_SETF(LVar2, EVT_FLOAT(-30.0))
        EVT_CALL(RandInt, 100, LVar3)
        EVT_ADDF(LVar3, -50)
        EVT_DIVF(LVar3, EVT_FLOAT(200.0))
        EVT_SETF(LVar4, EVT_FLOAT(1.0))
        EVT_SETF(LVar5, 0)
        EVT_SETF(LVar6, EVT_FLOAT(0.296))
        EVT_SETF(LVar7, EVT_FLOAT(0.296))
        EVT_SET(LVarF, LVarE)
        EVT_ADD(LVarF, CLONED_MODEL(0))
        EVT_EXEC(N(EVS_UpdateSmokeParticle))
        EVT_ADD(LVarE, 1)
        EVT_IF_GE(LVarE, 16)
            EVT_SET(LVarE, 0)
        EVT_END_IF
        EVT_WAIT(10)
        EVT_GOTO(0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShakeMachine) = {
    EVT_IF_EQ(MF_MachineShaking, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(MF_MachineShaking, TRUE)
    EVT_SET(LVarF, 0)
    EVT_LOOP(12)
        EVT_CALL(RandInt, 80, LVar0)
        EVT_SUB(LVar0, 40)
        EVT_CALL(RandInt, 50, LVar1)
        EVT_CALL(RandInt, 50, LVar2)
        EVT_SUB(LVar2, 25)
        EVT_PLAY_EFFECT(EFFECT_00, LVar0, LVar1, LVar2, 5, 10, 1, 1)
        EVT_ADD(LVarF, 1)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVarE, EVT_FLOAT(1.0), EVT_FLOAT(1.093), 2, 0, 0)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVarD, EVT_FLOAT(1.093), EVT_FLOAT(1.0), 2, 0, 0)
        EVT_SETF(LVar0, LVarE)
        EVT_SETF(LVar1, LVarD)
        EVT_SETF(LVar2, LVarE)
        EVT_IF_EQ(GB_FLO18_MachineDamage_Left, 0)
            EVT_CALL(ScaleModel, MODEL_o115, LVar0, LVar1, LVar2)
            EVT_CALL(ScaleModel, MODEL_o116, LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_IF_EQ(GB_FLO18_MachineDamage_Right, 0)
            EVT_CALL(ScaleModel, MODEL_o117, LVar0, LVar1, LVar2)
            EVT_CALL(ScaleModel, MODEL_o118, LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_IF_LE(GB_FLO18_MachineDamage_Left, 1)
            EVT_CALL(ScaleModel, MODEL_o119, LVar0, LVar1, LVar2)
        EVT_END_IF
        EVT_IF_LE(GB_FLO18_MachineDamage_Left, 2)
            EVT_IF_LE(GB_FLO18_MachineDamage_Right, 1)
                EVT_CALL(ScaleModel, MODEL_o120, LVar0, LVar1, LVar2)
                EVT_CALL(ScaleModel, MODEL_o121, LVar0, LVar1, LVar2)
                EVT_CALL(ScaleModel, MODEL_o122, LVar0, LVar1, LVar2)
                EVT_CALL(ScaleModel, MODEL_o123, LVar0, LVar1, LVar2)
                EVT_CALL(ScaleModel, MODEL_o124, LVar0, LVar1, LVar2)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(ScaleModel, MODEL_o113, LVar0, LVar1, LVar2)
        EVT_IF_LE(GB_FLO18_MachineDamage_Left, 2)
            EVT_IF_LE(GB_FLO18_MachineDamage_Right, 2)
                EVT_CALL(ScaleModel, MODEL_o100, LVar0, LVar1, LVar2)
                EVT_CALL(ScaleModel, MODEL_o99, LVar0, LVar1, LVar2)
                EVT_CALL(ScaleModel, MODEL_o125, LVar0, LVar1, LVar2)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(ScaleModel, MODEL_o92, LVar0, LVar1, LVar2)
        EVT_CALL(ScaleModel, MODEL_o93, LVar0, LVar1, LVar2)
        EVT_CALL(ScaleModel, MODEL_o94, LVar0, LVar1, LVar2)
        EVT_CALL(ScaleModel, MODEL_o95, LVar0, LVar1, LVar2)
        EVT_CALL(ScaleModel, MODEL_o91, LVar0, LVar1, LVar2)
        EVT_CALL(ScaleModel, MODEL_o114, LVar0, LVar1, LVar2)
        EVT_SUBF(LVar0, EVT_FLOAT(1.046))
        EVT_MULF(LVar0, EVT_FLOAT(100.0))
        EVT_IF_EQ(GB_FLO18_MachineDamage_Left, 0)
            EVT_CALL(RotateModel, MODEL_o115, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_o116, LVar0, 0, 0, 1)
        EVT_END_IF
        EVT_IF_EQ(GB_FLO18_MachineDamage_Right, 0)
            EVT_CALL(RotateModel, MODEL_o117, LVar0, 0, 0, 1)
            EVT_CALL(RotateModel, MODEL_o118, LVar0, 0, 0, 1)
        EVT_END_IF
        EVT_IF_LE(GB_FLO18_MachineDamage_Left, 1)
            EVT_CALL(RotateModel, MODEL_o119, LVar0, 0, 0, 1)
        EVT_END_IF
        EVT_IF_LE(GB_FLO18_MachineDamage_Left, 2)
            EVT_IF_LE(GB_FLO18_MachineDamage_Right, 1)
                EVT_CALL(RotateModel, MODEL_o120, LVar0, 0, 0, 1)
                EVT_CALL(RotateModel, MODEL_o121, LVar0, 0, 0, 1)
                EVT_CALL(RotateModel, MODEL_o122, LVar0, 0, 0, 1)
                EVT_CALL(RotateModel, MODEL_o123, LVar0, 0, 0, 1)
                EVT_CALL(RotateModel, MODEL_o124, LVar0, 0, 0, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(RotateModel, MODEL_o113, LVar0, 0, 0, 1)
        EVT_IF_LE(GB_FLO18_MachineDamage_Left, 2)
            EVT_IF_LE(GB_FLO18_MachineDamage_Right, 2)
                EVT_CALL(RotateModel, MODEL_o100, LVar0, 0, 0, 1)
                EVT_CALL(RotateModel, MODEL_o99, LVar0, 0, 0, 1)
                EVT_CALL(RotateModel, MODEL_o125, LVar0, 0, 0, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(RotateModel, MODEL_o92, LVar0, 0, 0, 1)
        EVT_CALL(RotateModel, MODEL_o93, LVar0, 0, 0, 1)
        EVT_CALL(RotateModel, MODEL_o94, LVar0, 0, 0, 1)
        EVT_CALL(RotateModel, MODEL_o95, LVar0, 0, 0, 1)
        EVT_CALL(RotateModel, MODEL_o91, LVar0, 0, 0, 1)
        EVT_CALL(RotateModel, MODEL_o114, LVar0, 0, 0, 1)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_SETF(LVar0, 1)
    EVT_SETF(LVar1, 1)
    EVT_SETF(LVar2, 1)
    EVT_IF_EQ(GB_FLO18_MachineDamage_Left, 0)
        EVT_CALL(ScaleModel, MODEL_o115, LVar0, LVar1, LVar2)
        EVT_CALL(ScaleModel, MODEL_o116, LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_IF_EQ(GB_FLO18_MachineDamage_Right, 0)
        EVT_CALL(ScaleModel, MODEL_o117, LVar0, LVar1, LVar2)
        EVT_CALL(ScaleModel, MODEL_o118, LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_IF_LE(GB_FLO18_MachineDamage_Left, 1)
        EVT_CALL(ScaleModel, MODEL_o119, LVar0, LVar1, LVar2)
    EVT_END_IF
    EVT_IF_LE(GB_FLO18_MachineDamage_Left, 2)
        EVT_IF_LE(GB_FLO18_MachineDamage_Right, 1)
            EVT_CALL(ScaleModel, MODEL_o120, LVar0, LVar1, LVar2)
            EVT_CALL(ScaleModel, MODEL_o121, LVar0, LVar1, LVar2)
            EVT_CALL(ScaleModel, MODEL_o122, LVar0, LVar1, LVar2)
            EVT_CALL(ScaleModel, MODEL_o123, LVar0, LVar1, LVar2)
            EVT_CALL(ScaleModel, MODEL_o124, LVar0, LVar1, LVar2)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ScaleModel, MODEL_o113, LVar0, LVar1, LVar2)
    EVT_IF_LE(GB_FLO18_MachineDamage_Left, 2)
        EVT_IF_LE(GB_FLO18_MachineDamage_Right, 2)
            EVT_CALL(ScaleModel, MODEL_o100, LVar0, LVar1, LVar2)
            EVT_CALL(ScaleModel, MODEL_o99, LVar0, LVar1, LVar2)
            EVT_CALL(ScaleModel, MODEL_o125, LVar0, LVar1, LVar2)
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(ScaleModel, MODEL_o92, LVar0, LVar1, LVar2)
    EVT_CALL(ScaleModel, MODEL_o93, LVar0, LVar1, LVar2)
    EVT_CALL(ScaleModel, MODEL_o94, LVar0, LVar1, LVar2)
    EVT_CALL(ScaleModel, MODEL_o95, LVar0, LVar1, LVar2)
    EVT_CALL(ScaleModel, MODEL_o91, LVar0, LVar1, LVar2)
    EVT_CALL(ScaleModel, MODEL_o114, LVar0, LVar1, LVar2)
    EVT_WAIT(1)
    EVT_SET(MF_MachineShaking, FALSE)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DamagedLeftOnce) = {
    EVT_SETF(LVar0, 0)
    EVT_SETF(LVar1, 0)
    EVT_SETF(LVar2, 0)
    EVT_SETF(LVar3, EVT_FLOAT(-1.0))
    EVT_SETF(LVar4, EVT_FLOAT(0.0))
    EVT_SETF(LVar5, EVT_FLOAT(3.0))
    EVT_THREAD
        EVT_WAIT(10)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o130, SOUND_PUFF_PUFF_PART_BREAKS, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_LOOP(300)
        EVT_ADDF(LVar4, EVT_FLOAT(-0.5))
        EVT_ADDF(LVar5, EVT_FLOAT(0.093))
        EVT_ADDF(LVar0, LVar3)
        EVT_ADDF(LVar1, LVar4)
        EVT_ADDF(LVar2, LVar5)
        EVT_IF_LT(LVar1, -10)
            EVT_SETF(LVar1, EVT_FLOAT(-10.0))
            EVT_SETF(LVar3, EVT_FLOAT(0.0))
            EVT_SETF(LVar4, EVT_FLOAT(0.0))
            EVT_IF_GE(LVar2, 80)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(TranslateModel, MODEL_o115, -78, 19, 2)
    EVT_CALL(TranslateModel, MODEL_o116, -78, 19, 2)
    EVT_CALL(TranslateModel, MODEL_o115, LVar0, LVar1, 0)
    EVT_CALL(TranslateModel, MODEL_o116, LVar0, LVar1, 0)
    EVT_CALL(RotateModel, MODEL_o115, LVar2, 0, 0, 1)
    EVT_CALL(RotateModel, MODEL_o116, LVar2, 0, 0, 1)
    EVT_CALL(TranslateModel, MODEL_o115, 78, -19, -2)
    EVT_CALL(TranslateModel, MODEL_o116, 78, -19, -2)
    EVT_WAIT(1)
EVT_END_LOOP
EVT_LABEL(0)
EVT_WAIT(30)
EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o130, COLLIDER_FLAGS_UPPER_MASK)
EVT_RETURN
EVT_END
};

EvtScript N(EVS_DamagedRightOnce) = {
    EVT_SETF(LVar0, 0)
    EVT_SETF(LVar1, 0)
    EVT_SETF(LVar2, 0)
    EVT_SETF(LVar3, EVT_FLOAT(0.0))
    EVT_SETF(LVar4, EVT_FLOAT(0.0))
    EVT_SETF(LVar5, EVT_FLOAT(-5.0))
    EVT_THREAD
        EVT_WAIT(12)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o175, SOUND_PUFF_PUFF_PANEL_BREAKS, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_LOOP(300)
        EVT_ADDF(LVar4, EVT_FLOAT(-0.5))
        EVT_ADDF(LVar0, LVar3)
        EVT_ADDF(LVar1, LVar4)
        EVT_ADDF(LVar2, LVar5)
        EVT_IF_LT(LVar2, -45)
            EVT_SET(LVar5, 5)
        EVT_END_IF
        EVT_IF_GT(LVar2, 0)
            EVT_SET(LVar2, 0)
            EVT_SET(LVar3, 5)
        EVT_END_IF
        EVT_IF_LT(LVar1, -25)
            EVT_SET(LVar4, 0)
            EVT_SET(LVar1, -25)
        EVT_END_IF
        EVT_IF_GT(LVar0, 90)
            EVT_GOTO(0)
        EVT_END_IF
        EVT_CALL(TranslateModel, MODEL_o117, 50, 28, 27)
        EVT_CALL(TranslateModel, MODEL_o118, 50, 28, 27)
        EVT_CALL(TranslateModel, MODEL_o117, 0, LVar1, 1)
        EVT_CALL(TranslateModel, MODEL_o118, 0, LVar1, 1)
        EVT_CALL(RotateModel, MODEL_o117, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o118, LVar0, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o117, LVar2, 0, 0, 1)
        EVT_CALL(RotateModel, MODEL_o118, LVar2, 0, 0, 1)
        EVT_CALL(TranslateModel, MODEL_o117, -50, -28, -27)
        EVT_CALL(TranslateModel, MODEL_o118, -50, -28, -27)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DamagedLeftTwice) = {
    EVT_SETF(LVar2, 0)
    EVT_SETF(LVar1, 0)
    EVT_SETF(LVar0, 0)
    EVT_SETF(LVar5, EVT_FLOAT(0.0))
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o174, SOUND_PUFF_PUFF_PANEL_BREAKS, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_LOOP(300)
        EVT_ADDF(LVar5, EVT_FLOAT(0.5))
        EVT_ADDF(LVar2, LVar5)
        EVT_IF_GE(LVar2, 80)
            EVT_SETF(LVar2, 80)
            EVT_MULF(LVar5, EVT_FLOAT(-0.5))
            EVT_IF_EQ(LVar5, 0)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(TranslateModel, MODEL_o119, -55, 5, 16)
        EVT_CALL(TranslateModel, MODEL_o119, LVar0, LVar1, 0)
        EVT_CALL(RotateModel, MODEL_o119, LVar2, 0, 0, 1)
        EVT_CALL(TranslateModel, MODEL_o119, 55, -5, -16)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_DamagedRightTwice) = {
    EVT_SETF(LVar2, 0)
    EVT_SETF(LVar1, 0)
    EVT_SETF(LVar0, 0)
    EVT_SETF(LVar5, EVT_FLOAT(0.0))
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o127, SOUND_PUFF_PUFF_PANEL_BREAKS, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_LOOP(300)
        EVT_ADDF(LVar5, EVT_FLOAT(0.5))
        EVT_ADDF(LVar2, LVar5)
        EVT_IF_GE(LVar2, 80)
            EVT_SETF(LVar2, 80)
            EVT_MULF(LVar5, EVT_FLOAT(-0.5))
            EVT_IF_EQ(LVar5, 0)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(TranslateModel, MODEL_o122, 60, 0, 16)
        EVT_CALL(RotateModel, MODEL_o122, LVar2, 0, 0, -1)
        EVT_CALL(TranslateModel, MODEL_o122, -60, 0, -16)
        EVT_CALL(TranslateModel, MODEL_o120, 0, 0, 27)
        EVT_CALL(TranslateModel, MODEL_o121, 0, 0, 27)
        EVT_CALL(RotateModel, MODEL_o120, LVar2, 1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o121, LVar2, 1, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o120, 0, 0, -27)
        EVT_CALL(TranslateModel, MODEL_o121, 0, 0, -27)
        EVT_CALL(TranslateModel, MODEL_o123, 0, 0, -41)
        EVT_CALL(TranslateModel, MODEL_o124, 0, 0, -41)
        EVT_CALL(RotateModel, MODEL_o123, LVar2, -1, 0, 0)
        EVT_CALL(RotateModel, MODEL_o124, LVar2, -1, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o123, 0, 0, 41)
        EVT_CALL(TranslateModel, MODEL_o124, 0, 0, 41)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LABEL(0)
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_BreakSmokestack) = {
    EVT_SETF(LVar0, 0)
    EVT_SETF(LVar1, 0)
    EVT_SETF(LVar2, 0)
    EVT_SETF(LVar3, EVT_FLOAT(-1.0))
    EVT_SETF(LVar4, EVT_FLOAT(0.0))
    EVT_SETF(LVar5, EVT_FLOAT(3.0))
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o131, SOUND_PUFF_PUFF_PART_BREAKS, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_LOOP(300)
        EVT_ADDF(LVar4, EVT_FLOAT(-0.5))
        EVT_ADDF(LVar5, EVT_FLOAT(0.093))
        EVT_ADDF(LVar0, LVar3)
        EVT_ADDF(LVar1, LVar4)
        EVT_ADDF(LVar2, LVar5)
        EVT_IF_LT(LVar1, -25)
            EVT_SETF(LVar1, EVT_FLOAT(-25.0))
            EVT_SETF(LVar3, EVT_FLOAT(0.0))
            EVT_SETF(LVar4, EVT_FLOAT(0.0))
            EVT_IF_GE(LVar2, 80)
                EVT_GOTO(0)
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(TranslateModel, MODEL_o100, 124, 17, 3)
    EVT_CALL(TranslateModel, MODEL_o100, LVar0, LVar1, 0)
    EVT_CALL(RotateModel, MODEL_o100, LVar2, 0, 0, -1)
    EVT_CALL(TranslateModel, MODEL_o100, -124, -17, -3)
    EVT_WAIT(1)
EVT_END_LOOP
EVT_LABEL(0)
EVT_RETURN
EVT_END
};

EvtScript N(EVS_BreakAntenna) = {
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o131, COLLIDER_FLAGS_UPPER_MASK)
    EVT_SETF(LVar0, 0)
    EVT_SETF(LVar1, 0)
    EVT_SETF(LVar2, 0)
    EVT_SETF(LVar3, EVT_FLOAT(3.0))
    EVT_SETF(LVar4, EVT_FLOAT(1.0))
    EVT_SETF(LVar5, EVT_FLOAT(5.0))
    EVT_THREAD
        EVT_WAIT(15)
        EVT_CALL(PlaySoundAtCollider, COLLIDER_o126, SOUND_PUFF_PUFF_PART_BREAKS, SOUND_SPACE_DEFAULT)
    EVT_END_THREAD
    EVT_LOOP(300)
        EVT_ADDF(LVar4, EVT_FLOAT(-0.5))
        EVT_ADDF(LVar0, LVar3)
        EVT_ADDF(LVar1, LVar4)
        EVT_ADDF(LVar2, LVar5)
        EVT_IF_LE(LVar1, -40)
            EVT_SETF(LVar1, -40)
            EVT_MULF(LVar4, EVT_FLOAT(-0.5))
            EVT_IF_LE(LVar4, 1)
                EVT_GOTO(1)
            EVT_END_IF
        EVT_END_IF
        EVT_IF_GE(LVar2, 60)
            EVT_SETF(LVar2, 60)
            EVT_SETF(LVar5, 0)
        EVT_END_IF
        EVT_CALL(TranslateModel, MODEL_o99, -34, 50, 10)
        EVT_CALL(TranslateModel, MODEL_o125, -34, 50, 10)
        EVT_CALL(TranslateModel, MODEL_o99, 0, LVar1, LVar0)
        EVT_CALL(RotateModel, MODEL_o99, LVar2, 0, 0, 1)
        EVT_CALL(TranslateModel, MODEL_o125, 0, LVar1, LVar0)
        EVT_CALL(RotateModel, MODEL_o125, LVar2, 0, 0, 1)
        EVT_CALL(TranslateModel, MODEL_o99, 34, -50, -10)
        EVT_CALL(TranslateModel, MODEL_o125, 34, -50, -10)
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_LABEL(1)
    EVT_WAIT(30)
    EVT_RETURN
    EVT_END
};

Vec3i N(SmokeBurstPositions)[] = {
    {  0,  0, 27 },
    { 80, 35, 27 },
    { 60, 10, 27 },
    { 30,  0, 27 },
    { 80, 35, 27 },
    { 30,  0, 27 },
    { 85,  0, 27 },
    { 80, 35, 27 },
};

EvtScript N(EVS_DamageMachine) = {
    #define LABEL_DONE 0
    EVT_SET(LVarA, LVar0) // in: damage part
    EVT_CALL(GetPlayerPos, LVar0, LVar1, LVar2)
    EVT_IF_LT(LVar0, -210)
        EVT_RETURN
    EVT_END_IF
    EVT_CALL(PlaySound, SOUND_PUFF_PUFF_SMASH)
    EVT_EXEC_WAIT(N(EVS_ShakeMachine))
    EVT_SET(LVar0, LVarA)
    EVT_IF_LT(GB_StoryProgress, STORY_CH6_DEFEATED_PUFF_PUFF_GUARDS)
        EVT_SET(MF_HitGuardedMachine, TRUE)
        EVT_RETURN
    EVT_END_IF
    EVT_IF_EQ(MF_MachineBeingDamaged, TRUE)
        EVT_RETURN
    EVT_END_IF
    // check damage type
    EVT_SET(MF_MachineBeingDamaged, TRUE)
    EVT_IF_GT(LVar0, DAMAGE_PART_PROTRUSTIONS)
        EVT_GOTO(LABEL_DONE)
    EVT_END_IF
    EVT_IF_EQ(LVar0, DAMAGE_PART_PROTRUSTIONS)
        EVT_GOTO(11)
    EVT_END_IF
    EVT_IF_EQ(LVar0, DAMAGE_PART_LEFT_SIDE)
        EVT_LABEL(11)
        EVT_IF_EQ(GB_FLO18_MachineDamage_Left, 0)
            EVT_SET(GB_FLO18_MachineDamage_Left, 1)
            EVT_EXEC(N(EVS_DamagedLeftOnce))
            EVT_GOTO(LABEL_DONE)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LVar0, DAMAGE_PART_RIGHT_SIDE)
        EVT_IF_EQ(GB_FLO18_MachineDamage_Right, 0)
            EVT_SET(GB_FLO18_MachineDamage_Right, 1)
            EVT_EXEC(N(EVS_DamagedRightOnce))
            EVT_GOTO(LABEL_DONE)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(LVar0, DAMAGE_PART_LEFT_SIDE)
        EVT_IF_EQ(GB_FLO18_MachineDamage_Left, 1)
            EVT_SET(GB_FLO18_MachineDamage_Left, 2)
            EVT_EXEC(N(EVS_DamagedLeftTwice))
            EVT_GOTO(LABEL_DONE)
        EVT_END_IF
    EVT_END_IF
    EVT_IF_EQ(GB_FLO18_MachineDamage_Left, 2)
        EVT_IF_EQ(GB_FLO18_MachineDamage_Right, 1)
            EVT_SET(GB_FLO18_MachineDamage_Right, 2)
            EVT_EXEC(N(EVS_DamagedRightTwice))
            EVT_GOTO(LABEL_DONE)
        EVT_END_IF
    EVT_END_IF
    // check if machine is fully broken (2 damage to each side)
    EVT_IF_EQ(GB_FLO18_MachineDamage_Left, 2)
        EVT_IF_EQ(GB_FLO18_MachineDamage_Right, 2)
            EVT_CALL(DisablePlayerInput, TRUE)
            EVT_CALL(UseSettingsFrom, CAM_DEFAULT, 40, 0, 0)
            EVT_CALL(SetPanTarget, CAM_DEFAULT, 40, 0, 0)
            EVT_CALL(SetCamSpeed, CAM_DEFAULT, EVT_FLOAT(1.5))
            EVT_CALL(PanToTarget, CAM_DEFAULT, 0, 1)
            EVT_SET(GB_FLO18_MachineDamage_Right, 3)
            EVT_EXEC_WAIT(N(EVS_ShakeMachine))
            EVT_EXEC_WAIT(N(EVS_ShakeMachine))
            EVT_EXEC_WAIT(N(EVS_ShakeMachine))
            EVT_WAIT(30)
            EVT_CALL(GetModelCenter, MODEL_o113)
            EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, 50, LVar2, 100, 20, 0, 30)
            EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, 30, LVar2, 120, 20, 0, 30)
            EVT_PLAY_EFFECT(EFFECT_SMOKE_IMPACT, 0, LVar0, 10, LVar2, 100, 20, 0, 30)
            EVT_WAIT(15)
            EVT_THREAD
                EVT_SET(LVar3, 6)
                EVT_USE_BUF(EVT_PTR(N(SmokeBurstPositions)))
                EVT_LOOP(ARRAY_COUNT(N(SmokeBurstPositions)))
                    EVT_BUF_READ3(LVar0, LVar1, LVar2)
                    EVT_CALL(PlaySoundAt, SOUND_FLO_PUFF_PUFF_SMOKE_BURST, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
                    EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, 1, 6)
                    EVT_WAIT(2)
                    EVT_ADD(LVar1, 5)
                    EVT_CALL(PlaySoundAt, SOUND_FLO_PUFF_PUFF_SMOKE_BURST, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
                    EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, 2, 15)
                    EVT_WAIT(LVar3)
                    EVT_ADD(LVar3, 1)
                EVT_END_LOOP
                EVT_SETF(LVar4, EVT_FLOAT(2.0))
                EVT_LOOP(2)
                    EVT_USE_BUF(EVT_PTR(N(SmokeBurstPositions)))
                    EVT_LOOP(ARRAY_COUNT(N(SmokeBurstPositions)))
                        EVT_BUF_READ3(LVar0, LVar1, LVar2)
                        EVT_CALL(PlaySoundAt, SOUND_FLO_PUFF_PUFF_SMOKE_BURST, SOUND_SPACE_DEFAULT, LVar0, LVar1, LVar2)
                        EVT_PLAY_EFFECT(EFFECT_SMOKE_BURST, 0, LVar0, LVar1, LVar2, 1, 25)
                        EVT_WAIT(LVar3)
                        EVT_ADD(LVar3, LVar4)
                        EVT_ADDF(LVar4, EVT_FLOAT(0.5))
                    EVT_END_LOOP
                EVT_END_LOOP
            EVT_END_THREAD
            EVT_CALL(PlaySoundAt, SOUND_FLO_PUFF_PUFF_EXPLODE, SOUND_SPACE_DEFAULT, 70, 40, 10)
            EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, 70, 40, 10, EVT_FLOAT(3.0), 30)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(1.0))
            EVT_CALL(PlaySoundAt, SOUND_FLO_PUFF_PUFF_EXPLODE, SOUND_SPACE_DEFAULT, 0, 30, 30)
            EVT_PLAY_EFFECT(EFFECT_RING_BLAST, 0, 0, 30, 30, EVT_FLOAT(4.0), 40)
            EVT_CALL(ShakeCam, CAM_DEFAULT, 0, 20, EVT_FLOAT(2.0))
            EVT_EXEC_WAIT(N(EVS_BreakSmokestack))
            EVT_CALL(PlaySoundAtCollider, COLLIDER_o126, SOUND_LRAW_PUFF_PUFF_MACHINE | SOUND_ID_TRIGGER_CHANGE_SOUND, SOUND_SPACE_DEFAULT)
            EVT_CALL(FadeOutMusic, 0, 1000)
            EVT_CALL(DisablePlayerPhysics, TRUE)
            EVT_WAIT(30)
            EVT_EXEC_WAIT(N(EVS_BreakAntenna))
            EVT_SET(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
            EVT_CALL(GotoMap, EVT_PTR("flo_15"), flo_15_ENTRY_1)
            EVT_WAIT(70)
            EVT_RETURN
        EVT_END_IF
    EVT_END_IF
    EVT_LABEL(LABEL_DONE)
    EVT_SET(MF_MachineBeingDamaged, FALSE)
    EVT_RETURN
    EVT_END
};

BombTrigger N(Machine_BombTrigger_01) = {
    .pos = { 5.0f, 0.0f, -10.0f },
    .radius = 0.0f
};

BombTrigger N(Machine_BombTrigger_02) = {
    .pos = { -5.0f, 0.0f, -20.0f },
    .radius = 0.0f
};

BombTrigger N(Machine_BombTrigger_03) = {
    .pos = { 50.0f, 0.0f, -10.0f },
    .radius = 0.0f
};

BombTrigger N(Machine_BombTrigger_04) = {
    .pos = { 105.0f, 0.0f, -10.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupMachine) = {
    EVT_IF_GE(GB_StoryProgress, STORY_CH6_DESTROYED_PUFF_PUFF_MACHINE)
        EVT_CALL(EnableModel, MODEL_o101, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o130, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, MODEL_o115, FALSE)
        EVT_CALL(EnableModel, MODEL_o116, FALSE)
        EVT_CALL(EnableModel, MODEL_o117, FALSE)
        EVT_CALL(EnableModel, MODEL_o118, FALSE)
        EVT_CALL(EnableModel, MODEL_o119, FALSE)
        EVT_CALL(EnableModel, MODEL_o120, FALSE)
        EVT_CALL(EnableModel, MODEL_o121, FALSE)
        EVT_CALL(EnableModel, MODEL_o122, FALSE)
        EVT_CALL(EnableModel, MODEL_o123, FALSE)
        EVT_CALL(EnableModel, MODEL_o124, FALSE)
        EVT_CALL(EnableModel, MODEL_o100, FALSE)
        EVT_CALL(EnableModel, MODEL_o99, FALSE)
        EVT_CALL(EnableModel, MODEL_o125, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o131, COLLIDER_FLAGS_UPPER_MASK)
        EVT_RETURN
    EVT_END_IF
    EVT_EXEC(N(EVS_AnimateMachineLightning))
    EVT_CALL(EnableModel, MODEL_o101, FALSE)
    EVT_IF_GE(GB_FLO18_MachineDamage_Left, 1)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o130, COLLIDER_FLAGS_UPPER_MASK)
        EVT_CALL(EnableModel, MODEL_o115, FALSE)
        EVT_CALL(EnableModel, MODEL_o116, FALSE)
    EVT_END_IF
    EVT_IF_GE(GB_FLO18_MachineDamage_Right, 1)
        EVT_CALL(EnableModel, MODEL_o117, FALSE)
        EVT_CALL(EnableModel, MODEL_o118, FALSE)
    EVT_END_IF
    EVT_IF_GE(GB_FLO18_MachineDamage_Left, 2)
        EVT_CALL(EnableModel, MODEL_o119, FALSE)
    EVT_END_IF
    EVT_IF_GE(GB_FLO18_MachineDamage_Right, 2)
        EVT_CALL(EnableModel, MODEL_o120, FALSE)
        EVT_CALL(EnableModel, MODEL_o121, FALSE)
        EVT_CALL(EnableModel, MODEL_o122, FALSE)
        EVT_CALL(EnableModel, MODEL_o123, FALSE)
        EVT_CALL(EnableModel, MODEL_o124, FALSE)
    EVT_END_IF
    EVT_IF_GE(GB_FLO18_MachineDamage_Right, 3)
        EVT_CALL(EnableModel, MODEL_o100, FALSE)
        EVT_CALL(EnableModel, MODEL_o99, FALSE)
        EVT_CALL(EnableModel, MODEL_o125, FALSE)
        EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o131, COLLIDER_FLAGS_UPPER_MASK)
        EVT_RETURN
    EVT_END_IF
    EVT_SET(LVar0, DAMAGE_PART_LEFT_SIDE)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_DamageMachine)), TRIGGER_WALL_HAMMER, COLLIDER_o174, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_DamageMachine)), TRIGGER_POINT_BOMB, EVT_PTR(N(Machine_BombTrigger_01)), 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_DamageMachine)), TRIGGER_POINT_BOMB, EVT_PTR(N(Machine_BombTrigger_02)), 1, 0)
    EVT_SET(LVar0, DAMAGE_PART_RIGHT_SIDE)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_DamageMachine)), TRIGGER_WALL_HAMMER, COLLIDER_o127, 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_DamageMachine)), TRIGGER_POINT_BOMB, EVT_PTR(N(Machine_BombTrigger_03)), 1, 0)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_DamageMachine)), TRIGGER_POINT_BOMB, EVT_PTR(N(Machine_BombTrigger_04)), 1, 0)
    EVT_SET(LVar0, DAMAGE_PART_LEVER)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_DamageMachine)), TRIGGER_WALL_HAMMER, COLLIDER_o130, 1, 0)
    EVT_SET(LVar0, DAMAGE_PART_SMOKE_STACK)
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_DamageMachine)), TRIGGER_WALL_HAMMER, COLLIDER_o131, 1, 0)
    EVT_SET(LVar0, 0)
    EVT_LOOP(16)
        EVT_SET(LVar1, LVar0)
        EVT_ADD(LVar1, CLONED_MODEL(0))
        EVT_ADD(LVar0, 1)
        EVT_CALL(CloneModel, MODEL_o101, LVar1)
        EVT_CALL(EnableModel, LVar1, FALSE)
    EVT_END_LOOP
    EVT_EXEC(N(EVS_ManageSmoke))
    EVT_CALL(EnableTexPanning, MODEL_o92, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o93, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o94, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o95, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o91, TRUE)
    EVT_CALL(EnableTexPanning, MODEL_o99, TRUE)
    EVT_THREAD
        EVT_SETF(LVarE, EVT_FLOAT(1.0))
        EVT_LABEL(0)
        EVT_IF_GE(GB_FLO18_MachineDamage_Right, 3)
            EVT_MULF(LVarE, EVT_FLOAT(0.953))
        EVT_END_IF
        EVT_ADDF(LVarF, LVarE)
        EVT_IF_EQ(LVarF, 1080)
            EVT_SETF(LVarF, 0)
        EVT_END_IF
        EVT_SET(LVar0, LVarF)
        EVT_DIV(LVar0, 9)
        EVT_MOD(LVar0, 4)
        EVT_MUL(LVar0, 0x4000)
        EVT_SET(LVar1, LVarF)
        EVT_DIV(LVar1, 4)
        EVT_MOD(LVar1, 2)
        EVT_MUL(LVar1, 0x4000)
        EVT_SET(LVar2, LVarF)
        EVT_DIV(LVar2, 5)
        EVT_MOD(LVar2, 2)
        EVT_MUL(LVar2, 0x4000)
        EVT_SET(LVar3, LVarF)
        EVT_DIV(LVar3, 6)
        EVT_MOD(LVar3, 2)
        EVT_MUL(LVar3, 0x4000)
        EVT_SET(LVar4, LVarF)
        EVT_DIV(LVar4, 2)
        EVT_MOD(LVar4, 2)
        EVT_MUL(LVar4, 0x8000)
        EVT_SET(LVar5, LVarF)
        EVT_DIV(LVar5, 8)
        EVT_MOD(LVar5, 2)
        EVT_MUL(LVar5, 0x4000)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_C, TEX_PANNER_MAIN, LVar0, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_D, TEX_PANNER_MAIN, LVar1, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_E, TEX_PANNER_MAIN, LVar2, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_F, TEX_PANNER_MAIN, LVar3, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_B, TEX_PANNER_MAIN, LVar4, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_A, TEX_PANNER_MAIN, LVar5, 0)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_9, TEX_PANNER_MAIN, LVar5, 0)
        EVT_WAIT(1)
        EVT_GOTO(0)
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};
