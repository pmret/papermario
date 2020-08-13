.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802E464C
/* 105ECC 802E464C 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 105ED0 802E4650 AFB00010 */  sw    $s0, 0x10($sp)
/* 105ED4 802E4654 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105ED8 802E4658 0C0B8DB9 */  jal   func_802E36E4
/* 105EDC 802E465C 0080802D */   daddu $s0, $a0, $zero
/* 105EE0 802E4660 8E030040 */  lw    $v1, 0x40($s0)
/* 105EE4 802E4664 3C028016 */  lui   $v0, 0x8016
/* 105EE8 802E4668 9442C7D2 */  lhu   $v0, -0x382e($v0)
/* 105EEC 802E466C A4620010 */  sh    $v0, 0x10($v1)
/* 105EF0 802E4670 3402FFFF */  ori   $v0, $zero, 0xffff
/* 105EF4 802E4674 A462000A */  sh    $v0, 0xa($v1)
/* 105EF8 802E4678 3C02802E */  lui   $v0, 0x802e
/* 105EFC 802E467C 2442455C */  addiu $v0, $v0, 0x455c
/* 105F00 802E4680 AE02003C */  sw    $v0, 0x3c($s0)
/* 105F04 802E4684 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105F08 802E4688 8FB00010 */  lw    $s0, 0x10($sp)
/* 105F0C 802E468C 03E00008 */  jr    $ra
/* 105F10 802E4690 27BD0018 */   addiu $sp, $sp, 0x18

/* 105F14 802E4694 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 105F18 802E4698 AFB00010 */  sw    $s0, 0x10($sp)
/* 105F1C 802E469C AFBF0014 */  sw    $ra, 0x14($sp)
/* 105F20 802E46A0 0C0B9193 */  jal   func_802E464C
/* 105F24 802E46A4 0080802D */   daddu $s0, $a0, $zero
/* 105F28 802E46A8 A200000B */  sb    $zero, 0xb($s0)
/* 105F2C 802E46AC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105F30 802E46B0 8FB00010 */  lw    $s0, 0x10($sp)
/* 105F34 802E46B4 03E00008 */  jr    $ra
/* 105F38 802E46B8 27BD0018 */   addiu $sp, $sp, 0x18

/* 105F3C 802E46BC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 105F40 802E46C0 AFB00010 */  sw    $s0, 0x10($sp)
/* 105F44 802E46C4 AFBF0014 */  sw    $ra, 0x14($sp)
/* 105F48 802E46C8 0C0B8DB9 */  jal   func_802E36E4
/* 105F4C 802E46CC 0080802D */   daddu $s0, $a0, $zero
/* 105F50 802E46D0 86040014 */  lh    $a0, 0x14($s0)
/* 105F54 802E46D4 3C02802E */  lui   $v0, 0x802e
/* 105F58 802E46D8 2442455C */  addiu $v0, $v0, 0x455c
/* 105F5C 802E46DC 0C047FF8 */  jal   func_8011FFE0
/* 105F60 802E46E0 AE02003C */   sw    $v0, 0x3c($s0)
/* 105F64 802E46E4 24030011 */  addiu $v1, $zero, 0x11
/* 105F68 802E46E8 A0430004 */  sb    $v1, 4($v0)
/* 105F6C 802E46EC 8C430000 */  lw    $v1, ($v0)
/* 105F70 802E46F0 3C040001 */  lui   $a0, 1
/* 105F74 802E46F4 00641825 */  or    $v1, $v1, $a0
/* 105F78 802E46F8 AC430000 */  sw    $v1, ($v0)
/* 105F7C 802E46FC 8FBF0014 */  lw    $ra, 0x14($sp)
/* 105F80 802E4700 8FB00010 */  lw    $s0, 0x10($sp)
/* 105F84 802E4704 03E00008 */  jr    $ra
/* 105F88 802E4708 27BD0018 */   addiu $sp, $sp, 0x18

/* 105F8C 802E470C 00000000 */  nop   
