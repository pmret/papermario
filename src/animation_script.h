#ifndef ANIMATION_SCRIPT_H
#define ANIMATION_SCRIPT_H

#include "common.h"

typedef s16 AnimScript[];

enum {
    AS_END,
    AS_WAIT,
    AS_OP_2,
    AS_END_LOOP,
    AS_OP_4,
    AS_SET_ROTATION,
    AS_ADD_ROTATION,
    AS_OP_7,
    AS_SET_POS,
    AS_OP_9,
    AS_LOOP,
    AS_OP_11,
    AS_OP_12,
    AS_OP_13,
    AS_SET_FLAGS,
    AS_SET_NODE_FLAGS,
    AS_CLEAR_NODE_FLAGS,
    AS_SET_SCALE,
    AS_SET_RENDER_MODE,
    AS_OP_19,
};

#endif
