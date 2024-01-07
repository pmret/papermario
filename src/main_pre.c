#include "PR/ultratypes.h"
#include "include_asset.h"

s32 ResetGameState = 0;
u16* ResetSavedFrameImg = NULL;
s16 D_80073E08 = 0;
s16 D_80073E0A = 0;

s32 D_80073E0C = 0; // unused?

INCLUDE_IMG("reset_tiles.png", ResetTilesImg);
