#include "../area.h"

#define NAMESPACE A(lava_piranha_AnimModel_SideHeadVine)

s32 N(padding) = 0;

StaticAnimatorNode N(Node07) = {
    .displayList = &N(Node07),
    .rot = { 0, 0, 13020 },
    .pos = { 62.0f, 53.0f, -20.0f },
};

StaticAnimatorNode N(Node06) = {
    .displayList = &N(Node07),
    .rot = { 0, 0, 13067 },
    .pos = { 97.0f, 51.0f, -20.0f },
    .sibling = &N(Node07),
};

StaticAnimatorNode N(Node05) = {
    .displayList = &N(Node07),
    .rot = { 0, 0, -10126 },
    .pos = { 75.0f, 19.0f, -20.0f },
    .sibling = &N(Node06),
};

StaticAnimatorNode N(Node04) = {
    .displayList = &N(Node07),
    .rot = { 0, 0, 122 },
    .pos = { 69.0f, -19.0f, -20.0f },
    .sibling = &N(Node05),
};

StaticAnimatorNode N(Node03) = {
    .displayList = &N(Node07),
    .rot = { 0, 0, 24663 },
    .pos = { 76.0f, 62.0f, -21.0f },
    .sibling = &N(Node04),
};

StaticAnimatorNode N(Node02) = {
    .displayList = &N(Node07),
    .rot = { 0, 0, 1470 },
    .pos = { 96.0f, 28.0f, -21.0f },
    .sibling = &N(Node03),
};

StaticAnimatorNode N(Node01) = {
    .displayList = &N(Node07),
    .rot = { 0, 0, -5339 },
    .pos = { 67.0f, 0.0f, -21.0f },
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
    nullptr,
};
