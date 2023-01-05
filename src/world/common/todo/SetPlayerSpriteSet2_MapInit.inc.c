#include "common.h"

ApiStatus N(SetPlayerSpriteSet2_MapInit)(Evt* script, s32 isInitialCall) {
    gGameStatusPtr->playerSpriteSet = PLAYER_SPRITES_COMBINED_EPILOGUE;
    return ApiStatus_BLOCK;
}
