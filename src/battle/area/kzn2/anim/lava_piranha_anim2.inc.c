#include "common.h"

#define NAMESPACE b_area_kzn2_lava_piranha_AnimModel_MainHeadVine

s32 N(padding) = 0;

StaticAnimatorNode N(8021C308) = {
    .displayList = &N(8021C308),
    .rot = { 0, 0, 4166 },
    .pos = { 102.0f, 99.0f, -10.0f },
};

StaticAnimatorNode N(8021C334) = {
    .displayList = &N(8021C308),
    .rot = { 0, 0, 11010 },
    .pos = { 137.0f, 94.0f, -10.0f },
    .sibling = &N(8021C308),
};

StaticAnimatorNode N(8021C360) = {
    .displayList = &N(8021C308),
    .rot = { 0, 0, -5416 },
    .pos = { 127.0f, 56.0f, -10.0f },
    .sibling = &N(8021C334),
};

StaticAnimatorNode N(8021C38C) = {
    .displayList = &N(8021C308),
    .rot = { 0, 0, -3640 },
    .pos = { 106.0f, 23.0f, -10.0f },
    .sibling = &N(8021C360),
};

StaticAnimatorNode N(8021C3B8) = {
    .displayList = &N(8021C308),
    .rot = { 0, 0, 5461 },
    .pos = { 122.0f, -13.0f, -10.0f },
    .sibling = &N(8021C38C),
};

StaticAnimatorNode N(8021C3E4) = {
    .displayList = &N(8021C308),
    .rot = { 0, 0, 21045 },
    .pos = { 120.0f, 108.0f, -11.0f },
    .sibling = &N(8021C3B8),
};

StaticAnimatorNode N(8021C410) = {
    .displayList = &N(8021C308),
    .rot = { 0, 0, 2796 },
    .pos = { 140.0f, 73.0f, -11.0f },
    .sibling = &N(8021C3E4),
};

StaticAnimatorNode N(8021C43C) = {
    .displayList = &N(8021C308),
    .rot = { 0, 0, -8169 },
    .pos = { 112.0f, 42.0f, -11.0f },
    .sibling = &N(8021C410),
};

StaticAnimatorNode N(8021C468) = {
    .displayList = &N(8021C308),
    .rot = { 0, 0, 910 },
    .pos = { 110.0f, 3.0f, -11.0f },
    .sibling = &N(8021C43C),
};

StaticAnimatorNode N(8021C494) = {
    .child = &N(8021C468),
};

StaticAnimatorNode* NAMESPACE[] = {
    &N(8021C494),
    &N(8021C468),
    &N(8021C43C),
    &N(8021C410),
    &N(8021C3E4),
    &N(8021C3B8),
    &N(8021C38C),
    &N(8021C360),
    &N(8021C334),
    &N(8021C308),
    NULL,
};
