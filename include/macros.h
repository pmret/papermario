#ifndef _MACROS_H_
#define _MACROS_H_

#ifndef SPLAT
#define INCLUDE_ASM(TYPE, FOLDER, NAME, ARGS...) \
  TYPE __attribute__((naked)) NAME(ARGS) { __asm__( ".include \"include/macro.inc\"\n.include \"asm/nonmatchings/"FOLDER"/"#NAME".s\"\n.set reorder\n.set at"); }
#else
#define INCLUDE_ASM(TYPE, FOLDER, NAME, ARGS...)
#endif

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))
#define ARRAY_COUNTU(arr) (u32)(sizeof(arr) / sizeof(arr[0]))

#define ASSERT(condition) if (!(condition)) { while (1) {} }
#define PANIC() ASSERT(0)

#define GAME_STATUS (*gGameStatusPtr)

#define SQ(x) (x*x)

#endif
