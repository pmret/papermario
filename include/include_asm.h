#ifndef __INCLUDE_ASM_H__
#define __INCLUDE_ASM_H__

#define STRINGIFY_(x) #x
#define STRINGIFY(x) STRINGIFY_(x)

#if !defined(SPLAT) && !defined(__CTX__)
#ifndef INCLUDE_ASM
#define INCLUDE_ASM(TYPE, FOLDER, NAME, ARGS...) \
   TYPE NAME(ARGS); \
  TYPE __attribute__((naked)) NAME(ARGS) { __asm__( ".include \"ver/"STRINGIFY(VERSION)"/asm/nonmatchings/"FOLDER"/"#NAME".s\"\n.set reorder\n.set at"); }
#endif
#ifndef PERMUTER
__asm__( ".include \"include/macro.inc\"\n");
#else
void __attribute__((naked)) dummy_permuter_func(void) { __asm__( ".include \"include/macro.inc\"\n"); }
#endif
#else
#define INCLUDE_ASM(TYPE, FOLDER, NAME, ARGS...)
#endif


#endif
