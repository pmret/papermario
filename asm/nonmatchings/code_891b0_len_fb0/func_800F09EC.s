.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800F09EC
/* 089E9C 800F09EC 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 089EA0 800F09F0 AFB00018 */  sw    $s0, 0x18($sp)
/* 089EA4 800F09F4 3C108011 */  lui   $s0, 0x8011
/* 089EA8 800F09F8 2610EFC8 */  addiu $s0, $s0, -0x1038
/* 089EAC 800F09FC AFBF001C */  sw    $ra, 0x1c($sp)
/* 089EB0 800F0A00 920400B4 */  lbu   $a0, 0xb4($s0)
/* 089EB4 800F0A04 2482FFFF */  addiu $v0, $a0, -1
/* 089EB8 800F0A08 2C420002 */  sltiu $v0, $v0, 2
/* 089EBC 800F0A0C 14400013 */  bnez  $v0, .L800F0A5C
/* 089EC0 800F0A10 3C02FF00 */   lui   $v0, 0xff00
/* 089EC4 800F0A14 8E0300B4 */  lw    $v1, 0xb4($s0)
/* 089EC8 800F0A18 3442FF00 */  ori   $v0, $v0, 0xff00
/* 089ECC 800F0A1C 00621824 */  and   $v1, $v1, $v0
/* 089ED0 800F0A20 3C021A00 */  lui   $v0, 0x1a00
/* 089ED4 800F0A24 1062000D */  beq   $v1, $v0, .L800F0A5C
/* 089ED8 800F0A28 00041600 */   sll   $v0, $a0, 0x18
/* 089EDC 800F0A2C 00021E03 */  sra   $v1, $v0, 0x18
/* 089EE0 800F0A30 2402000A */  addiu $v0, $zero, 0xa
/* 089EE4 800F0A34 10620003 */  beq   $v1, $v0, .L800F0A44
/* 089EE8 800F0A38 00000000 */   nop   
/* 089EEC 800F0A3C 14600004 */  bnez  $v1, .L800F0A50
/* 089EF0 800F0A40 24020004 */   addiu $v0, $zero, 4
.L800F0A44:
/* 089EF4 800F0A44 8E020000 */  lw    $v0, ($s0)
/* 089EF8 800F0A48 04400004 */  bltz  $v0, .L800F0A5C
/* 089EFC 800F0A4C 24020004 */   addiu $v0, $zero, 4
.L800F0A50:
/* 089F00 800F0A50 3C018011 */  lui   $at, 0x8011
/* 089F04 800F0A54 0803C2CB */  j     .L800F0B2C
/* 089F08 800F0A58 A42294AC */   sh    $v0, -0x6b54($at)

.L800F0A5C:
/* 089F0C 800F0A5C 3C048011 */  lui   $a0, 0x8011
/* 089F10 800F0A60 248494AC */  addiu $a0, $a0, -0x6b54
/* 089F14 800F0A64 94820000 */  lhu   $v0, ($a0)
/* 089F18 800F0A68 24430001 */  addiu $v1, $v0, 1
/* 089F1C 800F0A6C 00021400 */  sll   $v0, $v0, 0x10
/* 089F20 800F0A70 00021403 */  sra   $v0, $v0, 0x10
/* 089F24 800F0A74 28420004 */  slti  $v0, $v0, 4
/* 089F28 800F0A78 1440002C */  bnez  $v0, .L800F0B2C
/* 089F2C 800F0A7C A4830000 */   sh    $v1, ($a0)
/* 089F30 800F0A80 C60C0084 */  lwc1  $f12, 0x84($s0)
/* 089F34 800F0A84 A4800000 */  sh    $zero, ($a0)
/* 089F38 800F0A88 0C00A6C9 */  jal   clamp_angle
/* 089F3C 800F0A8C 46006307 */   neg.s $f12, $f12
/* 089F40 800F0A90 3C0140C9 */  lui   $at, 0x40c9
/* 089F44 800F0A94 34210FD0 */  ori   $at, $at, 0xfd0
/* 089F48 800F0A98 44811000 */  mtc1  $at, $f2
/* 089F4C 800F0A9C 00000000 */  nop   
/* 089F50 800F0AA0 46020002 */  mul.s $f0, $f0, $f2
/* 089F54 800F0AA4 00000000 */  nop   
/* 089F58 800F0AA8 27A50010 */  addiu $a1, $sp, 0x10
/* 089F5C 800F0AAC 3C0143B4 */  lui   $at, 0x43b4
/* 089F60 800F0AB0 44816000 */  mtc1  $at, $f12
/* 089F64 800F0AB4 27A60014 */  addiu $a2, $sp, 0x14
/* 089F68 800F0AB8 0C00A82D */  jal   sin_cos_rad
/* 089F6C 800F0ABC 460C0303 */   div.s $f12, $f0, $f12
/* 089F70 800F0AC0 860200B2 */  lh    $v0, 0xb2($s0)
/* 089F74 800F0AC4 C7A40010 */  lwc1  $f4, 0x10($sp)
/* 089F78 800F0AC8 44821000 */  mtc1  $v0, $f2
/* 089F7C 800F0ACC 00000000 */  nop   
/* 089F80 800F0AD0 468010A0 */  cvt.s.w $f2, $f2
/* 089F84 800F0AD4 46041102 */  mul.s $f4, $f2, $f4
/* 089F88 800F0AD8 00000000 */  nop   
/* 089F8C 800F0ADC C7A00014 */  lwc1  $f0, 0x14($sp)
/* 089F90 800F0AE0 46001082 */  mul.s $f2, $f2, $f0
/* 089F94 800F0AE4 00000000 */  nop   
/* 089F98 800F0AE8 3C013E4C */  lui   $at, 0x3e4c
/* 089F9C 800F0AEC 3421CCCD */  ori   $at, $at, 0xcccd
/* 089FA0 800F0AF0 44810000 */  mtc1  $at, $f0
/* 089FA4 800F0AF4 00000000 */  nop   
/* 089FA8 800F0AF8 46002102 */  mul.s $f4, $f4, $f0
/* 089FAC 800F0AFC 00000000 */  nop   
/* 089FB0 800F0B00 46001082 */  mul.s $f2, $f2, $f0
/* 089FB4 800F0B04 00000000 */  nop   
/* 089FB8 800F0B08 C6000028 */  lwc1  $f0, 0x28($s0)
/* 089FBC 800F0B0C 46040000 */  add.s $f0, $f0, $f4
/* 089FC0 800F0B10 44050000 */  mfc1  $a1, $f0
/* 089FC4 800F0B14 C6000030 */  lwc1  $f0, 0x30($s0)
/* 089FC8 800F0B18 46020000 */  add.s $f0, $f0, $f2
/* 089FCC 800F0B1C 3C064220 */  lui   $a2, 0x4220
/* 089FD0 800F0B20 44070000 */  mfc1  $a3, $f0
/* 089FD4 800F0B24 0C01C244 */  jal   func_80070910
/* 089FD8 800F0B28 0000202D */   daddu $a0, $zero, $zero
.L800F0B2C:
/* 089FDC 800F0B2C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 089FE0 800F0B30 8FB00018 */  lw    $s0, 0x18($sp)
/* 089FE4 800F0B34 03E00008 */  jr    $ra
/* 089FE8 800F0B38 27BD0020 */   addiu $sp, $sp, 0x20

