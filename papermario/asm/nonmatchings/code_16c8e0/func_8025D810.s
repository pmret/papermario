.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8025D810
/* 18C0F0 8025D810 8C8200C0 */  lw    $v0, 0xc0($a0)
/* 18C0F4 8025D814 00052880 */  sll   $a1, $a1, 2
/* 18C0F8 8025D818 00451021 */  addu  $v0, $v0, $a1
/* 18C0FC 8025D81C 8C4308B0 */  lw    $v1, 0x8b0($v0)
/* 18C100 8025D820 8C620000 */  lw    $v0, ($v1)
/* 18C104 8025D824 34420010 */  ori   $v0, $v0, 0x10
/* 18C108 8025D828 03E00008 */  jr    $ra
/* 18C10C 8025D82C AC620000 */   sw    $v0, ($v1)

