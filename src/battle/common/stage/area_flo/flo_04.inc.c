#include "battle/battle.h"
#include "mapfs/flo_bt04_shape.h"

#define NAMESPACE A(flo_04)

#include "common/CosInterpMinMax.inc.c"

EvtScript N(EVS_AnimateCloud) = {
    EVT_SET(LVarA, LVar0)
    EVT_SET(LVarF, 0)
    EVT_LOOP(0)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar0, EVT_FLOAT(0.968), EVT_FLOAT(1.031), 15, 0, 0)
        EVT_CALL(N(CosInterpMinMax), LVarF, LVar1, EVT_FLOAT(1.031), EVT_FLOAT(0.968), 15, 0, 0)
        EVT_CALL(ScaleModel, LVarA, LVar1, LVar0, 1)
        EVT_ADD(LVarF, 1)
        EVT_IF_GE(LVarF, 30)
            EVT_SET(LVarF, 0)
        EVT_END_IF
        EVT_WAIT(1)
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
};

#include "common/MakeSun.inc.c"

EvtScript N(EVS_PreBattle) = {
    EVT_CALL(SetSpriteShading, SHADING_NONE)
    EVT_CALL(SetCamBGColor, CAM_BATTLE, 0, 0, 0)
    EVT_SET(LVar0, MODEL_o412)
    EVT_EXEC(N(EVS_AnimateCloud))
    EVT_SET(LVar0, MODEL_o413)
    EVT_EXEC(N(EVS_AnimateCloud))
    EVT_SET(LVar0, MODEL_o414)
    EVT_EXEC(N(EVS_AnimateCloud))
    EVT_SET(LVar0, MODEL_o415)
    EVT_EXEC(N(EVS_AnimateCloud))
    EVT_SET(LVar0, MODEL_o419)
    EVT_EXEC(N(EVS_AnimateCloud))
    EVT_THREAD
        EVT_SET(LVar0, MODEL_o431)
        EVT_EXEC(N(EVS_AnimateCloud))
        EVT_SET(LVar0, MODEL_o432)
        EVT_EXEC(N(EVS_AnimateCloud))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_b2_2)
        EVT_EXEC(N(EVS_AnimateCloud))
        EVT_SET(LVar0, MODEL_b2_1)
        EVT_EXEC(N(EVS_AnimateCloud))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_b1_2)
        EVT_EXEC(N(EVS_AnimateCloud))
        EVT_SET(LVar0, MODEL_b1_1)
        EVT_EXEC(N(EVS_AnimateCloud))
        EVT_SET(LVar0, MODEL_b1_3)
        EVT_EXEC(N(EVS_AnimateCloud))
        EVT_WAIT(5)
        EVT_SET(LVar0, MODEL_o433)
        EVT_EXEC(N(EVS_AnimateCloud))
        EVT_SET(LVar0, MODEL_o434)
        EVT_EXEC(N(EVS_AnimateCloud))
    EVT_END_THREAD
    EVT_CALL(CloneModel, MODEL_o427, CLONED_MODEL(0))
    EVT_CALL(EnableModel, CLONED_MODEL(0), FALSE)
    EVT_CALL(TranslateModel, CLONED_MODEL(0), 0, 9, 0)
    EVT_CALL(ParentColliderToModel, 0, CLONED_MODEL(0))
    EVT_EXEC_WAIT(N(MakeSun))
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_PostBattle) = {
    EVT_RETURN
    EVT_END
};

s32 N(ForegroundModels)[] = {
    -1,
    MODEL_o431,
    MODEL_o419,
    STAGE_MODEL_LIST_END
};

Stage NAMESPACE = {
    .texture = "flo_tex",
    .shape = "flo_bt04_shape",
    .hit = "flo_bt04_hit",
    .bg = "sra_bg",
    .preBattle = &N(EVS_PreBattle),
    .postBattle = &N(EVS_PostBattle),
    .foregroundModelList = N(ForegroundModels),
};
