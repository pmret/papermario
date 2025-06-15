#include "kmr_11.h"

StaticAnimatorNode N(D_8024EEF0_8E8FF0) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy32),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_8024EF1C_8E901C) = {
    .pos = { -159.0f, 0.0f, -126.0f },
    .child = &N(D_8024EEF0_8E8FF0),
};

StaticAnimatorNode N(D_8024EF48_8E9048) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy31),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_8024EF74_8E9074) = {
    .pos = { -159.0f, 0.0f, -126.0f },
    .child = &N(D_8024EF48_8E9048),
    .sibling = &N(D_8024EF1C_8E901C),
};

StaticAnimatorNode N(D_8024EFA0_8E90A0) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy30),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_8024EFCC_8E90CC) = {
    .pos = { -159.0f, 0.0f, -126.0f },
    .child = &N(D_8024EFA0_8E90A0),
    .sibling = &N(D_8024EF74_8E9074),
};

StaticAnimatorNode N(D_8024EFF8_8E90F8) = {
    .pos = { 140.0f, -10.0f, -360.0f },
    .rot = { AS_F(0.0f), AS_F(-180.0f), AS_F(0.0f) },
    .child = &N(D_8024EFCC_8E90CC),
};

StaticAnimatorNode N(D_8024F024_8E9124) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy3),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_8024F050_8E9150) = {
    .pos = { -159.0f, 0.0f, -126.0f },
    .child = &N(D_8024F024_8E9124),
};

StaticAnimatorNode N(D_8024F07C_8E917C) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy2),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_8024F0A8_8E91A8) = {
    .pos = { -159.0f, 0.0f, -126.0f },
    .child = &N(D_8024F07C_8E917C),
    .sibling = &N(D_8024F050_8E9150),
};

StaticAnimatorNode N(D_8024F0D4_8E91D4) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy1),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_8024F100_8E9200) = {
    .pos = { -159.0f, 0.0f, -126.0f },
    .child = &N(D_8024F0D4_8E91D4),
    .sibling = &N(D_8024F0A8_8E91A8),
};

StaticAnimatorNode N(D_8024F12C_8E922C) = {
    .pos = { 0.0f, -10.0f, 0.0f },
    .child = &N(D_8024F100_8E9200),
    .sibling = &N(D_8024EFF8_8E90F8),
};

StaticAnimatorNode N(D_8024F158_8E9258) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .child = &N(D_8024F12C_8E922C),
};

StaticAnimatorNode N(D_8024F184_8E9284) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(-12.695089f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_dummy),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_8024F1B0_8E92B0) = {
    .pos = { 0.0f, 110.0f, 0.0f },
    .child = &N(D_8024F184_8E9284),
};

StaticAnimatorNode N(D_8024F1DC_8E92DC) = {
    .pos = { -237.0f, 109.0f, 155.0f },
    .rot = { AS_F(0.0f), AS_F(-12.695089f), AS_F(-179.9945f) },
    .modelID = AS_MODEL_ID(MODEL_b1),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_8024F208_8E9308) = {
    .pos = { 312.0f, -169.0f, 155.0f },
    .rot = { AS_F(0.0f), AS_F(-12.695089f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_b2),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_8024F234_8E9334) = {
    .pos = { -237.0f, 169.0f, 155.0f },
    .rot = { AS_F(0.0f), AS_F(-12.695089f), AS_F(-179.9945f) },
    .modelID = AS_MODEL_ID(MODEL_b3),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_8024F260_8E9360) = {
    .pos = { 312.0f, -229.0f, 155.0f },
    .rot = { AS_F(0.0f), AS_F(-12.695089f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_b4),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_8024F28C_8E938C) = {
    .pos = { -237.0f, 229.0f, 155.0f },
    .rot = { AS_F(0.0f), AS_F(-12.695089f), AS_F(-179.9945f) },
    .modelID = AS_MODEL_ID(MODEL_b5),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_8024F2B8_8E93B8) = {
    .pos = { 312.0f, -289.0f, 155.0f },
    .rot = { AS_F(0.0f), AS_F(-12.695089f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_b6),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_8024F2E4_8E93E4) = {
    .pos = { 75.0f, 0.0f, 0.0f },
    .sibling = &N(D_8024F2B8_8E93B8),
};

StaticAnimatorNode N(D_8024F310_8E9410) = {
    .pos = { 30.0f, 0.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-89.99725f) },
    .child = &N(D_8024F2E4_8E93E4),
};

StaticAnimatorNode N(D_8024F33C_8E943C) = {
    .pos = { 30.0f, 0.0f, 0.0f },
    .child = &N(D_8024F310_8E9410),
};

StaticAnimatorNode N(D_8024F368_8E9468) = {
    .pos = { 75.0f, 0.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-89.99725f) },
    .child = &N(D_8024F33C_8E943C),
    .sibling = &N(D_8024F28C_8E938C),
};

StaticAnimatorNode N(D_8024F394_8E9494) = {
    .pos = { 75.0f, 0.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(179.9945f) },
    .child = &N(D_8024F368_8E9468),
    .sibling = &N(D_8024F260_8E9360),
};

StaticAnimatorNode N(D_8024F3C0_8E94C0) = {
    .pos = { 30.0f, 0.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-89.99725f) },
    .child = &N(D_8024F394_8E9494),
};

StaticAnimatorNode N(D_8024F3EC_8E94EC) = {
    .pos = { 30.0f, 0.0f, 0.0f },
    .child = &N(D_8024F3C0_8E94C0),
};

StaticAnimatorNode N(D_8024F418_8E9518) = {
    .pos = { 75.0f, 0.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-89.99725f) },
    .child = &N(D_8024F3EC_8E94EC),
    .sibling = &N(D_8024F234_8E9334),
};

StaticAnimatorNode N(D_8024F444_8E9544) = {
    .pos = { 75.0f, 0.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(179.9945f) },
    .child = &N(D_8024F418_8E9518),
    .sibling = &N(D_8024F208_8E9308),
};

StaticAnimatorNode N(D_8024F470_8E9570) = {
    .pos = { 30.0f, 0.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-89.99725f) },
    .child = &N(D_8024F444_8E9544),
};

StaticAnimatorNode N(D_8024F49C_8E959C) = {
    .pos = { 30.0f, 0.0f, 0.0f },
    .child = &N(D_8024F470_8E9570),
};

StaticAnimatorNode N(D_8024F4C8_8E95C8) = {
    .pos = { 75.0f, 0.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-89.99725f) },
    .child = &N(D_8024F49C_8E959C),
    .sibling = &N(D_8024F1DC_8E92DC),
};

StaticAnimatorNode N(D_8024F4F4_8E95F4) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(179.9945f) },
    .child = &N(D_8024F4C8_8E95C8),
};

StaticAnimatorNode N(D_8024F520_8E9620) = {
    .pos = { 0.0f, 110.0f, 0.0f },
    .child = &N(D_8024F4F4_8E95F4),
    .sibling = &N(D_8024F1B0_8E92B0),
};

StaticAnimatorNode N(D_8024F54C_8E964C) = {
    .pos = { -266.0f, 0.0f, -99.0f },
    .rot = { AS_F(0.0f), AS_F(12.695089f), AS_F(0.0f) },
    .child = &N(D_8024F520_8E9620),
    .sibling = &N(D_8024F158_8E9258),
};

StaticAnimatorNode N(D_8024F578_8E9678) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .child = &N(D_8024F54C_8E964C),
};

StaticAnimatorNode* N(AnimSkeleton_Bridge)[] = {
    &N(D_8024F578_8E9678), &N(D_8024F54C_8E964C), &N(D_8024F520_8E9620), &N(D_8024F4F4_8E95F4),
    &N(D_8024F4C8_8E95C8), &N(D_8024F49C_8E959C), &N(D_8024F470_8E9570), &N(D_8024F444_8E9544),
    &N(D_8024F418_8E9518), &N(D_8024F3EC_8E94EC), &N(D_8024F3C0_8E94C0), &N(D_8024F394_8E9494),
    &N(D_8024F368_8E9468), &N(D_8024F33C_8E943C), &N(D_8024F310_8E9410), &N(D_8024F2E4_8E93E4),
    &N(D_8024F2B8_8E93B8), &N(D_8024F28C_8E938C), &N(D_8024F260_8E9360), &N(D_8024F234_8E9334),
    &N(D_8024F208_8E9308), &N(D_8024F1DC_8E92DC), &N(D_8024F1B0_8E92B0), &N(D_8024F184_8E9284),
    &N(D_8024F158_8E9258), &N(D_8024F12C_8E922C), &N(D_8024F100_8E9200), &N(D_8024F0D4_8E91D4),
    &N(D_8024F0A8_8E91A8), &N(D_8024F07C_8E917C), &N(D_8024F050_8E9150), &N(D_8024F024_8E9124),
    &N(D_8024EFF8_8E90F8), &N(D_8024EFCC_8E90CC), &N(D_8024EFA0_8E90A0), &N(D_8024EF74_8E9074),
    &N(D_8024EF48_8E9048), &N(D_8024EF1C_8E901C), &N(D_8024EEF0_8E8FF0), nullptr
};
