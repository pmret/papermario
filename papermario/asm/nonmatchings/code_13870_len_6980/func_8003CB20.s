.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8003CB20
/* 017F20 8003CB20 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 017F24 8003CB24 00052880 */  sll   $a1, $a1, 2
/* 017F28 8003CB28 00852021 */  addu  $a0, $a0, $a1
/* 017F2C 8003CB2C AFBF0010 */  sw    $ra, 0x10($sp)
/* 017F30 8003CB30 0C016914 */  jal   remove_effect
/* 017F34 8003CB34 8C840324 */   lw    $a0, 0x324($a0)
/* 017F38 8003CB38 8FBF0010 */  lw    $ra, 0x10($sp)
/* 017F3C 8003CB3C 03E00008 */  jr    $ra
/* 017F40 8003CB40 27BD0018 */   addiu $sp, $sp, 0x18

