#include "common.h"
#include "model.h"

#define EVT_MOVE_BUSHES(collider, bushModelL, bushmodelR, moveVarL, moveVarR) \
{ \
    EVT_CALL(PlaySoundAtCollider, collider, SOUND_SEPARATE_BUSHES, 0) \
    EVT_SET(LVar0, moveVarL) \
    EVT_SET(LVar1, moveVarR) \
    EVT_SET(LVar6, 0) \
    EVT_SET(LVar7, 0) \
    EVT_LOOP(60) \
        EVT_SETF(LVar2, moveVarL) \
        EVT_SETF(LVar3, moveVarR) \
        EVT_SUBF(LVar2, LVar0) \
        EVT_SUBF(LVar3, LVar1) \
        EVT_SETF(LVar4, LVar2) \
        EVT_SETF(LVar5, LVar3) \
        EVT_MULF(LVar4, EVT_FLOAT(0.09375)) \
        EVT_MULF(LVar5, EVT_FLOAT(0.09375)) \
        EVT_MULF(LVar6, EVT_FLOAT(0.8)) \
        EVT_MULF(LVar7, EVT_FLOAT(0.8)) \
        EVT_ADDF(LVar6, LVar4) \
        EVT_ADDF(LVar7, LVar5) \
        EVT_ADDF(LVar0, LVar6) \
        EVT_ADDF(LVar1, LVar7) \
        EVT_CALL(TranslateModel, bushModelL, moveVarL, 0, 0) \
        EVT_CALL(TranslateModel, bushmodelR, moveVarR, 0, 0) \
        EVT_CALL(N(MoveBush_AnimateShearing), bushModelL, LVar6) \
        EVT_CALL(N(MoveBush_AnimateShearing), bushmodelR, LVar7) \
        EVT_WAIT(1) \
    EVT_END_LOOP \
    EVT_RETURN \
    EVT_END \
}

#define EVT_MOVE_BUSH(collider, bushModel, moveVar) \
{ \
    EVT_CALL(PlaySoundAtCollider, collider, SOUND_SEPARATE_BUSHES, 0) \
    EVT_SET(LVar0, MV_CliffTopBush1OffsetR) \
    EVT_SET(LVar6, 0) \
    EVT_LOOP(60) \
        EVT_SETF(LVar2, moveVar) \
        EVT_SUBF(LVar2, LVar0) \
        EVT_SETF(LVar4, LVar2) \
        EVT_MULF(LVar4, EVT_FLOAT(0.09375)) \
        EVT_MULF(LVar6, EVT_FLOAT(0.8)) \
        EVT_ADDF(LVar6, LVar4) \
        EVT_ADDF(LVar0, LVar6) \
        EVT_CALL(TranslateModel, bushModel, moveVar, 0, 0) \
        EVT_CALL(N(MoveBush_AnimateShearing), bushModel, LVar6) \
        EVT_WAIT(1) \
    EVT_END_LOOP \
    EVT_RETURN \
    EVT_END \
}
