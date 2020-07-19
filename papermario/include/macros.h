#ifndef _MACROS_H_
#define _MACROS_H_

#define INCLUDE_ASM(FOLDER, NAME) \
  void __attribute__((naked)) NAME(void) { __asm__( ".include \"asm/"#FOLDER"/"#NAME".s\"\n"); }

#endif