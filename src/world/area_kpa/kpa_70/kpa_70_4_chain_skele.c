#include "kpa_70.h"

StaticAnimatorNode N(D_802417D0_A76040) = {
    .pos = { 0.0f, 150.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_m03),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_802417FC_A7606C) = {
    .pos = { 69.0f, 250.0f, 0.0f },
    .sibling = &N(D_802417D0_A76040),
    .modelID = AS_MODEL_ID(MODEL_m02),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80241828_A76098) = {
    .pos = { 106.0f, 9.0f, 0.0f },
    .sibling = &N(D_802417FC_A7606C),
    .modelID = AS_MODEL_ID(MODEL_m01),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80241854_A760C4) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .sibling = &N(D_80241828_A76098),
    .modelID = AS_MODEL_ID(MODEL_b03),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80241880_A760F0) = {
    .pos = { 0.0f, 150.0f, 0.0f },
    .sibling = &N(D_80241854_A760C4),
    .modelID = AS_MODEL_ID(MODEL_b02),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_802418AC_A7611C) = {
    .pos = { 30.0f, 180.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-89.99725f) },
    .sibling = &N(D_80241880_A760F0),
    .modelID = AS_MODEL_ID(MODEL_b01),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_802418D8_A76148) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .sibling = &N(D_802418AC_A7611C),
    .modelID = AS_MODEL_ID(MODEL_k02),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80241904_A76174) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .sibling = &N(D_802418D8_A76148),
    .modelID = AS_MODEL_ID(MODEL_k01),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80241930_A761A0) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .child = &N(D_80241904_A76174),
};

StaticAnimatorNode* N(ChainDriveSkeleton)[] = {
    &N(D_80241930_A761A0),
    &N(D_80241904_A76174),
    &N(D_802418D8_A76148),
    &N(D_802418AC_A7611C),
    &N(D_80241880_A760F0),
    &N(D_80241854_A760C4),
    &N(D_80241828_A76098),
    &N(D_802417FC_A7606C),
    &N(D_802417D0_A76040),
    NULL
};
