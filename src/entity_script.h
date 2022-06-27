#include "common.h"

typedef s32 EntityScript[0];
typedef s32 EntityModelScript[0];

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

enum {
    ENTITY_MODEL_SCRIPT_OP_End,
    ENTITY_MODEL_SCRIPT_OP_Draw,
    ENTITY_MODEL_SCRIPT_OP_Restart,
    ENTITY_MODEL_SCRIPT_OP_Loop,
    ENTITY_MODEL_SCRIPT_OP_SetRenderMode,
    ENTITY_MODEL_SCRIPT_OP_SetFlags,
    ENTITY_MODEL_SCRIPT_OP_ClearFlags,
    ENTITY_MODEL_SCRIPT_OP_DrawImage,
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

#define ems_End ENTITY_MODEL_SCRIPT_OP_End,
#define ems_Draw(dlist, holdTime) ENTITY_MODEL_SCRIPT_OP_Draw, holdTime, (s32)dlist,
#define ems_Restart ENTITY_MODEL_SCRIPT_OP_Restart,
#define ems_Loop ENTITY_MODEL_SCRIPT_OP_Loop,
#define ems_SetRenderMode(mode) ENTITY_MODEL_SCRIPT_OP_SetRenderMode, mode,
#define ems_SetFlags(flags) ENTITY_MODEL_SCRIPT_OP_SetFlags, flags,
#define ems_ClearFlags(flags) ENTITY_MODEL_SCRIPT_OP_ClearFlags, flags,
#define ems_DrawImage(raster, palette, width, height, holdTime) ENTITY_MODEL_SCRIPT_OP_DrawImage, holdTime, (s32)raster, (s32)palette, width, height,

#define STANDARD_ENTITY_MODEL_SCRIPT(gfx, renderMode) \
    { \
        ems_SetRenderMode(renderMode) \
        ems_Draw(gfx, 60) \
        ems_Restart \
        ems_End \
    }
