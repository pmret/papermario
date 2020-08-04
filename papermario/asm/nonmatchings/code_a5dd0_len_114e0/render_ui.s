.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel render_ui
/* 0A9658 80112F58 27BDFFE0 */  addiu $sp, $sp, -0x20
/* 0A965C 80112F5C AFB00010 */  sw    $s0, 0x10($sp)
/* 0A9660 80112F60 3C108015 */  lui   $s0, 0x8015
/* 0A9664 80112F64 26101700 */  addiu $s0, $s0, 0x1700
/* 0A9668 80112F68 AFB10014 */  sw    $s1, 0x14($sp)
/* 0A966C 80112F6C 0000882D */  daddu $s1, $zero, $zero
/* 0A9670 80112F70 AFBF0018 */  sw    $ra, 0x18($sp)
.L80112F74:
/* 0A9674 80112F74 96030000 */  lhu   $v1, ($s0)
/* 0A9678 80112F78 5060000A */  beql  $v1, $zero, .L80112FA4
/* 0A967C 80112F7C 26310001 */   addiu $s1, $s1, 1
/* 0A9680 80112F80 30620004 */  andi  $v0, $v1, 4
/* 0A9684 80112F84 14400007 */  bnez  $v0, .L80112FA4
/* 0A9688 80112F88 26310001 */   addiu $s1, $s1, 1
/* 0A968C 80112F8C 30620010 */  andi  $v0, $v1, 0x10
/* 0A9690 80112F90 14400004 */  bnez  $v0, .L80112FA4
/* 0A9694 80112F94 00000000 */   nop   
/* 0A9698 80112F98 8E020010 */  lw    $v0, 0x10($s0)
/* 0A969C 80112F9C 0040F809 */  jalr  $v0
/* 0A96A0 80112FA0 00000000 */  nop   
.L80112FA4:
/* 0A96A4 80112FA4 2A220002 */  slti  $v0, $s1, 2
/* 0A96A8 80112FA8 1440FFF2 */  bnez  $v0, .L80112F74
/* 0A96AC 80112FAC 26100018 */   addiu $s0, $s0, 0x18
/* 0A96B0 80112FB0 8FBF0018 */  lw    $ra, 0x18($sp)
/* 0A96B4 80112FB4 8FB10014 */  lw    $s1, 0x14($sp)
/* 0A96B8 80112FB8 8FB00010 */  lw    $s0, 0x10($sp)
/* 0A96BC 80112FBC 03E00008 */  jr    $ra
/* 0A96C0 80112FC0 27BD0020 */   addiu $sp, $sp, 0x20

