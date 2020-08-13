.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80120198
/* 0B6898 80120198 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0B689C 8012019C 2402F7FF */  addiu $v0, $zero, -0x801
/* 0B68A0 801201A0 AFB10014 */  sw    $s1, 0x14($sp)
/* 0B68A4 801201A4 00828824 */  and   $s1, $a0, $v0
/* 0B68A8 801201A8 3C038015 */  lui   $v1, 0x8015
/* 0B68AC 801201AC 8C633A40 */  lw    $v1, 0x3a40($v1)
/* 0B68B0 801201B0 00111080 */  sll   $v0, $s1, 2
/* 0B68B4 801201B4 AFBF001C */  sw    $ra, 0x1c($sp)
/* 0B68B8 801201B8 AFB20018 */  sw    $s2, 0x18($sp)
/* 0B68BC 801201BC AFB00010 */  sw    $s0, 0x10($sp)
/* 0B68C0 801201C0 00431021 */  addu  $v0, $v0, $v1
/* 0B68C4 801201C4 8C430000 */  lw    $v1, ($v0)
/* 0B68C8 801201C8 8C6400DC */  lw    $a0, 0xdc($v1)
/* 0B68CC 801201CC 10800005 */  beqz  $a0, .L801201E4
/* 0B68D0 801201D0 00C0902D */   daddu $s2, $a2, $zero
/* 0B68D4 801201D4 3C0200FF */  lui   $v0, 0xff
/* 0B68D8 801201D8 3442FFFF */  ori   $v0, $v0, 0xffff
/* 0B68DC 801201DC 00A21024 */  and   $v0, $a1, $v0
/* 0B68E0 801201E0 00442821 */  addu  $a1, $v0, $a0
.L801201E4:
/* 0B68E4 801201E4 3C013F80 */  lui   $at, 0x3f80
/* 0B68E8 801201E8 44810000 */  mtc1  $at, $f0
/* 0B68EC 801201EC 0000802D */  daddu $s0, $zero, $zero
/* 0B68F0 801201F0 AC650008 */  sw    $a1, 8($v1)
/* 0B68F4 801201F4 AC65000C */  sw    $a1, 0xc($v1)
/* 0B68F8 801201F8 AC6002CC */  sw    $zero, 0x2cc($v1)
/* 0B68FC 801201FC 1A400007 */  blez  $s2, .L8012021C
/* 0B6900 80120200 E4600090 */   swc1  $f0, 0x90($v1)
.L80120204:
/* 0B6904 80120204 0C047A2F */  jal   func_8011E8BC
/* 0B6908 80120208 0220202D */   daddu $a0, $s1, $zero
/* 0B690C 8012020C 26100001 */  addiu $s0, $s0, 1
/* 0B6910 80120210 0212102A */  slt   $v0, $s0, $s2
/* 0B6914 80120214 1440FFFB */  bnez  $v0, .L80120204
/* 0B6918 80120218 00000000 */   nop   
.L8012021C:
/* 0B691C 8012021C 8FBF001C */  lw    $ra, 0x1c($sp)
/* 0B6920 80120220 8FB20018 */  lw    $s2, 0x18($sp)
/* 0B6924 80120224 8FB10014 */  lw    $s1, 0x14($sp)
/* 0B6928 80120228 8FB00010 */  lw    $s0, 0x10($sp)
/* 0B692C 8012022C 03E00008 */  jr    $ra
/* 0B6930 80120230 27BD0020 */   addiu $sp, $sp, 0x20

