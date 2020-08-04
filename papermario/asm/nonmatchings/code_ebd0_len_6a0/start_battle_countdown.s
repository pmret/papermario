.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel start_battle_countdown
/* 00ECD0 800338D0 24020005 */  addiu $v0, $zero, 5
/* 00ECD4 800338D4 3C01800A */  lui   $at, 0x800a
/* 00ECD8 800338D8 A0220900 */  sb    $v0, 0x900($at)
/* 00ECDC 800338DC 03E00008 */  jr    $ra
/* 00ECE0 800338E0 00000000 */   nop   

