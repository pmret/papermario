.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80036430
/* 011830 80036430 240200FF */  addiu $v0, $zero, 0xff
/* 011834 80036434 3C01800A */  lui   $at, 0x800a
/* 011838 80036438 A4220940 */  sh    $v0, 0x940($at)
/* 01183C 8003643C 24020014 */  addiu $v0, $zero, 0x14
/* 011840 80036440 3C048011 */  lui   $a0, 0x8011
/* 011844 80036444 2484EFC8 */  addiu $a0, $a0, -0x1038
/* 011848 80036448 3C01800A */  lui   $at, 0x800a
/* 01184C 8003644C A4220942 */  sh    $v0, 0x942($at)
/* 011850 80036450 8C820000 */  lw    $v0, ($a0)
/* 011854 80036454 24030001 */  addiu $v1, $zero, 1
/* 011858 80036458 3C01800A */  lui   $at, 0x800a
/* 01185C 8003645C A4230944 */  sh    $v1, 0x944($at)
/* 011860 80036460 34421000 */  ori   $v0, $v0, 0x1000
/* 011864 80036464 03E00008 */  jr    $ra
/* 011868 80036468 AC820000 */   sw    $v0, ($a0)

