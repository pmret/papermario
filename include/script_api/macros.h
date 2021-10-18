#ifndef _SCRIPT_API_MACROS_H_
#define _SCRIPT_API_MACROS_H_

#include "evt.h"

#define EVT_END                                 EVT_CMD(EVT_OP_END),
#define EVT_RETURN                              EVT_CMD(EVT_OP_RETURN),
#define EVT_JUMP(EVT_SOURCE)                    EVT_CMD(EVT_OP_JUMP, (Bytecode) EVT_SOURCE),

#define EVT_LABEL(LABEL_ID)                     EVT_CMD(EVT_OP_LABEL, LABEL_ID),
#define EVT_GOTO(LABEL_ID)                      EVT_CMD(EVT_OP_GOTO, LABEL_ID),

#define EVT_LOOP(TIMES)                         EVT_CMD(EVT_OP_LOOP, TIMES),
#define EVT_END_LOOP                            EVT_CMD(EVT_OP_END_LOOP),
#define EVT_BREAK_LOOP                          EVT_CMD(EVT_OP_BREAK_LOOP),

#define EVT_WAIT_FRAMES(NUM_FRAMES)             EVT_CMD(EVT_OP_WAIT_FRAMES, NUM_FRAMES),
#define EVT_WAIT_SECS(NUM_SECONDS)              EVT_CMD(EVT_OP_WAIT_SECS, NUM_SECONDS),

#define EVT_IF_EQ(LVAR, RVAR)                   EVT_CMD(EVT_OP_IF_EQ, LVAR, RVAR),
#define EVT_IF_NE(LVAR, RVAR)                   EVT_CMD(EVT_OP_IF_NE, LVAR, RVAR),
#define EVT_IF_LT(LVAR, RVAR)                   EVT_CMD(EVT_OP_IF_LT, LVAR, RVAR),
#define EVT_IF_GT(LVAR, RVAR)                   EVT_CMD(EVT_OP_IF_GT, LVAR, RVAR),
#define EVT_IF_LE(LVAR, RVAR)                   EVT_CMD(EVT_OP_IF_LE, LVAR, RVAR),
#define EVT_IF_GE(LVAR, RVAR)                   EVT_CMD(EVT_OP_IF_GE, LVAR, RVAR),
#define EVT_IF_FLAG(LVAR, RVAR)                 EVT_CMD(EVT_OP_IF_FLAG, LVAR, RVAR),
#define EVT_IF_NOT_FLAG(LVAR, RVAR)             EVT_CMD(EVT_OP_IF_NOT_FLAG, LVAR, RVAR),
#define EVT_ELSE                                EVT_CMD(EVT_OP_ELSE),
#define EVT_END_IF                              EVT_CMD(EVT_OP_END_IF),

#define EVT_SWITCH(LVAR)                        EVT_CMD(EVT_OP_SWITCH, LVAR),
#define EVT_SWITCH_CONST(LCONST)                EVT_CMD(EVT_OP_SWITCH_CONST, LCONST),
#define EVT_CASE_EQ(RVAR)                       EVT_CMD(EVT_OP_CASE_EQ, RVAR),
#define EVT_CASE_NE(RVAR)                       EVT_CMD(EVT_OP_CASE_NE, RVAR),
#define EVT_CASE_LT(RVAR)                       EVT_CMD(EVT_OP_CASE_LT, RVAR),
#define EVT_CASE_GT(RVAR)                       EVT_CMD(EVT_OP_CASE_GT, RVAR),
#define EVT_CASE_LE(RVAR)                       EVT_CMD(EVT_OP_CASE_LE, RVAR),
#define EVT_CASE_GE(RVAR)                       EVT_CMD(EVT_OP_CASE_GE, RVAR),
#define EVT_CASE_DEFAULT                        EVT_CMD(EVT_OP_CASE_DEFAULT),
#define EVT_CASE_OR_EQ(RVAR)                    EVT_CMD(EVT_OP_CASE_OR_EQ, RVAR),
#define EVT_CASE_AND_EQ(RVAR)                   EVT_CMD(EVT_OP_CASE_AND_EQ, RVAR),
#define EVT_CASE_FLAG(RVAR)                     EVT_CMD(EVT_OP_CASE_FLAG, RVAR),
#define EVT_END_CASE_GROUP                      EVT_CMD(EVT_OP_END_CASE_GROUP),
#define EVT_CASE_RANGE(MIN, MAX)                EVT_CMD(EVT_OP_CASE_RANGE, MIN, MAX),
#define EVT_END_SWITCH                          EVT_CMD(EVT_OP_END_SWITCH),

#define EVT_SET(VAR, INT_VALUE)                 EVT_CMD(EVT_OP_SET, VAR, (Bytecode) INT_VALUE),
#define EVT_SET_CONST(VAR, CONST)               EVT_CMD(EVT_OP_SET_CONST, VAR, (Bytecode) CONST),
#define EVT_SETF(VAR, FLOAT_VALUE)              EVT_CMD(EVT_OP_SETF, VAR, FLOAT_VALUE),
#define EVT_ADD(VAR, INT_VALUE)                 EVT_CMD(EVT_OP_ADD, VAR, INT_VALUE),
#define EVT_SUB(VAR, INT_VALUE)                 EVT_CMD(EVT_OP_SUB, VAR, INT_VALUE),
#define EVT_MUL(VAR, INT_VALUE)                 EVT_CMD(EVT_OP_MUL, VAR, INT_VALUE),
#define EVT_DIV(VAR, INT_VALUE)                 EVT_CMD(EVT_OP_DIV, VAR, INT_VALUE),
#define EVT_MOD(VAR, INT_VALUE)                 EVT_CMD(EVT_OP_MOD, VAR, INT_VALUE),
#define EVT_ADDF(VAR, FLOAT_VALUE)              EVT_CMD(EVT_OP_ADDF, VAR, FLOAT_VALUE),
#define EVT_SUBF(VAR, FLOAT_VALUE)              EVT_CMD(EVT_OP_SUBF, VAR, FLOAT_VALUE),
#define EVT_MULF(VAR, FLOAT_VALUE)              EVT_CMD(EVT_OP_MULF, VAR, FLOAT_VALUE),
#define EVT_DIVF(VAR, FLOAT_VALUE)              EVT_CMD(EVT_OP_DIVF, VAR, FLOAT_VALUE),

#define EVT_USE_BUF(INT_PTR)                    EVT_CMD(EVT_OP_USE_BUF, (Bytecode) INT_PTR),
#define EVT_BUF_READ1(VAR)                      EVT_CMD(EVT_OP_BUF_READ1, VAR),
#define EVT_BUF_READ2(VAR1, VAR2)               EVT_CMD(EVT_OP_BUF_READ2, VAR1, VAR2),
#define EVT_BUF_READ3(VAR1, VAR2, VAR3)         EVT_CMD(EVT_OP_BUF_READ2, VAR1, VAR2, VAR3),
#define EVT_BUF_READ4(VAR1, VAR2, VAR3, VAR4)   EVT_CMD(EVT_OP_BUF_READ4, VAR1, VAR2, VAR3, VAR4),
#define EVT_BUF_PEEK(OFFSET, VAR)               EVT_CMD(EVT_OP_BUF_PEEK, OFFSET, VAR),

#define EVT_USE_FBUF(FLOAT_PTR)                 EVT_CMD(EVT_OP_USE_FBUF, (Bytecode) FLOAT_PTR),
#define EVT_FBUF_READ1(VAR)                     EVT_CMD(EVT_OP_FBUF_READ1, VAR),
#define EVT_FBUF_READ2(VAR1, VAR2)              EVT_CMD(EVT_OP_FBUF_READ2, VAR1, VAR2),
#define EVT_FBUF_READ3(VAR1, VAR2, VAR3)        EVT_CMD(EVT_OP_FBUF_READ3, VAR1, VAR2, VAR3),
#define EVT_FBUF_READ4(VAR1, VAR2, VAR3, VAR4)  EVT_CMD(EVT_OP_FBUF_READ4, VAR1, VAR2, VAR3, VAR4),
#define EVT_FBUF_PEEK(OFFSET, VAR)              EVT_CMD(EVT_OP_FBUF_PEEK, OFFSET, VAR),

#define EVT_USE_ARRAY(INT_PTR)                  EVT_CMD(EVT_OP_USE_ARRAY, (Bytecode) INT_PTR),
#define EVT_USE_FLAG_ARRAY(PACKED_FLAGS_PTR)    EVT_CMD(EVT_OP_USE_FLAG_ARRAY, (Bytecode) PACKED_FLAGS_PTR),
#define EVT_MALLOC_ARRAY(SIZE, OUT_PTR_VAR)     EVT_CMD(EVT_OP_MALLOC_ARRAY, SIZE, OUT_PTR_VAR),

#define EVT_BITWISE_AND(VAR, VALUE)             EVT_CMD(EVT_OP_BITWISE_AND, VAR, VALUE),
#define EVT_BITWISE_OR(VAR, VALUE)              EVT_CMD(EVT_OP_BITWISE_OR, VAR, VALUE),
#define EVT_BITWISE_AND_CONST(VAR, CONST)       EVT_CMD(EVT_OP_BITWISE_AND_CONST, VAR, CONST),
#define EVT_BITWISE_OR_CONST(VAR, CONST)        EVT_CMD(EVT_OP_BITWISE_OR_CONST, VAR, CONST),

#define EVT_EXEC(EVT_SOURCE)                    EVT_CMD(EVT_OP_EXEC, (Bytecode) EVT_SOURCE),
#define EVT_EXEC_GET_TID(EVT_SOURCE, OUTVAR)    EVT_CMD(EVT_OP_EXEC_GET_TID, (Bytecode) EVT_SOURCE, OUTVAR),
#define EVT_EXEC_WAIT(EVT_SOURCE)               EVT_CMD(EVT_OP_EXEC_WAIT, (Bytecode) EVT_SOURCE),

// TODO: args
#define EVT_BIND_TRIGGER(EVT_SOURCE, TRIGGER, ...) \
    EVT_CMD(EVT_OP_BIND, EVT_SOURCE, TRIGGER, __VA_ARGS__),
#define EVT_BIND_PADLOCK(EVT_SOURCE, ...)       EVT_CMD(EVT_OP_BIND_PADLOCK, EVT_SOURCE, __VA_ARGS__),
#define EVT_UNBIND                              EVT_CMD(EVT_OP_UNBIND),

#define EVT_KILL_THREAD(TID)                    EVT_CMD(EVT_OP_KILL_THREAD, TID),
#define EVT_SET_PRIORITY(PRIORITY)              EVT_CMD(EVT_OP_SET_PRIORITY, PRIORITY),
#define EVT_SET_TIMESCALE(TIMESCALE)            EVT_CMD(EVT_OP_SET_TIMESCALE, TIMESCALE),
#define EVT_SET_GROUP(GROUP)                    EVT_CMD(EVT_OP_SET_GROUP, GROUP),
#define EVT_SUSPEND_GROUP(GROUP)                EVT_CMD(EVT_OP_SUSPEND_GROUP, GROUP),
#define EVT_RESUME_GROUP(GROUP)                 EVT_CMD(EVT_OP_RESUME_GROUP, GROUP),
#define EVT_SUSPEND_OTHERS(GROUP)               EVT_CMD(EVT_OP_SUSPEND_OTHERS, GROUP),
#define EVT_RESUME_OTHERS(GROUP)                EVT_CMD(EVT_OP_RESUME_OTHERS, GROUP),
#define EVT_SUSPEND_THREAD(TID)                 EVT_CMD(EVT_OP_SUSPEND_THREAD, TID),
#define EVT_RESUME_THREAD(TID)                  EVT_CMD(EVT_OP_RESUME_THREAD, TID),
#define EVT_IS_THREAD_RUNNING(TID, OUTVAR)      EVT_CMD(EVT_OP_IS_THREAD_RUNNING, TID, OUTVAR),

#define EVT_THREAD                              EVT_CMD(EVT_OP_THREAD),
#define EVT_END_THREAD                          EVT_CMD(EVT_OP_END_THREAD),

#define EVT_CHILD_THREAD                        EVT_CMD(EVT_OP_CHILD_THREAD),
#define EVT_END_CHILD_THREAD                    EVT_CMD(EVT_OP_END_CHILD_THREAD),

#define EVT_CALL(FUNC, ...)                     EVT_CMD(EVT_OP_CALL, (Bytecode) FUNC, ##__VA_ARGS__),

#endif
