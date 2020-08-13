.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel PlayerJump
/* 0F6298 802D18E8 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0F629C 802D18EC AFBF0010 */  sw    $ra, 0x10($sp)
/* 0F62A0 802D18F0 0C0B4538 */  jal   player_jump
/* 0F62A4 802D18F4 0000302D */   daddu $a2, $zero, $zero
/* 0F62A8 802D18F8 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0F62AC 802D18FC 03E00008 */  jr    $ra
/* 0F62B0 802D1900 27BD0018 */   addiu $sp, $sp, 0x18

