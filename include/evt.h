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
    EVT_OP_CASE_ELSE,
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
    EVT_OP_NEW_ARRAY, ///< Allocates a new array. Args: length, s32*
    EVT_OP_AND, ///< Args: container, expression to bitwise AND with
    EVT_OP_AND_CONST, ///< Args: container, value to bitwise AND with
    EVT_OP_OR, ///< Args: container, expression to bitwise OR with
    EVT_OP_OR_CONST, ///< Args: container, value to bitwise OR with
    EVT_OP_CALL, ///< Args: *function, ...
    EVT_OP_EXEC, ///< Args: EvtSource*
    EVT_OP_EXEC_GET_TID, ///< Args: EvtSource*, container
    EVT_OP_EXEC_WAIT, ///< Spawns a script and waits for it to return before continuing. Args: EvtSource*
    EVT_OP_BIND_TRIGGER, ///< Args: EvtSource*, trigger flags, s32 target, 1, Trigger*
    EVT_OP_UNBIND, ///< Unbinds any triggers bound to this script.
    EVT_OP_KILL_THREAD, ///< Args: ScriptID
    EVT_OP_JUMP, ///< Args: EvtSource*
    EVT_OP_SET_PRIORITY, ///< Args: priority
    EVT_OP_SET_TIMESCALE, ///< Args: timescale
    EVT_OP_SET_GROUP, ///< Args: group
    EVT_OP_BIND_PADLOCK, ///< Args: EvtSource*, trigger flags, s32 target, ItemList*, 0, 1
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

#define EVT_VAR(v)           ((v -  30000000))
#define EVT_MAP_VAR(v)       ((v -  50000000))
#define EVT_FLAG(v)          ((v -  70000000))
#define EVT_MAP_FLAG(v)      ((v -  90000000))
#define EVT_AREA_FLAG(v)     ((v - 110000000))
#define EVT_SAVE_FLAG(v)     ((v - 130000000))
#define EVT_AREA_VAR(v)      ((v - 150000000))
#define EVT_SAVE_VAR(v)      ((v - 170000000))
#define EVT_ARRAY(v)         ((v - 190000000))
#define EVT_ARRAY_FLAG(v)    ((v - 210000000))
#define EVT_FIXED(v) (((v * 1024.0f) + -230000000)) // See evt_float_to_fixed_var
#define EVT_LIMIT        -250000000 // TODO better name
#define MAKE_ENTITY_END 0x80000000


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

#define EVT_CMD(opcode, argv...) \
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
