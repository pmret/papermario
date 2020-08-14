#ifndef _TYPES_H_
#define _TYPES_H_

#define UNK_TYPE s32
#define UNK_PTR void*
#define UNK_RET void
#define UNK_FUN_ARG void(*)(void)
#define UNK_FUN_PTR(name) void(*name)(void)
#define UNK_ARGS

typedef s32 bytecode[];

typedef struct {
    /* 0x00 */ u32 raster;  // swap these?
    /* 0x04 */ u32 palette; // ^
    /* 0x08 */ u16 startX;
    /* 0x0A */ u16 startY;
    /* 0x0C */ u16 width;
    /* 0x0E */ u16 height;
} bg_header; // size = 0x10

#endif