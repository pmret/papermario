.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_802459E0
/* 138D20 802459E0 27D00065 */   addiu $s0, $fp, 0x65
/* 138D24 802459E4 0C093BA0 */  jal   func_8024EE80
/* 138D28 802459E8 24040032 */   addiu $a0, $zero, 0x32
/* 138D2C 802459EC 0040202D */  daddu $a0, $v0, $zero
/* 138D30 802459F0 0200302D */  daddu $a2, $s0, $zero
/* 138D34 802459F4 8FA80084 */  lw    $t0, 0x84($sp)
/* 138D38 802459F8 240700FF */  addiu $a3, $zero, 0xff
/* 138D3C 802459FC 2508009B */  addiu $t0, $t0, 0x9b
/* 138D40 80245A00 0100282D */  daddu $a1, $t0, $zero
/* 138D44 80245A04 AFA80054 */  sw    $t0, 0x54($sp)
/* 138D48 80245A08 2408000A */  addiu $t0, $zero, 0xa
/* 138D4C 80245A0C AFA80010 */  sw    $t0, 0x10($sp)
/* 138D50 80245A10 24080001 */  addiu $t0, $zero, 1
/* 138D54 80245A14 0C04993B */  jal   draw_string
/* 138D58 80245A18 AFA80014 */   sw    $t0, 0x14($sp)
/* 138D5C 80245A1C 0200302D */  daddu $a2, $s0, $zero
/* 138D60 80245A20 24070001 */  addiu $a3, $zero, 1
/* 138D64 80245A24 8FA80084 */  lw    $t0, 0x84($sp)
/* 138D68 80245A28 3C048011 */  lui   $a0, 0x8011
/* 138D6C 80245A2C 8484F29C */  lh    $a0, -0xd64($a0)
/* 138D70 80245A30 24120003 */  addiu $s2, $zero, 3
/* 138D74 80245A34 AFB20018 */  sw    $s2, 0x18($sp)
/* 138D78 80245A38 25140119 */  addiu $s4, $t0, 0x119
/* 138D7C 80245A3C 0280282D */  daddu $a1, $s4, $zero
/* 138D80 80245A40 2408000A */  addiu $t0, $zero, 0xa
/* 138D84 80245A44 AFA80010 */  sw    $t0, 0x10($sp)
/* 138D88 80245A48 240800FF */  addiu $t0, $zero, 0xff
/* 138D8C 80245A4C 0C049DA7 */  jal   draw_number
/* 138D90 80245A50 AFA80014 */   sw    $t0, 0x14($sp)
/* 138D94 80245A54 27C6006C */  addiu $a2, $fp, 0x6c
/* 138D98 80245A58 8FA80084 */  lw    $t0, 0x84($sp)
/* 138D9C 80245A5C 8E24002C */  lw    $a0, 0x2c($s1)
/* 138DA0 80245A60 251300F8 */  addiu $s3, $t0, 0xf8
/* 138DA4 80245A64 0C051261 */  jal   set_icon_render_pos
/* 138DA8 80245A68 0260282D */   daddu $a1, $s3, $zero
/* 138DAC 80245A6C 8E24002C */  lw    $a0, 0x2c($s1)
/* 138DB0 80245A70 0C0511F8 */  jal   func_801447E0
/* 138DB4 80245A74 27D00056 */   addiu $s0, $fp, 0x56
/* 138DB8 80245A78 8FA50050 */  lw    $a1, 0x50($sp)
/* 138DBC 80245A7C 8E240010 */  lw    $a0, 0x10($s1)
/* 138DC0 80245A80 0C051261 */  jal   set_icon_render_pos
/* 138DC4 80245A84 27C6005E */   addiu $a2, $fp, 0x5e
/* 138DC8 80245A88 8E240010 */  lw    $a0, 0x10($s1)
/* 138DCC 80245A8C 0C0511F8 */  jal   func_801447E0
/* 138DD0 80245A90 27D5007B */   addiu $s5, $fp, 0x7b
/* 138DD4 80245A94 0C093BA0 */  jal   func_8024EE80
/* 138DD8 80245A98 24040033 */   addiu $a0, $zero, 0x33
/* 138DDC 80245A9C 0040202D */  daddu $a0, $v0, $zero
/* 138DE0 80245AA0 0200302D */  daddu $a2, $s0, $zero
/* 138DE4 80245AA4 240700FF */  addiu $a3, $zero, 0xff
/* 138DE8 80245AA8 8FA50054 */  lw    $a1, 0x54($sp)
/* 138DEC 80245AAC 2408000A */  addiu $t0, $zero, 0xa
/* 138DF0 80245AB0 AFA80010 */  sw    $t0, 0x10($sp)
/* 138DF4 80245AB4 24080001 */  addiu $t0, $zero, 1
/* 138DF8 80245AB8 0C04993B */  jal   draw_string
/* 138DFC 80245ABC AFA80014 */   sw    $t0, 0x14($sp)
/* 138E00 80245AC0 0280282D */  daddu $a1, $s4, $zero
/* 138E04 80245AC4 0200302D */  daddu $a2, $s0, $zero
/* 138E08 80245AC8 24070001 */  addiu $a3, $zero, 1
/* 138E0C 80245ACC 3C048011 */  lui   $a0, 0x8011
/* 138E10 80245AD0 8084F2A0 */  lb    $a0, -0xd60($a0)
/* 138E14 80245AD4 2408000A */  addiu $t0, $zero, 0xa
/* 138E18 80245AD8 AFA80010 */  sw    $t0, 0x10($sp)
/* 138E1C 80245ADC 240800FF */  addiu $t0, $zero, 0xff
/* 138E20 80245AE0 AFA80014 */  sw    $t0, 0x14($sp)
/* 138E24 80245AE4 0C049DA7 */  jal   draw_number
/* 138E28 80245AE8 AFB20018 */   sw    $s2, 0x18($sp)
/* 138E2C 80245AEC 0260282D */  daddu $a1, $s3, $zero
/* 138E30 80245AF0 8E24002C */  lw    $a0, 0x2c($s1)
/* 138E34 80245AF4 0C051261 */  jal   set_icon_render_pos
/* 138E38 80245AF8 27C6005D */   addiu $a2, $fp, 0x5d
/* 138E3C 80245AFC 8E24002C */  lw    $a0, 0x2c($s1)
/* 138E40 80245B00 0C0511F8 */  jal   func_801447E0
/* 138E44 80245B04 27D00074 */   addiu $s0, $fp, 0x74
/* 138E48 80245B08 8FA50050 */  lw    $a1, 0x50($sp)
/* 138E4C 80245B0C 8E240014 */  lw    $a0, 0x14($s1)
/* 138E50 80245B10 0C051261 */  jal   set_icon_render_pos
/* 138E54 80245B14 02A0302D */   daddu $a2, $s5, $zero
/* 138E58 80245B18 8E240014 */  lw    $a0, 0x14($s1)
/* 138E5C 80245B1C 0C0511F8 */  jal   func_801447E0
/* 138E60 80245B20 00000000 */   nop   
/* 138E64 80245B24 0C093BA0 */  jal   func_8024EE80
/* 138E68 80245B28 24040034 */   addiu $a0, $zero, 0x34
/* 138E6C 80245B2C 0040202D */  daddu $a0, $v0, $zero
/* 138E70 80245B30 0200302D */  daddu $a2, $s0, $zero
/* 138E74 80245B34 240700FF */  addiu $a3, $zero, 0xff
/* 138E78 80245B38 8FA50054 */  lw    $a1, 0x54($sp)
/* 138E7C 80245B3C 2408000A */  addiu $t0, $zero, 0xa
/* 138E80 80245B40 AFA80010 */  sw    $t0, 0x10($sp)
/* 138E84 80245B44 24080001 */  addiu $t0, $zero, 1
/* 138E88 80245B48 0C04993B */  jal   draw_string
/* 138E8C 80245B4C AFA80014 */   sw    $t0, 0x14($sp)
/* 138E90 80245B50 0280282D */  daddu $a1, $s4, $zero
/* 138E94 80245B54 0200302D */  daddu $a2, $s0, $zero
/* 138E98 80245B58 24070001 */  addiu $a3, $zero, 1
/* 138E9C 80245B5C 3C048011 */  lui   $a0, 0x8011
/* 138EA0 80245B60 9084F29F */  lbu   $a0, -0xd61($a0)
/* 138EA4 80245B64 2408000A */  addiu $t0, $zero, 0xa
/* 138EA8 80245B68 AFA80010 */  sw    $t0, 0x10($sp)
/* 138EAC 80245B6C 240800FF */  addiu $t0, $zero, 0xff
