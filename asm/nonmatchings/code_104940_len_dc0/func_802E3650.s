.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802E3650
/* 104ED0 802E3650 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 104ED4 802E3654 AFB00010 */  sw    $s0, 0x10($sp)
/* 104ED8 802E3658 0080802D */  daddu $s0, $a0, $zero
/* 104EDC 802E365C AFB20018 */  sw    $s2, 0x18($sp)
/* 104EE0 802E3660 AFBF001C */  sw    $ra, 0x1c($sp)
/* 104EE4 802E3664 AFB10014 */  sw    $s1, 0x14($sp)
/* 104EE8 802E3668 8E110040 */  lw    $s1, 0x40($s0)
/* 104EEC 802E366C 0C044AC8 */  jal   func_80112B20
/* 104EF0 802E3670 0000902D */   daddu $s2, $zero, $zero
/* 104EF4 802E3674 10400014 */  beqz  $v0, .L802E36C8
/* 104EF8 802E3678 3C030020 */   lui   $v1, 0x20
/* 104EFC 802E367C 8E020000 */  lw    $v0, ($s0)
/* 104F00 802E3680 00431024 */  and   $v0, $v0, $v1
/* 104F04 802E3684 10400011 */  beqz  $v0, .L802E36CC
/* 104F08 802E3688 0240102D */   daddu $v0, $s2, $zero
/* 104F0C 802E368C 24120001 */  addiu $s2, $zero, 1
/* 104F10 802E3690 0C0B8CDC */  jal   func_802E3370
/* 104F14 802E3694 0200202D */   daddu $a0, $s0, $zero
/* 104F18 802E3698 86240010 */  lh    $a0, 0x10($s1)
/* 104F1C 802E369C 2402FFFF */  addiu $v0, $zero, -1
/* 104F20 802E36A0 1082000A */  beq   $a0, $v0, .L802E36CC
/* 104F24 802E36A4 0240102D */   daddu $v0, $s2, $zero
/* 104F28 802E36A8 0C04C3D6 */  jal   get_item_entity
/* 104F2C 802E36AC 00000000 */   nop   
/* 104F30 802E36B0 C600004C */  lwc1  $f0, 0x4c($s0)
/* 104F34 802E36B4 3C014080 */  lui   $at, 0x4080
/* 104F38 802E36B8 44811000 */  mtc1  $at, $f2
/* 104F3C 802E36BC 00000000 */  nop   
/* 104F40 802E36C0 46020000 */  add.s $f0, $f0, $f2
/* 104F44 802E36C4 E440000C */  swc1  $f0, 0xc($v0)
.L802E36C8:
/* 104F48 802E36C8 0240102D */  daddu $v0, $s2, $zero
.L802E36CC:
/* 104F4C 802E36CC 8FBF001C */  lw    $ra, 0x1c($sp)
/* 104F50 802E36D0 8FB20018 */  lw    $s2, 0x18($sp)
/* 104F54 802E36D4 8FB10014 */  lw    $s1, 0x14($sp)
/* 104F58 802E36D8 8FB00010 */  lw    $s0, 0x10($sp)
/* 104F5C 802E36DC 03E00008 */  jr    $ra
/* 104F60 802E36E0 27BD0020 */   addiu $sp, $sp, 0x20

