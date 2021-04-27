#ifndef __INCLUDE_ASM_H__
#define __INCLUDE_ASM_H__

#define STRINGIFY_(x) #x
#define STRINGIFY(x) STRINGIFY_(x)

#if !defined(SPLAT) && !defined(__CTX__) && !defined(PERMUTER)
#ifndef INCLUDE_ASM
#define INCLUDE_ASM(TYPE, FOLDER, NAME, ARGS...) \
   TYPE NAME(ARGS); \
   __asm__( \
        ".section .text\n" \
        "\t.align\t2\n" \
        "\t.globl\t"#NAME"\n" \
        "\t.ent\t"#NAME"\n" \
        #NAME ":\n" \
        "\t.include \"ver/"STRINGIFY(VERSION)"/asm/nonmatchings/"FOLDER"/"#NAME".s\"\n" \
        "\t.set reorder\n" \
        "\t.set at\n" \
        "\t.end\t"#NAME \
    );
#endif
__asm__(".include \"include/macro.inc\"\n");
#ifdef MOVE_ADDU
__asm__(".include \"include/move_addu.inc\"\n");
#endif
#else
#define INCLUDE_ASM(TYPE, FOLDER, NAME, ARGS...)
#endif


#endif
