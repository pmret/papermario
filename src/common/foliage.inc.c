#include "common.h"
#include "effects.h"

#include "FoliageTransform.inc.c"

EvtScript N(EVS_SearchBush) = {
    UseBuf(LVar0)
    BufRead4(LVar1, LVar2, LVar3, LVar4)
    Call(GetPlayerPos, LVar5, LVarF, LVar7)
    Thread
        Set(LFlag0, false)
        IfNe(LVar1, 0)
            Loop(5)
                UseBuf(LVar1)
                BufRead1(LVar2)
                Loop(LVar2)
                    BufRead1(LVar3)
                    Call(N(TransformFoliage), LVar3, Float(0.1), 1, LVarF, 0)
                    IfEq(LFlag0, false)
                        Set(LFlag0, true)
                        Call(PlaySoundAtModel, LVar3, SOUND_SEARCH_BUSH, SOUND_SPACE_DEFAULT)
                    EndIf
                EndLoop
                Wait(1)
                UseBuf(LVar1)
                BufRead1(LVar2)
                Loop(LVar2)
                    BufRead1(LVar3)
                    Call(N(TransformFoliage), LVar3, Float(0.1), -1, LVarF, 0)
                EndLoop
                Wait(1)
            EndLoop
            UseBuf(LVar1)
            BufRead1(LVar2)
            Loop(LVar2)
                BufRead1(LVar3)
                Call(TranslateModel, LVar3, 0, 0, 0)
            EndLoop
            Wait(1)
        EndIf
    EndThread
    Thread
        IfNe(LVar2, 0)
            UseBuf(LVar2)
            BufRead1(LVar3)
            Loop(LVar3)
                BufRead1(LVar4)
                BufRead3(LVar5, LVar6, LVar7)
                BufRead3(LVar8, LVar9, LVarA)
                IfEq(LVarA, 0)
                    Call(DropItemEntity, LVar4, LVar5, LVar6, LVar7, LVar8, LVar9)
                Else
                    Call(GetValueByRef, LVarA, LVarB)
                    IfEq(LVarB, 0)
                        Call(SetValueByRef, LVarA, 1)
                        Call(DropItemEntity, LVar4, LVar5, LVar6, LVar7, LVar8, LVar9)
                    EndIf
                EndIf
            EndLoop
        EndIf
    EndThread
    Wait(15)
    IfNe(LVar4, 0)
        ExecWait(LVar4)
    EndIf
    Return
    End
};

EvtScript N(EVS_ShakeTree) = {
    SetTimescale(Float(2.0))
    UseBuf(LVar0)
    BufRead4(LVar1, LVar2, LVar3, LVar4)
    BufRead1(LVar5)
    Call(GetPlayerPos, LVar6, LVarF, LVar8)
    Call(PlaySound, SOUND_SMACK_TREE)
    Call(PlaySound, SOUND_SHAKE_TREE_LEAVES)
    Thread
        Set(LFlag0, false)
        IfNe(LVar1, 0)
            Wait(1)
            Loop(5)
                UseBuf(LVar1)
                BufRead1(LVar2)
                Loop(LVar2)
                    BufRead1(LVar3)
                    Call(N(TransformFoliage), LVar3, Float(0.1), Float(0.2), LVarF, 0)
                    IfEq(LFlag0, false)
                        Set(LFlag0, true)
                        Call(PlaySoundAtModel, LVar3, SOUND_SHAKE_TREE_LEAVES, SOUND_SPACE_DEFAULT)
                    EndIf
                EndLoop
                Wait(1)
                UseBuf(LVar1)
                BufRead1(LVar2)
                Loop(LVar2)
                    BufRead1(LVar3)
                    Call(N(TransformFoliage), LVar3, Float(0.1), Float(-0.2), LVarF, 0)
                EndLoop
                Wait(1)
            EndLoop
            UseBuf(LVar1)
            BufRead1(LVar2)
            Loop(LVar2)
                BufRead1(LVar3)
                Call(TranslateModel, LVar3, 0, 0, 0)
            EndLoop
            Wait(1)
        EndIf
    EndThread
    Thread
        Set(LFlag0, false)
        IfNe(LVar2, 0)
            Loop(5)
                UseBuf(LVar2)
                BufRead1(LVar3)
                Loop(LVar3)
                    BufRead1(LVar4)
                    Call(N(TransformFoliage), LVar4, Float(0.1), Float(0.2), LVarF, 0)
                    IfEq(LFlag0, false)
                        Set(LFlag0, true)
                        Call(PlaySoundAtModel, LVar4, SOUND_SMACK_TREE, SOUND_SPACE_DEFAULT)
                    EndIf
                EndLoop
                Wait(1)
                UseBuf(LVar2)
                BufRead1(LVar3)
                Loop(LVar3)
                    BufRead1(LVar4)
                    Call(N(TransformFoliage), LVar4, Float(0.1), Float(-0.2), LVarF, 0)
                EndLoop
                Wait(1)
            EndLoop
            UseBuf(LVar2)
            BufRead1(LVar3)
            Loop(LVar3)
                BufRead1(LVar4)
                Call(TranslateModel, LVar4, 0, 0, 0)
            EndLoop
            Wait(1)
        EndIf
    EndThread
    Thread
        IfNe(LVar3, 0)
            UseBuf(LVar3)
            BufRead1(LVar4)
            Loop(LVar4)
                BufRead1(LVar5)
                BufRead3(LVar6, LVar7, LVar8)
                BufRead3(LVar9, LVarA, LVarB)
                IfEq(LVarB, 0)
                    Call(DropItemEntity, LVar5, LVar6, LVar7, LVar8, LVar9, LVarA)
                Else
                    Call(GetValueByRef, LVarB, LVarC)
                    IfEq(LVarC, 0)
                        Call(SetValueByRef, LVarB, 1)
                        Call(DropItemEntity, LVar5, LVar6, LVar7, LVar8, LVar9, LVarA)
                    EndIf
                EndIf
            EndLoop
        EndIf
    EndThread
    Thread
        IfNe(LVar4, 0)
            UseBuf(LVar4)
            BufRead1(LVar5)
            Loop(LVar5)
                BufRead3(LVar6, LVar7, LVar8)
                PlayEffect(EFFECT_DROP_LEAVES, 0, LVar6, LVar7, LVar8, 100)
            EndLoop
        EndIf
    EndThread
    IfNe(LVar5, 0)
        ExecWait(LVar5)
    EndIf
    Wait(15)
    Return
    End
};
