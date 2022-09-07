#ifndef _TYPES_H_
#define _TYPES_H_

#include "ultra64.h"

#define UNK_TYPE s32
#define UNK_PTR void*
#define UNK_RET void
#define UNK_FUN_ARG void(*)(void)
#define UNK_FUN_PTR(name) void(*name)(void)
#define UNK_ARGS

typedef void (*StateFunc)(void);

typedef char* (*PrintCallback)(void*, const char*, u32);

/// Linker symbol address, as in `ld_addrs.h`.
typedef u8 Addr[];

#define BATTLE_ID(unk, area, stage, index) ((unk << 24) + (area << 16) + (stage << 8) + index)

#define PACK_BATTLE(battle, stage) ((battle) << 16 | ((stage) + 1))
#define NO_BATTLE 0

/// Terminates an extraAnimationList
#define ANIM_END -1

#endif
