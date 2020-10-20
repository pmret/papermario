#ifndef _TYPES_H_
#define _TYPES_H_

#include "ultra64.h"

#define UNK_TYPE s32
#define UNK_PTR void*
#define UNK_RET void
#define UNK_FUN_ARG void(*)(void)
#define UNK_FUN_PTR(name) void(*name)(void)
#define UNK_ARGS

typedef s32 FormationID;
#define FORMATION_ID(section, stage, index) (section << 16) + (stage << 8) + index

#endif
