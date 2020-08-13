.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_802DE9D8
/* 101AC8 802DE9D8 0080382D */  daddu $a3, $a0, $zero
/* 101ACC 802DE9DC 00052880 */  sll   $a1, $a1, 2
/* 101AD0 802DE9E0 3C04802E */  lui   $a0, 0x802e
/* 101AD4 802DE9E4 00852021 */  addu  $a0, $a0, $a1
/* 101AD8 802DE9E8 8C84F5B0 */  lw    $a0, -0xa50($a0)
/* 101ADC 802DE9EC 14800003 */  bnez  $a0, .L802DE9FC
/* 101AE0 802DE9F0 00061080 */   sll   $v0, $a2, 2
/* 101AE4 802DE9F4 03E00008 */  jr    $ra
/* 101AE8 802DE9F8 0000102D */   daddu $v0, $zero, $zero

.L802DE9FC:
/* 101AEC 802DE9FC 8C830000 */  lw    $v1, ($a0)
/* 101AF0 802DEA00 00431021 */  addu  $v0, $v0, $v1
/* 101AF4 802DEA04 8C430000 */  lw    $v1, ($v0)
/* 101AF8 802DEA08 8C840004 */  lw    $a0, 4($a0)
/* 101AFC 802DEA0C 8C620000 */  lw    $v0, ($v1)
/* 101B00 802DEA10 ACE20000 */  sw    $v0, ($a3)
/* 101B04 802DEA14 90620004 */  lbu   $v0, 4($v1)
/* 101B08 802DEA18 ACE20008 */  sw    $v0, 8($a3)
/* 101B0C 802DEA1C 90620005 */  lbu   $v0, 5($v1)
/* 101B10 802DEA20 ACE2000C */  sw    $v0, 0xc($a3)
/* 101B14 802DEA24 80620006 */  lb    $v0, 6($v1)
/* 101B18 802DEA28 00021080 */  sll   $v0, $v0, 2
/* 101B1C 802DEA2C 00441021 */  addu  $v0, $v0, $a0
/* 101B20 802DEA30 8C430000 */  lw    $v1, ($v0)
/* 101B24 802DEA34 24020001 */  addiu $v0, $zero, 1
/* 101B28 802DEA38 03E00008 */  jr    $ra
/* 101B2C 802DEA3C ACE30004 */   sw    $v1, 4($a3)

