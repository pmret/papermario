#ifndef _SCRIPT_API_MACROS_H_
#define _SCRIPT_API_MACROS_H_

#include "evt.h"
#include "stdlib/stdarg.h"

/****** EXPRESSIONS ***************************************************************************************************/

/// Expressions in EVT instructions should be one of the following types:
/// - Integer literals (as-is, s32)
/// - Float literals (EVT_FLOAT) - cast to int where a float is not accepted
/// - Pointers, string literals (EVT_PTR)
/// - Variables (LW, GW, LSW, GSW, UW)
/// - Flags (LF, GF, LSWF, GSWF, UF)
/// This is implemented in `evt_get_variable` and `evt_get_float_variable`.

/// Decimal constant.
/// Despite the name, "floats" are actually stored as fixed-point values.

#define EVT_LOCAL_VAR_CUTOFF     -20000000
#define EVT_LOCAL_VAR_OFFSET      30000000
#define EVT_MAP_VAR_CUTOFF       -40000000
#define EVT_MAP_VAR_OFFSET        50000000
#define EVT_LOCAL_FLAG_CUTOFF    -60000000
#define EVT_LOCAL_FLAG_OFFSET     70000000
#define EVT_MAP_FLAG_CUTOFF      -80000000
#define EVT_MAP_FLAG_OFFSET       90000000
#define EVT_AREA_FLAG_CUTOFF    -100000000
#define EVT_AREA_FLAG_OFFSET     110000000
#define EVT_GAME_FLAG_CUTOFF    -120000000
#define EVT_GAME_FLAG_OFFSET     130000000
#define EVT_AREA_BYTE_CUTOFF    -140000000
#define EVT_AREA_BYTE_OFFSET     150000000
#define EVT_GAME_BYTE_CUTOFF    -160000000
#define EVT_GAME_BYTE_OFFSET     170000000
#define EVT_ARRAY_VAR_CUTOFF    -180000000
#define EVT_ARRAY_VAR_OFFSET     190000000
#define EVT_ARRAY_FLAG_CUTOFF   -200000000
#define EVT_ARRAY_FLAG_OFFSET    210000000
#define EVT_FIXED_CUTOFF        -220000000
#define EVT_FIXED_OFFSET         230000000
#define EVT_IGNORE_ARG          -250000000 // used by a couple functions to selectively ignore args
#define EVT_LIMIT               -270000000 // TODO better name

 // This fixes an issue with fixed point numbers not being correct. Potentially a truncation vs round difference.
#define EVT_FLOAT_ROUND(x) ((x) >=0 ? (f64)((x) + 0.9) : (f64)(x))
#define EVT_FLOAT(DOUBLE)  ((Bytecode)EVT_FLOAT_ROUND(((DOUBLE) * 1024.0f)) - EVT_FIXED_OFFSET)

/// Progammatically converts EVT_FLOAT --> f32
#define EVT_FIXED_TO_FLOAT(x) ({f32 var = (x) + EVT_FIXED_OFFSET; var /= 1024.0f; var;})

/// Progammatically converts f32 --> EVT_FLOAT
#define EVT_FLOAT_TO_FIXED(x) (((x) * 1024.0f) + -EVT_FIXED_OFFSET)

/// Address/pointer constant.
#define EVT_PTR(sym) ((Bytecode) &(sym))

/// Local Word. A variable local to the current thread.
/// LWs are copied to any threads created by this one (EVT_EXEC, EVT_EXEC_WAIT, EVT_THREAD, EVT_CHILD_THREAD).
/// Additionally, EVT_EXEC_WAIT copies LWs back from the spawned thread when it completes.
///
/// Range: `0 <= v < 0x10`
#define LocalVar(INDEX) ((INDEX) - EVT_LOCAL_VAR_OFFSET)

/// Global Word. A variable global to all threads.
/// Cleared upon entering a new map.
///
/// Range: `0 <= v < 0x10`
#define MapVar(INDEX) ((INDEX) - EVT_MAP_VAR_OFFSET)

/// Local Flag. A boolean variable local to the current thread.
/// LFs are copied to any threads created by this one (EVT_EXEC, EVT_EXEC_WAIT, EVT_THREAD, EVT_CHILD_THREAD).
/// Additionally, EVT_EXEC_WAIT copies LFs back from the spawned thread when it completes.
///
/// Range: `0 <= v < 0x60`
#define LocalFlag(INDEX) ((INDEX) - EVT_LOCAL_FLAG_OFFSET)

/// Global Flag. A boolean variable global to all threads.
/// Cleared upon entering a new map.
///
/// Range: `0 <= v < 0x60`
#define MapFlag(INDEX) ((INDEX) - EVT_MAP_FLAG_OFFSET)

/// Local Save World Flag. A boolean variable local to the current world area, saved in the savefile.
/// Cleared upon entering a new world area.
///
/// Used to track whether items that respawn, such as coins, Goomnuts, or Koopa Leaves, have been collected.
///
/// Range: `0 <= v < 0x100`
#define AreaFlag(INDEX) ((INDEX) - EVT_AREA_FLAG_OFFSET)

/// Global Save World Flag. A boolean variable saved in the savefile.
///
/// Used to track whether badges, items, etc. have been collected or whether NPCs have been interacted with.
///
/// Range: `0 <= v < 0x800`
#define GameFlag(INDEX) ((INDEX) - EVT_GAME_FLAG_OFFSET)

/// Local Saved **Byte**. A variable local to the current world area, saved in the savefile.
/// Cleared upon a new world area.
///
/// Rarely used. Most common use is for NPCs with dialogue that changes depending on the number of times you have
/// interacted with them in their 'recent memory' (i.e. until you leave the area).
///
/// Range: `0 <= v < 0x10`
#define AreaByte(INDEX) ((INDEX) - EVT_AREA_BYTE_OFFSET)

/// Global Saved **Byte**. A variable saved in the save file.
///
/// Used for almost all savefile state.
#define GameByte(INDEX) ((INDEX) - EVT_GAME_BYTE_OFFSET)

/// User Word. A variable stored within the current thread's array.
/// You can load an array with EVT_USE_ARRAY or temporarily allocate one with EVT_MALLOC_ARRAY, then get/set values with
/// the `ArrayVar(index)` macro.
///
/// Range: `0 <= v`
#define ArrayVar(INDEX) ((INDEX) - EVT_ARRAY_VAR_OFFSET)

/// User Flag. A boolean variable stored within the current thread's flag array.
/// The flag array is distinct from the word array (unlike EVT_USE_BUF and EVT_USE_FBUF).
///
/// Range: `0 <= v`
#define ArrayFlag(INDEX) ((INDEX) - EVT_ARRAY_FLAG_OFFSET)

/// An entity index. Entities are assigned indices in the order they are created with EVT_CALL(MakeEntity, ...).
/// Supported in EVT_BIND_TRIGGER and EVT_BIND_PADLOCK only.
#define EVT_ENTITY_ID_BIT 0x4000
#define EVT_ENTITY_INDEX(entityIndex) ((entityIndex) + EVT_ENTITY_ID_BIT)

// inverse macros for obtaining the index of a variable from its encoded form
#define EVT_INDEX_OF_LOCAL_VAR(v)   ((v) + EVT_LOCAL_VAR_OFFSET)
#define EVT_INDEX_OF_LOCAL_FLAG(v)  ((v) + EVT_LOCAL_FLAG_OFFSET)
#define EVT_INDEX_OF_MAP_VAR(v)     ((v) + EVT_MAP_VAR_OFFSET)
#define EVT_INDEX_OF_MAP_FLAG(v)    ((v) + EVT_MAP_FLAG_OFFSET)
#define EVT_INDEX_OF_AREA_FLAG(v)   ((v) + EVT_AREA_FLAG_OFFSET)
#define EVT_INDEX_OF_AREA_BYTE(v)   ((v) + EVT_AREA_BYTE_OFFSET)
#define EVT_INDEX_OF_GAME_FLAG(v)   ((v) + EVT_GAME_FLAG_OFFSET)
#define EVT_INDEX_OF_GAME_BYTE(v)   ((v) + EVT_GAME_BYTE_OFFSET)
#define EVT_INDEX_OF_ARRAY_FLAG(v)  ((v) + EVT_ARRAY_FLAG_OFFSET)
#define EVT_INDEX_OF_ARRAY_VAR(v)   ((v) + EVT_ARRAY_VAR_OFFSET)

// shorthand names for LocalVar
#define LVar0 LocalVar(0)
#define LVar1 LocalVar(1)
#define LVar2 LocalVar(2)
#define LVar3 LocalVar(3)
#define LVar4 LocalVar(4)
#define LVar5 LocalVar(5)
#define LVar6 LocalVar(6)
#define LVar7 LocalVar(7)
#define LVar8 LocalVar(8)
#define LVar9 LocalVar(9)
#define LVarA LocalVar(10)
#define LVarB LocalVar(11)
#define LVarC LocalVar(12)
#define LVarD LocalVar(13)
#define LVarE LocalVar(14)
#define LVarF LocalVar(15)

// shorthand names for common LocalFlags
// these actually run all the way up to LocalFlag(96), but nothing past 15 is ever used
#define LFlag0 LocalFlag(0)
#define LFlag1 LocalFlag(1)
#define LFlag2 LocalFlag(2)
#define LFlag3 LocalFlag(3)
#define LFlag4 LocalFlag(4)
#define LFlag5 LocalFlag(5)
#define LFlag6 LocalFlag(6)
#define LFlag7 LocalFlag(7)
#define LFlag8 LocalFlag(8)
#define LFlag9 LocalFlag(9)
#define LFlagA LocalFlag(10)
#define LFlagB LocalFlag(11)
#define LFlagC LocalFlag(12)
#define LFlagD LocalFlag(13)
#define LFlagE LocalFlag(14)
#define LFlagF LocalFlag(15)

/****** INSTRUCTIONS **************************************************************************************************/

/// On each frame, the EVT manager will continue executing commands in all threads until a blocking command is
/// encountered. This means that if you have a thread that loops but does not block between iterations, the game will
/// freeze! Avoid this by inserting a blocking command such as EVT_WAIT(1) in the loop body.
///
/// Also note that threads are never executed in parallel. If your EVT script lacks blocking commands, it will be
/// executed all in one go, and race conditions cannot occur.
///
/// The following subset of EVT commands are blocking:
/// - EVT_EXEC_WAIT
/// - EVT_WAIT
/// - EVT_WAIT_SECONDS
/// - EVT_CALL (if function returns ApiStatus_BLOCK)

/// In EVT scripts, instructions are stored contiguously in the following structs:
///     struct {
///         Bytecode opcode;
///         Bytecode argc;
///         Bytecode argv[argc];
///     }
/// This macro expands to the given opcode and argv, with argc calculated automatically.

#ifndef PERMUTER
#ifndef M2CTX
#define EVT_CMD(opcode, argv...) \
    opcode, \
    (sizeof((Bytecode[]){argv})/sizeof(Bytecode)), \
    ##argv
#else
// This definition that passes in 0 for the number of args is used for pycparser since it can't handle varargs
#define EVT_CMD(opcode, argv...) \
    opcode, \
    0, \
    ##argv
#endif
#else
// This definition that passes in 0 for the number of args is used for pycparser since it can't handle varargs
#define EVT_CMD(opcode, argv...) \
    opcode, \
    0, \
    ##argv
#endif

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
#define EVT_WAIT(NUM_FRAMES)                    EVT_CMD(EVT_OP_WAIT_FRAMES, NUM_FRAMES),


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
/// That is, `EVT_SWITCH_CONST(LocalVar(0))` will switch over the value `0xFE363C80` instead of the value contained
/// within `LocalVar(0)`.
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

/// Marks the end of a switch case
#define EVT_BREAK_SWITCH                        EVT_CMD(EVT_OP_BREAK_SWITCH),

/// Marks the end of a switch statement and any case.
#define EVT_END_SWITCH                          EVT_CMD(EVT_OP_END_SWITCH),

/// Sets the given variable to a given value casted to an integer.
#define EVT_SET(VAR, INT_VALUE)                 EVT_CMD(EVT_OP_SET, VAR, (Bytecode) INT_VALUE),

/// Sets the given variable to a given value, skipping the evt_get_variable call.
/// That is, `EVT_SET_CONST(LocalVar(0), LocalVar(1))` will set `LocalVar(0)` to `0xFE363C81` instead of copying the value of
/// `LocalVar(1)` into `LocalVar(0)`.
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

/// Loads an s32 array pointer into the current thread for use with `ArrayVar(INDEX)`.
#define EVT_USE_ARRAY(INT_PTR)                  EVT_CMD(EVT_OP_USE_ARRAY, (Bytecode) INT_PTR),

/// Loads an s32 array pointer into the current thread for use with `UF(INDEX)`.
/// Flags are stored in a 'packed' structure where indices refer to bits.
#define EVT_USE_FLAG_ARRAY(PACKED_FLAGS_PTR)    EVT_CMD(EVT_OP_USE_FLAG_ARRAY, (Bytecode) PACKED_FLAGS_PTR),

/// Allocates a new array of the given size for use with `ArrayVar(INDEX)`.
/// EVT scripts do not have to worry about freeing this array.
#define EVT_MALLOC_ARRAY(SIZE, OUT_PTR_VAR)     EVT_CMD(EVT_OP_MALLOC_ARRAY, SIZE, OUT_PTR_VAR),

/// `VAR &= VALUE`
#define EVT_BITWISE_AND(VAR, VALUE)             EVT_CMD(EVT_OP_BITWISE_AND, VAR, VALUE),

/// `VAR &= CONST`, but CONST is treated as-is rather than dereferenced with evt_get_variable.
#define EVT_BITWISE_AND_CONST(VAR, CONST)       EVT_CMD(EVT_OP_BITWISE_AND_CONST, VAR, CONST),

/// `VAR |= VALUE`
#define EVT_BITWISE_OR(VAR, VALUE)              EVT_CMD(EVT_OP_BITWISE_OR, VAR, VALUE),

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

/// Sets the current thread's timescale. This is a multiplier applied to EVT_WAIT and EVT_WAIT_SECONDS.
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
///         EVT_CALL(SetPlayerPos, NPC_DISPOSE_LOCATION) // will not be executed
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
#define EVT_CALL(FUNC, ARGS...)                     EVT_CMD(EVT_OP_CALL, (Bytecode) FUNC, ##ARGS),

/// Does nothing in release version
#define EVT_DEBUG_LOG(STRING)                   EVT_CMD(EVT_OP_DEBUG_LOG, STRING),

/// Prints variable name and value
#define EVT_DEBUG_PRINT_VAR(VAR)                EVT_CMD(EVT_OP_DEBUG_PRINT_VAR, VAR),

/****** VECTOR OPERATIONS *********************************************************************************************/

// expand vector components
#define EVT_AS_VEC2(baseVar) (baseVar), (baseVar + 1)
#define EVT_AS_VEC3(baseVar) (baseVar), (baseVar + 1), (baseVar + 2)

// extract components from vector
#define EVT_VEC_X(baseVar) (baseVar)
#define EVT_VEC_Y(baseVar) (baseVar + 1)
#define EVT_VEC_Z(baseVar) (baseVar + 2)

#define EVT_VEC2_OP(OPERATION, MUT_BASE, x, y) \
    OPERATION(MUT_BASE + 0, x) \
    OPERATION(MUT_BASE + 1, y)

#define EVT_VEC3_OP(OPERATION, MUT_BASE, x, y, z) \
    OPERATION(MUT_BASE + 0, x) \
    OPERATION(MUT_BASE + 1, y) \
    OPERATION(MUT_BASE + 2, z)

#define EVT_VEC2_VOP(OPERATION, MUT_BASE, AMT_BASE) \
    OPERATION(MUT_BASE + 0, AMT_BASE + 0) \
    OPERATION(MUT_BASE + 1, AMT_BASE + 1)

#define EVT_VEC3_VOP(OPERATION, MUT_BASE, AMT_BASE) \
    OPERATION(MUT_BASE + 0, AMT_BASE + 0) \
    OPERATION(MUT_BASE + 1, AMT_BASE + 1) \
    OPERATION(MUT_BASE + 2, AMT_BASE + 2)

#define EVT_VEC2I_SET(baseVar, x, y)    EVT_VEC2_OP(EVT_SET, baseVar, x, y)
#define EVT_VEC2F_SET(baseVar, x, y)    EVT_VEC2_OP(EVT_SETF, baseVar, x, y)
#define EVT_VEC3I_SET(baseVar, x, y, z) EVT_VEC3_OP(EVT_SET, baseVar, x, y, z)
#define EVT_VEC3F_SET(baseVar, x, y, z) EVT_VEC3_OP(EVT_SETF, baseVar, x, y, z)

#define EVT_VEC2I_VSET(baseVar, baseSrc) EVT_VEC2_VOP(EVT_SET, baseVar, baseSrc)
#define EVT_VEC2F_VSET(baseVar, baseSrc) EVT_VEC2_VOP(EVT_SETF, baseVar, baseSrc)
#define EVT_VEC3I_VSET(baseVar, baseSrc) EVT_VEC3_VOP(EVT_SET, baseVar, baseSrc)
#define EVT_VEC3F_VSET(baseVar, baseSrc) EVT_VEC3_VOP(EVT_SETF, baseVar, baseSrc)

#define EVT_VEC2I_ADD(baseVar, x, y)    EVT_VEC2_OP(EVT_ADD, baseVar, x, y)
#define EVT_VEC2F_ADD(baseVar, x, y)    EVT_VEC2_OP(EVT_ADDF, baseVar, x, y)
#define EVT_VEC3I_ADD(baseVar, x, y, z) EVT_VEC3_OP(EVT_ADD, baseVar, x, y, z)
#define EVT_VEC3F_ADD(baseVar, x, y, z) EVT_VEC3_OP(EVT_ADDF, baseVar, x, y, z)

#define EVT_VEC2I_VADD(baseVar, baseAmt) EVT_VEC2_VOP(EVT_ADD, baseVar, baseAmt)
#define EVT_VEC2F_VADD(baseVar, baseAmt) EVT_VEC2_VOP(EVT_ADDF, baseVar, baseAmt)
#define EVT_VEC3I_VADD(baseVar, baseAmt) EVT_VEC3_VOP(EVT_ADD, baseVar, baseAmt)
#define EVT_VEC3F_VADD(baseVar, baseAmt) EVT_VEC3_VOP(EVT_ADDF, baseVar, baseAmt)

#define EVT_VEC2I_SUB(baseVar, x, y)    EVT_VEC2_OP(EVT_SUB, baseVar, x, y)
#define EVT_VEC2F_SUB(baseVar, x, y)    EVT_VEC2_OP(EVT_SUBF, baseVar, x, y)
#define EVT_VEC3I_SUB(baseVar, x, y, z) EVT_VEC3_OP(EVT_SUB, baseVar, x, y, z)
#define EVT_VEC3F_SUB(baseVar, x, y, z) EVT_VEC3_OP(EVT_SUBF, baseVar, x, y, z)

#define EVT_VEC2I_VSUB(baseVar, baseAmt) EVT_VEC2_VOP(EVT_SUB, baseVar, baseAmt)
#define EVT_VEC2F_VSUB(baseVar, baseAmt) EVT_VEC2_VOP(EVT_SUBF, baseVar, baseAmt)
#define EVT_VEC3I_VSUB(baseVar, baseAmt) EVT_VEC3_VOP(EVT_SUB, baseVar, baseAmt)
#define EVT_VEC3F_VSUB(baseVar, baseAmt) EVT_VEC3_VOP(EVT_SUBF, baseVar, baseAmt)

/****** COMMON SCRIPTS ************************************************************************************************/

#define EVT_IF_TRUE(b)  EVT_IF_NE(b, 0)
#define EVT_IF_FALSE(b) EVT_IF_EQ(b, 0)

#define EVT_EXIT_WALK(walkDistance, exitIdx, map, entryIdx) \
    { \
        EVT_SET_GROUP(EVT_GROUP_1B) \
        EVT_CALL(UseExitHeading, walkDistance, exitIdx) \
        EVT_EXEC(ExitWalk) \
        EVT_CALL(GotoMap, EVT_PTR(map), entryIdx) \
        EVT_WAIT(100) \
        EVT_RETURN \
        EVT_END \
    }

// alternate version of EVT_EXIT_WALK used on Pleasant Path which does not join EVT_GROUP_1B
#define EVT_EXIT_WALK_NOK(walkDistance, exitIdx, map, entryIdx) \
    { \
        EVT_CALL(UseExitHeading, walkDistance, exitIdx) \
        EVT_EXEC(ExitWalk) \
        EVT_CALL(GotoMap, EVT_PTR(map), entryIdx) \
        EVT_WAIT(100) \
        EVT_RETURN \
        EVT_END \
    }

// alternate version of EVT_EXIT_WALK which includes a call to DisablePlayerInput
#define EVT_EXIT_WALK_FIXED(walkDistance, exitIdx, map, entryIdx) \
    { \
        EVT_SET_GROUP(EVT_GROUP_1B) \
        EVT_CALL(DisablePlayerInput, TRUE) \
        EVT_CALL(UseExitHeading, walkDistance, exitIdx) \
        EVT_EXEC(ExitWalk) \
        EVT_CALL(GotoMap, EVT_PTR(map), entryIdx) \
        EVT_WAIT(100) \
        EVT_RETURN \
        EVT_END \
    }

#define EVT_EXIT_SINGLE_DOOR(exitIdx, map, entryIdx, colliderID, modelID, swingDir) \
    { \
        EVT_SET_GROUP(EVT_GROUP_1B) \
        EVT_CALL(DisablePlayerInput, TRUE) \
        EVT_SET(LVar0, exitIdx) \
        EVT_SET(LVar1, colliderID) \
        EVT_SET(LVar2, modelID) \
        EVT_SET(LVar3, swingDir) \
        EVT_EXEC(ExitSingleDoor) \
        EVT_WAIT(17) \
        EVT_CALL(GotoMap, EVT_PTR(map), entryIdx) \
        EVT_WAIT(100) \
        EVT_RETURN \
        EVT_END \
    }

#define EVT_EXIT_SPLIT_SINGLE_DOOR(exitIdx, map, entryIdx, colliderID, topModelID, bottomModelID, swingDir) \
    { \
        EVT_SET_GROUP(EVT_GROUP_1B) \
        EVT_CALL(DisablePlayerInput, TRUE) \
        EVT_SET(LVar0, exitIdx) \
        EVT_SET(LVar1, colliderID) \
        EVT_SET(LVar2, topModelID) \
        EVT_SET(LVar4, bottomModelID) \
        EVT_SET(LVar3, swingDir) \
        EVT_EXEC(ExitSplitSingleDoor) \
        EVT_WAIT(17) \
        EVT_CALL(GotoMap, EVT_PTR(map), entryIdx) \
        EVT_WAIT(100) \
        EVT_RETURN \
        EVT_END \
    }

#define EVT_EXIT_DOUBLE_DOOR(exitIdx, map, entryIdx, colliderID, leftDoorModelID, rightDoorModelID) \
    { \
        EVT_SET_GROUP(EVT_GROUP_1B) \
        EVT_CALL(DisablePlayerInput, TRUE) \
        EVT_SET(LVar0, exitIdx) \
        EVT_SET(LVar1, colliderID) \
        EVT_SET(LVar2, leftDoorModelID) \
        EVT_SET(LVar3, rightDoorModelID) \
        EVT_EXEC(ExitDoubleDoor) \
        EVT_WAIT(17) \
        EVT_CALL(GotoMap, EVT_PTR(map), entryIdx) \
        EVT_WAIT(100) \
        EVT_RETURN \
        EVT_END \
    }

// only set perspective to standard values
#define EVT_SETUP_CAMERA_MINIMAL() \
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096)

#define EVT_SETUP_CAMERA_DEFAULT() \
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096) \
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0) \
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)

#define EVT_SETUP_CAMERA_NO_LEAD() \
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096) \
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0) \
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE) \
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE)

// same as EVT_SETUP_CAMERA_NO_LEAD with calls reordered
#define EVT_SETUP_CAMERA_ALT_NO_LEAD() \
    EVT_CALL(SetCamPerspective, CAM_DEFAULT, CAM_UPDATE_FROM_ZONE, 25, 16, 4096) \
    EVT_CALL(SetCamBGColor, CAM_DEFAULT, 0, 0, 0) \
    EVT_CALL(SetCamLeadPlayer, CAM_DEFAULT, FALSE) \
    EVT_CALL(SetCamEnabled, CAM_DEFAULT, TRUE)

// allow macros with variable number of arguments
// see https://stackoverflow.com/questions/11761703/overloading-macro-on-number-of-arguments
// solution provided by R1tschY and edited by Gabriel Staples
#define __NARG__(args...) \
    __NARG_I_(args,__RSEQ_N())
#define __NARG_I_(args...) \
    __ARG_N(args)
#define __ARG_N( \
      _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
     _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
     _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
     _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
     _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
     _51,_52,_53,_54,_55,_56,_57,_58,_59,_60, \
     _61,_62,_63,N,...) N
#define __RSEQ_N() \
     63,62,61,60,                   \
     59,58,57,56,55,54,53,52,51,50, \
     49,48,47,46,45,44,43,42,41,40, \
     39,38,37,36,35,34,33,32,31,30, \
     29,28,27,26,25,24,23,22,21,20, \
     19,18,17,16,15,14,13,12,11,10, \
     9,8,7,6,5,4,3,2,1,0
#define _VFUNC_(name, n) name##n
#define _VFUNC(name, n) _VFUNC_(name, n)
#define VFUNC(func, args...) _VFUNC(func, __NARG__(args)) (args)

#define EVT_PLAY_EFFECT(args...) VFUNC(EVT_PLAY_EFFECT, args)
#define EVT_PLAY_EFFECT1(effect) \
    EVT_CALL(PlayEffect, effect, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
#define EVT_PLAY_EFFECT2(effect, subtype) \
    EVT_CALL(PlayEffect, effect, subtype, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
#define EVT_PLAY_EFFECT3(effect, subtype, a) \
    EVT_CALL(PlayEffect, effect, subtype, a, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
#define EVT_PLAY_EFFECT4(effect, subtype, a, b) \
    EVT_CALL(PlayEffect, effect, subtype, a, b, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0)
#define EVT_PLAY_EFFECT5(effect, subtype, a, b, c) \
    EVT_CALL(PlayEffect, effect, subtype, a, b, c, 0, 0, 0, 0, 0, 0, 0, 0, 0)
#define EVT_PLAY_EFFECT6(effect, subtype, a, b, c, d) \
    EVT_CALL(PlayEffect, effect, subtype, a, b, c, d, 0, 0, 0, 0, 0, 0, 0, 0)
#define EVT_PLAY_EFFECT7(effect, subtype, a, b, c, d, e) \
    EVT_CALL(PlayEffect, effect, subtype, a, b, c, d, e, 0, 0, 0, 0, 0, 0, 0)
#define EVT_PLAY_EFFECT8(effect, subtype, a, b, c, d, e, f) \
    EVT_CALL(PlayEffect, effect, subtype, a, b, c, d, e, f, 0, 0, 0, 0, 0, 0)
#define EVT_PLAY_EFFECT9(effect, subtype, a, b, c, d, e, f, g) \
    EVT_CALL(PlayEffect, effect, subtype, a, b, c, d, e, f, g, 0, 0, 0, 0, 0)
#define EVT_PLAY_EFFECT10(effect, subtype, a, b, c, d, e, f, g, h) \
    EVT_CALL(PlayEffect, effect, subtype, a, b, c, d, e, f, g, h, 0, 0, 0, 0)
#define EVT_PLAY_EFFECT11(effect, subtype, a, b, c, d, e, f, g, h, i) \
    EVT_CALL(PlayEffect, effect, subtype, a, b, c, d, e, f, g, h, i, 0, 0, 0)
#define EVT_PLAY_EFFECT12(effect, subtype, a, b, c, d, e, f, g, h, i, j) \
    EVT_CALL(PlayEffect, effect, subtype, a, b, c, d, e, f, g, h, i, j, 0, 0)
#define EVT_PLAY_EFFECT13(effect, subtype, a, b, c, d, e, f, g, h, i, j, k) \
    EVT_CALL(PlayEffect, effect, subtype, a, b, c, d, e, f, g, h, i, j, k, 0)
#define EVT_PLAY_EFFECT14(effect, subtype, a, b, c, d, e, f, g, h, i, j, k, l) \
    EVT_CALL(PlayEffect, effect, subtype, a, b, c, d, e, f, g, h, i, j, k, l)

#endif
