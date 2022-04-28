#ifndef _DEAD_STRUCTS_H_
#define _DEAD_STRUCTS_H_

#include "common_structs.h"
#include "enums.h"
#include "script_api/map.h"

typedef struct DeadEnemy {
    /* 0x000 */ s32 flags;
    /* 0x004 */ s8 encounterIndex;
    /* 0x005 */ s8 encountered;
    /* 0x006 */ u8 scriptGroup; /* scripts launched for this npc controller will be assigned this group */
    /* 0x007 */ s8 unk_07;
    /* 0x008 */ s16 npcID;
    /* 0x00A */ s16 spawnPos[3];
    /* 0x010 */ Vec3s unk_10;
    /* 0x016 */ char unk_16[2];
    /* 0x018 */ struct NpcSettings* npcSettings;
    /* 0x01C */ EvtScript* initBytecode;
    /* 0x020 */ EvtScript* interactBytecode;
    /* 0x024 */ EvtScript* aiBytecode;
    /* 0x028 */ EvtScript* hitBytecode;
    /* 0x02C */ EvtScript* auxBytecode;
    /* 0x030 */ EvtScript* defeatBytecode;
    /* 0x034 */ struct Evt* initScript;
    /* 0x038 */ struct Evt* interactScript;
    /* 0x03C */ struct Evt* aiScript;
    /* 0x040 */ struct Evt* hitScript;
    /* 0x044 */ struct Evt* auxScript;
    /* 0x048 */ struct Evt* defeatScript;
    /* 0x04C */ s32 initScriptID;
    /* 0x050 */ s32 interactScriptID;
    /* 0x054 */ s32 aiScriptID;
    /* 0x058 */ s32 hitScriptID;
    /* 0x05C */ s32 auxScriptID;
    /* 0x060 */ s32 defeatScriptID;
    /* 0x064 */ void* unk_64;
    /* 0x068 */ char unk_68[4];
    /* 0x06C */ s32 varTable[16];
    /* 0x0AC */ char unk_AC[4];
    /* 0x0B0 */ s32 aiFlags;
    /* 0x0B4 */ s8 aiPaused;
    /* 0x0B5 */ s8 unk_B5;
    /* 0x0B6 */ char unk_B6[2];
    /* 0x0B8 */ EvtScript* unk_B8; // some bytecode
    /* 0x0BC */ struct Evt* unk_BC; // some script
    /* 0x0C0 */ s32 unk_C0; // some script ID
    /* 0x0C4 */ s32 unk_C4;
    /* 0x0C8 */ s32 unk_C8;
    /* 0x0CC */ s32* animList;
    /* 0x0D0 */ EnemyTerritory* territory;
    /* 0x0D4 */ EnemyDrops* drops;
    /* 0x0D8 */ u32 tattleMsg;
    /* 0x0DC */ char unk_DC[42];
    /* 0x108 */ Vec3f unk_108; // Associated NPC Pos?
    /* 0x114 */ f32 unk_114;
    /* 0x118 */ f32 unk_118;
} DeadEnemy; // size = 0x11C

#endif
