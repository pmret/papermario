#include "../area.h"

#define NAMESPACE A(lava_piranha_AnimModel_MainHeadVine)

s32 N(padding) = 0;

StaticAnimatorNode N(Node09) = {
    .displayList = &N(Node09),
    .rot = { 0, 0, AS_F(22.885) },
    .pos = { 102.0f, 99.0f, -10.0f },
};

StaticAnimatorNode N(Node08) = {
    .displayList = &N(Node09),
    .rot = { 0, 0, AS_F(60.480) },
    .pos = { 137.0f, 94.0f, -10.0f },
    .sibling = &N(Node09),
};

StaticAnimatorNode N(Node07) = {
    .displayList = &N(Node09),
    .rot = { 0, 0, AS_F(-29.750) },
    .pos = { 127.0f, 56.0f, -10.0f },
    .sibling = &N(Node08),
};

StaticAnimatorNode N(Node06) = {
    .displayList = &N(Node09),
    .rot = { 0, 0, AS_F(-19.995) },
    .pos = { 106.0f, 23.0f, -10.0f },
    .sibling = &N(Node07),
};

StaticAnimatorNode N(Node05) = {
    .displayList = &N(Node09),
    .rot = { 0, 0, AS_F(29.999) },
    .pos = { 122.0f, -13.0f, -10.0f },
    .sibling = &N(Node06),
};

StaticAnimatorNode N(Node04) = {
    .displayList = &N(Node09),
    .rot = { 0, 0, AS_F(115.607) },
    .pos = { 120.0f, 108.0f, -11.0f },
    .sibling = &N(Node05),
};

StaticAnimatorNode N(Node03) = {
    .displayList = &N(Node09),
    .rot = { 0, 0, AS_F(15.360) },
    .pos = { 140.0f, 73.0f, -11.0f },
    .sibling = &N(Node04),
};

StaticAnimatorNode N(Node02) = {
    .displayList = &N(Node09),
    .rot = { 0, 0, AS_F(-44.875) },
    .pos = { 112.0f, 42.0f, -11.0f },
    .sibling = &N(Node03),
};

StaticAnimatorNode N(Node01) = {
    .displayList = &N(Node09),
    .rot = { 0, 0, AS_F(4.998) },
    .pos = { 110.0f, 3.0f, -11.0f },
    .sibling = &N(Node02),
};

StaticAnimatorNode N(Root) = {
    .child = &N(Node01),
};

StaticAnimatorNode* NAMESPACE[] = {
    &N(Root),
    &N(Node01),
    &N(Node02),
    &N(Node03),
    &N(Node04),
    &N(Node05),
    &N(Node06),
    &N(Node07),
    &N(Node08),
    &N(Node09),
    NULL,
};
