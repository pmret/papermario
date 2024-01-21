#define TEX_PAN_PARAMS_ID(panID) \
        Set(LVar0, (panID))

#define TEX_PAN_PARAMS_STEP(main_step_du, main_step_dv, aux_step_du, aux_step_dv) \
        Set(LVar1, (main_step_du)) \
        Set(LVar2, (main_step_dv)) \
        Set(LVar3, (aux_step_du)) \
        Set(LVar4, (aux_step_dv))

#define TEX_PAN_PARAMS_FREQ(main_freq_u, main_freq_v, aux_freq_u, aux_freq_v) \
        Set(LVar5, (main_freq_u)) \
        Set(LVar6, (main_freq_v)) \
        Set(LVar7, (aux_freq_u)) \
        Set(LVar8, (aux_freq_v))

#define TEX_PAN_PARAMS_INIT(main_init_u, main_init_v, aux_init_u, aux_init_v) \
        Set(LVar9, (main_init_u)) \
        Set(LVarA, (main_init_v)) \
        Set(LVarB, (aux_init_u)) \
        Set(LVarC, (aux_init_v)) \

extern EvtScript N(EVS_UpdateTexturePan);
