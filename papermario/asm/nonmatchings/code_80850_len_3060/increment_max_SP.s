.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel increment_max_SP
/* 083664 800EA1B4 3C038011 */  lui   $v1, 0x8011
/* 083668 800EA1B8 2463F290 */  addiu $v1, $v1, -0xd70
/* 08366C 800EA1BC 9062028E */  lbu   $v0, 0x28e($v1)
/* 083670 800EA1C0 24420001 */  addiu $v0, $v0, 1
/* 083674 800EA1C4 A062028E */  sb    $v0, 0x28e($v1)
/* 083678 800EA1C8 00021600 */  sll   $v0, $v0, 0x18
/* 08367C 800EA1CC 00021403 */  sra   $v0, $v0, 0x10
/* 083680 800EA1D0 03E00008 */  jr    $ra
/* 083684 800EA1D4 A4620290 */   sh    $v0, 0x290($v1)

