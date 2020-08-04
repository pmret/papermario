.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_model_from_list_index
/* 0B1430 8011AD30 3C028015 */  lui   $v0, 0x8015
/* 0B1434 8011AD34 8C4212CC */  lw    $v0, 0x12cc($v0)
/* 0B1438 8011AD38 00042080 */  sll   $a0, $a0, 2
/* 0B143C 8011AD3C 00822021 */  addu  $a0, $a0, $v0
/* 0B1440 8011AD40 03E00008 */  jr    $ra
/* 0B1444 8011AD44 8C820000 */   lw    $v0, ($a0)

