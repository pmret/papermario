#include "common.h"

#define NAMESPACE b_area_kzn2_lava_piranha_AnimModel_ExtraVine

s32 N(padding) = 0;

StaticAnimatorNode N(8021C678) = {
    .displayList = &N(8021C678),
    .rot = { 0, 0, 30065 },
    .pos = { 132.0f, -5.0f, -5.0f },
};

StaticAnimatorNode N(8021C6A4) = {
    .displayList = &N(8021C678),
    .rot = { 0, 0, -14585 },
    .pos = { 98.0f, 4.0f, -5.0f },
    .sibling = &N(8021C678),
};

StaticAnimatorNode N(8021C6D0) = {
    .displayList = &N(8021C678),
    .rot = { 0, 0, 22784 },
    .pos = { 129.0f, -26.0f, -6.0f },
    .sibling = &N(8021C6A4),
};

StaticAnimatorNode N(8021C6FC) = {
    .displayList = &N(8021C678),
    .rot = { 0, 0, -28213 },
    .pos = { 120.0f, 12.0f, -6.0f },
    .sibling = &N(8021C6D0),
};

StaticAnimatorNode N(8021C728) = {
    .displayList = &N(8021C678),
    .rot = { 0, 0, -7236 },
    .pos = { 87.0f, -13.0f, -6.0f },
    .sibling = &N(8021C6FC),
};

StaticAnimatorNode N(8021C754) = {
    .child = &N(8021C728),
};

StaticAnimatorNode* NAMESPACE[] = {
    &N(8021C754),
    &N(8021C728),
    &N(8021C6FC),
    &N(8021C6D0),
    &N(8021C6A4),
    &N(8021C678),
    NULL,
};
