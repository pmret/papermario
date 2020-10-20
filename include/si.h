#ifndef _SI_H_
#define _SI_H_

#include "ultra64.h"

#define SI_VAR(v) (v - 30000000)
#define SI_MAP_VAR(v) (v - 50000000)
#define SI_FLAG(v) (v - 70000000)
#define SI_MAP_FLAG(v) (v - 90000000)
#define SI_AREA_FLAG(v) (v - 110000000)
#define SI_SAVE_FLAG(v) (v - 130000000)
#define SI_AREA_VAR(v) (v - 150000000)
#define SI_SAVE_VAR(v) (v - 170000000)
#define SI_ARRAY(v) (v - 190000000)
#define SI_ARRAY_FLAG(v) (v - 210000000)
#define SI_FIXED(v) ((s32)(v * 1024.0f) - 230000000) // See float_to_fixed_var

/* Return type of si_execute_next_command */
#define SI_CONTINUE 0   /* Continue to next command */
#define SI_ABORT    1   /* Quit execution */
#define SI_FINISH   255 /* Return from script */

/* Return type of script API functions */
typedef s32 ApiStatus;
#define ApiStatus_BLOCK  0   /* Call again next frame */
#define ApiStatus_DONE1  1   /* Unconditional. Probably only exists to return a bool from functions */
#define ApiStatus_DONE2  2   /* Conditional on ScriptInstance->disableScripts */
#define ApiStatus_REPEAT 3   /* Call again immediately */
#define ApiStatus_FINISH 255 /* Corresponds to SI_FINISH */

#define SI_CMD(opcode, argv...) \
    opcode, \
    /* argc */ (sizeof((Bytecode[]){argv})/sizeof(Bytecode)), \
    ##argv

#define SI_END() SI_CMD(0x01)
#define SI_RETURN() SI_CMD(0x02)

#define SI_LABEL(i) SI_CMD(0x03, i)
#define SI_GOTO(i) SI_CMD(0x04, i)

#define SI_LOOP(i) SI_CMD(0x05, i)
#define SI_END_LOOP() SI_CMD(0x06)
#define SI_BREAK_LOOP() SI_CMD(0x07)

#define SI_WAIT_FRAMES(i) SI_CMD(0x08, i)
#define SI_WAIT_SECS(i) SI_CMD(0x09, i)

#define SI_IF_EQ(a, b) SI_CMD(0x0A, a, b)
#define SI_IF_NE(a, b) SI_CMD(0x0B, a, b)
#define SI_IF_LT(a, b) SI_CMD(0x0C, a, b)
#define SI_IF_GT(a, b) SI_CMD(0x0D, a, b)
#define SI_IF_LE(a, b) SI_CMD(0x0E, a, b)
#define SI_IF_GE(a, b) SI_CMD(0x0F, a, b)
#define SI_IF_BITS_ON(a, b) SI_CMD(0x10, a, b)
#define SI_IF_BITS_OFF(a, b) SI_CMD(0x11, a, b)
#define SI_ELSE() SI_CMD(0x12)
#define SI_END_IF() SI_CMD(0x13)

#define SI_SWITCH(a) SI_CMD(0x14, a)
#define SI_SWITCH_CONST(a) SI_CMD(0x15, a) // Does not get_variable
#define SI_CASE_EQ(b) SI_CMD(0x16, b)
#define SI_CASE_NE(b) SI_CMD(0x17, b)
#define SI_CASE_LT(b) SI_CMD(0x18, b)
#define SI_CASE_GT(b) SI_CMD(0x19, b)
#define SI_CASE_LE(b) SI_CMD(0x1A, b)
#define SI_CASE_GE(b) SI_CMD(0x1B, b)
#define SI_CASE_DEFAULT() SI_CMD(0x1C)
#define SI_CASE_OR_EQ(b) SI_CMD(0x1D, b)
#define SI_CASE_BITS_ON(b) SI_CMD(0x1F, b)
#define SI_END_MULTI_CASE() SI_CMD(0x20)
#define SI_CASE_RANGE(from, to) SI_CMD(0x21, from, to)
#define SI_BREAK_CASE() SI_CMD(0x22)
#define SI_END_SWITCH() SI_CMD(0x23)

#define SI_SET(varA, varB) SI_CMD(0x24, varA, varB)
#define SI_SET_CONST(var, value) SI_CMD(0x25, var, value) // Does not get_variable
#define SI_ADD(a, b) SI_CMD(0x27, a, b) // +=
#define SI_SUB(a, b) SI_CMD(0x28, a, b) // -=
#define SI_MUL(a, b) SI_CMD(0x29, a, b) // *=
#define SI_DIV(a, b) SI_CMD(0x2A, a, b) // /=
#define SI_MOD(a, b) SI_CMD(0x2B, a, b) // %=

#define SI_SET_F(var, value) SI_CMD(0x26, var, value)
#define SI_ADD_F(a, b) SI_CMD(0x2C, a, b) // +=
#define SI_SUB_F(a, b) SI_CMD(0x2D, a, b) // -=
#define SI_MUL_F(a, b) SI_CMD(0x2E, a, b) // *=
#define SI_DIV_F(a, b) SI_CMD(0x2F, a, b) // /=

// BUF_READ and BUF_READ_F take 1..4 args only
#define SI_USE_BUFFER(buf_ptr) SI_CMD(0x30, buf_ptr)
#define SI_BUF_READ(vars...) SI_CMD( \
    0x30 + (sizeof((Bytecode[]){vars})/sizeof(Bytecode)), \
    vars)
#define SI_BUF_PEEK(n, var) SI_CMD(0x35, n, var)
#define SI_USE_BUFFER_F(buf_ptr) SI_CMD(0x36, buf_ptr)
#define SI_BUF_READ_F(vars...) SI_CMD( \
    0x36 + (sizeof((Bytecode[]){vars})/sizeof(Bytecode)), \
    vars)
#define SI_BUF_PEEK_F(n, var) SI_CMD(0x3B, n, var)

#define SI_USE_ARRAY(arrPtr) SI_CMD(0x3C, arrPtr)
#define SI_NEW_ARRAY(len, arrPtr) SI_CMD(0x3D, len, arrPtr)
#define SI_USE_FLAGS(arrPtr) SI_CMD(0x3E, arrPtr)

#define SI_AND(varA, varB) SI_CMD(0x3F, varA, varB) // &=
#define SI_AND_CONST(var, value) SI_CMD(0x40, var, value) // &=
#define SI_OR(varA, varB) SI_CMD(0x41, varA, varB) // |=
#define SI_OR_CONST(var, value) SI_CMD(0x41, var, value) // |=

#define SI_CALL(func, argv...) SI_CMD(0x43, func, ##argv)
#define SI_EXEC(script) SI_CMD(0x44, script)
#define SI_EXEC_GET_ID(script, outScriptID) SI_CMD(0x45, script, outScriptID)
#define SI_EXEC_WAIT(script) SI_CMD(0x46, script)
#define SI_JUMP(script) SI_CMD(0x4A, script)

#define SI_BIND(script, trigger, target, outTriggerPtr) SI_CMD(0x47, script, trigger, target, 1, outTriggerPtr)
#define SI_BIND_PADLOCK(script, trigger, target, itemList) SI_CMD(0x4E, script, trigger, target, itemList, 0, 1)
#define SI_UNBIND_ME() SI_CMD(0x48)

#define SI_PRIORITY(p) SI_CMD(0x4B, p)
#define SI_TIMESCALE(t) SI_CMD(0x4C, t)
#define SI_GROUP(g) SI_CMD(0x4D, g)

#define SI_SUSPEND_GROUP(group) SI_CMD(0x4F, group)
#define SI_RESUME_GROUP(group) SI_CMD(0x50, group)
#define SI_SUSPEND_GROUP_NOT_ME(group) SI_CMD(0x51, group)
#define SI_RESUME_GROUP_NOT_ME(group) SI_CMD(0x52, group)

#define SI_KILL(scriptID) SI_CMD(0x49, scriptID)
#define SI_SUSPEND(scriptID) SI_CMD(0x53, scriptID)
#define SI_RESUME(scriptID) SI_CMD(0x54, scriptID)
#define SI_EXISTS(scriptID) SI_CMD(0x55, scriptID)

#define SI_THREAD() SI_CMD(0x56)
#define SI_END_THREAD() SI_CMD(0x57)

#define SI_CHILD_THREAD() SI_CMD(0x58)
#define SI_END_CHILD_THREAD() SI_CMD(0x59)

#define GEN_EXIT_WALK_SCRIPT(name, walkDistance, exitIdx, map, entryIdx) \
    Script name = { \
        SI_GROUP(0x1B), \
        SI_CALL(UseExitHeading, walkDistance, exitIdx), \
        SI_EXEC(ExitWalk), \
        SI_CALL(GotoMap, map, entryIdx), \
        SI_WAIT_FRAMES(100), \
        SI_RETURN(), \
        SI_END(), \
    };

#endif
