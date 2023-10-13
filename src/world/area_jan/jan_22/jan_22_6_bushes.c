#include "jan_22.h"
#include "model.h"

#define NAME_SUFFIX _Bushes
#include "common/foliage.inc.c"
#define NAME_SUFFIX

#include "../common/MoveBush.inc.c"

EvtScript N(EVS_MoveBushes_Separate) = {
    EVT_CALL(PlaySoundAtCollider, COLLIDER_o149, SOUND_SEPARATE_BUSHES, 0)
    EVT_SET(LVar0, MV_BushOffsetL)
    EVT_SET(LVar1, MV_BushOffsetR)
    EVT_SET(LVar6, 0)
    EVT_SET(LVar7, 0)
    EVT_LOOP(60)
        EVT_SETF(LVar2, MV_BushOffsetL)
        EVT_SETF(LVar3, MV_BushOffsetR)
        EVT_SUBF(LVar2, LVar0)
        EVT_SUBF(LVar3, LVar1)
        EVT_SETF(LVar4, LVar2)
        EVT_SETF(LVar5, LVar3)
        EVT_MULF(LVar4, EVT_FLOAT(0.09375))
        EVT_MULF(LVar5, EVT_FLOAT(0.09375))
        EVT_MULF(LVar6, EVT_FLOAT(0.8))
        EVT_MULF(LVar7, EVT_FLOAT(0.8))
        EVT_ADDF(LVar6, LVar4)
        EVT_ADDF(LVar7, LVar5)
        EVT_ADDF(LVar0, LVar6)
        EVT_ADDF(LVar1, LVar7)
        EVT_CALL(TranslateModel, MODEL_o143, MV_BushOffsetL, 0, 0)
        EVT_CALL(TranslateModel, MODEL_o144, MV_BushOffsetR, 0, 0)
        EVT_CALL(N(MoveBush_AnimateShearing), 29, LVar6)
        EVT_CALL(N(MoveBush_AnimateShearing), 31, LVar7)
        EVT_WAIT(1)
    EVT_END_LOOP
    // script is equivalent to MoveBushTemplates.h, except for this additional line:
    EVT_CALL(ModifyColliderFlags, MODIFY_COLLIDER_FLAGS_SET_BITS, COLLIDER_o149, COLLIDER_FLAGS_UPPER_MASK)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_SeparateBushesImmediately) = {
    EVT_CALL(TranslateModel, MODEL_o143, -45, 0, 0)
    EVT_CALL(TranslateModel, MODEL_o144, 45, 0, 0)
    EVT_CALL(N(MoveBush_AnimateShearing), 29, 0)
    EVT_CALL(N(MoveBush_AnimateShearing), 31, 0)
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_MoveBushes) = {
    EVT_EXEC(N(EVS_MoveBushes_Separate))
    EVT_CALL(MakeLerp, 0, 45, 30, EASING_CUBIC_OUT)
    EVT_LOOP(0)
        EVT_CALL(UpdateLerp)
        EVT_SETF(MV_BushOffsetR, LVar0)
        EVT_SETF(MV_BushOffsetL, MV_BushOffsetR)
        EVT_MULF(MV_BushOffsetL, -1)
        EVT_WAIT(1)
        EVT_IF_EQ(LVar1, 0)
            EVT_BREAK_LOOP
        EVT_END_IF
    EVT_END_LOOP
    EVT_RETURN
    EVT_END
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
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush1)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o314, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush2)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o315, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush3)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o316, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush4)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o326, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush5)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o327, 1, 0)
    EVT_SET(LVar0, EVT_PTR(N(SearchBush_Bush6)))
    EVT_BIND_TRIGGER(EVT_PTR(N(EVS_SearchBush_Bushes)), TRIGGER_WALL_PRESS_A, COLLIDER_o328, 1, 0)
    EVT_RETURN
    EVT_END
};
