#include "common.h"

#include "FoliageTransform.inc.c"

EvtSource N(searchBush) = {
    EVT_USE_BUF(EVT_VAR(0))
    EVT_BUF_READ4(EVT_VAR(1), EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
    EVT_CALL(GetPlayerPos, EVT_VAR(5), EVT_VAR(15), EVT_VAR(7))
    EVT_THREAD
        EVT_SET(EVT_FLAG(0), 0)
        EVT_IF_NE(EVT_VAR(1), 0)
            EVT_LOOP(5)
                EVT_USE_BUF(EVT_VAR(1))
                EVT_BUF_READ1(EVT_VAR(2))
                EVT_LOOP(EVT_VAR(2))
                    EVT_BUF_READ1(EVT_VAR(3))
                    EVT_CALL(N(TransformFoliage), EVT_VAR(3), EVT_FIXED(0.1), 1, EVT_VAR(15), 0)
                    EVT_IF_EQ(EVT_FLAG(0), 0)
                        EVT_SET(EVT_FLAG(0), 1)
                        EVT_CALL(PlaySoundAtModel, EVT_VAR(3), 339, 0)
                    EVT_END_IF
                EVT_END_LOOP
                EVT_WAIT_FRAMES(1)
                EVT_USE_BUF(EVT_VAR(1))
                EVT_BUF_READ1(EVT_VAR(2))
                EVT_LOOP(EVT_VAR(2))
                    EVT_BUF_READ1(EVT_VAR(3))
                    EVT_CALL(N(TransformFoliage), EVT_VAR(3), EVT_FIXED(0.1), -1, EVT_VAR(15), 0)
                EVT_END_LOOP
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_USE_BUF(EVT_VAR(1))
            EVT_BUF_READ1(EVT_VAR(2))
            EVT_LOOP(EVT_VAR(2))
                EVT_BUF_READ1(EVT_VAR(3))
                EVT_CALL(TranslateModel, EVT_VAR(3), 0, 0, 0)
            EVT_END_LOOP
            EVT_WAIT_FRAMES(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(EVT_VAR(2), 0)
            EVT_USE_BUF(EVT_VAR(2))
            EVT_BUF_READ1(EVT_VAR(3))
            EVT_LOOP(EVT_VAR(3))
                EVT_BUF_READ1(EVT_VAR(4))
                EVT_BUF_READ3(EVT_VAR(5), EVT_VAR(6), EVT_VAR(7))
                EVT_BUF_READ3(EVT_VAR(8), EVT_VAR(9), EVT_VAR(10))
                EVT_IF_EQ(EVT_VAR(10), 0)
                    EVT_CALL(DropItemEntity, EVT_VAR(4), EVT_VAR(5), EVT_VAR(6), EVT_VAR(7), EVT_VAR(8), EVT_VAR(9))
                EVT_ELSE
                    EVT_CALL(GetValueByRef, EVT_VAR(10), EVT_VAR(11))
                    EVT_IF_EQ(EVT_VAR(11), 0)
                        EVT_CALL(SetValueByRef, EVT_VAR(10), 1)
                        EVT_CALL(DropItemEntity, EVT_VAR(4), EVT_VAR(5), EVT_VAR(6), EVT_VAR(7), EVT_VAR(8), EVT_VAR(9))
                    EVT_END_IF
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_THREAD
    EVT_WAIT_FRAMES(15)
    EVT_IF_NE(EVT_VAR(4), 0)
        EVT_EXEC_WAIT(EVT_VAR(4))
    EVT_END_IF
    EVT_RETURN
    EVT_END
};

EvtSource N(shakeTree) = {
    EVT_SET_TIMESCALE(EVT_FIXED(2.0))
    EVT_USE_BUF(EVT_VAR(0))
    EVT_BUF_READ4(EVT_VAR(1), EVT_VAR(2), EVT_VAR(3), EVT_VAR(4))
    EVT_BUF_READ1(EVT_VAR(5))
    EVT_CALL(GetPlayerPos, EVT_VAR(6), EVT_VAR(15), EVT_VAR(8))
    EVT_CALL(PlaySound, SOUND_SMASH_GOOMNUT_TREE)
    EVT_CALL(PlaySound, 358)
    EVT_THREAD
        EVT_SET(EVT_FLAG(0), 0)
        EVT_IF_NE(EVT_VAR(1), 0)
            EVT_WAIT_FRAMES(1)
            EVT_LOOP(5)
                EVT_USE_BUF(EVT_VAR(1))
                EVT_BUF_READ1(EVT_VAR(2))
                EVT_LOOP(EVT_VAR(2))
                    EVT_BUF_READ1(EVT_VAR(3))
                    EVT_CALL(N(TransformFoliage), EVT_VAR(3), EVT_FIXED(0.1), EVT_FIXED(0.2), EVT_VAR(15), 0)
                    EVT_IF_EQ(EVT_FLAG(0), 0)
                        EVT_SET(EVT_FLAG(0), 1)
                        EVT_CALL(PlaySoundAtModel, EVT_VAR(3), 358, 0)
                    EVT_END_IF
                EVT_END_LOOP
                EVT_WAIT_FRAMES(1)
                EVT_USE_BUF(EVT_VAR(1))
                EVT_BUF_READ1(EVT_VAR(2))
                EVT_LOOP(EVT_VAR(2))
                    EVT_BUF_READ1(EVT_VAR(3))
                    EVT_CALL(N(TransformFoliage), EVT_VAR(3), EVT_FIXED(0.1), EVT_FIXED(-0.2), EVT_VAR(15), 0)
                EVT_END_LOOP
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_USE_BUF(EVT_VAR(1))
            EVT_BUF_READ1(EVT_VAR(2))
            EVT_LOOP(EVT_VAR(2))
                EVT_BUF_READ1(EVT_VAR(3))
                EVT_CALL(TranslateModel, EVT_VAR(3), 0, 0, 0)
            EVT_END_LOOP
            EVT_WAIT_FRAMES(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_SET(EVT_FLAG(0), 0)
        EVT_IF_NE(EVT_VAR(2), 0)
            EVT_LOOP(5)
                EVT_USE_BUF(EVT_VAR(2))
                EVT_BUF_READ1(EVT_VAR(3))
                EVT_LOOP(EVT_VAR(3))
                    EVT_BUF_READ1(EVT_VAR(4))
                    EVT_CALL(N(TransformFoliage), EVT_VAR(4), EVT_FIXED(0.1), EVT_FIXED(0.2), EVT_VAR(15), 0)
                    EVT_IF_EQ(EVT_FLAG(0), 0)
                        EVT_SET(EVT_FLAG(0), 1)
                        EVT_CALL(PlaySoundAtModel, EVT_VAR(4), 357, 0)
                    EVT_END_IF
                EVT_END_LOOP
                EVT_WAIT_FRAMES(1)
                EVT_USE_BUF(EVT_VAR(2))
                EVT_BUF_READ1(EVT_VAR(3))
                EVT_LOOP(EVT_VAR(3))
                    EVT_BUF_READ1(EVT_VAR(4))
                    EVT_CALL(N(TransformFoliage), EVT_VAR(4), EVT_FIXED(0.1), EVT_FIXED(-0.2), EVT_VAR(15), 0)
                EVT_END_LOOP
                EVT_WAIT_FRAMES(1)
            EVT_END_LOOP
            EVT_USE_BUF(EVT_VAR(2))
            EVT_BUF_READ1(EVT_VAR(3))
            EVT_LOOP(EVT_VAR(3))
                EVT_BUF_READ1(EVT_VAR(4))
                EVT_CALL(TranslateModel, EVT_VAR(4), 0, 0, 0)
            EVT_END_LOOP
            EVT_WAIT_FRAMES(1)
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(EVT_VAR(3), 0)
            EVT_USE_BUF(EVT_VAR(3))
            EVT_BUF_READ1(EVT_VAR(4))
            EVT_LOOP(EVT_VAR(4))
                EVT_BUF_READ1(EVT_VAR(5))
                EVT_BUF_READ3(EVT_VAR(6), EVT_VAR(7), EVT_VAR(8))
                EVT_BUF_READ3(EVT_VAR(9), EVT_VAR(10), EVT_VAR(11))
                EVT_IF_EQ(EVT_VAR(11), 0)
                    EVT_CALL(DropItemEntity, EVT_VAR(5), EVT_VAR(6), EVT_VAR(7), EVT_VAR(8), EVT_VAR(9), EVT_VAR(10))
                EVT_ELSE
                    EVT_CALL(GetValueByRef, EVT_VAR(11), EVT_VAR(12))
                    EVT_IF_EQ(EVT_VAR(12), 0)
                        EVT_CALL(SetValueByRef, EVT_VAR(11), 1)
                        EVT_CALL(DropItemEntity, EVT_VAR(5), EVT_VAR(6), EVT_VAR(7), EVT_VAR(8), EVT_VAR(9), EVT_VAR(10))
                    EVT_END_IF
                EVT_END_IF
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_THREAD
    EVT_THREAD
        EVT_IF_NE(EVT_VAR(4), 0)
            EVT_USE_BUF(EVT_VAR(4))
            EVT_BUF_READ1(EVT_VAR(5))
            EVT_LOOP(EVT_VAR(5))
                EVT_BUF_READ3(EVT_VAR(6), EVT_VAR(7), EVT_VAR(8))
                EVT_CALL(PlayEffect, 0x14, 0, EVT_VAR(6), EVT_VAR(7), EVT_VAR(8), 100, 0, 0, 0, 0, 0, 0, 0, 0)
            EVT_END_LOOP
        EVT_END_IF
    EVT_END_THREAD
    EVT_IF_NE(EVT_VAR(5), 0)
        EVT_EXEC_WAIT(EVT_VAR(5))
    EVT_END_IF
    EVT_WAIT_FRAMES(15)
    EVT_RETURN
    EVT_END
};
