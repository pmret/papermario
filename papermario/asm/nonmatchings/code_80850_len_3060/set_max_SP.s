.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel set_max_SP
/* 083688 800EA1D8 3C028011 */  lui   $v0, 0x8011
/* 08368C 800EA1DC 2442F290 */  addiu $v0, $v0, -0xd70
/* 083690 800EA1E0 A044028E */  sb    $a0, 0x28e($v0)
/* 083694 800EA1E4 00042600 */  sll   $a0, $a0, 0x18
/* 083698 800EA1E8 00042403 */  sra   $a0, $a0, 0x10
/* 08369C 800EA1EC 03E00008 */  jr    $ra
/* 0836A0 800EA1F0 A4440290 */   sh    $a0, 0x290($v0)

