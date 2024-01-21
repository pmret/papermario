#include "common.h"
#include "model.h"

#define EVT_MOVE_BUSHES(collider, bushModelL, bushmodelR, moveVarL, moveVarR) \
{ \
    Call(PlaySoundAtCollider, collider, SOUND_SEPARATE_BUSHES, 0) \
    Set(LVar0, moveVarL) \
    Set(LVar1, moveVarR) \
    Set(LVar6, 0) \
    Set(LVar7, 0) \
    Loop(60) \
        SetF(LVar2, moveVarL) \
        SetF(LVar3, moveVarR) \
        SubF(LVar2, LVar0) \
        SubF(LVar3, LVar1) \
        SetF(LVar4, LVar2) \
        SetF(LVar5, LVar3) \
        MulF(LVar4, Float(0.09375)) \
        MulF(LVar5, Float(0.09375)) \
        MulF(LVar6, Float(0.8)) \
        MulF(LVar7, Float(0.8)) \
        AddF(LVar6, LVar4) \
        AddF(LVar7, LVar5) \
        AddF(LVar0, LVar6) \
        AddF(LVar1, LVar7) \
        Call(TranslateModel, bushModelL, moveVarL, 0, 0) \
        Call(TranslateModel, bushmodelR, moveVarR, 0, 0) \
        Call(N(MoveBush_AnimateShearing), bushModelL, LVar6) \
        Call(N(MoveBush_AnimateShearing), bushmodelR, LVar7) \
        Wait(1) \
    EndLoop \
    Return \
    End \
}

#define EVT_MOVE_BUSH(collider, bushModel, moveVar) \
{ \
    Call(PlaySoundAtCollider, collider, SOUND_SEPARATE_BUSHES, 0) \
    Set(LVar0, MV_CliffTopBush1OffsetR) \
    Set(LVar6, 0) \
    Loop(60) \
        SetF(LVar2, moveVar) \
        SubF(LVar2, LVar0) \
        SetF(LVar4, LVar2) \
        MulF(LVar4, Float(0.09375)) \
        MulF(LVar6, Float(0.8)) \
        AddF(LVar6, LVar4) \
        AddF(LVar0, LVar6) \
        Call(TranslateModel, bushModel, moveVar, 0, 0) \
        Call(N(MoveBush_AnimateShearing), bushModel, LVar6) \
        Wait(1) \
    EndLoop \
    Return \
    End \
}
