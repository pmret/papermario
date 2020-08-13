.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_8025D4A0
/* 18BD80 8025D4A0 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 18BD84 8025D4A4 AFBF0010 */  sw    $ra, 0x10($sp)
/* 18BD88 8025D4A8 8C8200C0 */  lw    $v0, 0xc0($a0)
/* 18BD8C 8025D4AC 00052880 */  sll   $a1, $a1, 2
/* 18BD90 8025D4B0 00451021 */  addu  $v0, $v0, $a1
/* 18BD94 8025D4B4 0C016914 */  jal   remove_effect
/* 18BD98 8025D4B8 8C4408B0 */   lw    $a0, 0x8b0($v0)
/* 18BD9C 8025D4BC 8FBF0010 */  lw    $ra, 0x10($sp)
/* 18BDA0 8025D4C0 03E00008 */  jr    $ra
/* 18BDA4 8025D4C4 27BD0018 */   addiu $sp, $sp, 0x18

