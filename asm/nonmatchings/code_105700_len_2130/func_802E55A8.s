.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802E55A8
/* 106E28 802E55A8 27BDFFD8 */  addiu $sp, $sp, -0x28
/* 106E2C 802E55AC AFB00018 */  sw    $s0, 0x18($sp)
/* 106E30 802E55B0 0080802D */  daddu $s0, $a0, $zero
/* 106E34 802E55B4 AFB1001C */  sw    $s1, 0x1c($sp)
/* 106E38 802E55B8 AFB20020 */  sw    $s2, 0x20($sp)
/* 106E3C 802E55BC 3C128016 */  lui   $s2, 0x8016
/* 106E40 802E55C0 8E52C7D0 */  lw    $s2, -0x3830($s2)
/* 106E44 802E55C4 AFBF0024 */  sw    $ra, 0x24($sp)
/* 106E48 802E55C8 0C0B8DB9 */  jal   func_802E36E4
/* 106E4C 802E55CC 00A0882D */   daddu $s1, $a1, $zero
/* 106E50 802E55D0 0220202D */  daddu $a0, $s1, $zero
/* 106E54 802E55D4 C6000048 */  lwc1  $f0, 0x48($s0)
/* 106E58 802E55D8 C602004C */  lwc1  $f2, 0x4c($s0)
/* 106E5C 802E55DC C6040050 */  lwc1  $f4, 0x50($s0)
/* 106E60 802E55E0 3C028000 */  lui   $v0, 0x8000
/* 106E64 802E55E4 AFA00010 */  sw    $zero, 0x10($sp)
/* 106E68 802E55E8 4600018D */  trunc.w.s $f6, $f0
/* 106E6C 802E55EC 44053000 */  mfc1  $a1, $f6
/* 106E70 802E55F0 4600118D */  trunc.w.s $f6, $f2
/* 106E74 802E55F4 44063000 */  mfc1  $a2, $f6
/* 106E78 802E55F8 4600218D */  trunc.w.s $f6, $f4
/* 106E7C 802E55FC 44073000 */  mfc1  $a3, $f6
/* 106E80 802E5600 0C044631 */  jal   create_entity
/* 106E84 802E5604 AFA20014 */   sw    $v0, 0x14($sp)
/* 106E88 802E5608 0C04417A */  jal   get_entity_by_index
/* 106E8C 802E560C 0040202D */   daddu $a0, $v0, $zero
/* 106E90 802E5610 8C430040 */  lw    $v1, 0x40($v0)
/* 106E94 802E5614 92020004 */  lbu   $v0, 4($s0)
/* 106E98 802E5618 16400003 */  bnez  $s2, .L802E5628
/* 106E9C 802E561C A0620000 */   sb    $v0, ($v1)
/* 106EA0 802E5620 080B958B */  j     .L802E562C
/* 106EA4 802E5624 24020003 */   addiu $v0, $zero, 3

.L802E5628:
/* 106EA8 802E5628 24020006 */  addiu $v0, $zero, 6
.L802E562C:
/* 106EAC 802E562C A062000A */  sb    $v0, 0xa($v1)
/* 106EB0 802E5630 8FBF0024 */  lw    $ra, 0x24($sp)
/* 106EB4 802E5634 8FB20020 */  lw    $s2, 0x20($sp)
/* 106EB8 802E5638 8FB1001C */  lw    $s1, 0x1c($sp)
/* 106EBC 802E563C 8FB00018 */  lw    $s0, 0x18($sp)
/* 106EC0 802E5640 03E00008 */  jr    $ra
/* 106EC4 802E5644 27BD0028 */   addiu $sp, $sp, 0x28

/* 106EC8 802E5648 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 106ECC 802E564C 3C05802F */  lui   $a1, 0x802f
/* 106ED0 802E5650 24A5A7BC */  addiu $a1, $a1, -0x5844
/* 106ED4 802E5654 AFBF0010 */  sw    $ra, 0x10($sp)
/* 106ED8 802E5658 0C0B956A */  jal   func_802E55A8
/* 106EDC 802E565C 00000000 */   nop   
/* 106EE0 802E5660 8FBF0010 */  lw    $ra, 0x10($sp)
/* 106EE4 802E5664 03E00008 */  jr    $ra
/* 106EE8 802E5668 27BD0018 */   addiu $sp, $sp, 0x18

/* 106EEC 802E566C 00000000 */  nop   
