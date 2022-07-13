#ifndef ENTITY_H
#define ENTITY_H

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

#define ENTITY_ADDR(entity, type, data) (type)((s32)(entity->gfxBaseAddr) + ((s32)(data) & 0xFFFF))
#define ENTITY_ROM(name) { entity_model_##name##_ROM_START, entity_model_##name##_ROM_END }

extern ShadowBlueprint CircularShadowA;
extern ShadowBlueprint CircularShadowB;
extern ShadowBlueprint SquareShadow;
extern EntityBlueprint Entity_SavePoint;
extern EntityBlueprint Entity_RedSwitch;
extern EntityBlueprint Entity_BlueSwitch;
extern EntityBlueprint Entity_HugeBlueSwitch;
extern EntityBlueprint Entity_GreenStompSwitch;
extern EntityBlueprint Entity_InertYellowBlock;
extern EntityBlueprint Entity_InertRedBlock;
extern EntityBlueprint Entity_BrickBlock;
extern EntityBlueprint Entity_MulticoinBlock;
extern EntityBlueprint Entity_Hammer1Block;
extern EntityBlueprint Entity_Hammer1Block_WideHitbox;
extern EntityBlueprint Entity_Hammer1Block_TallHitbox;
extern EntityBlueprint Entity_Hammer1BlockTiny;
extern EntityBlueprint Entity_Hammer2Block;
extern EntityBlueprint Entity_Hammer2Block_WideHitbox;
extern EntityBlueprint Entity_Hammer2Block_TallHitbox;
extern EntityBlueprint Entity_Hammer2BlockTiny;
extern EntityBlueprint Entity_Hammer3Block_WideHitbox;
extern EntityBlueprint Entity_Hammer3Block_TallHitbox;
extern EntityBlueprint Entity_Hammer3BlockTiny;
extern EntityBlueprint Entity_PushBlock;
extern EntityBlueprint Entity_PowBlock;
extern EntityBlueprint Entity_YellowBlock;
extern EntityBlueprint Entity_HiddenYellowBlock;
extern EntityBlueprint Entity_RedBlock;
extern EntityBlueprint Entity_HiddenRedBlock;
extern EntityBlueprint Entity_TriggerBlock;
extern EntityBlueprint Entity_HeartBlock;
extern EntityBlueprint Entity_SuperBlock;
extern EntityBlueprint Entity_ScriptSpring;
extern EntityBlueprint Entity_SimpleSpring;
extern EntityBlueprint Entity_HiddenPanel;
extern EntityBlueprint Entity_GiantChest;
extern EntityBlueprint Entity_Chest;
extern EntityBlueprint Entity_WoodenCrate;
extern EntityBlueprint Entity_BlueWarpPipe;
extern EntityBlueprint Entity_Signpost;
extern EntityBlueprint Entity_Padlock;
extern EntityBlueprint Entity_PadlockRedFrame;
extern EntityBlueprint Entity_PadlockRedFace;
extern EntityBlueprint Entity_PadlockBlueFace;
extern EntityBlueprint Entity_BoardedFloor;
extern EntityBlueprint Entity_BombableRock;
extern EntityBlueprint Entity_BombableRock2;
extern EntityBlueprint Entity_Tweester;
extern EntityBlueprint Entity_StarBoxLauncher;
extern EntityBlueprint Entity_CymbalPlant;
extern EntityBlueprint Entity_PinkFlower;
extern EntityBlueprint Entity_SpinningFlower;
extern EntityBlueprint Entity_BellbellPlant;
extern EntityBlueprint Entity_TrumpetPlant;
extern EntityBlueprint Entity_Munchlesia;
extern EntityBlueprint Entity_ArrowSign;

#endif
