.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel RemoveItemEntity
/* 0FB97C 802D6FCC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FB980 802D6FD0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FB984 802D6FD4 8C82000C */  lw    $v0, 0xc($a0)
/* 0FB988 802D6FD8 0C0B1EAF */  jal   get_variable
/* 0FB98C 802D6FDC 8C450000 */   lw    $a1, ($v0)
/* 0FB990 802D6FE0 0C04CE7F */  jal   remove_item_entity_by_index
/* 0FB994 802D6FE4 0040202D */   daddu $a0, $v0, $zero
/* 0FB998 802D6FE8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FB99C 802D6FEC 24020002 */  addiu $v0, $zero, 2
/* 0FB9A0 802D6FF0 03E00008 */  jr    $ra
/* 0FB9A4 802D6FF4 27BD0018 */   addiu $sp, $sp, 0x18

