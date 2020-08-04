.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel PlayerJump1
/* 0F62B4 802D1904 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F62B8 802D1908 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F62BC 802D190C 0C0B4538 */  jal   player_jump
/* 0F62C0 802D1910 24060001 */   addiu $a2, $zero, 1
/* 0F62C4 802D1914 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F62C8 802D1918 03E00008 */  jr    $ra
/* 0F62CC 802D191C 27BD0018 */   addiu $sp, $sp, 0x18

