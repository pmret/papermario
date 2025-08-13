#include "animation_script.h"

StaticAnimatorNode N(D_80243040_C90BF0) = {
    .pos = { 102.0, 99.0, -10.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(22.8852) },
    .displayList = &N(D_80243040_C90BF0),
};

StaticAnimatorNode N(D_8024306C_C90C1C) = {
    .pos = { 137.0, 94.0, -10.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(60.481583) },
    .sibling = &N(D_80243040_C90BF0),
    .displayList = &N(D_80243040_C90BF0),
};

StaticAnimatorNode N(D_80243098_C90C48) = {
    .pos = { 127.0, 56.0, -10.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(-29.751884) },
    .sibling = &N(D_8024306C_C90C1C),
    .displayList = &N(D_80243040_C90BF0),
};

StaticAnimatorNode N(D_802430C4_C90C74) = {
    .pos = { 106.0, 23.0, -10.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(-19.995728) },
    .sibling = &N(D_80243098_C90C48),
    .displayList = &N(D_80243040_C90BF0),
};

StaticAnimatorNode N(D_802430F0_C90CA0) = {
    .pos = { 122.0, -13.0, -10.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(29.999084) },
    .sibling = &N(D_802430C4_C90C74),
    .displayList = &N(D_80243040_C90BF0),
};

StaticAnimatorNode N(D_8024311C_C90CCC) = {
    .pos = { 120.0, 108.0, -11.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(115.607162) },
    .sibling = &N(D_802430F0_C90CA0),
    .displayList = &N(D_80243040_C90BF0),
};

StaticAnimatorNode N(D_80243148_C90CF8) = {
    .pos = { 140.0, 73.0, -11.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(15.359355) },
    .sibling = &N(D_8024311C_C90CCC),
    .displayList = &N(D_80243040_C90BF0),
};

StaticAnimatorNode N(D_80243174_C90D24) = {
    .pos = { 112.0, 42.0, -11.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(-44.875027) },
    .sibling = &N(D_80243148_C90CF8),
    .displayList = &N(D_80243040_C90BF0),
};

StaticAnimatorNode N(D_802431A0_C90D50) = {
    .pos = { 110.0, 3.0, -11.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(4.998932) },
    .sibling = &N(D_80243174_C90D24),
    .displayList = &N(D_80243040_C90BF0),
};

StaticAnimatorNode N(D_802431CC_C90D7C) = {
    .pos = { 0.0, 0.0, 0.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(0.0) },
    .child = &N(D_802431A0_C90D50),
};

StaticAnimatorNode* N(AnimModel_MainHeadVine)[] = {
    &N(D_802431CC_C90D7C), &N(D_802431A0_C90D50), &N(D_80243174_C90D24), &N(D_80243148_C90CF8),
    &N(D_8024311C_C90CCC), &N(D_802430F0_C90CA0), &N(D_802430C4_C90C74), &N(D_80243098_C90C48),
    &N(D_8024306C_C90C1C), &N(D_80243040_C90BF0), nullptr, nullptr
};
