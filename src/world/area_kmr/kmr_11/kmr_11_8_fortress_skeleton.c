#include "kmr_11.h"

StaticAnimatorNode N(D_80247010_8E1110) = {
    .pos = { -334.0f, -285.0f, -118.0f },
    .rot = { AS_F(0.0f), AS_F(-164.94827f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_td1),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_8024703C_8E113C) = {
    .pos = { 0.0f, 89.0f, 0.0f },
    .rot = { AS_F(-180.0f), AS_F(0.0f), AS_F(0.0f) },
    .child = &N(D_80247010_8E1110),
};

StaticAnimatorNode N(D_80247068_8E1168) = {
    .pos = { -3.0f, -20.0f, -103.0f },
    .rot = { AS_F(-180.0f), AS_F(152.24768f), AS_F(0.0f) },
    .child = &N(D_8024703C_8E113C),
};

StaticAnimatorNode N(D_80247094_8E1194) = {
    .pos = { -129.0f, -285.0f, -386.0f },
    .rot = { AS_F(0.0f), AS_F(135.04807f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_te1),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_802470C0_8E11C0) = {
    .pos = { 0.0f, 89.0f, 0.0f },
    .rot = { AS_F(-180.0f), AS_F(0.0f), AS_F(0.0f) },
    .child = &N(D_80247094_8E1194),
};

StaticAnimatorNode N(D_802470EC_8E11EC) = {
    .pos = { -77.0f, -20.0f, -101.0f },
    .rot = { AS_F(-180.0f), AS_F(-147.74864f), AS_F(0.0f) },
    .child = &N(D_802470C0_8E11C0),
    .sibling = &N(D_80247068_8E1168),
};

StaticAnimatorNode N(D_80247118_8E1218) = {
    .pos = { 205.0f, -285.0f, -342.0f },
    .rot = { AS_F(0.0f), AS_F(75.0499f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_tf1),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247144_8E1244) = {
    .pos = { 0.0f, 89.0f, 0.0f },
    .rot = { AS_F(-180.0f), AS_F(0.0f), AS_F(0.0f) },
    .child = &N(D_80247118_8E1218),
};

StaticAnimatorNode N(D_80247170_8E1270) = {
    .pos = { -111.0f, -20.0f, -35.0f },
    .rot = { AS_F(-180.0f), AS_F(-87.74499f), AS_F(0.0f) },
    .child = &N(D_80247144_8E1244),
    .sibling = &N(D_802470EC_8E11EC),
};

StaticAnimatorNode N(D_8024719C_8E129C) = {
    .pos = { 334.0f, -285.0f, -31.0f },
    .rot = { AS_F(0.0f), AS_F(15.046235f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_ta1),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_802471C8_8E12C8) = {
    .pos = { 0.0f, 89.0f, 0.0f },
    .rot = { AS_F(-180.0f), AS_F(0.0f), AS_F(0.0f) },
    .child = &N(D_8024719C_8E129C),
};

StaticAnimatorNode N(D_802471F4_8E12F4) = {
    .pos = { -71.0f, -20.0f, 27.0f },
    .rot = { AS_F(-180.0f), AS_F(-27.746819f), AS_F(0.0f) },
    .child = &N(D_802471C8_8E12C8),
    .sibling = &N(D_80247170_8E1270),
};

StaticAnimatorNode N(D_80247220_8E1320) = {
    .pos = { 129.0f, -285.0f, 236.0f },
    .rot = { AS_F(0.0f), AS_F(-44.94644f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_tb1),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_8024724C_8E134C) = {
    .pos = { 0.0f, 89.0f, 0.0f },
    .rot = { AS_F(-180.0f), AS_F(0.0f), AS_F(0.0f) },
    .child = &N(D_80247220_8E1320),
};

StaticAnimatorNode N(D_80247278_8E1378) = {
    .pos = { 2.0f, -20.0f, 24.0f },
    .rot = { AS_F(-180.0f), AS_F(32.245857f), AS_F(0.0f) },
    .child = &N(D_8024724C_8E134C),
    .sibling = &N(D_802471F4_8E12F4),
};

StaticAnimatorNode N(D_802472A4_8E13A4) = {
    .pos = { -205.0f, -285.0f, 192.0f },
    .rot = { AS_F(0.0f), AS_F(-104.94461f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_tc1),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_802472D0_8E13D0) = {
    .pos = { 0.0f, 89.0f, 0.0f },
    .rot = { AS_F(-180.0f), AS_F(0.0f), AS_F(0.0f) },
    .child = &N(D_802472A4_8E13A4),
};

StaticAnimatorNode N(D_802472FC_8E13FC) = {
    .pos = { 36.0f, -20.0f, -41.0f },
    .rot = { AS_F(-180.0f), AS_F(92.24952f), AS_F(0.0f) },
    .child = &N(D_802472D0_8E13D0),
    .sibling = &N(D_80247278_8E1378),
};

StaticAnimatorNode N(D_80247328_8E1428) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .child = &N(D_802472FC_8E13FC),
};

StaticAnimatorNode N(D_80247354_8E1454) = {
    .pos = { -334.0f, -196.0f, -117.0f },
    .rot = { AS_F(0.0f), AS_F(-164.94827f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_td2),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247380_8E1480) = {
    .pos = { -3.0f, -109.0f, -103.0f },
    .rot = { AS_F(-180.0f), AS_F(152.24768f), AS_F(0.0f) },
    .child = &N(D_80247354_8E1454),
};

StaticAnimatorNode N(D_802473AC_8E14AC) = {
    .pos = { -129.0f, -196.0f, -385.0f },
    .rot = { AS_F(0.0f), AS_F(135.04807f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_te2),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_802473D8_8E14D8) = {
    .pos = { -77.0f, -109.0f, -101.0f },
    .rot = { AS_F(-180.0f), AS_F(-147.74864f), AS_F(0.0f) },
    .child = &N(D_802473AC_8E14AC),
    .sibling = &N(D_80247380_8E1480),
};

StaticAnimatorNode N(D_80247404_8E1504) = {
    .pos = { 205.0f, -196.0f, -341.0f },
    .rot = { AS_F(0.0f), AS_F(75.0499f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_tf2),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247430_8E1530) = {
    .pos = { -111.0f, -109.0f, -35.0f },
    .rot = { AS_F(-180.0f), AS_F(-87.74499f), AS_F(0.0f) },
    .child = &N(D_80247404_8E1504),
    .sibling = &N(D_802473D8_8E14D8),
};

StaticAnimatorNode N(D_8024745C_8E155C) = {
    .pos = { 334.0f, -196.0f, -30.0f },
    .rot = { AS_F(0.0f), AS_F(15.046235f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_ta2),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247488_8E1588) = {
    .pos = { -71.0f, -109.0f, 27.0f },
    .rot = { AS_F(-180.0f), AS_F(-27.746819f), AS_F(0.0f) },
    .child = &N(D_8024745C_8E155C),
    .sibling = &N(D_80247430_8E1530),
};

StaticAnimatorNode N(D_802474B4_8E15B4) = {
    .pos = { 129.0f, -196.0f, 237.0f },
    .rot = { AS_F(0.0f), AS_F(-44.94644f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_tb2),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_802474E0_8E15E0) = {
    .pos = { 2.0f, -109.0f, 24.0f },
    .rot = { AS_F(-180.0f), AS_F(32.245857f), AS_F(0.0f) },
    .child = &N(D_802474B4_8E15B4),
    .sibling = &N(D_80247488_8E1588),
};

StaticAnimatorNode N(D_8024750C_8E160C) = {
    .pos = { -205.0f, -196.0f, 193.0f },
    .rot = { AS_F(0.0f), AS_F(-104.94461f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_tc2),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247538_8E1638) = {
    .pos = { 36.0f, -109.0f, -41.0f },
    .rot = { AS_F(-180.0f), AS_F(92.24952f), AS_F(0.0f) },
    .child = &N(D_8024750C_8E160C),
    .sibling = &N(D_802474E0_8E15E0),
};

StaticAnimatorNode N(D_80247564_8E1664) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .child = &N(D_80247538_8E1638),
    .sibling = &N(D_80247328_8E1428),
};

StaticAnimatorNode N(D_80247590_8E1690) = {
    .pos = { -129.0f, -106.0f, -384.0f },
    .rot = { AS_F(0.0f), AS_F(135.04807f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_te3),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_802475BC_8E16BC) = {
    .pos = { -76.0f, -106.0f, -100.0f },
    .rot = { AS_F(0.0f), AS_F(-147.74864f), AS_F(0.0f) },
    .child = &N(D_80247590_8E1690),
};

StaticAnimatorNode N(D_802475E8_8E16E8) = {
    .pos = { -334.0f, -106.0f, -116.0f },
    .rot = { AS_F(0.0f), AS_F(-164.94827f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_td3),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247614_8E1714) = {
    .pos = { -3.0f, -106.0f, -103.0f },
    .rot = { AS_F(0.0f), AS_F(152.24768f), AS_F(0.0f) },
    .child = &N(D_802475E8_8E16E8),
    .sibling = &N(D_802475BC_8E16BC),
};

StaticAnimatorNode N(D_80247640_8E1740) = {
    .pos = { 205.0f, -106.0f, -340.0f },
    .rot = { AS_F(0.0f), AS_F(75.0499f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_tf3),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_8024766C_8E176C) = {
    .pos = { -110.0f, -106.0f, -35.0f },
    .rot = { AS_F(0.0f), AS_F(-87.74499f), AS_F(0.0f) },
    .child = &N(D_80247640_8E1740),
    .sibling = &N(D_80247614_8E1714),
};

StaticAnimatorNode N(D_80247698_8E1798) = {
    .pos = { 334.0f, -106.0f, -29.0f },
    .rot = { AS_F(0.0f), AS_F(15.046235f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_ta3),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_802476C4_8E17C4) = {
    .pos = { -71.0f, -106.0f, 26.0f },
    .rot = { AS_F(0.0f), AS_F(-27.746819f), AS_F(0.0f) },
    .child = &N(D_80247698_8E1798),
    .sibling = &N(D_8024766C_8E176C),
};

StaticAnimatorNode N(D_802476F0_8E17F0) = {
    .pos = { 129.0f, -106.0f, 238.0f },
    .rot = { AS_F(0.0f), AS_F(-44.94644f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_tb3),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_8024771C_8E181C) = {
    .pos = { 1.0f, -106.0f, 23.0f },
    .rot = { AS_F(0.0f), AS_F(32.245857f), AS_F(0.0f) },
    .child = &N(D_802476F0_8E17F0),
    .sibling = &N(D_802476C4_8E17C4),
};

StaticAnimatorNode N(D_80247748_8E1848) = {
    .pos = { -205.0f, -106.0f, 194.0f },
    .rot = { AS_F(0.0f), AS_F(-104.94461f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_tc3),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247774_8E1874) = {
    .pos = { 35.0f, -106.0f, -41.0f },
    .rot = { AS_F(0.0f), AS_F(92.24952f), AS_F(0.0f) },
    .child = &N(D_80247748_8E1848),
    .sibling = &N(D_8024771C_8E181C),
};

StaticAnimatorNode N(D_802477A0_8E18A0) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .child = &N(D_80247774_8E1874),
    .sibling = &N(D_80247564_8E1664),
};

StaticAnimatorNode N(D_802477CC_8E18CC) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .child = &N(D_802477A0_8E18A0),
};

StaticAnimatorNode N(D_802477F8_8E18F8) = {
    .pos = { -266.0f, 0.0f, -99.0f },
    .rot = { AS_F(0.0f), AS_F(12.695089f), AS_F(0.0f) },
    .child = &N(D_802477CC_8E18CC),
};

StaticAnimatorNode N(D_80247824_8E1924) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy27),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247850_8E1950) = {
    .pos = { -50.0f, -224.0f, 0.0f },
    .child = &N(D_80247824_8E1924),
};

StaticAnimatorNode N(D_8024787C_8E197C) = {
    .pos = { -67.0f, 0.0f, 86.0f },
    .rot = { AS_F(0.0f), AS_F(-44.99588f), AS_F(0.0f) },
    .child = &N(D_80247850_8E1950),
};

StaticAnimatorNode N(D_802478A8_8E19A8) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy28),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_802478D4_8E19D4) = {
    .pos = { -75.0f, -400.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-180.0f) },
    .child = &N(D_802478A8_8E19A8),
};

StaticAnimatorNode N(D_80247900_8E1A00) = {
    .pos = { -53.0f, 0.0f, 72.0f },
    .rot = { AS_F(0.0f), AS_F(-44.99588f), AS_F(0.0f) },
    .child = &N(D_802478D4_8E19D4),
    .sibling = &N(D_8024787C_8E197C),
};

StaticAnimatorNode N(D_8024792C_8E1A2C) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy29),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247958_8E1A58) = {
    .pos = { -50.0f, -224.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-89.99725f) },
    .child = &N(D_8024792C_8E1A2C),
};

StaticAnimatorNode N(D_80247984_8E1A84) = {
    .pos = { -58.0f, 0.0f, 55.0f },
    .rot = { AS_F(0.0f), AS_F(-44.99588f), AS_F(0.0f) },
    .child = &N(D_80247958_8E1A58),
    .sibling = &N(D_80247900_8E1A00),
};

StaticAnimatorNode N(D_802479B0_8E1AB0) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .child = &N(D_80247984_8E1A84),
};

StaticAnimatorNode N(D_802479DC_8E1ADC) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy21),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247A08_8E1B08) = {
    .pos = { -50.0f, -224.0f, 0.0f },
    .child = &N(D_802479DC_8E1ADC),
};

StaticAnimatorNode N(D_80247A34_8E1B34) = {
    .pos = { -288.0f, 0.0f, 204.0f },
    .rot = { AS_F(0.0f), AS_F(-89.99725f), AS_F(0.0f) },
    .child = &N(D_80247A08_8E1B08),
};

StaticAnimatorNode N(D_80247A60_8E1B60) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy22),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247A8C_8E1B8C) = {
    .pos = { -75.0f, -400.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-180.0f) },
    .child = &N(D_80247A60_8E1B60),
};

StaticAnimatorNode N(D_80247AB8_8E1BB8) = {
    .pos = { -300.0f, 0.0f, 201.0f },
    .rot = { AS_F(0.0f), AS_F(-89.99725f), AS_F(0.0f) },
    .child = &N(D_80247A8C_8E1B8C),
    .sibling = &N(D_80247A34_8E1B34),
};

StaticAnimatorNode N(D_80247AE4_8E1BE4) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy23),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247B10_8E1C10) = {
    .pos = { -50.0f, -224.0f, 0.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-89.99725f) },
    .child = &N(D_80247AE4_8E1BE4),
};

StaticAnimatorNode N(D_80247B3C_8E1C3C) = {
    .pos = { -269.0f, 0.0f, 186.0f },
    .rot = { AS_F(0.0f), AS_F(-89.99725f), AS_F(0.0f) },
    .child = &N(D_80247B10_8E1C10),
    .sibling = &N(D_80247AB8_8E1BB8),
};

StaticAnimatorNode N(D_80247B68_8E1C68) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .child = &N(D_80247B3C_8E1C3C),
    .sibling = &N(D_802479B0_8E1AB0),
};

StaticAnimatorNode N(D_80247B94_8E1C94) = {
    .pos = { 0.0f, -20.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy7),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247BC0_8E1CC0) = {
    .pos = { 0.0f, -400.0f, 203.0f },
    .child = &N(D_80247B94_8E1C94),
};

StaticAnimatorNode N(D_80247BEC_8E1CEC) = {
    .pos = { -271.0f, 0.0f, 53.0f },
    .child = &N(D_80247BC0_8E1CC0),
};

StaticAnimatorNode N(D_80247C18_8E1D18) = {
    .pos = { 0.0f, -20.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy8),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247C44_8E1D44) = {
    .pos = { 0.0f, -400.0f, 203.0f },
    .child = &N(D_80247C18_8E1D18),
};

StaticAnimatorNode N(D_80247C70_8E1D70) = {
    .pos = { -271.0f, 0.0f, 53.0f },
    .rot = { AS_F(0.0f), AS_F(9.997864f), AS_F(0.0f) },
    .child = &N(D_80247C44_8E1D44),
    .sibling = &N(D_80247BEC_8E1CEC),
};

StaticAnimatorNode N(D_80247C9C_8E1D9C) = {
    .pos = { 0.0f, -20.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy9),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247CC8_8E1DC8) = {
    .pos = { 0.0f, -400.0f, 203.0f },
    .child = &N(D_80247C9C_8E1D9C),
};

StaticAnimatorNode N(D_80247CF4_8E1DF4) = {
    .pos = { -271.0f, 0.0f, 53.0f },
    .rot = { AS_F(0.0f), AS_F(74.994965f), AS_F(0.0f) },
    .child = &N(D_80247CC8_8E1DC8),
    .sibling = &N(D_80247C70_8E1D70),
};

StaticAnimatorNode N(D_80247D20_8E1E20) = {
    .pos = { 0.0f, -20.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy10),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247D4C_8E1E4C) = {
    .pos = { 0.0f, -400.0f, 203.0f },
    .rot = { AS_F(0.0f), AS_F(89.99725f), AS_F(0.0f) },
    .child = &N(D_80247D20_8E1E20),
};

StaticAnimatorNode N(D_80247D78_8E1E78) = {
    .pos = { -271.0f, 0.0f, 53.0f },
    .rot = { AS_F(0.0f), AS_F(49.994812f), AS_F(0.0f) },
    .child = &N(D_80247D4C_8E1E4C),
    .sibling = &N(D_80247CF4_8E1DF4),
};

StaticAnimatorNode N(D_80247DA4_8E1EA4) = {
    .pos = { 0.0f, -20.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy11),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247DD0_8E1ED0) = {
    .pos = { 0.0f, -400.0f, 203.0f },
    .child = &N(D_80247DA4_8E1EA4),
};

StaticAnimatorNode N(D_80247DFC_8E1EFC) = {
    .pos = { -271.0f, 0.0f, 53.0f },
    .rot = { AS_F(0.0f), AS_F(-19.995728f), AS_F(0.0f) },
    .child = &N(D_80247DD0_8E1ED0),
    .sibling = &N(D_80247D78_8E1E78),
};

StaticAnimatorNode N(D_80247E28_8E1F28) = {
    .pos = { -30.0f, 20.0f, -30.0f },
    .child = &N(D_80247DFC_8E1EFC),
    .sibling = &N(D_80247B68_8E1C68),
};

StaticAnimatorNode N(D_80247E54_8E1F54) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy6),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247E80_8E1F80) = {
    .pos = { -135.0f, -400.0f, -191.0f },
    .rot = { AS_F(0.0f), AS_F(0.0f), AS_F(-180.0f) },
    .child = &N(D_80247E54_8E1F54),
};

StaticAnimatorNode N(D_80247EAC_8E1FAC) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy5),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247ED8_8E1FD8) = {
    .pos = { -150.0f, -400.0f, -191.0f },
    .child = &N(D_80247EAC_8E1FAC),
    .sibling = &N(D_80247E80_8E1F80),
};

StaticAnimatorNode N(D_80247F04_8E2004) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .modelID = AS_MODEL_ID(MODEL_dummy4),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247F30_8E2030) = {
    .pos = { -135.0f, -400.0f, -191.0f },
    .child = &N(D_80247F04_8E2004),
    .sibling = &N(D_80247ED8_8E1FD8),
};

StaticAnimatorNode N(D_80247F5C_8E205C) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .child = &N(D_80247F30_8E2030),
    .sibling = &N(D_80247E28_8E1F28),
};

StaticAnimatorNode N(D_80247F88_8E2088) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .child = &N(D_80247F5C_8E205C),
    .sibling = &N(D_802477F8_8E18F8),
};

StaticAnimatorNode N(D_80247FB4_8E20B4) = {
    .pos = { 276.0f, -401.0f, 194.0f },
    .rot = { AS_F(0.0f), AS_F(-12.695089f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_top),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80247FE0_8E20E0) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .child = &N(D_80247FB4_8E20B4),
};

StaticAnimatorNode N(D_8024800C_8E210C) = {
    .pos = { 8.0f, 26.0f, 104.0f },
    .rot = { AS_F(0.0f), AS_F(-177.84662f), AS_F(0.0f) },
    .child = &N(D_80247FE0_8E20E0),
};

StaticAnimatorNode N(D_80248038_8E2138) = {
    .pos = { -6.0f, 0.0f, 197.0f },
    .rot = { AS_F(0.0f), AS_F(177.84662f), AS_F(0.0f) },
    .child = &N(D_8024800C_8E210C),
};

StaticAnimatorNode N(D_80248064_8E2164) = {
    .pos = { 3.0f, 0.0f, 87.0f },
    .rot = { AS_F(89.99725f), AS_F(0.0f), AS_F(0.0f) },
    .child = &N(D_80248038_8E2138),
};

StaticAnimatorNode N(D_80248090_8E2190) = {
    .pos = { 300.0f, -250.0f, -150.0f },
    .rot = { AS_F(0.0f), AS_F(12.695089f), AS_F(0.0f) },
    .child = &N(D_80248064_8E2164),
    .sibling = &N(D_80247F88_8E2088),
};

StaticAnimatorNode N(D_802480BC_8E21BC) = {
    .pos = { 346.0f, -335.0f, -34.0f },
    .rot = { AS_F(0.0f), AS_F(14.996796f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_mado3),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_802480E8_8E21E8) = {
    .pos = { -343.0f, -55.0f, -56.0f },
    .rot = { AS_F(0.0f), AS_F(-14.996796f), AS_F(-34.998016f) },
    .child = &N(D_802480BC_8E21BC),
};

StaticAnimatorNode N(D_80248114_8E2214) = {
    .pos = { 176.0f, -206.0f, -342.0f },
    .rot = { AS_F(0.0f), AS_F(74.994965f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_mado1),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80248140_8E2240) = {
    .pos = { -376.0f, -106.0f, -82.0f },
    .rot = { AS_F(29.999084f), AS_F(-74.994965f), AS_F(0.0f) },
    .child = &N(D_80248114_8E2214),
    .sibling = &N(D_802480E8_8E21E8),
};

StaticAnimatorNode N(D_8024816C_8E226C) = {
    .pos = { 122.0f, -212.0f, 235.0f },
    .rot = { AS_F(0.0f), AS_F(-44.99588f), AS_F(0.0f) },
    .modelID = AS_MODEL_ID(MODEL_mado2),
    .vtxList = 0,
    .vertexStartOffset = -1
};

StaticAnimatorNode N(D_80248198_8E2298) = {
    .pos = { -252.0f, -102.0f, -80.0f },
    .rot = { AS_F(0.0f), AS_F(44.99588f), AS_F(89.99725f) },
    .child = &N(D_8024816C_8E226C),
    .sibling = &N(D_80248140_8E2240),
};

StaticAnimatorNode N(D_802481C4_8E22C4) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .child = &N(D_80248198_8E2298),
    .sibling = &N(D_80248090_8E2190),
};

StaticAnimatorNode N(D_802481F0_8E22F0) = {
    .pos = { 0.0f, 0.0f, 0.0f },
    .child = &N(D_802481C4_8E22C4),
};

StaticAnimatorNode* N(AnimSkeleton_Fortress)[] = {
    &N(D_802481F0_8E22F0), &N(D_802481C4_8E22C4), &N(D_80248198_8E2298), &N(D_8024816C_8E226C),
    &N(D_80248140_8E2240), &N(D_80248114_8E2214), &N(D_802480E8_8E21E8), &N(D_802480BC_8E21BC),
    &N(D_80248090_8E2190), &N(D_80248064_8E2164), &N(D_80248038_8E2138), &N(D_8024800C_8E210C),
    &N(D_80247FE0_8E20E0), &N(D_80247FB4_8E20B4), &N(D_80247F88_8E2088), &N(D_80247F5C_8E205C),
    &N(D_80247F30_8E2030), &N(D_80247F04_8E2004), &N(D_80247ED8_8E1FD8), &N(D_80247EAC_8E1FAC),
    &N(D_80247E80_8E1F80), &N(D_80247E54_8E1F54), &N(D_80247E28_8E1F28), &N(D_80247DFC_8E1EFC),
    &N(D_80247DD0_8E1ED0), &N(D_80247DA4_8E1EA4), &N(D_80247D78_8E1E78), &N(D_80247D4C_8E1E4C),
    &N(D_80247D20_8E1E20), &N(D_80247CF4_8E1DF4), &N(D_80247CC8_8E1DC8), &N(D_80247C9C_8E1D9C),
    &N(D_80247C70_8E1D70), &N(D_80247C44_8E1D44), &N(D_80247C18_8E1D18), &N(D_80247BEC_8E1CEC),
    &N(D_80247BC0_8E1CC0), &N(D_80247B94_8E1C94), &N(D_80247B68_8E1C68), &N(D_80247B3C_8E1C3C),
    &N(D_80247B10_8E1C10), &N(D_80247AE4_8E1BE4), &N(D_80247AB8_8E1BB8), &N(D_80247A8C_8E1B8C),
    &N(D_80247A60_8E1B60), &N(D_80247A34_8E1B34), &N(D_80247A08_8E1B08), &N(D_802479DC_8E1ADC),
    &N(D_802479B0_8E1AB0), &N(D_80247984_8E1A84), &N(D_80247958_8E1A58), &N(D_8024792C_8E1A2C),
    &N(D_80247900_8E1A00), &N(D_802478D4_8E19D4), &N(D_802478A8_8E19A8), &N(D_8024787C_8E197C),
    &N(D_80247850_8E1950), &N(D_80247824_8E1924), &N(D_802477F8_8E18F8), &N(D_802477CC_8E18CC),
    &N(D_802477A0_8E18A0), &N(D_80247774_8E1874), &N(D_80247748_8E1848), &N(D_8024771C_8E181C),
    &N(D_802476F0_8E17F0), &N(D_802476C4_8E17C4), &N(D_80247698_8E1798), &N(D_8024766C_8E176C),
    &N(D_80247640_8E1740), &N(D_80247614_8E1714), &N(D_802475E8_8E16E8), &N(D_802475BC_8E16BC),
    &N(D_80247590_8E1690), &N(D_80247564_8E1664), &N(D_80247538_8E1638), &N(D_8024750C_8E160C),
    &N(D_802474E0_8E15E0), &N(D_802474B4_8E15B4), &N(D_80247488_8E1588), &N(D_8024745C_8E155C),
    &N(D_80247430_8E1530), &N(D_80247404_8E1504), &N(D_802473D8_8E14D8), &N(D_802473AC_8E14AC),
    &N(D_80247380_8E1480), &N(D_80247354_8E1454), &N(D_80247328_8E1428), &N(D_802472FC_8E13FC),
    &N(D_802472D0_8E13D0), &N(D_802472A4_8E13A4), &N(D_80247278_8E1378), &N(D_8024724C_8E134C),
    &N(D_80247220_8E1320), &N(D_802471F4_8E12F4), &N(D_802471C8_8E12C8), &N(D_8024719C_8E129C),
    &N(D_80247170_8E1270), &N(D_80247144_8E1244), &N(D_80247118_8E1218), &N(D_802470EC_8E11EC),
    &N(D_802470C0_8E11C0), &N(D_80247094_8E1194), &N(D_80247068_8E1168), &N(D_8024703C_8E113C),
    &N(D_80247010_8E1110), NULL
};
