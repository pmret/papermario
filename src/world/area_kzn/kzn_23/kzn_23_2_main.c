#include "kzn_23.h"

#include "../common/SmokeTexPanners.inc.c"

// should add to zero over a full cycle
s32 N(LavaFluctuationOffsets)[] = {
     1,  2,  3,  3,  2,  1,
    -1, -2, -3, -3, -2, -1,
};

// overlay a sinusoidal offset to the lava level
EvtScript N(EVS_ModulateLavaLevel) = {
    EVT_LOOP(0)
        EVT_USE_BUF(N(LavaFluctuationOffsets))
        EVT_LOOP(ARRAY_COUNT(N(LavaFluctuationOffsets)))
            EVT_BUF_READ1(LVar1)
            EVT_ADD(MV_LavaLevel, LVar1)
            EVT_WAIT(3)
        EVT_END_LOOP
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_RaiseLava) = {
    EVT_EXEC(N(EVS_ModulateLavaLevel))
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, MODEL_yu, TEX_PANNER_0)
    EVT_SET(LVar0, 0)
    EVT_SET(LVar1, 0)
    EVT_SET(LVar2, 0)
    EVT_SET(LVar3, 0)
    EVT_SET(MV_LavaLevel, -105)
    EVT_SET(LVar5, 40)
    EVT_CALL(TranslateModel, MODEL_yu, 0, MV_LavaLevel, 0)
    EVT_WAIT(6)
    EVT_LABEL(10)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_MAIN, LVar0, LVar1)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_0, TEX_PANNER_AUX, LVar2, LVar3)
        EVT_SUB(LVar0, 700)
        EVT_ADD(LVar1, 700)
        EVT_ADD(LVar2, 200)
        EVT_SUB(LVar3, 300)
        EVT_IF_EQ(LVar5, 40)
            EVT_IF_LT(MV_LavaLevel, 2700)
                EVT_ADD(MV_LavaLevel, 20)
            EVT_ELSE
                EVT_SUB(LVar5, 1)
            EVT_END_IF
        EVT_ELSE
            EVT_IF_NE(LVar5, 0)
                EVT_SUB(LVar5, 1)
                EVT_SUB(MV_LavaLevel, 1)
            EVT_END_IF
        EVT_END_IF
        EVT_CALL(TranslateModel, MODEL_yu, 0, MV_LavaLevel, 0)
        EVT_WAIT(1)
        EVT_GOTO(10)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_Main) = {
    EVT_SET(GB_WorldLocation, LOCATION_MT_LAVALAVA)
    EVT_CALL(SetSpriteShading, SHADING_KZN_23)
    EVT_SETUP_CAMERA_DEFAULT()
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_RaiseLava))
    EVT_SET(LVar0, MODEL_kem1)
    EVT_EXEC(N(EVS_StartTexPanner_SmokeLeft))
    EVT_SET(LVar0, MODEL_kem2)
    EVT_EXEC(N(EVS_StartTexPanner_SmokeRight))
    EVT_RETURN
    EVT_END
};
