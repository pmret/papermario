.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80144278
/* 0DA978 80144278 27BDFFE8 */  addiu $sp, $sp, -0x18
/* 0DA97C 8014427C 0000282D */  daddu $a1, $zero, $zero
/* 0DA980 80144280 AFBF0010 */  sw    $ra, 0x10($sp)
/* 0DA984 80144284 0C050F12 */  jal   func_80143C48
/* 0DA988 80144288 24060001 */   addiu $a2, $zero, 1
/* 0DA98C 8014428C 8FBF0010 */  lw    $ra, 0x10($sp)
/* 0DA990 80144290 03E00008 */  jr    $ra
/* 0DA994 80144294 27BD0018 */   addiu $sp, $sp, 0x18

