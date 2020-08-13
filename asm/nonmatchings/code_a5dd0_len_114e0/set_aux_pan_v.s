.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel set_aux_pan_v
/* 0B2364 8011BC64 00042080 */  sll   $a0, $a0, 2
/* 0B2368 8011BC68 3C018015 */  lui   $at, 0x8015
/* 0B236C 8011BC6C 00240821 */  addu  $at, $at, $a0
/* 0B2370 8011BC70 AC253328 */  sw    $a1, 0x3328($at)
/* 0B2374 8011BC74 03E00008 */  jr    $ra
/* 0B2378 8011BC78 00000000 */   nop   

