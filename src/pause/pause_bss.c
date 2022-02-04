#include "types.h"

#ifndef M2CTX
#define BSS __attribute__ ((section (".bss")))
#else
#define BSS static
#endif

BSS s32 gPauseHeldButtons;
BSS s32 gPausePressedButtons;
BSS s32 gPauseCurrentDescMsg;
BSS s32 gPauseCurrentDescIconScript;
BSS s32 gPauseCursorIconID;
BSS s8 gPauseMenuCurrentTab;
BSS s8 D_802700D[7]; //padding
BSS s32 gPauseTutorialFrameCounter;
BSS s32 D_802700E4; // padding
BSS s32 gPauseCommonIconIDs[8];
BSS s32 gPauseShownDescMsg;
BSS s32 gPauseDescTextMaxPos;
BSS s32 gPauseDescTextPos;
BSS s32 gPauseDescTextOffset;
BSS s32 gPauseShownDescIconScript;
BSS s32 gPauseTutorialSprites[3];
BSS s32 D_80270128[2]; // padding
BSS s32 gPauseTabsIconIDs[6];
BSS s32 gPauseTabsPreviousTab;
BSS s32 gPauseTabsHorizScrollPos;
BSS s32 gPauseStatsIconIDs[12];
BSS s16 gPauseBadgesItemIds[128];
BSS s32 gPauseBadgesCurrentPage;
BSS s32 D_80270284; // unused
BSS s32 gPauseBadgesPages[60];
BSS s32 gPauseBadgesSelectedIndex;
BSS s32 D_8027037C; // always zero
BSS s32 gPauseBadgesSelectedItem;
BSS s16 gPauseBadgesNumItems;
BSS s32 D_80270388; // always zero
BSS s32 gPauseBadgesCurrentScrollPos;
BSS s32 gPauseBadgesTargetScrollPos;
BSS s32 D_80270394;
BSS s32 gPauseBadgesLevel;
BSS s32 gPauseBadgesCurrentTab;
BSS s32 gPauseBadgesBShowNotEnoughBP;
BSS s32 D_802703A4; // unused
BSS s32 gPauseBadgesIconIDs[22];
BSS s16 gPauseItemsItemIDs[100];
BSS s32 gPauseItemsCurrentPage;
BSS s32 D_802704CC;
BSS s32 gPauseItemsPages[60];
BSS s32 gPauseItemsSelectedIndex;
BSS u32 D_802705C4;
BSS s32 gPauseItemsSelectedItem;
BSS s16 gPauseItemsNumItems;
BSS s16 D_802705CE;
BSS s32 D_802705D0;
BSS s32 gPauseItemsCurrentScrollPos;
BSS s32 gPauseItemsTargetScrollPos;
BSS s32 D_802705DC;
BSS s32 gPauseItemsLevel;
BSS s32 gPauseItemsCurrentTab;
BSS s32 gPauseItemsIconIDs[20];
BSS s32 D_80270638;
BSS s32 D_8027063C;
BSS s32 gPausePartnersIconIDs[8];
BSS s32 gPausePartnersSpriteIDs[8];
BSS s32 gPausePartnersPartnerIdx[8];
BSS s32 gPausePartnersCurrentPartnerIdx;
BSS s32 gPausePartnersSelectedMove;
BSS f32 gPausePartnersRotAngle;
BSS s32 gPausePartnersLevel;
BSS s32 gPausePartnersNumPartners;
BSS s32 D_802706B4[3]; // padding
BSS s32 gPauseSpiritsSpriteIDs[8];
BSS s32 gPauseSpiritsIndexes[7];
BSS s32 gPauseSpiritsNumSpirits;
BSS s32 gPauseMapIconIDs[1];
BSS f32 gPauseMapCameraX;
BSS f32 gPauseMapCameraY;
BSS s32 gPauseMapMarioX;
BSS s32 gPauseMapMarioY;
BSS f32 gPauseMapTargetX;
BSS f32 gPauseMapTargetY;
BSS s32 gPauseMapCursorCurrentOption;
BSS s32 gPauseMapCursorCurrentOptionCopy;
BSS s32 gPauseMapSpacesInSnapRange;
BSS s32 D_80270728[2]; // padding
BSS s8  gPauseBufferPal1[512];
BSS s8  gPauseBufferImg1[15752];
BSS s8  gPauseBufferPal2[512];
BSS s8  gPauseBufferImg2[15752];
