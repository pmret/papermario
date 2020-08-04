.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel AddStarPieces
/* 0FBCA0 802D72F0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FBCA4 802D72F4 AFB00010 */  sw    $s0, 0x10($sp)
/* 0FBCA8 802D72F8 0080802D */  daddu $s0, $a0, $zero
/* 0FBCAC 802D72FC AFBF0014 */  sw    $ra, 0x14($sp)
/* 0FBCB0 802D7300 8E02000C */  lw    $v0, 0xc($s0)
/* 0FBCB4 802D7304 0C0B1EAF */  jal   get_variable
/* 0FBCB8 802D7308 8C450000 */   lw    $a1, ($v0)
/* 0FBCBC 802D730C 0C03A85C */  jal   add_star_pieces
/* 0FBCC0 802D7310 0040202D */   daddu $a0, $v0, $zero
/* 0FBCC4 802D7314 AE020084 */  sw    $v0, 0x84($s0)
/* 0FBCC8 802D7318 8FBF0014 */  lw    $ra, 0x14($sp)
/* 0FBCCC 802D731C 8FB00010 */  lw    $s0, 0x10($sp)
/* 0FBCD0 802D7320 24020002 */  addiu $v0, $zero, 2
/* 0FBCD4 802D7324 03E00008 */  jr    $ra
/* 0FBCD8 802D7328 27BD0018 */   addiu $sp, $sp, 0x18

