#ifndef _SI_H_
#define _SI_H_

#include "ultra64.h"

typedef s32 Bytecode;
typedef s32 ScriptID;

typedef enum ScriptOpcode {
    ScriptOpcode_END = 0x01,
    ScriptOpcode_RETURN,
    ScriptOpcode_LABEL, ///< Args: index
    ScriptOpcode_GOTO, ///< Args: index
    ScriptOpcode_LOOP, ///< Args: number of repeats (0 = infinite)
    ScriptOpcode_END_LOOP,
    ScriptOpcode_BREAK_LOOP,
    ScriptOpcode_SLEEP_FRAMES,
    ScriptOpcode_SLEEP_SECS,
    ScriptOpcode_IF_EQ, ///< Args: a, b
    ScriptOpcode_IF_NE, ///< Args: a, b
    ScriptOpcode_IF_LT, ///< Args: a, b
    ScriptOpcode_IF_GT, ///< Args: a, b
    ScriptOpcode_IF_LE, ///< Args: a, b
    ScriptOpcode_IF_GE, ///< Args: a, b
    ScriptOpcode_IF_FLAG, ///< Args: a, b
    ScriptOpcode_IF_NOT_FLAG, ///< Args: a, b
    ScriptOpcode_ELSE,
    ScriptOpcode_END_IF,
    ScriptOpcode_MATCH, ///< Args: expression to test against
    ScriptOpcode_MATCH_CONST, ///< Args: value to test against
    ScriptOpcode_CASE_EQ, ///< Args: expression to test for
    ScriptOpcode_CASE_NE, ///< Args: expression to test for
    ScriptOpcode_CASE_LT, ///< Args: expression to test for
    ScriptOpcode_CASE_GT, ///< Args: expression to test for
    ScriptOpcode_CASE_LE, ///< Args: expression to test for
    ScriptOpcode_CASE_GE, ///< Args: expression to test for
    ScriptOpcode_CASE_ELSE,
    ScriptOpcode_CASE_MULTI_OR_EQ, ///< Args: expression to test for
    ScriptOpcode_CASE_MULTI_AND_EQ, ///< Args: expression to test for
    ScriptOpcode_CASE_FLAG, ///< Args: expression to test for
    ScriptOpcode_END_CASE_MULTI, ///< Ends the case block of ScriptOpcode_CASE_MULTI_OR_EQ condition(s).
    ScriptOpcode_CASE_RANGE, ///< Args: from, to
    ScriptOpcode_BREAK_MATCH,
    ScriptOpcode_END_MATCH,
    ScriptOpcode_SET, ///< Args: container, expression
    ScriptOpcode_SET_CONST, ///< Args: container, value
    ScriptOpcode_SET_F, ///< Args: container, expression
    ScriptOpcode_ADD, ///< Args: container, expression to increment by
    ScriptOpcode_SUB, ///< Args: container, expression to decrement by
    ScriptOpcode_MUL, ///< Args: container, expression to multiply by
    ScriptOpcode_DIV, ///< Integer division. Args: container, expression to divide by
    ScriptOpcode_MOD, ///< Args: container, expression to divide by
    ScriptOpcode_ADD_F, ///< Args: container, expression to increment by
    ScriptOpcode_SUB_F, ///< Args: container, expression to decrement by
    ScriptOpcode_MUL_F, ///< Args: container, expression to multiply by
    ScriptOpcode_DIV_F, ///< Args: container, expression to divide by
    ScriptOpcode_USE_BUFFER, ///< Args: s32*
    ScriptOpcode_BUFFER_READ_1, /// Args: container
    ScriptOpcode_BUFFER_READ_2, /// Args: container, container
    ScriptOpcode_BUFFER_READ_3, /// Args: container, container, container
    ScriptOpcode_BUFFER_READ_4, /// Args: container, container, container, container
    ScriptOpcode_BUFFER_PEEK, ///< Args: index, container
    ScriptOpcode_USE_BUFFER_F, ///< Identical to USE_BUFFER. Args: f32*
    ScriptOpcode_BUFFER_READ_1_F, /// Args: container
    ScriptOpcode_BUFFER_READ_2_F, /// Args: container, container
    ScriptOpcode_BUFFER_READ_3_F, /// Args: container, container, container
    ScriptOpcode_BUFFER_READ_4_F, /// Args: container, container, container, container
    ScriptOpcode_BUFFER_PEEK_F, ///< Args: index, container
    ScriptOpcode_USE_ARRAY, ///< Args: *s32
    ScriptOpcode_USE_FLAGS, ///< Args: *s32
    ScriptOpcode_NEW_ARRAY, ///< Allocates a new array. Args: length, s32*
    ScriptOpcode_AND, ///< Args: container, expression to bitwise AND with
    ScriptOpcode_AND_CONST, ///< Args: container, value to bitwise AND with
    ScriptOpcode_OR, ///< Args: container, expression to bitwise OR with
    ScriptOpcode_OR_CONST, ///< Args: container, value to bitwise OR with
    ScriptOpcode_CALL, ///< Args: *function, ...
    ScriptOpcode_SPAWN_SCRIPT, ///< Args: Script*
    ScriptOpcode_SPAWN_GET_ID, ///< Args: Script*, container
    ScriptOpcode_AWAIT_SCRIPT, ///< Spawns a script and waits for it to return before continuing. Args: Script*
    ScriptOpcode_BIND_TRIGGER, ///< Args: Script*, trigger flags, s32 target, 1, Trigger*
    ScriptOpcode_UNBIND, ///< Unbinds any triggers bound to this script.
    ScriptOpcode_KILL_SCRIPT, ///< Args: ScriptID
    ScriptOpcode_JUMP, ///< Args: Script*
    ScriptOpcode_SET_PRIORITY, ///< Args: priority
    ScriptOpcode_SET_TIMESCALE, ///< Args: timescale
    ScriptOpcode_SET_GROUP, ///< Args: group
    ScriptOpcode_BIND_PADLOCK, ///< Args: Script*, trigger flags, s32 target, ItemList*, 0, 1
    ScriptOpcode_SUSPEND_GROUP, ///< Args: group
    ScriptOpcode_RESUME_GROUP, ///< Args: group
    ScriptOpcode_SUSPEND_OTHERS, ///< Args: group
    ScriptOpcode_RESUME_OTHERS, ///< Args: group
    ScriptOpcode_SUSPEND_SCRIPT, ///< Args: ScriptID
    ScriptOpcode_RESUME_SCRIPT, ///< Args: ScriptID
    ScriptOpcode_SCRIPT_EXISTS, ///< Args: ScriptID, container
    ScriptOpcode_SPAWN_THREAD,
    ScriptOpcode_END_SPAWN_THREAD,
    ScriptOpcode_PARALLEL_THREAD, ///< Parallel threads are killed as soon as the parent script returns.
    ScriptOpcode_END_PARALLEL_THREAD,
    ScriptOpcode_90,
    ScriptOpcode_DEBUG_PRINT, ///< Args: expression
    ScriptOpcode_92,
    ScriptOpcode_93,
    ScriptOpcode_94,
} ScriptOpcode;

#define SI_VAR(v)           ((v -  30000000))
#define SI_MAP_VAR(v)       ((v -  50000000))
#define SI_FLAG(v)          ((v -  70000000))
#define SI_MAP_FLAG(v)      ((v -  90000000))
#define SI_AREA_FLAG(v)     ((v - 110000000))
#define SI_SAVE_FLAG(v)     ((v - 130000000))
#define SI_AREA_VAR(v)      ((v - 150000000))
#define SI_SAVE_VAR(v)      ((v - 170000000))
#define SI_ARRAY(v)         ((v - 190000000))
#define SI_ARRAY_FLAG(v)    ((v - 210000000))
#define SI_FIXED(v) (((v * 1024.0f) + -230000000)) // See float_to_fixed_var
#define SI_LIMIT        -250000000 // TODO better name
#define MAKE_ENTITY_END 0x80000000

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
