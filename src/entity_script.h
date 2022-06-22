#include "common.h"

typedef s32 EntityScript[0];

enum {
    ENTITY_SCRIPT_OP_End,
    ENTITY_SCRIPT_OP_Jump,
    ENTITY_SCRIPT_OP_Call,
    ENTITY_SCRIPT_OP_SetCallback,
    ENTITY_SCRIPT_OP_Goto,
    ENTITY_SCRIPT_OP_Label,
    ENTITY_SCRIPT_OP_RestartBoundScript,
    ENTITY_SCRIPT_OP_SetFlags,
    ENTITY_SCRIPT_OP_ClearFlags,
    ENTITY_SCRIPT_OP_PlaySound,
};

#define es_End ENTITY_SCRIPT_OP_End,
#define es_Jump(script) ENTITY_SCRIPT_OP_Jump, (s32)script,
#define es_Call(func) ENTITY_SCRIPT_OP_Call, (s32)func,
#define es_SetCallback(func, time) ENTITY_SCRIPT_OP_SetCallback, time, (s32)func,
#define es_Goto(labelId) ENTITY_SCRIPT_OP_Goto, labelId,
#define es_Restart ENTITY_SCRIPT_OP_Goto, 0,
#define es_Label(labelId) ENTITY_SCRIPT_OP_Label, labelId,
#define es_RestartBoundScript ENTITY_SCRIPT_OP_RestartBoundScript,
#define es_SetFlags(flags) ENTITY_SCRIPT_OP_SetFlags, flags,
#define es_ClearFlags(flags) ENTITY_SCRIPT_OP_ClearFlags, flags,
#define es_PlaySound(soundId) ENTITY_SCRIPT_OP_PlaySound, soundId,
