#ifndef _TYPES_H_
#define _TYPES_H_

#include "ultra64.h"

#define UNK_TYPE s32
#define UNK_PTR void*
#define UNK_RET void
#define UNK_FUN_ARG void(*)(void)
#define UNK_FUN_PTR(name) void(*name)(void)
#define UNK_ARGS

typedef char* (*PrintCallback)(void*, const char*, u32);

/// Linker symbol address, as in `ld_addrs.h`.
typedef u8 Addr[];

#define BTL_NONE 0
#define BTL_DEFAULT_STAGE -1

/// Terminates an extraAnimationList
#define ANIM_LIST_END -1

#endif
