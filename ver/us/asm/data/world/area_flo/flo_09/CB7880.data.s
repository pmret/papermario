.include "macro.inc"

.section .data

dlabel D_80242880_CB7880
.word 0x00000030, 0x00000001, 0xFE363C80, 0x00000034, 0x00000004, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C85, 0xFE363C8F, 0xFE363C87, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000005, 0x00000001, 0x00000005, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, flo_09_TransformFoliage, 0xFE363C83, 0xF24A7AE7, 0x00000001, 0xFE363C8F, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtModel, 0xFE363C83, 0x00000153, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, flo_09_TransformFoliage, 0xFE363C83, 0xF24A7AE7, 0xFFFFFFFF, 0xFE363C8F, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000005, TranslateModel, 0xFE363C83, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C82, 0x00000000, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000033, 0x00000003, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0x00000033, 0x00000003, 0xFE363C88, 0xFE363C89, 0xFE363C8A, 0x0000000A, 0x00000002, 0xFE363C8A, 0x00000000, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000012, 0x00000000, 0x00000043, 0x00000003, GetValueByRef, 0xFE363C8A, 0xFE363C8B, 0x0000000A, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000043, 0x00000003, SetValueByRef, 0xFE363C8A, 0x00000001, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C84, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x0000000B, 0x00000002, 0xFE363C84, 0x00000000, 0x00000046, 0x00000001, 0xFE363C84, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80242BE0_CB7BE0
.word 0x0000004C, 0x00000001, 0xF24A8280, 0x00000030, 0x00000001, 0xFE363C80, 0x00000034, 0x00000004, 0xFE363C81, 0xFE363C82, 0xFE363C83, 0xFE363C84, 0x00000031, 0x00000001, 0xFE363C85, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C86, 0xFE363C8F, 0xFE363C88, 0x00000043, 0x00000002, PlaySound, 0x00000165, 0x00000043, 0x00000002, PlaySound, 0x00000166, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C81, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000005, 0x00000001, 0x00000005, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, flo_09_TransformFoliage, 0xFE363C83, 0xF24A7AE7, 0xF24A7B4D, 0xFE363C8F, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtModel, 0xFE363C83, 0x00000166, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000006, flo_09_TransformFoliage, 0xFE363C83, 0xF24A7AE7, 0xF24A79B4, 0xFE363C8F, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000030, 0x00000001, 0xFE363C81, 0x00000031, 0x00000001, 0xFE363C82, 0x00000005, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000043, 0x00000005, TranslateModel, 0xFE363C83, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C82, 0x00000000, 0x00000005, 0x00000001, 0x00000005, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000043, 0x00000006, flo_09_TransformFoliage, 0xFE363C84, 0xF24A7AE7, 0xF24A7B4D, 0xFE363C8F, 0x00000000, 0x0000000A, 0x00000002, 0xFBD3E280, 0x00000000, 0x00000024, 0x00000002, 0xFBD3E280, 0x00000001, 0x00000043, 0x00000004, PlaySoundAtModel, 0xFE363C84, 0x00000165, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000043, 0x00000006, flo_09_TransformFoliage, 0xFE363C84, 0xF24A7AE7, 0xF24A79B4, 0xFE363C8F, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000030, 0x00000001, 0xFE363C82, 0x00000031, 0x00000001, 0xFE363C83, 0x00000005, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000043, 0x00000005, TranslateModel, 0xFE363C84, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C83, 0x00000000, 0x00000030, 0x00000001, 0xFE363C83, 0x00000031, 0x00000001, 0xFE363C84, 0x00000005, 0x00000001, 0xFE363C84, 0x00000031, 0x00000001, 0xFE363C85, 0x00000033, 0x00000003, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000033, 0x00000003, 0xFE363C89, 0xFE363C8A, 0xFE363C8B, 0x0000000A, 0x00000002, 0xFE363C8B, 0x00000000, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0xFE363C8A, 0x00000012, 0x00000000, 0x00000043, 0x00000003, GetValueByRef, 0xFE363C8B, 0xFE363C8C, 0x0000000A, 0x00000002, 0xFE363C8C, 0x00000000, 0x00000043, 0x00000003, SetValueByRef, 0xFE363C8B, 0x00000001, 0x00000043, 0x00000007, DropItemEntity, 0xFE363C85, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0xFE363C89, 0xFE363C8A, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x00000056, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C84, 0x00000000, 0x00000030, 0x00000001, 0xFE363C84, 0x00000031, 0x00000001, 0xFE363C85, 0x00000005, 0x00000001, 0xFE363C85, 0x00000033, 0x00000003, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000043, 0x0000000F, PlayEffect, 0x00000014, 0x00000000, 0xFE363C86, 0xFE363C87, 0xFE363C88, 0x00000064, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000006, 0x00000000, 0x00000013, 0x00000000, 0x00000057, 0x00000000, 0x0000000B, 0x00000002, 0xFE363C85, 0x00000000, 0x00000046, 0x00000001, 0xFE363C85, 0x00000013, 0x00000000, 0x00000008, 0x00000001, 0x0000000F, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802431E4_CB81E4
.word 0x00000043, 0x00000005, GetNpcPos, 0x00000003, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000C, 0x00000002, 0xFE363C81, 0x00000000, 0x00000043, 0x00000002, GetModelCenter, 0xFE363C89, 0x00000027, 0x00000002, 0xFE363C82, 0x00000023, 0x00000043, 0x00000005, SetNpcPos, 0x00000003, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243264_CB8264
.word 0x0000000A, 0x00000002, 0xF84060E6, 0x00000000, 0x0000000A, 0x00000002, 0xF70F2E85, 0x00000001, 0x00000043, 0x00000007, MakeItemEntity, 0x00000141, 0xFFFFFF06, 0x00000064, 0x00000000, 0x0000000D, 0xF84060E6, 0x00000012, 0x00000000, 0x00000024, 0x00000002, 0xFE363C89, 0x0000000E, 0x00000044, 0x00000001, D_802431E4_CB81E4, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xF70F2E84, 0x00000000, 0x00000024, 0x00000002, 0xF70F2E85, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024330C_CB830C
.word 0x0000000A, 0x00000002, 0xF84060E6, 0x00000000, 0x00000024, 0x00000002, 0xF70F2E84, 0x00000001, 0x00000024, 0x00000002, 0xF70F2E85, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243354_CB8354
.word 0x0000000A, 0x00000002, 0xF84060E6, 0x00000000, 0x0000000A, 0x00000002, 0xF70F2E84, 0x00000001, 0x0000000A, 0x00000002, 0xF70F2E85, 0x00000000, 0x00000024, 0x00000002, 0xF70F2E85, 0x00000001, 0x00000002, 0x00000000, 0x00000013, 0x00000000, 0x00000013, 0x00000000, 0x00000024, 0x00000002, 0xFE363C89, 0x00000016, 0x00000044, 0x00000001, D_802431E4_CB81E4, 0x00000024, 0x00000002, 0xF70F2E84, 0x00000000, 0x00000024, 0x00000002, 0xF70F2E85, 0x00000000, 0x00000013, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243400_CB8400
.word 0x00000002, 0x0000000F, 0x00000010

dlabel D_8024340C_CB840C
.word 0x00000001, 0x0000000E

dlabel D_80243414_CB8414
.word D_80243400_CB8400, D_8024340C_CB840C, 0x00000000, 0x00000000, D_80243264_CB8264

dlabel D_80243428_CB8428
.word 0xC3480000, 0x00000000, 0x3F800000, 0x00000000

dlabel D_80243438_CB8438
.word 0x00000002, 0x00000013, 0x00000014

dlabel D_80243444_CB8444
.word 0x00000001, 0x00000012

dlabel D_8024344C_CB844C
.word D_80243438_CB8438, D_80243444_CB8444, 0x00000000, 0x00000000, D_8024330C_CB830C

dlabel D_80243460_CB8460
.word 0x00000000, 0x00000000, 0x3F800000, 0x00000000

dlabel D_80243470_CB8470
.word 0x00000002, 0x00000017, 0x00000018

dlabel D_8024347C_CB847C
.word 0x00000001, 0x00000016

dlabel D_80243484_CB8484
.word D_80243470_CB8470, D_8024347C_CB847C, 0x00000000, 0x00000000, D_80243354_CB8354

dlabel D_80243498_CB8498
.word 0x43480000, 0x00000000, 0x3F800000, 0x00000000, 0x00000024, 0x00000002, 0xF70F2E84, 0x00000000, 0x00000024, 0x00000002, 0xF70F2E85, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_80243414_CB8414, 0x00000047, 0x00000005, D_80242BE0_CB7BE0, 0x00001000, 0x0000000F, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80242BE0_CB7BE0, 0x00100000, D_80243428_CB8428, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_8024344C_CB844C, 0x00000047, 0x00000005, D_80242BE0_CB7BE0, 0x00001000, 0x00000010, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80242BE0_CB7BE0, 0x00100000, D_80243460_CB8460, 0x00000001, 0x00000000, 0x00000024, 0x00000002, 0xFE363C80, D_80243484_CB8484, 0x00000047, 0x00000005, D_80242BE0_CB7BE0, 0x00001000, 0x00000011, 0x00000001, 0x00000000, 0x00000047, 0x00000005, D_80242BE0_CB7BE0, 0x00100000, D_80243498_CB8498, 0x00000001, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802435B0_CB85B0
.word 0x3F800000, 0x000001F4, 0x0000000A, 0x42480000, 0x41F00000, 0x00000003, 0x40600000, 0x00000028, 0x00000003, 0x42C80000, 0x41F00000, 0x00000001

dlabel D_802435E0_CB85E0
.word 0x00000043, 0x00000002, DoBasicAI, D_802435B0_CB85B0, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243600_CB8600
.word 0x00000000, 0x001E0018, 0x00000000, 0x00000000, D_802435E0_CB85E0, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00130000

dlabel D_8024362C_CB862C
.float 4.5, 3.5, 2.6, 2.0, 1.5, 20.0

dlabel D_80243644_CB8644
.word 0x3F800000, 0x0000001E, 0x00000005, 0x42A00000, 0x41F00000, 0x00000002, 0x40900000, 0x00000006, 0x00000001, 0x42B40000, 0x41F00000, 0x00000001

dlabel D_80243674_CB8674
.word 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000005, 0xFFFFFD8A, 0x00000043, 0x00000003, SetSelfVar, 0x00000006, 0x00000032, 0x00000043, 0x00000003, SetSelfVar, 0x00000001, 0x000000C8, 0x00000043, 0x00000002, func_8024162C_CB662C, D_80243644_CB8644, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802436E4_CB86E4
.word 0x00000000, 0x001A0018, 0x00000000, 0x00000000, D_80243674_CB8674, EnemyNpcHit, 0x00000000, EnemyNpcDefeat, 0x00000000, 0x00000000, 0x00130000

dlabel D_80243710_CB8710
.word 0x00000000, 0x00180018, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00630000

dlabel D_8024373C_CB873C
.word 0x00000005, 0x00000001, 0x00000000, 0x00000043, 0x00000003, GetSelfVar, 0x00000000, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000005, GetNpcPos, 0xFFFFFFFF, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x0000000D, 0x00000002, 0xFE363C81, 0x00000000, 0x00000043, 0x00000004, GetPlayerPos, 0xFE363C80, 0xFE363C81, 0xFE363C82, 0x00000043, 0x00000003, SetNpcJumpscale, 0xFFFFFFFF, 0x00000000, 0x00000043, 0x00000006, NpcJump0, 0xFFFFFFFF, 0xFE363C80, 0x00000032, 0xFE363C82, 0x0000000F, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000001, 0x00000043, 0x00000003, BindNpcAI, 0xFFFFFFFF, D_80243674_CB8674, 0x00000013, 0x00000000, 0x00000016, 0x00000001, 0x00000002, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000001, 0x00000008, 0x00000001, 0x00000019, 0x00000043, 0x00000005, SetNpcPos, 0xFFFFFFFF, 0x00000000, 0xFFFFFC18, 0x00000000, 0x00000043, 0x00000004, SetNpcFlagBits, 0xFFFFFFFF, 0x00000002, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000000, 0x00000043, 0x00000002, DisablePlayerInput, 0x00000000, 0x00000023, 0x00000000, 0x00000008, 0x00000001, 0x00000001, 0x00000006, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_802438C8_CB88C8
.word 0x00000043, 0x00000002, GetBattleOutcome, 0xFE363C80, 0x00000014, 0x00000001, 0xFE363C80, 0x00000016, 0x00000001, 0x00000000, 0x00000043, 0x00000003, SetSelfVar, 0x00000000, 0x00000002, 0x00000043, 0x00000003, BindNpcAI, 0xFFFFFFFF, D_8024373C_CB873C, 0x00000043, 0x00000001, DoNpcDefeat, 0x00000016, 0x00000001, 0x00000001, 0x00000016, 0x00000001, 0x00000002, 0x00000023, 0x00000000, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_80243954_CB8954
.word 0x00000043, 0x00000003, BindNpcIdle, 0xFFFFFFFF, D_8024373C_CB873C, 0x00000043, 0x00000003, BindNpcDefeat, 0xFFFFFFFF, D_802438C8_CB88C8, 0x00000002, 0x00000000, 0x00000001, 0x00000000

dlabel D_8024398C_CB898C
.word 0x00000000, D_80243600_CB8600, 0xC3AF0000, 0x00000000, 0x42200000, 0x00002D00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x800F00A3, 0x00060000, 0x00A40004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0004, 0x33322666, 0x33320004, 0x33323FFF, 0x33320004, 0x33326665, 0x33320004, 0x33327FFF, 0x26660004, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0xFFFFFEA2, 0x00000000, 0x00000028, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFEA2, 0x00000000, 0x00000028, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00480001, 0x00480002, 0x00480003, 0x00480003, 0x00480001, 0x00480001, 0x00480008, 0x00480008, 0x00480006, 0x00480007, 0x00480001, 0x00480001, 0x00480001, 0x00480001, 0x00480001, 0x00480001, 0x00000003, 0x00000000, 0x00000000, 0x00000000

dlabel D_80243B7C_CB8B7C
.word 0x00000001, D_80243600_CB8600, 0x43820000, 0x00000000, 0x42960000, 0x00002D00, 0x00000000, 0x00000000, 0x00000000, 0x0000010E, 0x800F00A3, 0x00060000, 0x00A40004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980002, 0x3FFF2666, 0x4CCC0002, 0x3FFF3FFF, 0x3FFF0002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0004, 0x33322666, 0x33320004, 0x33323FFF, 0x33320004, 0x33326665, 0x33320004, 0x33327FFF, 0x26660004, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00030000, 0x00000104, 0x00000000, 0x0000004B, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0x00000104, 0x00000000, 0x0000004B, 0x000000C8, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00480001, 0x00480002, 0x00480003, 0x00480003, 0x00480001, 0x00480001, 0x00480008, 0x00480008, 0x00480006, 0x00480007, 0x00480001, 0x00480001, 0x00480001, 0x00480001, 0x00480001, 0x00480001, 0x00000003, 0x00000000, 0x00000000, 0x00000000

dlabel D_80243D6C_CB8D6C
.word 0x00000002, D_802436E4_CB86E4, 0xC2480000, 0x425C0000, 0x42B40000, 0x00002D00, 0x00000000, 0x00000000, 0x00000000, 0x0000005A, 0x800F00A3, 0x00060000, 0x00A40004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00040000, 0xFFFFFFCE, 0x00000037, 0x0000005A, 0x0000001E, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFFCE, 0x00000032, 0x0000005A, 0x000000FA, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x004B0002, 0x004B0002, 0x004B0003, 0x004B0003, 0x004B0001, 0x004B0002, 0x004B0006, 0x004B0006, 0x004B0004, 0x004B0002, 0x004B0001, 0x004B0001, 0x004B0001, 0x004B0001, 0x004B0001, 0x004B0001, 0x00000003, 0x00000000, 0x00000000, 0x00000000

dlabel D_80243F5C_CB8F5C
.word 0x00000003, D_80243710_CB8710, 0x00000000, 0xC47A0000, 0x00000000, 0x00002D04, D_80243954_CB8954, 0x00000000, 0x00000000, 0x0000005A, 0x800F00A3, 0x00060000, 0x00A40004, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x59980003, 0x3FFF2666, 0x4CCC0003, 0x3FFF3FFF, 0x3FFF0003, 0x33326665, 0x33320003, 0x33327FFF, 0x26660003, 0x26660000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00001999, 0x3FFF0002, 0x33322666, 0x33320002, 0x33323FFF, 0x33320002, 0x33326665, 0x33320002, 0x33327FFF, 0x26660002, 0x33320000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000001, 0x00040000, 0xFFFFFFCE, 0x00000037, 0x0000005A, 0x00000064, 0x00000000, 0xFFFF8001, 0x00000000, 0xFFFFFFCE, 0x00000032, 0x0000005A, 0x000000FA, 0x00000000, 0x00000000, 0x00000001, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x004B0002, 0x004B0002, 0x004B0003, 0x004B0003, 0x004B0001, 0x004B0002, 0x004B0006, 0x004B0006, 0x004B0004, 0x004B0002, 0x004B0001, 0x004B0001, 0x004B0001, 0x004B0001, 0x004B0001, 0x004B0001, 0x00000003, 0x00000000, 0x00000000, 0x00000000, 0x00000001, D_8024398C_CB898C, 0x18100005, 0x00000001, D_80243B7C_CB8B7C, 0x18150005, 0x00000001, D_80243D6C_CB8D6C, 0x18170002, 0x00000001, D_80243F5C_CB8F5C, 0x18170002, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000
