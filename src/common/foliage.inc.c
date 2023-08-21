#include "common.h"
#include "effects.h"

#include "FoliageTransform.inc.c"

EvtScript N(EVS_SearchBush) = {
    EVT_USE_BUF(LVar0)
    EVT_BUF_READ4(LVar1, LVar2, LVar3, LVar4)
    EVT_CALL(GetPlayerPos, LVar5, LVarF, LVar7)
    EVT_THREAD
        EVT_SET(LFlag0, FALSE)
        EVT_IF_NE(LVar1, 0)
            EVT_LOOP(5)
                EVT_USE_BUF(LVar1)
                EVT_BUF_READ1(LVar2)
                EVT_LOOP(LVar2)
                    EVT_BUF_READ1(LVar3)
                    EVT_CALL(N(TransformFoliage), LVar3, EVT_FLOAT(0.1), 1, LVarF, 0)
                    EVT_IF_EQ(LFlag0, FALSE)
                        EVT_SET(LFlag0, TRUE)
                        EVT_CALL(PlaySoundAtModel, LVar3, SOUND_SEARCH_BUSH, SOUND_SPACE_DEFAULT)
                    EVT_END_IF
                EVT_END_LOOP
                EVT_WAIT(1)
                EVT_USE_BUF(LVar1)
                EVT_BUF_READ1(LVar2)
                EVT_LOOP(LVar2)
                    EVT_BUF_READ1(LVar3)
                    EVT_CALL(N(TransformFoliage), LVar3, EVT_FLOAT(0.1), -1, LVarF, 0)
                EVT_END_LOOP
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_USE_BUF(LVar1)
            EVT_BUF_READ1(LVar2)
            EVT_LOOP(LVar2)
                EVT_BUF_READ1(LVar3)
                EVT_CALL(TranslateModel, LVar3, 0, 0, 0)
            EVT_END_LOOP
            EVT_WAIT(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(LVar2, 0)
            EVT_USE_BUF(LVar2)
            EVT_BUF_READ1(LVar3)
            EVT_LOOP(LVar3)
                EVT_BUF_READ1(LVar4)
                EVT_BUF_READ3(LVar5, LVar6, LVar7)
                EVT_BUF_READ3(LVar8, LVar9, LVarA)
                EVT_IF_EQ(LVarA, 0)
                    EVT_CALL(DropItemEntity, LVar4, LVar5, LVar6, LVar7, LVar8, LVar9)
                EVT_ELSE
                    EVT_CALL(GetValueByRef, LVarA, LVarB)
                    EVT_IF_EQ(LVarB, 0)
                        EVT_CALL(SetValueByRef, LVarA, 1)
                        EVT_CALL(DropItemEntity, LVar4, LVar5, LVar6, LVar7, LVar8, LVar9)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_IF_NE(LVar4, 0)
        EVT_EXEC_WAIT(LVar4)
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(EVS_ShakeTree) = {
    EVT_SET_TIMESCALE(EVT_FLOAT(2.0))
    EVT_USE_BUF(LVar0)
    EVT_BUF_READ4(LVar1, LVar2, LVar3, LVar4)
    EVT_BUF_READ1(LVar5)
    EVT_CALL(GetPlayerPos, LVar6, LVarF, LVar8)
    EVT_CALL(PlaySound, SOUND_SMACK_TREE)
    EVT_CALL(PlaySound, SOUND_SHAKE_TREE_LEAVES)
    EVT_THREAD
        EVT_SET(LFlag0, FALSE)
        EVT_IF_NE(LVar1, 0)
            EVT_WAIT(1)
            EVT_LOOP(5)
                EVT_USE_BUF(LVar1)
                EVT_BUF_READ1(LVar2)
                EVT_LOOP(LVar2)
                    EVT_BUF_READ1(LVar3)
                    EVT_CALL(N(TransformFoliage), LVar3, EVT_FLOAT(0.1), EVT_FLOAT(0.2), LVarF, 0)
                    EVT_IF_EQ(LFlag0, FALSE)
                        EVT_SET(LFlag0, TRUE)
                        EVT_CALL(PlaySoundAtModel, LVar3, SOUND_SHAKE_TREE_LEAVES, SOUND_SPACE_DEFAULT)
                    EVT_END_IF
                EVT_END_LOOP
                EVT_WAIT(1)
                EVT_USE_BUF(LVar1)
                EVT_BUF_READ1(LVar2)
                EVT_LOOP(LVar2)
                    EVT_BUF_READ1(LVar3)
                    EVT_CALL(N(TransformFoliage), LVar3, EVT_FLOAT(0.1), EVT_FLOAT(-0.2), LVarF, 0)
                EVT_END_LOOP
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_USE_BUF(LVar1)
            EVT_BUF_READ1(LVar2)
            EVT_LOOP(LVar2)
                EVT_BUF_READ1(LVar3)
                EVT_CALL(TranslateModel, LVar3, 0, 0, 0)
            EVT_END_LOOP
            EVT_WAIT(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LFlag0, FALSE)
        EVT_IF_NE(LVar2, 0)
            EVT_LOOP(5)
                EVT_USE_BUF(LVar2)
                EVT_BUF_READ1(LVar3)
                EVT_LOOP(LVar3)
                    EVT_BUF_READ1(LVar4)
                    EVT_CALL(N(TransformFoliage), LVar4, EVT_FLOAT(0.1), EVT_FLOAT(0.2), LVarF, 0)
                    EVT_IF_EQ(LFlag0, FALSE)
                        EVT_SET(LFlag0, TRUE)
                        EVT_CALL(PlaySoundAtModel, LVar4, SOUND_SMACK_TREE, SOUND_SPACE_DEFAULT)
                    EVT_END_IF
                EVT_END_LOOP
                EVT_WAIT(1)
                EVT_USE_BUF(LVar2)
                EVT_BUF_READ1(LVar3)
                EVT_LOOP(LVar3)
                    EVT_BUF_READ1(LVar4)
                    EVT_CALL(N(TransformFoliage), LVar4, EVT_FLOAT(0.1), EVT_FLOAT(-0.2), LVarF, 0)
                EVT_END_LOOP
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_USE_BUF(LVar2)
            EVT_BUF_READ1(LVar3)
            EVT_LOOP(LVar3)
                EVT_BUF_READ1(LVar4)
                EVT_CALL(TranslateModel, LVar4, 0, 0, 0)
            EVT_END_LOOP
            EVT_WAIT(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(LVar3, 0)
            EVT_USE_BUF(LVar3)
            EVT_BUF_READ1(LVar4)
            EVT_LOOP(LVar4)
                EVT_BUF_READ1(LVar5)
                EVT_BUF_READ3(LVar6, LVar7, LVar8)
                EVT_BUF_READ3(LVar9, LVarA, LVarB)
                EVT_IF_EQ(LVarB, 0)
                    EVT_CALL(DropItemEntity, LVar5, LVar6, LVar7, LVar8, LVar9, LVarA)
                EVT_ELSE
                    EVT_CALL(GetValueByRef, LVarB, LVarC)
                    EVT_IF_EQ(LVarC, 0)
                        EVT_CALL(SetValueByRef, LVarB, 1)
                        EVT_CALL(DropItemEntity, LVar5, LVar6, LVar7, LVar8, LVar9, LVarA)
                    EVT_END_IF
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(LVar4, 0)
            EVT_USE_BUF(LVar4)
            EVT_BUF_READ1(LVar5)
            EVT_LOOP(LVar5)
                EVT_BUF_READ3(LVar6, LVar7, LVar8)
                EVT_PLAY_EFFECT(EFFECT_DROP_LEAVES, 0, LVar6, LVar7, LVar8, 100)
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_THREAD
    EVT_IF_NE(LVar5, 0)
        EVT_EXEC_WAIT(LVar5)
    EVT_END_IF
    EVT_WAIT(15)
    EVT_RETURN
    EVT_END
};
