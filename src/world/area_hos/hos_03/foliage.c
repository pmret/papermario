#include "hos_03.h"
#include "effects.h"

#include "common/foliage.inc.c"

EvtScript N(EVS_ShakeTree_StarHaven) = {
    SetTimescale(Float(2.0))
    UseBuf(LVar0)
    BufRead4(LVar1, LVar2, LVar3, LVar4)
    BufRead1(LVar5)
    Call(GetPlayerPos, LVar6, LVarF, LVar8)
    Call(PlaySoundAtPlayer, SOUND_SMACK_TREE, SOUND_SPACE_DEFAULT)
    Call(PlaySoundAtPlayer, SOUND_SHAKE_TREE_LEAVES, SOUND_SPACE_DEFAULT)
    Thread
        IfNe(LVar1, 0)
            Wait(1)
            Loop(5)
                UseBuf(LVar1)
                BufRead1(LVar2)
                Loop(LVar2)
                    BufRead1(LVar3)
                    Call(N(TransformFoliage), LVar3, Float(0.1), Float(0.2), LVarF, 0)
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
        IfNe(LVar2, 0)
            Loop(5)
                UseBuf(LVar2)
                BufRead1(LVar3)
                Loop(LVar3)
                    BufRead1(LVar4)
                    Call(N(TransformFoliage), LVar4, Float(0.1), Float(0.2), LVarF, 0)
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
                PlayEffect(EFFECT_SPARKLES, 2, LVar6, LVar7, LVar8, 50)
                PlayEffect(EFFECT_SPARKLES, 2, LVar6, LVar7, LVar8, 50)
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

FoliageModelList N(Tree1_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o37, MODEL_o38, MODEL_o39);
FoliageModelList N(Tree1_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o32, MODEL_o35, MODEL_o36);

FoliageVectorList N(Tree1_Effects) = {
    .count = 2,
    .vectors = {
        { -669.0f, 60.0f, 296.0f },
        { -584.0f, 60.0f, 286.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree1) = {
    .leaves = &N(Tree1_LeafModels),
    .trunk = &N(Tree1_TrunkModels),
    .vectors = &N(Tree1_Effects),
};

BombTrigger N(BombPos_Tree1) = {
    .pos = { -629.0f, 35.0f, 296.0f },
    .radius = 0.0f
};

FoliageModelList N(Tree2_LeafModels)  = FOLIAGE_MODEL_LIST(MODEL_o43, MODEL_o44, MODEL_o45);
FoliageModelList N(Tree2_TrunkModels) = FOLIAGE_MODEL_LIST(MODEL_o40, MODEL_o41, MODEL_o42);

FoliageVectorList N(Tree2_Effects) = {
    .count = 2,
    .vectors = {
        { -528.0f, 60.0f, 324.0f },
        { -443.0f, 60.0f, 314.0f },
    }
};

ShakeTreeConfig N(ShakeTree_Tree2) = {
    .leaves = &N(Tree2_LeafModels),
    .trunk = &N(Tree2_TrunkModels),
    .vectors = &N(Tree2_Effects),
};

BombTrigger N(BombPos_Tree2) = {
    .pos = { -488.0f, 35.0f, 324.0f },
    .radius = 0.0f
};

EvtScript N(EVS_SetupFoliage) = {
    Set(LVar0, Ref(N(ShakeTree_Tree1)))
    BindTrigger(Ref(N(EVS_ShakeTree_StarHaven)), TRIGGER_WALL_HAMMER, COLLIDER_o35, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree_StarHaven)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree1)), 1, 0)
    Set(LVar0, Ref(N(ShakeTree_Tree2)))
    BindTrigger(Ref(N(EVS_ShakeTree_StarHaven)), TRIGGER_WALL_HAMMER, COLLIDER_o32, 1, 0)
    BindTrigger(Ref(N(EVS_ShakeTree_StarHaven)), TRIGGER_POINT_BOMB, Ref(N(BombPos_Tree2)), 1, 0)
    Return
    End
};
