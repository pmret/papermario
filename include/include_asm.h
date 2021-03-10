#ifndef __INCLUDE_ASM_H__
#define __INCLUDE_ASM_H__

#define STRINGIFY_(x) #x
#define STRINGIFY(x) STRINGIFY_(x)

#if !defined(SPLAT) && !defined(__CTX__) && !defined(PERMUTER)
#ifndef INCLUDE_ASM
#define INCLUDE_ASM(TYPE, FOLDER, NAME, ARGS...) \
   TYPE NAME(ARGS); \
  TYPE __attribute__((naked)) NAME(ARGS) { __asm__( ".include \"ver/"STRINGIFY(VERSION)"/asm/nonmatchings/"FOLDER"/"#NAME".s\"\n.set reorder\n.set at"); }
#endif
__asm__( ".include \"include/macro.inc\"\n");
#else
#define INCLUDE_ASM(TYPE, FOLDER, NAME, ARGS...)
#endif


#endif
