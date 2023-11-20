#ifndef _COMMON_STRUCTS_H_
#define _COMMON_STRUCTS_H_

#include "macros.h"
#include "ultra64.h"
#include "types.h"
#include "evt.h"
#include "enums.h"

struct Evt;

typedef ApiStatus(*ApiFunc)(struct Evt*, s32);

typedef Bytecode EvtScript[];

typedef void NoArgCallback(void*);

#define MSG_PTR u8*
#define IMG_PTR u8*
#define PAL_PTR u16*

#define MSG_BIN u8
#define IMG_BIN u8
#define PAL_BIN u16

typedef s32 b32;
typedef s16 b16;
typedef s8 b8;

typedef s32 HitID;
typedef u32 AnimID;

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

typedef struct Vec3b {
    /* 0x00 */ s8 x;
    /* 0x01 */ s8 y;
    /* 0x02 */ s8 z;
} Vec3b; // size = 0x03

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

typedef struct Vec2i {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
} Vec2i; // size = 0x08

typedef struct VecXZi {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 z;
} VecXZi; // size = 0x08

typedef struct Vec3i {
    /* 0x00 */ s32 x;
    /* 0x04 */ s32 y;
    /* 0x08 */ s32 z;
} Vec3i; // size = 0x0C

typedef struct Vec2f {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
} Vec2f; // size = 0x08

typedef struct VecXZf {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 z;
} VecXZf; // size = 0x08

typedef struct Vec3f {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
} Vec3f; // size = 0x0C

typedef struct Vec4f {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
    /* 0x0C */ f32 yaw;
} Vec4f; // size = 0x10

typedef struct Color4f {
    /* 0x00 */ f32 r;
    /* 0x04 */ f32 g;
    /* 0x08 */ f32 b;
    /* 0x0C */ f32 a;
} Color4f; // size = 0x10

typedef struct Color3i {
    /* 0x00 */ s32 r;
    /* 0x04 */ s32 g;
    /* 0x08 */ s32 b;
} Color3i; // size = 0xC

typedef struct Color4i {
    /* 0x00 */ s32 r;
    /* 0x04 */ s32 g;
    /* 0x08 */ s32 b;
    /* 0x0C */ s32 a;
} Color4i; // size = 0x10

typedef f32 Matrix4f[4][4]; // size = 0x40

typedef struct Matrix4s {
    /* 0x00 */ s16 whole[4][4];
    /* 0x20 */ s16 frac[4][4];
} Matrix4s; // size = 0x40

typedef struct CamConfiguration {
    /* 0x00 */ f32 boomYaw;
    /* 0x04 */ f32 boomLength;
    /* 0x08 */ f32 boomPitch;
    /* 0x0C */ f32 viewPitch;
    /* 0x10 */ Vec3f targetPos;
} CamConfiguration; // size = 0x1C

typedef struct DmaTable {
    /* 0x00 */ u8* start;
    /* 0x04 */ u8* end;
    /* 0x08 */ u8* dest;
} DmaTable;

typedef struct PartnerData {
    /* 0x00 */ u8 enabled;
    /* 0x01 */ s8 level;
    /* 0x02 */ s16 unk_02[3];
} PartnerData; // size = 0x08

typedef struct HeapNode {
    /* 0x00 */ struct HeapNode* next;
    /* 0x04 */ u32 length;
    /* 0x08 */ u16 allocated;
    /* 0x0A */ u16 entryID;
    /* 0x0C */ u32 capacity;
} HeapNode; // size = 0x10

#define NPC_BLUR_FRAMES 20

/// Ring buffer of an NPC's position over the past 20 frames.
typedef struct NpcMotionBlur {
    /* 0x00 */ s8 unused;
    /* 0x01 */ s8 index; ///< Current blur ring buffer index
    /* 0x02 */ char unk_02[2]; // padding?
    /* 0x04 */ f32 posX[NPC_BLUR_FRAMES];
    /* 0x54 */ f32 posY[NPC_BLUR_FRAMES];
    /* 0xA4 */ f32 posZ[NPC_BLUR_FRAMES];
} NpcMotionBlur; // size = 0xF4

typedef struct NpcChompBlur {
    /* 0x00 */ struct Npc* npc;
    /* 0x04 */ Vec3f offset;
} NpcChompBlur; // size = 0x10;

typedef struct NpcQuizmoBlur {
    /* 0x00 */ s32 flags;
    /* 0x04 */ char unk_04[0x4];
} NpcQuizmoBlur; // size = 0x8;

typedef struct NpcHistoryPoint {
    /* 0x00 */ b8 isAirborne;
    /* 0x01 */ char unk_01[0x3];
    /* 0x04 */ Vec3f pos;
} NpcHistoryPoint; // size = 0x10

typedef struct FollowAnims {
    /* 0x00 */ AnimID walk;
    /* 0x04 */ AnimID jump;
    /* 0x08 */ AnimID fall;
    /* 0x0C */ AnimID land;
    /* 0x10 */ AnimID idle;
    /* 0x14 */ AnimID run;
} FollowAnims; // size = 0x18

typedef struct NpcFollowData {
    /* 0x000 */ NpcHistoryPoint moveHistory[40];
    /* 0x280 */ s32 lastPointIdx;
    /* 0x284 */ s32 targetPointIdx;
    /* 0x288 */ s32 followState;
    /* 0x28C */ s32 targetNpcID;
    /* 0x290 */ FollowAnims* anims;
    /* 0x294 */ f32 walkSpeed;
    /* 0x298 */ f32 runSpeed;
    /* 0x29C */ f32 idleRadius;
    /* 0x2A0 */ f32 walkRadius;
} NpcFollowData; // size = 0x2A4

#define MAX_NPC_DECORATIONS 2

typedef struct Npc {
    /* 0x000 */ s32 flags;
    /* 0x004 */ void (*onUpdate)(struct Npc*); ///< Run before anything else for this NPC in update_npcs()
    /* 0x008 */ void (*onRender)(struct Npc*); ///< Run after the display list for this NPC is built
    /* 0x00C */ f32 yaw;
    /* 0x010 */ f32 planarFlyDist; /* also used for speech, temp0? */
    /* 0x014 */ f32 jumpScale; /* also used for speech, temp1? */
    /* 0x018 */ f32 moveSpeed;
    /* 0x01C */ f32 jumpVel;
    /* 0x020 */ union {
                void* any;
                NpcMotionBlur* motion; ///< Null unless flag 0x100000 is set.
                NpcChompBlur*  chomp;
                NpcQuizmoBlur* quizmo;
                NpcFollowData* followData;
                struct Npc*    keepAwayNpc;
                s32*           keepAwayStarted;
                } blur;
    /* 0x024 */ s32 spriteInstanceID;
    /* 0x028 */ AnimID curAnim;
    /* 0x02C */ s32 animNotifyValue;
    /* 0x030 */ f32 animationSpeed;
    /* 0x034 */ f32 renderYaw;
    /* 0x038 */ Vec3f pos;
    /* 0x044 */ Vec3f rot;
    /* 0x050 */ f32 rotPivotOffsetY;
    /* 0x054 */ Vec3f scale;
    /* 0x060 */ Vec3f moveToPos;
    /* 0x06C */ Vec3f colliderPos; /* used during collision with player */
    /* 0x078 */ s32 shadowIndex;
    /* 0x07C */ f32 shadowScale;
    /* 0x080 */ s32 collisionChannel; /* flags used with collision tracing */
    /* 0x084 */ s16 curFloor; /* colliderID */
    /* 0x086 */ s16 curWall; /* colliderID */
    /* 0x088 */ b16 isFacingAway;
    /* 0x08A */ s16 yawCamOffset;
    /* 0x08C */ s16 turnAroundYawAdjustment;
    /* 0x08E */ s16 duration; // TODO: name less vaguely
    /* 0x090 */ Vec3s homePos;
    /* 0x096 */ s16 unk_96;
    /* 0x098 */ s16 imgfxType;
    /* 0x09A */ s16 imgfxArg1;
    /* 0x09C */ s16 imgfxArg2;
    /* 0x09E */ s16 imgfxArg3;
    /* 0x0A0 */ s16 imgfxArg4;
    /* 0x0A2 */ u16 imgfxFlags;
    /* 0x0A4 */ s8 npcID;
    /* 0x0A5 */ char unk_A5;
    /* 0x0A6 */ s16 collisionDiameter;
    /* 0x0A8 */ s16 collisionHeight;
    /* 0x0AA */ s8 renderMode;
    /* 0x0AB */ s8 verticalRenderOffset;
    /* 0x0AC */ u8 alpha;
    /* 0x0AD */ u8 hideAlpha; ///< Used when hiding NPCs; Multiplied with Npc::alpha
    /* 0x0AE */ char unk_AE[2];
    /* 0x0B0 */ AnimID* extraAnimList;
    /* 0x0B4 */ s8 palSwapType; // 0..4 inclusive
    /* 0x0B5 */ s8 palSwapPrevType;
    /* 0x0B6 */ s8 resetPalAdjust;
    /* 0x0B7 */ s8 palAnimState;
    /* 0x0B8 */ char unk_B8[4];
    /* 0x0BC */ s16 nextPalTime;
    /* 0x0BE */ s16 palBlendAlpha;
    /* 0x0C0 */ s8 spriteColorVariations;
    /* 0x0C1 */ s8 originalPalettesCount;
    /* 0x0C2 */ char unk_C2[2];
    /* 0x0C4 */ PAL_PTR* originalPalettesList;
    /* 0x0C8 */ PAL_BIN copiedPalettes[16][SPR_PAL_SIZE];
    /* 0x2C8 */ PAL_PTR adjustedPalettes[16];
    /* 0x308 */ s16 blendPalA;
    /* 0x30A */ s16 blendPalB;
    /* 0x30C */ u16 palswapTimeHoldA;
    /* 0x30E */ s16 palswapTimeAtoB;
    /* 0x310 */ s16 palswapTimeHoldB;
    /* 0x312 */ s16 palswapTimeBtoA;
    /* 0x314 */ s16 blendPalC;
    /* 0x316 */ s16 blendPalD;
    /* 0x318 */ f32 screenSpaceOffset2D[2];
    /* 0x320 */ f32 verticalStretch;
    /* 0x324 */ struct EffectInstance* decorations[MAX_NPC_DECORATIONS];
    /* 0x32C */ s8 decorationType[MAX_NPC_DECORATIONS];
    /* 0x32E */ s8 changedDecoration[MAX_NPC_DECORATIONS];
    /* 0x330 */ s8 decorationInitialized[MAX_NPC_DECORATIONS];
    /* 0x332 */ s16 decorationGlowPhase[MAX_NPC_DECORATIONS];
    /* 0x336 */ char unk_336[10];
} Npc; // size = 0x340

typedef Npc* NpcList[MAX_NPCS];

typedef struct PlayerData {
    /* 0x000 */ s8 bootsLevel;
    /* 0x001 */ s8 hammerLevel;
    /* 0x002 */ s8 curHP;
    /* 0x003 */ s8 curMaxHP;
    /* 0x004 */ s8 hardMaxHP;
    /* 0x005 */ s8 curFP;
    /* 0x006 */ s8 curMaxFP;
    /* 0x007 */ s8 hardMaxFP;
    /* 0x008 */ s8 maxBP;
    /* 0x009 */ s8 level;
    /* 0x00A */ b8 hasActionCommands;
    /* 0x00B */ char pad_00B;
    /* 0x00C */ s16 coins;
    /* 0x00E */ s8 fortressKeyCount;
    /* 0x00F */ u8 starPieces;
    /* 0x010 */ s8 starPoints;
    /* 0x011 */ s8 unused_011;
    /* 0x012 */ s8 curPartner;
    /* 0x013 */ char pad_013;
    /* 0x014 */ struct PartnerData partners[12];
    /* 0x074 */ s16 keyItems[32];
    /* 0x0B4 */ s16 badges[128];
    /* 0x1B4 */ s16 invItems[10];
    /* 0x1C8 */ s16 storedItems[32];
    /* 0x208 */ s16 equippedBadges[64];
    /* 0x288 */ s8 unused_288;
    /* 0x289 */ s8 merleeSpellType;
    /* 0x28A */ s8 merleeCastsLeft;
    /* 0x28B */ char pad_28B;
    /* 0x28C */ s16 merleeTurnCount;
    /* 0x28E */ s8 maxStarPower;
    /* 0x28F */ char pad_28F;
    /* 0x290 */ s16 starPower;
    /* 0x292 */ s8 starBeamLevel;
    /* 0x293 */ char pad_293;
    /* 0x294 */ u16 actionCommandAttempts;
    /* 0x296 */ u16 actionCommandSuccesses;
    /* 0x298 */ u16 hitsTaken;
    /* 0x29A */ u16 hitsBlocked;
    /* 0x29C */ u16 playerFirstStrikes;
    /* 0x29E */ u16 enemyFirstStrikes;
    /* 0x2A0 */ u16 powerBounces;
    /* 0x2A2 */ u16 battlesCount;
    /* 0x2A4 */ u16 battlesWon;
    /* 0x2A6 */ u16 fleeAttempts;
    /* 0x2A8 */ u16 battlesFled;
    /* 0x2AA */ u16 trainingsDone;
    /* 0x2AC */ s32 walkingStepsTaken;
    /* 0x2B0 */ s32 runningStepsTaken;
    /* 0x2B4 */ u32 totalCoinsEarned;
    /* 0x2B8 */ s16 idleFrameCounter; /* frames with no inputs, overflows ever ~36 minutes of idling */
    /* 0x2BA */ char pad_2BA[2];
    /* 0x2BC */ u32 frameCounter; /* increases by 2 per frame */
    /* 0x2C0 */ u16 quizzesAnswered;
    /* 0x2C2 */ u16 quizzesCorrect;
    /* 0x2C4 */ s32 partnerUnlockedTime[12];
    /* 0x2F4 */ s32 partnerUsedTime[12];
    /* 0x324 */ s32 tradeEventStartTime;
    /* 0x328 */ s32 droTreeHintTime;
    /* 0x32C */ u16 starPiecesCollected;
    /* 0x32E */ u16 jumpGamePlays;
    /* 0x330 */ u32 jumpGameTotal; /* all-time winnings, max = 99999 */
    /* 0x334 */ u16 jumpGameRecord;
    /* 0x336 */ u16 smashGamePlays;
    /* 0x338 */ u32 smashGameTotal; /* all-time winnings, max = 99999 */
    /* 0x33C */ u16 smashGameRecord;
    /* 0x33E */ char pad_33E[2];
    /* 0x340 */ char reserved[0xE8]; // unused
} PlayerData; // size = 0x428

typedef struct Trigger {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 varIndex;
    /* 0x08 */ union {
    /*      */     s32 colliderID;
    /*      */     Vec4f* pos;
    /*      */ } location;
    /* 0x0C */ s32 (*onActivateFunc)(struct Trigger*);
    /* 0x10 */ EvtScript* onTriggerEvt;
    /* 0x14 */ struct Evt* runningScript;
    /* 0x18 */ s32 priority;
    /* 0x1C */ union {
    /*      */     s32 varTable[3];
    /*      */     f32 varTableF[3];
    /*      */     void* varTablePtr[3];
    /*      */ };
    /* 0x28 */ s32* itemList;
    /* 0x2C */ s32 tattleMsg;
    /* 0x30 */ u8 hasPlayerInteractPrompt;
    /* 0x31 */ char unk_31[3];
    /* 0x34 */ s32 runningScriptID;
} Trigger; // size = 0x38

typedef Trigger* TriggerList[MAX_TRIGGERS];

typedef struct TriggerBlueprint {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s16 varIndex;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ s32 colliderID;
    /* 0x0C */ s32 (*onActivateFunc)(struct Trigger*);
    /* 0x10 */ char unk_10[4];
    /* 0x14 */ s32 tattleMsg;
    /* 0x18 */ s32 hasPlayerInteractPrompt;
    /* 0x1C */ s32* itemList;
} TriggerBlueprint; // size = 0x20

typedef struct Evt {
    /* 0x000 */ u8 stateFlags;
    /* 0x001 */ u8 curArgc;
    /* 0x002 */ u8 curOpcode;
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
    /* 0x070 */ union {
    /*       */     s32 functionTemp[4];
    /*       */     f32 functionTempF[4];
    /*       */     void* functionTempPtr[4];
    /*       */ };
    /* 0x080 */ ApiFunc callFunction;
    /* 0x084 */ union {
    /*       */     s32 varTable[16];
    /*       */     f32 varTableF[16];
    /*       */     void* varTablePtr[16];
    /*       */ };
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
    /* 0x160 */ Bytecode* ptrSavedPos;
    /* 0x164 */ Bytecode* ptrCurLine;
} Evt; // size = 0x168

typedef Evt* ScriptList[MAX_SCRIPTS];

struct Entity;
struct SaveBlockData;
struct SwitchData;
struct ShatteringBlockData;
struct BlockData;
struct WoodenCrateData;
struct ChestData;
struct BlueWarpPipeData;
struct HeartBlockContentData;
struct SuperBlockContentData;
struct SimpleSpringData;
struct HiddenPanelData;
struct SignpostData;
struct PadlockData;
struct BoardedFloorData;
struct BombableRockData;
struct TweesterData;
struct StarBoxLauncherData;
struct CymbalPlantData;
struct PinkFlowerData;
struct SpinningFlowerData;
struct TrumpetPlantData;
struct MunchlesiaData;
struct ArrowSignData;

typedef s32 (*EntityCallback)(struct Entity*);

typedef struct DmaEntry {
    void* start;
    void* end;
} DmaEntry;

typedef struct EntityBlueprint {
    /* 0x00 */ u16 flags;
    /* 0x02 */ u16 typeDataSize;
    /* 0x04 */ UNK_PTR renderCommandList;
    /* 0x08 */ UNK_PTR modelAnimationNodes;
    /* 0x0C */ void (*fpInit)(struct Entity*);
    /* 0x10 */ UNK_PTR updateEntityScript;
    /* 0x14 */ EntityCallback fpHandleCollision;
    /* 0x18 */ union {
                DmaEntry dma;
                DmaEntry* dmaList;
               };
    /* 0x20 */ u8 entityType;
    /* 0x21 */ u8 aabbSize[3];
} EntityBlueprint; // size = 0x24

typedef union {
    s32* any;
    struct SaveBlockData* saveBlock;
    struct SwitchData* swtch;
    struct ShatteringBlockData* shatteringBlock;
    struct BlockData* block;
    struct WoodenCrateData* crate;
    struct ChestData* chest;
    struct BlueWarpPipeData* bluePipe;
    struct HeartBlockContentData* heartBlockContent;
    struct SuperBlockContentData* superBlockContent;
    struct SimpleSpringData* simpleSpring;
    struct HiddenPanelData* hiddenPanel;
    struct SignpostData* signPost;
    struct PadlockData* padlock;
    struct BoardedFloorData* boardedFloor;
    struct BombableRockData* bombableRock;
    struct TweesterData* tweester;
    struct StarBoxLauncherData* starBoxLauncher;
    struct CymbalPlantData* cymbalPlant;
    struct PinkFlowerData* pinkFlower;
    struct SpinningFlowerData* spinningFlower;
    struct TrumpetPlantData* trumpetPlant;
    struct MunchlesiaData* munchlesia;
    struct ArrowSignData* arrowSign;
} EntityData;

typedef struct Entity {
    /* 0x00 */ s32 flags;
    /* 0x04 */ u8 listIndex;
    /* 0x05 */ s8 unk_05;
    /* 0x06 */ u8 collisionFlags;
    /* 0x07 */ s8 collisionTimer;
    /* 0x08 */ u8 unk_08;
    /* 0x09 */ u8 scriptDelay;
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
    /* 0x28 */ EvtScript* boundScriptBytecode;
    /* 0x2C */ s32* savedReadPos[3];
    /* 0x38 */ EntityBlueprint* blueprint;
    /* 0x3C */ void (*renderSetupFunc)(s32);
    /* 0x40 */ EntityData dataBuf;
    /* 0x44 */ void* gfxBaseAddr;
    /* 0x48 */ Vec3f pos;
    /* 0x54 */ Vec3f scale;
    /* 0x60 */ Vec3f rot;
    /* 0x6C */ f32 shadowPosY;
    /* 0x70 */ Matrix4f inverseTransformMatrix; /* world-to-local */
    /* 0xB0 */ f32 effectiveSize;
    /* 0xB4 */ char unk_B4[4];
    /* 0xB8 */ Mtx transformMatrix;
} Entity; // size = 0xF8

typedef Entity* EntityList[MAX_ENTITIES];

struct Shadow;

typedef void (*ShadowCallback)(struct Shadow*);

// same as EntityBlueprint
typedef struct ShadowBlueprint {
    /* 0x00 */ u16 flags;
    /* 0x02 */ s16 typeDataSize;
    /* 0x04 */ UNK_PTR renderCommandList;
    /* 0x08 */ struct StaticAnimatorNode** animModelNode;
    /* 0x0C */ ShadowCallback(onCreateCallback);
    /* 0x10 */ char unk_10[0x10];
    /* 0x20 */ u8 entityType;
    /* 0x21 */ char aabbSize[3];
} ShadowBlueprint; // size = 0x24

typedef struct Shadow {
    /* 0x00 */ s32 flags;
    /* 0x04 */ u8 listIndex;
    /* 0x05 */ u8 alpha;
    /* 0x06 */ u8 unk_06;
    /* 0x07 */ char unk_07;
    /* 0x08 */ s16 entityModelID;
    /* 0x0A */ s16 vertexSegment;
    /* 0x0C */ Vec3s* vertexArray;
    /* 0x10 */ Vec3f pos;
    /* 0x1C */ Vec3f scale;
    /* 0x28 */ Vec3f rot;
    /* 0x34 */ char unk_34[0x4];
    /* 0x38 */ Mtx transformMatrix;
} Shadow; // size = 0x78

typedef Shadow* ShadowList[MAX_SHADOWS];

typedef struct Worker {
    /* 0x00 */ s32 flags;
    /* 0x04 */ void (*update)(void);
    /* 0x08 */ void (*draw)(void);
} Worker;

typedef Worker* WorkerList[MAX_WORKERS];

typedef struct MusicSettings {
    /* 0x00 */ u16 flags;
    /* 0x02 */ s16 state;
    /* 0x04 */ s32 fadeOutTime;
    /* 0x08 */ s32 fadeInTime;
    /* 0x0C */ s16 fadeStartVolume;
    /* 0x0E */ s16 fadeEndVolume;
    /* 0x10 */ s32 songID;
    /* 0x14 */ s32 variation;
    /* 0x18 */ s32 songName;
    /* 0x1C */ s32 battleSongID;
    /* 0x20 */ s32 battleVariation;
    /* 0x24 */ s32 savedSongID;
    /* 0x28 */ s32 savedVariation;
    /* 0x2C */ s32 savedSongName;
} MusicSettings; // size = 0x30

typedef struct MusicProximityTrigger {
    /* 0x00 */ VecXZf pos;
    /* 0x08 */ f32 innerDist;
    /* 0x0C */ f32 outerDist;
    /* 0x10 */ s32 unk;
    /* 0x14 */ s32 manualActivationFlag;
} MusicProximityTrigger; // size = 0x18

typedef struct StatusBar {
    /* 0x00 */ s32 hpIconHIDs[2];
    /* 0x08 */ s32 fpIconHIDs[2];
    /* 0x10 */ s32 coinIconHID;
    /* 0x14 */ s32 coinSparkleHID;
    /* 0x18 */ s32 spIconHID;
    /* 0x1C */ s32 spShineHID;
    /* 0x20 */ s32 hpTimesHID;
    /* 0x24 */ s32 fpTimesHID;
    /* 0x28 */ s32 spTimesHID;
    /* 0x2C */ s32 coinTimesHID;
    /* 0x30 */ s32 starIconHID;
    /* 0x34 */ s16 drawPosX; // base position of the whole bar
    /* 0x36 */ s16 drawPosY; // base position of the whole bar, animated when it appears
    /* 0x38 */ s16 showTimer;
    /* 0x3A */ b8 hidden;
    /* 0x3B */ b8 unk_3B;
    /* 0x3C */ b8 unk_3C;
    /* 0x3D */ s8 displayHP;
    /* 0x3E */ s8 displayFP;
    /* 0x3F */ char unk_3F;
    /* 0x40 */ s16 displayCoins;
    /* 0x42 */ s16 displayStarpoints;
    /* 0x44 */ s8 ignoreChanges; /* set != 0 to prevent automatic opening from HP/FP changes */
    /* 0x45 */ s8 openInputDisabled;
    /* 0x45 */ s8 alwaysShown; // when set, the status bar will always be shown. used while browsing a shop.
    /* 0x47 */ s8 disabled; /* set != 0 for menu to be disabled completely */
    /* 0x48 */ s16 displayStarPower;
    /* 0x4A */ s8 hpBlinking; /* bool */
    /* 0x4B */ s8 hpBlinkCounter;
    /* 0x4C */ s8 hpBlinkTimer; /* until stop */
    /* 0x4D */ s8 fpBlinking; /* bool */
    /* 0x4E */ s8 fpBlinkCounter;
    /* 0x4F */ s8 fpBlinkTimer; /* until stop */
    /* 0x50 */ s8 spBlinking;
    /* 0x51 */ s8 spBlinkCounter;
    /* 0x52 */ s8 starpointsBlinking; /* bool */
    /* 0x53 */ s8 starpointsBlinkCounter;
    /* 0x54 */ s8 coinsBlinking; /* bool */
    /* 0x55 */ s8 coinsBlinkCounter;
    /* 0x56 */ s8 coinsBlinkTimer; /* until stop */
    /* 0x57 */ s8 unk_57;
    /* 0x58 */ s8 unk_58;
    /* 0x59 */ s8 unk_59;
    /* 0x5A */ s8 spBarsToBlink; /* how many sp bars to blink */
    /* 0x5B */ char unk_5B;
    /* 0x5C */ s32 coinCountTimesHID;
    /* 0x60 */ s32 coinCountIconHID;
    /* 0x64 */ s32 iconIndex12;
    /* 0x68 */ s32 iconIndex13;
    /* 0x6C */ s8 coinCounterHideTime;
    /* 0x6D */ s8 unk_6D;
    /* 0x6E */ s8 unk_6E;
    /* 0x6F */ char unk_6F;
} StatusBar; // size = 0x70

typedef struct CameraInitData {
    /* 0x00 */ s16 flags;
    /* 0x02 */ s8 updateMode;
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
    union {
        struct {
            f32 Ax;
            f32 Ay;
            f32 Az;
            f32 Bx;
            f32 By;
            f32 Bz;
        } two;
        struct {
            f32 Ax;
            f32 Cx;
            f32 Az;
            f32 Bx;
            f32 Cz;
            f32 Bz;
        } three;
    } points;
    /* 0x24 */ f32 viewPitch;
    /* 0x28 */ s32 flag;
} CameraControlSettings; // size = 0x2C

typedef struct Camera {
    /* 0x000 */ u16 flags;
    /* 0x002 */ s16 moveFlags;
    /* 0x004 */ s16 updateMode;
    /* 0x006 */ s16 needsInit;
    /* 0x008 */ b16 isChangingMap;
    /* 0x00A */ s16 viewportW;
    /* 0x00C */ s16 viewportH;
    /* 0x00E */ s16 viewportStartX;
    /* 0x010 */ s16 viewportStartY;
    /* 0x012 */ s16 nearClip;
    /* 0x014 */ s16 farClip;
    /* 0x016 */ char unk_16[2];
    /* 0x018 */ f32 vfov;
    /* 0x01C */ s16 auxPitch;
    /* 0x01E */ s16 auxBoomLength;
    /* 0x020 */ s16 lookAt_dist;
    /* 0x022 */ s16 auxBoomPitch;
    /* 0x024 */ s16 auxBoomYaw;
    /* 0x026 */ s16 auxBoomZOffset;
    /* 0x028 */ s16 unk_28;
    /* 0x02A */ s16 zoomPercent;
    /* 0x02C */ s16 bgColor[3];
    /* 0x032 */ Vec3s targetScreenCoords;
    /* 0x038 */ u16 perspNorm;
    /* 0x03A */ char unk_3A[2];
    /* 0x03C */ Vec3f lookAt_eye;
    /* 0x048 */ Vec3f lookAt_obj;
    /* 0x054 */ Vec3f lookAt_obj_target;
    /* 0x060 */ Vec3f targetPos;
    /* 0x06C */ f32 curYaw;
    /* 0x070 */ f32 unk_70;
    /* 0x074 */ f32 curBoomYaw;
    /* 0x078 */ f32 curBoomLength;
    /* 0x07C */ f32 curYOffset;
    /* 0x080 */ char unk_80[4];
    /* 0x084 */ Vec3f trueRot;
    /* 0x090 */ f32 curBlendedYawNegated;
    /* 0x094 */ f32 curPitch;
    /* 0x098 */ f32 unk_98;
    /* 0x09C */ f32 unk_9C;
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
    /* 0x204 */ Mtx* unkMatrix;
    /* 0x208 */ s32 unk_208;
    /* 0x20C */ Matrix4s* unkEffectMatrix;
    /* 0x210 */ char unk_210[0x2];
    /* 0x212 */ s16 unk_212;
    /* 0x214 */ CameraUnk unk_214[4];
    /* 0x444 */ CameraControlSettings* prevController;
    /* 0x448 */ CameraControlSettings* curController;
    /* 0x44C */ CamConfiguration prevConfiguration;
    /* 0x468 */ CamConfiguration goalConfiguration;
    /* 0x484 */ f32 interpAlpha;
    /* 0x488 */ f32 linearInterp;
    /* 0x48C */ f32 linearInterpScale; /* 3.0? */
    /* 0x490 */ f32 moveSpeed;
    /* 0x494 */ f32 yinterpGoal;
    /* 0x498 */ f32 yinterpAlpha;
    /* 0x49C */ f32 yinterpRate; // smaller is faster; not valid for values less than 1.0, unstable below 0.5
    /* 0x4A0 */ f32 yinterpCur;
    /* 0x4A4 */ Vec3f prevTargetPos;
    /* 0x4B0 */ Vec3f movePos;
    /* 0x4BC */ Vec3f prevPrevMovePos;
    /* 0x4C8 */ Vec3f prevMovePos;
    /* 0x4D4 */ u16 prevPrevFollowPlayer;
    /* 0x4D6 */ u16 prevFollowPlayer;
    /* 0x4D8 */ CameraControlSettings controlSettings;
    /* 0x504 */ u16 followPlayer;
    /* 0x506 */ u16 panActive;
    /* 0x508 */ f32 panPhase;
    /* 0x50C */ f32 leadAmount;
    /* 0x510 */ f32 targetLeadAmount;
    /* 0x514 */ f32 leadInterpAlpha;
    /* 0x518 */ f32 accumulatedStickLead;
    /* 0x51C */ s32 increasingLeadInterp;
    /* 0x520 */ f32 unk_520;
    /* 0x524 */ f32 leadUnkX;
    /* 0x528 */ f32 leadUnkZ;
    /* 0x52C */ s32 unk_52C;
    /* 0x530 */ s32 unk_530;
    /* 0x534 */ CameraControlSettings* leadControlSettings;
    /* 0x538 */ char unk_538[0x18];
    /* 0x550 */ f32 unk_550;
    /* 0x554 */ s16 unk_554;
    /* 0x556 */ s16 unk_556;
} Camera; // size = 0x558

typedef struct BattleStatus {
    /* 0x000 */ s32 flags1;
    /* 0x004 */ s32 flags2;
    /* 0x008 */ union {
    /*       */     s32 varTable[16];
    /*       */     f32 varTableF[16];
    /*       */     void* varTablePtr[16];
    /*       */ };
    /* 0x048 */ s8 curSubmenu;
    /* 0x049 */ s8 unk_49;
    /* 0x04A */ s8 curPartnerSubmenu;
    /* 0x04B */ s8 unk_4B;
    /* 0x04C */ s8 lastPlayerMenuSelection[16];
    /* 0x05C */ s8 lastPartnerMenuSelection[16];
    /* 0x06C */ s16 cancelTargetMenuSubstate; // might be more generally for returning from nested 'inner' state
    /* 0x06E */ s16 acceptTargetMenuSubstate; // might be more generally for returning from nested 'inner' state
    /* 0x070 */ s16 enabledMenusFlags; // zero'd bits will be unavailable, used only for tutorial battles
    /* 0x072 */ char unk_72[2];
    /* 0x074 */ s32 enabledStarPowersFlags; // zero'd bits will be unavailable, used only for tutorial battles
    /* 0x078 */ s8 totalStarPoints;
    /* 0x079 */ s8 pendingStarPoints; /* how many to add */
    /* 0x07A */ s8 incrementStarPointDelay; /* related to star points, set to 0x28 when they are dropped */
    /* 0x07B */ u8 damageTaken;
    /* 0x07C */ s8 changePartnerAllowed;
    /* 0x07D */ s8 menuStatus[4]; ///< -1 = automatically pick the first move, 0 = disabled, 1 = enabled
    /* 0x081 */ s8 actionSuccess;
    /* 0x082 */ char unk_82;
    /* 0x083 */ s8 actionCommandMode;
    /* 0x084 */ s8 actionQuality; // actionCommandVar1 ?
    /* 0x085 */ s8 unk_85; // actionCommandVar2 ?
    /* 0x086 */ s8 actionResult; // see enum ActionResult
    /* 0x087 */ s8 blockResult; // see enum BlockResult
    /* 0x088 */ s8 itemUsesLeft; /* set to 2 for double dip, 3 for triple dip */
    /* 0x089 */ s8 hpDrainCount;
    /* 0x08A */ s8 nextMerleeSpellType;
    /* 0x08B */ s8 hustleTurns; /* numTurns from hustle drink, normally 0 */
    /* 0x08C */ s8 stateFreezeCount;
    /* 0x08D */ s8 endBattleFadeOutRate;
    /* 0x08E */ s8 initialEnemyCount; /* used for SP award bonus */
    /* 0x08F */ char unk_8F[1];
    /* 0x090 */ s16 unk_90;
    /* 0x092 */ s8 reflectFlags;
    /* 0x093 */ s8 unk_93;
    /* 0x094 */ s8 unk_94;
    /* 0x095 */ s8 waitForState;
    /* 0x096 */ s8 hammerCharge;
    /* 0x097 */ s8 jumpCharge;
    /* 0x098 */ char unk_98;
    /* 0x099 */ u8 rushFlags; /* 1 = mega rush, 2 = power rush */
    /* 0x09A */ s8 outtaSightActive;
    /* 0x09B */ s8 turboChargeTurnsLeft;
    /* 0x09C */ u8 turboChargeAmount; /* unused? */
    /* 0x09D */ s8 waterBlockTurnsLeft;
    /* 0x09E */ u8 waterBlockAmount; /* unused? */
    /* 0x09F */ char unk_9F;
    /* 0x0A0 */ struct EffectInstance* waterBlockEffect;
    /* 0x0A4 */ s8 cloudNineTurnsLeft;
    /* 0x0A5 */ s8 cloudNineDodgeChance; /* = 50/101 ≈ 49.5% */
    /* 0x0A6 */ char unk_A6[2];
    /* 0x0A8 */ struct EffectInstance* cloudNineEffect;
    /* 0x0AC */ s8 merleeAttackBoost;
    /* 0x0AD */ s8 merleeDefenseBoost;
    /* 0x0AE */ s8 hammerLossTurns;
    /* 0x0AF */ s8 jumpLossTurns;
    /* 0x0B0 */ s8 itemLossTurns;
    /* 0x0B1 */ char unk_B1[3];
    /* 0x0B4 */ UNK_FUN_PTR(preUpdateCallback);
    /* 0x0B8 */ UNK_FUN_PTR(initBattleCallback);
    /* 0x0BC */ struct Evt* controlScript; /* control handed over to this when changing partners */
    /* 0x0C0 */ s32 controlScriptID;
    /* 0x0C4 */ struct Evt* camMovementScript;
    /* 0x0C8 */ s32 camMovementScriptID;
    /* 0x0CC */ Vec3f camLookatObjPos;
    /* 0x0D8 */ struct Actor* playerActor;
    /* 0x0DC */ struct Actor* partnerActor;
    /* 0x0E0 */ struct Actor* enemyActors[MAX_ENEMY_ACTORS];
    /* 0x140 */ s16 enemyIDs[MAX_ENEMY_ACTORS];
    /* 0x170 */ s8 nextEnemyIndex; /* (during enemy turn) who should go next */
    /* 0x171 */ s8 numEnemyActors;
    /* 0x172 */ s16 activeEnemyActorID; /* (during enemy turn) enemy currently using their move */
    /* 0x174 */ struct Actor* curTurnEnemy;
    /* 0x178 */ s8 moveCategory; ///< 0 = jump, 1 = hammer, 5 = partner, ...
    /* 0x179 */ char unk_179;
    /* 0x17A */ s16 moveArgument; // argument provided for move; can be hammer/boots level, itemID, etc
    /* 0x17C */ s16 selectedMoveID;
    /* 0x17E */ s16 curAttackDamage;
    /* 0x180 */ s16 lastAttackDamage;
    /* 0x182 */ char unk_182[2];
    /* 0x184 */ s32 curTargetListFlags; /* set when creating a target list, also obtain from the flags field of moves */
    /* 0x188 */ s32 curAttackElement;
    /* 0x18C */ s32 curAttackEventSuppression;
    /* 0x190 */ s32 curAttackStatus;
    /* 0x194 */ u8 statusChance;
    /* 0x195 */ s8 statusDuration;
    /* 0x196 */ char unk_196;
    /* 0x197 */ s8 sampleTargetHomeIndex;
    /* 0x198 */ s8 powerBounceCounter;
    /* 0x199 */ s8 wasStatusInflicted; /* during last attack */
    /* 0x19A */ u8 curDamageSource;
    /* 0x19B */ char unk_19B[5];
    /* 0x1A0 */ s16 curTargetID; /* selected? */
    /* 0x1A2 */ s8 curTargetPart; /* selected? */
    /* 0x1A3 */ char unk_1A3;
    /* 0x1A4 */ s16 curTargetID2;
    /* 0x1A6 */ s8 curTargetPart2;
    /* 0x1A7 */ s8 battlePhase;
    /* 0x1A8 */ s16 attackerActorID;
    /* 0x1AA */ s16 unk_1AA;
    /* 0x1AC */ s8 unk_1AC;
    /* 0x1AD */ char unk_1AD;
    /* 0x1AE */ s16 submenuIcons[24]; /* icon IDs */
    /* 0x1DE */ u8 submenuMoves[24]; /* move IDs */
    /* 0x1F6 */ s8 submenuStatus[24]; ///< @see enum BattleSubmenuStatus
    /* 0x20E */ u8 submenuMoveCount;
    /* 0x20F */ char unk_20F;
    /* 0x210 */ s32 curButtonsDown;
    /* 0x214 */ s32 curButtonsPressed;
    /* 0x218 */ s32 curButtonsHeld;
    /* 0x21C */ s32 stickX;
    /* 0x220 */ s32 stickY;
    /* 0x224 */ s32 inputBitmask;
    /* 0x228 */ s32 stickAngle; /* 0-360 */
    /* 0x22C */ s32 stickMagnitude; /* 0-60 */
    /* 0x230 */ s32 holdInputBuffer[64];
    /* 0x330 */ s32 pushInputBuffer[64];
    /* 0x430 */ s8 holdInputBufferPos;
    /* 0x431 */ s8 inputBufferPos;
    /* 0x432 */ s8 darknessMode;
    /* 0x433 */ u8 unk_433;
    /* 0x434 */ s32* actionCmdDifficultyTable;
    /* 0x438 */ struct Stage* curStage;
    /* 0x43C */ struct EffectInstance* buffEffect;
    /* 0x440 */ u8 tattleFlags[28];
    /* 0x45C */ char unk_45C[4];
} BattleStatus; // size = 0x460

typedef struct TextureHeader {
    /* 0x00 */ s8 name[32];
    /* 0x20 */ u16 auxW;
    /* 0x22 */ u16 mainW;
    /* 0x24 */ u16 auxH;
    /* 0x26 */ u16 mainH;
    /* 0x28 */ u8 isVariant;
    /* 0x29 */ u8 extraTiles; // 0 - none, 1 - mipmap, 2 - ?, 3 - use aux tile
    /* 0x2A */ u8 auxCombineType : 6;
    /* 0x2A */ u8 auxCombineSubType : 2;
    /* 0x2B */ u8 auxFmt : 4;
    /* 0x2B */ u8 mainFmt : 4;
    /* 0x2C */ u8 auxBitDepth : 4;
    /* 0x2C */ u8 mainBitDepth : 4;
    /* 0x2D */ u8 auxWrapW : 4;
    /* 0x2D */ u8 mainWrapW : 4;
    /* 0x2E */ u8 auxWrapH : 4;
    /* 0x2E */ u8 mainWrapH : 4;
    /* 0x2F */ u8 filtering;
} TextureHeader; // size = 0x30

typedef struct MoveData {
    /* 0x00 */ s32 nameMsg;
    /* 0x04 */ s32 flags;
    /* 0x08 */ s32 shortDescMsg;
    /* 0x0C */ s32 fullDescMsg;
    /* 0x10 */ s8 category; ///< @see enum MoveType
    /* 0x11 */ s8 costFP;
    /* 0x12 */ s8 costBP;
    /* 0x13 */ u8 actionTip;
} MoveData; // size = 0x14

typedef struct Collider {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s16 nextSibling;
    /* 0x06 */ s16 firstChild;
    /* 0x08 */ s16 parentModelIndex;
    /* 0x0A */ s16 numTriangles;
    /* 0x0C */ struct ColliderTriangle* triangleTable;
    /* 0x10 */ union {
                   struct ColliderBoundingBox* aabb;
                   struct CameraControlSettings* camSettings;
               };
    /* 0x14 */ s16 numVertices;
    /* 0x16 */ char unk_16[2];
    /* 0x18 */ Vec3f* vertexTable; // contains local and global coordinates
} Collider; // size = 0x1C

typedef struct CollisionData {
    /* 0x00 */ Vec3f* vertices;
    /* 0x04 */ Collider* colliderList;
    /* 0x08 */ union {
                   struct ColliderBoundingBox* aabbs;
                   struct CameraControlSettings* camSettings;
               };
    /* 0x0C */ s16 numColliders;
    /* 0x0E */ char unk_0E[2];
} CollisionData; // size = 0x10

typedef struct AnimatorNode {
    /* 0x00 */ Gfx* displayList;
    /* 0x04 */ struct AnimatorNode* children[32];
    /* 0x84 */ Vec3f basePos; // ?
    /* 0x90 */ Vec3f pos;
    /* 0x9C */ Vec3f rot;
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
    /* 0x00 */ void* displayList;
    /* 0x04 */ Vec3f basePos;
    /* 0x10 */ Vec3f rot;
    /* 0x1C */ char unk_1C[0x4];
} AnimatorNodeBlueprint; // size = 0x20

typedef struct StaticAnimatorNode {
    /* 0x00 */ void* displayList; // sometimes StaticAnimatorNode*, sometimes Gfx*???
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
    /* 0x008 */ s16* animReadPos;
    /* 0x00C */ s16* savedReadPos;
    /* 0x010 */ AnimatorNode* rootNode;
    /* 0x014 */ u8 nextUniqueID;
    /* 0x015 */ u8 staticNodeIDs[0x7A]; // ?
    /* 0x08F */ char unk_08F[0x1];
    /* 0x090 */ f32 nextUpdateTime;
    /* 0x094 */ f32 timeScale;
    /* 0x098 */ Mtx mtx;
    /* 0x0D8 */ void* baseAddr;
    /* 0x0DC */ s16* animationBuffer;
    /* 0x0E0 */ StaticAnimatorNode* staticNodes[0x7A];
    /* 0x2C8 */ StaticAnimatorNode** staticRoot;
    /* 0x2CC */ s32 treeIndexPos;
    /* 0x2D0 */ s32 savedTreePos;
    /* 0x2D4 */ void (*fpRenderCallback)(void*);
    /* 0x2D8 */ void* renderCallbackArg;
    /* 0x2DC */ char unk_2DC[4];
} ModelAnimator; // size = 0x2E0

typedef ModelAnimator* AnimatedMeshList[MAX_ANIMATED_MESHES];

typedef struct ColliderBoundingBox {
    /* 0x00 */ Vec3f min;
    /* 0x0C */ Vec3f max;
    /* 0x18 */ s32 flagsForCollider;
} ColliderBoundingBox; // size = 0x1C

typedef struct ItemData {
    /* 0x00 */ s32 nameMsg;
    /* 0x04 */ s16 hudElemID;
    /* 0x06 */ s16 sortValue;
    /* 0x08 */ s32 targetFlags;
    /* 0x0C */ s16 sellValue;
    /* 0x0E */ char unk_0E[2];
    /* 0x10 */ s32 fullDescMsg;
    /* 0x14 */ s32 shortDescMsg;
    /* 0x18 */ s16 typeFlags;
    /* 0x1A */ u8 moveID;
    /* 0x1B */ s8 potencyA;
    /* 0x1C */ s8 potencyB;
    /* 0x1D */ char unk_1D[3];
} ItemData; // size = 0x20

typedef struct ItemEntity {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s16 boundVar;
    /* 0x06 */ s16 pickupMsgFlags;
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ struct ItemEntityPhysicsData* physicsData;
    /* 0x18 */ s16 itemID;
    /* 0x1A */ s8 state;
    /* 0x1B */ s8 spawnType;
    /* 0x1C */ u8 pickupDelay; /* num frames before item can be picked up */
    /* 0x1D */ s8 renderGroup;
    /* 0x1E */ s16 spawnAngle; /* if < 0, a random screen-relative angle is chosen: left or right */
    /* 0x20 */ s16 shadowIndex;
    /* 0x22 */ char unk_22[2];
    /* 0x24 */ u32* readPos;
    /* 0x28 */ u32* savedReadPos;
    /* 0x2C */ u8 lookupRasterIndex;
    /* 0x2D */ u8 lookupPaletteIndex;
    /* 0x2E */ u8 nextUpdate;
    /* 0x2F */ u8 alpha;
    /* 0x30 */ f32 scale;
    /* 0x34 */ Vec3s lastPos;
    /* 0x3A */ char unk_3A[2];
    /* 0x3C */ s32 sparkleNextUpdate;
    /* 0x40 */ s32* sparkleReadPos;
    /* 0x44 */ s32 sparkleUnk44;
    /* 0x48 */ s32* sparkleSavedPos;
    /* 0x4C */ IMG_PTR sparkleRaster;
    /* 0x50 */ PAL_PTR sparklePalette;
    /* 0x54 */ s32 sparkleWidth;
    /* 0x58 */ s32 sparkleHeight;
} ItemEntity; // size = 0x5C

typedef struct MessagePrintState {
    /* 0x000 */ u8* srcBuffer;
    /* 0x004 */ u16 printBufferPos;
    /* 0x006 */ char unk_06[2];
    /* 0x008 */ s32 msgID;
    /* 0x00C */ u16 srcBufferPos;
    /* 0x00E */ u16 curPrintDelay;
    /* 0x010 */ u8 printBuffer[1088]; // slightly larger than source buffer
    /* 0x450 */ s16 printBufferSize;
    /* 0x452 */ u16 effectFrameCounter;
    /* 0x454 */ u8 font;
    /* 0x455 */ u8 fontVariant;
    /* 0x456 */ Vec2s windowOffsetPos; // offset from baseWindowPos. used to animated window pos?
    /* 0x45A */ Vec2s windowBasePos; // ex: set by the parameters for choice style
    /* 0x45E */ u8 printDelayTime; // delay to print each chunk
    /* 0x45F */ u8 charsPerChunk; // how many chars to print at once
    /* 0x460 */ s32 curLinePos; // position along current line
    /* 0x464 */ u8 windowScrollRate;
    /* 0x465 */ char unk_465;
    /* 0x466 */ u16 nextLinePos; // ?
    /* 0x468 */ u8 lineCount;
    /* 0x469 */ char unk_469[0x3];
    /* 0x46C */ s32 unk_46C;
    /* 0x470 */ u8 curAnimFrame[4];
    /* 0x474 */ s16 animTimers[4];
    /* 0x47C */ u8 rewindArrowAnimState;
    /* 0x47D */ char unk_47D[0x1];
    /* 0x47E */ s16 rewindArrowCounter;
    /* 0x480 */ s16 rewindArrowSwingPhase;
    /* 0x482 */ Vec2su rewindArrowPos;
    /* 0x486 */ u8 curLine;
    /* 0x487 */ u8 unkArraySize;
    /* 0x488 */ u16 lineEndPos[4];
    /* 0x490 */ char unk_490[0x38];
    /* 0x4C8 */ u16 unk_4C8;
    /* 0x4CA */ s16 unk_4CA;
    /* 0x4CC */ u16 unk_4CC;
    /* 0x4CE */ u8 maxOption;
    /* 0x4CF */ char unk_4CF[0x1];
    /* 0x4D0 */ u16 cursorPosX[6];
    /* 0x4DC */ u16 cursorPosY[6];
    /* 0x4E8 */ u8 curOption;
    /* 0x4E9 */ s8 madeChoice;
    /* 0x4EA */ u8 cancelOption;
    /* 0x4EB */ char unk_4EB[0x1];
    /* 0x4EC */ u8 targetOption;
    /* 0x4ED */ u8 scrollingTime;
    /* 0x4EE */ u8 selectedOption;
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
    /* 0x51A */ u8 speechPan; // just pan?
    /* 0x51B */ char unk_51B[0x1];
    /* 0x51C */ u16 speechPitchShift;
    /* 0x51E */ char unk_51E[0x2];
    /* 0x520 */ s32 speechSoundIDA;
    /* 0x524 */ s32 speechSoundIDB;
    /* 0x528 */ u16 varBufferReadPos;
    /* 0x52A */ s8 unk_52A;
    /* 0x52B */ u8 curImageIndex;
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
    /* 0x544 */ IMG_PTR letterBackgroundImg;
    /* 0x548 */ PAL_PTR letterBackgroundPal;
    /* 0x54C */ IMG_PTR letterContentImg;
    /* 0x550 */ PAL_PTR letterContentPal;
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
    /* 0x40 */ u8 curPosX;
    /* 0x41 */ char unk_41;
    /* 0x42 */ u16 nextPos[2];
    /* 0x46 */ s16 textStartPos[2]; // relative to textbox
    /* 0x4A */ s16 textColor;
    /* 0x4C */ u8* printBuffer;
    /* 0x50 */ u8 nextCounter; // related to closing mssages and cmd FA
    /* 0x51 */ char unk_51[0x3];
} MessageDrawState; // size = 0x54

typedef struct MessageCharData {
    /* 0x0 */ IMG_PTR raster;
    /* 0x4 */ u8* charWidthTable;
    /* 0x8 */ u8 monospaceWidth;
    /* 0x9 */ u8 baseHeightOffset;
    /* 0xA */ char unk_0A[0x2];
} MessageCharData; // size = 0xC

typedef struct MessageCharset {
    /* 0x0 */ Vec2bu texSize;
    /* 0x2 */ s8 unk_02;
    /* 0x3 */ u8 newLineY;
    /* 0x4 */ u16 charRasterSize; // in bytes
    /* 0x6 */ char unk_06[0x2];
    /* 0x8 */ MessageCharData* rasters;
} MessageCharset; // size = 0xA;

typedef struct MesasgeFontGlyphData {
    /* 0x0 */ IMG_PTR raster;
    /* 0x4 */ PAL_PTR palette;
    /* 0x8 */ Vec2bu texSize;
    /* 0xA */ u8 charWidth;
    /* 0xB */ u8 charHeight;
} MesasgeFontGlyphData; // size = 0xC

typedef struct MessageImageData {
    /* 0x00 */ IMG_PTR raster;
    /* 0x04 */ PAL_PTR palette;
    /* 0x08 */ u16 width;
    /* 0x0A */ u16 height;
    /* 0x0C */ s32 format;
    /* 0x10 */ s32 bitDepth;
} MessageImageData; // size = 0x14

typedef struct MessageNumber {
    /* 0x00 */ IMG_PTR rasters;
    /* 0x04 */ u8 texSize;
    /* 0x05 */ u8 texWidth;
    /* 0x06 */ u8 texHeight;
    /* 0x07 */ u8 digitWidth[10];
    /* 0x11 */ u8 fixedWidth;
    /* 0x12 */ char unk_12[0x2];
} MessageNumber; // size = 0x14

typedef struct ShopItemEntity {
    /* 0x00 */ s32 index;
    /* 0x04 */ Vec3f pos;
} ShopItemEntity; // size = 0x10

typedef struct ShopOwner {
    /* 0x00 */ s32 npcID;
    /* 0x04 */ s32 idleAnim;
    /* 0x08 */ s32 talkAnim;
    /* 0x0C */ EvtScript* onBuyEvt;
    /* 0x10 */ EvtScript* unk_10Evt;
    /* 0x14 */ EvtScript* onTalkEvt;
    /* 0x18 */ s32* shopMsgIDs;
} ShopOwner;

typedef struct ShopItemLocation {
    /* 0x0 */ u16 posModelID;
    /* 0x2 */ u16 triggerColliderID;
} ShopItemLocation; // size = 0x4

typedef struct ShopItemData {
    /* 0x0 */ u32 itemID;
    /* 0x4 */ s32 price;
    /* 0x8 */ s32 descMsg;
} ShopItemData; // size = 0xC

typedef struct ShopSellPriceData {
    /* 0x0 */ s32 itemID;
    /* 0x4 */ s32 sellPrice;
    /* 0x8 */ char unk_08[0x4];
} ShopSellPriceData; // size = 0xC

typedef struct GameStatus {
    /* 0x000 */ u32 curButtons[4];
    /* 0x010 */ u32 pressedButtons[4]; /* bits = 1 for frame of button press */
    /* 0x020 */ u32 heldButtons[4]; /* bits = 1 every 4th frame during hold */
    /* 0x030 */ u32 prevButtons[4]; /* from previous frame */
    /* 0x040 */ s8 stickX[4]; /* with deadzone */
    /* 0x044 */ s8 stickY[4]; /* with deadzone */
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
    /* 0x071 */ s8 demoState; // see DemoState enum
    /* 0x072 */ s8 nextDemoScene; /* which part of the demo to play next */
    /* 0x073 */ u8 contBitPattern;
    /* 0x074 */ s8 debugEnemyContact;
    /* 0x075 */ s8 debugQuizmo;
    /* 0x076 */ b8 debugUnused1;
    /* 0x077 */ b8 debugUnused2;
    /* 0x078 */ s8 debugScripts;
    /* 0x079 */ char unk_79;
    /* 0x07A */ b8 musicEnabled;
    /* 0x07B */ char unk_7B;
    /* 0x07C */ b8 healthBarsEnabled;
    /* 0x07D */ b8 keepUsingPartnerOnMapChange;
    /* 0x07E */ u8 peachFlags; // see PeachFlags enum
    /* 0x07F */ s8 peachDisguise; // see PeachDisguises enum
    /* 0x080 */ u8 peachBakingIngredient; ///< @see PeachBakingItems enum
    /* 0x081 */ b8 multiplayerEnabled;
    /* 0x082 */ Vec2b altViewportOffset;
    /* 0x084 */ s8 playerSpriteSet;
    /* 0x085 */ char unk_85;
    /* 0x086 */ s16 areaID;
    /* 0x088 */ s16 prevArea;
    /* 0x08A */ b16 didAreaChange;
    /* 0x08C */ s16 mapID;
    /* 0x08E */ s16 entryID;
    /* 0x090 */ u16 unk_90;
    /* 0x092 */ u16 unk_92;
    /* 0x094 */ f32 exitTangent;
    /* 0x098 */ Vec3f playerPos;
    /* 0x0A4 */ f32 playerYaw;
    /* 0x0A8 */ s8 introPart;
    /* 0x0A9 */ s8 unk_A9; // selected language?
    /* 0x0AA */ s8 demoBattleFlags;
    /* 0x0AB */ u8 soundOutputMode;
    /* 0x0AC */ s8 startupState; // used for various startup states like logos, title screen, intro, and demo
    /* 0x0AD */ s8 logoTime;
    /* 0x0AE */ b8 skipLogos;
    /* 0x0AF */ s8 titleScreenTimer;
    /* 0x0B0 */ s8 titleScreenDismissTime;
    /* 0x0B1 */ char unk_B1[0x5];
    /* 0x0B6 */ s16 screenColorA;
    /* 0x0B8 */ s16 screenColorR;
    /* 0x0BA */ s16 screenColorG;
    /* 0x0BC */ s16 screenColorB;
    /* 0x0BE */ char unk_BE[94];
    /* 0x11C */ Vec3f playerGroundTraceAngles;
    /* 0x128 */ Vec3f playerGroundTraceNormal;
    /* 0x134 */ u16 frameCounter;
    /* 0x136 */ char unk_136[2];
    /* 0x138 */ u32 nextRNG;
    /* 0x13C */ s16 unk_13C;
    /* 0x13E */ char unk_13E[2];
    /* 0x140 */ ShopItemEntity* shopItemEntities;
    /* 0x144 */ struct Shop* mapShop;
    /* 0x148 */ s16 backgroundFlags;
    /* 0x14A */ s16 backgroundMinX;
    /* 0x14C */ s16 backgroundMinY;
    /* 0x14E */ s16 backgroundMaxX;
    /* 0x150 */ s16 backgroundMaxY;
    /* 0x152 */ s16 backgroundXOffset; /* (used for parallax scroll) */
    /* 0x154 */ IMG_PTR backgroundRaster;
    /* 0x158 */ PAL_PTR backgroundPalette;
    /* 0x15C */ u16 backgroundDarkness; // 255 = fully black
    /* 0x15E */ s16 savedBackgroundDarkness; // used during pause/unpause
    /* 0x160 */ Vec3s savedPos;
    /* 0x166 */ u8 saveSlot;
    /* 0x167 */ u8 loadType; /* (0 = from map, 1 = from main menu) */
    /* 0x168 */ u32 saveCount;
    /* 0x16C */ char unk_16C[12];
} GameStatus; // size = 0x178

typedef union PartnerAnimations {
    /* 0x00 */ s32 anims[9]; // see enum PartnerAnimIndices
    struct {
    /* 0x00 */ s32 still;
    /* 0x04 */ s32 walk;
    /* 0x08 */ s32 jump;
    /* 0x0C */ s32 fall;
    /* 0x10 */ s32 fly;
    /* 0x14 */ s32 idle;
    /* 0x18 */ s32 run;
    /* 0x1C */ s32 talk;
    /* 0x20 */ s32 hurt;
    };
} PartnerAnimations; // size = 0x24

typedef s32 (*PushBlockFallCallback)(Entity* block, Evt* script);
typedef struct PushBlockGrid {
    /* 0x00 */ u8* cells;
    /* 0x04 */ u8 numCellsX;
    /* 0x05 */ u8 numCellsZ;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ Vec3i centerPos;
    /* 0x14 */ PushBlockFallCallback(dropCallback);
    /* 0x18 */ char unk_18[4];
} PushBlockGrid; // size = 0x1C

typedef struct ItemEntityPhysicsData {
    /* 0x00 */ f32 verticalVel;
    /* 0x04 */ f32 gravity; /* 2 = normal, 1 = low gravity, higher values never 'settle' */
    /* 0x08 */ f32 collisionRadius;
    /* 0x0C */ f32 constVel;
    /* 0x10 */ f32 velX;
    /* 0x14 */ f32 velZ;
    /* 0x18 */ f32 moveAngle;
    /* 0x1C */ s32 timeLeft;
    /* 0x20 */ b32 useSimplePhysics;
} ItemEntityPhysicsData; // size = 0x24

typedef struct RenderTask {
    /* 0x00 */ s32 renderMode;
    /* 0x04 */ s32 dist; /* value between 0 and -10k */
    /* 0x08 */ void* appendGfxArg;
    /* 0x0C */ void (*appendGfx)(void*);
} RenderTask; // size = 0x10

typedef struct SelectableTarget {
    /* 0x00 */ s16 actorID;
    /* 0x02 */ s16 partID;
    /* 0x04 */ Vec3s truePos; // position where the cursor will be drawn
    /* 0x0A */ Vec3s sortPos; // effective position used for sorting, includes priority-based x offsets
    /* 0x10 */ s8 priorityOffset;
    /* 0x11 */ s8 column; // from xpos --> 0-3
    /* 0x12 */ s8 row; // from ypos --> 0-3
    /* 0x13 */ s8 layer; // from zpos --> 0-1
} SelectableTarget; // size = 0x14

typedef struct ActorPartMovement {
    /* 0x00 */ Vec3f absolutePos;
    /* 0x0C */ Vec3f goalPos;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ f32 jumpScale;
    /* 0x28 */ f32 moveSpeed;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ f32 angle;
    /* 0x34 */ f32 dist;
    /* 0x38 */ s16 moveTime;
    /* 0x3A */ s16 unk_3A;
    /* 0x3C */ s32 unk_3C;
    /* 0x40 */ char unk_40[0xC];
    /* 0x4C */ union {
    /*      */     s32 varTable[16];
    /*      */     f32 varTableF[16];
    /*      */     void* varTablePtr[16];
    /*      */ };

} ActorPartMovement; // size = 0x8C

typedef struct ActorPartBlueprint {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s8 index;
    /* 0x05 */ Vec3b posOffset;
    /* 0x08 */ Vec2b targetOffset;
    /* 0x0A */ s16 opacity;
    /* 0x0C */ s32* idleAnimations;
    /* 0x10 */ s32* defenseTable;
    /* 0x14 */ s32 eventFlags;
    /* 0x18 */ s32 elementImmunityFlags;
    /* 0x1C */ Vec2b projectileTargetOffset;
    /* 0x1E */ char unk_1E[2];
    /* 0x20 */ s32 overrideNameMsg; // name when this part is targeted; overrides name from actor type
} ActorPartBlueprint; // size = 0x24

typedef struct ActorPart {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 targetFlags; /* initialized to 0 */
    /* 0x08 */ ActorPartBlueprint* staticData;
    /* 0x0C */ struct ActorPart* nextPart;
    /* 0x10 */ struct ActorPartMovement* movement;
    /* 0x14 */ Vec3s partOffset;
    /* 0x1A */ Vec3s visualOffset;
    /* 0x20 */ Vec3f partOffsetFloat;
    /* 0x2C */ Vec3f absolutePos;
    /* 0x38 */ Vec3f rot;
    /* 0x44 */ Vec3s rotPivotOffset;
    /* 0x4A */ char unk_4A[2];
    /* 0x4C */ Vec3f scale;
    /* 0x58 */ Vec3f curPos;
    /* 0x64 */ f32 yaw;
    /* 0x68 */ s16 palAnimPosOffset[2]; // used by some palette animations to slightly adjust the screen position
    /* 0x6C */ Vec2s targetOffset;
    /* 0x70 */ s16 targetPriorityOffset;
    /* 0x72 */ Vec2bu size;
    /* 0x74 */ s8 verticalStretch;
    /* 0x75 */ Vec2b projectileTargetOffset;
    /* 0x77 */ char unk_77[1];
    /* 0x78 */ u32* defenseTable;
    /* 0x7C */ s32 eventFlags;
    /* 0x80 */ s32 elementalImmunities; // bits from Elements, i.e., ELEMENT_FIRE | ELEMENT_QUAKE
    /* 0x84 */ s32 spriteInstanceID;
    /* 0x88 */ u32 curAnimation;
    /* 0x8C */ s32 animNotifyValue;
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

typedef struct FontRasterSet {
    /* 0x00 */ u8 sizeX;
    /* 0x01 */ u8 sizeY;
    /* 0x02 */ char unk_02[10];
} FontRasterSet; // size = 0x0C

typedef struct CollisionStatus {
    /* 0x00 */ s16 pushingAgainstWall; /* FFFF = none for all below VVV */
    /* 0x02 */ s16 curFloor; /* valid on touch */
    /* 0x04 */ s16 lastTouchedFloor; /* valid after jump */
    /* 0x06 */ s16 floorBelow;
    /* 0x08 */ s16 curCeiling; /* valid on touching with head */
    /* 0x0A */ s16 curInspect; /* associated with TRIGGER_WALL_PRESS_A */
    /* 0x0C */ s16 unk_0C; /* associated with TRIGGER_FLAG_2000 */
    /* 0x0E */ s16 unk_0E; /* associated with TRIGGER_FLAG_4000 */
    /* 0x10 */ s16 unk_10; /* associated with TRIGGER_FLAG_8000 */
    /* 0x12 */ s16 curWall;
    /* 0x14 */ s16 lastWallHammered; /* valid when smashing */
    /* 0x16 */ s16 touchingWallTrigger; /* 0/1 */
    /* 0x18 */ s16 bombetteExploded; /* 0 = yes, FFFF = no */
    /* 0x1A */ char unk_1A[2];
    /* 0x1C */ Vec3f bombetteExplosionPos;
} CollisionStatus; // size = 0x28

typedef struct DecorFireTrail {
    /* 0x00 */ s16 scale;
} DecorFireTrail;

typedef struct DecorGoldenFlames {
    /* 0x00 */ s16 scaleX;
    /* 0x02 */ s16 scaleY;
    /* 0x04 */ s16 offsetX;
} DecorGoldenFlames;

typedef struct DecorRedFlames {
    /* 0x00 */ s16 scaleX;
    /* 0x02 */ s16 scaleY;
    /* 0x04 */ s16 alpha;
    /* 0x06 */ s16 offsetZ;
    /* 0x08 */ s16 unused1;
    /* 0x0A */ s16 unused2;
    /* 0x0C */ s16 unused3;
} DecorRedFlames;

typedef struct DecorBowserAura {
    /* 0x00 */ s16 scaleX;
    /* 0x02 */ s16 scaleY;
    /* 0x04 */ s16 alpha;
    /* 0x06 */ s16 offsetZ;
} DecorBowserAura;

typedef struct DecorDataSparkles {
    /* 0x00 */ s16 spawnInterval;
} DecorDataSparkles;

typedef struct DecorDataStars {
    /* 0x00 */ s16 scalePct;
    /* 0x02 */ s16 offsetY;
} DecorDataStars;

// data for any type of decoration can be stored here
typedef union DecorationData {
    s16 raw[8];
    DecorFireTrail fireTrail;
    DecorRedFlames redFlames;
    DecorGoldenFlames goldenFlames;
    DecorBowserAura bowserAura;
    DecorDataSparkles sparkles;
    DecorDataStars stars;
} DecorationData; // size = 0x10

#define MAX_ACTOR_DECORATIONS 2
#define ACTOR_BLUR_FRAMES 16

typedef struct DecorationTable {
    /* 0x000 */ PAL_BIN copiedPalettes[2][27][SPR_PAL_SIZE];
    /* 0x6C0 */ s8 paletteAdjustment;
    /* 0x6C1 */ b8 resetPalAdjust;
    /* 0x6C2 */ s8 palAnimState;
    /* 0x6C3 */ char unk_6C3[5];
    /* 0x6C8 */ s16 nextPalTime;
    /* 0x6CA */ s16 palBlendAlpha;
    /* 0x6CC */ s8 spriteColorVariations;
    /* 0x6CD */ s8 originalPalettesCount;
    /* 0x6CE */ char unk_6CE[2];
    /* 0x6D0 */ PAL_PTR* originalPalettesList;
    /* 0x6D4 */ PAL_PTR adjustedPalettes[27];
    /* 0x740 */ s16 blendPalA; // can be either palette or palset index
    /* 0x742 */ s16 blendPalB; // can be either palette or palset index
    /* 0x744 */ s16 palswapTimeHoldA;
    /* 0x746 */ s16 palswapTimeAtoB;
    /* 0x748 */ s16 palswapTimeHoldB;
    /* 0x74A */ s16 palswapTimeBtoA;
    /* 0x74C */ s16 palswapUnused1; // presumably palswapTimeHoldC for unimplemented triple cycling (A->B->C->A)
    /* 0x74E */ s16 palswapUnused2; // presumably palswapTimeCtoA  for unimplemented triple cycling (A->B->C->A)
    /* 0x750 */ s8 glowState;
    /* 0x751 */ b8 glowStateChanged;
    /* 0x752 */ s8 glowUnk1;
    /* 0x753 */ char pad753[5];
    /* 0x758 */ s16 glowUnk2;
    /* 0x75A */ s16 glowUnk3;
    /* 0x75C */ s16 glowPhase;
    /* 0x75E */ char pad75E[6];
    /* 0x764 */ s8 flashState;
    /* 0x765 */ s8 flashStateChanged;
    /* 0x766 */ s8 flashMode;
    /* 0x767 */ s8 flashFramesLeft;
    /* 0x768 */ u8 flashEnabled;
    /* 0x769 */ char unk_769[3];
    /* 0x76C */ PAL_PTR flashPalettes[16];
    /* 0x78C */ char unk_7AC[0x2C];
    /* 0x7D8 */ s8 blurUnused;
    /* 0x7D9 */ s8 blurBufferPos;
    /* 0x7DA */ s8 blurDrawCount;
    /* 0x7DB */ s8 blurEnableCount;
    /* 0x7DC */ s16 yaw[ACTOR_BLUR_FRAMES];
    /* 0x7FC */ s16 posX[ACTOR_BLUR_FRAMES];
    /* 0x81C */ s16 posY[ACTOR_BLUR_FRAMES];
    /* 0x83C */ s16 posZ[ACTOR_BLUR_FRAMES];
    /* 0x85C */ s8 rotPivotOffsetX[ACTOR_BLUR_FRAMES];
    /* 0x86C */ s8 rotPivotOffsetY[ACTOR_BLUR_FRAMES];
    /* 0x87C */ u8 rotX[ACTOR_BLUR_FRAMES];
    /* 0x88C */ u8 rotY[ACTOR_BLUR_FRAMES];
    /* 0x89C */ u8 rotZ[ACTOR_BLUR_FRAMES];
    /* 0x8AC */ s8 blurDisableDelay; // infinite when zero
    /* 0x8AD */ char unk_8AD[3];
    /* substruct for decorations? */
    /* 0x8B0 */ struct EffectInstance* effect[MAX_ACTOR_DECORATIONS];
    /* 0x8B8 */ s8 type[MAX_ACTOR_DECORATIONS];
    /* 0x8BA */ u8 changed[MAX_ACTOR_DECORATIONS];
    /* 0x8BC */ s8 state[MAX_ACTOR_DECORATIONS];
    /* 0x8BE */ s16 stateResetTimer[MAX_ACTOR_DECORATIONS];
    /* 0x8C2 */ char unk_8C0[4];
    /* 0x8C6 */ DecorationData decorData[MAX_ACTOR_DECORATIONS];
} DecorationTable; // size = 0x8E8

typedef struct PlayerPathElement {
    /* 0x00 */ b8 isJumping;
    /* 0x03 */ char unk_01[3];
    /* 0x04 */ Vec3f pos;
} PlayerPathElement; // size = 0x10

typedef struct LavaReset {
    /* 0x00 */ s32 colliderID;
    /* 0x04 */ Vec3f pos;
} LavaReset; // size = 0x10;

typedef struct BombTrigger {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ s32 radius; // effective 'size' of the object, usually set to zero because bombettes explosion radius is large enough
} BombTrigger; // size = 0x10;

// the use of this is a bug in sam_11
typedef struct BombTriggerF {
    /* 0x00 */ Vec3f pos;
    /* 0x0C */ f32 radius;
} BombTriggerF; // size = 0x10;

typedef struct AnimatedModel {
    /* 0x00 */ s32 animModelID;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ Vec3f rot;
    /* 0x1C */ Vec3f scale;
    /* 0x28 */ Mtx mtx;
    /* 0x68 */ s16* curAnimData;
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
    /* 0x00 */ Vec3f curPos;
    /* 0x0C */ Vec3f goalPos;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ char unk_24[0x18];
    /* 0x3C */ f32 acceleration;
    /* 0x40 */ f32 speed;
    /* 0x44 */ f32 vel;
    /* 0x48 */ f32 angle;
    /* 0x4C */ f32 dist;
    /* 0x50 */ f32 flyElapsed;
    /* 0x54 */ char unk_11C[4];
    /* 0x58 */ s16 flyTime;
    /* 0x5A */ s16 flyArcAmplitude;
} ActorMovement; // size = 0x5C;

// a single link of a chain chomp's chain
typedef struct ChompChain {
    /* 0x00 */ Vec3f curPos;
    /* 0x0C */ f32 unk_0C;
    /* 0x10 */ f32 unk_10;
    /* 0x14 */ f32 gravAccel;
    /* 0x18 */ f32 velY;
    /* 0x1C */ f32 settleAmt;
    /* 0x20 */ f32 settleRate;
    /* 0x24 */ f32 outerLinkLen;
    /* 0x28 */ f32 innerLinkLen;
    /* 0x2C */ f32 linkLengthZ;
} ChompChain; // size = 0x30

typedef struct ActorState { // TODO: Make the first field of this an ActorMovement
    /* 0x00 */ Vec3f curPos;
    /* 0x0C */ Vec3f goalPos;
    /* 0x18 */ Vec3f unk_18;
    /* 0x24 */ f32 unk_24;
    /* 0x28 */ f32 unk_28;
    /* 0x2C */ f32 unk_2C;
    /* 0x30 */ Vec3f velStep;
    /* 0x3C */ f32 acceleration;
    /* 0x40 */ f32 speed;
    /* 0x44 */ f32 vel;
    /* 0x48 */ f32 angle;
    /* 0x4C */ f32 dist;
    /* 0x50 */ f32 bounceDivisor;
    /* 0x54 */ char unk_54[0x4];
    /* 0x58 */ s32 animJumpRise;
    /* 0x5C */ s32 animJumpFall;
    /* 0x60 */ s32 animJumpLand;
    /* 0x64 */ s16 moveTime;
    /* 0x66 */ s16 moveArcAmplitude;
    /* 0x68 */ char unk_68[3];
    /* 0x6B */ u8 jumpPartIndex;
    /* 0x6C */ union {
    /*      */     s32 functionTemp[4];
    /*      */     f32 functionTempF[4];
    /*      */     void* functionTempPtr[4];
    /*      */ };
    /* 0x7C */ union {
    /*      */     s32 varTable[16];
    /*      */     f32 varTableF[16];
    /*      */     void* varTablePtr[16];
    /*      */ };
} ActorState; // size = 0xBC;

typedef struct Actor {
    /* 0x000 */ s32 flags;
    /* 0x004 */ s32 flags2;
    /* 0x008 */ struct ActorBlueprint* actorBlueprint;
    /* 0x00C */ ActorState state;
    /* 0x0C8 */ ActorMovement fly;
    /* 0x124 */ char unk_124[16];
    /* 0x134 */ u8 unk_134;
    /* 0x135 */ u8 footStepCounter;
    /* 0x136 */ u8 actorType;
    /* 0x137 */ char unk_137;
    /* 0x138 */ Vec3f homePos;
    /* 0x144 */ Vec3f curPos;
    /* 0x150 */ Vec3s headOffset;
    /* 0x156 */ Vec3s healthBarPos;
    /* 0x15C */ Vec3f rot;
    /* 0x168 */ Vec3s rotPivotOffset;
    /* 0x16E */ char unk_16E[2];
    /* 0x170 */ Vec3f scale;
    /* 0x17C */ Vec3f scaleModifier; /* multiplies normal scale factors componentwise */
    /* 0x188 */ f32 scalingFactor;
    /* 0x18C */ f32 yaw;
    /* 0x190 */ Vec2bu size;
    /* 0x192 */ s16 actorID;
    /* 0x194 */ Vec2b statusIconOffset;
    /* 0x196 */ Vec2b statusTextOffset;
    /* 0x198 */ Vec2b healthBarOffset;
    /* 0x19A */ s8 verticalRenderOffset; // visual only, does not affect target position
    /* 0x19B */ char unk_19B[1];
    /* 0x19C */ s32 actorTypeData1[6]; /* 4 = jump sound, 5 = attack sound */ // TODO: struct
    /* 0x1B4 */ s16 actorTypeData1b[2];
    /* 0x1B8 */ s8 curHP;
    /* 0x1B9 */ s8 maxHP;
    /* 0x1BA */ char unk_1BA[2];
    /* 0x1BC */ s8 healthFraction; /* used to render HP bar */
    /* 0x1BD */ char unk_1BD[3];
    /* 0x1C0 */ EvtScript* idleSource;
    /* 0x1C4 */ EvtScript* takeTurnSource;
    /* 0x1C8 */ EvtScript* handleEventSource;
    /* 0x1CC */ EvtScript* handlePhaseSource;
    /* 0x1D0 */ struct Evt* idleScript;
    /* 0x1D4 */ struct Evt* takeTurnScript;
    /* 0x1D8 */ struct Evt* handleEventScript;
    /* 0x1DC */ struct Evt* handlePhaseScript;
    /* 0x1E0 */ s32 idleScriptID;
    /* 0x1E4 */ s32 takeTurnScriptID;
    /* 0x1E8 */ s32 handleEventScriptID;
    /* 0x1EC */ s32 handleBatttlePhaseScriptID;
    /* 0x1F0 */ s8 lastEventType;
    /* 0x1F1 */ s8 turnPriority;
    /* 0x1F2 */ s8 enemyIndex; /* actorID = this | 200 */
    /* 0x1F3 */ s8 numParts;
    /* 0x1F4 */ struct ActorPart* partsTable;
    /* 0x1F8 */ s16 lastDamageTaken;
    /* 0x1FA */ s16 hpChangeCounter;
    /* 0x1FC */ s16 damageCounter;
    /* 0x1FE */ char unk_1FE[2];
    /* 0x200 */ struct EffectInstance* attackResultEffect;
    /* 0x204 */ s8 actionRatingCombo;
    /* 0x205 */ s8 actionRatingTime;
    /* 0x206 */ s8 healthBarHideTime;
    /* 0x207 */ s8 extraCoinBonus;
    /* 0x208 */ s8 instigatorValue; // from the enemy which initiated the encounter if this actor is first in the formation. allows that enemy to pass information to its actor.
    /* 0x209 */ char unk_209[3];
    /* 0x20C */ s32* statusTable;
    /* 0x210 */ s8 debuff;
    /* 0x211 */ s8 debuffDuration;
    /* 0x212 */ s8 staticStatus; /* 0B = yes */
    /* 0x213 */ s8 staticDuration;
    /* 0x214 */ s8 stoneStatus; /* 0C = yes */
    /* 0x215 */ s8 stoneDuration;
    /* 0x216 */ s8 koStatus; /* 0D = yes */
    /* 0x217 */ s8 koDuration;
    /* 0x218 */ s8 transparentStatus; /* 0E = yes */
    /* 0x219 */ s8 transparentDuration;
    /* 0x21A */ char unk_21A[2];
    /* 0x21C */ s8 statusAfflicted;
    /* 0x21D */ s8 disableDismissTimer;
    /* 0x21E */ s16 unk_21E;
    /* 0x220 */ b8 isGlowing; // also used for goombario charge amount
    /* 0x221 */ s8 attackBoost;
    /* 0x222 */ s8 defenseBoost;
    /* 0x223 */ s8 chillOutAmount; /* attack reduction */
    /* 0x224 */ s8 chillOutTurns;
    /* 0x225 */ char unk_225[3];
    /* 0x228 */ struct EffectInstance* icePillarEffect;
    /* 0x22C */ struct SelectableTarget targetData[MAX_ENEMY_ACTORS];
    /* 0x40C */ s8 targetListLength;
    /* 0x40D */ s8 targetIndexList[MAX_ENEMY_ACTORS]; /* into targetData */
    /* 0x425 */ s8 selectedTargetIndex; /* into target index list */
    /* 0x426 */ s8 targetPartID;
    /* 0x427 */ char unk_427[1];
    /* 0x428 */ s16 targetActorID;
    /* 0x42A */ char unk_42A[2];
    /* 0x42C */ union {
    /*       */     struct Shadow* ptr;
    /*       */     s32 id;
    /* 0x42C */ } shadow;
    /* 0x430 */ f32 shadowScale; /* = actor size / 24.0 */
    /* 0x434 */ s16 renderMode; /* initially 0xD, set to 0x22 if any part is transparent */
    /* 0x436 */ s16 hudElementDataIndex;
    /* 0x438 */ s32 loopingSoundID[2];
    /* 0x440 */ struct EffectInstance* disableEffect;
} Actor; // size = 0x444

typedef struct BackgroundHeader {
    /* 0x00 */ IMG_PTR raster;
    /* 0x04 */ PAL_PTR palette;
    /* 0x08 */ u16 startX;
    /* 0x0A */ u16 startY;
    /* 0x0C */ u16 width;
    /* 0x0E */ u16 height;
} BackgroundHeader; // size = 0x10

typedef struct FontData {
    /* 0x00 */ char unk_00[24];
} FontData; // size = 0x18

typedef struct SlideParams {
    /* 0x00 */ f32 heading;
    /* 0x04 */ f32 maxDescendAccel;
    /* 0x08 */ f32 launchVel;
    /* 0x0C */ f32 maxDescendVel;
    /* 0x10 */ f32 integrator[4];
} SlideParams; // size = 0x14

typedef struct PlayerStatus {
    /* 0x000 */ s32 flags; // PlayerStatusFlags
    /* 0x004 */ u32 animFlags;
    /* 0x008 */ s16 curStateTime;
    /* 0x00A */ s8 shiverTime;
    /* 0x00B */ char unk_0B;
    /* 0x00C */ s8 peachDisguise;
    /* 0x00D */ s8 availableDisguiseType; ///< set in main map scripts
    /* 0x00E */ u8 curAlpha;
    /* 0x00F */ u8 prevAlpha;
    /* 0x010 */ s16 blinkTimer;
    /* 0x012 */ s16 moveFrames;
    /* 0x014 */ s8 enableCollisionOverlapsCheck;
    /* 0x015 */ s8 inputDisabledCount; /* whether the C-up menu can appear */
    /* 0x016 */ Vec3s lastGoodPos;
    /* 0x01C */ Vec3f pushVel;
    /* 0x028 */ Vec3f pos;
    /* 0x034 */ Vec2f groundAnglesXZ; /* angles along X/Z axes of ground beneath player */
    /* 0x03C */ VecXZf jumpFromPos;
    /* 0x044 */ VecXZf landPos;
    /* 0x04C */ f32 jumpFromHeight;
    /* 0x050 */ f32 jumpApexHeight;
    /* 0x054 */ f32 curSpeed;
    /* 0x058 */ f32 walkSpeed;
    /* 0x05C */ f32 runSpeed;
    /* 0x060 */ s32 unk_60;
    /* 0x064 */ f32 overlapPushAmount;
    /* 0x068 */ f32 groundNormalPitch;
    /* 0x06C */ f32 maxJumpSpeed;
    /* 0x070 */ f32 gravityIntegrator[4]; // derivatives of y; 0 = velocity, 1 = accel, etc
    /* 0x080 */ f32 targetYaw;
    /* 0x084 */ f32 curYaw;
    /* 0x088 */ f32 overlapPushYaw;
    /* 0x08C */ f32 pitch;
    /* 0x090 */ f32 flipYaw[4];
    /* 0x0A0 */ f32 heading;
    /* 0x0A4 */ AnimID trueAnimation; ///< Encoding back-facing sprite
    /* 0x0A8 */ f32 spriteFacingAngle; /* angle of sprite, relative to camera, from 0 to 180 */
    /* 0x0AC */ char unk_AC[4];
    /* 0x0B0 */ s16 colliderHeight;
    /* 0x0B2 */ s16 colliderDiameter;
    /* 0x0B4 */ s8 actionState;
    /* 0x0B5 */ s8 prevActionState;
    /* 0x0B6 */ s8 actionSubstate;
    /* 0x0B7 */ char unk_B7;
    /* 0x0B8 */ AnimID anim;
    /* 0x0BC */ u16 animNotifyValue;
    /* 0x0BE */ s8 renderMode;
    /* 0x0BF */ s8 hazardType;
    /* 0x0C0 */ s16 timeInAir;
    /* 0x0C2 */ s16 peakJumpTime; // frame of current jump when player Y velocity went from position to negative
    /* 0x0C4 */ s8 peachItemHeld;
    /* 0x0C5 */ s8 camResetDelay;
    /* 0x0C6 */ s16 interactingWithID;
    /* 0x0C8 */ Npc* encounteredNPC;
    /* 0x0CC */ s32 shadowID;
    /* 0x0D0 */ SlideParams* slideParams;
    /* 0x0D4 */ f32 spinRate;
    /* 0x0D8 */ struct EffectInstance* specialDecorationEffect;
    /* 0x0DC */ s32 curButtons;
    /* 0x0E0 */ s32 pressedButtons;
    /* 0x0E4 */ s32 heldButtons;
    /* 0x0E8 */ s32 stickAxis[2];
    /* 0x0F0 */ s32 curButtonsBuffer[10];
    /* 0x118 */ s32 pressedButtonsBuffer[10];
    /* 0x140 */ s32 heldButtonsBuffer[10];
    /* 0x168 */ s32 stickXBuffer[10];
    /* 0x190 */ s32 stickYBuffer[10];
    /* 0x1B8 */ s32 inputBufPos;
    /* 0x1BC */ char unk_1BC[196];
    /* 0x280 */ s8 poundImpactDelay; // governs period of immobility after landing a ground pound
    /* 0x281 */ char unk_281[7];
} PlayerStatus; // size = 0x288

typedef struct SaveGlobals {
    /* 0x00 */ char magicString[16]; /* "Mario Story 006" string */
    /* 0x10 */ s8 pad[32]; /* always zero */
    /* 0x30 */ s32 crc1;
    /* 0x34 */ s32 crc2;
    /* 0x38 */ s32 useMonoSound;
    /* 0x3C */ u32 lastFileSelected;
    /* 0x40 */ s8 reserved[64]; // unused
} SaveGlobals; // size = 0x80

typedef struct SaveMetadata {
    /* 0x00 */ s32 timePlayed;
    /* 0x04 */ u8 spiritsRescued;
    /* 0x05 */ char unk_05[1];
    /* 0x06 */ s8 level;
    /* 0x07 */ unsigned char filename[8];
    /* 0x0F */ char unk_0F[9];
} SaveMetadata; // size = 0x18

typedef struct SaveData {
    /* 0x0000 */ char magicString[16]; /* "Mario Story 006" string */
    /* 0x0010 */ s8 pad[32]; /* always zero */
    /* 0x0030 */ s32 crc1;
    /* 0x0034 */ s32 crc2;
    /* 0x0038 */ s32 saveSlot;
    /* 0x003C */ s32 saveCount;
    /* 0x0040 */ PlayerData player;
    /* 0x0468 */ s16 areaID;
    /* 0x046A */ s16 mapID;
    /* 0x046C */ s16 entryID;
    /* 0x046E */ char unk_46E[2];
    /* 0x0470 */ s32 enemyDefeatFlags[60][12];
    /* 0x0FB0 */ s32 globalFlags[64];
    /* 0x10B0 */ s8 globalBytes[512];
    /* 0x12B0 */ s32 areaFlags[8];
    /* 0x12D0 */ s8 areaBytes[16];
    /* 0x12E0 */ s8 debugEnemyContact;
    /* 0x12E0 */ b8 debugUnused1;
    /* 0x12E0 */ b8 debugUnused2;
    /* 0x12E0 */ b8 musicEnabled;
    /* 0x12E4 */ char unk_12E4[0x2];
    /* 0x12E6 */ Vec3s savePos;
    /* 0x12EC */ SaveMetadata metadata;
    /* 0x1304 */ char unk_1304[0x7C];
} SaveData; // size = 0x1380

typedef struct Path {
    /* 0x00 */ s32 numVectors;
    /* 0x04 */ f32* lengths;
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
    /* 0x08 */ Vec2b* path;
    /* 0x0C */ s32 afterRequirement;
    /* 0x10 */ s32 id;
} PauseMapSpace; // size = 0x14

typedef struct MenuPanel {
    /* 0x00 */ u8 initialized;
    /* 0x01 */ s8 col;
    /* 0x02 */ s8 row;
    /* 0x03 */ u8 selected; // usually set to the current value from gridData
    /* 0x04 */ s8 page; // filemenu: 0 = select, 1 = delete, 3 = copy from, 4 = copy to, all else = save
    /* 0x05 */ s8 numCols;
    /* 0x06 */ s8 numRows;
    /* 0x07 */ s8 numPages; // unsure
    /* 0x08 */ u8* gridData; // user value at each 3D grid point (page, row, col)
    /* 0x0C */ void (*fpInit)(struct MenuPanel*);
    /* 0x10 */ void (*fpHandleInput)(struct MenuPanel*);
    /* 0x14 */ void (*fpUpdate)(struct MenuPanel*);
    /* 0x18 */ void (*fpCleanup)(struct MenuPanel*);
} MenuPanel; // size = 0x1C

typedef struct WindowBackground {
    /* 0x00 */ IMG_PTR imgData;
    /* 0x04 */ u8 fmt : 4;
    /* 0x04 */ u8 bitDepth : 4;
    /* 0x05 */ u8 width;
    /* 0x06 */ u8 height;
    /* 0x07 */ char unk_07[4];
    /* 0x0B */ s8 size;
} WindowBackground; // size = 0xC

typedef struct WindowCorners {
    /* 0x00 */ IMG_PTR imgData;
    /* 0x04 */ u8 fmt : 4;
    /* 0x04 */ u8 bitDepth : 4;
    /* 0x05 */ Vec2bu size1;
    /* 0x07 */ Vec2bu size2;
    /* 0x09 */ Vec2bu size3;
    /* 0x0B */ Vec2bu size4;
    /* 0x0D */ char unk_0D[3];
} WindowCorners; // size = 0x10

typedef struct WindowStyleCustom {
    /* 0x00 */ WindowBackground background;
    /* 0x0C */ WindowCorners corners;
    /* 0x1C */ char unk_1C[0x4];
    /* 0x20 */ Gfx opaqueCombineMode; // used when alpha == 255
    /* 0x28 */ Gfx transparentCombineMode; // used when alpha < 255
    /* 0x30 */ Color_RGBA8 color1;
    /* 0x34 */ Color_RGBA8 color2;
} WindowStyleCustom; // size = 0x38;

typedef union {
    int defaultStyleID;
    WindowStyleCustom* customStyle;
} WindowStyle TRANSPARENT_UNION;

typedef union {
    int i;
    void (*func)(s32 windowIndex, s32* flags, s32* posX, s32* posY, s32* posZ, f32* scaleX, f32* scaleY,
                                 f32* rotX, f32* rotY, f32* rotZ, s32* darkening, s32* opacity);
} WindowUpdateFunc TRANSPARENT_UNION;

typedef struct MenuWindowBP {
    /* 0x00 */ s8 windowID;
    /* 0x01 */ char unk_01;
    /* 0x02 */ Vec2s pos;
    /* 0x06 */ s16 width;
    /* 0x08 */ s16 height;
    /* 0x0A */ u8 priority;
    /* 0x0B */ char unk_0B;
    /* 0x0C */ void (*fpDrawContents)(MenuPanel* menu, s32 baseX, s32 baseY, s32 width, s32 height, s32 opacity, s32 darkening);
    /* 0x10 */ MenuPanel* tab;
    /* 0x14 */ s8 parentID;
    /* 0x15 */ char unk_15[3];
    /* 0x18 */ WindowUpdateFunc fpUpdate;
    /* 0x1C */ u8 extraFlags;
    /* 0x1D */ char unk_1D[3];
    /* 0x20 */ WindowStyle style;
} MenuWindowBP; // size = 0x24;

typedef struct {
    /* 0x00 */ u8 flags;
    /* 0x01 */ u8 priority; // lower priority rendered first
    /* 0x02 */ u8 originalPriority;
    /* 0x03 */ s8 parent;
    /* 0x04 */ WindowUpdateFunc fpUpdate;
    /* 0x08 */ WindowUpdateFunc fpPending;
    /* 0x0C */ Vec2s pos;
    /* 0x10 */ s16 width;
    /* 0x12 */ s16 height;
    /* 0x14 */ UNK_FUN_PTR(fpDrawContents);
    /* 0x18 */ void* drawContentsArg0;
    /* 0x1C */ u8 updateCounter;
    /* 0x1D */ char unk_1D[3];
} Window; // size = 0x20

#if VERSION_JP
#define DISPLAYCONTEXT_GFX_COUNT 0x2000
#elif VERSION_IQUE
#define DISPLAYCONTEXT_GFX_COUNT 0x2200
#else
#define DISPLAYCONTEXT_GFX_COUNT 0x2080
#endif

typedef struct {
    /* 0x00000 */ LookAt lookAt;
    /* 0x00020 */ Hilite hilite;
    /* 0x00030 */ Mtx camPerspMatrix[8]; // could only be length 4, unsure
    /* 0x00230 */ Gfx mainGfx[DISPLAYCONTEXT_GFX_COUNT];
    /* 0x10630 */ Gfx backgroundGfx[0x200]; // used by gfx_task_background
#if VERSION_PAL
    // TODO: find where this space belongs to
    s32 pad[0x300];
#endif
    /* 0x11630 */ Mtx matrixStack[0x200];
} DisplayContext; // size = 0x19630

typedef struct PlayerSpinState {
    /* 0x00 */ s8 stopSoundTimer;
    /* 0x01 */ s8 hasBufferedSpin;
    /* 0x02 */ s8 hitWallTime; // incremented while blocked by a wall
    /* 0x03 */ s8 spinCountdown;
    /* 0x04 */ s32 prevActionState;
    /* 0x08 */ Vec2i bufferedStickAxis;
    /* 0x10 */ f32 spinDirectionMagnitude;
    /* 0x14 */ Vec2f spinDirection;
    /* 0x1C */ f32 inputMagnitude;
    /* 0x20 */ f32 spinRate;
    /* 0x24 */ f32 speedScale;
    /* 0x28 */ f32 frictionScale;
    /* 0x2C */ s16 initialSpinTime;
    /* 0x2E */ s16 fullSpeedSpinTime;
    /* 0x30 */ s32 spinSoundID;
} PlayerSpinState; // size = 0x34

typedef struct TweesterPhysics {
    /* 0x00 */ s32 countdown;
    /* 0x04 */ s32 state;
    /* 0x08 */ s32 prevFlags; ///< Partner npc flags before contact with Tweester
    /* 0x0C */ f32 radius;
    /* 0x10 */ f32 angle;
    /* 0x14 */ f32 angularVel;
    /* 0x18 */ f32 liftoffVelPhase;
} TweesterPhysics; // size = 0x1C

typedef struct PartnerStatus {
    /* 0x000 */ s8 partnerActionState;
    /* 0x001 */ b8 shouldResumeAbility;
    /* 0x002 */ b8 partnerAction_unk_2;
    /* 0x003 */ s8 actingPartner;
    /* 0x004 */ s16 stickX;
    /* 0x006 */ s16 stickY;
    /* 0x008 */ s32 curButtons;
    /* 0x00C */ s32 pressedButtons;
    /* 0x010 */ s32 heldButtons;
    /* 0x014 */ s8 inputDisabledCount;
    /* 0x015 */ char unk_15[3];
    /* 0x018 */ Npc npc;
    /* 0x358 */ s32 unk_358;
    /* 0x35C */ char unk_35C[0x4];
} PartnerStatus; // size = 0x360

typedef struct SpriteRasterInfo {
    /* 0x00 */ IMG_PTR raster;
    /* 0x04 */ PAL_PTR defaultPal;
    /* 0x08 */ s32 width;
    /* 0x0C */ s32 height;
} SpriteRasterInfo; // size = 0x10

typedef struct KnockdownData {
    /* 0x00 */ s32 imgfxIdx;
    /* 0x04 */ s32 workerID;
    /* 0x08 */ s32 spriteIndex;
    /* 0x0C */ s32 rasterIndex;
    /* 0x10 */ Vec3f pos;
    /* 0x1C */ Vec3f rot;
    /* 0x28 */ Vec3f scale;
    /* 0x34 */ f32 width;
    /* 0x38 */ f32 height;
} KnockdownData; // size = 0x3C

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
    /* 0x44 */ f32 jumpVel;
    /* 0x48 */ f32 moveTime;
} VirtualEntity; // size = 0x4C

typedef VirtualEntity* VirtualEntityList[0x40];

typedef struct Message {
    /* 0x00 */ b32 unk_00;
    /* 0x04 */ s32 entityModelIndex;
    /* 0x08 */ Vec3f accel;
    /* 0x14 */ Vec3f vel;
    /* 0x20 */ s32 appearTime;
    /* 0x24 */ s32 unk_24;
    /* 0x28 */ f32 rotZ;
    /* 0x2C */ f32 rotVelZ;
    /* 0x30 */ f32 rotY;
    /* 0x34 */ f32 scale;
    /* 0x38 */ Vec3f pos;
    /* 0x44 */ s32 deleteTime;
    /* 0x48 */ f32 unk_48;
} Message; // size = 0x4C

struct PopupMessage;
typedef void (*PopupMessageCallback)(void* popup);
typedef struct PopupMessage {
    /* 0x00 */ s32 unk_00;
    /* 0x04 */ PopupMessageCallback updateFunc;
    /* 0x08 */ PopupMessageCallback renderWorldFunc;
    /* 0x0C */ PopupMessageCallback renderUIFunc;
    /* 0x10 */ s16 active;
    /* 0x12 */ s16 messageIndex;
    /* 0x14 */ s16 duration;
    /* 0x16 */ s8 showMsgState;
    /* 0x17 */ s8 needsInit;
    /* 0x18 */ Message* message;
} PopupMessage; // size = 0x1C

typedef struct HiddenPanelsData {
    /* 0x00 */ s8 tryFlipTrigger;
    /* 0x01 */ u8 panelsCount;
    /* 0x02 */ s8 activateISpy;
    /* 0x03 */ char unk_03[0x5];
    /* 0x08 */ f32 flipTriggerPosY;
    /* 0x0C */ char unk_0C[0x4];
} HiddenPanelsData; // size = 0x10

typedef struct SpriteShadingLightSource {
    /* 0x00 */ s8 flags;
    /* 0x01 */ Color_RGB8 rgb;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 falloff;
    /* 0x14 */ s8 unk_14;
    /* 0x15 */ char unk_15[0x3];
} SpriteShadingLightSource; // size = 0x18

typedef struct SpriteShadingProfile {
    /* 0x00 */ u16 flags;
    /* 0x02 */ char unk_02[0x2];
    /* 0x04 */ SpriteShadingLightSource sources[7];
    /* 0xAC */ Color_RGB8 ambientColor;
    /* 0xAF */ u8 ambientPower; // ?
} SpriteShadingProfile; // size = 0xB0

typedef struct ImgFXOverlayTexture {
    /* 0x00 */ IMG_PTR raster;
    /* 0x04 */ PAL_PTR palette;
    /* 0x08 */ u16 width;
    /* 0x0A */ u16 height;
    /* 0x0C */ s32 offsetX;
    /* 0x10 */ s32 offsetY;
    /* 0x14 */ Gfx* displayList;
} ImgFXOverlayTexture; // size = 0x18

typedef struct ImgFXTexture {
    /* 0x00 */ IMG_PTR raster;
    /* 0x04 */ PAL_PTR palette;
    /* 0x08 */ u16 width;
    /* 0x0A */ u16 height;
    /* 0x0C */ s16 xOffset;
    /* 0x0E */ s16 yOffset;
    /* 0x10 */ u8 alpha;
    /* 0x11 */ char unk_11[3];
    /* 0x14 */ Gfx* dlist;
} ImgFXTexture; // size = 0x18

typedef struct ImgFXWorkingTexture {
    /* 0x00 */ ImgFXTexture tex;
    /* 0x18 */ s16 unk_18;
    /* 0x1A */ char unk_1A[0x4];
    /* 0x1E */ s16 unk_1E;
    /* 0x20 */ char unk_20[0x4];
    /* 0x24 */ u8 alphaMultiplier;
} ImgFXWorkingTexture; // size = 0x25

typedef struct SongUpdateEvent {
    /* 0x00 */ s32 songName;
    /* 0x04 */ s32 duration;
    /* 0x08 */ s32 startVolume;
    /* 0x0C */ s32 finalVolume;
    /* 0x10 */ s32 variation;
    /* 0x14 */ s32 unk14;
    /* 0x18 */ s32 unk18;
    /* 0x1C */ s32 unk1C; // may be fake
} SongUpdateEvent; // size = 0x1C or 0x20

// unfortunately, cant use bitfield for this
// format: ABCC00DD
// A = playerID
// B = trackIndex
// C = musicEventID
// D = scriptSelector
typedef u32 MusicEventTrigger;

// allows Evt scripts to be triggered by BGM commands
typedef struct MusicEvent {
    s32 musicEventID; // user-defined, events will respond to BGM Trigger commands with matching ID
    EvtScript* scripts[4];
} MusicEvent;

typedef struct ParadeNpcInfo {
    /* 0x00 */ u32 initialAnim;
    /* 0x04 */ AnimID* animList;
    /* 0x08 */ Vec3f pos;
    /* 0x14 */ f32 yaw;
} ParadeNpcInfo; // size = 0x18

typedef struct CreditsEntry {
    /* 0x00 */ s32 msgID;
    /* 0x04 */ s32 posX;
    /* 0x08 */ s32 posY;
    /* 0x0C */ s32 palette;
    /* 0x10 */ s32 appearMode;
    /* 0x14 */ s32 appearTime;
    /* 0x18 */ s32 perCharDelayIn;
    /* 0x1C */ s32 holdMode;
    /* 0x20 */ s32 holdTime;
    /* 0x24 */ s32 vanishMode;
    /* 0x28 */ s32 vanishTime;
    /* 0x2C */ s32 perCharDelayOut;
    /* 0x30 */ s32 next;
    /* 0x34 */ s16 flags;
    /* 0x36 */ char pad_36[2];
} CreditsEntry; // size = 0x38

typedef struct CreditsLine {
    /* 0x00 */ u8* message;
    /* 0x04 */ char unk_04[0x4];
    /* 0x08 */ s32 time;
    /* 0x0C */ s32 state;
    /* 0x10 */ s32 palette;
    /* 0x14 */ s32 msgWidth;
    /* 0x18 */ s32 appearMode;
    /* 0x1C */ s32 appearTime;
    /* 0x20 */ s32 perCharDelayIn;
    /* 0x24 */ char unk_24[0x10];
    /* 0x34 */ s32 holdMode;
    /* 0x38 */ s32 holdTime;
    /* 0x3C */ char unk_3C[0x10];
    /* 0x4C */ s32 vanishMode;
    /* 0x50 */ s32 vanishTime;
    /* 0x54 */ s32 perCharDelayOut;
    /* 0x58 */ char unk_58[0x10];
    /* 0x68 */ s32 posX;
    /* 0x6C */ s32 posY;
    /* 0x70 */ s16 flags;
    /* 0x72 */ char unk_72[2];
} CreditsLine; // size = 0x74

typedef struct CreditsChar {
    /* 0x00 */ s32 charIndex;
    /* 0x04 */ s32 font;
    /* 0x08 */ s32 variation;
    /* 0x0C */ s32 palette;
    /* 0x10 */ s32 posX;
    /* 0x14 */ s32 posY;
    /* 0x18 */ s32 fadeInTime;
} CreditsChar; // size = unk

typedef struct CreditsData {
    /* 0x00 */ u32 workerID;
    /* 0x04 */ CreditsLine lines[32];
} CreditsData; // size = 0x74

typedef struct CreditsPairOffset {
    /* 0x00 */ u8 firstChar;
    /* 0x01 */ u8 secondChar;
    /* 0x02 */ s16 offset;
} CreditsPairOffset; // size = 0x4

typedef struct PartnerDMAData {
    /* 0x00 */ u32 dmaStart;
    /* 0x04 */ u32 dmaEnd;
    /* 0x08 */ void* dmaDest;
    /* 0x0C */ struct ActorBlueprint* ActorBlueprint;
    /* 0x10 */ s32 y;
} PartnerDMAData; // size = 0x14

typedef struct MsgVoice {
    /* 0x00 */ s32 voiceA;
    /* 0x04 */ s32 voiceB;
    /* 0x08 */ s32 pitchShift;
} MsgVoice; // size = 0x0C

typedef struct Rect {
    /* 0x00 */ s32 ulx;
    /* 0x04 */ s32 uly;
    /* 0x08 */ s32 lrx;
    /* 0x0C */ s32 lry;
} Rect; // size = 0x10

typedef struct LavaPiranhaVine {
    /* 0x000 */ Vec3f bonePos[9];
    /* 0x06C */ f32 boneRot[9];
    /* 0x090 */ s32 boneCount;
    /* 0x094 */ f32 boneLength;
    /* 0x098 */ Vec3f points[27];
    /* 0x1DC */ s32 numPoints;
} LavaPiranhaVine;

typedef struct SpeechBubbleData {
    /* 0x00 */ Npc* encounteredNPC;
    /* 0x04 */ Vec3f pos;
    /* 0x10 */ f32 yaw;
    /* 0x14 */ f32 scale;
    /* 0x18 */ s32 unk_18;
    /* 0x1C */ f32 unk_1C; //lastPosY?
    /* 0x20 */ s32 holdTime;
    /* 0x24 */ char unk_24[6];
    /* 0x2A */ u8 state;
    /* 0x2B */ u8 brightness;
} SpeechBubbleData; /* size = 0x2C */

#endif
