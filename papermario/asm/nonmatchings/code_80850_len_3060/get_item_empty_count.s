.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel get_item_empty_count
/* 080AD0 800E7620 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 080AD4 800E7624 AFBF0010 */  sw    $ra, 0x10($sp)
/* 080AD8 800E7628 0C039D7B */  jal   get_item_count
/* 080ADC 800E762C 00000000 */   nop   
/* 080AE0 800E7630 2403000A */  addiu $v1, $zero, 0xa
/* 080AE4 800E7634 8FBF0010 */  lw    $ra, 0x10($sp)
/* 080AE8 800E7638 00621023 */  subu  $v0, $v1, $v0
/* 080AEC 800E763C 03E00008 */  jr    $ra
/* 080AF0 800E7640 27BD0018 */   addiu $sp, $sp, 0x18

