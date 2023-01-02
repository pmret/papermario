#include "animation_script.h"

extern Gfx N(toad_house_blanket_gfx)[];
extern Vtx N(toad_house_blanket_vtx)[];
extern IMG_BIN N(toad_house_blanket_img)[];

StaticAnimatorNode N(D_80248AA0_971C60) = {
    .displayList = N(toad_house_blanket_gfx),
    .vertexStartOffset = 0x02EE,
    .vtxList = N(toad_house_blanket_vtx),
};

StaticAnimatorNode N(D_80248ACC_971C8C) = {
    .displayList = N(toad_house_blanket_gfx),
    .sibling = &N(D_80248AA0_971C60),
    .vertexStartOffset = 0x02BC,
    .vtxList = N(toad_house_blanket_vtx),
};

StaticAnimatorNode N(D_80248AF8_971CB8) = {
    .displayList = N(toad_house_blanket_gfx),
    .sibling = &N(D_80248ACC_971C8C),
    .vertexStartOffset = 0x028A,
    .vtxList = N(toad_house_blanket_vtx),
};

StaticAnimatorNode N(D_80248B24_971CE4) = {
    .displayList = N(toad_house_blanket_gfx),
    .sibling = &N(D_80248AF8_971CB8),
    .vertexStartOffset = 0x0258,
    .vtxList = N(toad_house_blanket_vtx),
};

StaticAnimatorNode N(D_80248B50_971D10) = {
    .displayList = N(toad_house_blanket_gfx),
    .sibling = &N(D_80248B24_971CE4),
    .vertexStartOffset = 0x0226,
    .vtxList = N(toad_house_blanket_vtx),
};

StaticAnimatorNode N(D_80248B7C_971D3C) = {
    .displayList = N(toad_house_blanket_gfx),
    .sibling = &N(D_80248B50_971D10),
    .vertexStartOffset = 0x01F4,
    .vtxList = N(toad_house_blanket_vtx),
};

StaticAnimatorNode N(D_80248BA8_971D68) = {
    .displayList = N(toad_house_blanket_gfx),
    .sibling = &N(D_80248B7C_971D3C),
    .vertexStartOffset = 0x01C2,
    .vtxList = N(toad_house_blanket_vtx),
};

StaticAnimatorNode N(D_80248BD4_971D94) = {
    .displayList = N(toad_house_blanket_gfx),
    .sibling = &N(D_80248BA8_971D68),
    .vertexStartOffset = 0x0190,
    .vtxList = N(toad_house_blanket_vtx),
};

StaticAnimatorNode N(D_80248C00_971DC0) = {
    .displayList = N(toad_house_blanket_gfx),
    .sibling = &N(D_80248BD4_971D94),
    .vertexStartOffset = 0x015E,
    .vtxList = N(toad_house_blanket_vtx),
};

StaticAnimatorNode N(D_80248C2C_971DEC) = {
    .displayList = N(toad_house_blanket_gfx),
    .sibling = &N(D_80248C00_971DC0),
    .vertexStartOffset = 0x012C,
    .vtxList = N(toad_house_blanket_vtx),
};

StaticAnimatorNode N(D_80248C58_971E18) = {
    .displayList = N(toad_house_blanket_gfx),
    .sibling = &N(D_80248C2C_971DEC),
    .vertexStartOffset = 0x00FA,
    .vtxList = N(toad_house_blanket_vtx),
};

StaticAnimatorNode N(D_80248C84_971E44) = {
    .displayList = N(toad_house_blanket_gfx),
    .sibling = &N(D_80248C58_971E18),
    .vertexStartOffset = 0x00C8,
    .vtxList = N(toad_house_blanket_vtx),
};

StaticAnimatorNode N(D_80248CB0_971E70) = {
    .displayList = N(toad_house_blanket_gfx),
    .sibling = &N(D_80248C84_971E44),
    .vertexStartOffset = 0x0096,
    .vtxList = N(toad_house_blanket_vtx),
};

StaticAnimatorNode N(D_80248CDC_971E9C) = {
    .displayList = N(toad_house_blanket_gfx),
    .sibling = &N(D_80248CB0_971E70),
    .vertexStartOffset = 0x0064,
    .vtxList = N(toad_house_blanket_vtx),
};

StaticAnimatorNode N(D_80248D08_971EC8) = {
    .displayList = N(toad_house_blanket_gfx),
    .sibling = &N(D_80248CDC_971E9C),
    .vertexStartOffset = 0x0032,
    .vtxList = N(toad_house_blanket_vtx),
};

StaticAnimatorNode N(D_80248D34_971EF4) = {
    .displayList = N(toad_house_blanket_gfx),
    .sibling = &N(D_80248D08_971EC8),
    .vertexStartOffset = 0,
    .vtxList = N(toad_house_blanket_vtx),
};

StaticAnimatorNode N(D_80248D60_971F20) = {
    .child = &N(D_80248D34_971EF4),
    .vertexStartOffset = -1,
};

StaticAnimatorNode* N(D_80248D8C_971F4C)[] = {
    &N(D_80248D60_971F20), &N(D_80248D34_971EF4), &N(D_80248D08_971EC8), &N(D_80248CDC_971E9C),
    &N(D_80248CB0_971E70), &N(D_80248C84_971E44), &N(D_80248C58_971E18), &N(D_80248C2C_971DEC),
    &N(D_80248C00_971DC0), &N(D_80248BD4_971D94), &N(D_80248BA8_971D68), &N(D_80248B7C_971D3C),
    &N(D_80248B50_971D10), &N(D_80248B24_971CE4), &N(D_80248AF8_971CB8), &N(D_80248ACC_971C8C),
    &N(D_80248AA0_971C60), NULL
};

#include "world/toad_house/blanket.vtx.inc.c"
#include "world/toad_house/blanket.gfx.inc.c"
#include "world/toad_house/blanket.png.inc.c"

AnimScript N(ANS_ToadHouseBlanket) = {
        AS_OP_19,
        AS_SET_ROTATION, 1, AS_F(0.0), AS_F(0.0), AS_F(0.0),
        AS_SET_POS, 1, 0, 0, 0,
        AS_SET_SCALE, 1, AS_F(1.0), AS_F(1.0), AS_F(1.0),
        AS_SET_ROTATION, 2, AS_F(0.0), AS_F(0.0), AS_F(0.0),
        AS_SET_POS, 2, 0, 0, 0,
        AS_SET_SCALE, 2, AS_F(1.0), AS_F(1.0), AS_F(1.0),
        AS_SET_ROTATION, 3, AS_F(0.0), AS_F(0.0), AS_F(0.0),
        AS_SET_POS, 3, 0, 0, 0,
        AS_SET_SCALE, 3, AS_F(1.0), AS_F(1.0), AS_F(1.0),
        AS_SET_ROTATION, 4, AS_F(0.0), AS_F(0.0), AS_F(0.0),
        AS_SET_POS, 4, 0, 0, 0,
        AS_SET_SCALE, 4, AS_F(1.0), AS_F(1.0), AS_F(1.0),
        AS_SET_ROTATION, 5, AS_F(0.0), AS_F(0.0), AS_F(0.0),
        AS_SET_POS, 5, 0, 0, 0,
        AS_SET_SCALE, 5, AS_F(1.0), AS_F(1.0), AS_F(1.0),
        AS_SET_ROTATION, 6, AS_F(0.0), AS_F(0.0), AS_F(0.0),
        AS_SET_POS, 6, 0, 0, 0,
        AS_SET_SCALE, 6, AS_F(1.0), AS_F(1.0), AS_F(1.0),
        AS_SET_ROTATION, 7, AS_F(0.0), AS_F(0.0), AS_F(0.0),
        AS_SET_POS, 7, 0, 0, 0,
        AS_SET_SCALE, 7, AS_F(1.0), AS_F(1.0), AS_F(1.0),
        AS_SET_ROTATION, 8, AS_F(0.0), AS_F(0.0), AS_F(0.0),
        AS_SET_POS, 8, 0, 0, 0,
        AS_SET_SCALE, 8, AS_F(1.0), AS_F(1.0), AS_F(1.0),
        AS_SET_ROTATION, 9, AS_F(0.0), AS_F(0.0), AS_F(0.0),
        AS_SET_POS, 9, 0, 0, 0,
        AS_SET_SCALE, 9, AS_F(1.0), AS_F(1.0), AS_F(1.0),
        AS_SET_ROTATION, 10, AS_F(0.0), AS_F(0.0), AS_F(0.0),
        AS_SET_POS, 10, 0, 0, 0,
        AS_SET_SCALE, 10, AS_F(1.0), AS_F(1.0), AS_F(1.0),
        AS_SET_ROTATION, 11, AS_F(0.0), AS_F(0.0), AS_F(0.0),
        AS_SET_POS, 11, 0, 0, 0,
        AS_SET_SCALE, 11, AS_F(1.0), AS_F(1.0), AS_F(1.0),
        AS_SET_ROTATION, 12, AS_F(0.0), AS_F(0.0), AS_F(0.0),
        AS_SET_POS, 12, 0, 0, 0,
        AS_SET_SCALE, 12, AS_F(1.0), AS_F(1.0), AS_F(1.0),
        AS_SET_ROTATION, 13, AS_F(0.0), AS_F(0.0), AS_F(0.0),
        AS_SET_POS, 13, 0, 0, 0,
        AS_SET_SCALE, 13, AS_F(1.0), AS_F(1.0), AS_F(1.0),
        AS_SET_ROTATION, 14, AS_F(0.0), AS_F(0.0), AS_F(0.0),
        AS_SET_POS, 14, 0, 0, 0,
        AS_SET_SCALE, 14, AS_F(1.0), AS_F(1.0), AS_F(1.0),
        AS_SET_ROTATION, 15, AS_F(0.0), AS_F(0.0), AS_F(0.0),
        AS_SET_POS, 15, 0, 0, 0,
        AS_SET_SCALE, 15, AS_F(1.0), AS_F(1.0), AS_F(1.0),
        AS_SET_ROTATION, 16, AS_F(0.0), AS_F(0.0), AS_F(0.0),
        AS_SET_POS, 16, 0, 0, 0,
        AS_SET_SCALE, 16, AS_F(1.0), AS_F(1.0), AS_F(1.0),
        AS_SET_ROTATION, 17, AS_F(0.0), AS_F(0.0), AS_F(0.0),
        AS_SET_POS, 17, 0, 0, 0,
        AS_SET_SCALE, 17, AS_F(1.0), AS_F(1.0), AS_F(1.0),
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
        AS_WAIT, 1,
    AS_END_LOOP,
    AS_END,
};
