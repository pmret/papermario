#include "pra_31.h"

#include "world/area_pra/pra_31/unk_01.gfx.inc.c"
#include "world/area_pra/pra_31/unk_02.gfx.inc.c"
#include "world/area_pra/pra_31/unk_03.gfx.inc.c"
#include "world/area_pra/pra_31/unk_04.gfx.inc.c"
#include "world/area_pra/pra_31/unk_05.gfx.inc.c"
#include "world/area_pra/pra_31/unk_06.gfx.inc.c"
#include "world/area_pra/pra_31/unk_07.gfx.inc.c"
#include "world/area_pra/pra_31/unk_08.gfx.inc.c"
#include "world/area_pra/pra_31/unk_09.gfx.inc.c"
#include "world/area_pra/pra_31/unk_10.gfx.inc.c"
#include "world/area_pra/pra_31/unk_11.gfx.inc.c"
#include "world/area_pra/pra_31/unk_12.gfx.inc.c"
#include "world/area_pra/pra_31/unk_13.gfx.inc.c"
#include "world/area_pra/pra_31/unk_14.gfx.inc.c"
#include "world/area_pra/pra_31/unk_15.gfx.inc.c"
#include "world/area_pra/pra_31/unk_16.gfx.inc.c"
#include "world/area_pra/pra_31/unk_17.gfx.inc.c"
#include "world/area_pra/pra_31/unk_18.gfx.inc.c"
#include "world/area_pra/pra_31/unk_19.gfx.inc.c"
#include "world/area_pra/pra_31/unk_20.gfx.inc.c"
#include "world/area_pra/pra_31/unk_21.gfx.inc.c"
#include "world/area_pra/pra_31/unk_22.gfx.inc.c"
#include "world/area_pra/pra_31/unk_23.gfx.inc.c"
#include "world/area_pra/pra_31/unk_24.gfx.inc.c"
#include "world/area_pra/pra_31/unk_25.gfx.inc.c"
#include "world/area_pra/pra_31/unk_26.gfx.inc.c"
#include "world/area_pra/pra_31/unk_27.gfx.inc.c"
#include "world/area_pra/pra_31/unk_28.gfx.inc.c"
#include "world/area_pra/pra_31/unk_29.gfx.inc.c"
#include "world/area_pra/pra_31/unk_30.gfx.inc.c"
#include "world/area_pra/pra_31/unk_31.gfx.inc.c"
#include "world/area_pra/pra_31/unk_32.gfx.inc.c"
#include "world/area_pra/pra_31/unk_33.gfx.inc.c"
#include "world/area_pra/pra_31/unk_34.gfx.inc.c"

// 0x10 long, doesnt seem to indicate a split
s32 N(post_gfx_pad)[] = { 0, 0, 0, 0 };

StaticAnimatorNode N(D_80245A90_D847F0) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .displayList = &N(unk_29_gfx),
};

StaticAnimatorNode N(D_80245ABC_D8481C) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .child = &N(D_80245A90_D847F0),
};

StaticAnimatorNode N(D_80245AE8_D84848) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .displayList = &N(unk_28_gfx),
};

StaticAnimatorNode N(D_80245B14_D84874) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .child = &N(D_80245AE8_D84848),
    .sibling = &N(D_80245ABC_D8481C),
};

StaticAnimatorNode N(D_80245B40_D848A0) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .displayList = &N(unk_27_gfx),
};

StaticAnimatorNode N(D_80245B6C_D848CC) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .child = &N(D_80245B40_D848A0),
    .sibling = &N(D_80245B14_D84874),
};

StaticAnimatorNode N(D_80245B98_D848F8) = {
    .pos = { 500.0f, 50.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(89.99725f) },
    .child = &N(D_80245B6C_D848CC),
};

StaticAnimatorNode N(D_80245BC4_D84924) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .displayList = &N(unk_25_gfx),
};

StaticAnimatorNode N(D_80245BF0_D84950) = {
    .pos = { 420.0f, 50.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-89.99725f) },
    .child = &N(D_80245BC4_D84924),
    .sibling = &N(D_80245B98_D848F8),
};

StaticAnimatorNode N(D_80245C1C_D8497C) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .displayList = &N(unk_21_gfx),
};

StaticAnimatorNode N(D_80245C48_D849A8) = {
    .pos = { 410.0f, 40.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-180.0f) },
    .child = &N(D_80245C1C_D8497C),
    .sibling = &N(D_80245BF0_D84950),
};

StaticAnimatorNode N(D_80245C74_D849D4) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .displayList = &N(unk_19_gfx),
};

StaticAnimatorNode N(D_80245CA0_D84A00) = {
    .pos = { 400.0f, 40.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-89.99725f) },
    .child = &N(D_80245C74_D849D4),
    .sibling = &N(D_80245C48_D849A8),
};

StaticAnimatorNode N(D_80245CCC_D84A2C) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .displayList = &N(unk_15_gfx),
};

StaticAnimatorNode N(D_80245CF8_D84A58) = {
    .pos = { 390.0f, 30.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-180.0f) },
    .child = &N(D_80245CCC_D84A2C),
    .sibling = &N(D_80245CA0_D84A00),
};

StaticAnimatorNode N(D_80245D24_D84A84) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .displayList = &N(unk_13_gfx),
};

StaticAnimatorNode N(D_80245D50_D84AB0) = {
    .pos = { 380.0f, 30.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-89.99725f) },
    .child = &N(D_80245D24_D84A84),
    .sibling = &N(D_80245CF8_D84A58),
};

StaticAnimatorNode N(D_80245D7C_D84ADC) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .displayList = &N(unk_11_gfx),
};

StaticAnimatorNode N(D_80245DA8_D84B08) = {
    .pos = { 380.0f, 20.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(89.99725f) },
    .child = &N(D_80245D7C_D84ADC),
    .sibling = &N(D_80245D50_D84AB0),
};

StaticAnimatorNode N(D_80245DD4_D84B34) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .displayList = &N(unk_09_gfx),
};

StaticAnimatorNode N(D_80245E00_D84B60) = {
    .pos = { 370.0f, 20.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-180.0f) },
    .child = &N(D_80245DD4_D84B34),
    .sibling = &N(D_80245DA8_D84B08),
};

StaticAnimatorNode N(D_80245E2C_D84B8C) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .displayList = &N(unk_07_gfx),
};

StaticAnimatorNode N(D_80245E58_D84BB8) = {
    .pos = { 360.0f, 20.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-89.99725f) },
    .child = &N(D_80245E2C_D84B8C),
    .sibling = &N(D_80245E00_D84B60),
};

StaticAnimatorNode N(D_80245E84_D84BE4) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .displayList = &N(unk_05_gfx),
};

StaticAnimatorNode N(D_80245EB0_D84C10) = {
    .pos = { 360.0f, 10.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(89.99725f) },
    .child = &N(D_80245E84_D84BE4),
    .sibling = &N(D_80245E58_D84BB8),
};

StaticAnimatorNode N(D_80245EDC_D84C3C) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .displayList = &N(unk_03_gfx),
};

StaticAnimatorNode N(D_80245F08_D84C68) = {
    .pos = { 350.0f, 10.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-180.0f) },
    .child = &N(D_80245EDC_D84C3C),
    .sibling = &N(D_80245EB0_D84C10),
};

StaticAnimatorNode N(D_80245F34_D84C94) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .displayList = &N(unk_01_gfx),
};

StaticAnimatorNode N(D_80245F60_D84CC0) = {
    .pos = { 340.0f, 10.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-89.99725f) },
    .child = &N(D_80245F34_D84C94),
    .sibling = &N(D_80245F08_D84C68),
};

StaticAnimatorNode N(D_80245F8C_D84CEC) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .displayList = &N(unk_17_gfx),
};

StaticAnimatorNode N(D_80245FB8_D84D18) = {
    .pos = { 400.0f, 30.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(89.99725f) },
    .child = &N(D_80245F8C_D84CEC),
    .sibling = &N(D_80245F60_D84CC0),
};

StaticAnimatorNode N(D_80245FE4_D84D44) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .displayList = &N(unk_23_gfx),
};

StaticAnimatorNode N(D_80246010_D84D70) = {
    .pos = { 420.0f, 40.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(89.99725f) },
    .child = &N(D_80245FE4_D84D44),
    .sibling = &N(D_80245FB8_D84D18),
};

StaticAnimatorNode N(D_8024603C_D84D9C) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .child = &N(D_80246010_D84D70),
};

StaticAnimatorNode N(D_80246068_D84DC8) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .child = &N(D_8024603C_D84D9C),
};

StaticAnimatorNode* N(AS_Stairs_Skeleton)[] = {
    &N(D_80246068_D84DC8), &N(D_8024603C_D84D9C),
    &N(D_80246010_D84D70), &N(D_80245FE4_D84D44),
    &N(D_80245FB8_D84D18), &N(D_80245F8C_D84CEC),
    &N(D_80245F60_D84CC0), &N(D_80245F34_D84C94),
    &N(D_80245F08_D84C68), &N(D_80245EDC_D84C3C),
    &N(D_80245EB0_D84C10), &N(D_80245E84_D84BE4),
    &N(D_80245E58_D84BB8), &N(D_80245E2C_D84B8C),
    &N(D_80245E00_D84B60), &N(D_80245DD4_D84B34),
    &N(D_80245DA8_D84B08), &N(D_80245D7C_D84ADC),
    &N(D_80245D50_D84AB0), &N(D_80245D24_D84A84),
    &N(D_80245CF8_D84A58), &N(D_80245CCC_D84A2C),
    &N(D_80245CA0_D84A00), &N(D_80245C74_D849D4),
    &N(D_80245C48_D849A8), &N(D_80245C1C_D8497C),
    &N(D_80245BF0_D84950), &N(D_80245BC4_D84924),
    &N(D_80245B98_D848F8), &N(D_80245B6C_D848CC),
    &N(D_80245B40_D848A0), &N(D_80245B14_D84874),
    &N(D_80245AE8_D84848), &N(D_80245ABC_D8481C),
    &N(D_80245A90_D847F0), NULL
};
