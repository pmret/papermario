.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_800E98D4
/* 082D84 800E98D4 3C028011 */  lui   $v0, 0x8011
/* 082D88 800E98D8 2442EF58 */  addiu $v0, $v0, -0x10a8
/* 082D8C 800E98DC 80430046 */  lb    $v1, 0x46($v0)
/* 082D90 800E98E0 80420044 */  lb    $v0, 0x44($v0)
/* 082D94 800E98E4 03E00008 */  jr    $ra
/* 082D98 800E98E8 00621021 */   addu  $v0, $v1, $v0

