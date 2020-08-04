.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel EndSpeech
/* 0F4C7C 802D02CC 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F4C80 802D02D0 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F4C84 802D02D4 0C0B40C8 */  jal   _show_message
/* 0F4C88 802D02D8 24060001 */   addiu $a2, $zero, 1
/* 0F4C8C 802D02DC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F4C90 802D02E0 03E00008 */  jr    $ra
/* 0F4C94 802D02E4 27BD0018 */   addiu $sp, $sp, 0x18

