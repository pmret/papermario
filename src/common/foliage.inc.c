#include "common.h"

#include "FoliageTransform.inc.c"

EvtScript N(searchBush) = {
    EVT_USE_BUF(LocalVar(0))
    EVT_BUF_READ4(LocalVar(1), LocalVar(2), LocalVar(3), LocalVar(4))
    EVT_CALL(GetPlayerPos, LocalVar(5), LocalVar(15), LocalVar(7))
    EVT_THREAD
        EVT_SET(LocalFlag(0), 0)
        EVT_IF_NE(LocalVar(1), 0)
            EVT_LOOP(5)
                EVT_USE_BUF(LocalVar(1))
                EVT_BUF_READ1(LocalVar(2))
                EVT_LOOP(LocalVar(2))
                    EVT_BUF_READ1(LocalVar(3))
                    EVT_CALL(N(TransformFoliage), LocalVar(3), EVT_FIXED(0.1), 1, LocalVar(15), 0)
                    EVT_IF_EQ(LocalFlag(0), 0)
                        EVT_SET(LocalFlag(0), 1)
                        EVT_CALL(PlaySoundAtModel, LocalVar(3), 339, 0)
                    EVT_END_IF
                EVT_END_LOOP
                EVT_WAIT(1)
                EVT_USE_BUF(LocalVar(1))
                EVT_BUF_READ1(LocalVar(2))
                EVT_LOOP(LocalVar(2))
                    EVT_BUF_READ1(LocalVar(3))
                    EVT_CALL(N(TransformFoliage), LocalVar(3), EVT_FIXED(0.1), -1, LocalVar(15), 0)
                EVT_END_LOOP
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_USE_BUF(LocalVar(1))
            EVT_BUF_READ1(LocalVar(2))
            EVT_LOOP(LocalVar(2))
                EVT_BUF_READ1(LocalVar(3))
                EVT_CALL(TranslateModel, LocalVar(3), 0, 0, 0)
            EVT_END_LOOP
            EVT_WAIT(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(LocalVar(2), 0)
            EVT_USE_BUF(LocalVar(2))
            EVT_BUF_READ1(LocalVar(3))
            EVT_LOOP(LocalVar(3))
                EVT_BUF_READ1(LocalVar(4))
                EVT_BUF_READ3(LocalVar(5), LocalVar(6), LocalVar(7))
                EVT_BUF_READ3(LocalVar(8), LocalVar(9), LocalVar(10))
                EVT_IF_EQ(LocalVar(10), 0)
                    EVT_CALL(DropItemEntity, LocalVar(4), LocalVar(5), LocalVar(6), LocalVar(7), LocalVar(8), LocalVar(9))
                EVT_ELSE
                    EVT_CALL(GetValueByRef, LocalVar(10), LocalVar(11))
                    EVT_IF_EQ(LocalVar(11), 0)
                        EVT_CALL(SetValueByRef, LocalVar(10), 1)
                        EVT_CALL(DropItemEntity, LocalVar(4), LocalVar(5), LocalVar(6), LocalVar(7), LocalVar(8), LocalVar(9))
                    EVT_END_IF
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT(15)
    EVT_IF_NE(LocalVar(4), 0)
        EVT_EXEC_WAIT(LocalVar(4))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtScript N(shakeTree) = {
    EVT_SET_TIMESCALE(EVT_FIXED(2.0))
    EVT_USE_BUF(LocalVar(0))
    EVT_BUF_READ4(LocalVar(1), LocalVar(2), LocalVar(3), LocalVar(4))
    EVT_BUF_READ1(LocalVar(5))
    EVT_CALL(GetPlayerPos, LocalVar(6), LocalVar(15), LocalVar(8))
    EVT_CALL(PlaySound, SOUND_SMASH_GOOMNUT_TREE)
    EVT_CALL(PlaySound, 358)
    EVT_THREAD
        EVT_SET(LocalFlag(0), 0)
        EVT_IF_NE(LocalVar(1), 0)
            EVT_WAIT(1)
            EVT_LOOP(5)
                EVT_USE_BUF(LocalVar(1))
                EVT_BUF_READ1(LocalVar(2))
                EVT_LOOP(LocalVar(2))
                    EVT_BUF_READ1(LocalVar(3))
                    EVT_CALL(N(TransformFoliage), LocalVar(3), EVT_FIXED(0.1), EVT_FIXED(0.2), LocalVar(15), 0)
                    EVT_IF_EQ(LocalFlag(0), 0)
                        EVT_SET(LocalFlag(0), 1)
                        EVT_CALL(PlaySoundAtModel, LocalVar(3), 358, 0)
                    EVT_END_IF
                EVT_END_LOOP
                EVT_WAIT(1)
                EVT_USE_BUF(LocalVar(1))
                EVT_BUF_READ1(LocalVar(2))
                EVT_LOOP(LocalVar(2))
                    EVT_BUF_READ1(LocalVar(3))
                    EVT_CALL(N(TransformFoliage), LocalVar(3), EVT_FIXED(0.1), EVT_FIXED(-0.2), LocalVar(15), 0)
                EVT_END_LOOP
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_USE_BUF(LocalVar(1))
            EVT_BUF_READ1(LocalVar(2))
            EVT_LOOP(LocalVar(2))
                EVT_BUF_READ1(LocalVar(3))
                EVT_CALL(TranslateModel, LocalVar(3), 0, 0, 0)
            EVT_END_LOOP
            EVT_WAIT(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(LocalFlag(0), 0)
        EVT_IF_NE(LocalVar(2), 0)
            EVT_LOOP(5)
                EVT_USE_BUF(LocalVar(2))
                EVT_BUF_READ1(LocalVar(3))
                EVT_LOOP(LocalVar(3))
                    EVT_BUF_READ1(LocalVar(4))
                    EVT_CALL(N(TransformFoliage), LocalVar(4), EVT_FIXED(0.1), EVT_FIXED(0.2), LocalVar(15), 0)
                    EVT_IF_EQ(LocalFlag(0), 0)
                        EVT_SET(LocalFlag(0), 1)
                        EVT_CALL(PlaySoundAtModel, LocalVar(4), 357, 0)
                    EVT_END_IF
                EVT_END_LOOP
                EVT_WAIT(1)
                EVT_USE_BUF(LocalVar(2))
                EVT_BUF_READ1(LocalVar(3))
                EVT_LOOP(LocalVar(3))
                    EVT_BUF_READ1(LocalVar(4))
                    EVT_CALL(N(TransformFoliage), LocalVar(4), EVT_FIXED(0.1), EVT_FIXED(-0.2), LocalVar(15), 0)
                EVT_END_LOOP
                EVT_WAIT(1)
            EVT_END_LOOP
            EVT_USE_BUF(LocalVar(2))
            EVT_BUF_READ1(LocalVar(3))
            EVT_LOOP(LocalVar(3))
                EVT_BUF_READ1(LocalVar(4))
                EVT_CALL(TranslateModel, LocalVar(4), 0, 0, 0)
            EVT_END_LOOP
            EVT_WAIT(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(LocalVar(3), 0)
            EVT_USE_BUF(LocalVar(3))
            EVT_BUF_READ1(LocalVar(4))
            EVT_LOOP(LocalVar(4))
                EVT_BUF_READ1(LocalVar(5))
                EVT_BUF_READ3(LocalVar(6), LocalVar(7), LocalVar(8))
                EVT_BUF_READ3(LocalVar(9), LocalVar(10), LocalVar(11))
                EVT_IF_EQ(LocalVar(11), 0)
                    EVT_CALL(DropItemEntity, LocalVar(5), LocalVar(6), LocalVar(7), LocalVar(8), LocalVar(9), LocalVar(10))
                EVT_ELSE
                    EVT_CALL(GetValueByRef, LocalVar(11), LocalVar(12))
                    EVT_IF_EQ(LocalVar(12), 0)
                        EVT_CALL(SetValueByRef, LocalVar(11), 1)
                        EVT_CALL(DropItemEntity, LocalVar(5), LocalVar(6), LocalVar(7), LocalVar(8), LocalVar(9), LocalVar(10))
                    EVT_END_IF
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(LocalVar(4), 0)
            EVT_USE_BUF(LocalVar(4))
            EVT_BUF_READ1(LocalVar(5))
            EVT_LOOP(LocalVar(5))
                EVT_BUF_READ3(LocalVar(6), LocalVar(7), LocalVar(8))
                EVT_CALL(PlayEffect, 0x14, 0, LocalVar(6), LocalVar(7), LocalVar(8), 100, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_THREAD
    EVT_IF_NE(LocalVar(5), 0)
        EVT_EXEC_WAIT(LocalVar(5))
    EVT_END_IF
    EVT_WAIT(15)
    EVT_RETURN
    EVT_END
};
