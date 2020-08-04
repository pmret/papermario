.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel add_fortress_keys
/* 083848 800EA398 3C038011 */  lui   $v1, 0x8011
/* 08384C 800EA39C 2463F290 */  addiu $v1, $v1, -0xd70
/* 083850 800EA3A0 9062000E */  lbu   $v0, 0xe($v1)
/* 083854 800EA3A4 00441021 */  addu  $v0, $v0, $a0
/* 083858 800EA3A8 A062000E */  sb    $v0, 0xe($v1)
/* 08385C 800EA3AC 00021600 */  sll   $v0, $v0, 0x18
/* 083860 800EA3B0 03E00008 */  jr    $ra
/* 083864 800EA3B4 00021603 */   sra   $v0, $v0, 0x18

