.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel is_status_menu_visible
/* 082DC0 800E9910 3C028011 */  lui   $v0, 0x8011
/* 082DC4 800E9914 8042EF92 */  lb    $v0, -0x106e($v0)
/* 082DC8 800E9918 03E00008 */  jr    $ra
/* 082DCC 800E991C 2C420001 */   sltiu $v0, $v0, 1

