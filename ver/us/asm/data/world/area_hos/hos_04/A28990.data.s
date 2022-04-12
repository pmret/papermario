.include "macro.inc"

.section .data

dlabel D_80241AC0_A28990
.word 0xC4274000, 0x42C40000, 0xC2080000, 0xC4274000, 0x42880000, 0xC2080000, 0xC4210000, 0x41600000, 0xC1B80000, 0xC40D0000, 0x41000000, 0x42200000, 0xC3A20000, 0x43080000, 0x432F0000, 0xC2180000, 0x42EC0000, 0x00000000, 0x434D0000, 0x42DE0000, 0x00000000, 0x43988000, 0x42CA0000, 0x00000000, 0x00000000

dlabel D_80241B24_A289F4
.word 0x00000000, 0x442F0000, 0xBF666666, 0x00000000, 0xBF800000, 0x00000000, 0x43FA0000, 0xBF800000, 0x00000000, 0xC18B3333, 0x00000000

dlabel D_80241B50_A28A20
.word 0x00000000

dlabel D_80241B54_A28A24
.word 0x44264000, 0xBF666666, 0x00000000, 0xBF800000, 0x00000000, 0x43FA0000, 0xBF800000, 0x00000000

dlabel D_80241B74_A28A44
.word 0xC18B3333, 0x00000000

dlabel D_80241B7C_A28A4C
.word 0x442F0000

dlabel D_80241B80_A28A50
.word 0x00000000

dlabel D_80241B84_A28A54
.word 0x00000000

dlabel D_80241B88_A28A58
.word 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000003, hos_04_SetCamXXVfov, 0x00000000, 0x0000004B, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0x00000000, 0x0000001E, 0x00000000, 0x00000043, 0x00000003, LoadSettings, 0x00000000, D_80241B50_A28A20, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000056, 0x00000000, 0x00000044, 0x00000001, D_80241C5C_A28B2C, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241C5C_A28B2C
.word 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x0020001A, 0x00000043, 0x00000003, SetNpcYaw, 0x00000000, 0x000000B4, 0x00000043, 0x00000001, func_802409B0_A27880, 0x00000008, 0x00000001, 0x0000000F, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000000A, 0x00000043, 0x00000004, InterpNpcYaw, 0x00000000, 0x00000000, 0x00000000, 0x00000008, 0x00000001, 0x00000002, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x00200000, 0x00000008, 0x00000001, 0x00000014, 0x00000043, 0x00000004, InterpNpcYaw, 0x00000000, 0x000000B4, 0x00000000, 0x00000008, 0x00000001, 0x00000002, 0x00000043, 0x00000003, SetNpcAnimation, 0x00000000, 0x0020001A, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000064, 0x00000043, 0x00000001, func_80240A84_A27954, 0x00000057, 0x00000000, 0x00000043, 0x00000005, LoadPath, 0x000000C8, D_80241AC0_A28990, 0x00000008, 0x00000000, 0x00000003, 0x00000001, 0x00000000, 0x00000043, 0x00000001, GetNextPathPos, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0x00000008, 0x00000001, 0x00000001, 0x0000000A, 0x00000002, 0xFE363C80, 0x00000001, 0x00000004, 0x00000001, 0x00000000, 0x00000013, 0x00000000, 0x00000043, 0x00000005, SetNpcPos, 0x00000000, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x00000055, 0x00000043, 0x00000001, func_8024068C_A2755C, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x00000078, 0x00000043, 0x00000001, func_80240654_A27524, 0x00000002, 0x00000000, 0x00000001, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000043, 0x00000002, DisablePlayerPhysics, 0x00000001, 0x00000043, 0x00000003, SetCamLeadPlayer, 0x00000000, 0x00000000, 0x00000043, 0x00000003, hos_04_SetCamXXVfov, 0x00000000, 0x0000004B, 0x00000043, 0x00000005, SetPanTarget, 0x00000000, 0x00000000, 0x0000001E, 0x00000000, 0x00000043, 0x00000003, LoadSettings, 0x00000000, D_80241B24_A289F4, 0x00000043, 0x00000004, PanToTarget, 0x00000000, 0x00000000, 0x00000001, 0x00000043, 0x00000003, SetCamSpeed, 0x00000000, 0xF24BE280, 0x00000056, 0x00000000, 0x00000043, 0x00000001, func_802408F8_A277C8, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000008, 0x00000001, 0x0000012C, 0x00000043, 0x00000001, func_80240654_A27524, 0x00000057, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241F40_A28E10
.word 0x00000000, 0x001A0018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000, 0x00000000, 0x00140014, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000, 0x00000000, 0x00160018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_80241FC4_A28E94
.word 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80241FD4_A28EA4
.word 0x00000000, D_80241F40_A28E10, 0x00000000, 0xC47A0000, 0x00000000, 0x00000801, D_80241FC4_A28E94, 0x00000000, 0x00000000, 0x0000010E, 0x80000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007FFF, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00200001, 0x00200005, 0x00200008, 0x00200008, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00200001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_80241FD4_A28EA4, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
