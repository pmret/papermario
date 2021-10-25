#ifndef _SCRIPT_API_MACROS_H_
#define _SCRIPT_API_MACROS_H_

#include "evt.h"

/****** EXPRESSIONS ***************************************************************************************************/

/// Expressions in EVT instructions should be one of the following types:
/// - Integer literals (as-is, s32)
/// - Float literals (EVT_FLOAT) - cast to int where a float is not accepted
/// - Pointers, string literals (EVT_ADDR)
/// - Variables (LW, GW, LSW, GSW, UW)
/// - Flags (LF, GF, LSWF, GSWF, UF)
/// This is implemented in `evt_get_variable` and `evt_get_float_variable`.

/// Decimal constant.
/// Despite the name, "floats" are actually stored as fixed-point values.
#define EVT_FLOAT(DOUBLE) (((Bytecode)(DOUBLE * 1024.0f) + -230000000))

/// Address/pointer constant.
#define EVT_ADDR(sym) (((Bytecode) &((sym))))

/// Local Word. A variable local to the current thread.
/// LWs are copied to any threads created by this one (EVT_EXEC, EVT_EXEC_WAIT, EVT_THREAD, EVT_CHILD_THREAD).
/// Additionally, EVT_EXEC_WAIT copies LWs back from the spawned thread when it completes.
///
/// Range: `0 <= v < 0x10`
/// Star Rod equivalent: `*Var[v]`.
#define LW(INDEX) ((((INDEX)) - 30000000))

/// Global Word. A variable global to all threads.
/// Cleared upon entering a new map.
///
/// Range: `0 <= v < 0x10`
/// Star Rod equivalent: `*MapVar[v]`.
#define GW(INDEX) ((((INDEX)) - 50000000))

/// Local Flag. A boolean variable local to the current thread.
/// LFs are copied to any threads created by this one (EVT_EXEC, EVT_EXEC_WAIT, EVT_THREAD, EVT_CHILD_THREAD).
/// Additionally, EVT_EXEC_WAIT copies LFs back from the spawned thread when it completes.
///
/// Range: `0 <= v < 0x60`
/// Star Rod equivalent: `*Flag[v]`.
#define LF(INDEX) ((((INDEX)) - 70000000))

/// Global Flag. A boolean variable global to all threads.
/// Cleared upon entering a new map.
///
/// Range: `0 <= v < 0x60`
/// Star Rod equivalent: `*MapFlag[v]`.
#define GF(INDEX) ((((INDEX)) - 90000000))

/// Local Save World Flag. A boolean variable local to the current world area, saved in the savefile.
/// Cleared upon entering a new world area.
///
/// Used to track whether items that respawn, such as coins, Goomnuts, or Koopa Leaves, have been collected.
///
/// Range: `0 <= v < 0x100`
/// Star Rod equivalent: `*AreaFlag[v]`.
#define LSWF(INDEX) ((((INDEX)) - 110000000))

/// Global Save World Flag. A boolean variable saved in the savefile.
///
/// Used to track whether badges, items, etc. have been collected or whether NPCs have been interacted with.
///
/// Range: `0 <= v < 0x800`
/// Star Rod equivalent: `*SaveFlag[v]`.
#define GSWF(INDEX) ((((INDEX)) - 130000000))

/// Local Saved **Byte**. A variable local to the current world area, saved in the savefile.
/// Cleared upon a new world area.
///
/// Rarely used. Most common use is for NPCs with dialogue that changes depending on the number of times you have
/// interacted with them in their 'recent memory' (i.e. until you leave the area).
///
/// Range: `0 <= v < 0x10`
/// Star Rod equivalent: `*AreaByte[v]`.
#define LSW(INDEX) ((((INDEX)) - 150000000))

/// Global Saved **Byte**. A variable saved in the save file.
///
/// Used for almost all savefile state.
#define GSW(INDEX) (((((INDEX)) - 170000000))

// TODO(docs): figure out what 'U' might stand for in UW and UF
/// **Array** Word. A variable stored within the current thread's array.
/// You can load an array with EVT_USE_ARRAY or temporarily allocate one with EVT_MALLOC_ARRAY, then get/set values with
/// the `UW(index)` macro.
///
/// Range: `0 <= v`
/// Star Rod equivalent: `*Array[v]`.
#define UW(INDEX) ((((INDEX)) - 190000000))

/// **Array** Flag. A boolean variable stored within the current thread's flag array.
/// The flag array is distinct from the word array (unlike EVT_USE_BUF and EVT_USE_FBUF).
///
/// Range: `0 <= v`
/// Star Rod equivalent: `*Array[v]`.
#define UF(INDEX) ((((v)) - 210000000))

/// An entity index. Entities are assigned indices in the order they are created with EVT_CALL(MakeEntity, ...).
/// Supported in EVT_BIND_TRIGGER and EVT_BIND_PADLOCK only.
#define EVT_ENTITY_INDEX(entityIndex) (((((entityIndex)) + 0x400)))


/****** INSTRUCTIONS **************************************************************************************************/

/// On each frame, the EVT manager will continue executing commands in all threads until a blocking command is
/// encountered. This means that if you have a thread that loops but does not block between iterations, the game will
/// freeze! Avoid this by inserting a blocking command such as EVT_WAIT_FRAMES(1) in the loop body.
///
/// Also note that threads are never executed in parallel. If your EVT script lacks blocking commands, it will be
/// executed all in one go, and race conditions cannot occur.
///
/// The following subset of EVT commands are blocking:
/// - EVT_EXEC_WAIT
/// - EVT_WAIT_FRAMES
/// - EVT_WAIT_SECONDS
/// - EVT_CALL (if function returns ApiStatus_BLOCK)

/// In EVT scripts, instructions are stored contiguously in the following structs:
///     struct {
///         Bytecode opcode;
///         Bytecode argc;
///         Bytecode argv[argc];
///     }
/// This macro expands to the given opcode and argv, with argc calculated automatically.
#define EVT_CMD(opcode, argv...) \
    opcode, \
    (sizeof((Bytecode[]){argv})/sizeof(Bytecode)), \
    ##argv

/// Signals the end of EVT script data. A script missing this will likely crash on load.
#define EVT_END                                 EVT_CMD(EVT_OP_END),

/// Kills the current EVT thread.
/// A script missing a return will live - but do nothing - forever, or until something else kills it (e.g. leaving the map).
#define EVT_RETURN                              EVT_CMD(EVT_OP_RETURN),

/// Jumps to a given instruction pointer and begins execution from there.
/// You can jump to a different EVT source and labels etc. will be loaded as expected.
/// The timescale for the current thread is also reset to the global default.
#define EVT_JUMP(EVT_SOURCE)                    EVT_CMD(EVT_OP_JUMP, (Bytecode) EVT_SOURCE),

/// Marks this point in the script as a EVT_GOTO target.
///
/// Range: `0 <= LABEL_ID <= 0x16`
#define EVT_LABEL(LABEL_ID)                     EVT_CMD(EVT_OP_LABEL, LABEL_ID),

/// Moves execution to the given label.
///
/// Range: `0 <= LABEL_ID <= 0x16`
#define EVT_GOTO(LABEL_ID)                      EVT_CMD(EVT_OP_GOTO, LABEL_ID),

/// Marks the beginning of a loop.
///
///     EVT_LOOP(TIMES)
///         ...
///     EVT_END_LOOP
///
/// The variable or value given in `TIMES` is decremented upon each loop iteration.
/// After the "1" iteration completes, the loop exits.
/// Use EVT_LOOP(0) for an infinite loop; make sure it breaks or blocks to avoid a freeze.
///
/// Up to 8 loops may be nested within a single script.
#define EVT_LOOP(TIMES)                         EVT_CMD(EVT_OP_LOOP, TIMES),

/// Marks the end of a loop.
#define EVT_END_LOOP                            EVT_CMD(EVT_OP_END_LOOP),

/// Breaks out of the innermost loop.
#define EVT_BREAK_LOOP                          EVT_CMD(EVT_OP_BREAK_LOOP),

/// Blocks for the given number of frames.
#define EVT_WAIT_FRAMES(NUM_FRAMES)             EVT_CMD(EVT_OP_WAIT_FRAMES, NUM_FRAMES),

/// Blocks for the given number of seconds.
#define EVT_WAIT_SECS(NUM_SECONDS)              EVT_CMD(EVT_OP_WAIT_SECS, NUM_SECONDS),

/// Marks the beginning of an if statement that only executes if `LVAR == RVAR`.
///
///     EVT_IF_EQ(LVAR, RVAR)
///         ...
///     EVT_ELSE
///         ...
///     EVT_END_IF
///
/// The EVT_ELSE block is optional.
#define EVT_IF_EQ(LVAR, RVAR)                   EVT_CMD(EVT_OP_IF_EQ, LVAR, RVAR),

/// Marks the beginning of an if statement that only executes if `LVAR != RVAR`.
#define EVT_IF_NE(LVAR, RVAR)                   EVT_CMD(EVT_OP_IF_NE, LVAR, RVAR),

/// Marks the beginning of an if statement that only executes if `LVAR < RVAR`.
#define EVT_IF_LT(LVAR, RVAR)                   EVT_CMD(EVT_OP_IF_LT, LVAR, RVAR),

/// Marks the beginning of an if statement that only executes if `LVAR <= RVAR`.
#define EVT_IF_GT(LVAR, RVAR)                   EVT_CMD(EVT_OP_IF_GT, LVAR, RVAR),

/// Marks the beginning of an if statement that only executes if `LVAR > RVAR`.
#define EVT_IF_LE(LVAR, RVAR)                   EVT_CMD(EVT_OP_IF_LE, LVAR, RVAR),

/// Marks the beginning of an if statement that only executes if `LVAR >= RVAR`.
#define EVT_IF_GE(LVAR, RVAR)                   EVT_CMD(EVT_OP_IF_GE, LVAR, RVAR),

/// Marks the beginning of an if statement that only executes if the RVAR flag is set on LVAR,
/// i.e. `(LVAR & RVAR) != 1`.
#define EVT_IF_FLAG(LVAR, RVAR)                 EVT_CMD(EVT_OP_IF_FLAG, LVAR, RVAR),

/// Marks the beginning of an if statement that only executes if the RVAR flag is unset on LVAR,
/// i.e. `(LVAR & RVAR) == 0`.
#define EVT_IF_NOT_FLAG(LVAR, RVAR)             EVT_CMD(EVT_OP_IF_NOT_FLAG, LVAR, RVAR),

/// Marks the end of an if statement and the start of the else block.
#define EVT_ELSE                                EVT_CMD(EVT_OP_ELSE),

/// Marks the end of an if statement or an else block.
#define EVT_END_IF                              EVT_CMD(EVT_OP_END_IF),

/// Marks the start of a switch statement.
///
///     EVT_SWITCH(LVAR)
///         EVT_CASE_EQ(RVAR)
///             ...
///     EVT_END_SWITCH
///
/// Unlike C, EVT switch statements do not have fallthrough by default.
/// If you want to opt-in to fallthrough, use EVT_CASE_OR_EQ.
///
/// Up to 8 switch statements may be nested within a single script.
#define EVT_SWITCH(LVAR)                        EVT_CMD(EVT_OP_SWITCH, LVAR),

/// Marks the start of a switch statement where the given value is treated as-is instead of using evt_get_variable.
/// That is, `EVT_SWITCH_CONST(LW(0))` will switch over the value `0xFE363C80` instead of the value contained
/// within `LW(0)`.
#define EVT_SWITCH_CONST(LCONST)                EVT_CMD(EVT_OP_SWITCH_CONST, LCONST),

/// Marks the start of a switch case that executes only if `LVAR == RVAR`. It also marks the end of any previous case.
#define EVT_CASE_EQ(RVAR)                       EVT_CMD(EVT_OP_CASE_EQ, RVAR),

/// Marks the start of a switch case that executes only if `LVAR != RVAR`. It also marks the end of any previous case.
#define EVT_CASE_NE(RVAR)                       EVT_CMD(EVT_OP_CASE_NE, RVAR),

/// Marks the start of a switch case that executes only if `LVAR < RVAR`. It also marks the end of any previous case.
#define EVT_CASE_LT(RVAR)                       EVT_CMD(EVT_OP_CASE_LT, RVAR),

/// Marks the start of a switch case that executes only if `LVAR <= RVAR`. It also marks the end of any previous case.
#define EVT_CASE_GT(RVAR)                       EVT_CMD(EVT_OP_CASE_GT, RVAR),

/// Marks the start of a switch case that executes only if `LVAR > RVAR`. It also marks the end of any previous case.
#define EVT_CASE_LE(RVAR)                       EVT_CMD(EVT_OP_CASE_LE, RVAR),

/// Marks the start of a switch case that executes only if `LVAR >= RVAR`. It also marks the end of any previous case.
#define EVT_CASE_GE(RVAR)                       EVT_CMD(EVT_OP_CASE_GE, RVAR),

/// Marks the start of a switch case that executes unconditionally. It also marks the end of any previous case.
#define EVT_CASE_DEFAULT                        EVT_CMD(EVT_OP_CASE_DEFAULT),

/// Marks the start of a switch case that executes only if `LVAR == RVAR`. It also marks the end of any previous case.
/// Unlike EVT_CASE_EQ, EVT_CASE_OR_EQ will fallthrough to the next case until EVT_END_CASE_GROUP is reached.
#define EVT_CASE_OR_EQ(RVAR)                    EVT_CMD(EVT_OP_CASE_OR_EQ, RVAR),

/// Marks the start of a switch case that executes only if `LVAR == RVAR`. It also marks the end of any previous case.
/// Similar to EVT_CASE_OR_EQ, EVT_CASE_AND_EQ has fallthrough. However, if `LVAR != RVAR`, fallthrough does not apply.
#define EVT_CASE_AND_EQ(RVAR)                   EVT_CMD(EVT_OP_CASE_AND_EQ, RVAR),

/// Marks the start of a switch case that executes only if the `RVAR` flag is set on `LVAR`, i.e. `(LVAR & RVAR) != 1`.
/// It also marks the end of any previous case.
#define EVT_CASE_FLAG(RVAR)                     EVT_CMD(EVT_OP_CASE_FLAG, RVAR),

/// Marks the end of a switch case group (EVT_CASE_OR_EQ and/or EVT_CASE_AND_EQ), stopping fallthrough.
#define EVT_END_CASE_GROUP                      EVT_CMD(EVT_OP_END_CASE_GROUP),

/// Marks the start of a switch case that executes only if `MIN <= LVAR <= MAX` (inclusive).
/// It also marks the end of any previous case.
#define EVT_CASE_RANGE(MIN, MAX)                EVT_CMD(EVT_OP_CASE_RANGE, MIN, MAX),

/// Marks the end of a switch statement and any case.
#define EVT_END_SWITCH                          EVT_CMD(EVT_OP_END_SWITCH),

/// Sets the given variable to a given value casted to an integer.
#define EVT_SET(VAR, INT_VALUE)                 EVT_CMD(EVT_OP_SET, VAR, (Bytecode) INT_VALUE),

/// Sets the given variable to a given value, skipping the evt_get_variable call.
/// That is, `EVT_SET_CONST(LW(0), LW(1))` will set `LW(0)` to `0xFE363C81` instead of copying the value of
/// `LW(1)` into `LW(0)`.
#define EVT_SET_CONST(VAR, CONST)               EVT_CMD(EVT_OP_SET_CONST, VAR, (Bytecode) CONST),

/// Sets the given variable to a given value, but supports EVT_FLOATs.
#define EVT_SETF(VAR, FLOAT_VALUE)              EVT_CMD(EVT_OP_SETF, VAR, FLOAT_VALUE),

// Basic arithmetic operations.
#define EVT_ADD(VAR, INT_VALUE)                 EVT_CMD(EVT_OP_ADD, VAR, INT_VALUE),
#define EVT_SUB(VAR, INT_VALUE)                 EVT_CMD(EVT_OP_SUB, VAR, INT_VALUE),
#define EVT_MUL(VAR, INT_VALUE)                 EVT_CMD(EVT_OP_MUL, VAR, INT_VALUE),
#define EVT_DIV(VAR, INT_VALUE)                 EVT_CMD(EVT_OP_DIV, VAR, INT_VALUE),
#define EVT_MOD(VAR, INT_VALUE)                 EVT_CMD(EVT_OP_MOD, VAR, INT_VALUE),

// Basic floating-point arithmetic operations.
#define EVT_ADDF(VAR, FLOAT_VALUE)              EVT_CMD(EVT_OP_ADDF, VAR, FLOAT_VALUE),
#define EVT_SUBF(VAR, FLOAT_VALUE)              EVT_CMD(EVT_OP_SUBF, VAR, FLOAT_VALUE),
#define EVT_MULF(VAR, FLOAT_VALUE)              EVT_CMD(EVT_OP_MULF, VAR, FLOAT_VALUE),
#define EVT_DIVF(VAR, FLOAT_VALUE)              EVT_CMD(EVT_OP_DIVF, VAR, FLOAT_VALUE),

/// Loads a s32 pointer for use with subsequent EVT_BUF_READ commands.
#define EVT_USE_BUF(INT_PTR)                    EVT_CMD(EVT_OP_USE_BUF, (Bytecode) INT_PTR),

/// Consumes the next s32 from the buffer and stores it in the given variable.
#define EVT_BUF_READ1(VAR)                      EVT_CMD(EVT_OP_BUF_READ1, VAR),

/// Consumes the next two s32s from the buffer and stores them in the given variables.
#define EVT_BUF_READ2(VAR1, VAR2)               EVT_CMD(EVT_OP_BUF_READ2, VAR1, VAR2),

/// Consumes the next three s32s from the buffer and stores them in the given variables.
#define EVT_BUF_READ3(VAR1, VAR2, VAR3)         EVT_CMD(EVT_OP_BUF_READ3, VAR1, VAR2, VAR3),

/// Consumes the next four s32s from the buffer and stores them in the given variables.
#define EVT_BUF_READ4(VAR1, VAR2, VAR3, VAR4)   EVT_CMD(EVT_OP_BUF_READ4, VAR1, VAR2, VAR3, VAR4),

/// Gets the s32 at the given offset of the buffer and stores it in the given variable, without consuming it.
#define EVT_BUF_PEEK(OFFSET, VAR)               EVT_CMD(EVT_OP_BUF_PEEK, OFFSET, VAR),

/// Identical to EVT_USE_BUF. Beware that the int buffer and the float buffer are not distinct.
#define EVT_USE_FBUF(FLOAT_PTR)                 EVT_CMD(EVT_OP_USE_FBUF, (Bytecode) FLOAT_PTR),

/// Consumes the next f32 from the buffer and stores it in the given variable.
#define EVT_FBUF_READ1(VAR)                     EVT_CMD(EVT_OP_FBUF_READ1, VAR),

/// Consumes the next two f32s from the buffer and stores them in the given variables.
#define EVT_FBUF_READ2(VAR1, VAR2)              EVT_CMD(EVT_OP_FBUF_READ2, VAR1, VAR2),

/// Consumes the next three f32s from the buffer and stores them in the given variables.
#define EVT_FBUF_READ3(VAR1, VAR2, VAR3)        EVT_CMD(EVT_OP_FBUF_READ3, VAR1, VAR2, VAR3),

/// Consumes the next four f32s from the buffer and stores them in the given variables.
#define EVT_FBUF_READ4(VAR1, VAR2, VAR3, VAR4)  EVT_CMD(EVT_OP_FBUF_READ4, VAR1, VAR2, VAR3, VAR4),

/// Gets the f32 at the given offset of the buffer and stores it in the given variable, without consuming it.
#define EVT_FBUF_PEEK(OFFSET, VAR)              EVT_CMD(EVT_OP_FBUF_PEEK, OFFSET, VAR),

/// Loads an s32 array pointer into the current thread for use with `UW(INDEX)`.
#define EVT_USE_ARRAY(INT_PTR)                  EVT_CMD(EVT_OP_USE_ARRAY, (Bytecode) INT_PTR),

/// Loads an s32 array pointer into the current thread for use with `UF(INDEX)`.
/// Flags are stored in a 'packed' structure where indices refer to bits.
#define EVT_USE_FLAG_ARRAY(PACKED_FLAGS_PTR)    EVT_CMD(EVT_OP_USE_FLAG_ARRAY, (Bytecode) PACKED_FLAGS_PTR),

/// Allocates a new array of the given size for use with `UW(INDEX)`.
/// EVT scripts do not have to worry about freeing this array.
#define EVT_MALLOC_ARRAY(SIZE, OUT_PTR_VAR)     EVT_CMD(EVT_OP_MALLOC_ARRAY, SIZE, OUT_PTR_VAR),

/// `VAR &= VALUE`
#define EVT_BITWISE_AND(VAR, VALUE)             EVT_CMD(EVT_OP_BITWISE_AND, VAR, VALUE),

/// `VAR |= VALUE`
#define EVT_BITWISE_OR(VAR, VALUE)              EVT_CMD(EVT_OP_BITWISE_OR, VAR, VALUE),

/// `VAR &= CONST`, but CONST is treated as-is rather than dereferenced with evt_get_variable.
#define EVT_BITWISE_AND_CONST(VAR, CONST)       EVT_CMD(EVT_OP_BITWISE_AND_CONST, VAR, CONST),

/// `VAR |= CONST`, but CONST is treated as-is rather than dereferenced with evt_get_variable.
#define EVT_BITWISE_OR_CONST(VAR, CONST)        EVT_CMD(EVT_OP_BITWISE_OR_CONST, VAR, CONST),

/// Launches a new thread.
/// The following values are copied from the current thread to the new thread:
/// - LFs
/// - LWs
/// - Array pointer
/// - Flag array pointer
/// - Priority
/// - Group
#define EVT_EXEC(EVT_SOURCE)                    EVT_CMD(EVT_OP_EXEC, (Bytecode) EVT_SOURCE),

/// Identical to EVT_EXEC, but the newly-launched thread ID is stored in OUTVAR.
/// The other thread may be interacted with using EVT_KILL_THREAD, EVT_SUSPEND_THREAD, EVT_RESUME_THREAD, and
/// EVT_IS_THREAD_RUNNING.
#define EVT_EXEC_GET_TID(EVT_SOURCE, OUTVAR)    EVT_CMD(EVT_OP_EXEC_GET_TID, (Bytecode) EVT_SOURCE, OUTVAR),

/// Launches a new child thread.
/// Blocks for at least one frame unless the child thread is made to have a higher priority than the parent.
///
/// The following values are inherited and then copied back to the parent thread upon completion:
/// - LFs
/// - LWs
/// - Array pointer
/// - Flag array pointer
/// - Priority
/// - Group
///
/// Child threads are killed, suspended, and resumed as their parents are, for example, a different thread using
/// EVT_KILL_THREAD to kill a parent thread would also kill its child thread(s) launched by this command.
#define EVT_EXEC_WAIT(EVT_SOURCE)               EVT_CMD(EVT_OP_EXEC_WAIT, (Bytecode) EVT_SOURCE),

/// Sets up a script to launch when a particular event is triggered.
///
/// Valid triggers:
/// - TRIGGER_WALL_PUSH
/// - TRIGGER_FLOOR_TOUCH
/// - TRIGGER_WALL_PRESS_A (displays "!" icon above player)
/// - TRIGGER_FLOOR_JUMP
/// - TRIGGER_WALL_TOUCH
/// - TRIGGER_FLOOR_PRESS_A
/// - TRIGGER_WALL_HAMMER
/// - TRIGGER_GAME_FLAG_SET (TODO: rename)
/// - TRIGGER_AREA_FLAG_SET (TODO: rename)
/// - TRIGGER_CEILING_TOUCH
/// - TRIGGER_FLOOR_ABOVE
/// - TRIGGER_POINT_BOMB (takes Vec3f* instead of collider ID)
///
/// For the `COLLIDER_ID` param, the following values are accepted:
/// - Collider ID
/// - Entity ID (use EVT_ENTITY_INDEX)
/// - Pointer to a Vec3f (for TRIGGER_POINT_BOMB only)
///
/// Only one thread will run for a trigger at once.
#define EVT_BIND_TRIGGER(EVT_SOURCE, TRIGGER, COLLIDER_ID, UNK_A3, TRIGGER_PTR_OUTVAR) \
    EVT_CMD(EVT_OP_BIND_TRIGGER, (Bytecode) EVT_SOURCE, TRIGGER, (Bytecode) COLLIDER_ID, UNK_A3, TRIGGER_PTR_OUTVAR),

/// Similar to EVT_BIND_TRIGGER, but also takes arguments for the item list to show.
#define EVT_BIND_PADLOCK(EVT_SOURCE, TRIGGER, COLLIDER_ID, ITEM_LIST, UNK_A3, TRIGGER_PTR_OUTVAR) \
    EVT_CMD(EVT_OP_BIND_PADLOCK, (Bytecode) EVT_SOURCE, TRIGGER, COLLIDER_ID, (Bytecode) ITEM_LIST, UNK_A3, TRIGGER_PTR_OUTVAR),

/// Unbinds the current thread from the trigger it was bound to, if any.
#define EVT_UNBIND                              EVT_CMD(EVT_OP_UNBIND),

/// Kills a thread by its thread ID.
#define EVT_KILL_THREAD(TID)                    EVT_CMD(EVT_OP_KILL_THREAD, TID),

/// Sets the current thread's priority. Higher-priority threads execute before lower-priority threads on each frame.
#define EVT_SET_PRIORITY(PRIORITY)              EVT_CMD(EVT_OP_SET_PRIORITY, PRIORITY),

/// Sets the current thread's timescale. This is a multiplier applied to EVT_WAIT_FRAMES and EVT_WAIT_SECONDS.
#define EVT_SET_TIMESCALE(TIMESCALE)            EVT_CMD(EVT_OP_SET_TIMESCALE, TIMESCALE),

/// Sets the current thread's group. Group value meanings are currently not known.
#define EVT_SET_GROUP(GROUP)                    EVT_CMD(EVT_OP_SET_GROUP, GROUP),

/// Suspends all threads in a group.
#define EVT_SUSPEND_GROUP(GROUP)                EVT_CMD(EVT_OP_SUSPEND_GROUP, GROUP),

/// Resumes all threads in a group.
#define EVT_RESUME_GROUP(GROUP)                 EVT_CMD(EVT_OP_RESUME_GROUP, GROUP),

/// Suspends all threads in a group, except the current thread.
#define EVT_SUSPEND_OTHERS(GROUP)               EVT_CMD(EVT_OP_SUSPEND_OTHERS, GROUP),

/// Resumes all threads in a group, except the current thread.
#define EVT_RESUME_OTHERS(GROUP)                EVT_CMD(EVT_OP_RESUME_OTHERS, GROUP),

/// Suspends all threads in a group, except the current thread.
#define EVT_SUSPEND_THREAD(TID)                 EVT_CMD(EVT_OP_SUSPEND_THREAD, TID),

/// Resumes a thread by its thread ID.
#define EVT_RESUME_THREAD(TID)                  EVT_CMD(EVT_OP_RESUME_THREAD, TID),

/// Sets OUTVAR to TRUE/FALSE depending on whether a thread with the given ID exists (i.e. has not been killed).
#define EVT_IS_THREAD_RUNNING(TID, OUTVAR)      EVT_CMD(EVT_OP_IS_THREAD_RUNNING, TID, OUTVAR),

/// Marks the start of a thread block. Commands between this and a matching EVT_END_THREAD
/// will be executed on their own, new thread instead of on the current thread.
#define EVT_THREAD                              EVT_CMD(EVT_OP_THREAD),

/// Marks the end of a thread block.
#define EVT_END_THREAD                          EVT_CMD(EVT_OP_END_THREAD),

/// Marks the start of a child thread block. Commands between this and a matching EVT_END_CHILD_THREAD
/// will be executed as a new child thread instead of on the current thread.
///
/// Child threads are killed if the parent thread dies, so the following script does NOT set the player's position:
///
///     EVT_CHILD_THREAD
///         EVT_WAIT_SECONDS(1)                 // child thread will be killed whilst waiting
///         EVT_CALL(SetPlayerPos, 0, -1000, 0) // will not be executed
///     EVT_END_CHILD_THREAD
///     EVT_RETURN                              // parent thread dies
///
#define EVT_CHILD_THREAD                        EVT_CMD(EVT_OP_CHILD_THREAD),

/// Marks the end of a child thread block.
#define EVT_END_CHILD_THREAD                    EVT_CMD(EVT_OP_END_CHILD_THREAD),

/// Calls a given C EVT API function with any number of arguments.
///
/// An API function has the following signature:
///
///     ApiStatus ApiFunction(Evt* thread, s32 isInitialCall);
///
/// This function could then be called with the following command:
///
///     EVT_CALL(ApiFunction)
///
/// The given arguments can be accessed from the API function using `thread->ptrReadPos`.
#define EVT_CALL(FUNC, ...)                     EVT_CMD(EVT_OP_CALL, (Bytecode) FUNC, ##__VA_ARGS__),


/****** COMMON SCRIPTS ************************************************************************************************/

#define EXIT_WALK_SCRIPT(walkDistance, exitIdx, map, entryIdx) \
    { \
        EVT_SET_GROUP(0x1B) \
        EVT_CALL(UseExitHeading, walkDistance, exitIdx) \
        EVT_EXEC(ExitWalk) \
        EVT_CALL(GotoMap, EVT_PTR(map), entryIdx) \
        EVT_WAIT_FRAMES(100) \
        EVT_RETURN \
        EVT_END \
    }

#endif
