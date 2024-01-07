#ifndef _H_INCLUDE_ASSET

#define INCLUDE_IMG(FILENAME, SYMBOLNAME) \
    extern u8 SYMBOLNAME[]; \
    __asm__( \
        ".globl " #SYMBOLNAME"\n" \
        ".data\n" \
        ".type " #SYMBOLNAME", @object\n" \
        #SYMBOLNAME":\n" \
        ".incbin \"ver/"STRINGIFY(VERSION)"/build/" FILENAME "\"\n" \
    )

#define INCLUDE_PAL(FILENAME, SYMBOLNAME) \
    extern u16 SYMBOLNAME[]; \
    __asm__( \
        ".globl " #SYMBOLNAME"\n" \
        ".data\n" \
        ".type " #SYMBOLNAME", @object\n" \
        #SYMBOLNAME":\n" \
        ".incbin \"ver/"STRINGIFY(VERSION)"/build/" FILENAME "\"\n" \
    )

#endif // _H_INCLUDE_ASSET
