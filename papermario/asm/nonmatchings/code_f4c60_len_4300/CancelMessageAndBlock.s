.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel CancelMessageAndBlock
/* 0F55F8 802D0C48 3C04802E */  lui   $a0, 0x802e
/* 0F55FC 802D0C4C 8C84B260 */  lw    $a0, -0x4da0($a0)
/* 0F5600 802D0C50 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F5604 802D0C54 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F5608 802D0C58 0C0496C2 */  jal   cancel_message
/* 0F560C 802D0C5C 00000000 */   nop   
/* 0F5610 802D0C60 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F5614 802D0C64 0000102D */  daddu $v0, $zero, $zero
/* 0F5618 802D0C68 03E00008 */  jr    $ra
/* 0F561C 802D0C6C 27BD0018 */   addiu $sp, $sp, 0x18

