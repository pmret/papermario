.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel CloseChoice
/* 0F55A8 802D0BF8 3C04802E */  lui   $a0, 0x802e
/* 0F55AC 802D0BFC 8C84B268 */  lw    $a0, -0x4d98($a0)
/* 0F55B0 802D0C00 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F55B4 802D0C04 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F55B8 802D0C08 0C04971C */  jal   close_message
/* 0F55BC 802D0C0C 00000000 */   nop   
/* 0F55C0 802D0C10 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F55C4 802D0C14 24020001 */  addiu $v0, $zero, 1
/* 0F55C8 802D0C18 03E00008 */  jr    $ra
/* 0F55CC 802D0C1C 27BD0018 */   addiu $sp, $sp, 0x18

