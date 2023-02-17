#include "common.h"

#define NAMESPACE b_area_kzn2_lava_piranha_AnimModel_SideHeadVine

s32 N(padding) = 0;

StaticAnimatorNode N(8021C4F0) = {
    .displayList = &N(8021C4F0),
    .rot = { 0, 0, 13020 },
    .pos = { 62.0f, 53.0f, -20.0f },
};

StaticAnimatorNode N(8021C51C) = {
    .displayList = &N(8021C4F0),
    .rot = { 0, 0, 13067 },
    .pos = { 97.0f, 51.0f, -20.0f },
    .sibling = &N(8021C4F0),
};

StaticAnimatorNode N(8021C548) = {
    .displayList = &N(8021C4F0),
    .rot = { 0, 0, -10126 },
    .pos = { 75.0f, 19.0f, -20.0f },
    .sibling = &N(8021C51C),
};

StaticAnimatorNode N(8021C574) = {
    .displayList = &N(8021C4F0),
    .rot = { 0, 0, 122 },
    .pos = { 69.0f, -19.0f, -20.0f },
    .sibling = &N(8021C548),
};

StaticAnimatorNode N(8021C5A0) = {
    .displayList = &N(8021C4F0),
    .rot = { 0, 0, 24663 },
    .pos = { 76.0f, 62.0f, -21.0f },
    .sibling = &N(8021C574),
};

StaticAnimatorNode N(8021C5CC) = {
    .displayList = &N(8021C4F0),
    .rot = { 0, 0, 1470 },
    .pos = { 96.0f, 28.0f, -21.0f },
    .sibling = &N(8021C5A0),
};

StaticAnimatorNode N(8021C5F8) = {
    .displayList = &N(8021C4F0),
    .rot = { 0, 0, -5339 },
    .pos = { 67.0f, 0.0f, -21.0f },
    .sibling = &N(8021C5CC),
};

StaticAnimatorNode N(8021C624) = {
    .child = &N(8021C5F8),
};

StaticAnimatorNode* NAMESPACE[] = {
    &N(8021C624),
    &N(8021C5F8),
    &N(8021C5CC),
    &N(8021C5A0),
    &N(8021C574),
    &N(8021C548),
    &N(8021C51C),
    &N(8021C4F0),
    NULL,
};
