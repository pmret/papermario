.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel ContinueSpeech
/* 0F4C98 802D02E8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F4C9C 802D02EC AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F4CA0 802D02F0 0C0B40C8 */  jal   _show_message
/* 0F4CA4 802D02F4 24060002 */   addiu $a2, $zero, 2
/* 0F4CA8 802D02F8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F4CAC 802D02FC 03E00008 */  jr    $ra
/* 0F4CB0 802D0300 27BD0018 */   addiu $sp, $sp, 0x18

