#include "../area.h"

#define NAMESPACE A(lava_piranha_AnimModel_ExtraVine)

s32 N(padding) = 0;

StaticAnimatorNode N(Node05) = {
    .displayList = &N(Node05),
    .rot = { 0, 0, AS_F(165.157) },
    .pos = { 132.0f, -5.0f, -5.0f },
};

StaticAnimatorNode N(Node04) = {
    .displayList = &N(Node05),
    .rot = { 0, 0, AS_F(-80.120) },
    .pos = { 98.0f, 4.0f, -5.0f },
    .sibling = &N(Node05),
};

StaticAnimatorNode N(Node03) = {
    .displayList = &N(Node05),
    .rot = { 0, 0, AS_F(125.160) },
    .pos = { 129.0f, -26.0f, -6.0f },
    .sibling = &N(Node04),
};

StaticAnimatorNode N(Node02) = {
    .displayList = &N(Node05),
    .rot = { 0, 0, AS_F(-154.983) },
    .pos = { 120.0f, 12.0f, -6.0f },
    .sibling = &N(Node03),
};

StaticAnimatorNode N(Node01) = {
    .displayList = &N(Node05),
    .rot = { 0, 0, AS_F(-39.749) },
    .pos = { 87.0f, -13.0f, -6.0f },
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
    nullptr,
};
