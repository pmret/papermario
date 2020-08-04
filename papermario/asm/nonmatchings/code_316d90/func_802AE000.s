.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802AE000
/* 316D90 802AE000 27BDFFC0 */  addiu $sp, $sp, -0x40
/* 316D94 802AE004 AFB40028 */  sw    $s4, 0x28($sp)
/* 316D98 802AE008 3C1433F5 */  lui   $s4, 0x33f5
/* 316D9C 802AE00C AFB30024 */  sw    $s3, 0x24($sp)
/* 316DA0 802AE010 3C137013 */  lui   $s3, 0x7013
/* 316DA4 802AE014 2673ACA1 */  addiu $s3, $s3, -0x535f
/* 316DA8 802AE018 AFB00018 */  sw    $s0, 0x18($sp)
/* 316DAC 802AE01C 0000802D */  daddu $s0, $zero, $zero
/* 316DB0 802AE020 3C05B000 */  lui   $a1, 0xb000
/* 316DB4 802AE024 34A50800 */  ori   $a1, $a1, 0x800
/* 316DB8 802AE028 3C04800A */  lui   $a0, 0x800a
/* 316DBC 802AE02C 8C84A638 */  lw    $a0, -0x59c8($a0)
/* 316DC0 802AE030 27A60010 */  addiu $a2, $sp, 0x10
/* 316DC4 802AE034 AFB20020 */  sw    $s2, 0x20($sp)
/* 316DC8 802AE038 0200902D */  daddu $s2, $s0, $zero
/* 316DCC 802AE03C AFB5002C */  sw    $s5, 0x2c($sp)
/* 316DD0 802AE040 3C158006 */  lui   $s5, 0x8006
/* 316DD4 802AE044 26B50DC0 */  addiu $s5, $s5, 0xdc0
/* 316DD8 802AE048 AFBF003C */  sw    $ra, 0x3c($sp)
/* 316DDC 802AE04C AFBE0038 */  sw    $fp, 0x38($sp)
/* 316DE0 802AE050 AFB70034 */  sw    $s7, 0x34($sp)
/* 316DE4 802AE054 AFB60030 */  sw    $s6, 0x30($sp)
/* 316DE8 802AE058 02A0F809 */  jalr  $s5
/* 316DEC 802AE05C AFB1001C */  sw    $s1, 0x1c($sp)
/* 316DF0 802AE060 3C110031 */  lui   $s1, 0x31
/* 316DF4 802AE064 26316C00 */  addiu $s1, $s1, 0x6c00
/* 316DF8 802AE068 8FA20010 */  lw    $v0, 0x10($sp)
/* 316DFC 802AE06C 3C030031 */  lui   $v1, 0x31
/* 316E00 802AE070 24636D90 */  addiu $v1, $v1, 0x6d90
/* 316E04 802AE074 0282A023 */  subu  $s4, $s4, $v0
/* 316E08 802AE078 0223102B */  sltu  $v0, $s1, $v1
/* 316E0C 802AE07C 1040002B */  beqz  $v0, .L802AE12C
/* 316E10 802AE080 241E0023 */   addiu $fp, $zero, 0x23
/* 316E14 802AE084 24170003 */  addiu $s7, $zero, 3
/* 316E18 802AE088 0060B02D */  daddu $s6, $v1, $zero
.L802AE08C:
/* 316E1C 802AE08C 0220282D */  daddu $a1, $s1, $zero
/* 316E20 802AE090 3C04800A */  lui   $a0, 0x800a
/* 316E24 802AE094 8C84A638 */  lw    $a0, -0x59c8($a0)
/* 316E28 802AE098 02A0F809 */  jalr  $s5
/* 316E2C 802AE09C 27A60010 */  addiu $a2, $sp, 0x10
/* 316E30 802AE0A0 8FA30010 */  lw    $v1, 0x10($sp)
/* 316E34 802AE0A4 2407000F */  addiu $a3, $zero, 0xf
/* 316E38 802AE0A8 3065FFFF */  andi  $a1, $v1, 0xffff
/* 316E3C 802AE0AC 00032402 */  srl   $a0, $v1, 0x10
/* 316E40 802AE0B0 00A41021 */  addu  $v0, $a1, $a0
/* 316E44 802AE0B4 02028021 */  addu  $s0, $s0, $v0
/* 316E48 802AE0B8 00121682 */  srl   $v0, $s2, 0x1a
/* 316E4C 802AE0BC 1447000F */  bne   $v0, $a3, .L802AE0FC
/* 316E50 802AE0C0 00031682 */   srl   $v0, $v1, 0x1a
/* 316E54 802AE0C4 24070009 */  addiu $a3, $zero, 9
/* 316E58 802AE0C8 50470003 */  beql  $v0, $a3, .L802AE0D8
/* 316E5C 802AE0CC 00031542 */   srl   $v0, $v1, 0x15
/* 316E60 802AE0D0 145E000A */  bne   $v0, $fp, .L802AE0FC
/* 316E64 802AE0D4 00031542 */   srl   $v0, $v1, 0x15
.L802AE0D8:
/* 316E68 802AE0D8 3043001F */  andi  $v1, $v0, 0x1f
/* 316E6C 802AE0DC 00121402 */  srl   $v0, $s2, 0x10
/* 316E70 802AE0E0 3042001F */  andi  $v0, $v0, 0x1f
/* 316E74 802AE0E4 14620005 */  bne   $v1, $v0, .L802AE0FC
/* 316E78 802AE0E8 3082001F */   andi  $v0, $a0, 0x1f
/* 316E7C 802AE0EC 14620003 */  bne   $v1, $v0, .L802AE0FC
/* 316E80 802AE0F0 3242FFFF */   andi  $v0, $s2, 0xffff
/* 316E84 802AE0F4 02058023 */  subu  $s0, $s0, $a1
/* 316E88 802AE0F8 02028023 */  subu  $s0, $s0, $v0
.L802AE0FC:
/* 316E8C 802AE0FC 8FA40010 */  lw    $a0, 0x10($sp)
/* 316E90 802AE100 00041682 */  srl   $v0, $a0, 0x1a
/* 316E94 802AE104 14570006 */  bne   $v0, $s7, .L802AE120
/* 316E98 802AE108 26310004 */   addiu $s1, $s1, 4
/* 316E9C 802AE10C 3083FFFF */  andi  $v1, $a0, 0xffff
/* 316EA0 802AE110 00041402 */  srl   $v0, $a0, 0x10
/* 316EA4 802AE114 3042FC00 */  andi  $v0, $v0, 0xfc00
/* 316EA8 802AE118 00621821 */  addu  $v1, $v1, $v0
/* 316EAC 802AE11C 02038023 */  subu  $s0, $s0, $v1
.L802AE120:
/* 316EB0 802AE120 0236102B */  sltu  $v0, $s1, $s6
/* 316EB4 802AE124 1440FFD9 */  bnez  $v0, .L802AE08C
/* 316EB8 802AE128 0080902D */   daddu $s2, $a0, $zero
.L802AE12C:
/* 316EBC 802AE12C 3C02FFD6 */  lui   $v0, 0xffd6
/* 316EC0 802AE130 3442E66D */  ori   $v0, $v0, 0xe66d
/* 316EC4 802AE134 02021021 */  addu  $v0, $s0, $v0
/* 316EC8 802AE138 02821023 */  subu  $v0, $s4, $v0
/* 316ECC 802AE13C 02629821 */  addu  $s3, $s3, $v0
/* 316ED0 802AE140 00131F02 */  srl   $v1, $s3, 0x1c
/* 316ED4 802AE144 24020008 */  addiu $v0, $zero, 8
/* 316ED8 802AE148 14620005 */  bne   $v1, $v0, .L802AE160
/* 316EDC 802AE14C 00000000 */   nop   
/* 316EE0 802AE150 0260F809 */  jalr  $s3
/* 316EE4 802AE154 00000000 */  nop   
/* 316EE8 802AE158 080AB85C */  j     .L802AE170
/* 316EEC 802AE15C 00000000 */   nop   

.L802AE160:
/* 316EF0 802AE160 3C04803E */  lui   $a0, 0x803e
/* 316EF4 802AE164 2484A800 */  addiu $a0, $a0, -0x5800
/* 316EF8 802AE168 0C00A40C */  jal   _heap_create
/* 316EFC 802AE16C 3C050001 */   lui   $a1, 1
.L802AE170:
/* 316F00 802AE170 8FBF003C */  lw    $ra, 0x3c($sp)
/* 316F04 802AE174 8FBE0038 */  lw    $fp, 0x38($sp)
/* 316F08 802AE178 8FB70034 */  lw    $s7, 0x34($sp)
/* 316F0C 802AE17C 8FB60030 */  lw    $s6, 0x30($sp)
/* 316F10 802AE180 8FB5002C */  lw    $s5, 0x2c($sp)
/* 316F14 802AE184 8FB40028 */  lw    $s4, 0x28($sp)
/* 316F18 802AE188 8FB30024 */  lw    $s3, 0x24($sp)
/* 316F1C 802AE18C 8FB20020 */  lw    $s2, 0x20($sp)
/* 316F20 802AE190 8FB1001C */  lw    $s1, 0x1c($sp)
/* 316F24 802AE194 8FB00018 */  lw    $s0, 0x18($sp)
/* 316F28 802AE198 03E00008 */  jr    $ra
/* 316F2C 802AE19C 27BD0040 */   addiu $sp, $sp, 0x40

.set reorder
