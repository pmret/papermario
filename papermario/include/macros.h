#ifndef _MACROS_H_
#define _MACROS_H_

#define INCLUDE_ASM(FOLDER, NAME, ARGS...) \
  __attribute__((naked)) NAME(ARGS) { __asm__( ".include \"asm/nonmatchings/"#FOLDER"/"#NAME".s\"\n.set reorder"); }

#endif