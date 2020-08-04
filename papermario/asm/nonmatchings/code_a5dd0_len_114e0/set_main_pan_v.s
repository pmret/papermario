.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel set_main_pan_v
/* 0B2334 8011BC34 00042080 */  sll   $a0, $a0, 2
/* 0B2338 8011BC38 3C018015 */  lui   $at, 0x8015
/* 0B233C 8011BC3C 00240821 */  addu  $at, $at, $a0
/* 0B2340 8011BC40 AC2532A8 */  sw    $a1, 0x32a8($at)
/* 0B2344 8011BC44 03E00008 */  jr    $ra
/* 0B2348 8011BC48 00000000 */   nop   

