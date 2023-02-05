#ifndef ITEM_ENTITY_H
#define ITEM_ENTITY_H

#include "common.h"

typedef s32 ItemScript[];

enum {
    ITEM_SCRIPT_OP_End,
    ITEM_SCRIPT_OP_SetImage,
    ITEM_SCRIPT_OP_Restart,
    ITEM_SCRIPT_OP_Loop,
    ITEM_SCRIPT_OP_RandomRestart
};

#define is_End ITEM_SCRIPT_OP_End,
#define is_SetIcon(time, icon) ITEM_SCRIPT_OP_SetImage, time, ICON_##icon##_raster, ICON_##icon##_palette, 0, 0,
#define is_Restart ITEM_SCRIPT_OP_Restart,
#define is_Loop ITEM_SCRIPT_OP_Loop,
#define is_RandomRestart(max, cutoff) ITEM_SCRIPT_OP_RandomRestart, max, cutoff,

#endif
