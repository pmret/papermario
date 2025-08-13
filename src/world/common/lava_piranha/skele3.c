#include "animation_script.h"

StaticAnimatorNode N(D_802433B0_C90F60) = {
    .pos = { 132.0, -5.0, -5.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(165.157013) },
    .displayList = &N(D_802433B0_C90F60),
};

StaticAnimatorNode N(D_802433DC_C90F8C) = {
    .pos = { 98.0, 4.0, -5.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(-80.120239) },
    .sibling = &N(D_802433B0_C90F60),
    .displayList = &N(D_802433B0_C90F60),
};

StaticAnimatorNode N(D_80243408_C90FB8) = {
    .pos = { 129.0, -26.0, -6.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(125.160072) },
    .sibling = &N(D_802433DC_C90F8C),
    .displayList = &N(D_802433B0_C90F60),
};

StaticAnimatorNode N(D_80243434_C90FE4) = {
    .pos = { 120.0, 12.0, -6.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(-154.983368) },
    .sibling = &N(D_80243408_C90FB8),
    .displayList = &N(D_802433B0_C90F60),
};

StaticAnimatorNode N(D_80243460_C91010) = {
    .pos = { 87.0, -13.0, -6.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(-39.749748) },
    .sibling = &N(D_80243434_C90FE4),
    .displayList = &N(D_802433B0_C90F60),
};

StaticAnimatorNode N(D_8024348C_C9103C) = {
    .pos = { 0.0, 0.0, 0.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(0.0) },
    .child = &N(D_80243460_C91010),
};

StaticAnimatorNode* N(AnimModel_ExtraVine)[] = {
    &N(D_8024348C_C9103C), &N(D_80243460_C91010), &N(D_80243434_C90FE4), &N(D_80243408_C90FB8),
    &N(D_802433DC_C90F8C), &N(D_802433B0_C90F60), nullptr, nullptr
};
