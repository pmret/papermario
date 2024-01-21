#include "iwa_11.h"

#define NUM_SECTIONS 6

s32 N(TrackSections)[NUM_SECTIONS] = {
    MODEL_field_a,
    MODEL_field_b,
    MODEL_field_c,
    MODEL_field_d,
    MODEL_field_e,
    MODEL_field_f,
};

s32 N(SectionOffsets)[][NUM_SECTIONS + 1] = {
    { -6000,  -5750,  -5750,  -5750,  -3250,  -3250,  -3250 },
    { -4500,  -4250,  -5750,  -5750,  -3250,  -3250,  -3250 },
    { -4000,  -4250,  -4250,  -5750,  -3250,  -3250,  -3250 },
    { -3250,  -3250,  -4250,  -5750,  -3250,  -3250,  -3250 },
    { -2750,  -3250,  -3250,  -3250,  -3250,  -3250,  -3250 },
    { -2500,  -3250,  -3250,  -3250,  -3250,  -3250,  -3250 },
    {   250,  -3250,  -3250,  -3250,  -3250,  -2250,  -3250 },
    {   750,  -3250,  -3250,  -3250,   -750,  -2250,  -2250 },
    {  1500,  -3250,  -3250,  -3250,   -750,   -750,  -2250 },
    {  2000,  -3250,  -3250,  -3250,   -750,   -750,   -750 },
    {  2750,  -3250,  -3250,  -3250,   1750,    250,   -750 },
    {  3250,  -3250,  -3250,  -3250,   1750,    250,    250 },
    {  4000,  -3250,  -3250,  -3250,   1750,   1750,    250 },
    {  4500,  -3250,  -3250,  -3250,   1750,   1750,   1750 },
};

API_CALLABLE(N(GetSectionPosOffsets)) {
    s32 value = script->varTable[0];
    s32 index, i;

    for (i = 0; i < ARRAY_COUNT(N(SectionOffsets)); i++) {
        if (value < N(SectionOffsets)[i][0]) {
            break;
        }
    }
    index = i - 1;

    for (i = 0; i < NUM_SECTIONS; i++) {
        script->varTable[i + 5] = N(SectionOffsets)[index][i + 1];
    }

    return ApiStatus_DONE2;
}

EvtScript N(EVS_UpdateSceneryPos) = {
    Call(TranslateGroup, MODEL_mac_side, -5750, 0, 0)
    Call(TranslateGroup, MODEL_turen, -3250, 0, 0)
    Call(TranslateGroup, MODEL_iwa_side, 1750, 0, 0)
    Call(GetEntryID, LVar2)
    Switch(LVar2)
        CaseEq(iwa_11_ENTRY_0)
            Set(LVar3, 350)
            Set(MV_TrainMoveSpeed, 10)
        CaseEq(iwa_11_ENTRY_1)
            Set(LVar3, 400)
            Set(MV_TrainMoveSpeed, -10)
    EndSwitch
    Loop(0)
        Set(LVar0, MV_TrainMoveDist)
        Sub(LVar0, LVar3)
        Call(SetPanTarget, CAM_DEFAULT, LVar0, 0, 0)
        Call(N(GetSectionPosOffsets))
        Call(TranslateGroup, MODEL_field_a, LVar5, 0, 0)
        Call(TranslateGroup, MODEL_field_b, LVar6, 0, 0)
        Call(TranslateGroup, MODEL_field_c, LVar7, 0, 0)
        Call(TranslateGroup, MODEL_field_d, LVar8, 0, 0)
        Call(TranslateGroup, MODEL_field_e, LVar9, 0, 0)
        Call(TranslateGroup, MODEL_field_f, LVarA, 0, 0)
        Wait(1)
    EndLoop
    Return
    End
};
