#include "jan_22.h"
#include "model.h"

#define NAME_SUFFIX _Bushes
#include "common/foliage.inc.c"
#define NAME_SUFFIX

#include "../common/MoveBush.inc.c"

EvtScript N(EVS_MoveBushes_Separate) = {
    Call(PlaySoundAtCollider, COLLIDER_o149, SOUND_SEPARATE_BUSHES, 0)
    Set(LVar0, MV_BushOffsetL)
    Set(LVar1, MV_BushOffsetR)
    Set(LVar6, 0)
    Set(LVar7, 0)
    Loop(60)
        SetF(LVar2, MV_BushOffsetL)
        SetF(LVar3, MV_BushOffsetR)
        SubF(LVar2, LVar0)
        SubF(LVar3, LVar1)
        SetF(LVar4, LVar2)
        SetF(LVar5, LVar3)
        MulF(LVar4, Float(0.09375))
        MulF(LVar5, Float(0.09375))
        MulF(LVar6, Float(0.8))
        MulF(LVar7, Float(0.8))
        AddF(LVar6, LVar4)
        AddF(LVar7, LVar5)
        AddF(LVar0, LVar6)
        AddF(LVar1, LVar7)
        Call(TranslateModel, MODEL_o143, MV_BushOffsetL, 0, 0)
        Call(TranslateModel, MODEL_o144, MV_BushOffsetR, 0, 0)
        Call(N(MoveBush_AnimateShearing), 29, LVar6)
        Call(N(MoveBush_AnimateShearing), 31, LVar7)
        Wait(1)
    EndLoop
    // script is equivalent to MoveBushTemplates.h, except for this additional line:
    Call(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o149, COLLIDER_FLAGS_UPPER_MASK)
    Return
    End
};

EvtScript N(EVS_SeparateBushesImmediately) = {
    Call(TranslateModel, MODEL_o143, -45, 0, 0)
    Call(TranslateModel, MODEL_o144, 45, 0, 0)
    Call(N(MoveBush_AnimateShearing), 29, 0)
    Call(N(MoveBush_AnimateShearing), 31, 0)
    Return
    End
};

EvtScript N(EVS_MoveBushes) = {
    Exec(N(EVS_MoveBushes_Separate))
    Call(MakeLerp, 0, 45, 30, EASING_CUBIC_OUT)
    Loop(0)
        Call(UpdateLerp)
        SetF(MV_BushOffsetR, LVar0)
        SetF(MV_BushOffsetL, MV_BushOffsetR)
        MulF(MV_BushOffsetL, -1)
        Wait(1)
        IfEq(LVar1, 0)
            BreakLoop
        EndIf
    EndLoop
    Return
    End
};

FoliageModelList N(Bush1_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o337);

FoliageVectorList N(Bush1_Effects) = {
    .count = 1,
    .vectors = {
        { -453.0f, 15.0f, 90.0f },
    }
};

SearchBushConfig N(SearchBush_Bush1) = {
    .bush = &N(Bush1_BushModels),
    .vectors = &N(Bush1_Effects),
};

FoliageModelList N(Bush2_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o338);

FoliageVectorList N(Bush2_Effects) = {
    .count = 1,
    .vectors = {
        { -292.0f, 16.0f, 135.0f },
    }
};

SearchBushConfig N(SearchBush_Bush2) = {
    .bush = &N(Bush2_BushModels),
    .vectors = &N(Bush2_Effects),
};

FoliageModelList N(Bush3_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o339);

FoliageVectorList N(Bush3_Effects) = {
    .count = 1,
    .vectors = {
        { -180.0f, 15.0f, 120.0f },
    }
};

SearchBushConfig N(SearchBush_Bush3) = {
    .bush = &N(Bush3_BushModels),
    .vectors = &N(Bush3_Effects),
};

FoliageModelList N(Bush4_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o349);

FoliageVectorList N(Bush4_Effects) = {
    .count = 1,
    .vectors = {
        { 456.0f, 16.0f, 135.0f },
    }
};

SearchBushConfig N(SearchBush_Bush4) = {
    .bush = &N(Bush4_BushModels),
    .vectors = &N(Bush4_Effects),
};

FoliageModelList N(Bush5_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o350);

FoliageVectorList N(Bush5_Effects) = {
    .count = 1,
    .vectors = {
        { 658.0f, 15.0f, 110.0f },
    }
};

SearchBushConfig N(SearchBush_Bush5) = {
    .bush = &N(Bush5_BushModels),
    .vectors = &N(Bush5_Effects),
};

FoliageModelList N(Bush6_BushModels) = FOLIAGE_MODEL_LIST(MODEL_o351);

FoliageVectorList N(Bush6_Effects) = {
    .count = 1,
    .vectors = {
        { 710.0f, 15.0f, -30.0f },
    }
};

SearchBushConfig N(SearchBush_Bush6) = {
    .bush = &N(Bush6_BushModels),
    .vectors = &N(Bush6_Effects),
};

EvtScript N(EVS_SetupBushes) = {
    Set(LVar0, Ref(N(SearchBush_Bush1)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o314, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush2)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o315, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush3)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o316, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush4)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o326, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush5)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o327, 1, 0)
    Set(LVar0, Ref(N(SearchBush_Bush6)))
    BindTrigger(Ref(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o328, 1, 0)
    Return
    End
};
