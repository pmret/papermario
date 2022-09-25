#include "common.h"

#define TEX_PAN_PARAMS_ID(panID) \
        EVT_SET(LVar0, (panID))

#define TEX_PAN_PARAMS_STEP(main_step_du, main_step_dv, aux_step_du, aux_step_dv) \
        EVT_SET(LVar1, (main_step_du)) \
        EVT_SET(LVar2, (main_step_dv)) \
        EVT_SET(LVar3, (aux_step_du)) \
        EVT_SET(LVar4, (aux_step_dv))

#define TEX_PAN_PARAMS_FREQ(main_freq_u, main_freq_v, aux_freq_u, aux_freq_v) \
        EVT_SET(LVar5, (main_freq_u)) \
        EVT_SET(LVar6, (main_freq_v)) \
        EVT_SET(LVar7, (aux_freq_u)) \
        EVT_SET(LVar8, (aux_freq_v))

#define TEX_PAN_PARAMS_INIT(main_init_u, main_init_v, aux_init_u, aux_init_v) \
        EVT_SET(LVar9, (main_init_u)) \
        EVT_SET(LVarA, (main_init_v)) \
        EVT_SET(LVarB, (aux_init_u)) \
        EVT_SET(LVarC, (aux_init_v)) \

EvtScript N(EVS_UpdateTexturePan) = {
    EVT_SET_GROUP(EVT_GROUP_00)
    EVT_IF_EQ(LVar5, 1)
        EVT_IF_EQ(LVar6, 1)
            EVT_IF_EQ(LVar7, 1)
                EVT_IF_EQ(LVar8, 1)
                    EVT_CALL(N(UpdateTexturePanSmooth))
                    EVT_RETURN
                EVT_END_IF
            EVT_END_IF
        EVT_END_IF
    EVT_END_IF
    EVT_CALL(N(UpdateTexturePanStepped))
    EVT_RETURN
    EVT_END
};
