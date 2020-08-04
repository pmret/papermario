.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80246504
/* 139844 80246504 0276102A */  slt   $v0, $s3, $s6
/* 139848 80246508 10400073 */  beqz  $v0, .L802466D8
/* 13984C 8024650C 26520001 */   addiu $s2, $s2, 1
/* 139850 80246510 26730001 */  addiu $s3, $s3, 1
/* 139854 80246514 00158080 */  sll   $s0, $s5, 2
/* 139858 80246518 3C058025 */  lui   $a1, 0x8025
