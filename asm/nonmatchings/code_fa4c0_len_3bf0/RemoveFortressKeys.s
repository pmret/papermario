.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel RemoveFortressKeys
/* 0FB644 802D6C94 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0FB648 802D6C98 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0FB64C 802D6C9C 8C82000C */  lw    $v0, 0xc($a0)
/* 0FB650 802D6CA0 0C0B1EAF */  jal   get_variable
/* 0FB654 802D6CA4 8C450000 */   lw    $a1, ($v0)
/* 0FB658 802D6CA8 0C03A8EE */  jal   subtract_fortress_keys
/* 0FB65C 802D6CAC 0040202D */   daddu $a0, $v0, $zero
/* 0FB660 802D6CB0 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0FB664 802D6CB4 24020002 */  addiu $v0, $zero, 2
/* 0FB668 802D6CB8 03E00008 */  jr    $ra
/* 0FB66C 802D6CBC 27BD0018 */   addiu $sp, $sp, 0x18

