#ifndef _COMMON_STRUCTS_H_
#define _COMMON_STRUCTS_H_

#include "macros.h"
#include "ultra64.h"
#include "types.h"
#include "evt.h"
#include "enums.h"

struct Evt;

typedef ApiStatus(*ApiFunc)(struct Evt*, s32);

typedef Bytecode EvtSource[0];

typedef struct {
    u8 r, g, b, a;
} Color_RGBA8;

typedef struct {
    u8 r, g, b;
} Color_RGB8;

typedef struct Vec2b {
    /* 0x00 */ s8 x;
    /* 0x01 */ s8 y;
} Vec2b; // size = 0x02

typedef struct Vec2bu {
    /* 0x00 */ u8 x;
    /* 0x01 */ u8 y;
} Vec2bu; // size = 0x02

typedef struct Vec2f {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
} Vec2f; // size = 0x08

typedef struct Vec3b {
    /* 0x00 */ s8 x;
    /* 0x01 */ s8 y;
    /* 0x02 */ s8 z;
} Vec3b; // size = 0x03

typedef struct Vec3f {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
} Vec3f; // size = 0x0C

typedef struct Vec3i {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 z;
} Vec3i; // size = 0x0C

typedef struct Vec2s {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
} Vec2s; // size = 0x04

typedef struct Vec2su {
    /* 0x00 */ u16 x;
    /* 0x02 */ u16 y;
} Vec2su; // size = 0x04

typedef struct Vec3s {
    /* 0x00 */ s16 x;
    /* 0x02 */ s16 y;
    /* 0x04 */ s16 z;
} Vec3s; // size = 0x06

typedef struct Vec4f {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 yaw;
} Vec4f; // size = 0x10

typedef f32 Matrix4f[4][4]; // size = 0x40

typedef struct Matrix4s {
    /* 0x00 */ s16 whole[4][4];
    /* 0x20 */ s16 frac[4][4];
} Matrix4s; // size = 0x40

typedef struct CamPosSettings {
    /* 0x00 */ f32 boomYaw;
    /* 0x04 */ f32 boomLength;
    /* 0x08 */ f32 boomPitch;
    /* 0x0C */ f32 viewPitch;
    /* 0x10 */ Vec3f position;
} CamPosSettings; // size = 0x1C

typedef struct DmaTable {
    /* 0x00 */ s32 dmaStart;
    /* 0x04 */ s32 dmaEnd;
    /* 0x08 */ s32 dmaDest;
} DmaTable;

typedef struct PartnerData {
    /* 0x00 */ u8 enabled;
    /* 0x01 */ s8 level;
    /* 0x02 */ s16 unk_02[3];
} PartnerData; // size = 0x08

typedef struct HeapNode {
    /* 0x00 */ struct HeapNode* next;
    /* 0x04 */ s32 length;
    /* 0x08 */ u16 allocated;
    /* 0x0A */ s16 entryID;
    /* 0x0C */ s32 capacity;
} HeapNode; // size = 0x10

/// Ring buffer of an NPC's position over the past 20 frames.
typedef struct BlurBuffer {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ s8 index; ///< Current blur ring buffer index
    /* 0x02 */ char unk_02[2]; // padding?
    /* 0x04 */ f32 x[20];
    /* 0x54 */ f32 y[20];
    /* 0xA4 */ f32 z[20];
} BlurBuffer; // size = 0xF4

typedef s16 Palette16[16]; // size = 0x20

typedef struct Npc {
    /* 0x000 */ s32 flags;
    /* 0x004 */ void (*onUpdate)(struct Npc*); ///< Run before anything else for this NPC in update_npcs()
    /* 0x008 */ void (*onRender)(struct Npc*); ///< Run after the display list for this NPC is built
    /* 0x00C */ f32 yaw;
    /* 0x010 */ f32 planarFlyDist; /* also used for speech, temp0? */
    /* 0x014 */ f32 jumpScale; /* also used for speech, temp1? */
    /* 0x018 */ f32 moveSpeed;
    /* 0x01C */ f32 jumpVelocity;
    /* 0x020 */ struct BlurBuffer* blurBuf; ///< Null unless flag 0x100000 is set.
    /* 0x024 */ s32 spriteInstanceID;
    /* 0x028 */ union {
    /*       */   u16 h;
    /*       */   u32 w;
    /*       */ } currentAnim;
    /* 0x02C */ s32 unk_2C;
    /* 0x030 */ f32 animationSpeed;
    /* 0x034 */ f32 renderYaw;
    /* 0x038 */ Vec3f pos;
    /* 0x044 */ Vec3f rotation;
    /* 0x050 */ f32 rotationVerticalPivotOffset;
    /* 0x054 */ Vec3f scale;
    /* 0x060 */ Vec3f moveToPos;
    /* 0x06C */ Vec3f colliderPos; /* used during collision with player */
    /* 0x078 */ s32 shadowIndex;
    /* 0x07C */ f32 shadowScale;
    /* 0x080 */ s32 unk_80;
    /* 0x084 */ s16 unk_84;
    /* 0x086 */ s16 unk_86;
    /* 0x088 */ s16 isFacingAway;
    /* 0x08A */ s16 yawCamOffset;
    /* 0x08C */ s16 turnAroundYawAdjustment;
    /* 0x08E */ s16 duration; // TODO: name less vaguely
    /* 0x090 */ Vec3s homePos;
    /* 0x096 */ s16 unk_96;
    /* 0x098 */ s16 unk_98;
    /* 0x09A */ s16 unk_9A;
    /* 0x09C */ s16 unk_9C;
    /* 0x09E */ s16 unk_9E;
    /* 0x0A0 */ s16 unk_A0;
    /* 0x0A2 */ u16 unk_A2;
    /* 0x0A4 */ s8 npcID;
    /* 0x0A5 */ char unk_A5;
    /* 0x0A6 */ s16 collisionRadius;
    /* 0x0A8 */ s16 collisionHeight;
    /* 0x0AA */ s8 renderMode;
    /* 0x0AB */ s8 unk_AB;
    /* 0x0AC */ u8 alpha;
    /* 0x0AD */ u8 alpha2; ///< Multiplied with Npc::alpha
    /* 0x0AE */ char unk_AE[2];
    /* 0x0B0 */ s32** extraAnimList;
    /* 0x0B4 */ s8 unk_B4; // some kind of rendering type, 0..4 inclusive
    /* 0x0B5 */ s8 unk_B5;
    /* 0x0B6 */ s8 unk_B6;
    /* 0x0B7 */ s8 unk_B7;
    /* 0x0B8 */ char unk_B8[8];
    /* 0x0C0 */ s8 unk_C0;
    /* 0x0C1 */ s8 paletteCount;
    /* 0x0C2 */ char unk_C2[2];
    /* 0x0C4 */ s32* spritePaletteList;
    /* 0x0C8 */ Palette16 localPaletteData[16];
    /* 0x2C8 */ Palette16* localPalettes[16];
    /* 0x308 */ s16 unk_308;
    /* 0x30A */ s16 unk_30A;
    /* 0x30C */ s16 unk_30C;
    /* 0x30E */ s16 unk_30E;
    /* 0x310 */ s16 unk_310;
    /* 0x312 */ s16 unk_312;
    /* 0x314 */ s16 unk_314;
    /* 0x316 */ s16 unk_316;
    /* 0x318 */ f32 screenSpaceOffset2D[2];
    /* 0x320 */ f32 verticalStretch;
    /* 0x324 */ struct EffectInstance* decorations[2];
    /* 0x32C */ s8 decorationType[2];
    /* 0x32E */ s8 changedDecoration[2];
    /* 0x330 */ s8 decorationInitialised[2];
    /* 0x332 */ s16 decorationUnk[2];
    /* 0x336 */ char unk_336[10];
} Npc; // size = 0x340

typedef Npc* NpcList[MAX_NPCS];

typedef struct PlayerData {
    /* 0x000 */ s8 bootsLevel;
    /* 0x001 */ s8 hammerLevel;
    /* 0x002 */ s8 curHP;
    /* 0x003 */ s8 curMaxHP;
    /* 0x004 */ u8 hardMaxHP;
    /* 0x005 */ s8 curFP;
    /* 0x006 */ s8 curMaxFP;
    /* 0x007 */ u8 hardMaxFP;
    /* 0x008 */ s8 maxBP;
    /* 0x009 */ s8 level;
    /* 0x00A */ s8 hasActionCommands;
    /* 0x00B */ char unk_0B;
    /* 0x00C */ s16 coins;
    /* 0x00E */ s8 fortressKeyCount;
    /* 0x00F */ u8 starPieces;
    /* 0x010 */ s8 starPoints;
    /* 0x011 */ char unk_11;
    /* 0x012 */ s8 currentPartner;
    /* 0x013 */ char unk_13;
    /* 0x014 */ struct PartnerData partners[12];
    /* 0x074 */ s16 keyItems[32];
    /* 0x0B4 */ s16 badges[128];
    /* 0x1B4 */ s16 invItems[10];
    /* 0x1C8 */ s16 storedItems[32];
    /* 0x208 */ s16 equippedBadges[64];
    /* 0x288 */ char unk_288;
    /* 0x289 */ u8 merleeSpellType;
    /* 0x28A */ s8 merleeCastsLeft;
    /* 0x28B */ char unk_28B;
    /* 0x28C */ s16 merleeTurnCount;
    /* 0x28E */ s8 maxStarPower;
    /* 0x28F */ char unk_28F;
    /* 0x290 */ s16 specialBarsFilled;
    /* 0x292 */ s8 unk_292;
    /* 0x293 */ char unk_293[0x1];
    /* 0x294 */ u16 otherHitsTaken;
    /* 0x296 */ s16 unk_296;
    /* 0x298 */ u16 hitsTaken;
    /* 0x29A */ u16 hitsBlocked;
    /* 0x29C */ s16 playerFirstStrikes;
    /* 0x29E */ s16 enemyFirstStrikes;
    /* 0x2A0 */ u16 powerBounces;
    /* 0x2A2 */ s16 battlesCount;
    /* 0x2A4 */ s16 unk_2A4[4];
    /* 0x2AC */ s32 unk_2AC;
    /* 0x2B0 */ s32 unk_2B0;
    /* 0x2B4 */ u32 totalCoinsEarned;
    /* 0x2B8 */ s16 idleFrameCounter; /* frames with no inputs, overflows ever ~36 minutes of idling */
    /* 0x2BA */ char unk_2BA[2];
    /* 0x2BC */ u32 frameCounter; /* increases by 2 per frame */
    /* 0x2C0 */ s16 quizzesAnswered;
    /* 0x2C2 */ s16 quizzesCorrect;
    /* 0x2C4 */ s32 unk_2C4[12];
    /* 0x2F4 */ s32 unk_2F4[12];
    /* 0x324 */ s32 tradeEventStartTime;
    /* 0x328 */ s32 unk_328;
    /* 0x32C */ s16 starPiecesCollected;
    /* 0x32E */ s16 jumpGamePlays;
    /* 0x330 */ s32 jumpGameTotal; /* all-time winnings, max = 99999 */
    /* 0x334 */ s16 jumpGameRecord;
    /* 0x336 */ s16 smashGamePlays;
    /* 0x338 */ s32 smashGameTotal; /* all-time winnings, max = 99999 */
    /* 0x33C */ s16 smashGameRecord;
    /* 0x33E */ char unk_33E[2];
} PlayerData; // size = 0x340

typedef union {
    struct {
        /* 0x0 */ s16 genericFlagIndex;
        /* 0x2 */ char unk_2;
    } bytes;
    s32 flags;
} TriggerFlags;

typedef struct Trigger {
    /* 0x00 */ TriggerFlags flags;
    /* 0x04 */ s32 params1;
    /* 0x08 */ s32 params2;
    /* 0x0C */ s32 (*functionHandler)(struct Trigger*);
    /* 0x10 */ EvtSource* scriptSource;
    /* 0x14 */ struct Evt* runningScript;
    /* 0x18 */ s32 priority;
    /* 0x1C */ s32 scriptVars[3];
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ u8 unk_30;
    /* 0x31 */ char unk_31[3];
    /* 0x34 */ s32 runningScriptID;
} Trigger; // size = 0x38

typedef Trigger* TriggerList[MAX_TRIGGERS];

typedef union X32 {
    s32 s;
    f32 f;
} X32;

typedef struct Evt {
    /* 0x000 */ u8 state;
    /* 0x001 */ u8 currentArgc;
    /* 0x002 */ u8 currentOpcode;
    /* 0x003 */ u8 priority;
    /* 0x004 */ u8 groupFlags;
    /* 0x005 */ s8 blocked; /* 1 = blocking */
    /* 0x006 */ s8 loopDepth; /* how many nested loops we are in, >= 8 hangs forever */
    /* 0x007 */ s8 switchDepth; /* how many nested switches we are in, max = 8 */
    /* 0x008 */ Bytecode* ptrNextLine;
    /* 0x00C */ Bytecode* ptrReadPos;
    /* 0x010 */ s8 labelIndices[16];
    /* 0x020 */ UNK_PTR labelPositions[16];
    /* 0x060 */ UNK_PTR userData; /* unknown pointer; allocated on the heap, free'd in kill_script() */
    /* 0x064 */ struct Evt* blockingParent; /* parent? */
    /* 0x068 */ struct Evt* childScript;
    /* 0x06C */ struct Evt* parentScript; /* brother? */
    /* 0x070 */ s32 functionTemp[4];
    /* 0x080 */ ApiFunc callFunction;
    /* 0x084 */ s32 varTable[16];
    /* 0x0C4 */ s32 varFlags[3];
    /* 0x0D0 */ s32 loopStartTable[8];
    /* 0x0F0 */ s32 loopCounterTable[8];
    /* 0x110 */ s8 switchBlockState[8];
    /* 0x118 */ s32 switchBlockValue[8];
    /* 0x138 */ s32* buffer;
    /* 0x13C */ s32* array;
    /* 0x140 */ s32* flagArray;
    /* 0x144 */ s32 id;
    /* 0x148 */ union {
        s32 enemyID;
        s32 actorID;
        struct Enemy* enemy; ///< For overworld scripts owned by an Npc
        struct Actor* actor; ///< For battle scripts
    } owner1;                ///< Initially -1
    /* 0x14C */ union {
        s32 npcID;
        s32 triggerID;
        struct Npc* npc;            ///< For overworld scripts owned by an Npc
        struct Trigger* trigger;
    } owner2;                       ///< Initially -1
    /* 0x150 */ f32 timeScale;
    /* 0x154 */ f32 frameCounter;
    /* 0x158 */ s32 unk_158;
    /* 0x15C */ Bytecode* ptrFirstLine;
    /* 0x160 */ Bytecode* ptrSavedPosition;
    /* 0x164 */ Bytecode* ptrCurrentLine;
} Evt; // size = 0x168

typedef Evt* ScriptList[MAX_SCRIPTS];

struct Entity;

typedef s32 (*EntityCallback)(struct Entity*);

typedef struct Entity {
    /* 0x00 */ s32 flags;
    /* 0x04 */ u8 listIndex;
    /* 0x05 */ char unk_05;
    /* 0x06 */ u8 collisionFlags;
    /* 0x07 */ s8 unk_07;
    /* 0x08 */ char unk_08;
    /* 0x09 */ u8 hasEntityScript;
    /* 0x0A */ u8 type;
    /* 0x0B */ u8 alpha;
    /* 0x0C */ Vec3s aabb;
    /* 0x12 */ s16 vertexSegment;
    /* 0x14 */ s16 virtualModelIndex;
    /* 0x16 */ s16 shadowIndex;
    /* 0x18 */ s32* scriptReadPos;
    /* 0x1C */ EntityCallback updateScriptCallback;
    /* 0x20 */ EntityCallback updateMatrixOverride;
    /* 0x24 */ Evt* boundScript;
    /* 0x28 */ Bytecode* boundScriptBytecode;
    /* 0x2C */ s32* savedReadPos;
    /* 0x30 */ char unk_30[0x8];
    /* 0x38 */ struct StaticEntityData* staticData;
    /* 0x3C */ UNK_PTR renderSetupFunc; // pointer to draw func(?)
    /* 0x40 */ s32* dataBuf;
    /* 0x44 */ Mtx* vertexData;
    /* 0x48 */ Vec3f position;
    /* 0x54 */ Vec3f scale;
    /* 0x60 */ Vec3f rotation;
    /* 0x6C */ f32 shadowPosY;
    /* 0x70 */ Matrix4f* inverseTransformMatrix; /* world-to-local */
    /* 0x74 */ char unk_74[60];
    /* 0xB0 */ float effectiveSize;
    /* 0xB4 */ char unk_B4[4];
    /* 0xB8 */ Mtx transformMatrix;
} Entity; // size = 0xF8

typedef Entity* EntityList[MAX_ENTITIES];

typedef struct DynamicEntity {
    /* 0x00 */ s32 flags;
    /* 0x04 */ void (*update)(void);
    /* 0x08 */ void (*draw)(void);
} DynamicEntity;

typedef DynamicEntity* DynamicEntityList[MAX_DYNAMIC_ENTITIES];

typedef struct StaticEntityData {
    /* 0x00 */ s16 flags;
    /* 0x02 */ s16 argSize;
    /* 0x04 */ UNK_PTR unk_04;
    /* 0x08 */ char unk_08[4];
    /* 0x0C */ UNK_FUN_PTR(unk_data_func);
    /* 0x10 */ UNK_PTR unk_data_ptr1;
    /* 0x14 */ EntityCallback unk_data_ptr2;
    /* 0x18 */ s32 dmaStart;
    /* 0x1C */ s32 dmaEnd;
    /* 0x20 */ u8 entityType;
    /* 0x21 */ char unk_21[3];
} StaticEntityData; // size = 0x24

typedef struct MusicSettings {
    /* 0x00 */ u16 flags;
    /* 0x02 */ u16 unk_02;
    /* 0x04 */ s32 fadeOutTime;
    /* 0x08 */ s32 fadeInTime;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s32 songID;
    /* 0x14 */ s32 variation;
    /* 0x18 */ s32 songName;
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ s32 unk_28;
    /* 0x2C */ s32 unk_2C;
} MusicSettings; // size = 0x30

typedef struct UiStatus {
    /* 0x00 */ s32 hpIconIndexes[2];
    /* 0x08 */ s32 fpIconIndexes[2];
    /* 0x10 */ s32 coinIconIndex;
    /* 0x14 */ s32 coinIconIndex2; /* purpose? */
    /* 0x18 */ s32 starpointsIconIndex;
    /* 0x1C */ s32 starpointsIconIndex2; /* purpose? */
    /* 0x20 */ s32 iconIndex8;
    /* 0x24 */ s32 iconIndex9;
    /* 0x28 */ s32 iconIndexA;
    /* 0x2C */ s32 iconIndexB;
    /* 0x30 */ s32 iconIndexC;
    /* 0x34 */ s16 drawPosX; /* overall x-offset for whole UI */
    /* 0x36 */ s16 drawPosY; /* modulated as it appears, goes away */
    /* 0x38 */ s16 showTimer;
    /* 0x3A */ s8 hidden;
    /* 0x3B */ s8 unk_3B[2];
    /* 0x3D */ u8 displayHP;
    /* 0x3E */ u8 displayFP;
    /* 0x3F */ char unk_3F;
    /* 0x40 */ s16 displayCoins;
    /* 0x42 */ s16 displayStarpoints;
    /* 0x44 */ s8 ignoreChanges; /* set != 0 to prevent automatic opening from HP/FP changes */
    /* 0x45 */ s8 unk_45[2];
    /* 0x47 */ s8 disabled; /* set != 0 for menu to be disabled completely */
    /* 0x48 */ s16 displaySP;
    /* 0x4A */ s8 hpBlinking; /* bool */
    /* 0x4B */ u8 hpBlinkCounter;
    /* 0x4C */ u8 hpBlinkTimer; /* until stop */
    /* 0x4D */ s8 fpBlinking; /* bool */
    /* 0x4E */ u8 fpBlinkCounter;
    /* 0x4F */ u8 fpBlinkTimer; /* until stop */
    /* 0x50 */ s8 spBlinking;
    /* 0x51 */ u8 spBlinkCounter;
    /* 0x52 */ s8 starpointsBlinking; /* bool */
    /* 0x53 */ u8 starpointsBlinkCounter;
    /* 0x54 */ s8 coinsBlinking; /* bool */
    /* 0x55 */ u8 coinsBlinkCounter;
    /* 0x56 */ u8 coinsBlinkTimer; /* until stop */
    /* 0x57 */ char unk_57[3];
    /* 0x5A */ u8 spBarsToBlink; /* how many sp bars to blink */
    /* 0x5B */ char unk_5B;
    /* 0x5C */ s32 iconIndex10;
    /* 0x60 */ s32 iconIndex11;
    /* 0x64 */ s32 iconIndex12;
    /* 0x68 */ s32 iconIndex13;
    /* 0x6C */ s8 unk_6C[4];
} UiStatus; // size = 0x70

typedef struct Collider {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s16 nextSibling;
    /* 0x06 */ s16 firstChild;
    /* 0x08 */ s16 parentModelIndex;
    /* 0x0A */ s16 numTriangles;
    /* 0x0C */ struct ColliderTriangle* triangleTable;
    /* 0x10 */ struct ColliderBoundingBox* aabb;
    /* 0x14 */ char unk_14[4];
    /* 0x18 */ f32* vertexTable; // 3?
} Collider; // size = 0x1C

typedef struct CameraInitData {
    /* 0x00 */ s16 flags;
    /* 0x02 */ s8 type;
    /* 0x03 */ char unk_03;
    /* 0x04 */ s16 viewWidth;
    /* 0x06 */ s16 viewHeight;
    /* 0x08 */ s16 viewStartX;
    /* 0x0A */ s16 viewStartY;
    /* 0x0C */ s16 nearClip;
    /* 0x0E */ s16 farClip;
    /* 0x10 */ s16 vfov;
} CameraInitData; // size = 0x12;

typedef struct CameraUnk {
    /* 0x00 */ s16 unk_00;
    /* 0x02 */ s16 unk_02;
    /* 0x04 */ char unk_04[0x8];
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ char unk_10[0x54];
    /* 0x64 */ s32 unk_64;
    /* 0x68 */ char unk_68[0x24];
} CameraUnk; // size = 0x8C

typedef struct CameraControlSettings {
    /* 0x00 */ s32 type;
    /* 0x04 */ f32 boomLength;
    /* 0x08 */ f32 boomPitch;
    /* 0x0C */ Vec3f posA;
    /* 0x18 */ Vec3f posB;
    /* 0x24 */ f32 viewPitch;
    /* 0x28 */ s32 flag;
} CameraControlSettings; // size = 0x2C

typedef struct Camera {
    /* 0x000 */ u16 flags;
    /* 0x002 */ s16 moveFlags;
    /* 0x004 */ s16 updateMode;
    /* 0x006 */ s16 unk_06;
    /* 0x008 */ s16 changingMap;
    /* 0x00A */ s16 viewportW;
    /* 0x00C */ s16 viewportH;
    /* 0x00E */ s16 viewportStartX;
    /* 0x010 */ s16 viewportStartY;
    /* 0x012 */ s16 nearClip;
    /* 0x014 */ s16 farClip;
    /* 0x016 */ char unk_16[2];
    /* 0x018 */ f32 vfov;
    /* 0x01C */ s16 unk_1C;
    /* 0x01E */ s16 unk_1E;
    /* 0x020 */ s16 unk_20;
    /* 0x022 */ s16 unk_22;
    /* 0x024 */ s16 unk_24;
    /* 0x026 */ s16 unk_26;
    /* 0x028 */ s16 unk_28;
    /* 0x02A */ s16 zoomPercent;
    /* 0x02C */ s16 bgColor[3];
    /* 0x032 */ Vec3s targetScreenCoords;
    /* 0x038 */ u16 perspNorm;
    /* 0x03A */ char unk_3A[2];
    /* 0x03C */ Vec3f lookAt_eye;
    /* 0x048 */ Vec3f lookAt_obj;
    /* 0x054 */ f32 unk_54;
    /* 0x058 */ f32 unk_58;
    /* 0x05C */ f32 unk_5C;
    /* 0x060 */ Vec3f targetPos;
    /* 0x06C */ f32 currentYaw;
    /* 0x070 */ f32 unk_70;
    /* 0x074 */ f32 currentBoomYaw;
    /* 0x078 */ f32 currentBoomLength;
    /* 0x07C */ f32 currentYOffset;
    /* 0x080 */ char unk_80[4];
    /* 0x084 */ Vec3f trueRotation;
    /* 0x090 */ f32 currentBlendedYawNegated;
    /* 0x094 */ f32 currentPitch;
    /* 0x098 */ s32 unk_98;
    /* 0x09C */ s32 unk_9C;
    /* 0x0A0 */ Vp vp;
    /* 0x0B0 */ Vp vpAlt;
    /* 0x0C0 */ s32 unk_C0;
    /* 0x0C4 */ f32 unk_C4;
    /* 0x0C8 */ char unk_C8[0xC];
    /* 0x0D4 */ Matrix4f perspectiveMatrix;
    /* 0x114 */ Matrix4f viewMtxPlayer; /* centers on player */
    /* 0x154 */ Matrix4f viewMtxLeading; /* leads player slightly */
    /* 0x194 */ Matrix4f viewMtxShaking; /* used while ShakeCam is active */
    /* 0x1D4 */ char unk_1D4[0x28];
    /* 0x1FC */ void (*fpDoPreRender)(struct Camera*);
    /* 0x200 */ void (*fpDoPostRender)(struct Camera*);
    /* 0x204 */ Matrix4s* unkMatrix;
    /* 0x208 */ s32 unk_208;
    /* 0x20C */ Matrix4s* unkEffectMatrix;
    /* 0x210 */ char unk_210[0x2];
    /* 0x212 */ s16 unk_212;
    /* 0x214 */ CameraUnk unk_214[4];
    /* 0x444 */ CameraControlSettings* prevController;
    /* 0x448 */ CameraControlSettings* currentController;
    /* 0x44C */ CamPosSettings oldCameraSettings;
    /* 0x468 */ CamPosSettings newCameraSettings;
    /* 0x484 */ f32 interpAlpha;
    /* 0x488 */ f32 linearInterp;
    /* 0x48C */ f32 linearInterpScale; /* 3.0? */
    /* 0x490 */ f32 moveSpeed;
    /* 0x494 */ f32 unk_494;
    /* 0x498 */ f32 unk_498;
    /* 0x49C */ f32 unk_49C;
    /* 0x4A0 */ f32 savedTargetY;
    /* 0x4A4 */ f32 unk_4A4;
    /* 0x4A8 */ f32 unk_4A8;
    /* 0x4AC */ f32 unk_4AC;
    /* 0x4B0 */ Vec3f movePos;
    /* 0x4BC */ Vec3f prevPrevMovePos;
    /* 0x4C8 */ Vec3f prevMovePos;
    /* 0x4D4 */ u16 prevPrevFollowFlags;
    /* 0x4D6 */ u16 prevFollowFlags;
    /* 0x4D8 */ CameraControlSettings controlSettings;
    /* 0x504 */ u16 followPlayer;
    /* 0x506 */ u16 unk_506;
    /* 0x508 */ f32 panPhase;
    /* 0x50C */ f32 leadAmount;
    /* 0x510 */ f32 unk_510;
    /* 0x514 */ f32 unk_514;
    /* 0x518 */ f32 unk_518;
    /* 0x51C */ s32 unk_51C;
    /* 0x520 */ f32 unk_520;
    /* 0x524 */ f32 unk_524;
    /* 0x528 */ f32 unk_528;
    /* 0x52C */ s32 unk_52C;
    /* 0x530 */ s32 unk_530;
    /* 0x534 */ struct ColliderBoundingBox* aabbForZoneBelow;
    /* 0x538 */ char unk_538[0x18];
    /* 0x550 */ f32 unk_550;
    /* 0x554 */ s16 unk_554;
    /* 0x556 */ s16 unk_556;
} Camera; // size = 0x558

typedef struct BattleStatusUnkInner {
    /* 0x00 */ char unk_00[0x10];
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ char unk_12[8];
    /* 0x1A */ s16 unk_1A;
    /* 0x1C */ char unk_1C[8];
    /* 0x24 */ s16 unk_24;
} BattleStatusUnkInner; // size = unknown

typedef struct BattleStatusUnk {
    /* 0x00 */ char unk_00[0xC];
    /* 0x0C */ BattleStatusUnkInner* unk_0C;
} BattleStatusUnk; // size = unknown

typedef struct FGModelData {
    /* 0x00 */ char unk_00[0x18];
    /* 0x18 */ s32* idList;
} FGModelData; // size = unknown

typedef struct BattleStatus {
    /* 0x000 */ s32 flags1;
    /* 0x004 */ s32 flags2;
    /* 0x008 */ s32 varTable[16];
    /* 0x048 */ u8 currentSubmenu;
    /* 0x049 */ char unk_49[3];
    /* 0x04C */ s8 unk_4C;
    /* 0x04D */ s8 unk_4D;
    /* 0x04E */ s8 unk_4E;
    /* 0x04F */ s8 unk_4F;
    /* 0x050 */ s8 unk_50;
    /* 0x051 */ s8 unk_51;
    /* 0x052 */ s8 unk_52;
    /* 0x053 */ s8 stratsLastCursorPos;
    /* 0x054 */ char unk_54[8];
    /* 0x05C */ s8 unk_5C;
    /* 0x05D */ s8 unk_5D;
    /* 0x05E */ char unk_5E[4];
    /* 0x062 */ s8 unk_62;
    /* 0x063 */ s8 unk_63;
    /* 0x064 */ char unk_64[12];
    /* 0x070 */ s16 unk_70;
    /* 0x072 */ char unk_72[2];
    /* 0x074 */ s32 unk_74;
    /* 0x078 */ u8 totalStarPoints;
    /* 0x079 */ u8 pendingStarPoints; /* how many to add */
    /* 0x07A */ u8 incrementStarPointDelay; /* related to star points, set to 0x28 when they are dropped */
    /* 0x07B */ u8 damageTaken;
    /* 0x07C */ u8 changePartnerAllowed;
    /* 0x07D */ char unk_7D[4];
    /* 0x081 */ s8 actionSuccess;
    /* 0x082 */ char unk_82;
    /* 0x083 */ s8 unk_83;
    /* 0x084 */ s8 unk_84;
    /* 0x085 */ s8 unk_85;
    /* 0x086 */ s8 unk_86;
    /* 0x087 */ s8 blockResult; /* 0 = fail, 1 = success, -1 = mashed */
    /* 0x088 */ u8 itemUsesLeft; /* set to 2 for doublke dip, 3 for triple */
    /* 0x089 */ u8 hpDrainCount;
    /* 0x08A */ s8 unk_8A;
    /* 0x08B */ s8 hustleTurns; /* numTurns from hustle drink, normally 0 */
    /* 0x08C */ char unk_8C;
    /* 0x08D */ s8 unk_8D;
    /* 0x08E */ s8 initialEnemyCount; /* used for SP award bonus */
    /* 0x08F */ char unk_8F[1];
    /* 0x090 */ s16 unk_90;
    /* 0x092 */ s8 unk_92;
    /* 0x093 */ char unk_93;
    /* 0x094 */ s8 unk_94;
    /* 0x095 */ s8 unk_95;
    /* 0x096 */ s8 hammerCharge;
    /* 0x097 */ s8 jumpCharge;
    /* 0x098 */ char unk_98;
    /* 0x099 */ u8 rushesFlags; /* 1 = mega rush, 2 = power rush */
    /* 0x09A */ s8 outtaSightActive;
    /* 0x09B */ s8 turboChargeTurnsLeft;
    /* 0x09C */ u8 turboChargeAmount; /* unused? */
    /* 0x09D */ s8 waterBlockTurnsLeft;
    /* 0x09E */ u8 waterBlockAmount; /* unused? */
    /* 0x09F */ char unk_9F;
    /* 0x0A0 */ s32* unk_A0;
    /* 0x0A4 */ s8 cloudNineTurnsLeft;
    /* 0x0A5 */ s8 cloudNineDodgeChance; /* = 50% */
    /* 0x0A6 */ char unk_A6[2];
    /* 0x0A8 */ struct EffectInstance* cloudNineEffect;
    /* 0x0AC */ char unk_AC;
    /* 0x0AD */ s8 unk_AD;
    /* 0x0AE */ s8 hammerLossTurns;
    /* 0x0AF */ s8 jumpLossTurns;
    /* 0x0B0 */ s8 itemLossTurns;
    /* 0x0B1 */ char unk_B1[3];
    /* 0x0B4 */ UNK_FUN_PTR(preUpdateCallback);
    /* 0x0B8 */ UNK_FUN_PTR(unk_B8);
    /* 0x0BC */ struct Evt* controlScript; /* control handed over to this when changing partners */
    /* 0x0C0 */ s32 controlScriptID;
    /* 0x0C4 */ struct Evt* camMovementScript;
    /* 0x0C8 */ s32 camMovementScriptID;
    /* 0x0CC */ Vec3f unk_CC;
    /* 0x0D8 */ struct Actor* playerActor;
    /* 0x0DC */ struct Actor* partnerActor;
    /* 0x0E0 */ struct Actor* enemyActors[24];
    /* 0x140 */ s16 enemyIDs[24];
    /* 0x170 */ s8 unk_170;
    /* 0x171 */ s8 numEnemyActors;
    /* 0x172 */ s16 currentTurnEnemyID;
    /* 0x174 */ struct Actor* currentTurnEnemy;
    /* 0x178 */ s8 moveCategory;
    /* 0x179 */ char unk_179;
    /* 0x17A */ s16 selectedItemID;
    /* 0x17C */ s16 selectedMoveID;
    /* 0x17E */ s16 currentAttackDamage;
    /* 0x180 */ s16 lastAttackDamage;
    /* 0x182 */ char unk_182[2];
    /* 0x184 */ s32 currentTargetListFlags; /* set when creating a target list, also obtain from the flags field of moves */
    /* 0x188 */ s32 currentAttackElement;
    /* 0x18C */ s32 currentAttackEventSuppression;
    /* 0x190 */ s32 currentAttackStatus;
    /* 0x194 */ u8 statusChance;
    /* 0x195 */ u8 statusDuration;
    /* 0x196 */ char unk_196;
    /* 0x197 */ u8 targetHomeIndex; /* some sort of home idnex used for target list construction */
    /* 0x198 */ u8 powerBounceCounter;
    /* 0x199 */ s8 wasStatusInflicted; /* during last attack */
    /* 0x19A */ u8 unk_19A;
    /* 0x19B */ char unk_19B[5];
    /* 0x1A0 */ s16 currentTargetID; /* selected? */
    /* 0x1A2 */ s8 currentTargetPart; /* selected? */
    /* 0x1A3 */ char unk_1A3;
    /* 0x1A4 */ s16 currentTargetID2;
    /* 0x1A6 */ s8 currentTargetPart2;
    /* 0x1A7 */ s8 battlePhase;
    /* 0x1A8 */ s16 attackerActorID;
    /* 0x1AA */ char unk_1AA[4];
    /* 0x1AE */ s16 submenuIcons[24]; /* icon IDs */
    /* 0x1DE */ u8 submenuMoves[24]; /* move IDs */
    /* 0x1F6 */ u8 submenuEnabled[24];
    /* 0x20E */ u8 submenuMoveCount;
    /* 0x20F */ char unk_20F;
    /* 0x210 */ s32 currentButtonsDown;
    /* 0x214 */ s32 currentButtonsPressed;
    /* 0x218 */ s32 currentButtonsHeld;
    /* 0x21C */ s32 stickX;
    /* 0x220 */ s32 stickY;
    /* 0x224 */ s32 inputBitmask;
    /* 0x228 */ s32 dpadX; /* 0-360 */
    /* 0x22C */ s32 dpadY; /* 0-60 */
    /* 0x230 */ s32 holdInputBuffer[64];
    /* 0x330 */ s32 pushInputBuffer[64];
    /* 0x430 */ s8 holdInputBufferPos;
    /* 0x431 */ s8 inputBufferPos;
    /* 0x432 */ s8 unk_432;
    /* 0x433 */ char unk_433;
    /* 0x434 */ s32* unk_434;
    /* 0x438 */ FGModelData* foregroundModelData;
    /* 0x43C */ BattleStatusUnk* unk_43C;
    /* 0x440 */ u8 tattleFlags[27];
    /* 0x45B */ char unk_45B[5];
} BattleStatus; // size = 0x460

typedef struct TextureHeader {
    /* 0x00 */ s8 name[32];
    /* 0x20 */ s16 auxW;
    /* 0x22 */ s16 mainW;
    /* 0x24 */ s16 auxH;
    /* 0x26 */ s16 mainH;
    /* 0x28 */ char unk_28;
    /* 0x29 */ u8 extraTiles;
    /* 0x2A */ u8 colorCombine;
    /* 0x2B */ u8 fmt;
    /* 0x2C */ u8 bitDepth;
    /* 0x2D */ u8 wrapH;
    /* 0x2E */ u8 wrapV;
    /* 0x2F */ u8 filtering;
} TextureHeader; // size = 0x30

typedef struct StaticMove {
    /* 0x00 */ s32 moveNameID;
    /* 0x04 */ s32 flags;
    /* 0x08 */ s32 worldDescID;
    /* 0x0C */ s32 menuDescID;
    /* 0x10 */ u8 battleSubmenu;
    /* 0x11 */ u8 costFP;
    /* 0x12 */ s8 costBP;
    /* 0x13 */ u8 actionCommandID;
} StaticMove; // size = 0x14

typedef struct CollisionData {
    /* 0x00 */ f32* vertices;
    /* 0x04 */ Collider* colliderList;
    /* 0x08 */ struct ColliderBoundingBox** aabbs;
    /* 0x0C */ s16 numColliders;
    /* 0x0E */ char unk_0E[2];
} CollisionData; // size = 0x10

typedef struct ModelGroupData {
    /* 0x00 */ UNK_PTR transformMatrix;
    /* 0x04 */ Lightsn* lightingGroup;
    /* 0x08 */ s32 numLights;
    /* 0x0C */ s32 numChildren;
    /* 0x10 */ struct ModelNode** childList;
} ModelGroupData; // size = 0x14

typedef struct ModelDisplayData {
    /* 0x0 */ Gfx* displayList;
    /* 0x4 */ char unk_00[0x4];
} ModelDisplayData; // size = 0x8

typedef struct AnimatorNode {
    /* 0x00 */ Gfx* displayList;
    /* 0x04 */ struct AnimatorNode* children[0x20];
    /* 0x84 */ Vec3f basePos; // ?
    /* 0x90 */ Vec3f pos;
    /* 0x9C */ Vec3f rotation;
    /* 0xA8 */ Vec3f scale;
    /* 0xB4 */ Matrix4f mtx;
    /* 0xF4 */ s16 flags;
    /* 0xF6 */ s16 uniqueIndex;
    /* 0xF8 */ s16 vertexStartOffset;
    /* 0xFA */ char unk_FA[2];
    /* 0xFC */ union {
    /*      */   s32 modelID;
    /*      */   Vtx* vtxList;
    /*      */ } fcData;
} AnimatorNode; // size = 0x100

typedef struct AnimatorNodeBlueprint {
    /* 0x00 */ Gfx* displayList;
    /* 0x04 */ Vec3f basePos;
    /* 0x10 */ Vec3f rotation;
    /* 0x1C */ char unk_1C[0x4];
} AnimatorNodeBlueprint; // size = 0x20

typedef struct StaticAnimatorNode {
    /* 0x00 */ Gfx* displayList; // can sometime point to a node???
    /* 0x04 */ Vec3s rot; /* range = -180,180 */
    /* 0x0A */ char unk_0A[0x2];
    /* 0x0C */ Vec3f pos;
    /* 0x18 */ struct StaticAnimatorNode* sibling;
    /* 0x1C */ struct StaticAnimatorNode* child;
    /* 0x20 */ s16 vertexStartOffset;
    /* 0x22 */ char unk_22[0x2];
    /* 0x24 */ Vtx* vtxList;
    /* 0x28 */ s16 modelID;
    /* 0x2A */ char unk_2A[0x2];
} StaticAnimatorNode; // size = 0x2C

typedef struct ModelAnimator {
    /* 0x000 */ u32 flags;
    /* 0x004 */ s8 renderMode;
    /* 0x005 */ char unk_05[3];
    /* 0x008 */ s8* animReadPos;
    /* 0x00C */ s8* savedReadPos;
    /* 0x010 */ AnimatorNode* rootNode;
    /* 0x014 */ u8 nextUniqueID;
    /* 0x015 */ u8 staticNodeIDs[0x7A]; // ?
    /* 0x08F */ char unk_08F[0x1];
    /* 0x090 */ f32 nextUpdateTime;
    /* 0x094 */ f32 timeScale;
    /* 0x098 */ Mtx mtx;
    /* 0x0D8 */ Vtx** vertexArray;
    /* 0x0DC */ s8* animationBuffer;
    /* 0x0E0 */ StaticAnimatorNode* staticNodes[0x7A];
    /* 0x2C8 */ StaticAnimatorNode** staticRoot;
    /* 0x2CC */ s32 treeIndexPos;
    /* 0x2D0 */ s32 savedTreePos;
    /* 0x2D4 */ void (*fpRenderCallback)(void);
    /* 0x2D8 */ s32 renderCallbackArg;
    /* 0x2DC */ char unk_2DC[4];
} ModelAnimator; // size = 0x2E0

typedef ModelAnimator* AnimatedMeshList[MAX_ANIMATED_MESHES];

typedef struct PrintHandle {
    /* 0x000 */ char unk_00[16];
    /* 0x010 */ s8* printbuf;
    /* 0x014 */ char unk_14[1344];
} PrintHandle; // size = 0x554

typedef struct OtherPrint {
    /* 0x00 */ char unk_00[16];
    /* 0x10 */ f32 msgScaleH;
    /* 0x14 */ f32 msgScaleW;
    /* 0x18 */ f32 characterScaleH;
    /* 0x1C */ f32 characterScaleW;
    /* 0x20 */ char unk_20[32];
    /* 0x40 */ s32 currentPosX;
    /* 0x44 */ char unk_44[16];
} OtherPrint; // size = 0x54

typedef struct ColliderBoundingBox {
    /* 0x00 */ f32 min[3];
    /* 0x0C */ f32 max[3];
    /* 0x18 */ s32 flagsForCollider;
} ColliderBoundingBox; // size = 0x1C

typedef struct StaticItem {
    /* 0x00 */ s32 nameMsg;
    /* 0x04 */ s16 iconID;
    /* 0x06 */ s16 badgeSortPriority;
    /* 0x08 */ s32 targetFlags;
    /* 0x0C */ s16 sellValue;
    /* 0x0E */ char unk_0E[2];
    /* 0x10 */ s32 menuMsg;
    /* 0x14 */ s32 itemMsg;
    /* 0x18 */ s16 typeFlags;
    /* 0x1A */ u8 moveID;
    /* 0x1B */ s8 potencyA;
    /* 0x1C */ s8 potencyB;
    /* 0x1D */ char unk_1D[3];
} StaticItem; // size = 0x20

typedef struct ItemEntity {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s16 boundVar; /* see make_item_entity */
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ Vec3f position;
    /* 0x14 */ struct ItemEntityPhysicsData* physicsData;
    /* 0x18 */ s16 itemID; /* into item table, also worldIconID */
    /* 0x1A */ u8 state;
    /* 0x1B */ s8 type;
    /* 0x1C */ u8 pickupDelay; /* num frames before item can be picked up */
    /* 0x1D */ char unk_1D;
    /* 0x1E */ s16 wsFaceAngle; /* < 0 means none */
    /* 0x20 */ s16 shadowIndex;
    /* 0x22 */ char unk_22[2];
    /* 0x24 */ u32* readPos;
    /* 0x28 */ u32* savedReadPos;
    /* 0x2C */ char unk_2C[2];
    /* 0x2E */ u8 unkCounter;
    /* 0x2F */ s8 unk_2F;
    /* 0x30 */ f32 scale;
    /* 0x34 */ char unk_34[8];
    /* 0x3C */ s32 framesLeft;
    /* 0x40 */ s32* currentState;
    /* 0x44 */ s32 unk_44;
    /* 0x48 */ s32* sequenceStart;
    /* 0x4C */ s32* unk_4C;
    /* 0x50 */ s32* unk_50;
    /* 0x54 */ s32 unk_54;
    /* 0x58 */ s32 unk_58;
} ItemEntity; // size = 0x5C

typedef struct MessagePrintState {
    /* 0x000 */ s8* srcBuffer;
    /* 0x004 */ s16 printBufferPos;
    /* 0x006 */ char unk_06[2];
    /* 0x008 */ s32 msgID;
    /* 0x00C */ s16 srcBufferPos;
    /* 0x00E */ s16 currentPrintDelay;
    /* 0x010 */ u8 printBuffer[1088]; // slightly larger than source buffer
    /* 0x450 */ s16 printBufferSize;
    /* 0x452 */ u16 effectFrameCounter;
    /* 0x454 */ u8 font;
    /* 0x455 */ s8 fontVariant;
    /* 0x456 */ Vec2s windowOffsetPos; // offset from baseWindowPos. used to animated window pos?
    /* 0x45A */ Vec2s windowBasePos; // ex: set by the parameters for choice style
    /* 0x45E */ s8 printDelayTime; // delay to print each chunk
    /* 0x45F */ s8 charsPerChunk; // how many chars to print at once
    /* 0x460 */ s32 curLinePos; // position along current line
    /* 0x464 */ s8 unk_464;
    /* 0x465 */ char unk_465;
    /* 0x466 */ s16 nextLinePos; // ?
    /* 0x468 */ s8 lineCount;
    /* 0x469 */ char unk_469[0x3];
    /* 0x46C */ s32 unk_46C;
    /* 0x470 */ u8 currentAnimFrame[4];
    /* 0x474 */ s16 animTimers[4];
    /* 0x47C */ s8 rewindArrowAnimState;
    /* 0x47D */ char unk_47D[0x1];
    /* 0x47E */ s16 rewindArrowBlinkCounter;
    /* 0x480 */ s16 unk_480;
    /* 0x482 */ Vec2s rewindArrowPos;
    /* 0x486 */ s8 currentLine;
    /* 0x487 */ u8 unkArraySize;
    /* 0x488 */ u16 lineEndPos[4];
    /* 0x490 */ char unk_490[0x38];
    /* 0x4C8 */ u16 unk_4C8;
    /* 0x4CA */ s16 unk_4CA;
    /* 0x4CC */ u16 unk_4CC;
    /* 0x4CE */ s8 maxOption;
    /* 0x4CF */ char unk_4CF[0x1];
    /* 0x4D0 */ s16 cursorPosX[6];
    /* 0x4DC */ s16 cursorPosY[6];
    /* 0x4E8 */ u8 currentOption;
    /* 0x4E9 */ s8 madeChoice;
    /* 0x4EA */ u8 cancelOption;
    /* 0x4EB */ char unk_4EB[0x1];
    /* 0x4EC */ s8 targetOption;
    /* 0x4ED */ s8 unkCounter;
    /* 0x4EE */ s8 selectedOption;
    /* 0x4EF */ char unk_4EF[0x9];
    /* 0x4F8 */ u8 windowState;
    /* 0x4F9 */ char unk_4F9[0x3];
    /* 0x4FC */ s32 stateFlags;
    /* 0x500 */ s16 delayFlags; // ?
    /* 0x502 */ char unk_502[0x2];
    /* 0x504 */ s32* closedWritebackBool; // if not null, writes 1 here when message closes
    /* 0x508 */ u8 style;
    /* 0x509 */ u8 fadeInCounter;
    /* 0x50A */ Vec2s initOpenPos; // where the message originates from, in screen-space coords
    /* 0x50E */ Vec2su openStartPos;
    /* 0x512 */ u8 fadeOutCounter;
    /* 0x513 */ char unk_513[0x1];
    /* 0x514 */ Vec2su windowSize;
    /* 0x518 */ s8 speechSoundType;
    /* 0x519 */ u8 volume;
    /* 0x51A */ s8 speechPan; // just pan?
    /* 0x51B */ char unk_51B[0x1];
    /* 0x51C */ u16 speechVolumePitch;
    /* 0x51E */ char unk_51E[0x2];
    /* 0x520 */ s32 speedSoundIDA;
    /* 0x524 */ s32 speedSoundIDB;
    /* 0x528 */ s16 varBufferReadPos;
    /* 0x52A */ s8 unk_52A;
    /* 0x52B */ u8 currentImageIndex;
    /* 0x52C */ Vec2su varImageScreenPos; // in addition, posX=0 is taken as 'dont draw'
    /* 0x530 */ u8 varImgHasBorder;
    /* 0x531 */ u8 varImgFinalAlpha;
    /* 0x532 */ u8 varImgAlphaFadeStep; // how much to fade in per frame
    /* 0x533 */ u8 varImageDisplayState; // 0 = fade in, 1 = fully visible, 2 = fade out
    /* 0x534 */ s16 varImageFadeTimer; // frames faded in
    /* 0x536 */ s16 msgHeight;
    /* 0x538 */ u16 msgWidth;
    /* 0x53A */ s8 maxLineChars;
    /* 0x53B */ s8 numLines;
    /* 0x53C */ u8 maxLinesPerPage;
    /* 0x53D */ char unk_53D[0x3];
    /* 0x540 */ f32 sizeScale;
    /* 0x544 */ s32* letterBackgroundImg;
    /* 0x548 */ s32* letterBackgroundPal;
    /* 0x54C */ s32* letterContentImg;
    /* 0x550 */ s32* letterContentPal;
    /* 0x554 */ char unk_554[0x4];
} MessagePrintState; // size = 0x558

typedef struct MessageDrawState {
    /* 0x00 */ s32 clipX[2]; // characters beyond this pos get skipped
    /* 0x08 */ s32 clipY[2]; // characters beyond this pos get skipped
    /* 0x10 */ Vec2f msgScale;
    /* 0x18 */ Vec2f charScale;
    /* 0x20 */ s32 drawBufferPos; // msg gets printed here and read for display
    /* 0x24 */ s16 savedPos[2];
    /* 0x28 */ u8 savedColor;
    /* 0x29 */ u8 unk_29;
    /* 0x2A */ char unk_2A[0x1];
    /* 0x2B */ u8 framePalette;
    /* 0x2C */ s8 unk_2C;
    /* 0x2D */ u8 unk_2D;
    /* 0x2E */ u8 centerPos;
    /* 0x2F */ char unk_2F[0x1];
    /* 0x30 */ s32 visiblePrintedCount;
    /* 0x34 */ u16 printModeFlags; // C0 = center, 10 = drawing image
    /* 0x36 */ char unk_36[0x2];
    /* 0x38 */ u32 effectFlags;
    /* 0x3C */ u16 font; // 0 or 1
    /* 0x3E */ u16 fontVariant;
    /* 0x40 */ u8 currentPosX;
    /* 0x41 */ char unk_41;
    /* 0x42 */ u16 nextPos[2];
    /* 0x46 */ s16 textStartPos[2]; // relative to textbox
    /* 0x4A */ s16 textColor;
    /* 0x4C */ u8* printBuffer;
    /* 0x50 */ u8 nextCounter; // related to closing mssages and cmd FA
    /* 0x51 */ char unk_51[0x3];
} MessageDrawState; // size = 0x54

typedef struct MessageCharData {
    /* 0x0 */ s8* raster;
    /* 0x4 */ u8* charWidthTable;
    /* 0x8 */ u8 monospaceWidth;
    /* 0x9 */ u8 baseHeightOffset;
    /* 0xA */ char unk_0A[0x2];
} MessageCharData; // size = 0xC

typedef struct MessageCharset {
    /* 0x0 */ Vec2b texSize;
    /* 0x2 */ s8 unk_02;
    /* 0x3 */ u8 newLineY;
    /* 0x4 */ s16 charRasterSize; // in bytes
    /* 0x6 */ char unk_06[0x2];
    /* 0x8 */ MessageCharData* rasters;
} MessageCharset; // size = 0xA;

typedef struct MesasgeFontGlyphData {
    /* 0x0 */ s8* raster;
    /* 0x4 */ s16* palette;
    /* 0x8 */ Vec2b texSize;
    /* 0xA */ s8 charWidth;
    /* 0xB */ s8 charHeight;
} MesasgeFontGlyphData; // size = 0xC

typedef struct MessageNumber {
    /* 0x00 */ s32* rasters;
    /* 0x04 */ s8 texSize;
    /* 0x05 */ u8 texWidth;
    /* 0x06 */ u8 texHeight;
    /* 0x07 */ s8 digitWidth[10];
    /* 0x11 */ s8 fixedWidth;
    /* 0x12 */ char unk_12[0x2];
} MessageNumber; // size = 0x14

typedef struct ShopItemEntity {
    /* 0x00 */ s32 index;
    /* 0x04 */ Vec3f pos;
} ShopItemEntity; // size = 0x10

typedef struct GameStatus {
    /* 0x000 */ u32 currentButtons;
    /* 0x004 */ u32 altCurrentButtons; /* input used for batte when flag 80000 set */
    /* 0x008 */ char unk_08[8];
    /* 0x010 */ u32 pressedButtons; /* bits = 1 for frame of button press */
    /* 0x014 */ u32 altPressedButtons; /* input used for batte when flag 80000 set */
    /* 0x018 */ char unk_18[8];
    /* 0x020 */ u32 heldButtons; /* bits = 1 every 4th frame during hold */
    /* 0x024 */ u32 altHeldButtons; /* input used for batte when flag 80000 set */
    /* 0x028 */ char unk_28[8];
    /* 0x030 */ u32 prevButtons; /* from previous frame */
    /* 0x034 */ char unk_34[12];
    /* 0x040 */ s8 stickX; /* with deadzone */
    /* 0x041 */ s8 altStickX; /* input used for batte when flag 80000 set */
    /* 0x042 */ char unk_42[2];
    /* 0x044 */ s8 stickY; /* with deadzone */
    /* 0x045 */ s8 altStickY; /* input used for batte when flag 80000 set */
    /* 0x046 */ char unk_46[2];
    /* 0x048 */ s16 unk_48[4];
    /* 0x050 */ s16 unk_50[4];
    /* 0x058 */ s16 unk_58;
    /* 0x05A */ char unk_5A[6];
    /* 0x060 */ s16 unk_60;
    /* 0x062 */ char unk_62[6];
    /* 0x068 */ s16 demoButtonInput;
    /* 0x06A */ s8 demoStickX;
    /* 0x06B */ s8 demoStickY;
    /* 0x06C */ s32 mainScriptID;
    /* 0x070 */ s8 isBattle;
    /* 0x071 */ s8 demoState; /* (0 = not demo, 1 = map demo, 2 = demo map changing) */
    /* 0x072 */ s8 nextDemoScene; /* which part of the demo to play next */
    /* 0x073 */ u8 contBitPattern;
    /* 0x074 */ s8 debugEnemyContact;
    /* 0x075 */ s8 debugQuizmo;
    /* 0x076 */ s8 unk_76;
    /* 0x077 */ char unk_77;
    /* 0x078 */ s8 disableScripts;
    /* 0x079 */ char unk_79;
    /* 0x07A */ s8 musicEnabled;
    /* 0x07B */ char unk_7B;
    /* 0x07C */ s8 unk_7C;
    /* 0x07D */ s8 unk_7D;
    /* 0x07E */ u8 peachFlags; /* (1 = isPeach, 2 = isTransformed, 4 = hasUmbrella) */
    /* 0x07F */ s8 peachDisguise; /* (1 = koopatrol, 2 = hammer bros, 3 = clubba) */
    /* 0x080 */ u8 peachAnimIdx; ///< @see world_action_idle_peachAnims
    /* 0x081 */ s8 unk_81;
    /* 0x082 */ s8 unk_82;
    /* 0x083 */ s8 unk_83;
    /* 0x084 */ s8 playerSpriteSet;
    /* 0x085 */ char unk_85;
    /* 0x086 */ s16 areaID;
    /* 0x088 */ s16 prevArea;
    /* 0x08A */ s16 didAreaChange;
    /* 0x08C */ s16 mapID;
    /* 0x08E */ s16 entryID;
    /* 0x090 */ u16 unk_90;
    /* 0x092 */ u16 unk_92;
    /* 0x094 */ f32 exitTangent;
    /* 0x098 */ Vec3f playerPos;
    /* 0x0A4 */ f32 playerYaw;
    /* 0x0A8 */ s8 creditsViewportMode;
    /* 0x0A9 */ s8 unk_A9;
    /* 0x0AA */ s8 demoFlags;
    /* 0x0AB */ u8 unk_AB;
    /* 0x0AC */ s8 loadMenuState;
    /* 0x0AD */ s8 menuCounter;
    /* 0x0AE */ s8 bSkipIntro;
    /* 0x0AF */ char unk_AF[0x7];
    /* 0x0B6 */ s16 bootAlpha;
    /* 0x0B8 */ s16 bootBlue;
    /* 0x0BA */ s16 bootGreen;
    /* 0x0BC */ s16 bootRed;
    /* 0x0BE */ char unk_BE[94];
    /* 0x11C */ Vec3f unk_11C;
    /* 0x128 */ Vec3f playerTraceNormal;
    /* 0x134 */ u16 frameCounter;
    /* 0x136 */ char unk_136[2];
    /* 0x138 */ s32 nextRNG;
    /* 0x13C */ s16 unk_13C;
    /* 0x13E */ char unk_13E[2];
    /* 0x140 */ ShopItemEntity* shopItemEntities;
    /* 0x144 */ struct Shop* mapShop;
    /* 0x148 */ s16 enableBackground; /* (bit 2 is also used for something) */
    /* 0x14A */ s16 backgroundMinW;
    /* 0x14C */ s16 backgroundMinH;
    /* 0x14E */ s16 backgroundMaxW;
    /* 0x150 */ s16 backgroundMaxH;
    /* 0x152 */ s16 backgroundXOffset; /* (used for parallax scroll) */
    /* 0x154 */ UNK_PTR backgroundRaster;
    /* 0x158 */ UNK_PTR backgroundPalette;
    /* 0x15C */ s16 unk_15C;
    /* 0x15E */ u16 unk_15E;
    /* 0x160 */ Vec3s savedPos;
    /* 0x166 */ u8 saveSlot;
    /* 0x167 */ u8 loadType; /* (0 = from map, 1 = from main menu) */
    /* 0x168 */ u32 saveCount;
    /* 0x16C */ char unk_16C[12];
} GameStatus; // size = 0x178

// PartnerAnims
typedef struct PartnerAnimations {
    /* 0x00 */ UNK_PTR anims[9];
} PartnerAnimations; // size = 0x24

typedef struct Shadow {
    /* 0x00 */ s32 flags;
    /* 0x04 */ u8 listIndex;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ char unk_07;
    /* 0x08 */ s16 entityModelID;
    /* 0x0A */ s16 vertexSegment;
    /* 0x0C */ Vtx_tn** vertexArray;
    /* 0x10 */ Vec3f position;
    /* 0x1C */ Vec3f scale;
    /* 0x28 */ Vec3f rotation;
    /* 0x34 */ char unk_34[0x4];
    /* 0x38 */ Mtx transformMatrix;
} Shadow; // size = 0x78

typedef Shadow* ShadowList[MAX_SHADOWS];

typedef struct StaticShadowData {
    /* 0x00 */ u16 flags;
    /* 0x02 */ char unk_02[0x2];
    /* 0x04 */ s32* unk_04;
    /* 0x08 */ StaticAnimatorNode** animModelNode;
    /* 0x0C */ void (*onCreateCallback)(Shadow* shadow);
    /* 0x10 */ char unk_10[0x10];
    /* 0x20 */ s32 unk_20;
} StaticShadowData; // size = 0x24

typedef struct PushBlockGrid {
    /* 0x00 */ s8* cells;
    /* 0x04 */ u8 numCellsX;
    /* 0x05 */ u8 numCellsZ;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ s32 centerPos[3];
    /* 0x14 */ UNK_FUN_PTR(dropCallback);
    /* 0x18 */ char unk_18[4];
} PushBlockGrid; // size = 0x1C

typedef struct ItemEntityPhysicsData {
    /* 0x00 */ f32 verticalVelocity;
    /* 0x04 */ f32 gravity; /* 2 = normal, 1 = low gravity, higher values never 'settle' */
    /* 0x08 */ char unk_08[4];
    /* 0x0C */ f32 constVelocity;
    /* 0x10 */ f32 velx;
    /* 0x14 */ f32 velz;
    /* 0x18 */ f32 moveAngle;
    /* 0x1C */ char unk_1C[8];
} ItemEntityPhysicsData; // size = 0x24

typedef struct RenderTask {
    /* 0x00 */ s32 renderMode;
    /* 0x04 */ s32 distance; /* value between 0 and -10k */
    /* 0x08 */ void* appendGfxArg;
    /* 0x0C */ void (*appendGfx)(void*);
} RenderTask; // size = 0x10

typedef struct SelectableTarget {
    /* 0x00 */ s16 actorID;
    /* 0x02 */ s16 partID; /* sometimes loaded as byte from 0x3 */
    /* 0x04 */ Vec3s pos;
    /* 0x0A */ char unk_0A[7];
    /* 0x11 */ u8 homeCol; /* from xpos --> 0-3 */
    /* 0x12 */ u8 homeRow; /* from ypos --> 0-3 */
    /* 0x13 */ u8 layer; /* from zpos? --> 0-1 */
} SelectableTarget; // size = 0x14

typedef struct ActorPartMovement {
    /* 0x00 */ char unk_00[12];
    /* 0x0C */ Vec3f goalPos;
    /* 0x18 */ char unk_18[12];
    /* 0x24 */ f32 jumpScale;
    /* 0x28 */ f32 moveSpeed;
    /* 0x2C */ char unk_2C[32];
    /* 0x4C */ s32 varTable[16];
} ActorPartMovement; // size = 0x8C

typedef struct ActorPart {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 targetFlags; /* initialized to 0 */
    /* 0x08 */ struct ActorPartDesc* staticData;
    /* 0x0C */ struct ActorPart* nextPart;
    /* 0x10 */ struct ActorPartMovement* movement;
    /* 0x14 */ Vec3s partOffset;
    /* 0x1A */ Vec3s visualOffset;
    /* 0x20 */ Vec3f partOffsetFloat;
    /* 0x2C */ Vec3f absolutePosition;
    /* 0x38 */ Vec3f rotation;
    /* 0x44 */ Vec3s rotationPivotOffset;
    /* 0x4A */ char unk_4A[2];
    /* 0x4C */ Vec3f scale;
    /* 0x58 */ Vec3f currentPos;
    /* 0x64 */ f32 yaw;
    /* 0x68 */ s16 unkOffset[2];
    /* 0x6C */ Vec2s targetOffset;
    /* 0x70 */ s16 unk_70;
    /* 0x72 */ Vec2bu size;
    /* 0x74 */ u8 verticalStretch;
    /* 0x75 */ s8 unk_75;
    /* 0x76 */ s8 unk_76;
    /* 0x77 */ char unk_77[1];
    /* 0x78 */ u32* defenseTable;
    /* 0x7C */ s32 eventFlags;
    /* 0x80 */ s32 partFlags3;
    /* 0x84 */ s32 unk_84;
    /* 0x88 */ s32 currentAnimation;
    /* 0x8C */ s32 unk_8C;
    /* 0x90 */ f32 animationRate;
    /* 0x94 */ u32* idleAnimations;
    /* 0x98 */ s16 opacity;
    /* 0x9A */ char unk_9A[2];
    /* 0x9C */ s32 shadowIndex;
    /* 0xA0 */ f32 shadowScale;
    /* 0xA4 */ s32 partTypeData[6];
    /* 0xBC */ s16 actorTypeData2b[2];
    /* 0xC0 */ struct DecorationTable* decorationTable; /* initialized to 0 */
} ActorPart; // size = 0xC4

typedef struct ColliderTriangle {
    /* 0x00 */ Vec3f* v1; /* note: the order of v1,2,3 is reversed from the ijk in the hit file */
    /* 0x04 */ Vec3f* v2;
    /* 0x08 */ Vec3f* v3;
    /* 0x0C */ Vec3f e13; /* = v3 - v1 */
    /* 0x18 */ Vec3f e21; /* = v1 - v2 */
    /* 0x24 */ Vec3f e32; /* = v2 - v3 */
    /* 0x30 */ Vec3f normal;
    /* 0x3C */ s16 oneSided; /* 1 = yes, 0 = no */
    /* 0x3E */ char unk_3E[2];
} ColliderTriangle; // size = 0x40

typedef struct StaticPartner {
    /* 0x00 */ s32 dmaStart;
    /* 0x04 */ s32 dmaEnd;
    /* 0x08 */ s32 dmaDest;
    /* 0x0C */ s32 isFlying;
    /* 0x10 */ UNK_FUN_PTR(fpInit);
    /* 0x14 */ Bytecode* spScriptA;
    /* 0x18 */ Bytecode* spScriptB;
    /* 0x1C */ Bytecode* spScriptC;
    /* 0x20 */ Bytecode* spScriptD;
    /* 0x24 */ s32 idleAnim;
    /* 0x28 */ UNK_FUN_PTR(fpFuncA);
    /* 0x2C */ UNK_FUN_PTR(fpFuncB);
    /* 0x30 */ UNK_FUN_PTR(fpFuncC);
    /* 0x34 */ UNK_FUN_PTR(fpFuncD);
    /* 0x38 */ UNK_FUN_PTR(fpFuncE);
    /* 0x3C */ Bytecode* spScriptX;
} StaticPartner; // size = 0x40

typedef struct FontRasterSet {
    /* 0x00 */ u8 sizeX;
    /* 0x01 */ u8 sizeY;
    /* 0x02 */ char unk_02[10];
} FontRasterSet; // size = 0x0C

typedef s32 (*TriggerHandlerFunc)(Trigger*);

typedef struct TriggerDefinition {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s16 colliderIndex;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ s32 flagIndex;
    /* 0x0C */ TriggerHandlerFunc function;
    /* 0x10 */ char unk_10[4];
    /* 0x14 */ s32 unk_14;
    /* 0x18 */ s32 inputArg3;
    /* 0x1C */ s32 unk_1C;
} TriggerDefinition; // size = 0x20

typedef struct CollisionStatus {
    /* 0x00 */ s16 pushingAgainstWall; /* FFFF = none for all below VVV */
    /* 0x02 */ s16 currentFloor; /* valid on touch */
    /* 0x04 */ s16 lastTouchedFloor; /* valid after jump */
    /* 0x06 */ s16 floorBelow;
    /* 0x08 */ s16 currentCeiling; /* valid on touching with head */
    /* 0x0A */ s16 unk_0A;
    /* 0x0C */ s16 unk_0C;
    /* 0x0E */ s16 unk_0E;
    /* 0x10 */ s16 unk_10;
    /* 0x12 */ s16 currentWall;
    /* 0x14 */ s16 lastWallHammered; /* valid when smashing */
    /* 0x16 */ s16 touchingWallTrigger; /* 0/1 */
    /* 0x18 */ s16 bombetteExploded; /* 0 = yes, FFFF = no */
    /* 0x1A */ char unk_1A[2];
    /* 0x1C */ Vec3f bombetteExplosionPos;
} CollisionStatus; // size = 0x28

typedef struct DecorationUnk {
    /* 0x00 */ s16 unk00;
    /* 0x04 */ s16 unk04;
    /* 0x08 */ s16 unk08;
    /* 0x0C */ s16 unk0C;
    /* 0x10 */ s16 unk10;
    /* 0x14 */ s16 unk14;
    /* 0x18 */ s16 unk18;
    /* 0x1C */ s16 unk1C;
} DecorationUnk; // size = 0x20

typedef struct DecorationTable {
    /* 0x000 */ char unk_00[0x6C0];
    /* 0x6C0 */ s8 unk_6C0;
    /* 0x6C1 */ s8 unk_6C1;
    /* 0x6C2 */ s8 unk_6C2;
    /* 0x6C3 */ char unk_6C3[10];
    /* 0x6CD */ s8 unk_6CD;
    /* 0x6CE */ char unk_6CE[6];
    /* 0x6D4 */ s32* unk_6D4;
    /* 0x6D8 */ char unk_6D8[120];
    /* 0x750 */ s8 unk_750;
    /* 0x751 */ s8 unk_751;
    /* 0x752 */ s8 unk_752;
    /* 0x753 */ char unk_753[17];
    /* 0x764 */ s8 unk_764;
    /* 0x765 */ s8 unk_765;
    /* 0x766 */ s8 unk_766;
    /* 0x767 */ s8 unk_767;
    /* 0x768 */ s8 unk_768;
    /* 0x769 */ char unk_769[3];
    /* 0x76C */ s16 unk_76C[16];
    /* 0x78C */ char unk_78C[76];
    /* 0x7D8 */ s8 unk_7D8;
    /* 0x7D9 */ s8 unk_7D9;
    /* 0x7DA */ char unk_7DA;
    /* 0x7DB */ s8 unk_7DB;
    /* 0x7DC */ s16 scale[16];
    /* 0x7FC */ s16 posX[16];
    /* 0x81C */ s16 posY[16];
    /* 0x83C */ s16 posZ[16];
    /* 0x85C */ u8 rotationPivotOffsetX[16];
    /* 0x86C */ u8 rotationPivotOffsetY[16];
    /* 0x87C */ u8 rotX[16];
    /* 0x88C */ u8 rotY[16];
    /* 0x89C */ u8 rotZ[16];
    /* 0x8AC */ u8 effectType; /* 0 =  blur, 14 = none? */
    /* 0x8AD */ char unk_8AD[3];
    /* 0x8B0 */ struct Temp8025D160* unk_8B0[2];
    /* 0x8B8 */ s8 decorationType[2];
    /* 0x8BA */ u8 unk_8BA[2];
    /* 0x8BC */ u8 unk_8BC[2];
    /* 0x8C0 */ s16 unk_8C0[4];
    /* 0x8C6 */ DecorationUnk unk_8C6[2];
} DecorationTable; // size = 0x8E8

typedef struct ShopOwner {
    /* 0x00 */ s32 npcID;
    /* 0x04 */ s32 idleAnim;
    /* 0x08 */ s32 talkAnim;
    /* 0x0C */ char unk_0C[0x4];
    /* 0x10 */ Bytecode* unkScript;
    /* 0x14 */ char unk_14[0x4];
    /* 0x18 */ s32* shopMsgIDs;
} ShopOwner;

typedef struct ShopItemLocation {
    /* 0x0 */ s16 posModelID;
    /* 0x2 */ s16 triggerColliderID;
} ShopItemLocation; // size = 0x4

typedef struct StaticInventoryItem {
    /* 0x0 */ s32 unk_00;
    /* 0x4 */ s32 price;
    /* 0x8 */ s32 unk_08;
} StaticInventoryItem; // size = 0xC

typedef struct StaticPriceItem {
    /* 0x0 */ s32 itemID;
    /* 0x4 */ s32 sellPrice;
    /* 0x8 */ char unk_08[0x4];
} StaticPriceItem; // size = 0xC

typedef struct PopupMenu {
    /* 0x000 */ s32* ptrIcon[32];
    /* 0x080 */ char unk_80[4];
    /* 0x084 */ s32 nameMsg[32];
    /* 0x104 */ char unk_104[4];
    /* 0x108 */ s32 userIndex[32]; // used to map menu order to a user-ID for each item
    /* 0x188 */ char unk_188[4];
    /* 0x18C */ s32 enabled[32];
    /* 0x20C */ char unk_20C[4];
    /* 0x210 */ s32 value[32]; // sale price, etc
    /* 0x290 */ char unk_290[4];
    /* 0x294 */ s32 descMsg[32];
    /* 0x314 */ char unk_314[4];
    /* 0x318 */ s32 popupType; // C = keys
    /* 0x31C */ s32 unk_31C;
    /* 0x320 */ s32 unk_320;
    /* 0x324 */ s32 numEntries;
    /* 0x328 */ s32 initialPos;
    /* 0x32C */ s16 result;
    /* 0x32E */ char unk_32E[0x2];
} PopupMenu; // size = 0x330

typedef struct Shop {
    /* 0x000 */ s16 flags;
    /* 0x002 */ s16 numItems;
    /* 0x004 */ s16 numSpecialPrices;
    /* 0x006 */ char unk_06[2];
    /* 0x008 */ s32 currentItemSlot;
    /* 0x00C */ s32 selectedStoreItemSlot;
    /* 0x010 */ ShopOwner* owner;
    /* 0x014 */ ShopItemLocation* staticItemPositions;
    /* 0x018 */ StaticInventoryItem* staticInventory;
    /* 0x01C */ StaticPriceItem* staticPriceList;
    /* 0x020 */ s32 costIconID;
    /* 0x024 */ s32 inventoryItemFlags;
    /* 0x028 */ PopupMenu itemSelectMenu;
    /* 0x358 */ s32 unk_358;
} Shop; // size = 0x35C

typedef struct Encounter {
    /* 0x00 */ s32 count;
    /* 0x04 */ struct Enemy* enemy[16];
    /* 0x44 */ u16 battle;
    /* 0x46 */ s16 stage;
    /* 0x48 */ s16 encounterID;
    /* 0x4A */ char unk_4C[0x12];
} Encounter; // size = 0x5C

typedef struct PlayerPathElement {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ Vec3f pos;
} PlayerPathElement; // size = 0x10

typedef struct AnimatedModel {
    /* 0x00 */ s32 animModelID;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f rot;
    /* 0x1C */ Vec3f scale;
    /* 0x28 */ Mtx mtx;
    /* 0x68 */ u32 currentAnimData;
    /* 0x6C */ char unk_6C[4];
} AnimatedModel; // size = 0x70

typedef AnimatedModel* AnimatedModelList[MAX_ANIMATED_MODELS];

typedef struct CollisionHeader {
    /* 0x00 */ s16 numColliders;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ s32 treeOffset;
    /* 0x08 */ s16 numVerts;
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ s32 triangleTableOffset;
    /* 0x10 */ s16 bbTableSize;
    /* 0x12 */ char unk_12[2];
    /* 0x14 */ s32 bbTableOffset;
    /* 0x18 */ char unk_18[8];
} CollisionHeader; // size = 0x20

typedef struct ActorMovement {
    /* 0x00 */ Vec3f currentPos;
    /* 0x0C */ Vec3f goalPos;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ char unk_24[24];
    /* 0x3C */ f32 acceleration;
    /* 0x40 */ f32 speed;
    /* 0x44 */ f32 velocity;
    /* 0x48 */ f32 angle;
    /* 0x4C */ f32 distance;
} ActorMovement; // size = 0x50;

typedef struct ChompChainAnimationState {
    /* 0x00 */ Vec3f currentPos;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ Vec3f scale;
} ChompChainAnimationState; // size = 0x30

typedef struct ActorState { // TODO: Make the first field of this an ActorMovement
    /* 0x00 */ Vec3f currentPos;
    /* 0x0C */ Vec3f goalPos;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ char unk_24[24];
    /* 0x3C */ f32 acceleration;
    /* 0x40 */ f32 speed;
    /* 0x44 */ f32 velocity;
    /* 0x48 */ f32 angle;
    /* 0x4C */ f32 distance;
    /* 0x50 */ f32 bounceDivisor;
    /* 0x54 */ char unk_54[0x4];
    /* 0x58 */ s32 animJumpRise;
    /* 0x5C */ s32 animJumpFall;
    /* 0x60 */ s32 animJumpLand;
    /* 0x64 */ s16 moveTime;
    /* 0x66 */ s16 moveArcAmplitude;
    /* 0x68 */ char unk_68[3];
    /* 0x6B */ u8 jumpPartIndex;
    /* 0x6C */ ChompChainAnimationState* unk_6C;
    /* 0x70 */ char unk_70[12];
    /* 0x7C */ s32 varTable[16];
} ActorState; // size = 0xBC;

typedef struct Actor {
    /* 0x000 */ s32 flags;
    /* 0x004 */ char unk_04[4];
    /* 0x008 */ struct ActorDesc* staticActorData;
    /* 0x00C */ ActorState state;
    /* 0x0C8 */ ActorMovement fly;
    /* 0x118 */ f32 flyElapsed;
    /* 0x11C */ char unk_11C[4];
    /* 0x120 */ s16 flyTime;
    /* 0x122 */ s16 flyArcAmplitude;
    /* 0x124 */ char unk_124[17];
    /* 0x135 */ u8 footStepCounter;
    /* 0x136 */ u8 actorType;
    /* 0x137 */ char unk_137;
    /* 0x138 */ Vec3f homePos;
    /* 0x144 */ Vec3f currentPos;
    /* 0x150 */ Vec3s headOffset;
    /* 0x156 */ Vec3s healthBarPosition;
    /* 0x15C */ Vec3f rotation;
    /* 0x168 */ Vec3s rotationPivotOffset;
    /* 0x16E */ char unk_16E[2];
    /* 0x170 */ Vec3f scale;
    /* 0x17C */ Vec3f scaleModifier; /* multiplies normal scale factors componentwise */
    /* 0x188 */ f32 scalingFactor;
    /* 0x18C */ f32 yaw;
    /* 0x190 */ Vec2bu size;
    /* 0x192 */ s16 actorID;
    /* 0x194 */ s8 unk_194;
    /* 0x195 */ s8 unk_195;
    /* 0x196 */ s8 unk_196;
    /* 0x197 */ s8 unk_197;
    /* 0x198 */ Vec2b unk_198;
    /* 0x19A */ s8 unk_19A;
    /* 0x19B */ char unk_19B[1];
    /* 0x19C */ s32 actorTypeData1[6]; /* 4 = jump sound, 5 = attack sound */ // TODO: struct
    /* 0x1B4 */ s16 actorTypeData1b[2];
    /* 0x1B8 */ s8 currentHP;
    /* 0x1B9 */ s8 maxHP;
    /* 0x1BA */ char unk_1BA[2];
    /* 0x1BC */ u8 hpFraction; /* used to render HP bar */
    /* 0x1BD */ char unk_1BD[3];
    /* 0x1C0 */ EvtSource* idleScriptSource;
    /* 0x1C4 */ EvtSource* takeTurnScriptSource;
    /* 0x1C8 */ EvtSource* onHitScriptSource;
    /* 0x1CC */ EvtSource* onTurnChanceScriptSource;
    /* 0x1D0 */ struct Evt* idleScript;
    /* 0x1D4 */ struct Evt* takeTurnScript;
    /* 0x1D8 */ struct Evt* onHitScript;
    /* 0x1DC */ struct Evt* onTurnChangeScript;
    /* 0x1E0 */ s32 idleScriptID;
    /* 0x1E4 */ s32 takeTurnID;
    /* 0x1E8 */ s32 onHitID;
    /* 0x1EC */ s32 onTurnChangeID;
    /* 0x1F0 */ s8 lastEventType;
    /* 0x1F1 */ s8 turnPriority;
    /* 0x1F2 */ u8 enemyIndex; /* actorID = this | 200 */
    /* 0x1F3 */ u8 numParts;
    /* 0x1F4 */ struct ActorPart* partsTable;
    /* 0x1F8 */ s16 lastDamageTaken;
    /* 0x1FA */ u16 hpChangeCounter;
    /* 0x1FC */ s16 damageCounter;
    /* 0x1FE */ char unk_1FE[2];
    /* 0x200 */ s32** unk_200; // Probably a struct but not sure what yet
    /* 0x204 */ s8 unk_204;
    /* 0x205 */ char unk_205[0x1];
    /* 0x206 */ s8 unk_206;
    /* 0x207 */ s8 extraCoinBonus;
    /* 0x208 */ s8 unk_208;
    /* 0x209 */ char unk_209[3];
    /* 0x20C */ struct DictionaryEntry* statusTable;
    /* 0x210 */ s8 debuff;
    /* 0x211 */ s8 debuffDuration;
    /* 0x212 */ s8 staticStatus; /* 0B = yes */
    /* 0x213 */ s8 staticDuration;
    /* 0x214 */ s8 stoneStatus; /* 0C = yes */
    /* 0x215 */ s8 stoneDuration;
    /* 0x216 */ s8 koStatus; /* 0D = yes */
    /* 0x217 */ s8 koDuration;
    /* 0x218 */ s8 transStatus; /* 0E = yes */
    /* 0x219 */ s8 transDuration;
    /* 0x21A */ char unk_21A[2];
    /* 0x21C */ u8 status;
    /* 0x21D */ char unk_21D[3];
    /* 0x220 */ s8 isGlowing;
    /* 0x221 */ s8 attackBoost;
    /* 0x222 */ s8 defenseBoost;
    /* 0x223 */ s8 chillOutAmount; /* attack reduction */
    /* 0x224 */ s8 chillOutTurns;
    /* 0x225 */ char unk_225[3];
    /* 0x228 */ struct EffectInstance* unk_228;
    /* 0x22C */ struct SelectableTarget targetData[24];
    /* 0x40C */ s8 targetListLength;
    /* 0x40D */ s8 targetIndexList[24]; /* into targetData */
    /* 0x425 */ s8 selectedTargetIndex; /* into target index list */
    /* 0x426 */ s8 targetPartIndex;
    /* 0x427 */ char unk_427;
    /* 0x428 */ s16 targetActorID;
    /* 0x42A */ char unk_42A[2];
    /* 0x42C */ struct Shadow* shadow; /* might be shadow ID */
    /* 0x430 */ f32 shadowScale; /* = actor size / 24.0 */
    /* 0x434 */ s16 renderMode; /* initially 0xD, set to 0x22 if any part is transparent */
    /* 0x436 */ s16 hudElementDataIndex;
    /* 0x438 */ s32 x[2]; /* ??? see FUN_80253974 */
    /* 0x440 */ struct HudElement* ptrDefuffIcon;
} Actor; // size = 0x444

typedef struct BackgroundHeader {
    /* 0x00 */ void* raster;
    /* 0x04 */ void* palette;
    /* 0x08 */ u16 startX;
    /* 0x0A */ u16 startY;
    /* 0x0C */ u16 width;
    /* 0x0E */ u16 height;
} BackgroundHeader; // size = 0x10

typedef struct FontData {
    /* 0x00 */ char unk_00[24];
} FontData; // size = 0x18

typedef struct PlayerStatus {
    /* 0x000 */ s32 flags;
    /* 0x004 */ u32 animFlags;
    /* 0x008 */ s16 framesOnGround; /* Number of frames since last jump landed */
    /* 0x00A */ char unk_0A[2];
    /* 0x00C */ s8 peachDisguise;
    /* 0x00D */ s8 unk_0D;
    /* 0x00E */ u8 alpha1;
    /* 0x00F */ u8 alpha2;
    /* 0x010 */ s16 unk_10;
    /* 0x012 */ s16 moveFrames;
    /* 0x014 */ s8 enableCollisionOverlapsCheck;
    /* 0x015 */ s8 statusMenuCounterinputEnabledCounter; /* whether the C-up menu can appear */
    /* 0x016 */ Vec3s lastGoodPosition;
    /* 0x01C */ Vec3f extraVelocity;
    /* 0x028 */ Vec3f position;
    /* 0x034 */ char unk_34[8];
    /* 0x03C */ f32 unk_3C;
    /* 0x040 */ f32 unk_40;
    /* 0x044 */ f32 decorationPos[2];
    /* 0x04C */ f32 unk_4C;
    /* 0x050 */ f32 jumpApexHeight;
    /* 0x054 */ f32 currentSpeed;
    /* 0x058 */ f32 walkSpeed;
    /* 0x05C */ f32 runSpeed;
    /* 0x060 */ s32 unk_60;
    /* 0x064 */ f32 unk_64;
    /* 0x068 */ f32 normalPitch;
    /* 0x06C */ f32 unk_6C;
    /* 0x070 */ f32 gravityIntegrator[4];
    /* 0x080 */ f32 targetYaw;
    /* 0x084 */ f32 currentYaw;
    /* 0x088 */ f32 unk_88;
    /* 0x08C */ f32 unk_8C;
    /* 0x090 */ f32 unk_90;
    /* 0x094 */ s32 unk_94;
    /* 0x098 */ s32 unk_98;
    /* 0x09C */ s32 unk_9C;
    /* 0x0A0 */ f32 heading;
    /* 0x0A4 */ s32 trueAnimation; ///< Encoding back-facing sprite
    /* 0x0A8 */ f32 spriteFacingAngle; /* angle of sprite, relative to camera, from 0 to 180 */
    /* 0x0AC */ char unk_AC[4];
    /* 0x0B0 */ s16 colliderHeight;
    /* 0x0B2 */ s16 colliderDiameter;
    /* 0x0B4 */ s8 actionState;
    /* 0x0B5 */ s8 prevActionState;
    /* 0x0B6 */ s8 fallState; ///< Also used as sleep state in Peach idle action
    /* 0x0B7 */ char unk_B7;
    /* 0x0B8 */ u32 anim;
    /* 0x0BC */ u16 unk_BC;
    /* 0x0BE */ s8 renderMode;
    /* 0x0BF */ s8 unk_BF;
    /* 0x0C0 */ s16 decorationList;
    /* 0x0C2 */ s16 unk_C2;
    /* 0x0C4 */ char unk_C4;
    /* 0x0C5 */ s8 unk_C5;
    /* 0x0C6 */ s16 unk_C6;
    /* 0x0C8 */ s32* unk_C8;
    /* 0x0CC */ s32 shadowID;
    /* 0x0D0 */ f32* unk_D0;
    /* 0x0D4 */ f32 unk_D4;
    /* 0x0D8 */ UNK_PTR** unk_D8;
    /* 0x0DC */ s32 currentButtons;
    /* 0x0E0 */ s32 pressedButtons;
    /* 0x0E4 */ s32 heldButtons;
    /* 0x0E8 */ s32 stickAxis[2];
    /* 0x0F0 */ s32 currentButtonsBuffer[10];
    /* 0x118 */ s32 pressedButtonsBuffer[10];
    /* 0x140 */ s32 heldButtonsBuffer[10];
    /* 0x168 */ s32 stickXBuffer[10];
    /* 0x190 */ s32 stickYBuffer[10];
    /* 0x1B8 */ s32 inputBufPos;
    /* 0x1BC */ char unk_1BC[196];
    /* 0x280 */ s8 unk_280;
    /* 0x281 */ char unk_281[7];
} PlayerStatus; // size = 0x288

typedef struct EncounterStatus {
    /* 0x000 */ s32 flags;
    /* 0x004 */ s8 eFirstStrike; /* 0 = none, 1 = player, 2 = enemy */
    /* 0x005 */ s8 hitType; /* 1 = none/enemy, 2 = jump */
    /* 0x006 */ s8 hitTier; /* 0 = normal, 1 = super, 2 = ultra */
    /* 0x007 */ char unk_07;
    /* 0x008 */ s8 unk_08;
    /* 0x009 */ s8 battleOutcome; /* 0 = won, 1 = lost */
    /* 0x00A */ s8 unk_0A;
    /* 0x00B */ s8 merleeCoinBonus; /* triple coins when != 0 */
    /* 0x00C */ u8 damageTaken; /* valid after battle */
    /* 0x00D */ char unk_0D;
    /* 0x00E */ s16 coinsEarned; /* valid after battle */
    /* 0x010 */ char unk_10;
    /* 0x011 */ u8 allowFleeing;
    /* 0x012 */ s8 unk_12;
    /* 0x013 */ u8 dropWhackaBump;
    /* 0x014 */ s32 songID;
    /* 0x018 */ s32 unk_18;
    /* 0x01C */ s8 numEncounters; /* number of encounters for current map (in list) */
    /* 0x01D */ s8 currentAreaIndex;
    /* 0x01E */ u8 currentMapIndex;
    /* 0x01F */ u8 currentEntryIndex;
    /* 0x020 */ s8 mapID;
    /* 0x021 */ s8 resetMapEncounterFlags;
    /* 0x021 */ char unk_22[2];
    /* 0x024 */ s32* npcGroupList;
    /* 0x028 */ struct Encounter* encounterList[24];
    /* 0x088 */ struct Encounter* currentEncounter;
    /* 0x08C */ struct Enemy* currentEnemy;
    /* 0x090 */ s32 fadeOutAmount;
    /* 0x094 */ s32 unk_94;
    /* 0x098 */ s32 fadeOutAccel;
    /* 0x09C */ s32 battleStartCountdown;
    /* 0x0A0 */ char unk_A0[16];
    /* 0x0B0 */ s32 defeatFlags[60][12];
    /* 0xFB0 */ s16 recentMaps[2];
    /* 0xFB4 */ char unk_FB4[4];
} EncounterStatus; // size = 0xFB8

typedef struct SaveData {
    /* 0x0000 */ char magicString[16]; /* "Mario Story 006" string */
    /* 0x0010 */ s8 pad[32]; /* always zero */
    /* 0x0030 */ s32 crc1;
    /* 0x0034 */ s32 crc2;
    /* 0x0038 */ s32 saveSlot;
    /* 0x003C */ u32 saveCount;
    /* 0x0040 */ PlayerData player;
    /* 0x0380 */ char unk_380[0xE0];
    /* 0x0460 */ s32 starPoints;
    /* 0x0464 */ char unk_464[4];
    /* 0x0468 */ s16 areaID;
    /* 0x046A */ s16 mapID;
    /* 0x046C */ s16 entryID;
    /* 0x046E */ char unk_46E[2];
    /* 0x0470 */ s32 enemyDefeatFlags[720];
    /* 0x0FB0 */ s32 globalFlags[64];
    /* 0x10B0 */ s8 globalBytes[512];
    /* 0x12B0 */ s32 areaFlags[8];
    /* 0x12D0 */ s8 areaBytes[16];
    /* 0x12E0 */ char unk_12E0[6];
    /* 0x12E6 */ Vec3s savePos;
    /* 0x12EC */ s32 unk_12EC;
    /* 0x12F0 */ s8 unk_12F0[12]; /* player name starts at 4th char */
    /* 0x12FC */ s32 unk_12FC;
    /* 0x1300 */ s32 unk_1300;
    /* 0x1304 */ char unk_1304[0x7C];
} SaveData; // size = 0x1380

typedef struct {
    /* 0x00 */ s32 numVectors;
    /* 0x04 */ s32 unk_04;
    /* 0x08 */ Vec3f* staticVectorList;
    /* 0x0C */ Vec3f* vectors;
    /* 0x10 */ s32 timeElapsed;
    /* 0x14 */ s32 timeLeft;
    /* 0x18 */ s32 easingType;
} Path; // size = 0x1C

typedef struct {
    /* 0x00 */ u8 enabled;
    /* 0x01 */ u8 listStart;
    /* 0x02 */ u8 numCols;
    /* 0x03 */ u8 numRows;
    /* 0x04 */ s32 startIndex;
    /* 0x08 */ s32 count;
} PauseItemPage; // size = 0xC

typedef struct PauseMapSpace {
    /* 0x00 */ Vec2s pos;
    /* 0x04 */ u8 parent;
    /* 0x05 */ u8 pathLength;
    /* 0x06 */ s16 unk_06; // always 0
    /* 0x08 */ Vec2b* path;
    /* 0x0C */ s32 afterRequirement;
    /* 0x10 */ s32 id;
} PauseMapSpace; // size = 0x14

typedef struct MenuPanel {
    /* 0x00 */ u8 initialized; //?
    /* 0x01 */ s8 col;
    /* 0x02 */ s8 row;
    /* 0x03 */ u8 selected; // usually set to the current value from gridData
    /* 0x04 */ s8 page; // filemenu: 0 = select, 1 = delete, 3 = copy from, 4 = copy to, all else = save
    /* 0x05 */ s8 numCols;
    /* 0x06 */ s8 numRows;
    /* 0x07 */ s8 numPages; // unsure
    /* 0x08 */ u8* gridData; // user value at each 3D grid point (page, row, col)
    /* 0x0C */ UNK_FUN_PTR(fpInit);
    /* 0x10 */ UNK_FUN_PTR(fpHandleInput);
    /* 0x14 */ UNK_FUN_PTR(fpUpdate);
    /* 0x18 */ UNK_FUN_PTR(fpCleanup);
} MenuPanel; // size = 0x1C

typedef struct WindowBackground {
    /* 0x00 */ s32* imgData;
    /* 0x04 */ s8 packedTileFormat; // upper = fmt, lower = depth; e.g., 31 = CI-8
    /* 0x05 */ s8 width;
    /* 0x06 */ s8 height;
    /* 0x07 */ char unk_07[4];
    /* 0x0B */ s8 size;
} WindowBackground; // size = 0xC

typedef struct WindowCorners {
    /* 0x00 */ s32* imgData;
    /* 0x04 */ s8 packedTileFormat; // upper = fmt, lower = depth; e.g., 31 = CI-8
    /* 0x05 */ Vec2b size1;
    /* 0x07 */ Vec2b size2;
    /* 0x09 */ Vec2b size3;
    /* 0x0B */ Vec2b size4;
    /* 0x0D */ char unk_0D[3];
} WindowCorners; // size = 0x10

typedef struct WindowStyleCustom {
    /* 0x00 */ WindowBackground background;
    /* 0x0C */ WindowCorners corners;
    /* 0x1C */ char unk_1C[0x4];
    /* 0x20 */ s32 opaqueCombineMode[2]; // used when alpha == 255
    /* 0x28 */ s32 transparentCombineMode[2]; // used when alpha < 255
    /* 0x30 */ s8 color1[4];
    /* 0x34 */ s8 color2[4];
} WindowStyleCustom; // size = 0x38;

typedef struct MenuWindowBP {
    /* 0x00 */ s8 windowID;
    /* 0x01 */ char unk_01;
    /* 0x02 */ Vec2s pos;
    /* 0x06 */ s16 height;
    /* 0x08 */ s16 width; // switch? ^
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ UNK_FUN_PTR(fpDrawContents);
    /* 0x10 */ MenuPanel* tab;
    /* 0x14 */ s32 parentID;
    /* 0x18 */ UNK_FUN_PTR(fpUpdate);
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ WindowStyleCustom* style;
} MenuWindowBP; // size = 0x24;

typedef struct {
    /* 0x00 */ u8 flags;
    /* 0x01 */ s8 panelID; // ?
    /* 0x02 */ s8 unk_02; // related to heirarchy somehow - sibling? group?
    /* 0x03 */ s8 parent; // ?
    /* 0x04 */ UNK_FUN_PTR(fpUpdate);
    /* 0x08 */ UNK_FUN_PTR(fpPending);
    /* 0x0C */ Vec2s pos;
    /* 0x10 */ s16 width;
    /* 0x12 */ s16 height;
    /* 0x14 */ UNK_FUN_PTR(fpDrawContents);
    /* 0x18 */ s32 drawContentsArg0;
    /* 0x1C */ u8 updateCounter;
    /* 0x1D */ char unk_1D[3];
} Window; // size = 0x20

// BEGIN ENTITY-SPECIFIC STRUCTS

typedef struct struct802E2BA4 {
    /* 0x00 */ char unk_00[2];
    /* 0x02 */ u16 unk_02[24][2];
} struct802E2BA4;

// from 102c80, size unknown.
typedef struct struct802E1400 {
    /* 0x000 */ Vec3f unk_00;
    /* 0x00C */ char unk_0C[4];
    /* 0x010 */ s8 unk_10;
    /* 0x011 */ s8 unk_11;
    /* 0x014 */ Vec3f unk_14;
    /* 0x020 */ u16 unk_20;
    /* 0x022 */ s16 unk_22;
    /* 0x024 */ s16 unk_24;
    /* 0x028 */ Entity* attachedEntity;
    /* 0x02C */ char unk_2C[8];
    /* 0x034 */ struct802E2BA4* unk_34;
    /* 0x038 */ f32 unk_38;
    /* 0x03C */ union {
        /*       */     s16 s;
        /*       */     s8 b[2];
    } unk_3C;
    /* 0x03E */ char unk_3E[0x4D];
    /* 0x08B */ u8 unk_8B[24];
    /* 0x0A3 */ char unk_A3; // padding?
    /* 0x0A4 */ u8 unk_A4[24];
    /* 0x0BC */ char unk_BC[4];
    /* 0x0C0 */ f32 unk_C0[24];
    /* 0x120 */ char unk_120[4];
    /* 0x124 */ f32 unk_124[24];
    /* 0x184 */ char unk_184[4];
    /* 0x188 */ f32 unk_188[24];
} struct802E1400;

// from 104940_len_dc0, size unknown
// appears to belong to the hammer blocks(?)
typedef struct struct802E3650 {
    /* 0x000 */ u8 unk_00;
    /* 0x001 */ char unk_01[2];
    /* 0x003 */ s8 unk_03;
    /* 0x004 */ s16 unk_04;
    /* 0x006 */ s16 unk_06;
    /* 0x008 */ char unk_08[2];
    /* 0x00A */ u16 unk_0A;
    /* 0x00C */ char unk_0C[2];
    /* 0x00E */ s16 unk_0E;
    /* 0x010 */ s16 unk_10;
    /* 0x012 */ s16 unk_12;
    /* 0x014 */ f32 unk_14;
    /* 0x018 */ f32 unk_18;
    /* 0x01C */ char unk_1C[0x10C];
    /* 0x128 */ UNK_PTR unk_128;
    /* 0x12C */ UNK_PTR unk_12C;
} struct802E3650;

// size unknown
typedef struct struct802E4B10 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ s8 unk_02;
    /* 0x03 */ s8 unk_03;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ char unk_08;
    /* 0x09 */ u8 unk_09;
    /* 0x0A */ u8 unk_0A;
    /* 0x0B */ char unk_0B; // padding?
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ s32 unk_10;
    /* 0x14 */ f32 unk_14;
    /* 0x18 */ f32 unk_18;
    /* 0x1C */ f32 unk_1C;
    /* 0x20 */ f32 unk_20;
    /* 0x24 */ u16 unk_24;
    /* 0x24 */ s16 unk_26;
    /* 0x28 */ f32 unk_28[0xB];
    /* 0x54 */ f32 unk_54;
    /* 0x58 */ char unk_58[0x78];
    /* 0xD0 */ u16 unk_D0;
    /* 0xD4 */ f32 unk_D4[0];
} struct802E4B10;

// END ENTITY-SPECIFIC STRUCTS

typedef struct {
    /* 0x00000 */ LookAt lookAt[2];
    /* 0x00030 */ Matrix4s camPerspMatrix[8]; // could only be length 4, unsure
    /* 0x00230 */ Gfx mainGfx[0x2080];
    /* 0x10630 */ Gfx backgroundGfx[0x200]; // used by gfx_task_background
    /* 0x11630 */ Mtx matrixStack[0x200];
} DisplayContext; // size = 0x19630

typedef struct Temp8010F250 {
    /* 0x00 */ s8 unk_00;
    /* 0x01 */ s8 unk_01;
    /* 0x02 */ char unk_02[5];
    /* 0x07 */ s8 unk_07;
    /* 0x08 */ s32 unk_08;
    /* 0x0C */ s32 unk_0C;
    /* 0x10 */ char unk_10[0x20];
    /* 0x30 */ s32 unk_30;
} Temp8010F250; // size = 0x34

typedef struct PartnerActionStatus {
    /* 0x000 */ union {
        /*       */     s32 i;
        /*       */     s8 b[4];
    } actionState;
    /* 0x004 */ s16 stickX;
    /* 0x006 */ s16 stickY;
    /* 0x008 */ s32 currentButtons;
    /* 0x00C */ s32 pressedButtons;
    /* 0x010 */ s32 heldButtons;
    /* 0x014 */ s8 inputDisabled;
    /* 0x015 */ char unk_15[3];
    /* 0x018 */ Npc npc;
    /* 0x358 */ s32 unk_358;
    /* 0x35C */ char unk_35C[0x4];
} PartnerActionStatus; // size = 0x360

typedef struct Temp8025D160 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ char unk_04[8];
    /* 0x0C */ struct Temp8025D160_2* unk_0C;
} Temp8025D160; // size = 0x10 (?)

typedef struct Temp8025D160_2 {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ f32 unk_04;
    /* 0x08 */ f32 unk_08;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ char unk_10[12];
    /* 0x1C */ s32 unk_1C;
    /* 0x20 */ s32 unk_20;
    /* 0x24 */ char unk_24[8];
    /* 0x2C */ s32 unk_2C;
    /* 0x30 */ s32 unk_30;
    /* 0x34 */ f32 unk_34;
} Temp8025D160_2; // size = 0x38 (?)

typedef struct EntityModel {
    /* 0x00 */ s32 flags;
    /* 0x04 */ u8 renderMode;
    /* 0x05 */ u8 unk_05;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ u8 unk_07;
    /* 0x08 */ f32 nextFrameTime; ///< Set to 1.0 after each update
    /* 0x0C */ f32 timeScale; ///< Default is 1.0
    /* 0x10 */ s32* cmdListReadPos;
    /* 0x14 */ Gfx* displayList;
    /* 0x18 */ Matrix4s transform;
    /* 0x58 */ s32* cmdListSavedPos;
    /* 0x5C */ Vtx* vertexArray;
    /* 0x60 */ UNK_FUN_PTR(fpSetupGfxCallback);
    /* 0x64 */ s32 setupGfxCallbackArg0;
} EntityModel; // size = 0x68

typedef EntityModel* EntityModelList[MAX_ENTITY_MODELS];

typedef struct VirtualEntity {
    /* 0x00 */ s32 entityModelIndex;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f rot;
    /* 0x1C */ Vec3f scale;
    /* 0x28 */ Vec3f goalPos;
    /* 0x34 */ f32 moveDist;
    /* 0x38 */ f32 moveAngle;
    /* 0x3C */ f32 moveSpeed;
    /* 0x40 */ f32 jumpGravity;
    /* 0x44 */ f32 jumpVelocity;
    /* 0x48 */ f32 moveTime;
} VirtualEntity; // size = 0x4C

typedef VirtualEntity* VirtualEntityList[0x40];

typedef struct TempSetZoneEnabled {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s16 id1;
    /* 0x06 */ s16 id2;
    /* 0x08 */ char unk_08[0x8];
    /* 0x10 */ CameraControlSettings* unk_10;
    /* 0x14 */ char unk_14[0x8];
} TempSetZoneEnabled; // size = 0x1C

typedef struct ActionCommandStatus {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ s32 hudElements[15];
    /* 0x40 */ char unk_40[0x4];
    /* 0x44 */ s16 barFillLevel;
    /* 0x46 */ s16 unk_46;
    /* 0x48 */ s16 unk_48;
    /* 0x4A */ s16 actionCommandID; // current action command id?
    /* 0x4C */ s16 state;
    /* 0x4E */ s16 unk_4E;
    /* 0x50 */ s16 unk_50;
    /* 0x52 */ s16 unk_52;
    /* 0x54 */ s16 unk_54;
    /* 0x56 */ s16 hudElementX;
    /* 0x58 */ s16 hudElementY;
    /* 0x5A */ s16 unk_5A;
    /* 0x5C */ s8 unk_5C;
    /* 0x5D */ s8 unk_5D;
    /* 0x5E */ s8 autoSucceed;
    /* 0x5F */ s8 unk_5F;
    /* 0x60 */ s8 unk_60;
    /* 0x61 */ s8 unk_61;
    /* 0x62 */ s8 unk_62;
    /* 0x63 */ s8 unk_63;
    /* 0x64 */ s16 unk_64;
    /* 0x66 */ s16 unk_66;
    /* 0x68 */ s16 unk_68;
    /* 0x6A */ s16 unk_6A;
    /* 0x6C */ s16 unk_6C;
    /* 0x6E */ s16 hitsTakenIsMax;
    /* 0x70 */ s16 unk_70;
    /* 0x72 */ s16 unk_72;
    /* 0x74 */ s16 mashMeterCutoffs[6]; // upper bounds for each interval
    /* 0x80 */ s8 mashMeterIntervals;
} ActionCommandStatus;

struct PopupMessage;
typedef void (*PopupMessageCallback)(struct PopupMessage* popup);
typedef struct PopupMessage {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ PopupMessageCallback updateFunc;
    /* 0x08 */ PopupMessageCallback unk_08;
    /* 0x0C */ PopupMessageCallback drawFunc;
    /* 0x10 */ s16 active;
    /* 0x12 */ s16 messageIndex;
    /* 0x14 */ s16 duration;
    /* 0x16 */ s8 unk_16;
    /* 0x17 */ s8 unk_17;
    /* 0x18 */ s32* message;
} PopupMessage; // size = 0x1C

typedef struct unkPartnerStruct {
    /* 0x000 */ s32 unk_00;
    /* 0x004 */ s32 unk_04;
    /* 0x008 */ s32 unk_08;
    /* 0x00c */ f32 unk_0C;
    /* 0x010 */ f32 unk_10;
    /* 0x014 */ f32 unk_14;
    /* 0x018 */ f32 unk_18;
} unkPartnerStruct; // size = 0x1C

typedef struct struct8015A578 {
    /* 0x00 */ u8 unk_00;
    /* 0x01 */ u8 unk_01;
    /* 0x02 */ u8 unk_02;
    /* 0x03 */ u8 unk_03[5];
    /* 0x08 */ f32 unk_08;
} struct8015A578; // size = 0x0C

#endif
