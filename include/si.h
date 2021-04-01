#ifndef _SI_H_
#define _SI_H_

#include "ultra64.h"

typedef s32 Bytecode;
typedef s32 ScriptID;

typedef enum ScriptOpcode {
    /* 0x01 */ ScriptOpcode_END = 0x01,
    /* 0x02 */ ScriptOpcode_RETURN,
    /* 0x03 */ ScriptOpcode_LABEL, ///< Args: index
    /* 0x04 */ ScriptOpcode_GOTO, ///< Args: index
    /* 0x05 */ ScriptOpcode_LOOP, ///< Args: number of repeats (0 = infinite)
    /* 0x06 */ ScriptOpcode_END_LOOP,
    /* 0x07 */ ScriptOpcode_BREAK_LOOP,
    /* 0x08 */ ScriptOpcode_SLEEP_FRAMES,
    /* 0x09 */ ScriptOpcode_SLEEP_SECS,
    /* 0x0a */ ScriptOpcode_IF_EQ, ///< Args: a, b
    /* 0x0b */ ScriptOpcode_IF_NE, ///< Args: a, b
    /* 0x0c */ ScriptOpcode_IF_LT, ///< Args: a, b
    /* 0x0d */ ScriptOpcode_IF_GT, ///< Args: a, b
    /* 0x0e */ ScriptOpcode_IF_LE, ///< Args: a, b
    /* 0x0f */ ScriptOpcode_IF_GE, ///< Args: a, b
    /* 0x10 */ ScriptOpcode_IF_FLAG, ///< Args: a, b
    /* 0x11 */ ScriptOpcode_IF_NOT_FLAG, ///< Args: a, b
    /* 0x12 */ ScriptOpcode_ELSE,
    /* 0x13 */ ScriptOpcode_END_IF,
    /* 0x14 */ ScriptOpcode_MATCH, ///< Args: expression to test against
    /* 0x15 */ ScriptOpcode_MATCH_CONST, ///< Args: value to test against
    /* 0x16 */ ScriptOpcode_CASE_EQ, ///< Args: expression to test for
    /* 0x17 */ ScriptOpcode_CASE_NE, ///< Args: expression to test for
    /* 0x18 */ ScriptOpcode_CASE_LT, ///< Args: expression to test for
    /* 0x19 */ ScriptOpcode_CASE_GT, ///< Args: expression to test for
    /* 0x1a */ ScriptOpcode_CASE_LE, ///< Args: expression to test for
    /* 0x1b */ ScriptOpcode_CASE_GE, ///< Args: expression to test for
    /* 0x1c */ ScriptOpcode_CASE_ELSE,
    /* 0x1d */ ScriptOpcode_CASE_MULTI_OR_EQ, ///< Args: expression to test for
    /* 0x1e */ ScriptOpcode_CASE_MULTI_AND_EQ, ///< Args: expression to test for
    /* 0x1f */ ScriptOpcode_CASE_FLAG, ///< Args: expression to test for
    /* 0x20 */ ScriptOpcode_END_CASE_MULTI, ///< Ends the case block of ScriptOpcode_CASE_MULTI_OR_EQ condition(s).
    /* 0x21 */ ScriptOpcode_CASE_RANGE, ///< Args: from, to
    /* 0x22 */ ScriptOpcode_BREAK_MATCH,
    /* 0x23 */ ScriptOpcode_END_MATCH,
    /* 0x24 */ ScriptOpcode_SET, ///< Args: container, expression
    /* 0x25 */ ScriptOpcode_SET_CONST, ///< Args: container, value
    /* 0x26 */ ScriptOpcode_SET_F, ///< Args: container, expression
    /* 0x27 */ ScriptOpcode_ADD, ///< Args: container, expression to increment by
    /* 0x28 */ ScriptOpcode_SUB, ///< Args: container, expression to decrement by
    /* 0x29 */ ScriptOpcode_MUL, ///< Args: container, expression to multiply by
    /* 0x2a */ ScriptOpcode_DIV, ///< Integer division. Args: container, expression to divide by
    /* 0x2b */ ScriptOpcode_MOD, ///< Args: container, expression to divide by
    /* 0x2c */ ScriptOpcode_ADD_F, ///< Args: container, expression to increment by
    /* 0x2d */ ScriptOpcode_SUB_F, ///< Args: container, expression to decrement by
    /* 0x2e */ ScriptOpcode_MUL_F, ///< Args: container, expression to multiply by
    /* 0x2f */ ScriptOpcode_DIV_F, ///< Args: container, expression to divide by
    /* 0x30 */ ScriptOpcode_USE_BUFFER, ///< Args: s32*
    /* 0x31 */ ScriptOpcode_BUFFER_READ_1, /// Args: container
    /* 0x32 */ ScriptOpcode_BUFFER_READ_2, /// Args: container, container
    /* 0x33 */ ScriptOpcode_BUFFER_READ_3, /// Args: container, container, container
    /* 0x34 */ ScriptOpcode_BUFFER_READ_4, /// Args: container, container, container, container
    /* 0x35 */ ScriptOpcode_BUFFER_PEEK, ///< Args: index, container
    /* 0x36 */ ScriptOpcode_USE_BUFFER_F, ///< Identical to USE_BUFFER. Args: f32*
    /* 0x37 */ ScriptOpcode_BUFFER_READ_1_F, /// Args: container
    /* 0x38 */ ScriptOpcode_BUFFER_READ_2_F, /// Args: container, container
    /* 0x39 */ ScriptOpcode_BUFFER_READ_3_F, /// Args: container, container, container
    /* 0x3a */ ScriptOpcode_BUFFER_READ_4_F, /// Args: container, container, container, container
    /* 0x3b */ ScriptOpcode_BUFFER_PEEK_F, ///< Args: index, container
    /* 0x3c */ ScriptOpcode_USE_ARRAY, ///< Args: *s32
    /* 0x3d */ ScriptOpcode_USE_FLAGS, ///< Args: *s32
    /* 0x3e */ ScriptOpcode_NEW_ARRAY, ///< Allocates a new array. Args: length, s32*
    /* 0x3f */ ScriptOpcode_AND, ///< Args: container, expression to bitwise AND with
    /* 0x40 */ ScriptOpcode_AND_CONST, ///< Args: container, value to bitwise AND with
    /* 0x41 */ ScriptOpcode_OR, ///< Args: container, expression to bitwise OR with
    /* 0x42 */ ScriptOpcode_OR_CONST, ///< Args: container, value to bitwise OR with
    /* 0x43 */ ScriptOpcode_CALL, ///< Args: *function, ...
    /* 0x44 */ ScriptOpcode_SPAWN_SCRIPT, ///< Args: Script*
    /* 0x45 */ ScriptOpcode_SPAWN_SCRIPT_GET_ID, ///< Args: Script*, container
    /* 0x46 */ ScriptOpcode_AWAIT_SCRIPT, ///< Spawns a script and waits for it to return before continuing. Args: Script*
    /* 0x47 */ ScriptOpcode_BIND_TRIGGER, ///< Args: Script*, trigger flags, s32 target, 1, Trigger*
    /* 0x48 */ ScriptOpcode_UNBIND, ///< Unbinds any triggers bound to this script.
    /* 0x49 */ ScriptOpcode_KILL_SCRIPT, ///< Args: ScriptID
    /* 0x4a */ ScriptOpcode_JUMP, ///< Args: Script*
    /* 0x4b */ ScriptOpcode_SET_PRIORITY, ///< Args: priority
    /* 0x4c */ ScriptOpcode_SET_TIMESCALE, ///< Args: timescale
    /* 0x4d */ ScriptOpcode_SET_GROUP, ///< Args: group
    /* 0x4f */ ScriptOpcode_BIND_PADLOCK, ///< Args: Script*, trigger flags, s32 target, ItemList*, 0, 1
    /* 0x50 */ ScriptOpcode_SUSPEND_GROUP, ///< Args: group
    /* 0x51 */ ScriptOpcode_RESUME_GROUP, ///< Args: group
    /* 0x52 */ ScriptOpcode_SUSPEND_OTHERS, ///< Args: group
    /* 0x53 */ ScriptOpcode_RESUME_OTHERS, ///< Args: group
    /* 0x54 */ ScriptOpcode_SUSPEND_SCRIPT, ///< Args: ScriptID
    /* 0x55 */ ScriptOpcode_RESUME_SCRIPT, ///< Args: ScriptID
    /* 0x56 */ ScriptOpcode_SCRIPT_EXISTS, ///< Args: ScriptID, container
    /* 0x57 */ ScriptOpcode_SPAWN_THREAD,
    /* 0x58 */ ScriptOpcode_END_SPAWN_THREAD,
    /* 0x59 */ ScriptOpcode_PARALLEL_THREAD, ///< Parallel threads are killed as soon as the parent script returns.
    /* 0x5a */ ScriptOpcode_END_PARALLEL_THREAD,
    /* 0x5b */ ScriptOpcode_DEBUG_PRINT = 0x5B, ///< Args: expression
} ScriptOpcode;

#define SI_VAR(v) ((v - 30000000))
#define SI_MAP_VAR(v) ((v - 50000000))
#define SI_FLAG(v) ((v - 70000000))
#define SI_MAP_FLAG(v) ((v - 90000000))
#define SI_AREA_FLAG(v) ((v - 110000000))
#define SI_SAVE_FLAG(v) ((v - 130000000))
#define SI_AREA_VAR(v) ((v - 150000000))
#define SI_SAVE_VAR(v) ((v - 170000000))
#define SI_ARRAY(v) ((v - 190000000))
#define SI_ARRAY_FLAG(v) ((v - 210000000))
#define SI_FIXED(v) (((v * 1024.0f) + -230000000)) // See float_to_fixed_var
#define ARGS_END 0x80000000

#define STORY_PROGRESS SI_SAVE_VAR(0)
#define WORLD_LOCATION SI_SAVE_VAR(425)

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

#define EXIT_WALK_SCRIPT(walkDistance, exitIdx, map, entryIdx) \
    SCRIPT({ \
        group 0x1B; \
        UseExitHeading(walkDistance, exitIdx); \
        spawn ExitWalk; \
        GotoMap(map, entryIdx); \
        sleep 100; \
    })

#endif
