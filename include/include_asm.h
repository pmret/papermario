#ifndef __INCLUDE_ASM_H__
#define __INCLUDE_ASM_H__

#define STRINGIFY_(x) #x
#define STRINGIFY(x) STRINGIFY_(x)

#if !defined(SPLAT) && !defined(__CTX__) && !defined(PERMUTER)
#ifndef INCLUDE_ASM
#define INCLUDE_ASM_INTERNAL(TYPE, BASE_FOLDER, FOLDER, NAME, ARGS...) \
   __asm__( \
        ".section .text\n" \
        "\t.align\t2\n" \
        "\t.globl\t"#NAME"\n" \
        "\t.ent\t"#NAME"\n" \
        #NAME ":\n" \
        "\t.include \"ver/"STRINGIFY(VERSION)"/asm/"BASE_FOLDER"/"FOLDER"/"#NAME".s\"\n" \
        "\t.set reorder\n" \
        "\t.set at\n" \
        "\t.end\t"#NAME \
    );
#define INCLUDE_ASM(TYPE, FOLDER, NAME, ARGS...) INCLUDE_ASM_INTERNAL(TYPE, "nonmatchings", FOLDER, NAME, ARGS)
#define INCLUDE_ASM_SHIFT(TYPE, FOLDER, NAME, ARGS...) INCLUDE_ASM_INTERNAL(TYPE, "shiftable", FOLDER, NAME, ARGS)
#endif
__asm__(".include \"include/macro.inc\"\n");
#else
#define INCLUDE_ASM(TYPE, FOLDER, NAME, ARGS...)
#endif


#endif
