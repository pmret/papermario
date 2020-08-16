#ifndef _COMMON_STRUCTS_H_
#define _COMMON_STRUCTS_H_

#include "ultra64.h"
#include "types.h"

typedef struct Vec3f {
    /* 0x00 */ f32 x;
    /* 0x04 */ f32 y;
    /* 0x08 */ f32 z;
} Vec3f; // size = 0x0C

typedef struct Matrix4f {
    /* 0x00 */ f32 mtx[4][4];
} Matrix4f; // size = 0x40

typedef struct Matrix4s {
    /* 0x00 */ s16 whole[4][4];
    /* 0x20 */ s16 frac[4][4];
} Matrix4s; // size = 0x40

typedef struct CamPosSettings {
    /* 0x00 */ f32 boomYaw;
    /* 0x04 */ f32 boomLength;
    /* 0x08 */ f32 boomPitch;
    /* 0x0C */ f32 viewPitch;
    /* 0x10 */ struct Vec3f position;
} CamPosSettings; // size = 0x1C

typedef struct PartnerData {
    /* 0x00 */ u8 enabled;
    /* 0x01 */ u8 level;
    /* 0x02 */ s16 unk_02[3];
} PartnerData; // size = 0x08

typedef struct HeapNode {
    /* 0x00 */ UNK_PTR next;
    /* 0x04 */ s32 length;
    /* 0x08 */ s16 allocated;
    /* 0x0A */ s16 entryID;
    /* 0x0C */ s32 capacity;
} HeapNode; // size = 0x10

typedef struct NpcBlurData {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ f32 xpos[20];
    /* 0x54 */ f32 ypos[20];
    /* 0xA4 */ f32 zpos[20];
} NpcBlurData; // size = 0xF4

typedef struct Npc {
    /* 0x000 */ s32 flags;
    /* 0x004 */ UNK_PTR onUpdate; /* run before anything else for this npc in the npc update step */
    /* 0x008 */ UNK_PTR onRender; /* run after the display list for this npc is built */
    /* 0x00C */ f32 yaw;
    /* 0x010 */ f32 planarFlyDist; /* also used for speech, temp0? */
    /* 0x014 */ f32 jumpScale; /* also used for speech, temp1? */
    /* 0x018 */ f32 moveSpeed;
    /* 0x01C */ f32 jumpVelocity;
    /* 0x020 */ struct NpcBlurData* blurData; /* related to movement somehow... */
    /* 0x024 */ char unk_24[4];
    /* 0x028 */ u32 currentAnim;
    /* 0x02C */ char unk_2C[12];
    /* 0x038 */ struct Vec3f pos;
    /* 0x044 */ struct Vec3f rotation;
    /* 0x050 */ char unk_50[4];
    /* 0x054 */ struct Vec3f scale;
    /* 0x060 */ struct Vec3f moveToPos;
    /* 0x06C */ struct Vec3f colliderPos; /* used during collision with player */
    /* 0x078 */ s32 shadowIndex;
    /* 0x07C */ f32 shadowScale;
    /* 0x080 */ char unk_80[8];
    /* 0x088 */ s16 isFacingAway;
    /* 0x08A */ s16 yawCamOffset;
    /* 0x08C */ char unk_8C[2];
    /* 0x08E */ s16 duration; /* formerly interp_counter */
    /* 0x090 */ s16 homePos[3];
    /* 0x096 */ char unk_96[14];
    /* 0x0A4 */ u8 npcID;
    /* 0x0A5 */ char unk_A5;
    /* 0x0A6 */ s16 collisionRadius;
    /* 0x0A8 */ s16 collisionHeight;
    /* 0x0AA */ u8 renderMode;
    /* 0x0AB */ char unk_AB[661];
} Npc; // size = 0x340

typedef struct PlayerData {
    /* 0x000 */ u8 bootsLevel;
    /* 0x001 */ s8 hammerLevel;
    /* 0x002 */ s8 curHP;
    /* 0x003 */ s8 curMaxHP;
    /* 0x004 */ u8 hardMaxHP;
    /* 0x005 */ s8 curFP;
    /* 0x006 */ s8 curMaxFP;
    /* 0x007 */ u8 hardMaxFP;
    /* 0x008 */ u8 maxBP;
    /* 0x009 */ u8 level;
    /* 0x00A */ u8 hasActionCommands;
    /* 0x00B */ char unk_0B;
    /* 0x00C */ s16 coins;
    /* 0x00E */ s8 fortressKeyCount;
    /* 0x00F */ u8 starPieces;
    /* 0x010 */ s8 starPoints;
    /* 0x011 */ char unk_11;
    /* 0x012 */ u8 currentPartner;
    /* 0x013 */ char unk_13;
    /* 0x014 */ struct PartnerData partners[12];
    /* 0x074 */ s16 keyItems[32];
    /* 0x0B4 */ s16 badges[128];
    /* 0x1B4 */ s16 invItems[10];
    /* 0x1C8 */ s16 storedItems[32];
    /* 0x208 */ s16 equippedBadges[64];
    /* 0x288 */ char unk_288;
    /* 0x289 */ u8 merleeSpellType;
    /* 0x28A */ u8 merleeCastsLeft;
    /* 0x28B */ char unk_28B;
    /* 0x28C */ s16 merleeTurnCount;
    /* 0x28E */ s8 maxStarPower;
    /* 0x28F */ char unk_28F;
    /* 0x290 */ s16 specialBarsFilled;
    /* 0x292 */ char unk_292[2];
    /* 0x294 */ s16 otherHitsTaken;
    /* 0x296 */ s16 unk_296;
    /* 0x298 */ s16 hitsTaken;
    /* 0x29A */ s16 hitsBlocked;
    /* 0x29C */ s16 playerFirstStrikes;
    /* 0x29E */ s16 enemyFirstStrikes;
    /* 0x2A0 */ s16 powerBounces;
    /* 0x2A2 */ s16 battlesCount;
    /* 0x2A4 */ s16 unk_2A4[4];
    /* 0x2AC */ s32 unk_2AC;
    /* 0x2B0 */ s32 unk_2B0;
    /* 0x2B4 */ u32 totalCoinsEarned;
    /* 0x2B8 */ s16 idleFrameCounter; /* frames with no inputs, overflows ever ~36 minutes of idling */
    /* 0x2BA */ char unk_2BA[2];
    /* 0x2BC */ s32 frameCounter; /* increases by 2 per frame */
    /* 0x2C0 */ s16 quizzesAnswered;
    /* 0x2C2 */ s16 quizzesCorrect;
    /* 0x2C4 */ s32 unk_2C4[12];
    /* 0x2F4 */ s32 unk_2F4[12];
    /* 0x324 */ char unk_324;
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

typedef struct Trigger {
    /* 0x00 */ s16 genericFlagIndex;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ s16 crateFlagIndex;
    /* 0x06 */ s16 panelFlagIndex;
    /* 0x08 */ s32 colliderID;
    /* 0x0C */ UNK_FUN_PTR(functionHandler);
    /* 0x10 */ bytecode* scriptStart;
    /* 0x14 */ struct Script* runningScript;
    /* 0x18 */ s32 priority;
    /* 0x1C */ s32 scriptVars[3];
    /* 0x28 */ char unk_28[12];
    /* 0x34 */ s32 runningScriptID;
} Trigger; // size = 0x38

typedef struct Enemy {
    /* 0x00 */ s32 flags;
    /* 0x04 */ u8 encounterIndex;
    /* 0x05 */ s8 encountered;
    /* 0x06 */ u8 scriptGroup; /* scripts launched for this npc controller will be assigned this group */
    /* 0x07 */ char unk_07;
    /* 0x08 */ s16 npcID;
    /* 0x0A */ s16 spawnPos[3];
    /* 0x10 */ char unk_10[8];
    /* 0x18 */ struct StaticNpcSettings* npcSettings;
    /* 0x1C */ bytecode* initBytecode;
    /* 0x20 */ bytecode* interactBytecode;
    /* 0x24 */ bytecode* aiBytecode;
    /* 0x28 */ bytecode* hitBytecode;
    /* 0x2C */ bytecode* auxBytecode;
    /* 0x30 */ bytecode* defeatBytecode;
    /* 0x34 */ struct Script* initScript;
    /* 0x38 */ struct Script* interactScript;
    /* 0x3C */ struct Script* aiScript;
    /* 0x40 */ struct Script* hitScript;
    /* 0x44 */ struct Script* auxScript;
    /* 0x48 */ struct Script* defeatScript;
    /* 0x4C */ s32 initScriptID;
    /* 0x50 */ s32 interactScriptID;
    /* 0x54 */ s32 aiScriptID;
    /* 0x58 */ s32 hitScriptID;
    /* 0x5C */ s32 auxScriptID;
    /* 0x60 */ s32 defeatScriptID;
    /* 0x64 */ char unk_64[8];
    /* 0x6C */ s32 varTable[16];
    /* 0xAC */ char unk_AC[12];
    /* 0xB8 */ s32 unkSettings24;
    /* 0xBC */ char unk_BC[16];
    /* 0xCC */ UNK_PTR animList;
    /* 0xD0 */ UNK_PTR territoryData;
    /* 0xD4 */ UNK_PTR dropTables;
    /* 0xD8 */ u32 tattleString;
    /* 0xDC */ char unk_DC[20];
} Enemy; // size = 0xF0

typedef struct StaticNpcSettings {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ s16 height;
    /* 0x06 */ s16 radius;
    /* 0x08 */ UNK_PTR otherAI;
    /* 0x0C */ bytecode* interactScript;
    /* 0x10 */ bytecode* aiScript;
    /* 0x14 */ bytecode* hitScript;
    /* 0x18 */ bytecode* auxScript;
    /* 0x1C */ bytecode* defeatScript;
    /* 0x20 */ s32 flags;
    /* 0x24 */ char unk_24[4];
    /* 0x28 */ s16 level;
    /* 0x2A */ s16 unkFlags;
} StaticNpcSettings; // size = 0x2C

typedef struct Script {
    /* 0x000 */ u8 state;
    /* 0x001 */ u8 currentArgc;
    /* 0x002 */ u8 currentOpcode;
    /* 0x003 */ u8 priority;
    /* 0x004 */ u8 groupFlags;
    /* 0x005 */ u8 blocked; /* 1 = blocking */
    /* 0x006 */ s8 loopDepth; /* how many nested loops we are in, >= 8 hangs forever */
    /* 0x007 */ s8 switchDepth; /* how many nested switches we are in, max = 8 */
    /* 0x008 */ bytecode* ptrNextLine;
    /* 0x00C */ bytecode* ptrReadPos;
    /* 0x010 */ u8 labelIndices[16];
    /* 0x020 */ UNK_PTR labelPositions[16];
    /* 0x060 */ s32 deleted; /* set to zero in KillScript when malloc'd */
    /* 0x064 */ struct Script* blockingParent; /* parent? */
    /* 0x068 */ struct Script* childScript;
    /* 0x06C */ struct Script* parentScript; /* brother? */
    /* 0x070 */ s32 functionTemp[4];
    /* 0x080 */ UNK_PTR callFunction;
    /* 0x084 */ s32 varTable[16];
    /* 0x0C4 */ s32 varFlags[3];
    /* 0x0D0 */ s32 loopStartTable[8];
    /* 0x0F0 */ s32 loopCounterTable[8];
    /* 0x110 */ u8 switchBlockState[8];
    /* 0x118 */ s32 switchBlockValue[8];
    /* 0x138 */ s32* buffer;
    /* 0x13C */ UNK_PTR array;
    /* 0x140 */ UNK_PTR flagArray;
    /* 0x144 */ s32 uniqueID;
    /* 0x148 */ struct Enemy* ownerActorID; /* controller*, battle ID, trigger* */
    /* 0x14C */ u32 ownerID; /* can be an npcID, a triggerID, a trigger ptr */
    /* 0x150 */ f32 timeScale;
    /* 0x154 */ f32 frameCounter;
    /* 0x158 */ char unk_158[4];
    /* 0x15C */ bytecode* ptrFirstLine;
    /* 0x160 */ bytecode* ptrSavedPosition;
    /* 0x164 */ bytecode* ptrCurrentLine;
} Script; // size = 0x168

typedef struct Entity {
    /* 0x00 */ s32 flags;
    /* 0x04 */ char unk_04[7];
    /* 0x0B */ u8 alpha; /* reported by rain */
    /* 0x0C */ s16 aabb[3];
    /* 0x12 */ char unk_12[4];
    /* 0x16 */ s16 shadowIndex;
    /* 0x18 */ char unk_18[16];
    /* 0x28 */ bytecode* boundScript;
    /* 0x2C */ char unk_2C[12];
    /* 0x38 */ struct StaticEntityData* static_data;
    /* 0x3C */ char unk_3C[4];
    /* 0x40 */ struct Trigger* trigger;
    /* 0x44 */ s32* vertexData;
    /* 0x48 */ f32 position[3];
    /* 0x54 */ f32 scale[3];
    /* 0x60 */ f32 rotation[3];
    /* 0x6C */ char unk_6C[4];
    /* 0x70 */ struct Matrix4f* inverseTransformMatrix; /* world-to-local */
    /* 0x74 */ char unk_74[60];
    /* 0xB0 */ u8 radius; /* Created by retype action */
    /* 0xB1 */ char unk_B1[71];
} Entity; // size = 0xF8

typedef struct StaticEntityData {
    /* 0x00 */ s16 flags;
    /* 0x02 */ s16 argSize;
    /* 0x04 */ char unk_04[8];
    /* 0x0C */ UNK_FUN_PTR(unk_data_func);
    /* 0x10 */ UNK_PTR unk_data_ptr1;
    /* 0x14 */ UNK_PTR unk_data_ptr2;
    /* 0x18 */ s32 dmaStart;
    /* 0x1C */ s32 dmaEnd;
    /* 0x20 */ char unk_20[4];
} StaticEntityData; // size = 0x24

typedef struct MusicPlayer {
    /* 0x00 */ s16 unkFlags;
    /* 0x02 */ char unk_02[2];
    /* 0x04 */ s32 fadeOutTime;
    /* 0x08 */ s32 fadeInTime;
    /* 0x0C */ char unk_0C[4];
    /* 0x10 */ s32 songID;
    /* 0x14 */ s32 variation;
    /* 0x18 */ char unk_18[24];
} MusicPlayer; // size = 0x30

typedef struct StaticNpc {
    /* 0x000 */ s32 ID;
    /* 0x004 */ struct StaticNpcSettings* npcSettings;
    /* 0x008 */ s32 spawnPos[3];
    /* 0x014 */ s32 flags;
    /* 0x018 */ bytecode* initScript;
    /* 0x01C */ char unk_1C[8];
    /* 0x024 */ s32 spawnYaw;
    /* 0x028 */ s16 itemDrops[25];
    /* 0x05A */ s16 heartDrops[32];
    /* 0x09A */ s16 flowerDrops[32];
    /* 0x0DA */ s16 minCoinBonus;
    /* 0x0DC */ s16 maxCoinBonus;
    /* 0x0DE */ char unk_DE[2];
    /* 0x0E0 */ s32 movementData[48];
    /* 0x1A0 */ s32 animations[16];
    /* 0x1E0 */ char unk_1E0[8];
    /* 0x1E8 */ UNK_PTR extraAnimations;
    /* 0x1EC */ s32 tattle;
} StaticNpc; // size = 0x1F0

typedef struct MenuIcon {
    /* 0x00 */ u32 flags;
    /* 0x04 */ u32* readPos;
    /* 0x08 */ u32* startReadPos;
    /* 0x0C */ u32* ptrPropertyList;
    /* 0x10 */ u32* imageAddr;
    /* 0x14 */ u32* paletteAddr;
    /* 0x18 */ u32 memOffset;
    /* 0x1C */ char unk_1C[24];
    /* 0x34 */ f32 widthScaleF; /* X.10 fmt (divide by 1024.0 to get float) */
    /* 0x38 */ f32 heightScaleF; /* X.10 fmt (divide by 1024.0 to get float) */
    /* 0x3C */ s16 renderPosX;
    /* 0x3E */ s16 renderPosY;
    /* 0x40 */ u8 screenPosOffset[2];
    /* 0x42 */ u8 worldPosOffset[3];
    /* 0x45 */ char unk_45[2];
    /* 0x47 */ u8 updateTimer;
    /* 0x48 */ u8 sizeX; /* screen size? */
    /* 0x49 */ u8 sizeY; /* screen size? */
    /* 0x4A */ char unk_4A[10];
} MenuIcon; // size = 0x54

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
    /* 0x18 */ f32* vertexTable[3];
} Collider; // size = 0x1C

typedef struct Camera {
    /* 0x000 */ s16 flags;
    /* 0x002 */ s16 moveFlags;
    /* 0x004 */ s16 mode;
    /* 0x006 */ char unk_06[4];
    /* 0x00A */ s16 viewportW;
    /* 0x00C */ s16 viewportH;
    /* 0x00E */ s16 viewportStartX;
    /* 0x010 */ s16 viewportStartY;
    /* 0x012 */ s16 nearClip;
    /* 0x014 */ s16 farClip;
    /* 0x016 */ char unk_16[2];
    /* 0x018 */ f32 vfov;
    /* 0x01C */ char unk_1C[14];
    /* 0x02A */ s16 zoomPercent;
    /* 0x02C */ s16 backgroundColor[3];
    /* 0x032 */ s16 targetScreenCoords[3];
    /* 0x038 */ s16 perspNorm;
    /* 0x03A */ char unk_3A[2];
    /* 0x03C */ f32 lookAt_eye[3];
    /* 0x048 */ f32 lookAt_obj[3];
    /* 0x054 */ char unk_54[12];
    /* 0x060 */ struct Vec3f targetPos;
    /* 0x06C */ f32 currentYaw;
    /* 0x070 */ char unk_70[4];
    /* 0x074 */ f32 currentBoomYaw;
    /* 0x078 */ f32 currentBoomLength;
    /* 0x07C */ f32 currentYOffset;
    /* 0x080 */ char unk_80[4];
    /* 0x084 */ f32 trueRotation[3];
    /* 0x090 */ f32 currentBlendedYawNegated;
    /* 0x094 */ f32 currentPitch;
    /* 0x098 */ char unk_98[60];
    /* 0x0D4 */ struct Matrix4f perspectiveMatrix;
    /* 0x114 */ struct Matrix4f viewMtxPlayer; /* centers on player */
    /* 0x154 */ struct Matrix4f viewMtxLeading; /* leads player slightly */
    /* 0x194 */ struct Matrix4f viewMtxShaking; /* used while ShakeCam is active */
    /* 0x1D4 */ char unk_1D4[48];
    /* 0x204 */ struct Matrix4s* unkMatrix;
    /* 0x208 */ char unk_208[572];
    /* 0x444 */ struct Zone* prevZone;
    /* 0x448 */ struct Zone* currentZone;
    /* 0x44C */ struct CamPosSettings initialSettings; /* for start of blend between zones */
    /* 0x468 */ struct CamPosSettings targetSettings; /* goal for blend between zones */
    /* 0x484 */ f32 sinInterpAlpha;
    /* 0x488 */ f32 linearInterp;
    /* 0x48C */ f32 linearInterpScale; /* 3.0? */
    /* 0x490 */ f32 moveSpeed;
    /* 0x494 */ char unk_494[28];
    /* 0x4B0 */ struct Vec3f movePos;
    /* 0x4BC */ char unk_4BC[28];
    /* 0x4D8 */ s32 controllerType;
    /* 0x4DC */ f32 controllerBoomLen;
    /* 0x4E0 */ f32 controllerBoomPitch;
    /* 0x4E4 */ struct Vec3f posA;
    /* 0x4F0 */ struct Vec3f posB;
    /* 0x4FC */ f32 controllerViewPitch;
    /* 0x500 */ char unk_500[4];
    /* 0x504 */ s16 boolTargetPlayer;
    /* 0x506 */ char unk_506[2];
    /* 0x508 */ s32 panPhase;
    /* 0x50C */ f32 leadAmount;
    /* 0x510 */ char unk_510[36];
    /* 0x534 */ struct ColliderBoundingBox* aabbForZoneBelow;
    /* 0x538 */ char unk_538[32];
} Camera; // size = 0x558

typedef struct BattleStatus {
    /* 0x000 */ s32 flags1;
    /* 0x004 */ s32 flags2;
    /* 0x008 */ s32 varTable[16];
    /* 0x048 */ u8 currentSubmenu;
    /* 0x049 */ char unk_49[10];
    /* 0x053 */ u8 stratsLastCursorPos;
    /* 0x054 */ char unk_54[36];
    /* 0x078 */ u8 totalStarPoints;
    /* 0x079 */ u8 pendingStarPoints; /* how many to add */
    /* 0x07A */ u8 incrementStarPointDelay; /* related to star points, set to 0x28 when they are dropped */
    /* 0x07B */ u8 damageTaken;
    /* 0x07C */ u8 changePartnerAllowed;
    /* 0x07D */ char unk_7D[10];
    /* 0x087 */ u8 blockResult; /* 0 = fail, 1 = success, -1 = mashed */
    /* 0x088 */ u8 itemUsesLeft; /* set to 2 for doublke dip, 3 for triple */
    /* 0x089 */ u8 hpDrainCount;
    /* 0x08A */ char unk_8A;
    /* 0x08B */ u8 hustleTurns; /* numTurns from hustle drink, normally 0 */
    /* 0x08C */ char unk_8C[2];
    /* 0x08E */ u8 initialEnemyCount; /* used for SP award bonus */
    /* 0x08F */ char unk_8F[7];
    /* 0x096 */ u8 hammerCharge;
    /* 0x097 */ u8 jumpCharge;
    /* 0x098 */ char unk_98;
    /* 0x099 */ u8 dangerFlags; /* 1 = danger, 2 = peril */
    /* 0x09A */ u8 outtaSightActive;
    /* 0x09B */ u8 turboChargeTurnsLeft;
    /* 0x09C */ u8 turboChargeAmount; /* unused? */
    /* 0x09D */ u8 waterBlockTurnsLeft;
    /* 0x09E */ u8 waterBlockAmount; /* unused? */
    /* 0x09F */ char unk_9F[5];
    /* 0x0A4 */ u8 cloudNineTurnsLeft;
    /* 0x0A5 */ u8 cloudNineDodgeChance; /* = 50% */
    /* 0x0A6 */ char unk_A6[2];
    /* 0x0A8 */ s32 cloudNineEffect;
    /* 0x0AC */ char unk_AC[2];
    /* 0x0AE */ u8 hammerLossTurns;
    /* 0x0AF */ u8 jumpLossTurns;
    /* 0x0B0 */ u8 itemLossTurns;
    /* 0x0B1 */ char unk_B1[3];
    /* 0x0B4 */ UNK_FUN_PTR(preUpdateCallback);
    /* 0x0B8 */ char unk_B8[4];
    /* 0x0BC */ struct Script* controlScript; /* control handed over to this when changing partners, maybe general? */
    /* 0x0C0 */ s32 controlScriptID;
    /* 0x0C4 */ struct Script* camMovementScript;
    /* 0x0C8 */ s32 camMovementScriptID;
    /* 0x0CC */ char unk_CC[12];
    /* 0x0D8 */ struct Actor* playerActor;
    /* 0x0DC */ struct Actor* partnerActor;
    /* 0x0E0 */ struct Actor* enemyActors[24];
    /* 0x0E4 */ char unk_E4[92];
    /* 0x140 */ s16 enemyIDs[24];
    /* 0x170 */ char unk_170;
    /* 0x171 */ u8 numEnemyActors;
    /* 0x172 */ char unk_172[6];
    /* 0x178 */ u8 moveCategory;
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
    /* 0x199 */ u8 wasStatusInflicted; /* during last attack */
    /* 0x19A */ char unk_19A[6];
    /* 0x1A0 */ s16 currentTargetID; /* selected? */
    /* 0x1A2 */ u8 currentTargetPart; /* selected? */
    /* 0x1A3 */ char unk_1A3;
    /* 0x1A4 */ s16 currentTargetID2;
    /* 0x1A6 */ u8 currentTargetPart2;
    /* 0x1A7 */ u8 battlePhase;
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
    /* 0x21C */ f32 stickX;
    /* 0x220 */ f32 stickY;
    /* 0x224 */ s32 inputBitmask;
    /* 0x228 */ s32 dpadX; /* 0-360 */
    /* 0x22C */ s32 dpadY; /* 0-60 */
    /* 0x230 */ s32 holdInputBuffer[64];
    /* 0x330 */ s32 pushInputBuffer[64];
    /* 0x430 */ u8 holdInputBufferPos;
    /* 0x431 */ u8 inputBufferPos;
    /* 0x432 */ char unk_432[6];
    /* 0x438 */ s32* foregroundModelList;
    /* 0x43C */ UNK_PTR turboChargeCounter;
    /* 0x440 */ u8 tattleFlags[27];
    /* 0x45B */ char unk_45B[17];
    /* 0x46C */ s32 battleState; /* 0 = load assets, 1 = create actors, 4 = start scripts, 7 & 8 = unk */
    /* 0x470 */ char unk_470[10];
    /* 0x47A */ u8 currentBattleSection;
    /* 0x47B */ char unk_47B[21];
} BattleStatus; // size = 0x490

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

typedef struct StaticActorData {
    /* 0x00 */ s32 flags;
    /* 0x04 */ char unk_04;
    /* 0x05 */ u8 type;
    /* 0x06 */ u8 level;
    /* 0x07 */ u8 maxHP;
    /* 0x08 */ s16 partCount;
    /* 0x0A */ char unk_0A[2];
    /* 0x0C */ struct StaticActorPart** partsData;
    /* 0x10 */ UNK_PTR script;
    /* 0x14 */ UNK_PTR statusTable;
    /* 0x18 */ u8 escapeChance;
    /* 0x19 */ u8 airLiftChance;
    /* 0x1A */ u8 spookChance;
    /* 0x1B */ u8 baseStatusChance;
    /* 0x1C */ u8 upAndAwayChance;
    /* 0x1D */ u8 spinSmashReq;
    /* 0x1E */ u8 powerBounceChance;
    /* 0x1F */ u8 coinReward;
    /* 0x20 */ u8 size[2];
    /* 0x22 */ u8 hpBarOffset[2];
    /* 0x24 */ u8 statusIconOffset[2];
    /* 0x26 */ u8 statusMessageOffset[2];
} StaticActorData; // size = 0x28

typedef struct Move {
    /* 0x00 */ s32 moveNameID;
    /* 0x04 */ s32 flags;
    /* 0x08 */ s32 worldDescID;
    /* 0x0C */ s32 menuDescID;
    /* 0x10 */ u8 battleSubmenu;
    /* 0x11 */ u8 costFP;
    /* 0x12 */ u8 costBP;
    /* 0x13 */ u8 actionCommandID;
} Move; // size = 0x14

typedef struct CollisionData {
    /* 0x00 */ f32* vertices[3];
    /* 0x04 */ struct Collider* collider_list;
    /* 0x08 */ struct ColliderBoundingBox** aabbs;
    /* 0x0C */ s16 numColliders;
    /* 0x0E */ char unk_0E[2];
} CollisionData; // size = 0x10

typedef struct Model {
    /* 0x00 */ s16 flags;
    /* 0x02 */ s16 modelID;
    /* 0x04 */ char unk_04[4];
    /* 0x08 */ s32* modelNode;
    /* 0x0C */ struct ModelGroupData* groupData;
    /* 0x10 */ s32* currentSpecialMatrix;
    /* 0x14 */ char unk_14[4];
    /* 0x18 */ struct Matrix4s specialMatrix;
    /* 0x58 */ struct Matrix4f transformMatrix;
    /* 0x98 */ f32 center[3]; /* Created by retype action */
    /* 0xA4 */ u8 texPannerID;
    /* 0xA5 */ u8 specialDisplayListID;
    /* 0xA6 */ u8 renderMode; /* Created by retype action */
    /* 0xA7 */ char unk_A7;
    /* 0xA8 */ u8 textureID;
    /* 0xA9 */ char unk_A9[7];
} Model; // size = 0xB0

typedef struct AnimatedMesh {
    /* 0x000 */ s32 flags;
    /* 0x004 */ u8 renderMode;
    /* 0x005 */ char unk_05[3];
    /* 0x008 */ u32* animation1;
    /* 0x00C */ u32* animation2;
    /* 0x010 */ char unk_10[136];
    /* 0x098 */ struct Matrix4s mtx;
    /* 0x0D8 */ char unk_D8[500];
    /* 0x2CC */ s32 time;
    /* 0x2D0 */ char unk_2D0[16];
} AnimatedMesh; // size = 0x2E0

typedef struct PrintHandle {
    /* 0x000 */ char unk_00[16];
    /* 0x010 */ s8* printbuf; /* Created by retype action */
    /* 0x014 */ char unk_14[1344];
} PrintHandle; // size = 0x554

typedef struct OtherPrint {
    /* 0x00 */ char unk_00[16];
    /* 0x10 */ f32 stringScaleH;
    /* 0x14 */ f32 stringScaleW;
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

typedef struct Item {
    /* 0x00 */ s32 nameString;
    /* 0x04 */ s16 iconID;
    /* 0x06 */ s16 badgeSortPriority;
    /* 0x08 */ s32 targetFlags;
    /* 0x0C */ s16 sellValue;
    /* 0x0E */ char unk_0E[2];
    /* 0x10 */ s32 menuString;
    /* 0x14 */ s32 itemString;
    /* 0x18 */ s16 typeFlags;
    /* 0x1A */ u8 moveID;
    /* 0x1B */ u8 potencyA;
    /* 0x1C */ u8 potencyB;
    /* 0x1D */ char unk_1D[3];
} Item; // size = 0x20

typedef struct Effect {
    /* 0x00 */ char unk_00[32];
} Effect; // size = 0x20

typedef struct ItemEntity {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s16 boundVar; /* see make_item_entity */
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ struct Vec3f position;
    /* 0x14 */ struct ItemEntityPhysicsData* physicsData;
    /* 0x18 */ s16 itemID; /* into item table, also worldIconID */
    /* 0x1A */ u8 state;
    /* 0x1B */ u8 type;
    /* 0x1C */ u8 pickupDelay; /* num frames before item can be picked up */
    /* 0x1D */ char unk_1D;
    /* 0x1E */ s16 wsFaceAngle; /* < 0 means none */
    /* 0x20 */ s16 shadowIndex;
    /* 0x22 */ char unk_22[2];
    /* 0x24 */ u32* readPos;
    /* 0x28 */ u32* savedReadPos;
    /* 0x2C */ char unk_2C[2];
    /* 0x2E */ u8 unkCounter;
    /* 0x2F */ char unk_2F;
    /* 0x30 */ f32 scale;
    /* 0x34 */ char unk_34[40];
} ItemEntity; // size = 0x5C

typedef struct ModelNode {
    /* 0x00 */ s32 type; /* 2 = model */
    /* 0x04 */ UNK_PTR displayList;
    /* 0x08 */ s32 numProperties;
    /* 0x0C */ UNK_PTR propertyList;
    /* 0x10 */ struct ModelGroupData* groupData;
} ModelNode; // size = 0x14

typedef struct StaticShadowData {
    /* 0x00 */ s16 flags;
    /* 0x02 */ char unk_02[34];
} StaticShadowData; // size = 0x24

typedef struct SpriteComponent {
    /* 0x00 */ char unk_00[8];
    /* 0x08 */ s16** readPos;
    /* 0x0C */ f32 waitTime;
    /* 0x10 */ s32 loopCounter;
    /* 0x14 */ s32 currentRaster;
    /* 0x18 */ s32 currentPalette;
    /* 0x1C */ struct Vec3f posOffset;
    /* 0x28 */ struct Vec3f compPos;
    /* 0x34 */ struct Vec3f rotation;
    /* 0x40 */ struct Vec3f scale;
    /* 0x4C */ char unk_4C[4];
} SpriteComponent; // size = 0x50

typedef struct PrintContext {
    /* 0x000 */ s8* string;
    /* 0x004 */ s16 bufPos;
    /* 0x006 */ char unk_06[2];
    /* 0x008 */ s32 stringID;
    /* 0x00C */ char unk_0C[4];
    /* 0x010 */ u8 buffer[1024];
    /* 0x410 */ char unk_410[68];
    /* 0x454 */ u8 font;
    /* 0x455 */ char unk_455;
    /* 0x456 */ s16 startPosX;
    /* 0x458 */ s16 startPosY;
    /* 0x45A */ char unk_45A[45];
    /* 0x487 */ u8 unkArraySize;
    /* 0x488 */ s16 unkArrayunkLength[4];
    /* 0x490 */ char unk_490[108];
    /* 0x4FC */ s32 stateFlags;
    /* 0x500 */ char unk_500[9];
    /* 0x509 */ u8 lerpElpasedTime;
    /* 0x50A */ s16 startX;
    /* 0x50C */ s16 startY;
    /* 0x50E */ char unk_50E[6];
    /* 0x514 */ s16 sizeY;
    /* 0x516 */ s16 sizeX;
    /* 0x518 */ char unk_518[19];
    /* 0x52B */ u8 currentImageIndex;
    /* 0x52C */ char unk_52C[10];
    /* 0x536 */ s16 height;
    /* 0x538 */ s16 width;
    /* 0x53A */ char unk_53A[30];
} PrintContext; // size = 0x558

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
    /* 0x040 */ u8 stickX; /* with deadzone */
    /* 0x041 */ u8 altStickX; /* input used for batte when flag 80000 set */
    /* 0x042 */ char unk_42[2];
    /* 0x044 */ u8 stickY; /* with deadzone */
    /* 0x045 */ u8 altStickY; /* input used for batte when flag 80000 set */
    /* 0x046 */ char unk_46[34];
    /* 0x068 */ s16 demoButtonInput;
    /* 0x06A */ s8 demoStickX;
    /* 0x06B */ s8 demoStickY;
    /* 0x06C */ s32 mainScriptID;
    /* 0x070 */ s8 isBattle;
    /* 0x071 */ s8 demoState; /* (0 = not demo, 1 = map demo, 2 = demo map changing) */
    /* 0x072 */ u8 nextDemoScene; /* which part of the demo to play next */
    /* 0x073 */ u8 contBitPattern;
    /* 0x074 */ char unk_74[4];
    /* 0x078 */ u8 disableScripts;
    /* 0x079 */ char unk_79;
    /* 0x07A */ s8 musicEnabled;
    /* 0x07B */ char unk_7B[3];
    /* 0x07E */ u8 peachFlags; /* (1 = isPeach, 2 = isTransformed, 4 = hasUmbrella) */
    /* 0x07F */ u8 peachDisguise; /* (1 = koopatrol, 2 = hammer bros, 3 = clubba) */
    /* 0x080 */ char unk_80[6];
    /* 0x086 */ s16 areaID; /* Created by retype action */
    /* 0x088 */ s16 prevArea;
    /* 0x08A */ s16 changedArea; /* (1 = yes) */
    /* 0x08C */ s16 mapID;
    /* 0x08E */ s16 entryID;
    /* 0x090 */ char unk_90[4];
    /* 0x094 */ f32 exitAngle;
    /* 0x098 */ struct Vec3f playerPos;
    /* 0x0A4 */ f32 playerYaw;
    /* 0x0A8 */ char unk_A8[4];
    /* 0x0AC */ s8 loadMenuState;
    /* 0x0AD */ u8 menuCounter;
    /* 0x0AE */ char unk_AE[8];
    /* 0x0B6 */ s16 bootAlpha;
    /* 0x0B8 */ s16 bootBlue;
    /* 0x0BA */ s16 bootGreen;
    /* 0x0BC */ s16 bootRed;
    /* 0x0BE */ char unk_BE[106];
    /* 0x128 */ f32 playerTraceNormal[3];
    /* 0x134 */ u16 frameCounter;
    /* 0x136 */ char unk_136[2];
    /* 0x138 */ s32 nextRNG;
    /* 0x13C */ char unk_13C[4];
    /* 0x140 */ UNK_PTR shopItemData;
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
    /* 0x15E */ char unk_15E[0x2];
    /* 0x160 */ s16 savedPos[3];
    /* 0x166 */ s8 saveSlot;
    /* 0x167 */ u8 loadType; /* (0 = from map, 1 = from main menu) */
    /* 0x168 */ s32 saveCount;
    /* 0x16C */ char unk_16C[12];
} GameStatus; // size = 0x178

typedef struct PartnerAnimations {
    /* 0x00 */ char unk_00[36];
} PartnerAnimations; // size = 0x24

typedef struct Shadow {
    /* 0x00 */ s32 flags;
    /* 0x04 */ char unk_04[12];
    /* 0x10 */ struct Vec3f position;
    /* 0x1C */ struct Vec3f scale;
    /* 0x28 */ char unk_28[80];
} Shadow; // size = 0x78

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
    /* 0x04 */ s32 dist; /* value between 0 and -10k */
    /* 0x08 */ struct Model* model;
    /* 0x0C */ UNK_FUN_PTR(fpBuildDL); /* function for making display list for model */
} RenderTask; // size = 0x10

typedef struct SelectableTarget {
    /* 0x00 */ s16 actorID;
    /* 0x02 */ s16 partID; /* sometimes loaded as byte from 0x3 */
    /* 0x04 */ s16 pos[3];
    /* 0x0A */ char unk_0A[7];
    /* 0x11 */ u8 homeCol; /* from xpos --> 0-3 */
    /* 0x12 */ u8 homeRow; /* from ypos --> 0-3 */
    /* 0x13 */ u8 layer; /* from zpos? --> 0-1 */
} SelectableTarget; // size = 0x14

typedef struct ActorPartMovement {
    /* 0x00 */ char unk_00[12];
    /* 0x0C */ f32 goalPos[3];
    /* 0x18 */ char unk_18[12];
    /* 0x24 */ f32 jumpScale;
    /* 0x28 */ f32 moveSpeed;
    /* 0x2C */ char unk_2C[32];
    /* 0x4C */ s32 varTable[16];
} ActorPartMovement; // size = 0x8C

typedef struct ActorPart {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s32 targetFlags; /* initialized to 0 */
    /* 0x08 */ struct StaticActorPart* staticData;
    /* 0x0C */ struct ActorPart* nextPart;
    /* 0x10 */ struct ActorPartMovement* movement;
    /* 0x14 */ s16 partOffset[3];
    /* 0x1A */ s16 visualOffset[3];
    /* 0x20 */ struct Vec3f partOffsetFloat;
    /* 0x2C */ struct Vec3f absolutePosition;
    /* 0x38 */ struct Vec3f rotation;
    /* 0x44 */ s16 rotationPivotOffset[3];
    /* 0x4A */ char unk_4A[2];
    /* 0x4C */ f32 scale[3];
    /* 0x58 */ struct Vec3f currentPos;
    /* 0x64 */ f32 yaw;
    /* 0x68 */ s16 unkOffset[2];
    /* 0x6C */ s16 targetOffset[2];
    /* 0x70 */ s16 unk;
    /* 0x72 */ u8 size[2];
    /* 0x74 */ u8 verticalStretch;
    /* 0x75 */ char unk_75[3];
    /* 0x78 */ u32* defenseTable;
    /* 0x7C */ s32 eventFlags;
    /* 0x80 */ s32 partFlags3;
    /* 0x84 */ char unk_84[4];
    /* 0x88 */ s32 currentAnimation;
    /* 0x8C */ char unk_8C[4];
    /* 0x90 */ f32 animationRate;
    /* 0x94 */ u32* idleAnimations;
    /* 0x98 */ s16 opacity;
    /* 0x9A */ char unk_9A[2];
    /* 0x9C */ struct Shadow* shadow;
    /* 0xA0 */ f32 shadowScale;
    /* 0xA4 */ s32 partTypeData[6];
    /* 0xBC */ s16 actorTypeData2b[2];
    /* 0xC0 */ struct DecorationTable* decorationTable; /* initialized to 0 */
} ActorPart; // size = 0xC4

typedef struct ColliderTriangle {
    /* 0x00 */ f32* v1[3]; /* note: the order of v1,2,3 is reversed from the ijk in the hit file */
    /* 0x04 */ f32* v2[3];
    /* 0x08 */ f32* v3[3];
    /* 0x0C */ f32 e13[3]; /* = v3 - v1 */
    /* 0x18 */ f32 e21[3]; /* = v1 - v2 */
    /* 0x24 */ f32 e32[3]; /* = v2 - v3 */
    /* 0x30 */ f32 normal[3];
    /* 0x3C */ s16 oneSided; /* 1 = yes, 0 = no */
    /* 0x3E */ char unk_3E[2];
} ColliderTriangle; // size = 0x40

typedef struct Partner {
    /* 0x00 */ s32 dmaStart;
    /* 0x04 */ s32 dmaEnd;
    /* 0x08 */ s32 dmaDest;
    /* 0x0C */ s32 isFlying;
    /* 0x10 */ UNK_FUN_PTR(fpInit);
    /* 0x14 */ bytecode* spScriptA;
    /* 0x18 */ bytecode* spScriptB;
    /* 0x1C */ bytecode* spScriptC;
    /* 0x20 */ bytecode* spScriptD;
    /* 0x24 */ s32 idleAnim;
    /* 0x28 */ UNK_FUN_PTR(fpFuncA);
    /* 0x2C */ UNK_FUN_PTR(fpFuncB);
    /* 0x30 */ UNK_FUN_PTR(fpFuncC);
    /* 0x34 */ UNK_FUN_PTR(fpFuncD);
    /* 0x38 */ UNK_FUN_PTR(fpFuncE);
    /* 0x3C */ bytecode* spScriptX;
} Partner; // size = 0x40

typedef struct FontRasterSet {
    /* 0x00 */ u8 sizeX;
    /* 0x01 */ u8 sizeY;
    /* 0x02 */ char unk_02[10];
} FontRasterSet; // size = 0x0C

typedef struct TriggerBp {
    /* 0x00 */ s32 flags;
    /* 0x04 */ s16 colliderIndex;
    /* 0x06 */ char unk_06[2];
    /* 0x08 */ s32 flagIndex;
    /* 0x0C */ UNK_FUN_PTR(function);
    /* 0x10 */ char unk_10[8];
    /* 0x18 */ s32 inputArg3;
    /* 0x1C */ char unk_1C[4];
} TriggerBp; // size = 0x20

typedef struct CollisionStatus {
    /* 0x00 */ s16 pushingAgainstWall; /* FFFF = none for all below VVV */
    /* 0x02 */ s16 currentFloor; /* valid on touch */
    /* 0x04 */ s16 lastTouchedFloor; /* valid after jump */
    /* 0x06 */ s16 floorBelow;
    /* 0x08 */ s16 currentCeiling; /* valid on touching with head */
    /* 0x0A */ char unk_0A[8];
    /* 0x12 */ s16 currentWall;
    /* 0x14 */ s16 lastWallHammered; /* valid when smashing */
    /* 0x16 */ s16 touchingWallTrigger; /* 0/1 */
    /* 0x18 */ s16 bombetteExploded; /* 0 = yes, FFFF = no */
    /* 0x1A */ char unk_1A[2];
    /* 0x1C */ f32 bombetteExplositionPos[3];
} CollisionStatus; // size = 0x28

typedef struct DecorationTable {
    /* 0x000 */ char unk_00[2012];
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
    /* 0x8AD */ char unk_8AD[11];
    /* 0x8B8 */ u8 decorationType[2];
    /* 0x8BA */ char unk_8BA[46];
} DecorationTable; // size = 0x8E8

typedef struct Shop {
    /* 0x000 */ char unk_00[20];
    /* 0x014 */ UNK_PTR staticItemPositions;
    /* 0x018 */ UNK_PTR staticInventory;
    /* 0x01C */ UNK_PTR staticPriceList;
    /* 0x020 */ char unk_20[828];
} Shop; // size = 0x35C

typedef struct Encounter {
    /* 0x00 */ s32 count;
    /* 0x04 */ struct Enemy* enemy[16];
    /* 0x08 */ char unk_08[60];
    /* 0x44 */ s16 battle;
    /* 0x46 */ s16 stage;
    /* 0x48 */ s16 encounterID;
    /* 0x4A */ char unk_4A[2];
} Encounter; // size = 0x4C

typedef struct PlayerPathElement {
    /* 0x00 */ char unk_00[4];
    /* 0x04 */ struct Vec3f pos;
} PlayerPathElement; // size = 0x10

typedef struct AnimatedModel {
    /* 0x00 */ s32 animModelID;
    /* 0x04 */ struct Vec3f pos; /* Created by retype action */
    /* 0x10 */ struct Vec3f rot;
    /* 0x1C */ struct Vec3f scale;
    /* 0x28 */ struct Matrix4s* mtx;
    /* 0x2C */ char unk_2C[60];
    /* 0x68 */ u32 currentAnimData;
    /* 0x6C */ char unk_6C[4];
} AnimatedModel; // size = 0x70

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

typedef struct Zone {
    /* 0x00 */ s32 type;
    /* 0x04 */ f32 boomLength;
    /* 0x08 */ f32 boomPitch;
    /* 0x0C */ f32 pos[6];
    /* 0x24 */ f32 viewPitch;
    /* 0x28 */ s32 flag;
} Zone; // size = 0x2C

typedef struct Actor {
    /* 0x000 */ s32 flags;
    /* 0x004 */ char unk_04[4];
    /* 0x008 */ struct StaticActorData* staticActorData;
    /* 0x00C */ struct Vec3f moveCurrentPos;
    /* 0x018 */ struct Vec3f moveGoalPos;
    /* 0x024 */ struct Vec3f moveEndPos; /* where other actors should target this one at. saved before partner switching */
    /* 0x030 */ char unk_30[24];
    /* 0x048 */ f32 jumpAccel;
    /* 0x04C */ f32 moveSpeed;
    /* 0x050 */ f32 jumpVelocity;
    /* 0x054 */ f32 moveAngle;
    /* 0x058 */ f32 moveDistance; /* 2D projection, used for jump */
    /* 0x05C */ f32 bounceDivisor;
    /* 0x060 */ char unk_60[4];
    /* 0x064 */ s32 animJumpRise;
    /* 0x068 */ s32 animJumpFall;
    /* 0x06C */ s32 animJumpLand;
    /* 0x070 */ s16 moveTime;
    /* 0x072 */ s16 moveArcAmplitude;
    /* 0x074 */ char unk_74[3];
    /* 0x077 */ u8 jumpPartIndex;
    /* 0x078 */ char unk_78[16];
    /* 0x088 */ s32 varTable[16];
    /* 0x0C8 */ struct Vec3f flyCurrentPos;
    /* 0x0D4 */ struct Vec3f flyGoalPos;
    /* 0x0E0 */ struct Vec3f flyTempPos; /* used for start in fly functions, end in flyrun functions */
    /* 0x0EC */ char unk_EC[24];
    /* 0x104 */ f32 flyJumpAccel;
    /* 0x108 */ f32 flySpeed;
    /* 0x10C */ f32 flyJumpVelocity;
    /* 0x110 */ f32 flyAngleYaw;
    /* 0x114 */ f32 flyDistance;
    /* 0x118 */ f32 flyElapsed;
    /* 0x11C */ char unk_11C[4];
    /* 0x120 */ s16 flyTime;
    /* 0x122 */ s16 flyArcAmplitude;
    /* 0x124 */ char unk_124[17];
    /* 0x135 */ u8 footStepCounter;
    /* 0x136 */ u8 actorType;
    /* 0x137 */ char unk_137;
    /* 0x138 */ struct Vec3f homePos;
    /* 0x144 */ struct Vec3f currentPos;
    /* 0x150 */ s16 otherPosheadOffset[3];
    /* 0x156 */ s16 healthBarPosition[3];
    /* 0x15C */ f32 rotation[3];
    /* 0x168 */ s16 rotationPivotOffset[3];
    /* 0x16E */ char unk_16E[2];
    /* 0x170 */ f32 scale[3];
    /* 0x17C */ f32 scaleModifier[3]; /* multiplies normal scale factors componentwise */
    /* 0x188 */ f32 scalingFactor;
    /* 0x18C */ f32 yaw;
    /* 0x190 */ u8 size[2];
    /* 0x192 */ s16 actorID;
    /* 0x194 */ char unk_194[8];
    /* 0x19C */ s32 actorTypeData1[6]; /* 4 = jump sound */
    /* 0x1B4 */ s16 actorTypeData1b[2];
    /* 0x1B8 */ u8 currentHP;
    /* 0x1B9 */ u8 maxHP;
    /* 0x1BA */ char unk_1BA[2];
    /* 0x1BC */ u8 hpFraction; /* used to render HP bar */
    /* 0x1BD */ char unk_1BD[3];
    /* 0x1C0 */ bytecode* idleCode;
    /* 0x1C4 */ bytecode* takeTurnCode;
    /* 0x1C8 */ bytecode* onHitCode;
    /* 0x1CC */ bytecode* onTurnChangeCode;
    /* 0x1D0 */ struct Script* idleScript;
    /* 0x1D4 */ struct Script* takeTurnScript;
    /* 0x1D8 */ struct Script* onHitScript;
    /* 0x1DC */ struct Script* onTurnChangeScript;
    /* 0x1E0 */ s32 idleScriptID;
    /* 0x1E4 */ s32 takeTurnID;
    /* 0x1E8 */ s32 onHitID;
    /* 0x1EC */ s32 onTurnChangeID;
    /* 0x1F0 */ u8 lastEventType;
    /* 0x1F1 */ u8 turnPriority;
    /* 0x1F2 */ u8 enemyIndex; /* actorID = this | 200 */
    /* 0x1F3 */ u8 numParts;
    /* 0x1F4 */ struct ActorPart* partsTable;
    /* 0x1F8 */ s16 lastDamageTaken;
    /* 0x1FA */ s16 hpChangeCounter;
    /* 0x1FC */ s16 damageCounter;
    /* 0x1FE */ char unk_1FE[9];
    /* 0x207 */ u8 extraCoinBonus;
    /* 0x208 */ char unk_208[4];
    /* 0x20C */ u32* statusTable;
    /* 0x210 */ u8 debuff;
    /* 0x211 */ u8 debuffDuration;
    /* 0x212 */ u8 staticStatus; /* 0B = yes */
    /* 0x213 */ u8 staticDuration;
    /* 0x214 */ u8 stoneStatus; /* 0C = yes */
    /* 0x215 */ u8 stoneDuration;
    /* 0x216 */ u8 koStatus; /* 0D = yes */
    /* 0x217 */ u8 koDuration;
    /* 0x218 */ u8 transStatus; /* 0E = yes */
    /* 0x219 */ u8 transDuration;
    /* 0x21A */ char unk_21A[2];
    /* 0x21C */ u8 status;
    /* 0x21D */ char unk_21D[3];
    /* 0x220 */ u8 bGlowing;
    /* 0x221 */ u8 attackBoost;
    /* 0x222 */ u8 defenseBoost;
    /* 0x223 */ u8 chillOutAmount; /* attack reduction */
    /* 0x224 */ u8 chillOutTurns;
    /* 0x225 */ char unk_225[7];
    /* 0x22C */ struct SelectableTarget targetData[24];
    /* 0x40C */ u8 targetListLength;
    /* 0x40D */ u8 targetIndexList[24]; /* into targetData */
    /* 0x425 */ u8 selectedTargetIndex; /* into target index list */
    /* 0x426 */ u8 targetPartIndex;
    /* 0x427 */ char unk_427;
    /* 0x428 */ s16 targetActorID;
    /* 0x42A */ char unk_42A[2];
    /* 0x42C */ struct Shadow* shadow; /* might be shadow ID */
    /* 0x430 */ f32 shadowScale; /* = actor size / 24.0 */
    /* 0x434 */ s16 renderMode; /* initially 0xD, set to 0x22 if any part is transparent */
    /* 0x436 */ char unk_436[2];
    /* 0x438 */ s32 x[2]; /* ??? see FUN_80253974 */
    /* 0x440 */ struct MenuIcon* ptrDefuffIcon;
} Actor; // size = 0x444

typedef struct StaticActorPart {
    /* 0x00 */ s32 flags;
    /* 0x04 */ u8 index;
    /* 0x05 */ u8 posOffset[3];
    /* 0x08 */ u8 targetOffset[2];
    /* 0x0A */ s16 opacity;
    /* 0x0C */ u32* idleAnimations;
    /* 0x10 */ u32* defenseTable;
    /* 0x14 */ s32 eventFlags;
    /* 0x18 */ s32 flags3;
    /* 0x1C */ char unk_1C[8];
} StaticActorPart; // size = 0x24

typedef struct TileDescriptor {
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
} TileDescriptor; // size = 0x30

typedef struct BackgroundHeader {
    /* 0x00 */ u32 raster;
    /* 0x04 */ u32 palette;
    /* 0x08 */ u16 startX;
    /* 0x0A */ u16 startY;
    /* 0x0C */ u16 width;
    /* 0x0E */ u16 height;
} BackgroundHeader; // size = 0x10

typedef struct ModelGroupData {
    /* 0x00 */ UNK_PTR transformMatrix;
    /* 0x04 */ UNK_PTR lightingGroup;
    /* 0x08 */ s32 numLights;
    /* 0x0C */ s32 numChildren;
    /* 0x10 */ struct ModelNode** childList;
} ModelGroupData; // size = 0x14

typedef struct FontData {
    /* 0x00 */ char unk_00[24];
} FontData; // size = 0x18

typedef struct Crash {
    /* 0x000 */ char unk_00[20];
    /* 0x014 */ s32 threadID;
    /* 0x018 */ char unk_18[12];
    /* 0x024 */ s64 AT; /* Created by retype action */
    /* 0x02C */ s64 V0; /* Created by retype action */
    /* 0x034 */ s64 V1; /* Created by retype action */
    /* 0x03C */ s64 A0; /* Created by retype action */
    /* 0x044 */ s64 A1; /* Created by retype action */
    /* 0x04C */ s64 A2; /* Created by retype action */
    /* 0x054 */ s64 A3;
    /* 0x05C */ char unk_5C[16];
    /* 0x06C */ s32 T2;
    /* 0x070 */ char unk_70[168];
    /* 0x118 */ s32 SR; /* Created by retype action */
    /* 0x11C */ s32 PC;
    /* 0x120 */ s32 interrupt;
    /* 0x124 */ s32 VA; /* Created by retype action */
    /* 0x128 */ char unk_128[208];
} Crash; // size = 0x1F8

typedef struct PlayerStatus {
    /* 0x000 */ s32 flags;
    /* 0x004 */ u32 animFlags;
    /* 0x008 */ s16 framesOnGround; /* Number of frames since last jump landed */
    /* 0x00A */ char unk_0A[2];
    /* 0x00C */ u8 peachDisguise;
    /* 0x00D */ char unk_0D[5];
    /* 0x012 */ s16 moveFrames;
    /* 0x014 */ u8 enableCollisionOverlapsCheck;
    /* 0x015 */ u8 statusMenuCounterinputEnabledCounter; /* whether the C-up menu can appear */
    /* 0x016 */ s16 lastGoodPosition[3];
    /* 0x01C */ struct Vec3f extraVelocity;
    /* 0x028 */ struct Vec3f position;
    /* 0x034 */ char unk_34[16];
    /* 0x044 */ f32 decorationPos[2];
    /* 0x04C */ char unk_4C[4];
    /* 0x050 */ f32 jumpApexHeight;
    /* 0x054 */ s32 currentSpeed;
    /* 0x058 */ f32 walkSpeed;
    /* 0x05C */ f32 runSpeed;
    /* 0x060 */ char unk_60[8];
    /* 0x068 */ f32 normalPitch;
    /* 0x06C */ char unk_6C[4];
    /* 0x070 */ f32 gravityIntegrator[4];
    /* 0x080 */ f32 targetYaw;
    /* 0x084 */ f32 currentYaw;
    /* 0x088 */ char unk_88[24];
    /* 0x0A0 */ f32 heading;
    /* 0x0A4 */ char unk_A4[4];
    /* 0x0A8 */ f32 spriteFacingAngle; /* angle of sprite, relative to camera, from 0 to 180 */
    /* 0x0AC */ char unk_AC[4];
    /* 0x0B0 */ s16 colliderHeight;
    /* 0x0B2 */ s16 colliderDiameter;
    /* 0x0B4 */ u8 actionState;
    /* 0x0B5 */ u8 prevActionState;
    /* 0x0B6 */ u8 fallState;
    /* 0x0B7 */ char unk_B7;
    /* 0x0B8 */ s32 anim;
    /* 0x0BC */ char unk_BC[2];
    /* 0x0BE */ u8 renderMode;
    /* 0x0BF */ char unk_BF;
    /* 0x0C0 */ u32* decorationList;
    /* 0x0C4 */ char unk_C4[8];
    /* 0x0CC */ s32 shadowID;
    /* 0x0D0 */ char unk_D0[12];
    /* 0x0DC */ s32 currentButtons;
    /* 0x0E0 */ s32 pressedButtons;
    /* 0x0E4 */ s32 heldButtons;
    /* 0x0E8 */ f32 stickAxis[2];
    /* 0x0F0 */ s32 currentButtonsBuffer[10];
    /* 0x118 */ s32 pressedButtonsBuffer[10];
    /* 0x140 */ s32 heldButtonsBuffer[10];
    /* 0x168 */ f32 stickXBuffer[10];
    /* 0x190 */ f32 stickYBuffer[10];
    /* 0x1B8 */ s32 inputBufPos;
    /* 0x1BC */ char unk_1BC[204];
} PlayerStatus; // size = 0x288

typedef struct AnimatedModelNode {
    /* 0x00 */ u32* displayList;
    /* 0x04 */ s16 rot[3]; /* range = -180,180 */
    /* 0x0A */ char unk_0A[34];
} AnimatedModelNode; // size = 0x2C

typedef struct EncounterStatus {
    /* 0x00 */ s32 flags;
    /* 0x04 */ u8 eFirstStrike; /* 0 = none, 1 = player, 2 = enemy */
    /* 0x05 */ u8 hitType; /* 1 = none/enemy, 2 = jump */
    /* 0x06 */ u8 hitTier; /* 0 = normal, 1 = super, 2 = ultra */
    /* 0x07 */ char unk_07[2];
    /* 0x09 */ u8 battleOutcome; /* 0 = won, 1 = lost */
    /* 0x0A */ char unk_0A;
    /* 0x0B */ u8 merleeCoinBonus; /* triple coins when != 0 */
    /* 0x0C */ u8 damageTaken; /* valid after battle */
    /* 0x0D */ char unk_0D;
    /* 0x0E */ s16 coinsEarned; /* valid after battle */
    /* 0x10 */ char unk_10;
    /* 0x11 */ u8 allowFleeing;
    /* 0x12 */ char unk_12;
    /* 0x13 */ u8 dropWhackaBump;
    /* 0x14 */ s32 songID;
    /* 0x18 */ char unk_18[4];
    /* 0x1C */ u8 numEncounters; /* number of encounters for current map (in list) */
    /* 0x1D */ char unk_1D[3];
    /* 0x20 */ u8 mapID;
    /* 0x21 */ char unk_21[3];
    /* 0x24 */ s32* npcGroupList;
    /* 0x28 */ struct Encounter* enounterList[24];
    /* 0x2C */ char unk_2C[92];
    /* 0x88 */ struct Encounter* currentEncounter;
    /* 0x8C */ struct Enemy* currentEnemy;
    /* 0x90 */ char unk_90[4];
} EncounterStatus; // size = 0x94

#endif
