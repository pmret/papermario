#ifndef _EVT_H_
#define _EVT_H_

#include "ultra64.h"

// Should be at least the width of a pointer i.e. intptr_t
typedef s32 Bytecode;

enum {
    EVT_OP_INTERNAL_FETCH,
    EVT_OP_END,
    EVT_OP_RETURN,
    EVT_OP_LABEL, ///< Args: index
    EVT_OP_GOTO, ///< Args: index
    EVT_OP_LOOP, ///< Args: number of repeats (0 = infinite)
    EVT_OP_END_LOOP,
    EVT_OP_BREAK_LOOP,
    EVT_OP_WAIT_FRAMES,
    EVT_OP_WAIT_SECS,
    EVT_OP_IF_EQ, ///< Args: a, b
    EVT_OP_IF_NE, ///< Args: a, b
    EVT_OP_IF_LT, ///< Args: a, b
    EVT_OP_IF_GT, ///< Args: a, b
    EVT_OP_IF_LE, ///< Args: a, b
    EVT_OP_IF_GE, ///< Args: a, b
    EVT_OP_IF_FLAG, ///< Args: a, b
    EVT_OP_IF_NOT_FLAG, ///< Args: a, b
    EVT_OP_ELSE,
    EVT_OP_END_IF,
    EVT_OP_SWITCH, ///< Args: expression to test against
    EVT_OP_SWITCH_CONST, ///< Args: value to test against
    EVT_OP_CASE_EQ, ///< Args: expression to test for
    EVT_OP_CASE_NE, ///< Args: expression to test for
    EVT_OP_CASE_LT, ///< Args: expression to test for
    EVT_OP_CASE_GT, ///< Args: expression to test for
    EVT_OP_CASE_LE, ///< Args: expression to test for
    EVT_OP_CASE_GE, ///< Args: expression to test for
    EVT_OP_CASE_DEFAULT,
    EVT_OP_CASE_OR_EQ, ///< Args: expression to test for
    EVT_OP_CASE_AND_EQ, ///< Args: expression to test for
    EVT_OP_CASE_FLAG, ///< Args: expression to test for
    EVT_OP_END_CASE_GROUP, ///< Ends the case block of EVT_OP_CASE_OR_EQ condition(s).
    EVT_OP_CASE_RANGE, ///< Args: from, to
    EVT_OP_BREAK_SWITCH,
    EVT_OP_END_SWITCH,
    EVT_OP_SET, ///< Args: container, expression
    EVT_OP_SET_CONST, ///< Args: container, value
    EVT_OP_SETF, ///< Args: container, expression
    EVT_OP_ADD, ///< Args: container, expression to increment by
    EVT_OP_SUB, ///< Args: container, expression to decrement by
    EVT_OP_MUL, ///< Args: container, expression to multiply by
    EVT_OP_DIV, ///< Integer division. Args: container, expression to divide by
    EVT_OP_MOD, ///< Args: container, expression to divide by
    EVT_OP_ADDF, ///< Args: container, expression to increment by
    EVT_OP_SUBF, ///< Args: container, expression to decrement by
    EVT_OP_MULF, ///< Args: container, expression to multiply by
    EVT_OP_DIVF, ///< Args: container, expression to divide by
    EVT_OP_USE_BUF, ///< Args: s32*
    EVT_OP_BUF_READ1, /// Args: container
    EVT_OP_BUF_READ2, /// Args: container, container
    EVT_OP_BUF_READ3, /// Args: container, container, container
    EVT_OP_BUF_READ4, /// Args: container, container, container, container
    EVT_OP_BUF_PEEK, ///< Args: index, container
    EVT_OP_USE_FBUF, ///< Identical to USE_BUFFER. Args: f32*
    EVT_OP_FBUF_READ1, /// Args: container
    EVT_OP_FBUF_READ2, /// Args: container, container
    EVT_OP_FBUF_READ3, /// Args: container, container, container
    EVT_OP_FBUF_READ4, /// Args: container, container, container, container
    EVT_OP_FBUF_PEEK, ///< Args: index, container
    EVT_OP_USE_ARRAY, ///< Args: *s32
    EVT_OP_USE_FLAGS, ///< Args: *s32
    EVT_OP_MALLOC_ARRAY, ///< Allocates a new array. Args: length, s32*
    EVT_OP_BITWISE_AND, ///< Args: container, expression to bitwise AND with
    EVT_OP_BITWISE_AND_CONST, ///< Args: container, value to bitwise AND with
    EVT_OP_BITWISE_OR, ///< Args: container, expression to bitwise OR with
    EVT_OP_BITWISE_OR_CONST, ///< Args: container, value to bitwise OR with
    EVT_OP_CALL, ///< Args: *function, ...
    EVT_OP_EXEC, ///< Args: EvtScript*
    EVT_OP_EXEC_GET_TID, ///< Args: EvtScript*, container
    EVT_OP_EXEC_WAIT, ///< Spawns a script and waits for it to return before continuing. Args: EvtScript*
    EVT_OP_BIND_TRIGGER, ///< Args: EvtScript*, trigger flags, s32 target, 1, Trigger*
    EVT_OP_UNBIND, ///< Unbinds any triggers bound to this script.
    EVT_OP_KILL_THREAD, ///< Args: ScriptID
    EVT_OP_JUMP, ///< Args: EvtScript*
    EVT_OP_SET_PRIORITY, ///< Args: priority
    EVT_OP_SET_TIMESCALE, ///< Args: timescale
    EVT_OP_SET_GROUP, ///< Args: group
    EVT_OP_BIND_PADLOCK, ///< Args: EvtScript*, trigger flags, s32 target, ItemList*, 0, 1
    EVT_OP_SUSPEND_GROUP, ///< Args: group
    EVT_OP_RESUME_GROUP, ///< Args: group
    EVT_OP_SUSPEND_OTHERS, ///< Args: group
    EVT_OP_RESUME_OTHERS, ///< Args: group
    EVT_OP_SUSPEND_THREAD, ///< Args: ScriptID
    EVT_OP_RESUME_THREAD, ///< Args: ScriptID
    EVT_OP_IS_THREAD_RUNNING, ///< Args: ScriptID, container
    EVT_OP_THREAD,
    EVT_OP_END_THREAD,
    EVT_OP_CHILD_THREAD, ///< Parallel threads are killed as soon as the parent script returns.
    EVT_OP_END_CHILD_THREAD,
    EVT_OP_90,
    EVT_OP_DEBUG_PRINT, ///< Args: expression
    EVT_OP_92,
    EVT_OP_93,
    EVT_OP_94,
};

// deprecated, use those in script_api/macros.h instead
#define EVT_VAR(v)           ((v -  30000000))
#define EVT_MAP_VAR(v)       ((v -  50000000))
#define EVT_FLAG(v)          ((v -  70000000))
#define EVT_MAP_FLAG(v)      ((v -  90000000))
#define EVT_AREA_FLAG(v)     ((v - 110000000))
#define EVT_SAVE_FLAG(v)     ((v - 130000000))
#define EVT_AREA_VAR(v)      ((v - 150000000))
#define EVT_SAVE_VAR(v)      ((v - 170000000))
#define EVT_ARRAY(v)         (Bytecode) ((v - 190000000))
#define EVT_ARRAY_FLAG(v)    ((v - 210000000))
#define EVT_FIXED(v)         (((v * 1024.0f) + -230000000)) // See evt_float_to_fixed_var
#define EVT_PTR(sym)         (Bytecode) &sym
#define EVT_LIMIT            -250000000 // TODO better name
#define MAKE_ENTITY_END      0x80000000

#define EVT_INDEX_OF_VAR(v)         ((v +  30000000))
#define EVT_INDEX_OF_FLAG(v)        ((v +  70000000))
#define EVT_INDEX_OF_MAP_VAR(v)     ((v +  50000000))
#define EVT_INDEX_OF_MAP_FLAG(v)    ((v +  90000000))
#define EVT_INDEX_OF_AREA_FLAG(v)   ((v + 110000000))
#define EVT_INDEX_OF_AREA_BYTE(v)   ((v + 150000000))
#define EVT_INDEX_OF_SAVE_FLAG(v)   ((v + 130000000))
#define EVT_INDEX_OF_SAVE_BYTE(v)   ((v + 170000000))

// shorthand names for EVT_VAR
#define VAR0 EVT_VAR(0)
#define VAR1 EVT_VAR(1)
#define VAR2 EVT_VAR(2)
#define VAR3 EVT_VAR(3)
#define VAR4 EVT_VAR(4)
#define VAR5 EVT_VAR(5)
#define VAR6 EVT_VAR(6)
#define VAR7 EVT_VAR(7)
#define VAR8 EVT_VAR(8)
#define VAR9 EVT_VAR(9)
#define VARA EVT_VAR(10)
#define VARB EVT_VAR(11)
#define VARC EVT_VAR(12)
#define VARD EVT_VAR(13)
#define VARE EVT_VAR(14)
#define VARF EVT_VAR(15)

// deprecated, use enum GSW/GSWF
#define EVT_STORY_PROGRESS EVT_SAVE_VAR(0)
#define EVT_SAVE_FLAG_PLACES_VISITED EVT_SAVE_FLAG(0x7AA)
#define EVT_SAVE_FLAG_TUTORIAL_GOT_STAR_PIECE EVT_SAVE_FLAG(101)
#define EVT_WORLD_LOCATION EVT_SAVE_VAR(425)

/* Return type of evt_execute_next_command */
#define EVT_CONTINUE 0   /* Continue to next command */
#define EVT_ABORT    1   /* Quit execution */
#define EVT_FINISH   255 /* Return from script */

/* Return type of script API functions */
typedef s32 ApiStatus;
#define ApiStatus_BLOCK  0   /* Call again next frame */
#define ApiStatus_DONE1  1   /* Unconditional. Probably only exists to return a bool from functions */
#define ApiStatus_DONE2  2   /* Conditional on Evt->disableScripts */
#define ApiStatus_REPEAT 3   /* Call again immediately */
#define ApiStatus_FINISH 255 /* Corresponds to EVT_FINISH */

enum EventGroupFlags {
    EVT_GROUP_00    = 0x00,
    EVT_GROUP_0B    = 0x0B, // 8 | 4 | 1
    EVT_GROUP_1B    = 0x1B, // 10 | 8 | 4 | 1
    EVT_GROUP_EF    = 0xEF, // ~10
    EVT_GROUP_01    = 0x01,
    EVT_GROUP_02    = 0x02,
    EVT_GROUP_04    = 0x04,
    EVT_GROUP_08    = 0x08,
    EVT_GROUP_10    = 0x10,
};

enum EventPriority {
    EVT_PRIORITY_0  = 0x00, // map main script
    EVT_PRIORITY_1  = 0x01,
    EVT_PRIORITY_A  = 0x0A,
    EVT_PRIORITY_14 = 0x14,
};

enum EventStateFlags {
    EVT_FLAG_01     = 0x01,
    EVT_FLAG_10     = 0x10, // has child?
    EVT_FLAG_20     = 0x20, // add to global script list
    EVT_FLAG_40     = 0x40, // thread?
};

#endif
