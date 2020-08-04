.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_player_data
/* 080A14 800E7564 3C028011 */  lui   $v0, 0x8011
/* 080A18 800E7568 2442F290 */  addiu $v0, $v0, -0xd70
/* 080A1C 800E756C 03E00008 */  jr    $ra
/* 080A20 800E7570 00000000 */   nop   

