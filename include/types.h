#ifndef _TYPES_H_
#define _TYPES_H_

#include "ultra64.h"

#define UNK_TYPE s32
#define UNK_PTR void*
#define UNK_RET void
#define UNK_FUN_ARG void(*)(void)
#define UNK_FUN_PTR(name) void(*name)(void)
#define UNK_ARGS

typedef s32 BattleID;
#define BATTLE_ID(area, stage, index) ((area << 16) + (stage << 8) + index)

typedef s32 NpcAnimID;
#define NPC_ANIM(sprite, palette, anim) ((_NPC_SPRITE_##sprite << 16) + (_NPC_PALETTE_##sprite##_##palette << 8) + _NPC_ANIM_##sprite##_##anim)

#endif
