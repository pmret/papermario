.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches


glabel func_8003C984
/* 017D84 8003C984 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 017D88 8003C988 00052880 */  sll   $a1, $a1, 2
/* 017D8C 8003C98C 00852021 */  addu  $a0, $a0, $a1
/* 017D90 8003C990 AFBF0010 */  sw    $ra, 0x10($sp)
/* 017D94 8003C994 0C016914 */  jal   remove_effect
/* 017D98 8003C998 8C840324 */   lw    $a0, 0x324($a0)
/* 017D9C 8003C99C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 017DA0 8003C9A0 03E00008 */  jr    $ra
/* 017DA4 8003C9A4 27BD0018 */   addiu $sp, $sp, 0x18

