.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel SpeakToNpc
/* 0F4CB4 802D0304 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F4CB8 802D0308 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F4CBC 802D030C 0C0B40C8 */  jal   _show_message
/* 0F4CC0 802D0310 24060003 */   addiu $a2, $zero, 3
/* 0F4CC4 802D0314 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F4CC8 802D0318 03E00008 */  jr    $ra
/* 0F4CCC 802D031C 27BD0018 */   addiu $sp, $sp, 0x18

