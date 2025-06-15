#include "animation_script.h"

StaticAnimatorNode N(D_80243228_C90DD8) = {
    .pos = { 62.0, 53.0, -20.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(71.523178) },
    .displayList = &N(D_80243228_C90DD8),
};

StaticAnimatorNode N(D_80243254_C90E04) = {
    .pos = { 97.0, 51.0, -20.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(71.781364) },
    .sibling = &N(D_80243228_C90DD8),
    .displayList = &N(D_80243228_C90DD8),
};

StaticAnimatorNode N(D_80243280_C90E30) = {
    .pos = { 75.0, 19.0, -20.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(-55.625477) },
    .sibling = &N(D_80243254_C90E04),
    .displayList = &N(D_80243228_C90DD8),
};

StaticAnimatorNode N(D_802432AC_C90E5C) = {
    .pos = { 69.0, -19.0, -20.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(0.670186) },
    .sibling = &N(D_80243280_C90E30),
    .displayList = &N(D_80243228_C90DD8),
};

StaticAnimatorNode N(D_802432D8_C90E88) = {
    .pos = { 76.0, 62.0, -21.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(135.4820) },
    .sibling = &N(D_802432AC_C90E5C),
    .displayList = &N(D_80243228_C90DD8),
};

StaticAnimatorNode N(D_80243304_C90EB4) = {
    .pos = { 96.0, 28.0, -21.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(8.075197) },
    .sibling = &N(D_802432D8_C90E88),
    .displayList = &N(D_80243228_C90DD8),
};

StaticAnimatorNode N(D_80243330_C90EE0) = {
    .pos = { 67.0, 0.0, -21.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(-29.328897) },
    .sibling = &N(D_80243304_C90EB4),
    .displayList = &N(D_80243228_C90DD8),
};

StaticAnimatorNode N(D_8024335C_C90F0C) = {
    .pos = { 0.0, 0.0, 0.0 },
    .rot = { AS_F(0.0), AS_F(0.0), AS_F(0.0) },
    .child = &N(D_80243330_C90EE0),
};

StaticAnimatorNode* N(AnimModel_SideHeadVine)[] = {
    &N(D_8024335C_C90F0C), &N(D_80243330_C90EE0), &N(D_80243304_C90EB4), &N(D_802432D8_C90E88),
    &N(D_802432AC_C90E5C), &N(D_80243280_C90E30), &N(D_80243254_C90E04), &N(D_80243228_C90DD8),
    nullptr, nullptr
};
