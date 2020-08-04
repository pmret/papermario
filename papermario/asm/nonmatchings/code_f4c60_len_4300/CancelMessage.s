.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel CancelMessage
/* 0F55D0 802D0C20 3C04802E */  lui   $a0, 0x802e
/* 0F55D4 802D0C24 8C84B260 */  lw    $a0, -0x4da0($a0)
/* 0F55D8 802D0C28 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F55DC 802D0C2C AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F55E0 802D0C30 0C0496C2 */  jal   cancel_message
/* 0F55E4 802D0C34 00000000 */   nop   
/* 0F55E8 802D0C38 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F55EC 802D0C3C 24020002 */  addiu $v0, $zero, 2
/* 0F55F0 802D0C40 03E00008 */  jr    $ra
/* 0F55F4 802D0C44 27BD0018 */   addiu $sp, $sp, 0x18

