#ifndef _MACROS_H_
#define _MACROS_H_

#define INCLUDE_ASM(FOLDER, NAME, ARGS...) \
  __attribute__((naked)) NAME(ARGS) { __asm__( ".include \"include/macro.inc\"\n.include \"asm/nonmatchings/"#FOLDER"/"#NAME".s\"\n.set reorder\n.set at"); }

#define ARRAY_COUNT(arr) (s32)(sizeof(arr) / sizeof(arr[0]))
#define ARRAY_COUNTU(arr) (u32)(sizeof(arr) / sizeof(arr[0]))

#define ASSERT(condition) if (!(condition)) { while (1) {} }

#endif
