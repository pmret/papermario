#ifndef ENTITY_H
#define ENTITY_H

#include "common.h"

typedef s32 EntityScript[];
typedef s32 EntityModelScript[];

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

#define BLOCK_GRID_SIZE 25

#define TWEESTER_PATH_STOP 0x80000000
#define TWEESTER_PATH_LOOP 0x80000001

typedef struct SaveBlockData {
    /* 0x000 */ char unk_0[4];
    /* 0x004 */ s16 angle;
    /* 0x006 */ char unk_6[0x1A];
} SaveBlockData; // size = 0x20

typedef struct SwitchData {
    /* 0x000 */ f32 fallVel;
    /* 0x004 */ f32 deltaScaleX;
    /* 0x008 */ f32 deltaScaleY;
    /* 0x00C */ char unk_0C[4];
    /* 0x010 */ s8 animStateScaleX;
    /* 0x011 */ s8 animStateScaleY;
    /* 0x014 */ Vec3f baseScale;
    /* 0x020 */ u16 areaFlagIndex;
    /* 0x022 */ s16 greenMotionTimer;
    /* 0x024 */ s16 scaleAnimTimer;
    /* 0x028 */ struct Entity* linkedSwitch;
} SwitchData; // size = 0x2C

typedef struct ShatteringBlockData {
    /* 0x000 */ u16 fragmentFlags[25];
    /* 0x034 */ Gfx** fragmentDisplayLists;
    /* 0x038 */ f32 originalPosY;
    /* 0x03C */ s16 alpha;
    /* 0x03E */ s16 fadeOutCounter;
    /* 0x040 */ s8 fragmentRebounds[25];
    /* 0x059 */ s8 fragmentRotSpeed[25];
    /* 0x072 */ u8 fragmentMoveAngle[25]; // scaled to map [0,255] -> [0,360]
    /* 0x08B */ u8 fragmentRotX[25]; // scaled to map [0,255] -> [0,360]
    /* 0x0A4 */ u8 fragmentRotY[25]; // scaled to map [0,255] -> [0,360]
    /* 0x0C0 */ f32 fragmentPosX[25];
    /* 0x124 */ f32 fragmentPosY[25];
    /* 0x188 */ f32 fragmentPosZ[25];
    /* 0x1EC */ f32 fragmentFallSpeed[25];
} ShatteringBlockData; // size = 0x250

typedef struct BlockData {
    /* 0x000 */ u8 parentEntityIndex; // for block entities spawned by other block entities
    /* 0x001 */ char unk_01[2];
    /* 0x003 */ s8 empty;
    /* 0x004 */ s16 coinsLeft;
    /* 0x006 */ s16 timeLeft;
    /* 0x008 */ char unk_08[2];
    /* 0x00A */ u16 gameFlagIndex;
    /* 0x00C */ char unk_0C[2];
    /* 0x00E */ s16 sinkingTimer;
    /* 0x010 */ s16 item; // for spawned item entities
    /* 0x012 */ s16 childEntityIndex; // for block entities that spawn other block entities
    /* 0x014 */ f32 initialY;
    /* 0x018 */ f32 recoilInterpPhase;
    /* 0x01C */ char unk_1C[0x4];
} BlockData; // size = 0x20

typedef struct SuperBlockContentData {
    /* 0x000 */ u8 parentEntityIndex; // for block entities spawned by other block entities
    /* 0x001 */ u8 unk_01;
    /* 0x002 */ s8 effectTimer;
    /* 0x003 */ s8 unk_03;
    /* 0x004 */ f32 unk_04;
    /* 0x008 */ u8 paletteTimer;
    /* 0x009 */ u8 paletteArrOffset;
    /* 0x00A */ u8 isHidden;
    /* 0x00B */ char unk_0B; // padding?
    /* 0x00C */ s32 unk_0C;
    /* 0x010 */ Mtx unk_10;
    /* 0x050 */ Mtx unk_50;
    /* 0x090 */ Mtx unk_90;
    /* 0x0D0 */ u16 yawBufferPos;
    /* 0x0D4 */ f32 yawBuffer[20];
    /* 0x124 */ s32 unk_124;
    /* 0x128 */ Gfx* gfx1;
    /* 0x12C */ Gfx* gfx2;
} SuperBlockContentData; // size = 0x130

// size unknown
typedef struct HeartBlockContentData {
    /* 0x000 */ u8 parentEntityIndex; // for block entities spawned by other block entities
    /* 0x001 */ u8 state;
    /* 0x002 */ s8 sparkleTimer;
    /* 0x003 */ s8 sparkleTrailTimer;
    /* 0x004 */ f32 sparkleTrailPosY;
    /* 0x008 */ u8 heartbeatTimer;
    /* 0x009 */ u8 unk_09;
    /* 0x00A */ u8 sparkleEffectType;
    /* 0x00B */ char unk_0B; // padding?
    /* 0x00C */ s32 unk_0C;
    /* 0x010 */ s32 unk_10;
    /* 0x014 */ f32 riseVel;
    /* 0x018 */ f32 sparkleTrailAngle;
    /* 0x01C */ f32 sparkleTrailRadius;
    /* 0x020 */ f32 bouncePhase;
    /* 0x024 */ u16 yawBufferPos;
    /* 0x026 */ s16 unk_26;
    /* 0x028 */ f32 yawBuffer[10];
    /* 0x050 */ f32 unk_50;
    /* 0x054 */ f32 rotRate;
    /* 0x058 */ Mtx unk_58;
    /* 0x098 */ Mtx unk_98;
} HeartBlockContentData; // size = 0xD8

typedef struct WoodenCrateData {
    /* 0x000 */ s32 itemID;
    /* 0x004 */ u16 globalFlagIndex;
    /* 0x006 */ u8 unk_06[2];
    /* 0x008 */ Gfx** fragmentsGfx;
    /* 0x00C */ f32 basePosY;
    /* 0x010 */ s8 fragmentRebounds[36];
    /* 0x034 */ u8 fragmentMoveAngle[36]; // X,Z plane -- scaled to map [0,255] -> [0,360], also used as fragment alpha
    /* 0x058 */ u8 fragmentRotX[36]; // scaled to map [0,255] -> [0,360]
    /* 0x07C */ u8 fragmentRotY[36]; // scaled to map [0,255] -> [0,360]
    /* 0x0A0 */ u8 fragmentLateralSpeed[36]; // scaled to map [0,255] -> [0,25.5]
    /* 0x0C4 */ f32 fragmentRotSpeed[36];
    /* 0x154 */ f32 fragmentPosX[36];
    /* 0x1E4 */ f32 fragmentPosY[36];
    /* 0x274 */ f32 fragmentPosZ[36];
    /* 0x304 */ f32 fragmentFallSpeed[36];
} WoodenCrateData; // size = 0x394

// size unknown
typedef struct ChestData {
    /* 0x00 */ u16 gameFlagIndex;
    /* 0x02 */ s16 giveItemTimer;
    /* 0x04 */ u8 state;
    /* 0x05 */ u8 openState;
    /* 0x06 */ s8 postLidAnimDelay;
    /* 0x07 */ s8 unk_07;
    /* 0x08 */ f32 lidAngle;
    /* 0x0C */ f32 lidAnimInterpPhase;
    /* 0x10 */ s32 itemID;
    /* 0x14 */ s32 itemEntityIndex;
    /* 0x18 */ Vec3f itemEntityPos;
    /* 0x24 */ f32 giveItemRadiusInterpPhase;
    /* 0x28 */ f32 giveItemHeightInterpPhase;
    /* 0x2C */ f32 itemVelY;
    /* 0x30 */ s8 gotItemDone;
    /* 0x31 */ char unk_31[3];
    /* 0x34 */ struct EffectInstance* gotItemEffect;
} ChestData; // size = 0x38

typedef struct BlueWarpPipeData {
    /* 0x00 */ s32 unk_00; // proably flags
    /* 0x04 */ s32 timer;
    /* 0x08 */ s32 isRaised;
    /* 0x0C */ s32 entryID;
    /* 0x10 */ EvtScript* onEnterPipeEvt;
    /* 0x14 */ s32 flagIndex;
    /* 0x18 */ f32 finalPosY;
} BlueWarpPipeData; // size = 0x1C

typedef struct SimpleSpringData {
    /* 0x00 */ s32 launchVel;
} SimpleSpringData; // size = 0x04

typedef struct HiddenPanelData {
    /* 0x00 */ s8 state; // TODO: enum
    /* 0x01 */ s8 timer;
    /* 0x02 */ s8 unk_02;
    /* 0x03 */ s8 needSpawnItem;
    /* 0x04 */ s8 unk_04;
    /* 0x05 */ s8 unk_05;
    /* 0x06 */ u16 pickupVar;
    /* 0x08 */ s32 standingNpcIndex;
    /* 0x0C */ s32 npcFlags;
    /* 0x10 */ s32 itemID;
    /* 0x14 */ s32 spawnedItemIndex;
    /* 0x18 */ Vec3i spawnedItemPos;
    /* 0x24 */ f32 initialY;
    /* 0x28 */ f32 riseVel;
    /* 0x2C */ f32 riseInterpPhase;
    /* 0x30 */ f32 rotSpeed;
    /* 0x34 */ Matrix4f entityMatrix;
    /* 0x74 */ u16 modelID;
    /* 0x76 */ char unk_76[0x2];
    /* 0x78 */ Gfx* renderDList;
}   HiddenPanelData; // size = 0x7C

typedef struct SignpostData {
    /* 0x00 */ char unk_00[8];
} SignpostData; // size = 0x08

typedef struct PadlockData {
    /* 0x00 */ f32 pushSpeed;
    /* 0x04 */ f32 shacklePos;
    /* 0x08 */ f32 fallSpeed;
    /* 0x0C */ f32 rotSpeed;
    /* 0x10 */ u8 blinkCounter;
    /* 0x11 */ s8 timer;
    /* 0x12 */ s8 state;
    /* 0x13 */ char unk_13;
    /* 0x14 */ Mtx* shackleMtx;
    /* 0x18 */ Gfx* shackleGfx;
} PadlockData; // size = 0x1C

typedef struct BoardedFloorData {
    /* 0x000 */ Gfx** fragmentsGfx;
    /* 0x004 */ f32 inititalY;
    /* 0x008 */ s8 fragmentRebounds[13];
    /* 0x015 */ u8 fragmentMoveAngle[13];
    /* 0x022 */ u8 fragmentRotX[13];
    /* 0x02F */ u8 fragmentRotY[13];
    /* 0x03C */ u8 fragmentLateralSpeed[13];
    /* 0x04C */ f32 fragmentRotSpeed[13];
    /* 0x080 */ f32 fragmentPosX[13];
    /* 0x0B4 */ f32 fragmentPosY[13];
    /* 0x0E8 */ f32 fragmentPosZ[13];
    /* 0x11C */ f32 fragmentFallSpeed[13];
} BoardedFloorData; // size = 0x150

typedef struct BombableRockData {
    /* 0x00 */ Gfx** fragmentsGfx;
    /* 0x04 */ f32 inititalY;
    /* 0x08 */ s8 fragmentRebounds[6];
    /* 0x0E */ u8 fragmentMoveAngle[6];
    /* 0x14 */ u8 fragmentRotX[6];
    /* 0x1A */ u8 fragmentRotY[6];
    /* 0x20 */ u8 fragmentLateralSpeed[6];
    /* 0x28 */ f32 fragmentRotSpeed[6];
    /* 0x40 */ f32 fragmentPosX[6];
    /* 0x58 */ f32 fragmentPosY[6];
    /* 0x70 */ f32 fragmentPosZ[6];
    /* 0x88 */ f32 fragmentFallSpeed[6];
} BombableRockData; // size = 0xA0

typedef s32 TweesterPath[];

typedef struct TweesterData {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ s8 faceAnimState;
    /* 0x02 */ s8 faceAnimTimer;
    /* 0x03 */ s8 faceAnimTexOffset;
    /* 0x04 */ f32 rotSpeed;
    /* 0x08 */ f32 innerWhirlRotY;
    /* 0x0C */ f32 outerWhirlRotY;
    /* 0x10 */ Mtx mtxInnerWhirl;
    /* 0x50 */ Mtx mtxOuterWhirl;
    /* 0x90 */ s16 innerWhirlTexOffsetX;
    /* 0x92 */ s16 innerWhirlTexOffsetY;
    /* 0x94 */ s16 outerWhirlTexOffsetX;
    /* 0x96 */ s16 outerWhirlTexOffsetY;
    /* 0x98 */ s16 frameCounter;
    /* 0x9C */ s32* curPath;
    /* 0xA0 */ s32** paths;
    /* 0xA4 */ s16 targetX;
    /* 0xA6 */ s16 targetY;
    /* 0xA8 */ s16 targetZ;
    /* 0xAA */ s16 pathOffset;
    /* 0xAC */ char unk_AC[12];
    /* 0xB8 */ f32 yaw;
    /* 0xBC */ char unk_BC[4];
} TweesterData; // size = 0xC0;

typedef struct StarBoxLauncherData {
    /* 0x00 */ s8 state;
    /* 0x01 */ s8 timer;
    /* 0x02 */ s8 flags;
    /* 0x03 */ s8 faceDataIndex;
    /* 0x04 */ s8 faceAnimTimer;
    /* 0x05 */ s8 faceTexOffset;
    /* 0x08 */ f32 basePosX;
    /* 0x0C */ f32 basePosZ;
    /* 0x10 */ f32 basePosY;
    /* 0x14 */ f32 riseSpeedPhase;
    /* 0x18 */ f32 riseVel;
    /* 0x1C */ f32 rotZPhase;
    /* 0x20 */ f32 maxRotZ;
} StarBoxLauncherData; // size = 0x24

typedef struct CymbalPlantData {
    /* 0x0 */ u8 state;
    /* 0x1 */ s8 unk_01;
    /* 0x2 */ s16 timer;
    /* 0x4 */ f32 angle;
    /* 0x8 */ f32 dist;
} CymbalPlantData; // size = 0xC

typedef struct PinkFlowerData {
    /* 0x0 */ u16 state;
    /* 0x2 */ u16 timer;
    /* 0x4 */ u16 linkedEntityIndex;
    /* 0x8 */ f32 initialRotY;
} PinkFlowerData; // size = 0xC

typedef struct SpinningFlowerData {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s8 state;
    /* 0x04 */ Vec3f rot;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ f32 spinSpeed;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ char unk_1C[0x0C];
    /* 0x28 */ s16 unk_28;
    /* 0x2A */ s16 unk_2A;
    /* 0x2C */ s16 unk_2C;
    /* 0x30 */ Mtx unk_30;
} SpinningFlowerData; // size = 0x70

typedef struct TrumpetPlantData {
    /* 0x0 */ s32 numCoins;
} TrumpetPlantData; // size = 0x4

typedef struct MunchlesiaData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s8 unk_04[0x8];
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
} MunchlesiaData; // size = 0x1C

typedef struct ArrowSignData {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 angle;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
} ArrowSignData; // size = 0x10

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
extern EntityBlueprint Entity_Hammer1Block_WideX;
extern EntityBlueprint Entity_Hammer1Block_WideZ;
extern EntityBlueprint Entity_Hammer1BlockTiny;
extern EntityBlueprint Entity_Hammer2Block;
extern EntityBlueprint Entity_Hammer2Block_WideX;
extern EntityBlueprint Entity_Hammer2Block_WideZ;
extern EntityBlueprint Entity_Hammer2BlockTiny;
extern EntityBlueprint Entity_Hammer3Block;
extern EntityBlueprint Entity_Hammer3Block_WideX;
extern EntityBlueprint Entity_Hammer3Block_WideZ;
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

typedef struct EntityModel {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s8 renderMode;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ f32 nextFrameTime; ///< Set to 1.0 after each update
    /* 0x0C */ f32 timeScale; ///< Default is 1.0
    /* 0x10 */ EntityModelScript* cmdListReadPos;
    /* 0x14 */ union {
                    Gfx* displayList;
                    SpriteRasterInfo* imageData;
               } gfx;
    /* 0x18 */ Mtx transform;
    /* 0x58 */ EntityModelScript* cmdListSavedPos;
    /* 0x5C */ Vec3s* vertexArray;
    /* 0x60 */ void (*fpSetupGfxCallback)(void*);
    /* 0x64 */ void* setupGfxCallbackArg0;
} EntityModel; // size = 0x68

typedef EntityModel* EntityModelList[MAX_ENTITY_MODELS];

EntityModel* get_entity_model(s32 idx);
s32 load_entity_model(EntityModelScript* cmdList);
s32 ALT_load_entity_model(EntityModelScript* cmdList);
void entity_set_render_script(Entity* entity, EntityModelScript* cmdList);
void set_entity_model_render_command_list(s32 idx, EntityModelScript* cmdList);

void virtual_entity_list_render_world(void);
void virtual_entity_list_render_UI(void);

#endif
