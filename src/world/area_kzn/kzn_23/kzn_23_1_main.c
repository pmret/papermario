#include "kzn_23.h"

extern EvtScript N(EVS_SetupMusic);
extern NpcGroupList N(DefaultNPCs);

#include "world/common/atomic/TexturePan.inc.c"
#include "world/common/atomic/TexturePan.data.inc.c"

EvtScript N(EVS_StartTexPanner3) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, LVar0, TEX_PANNER_3)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_3)
        TEX_PAN_PARAMS_STEP(-200, 0, 600, -400)
        TEX_PAN_PARAMS_FREQ(   1, 0,   1,    1)
        TEX_PAN_PARAMS_INIT(   0, 0,   0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_StartTexPanner4) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_CALL(SetTexPanner, LVar0, TEX_PANNER_4)
    EVT_THREAD
        TEX_PAN_PARAMS_ID(TEX_PANNER_4)
        TEX_PAN_PARAMS_STEP(500, 0, 0, -400)
        TEX_PAN_PARAMS_FREQ(  1, 0, 0,    1)
        TEX_PAN_PARAMS_INIT(  0, 0, 0,    0)
        EVT_EXEC(N(EVS_UpdateTexturePan))
    EVT_END_THREAD
    EVT_RETURN
    EVT_END
};

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
        EVT_CALL(SetTexPanOffset, TEX_PANNER_0, 0, LVar0, LVar1)
        EVT_CALL(SetTexPanOffset, TEX_PANNER_0, 1, LVar2, LVar3)
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
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, 3, 25, 16, 4096)
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0)
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)
    EVT_CALL(MakeNpcs, TRUE, EVT_PTR(N(DefaultNPCs)))
    EVT_EXEC(N(EVS_SetupMusic))
    EVT_EXEC(N(EVS_RaiseLava))
    EVT_SET(LVar0, MODEL_kem1)
    EVT_EXEC(N(EVS_StartTexPanner3))
    EVT_SET(LVar0, MODEL_kem2)
    EVT_EXEC(N(EVS_StartTexPanner4))
    EVT_RETURN
    EVT_END
};
