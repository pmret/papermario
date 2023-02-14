#include "common.h"
#include "audio.h"
#include "model.h"

typedef s32 TlbEntry[0x1000 / 4];
typedef TlbEntry TlbMappablePage[15];

BSS TlbMappablePage D_80197000;
BSS u8 D_801A6000[0x1000];
BSS u8 BattleEntityHeapBottom[0x3000];
BSS u8 AuHeapBase[AUDIO_HEAP_SIZE];
BSS u8 D_80200000[0x4000];
BSS u8 D_80204000[0x3000];
BSS u8 D_80207000[0x3000];
BSS u8 D_8020A000[0x6000];
BSS ShapeFile gMapShapeData;
