.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel alLink
/* 0267EC 8004B3EC 8CA20000 */  lw    $v0, ($a1)
/* 0267F0 8004B3F0 AC850004 */  sw    $a1, 4($a0)
/* 0267F4 8004B3F4 AC820000 */  sw    $v0, ($a0)
/* 0267F8 8004B3F8 8CA20000 */  lw    $v0, ($a1)
/* 0267FC 8004B3FC 54400001 */  bnel  $v0, $zero, .L8004B404
/* 026800 8004B400 AC440004 */   sw    $a0, 4($v0)
.L8004B404:
/* 026804 8004B404 03E00008 */  jr    $ra
/* 026808 8004B408 ACA40000 */   sw    $a0, ($a1)

