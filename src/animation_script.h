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

#define _AS_ROUND(x) ((int) (x < 0 ? x - 0.5 : x + 0.5))
#define AS_F(x) (_AS_ROUND((x) * 32767.0 / 180.0))

#define as_End AS_END,
#define as_Wait(time) AS_WAIT, time,
#define as_EndLoop AS_END_LOOP,
#define as_Restart AS_END_LOOP,
#define as_Loop AS_LOOP,
#define as_SetRotation(node, x, y, z) AS_SET_ROTATION, node, AS_F(x), AS_F(y), AS_F(z),
#define as_SetPos(node, x, y, z) AS_SET_POS, node, x, y, z,
#define as_SetScale(node, x, y, z) AS_SET_SCALE, node, AS_F(x), AS_F(y), AS_F(z),
#define as_DisableMirroring AS_OP_19,

#define AS_MODEL_ID(modelID) ((modelID) + 1)
#define AS_NULL_MODEL 0

// used in entity models
#define ENTITY_ANIM_NULL (void*)(0xFFFFFFFF)
#endif
