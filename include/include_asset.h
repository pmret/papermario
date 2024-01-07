#ifndef _H_INCLUDE_ASSET

#define ASTRINGIFY_(x) #x
#define ASTRINGIFY(x) ASTRINGIFY_(x)

#define _INCLUDE_IMG(FILENAME, SYMBOLNAME) \
    extern unsigned char SYMBOLNAME[]; \
    __asm__( \
        ".globl " #SYMBOLNAME"\n" \
        ".data\n" \
        ".align 2\n" \
        ".type " #SYMBOLNAME", @object\n" \
        #SYMBOLNAME":\n" \
        ".incbin \"ver/"ASTRINGIFY(VERSION)"/build/" FILENAME ".bin\"\n" \
    )

// two macros are needed for N() usage
#define INCLUDE_IMG(FILENAME, SYMBOLNAME) \
    _INCLUDE_IMG(FILENAME, SYMBOLNAME)

#define INCLUDE_PAL(FILENAME, SYMBOLNAME) \
    extern unsigned short SYMBOLNAME[]; \
    __asm__( \
        ".globl " #SYMBOLNAME"\n" \
        ".data\n" \
        ".align 2\n" \
        ".type " #SYMBOLNAME", @object\n" \
        #SYMBOLNAME":\n" \
        ".incbin \"ver/"ASTRINGIFY(VERSION)"/build/" FILENAME ".bin\"\n" \
    )

#endif // _H_INCLUDE_ASSET
